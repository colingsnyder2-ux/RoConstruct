"""Ranking equivalence and tie-only alignment. No client/compiler required."""
import sys
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from roc import match, server


class FingerprintRankTests(unittest.TestCase):
    def test_exact_tie_uses_matching_data_single_and_batch(self):
        code = b'\x90\xc3'
        funcs = [('wrong', code, []), ('right', code, [])]
        for batch in (False, True):
            with patch.object(match, 'target', return_value=(code, [], {})), \
                 patch.object(match, 'compile_text', return_value=b'obj'), \
                 patch.object(match, 'coff_functions', return_value=funcs), \
                 patch.object(match, 'coff_data_refs', side_effect=lambda obj, name: name), \
                 patch.object(match, 'data_check', side_effect=[([], ['wrong data']), ([(123, 4)], [])]):
                if batch:
                    self.assertEqual(server.check_many_text('C', ['00401000'], 'source'),
                                     [('00401000', 100, [(123, 4)])])
                else:
                    result = match.check_text('C', '00401000', 'source', include_diagnosis=True)
                    self.assertEqual(result[:2], (100, 'right'))
                    self.assertEqual(result[3:], ([(123, 4)], {}))

    def check(self, code, funcs, bad=(), relocs=(), diagnosis=False):
        with patch.object(match, 'target', return_value=(code, list(relocs), {})), \
             patch.object(match, 'compile_text', return_value=b'obj'), \
             patch.object(match, 'coff_functions', return_value=funcs), \
             patch.object(match, 'diff', return_value='diff'), \
             patch.object(match, 'coff_data_refs', return_value=[]), \
             patch.object(match, 'data_check', return_value=([(123, 4)], list(bad))), \
             patch.object(match, 'align_insns', wraps=match.align_insns) as aligned:
            result = match.check_text('C', '00401000', 'source', include_diagnosis=diagnosis)
            return result, aligned.call_count

    def test_exact_order_and_data(self):
        code = b'\x90\xc3'
        funcs = [('loser', b'\xcc\xc3', []), ('first', code, []), ('second', code, [])]
        for bad in ((), ('constant differs',)):
            result, calls = self.check(code, funcs, bad)
            self.assertEqual(result[:2], (99 if bad else 100, 'first'))
            self.assertEqual(calls, 0)
            self.assertEqual(result[3], [(123, 4)])

    def test_fuzzy_matches_exhaustive_ranking(self):
        funcs = [('ret', b'\xc3', []), ('nop', b'\x90\xc3', []),
                 ('push', b'\x50\xc3', []), ('pop', b'\x58\xc3', []),
                 ('long', b'\x55\x8b\xec\x90\xc9\xc3', [])]
        for code in (b'\x51\xc3', b'\x90\x90\xc3', b'\x55\x8b\xec\xc9\xc3'):
            expected = max(funcs, key=lambda f: match.rank_candidate(code, [], f[1], f[2]))
            highest = max(match.score(code, [], f[1], f[2]) for f in funcs)
            ties = sum(match.score(code, [], f[1], f[2]) == highest for f in funcs)
            result, calls = self.check(code, funcs)
            self.assertEqual(result[:2], (highest, expected[0]))
            self.assertEqual(calls, ties)

    def test_empty_object(self):
        result, calls = self.check(b'\xc3', [])
        self.assertEqual(result[:2], (0, None))
        self.assertEqual(calls, 0)

    def test_relocations_keep_exact_and_first_tie(self):
        code = b'\xe8\x01\x02\x03\x04\xc3'
        funcs = [('first', b'\xe8\x11\x22\x33\x44\xc3', [1]),
                 ('second', b'\xe8\x55\x66\x77\x88\xc3', [1])]
        result, calls = self.check(code, funcs, relocs=[1], diagnosis=True)
        self.assertEqual(result[:2], (100, 'first'))
        self.assertEqual(result[4], {})
        self.assertEqual(calls, 0)

    def test_diagnosis_uses_same_fuzzy_winner(self):
        code = b'\x51\xc3'
        funcs = [('push', b'\x50\xc3', []), ('nop', b'\x90\xc3', []),
                 ('long', b'\x55\x8b\xec\xc9\xc3', [])]
        best = max(funcs, key=lambda f: match.rank_candidate(code, [], f[1], f[2]))
        result, _ = self.check(code, funcs, diagnosis=True)
        self.assertEqual(result[1], best[0])
        self.assertEqual(result[4], match.diagnose(code, [], best[1], best[2]))


if __name__ == '__main__':
    unittest.main()
