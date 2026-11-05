"""Compile/test a findings 2008-06 package using installed ROC toolchains."""
import argparse
import copy
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import uuid


def restore(package):
    path = package / 'work/large-files.json'
    if not path.exists():
        return
    manifest = json.loads(path.read_text(encoding='utf-8'))
    for relative, entry in manifest.items():
        target = (package / relative).resolve()
        if not target.is_relative_to(package.resolve()):
            raise ValueError('Unsafe restored path')
        if target.exists() and target.stat().st_size == entry['bytes']:
            if hashlib.sha256(target.read_bytes()).hexdigest() == entry['sha256']:
                continue
        target.parent.mkdir(parents=True, exist_ok=True)
        temporary = target.with_name(target.name + '.restoring-' + uuid.uuid4().hex)
        digest, size = hashlib.sha256(), 0
        try:
            with temporary.open('wb') as output:
                for part in entry['parts']:
                    path = (package / part).resolve()
                    if not path.is_relative_to(package.resolve()):
                        raise ValueError('Unsafe chunk path')
                    with path.open('rb') as source:
                        while data := source.read(1024 * 1024):
                            output.write(data)
                            digest.update(data)
                            size += len(data)
            if digest.hexdigest() != entry['sha256'] or size != entry['bytes']:
                raise ValueError('Large-file checksum mismatch: ' + relative)
            temporary.replace(target)
        finally:
            temporary.unlink(missing_ok=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--roc-root', type=Path)
    parser.add_argument('--build-root', type=Path, help='existing complete module output tree for --tests-only')
    modes = parser.add_mutually_exclusive_group()
    modes.add_argument('--smoke-only', action='store_true')
    modes.add_argument('--tests-only', action='store_true')
    args = parser.parse_args()
    package = Path(__file__).resolve().parents[1]
    candidates = ([args.roc_root] if args.roc_root else [])
    if os.environ.get('ROC_ROOT'):
        candidates.append(Path(os.environ['ROC_ROOT']))
    candidates.extend(package.parents)
    candidates.extend(parent / 'RoConstruct' for parent in package.parents)
    root = next((p.resolve() for p in candidates if (p / 'roc/rebuild.py').is_file()), None)
    if root is None:
        raise SystemExit('Set ROC_ROOT to a configured RoConstruct checkout (compiler/dependencies required).')
    sys.path.insert(0, str(root))
    from roc import rebuild, libs
    run = package / 'work/build/manual-tests' / uuid.uuid4().hex
    workspace = run / 'rebuild/2008-06'
    workspace.mkdir(parents=True)
    results = {'source': str(package), 'tooling': str(root), 'modules': {},
               'note': 'Local package build; not a server acceptance receipt.'}
    print('Output:', run, flush=True)
    try:
        if not args.smoke_only:
            restore(package)
        for source, target in [('config', 'modules'), ('patches', 'patches'),
                               ('tests', 'tests'), ('src/glue', 'glue'), ('verification/manifests', 'manifests')]:
            if (package / source).is_dir():
                shutil.copytree(package / source, workspace / target)
        (workspace / 'out').mkdir()

        def link(source, target):
            if os.name == 'nt':
                subprocess.run(['cmd', '/c', 'mklink', '/J', str(target), str(source)], check=True, capture_output=True)
            else:
                target.symlink_to(source, target_is_directory=True)

        link(root / 'tools', run / 'tools')
        if (root / 'src').is_dir():
            link(root / 'src', run / 'src')
        native = str(package / 'src/Client').replace('\\', '/')

        def paths(value):
            if isinstance(value, dict):
                return {key: paths(item) for key, item in value.items()}
            if isinstance(value, list):
                return [paths(item) for item in value]
            if isinstance(value, str):
                for prefix in ('../rbxgs/Client', '../../rbxgs/Client', 'tools/rbxgs/Client'):
                    if value == prefix or value.startswith(prefix + '/'):
                        return native + value[len(prefix):]
            return value

        # Recipe source/include paths now compile the package's assembled source.
        libs.RECIPES = paths(copy.deepcopy(libs.RECIPES))
        for config in (workspace / 'modules').glob('*.json'):
            spec = paths(json.loads(config.read_text(encoding='utf-8')))
            if spec.get('overlay', {}).get('root') == native:
                spec.pop('overlay')  # exported native source is already patched
            config.write_text(json.dumps(spec, indent=2), encoding='utf-8')
        rebuild.ROOT = run
        rebuild.TOOLS = root / 'tools'
        rebuild.progress = lambda *a, **kw: None
        results['toolchain'] = rebuild.doctor('2008-06')
        if not results['toolchain']:
            return 1
        if args.smoke_only:
            return 0
        visited = set()
        prior = ([args.build_root] if args.build_root else []) + [package / 'work/build']
        prior += [p / 'rebuild/2008-06/out' for p in sorted((package / 'work/build/manual-tests').glob('*'), key=lambda p: p.stat().st_mtime, reverse=True) if p != run]
        overlay = root / 'rebuild/2008-06/patches/rbxgs-client.json'
        metadata = json.loads((package / 'package.json').read_text(encoding='utf-8'))
        if overlay.exists() and hashlib.sha256(overlay.read_bytes()).hexdigest() == metadata['overlay_sha256']:
            prior.append(root / 'rebuild/2008-06/out')
        required, pending = set(), ['rbxgs-app']
        while pending:
            spec = rebuild.load_module('2008-06', pending.pop())
            if spec['name'] in required:
                continue
            required.add(spec['name'])
            pending.extend(spec.get('depends', []))
        built = next((p for p in prior if all((p / name / 'linked/linked.lib').exists() for name in required)), None)
        if args.tests_only and built is None:
            raise RuntimeError('No local engine build found. Run compile_test.bat without --tests-only first.')

        def build(name):
            if name in visited:
                return
            spec = rebuild.load_module('2008-06', name)
            for dependency in spec.get('depends', []):
                build(dependency)
            visited.add(name)
            if args.tests_only:
                source = built / spec['name'] / 'linked'
                if not (source / 'linked.lib').exists():
                    raise RuntimeError('Missing rebuilt library: ' + str(source / 'linked.lib'))
                target = workspace / 'out' / spec['name'] / 'linked'
                target.mkdir(parents=True)
                for path in source.iterdir():
                    if path.suffix.lower() in {'.lib', '.dll', '.manifest'}:
                        shutil.copy2(path, target / path.name)
            else:
                verified = package / 'work/build' / spec['name'] / 'verified'
                if verified.is_dir():
                    shutil.copytree(verified, workspace / 'out' / spec['name'] / 'verified')
                report = rebuild.build_module('2008-06', name)
                results['modules'][name] = report
                if not report['linked'] or report['test_exit'] != 0:
                    raise RuntimeError('Module build/test failed: ' + name)

        build('rbxgs-app')
        results['milestones'] = rebuild.milestones('2008-06')
        return 0 if all(item['passed'] for item in results['milestones'].values()) else 1
    except Exception as error:
        results['error'] = str(error)
        print('FAILED:', error, flush=True)
        return 1
    finally:
        (run / 'result.json').write_text(json.dumps(results, indent=2) + '\n', encoding='utf-8')
        print('Report:', run / 'result.json', flush=True)


if __name__ == '__main__':
    raise SystemExit(main())
