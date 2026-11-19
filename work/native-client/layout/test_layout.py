"""Regression checks for the layout proof tools; no native compiler needed."""
import json
import copy
import io
import subprocess
import struct
import tempfile
import time
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

import inventory
import build_batch
import common
import exe_diff
import gui_consumers
import generic_consumers
import layout_apply
import live_source_drift
import newline_drift
import vendor_pair_review
import order_review
import resource_review
import refresh_protection
from prove_out_inventory import references
from coff_compare import compare_merge, parse, strict, tu_signature
from layout_verify import verify
from layout_apply import missing_consumer_roots, validate_consumer_inventory, validate_lease
from pdb_lines import line_blocks, subsections
from common import HERE, ROOT, family_gate, relative, save, sha


def obj(target=b'_target', local=b'_local', payload=b'\xc3'):
    # One code definition and one undefined target; relocation keeps its addend.
    code = b'\xe8\0\0\0\0' + payload
    symptr = 60 + len(code) + 10
    head = struct.pack('<HHIIIHH', 0x14c, 1, 0, symptr, 2, 0, 0)
    section = struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, len(code), 60,
                          60 + len(code), 0, 1, 0, 0x60000020)
    syms = struct.pack('<8sIhHBB', local.ljust(8, b'\0'), 0, 1, 0x20, 3, 0)
    syms += struct.pack('<8sIhHBB', target.ljust(8, b'\0'), 0, 0, 0, 2, 0)
    return head + section + code + struct.pack('<IIH', 1, 1, 20) + syms + struct.pack('<I', 4)


class LayoutTests(unittest.TestCase):
    def test_repeated_target_symbol_names_require_identity_review(self):
        rows = {'00401000': {'name': '?shared@@'}, '00402000': {'name': '?shared@@'},
                '00403000': {'name': '?unique@@'}, '00404000': {'name': None}}
        inventory.mark_ambiguous_names(rows)
        self.assertEqual(rows['00401000']['duplicate_target_name_count'], 2)
        self.assertTrue(rows['00402000']['requires_identity_review'])
        self.assertFalse(rows['00403000']['requires_identity_review'])
        self.assertFalse(rows['00404000']['requires_identity_review'])

    def test_case_only_paths_are_reviewed_separately_from_split_candidates(self):
        self.assertEqual(inventory.target_review_flags({'client/app/gui/GUI.cpp', 'client/app/gui/gui.cpp'}),
                         (False, True))
        self.assertEqual(inventory.target_review_flags({'client/app/gui/GUI.cpp', 'client/app/gui/Button.cpp'}),
                         (True, False))
        self.assertEqual(inventory.target_review_flags({'client/app/gui/GUI.cpp', 'client/app/gui/gui.cpp',
                                                        'client/app/gui/Button.cpp'}), (True, True))

    def test_protection_refresh_allows_only_stronger_protection(self):
        old = [{'file': 'roc/tool.py', 'sha256': 'abc', 'protected': False, 'references': []}]
        new = [{**old[0], 'protected': True}]
        self.assertTrue(refresh_protection.protection_only(old, new))
        self.assertFalse(refresh_protection.protection_only(new, old))
        self.assertFalse(refresh_protection.protection_only(old, [{**new[0], 'sha256': 'changed'}]))
        self.assertFalse(refresh_protection.protection_only(old, new + new))

    def test_generic_consumer_keeps_dynamic_and_glob_paths_for_review(self):
        self.assertTrue(generic_consumers.is_generic({'kind': 'literal', 'path_expression': 'native-classes/'}))
        self.assertTrue(generic_consumers.is_generic({'kind': 'glob', 'path_expression': 'native-classes/*.cpp'}))
        self.assertTrue(generic_consumers.is_generic({'kind': 'derived', 'path_expression': 'native-classes/Foo.cpp'}))
        self.assertFalse(generic_consumers.is_generic({'kind': 'literal', 'path_expression': 'native-classes/Foo.cpp'}))

    def test_consumer_protection_covers_owned_trees_and_generated_digest(self):
        for path in ('work/native-client/worker/draft.cpp', 'work/native-client/worker/note.txt',
                     'tools/vendor/source.cpp', 'clients/2008-06/sources.txt', 'docs/integration.json',
                     'docs/source-links.json', 'docs/progress.json', 'docs/history.json', 'docs/rebuild-progress.json',
                     'rebuild/2008-06/_archive/p6/build_client.py', 'rebuild/2008-06/p6/build_client.py',
                     'roc/draft_append.py', 'roc.py'):
            self.assertTrue(inventory.protected_consumer(path))
        self.assertFalse(inventory.protected_consumer('rebuild/2008-06/tests/record.py'))

    def test_streamed_consumer_records_handle_chunk_boundaries_and_truncation(self):
        rows = [{'file': 'a', 'text': 'brace } and quote "'}, {'file': 'b', 'text': 'é'}]
        data = json.dumps(rows, ensure_ascii=False)
        self.assertEqual(list(gui_consumers.records(io.StringIO(data), chunk_size=1)), rows)
        for broken in (data[:-1], '[{},]', '[{} {}]', data + ' x'):
            with self.assertRaises(ValueError):
                list(gui_consumers.records(io.StringIO(broken), chunk_size=2))

    def test_mapping_input_inventory_detects_openrbx_and_identity_changes(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            nc = root / 'work/native-client'
            here = nc / 'layout'
            original = root / 'tools/openrbx/Client/App/foo.cpp'
            original.parent.mkdir(parents=True)
            here.mkdir(parents=True)
            original.write_text('first')
            (nc / 'unnamed-identities.json').write_text('{}')
            (here / 'pdb-lines.json').write_text('{}')
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'HERE', here):
                before = inventory.mapping_inputs()
                original.write_text('changed')
                self.assertNotEqual(before, inventory.mapping_inputs())
                original.write_text('first')
                (nc / 'unnamed-identities.json').write_text('{"x": 1}')
                self.assertNotEqual(before, inventory.mapping_inputs())

    def test_source_inventory_blocks_added_removed_and_changed_files(self):
        frozen = {'a.cpp': 'hash-a', 'b.h': 'hash-b'}
        layout_apply.validate_source_inventory(frozen, dict(frozen))
        for current in ({'a.cpp': 'hash-a'}, {'a.cpp': 'hash-a', 'b.h': 'changed'},
                        {'a.cpp': 'hash-a', 'b.h': 'hash-b', 'new.cpp': 'hash-c'}):
            with self.assertRaises(ValueError):
                layout_apply.validate_source_inventory(frozen, current)

    def test_related_unmapped_unit_requires_fresh_explicit_review(self):
        with tempfile.TemporaryDirectory(dir=ROOT) as directory:
            root = Path(directory)
            a, b = root / 'TextDisplay.cpp', root / 'AppUnit.cpp'
            a.write_text('source')
            b.write_text('other source')
            target = 'client/app/gui/gui.cpp'
            mapping = {relative(a): {'original_path': 'client/app/gui/GUI.cpp', 'sha256': sha(a)},
                       relative(b): {'original_path': None, 'sha256': sha(b), 'function_target_candidates': [target]}}
            selected = {relative(a): mapping[relative(a)]}
            self.assertTrue(layout_apply.related_review_blockers(selected, mapping, {}))
            review = {target: {'members': {relative(a): sha(a), relative(b): sha(b)},
                               'note': 'Reviewed each candidate definition.'}}
            self.assertFalse(layout_apply.related_review_blockers(selected, mapping, review))
            b.write_text('changed source')
            self.assertTrue(layout_apply.related_review_blockers(selected, mapping, review))
            review[target]['members'][relative(b)] = sha(b)
            self.assertTrue(layout_apply.related_review_blockers(selected, mapping, review))

    def test_vendor_pair_review_finds_literal_includes(self):
        self.assertEqual(vendor_pair_review.includes(b'#include "../cache/unit.cpp.i"\n'),
                         ['../cache/unit.cpp.i'])

    def test_newline_drift_keeps_content_differences_distinct(self):
        self.assertEqual(newline_drift.classify(b'a\r\nb\r\n', b'a\nb\n'), 'line endings only')
        self.assertEqual(newline_drift.classify(b'a\n', b'b\r\n'), 'other content or byte difference')
        self.assertEqual(newline_drift.classify(b'a\n', b'a\n'), 'identical')

    def test_live_drift_detects_added_removed_and_changed(self):
        previous = {'same': '1', 'changed': '2', 'removed': '3'}
        current = {'same': '1', 'changed': '4', 'added': '5'}
        self.assertEqual(live_source_drift.differences(previous, current),
                         {'added': ['added'], 'removed': ['removed'], 'changed': ['changed']})

    def test_resource_review_compares_original_without_proving_provenance(self):
        with tempfile.TemporaryDirectory(dir=ROOT) as directory:
            root = Path(directory)
            (root / 'res').mkdir()
            asset = root / 'res/a.png'
            asset.write_bytes(b'asset')
            rc = root / 'Roblox.rc'
            rc.write_text('"A" PNG "res\\\\a.png"\n"B" PNG "res\\\\missing.png"\n'
                          '133 PNG "res\\\\a.png"\n')
            resources = [{'path': ['PNG', '"A"', '1033'], 'sha256': sha(asset)},
                         {'path': ['PNG', '133', '1033'], 'sha256': sha(asset)}]
            rows = resource_review.review(rc, resources)
            self.assertEqual([r['status'] for r in rows], ['hash matches', 'missing source file', 'hash matches'])

    def test_source_order_review_excludes_ambiguous_matches(self):
        def row(name, line, modules=('a.obj',)):
            return {'name': name, 'line': line, 'target_path': 'client/app/a.cpp',
                    'evidence': 'pdb', 'donor_modules': list(modules),
                    'donor_source_files': ['client/app/a.cpp']}
        functions = {'00001000': row('first', 20), '00002000': row('second', 10),
                     '00003000': row('ambiguous', 30, ('a.obj', 'b.obj')),
                     '00004000': row('duplicate', 40), '00005000': row('duplicate', 50),
                     '00006000': row('same-line', 20)}
        group = order_review.review(functions)[0]
        self.assertEqual(group['functions'], 3)
        self.assertEqual(group['comparable_pairs'], 2)
        self.assertEqual(group['reversed_pairs'], 1)

    def test_source_include_rewrite_preserves_pure_move_in_index(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source, header = root / 'old/source.cpp', root / 'include/header.h'
            source.parent.mkdir()
            header.parent.mkdir()
            original = b'#include "../include/header.h"\n'
            source.write_bytes(original)
            header.write_text('header')
            for command in (['git', 'init', '-q'], ['git', 'add', '.'],
                            ['git', '-c', 'user.name=Test', '-c', 'user.email=test@example.invalid',
                             'commit', '-qm', 'fixture']):
                subprocess.run(command, cwd=root, check=True, capture_output=True)
            selected = {'old/source.cpp': {'target_path': 'new/deeper/source.cpp'}}
            manifest = {'family': 'gui', 'freeze_confirmed': True, 'lease_name': 'fixture',
                        'consumer_rewrites': [], 'source_rewrites': [{'file': 'old/source.cpp',
                        'sha256': sha(source), 'replacements': [{'old': '../include/header.h',
                        'new': '../../include/header.h', 'count': 1}]}]}
            with patch.object(common, 'ROOT', root), patch.object(layout_apply, 'ROOT', root), \
                 patch.object(layout_apply, 'HERE', root / 'layout'), \
                 patch.object(layout_apply, 'preview', return_value=(selected, [])), \
                 patch.object(layout_apply, 'missing_consumer_roots', return_value=[]), \
                 patch.object(layout_apply, 'validate_current_sources'), \
                 patch.object(layout_apply, 'ownership'), patch.object(inventory, 'consumers', return_value=[]), \
                 patch.object(layout_apply, 'load', return_value={}) as loader, \
                 patch.object(layout_apply, 'save'):
                loader.side_effect = [[], {}]
                layout_apply.apply('gui', manifest)
            moved = root / 'new/deeper/source.cpp'
            self.assertEqual(moved.read_bytes(), b'#include "../../include/header.h"\n')
            staged = subprocess.check_output(['git', 'show', ':new/deeper/source.cpp'], cwd=root)
            self.assertEqual(staged, original)

    def test_reviewed_source_rewrites_are_limited_to_moved_files(self):
        consumers = [{'file': 'consumer.py'}]
        selected = {'source.cpp': {'target_path': 'target.cpp'}}
        reviews = [{'file': 'consumer.py'}]
        self.assertEqual(layout_apply.reviewed_rewrites(consumers, selected, reviews,
                         [{'file': 'source.cpp'}]), reviews + [{'file': 'source.cpp'}])
        for extra in ([{'file': 'other.cpp'}], [{'file': 'source.cpp'}, {'file': 'source.cpp'}],
                      [{'file': 'consumer.py'}]):
            with self.assertRaises(ValueError):
                layout_apply.reviewed_rewrites(consumers, selected, reviews, extra)
        with self.assertRaises(ValueError):
            layout_apply.reviewed_rewrites(consumers, selected, [], [])

    def test_moved_relative_include_requires_same_header(self):
        with tempfile.TemporaryDirectory(dir=ROOT) as directory:
            root = Path(directory)
            source = root / 'old/source.cpp'
            header = root / 'include/header.h'
            destination = root / 'new/deeper/source.cpp'
            source.parent.mkdir(parents=True)
            header.parent.mkdir()
            header.write_text('header')
            original = b'#include "../include/header.h"\n'
            source.write_bytes(original)
            selected = {relative(source): {'target_path': relative(destination)}}
            self.assertTrue(layout_apply.broken_relative_includes(selected, {}))
            rewritten = b'#include "../../include/header.h"\n'
            self.assertFalse(layout_apply.broken_relative_includes(selected, {source: (original, rewritten)}))
            moved_header = root / 'new/include/header.h'
            selected[relative(header)] = {'target_path': relative(moved_header)}
            self.assertFalse(layout_apply.broken_relative_includes(selected, {source: (original, original)}))
            self.assertTrue(layout_apply.broken_relative_includes(selected, {source: (original, rewritten)}))

    def test_owner_index_excludes_test_and_example_sources(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            nc = root / 'work/native-client'
            nc.mkdir(parents=True)
            (nc / 'webservice-pdb-source-paths.txt').write_text('')
            for suffix in ('App/gui/Panel.cpp', 'boost/libs/test/fixture.cpp', 'boost/libs/example/demo.cpp'):
                path = root / 'tools/openrbx/Client' / suffix
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text('void Owner::method() {}\n')
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'relative', lambda p: p.relative_to(root).as_posix()):
                inventory.path_index()
                paths = {path for path, _ in inventory.OPEN_OWNER_DEFS[('Owner', 'method')]}
            self.assertEqual(paths, {'client/app/gui/panel.cpp'})

    def test_openrbx_owner_definitions_exclude_calls_and_declarations(self):
        text = ('// Wrong::fake() {}\n'
                'void caller() { Other::call(); }\n'
                'void Declared::only();\n'
                '\n'
                'ArrowButton::ArrowButton(int n) : Base(n) {}\n'
                'bool ArrowButton::isEnabled() const\n{ return true; }\n')
        self.assertEqual(inventory.openrbx_owner_definitions(text), {
            ('ArrowButton', 'ArrowButton'): [5], ('ArrowButton', 'isEnabled'): [6]})

    def test_unique_openrbx_owner_path_stays_inferred(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            nc = root / 'work/native-client'
            (root / 'work/2008-06').mkdir(parents=True)
            nc.mkdir(parents=True)
            (root / 'work/2008-06/identity-registry.json').write_text(json.dumps({
                '00400000': {'kind': 'code', 'name': '?isEnabled@ArrowButton@RBX@@UAE_NXZ', 'owner_class': 'RBX::ArrowButton'},
                '00400010': {'kind': 'code', 'name': '?other@ArrowButton@RBX@@QAEXXZ', 'owner_class': 'RBX::ArrowButton'},
                '00400020': {'kind': 'code', 'name': '??0ArrowButton@RBX@@QAE@XZ', 'owner_class': 'RBX::ArrowButton'},
                '00400030': {'kind': 'code', 'name': '?isenabled@ArrowButton@RBX@@UAE_NXZ', 'owner_class': 'RBX::ArrowButton'}}))
            inventory.CHOICES.clear()
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'HERE', nc / 'layout'), patch.dict(inventory.OPEN_PATHS, {}, clear=True), \
                 patch.dict(inventory.OPEN_OWNER_PATHS, {'ArrowButton': ['client/app/gui/arrowpanel.cpp']}, clear=True), \
                 patch.dict(inventory.OPEN_OWNER_DEFS, {('ArrowButton', 'isEnabled'): [
                     ('client/app/gui/arrowpanel.cpp', 107)], ('ArrowButton', 'ArrowButton'): [
                     ('client/app/gui/arrowpanel.cpp', 46)]}, clear=True):
                result = inventory.functions({'client/app/gui/arrowpanel.cpp': ['Client/App/gui/ArrowPanel.cpp']}, {})
                row = result['00400000']
            self.assertEqual(row['target_path'], 'client/app/gui/ArrowPanel.cpp')
            self.assertTrue(row['inferred_path'])
            self.assertEqual(row['openrbx_definition_lines'], [107])
            self.assertEqual(result['00400020']['openrbx_definition_lines'], [46])
            self.assertIsNone(result['00400010']['target_path'])
            self.assertIsNone(result['00400030']['target_path'])
            inventory.CHOICES.clear()
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'HERE', nc / 'layout'), patch.dict(inventory.OPEN_PATHS, {}, clear=True), \
                 patch.dict(inventory.OPEN_OWNER_DEFS, {('ArrowButton', 'isEnabled'): [
                     ('client/app/gui/arrowpanel.cpp', 46), ('client/app/gui/other.cpp', 12)]}, clear=True):
                ambiguous = inventory.functions({}, {})['00400000']
            self.assertIsNone(ambiguous['target_path'])
            self.assertEqual(len(ambiguous['candidates']), 2)

    def test_candidate_targets_retain_origin_addresses(self):
        funcs = {'00400000': {'target_path': 'client/app/gui/Foo.cpp'},
                 '00400010': {'target_path': 'client/app/gui/Foo.cpp'},
                 '00400020': {'target_path': None}}
        result = inventory.target_address_evidence({'00400010', '00400020', '00400000', '00400030'}, funcs)
        self.assertEqual(result, {'client/app/gui/Foo.cpp': ['00400000', '00400010']})

    def test_possible_related_units_include_unmapped_candidates(self):
        rows = {
            'ArrowPanel.cpp': {'original_path': 'client/app/gui/ArrowPanel.cpp',
                               'function_target_candidates': ['client/app/gui/ArrowPanel.cpp']},
            'GuiWidgets.cpp': {'original_path': None,
                               'function_target_candidates': ['client/app/gui/arrowpanel.cpp']},
            'Other.cpp': {'original_path': None, 'function_target_candidates': ['client/app/gui/Other.cpp']}}
        groups = inventory.possible_related_units(rows)
        group = groups['client/app/gui/arrowpanel.cpp']
        self.assertEqual({row['file'] for row in group}, {'ArrowPanel.cpp', 'GuiWidgets.cpp'})
        self.assertEqual(next(row for row in group if row['file'] == 'GuiWidgets.cpp')['evidence'], ['address-heuristic'])
        self.assertNotIn('client/app/gui/other.cpp', groups)

    def test_family_gate_rejects_path_traversal(self):
        self.assertEqual(family_gate('gui'), HERE / 'gates' / 'gui')
        for name in ('..', '../other', 'a/b', 'a\\b', 'C:other'):
            with self.assertRaises(ValueError):
                family_gate(name)

    def test_before_build_preserves_declared_input_snapshot(self):
        gates = HERE / 'gates'
        gates.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(dir=gates) as directory:
            root = Path(directory)
            source, snapshot, output = root / 'source.cpp', root / 'snapshot.cpp', root / 'before.obj'
            source.write_text('original')
            manifest = root / 'manifest.json'
            manifest.write_text(json.dumps({'family': root.name,
                'inputs': {'before': {relative(source): sha(source)}},
                'before_input_snapshots': {relative(source): relative(snapshot)},
                'commands': {'before': [['fake-compiler']]}, 'outputs': {'before': [relative(output)]}}))
            def compile_fixture(*args, **kwargs):
                output.write_bytes(obj())
                return SimpleNamespace(returncode=0)
            with patch.object(build_batch.subprocess, 'run', side_effect=compile_fixture), \
                 patch.object(build_batch, 'save'):
                self.assertEqual(build_batch.run(manifest, 'before'), 0)
            self.assertEqual(snapshot.read_text(), 'original')

    def test_moved_source_requires_preserved_before_snapshot(self):
        gates = HERE / 'gates'
        gates.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(dir=gates) as directory:
            root = Path(directory)
            old, snapshot, new = root / 'old.cpp', root / 'snapshot.cpp', root / 'new.cpp'
            snapshot.write_text('before')
            new.write_text('after')
            before, after = root / 'before.obj', root / 'after.obj'
            before.write_bytes(obj())
            after.write_bytes(obj())
            stages = {'before': {relative(old): sha(snapshot)}, 'after': {relative(new): sha(new)}}
            receipts = []
            for stage, artifact in (('before', before), ('after', after)):
                receipt = root / (stage + '.json')
                receipt.write_text(json.dumps({'stage': stage, 'returncode': 0, 'reuse_objects': False,
                    'commands': [{'returncode': 0}], 'inputs': stages[stage],
                    'outputs': {relative(artifact): sha(artifact)}}))
                receipts.append(relative(receipt))
            checkpoint = root / 'checkpoint.json'
            checkpoint.write_text(json.dumps({'returncode': 0, 'reuse_objects': False,
                'command': ['rebuild/2008-06/tests/verify_native_checkpoint.py'], 'inputs': stages['after']}))
            manifest = {'family': root.name, 'standard': 'unchanged', 'inputs': stages,
                'before_input_snapshots': {relative(old): relative(snapshot)},
                'before_objects': [relative(before)], 'after_objects': [relative(after)],
                'build_receipts': receipts, 'checkpoint_receipt': relative(checkpoint)}
            self.assertTrue(verify(manifest)['passed'])
            snapshot.write_text('tampered')
            with self.assertRaises(ValueError):
                verify(manifest)

    def test_apply_preview_blocks_inline_placement_review(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / 'before.cpp'
            source.write_text('source')
            src = 'rebuild/2008-06/native-classes/Foo.cpp'
            dst = 'rebuild/2008-06/client/app/gui/Foo.cpp'
            row = {'family': 'gui', 'approved': True, 'target_path': dst, 'sha256': sha(source),
                   'merge_group': None, 'requires_split_review': False, 'requires_inline_placement_review': True}
            with patch.object(layout_apply, 'load', return_value={src: row}), \
                 patch.object(layout_apply, 'inside', side_effect=lambda p: source if p == src else root / 'after.cpp'):
                _, blockers = layout_apply.preview('gui')
            self.assertTrue(any('inline' in reason.lower() for reason in blockers))
            row.update(requires_inline_placement_review=False, requires_case_review=True)
            with patch.object(layout_apply, 'load', return_value={src: row}), \
                 patch.object(layout_apply, 'inside', side_effect=lambda p: source if p == src else root / 'after.cpp'):
                _, blockers = layout_apply.preview('gui')
            self.assertTrue(any('case' in reason.lower() for reason in blockers))
            row.update(requires_case_review=False, requires_identity_review=True)
            with patch.object(layout_apply, 'load', return_value={src: row}), \
                 patch.object(layout_apply, 'inside', side_effect=lambda p: source if p == src else root / 'after.cpp'):
                _, blockers = layout_apply.preview('gui')
            self.assertTrue(any('identity' in reason.lower() for reason in blockers))

    def test_multifile_pdb_lines_require_inline_review(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            nc = root / 'work/native-client'
            here = nc / 'layout'
            (root / 'work/2008-06').mkdir(parents=True)
            here.mkdir(parents=True)
            (root / 'work/2008-06/identity-registry.json').write_text(json.dumps({
                '00400000': {'kind': 'code', 'name': '?foo@@'}}))
            (here / 'pdb-lines.json').write_text(json.dumps({'functions': [{
                'decorated_names': ['?foo@@'], 'file': 'client/app/foo.cpp', 'line': 10,
                'source_files': ['client/app/foo.cpp', 'client/app/include/foo.h'], 'module': 'foo'}]}))
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'HERE', here):
                row = inventory.functions({}, {})['00400000']
            self.assertEqual(row['target_path'], 'client/app/foo.cpp')
            self.assertTrue(row['requires_inline_review'])
            self.assertEqual(len(row['donor_source_files']), 2)

    def test_exe_comparison_cannot_compare_original_to_itself(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'original.exe'
            path.write_bytes(b'not a PE')
            with self.assertRaises(ValueError):
                exe_diff.compare(path, path)

    def test_equal_executable_bytes_do_not_prove_source_provenance(self):
        with tempfile.TemporaryDirectory() as directory:
            before, after = Path(directory) / 'original.exe', Path(directory) / 'candidate.exe'
            before.write_bytes(b'same')
            after.write_bytes(b'same')
            with patch.object(exe_diff, 'describe', return_value={'sha256': sha(before)}):
                result = exe_diff.compare(before, after)
            self.assertTrue(result['full_file_identical'])
            self.assertFalse(result['source_only_verified'])

    def test_unchanged_tu_ignores_debug_data_but_not_code(self):
        before = self.parsed(obj())
        debug = copy.deepcopy(before['sections'][0])
        debug.update(name='.debug$S', chars=0x42100040, data=b'old path', relocations=[])
        before['sections'].append(debug)
        after = copy.deepcopy(before)
        after['sections'][-1]['data'] = b'new path'
        self.assertNotEqual(strict(before), strict(after))
        self.assertEqual(tu_signature(before), tu_signature(after))
        after['sections'][-1]['chars'] |= 0x20000000
        self.assertNotEqual(tu_signature(before), tu_signature(after))
        after['sections'][-1]['chars'] &= ~0x20000000
        after['sections'][-1]['chars'] |= 0x20
        self.assertNotEqual(tu_signature(before), tu_signature(after))
        after['sections'][-1]['chars'] &= ~0x20
        after['sections'][0]['data'] = b'changed code'
        self.assertNotEqual(tu_signature(before), tu_signature(after))

    def test_refresh_refuses_to_overwrite_reviewed_or_moved_layout(self):
        inventory.validate_refresh({'a.cpp': {'approved': False}}, {})
        with self.assertRaises(ValueError):
            inventory.validate_refresh({'a.cpp': {'approved': True}}, {})
        with self.assertRaises(ValueError):
            inventory.validate_refresh({}, {'gui': {'status': 'applied'}})

    def test_consumer_inventory_rejects_new_removed_or_changed_files(self):
        frozen = [{'file': 'a.py', 'sha256': 'a'}, {'file': 'b.json', 'sha256': 'b'}]
        validate_consumer_inventory(frozen, list(reversed(frozen)))
        for current in ([frozen[0]], frozen + [{'file': 'new.py', 'sha256': 'c'}],
                        [frozen[0], {'file': 'b.json', 'sha256': 'changed'}], frozen + [frozen[0]],
                        [frozen[0], {'file': 'b.json', 'sha256': 'b', 'protected': True}]):
            with self.assertRaises(ValueError):
                validate_consumer_inventory(frozen, current)

    def test_build_refuses_preexisting_output(self):
        gates = HERE / 'gates'
        gates.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(dir=gates) as directory:
            root = Path(directory)
            source, output, manifest = root / 'source.cpp', root / 'before.obj', root / 'manifest.json'
            source.write_text('source')
            output.write_bytes(obj())
            manifest.write_text(json.dumps({'family': root.name, 'inputs': {'before': {relative(source): sha(source)}},
                'commands': {'before': [['fake-compiler']]}, 'outputs': {'before': [relative(output)]}}))
            with patch.object(build_batch.subprocess, 'run', return_value=SimpleNamespace(returncode=0)), \
                 patch.object(build_batch, 'save'):
                with self.assertRaises(ValueError):
                    build_batch.run(manifest, 'before')

    def test_build_refuses_preexisting_receipt(self):
        gates = HERE / 'gates'
        gates.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(dir=gates) as directory:
            root = Path(directory)
            source, output, manifest = root / 'source.cpp', root / 'before.obj', root / 'manifest.json'
            source.write_text('source')
            (root / 'before-receipt.json').write_text('prior result')
            manifest.write_text(json.dumps({'family': root.name, 'inputs': {'before': {relative(source): sha(source)}},
                'commands': {'before': [['fake-compiler']]}, 'outputs': {'before': [relative(output)]}}))
            def compile_fixture(*args, **kwargs):
                output.write_bytes(obj())
                return SimpleNamespace(returncode=0)
            with patch.object(build_batch.subprocess, 'run', side_effect=compile_fixture), \
                 patch.object(build_batch, 'save'):
                with self.assertRaises(ValueError):
                    build_batch.run(manifest, 'before')

    def test_openrbx_test_source_is_not_a_production_path(self):
        inventory.CHOICES.clear()
        with patch.dict(inventory.OPEN_PATHS, {('shared_ptr', '.cpp'): [
                'client/boost_1_34_1/libs/python/test/shared_ptr.cpp']}, clear=True):
            choice = inventory.choose_path('boost::shared_ptr', '.cpp', {}, {})
        self.assertIsNone(choice['target_path'])
        self.assertTrue(choice['inferred_path'])
        self.assertIn('client/boost_1_34_1/libs/python/test/shared_ptr.cpp', choice['candidates'])

    def test_test_source_candidate_is_not_overridden_by_header_guess(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            nc = root / 'work/native-client'
            (root / 'work/2008-06').mkdir(parents=True)
            nc.mkdir(parents=True)
            (root / 'work/2008-06/identity-registry.json').write_text(json.dumps({
                '00400000': {'kind': 'code', 'name': 'test', 'owner_class': 'boost::shared_ptr'}}))
            inventory.CHOICES.clear()
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'HERE', nc / 'layout'), \
                 patch.dict(inventory.OPEN_PATHS, {
                     ('shared_ptr', '.cpp'): ['client/boost/libs/python/test/shared_ptr.cpp'],
                     ('shared_ptr', '.h'): ['client/boost/include/shared_ptr.h']}, clear=True):
                row = inventory.functions({}, {})['00400000']
            self.assertIsNone(row['target_path'])

    def test_owner_basename_match_is_inferred_for_function(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            nc = root / 'work/native-client'
            (root / 'work/2008-06').mkdir(parents=True)
            nc.mkdir(parents=True)
            (root / 'work/2008-06/identity-registry.json').write_text(json.dumps({
                '00400000': {'kind': 'code', 'name': 'test', 'owner_class': 'RBX::ArrowPanel'}}))
            inventory.CHOICES.clear()
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'HERE', nc / 'layout'), patch.dict(inventory.OPEN_PATHS, {}, clear=True):
                row = inventory.functions({}, {'arrowpanel': ['client/app/gui/arrowpanel.cpp']})['00400000']
            self.assertEqual(row['target_path'], 'client/app/gui/arrowpanel.cpp')
            self.assertTrue(row['inferred_path'])
            self.assertIsNone(row['line'])

    def test_apply_requires_website_consumer_tree(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.assertEqual(missing_consumer_roots(root), ['work/native-client/prove-out'])
            (root / 'work/native-client/prove-out').mkdir(parents=True)
            self.assertEqual(missing_consumer_roots(root), [])

    def test_prove_out_reference_kinds_and_counts(self):
        rows = references(['native-classes/Foo.cpp\n', 'glob("native-headers/gui/*.h")\n',
                           'native-classes/Foo.cpp\n'])
        self.assertEqual(rows, [
            {'expression': 'native-classes/Foo.cpp', 'kind': 'literal', 'count': 2},
            {'expression': 'native-headers/gui/*.h', 'kind': 'glob', 'count': 1}])

    def test_nested_ignored_consumers_are_inventoried(self):
        with tempfile.TemporaryDirectory(dir=ROOT) as directory:
            root = Path(directory)
            nc = root / 'work/native-client'
            for path in (root / 'work/2008-06/shared-layouts/receipt.json',
                         root / 'rebuild/2008-06/tests/nested/ignored.py',
                         root / 'rebuild/2008-06/native-world/ignored.cpp',
                         root / 'docs/nested/ignored.json', root / 'docs/integration.json',
                         nc / 'prove-out/nested/page.json', nc / 'prove-out/nested/unit.cpp',
                         nc / 'worker/note.txt', nc / 'worker/draft.cpp'):
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text('{"source":"rebuild/2008-06/native-classes/Foo.cpp"}')
            with patch.object(inventory, 'ROOT', root), patch.object(inventory, 'NC', nc), \
                 patch.object(inventory, 'relative', lambda p: p.relative_to(root).as_posix()), \
                 patch.object(inventory, 'sources', return_value=[]), \
                 patch.object(inventory.subprocess, 'run', return_value=SimpleNamespace(returncode=1, stdout=b'')):
                rows = inventory.consumers()
            self.assertEqual({row['file'] for row in rows}, {
                'work/2008-06/shared-layouts/receipt.json', 'work/native-client/prove-out/nested/page.json',
                'work/native-client/prove-out/nested/unit.cpp', 'rebuild/2008-06/tests/nested/ignored.py',
                'rebuild/2008-06/native-world/ignored.cpp', 'docs/nested/ignored.json', 'docs/integration.json',
                'work/native-client/worker/note.txt', 'work/native-client/worker/draft.cpp'})
            self.assertTrue(next(row for row in rows if 'prove-out' in row['file'])['protected'])
            self.assertTrue(next(row for row in rows if 'shared-layouts' in row['file'])['protected'])
            self.assertTrue(all(row['protected'] for row in rows if '/worker/' in row['file']))
            self.assertTrue(next(row for row in rows if row['file'] == 'docs/integration.json')['protected'])

    def parsed(self, raw):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'unit.obj'
            path.write_bytes(raw)
            return parse(path)

    def test_symbolic_relocation_change_fails(self):
        a, b = self.parsed(obj()), self.parsed(obj(target=b'_other'))
        self.assertNotEqual(strict(a), strict(b))
        self.assertFalse(compare_merge([a], [b])['passed'])

    def test_local_rename_only_allowed_for_merge(self):
        a, b = self.parsed(obj()), self.parsed(obj(local=b'_new'))
        self.assertNotEqual(strict(a), strict(b))
        self.assertTrue(compare_merge([a], [b])['passed'])

    def test_code_difference_fails(self):
        a, b = self.parsed(obj()), self.parsed(obj(payload=b'\x90'))
        self.assertFalse(compare_merge([a], [b])['passed'])

    def test_truncated_coff_fails(self):
        with self.assertRaises((ValueError, struct.error)):
            self.parsed(obj()[:-20])

    def test_coff_code_section_cannot_have_missing_raw_data(self):
        malformed = bytearray(obj())
        struct.pack_into('<I', malformed, 40, 0)
        with self.assertRaises(ValueError):
            self.parsed(bytes(malformed))
        struct.pack_into('<I', malformed, 56, 0xc0000080)
        self.assertEqual(self.parsed(bytes(malformed))['sections'][0]['data'], b'\0' * 6)

    def test_c13_lines_and_columns(self):
        data = struct.pack('<IHHI', 100, 2, 1, 40)
        data += struct.pack('<III', 0, 2, 36)
        data += struct.pack('<IIII', 0, 0x8000002a, 4, 43)
        data += struct.pack('<HHHH', 1, 8, 2, 9)
        rows = list(line_blocks(data, {0: 'client/app/foo.cpp'}))
        self.assertEqual([(v['offset'], v['line']) for v in rows], [(100, 42), (104, 43)])
        self.assertEqual(rows[0]['file'], 'client/app/foo.cpp')
        self.assertTrue(rows[0]['statement'])

    def test_bad_c13_block_fails(self):
        with self.assertRaises(ValueError):
            list(line_blocks(struct.pack('<IHHI', 0, 1, 0, 8) + struct.pack('<III', 0, 2, 12), {}))

    def test_c13_line_outside_contribution_fails(self):
        data = struct.pack('<IHHI', 100, 2, 0, 4)
        data += struct.pack('<III', 0, 1, 20) + struct.pack('<II', 4, 42)
        with self.assertRaises(ValueError):
            list(line_blocks(data, {0: 'client/app/foo.cpp'}))

    def test_c13_trailing_partial_block_fails(self):
        with self.assertRaises(ValueError):
            list(line_blocks(struct.pack('<IHHI', 0, 1, 0, 8) + b'\x00', {}))

    def test_subsection_alignment(self):
        data = struct.pack('<II', 0xf3, 1) + b'x\0\0\0' + struct.pack('<II', 0xf4, 0)
        self.assertEqual(list(subsections(data)), [(0xf3, b'x'), (0xf4, b'')])

    def test_missing_build_evidence_never_passes(self):
        self.assertFalse(verify({'family': 'gui'})['passed'])

    def test_receipt_inputs_must_match_frozen_inputs(self):
        with tempfile.TemporaryDirectory(dir=ROOT) as directory:
            root = Path(directory)
            source, artifact = root / 'source.cpp', root / 'before.obj'
            after = root / 'after.obj'
            source.write_text('current source')
            artifact.write_bytes(obj())
            after.write_bytes(obj())
            inputs = {relative(source): sha(source)}
            receipt = root / 'build.json'
            receipt.write_text(json.dumps({'returncode': 0, 'reuse_objects': False,
                'stage': 'before', 'commands': [{'returncode': 0}], 'inputs': {relative(source): 'stale'},
                'outputs': {relative(artifact): sha(artifact)}}))
            after_receipt = root / 'after-build.json'
            after_receipt.write_text(json.dumps({'returncode': 0, 'reuse_objects': False,
                'stage': 'after', 'commands': [{'returncode': 0}], 'inputs': inputs,
                'outputs': {relative(after): sha(after)}}))
            checkpoint = root / 'checkpoint.json'
            checkpoint.write_text(json.dumps({'returncode': 0, 'reuse_objects': False,
                'command': ['rebuild/2008-06/tests/verify_native_checkpoint.py'], 'inputs': inputs}))
            manifest = {'family': 'gui', 'standard': 'unchanged', 'inputs': {'before': inputs, 'after': inputs},
                'before_objects': [relative(artifact)], 'after_objects': [relative(after)],
                'build_receipts': [relative(receipt), relative(after_receipt)], 'checkpoint_receipt': relative(checkpoint)}
            with self.assertRaises(ValueError):
                verify(manifest)
            build = json.loads(receipt.read_text())
            build['inputs'] = inputs
            receipt.write_text(json.dumps(build))
            self.assertTrue(verify(manifest)['passed'])
            manifest['after_objects'] = [relative(artifact)]
            with self.assertRaises(ValueError):
                verify(manifest)
            manifest['after_objects'] = [relative(after)]
            bad_stage = json.loads(after_receipt.read_text())
            bad_stage['stage'] = 'before'
            after_receipt.write_text(json.dumps(bad_stage))
            with self.assertRaises(ValueError):
                verify(manifest)
            bad_stage['stage'] = 'after'
            after_receipt.write_text(json.dumps(bad_stage))
            check = json.loads(checkpoint.read_text())
            check['inputs'] = {relative(source): 'stale'}
            checkpoint.write_text(json.dumps(check))
            with self.assertRaises(ValueError):
                verify(manifest)

    def test_report_path_cannot_escape_layout(self):
        with self.assertRaises(ValueError):
            save('../outside-layout-test.json', {})

    def test_lease_must_be_owned_and_cover_every_path(self):
        leases = [{'name': 'gui', 'user': 'alice', 'patterns': ['src/gui/*'], 'expires': time.time() + 300}]
        validate_lease(leases, False, 'alice', 'gui', ['src/gui/a.cpp'])
        for stale, user, name, paths in [
                (True, 'alice', 'gui', ['src/gui/a.cpp']),
                (False, 'bob', 'gui', ['src/gui/a.cpp']),
                (False, 'alice', 'gui', ['src/gui/a.cpp', 'src/other.cpp']),
                (False, 'alice', 'ui', ['src/gui/a.cpp'])]:
            with self.assertRaises(ValueError):
                validate_lease(leases, stale, user, name, paths)
        with self.assertRaises(ValueError):
            validate_lease(leases + [{'name': 'other', 'user': 'alice', 'patterns': ['src/gui/*'],
                                      'expires': time.time() + 300}], False, 'alice', 'gui', ['src/gui/a.cpp'])



class ExportIncludeTest(unittest.TestCase):
    def test_relative_include_follows_export_and_search_include_stays(self):
        import layout_export
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            src = root / 'a/b/x.cpp'
            hdr = root / 'a/inc/y.h'
            hdr.parent.mkdir(parents=True); src.parent.mkdir(parents=True)
            hdr.write_text('')
            text = '#include "../inc/y.h"\n#include "gui/Gui.h"\n'
            dest = root / 'out/c/d/e/x.cpp'
            out, changes = layout_export.rewrite(text, src, dest, root / 'none')
            self.assertEqual(out, '#include "../../../../a/inc/y.h"\n#include "gui/Gui.h"\n')
            out, _ = layout_export.rewrite(text, src, dest, root / 'a/inc')
            self.assertIn('#include "y.h"', out)
            self.assertEqual(len(changes), 1)


from test_clean import CleanTest, JoinTest, MergeLocalsTest, RepairTest, WrapperTest  # noqa: E402,F401
from test_overrides import OverrideSelectTest, WorkersTest  # noqa: E402,F401
from test_stage import StageFilesTest  # noqa: E402,F401
from test_ios import IosNameTest  # noqa: E402,F401


if __name__ == '__main__':
    unittest.main()
