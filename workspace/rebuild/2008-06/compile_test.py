"""Compile current local engine sources and run existing runtime harnesses.

Double-click compile_test.bat for a full build. --smoke-only checks the compiler.
--tests-only relinks tests against existing rebuilt libraries. Outputs stay in a
separate run folder; this never submits integrations or regenerates overlays.
"""
import argparse
import json
from pathlib import Path
import shutil
import sys
import uuid


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    modes = parser.add_mutually_exclusive_group()
    modes.add_argument('--smoke-only', action='store_true')
    modes.add_argument('--tests-only', action='store_true')
    args = parser.parse_args()
    source = Path(__file__).resolve().parent
    root = source.parents[1]
    sys.path.insert(0, str(root))
    from roc import rebuild

    run = source / 'out' / 'manual-tests' / uuid.uuid4().hex
    run.mkdir(parents=True)
    shutil.copytree(source / 'tests', run / 'tests')
    if (source / 'manifests').exists():
        shutil.copytree(source / 'manifests', run / 'manifests')
    (run / 'out').mkdir()
    rebuild.workspace = lambda client: run
    # Local tests must not send progress webhooks or overwrite public status.
    rebuild.progress = lambda *a, **kw: None
    results = {'source': str(root), 'output': str(run), 'modules': {},
               'note': 'Current local sources; not an integration acceptance receipt.'}
    print('Output:', run, flush=True)
    try:
        results['toolchain'] = rebuild.doctor('2008-06')
        if not results['toolchain']:
            return 1
        if args.smoke_only:
            return 0
        seen = set()

        def build(name):
            if name in seen:
                return
            spec = rebuild.load_module('2008-06', name)
            for dep in spec.get('depends', []):
                build(dep)
            seen.add(name)
            if args.tests_only:
                linked = source / 'out' / spec['name'] / 'linked'
                if not (linked / 'linked.lib').exists():
                    raise RuntimeError('Missing rebuilt library: ' + str(linked / 'linked.lib'))
                shutil.copytree(linked, run / 'out' / spec['name'] / 'linked')
            else:
                report = rebuild.build_module('2008-06', name)
                results['modules'][name] = report
                if not report['linked'] or report['test_exit'] != 0:
                    raise RuntimeError('Module build/test failed: ' + name)

        build('rbxgs-app')
        results['milestones'] = rebuild.milestones('2008-06')
        passed = all(item['passed'] for item in results['milestones'].values())
        print('All runtime tests passed.' if passed else
              'Runtime failures remain. Read result.json / out/milestones.json.', flush=True)
        return 0 if passed else 1
    except Exception as error:
        results['error'] = str(error)
        print('FAILED:', error, flush=True)
        return 1
    finally:
        (run / 'result.json').write_text(json.dumps(results, indent=2) + '\n', encoding='utf-8')
        print('Report:', run / 'result.json', flush=True)


if __name__ == '__main__':
    raise SystemExit(main())
