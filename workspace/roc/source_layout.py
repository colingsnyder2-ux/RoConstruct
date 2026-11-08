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
    prefix = 'workspace/rebuild/2008-06/'
    roots = ['native-headers'] + [project + '/include' for project in PROJECTS]
    listing = git(root, 'ls-tree', '-rz', base, '--', *(prefix + path for path in roots)).split(b'\0')
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
        target = output.parent.joinpath(*relative.parts)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(blobs[blob])


def trial_wrapper_bytes(root, base, name):
    if not isinstance(name, str) or str(safe(name)) != name or '/' in name or not name.endswith(('.h', '.hpp')):
        raise ValueError('Unsafe trial header name')
    expected = ('#include "../../tests/' + name + '"\n').encode()
    paths = ('workspace/rebuild/2008-06/experiments/trials/', '2008-06/experiments/trials/')
    versions = []
    for prefix in paths:
        result = subprocess.run(['git', 'show', base + ':' + prefix + name], cwd=root, capture_output=True)
        versions.append(None if result.returncode else result.stdout)
    if versions == [None, None]:
        return expected
    if versions[0] is None or versions[0] != versions[1] or versions[0].replace(b'\r\n', b'\n') != expected:
        raise ValueError('Existing trial header wrapper differs: ' + name)
    return versions[0]


def snapshot_trial_headers(root, base, out, staged):
    """Freeze sibling test headers and forward organized trial includes to them."""
    trial_sources = [native for old, _, native, _, _, _ in staged if old.startswith('tests/')]
    if not trial_sources:
        return {}, []
    prefix = 'workspace/rebuild/2008-06/tests/'
    entries = {}
    for row in git(root, 'ls-tree', '-rz', base, '--', prefix).split(b'\0'):
        if not row:
            continue
        meta, path = row.split(b'\t', 1)
        name = path.decode('utf-8')[len(prefix):]
        if '/' not in name and name.endswith(('.h', '.hpp')):
            safe(name)
            mode, kind, blob = meta.split()
            if mode not in (b'100644', b'100755') or kind != b'blob':
                raise ValueError('Non-regular test header: ' + name)
            entries[name] = blob.decode()
    used = set()
    for source in trial_sources:
        used.update(name.decode() for name in re.findall(rb'(?m)^\s*#\s*include\s*"([^"/\\]+)"', source)
                    if name.decode() in entries)
    for name in sorted(used):
        public = git(root, 'rev-parse', base + ':2008-06/tests/' + name).decode().strip()
        if public != entries[name]:
            raise ValueError('Public trial header differs: ' + name)
        trial_wrapper_bytes(root, base, name)
    for name, blob in entries.items():
        content = git(root, 'cat-file', 'blob', blob)
        for tree in ('original', 'candidate'):
            target = out / tree / 'tests' / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(content)
    for name in sorted(used):
        target = out / 'candidate/experiments/trials' / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(trial_wrapper_bytes(root, base, name))
    return entries, sorted(used)


def checked_base(root, base):
    if not re.fullmatch('[0-9a-f]{40}', base):
        raise ValueError('Base must be an exact commit ID')
    if git(root, 'rev-parse', base + '^{commit}').decode().strip() != base:
        raise ValueError('Base is not the requested commit')


def inspect_move(root, base, row):
    old, new = safe(row['source']), safe(row['target'])
    source_ok = (len(old.parts) == 2 or (len(old.parts) >= 4 and old.parts[1] == 'accepted'))
    native = (source_ok and old.parts[0] == 'native-classes' and old.suffix == '.cpp'
              and len(new.parts) >= 3 and new.parts[0] in PROJECTS and new.parts[1] == 'src'
              and (bool(row.get('checks')) or row.get('preservation_only') is True))
    trial = (len(old.parts) == 2 and old.parts[0] == 'tests' and old.name.endswith('Trial.cpp')
             and len(new.parts) == 3 and new.parts[:2] == ('experiments', 'trials')
             and row.get('preservation_only') is True and not row.get('checks'))
    if new.name != old.name or not (native or trial):
        raise ValueError('Move needs a native source or inactive trial, matching destination and required evidence')
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
    trial_headers, trial_wrappers = snapshot_trial_headers(root, base, out, staged)
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
                runner_sha256=sha(git(root, 'show', base + ':workspace/rebuild/2008-06/tests/native_check_runner.py')), moves=records,
                trial_headers=trial_headers, trial_wrappers=trial_wrappers)
    (out / 'plan.json').write_text(json.dumps(plan, indent=2) + '\n', encoding='utf-8')
    (out / 'batch.json').write_text(json.dumps({'jobs': jobs}, indent=2) + '\n', encoding='utf-8')
    return plan


def local_symbol_identities(symbols):
    """Normalize one file-local MSVC namespace only for uniquely defined targets."""
    pattern = re.compile(r'\?A0x[0-9a-fA-F]{8}@@')
    tags = {tag for name, _, _, _ in symbols.values() for tag in pattern.findall(name)}
    if len(tags) != 1:
        return {}
    grouped = {}
    for name, value, section, kind in symbols.values():
        if pattern.search(name):
            grouped.setdefault(name, set()).add((section, value, kind))
    return {name: (pattern.sub('?A0xLOCAL@@', name), *next(iter(locations)))
            for name, locations in grouped.items()
            if len(locations) == 1 and next(iter(locations))[0] > 0}


def object_identity(raw):
    sections, symbols, _, _ = match._coff_data_index(raw)
    local = local_symbol_identities(symbols)
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
            symbol_name = symbols[sym][0]
            relocs.append((offset, local.get(symbol_name, (symbol_name,)), kind))
        result.append((name, section[9], data, relocs))
    # Full section bytes and relocations above already cover each function body.
    # Retain every defined function symbol and location without disassembling it.
    functions = [(local.get(name, (name,)), value, section, kind)
                 for name, value, section, kind in symbols.values()
                 if section > 0 and kind == 0x20 and not sections[section - 1][-1] & 0x800]
    return result, functions


def validate_public_package(root, base, package):
    """Fail closed if any existing public package entry is missing or stale."""
    files = package.get('files')
    if not isinstance(files, dict):
        raise ValueError('Public package lacks a file inventory')
    prefix = '2008-06/'
    blobs = {}
    for line in git(root, 'ls-tree', '-rz', base, '--', prefix).split(b'\0'):
        if not line:
            continue
        meta, path = line.split(b'\t', 1)
        mode, kind, blob = meta.split()
        name = path.decode('utf-8')[len(prefix):]
        if name in files:
            if mode not in (b'100644', b'100755') or kind != b'blob':
                raise ValueError('Non-regular public package entry: ' + name)
            blobs[name] = blob.decode()
    for name in files:
        safe(name)
        if name not in blobs:
            raise ValueError('Missing public package entry: ' + name)
    ids = sorted(set(blobs.values()))
    data = io.BytesIO(git(root, 'cat-file', '--batch', data=('\n'.join(ids) + '\n').encode()))
    hashes = {}
    for blob in ids:
        head = data.readline().split()
        if len(head) != 3 or head[0].decode() != blob or head[1] != b'blob':
            raise ValueError('Public package blob mismatch')
        content = data.read(int(head[2]))
        if data.read(1) != b'\n':
            raise ValueError('Truncated public package blob')
        hashes[blob] = sha(content)
    for name, blob in blobs.items():
        if files[name] != hashes[blob]:
            raise ValueError('Public package entry is stale: ' + name)


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
    prefix = 'workspace/rebuild/2008-06/'
    roots = ['native-headers'] + [project + '/include' for project in PROJECTS]
    header_blobs = {}
    for line in git(root, 'ls-tree', '-rz', plan['base'], '--', *(prefix + path for path in roots)).split(b'\0'):
        if line:
            meta, path = line.split(b'\t', 1)
            mode, kind, blob = meta.split()
            if mode not in (b'100644', b'100755') or kind != b'blob':
                raise ValueError('Non-regular canonical header')
            header_blobs[path.decode()[len(prefix):]] = blob.decode()
    frozen = (out / 'frozen/rebuild/2008-06').resolve()
    trial_headers = plan.get('trial_headers', {})
    trial_wrappers = set(plan.get('trial_wrappers', []))
    wrapper_contents = {name: trial_wrapper_bytes(root, plan['base'], name) for name in trial_wrappers}
    if trial_headers:
        prefix_tests = 'workspace/rebuild/2008-06/tests/'
        actual_headers = {}
        for row in git(root, 'ls-tree', '-rz', plan['base'], '--', prefix_tests).split(b'\0'):
            if row:
                meta, path = row.split(b'\t', 1)
                name = path.decode()[len(prefix_tests):]
                if '/' not in name and name.endswith(('.h', '.hpp')):
                    mode, kind, blob = meta.split()
                    if mode not in (b'100644', b'100755') or kind != b'blob':
                        raise ValueError('Non-regular trial header')
                    actual_headers[name] = blob.decode()
        if actual_headers != trial_headers or not trial_wrappers <= set(trial_headers):
            raise ValueError('Trial header snapshot differs from base')
    unfrozen_roots = tuple((root / 'rebuild/2008-06' / header_root).resolve() for header_root in roots)
    resolved_paths = {}
    def resolved(path):
        key = os.fspath(path)
        if key not in resolved_paths:
            resolved_paths[key] = Path(path).resolve()
        return resolved_paths[key]
    index = {str(resolved(r['source'])).casefold(): r for r in results}
    if len(index) != len(results):
        raise ValueError('Duplicate runner source')
    fingerprints = {}
    def fingerprint(path):
        path = resolved(path)
        if path not in fingerprints:
            content = path.read_bytes()
            fingerprints[path] = (sha(content), hashlib.sha1(b'blob ' + str(len(content)).encode() + b'\0' + content).hexdigest())
        return fingerprints[path]
    accepted, skipped, required_test_headers, required_trial_wrappers = [], [], set(), set()
    for move in plan['moves']:
        old, new = safe(move['source']), safe(move['target'])
        try:
            move_test_headers, move_wrappers = set(), set()
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
                if not any(resolved(path) == resolved(source) for path in result.get('dependencies', {})):
                    raise ValueError('Source dependency missing from receipt')
                for path, digest in result['dependencies'].items():
                    dependency = resolved(path)
                    dependency_sha, dependency_blob = fingerprint(dependency)
                    if dependency_sha != digest:
                        raise ValueError('Dependency changed: ' + path)
                    if dependency.is_relative_to(frozen):
                        relative = dependency.relative_to(frozen).as_posix()
                        if header_blobs.get(relative) != dependency_blob:
                            raise ValueError('Frozen header differs from canonical base: ' + path)
                    elif any(dependency.is_relative_to(header_root) for header_root in unfrozen_roots):
                        raise ValueError('Unfrozen native header: ' + path)
                    elif dependency.parent in (resolved(out / 'original/tests'), resolved(out / 'candidate/tests')) and dependency.suffix in ('.h', '.hpp'):
                        if trial_headers.get(dependency.name) != dependency_blob:
                            raise ValueError('Unverified trial header: ' + path)
                        move_test_headers.add(dependency.name)
                    elif dependency.parent == resolved(out / 'candidate/experiments/trials') and dependency.suffix in ('.h', '.hpp'):
                        expected = wrapper_contents.get(dependency.name, b'')
                        if dependency.name not in trial_wrappers or fingerprint(dependency)[0] != sha(expected):
                            raise ValueError('Unverified trial header wrapper: ' + path)
                        move_wrappers.add(dependency.name)
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
            for name in move_test_headers:
                public_blob = git(root, 'rev-parse', plan['base'] + ':2008-06/tests/' + name).decode().strip()
                if public_blob != trial_headers[name]:
                    raise ValueError('Public trial dependency differs: ' + name)
            required_test_headers.update(move_test_headers)
            required_trial_wrappers.update(move_wrappers)
            accepted.append(dict(move, proofs=[{key: r[key] for key in
                ('source_sha256', 'object_sha256', 'flags', 'dependencies', 'build_inputs', 'checks')}
                for r in pair]))
        except (KeyError, OSError, ValueError) as error:
            skipped.append(dict(move, reason=str(error)))
    for path, (expected, _) in fingerprints.items():
        if sha(path.read_bytes()) != expected:
            raise ValueError('Input changed during batch verification: ' + str(path))
    for original, target in resolved_paths.items():
        if Path(original).resolve() != target:
            raise ValueError('Input path changed during batch verification: ' + original)
    if tuple((root / 'rebuild/2008-06' / name).resolve() for name in roots) != unfrozen_roots:
        raise ValueError('Header roots changed during batch verification')
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
    for name in sorted(required_test_headers):
        path = str(out / 'original/tests' / name)
        manifest['files']['rebuild/2008-06/tests/' + name] = path
        mirror['2008-06/tests/' + name] = path
    for name in sorted(required_trial_wrappers):
        path = str(out / 'candidate/experiments/trials' / name)
        manifest['files']['rebuild/2008-06/experiments/trials/' + name] = path
        mirror['2008-06/experiments/trials/' + name] = path
    package_output = None
    if mirror:
        package = json.loads(git(root, 'show', plan['base'] + ':2008-06/package.json'))
        validate_public_package(root, plan['base'], package)
        for name, source in mirror.items():
            relative = name.removeprefix('2008-06/')
            package['files'][relative] = sha(Path(source).read_bytes())
        package['files'] = dict(sorted(package['files'].items()))
        package_output = ('public-package.json', package)
        mirror['2008-06/package.json'] = str(out / package_output[0])
    report = dict(base=plan['base'], header_tree=plan['header_tree'], run=str(run), accepted=accepted,
                  skipped=skipped, scope='Object equivalence and listed original code/data checks only; preservation-only moves do not prove original identity; no runtime or server credit.')
    outputs = (('review.json', report), ('integration-manifest.json', manifest), ('public-manifest.json', mirror))
    if package_output:
        outputs += (package_output,)
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
