import unittest
from pathlib import Path

import function_map

ROOT = Path(__file__).resolve().parents[3]
HAVE = all((ROOT / p).exists() for p in ('clients/2008-06/Roblox.exe', 'work/2008-06/functions.jsonl', 'docs/data/2008-06.json',
                                          'local/references/mobile-index/symbols.sqlite'))

FLOORS = {'S': 0.90, 'U': 0.85, 'D': 0.80, 'K': 0.65, 'B': 0.80, 'H': 0.90}      # held-out accuracy of each inference rule
CEILING = 0.08                                                          # share of code bytes with no file guess


@unittest.skipUnless(HAVE, 'needs the 2008 exe, its function list and the iOS debug-map index')
class MapRegressionTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        import contextlib
        import io
        with contextlib.redirect_stdout(io.StringIO()):
            function_map.main(True)
        cls.metrics = function_map.main.metrics

    def test_inference_rules_stay_accurate(self):
        for tier, floor in FLOORS.items():
            got = self.metrics['holdout'].get(tier)
            self.assertIsNotNone(got, 'no held-out cases for %s' % tier)
            self.assertGreaterEqual(got, floor, 'rule %s fell to %.0f%%' % (tier, 100 * got))

    def test_unassigned_share_does_not_grow(self):
        self.assertLessEqual(self.metrics['unassigned_share'], CEILING)


if __name__ == '__main__':
    unittest.main()
