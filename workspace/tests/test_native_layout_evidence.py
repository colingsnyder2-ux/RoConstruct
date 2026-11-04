import importlib.util
from pathlib import Path
import tempfile
import unittest
import struct
from unittest.mock import patch

PATH = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_layout_evidence.py'
spec = importlib.util.spec_from_file_location('layout_evidence', PATH)
layout = importlib.util.module_from_spec(spec)
spec.loader.exec_module(layout)


class LayoutEvidenceTests(unittest.TestCase):
    def test_alias_adjustment_width_and_return(self):
        # mov esi,ecx; add esi,10h; mov eax,[esi+4]; mov byte ptr [ecx+8],1; ret 4
        evidence = layout.extract(bytes.fromhex('8bf183c6108b4604c6410801c20400'))
        self.assertEqual([(r['this_offset'], r['width'], r['kind']) for r in evidence['accesses']],
                         [(20, 4, 'read'), (8, 1, 'write')])
        self.assertEqual(evidence['returns'][0]['stack_pop'], 4)

    def test_loaded_pointer_not_this_and_partial_clobber(self):
        evidence = layout.extract(bytes.fromhex('8b41088b5010b1018b4114'))
        self.assertEqual([r['this_offset'] for r in evidence['accesses']], [8])
        self.assertEqual(len(evidence['uncertain']), 1)
        self.assertEqual(evidence['derived_accesses'][0]['pointer_origin'], ('load', 0, 8))
        self.assertEqual(evidence['derived_accesses'][0]['displacement'], 16)

    def test_branch_merge_and_call_invalidate_aliases(self):
        self.assertEqual(layout.extract(bytes.fromhex('75008b4104'))['accesses'][0]['this_offset'], 4)
        # One path overwrites ecx; joined access must remain uncertain.
        self.assertEqual(layout.extract(bytes.fromhex('75028bc88b4104'))['accesses'], [])
        evidence = layout.extract(bytes.fromhex('8bf1e8000000008b41048b4608'))
        self.assertEqual([r['this_offset'] for r in evidence['accesses']], [8])

    def test_loop_merge_drops_changing_alias(self):
        evidence = layout.extract(bytes.fromhex('8b410483c10475f8c3'))
        self.assertEqual(evidence['accesses'], [])

    def test_index_and_relocation_remain_uncertain(self):
        self.assertEqual(layout.extract(bytes.fromhex('8b448104'))['accesses'], [])
        self.assertEqual(layout.extract(bytes.fromhex('8b8100010000'), relocs=[2])['accesses'], [])

    def test_index_keeps_base_evidence_without_field_claim(self):
        result = layout.extract(bytes.fromhex('8b448104'))
        self.assertEqual(result['indexed_accesses'][0]['base_origin'], 0)
        self.assertEqual(result['indexed_accesses'][0]['scale'], 4)
        self.assertEqual(result['accesses'], [])

    def test_segment_context_is_not_this_field(self):
        result = layout.extract(bytes.fromhex('648b010f'))
        self.assertEqual(result['context_accesses'][0]['segment'], 'fs')
        self.assertEqual(result['accesses'], [])
        self.assertTrue(any(r['reason'] == 'undecoded trailing bytes' for r in result['uncertain']))

    def test_pointer_aliases_cleared_at_calls(self):
        result = layout.extract(bytes.fromhex('8b4108e8000000008b5010'))
        self.assertEqual(result['derived_accesses'][0]['pointer_origin'], ('call_result_bits', 3))
        self.assertEqual(result['accesses'][0]['this_offset'], 8)

    def test_frame_spill_and_reload_recovers_this(self):
        # push ebp; mov ebp,esp; sub esp,8; spill ecx; clobber ecx; reload; read field
        result = layout.extract(bytes.fromhex('558bec83ec08894df831c98b45f88b500c'))
        self.assertEqual(result['accesses'][-1]['this_offset'], 12)
        self.assertEqual(result['stack_accesses'][-1]['entry_sp_offset'], -12)

    def test_esp_adjustments_share_slot_coordinates(self):
        result = layout.extract(bytes.fromhex('83ec08890c2483ec048b4424048b500c'))
        self.assertEqual(result['accesses'][-1]['this_offset'], 12)

    def test_push_pop_recovers_alias(self):
        result = layout.extract(bytes.fromhex('5131c95e8b4604'))
        self.assertEqual(result['accesses'][-1]['this_offset'], 4)

    def test_partial_stack_write_invalidates_full_spill(self):
        result = layout.extract(bytes.fromhex('83ec08890c24c6442401018b04248b500c'))
        self.assertEqual(result['accesses'], [])
        self.assertEqual(result['derived_accesses'][-1]['pointer_origin'][0], 'stack_load')

    def test_unknown_memory_write_invalidates_spills(self):
        result = layout.extract(bytes.fromhex('83ec08890c2489128b04248b500c'))
        self.assertEqual(result['accesses'], [])

    def test_call_invalidates_spill_but_preserves_frame_coordinate(self):
        result = layout.extract(bytes.fromhex('558bec83ec08894df8e8000000008b45f88b500c'))
        self.assertEqual(result['accesses'], [])
        self.assertEqual(result['derived_accesses'][-1]['pointer_origin'][0], 'stack_load')
        self.assertEqual(result['stack_accesses'][-1]['entry_sp_offset'], -12)

    def test_disagreeing_branch_spills_do_not_restore_this(self):
        # Only one incoming path writes this into slot.
        result = layout.extract(bytes.fromhex('83ec087503890c248b04248b500c'))
        self.assertEqual(result['accesses'], [])

    def test_stack_address_alias_write_invalidates_slot(self):
        result = layout.extract(bytes.fromhex('83ec08890c248d1424c602008b04248b500c'))
        self.assertEqual(result['accesses'], [])

    def test_dynamic_esp_cannot_restore_known_spill(self):
        result = layout.extract(bytes.fromhex('83ec08890c2483e4f08b04248b500c'))
        self.assertEqual(result['accesses'], [])

    def test_indexed_load_origin_remains_non_this(self):
        result = layout.extract(bytes.fromhex('8b4481048b5010'))
        self.assertEqual(result['accesses'], [])
        self.assertEqual(result['derived_accesses'][0]['pointer_origin'][0], 'indexed_load')

    def test_repeated_calls_group_without_resolving_abi(self):
        result = layout.extract(bytes.fromhex('e800000000e8fbffffff'))
        groups = layout.review_groups(result)
        self.assertEqual(len(groups), 1)
        self.assertEqual(groups[0]['sites'], [0, 5])
        self.assertIn('ABI not analyzed', groups[0]['evidence']['reason'])

    def test_indirect_calls_never_collapsed_to_one_callee(self):
        result = layout.extract(bytes.fromhex('ffd0ffd0'))
        self.assertEqual(len(layout.review_groups(result)), 2)

    def test_call_binding_requires_matching_shape(self):
        raw = struct.pack('<IIH', 1, 0, 20)
        section = (None, 0, 0, 0, 0, 0, 0, 1)
        code = bytes.fromhex('e800000000')
        index = ([section], {0: ('?callee@@',)}, {'?caller@@': (0, 0)}, {})
        with patch.object(layout.match, '_coff_data_index', return_value=index):
            with patch.object(layout.match, 'exact_match', return_value=True):
                result = layout.call_obligations(raw, '?caller@@', code, [1], code, [], 4096)
                self.assertEqual(result['groups'][0]['candidate_rel32_symbol'], '?callee@@')
                self.assertEqual(result['groups'][0]['expected_original_destination'], '0x1005')
            with patch.object(layout.match, 'exact_match', return_value=False):
                result = layout.call_obligations(raw, '?caller@@', code, [1], code, [], 4096)
                self.assertIsNone(result['groups'][0]['candidate_rel32_symbol'])

    def test_difference_is_not_layout_failure(self):
        result = layout.compare(layout.extract(bytes.fromhex('8b4104c3')), layout.extract(bytes.fromhex('8b4108c3')))
        self.assertEqual(result['target_only'][0]['this_offset'], 4)
        self.assertEqual(result['candidate_only'][0]['this_offset'], 8)
        self.assertTrue(result['observed_stack_pops_equal'])

    def test_header_assertions_are_uncompiled(self):
        with tempfile.TemporaryDirectory() as folder:
            header = Path(folder) / 'test.h'
            header.write_text('typedef char Size[sizeof(Foo) == 0x20 ? 1 : -1];\nstatic_assert(offsetof(Foo, member) == 12);')
            rows = layout.header_assertions(header)
            self.assertEqual([r['expected'] for r in rows], [32, 12])
            self.assertEqual(rows[1]['line'], 2)
            self.assertEqual(rows[0]['status'], 'source_assertion_uncompiled')


if __name__ == '__main__':
    unittest.main()
