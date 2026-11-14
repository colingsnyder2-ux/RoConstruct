import unittest
from collections import defaultdict
import json
import struct
from types import SimpleNamespace
from pathlib import Path
from tempfile import TemporaryDirectory
from unittest.mock import patch

from roc.draft_native import claims_from, closed_function_targets, compile_review_blockers, freeze_headers, numeric_literal_targets, original_function, reviewed_call_targets, verified_reference_evidence
from roc.draft_merger import content_hash


class ClaimsFromTests(unittest.TestCase):
    def test_reference_verifier_falls_back_to_full_data_audit(self):
        binder = SimpleNamespace(verify=lambda *_args: (_ for _ in ()).throw(KeyError('local guard')))
        original = SimpleNamespace()
        with TemporaryDirectory() as temp:
            obj = Path(temp) / 'unit.obj'
            obj.write_bytes(b'object')
            with patch('roc.match.coff_functions', return_value=[('?method', b'code', {1})]), \
                    patch('roc.match.target', return_value=(b'target', {1}, None)), \
                    patch('roc.native_bulk.Targets') as targets, \
                    patch('roc.native_bulk.audit_references', return_value=([{'symbol': 'guard'}], [])):
                result = verified_reference_evidence(original, binder, obj,
                    [('?method', 0x401000)], {'?callee': 0x402000}, {'?method': 0x401000})
        self.assertEqual(result[0]['references'], [{'symbol': 'guard'}])
        self.assertEqual(result[0]['local_eh'], [])
        targets.assert_called_once_with('2008-06')

    def test_non_function_target_is_a_blocker_not_process_exit(self):
        with patch('roc.draft_native.match.target', side_effect=SystemExit('no function starts there')):
            target, blocker = original_function(0x826bfc)
        self.assertIsNone(target)
        self.assertEqual(blocker, 'no function starts there')

    def test_external_closure_requires_unique_independent_original_identity(self):
        anchor = dict(symbol='?Good@@YAXXZ', address='00401000', evidence='unique-body',
                      body_exact=True, function_start=True)
        records = [anchor, dict(anchor, symbol='?Voted@@YAXXZ', evidence='vote-selected-body'),
                   dict(anchor, symbol='?NotExact@@YAXXZ', body_exact=False),
                   dict(anchor, symbol='?Ambiguous@@YAXXZ'),
                   dict(anchor, symbol='?Ambiguous@@YAXXZ', address='00402000')]
        self.assertEqual(closed_function_targets(records), {'?Good@@YAXXZ': 0x401000})

    def test_extracts_nested_symbol_address_records(self):
        claims = claims_from({
            "records": [
                {"symbol": "?First@@YAXXZ", "address": "00401000"},
                {"nested": {"name": "_Second", "addr": 0x401234}},
            ]
        })
        self.assertEqual(claims["?First@@YAXXZ"], {0x401000})
        self.assertEqual(claims["_Second"], {0x401234})

    def test_ignores_invalid_and_out_of_range_addresses(self):
        claims = claims_from([
            {"symbol": "?BadHex", "address": "not-hex"},
            {"symbol": "?TooLow", "address": "003fffff"},
            {"symbol": "?TooHigh", "address": "01000000"},
            {"symbol": "?Bool", "address": True},
            {"symbol": "?Float", "address": float(0x401000)},
        ])
        self.assertEqual(dict(claims), {})

    def test_duplicates_collapse_into_sets_and_existing_mapping_is_mutated(self):
        found = defaultdict(set)
        result = claims_from([
            {"symbol": "?Same", "address": "00401000"},
            {"symbol": "?Same", "address": 0x401000},
            {"symbol": "?Same", "address": "00401001"},
        ], found)
        self.assertIs(result, found)
        self.assertEqual(found["?Same"], {0x401000, 0x401001})

    def test_command_fields_are_inert(self):
        claims = claims_from({
            "command": "raise RuntimeError('must not run')",
            "script": "__import__('os').remove('important')",
            "symbol": "?Safe",
            "address": "00401000",
        })
        self.assertEqual(claims["?Safe"], {0x401000})
        self.assertNotIn("command", claims)
        self.assertNotIn("script", claims)


class CompileReviewBlockerTests(unittest.TestCase):
    def test_ordinary_angle_header_is_allowed(self):
        self.assertEqual(compile_review_blockers(b"#include <vector>\n"), [])

    def test_absolute_unc_computed_import_and_alias_are_blocked(self):
        for source in (
            '#include "C:/outside.h"',
            '#include "\\\\server\\share\\outside.h"',
            '#include HEADER_NAME',
            '#import "outside.tlb"',
            '#pragma include_alias("old.h", "new.h")',
        ):
            with self.subTest(source=source):
                self.assertTrue(compile_review_blockers(source.encode()))

    def test_line_spliced_directives_are_checked(self):
        self.assertTrue(compile_review_blockers(b"#inc\\\nlude HEADER_NAME\n"))
        self.assertTrue(compile_review_blockers(b"#pragma include_\\\nalias(foo, bar)\n"))

    def test_relative_parent_include_requires_existing_canonical_file_within_root(self):
        with TemporaryDirectory() as temp:
            root = Path(temp)
            source_path = "src/native.cpp"
            (root / "shared.h").write_text("// canonical")
            inside = compile_review_blockers(b'#include "../shared.h"', root, source_path)
            outside = compile_review_blockers(b'#include "../../outside.h"', root, source_path)
            missing = compile_review_blockers(b'#include "../missing.h"', root, source_path)
            self.assertEqual(inside, [])
            self.assertTrue(outside)
            self.assertTrue(missing)

    def test_comments_do_not_trigger(self):
        source = b"// #include C:/outside.h\n/* #import outside */\n// #pragma include_alias(x,y)\n#include <vector>\n"
        self.assertEqual(compile_review_blockers(source), [])

    def test_mismatched_include_delimiters_are_blocked(self):
        self.assertTrue(compile_review_blockers(b'#include <foo"\n'))
        self.assertTrue(compile_review_blockers(b'#include "foo>\n'))


class FreezeHeadersTests(unittest.TestCase):
    def test_copies_inventory_binds_hashes_and_keeps_snapshots_immutable(self):
        with TemporaryDirectory() as temp:
            root = Path(temp)
            source = root / "rebuild/2008-06/native-classes/A.cpp"
            header = root / "rebuild/2008-06/native-headers/a/A.h"
            source.parent.mkdir(parents=True)
            header.parent.mkdir(parents=True)
            source.write_bytes(b"source-v1\x00")
            header.write_bytes(b"header-v1\x00")
            output = root / "work/native/run"
            output.mkdir(parents=True)

            with patch("roc.input_reuse.ensure_link") as ensure_link:
                first, first_inventory = freeze_headers(root, output)
                source.write_bytes(b"source-v2")
                header.write_bytes(b"header-v2")
                second, second_inventory = freeze_headers(root, output)

            source_key = "rebuild/2008-06/native-classes/A.cpp"
            header_key = "rebuild/2008-06/native-headers/a/A.h"
            self.assertEqual((first / source_key).read_bytes(), b"source-v1\x00")
            self.assertEqual((first / header_key).read_bytes(), b"header-v1\x00")
            self.assertEqual((second / source_key).read_bytes(), b"source-v2")
            self.assertEqual((second / header_key).read_bytes(), b"header-v2")
            self.assertEqual(first_inventory[source_key], content_hash(b"source-v1\x00"))
            self.assertEqual(first_inventory[header_key], content_hash(b"header-v1\x00"))
            self.assertEqual(second_inventory[source_key], content_hash(b"source-v2"))
            self.assertEqual(second_inventory[header_key], content_hash(b"header-v2"))
            self.assertEqual(json.loads((first / "inventory.json").read_text()), first_inventory)
            self.assertEqual(json.loads((second / "inventory.json").read_text()), second_inventory)
            self.assertNotEqual(first, second)
            self.assertEqual(ensure_link.call_count, 2)


if __name__ == "__main__":
    unittest.main()


class NumericLiteralTargetTests(unittest.TestCase):
    def test_call_inference_requires_local_identity_and_executable_target(self):
        with TemporaryDirectory() as temp:
            obj = Path(temp) / 'unit.obj'
            raw = bytearray(100)
            raw[20:26] = b'\xe8\x00\x00\x00\x00\xc3'
            struct.pack_into('<IIH', raw, 60, 1, 0, 20)
            obj.write_bytes(raw)
            sections = [None, (0, 0, 0, 6, 20, 60, 0, 1)]
            target = b'\xe8' + struct.pack('<i', 0x402000 - (0x401000 + 5)) + b'\xc3'
            original = SimpleNamespace(image=0x400000, imported=lambda value: None,
                pe=SimpleNamespace(sections=[SimpleNamespace(Characteristics=0x20000000, VirtualAddress=0x1000, Misc_VirtualSize=0x3000)]))
            binder = SimpleNamespace(plain=lambda name: name)
            bindings = [dict(symbol='?callee@@YAXXZ', address='00402000', function_start=True, votes=2, evidence='reference-vote')]
            with patch('roc.match._coff_data_index', return_value=(sections, [('?callee@@YAXXZ',)], {'?method': (0, 1)}, None)), \
                    patch('roc.match.coff_functions', return_value=[('?method', bytes(raw[20:26]), {})]), \
                    patch('roc.match.target', return_value=(target, {}, None)), \
                    patch('roc.match.exact_match', return_value=True):
                self.assertEqual(reviewed_call_targets(original, binder, obj, [('?method', 0x401000)], bindings)['targets'],
                                 {'?callee@@YAXXZ': 0x402000})
                self.assertEqual(reviewed_call_targets(original, binder, obj, [('?method', 0x401000)], [])['targets'], {})
                original.pe.sections[0].Characteristics = 0
                self.assertEqual(reviewed_call_targets(original, binder, obj, [('?method', 0x401000)], bindings)['targets'], {})

    def test_source_review_can_infer_unique_exact_direct_call(self):
        with TemporaryDirectory() as temp:
            obj = Path(temp) / 'unit.obj'
            raw = bytearray(100)
            raw[20:26] = b'\xe8\x00\x00\x00\x00\xc3'
            struct.pack_into('<IIH', raw, 60, 1, 0, 20)
            obj.write_bytes(raw)
            sections = [None, (0, 0, 0, 6, 20, 60, 0, 1)]
            target = b'\xe8' + struct.pack('<i', 0x402000 - (0x401000 + 5)) + b'\xc3'
            original = SimpleNamespace(image=0x400000, imported=lambda value: None,
                pe=SimpleNamespace(sections=[SimpleNamespace(Characteristics=0x20000000, VirtualAddress=0x1000, Misc_VirtualSize=0x3000)]))
            binder = SimpleNamespace(plain=lambda name: name)
            with patch('roc.match._coff_data_index', return_value=(sections, [('?callee@@YAXXZ',)], {'?method': (0, 1)}, None)), \
                    patch('roc.match.coff_functions', return_value=[('?method', bytes(raw[20:26]), {})]), \
                    patch('roc.match.target', return_value=(target, {}, None)), \
                    patch('roc.match.exact_match', return_value=True):
                result = reviewed_call_targets(original, binder, obj, [('?method', 0x401000)], [], allow_exact_inferred=True)
                self.assertEqual(result['targets'], {'?callee@@YAXXZ': 0x402000})
                self.assertEqual(result['notes'][0]['evidence'], 'exact-caller-relocation')

    def test_original_and_emitted_numeric_bytes_must_both_match(self):
        with TemporaryDirectory() as temp:
            obj = Path(temp) / 'unit.obj'
            raw = bytearray(100)
            raw[20:26] = b'\xa1\x00\x00\x00\x00\xc3'
            raw[40:44] = struct.pack('<f', 0.5)
            struct.pack_into('<IIH', raw, 60, 1, 0, 6)
            obj.write_bytes(raw)
            sections = [None, (0, 0, 0, 6, 20, 60, 0, 1), (0, 0, 0, 4, 40, 0, 0, 0)]
            symbols = [('__real@3f000000',)]
            definitions = {'?method': (0, 1), '__real@3f000000': (0, 2)}
            target = b'\xa1' + struct.pack('<I', 0x819bac) + b'\xc3'
            original = SimpleNamespace(data=lambda address, width: struct.pack('<f', 0.5))
            with patch('roc.match._coff_data_index', return_value=(sections, symbols, definitions, None)), \
                    patch('roc.match.coff_functions', return_value=[('?method', bytes(raw[20:26]), {})]), \
                    patch('roc.match.target', return_value=(target, {}, None)), \
                    patch('roc.match.exact_match', return_value=True):
                result = numeric_literal_targets(original, obj, [('?method', 0x401000)])
                self.assertEqual(result['targets'], {'__real@3f000000': 0x819bac})
                original.data = lambda address, width: struct.pack('<f', 1.0)
                with self.assertRaisesRegex(ValueError, 'bytes differ'):
                    numeric_literal_targets(original, obj, [('?method', 0x401000)])
                original.data = lambda address, width: struct.pack('<f', 0.5)
                raw[40:44] = struct.pack('<f', 1.0)
                obj.write_bytes(raw)
                with self.assertRaisesRegex(ValueError, 'bytes differ'):
                    numeric_literal_targets(original, obj, [('?method', 0x401000)])
