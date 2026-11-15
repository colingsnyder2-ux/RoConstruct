from roc.native_autopilot_search import rank_bodies


def test_similarity_ranks_instruction_shape_and_keeps_address_differences_visible():
    target = bytes.fromhex('b8 78563412 83c001 c3')
    candidates = [('other', bytes.fromhex('33c0 90 90 90 90 90 90 c3'), []),
                  ('same_shape', bytes.fromhex('b8 00000000 83c001 c3'), [1])]
    rows = rank_bodies(target, [], candidates)
    assert rows[0]['symbol'] == 'same_shape'
    assert rows[0]['metrics']['positional_percent'] == 100.0
    assert rows[0]['metrics']['raw_positional_percent'] < 100.0
    assert rows[0]['shape_percent'] == 100.0
    assert rows[0]['verified'] is False


def test_identical_template_bodies_remain_multiple_candidates():
    body = bytes.fromhex('8b4104c3')
    rows = rank_bodies(body, [], [('A', body, []), ('B', body, [])])
    assert len(rows) == 2
    assert all(row['ambiguous_best'] for row in rows)
