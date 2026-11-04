"""Reviewed tables must never become mining targets or website functions."""
import hashlib
import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from roc import agent, analyze, match, progress, server


class FunctionDataTests(unittest.TestCase):
    def test_agent_does_not_treat_missing_disassembly_as_data(self):
        self.assertFalse(agent.is_data_table({"size": 2_000_000, "kind": "code"}))
        self.assertTrue(agent.is_data_table({"size": 4096, "kind": "data"}))

    def test_scoped_publish_preserves_other_clients(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "docs/data").mkdir(parents=True)
            old = dict(name="other", started=True, **progress.summarize([[1, 42, 100]]))
            (root / "docs/progress.json").write_text(json.dumps({"clients": [old]}))
            (root / "docs/data/other.json").write_text("unchanged")
            with patch.object(progress, "ROOT", root), patch.object(progress, "DOCS", root / "docs"), \
                 patch.object(progress.clients, "load", return_value={
                     "other": {"compiler": "test"}, "2008-06": {"compiler": "test"}}), \
                 patch.object(progress, "library_meta", return_value={}), \
                 patch.object(progress, "source_links", return_value={}), \
                 patch.object(progress, "head_commit", return_value=("test", "test")):
                result = progress.build(remote={"scores": {}, "leaderboard": []}, client="2008-06")
            self.assertEqual(next(r for r in result["clients"] if r["name"] == "other"), old)
            self.assertEqual((root / "docs/data/other.json").read_text(), "unchanged")

    def test_data_is_not_disassembled_or_promoted_by_old_exact(self):
        va = 0x401000
        # Fake CALL in a table must not seed the apparent target at va+8.
        code = bytes.fromhex("c3") + b"\xcc" * 15 + bytes.fromhex("e8f3ffffffcccccc")
        rows = analyze.find_functions(code, va, {va, va + 16}, [],
                                      proven=[(va + 16, 8)], keep={va, va + 16},
                                      data=[(va + 16, 8)])
        analyze.mark_matched_code(rows, {"00401010"})
        self.assertEqual([(r["addr"], r["size"], r["kind"]) for r in rows],
                         [("00401000", 1, "code"), ("00401010", 8, "data")])

    def test_review_is_scoped_and_hash_checked(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "research").mkdir()
            (root / "research/function-data.json").write_text(json.dumps({"2008-06": [
                {"addr": "00401000", "size": 4, "sha256": hashlib.sha256(b"data").hexdigest()}]}))
            with patch.object(analyze, "ROOT", root):
                self.assertEqual(analyze.known_data("2008-06", lambda a, n: b"data"), [(0x401000, 4)])
                self.assertEqual(analyze.known_data("2009-06", lambda a, n: b"data"), [])
                with self.assertRaisesRegex(ValueError, "Reviewed data bytes changed"):
                    analyze.known_data("2008-06", lambda a, n: b"nope")

    def test_direct_target_rejects_data_before_loading_binary(self):
        with patch.object(match, "_functions", return_value={"00401000": {"kind": "data"}}), \
             patch.object(match, "_image") as image:
            with self.assertRaisesRegex(match.CompileError, "reviewed data, not a function"):
                match.target("2008-06", "00401000")
            image.assert_not_called()

    def test_reseed_prunes_old_source_and_lease_progress_excludes_table(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            work = root / "work/2008-06"
            work.mkdir(parents=True)
            rows = [{"addr": "00401000", "size": 8, "kind": "code", "unit": "Real"},
                    {"addr": "00402000", "size": 4096, "kind": "code", "unit": "FakeOnly"}]
            inventory = work / "functions.jsonl"
            inventory.write_text("".join(json.dumps(r) + "\n" for r in rows))
            with patch.object(server, "ROOT", root):
                store = server.Store(":memory:", 600)
                try:
                    store.seed("2008-06")
                    store.submit("2008-06", "00402000", "test", 100, "fake source")
                    rows[1]["kind"] = "data"
                    inventory.write_text("".join(json.dumps(r) + "\n" for r in rows))
                    store.seed("2008-06")
                    self.assertIsNone(store.best("2008-06", "00402000"))
                    self.assertIsNone(store.lease("test", "worker", ["2008-06"], "", 5000,
                                                 targets=[{"client": "2008-06", "addr": "00402000"}]))
                    with self.assertRaisesRegex(ValueError, "unknown function"):
                        store.submit("2008-06", "00402000", "test", 100, "fake source")
                finally:
                    store.db.close()
            with patch.object(progress, "ROOT", root), patch.object(progress, "DOCS", root / "docs"), \
                 patch.object(progress.clients, "load", return_value={"2008-06": {"compiler": "test"}}), \
                 patch.object(progress, "library_meta", return_value={}), \
                 patch.object(progress, "source_links", return_value={}), \
                 patch.object(progress, "head_commit", return_value=("test", "test")), \
                 patch.object(progress, "landmarks", return_value=[]):
                result = progress.build(remote={"scores": {"2008-06": {"00402000": 100}}, "leaderboard": []})
            row = result["clients"][0]
            self.assertEqual((row["functions"], row["bytes"], row["matched_bytes"]), (1, 8, 0))
            site = json.loads((root / "docs/data/2008-06.json").read_text())
            self.assertEqual(site["units"], ["Real"])
            self.assertEqual([r[0] for r in site["funcs"]], [0x401000])


if __name__ == "__main__":
    unittest.main()
