import json
import tempfile
import unittest
from pathlib import Path

from inventory import collect


class InventoryTest(unittest.TestCase):
    def test_receipts_track_latest_source_and_missing_inputs(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            route = root / 'work/donorfree-route'
            (route / 'linkexp').mkdir(parents=True)
            (route / 'renamed').mkdir()
            source = root / 'source.cpp'
            source.write_text('old')
            receipt = root / 'result.json'
            receipt.write_text(json.dumps([{'source': str(source), 'status': 'complete'}]))
            (route / 'linkexp/qt_results.txt').write_text(str(receipt) + '\n' + str(root / 'missing.json'))
            (route / 'renamed/results.json').write_text(json.dumps([{'object': 'x.obj'}, {'object': 'y.obj'}]))
            first = collect(root)
            source.write_text('new')
            second = collect(root)
            self.assertEqual(first['converted_object_entries'], 2)
            self.assertEqual(first['missing_receipts'], [str(root / 'missing.json')])
            self.assertNotEqual(first['source_candidates'][0]['sha256'], second['source_candidates'][0]['sha256'])


if __name__ == '__main__':
    unittest.main()
