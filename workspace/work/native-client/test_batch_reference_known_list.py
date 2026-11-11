import json
from pathlib import Path
import tempfile
import unittest
from batch_reference_bind import read_known_list


class KnownListTest(unittest.TestCase):
    def test_large_list_and_spaces_are_preserved(self):
        paths = ['C:/Project With Spaces/receipt-%04d.json' % n for n in range(2000)]
        with tempfile.TemporaryDirectory() as tmp:
            p = Path(tmp) / 'known.json'
            p.write_text(json.dumps(paths), encoding='utf-8')
            self.assertEqual(read_known_list(p), list(map(Path, paths)))
            p.write_text(json.dumps(['ok', 2]), encoding='utf-8')
            with self.assertRaises(ValueError):
                read_known_list(p)

if __name__ == '__main__':
    unittest.main()
