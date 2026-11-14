import pytest

from roc import match


def test_metrics_distinguish_alignment_from_positional_agreement():
    metrics = match.comparison_metrics(b'abcdef', [], b'bcdefa', [])
    assert metrics['fuzzy_percent'] == pytest.approx(83.333333)
    assert metrics['positional_percent'] == 0
    assert metrics['unmasked_differences'] == 6
    assert metrics['length_delta'] == 0


def test_metrics_count_missing_tail_bytes():
    metrics = match.comparison_metrics(b'abcde', [], b'abc', [])
    assert metrics['positional_percent'] == 60
    assert metrics['unmasked_differences'] == 2
    assert metrics['mismatch_offsets'] == [3, 4]
    assert metrics['length_delta'] == -2


def test_metrics_expose_relocation_masking_and_missing_relocations():
    metrics = match.comparison_metrics(b'A1234Z', [1], b'A0000Y', [])
    assert metrics['compared_unmasked_bytes'] == 2
    assert metrics['unmasked_differences'] == 1
    assert metrics['positional_percent'] == 50
    assert metrics['missing_relocations'] == [1]
    assert metrics['masked_bytes'] == 4


def test_metrics_keep_fractional_scores_and_bound_offset_output():
    metrics = match.comparison_metrics(b'a' * 301, [], b'a' * 300 + b'b', [])
    assert metrics['fuzzy_percent'] == pytest.approx(99.667774)
    changed = match.comparison_metrics(b'a' * 100, [], b'b' * 100, [])
    assert len(changed['mismatch_offsets']) == 32
    assert changed['mismatch_offsets_truncated'] is True
