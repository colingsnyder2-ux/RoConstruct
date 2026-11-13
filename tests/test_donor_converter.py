import importlib.util
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from roc import donor_converter


class DonorConverterTests(unittest.TestCase):
    def test_roc_command_routes_sources_to_converter(self):
        script = Path(__file__).resolve().parents[1] / "roc.py"
        spec = importlib.util.spec_from_file_location("roc_donor_converter_cli_test", script)
        cli = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cli)
        report = {"summary": {"sources": 1, "compiled": 1, "exact": 2, "missing": 1}}

        with patch("roc.donor_converter.convert", return_value=report) as convert:
            cli.main(["donor-convert", "tools/rbxgs/Client/App/Test.cpp", "--output", "result.json"])

        convert.assert_called_once_with(cli.ROOT, ["tools/rbxgs/Client/App/Test.cpp"], Path("result.json"))

    def test_resolve_sources_only_accepts_cpp_inside_donor_roots(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            source = root / "tools/rbxgs/Client/Part.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("void f() {}")
            outside = root / "rebuild/2008-06/native-classes/Part.cpp"
            outside.parent.mkdir(parents=True)
            outside.write_text("void f() {}")

            self.assertEqual(donor_converter.resolve_sources(root, [source]), [source.resolve()])
            with self.assertRaisesRegex(ValueError, "outside donor roots"):
                donor_converter.resolve_sources(root, [outside])

    def test_identity_hypotheses_keeps_exact_functions_and_marks_conflicts(self):
        closure = {"bindings": [
            {"symbol": "?good@@YAXXZ", "address": "00401000", "body_exact": True, "function_start": True},
            {"symbol": "?conflict@@YAXXZ", "address": "00402000", "body_exact": True, "function_start": True},
            {"symbol": "?conflict@@YAXXZ", "address": "00403000", "body_exact": True, "function_start": True},
            {"symbol": "?data@@3HA", "address": "00404000", "body_exact": True, "function_start": False},
        ]}

        names, bindings = donor_converter.identity_hypotheses(closure)

        self.assertEqual(names["?good@@YAXXZ"], {"00401000"})
        self.assertNotIn("?conflict@@YAXXZ", names)
        self.assertIsNone(bindings["?conflict@@YAXXZ"])
        self.assertNotIn("?data@@3HA", bindings)

    def test_classify_object_reports_only_proven_rows_as_exact(self):
        rows = [
            {"symbol": "?yes@@YAXXZ", "status": "inactive_exact", "addr": "00401000"},
            {"symbol": "?no@@YAXXZ", "status": "draft"},
        ]

        report = donor_converter.classify_object(
            b"obj", object(), {}, {}, harvest=lambda *args: rows, rank=lambda *args: [])

        self.assertEqual(report["summary"], {
            "functions": 2, "exact": 1, "draft": 1, "ambiguous": 0,
            "repair_candidates": 0, "proof_candidates": 0,
            "reference_identities": 0, "identity_conflicts": 0})
        self.assertEqual(report["exact_candidates"], [rows[0]])

    def test_label_candidates_separates_integrated_waiting_and_missing(self):
        rows = [
            {"addr": "00401000"},
            {"addr": "00402000"},
            {"addr": "00403000"},
        ]

        summary = donor_converter.label_candidates(rows, {
            "native": ["00401000"],
            "inactive": {"00402000": ["waiting"]},
        })

        self.assertEqual([row["integration"] for row in rows], ["integrated", "waiting", "missing"])
        self.assertEqual(summary, {"integrated": 1, "waiting": 1, "missing": 1})

    def test_rank_partials_uses_named_target_but_never_calls_it_exact(self):
        class Targets:
            def body(self, address):
                return b"target", []

        rows = donor_converter.rank_partials(
            b"obj", Targets(), {"?near@@YAXXZ": {"00401000"}}, set(), threshold=.8,
            functions=lambda raw: [("?near@@YAXXZ", b"candidate", [])],
            similarity=lambda *args: .91,
            diagnose=lambda *args: {"mismatch_class": "immediate/constant mismatch",
                                    "classifications": [{"category": "immediate/constant mismatch"}],
                                    "byte_diffs": [{"offset": 2}]})

        self.assertEqual(rows, [{
            "symbol": "?near@@YAXXZ", "addr": "00401000", "similarity": .91,
            "status": "repair_candidate", "proof": "advisory-not-exact",
            "diagnosis": {"mismatch_class": "immediate/constant mismatch",
                          "classifications": [{"category": "immediate/constant mismatch"}],
                          "byte_diffs": [{"offset": 2}], "target_size": 6, "candidate_size": 9},
        }])

    def test_rank_partials_calls_full_similarity_proof_blocked(self):
        class Targets:
            def body(self, address):
                return b"target", []

        rows = donor_converter.rank_partials(
            b"obj", Targets(), {"?near@@YAXXZ": {"00401000"}}, set(),
            functions=lambda raw: [("?near@@YAXXZ", b"candidate", [])],
            similarity=lambda *args: 1.0)

        self.assertEqual(rows[0]["status"], "proof_candidate")
        self.assertEqual(rows[0]["proof"], "advisory-reference-unproved")

    def test_attach_blockers_copies_matching_proof_errors(self):
        advisory = [{"symbol": "?near@@YAXXZ", "addr": "00401000"}]
        harvested = [{
            "symbol": "?near@@YAXXZ",
            "rejections": [{"addr": "00401000", "errors": ["unproven reference identity: ?data@@3HA"]}],
        }]

        donor_converter.attach_blockers(advisory, harvested)

        self.assertEqual(advisory[0]["blockers"], ["unproven reference identity: ?data@@3HA"])

    def test_learn_reference_identities_requires_external_consensus(self):
        rows = [{"symbol": "?parent@@YAXXZ", "rejections": [{
            "addr": "00401000",
            "errors": ["unproven reference identity: ?callee@@YAXXZ"],
            "references": [
                {"symbol": "?callee@@YAXXZ", "address": "00402000", "external": True},
                {"symbol": "?local@@3HA", "address": "00403000", "external": False},
            ],
        }]}]

        learned, conflicts = donor_converter.learn_reference_identities(rows, {})

        self.assertEqual(learned, {"?callee@@YAXXZ": ("00402000", 1)})
        self.assertEqual(conflicts, {})
        self.assertNotIn("?local@@3HA", learned)

    def test_learn_reference_identities_rejects_disagreement(self):
        rows = [{"symbol": "?parent@@YAXXZ", "rejections": [{
            "addr": "00401000",
            "errors": ["unproven reference identity: ?callee@@YAXXZ"],
            "references": [{"symbol": "?callee@@YAXXZ", "address": address, "external": True}],
        }]} for address in ("00402000", "00403000")]

        learned, conflicts = donor_converter.learn_reference_identities(rows, {})

        self.assertEqual(learned, {})
        self.assertEqual(conflicts, {"?callee@@YAXXZ": ["00402000", "00403000"]})

    def test_close_reference_identities_rechecks_after_learning(self):
        calls = []

        def harvest(raw, targets, names, bindings):
            calls.append(dict(bindings))
            if "?callee@@YAXXZ" in bindings:
                return [{"symbol": "?parent@@YAXXZ", "status": "inactive_exact", "addr": "00401000"}]
            return [{"symbol": "?parent@@YAXXZ", "status": "draft", "rejections": [{
                "addr": "00401000",
                "errors": ["unproven reference identity: ?callee@@YAXXZ"],
                "references": [{"symbol": "?callee@@YAXXZ", "address": "00402000", "external": True}],
            }]}]

        rows, learned, conflicts = donor_converter.close_reference_identities(
            b"obj", object(), {"?parent@@YAXXZ": {"00401000"}}, {}, harvest=harvest)

        self.assertEqual(rows[0]["status"], "inactive_exact")
        self.assertEqual(learned, [{"symbol": "?callee@@YAXXZ", "address": "00402000",
                                    "observations": 1, "round": 1}])
        self.assertEqual(conflicts, {})
        self.assertEqual(len(calls), 2)


if __name__ == "__main__":
    unittest.main()
