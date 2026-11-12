import json
from pathlib import Path
from tempfile import TemporaryDirectory
import unittest
from unittest.mock import patch

from roc.draft_getter import getter_contract, prove


class GetterContractTests(unittest.TestCase):
    def test_extracts_direct_getter_contract(self):
        contract = getter_contract({
            "method_source": "std::string TextDisplay::getLabel() const {return label;}",
            "method": "RBX::TextDisplay::getLabel() const",
        })
        self.assertEqual(contract["owner"], "TextDisplay")
        self.assertEqual(contract["name"], "getLabel")
        self.assertEqual(contract["member"], "label")
        self.assertEqual(contract["return_type"], "std::string")
        self.assertEqual(contract["namespace"], "RBX")
        self.assertTrue(contract["signature"])
        self.assertIn(b"namespace RBX", contract["append"])

    def test_rejects_non_getter_or_mismatched_declaration(self):
        method = "std::string TextDisplay::getLabel() const {return label;}"
        for source, identity in (
            ("std::string TextDisplay::getLabel() const {if (ready) return label; return {};}", "RBX::TextDisplay::getLabel() const"),
            (method + "\nint TextDisplay::other() const {return 1;}", "RBX::TextDisplay::getLabel() const"),
            ("std::string TextDisplay::getLabel() const {label = other; return label;}", "RBX::TextDisplay::getLabel() const"),
            ("long TextDisplay::getLabel() const {return label;}", "RBX::TextDisplay::getLabel() const"),
            (method, "RBX::TextDisplay::different() const"),
        ):
            with self.subTest(source=source, identity=identity):
                with self.assertRaises(ValueError):
                    getter_contract({"method_source": source, "method": identity})


class ProveCleanupTests(unittest.TestCase):
    def test_result_write_failure_still_releases_integration_lock(self):
        with TemporaryDirectory() as temp:
            root = Path(temp)
            target = "rebuild/2008-06/native-classes/TextDisplay.cpp"
            source = root / target
            source.parent.mkdir(parents=True)
            source.write_bytes(b"canonical source")
            review_dir = root / "work/draft-merger/reviews"
            review_dir.mkdir(parents=True)
            review_file = review_dir / "review.json"
            review_file.write_text(json.dumps({
                "method_source": "std::string TextDisplay::getLabel() const {return label;}",
                "method": "RBX::TextDisplay::getLabel() const",
                "target": target,
                "address": "00401000",
                "evidence": {
                    "canonical_source": {"sha256": "0" * 64},
                    "header": {"path": "unused.h", "sha256": "0" * 64},
                },
            }))

            def integration_lock(_root, action, token=None):
                return {"token": "test-token"} if action == "start" else {}

            with patch("roc.draft_getter.native_drafts.integration_lock", side_effect=integration_lock) as lock, \
                    patch("roc.draft_getter.native_drafts.atomic", side_effect=RuntimeError("result-write-error")):
                with self.assertRaisesRegex(RuntimeError, "result-write-error"):
                    prove(root, review_file)

        self.assertEqual([call.args[1] for call in lock.call_args_list], ["start", "release"])


if __name__ == "__main__":
    unittest.main()
