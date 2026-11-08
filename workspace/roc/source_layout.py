"""Prepare and verify reviewed native source moves without changing the checkout.

Input is a reviewed JSON spec: {"base": COMMIT, "moves": [{"source":
"native-classes/A.cpp", "target": "WindowsClient/src/A.cpp", "checks":
[{"addr": "00400000", "symbol": "?method@"}]}]}. Run the existing native
batch runner with BASE set to OUT/frozen/rebuild/2008-06. Then verify its run.
Verification writes explicit integration/public manifests; it never commits.
"""
import argparse
import hashlib
import io
import json
import os
from pathlib import Path, PurePosixPath
import re
import struct
import subprocess
import sys

from roc import match

PROJECTS = ('App', 'Base', 'Network', 'Rendering', 'WindowsClient', 'Studio', 'Unclassified')
BANNER = re.compile(rb'(?m)^// >>> native-status \(generated\)[^\n]*\n(?://[^\n]*\n)*?// <<< native-status[^\n]*(?:\n|$)')
MARKER = b'// Compatibility translation unit; compile this file or the organized source, not both.\n'


def git(root, *args, data=None):
    return subprocess.check_output(['git', *args], cwd=root, input=data)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def safe(path):
    p = PurePosixPath(path)
    if not path or '\\' in path or ':' in path or p.is_absolute() or any(x in ('', '.', '..') for x in p.parts):
        raise ValueError('Unsafe path: ' + path)
    return p


def compatibility_shim(old, new, native):
    flags = re.findall(rb'(?m)^// native-flags: [^\r\n]*', native)
    if len(flags) > 1:
        raise ValueError('Multiple native flag profiles require review')
    include = os.path.relpath(str(new), str(old.parent)).replace('\\', '/')
    return (flags[0] + b'\n' if flags else b'') + MARKER + b'#include "' + include.encode() + b'"\n'


def snapshot_headers(root, base, output):
    prefix = 'workspace/rebuild/2008-06/native-headers/'
    listing = git(root, 'ls-tree', '-rz', base, '--', prefix).split(b'\0')
    entries = []
    for line in listing:
        if not line:
            continue
        meta, name = line.split(b'\t', 1)
        mode, kind, blob = meta.split()
        path = name.decode('utf-8')
        if mode not in (b'100644', b'100755') or kind != b'blob' or not path.startswith(prefix):
            raise ValueError('Non-regular header input: ' + path)
        relative = safe(path[len(prefix):])
        entries.append((relative, blob.decode()))
    if not entries:
        raise ValueError('No canonical headers at base')
    import io
    ids = sorted({blob for _, blob in entries})
    raw = git(root, 'cat-file', '--batch', data=('\n'.join(ids) + '\n').encode())
    stream, blobs = io.BytesIO(raw), {}
    for blob in ids:
        head = stream.readline().split()
        if head[0].decode() != blob or head[1] != b'blob':
            raise ValueError('Header blob mismatch')
        blobs[blob] = stream.read(int(head[2]))
        stream.read(1)
    for relative, blob in entries:
        target = output.joinpath(*relative.parts)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(blobs[blob])


def checked_base(root, base):
    if not re.fullmatch('[0-9a-f]{40}', base):
        raise ValueError('Base must be an exact commit ID')
    if git(root, 'rev-parse', base + '^{commit}').decode().strip() != base:
        raise ValueError('Base is not the requested commit')


def inspect_move(root, base, row):
    old, new = safe(row['source']), safe(row['target'])
    if (len(old.parts) != 2 or old.parts[0] != 'native-classes' or old.suffix != '.cpp'
            or len(new.parts) < 3 or new.parts[0] not in PROJECTS or new.parts[1] != 'src'
            or new.name != old.name or (not row.get('checks') and row.get('preservation_only') is not True)):
        raise ValueError('Move needs a native source, matching project destination and independent checks or explicit preservation-only mode')
    for check in row.get('checks', []):
        if (not isinstance(check, dict) or not isinstance(check.get('addr'), str)
                or not re.fullmatch('[0-9a-fA-F]{8}', check['addr'])
                or not isinstance(check.get('symbol'), str) or not check['symbol']):
            raise ValueError('Each check needs an original address and symbol')
    oldpath, newpath = str(old), str(new)
    native = git(root, 'show', base + ':workspace/rebuild/2008-06/' + oldpath)
    public = git(root, 'show', base + ':2008-06/' + oldpath)
    if MARKER in native or re.search(rb'^\s*#\s*include\s*"\.\.?/', native, re.M):
        raise ValueError('Existing shim or relative include requires manual review: ' + oldpath)
    if (BANNER.sub(b'', public).replace(b'\r\n', b'\n') != native.replace(b'\r\n', b'\n')
            and row.get('preserve_public_variant') is not True):
        raise ValueError('Public source differs beyond status/line endings: ' + oldpath)
    if BANNER.sub(b'', public).replace(b'\r\n', b'\n') == native.replace(b'\r\n', b'\n'):
        compatibility_shim(old, new, public)
    for prefix in ('workspace/rebuild/2008-06/', '2008-06/'):
        check = subprocess.run(['git', 'cat-file', '-e', base + ':' + prefix + newpath], cwd=root, capture_output=True)
        if check.returncode == 0:
            raise ValueError('Destination already exists: ' + prefix + newpath)
    return oldpath, newpath, native, public, compatibility_shim(old, new, native), row.get('checks', [])


def suggest(root, base, target_prefix, checks, output):
    """Index a reviewed checks manifest; suggestions are not approval."""
    root, output = Path(root).resolve(), Path(output).resolve()
    allowed = (root / 'work/native-candidates').resolve()
    if not output.is_relative_to(allowed) or output.exists():
        raise ValueError('Suggestions need a new output under work/native-candidates')
    checked_base(root, base)
    prefix = safe(target_prefix)
    if len(prefix.parts) < 2 or prefix.parts[0] not in PROJECTS or prefix.parts[1] != 'src':
        raise ValueError('Target prefix must be an organized project source folder')
    moves, skipped, seen = [], [], set()
    for job in checks.get('jobs', []):
        try:
            old = safe(job['source'])
            row = {'source': str(old), 'target': str(prefix / old.name), 'checks': job.get('checks', [])}
            if str(old).casefold() in seen:
                raise ValueError('Duplicate source')
            seen.add(str(old).casefold())
            inspect_move(root, base, row)
            moves.append(row)
        except (KeyError, TypeError, ValueError, subprocess.CalledProcessError) as error:
            skipped.append({'source': job.get('source') if isinstance(job, dict) else None, 'reason': str(error)})
    output.parent.mkdir(parents=True, exist_ok=True)
    result = dict(base=base, moves=moves, skipped=skipped,
                  scope='Suggestions only; review source, classification and original evidence before use.')
    with output.open('x', encoding='utf-8') as stream:
        json.dump(result, stream, indent=2)
        stream.write('\n')
    return result


def prepare(root, spec, out):
    root, out = Path(root).resolve(), Path(out).resolve()
    allowed = (root / 'work/native-candidates').resolve()
    if not out.is_relative_to(allowed) or out == allowed:
        raise ValueError('Output must be a fresh folder under work/native-candidates')
    base = spec['base']
    checked_base(root, base)
    moves = spec.get('moves') or []
    if not moves:
        raise ValueError('No reviewed moves')
    staged, seen = [], set()
    for row in moves:
        old, new = safe(row['source']), safe(row['target'])
        if any(x.casefold() in seen for x in (str(old), str(new))):
            raise ValueError('Duplicate or case-colliding move')
        seen.update(x.casefold() for x in (str(old), str(new)))
        staged.append(inspect_move(root, base, row))
    out.mkdir(parents=True, exist_ok=False)
    snapshot_headers(root, base, out / 'frozen/rebuild/2008-06/native-headers')
    jobs, records = [], []
    for old, new, native, public, shim, checks in staged:
        original = out / 'original' / old
        original.parent.mkdir(parents=True, exist_ok=True)
        original.write_bytes(native)
        jobs.append(dict(source=str(original), checks=checks))
        for name, content in ((old, shim), (new, native)):
            path = out / 'candidate' / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(content)
            jobs.append(dict(source=str(path), checks=checks))
        pub = out / 'public' / old
        pub.parent.mkdir(parents=True, exist_ok=True)
        pub.write_bytes(public)
        public_variant = BANNER.sub(b'', public).replace(b'\r\n', b'\n') != native.replace(b'\r\n', b'\n')
        if not public_variant:
            pubshim = out / 'public-shim' / old
            pubshim.parent.mkdir(parents=True, exist_ok=True)
            pubshim.write_bytes(compatibility_shim(safe(old), safe(new), public))
        records.append(dict(source=old, target=new, source_sha256=sha(native), public_sha256=sha(public),
                            checks=checks, preservation_only=not bool(checks),
                            public_variant=public_variant))
    plan = dict(base=base, header_tree=git(root, 'rev-parse', base + ':workspace/rebuild/2008-06/native-headers').decode().strip(),
                runner_sha256=sha(git(root, 'show', base + ':workspace/rebuild/2008-06/tests/native_check_runner.py')), moves=records)
    (out / 'plan.json').write_text(json.dumps(plan, indent=2) + '\n', encoding='utf-8')
    (out / 'batch.json').write_text(json.dumps({'jobs': jobs}, indent=2) + '\n', encoding='utf-8')
    return plan


def object_identity(raw):
    sections, symbols, _, _ = match._coff_data_index(raw)
    result = []
    for section in sections:
        name = section[0].rstrip(b'\0').decode('latin-1')
        if name.startswith('.debug'):
            continue
        data = raw[section[4]:section[4] + section[3]] if section[4] else b''
        relocs = []
        for index in range(section[7]):
            offset, sym, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * index)
            if sym not in symbols:
                raise ValueError('Unresolved COFF symbol index')
            relocs.append((offset, symbols[sym][0], kind))
        result.append((name, section[9], data, relocs))
    return result, match.coff_functions(raw)


def verify(root, out, run):
    root, out, run = Path(root).resolve(), Path(out).resolve(), Path(run).resolve()
    if not out.is_relative_to((root / 'work/native-candidates').resolve()):
        raise ValueError('Invalid candidate folder')
    if not run.is_relative_to((root / 'work/2008-06/native-check-runs').resolve()):
        raise ValueError('Invalid native runner folder')
    plan = json.loads((out / 'plan.json').read_text(encoding='utf-8'))
    summary = json.loads((run / 'summary.json').read_text(encoding='utf-8'))
    results = json.loads((run / 'results.json').read_text(encoding='utf-8'))
    total = len(plan['moves']) * 3
    if (summary.get('state') not in ('complete', 'failed') or summary.get('error')
            or summary.get('shared_headers_changed') != [] or summary.get('total_sources') != total
            or summary.get('completed_sources') != total or len(results) != total):
        raise ValueError('Runner incomplete or shared headers changed')
    if summary.get('state') == 'failed' and not any(row.get('status') != 'complete' for row in results):
        raise ValueError('Failed runner has no failed source')
    runner = git(root, 'show', plan['base'] + ':workspace/rebuild/2008-06/tests/native_check_runner.py')
    if summary.get('observer_sha256') != sha(runner):
        raise ValueError('Runner differs from reviewed canonical version')
    prefix = 'workspace/rebuild/2008-06/native-headers/'
    header_blobs = {}
    for line in git(root, 'ls-tree', '-rz', plan['base'], '--', prefix).split(b'\0'):
        if line:
            meta, path = line.split(b'\t', 1)
            mode, kind, blob = meta.split()
            if mode not in (b'100644', b'100755') or kind != b'blob':
                raise ValueError('Non-regular canonical header')
            header_blobs[path.decode()[len(prefix):]] = blob.decode()
    frozen = (out / 'frozen/rebuild/2008-06/native-headers').resolve()
    index = {str(Path(r['source']).resolve()).casefold(): r for r in results}
    if len(index) != len(results):
        raise ValueError('Duplicate runner source')
    fingerprints = {}
    def fingerprint(path):
        path = Path(path).resolve()
        if path not in fingerprints:
            content = path.read_bytes()
            fingerprints[path] = (sha(content), hashlib.sha1(b'blob ' + str(len(content)).encode() + b'\0' + content).hexdigest())
        return fingerprints[path]
    accepted, skipped = [], []
    for move in plan['moves']:
        old, new = safe(move['source']), safe(move['target'])
        try:
            pair = [index[str(path.resolve()).casefold()] for path in
                    (out / 'original' / old, out / 'candidate' / old, out / 'candidate' / new)]
            raw = []
            for result in pair:
                if result.get('status') != 'complete':
                    raise ValueError('Source failed: ' + result.get('error', 'no compiler receipt')
                                     + ('; log: ' + result['log'] if result.get('log') else ''))
                source = Path(result['source'])
                obj = Path(result['object'])
                if (result.get('changed_inputs')
                        or not result.get('build_inputs') or fingerprint(source)[0] != result.get('source_sha256')
                        or not obj.resolve().is_relative_to(run)
                        or fingerprint(obj)[0] != result.get('object_sha256')):
                    raise ValueError('Incomplete or stale source/object')
                if not any(Path(path).resolve() == source.resolve() for path in result.get('dependencies', {})):
                    raise ValueError('Source dependency missing from receipt')
                for path, digest in result['dependencies'].items():
                    dependency = Path(path).resolve()
                    dependency_sha, dependency_blob = fingerprint(dependency)
                    if dependency_sha != digest:
                        raise ValueError('Dependency changed: ' + path)
                    if dependency.is_relative_to(frozen):
                        relative = dependency.relative_to(frozen).as_posix()
                        if header_blobs.get(relative) != dependency_blob:
                            raise ValueError('Frozen header differs from canonical base: ' + path)
                    elif dependency.is_relative_to((root / 'rebuild/2008-06/native-headers').resolve()):
                        raise ValueError('Unfrozen native header: ' + path)
                if not result['build_inputs'].get('compiler'):
                    raise ValueError('Compiler identity missing')
                for path, digest in result['build_inputs']['compiler'].items():
                    if fingerprint(path)[0] != digest:
                        raise ValueError('Compiler changed: ' + path)
                if any(row.get('status') != 'exact' or row.get('data_errors') for row in result['checks']):
                    raise ValueError('Original code/data check failed')
                if len(result['checks']) != len(move['checks']):
                    raise ValueError('Missing original checks')
                for actual, expected in zip(result['checks'], move['checks']):
                    if (actual.get('addr', '').lower() != expected['addr'].lower()
                            or actual.get('requested_symbol') != expected['symbol']):
                        raise ValueError('Original check does not match reviewed spec')
                    functions = match.coff_functions(obj.read_bytes())
                    found = ([item for item in functions if item[0] == expected['symbol']] or
                             [item for item in functions if item[0].startswith(expected['symbol'])])
                    if len(found) != 1:
                        raise ValueError('Missing or ambiguous object symbol')
                    symbol, body, refs = found[0]
                    target, target_refs, _ = match.target('2008-06', expected['addr'])
                    if not set(target_refs) <= set(refs) or not match.exact_match(target, target_refs, body, refs):
                        raise ValueError('Independent original code check failed')
                    _, errors = match.data_check('2008-06', expected['addr'], target, match.coff_data_refs(obj.read_bytes(), symbol))
                    if errors:
                        raise ValueError('Independent original data check failed')
                raw.append(obj.read_bytes())
            if any(result['flags'] != pair[0]['flags'] for result in pair[1:]):
                raise ValueError('Build flags differ')
            if any(result['build_inputs'] != pair[0]['build_inputs'] for result in pair[1:]):
                raise ValueError('Build toolchain differs')
            identity = object_identity(raw[0])
            if any(object_identity(value) != identity for value in raw[1:]):
                raise ValueError('Code/data or named relocations differ')
            native = git(root, 'show', plan['base'] + ':workspace/rebuild/2008-06/' + str(old))
            public = git(root, 'show', plan['base'] + ':2008-06/' + str(old))
            if sha(native) != move['source_sha256'] or sha(public) != move['public_sha256']:
                raise ValueError('Recorded base content changed')
            if ((out / 'original' / old).read_bytes() != native or (out / 'candidate' / new).read_bytes() != native
                    or (out / 'public' / old).read_bytes() != public):
                raise ValueError('Candidate or public snapshot changed')
            if (out / 'candidate' / old).read_bytes() != compatibility_shim(old, new, native):
                raise ValueError('Compatibility source differs from reviewed wrapper')
            if not move.get('public_variant') and (out / 'public-shim' / old).read_bytes() != compatibility_shim(old, new, public):
                raise ValueError('Public compatibility source differs from reviewed wrapper')
            accepted.append(dict(move, proofs=[{key: r[key] for key in
                ('source_sha256', 'object_sha256', 'flags', 'dependencies', 'build_inputs', 'checks')}
                for r in pair]))
        except (KeyError, OSError, ValueError) as error:
            skipped.append(dict(move, reason=str(error)))
    for path, (expected, _) in fingerprints.items():
        if sha(path.read_bytes()) != expected:
            raise ValueError('Input changed during batch verification: ' + str(path))
    manifest = {'base': plan['base'], 'files': {}}
    mirror = {}
    for move in accepted:
        old, new = move['source'], move['target']
        manifest['files']['rebuild/2008-06/' + old] = str(out / 'candidate' / old)
        manifest['files']['rebuild/2008-06/' + new] = str(out / 'candidate' / new)
        if move.get('public_variant'):
            mirror['2008-06/' + new] = str(out / 'candidate' / new)
        else:
            mirror['2008-06/' + old] = str(out / 'public-shim' / old)
            mirror['2008-06/' + new] = str(out / 'public' / old)
    report = dict(base=plan['base'], header_tree=plan['header_tree'], run=str(run), accepted=accepted,
                  skipped=skipped, scope='Object equivalence and listed original code/data checks only; preservation-only moves do not prove original identity; no runtime or server credit.')
    outputs = (('review.json', report), ('integration-manifest.json', manifest), ('public-manifest.json', mirror))
    if any((out / name).exists() for name, _ in outputs):
        raise FileExistsError('Refusing to overwrite existing review output')
    for name, value in outputs:
        path = out / name
        path.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')
    return report


def run(root, out, approved_runner, workers):
    """Compile isolated candidates with an explicitly pinned canonical runner, then verify."""
    root, out = Path(root).resolve(), Path(out).resolve()
    if not out.is_relative_to((root / 'work/native-candidates').resolve()):
        raise ValueError('Invalid candidate folder')
    plan = json.loads((out / 'plan.json').read_text(encoding='utf-8'))
    runner = git(root, 'show', plan['base'] + ':workspace/rebuild/2008-06/tests/native_check_runner.py')
    if not re.fullmatch('[0-9a-f]{64}', approved_runner) or sha(runner) != approved_runner:
        raise ValueError('Canonical runner hash does not match the reviewed hash')
    runner_file = out / 'reviewed-native-check-runner.py'
    if runner_file.exists() or (out / 'runner.log').exists():
        raise FileExistsError('Refusing to overwrite runner')
    runner_file.write_bytes(runner)
    command = '''import importlib.util, sys
from pathlib import Path
root, out, runner, workers = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3]), sys.argv[4]
sys.path.insert(0, str(root))
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
spec = importlib.util.spec_from_file_location('reviewed_native_check_runner', runner)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
module.ROOT, module.BASE = root, out / 'frozen/rebuild/2008-06'
module.RUNS = root / 'work/2008-06/native-check-runs'
sys.argv = [str(runner), 'run', str(out / 'batch.json'), '--workers', workers]
module.main()
'''
    process = subprocess.run([sys.executable, '-c', command, str(root), str(out), str(runner_file), str(workers)],
                             cwd=root, capture_output=True, text=True, encoding='utf-8', errors='replace')
    (out / 'runner.log').write_text(process.stdout + process.stderr, encoding='utf-8')
    summaries = []
    for line in process.stdout.splitlines():
        if line.startswith('{'):
            summaries.append(json.loads(line))
    if len(summaries) != 1 or not summaries[0].get('run'):
        raise ValueError('Runner did not return one complete run')
    if process.returncode and not (process.returncode == 1 and summaries[0].get('state') == 'failed'):
        raise RuntimeError('Native runner failed; inspect ' + str(out / 'runner.log'))
    return verify_with_root(root, out, summaries[0]['run'])


def verify_with_root(root, out, run_dir):
    """Use the target checkout's matching tools, even when this module is in scratch."""
    root = Path(root).resolve()
    if Path(match.ROOT).resolve() == root:
        return verify(root, out, run_dir)
    command = '''import importlib.util, json, sys
from pathlib import Path
root, source, out, run = map(Path, sys.argv[1:])
sys.path.insert(0, str(root))
spec = importlib.util.spec_from_file_location('reviewed_source_layout', source)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
print(json.dumps(module.verify(root, out, run)))
'''
    process = subprocess.run([sys.executable, '-c', command, str(root), str(Path(__file__).resolve()), str(out), str(run_dir)],
                             cwd=root, capture_output=True, text=True, encoding='utf-8', errors='replace')
    if process.returncode:
        raise RuntimeError('Bulk verification failed: ' + process.stderr[-1200:])
    return json.loads(process.stdout)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, required=True)
    actions = parser.add_subparsers(dest='action', required=True)
    s = actions.add_parser('suggest')
    s.add_argument('--base', required=True)
    s.add_argument('--target-prefix', required=True)
    s.add_argument('--checks', type=Path, required=True)
    s.add_argument('--output', type=Path, required=True)
    p = actions.add_parser('prepare')
    p.add_argument('--spec', type=Path, required=True)
    p.add_argument('--out', type=Path, required=True)
    v = actions.add_parser('verify')
    v.add_argument('--out', type=Path, required=True)
    v.add_argument('--run', type=Path, required=True)
    r = actions.add_parser('run')
    r.add_argument('--out', type=Path, required=True)
    r.add_argument('--approved-runner', required=True, help='SHA-256 of the reviewed canonical runner')
    r.add_argument('--workers', type=int, choices=range(1, 9), default=3)
    args = parser.parse_args()
    if args.action == 'suggest':
        result = suggest(args.root, args.base, args.target_prefix, json.loads(args.checks.read_text(encoding='utf-8')), args.output)
    elif args.action == 'prepare':
        result = prepare(args.root, json.loads(args.spec.read_text(encoding='utf-8')), args.out)
    elif args.action == 'verify':
        result = verify_with_root(args.root, args.out, args.run)
    else:
        result = run(args.root, args.out, args.approved_runner, args.workers)
    print(json.dumps({'action': args.action, 'moves': len(result.get('moves', result.get('accepted', []))), 'skipped': len(result.get('skipped', []))}))


if __name__ == '__main__':
    main()
