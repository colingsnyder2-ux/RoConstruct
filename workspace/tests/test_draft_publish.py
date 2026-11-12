import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from contextlib import closing
from types import SimpleNamespace
from unittest.mock import patch

from roc import draft_proof
from roc.draft_merger import SCHEMA, content_hash
from roc.draft_publish import BRANCH, publish, native_input_snapshot, verify_sources


class NativeInputSnapshotTests(unittest.TestCase):
    def test_snapshot_matches_existing_gate_and_identifies_content_changes(self):
        from roc.integration_verify import digest_paths
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            source = root / 'source.cpp'
            source.write_bytes(b'old')
            with patch('roc.integration_verify.input_paths', return_value=({source}, {source})):
                before, files = native_input_snapshot(root)
                self.assertEqual(before, digest_paths(root, {source}))
                source.write_bytes(b'new')
                after, changed = native_input_snapshot(root)
            self.assertNotEqual(before, after)
            self.assertEqual(files[str(source)], content_hash(b'old'))
            self.assertEqual(changed[str(source)], content_hash(b'new'))

    def test_snapshot_excludes_transient_roc_claude_probe_sources(self):
        from roc.integration_verify import digest_paths
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            stable = root / 'rebuild/2008-06/native-headers/Stable.h'
            scratch = root / 'rebuild/2008-06/Source/App/roc_claude_probe.cpp'
            stable.parent.mkdir(parents=True)
            scratch.parent.mkdir(parents=True)
            stable.write_text('stable')
            scratch.write_text('first')
            with patch('roc.integration_verify.input_paths', return_value=({stable, scratch}, {stable, scratch})):
                before, files = native_input_snapshot(root)
                scratch.write_text('second')
                after, changed = native_input_snapshot(root)
            self.assertEqual(before, after)
            self.assertEqual(files, changed)
            self.assertEqual(before, digest_paths(root, {stable}))


class DraftPublishTests(unittest.TestCase):
    source_path = 'rebuild/2008-06/native-classes/TextDisplay.cpp'

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        base = Path(self.temp.name)
        self.root = base / 'repo'
        self.origin = base / 'origin.git'
        self.root.mkdir()
        self.run_git(self.origin.parent, 'init', '--bare', str(self.origin))
        self.run_git(self.root, 'init', '-q')
        self.run_git(self.root, 'config', 'user.name', 'Test Publisher')
        self.run_git(self.root, 'config', 'user.email', 'publisher@example.invalid')
        self.run_git(self.root, 'checkout', '-b', BRANCH)
        self.run_git(self.root, 'remote', 'add', 'origin', str(self.origin))
        self.source = self.root / self.source_path
        self.source.parent.mkdir(parents=True)
        self.baseline = (b'#include "gui/Gui.h"\n\nnamespace RBX {\n'
                         b'int TextDisplay::getFontSize() const { return fontSize; }\n}\n')
        self.candidate = self.baseline + (
            b'\nnamespace RBX {\nstd::string TextDisplay::getLabel() const { return label; }\n}\n')
        self.source.write_bytes(self.baseline)
        notes = self.root / 'docs/notes.txt'
        notes.parent.mkdir(parents=True)
        notes.write_text('baseline note\n')
        other_work = self.root / 'work/2008-06/othertracked.txt'
        other_work.parent.mkdir(parents=True)
        other_work.write_text('preserve other work file\n')
        self.run_git(self.root, 'add', '.')
        self.run_git(self.root, 'commit', '-m', 'baseline')
        self.base = self.run_git(self.root, 'rev-parse', 'HEAD')
        self.run_git(self.root, 'push', 'origin', 'HEAD:refs/heads/' + BRANCH)
        self.source.write_bytes(self.candidate)
        self.proof_id = 'proof-text-display'
        self.expected_receipt = {
            'schema': 1,
            'kind': 'independent-draft-proof',
            'candidate_sha256': content_hash(self.candidate),
            'input_key': 'a' * 64,
            'client': '2008-06',
            'verifier_sha256': 'b' * 64,
            'before_methods': ['RBX::TextDisplay::getFontSize()const'],
            'after_methods': ['RBX::TextDisplay::getFontSize()const', 'RBX::TextDisplay::getLabel()const'],
            'checks': {name: True for name in draft_proof.BASE_CHECKS},
            'reference_evidence': [{'symbol': '?getLabel@TextDisplay@RBX@@', 'address': '00574580'}],
        }
        db_path = self.root / 'work/draft-merger/state.sqlite3'
        db_path.parent.mkdir(parents=True)
        import sqlite3
        with closing(sqlite3.connect(db_path)) as db, db:
            db.executescript(SCHEMA)
            db.execute('INSERT INTO proofs VALUES(?,?,?,?,?,?)', (
                self.proof_id, self.expected_receipt['input_key'], 'original-msvc-method-v1',
                self.expected_receipt['candidate_sha256'], json.dumps(self.expected_receipt), 1))
            db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)', (
                'action-text-display', 'run-1', 'bundle-1', self.source_path,
                content_hash(self.baseline), content_hash(self.candidate), 'applied-inactive',
                json.dumps({'proof': self.proof_id})))

    def tearDown(self):
        self.temp.cleanup()

    @staticmethod
    def run_git(root, *args):
        result = subprocess.run(['git', '-C', str(root), *args], check=True,
                                capture_output=True, text=True)
        return result.stdout.strip()

    def add_unrelated_dirty_and_staged_changes(self):
        notes = self.root / 'docs/notes.txt'
        notes.write_text('staged note\n')
        self.run_git(self.root, 'add', 'docs/notes.txt')
        notes.write_text('unstaged note\n')

    def run_publish(self, push=False, verify_side_effect=None, preservation='pass'):
        real_run = subprocess.run
        external_calls = []

        def run(argv, *args, **kwargs):
            if argv[0] == 'git':
                return real_run(argv, *args, **kwargs)
            external_calls.append(argv)
            if (argv[0] == sys.executable and len(argv) > 1 and
                    Path(argv[1]).name == 'verify_fork_preservation.py' and preservation != 'missing'):
                receipt = {'passed': preservation == 'pass',
                           'losses': [] if preservation == 'pass' else ['unrelated tree changed']}
                Path(argv[argv.index('--output') + 1]).write_text(json.dumps(receipt))
            return subprocess.CompletedProcess(argv, 0, b'', b'')

        def verify(root, sources, receipts, output):
            if verify_side_effect:
                verify_side_effect()
            return {'sources': {name: {'source_sha256': content_hash(raw), 'methods': []}
                                for name, raw in sources.items()}}

        with patch('roc.draft_publish.native_drafts.integration_lock',
                   side_effect=lambda root, action, token=None: {'token': 'test-lock'}), \
                patch('roc.draft_publish.render_status', side_effect=lambda root, path, raw: raw), \
                patch('roc.draft_publish.verify_sources', side_effect=verify), \
                patch('roc.draft_publish.subprocess.run', side_effect=run):
            result = publish(self.root, push=push)
        return result, external_calls

    def test_local_commit_contains_only_selected_source_and_receipt_preserves_other_staging(self):
        self.add_unrelated_dirty_and_staged_changes()
        result, calls = self.run_publish(push=False)

        self.assertEqual(result['state'], 'committed-local', result)
        self.assertFalse(result['pushed'])
        self.assertEqual(self.source.read_bytes(), self.candidate)
        committed_paths = self.run_git(self.root, 'diff-tree', '--no-commit-id', '--name-only', '-r', result['commit']).splitlines()
        self.assertEqual(set(committed_paths), {self.source_path, result['publication_receipt']})
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'refs/heads/' + BRANCH), result['commit'])
        self.assertEqual(self.run_git(self.origin, 'rev-parse', 'refs/heads/' + BRANCH), self.base)
        self.assertTrue((self.root / 'work/2008-06/shared-layouts').is_dir())
        self.assertEqual(self.run_git(self.root, 'show', ':docs/notes.txt'), 'staged note')
        self.assertEqual((self.root / 'docs/notes.txt').read_text(), 'unstaged note\n')
        self.assertIn('lease', ' '.join(' '.join(call) for call in calls))

    def test_push_flag_updates_only_local_bare_origin_branch(self):
        result, _ = self.run_publish(push=True)
        self.assertEqual(result['state'], 'pushed')
        self.assertTrue(result['pushed'])
        self.assertEqual(self.run_git(self.origin, 'rev-parse', 'refs/heads/' + BRANCH), result['commit'])
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'HEAD'), result['commit'])

    def test_publication_replays_source_only_exact_call_inference(self):
        for name in ('draft_publish', 'draft_native', 'draft_proof'):
            path = self.root / 'roc' / (name + '.py')
            path.parent.mkdir(exist_ok=True)
            path.write_text(name)
        output = self.root / 'publication-test'
        output.mkdir()
        receipt = dict(self.expected_receipt, kind='reviewed-source-improvement')
        binder = SimpleNamespace(verify=lambda *args: [])

        def compile_source(toolchain, command, args, directory, timeout):
            Path(next(arg[3:] for arg in args if arg.startswith('/Fo'))).write_bytes(b'object')
            return 0, ''

        calls = dict(targets={}, notes=[], import_aliases=set())
        with patch('roc.draft_publish.native_input_snapshot', return_value=('inputs', {})), \
                patch('roc.input_reuse.ensure_link'), \
                patch('roc.draft_native.original_view', return_value=(object(), binder)), \
                patch('roc.draft_native.flags', return_value=[]), \
                patch('roc.draft_native.closed_function_targets', return_value={}), \
                patch('roc.draft_native.numeric_literal_targets', return_value={'targets': {}, 'literals': []}), \
                patch('roc.draft_native.reviewed_call_targets', return_value=calls) as infer, \
                patch('roc.rebuild.toolchain', return_value=object()), \
                patch('roc.rebuild.run', side_effect=compile_source):
            verify_sources(self.root, {self.source_path: self.candidate}, {self.source_path: [receipt]}, output)
        self.assertTrue(infer.call_args.kwargs['allow_exact_inferred'])

    def test_proven_new_source_file_can_be_published(self):
        new_path = 'rebuild/2008-06/native-classes/NewProofed.cpp'
        raw = b'int newProofedMethod() { return 1; }\n'
        self.source.write_bytes(self.baseline)
        (self.root / new_path).write_bytes(raw)
        receipt = dict(self.expected_receipt, candidate_sha256=content_hash(raw),
                       before_methods=[], after_methods=['newProofedMethod'])
        with closing(__import__('sqlite3').connect(self.root / 'work/draft-merger/state.sqlite3')) as db, db:
            db.execute('DELETE FROM actions')
            db.execute('INSERT OR REPLACE INTO proofs VALUES(?,?,?,?,?,?)',
                       ('proof-new', receipt['input_key'], 'original-msvc-method-v1',
                        receipt['candidate_sha256'], json.dumps(receipt), 1))
            db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)',
                       ('action-new', 'run-1', 'bundle-new', new_path, None, content_hash(raw),
                        'applied-inactive', json.dumps({'proof': 'proof-new'})))
        result, _ = self.run_publish()
        self.assertEqual(result['state'], 'committed-local', result)
        self.assertIn(new_path, self.run_git(self.root, 'diff-tree', '--no-commit-id', '--name-only', '-r', result['commit']).splitlines())

    def test_incrementally_proven_new_source_file_can_be_published(self):
        new_path = 'rebuild/2008-06/native-classes/NewIncremental.cpp'
        prior = b'int firstMethod() { return 1; }\n'
        raw = prior + b'int secondMethod() { return 2; }\n'
        self.source.write_bytes(self.baseline)
        (self.root / new_path).write_bytes(raw)
        receipt = dict(self.expected_receipt, candidate_sha256=content_hash(raw),
                       before_methods=['firstMethod'], after_methods=['firstMethod', 'secondMethod'])
        with closing(__import__('sqlite3').connect(self.root / 'work/draft-merger/state.sqlite3')) as db, db:
            db.execute('DELETE FROM actions')
            db.execute('INSERT OR REPLACE INTO proofs VALUES(?,?,?,?,?,?)',
                       ('proof-new-incremental', receipt['input_key'], 'original-msvc-method-v1',
                        receipt['candidate_sha256'], json.dumps(receipt), 1))
            db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)',
                       ('action-new-incremental', 'run-1', 'bundle-new', new_path, content_hash(prior), content_hash(raw),
                        'applied-inactive', json.dumps({'proof': 'proof-new-incremental'})))
        result, _ = self.run_publish()
        self.assertEqual(result['state'], 'committed-local', result)
        self.assertIn(new_path, self.run_git(self.root, 'diff-tree', '--no-commit-id', '--name-only', '-r', result['commit']).splitlines())

    def test_selected_staged_change_is_rejected_without_commit(self):
        self.run_git(self.root, 'add', self.source_path)
        result, _ = self.run_publish()
        self.assertEqual(result['state'], 'blocked')
        self.assertIn('unrelated staged changes', result['error'])
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'HEAD'), self.base)
        self.assertEqual(self.source.read_bytes(), self.candidate)

    def test_remote_head_divergence_blocks_before_lease_or_mutation(self):
        clone = self.root.parent / 'divergent'
        self.run_git(self.root.parent, 'clone', '--branch', BRANCH, str(self.origin), str(clone))
        self.run_git(clone, 'config', 'user.name', 'Remote Divergence')
        self.run_git(clone, 'config', 'user.email', 'remote@example.invalid')
        (clone / 'docs/remote.txt').write_text('remote ahead\n')
        self.run_git(clone, 'add', '.')
        self.run_git(clone, 'commit', '-m', 'remote ahead')
        self.run_git(clone, 'push', 'origin', 'HEAD:refs/heads/' + BRANCH)
        original = self.source.read_bytes()

        result, calls = self.run_publish()
        self.assertEqual(result['state'], 'blocked')
        self.assertIn('Origin and local HEAD differ', result['error'])
        self.assertFalse(any('lease' in ' '.join(call) for call in calls))
        self.assertEqual(self.source.read_bytes(), original)
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'HEAD'), self.base)

    def test_source_changed_during_verification_blocks_without_restoring_it(self):
        changed = b'local concurrent edit\n'

        def mutate():
            self.source.write_bytes(changed)

        result, _ = self.run_publish(verify_side_effect=mutate)
        self.assertEqual(result['state'], 'blocked')
        self.assertIn('Selected source changed before exclusive commit', result['error'])
        self.assertEqual(self.source.read_bytes(), changed)
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'HEAD'), self.base)

    def test_missing_preservation_receipt_blocks_before_head_mutation(self):
        result, _ = self.run_publish(preservation='missing')
        self.assertEqual(result['state'], 'blocked')
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'HEAD'), self.base)
        self.assertEqual(self.source.read_bytes(), self.candidate)

    def test_failed_preservation_receipt_blocks_before_head_mutation(self):
        result, _ = self.run_publish(preservation='failed')
        self.assertEqual(result['state'], 'blocked')
        self.assertIn('zero losses', result['error'])
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'HEAD'), self.base)
        self.assertEqual(self.source.read_bytes(), self.candidate)

    def test_preexisting_index_lock_is_preserved_and_blocks_safely(self):
        lock = self.root / '.git/index.lock'
        lock.write_bytes(b'owned by another git process')
        result, _ = self.run_publish()
        self.assertEqual(result['state'], 'blocked')
        self.assertTrue(lock.exists())
        self.assertEqual(lock.read_bytes(), b'owned by another git process')
        self.assertEqual(self.run_git(self.root, 'rev-parse', 'HEAD'), self.base)
        self.assertEqual(self.source.read_bytes(), self.candidate)


if __name__ == '__main__':
    unittest.main()
