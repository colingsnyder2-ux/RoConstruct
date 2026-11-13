import tempfile
import unittest
from pathlib import Path

from roc import donor_converter


class DonorConverterTests(unittest.TestCase):
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
            "repair_candidates": 0, "proof_candidates": 0})
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
            similarity=lambda *args: .91)

        self.assertEqual(rows, [{
            "symbol": "?near@@YAXXZ", "addr": "00401000", "similarity": .91,
            "status": "repair_candidate", "proof": "advisory-not-exact",
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


if __name__ == "__main__":
    unittest.main()
