"""Byte-identical candidates must be distinguished by referenced data."""
from unittest.mock import patch
from benchmarks.shared_mfc_verify import verify


def test_exact_tie_checks_data_before_selecting_symbol():
    with patch('benchmarks.shared_mfc_verify.match.coff_functions', return_value=[
        ('wrong_class', b'code', []), ('right_class', b'code', [])
    ]), patch('benchmarks.shared_mfc_verify.match.score', return_value=100), \
        patch('benchmarks.shared_mfc_verify.match.coff_data_refs', side_effect=lambda o, s: s), \
        patch('benchmarks.shared_mfc_verify.match.data_check',
              side_effect=[([], ['wrong RTTI']), ([], [])]):
        result = verify('client', 'addr', b'code', [], b'object')
    assert result['symbol'] == 'right_class'
    assert result['score'] == 100
    assert result['data_errors'] == []


def test_all_exact_ties_with_bad_data_remain_partial():
    with patch('benchmarks.shared_mfc_verify.match.coff_functions', return_value=[
        ('class_a', b'code', []), ('class_b', b'code', [])
    ]), patch('benchmarks.shared_mfc_verify.match.score', return_value=100), \
        patch('benchmarks.shared_mfc_verify.match.coff_data_refs', return_value=[]), \
        patch('benchmarks.shared_mfc_verify.match.data_check', return_value=([], ['bad data'])):
        result = verify('client', 'addr', b'code', [], b'object')
    assert result['score'] == 99 and result['code_score'] == 100
    assert result['data_errors'] == ['bad data']
