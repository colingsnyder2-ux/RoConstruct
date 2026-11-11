import tempfile
import unittest
from pathlib import Path

from roc.delink import _allowed_hits


class NativeDelinkFilterTests(unittest.TestCase):
    def test_allowlist_restricts_symbol_to_verified_target(self):
        with tempfile.TemporaryDirectory() as folder:
            obj = Path(folder) / "family.obj"
            allowed = {str(obj.resolve()): {"?body": 0x401000}}
            self.assertEqual(_allowed_hits(allowed, obj, "?body", [0x401000, 0x402000]), [0x401000])

    def test_unlisted_symbol_or_object_has_no_hits(self):
        with tempfile.TemporaryDirectory() as folder:
            obj = Path(folder) / "family.obj"
            allowed = {str(obj.resolve()): {"?body": 0x401000}}
            self.assertEqual(_allowed_hits(allowed, obj, "?other", [0x401000]), [])
            self.assertEqual(_allowed_hits(allowed, obj.with_name("other.obj"), "?body", [0x401000]), [])

    def test_none_preserves_all_candidate_hits(self):
        hits = [0x401000, 0x402000]
        self.assertIs(_allowed_hits(None, "family.obj", "?body", hits), hits)


if __name__ == "__main__":
    unittest.main()
