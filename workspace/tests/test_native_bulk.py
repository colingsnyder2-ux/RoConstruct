import hashlib
import json
from pathlib import Path
import struct
import tempfile
import types
import unittest
from unittest.mock import patch

from roc import delink, native_bulk
from roc.delink import Coff, DIR32, FLAGS, REL32


def object_bytes(body, relocations=()):
    coff = Coff()
    section = coff.section(".text", body, FLAGS[".text"])
    coff.symbol("?familyBody@@YAXXZ", section, 0, function=True)
    for offset, kind, symbol in relocations:
        index = coff.symbol(symbol)
        coff.sections[section - 1]["relocs"].append((offset, index, kind))
    with tempfile.TemporaryDirectory() as folder:
        path = Path(folder) / "family.obj"
        coff.write(path)
        return path.read_bytes()


def nested_data_object(body):
    coff = Coff()
    text = coff.section(".text", body, FLAGS[".text"])
    coff.symbol("?familyBody@@YAXXZ", text, 0, function=True)
    data = coff.section(".data", bytes(4), FLAGS[".data"])
    global_symbol = coff.symbol("?global@@3PAHA", data, 0)
    nested = coff.section(".rdata", b"ABCD", FLAGS[".rdata"])
    nested_symbol = coff.symbol("?nested@@3PAHA", nested, 0)
    coff.sections[text - 1]["relocs"].append((1, global_symbol, DIR32))
    coff.sections[data - 1]["relocs"].append((0, nested_symbol, DIR32))
    with tempfile.TemporaryDirectory() as folder:
        path = Path(folder) / "nested.obj"
        coff.write(path)
        return path.read_bytes()


class FakeTargets:
    def __init__(self, bodies, candidate_rows=None):
        self.bodies = bodies
        self.candidate_rows = candidate_rows or {}
        self.identity = "targets-test"
        self.base = 0x1000
        self.image = bytes(0x4000)
        self.relocs = set()

    def candidates(self, body, relocs):
        return list(self.candidate_rows.get((body, tuple(relocs)), []))

    def body(self, addr):
        return self.bodies[addr]

    def data(self, va, size):
        return bytes(size)

    def data_relocations(self, va, size):
        return set()


class NativeBulkTests(unittest.TestCase):
    def test_harvest_proves_exact_body_without_relocations(self):
        code = b"\x55\x8b\xec\x83\xec\x08\xc3"
        rows = native_bulk.harvest(object_bytes(code), FakeTargets({"00001000": (code, [])}),
                                   {"?familyBody@@YAXXZ": {"00001000"}}, {})
        self.assertEqual(rows[0]["status"], "inactive_exact")
        self.assertEqual(rows[0]["addr"], "00001000")
        self.assertEqual(rows[0]["identity"], native_bulk.digest([code.hex(), []]))

    def test_wrong_reference_identity_rejects_masked_byte_match(self):
        target_address = 0x1000
        destination = 0x2000
        displacement = destination - (target_address + 5)
        original = b"\xe8" + struct.pack("<i", displacement) + b"\xc3"
        candidate = b"\xe8\0\0\0\0\xc3"
        raw = object_bytes(candidate, [(1, REL32, "?callee@@YAXXZ")])
        rows = native_bulk.harvest(raw, FakeTargets({"00001000": (original, [])}),
                                   {"?familyBody@@YAXXZ": {"00001000"}},
                                   {"?callee@@YAXXZ": "00003000"})
        self.assertEqual(rows[0]["status"], "draft")
        self.assertIn("reference identity differs: ?callee@@YAXXZ",
                      rows[0]["rejections"][0]["errors"])

    def test_absolute_field_without_original_relocation_is_rejected(self):
        original = b"\xb8\x00\x20\x00\x00\xc3"
        candidate = b"\xb8\0\0\0\0\xc3"
        raw = object_bytes(candidate, [(1, DIR32, "?global@@3HA")])
        rows = native_bulk.harvest(raw, FakeTargets({"00001000": (original, [])}),
                                   {"?familyBody@@YAXXZ": {"00001000"}}, {})
        self.assertEqual(rows[0]["status"], "draft")
        self.assertIn("absolute field is not relocated in original",
                      rows[0]["rejections"][0]["errors"])

    def test_nested_data_pointer_matches_target_and_identity(self):
        original = b"\xb8\x00\x20\x00\x00\xc3"
        candidate = b"\xb8\0\0\0\0\xc3"

        class NestedTargets(FakeTargets):
            def __init__(self):
                super().__init__({"00001000": (original, [1])})
                self.relocs = {0x2000}

            def data(self, va, size):
                return struct.pack("<I", 0x3000) if va == 0x2000 and size == 4 else b"ABCD"[:size]

            def data_relocations(self, va, size):
                return {0} if va == 0x2000 and size == 4 else set()

        names = {"?familyBody@@YAXXZ": {"00001000"}}
        bindings = {"?global@@3PAHA": "00002000", "?nested@@3PAHA": "00003000"}
        targets = NestedTargets()
        targets.bodies["00001000"] = (original, [1])
        accepted = native_bulk.harvest(nested_data_object(candidate), targets, names, bindings)
        self.assertEqual(accepted[0]["status"], "inactive_exact")
        self.assertEqual(accepted[0]["references"][0]["address"], "00002000")

        wrong = dict(bindings, **{"?nested@@3PAHA": "00004000"})
        rejected = native_bulk.harvest(nested_data_object(candidate), targets, names, wrong)
        self.assertEqual(rejected[0]["status"], "draft")
        self.assertIn("reference identity differs: ?nested@@3PAHA",
                      rejected[0]["rejections"][0]["errors"])

    def test_ambiguous_named_aliases_do_not_become_provider(self):
        code = b"\x55\x8b\xec\x83\xec\x08\xc3"
        targets = FakeTargets({"00001000": (code, []), "00002000": (code, [])})
        rows = native_bulk.harvest(object_bytes(code), targets,
                                   {"?familyBody@@YAXXZ": {"00001000", "00002000"}}, {})
        self.assertEqual(rows[0]["status"], "ambiguous")
        self.assertNotIn("addr", rows[0])

    def test_receipt_records_skip_pending_and_nonexact_lanes(self):
        exact = {"symbol": "?exact@@", "address": "00401000", "exact": True}
        receipt = {"methods": [exact], "pending_methods": [dict(exact, address="00402000")],
                   "rows": [dict(exact, address="00403000", exact=False),
                            dict(exact, address="00404000", pending_build=True),
                            dict(exact, address="00405000", exact_pending_build_only=True)]}
        self.assertEqual(list(native_bulk.records(receipt)), [exact])

    def test_stale_receipt_source_is_blocked_and_not_bound(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "src").mkdir()
            (root / "src/body.cpp").write_text("void body() {}\n")
            (root / "evidence.json").write_text(json.dumps({
                "sources": {"src/body.cpp": "0" * 64},
                "methods": [{"symbol": "?body@@", "address": "00401000"}],
            }))
            symbols, bindings, blockers, _ = native_bulk.seed_evidence(root, ["evidence.json"])
        self.assertTrue(any(blocker.startswith("stale reference receipt:") for blocker in blockers))
        self.assertEqual(symbols, {})
        self.assertEqual(bindings, {})

    def test_evidence_path_traversal_is_rejected(self):
        with tempfile.TemporaryDirectory() as folder:
            with self.assertRaises(ValueError):
                native_bulk.seed_evidence(Path(folder), ["../outside.json"])

    def test_run_reuses_object_and_harvest_cache_when_inputs_stay_fresh(self):
        code = b"\x55\x8b\xec\x83\xec\x08\xc3"
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            source = root / "src/2008-06/body.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("void body() {}\n")
            receipt = root / "work/2008-06/evidence.json"
            receipt.parent.mkdir(parents=True)
            receipt.write_text(json.dumps({
                "sources": {"src/2008-06/body.cpp": native_bulk.sha(source)},
                "methods": [{"symbol": "?familyBody@@YAXXZ", "address": "00001000"}],
            }))
            tools = root / "toolchain"
            tools.mkdir()
            compiler = tools / "cl.exe"
            compiler.write_bytes(b"fake compiler marker")
            for name in ("c1xx.dll", "c2.dll", "mspdb80.dll", "mspdb90.dll"):
                (tools / name).write_bytes(name.encode())
            runner_path = root / "native_check_runner.py"
            runner_path.write_text("# mocked checker\n")
            calls = []

            def compile_job(job, output, tc):
                calls.append(job["source"])
                output = Path(output)
                output.mkdir(parents=True, exist_ok=True)
                obj = output / "body.obj"
                obj.write_bytes(object_bytes(code))
                return {"status": "complete", "source_sha256": native_bulk.sha(job["source"]),
                        "object": str(obj), "object_sha256": native_bulk.sha(obj), "dependencies": {}}

            fake_runner = types.SimpleNamespace(__file__=str(runner_path),
                                                compiler_flags=lambda path: ["/O2"],
                                                compile_job=compile_job)

            class TargetsForRun(FakeTargets):
                def __init__(self, client, selected=None):
                    super().__init__({"00001000": (code, [])})

            config = {"client": "2008-06", "families": [{"name": "Body", "sources": ["src/2008-06/body.cpp"],
                      "evidence": ["work/2008-06/evidence.json"]}]}
            output = root / "bulk-out"
            with patch.object(native_bulk, "checker", return_value=fake_runner), \
                    patch.object(native_bulk, "Targets", TargetsForRun), \
                    patch.object(native_bulk.rebuild, "toolchain", return_value={"cl": str(compiler)}):
                first = native_bulk.run(config, output, root=root)
                second = native_bulk.run(config, output, root=root)

        self.assertEqual(len(calls), 1)
        self.assertEqual(first["metrics"]["compile_invocations"], 1)
        self.assertEqual(second["metrics"]["compile_invocations"], 0)
        self.assertEqual(second["metrics"]["reused_objects"], 1)
        self.assertEqual(second["families"][0]["symbols"][0]["status"], "inactive_exact")

    def test_missing_include_creation_wakes_cached_compile_failure(self):
        code = b"\x55\x8b\xec\x83\xec\x08\xc3"
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            source = root / "src/2008-06/body.cpp"
            source.parent.mkdir(parents=True)
            source.write_text('#include "Late.h"\nvoid body() {}\n')
            tools = root / "toolchain"
            tools.mkdir()
            compiler = tools / "cl.exe"
            compiler.write_bytes(b"fake compiler marker")
            for name in ("c1xx.dll", "c2.dll", "mspdb80.dll", "mspdb90.dll"):
                (tools / name).write_bytes(name.encode())
            runner_path = root / "native_check_runner.py"
            runner_path.write_text("# mocked checker\n")
            calls = []

            def compile_job(job, output, tc):
                calls.append(job["source"])
                output = Path(output)
                output.mkdir(parents=True, exist_ok=True)
                if len(calls) == 1:
                    (output / "compile.log").write_text("Cannot open include file: 'Late.h'\n")
                    return {"status": "failed", "error": "missing include"}
                obj = output / "body.obj"
                obj.write_bytes(object_bytes(code))
                return {"status": "complete", "source_sha256": native_bulk.sha(job["source"]),
                        "object": str(obj), "object_sha256": native_bulk.sha(obj), "dependencies": {}}

            fake_runner = types.SimpleNamespace(__file__=str(runner_path),
                                                compiler_flags=lambda path: ["/O2"],
                                                compile_job=compile_job)

            class TargetsForRun(FakeTargets):
                def __init__(self, client, selected=None):
                    super().__init__({})

            config = {"client": "2008-06", "families": [{"name": "Body", "sources": ["src/2008-06/body.cpp"]}]}
            output = root / "bulk-out"
            with patch.object(native_bulk, "checker", return_value=fake_runner), \
                    patch.object(native_bulk, "Targets", TargetsForRun), \
                    patch.object(native_bulk.rebuild, "toolchain", return_value={"cl": str(compiler)}):
                first = native_bulk.run(config, output, root=root)
                parked = native_bulk.run(config, output, root=root)
                (source.parent / "Late.h").write_text("// include appeared\n")
                awakened = native_bulk.run(config, output, root=root)

        self.assertEqual(len(calls), 2)
        self.assertEqual(first["metrics"]["compile_invocations"], 1)
        self.assertEqual(parked["metrics"]["compile_invocations"], 0)
        self.assertEqual(parked["metrics"]["parked_unchanged_failures"], 1)
        self.assertEqual(awakened["metrics"]["compile_invocations"], 1)

    def test_header_drift_during_compile_invalidates_exact_proofs_and_metrics(self):
        code = b"\x55\x8b\xec\x83\xec\x08\xc3"
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            source = root / "src/2008-06/body.cpp"
            source.parent.mkdir(parents=True)
            source.write_text('#include "Contract.h"\nvoid body() {}\n')
            header = source.parent / "Contract.h"
            header.write_text("// contract before compile\n")
            receipt = root / "work/2008-06/evidence.json"
            receipt.parent.mkdir(parents=True)
            receipt.write_text(json.dumps({
                "sources": {"src/2008-06/body.cpp": native_bulk.sha(source)},
                "methods": [{"symbol": "?familyBody@@YAXXZ", "address": "00001000"}],
            }))
            tools = root / "toolchain"
            tools.mkdir()
            compiler = tools / "cl.exe"
            compiler.write_bytes(b"fake compiler marker")
            for name in ("c1xx.dll", "c2.dll", "mspdb80.dll", "mspdb90.dll"):
                (tools / name).write_bytes(name.encode())
            runner_path = root / "native_check_runner.py"
            runner_path.write_text("# mocked checker\n")

            def compile_job(job, output, tc):
                header_hash = native_bulk.sha(header)
                header.write_text("// contract changed during compile\n")
                output = Path(output)
                output.mkdir(parents=True, exist_ok=True)
                obj = output / "body.obj"
                obj.write_bytes(object_bytes(code))
                return {"status": "complete", "source_sha256": native_bulk.sha(job["source"]),
                        "object": str(obj), "object_sha256": native_bulk.sha(obj),
                        "dependencies": {str(header): header_hash}}

            fake_runner = types.SimpleNamespace(__file__=str(runner_path),
                                                compiler_flags=lambda path: ["/O2"],
                                                compile_job=compile_job)

            class TargetsForRun(FakeTargets):
                def __init__(self, client, selected=None):
                    super().__init__({"00001000": (code, [])})

            config = {"client": "2008-06", "families": [{"name": "Body", "sources": ["src/2008-06/body.cpp"],
                      "evidence": ["work/2008-06/evidence.json"]}]}
            with patch.object(native_bulk, "checker", return_value=fake_runner), \
                    patch.object(native_bulk, "Targets", TargetsForRun), \
                    patch.object(native_bulk.rebuild, "toolchain", return_value={"cl": str(compiler)}):
                report = native_bulk.run(config, root / "bulk-out", root=root)

        self.assertEqual(report["metrics"]["compile_invocations"], 1)
        self.assertEqual(report["metrics"]["inactive_distinct_addresses"], 0)
        self.assertEqual(report["families"][0]["symbols"][0]["status"], "stale")
        self.assertEqual(report["families"][0]["jobs"][0]["checks"], [])
        self.assertTrue(any("inputs changed during batch" in blocker
                            for blocker in report["families"][0]["blockers"]))

    def test_prepare_link_rejects_stale_inputs_before_delink(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            source = root / "source.cpp"
            source.write_text("void body() {}\n")
            output = root / "preflight"
            report = {"client": "2008-06", "tools": {}, "target_identity": "targets-v1",
                      "families": [{"name": "Body", "inputs": {str(source): "0" * 64}, "jobs": []}],
                      "promotion": {"batches": [], "selected_providers": {}}}
            with patch.object(native_bulk, "Targets", return_value=types.SimpleNamespace(identity="targets-v1")), \
                    patch.object(delink, "delink") as make_delink:
                with self.assertRaisesRegex(ValueError, "stale preflight inputs"):
                    native_bulk.prepare_link(report, output)
            make_delink.assert_not_called()
            self.assertFalse(output.exists())

    def test_prepare_link_never_selects_blocked_family(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            output = root / "preflight"
            obj = root / "body.obj"
            obj.write_bytes(b"synthetic object receipt")
            report = {"client": "2008-06", "tools": {}, "target_identity": "targets-v1",
                      "families": [{"name": "Blocked", "inputs": {},
                                    "jobs": [{"object": str(obj), "object_sha256": native_bulk.sha(obj),
                                              "checks": [{"symbol": "?body@@", "addr": "00001000"}]}],
                                    "symbols": [{"symbol": "?body@@", "addr": "00001000",
                                                 "identity": "body-id", "status": "inactive_exact"}]}],
                      "promotion": {"batches": [{"families": ["Blocked"], "ready_for_preflight": False}],
                                    "selected_providers": {"?body@@": {"origin": "native", "owner": "Blocked",
                                                                         "address": "00001000", "identity": "body-id"}}}}
            with patch.object(native_bulk, "Targets", return_value=types.SimpleNamespace(identity="targets-v1")), \
                    patch.object(delink, "delink") as make_delink:
                with self.assertRaisesRegex(ValueError, "no fresh dependency-ready providers"):
                    native_bulk.prepare_link(report, output)
            make_delink.assert_not_called()
            self.assertFalse(output.exists())


if __name__ == "__main__":
    unittest.main()
