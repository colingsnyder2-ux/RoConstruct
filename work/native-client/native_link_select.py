"""Select link providers only when their cached native object proves target body exact."""
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path[:0] = [str(ROOT), str(HERE)]
from roc.native_bulk import Targets
from roc import match, rebuild
import native_template_probe as probe


def provider_source(stem):
    """Native class source, or an explicitly inventoried local vendor wrapper."""
    native = ROOT / 'rebuild/2008-06/native-classes' / (stem + '.cpp')
    local = HERE / (stem + '.cpp')
    return native if native.is_file() else local if local.is_file() else None


def guid_exact(raw, row, stem, targets):
    """Only authentic typed GUID definitions, exact 16 bytes without relocations."""
    if not row['symbol'].endswith('@@3U_GUID@@B'):
        return False
    source = provider_source(stem)
    text = source.read_text() if source else ''
    name = row['symbol'][1:].split('@@', 1)[0]
    if not re.search(r'extern\s+const\s+(?:IID|CLSID|GUID)\s+' + re.escape(name) + r'\s*=\s*\{', text):
        return False
    sections, _, definitions, _ = match._coff_data_index(raw)
    if row['symbol'] not in definitions:
        return False
    offset, sec = definitions[row['symbol']]
    _, _, _, size, ptr, relocptr, _, nrel, _, flags = sections[sec]
    va = int(row['address'], 16)
    if not ptr or offset + 16 > size or flags & 0x20000000 or targets.data_relocations(va, 16):
        return False
    if any(offset <= struct.unpack_from('<I', raw, relocptr + i * 10)[0] < offset + 16 for i in range(nrel)):
        return False
    return raw[ptr + offset:ptr + offset + 16] == targets.data(va, 16)


def objects(stem, engine_abi, native_headers=False):
    if native_headers:
        path = HERE / 'obj' / (stem + '.obj')
        return [path] if path.is_file() else []
    if engine_abi:
        path = HERE / 'obj-engine-abi' / (stem + '.obj')
        return [path] if path.is_file() else []
    roots = ('claude-template-applied', 'claude-profile-applied')
    return [HERE / root / stem / 'after' / 'candidate.obj' for root in roots
            if (HERE / root / stem / 'after' / 'candidate.obj').is_file()]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--input', type=Path, default=HERE / 'claude-link-unresolved-providers.json')
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--limit', type=int, default=20)
    ap.add_argument('--engine-abi', action='store_true')
    ap.add_argument('--native-headers', action='store_true', help='compile providers with native 2008 headers, retaining engine-ABI link baseline')
    ap.add_argument('--closure-from', type=Path, help='also prove introduced dependencies from a prior family trial')
    ap.add_argument('--closed-from', type=Path, help='trial the prior batch providers with no introduced dependencies')
    ap.add_argument('--exclude', type=Path, default=HERE / 'link' / 'selected-engine-cumulative.json')
    ap.add_argument('--unresolved', type=Path, default=HERE / 'link' / 'probe.json')
    ap.add_argument('--rejected', type=Path, default=HERE / 'link' / 'selected-engine-rejected.json')
    ap.add_argument('--include-multi', action='store_true',
                    help='also inspect multi-provider rows; prefer already-linked exact provider')
    ap.add_argument('--trial-link', action='store_true', help='compare cumulative baseline and selected batch link probes')
    ap.add_argument('--provider', action='append', help='restrict to one or more source families after an input repair')
    ap.add_argument('--identity-closure', type=Path, help='add exact closure bodies for --closure-provider')
    ap.add_argument('--closure-provider', action='append', help='source family supplying --identity-closure bodies')
    ap.add_argument('--fresh-only', action='store_true', help='trial only providers compiled during this invocation')
    ap.add_argument('--reuse-current', action='store_true', help='reuse a hash-checked successful object after selector-only changes')
    args = ap.parse_args()
    if bool(args.identity_closure) != bool(args.closure_provider):
        ap.error('--identity-closure and --closure-provider must be used together')
    if args.closed_from:
        previous = json.loads(args.closed_from.read_text()).get('link_trial', {})
        if 'provider_dependencies' not in previous:
            ap.error('--closed-from needs a trial receipt with provider dependency attribution')
        args.provider = [row['source'] for row in previous['provider_dependencies'] if row['introduced_count'] == 0]
        args.trial_link = True
    if args.native_headers and not args.engine_abi:
        ap.error('--native-headers requires --engine-abi baseline')
    targets, _ = Targets('2008-06'), probe.runner()
    rows = json.loads(args.input.read_text())
    if args.identity_closure:
        unresolved_now = set(json.loads(args.unresolved.read_text()).get('unresolved', [])) if args.unresolved.is_file() else set()
        known = {(row['symbol'], tuple(row.get('providers', ()))) for row in rows}
        for binding in json.loads(args.identity_closure.read_text()).get('bindings', []):
            if not (binding.get('body_exact') and binding.get('function_start') and binding.get('symbol') in unresolved_now):
                continue
            for provider in args.closure_provider:
                row = {'symbol': binding['symbol'], 'kind': 'native-source-defines',
                       'providers': [provider], 'address': binding['addr'],
                       'identity_evidence': binding.get('evidence')}
                if (row['symbol'], tuple(row['providers'])) not in known:
                    rows.append(row)
    if args.provider is not None:
        rows = [dict(row, providers=[p for p in row.get('providers', []) if p in args.provider])
                for row in rows if set(row.get('providers', [])) & set(args.provider)]
    registry_path = ROOT / 'work/2008-06/identity-registry.json'
    registry = json.loads(registry_path.read_text()) if registry_path.is_file() else {}
    named = {r['name']: a for a, r in registry.items() if not r.get('placeholder')}
    for row in rows:
        if not row.get('address') and row['symbol'].endswith('@@3U_GUID@@B'):
            row['address'] = named.get(row['symbol'])
    guid_bindings = {row['symbol']: row for row in rows if row.get('address') and row['symbol'].endswith('@@3U_GUID@@B')}
    if args.unresolved.is_file():
        unresolved = set(json.loads(args.unresolved.read_text()).get('unresolved', []))
        if args.closure_from:
            unresolved |= set(json.loads(args.closure_from.read_text()).get('link_trial', {}).get('introduced', []))
        rows = [row for row in rows if row['symbol'] in unresolved]
    excluded = set()
    if args.exclude and args.exclude.is_file():
        excluded = {row['source'] for row in json.loads(args.exclude.read_text()).get('selected', [])}
    if args.rejected.is_file():
        excluded |= set(json.loads(args.rejected.read_text()).get('sources', []))
    eligible = lambda row: (row.get('kind') == 'native-source-defines' and row.get('address') and
                            (len(row.get('providers', [])) == 1 or args.include_multi))
    current_attempts, fingerprints, compiled_stems = {}, {}, set()
    if args.engine_abi:
        trials = HERE / 'link' / ('native-header-experimental.json' if args.native_headers else 'engine-abi-experimental.json')
        trial_data = json.loads(trials.read_text()) if trials.is_file() else {'stems': []}
        current_attempts = trial_data.setdefault('attempts', {})
        header_hash = hashlib.sha256()
        inputs = sorted(p for p in (ROOT / 'rebuild/2008-06/native-headers').rglob('*')
                        if p.is_file() and p.suffix.lower() in ('.h', '.hpp', '.inl', '.inc')) + [HERE / 'inventory_flags.py', HERE / 'inventory.py', Path(__file__)]
        for path in inputs:
            header_hash.update(str(path.relative_to(ROOT)).encode())
            header_hash.update(path.read_bytes())
        for row in rows:
            for stem in row.get('providers', []):
                source = provider_source(stem)
                if source:
                    fingerprints[stem] = hashlib.sha256(header_hash.digest() + source.read_bytes()).hexdigest()
        names, seen = [], set()
        for row in rows:
            providers = row.get('providers', [])
            if not eligible(row):
                continue
            for stem in providers:
                attempt = current_attempts.get(stem, {})
                obj = HERE / ('obj' if args.native_headers else 'obj-engine-abi') / (stem + '.obj')
                reusable = args.reuse_current and attempt.get('compile_ok') and obj.is_file() and \
                    hashlib.sha256(obj.read_bytes()).hexdigest() == attempt.get('object_sha256')
                if stem in seen or stem in excluded or stem not in fingerprints or attempt.get('fingerprint') == fingerprints[stem] or reusable:
                    continue
                source = provider_source(stem)
                # inventory compiles from its object directory, so wrappers
                # outside native-classes must be absolute source paths.
                names.append(str(source.resolve()))
                seen.add(stem)
                if len(names) == args.limit:
                    break
            if len(names) == args.limit:
                break
        # inventory.py writes a shared object cache.  Record all trial stems so
        # linkprobe cannot accidentally link a compiled-but-unproved provider.
        trial_data['stems'] = sorted(set(trial_data.get('stems', [])) | {Path(n).stem for n in names})
        trials.parent.mkdir(parents=True, exist_ok=True)
        trials.write_text(json.dumps(trial_data, indent=1) + '\n')
        env = dict(os.environ, ROC_ENGINE_ABI='0' if args.native_headers else '1')
        if names:
            compiled_stems = {Path(name).stem for name in names}
            run = subprocess.run([sys.executable, str(HERE / 'inventory.py')] + names, cwd=ROOT, env=env, check=False)
            if run.returncode:
                raise RuntimeError('provider inventory failed (exit %s)' % run.returncode)
            results = json.loads((HERE / 'inventory.json').read_text())
            for name in names:
                stem = Path(name).stem
                obj = HERE / ('obj' if args.native_headers else 'obj-engine-abi') / (stem + '.obj')
                result = results.get(Path(name).name, {})
                ok = result.get('ok', False) and obj.is_file()
                current_attempts[stem] = {'fingerprint': fingerprints[stem], 'compile_ok': ok,
                                          'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest() if ok else None,
                                          'errors': result.get('errors', [])}
            trials.write_text(json.dumps(trial_data, indent=1) + '\n')
    selected, blocked, cache = [], [], {}
    proof_version = hashlib.sha256((HERE / 'native_template_probe.py').read_bytes() +
                                   (ROOT / 'roc/match.py').read_bytes() +
                                   (ROOT / 'roc/native_bulk.py').read_bytes() +
                                   (ROOT / 'roc/native_sweep.py').read_bytes() +
                                   (ROOT / 'roc/fingerprint.py').read_bytes()).hexdigest()
    proof_folder = HERE / 'link/native-body-proof-cache'
    proof_folder.mkdir(exist_ok=True)
    used = set()
    for row in rows:
        providers = row.get('providers', [])
        if not eligible(row):
            continue
        if len(providers) == 1 and providers[0] in excluded:
            continue
        ordered = sorted(providers, key=lambda stem: (stem not in excluded, stem))
        exact, chosen, stem = False, None, None
        for candidate_stem in ordered:
            if args.fresh_only and candidate_stem not in compiled_stems:
                continue
            if args.engine_abi and candidate_stem not in excluded:
                attempt = current_attempts.get(candidate_stem, {})
                reusable = args.reuse_current and attempt.get('compile_ok') and any(
                    hashlib.sha256(obj.read_bytes()).hexdigest() == attempt.get('object_sha256')
                    for obj in objects(candidate_stem, args.engine_abi, args.native_headers))
                if (attempt.get('fingerprint') != fingerprints.get(candidate_stem) and not reusable) or not attempt.get('compile_ok'):
                    continue
            for obj in objects(candidate_stem, args.engine_abi, args.native_headers):
                if args.engine_abi and candidate_stem not in excluded and hashlib.sha256(obj.read_bytes()).hexdigest() != attempt.get('object_sha256'):
                    continue
                if row['symbol'].endswith('@@3U_GUID@@B'):
                    raw = obj.read_bytes()
                    _, _, definitions, _ = match._coff_data_index(raw)
                    guids = [name for name in definitions if name.endswith('@@3U_GUID@@B')]
                    if any(name not in guid_bindings or not guid_exact(raw, guid_bindings[name], candidate_stem, targets)
                           for name in guids):
                        continue
                key = str(obj)
                if key not in cache:
                    raw = obj.read_bytes()
                    proof_key = hashlib.sha256(raw + targets.identity.encode() + proof_version.encode()).hexdigest()
                    saved = proof_folder / (proof_key + '.json')
                    try:
                        cache[key] = json.loads(saved.read_text())
                    except (OSError, ValueError):
                        cache[key] = probe.exact(raw, targets)
                        saved.write_text(json.dumps(cache[key], sort_keys=True) + '\n')
                if row['address'] in cache[key].get(row['symbol'], []) or guid_exact(obj.read_bytes(), row, candidate_stem, targets):
                    exact, chosen, stem = True, obj, candidate_stem
                    break
            if exact:
                break
        if not exact:
            reason = 'no-current-native-object' if not any(objects(s, args.engine_abi, args.native_headers) for s in providers) else 'provider-body-not-exact'
            if args.engine_abi and all(not current_attempts.get(s, {}).get('compile_ok') for s in providers):
                reason = 'current-provider-compile-failed-or-unchecked'
            blocked.append(dict(row, reason=reason))
            continue
        if stem in excluded:
            continue
        if stem not in used and len(used) >= args.limit:
            continue
        if stem not in used:
            selected.append({'source': stem, 'object': str(chosen.relative_to(ROOT)).replace('\\', '/'),
                             'symbols': []})
            used.add(stem)
        next(item for item in selected if item['source'] == stem)['symbols'].append(
            {'symbol': row['symbol'], 'address': row['address'],
             'kind': 'data' if row['symbol'].endswith('@@3U_GUID@@B') else 'code'})
    args.output.parent.mkdir(parents=True, exist_ok=True)
    funcs = match._functions('2008-06')
    isolate_root = HERE / 'link' / 'native-isolated' / args.output.stem
    isolated = []
    for item in selected:
        raw = (ROOT / item['object']).read_bytes()
        keep = {symbol['symbol'] for symbol in item['symbols']}
        trimmed = rebuild.strip_symbols(raw, keep=keep)
        _, _, definitions, _ = match._coff_data_index(trimmed)
        # `$LN*` is VS2008's local EH/debug label spelling.  It cannot satisfy
        # another object and has no target identity; all named link externals
        # remain subject to the strict residual-definition gate.
        extras = sorted(name for name in definitions if name not in keep and not name.startswith('$'))
        if extras:
            blocked.extend({'symbol': symbol['symbol'], 'kind': symbol['kind'],
                            'providers': [item['source']], 'address': symbol['address'],
                            'reason': 'isolation-left-unproved-definitions', 'definitions': extras[:12]}
                           for symbol in item['symbols'])
            continue
        proof = probe.exact(trimmed, targets)
        lost = [symbol['symbol'] for symbol in item['symbols']
                if symbol['kind'] == 'code' and symbol['address'] not in proof.get(symbol['symbol'], [])]
        if lost:
            blocked.extend({'symbol': symbol['symbol'], 'kind': symbol['kind'],
                            'providers': [item['source']], 'address': symbol['address'],
                            'reason': 'isolation-reproof-failed', 'lost': lost[:12]}
                           for symbol in item['symbols'])
            continue
        path = isolate_root / (item['source'] + '.obj')
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(trimmed)
        copy = dict(item, object=str(path.relative_to(ROOT)).replace('\\', '/'))
        isolated.append(copy)
    selected = isolated
    code_addresses = {symbol['address'] for item in selected for symbol in item['symbols'] if symbol['kind'] == 'code'}
    proved_bytes = sum(funcs.get(addr, {}).get('size', 0) for addr in code_addresses)
    args.output.write_text(json.dumps({'selected': selected, 'blocked': blocked,
                                       'candidate_proved_code_bytes': proved_bytes,
                                       'newly_compiled_sources': sorted(compiled_stems),
                                       'isolated_sources': [item['source'] for item in selected],
                                       'scope': 'cached native object direct body equality; link selection only'}, indent=1) + '\n')
    print(json.dumps({'sources': len(selected), 'symbols': sum(len(x['symbols']) for x in selected),
                      'blocked': len(blocked)}))
    if args.trial_link and selected:
        env = dict(os.environ)
        if args.engine_abi:
            env['ROC_ENGINE_ABI'] = '1'
        baseline = str(args.exclude.resolve()) if args.exclude and args.exclude.is_file() else ''
        probes = []
        for receipts in (baseline, os.pathsep.join(p for p in (baseline, str(args.output.resolve())) if p)):
            env['ROC_LINK_EXTRA'] = receipts
            run = subprocess.run([sys.executable, str(HERE / 'linkprobe.py')], cwd=ROOT, env=env,
                                 text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            if run.returncode:
                raise RuntimeError('link probe failed: ' + run.stdout[-2000:])
            result = json.loads((HERE / 'link/probe.json').read_text())
            if result.get('link_exit_code') not in (0, 1120):
                raise RuntimeError('link trial has a non-unresolved linker error: ' + str(result.get('link_exit_code')))
            probes.append(result)
        before, after = probes
        resolved = sorted(set(before['unresolved']) - set(after['unresolved']))
        introduced = sorted(set(after['unresolved']) - set(before['unresolved']))
        comparison = {'unresolved_before': len(before['unresolved']), 'unresolved_after': len(after['unresolved']),
                      'resolved': resolved, 'introduced': introduced, 'duplicates': after['duplicates'],
                      'net_gain': len(resolved) - len(introduced),
                      'eligible_for_selection': len(resolved) > len(introduced) and not after['duplicates'],
                      'runtime_executed': False}
        attribution = []
        for item in selected:
            raw = (ROOT / item['object']).read_bytes()
            _, symbols, _, _ = match._coff_data_index(raw)
            undefined = {name for name, value, sec, typ in symbols.values() if sec == 0 and value == 0}
            deps = sorted(undefined & set(introduced))
            attribution.append({'source': item['source'], 'introduced_dependencies': deps,
                                'introduced_count': len(deps)})
        comparison['provider_dependencies'] = attribution
        receipt = json.loads(args.output.read_text())
        receipt['link_trial'] = comparison
        args.output.write_text(json.dumps(receipt, indent=1) + '\n')
        print(json.dumps({key: comparison[key] for key in ('unresolved_before', 'unresolved_after', 'net_gain', 'eligible_for_selection')} |
                         {'resolved_count': len(resolved), 'introduced_count': len(introduced),
                          'duplicate_count': len(after['duplicates']), 'receipt': str(args.output)}))
        if not comparison['eligible_for_selection']:
            env['ROC_LINK_EXTRA'] = baseline
            restore = subprocess.run([sys.executable, str(HERE / 'linkprobe.py')], cwd=ROOT, env=env,
                                     text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            if restore.returncode:
                raise RuntimeError('baseline restore failed: ' + restore.stdout[-2000:])
            restored = json.loads((HERE / 'link/probe.json').read_text())
            if restored['unresolved'] != before['unresolved'] or restored['duplicates'] != before['duplicates']:
                raise RuntimeError('baseline input state changed during rejected trial')


if __name__ == '__main__':
    main()
