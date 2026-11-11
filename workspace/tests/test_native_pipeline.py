import hashlib
import json
from pathlib import Path
import tempfile
import unittest

from roc.native_pipeline import run, validate


class PipelineTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / 'source').write_text('reviewed')
        (self.root / 'proof.json').write_text('{"passed": true}')
        self.spec = dict(schema=1, reviewed_by='test', inputs={
            'source': hashlib.sha256(b'reviewed').hexdigest()}, stages=[
            dict(name='proof', kind='check', argv=['check'], assertions=[
                dict(file='proof.json', key='passed', equals=True)]),
            dict(name='push', kind='integrate', argv=['push']),
            dict(name='package', kind='publish', argv=['publish'])],
            cleanup=[dict(argv=['release-lease'])])
        self.plan = self.root / 'plan.json'
        self.calls = []
        self.guards = []

    def execute(self, stage, root):
        self.calls.append(stage['argv'][0])
        if stage['argv'] == ['check']:
            import os
            receipt = root / 'proof.json'
            before = receipt.stat().st_mtime_ns
            os.utime(receipt, ns=(before + 1000000, before + 1000000))

    def guard(self, root, action, **kwargs):
        self.guards.append(action)
        return {'token': 'test'}

    def invoke(self, execute=None):
        self.plan.write_text(json.dumps(self.spec))
        return run(self.plan, self.root, execute or self.execute, self.guard)

    def test_resume_rechecks_without_repush(self):
        self.invoke()
        self.calls.clear()
        self.invoke()
        self.assertEqual(self.calls, ['check', 'release-lease'])

    def test_changed_source_blocks_and_cleans(self):
        (self.root / 'source').write_text('changed')
        with self.assertRaisesRegex(ValueError, 'Pinned input'):
            self.invoke()
        self.assertEqual(self.calls, ['release-lease'])
        self.assertEqual(self.guards, ['start', 'release'])

    def test_false_receipt_blocks_push(self):
        (self.root / 'proof.json').write_text('{"passed": false}')
        with self.assertRaisesRegex(ValueError, 'assertion failed'):
            self.invoke()
        self.assertNotIn('push', self.calls)

    def test_uncertain_push_never_replayed(self):
        def fail(stage, root):
            self.execute(stage, root)
            if stage['argv'] == ['push']:
                raise RuntimeError('connection lost')
        with self.assertRaises(RuntimeError):
            self.invoke(fail)
        self.calls.clear()
        with self.assertRaisesRegex(ValueError, 'Uncertain side effect'):
            self.invoke()
        self.assertNotIn('push', self.calls)

    def test_zero_exit_without_assertion_rejected(self):
        del self.spec['stages'][0]['assertions']
        with self.assertRaisesRegex(ValueError, 'receipt assertions'):
            validate(self.spec)

    def test_cleanup_failure_recorded(self):
        def fail(stage, root):
            self.execute(stage, root)
            if stage['argv'] == ['release-lease']:
                raise RuntimeError('lease server unavailable')
        with self.assertRaisesRegex(RuntimeError, 'Cleanup failed'):
            self.invoke(fail)
        self.assertEqual(self.guards[-1], 'release')

    def test_stale_receipt_rejected(self):
        with self.assertRaisesRegex(ValueError, 'not refreshed'):
            self.invoke(lambda stage, root: None)


if __name__ == '__main__':
    unittest.main()
