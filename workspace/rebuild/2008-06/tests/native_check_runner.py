"""Background native diagnostics: compile each source once, reuse isolated objects.

start MANIFEST launches hidden background work; status RUN reads a compact receipt.
run MANIFEST runs in foreground. analyze RUN [--manifest MANIFEST] compares the
recorded objects again WITHOUT compiling. Manifest: {"jobs":[{"source":
"native-classes/Foo.cpp","checks":[{"addr":"00500000","symbol":"?foo@"}],
"ranges":["00500000-00510000"],"layouts":[{"addr":"00500000","symbol":"?foo@",
"thiscall":true}]}]}. Source paths relative to rebuild/2008-06; other CLI paths
relative to cwd. Three workers default. No cross-run compile cache, client run,
link, server match or P5/P6 gate. Range hits prove masked bytes, not identity.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import struct
import sys
import time
import uuid

ROOT = Path(__file__).resolve().parents[3]
BASE = ROOT / 'rebuild/2008-06'
RUNS = ROOT / 'work/2008-06/native-check-runs'
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild, native_work


# Original IWorkspace COM slots (IDispatch + SaveToFile/SaveSelectionToFile).
# See record_native_workspace_save.py; verify the original slot before trusting a label.
METHOD_IDENTITIES = {
    '?SaveToFile@CWorkspace@@UAGJPA_W@Z': ('0046c780', 0x80ae88),
    '?SaveSelectionToFile@CWorkspace@@UAGJPA_W@Z': ('0046b8d0', 0x80ae8c),
}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def save(path, value):
    temporary = path.with_name(path.name + '.' + uuid.uuid4().hex + '.tmp')
    temporary.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')
    os.replace(temporary, path)


def jobs_from(data):
    jobs = {}
    if not data.get('jobs'):
        raise ValueError('manifest needs nonempty jobs')
    for item in data['jobs']:
        source = (BASE / item['source']).resolve()
        if not source.is_file():
            raise ValueError('missing source: ' + str(source))
        job = jobs.setdefault(str(source).casefold(), {'source': str(source), 'checks': [], 'ranges': [], 'layouts': []})
        for field in ('checks', 'ranges', 'layouts'):
            for value in item.get(field, []):
                if field == 'ranges':
                    lo, hi = (int(s, 16) for s in value.split('-'))
                    if lo >= hi:
                        raise ValueError('range needs LO < HI')
                else:
                    int(value['addr'], 16)
                    if not value.get('symbol'):
                        raise ValueError('check/layout needs symbol')
                    if field == 'layouts' and value.get('thiscall') is not True:
                        raise ValueError('layout needs explicit thiscall=true')
                if value not in job[field]:
                    job[field].append(value)
    return list(jobs.values())


def compiler_flags(source, override=None):
    recipe = libs.RECIPES['rbxgs']
    headers = str(BASE / 'native-headers')
    pinned = re.search(r'^// native-flags: (.*)$', source.read_text(encoding='utf-8-sig'), re.M)
    profile = override or os.environ.get('NATIVE_FLAGS') or (pinned[1] if pinned else '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS')
    flags = ['/nologo', '/c'] + profile.replace('{headers}', headers).split()
    # Runner owns output paths; reject overrides that could collide with other work.
    if any(flag.lower().startswith(('/fo', '/fd', '/yc', '/yu'))
           or flag.lower().startswith('/fp') and not flag.lower().startswith('/fp:')
           or flag.lower().startswith('/fa') and not flag.lower().startswith('/favor:')
           or flag.startswith('@') for flag in flags):
        raise ValueError('profile output/PCH/response flags unsupported in isolated runner')
    flags = ['/DBOOST_ALL_NO_LIB'] + ['/D' + v for v in recipe['defines'].split()] + flags
    flags += ['/I' + headers, '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
    flags += ['/I' + str((libs.LIBS / v).resolve()) for v in recipe['include'] if v != 'WINSDK']
    return flags + ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK', '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]


def check_calls(raw, symbol, body, target, address, expected):
    """Assert reviewed direct-call bindings; indirect calls remain explicit blockers.

    Expected rows are {offset: instruction offset, target: original hex VA,
    symbol: exact decorated COFF name}. This proves bindings, not callee ABI.
    """
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL
    from capstone.x86 import X86_OP_IMM
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    refs = {}
    for index in range(table[7]):
        offset, name, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * index)
        if start <= offset < start + len(body):
            refs[offset - start] = (symbols[name][0], kind)
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    declarations = {row['offset']: row for row in expected}
    if len(declarations) != len(expected):
        raise ValueError('duplicate call expectation offset')
    rows = []
    for instruction in decoder.disasm(target, address):
        if not instruction.group(CS_GRP_CALL):
            continue
        offset = instruction.address - address
        direct = instruction.operands[0].type == X86_OP_IMM
        destination = instruction.operands[0].imm if direct else None
        binding = refs.get(offset + 1)
        wanted = declarations.pop(offset, None)
        ok = bool(direct and instruction.bytes[0] == 0xe8 and binding and binding[1] == 20
                  and wanted and binding[0] == wanted['symbol']
                  and destination == int(wanted['target'], 16)
                  and body[offset + 1:offset + 5] == b'\0\0\0\0')
        rows.append({'offset': offset, 'target': f'{destination:08x}' if direct else None,
                     'symbol': binding[0] if binding else None,
                     'status': 'verified_binding' if ok else 'unresolved_or_wrong_binding'})
    return {'passed': not declarations and all(row['status'] == 'verified_binding' for row in rows),
            'calls': rows, 'unused_expectations': list(declarations.values()),
            'scope': 'Reviewed direct-call symbol/address bindings only; indirect calls, provider selection and callee ABI require separate proof.'}


def analyze_object(job, obj):
    raw = obj.read_bytes()
    bodies = match.coff_functions(raw)
    checks, coverage, layouts = [], [], []
    for check in job['checks']:
        check_started = time.monotonic()
        addr = f"{int(check['addr'], 16):08x}"
        target, refs, _ = match.target('2008-06', addr)
        found = [b for b in bodies if b[0] == check['symbol']] or [b for b in bodies if b[0].startswith(check['symbol'])]
        row = {'addr': addr, 'requested_symbol': check['symbol'], 'status': 'missing'}
        if len(found) > 1:
            row.update(status='ambiguous', candidates=[f[0] for f in found])
        elif found:
            name, body, relocs = found[0]
            exact = set(refs) <= set(relocs) and match.exact_match(target, refs, body, relocs)
            row.update(symbol=name, status='exact' if exact else 'different', score=match.score(target, refs, body, relocs),
                       target_size=len(target), object_size=len(body), target_sha256=hashlib.sha256(target).hexdigest())
            masked = set(refs) | set(relocs)
            row['first_byte_difference'] = next((i for i in range(min(len(target), len(body)))
                if not any(r <= i < r + 4 for r in masked) and target[i] != body[i]),
                min(len(target), len(body)) if len(target) != len(body) else None)
            identity = METHOD_IDENTITIES.get(name)
            if identity:
                expected, slot = identity
                image_base, image = match._image('2008-06')
                original = struct.unpack_from('<I', image, slot - image_base)[0]
                passed = addr == expected and original == int(expected, 16)
                row['method_identity'] = dict(expected=expected, vtable_slot=f'{slot:08x}',
                                              original_slot_target=f'{original:08x}', passed=passed)
                if not passed:
                    row.update(status='method_identity_mismatch', masked_byte_score=row['score'], score=0)
                    exact = False
            if exact:
                data_matches, data_errors = match.data_check('2008-06', addr, target, match.coff_data_refs(raw, name))
                row.update(data_matches=data_matches, data_errors=data_errors)
                if 'calls' in check:
                    row['call_identity'] = check_calls(raw, name, body, target, int(addr, 16), check['calls'])
        row['check_seconds'] = round(time.monotonic() - check_started, 6)
        checks.append(row)
    if job['ranges']:
        functions = [json.loads(line) for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()]
        for interval in job['ranges']:
            lo, hi = (int(v, 16) for v in interval.split('-'))
            hits, missing = [], []
            for function in functions:
                addr = function['addr']
                if not lo <= int(addr, 16) < hi or function.get('kind', 'code') != 'code':
                    continue
                target, refs, _ = match.target('2008-06', addr)
                names = [name for name, body, relocs in bodies if len(body) == len(target) and set(refs) <= set(relocs) and match.exact_match(target, refs, body, relocs)]
                if names:
                    hits.append({'addr': addr, 'symbols': names, 'size': len(target)})
                else:
                    missing.append({'addr': addr, 'size': len(target)})
            coverage.append({'range': interval, 'hits': hits, 'missing': missing,
                             'scope': 'masked-byte analogs; symbol identity and call bindings unproven'})
    if job['layouts']:
        import native_layout_evidence as layout
        for check in job['layouts']:
            hits = [b for b in bodies if b[0] == check['symbol']] or [b for b in bodies if b[0].startswith(check['symbol'])]
            if len(hits) != 1:
                raise ValueError('layout symbol missing/ambiguous: ' + check['symbol'])
            name, body, refs = hits[0]
            address = int(check['addr'], 16)
            target, target_refs, _ = match.target('2008-06', f'{address:08x}')
            original, candidate = layout.extract(target, address, target_refs), layout.extract(body, address, refs)
            layouts.append({'addr': check['addr'], 'symbol': name, 'target': original, 'candidate': candidate,
                            'comparison': layout.compare(original, candidate),
                            'call_obligations': layout.call_obligations(raw, name, body, refs, target, target_refs, address),
                            'scope': layout.__doc__})
    return {'checks': checks, 'coverage': coverage, 'layouts': layouts}


def build_inputs(tc):
    compiler = Path(tc['cl']) if tc.get('cl') else None
    paths = [compiler] + [compiler.with_name(name) for name in ('c1.dll', 'c1xx.dll', 'c2.dll')] if compiler else []
    if tc.get('mspdb'):
        paths.append(Path(tc['mspdb']))
    return dict(compiler={str(p): sha(p) for p in paths if p.is_file()},
                includes={k: str(tc[k]) if tc.get(k) else None for k in ('vc_include', 'atlmfc_include', 'sdk_include')})


def build_changes(receipt, tc):
    changed = []
    if not receipt.get('build_inputs'):
        changed.append('build configuration unrecorded; historical evidence only')
    elif receipt['build_inputs'] != build_inputs(tc):
        changed.append('compiler/toolchain inputs changed')
    # An explicit current override selects a new configuration. Otherwise reuse
    # the captured override, even after the original shell environment ended.
    override = os.environ.get('NATIVE_FLAGS') or receipt.get('native_flags')
    if compiler_flags(Path(receipt['source']), override) != receipt.get('flags'):
        changed.append('compiler flags changed')
    return changed


def compile_job(job, folder, tc):
    folder.mkdir()
    started = time.time_ns()
    clock = time.monotonic()
    source = Path(job['source'])
    result = {'source': str(source), 'status': 'failed', 'object': str(folder / 'candidate.obj')}
    try:
        exhausted = native_work.over_budget(job.get('checks', []))
        if exhausted:
            result['error'] = 'function budget exhausted; park or finish session: ' + ', '.join(exhausted)
            return result
        before = sha(source)
        flags = compiler_flags(source)
        result.update(build_inputs=build_inputs(tc), native_flags=os.environ.get('NATIVE_FLAGS'))
        compile_started = time.monotonic()
        code, log = rebuild.run(tc, 'cl', flags + ['/showIncludes', '/Fo' + result['object'], '/Fd' + str(folder / 'compiler.pdb'), str(source)], folder)
        result['compile_seconds'] = round(time.monotonic() - compile_started, 3)
        (folder / 'compile.log').write_text(log, encoding='utf-8')
        result.update(compiler_exit=code, source_sha256=before, flags=flags, log=str(folder / 'compile.log'))
        if code:
            result['error'] = 'compiler failed; see compile.log'
            return result
        dependencies = {source}
        for line in log.splitlines():
            hit = re.match(r'\s*Note: including file:\s*(.*?)\s*$', line)
            if hit:
                dependencies.add(Path(hit[1]).resolve())
        result['dependencies'] = {str(p): sha(p) for p in sorted(dependencies)}
        # Fingerprints are evidence, not a cache key. No reuse of changed builds.
        changed = [str(p) for p in dependencies if p != source and p.stat().st_mtime_ns >= started]
        changed += build_changes(result, tc)
        if sha(source) != before or changed:
            result.update(error='inputs changed during compile; rerun', changed_inputs=changed)
            return result
        obj = Path(result['object'])
        result['object_sha256'] = sha(obj)
        analysis_started = time.monotonic()
        result.update(analyze_object(job, obj), status='complete')
        result['analysis_seconds'] = round(time.monotonic() - analysis_started, 3)
        return result
    except Exception as error:
        result['error'] = f'{type(error).__name__}: {error}'
        return result
    finally:
        result['seconds'] = round(time.monotonic() - clock, 3)
        save(folder / 'receipt.json', result)


def compact(results):
    checks = [row for result in results if result['status'] == 'complete' for row in result.get('checks', [])]
    ranges = {}
    for result in results:
        for coverage in result.get('coverage', []):
            group = ranges.setdefault(coverage['range'], {'functions': {}, 'hits': set()})
            for row in coverage['hits'] + coverage['missing']:
                group['functions'][row['addr']] = row['size']
            group['hits'].update(row['addr'] for row in coverage['hits'])
    return {'compiled_sources': len(results), 'failed_sources': sum(r['status'] != 'complete' for r in results),
            'compile_seconds_sum': round(sum(r.get('compile_seconds', 0) for r in results), 3),
            'analysis_seconds_sum': round(sum(r.get('analysis_seconds', 0) for r in results), 3),
            'exact_checks': sum(r['status'] == 'exact' for r in checks), 'checks': len(checks),
            'data_checked': sum('data_errors' in r for r in checks),
            'verified_checks': sum(r['status'] == 'exact' and 'data_errors' in r and not r['data_errors'] for r in checks),
            'binding_verified_checks': sum(r['status'] == 'exact' and 'data_errors' in r and not r['data_errors']
                                           and r.get('call_identity', {}).get('passed', False) for r in checks),
            'data_mismatches': [r for r in checks if r.get('data_errors')][:8],
            'issues': [{'source': r['source'], 'error': r['error']} for r in results if r.get('error')][:8],
            'mismatches': [r for r in checks if r['status'] != 'exact'][:8],
            'coverage': [{'range': interval, 'matched_functions': len(group['hits']), 'functions': len(group['functions']),
                          'matched_bytes': sum(group['functions'][addr] for addr in group['hits']),
                          'scope': 'masked-byte analogs, not identity proof'} for interval, group in ranges.items()]}


def execute(run, workers):
    # Exclusive claim: two foreground/background workers never share a run.
    with (run / 'claim').open('x') as claim:
        claim.write(str(os.getpid()))
    data = json.loads((run / 'manifest.json').read_text())
    jobs = data['jobs']
    headers = native_work.headers()
    save(run / 'shared-headers.json', headers)
    summary = {'state': 'running', 'pid': os.getpid(), 'run': str(run), 'total_sources': len(jobs), 'completed_sources': 0,
               'observer_sha256': sha(Path(__file__)), 'manifest_sha256': sha(run / 'manifest.json'),
               'work_log_sha256': sha(native_work.__file__),
               'timing_log': str(run / 'function-timings.jsonl'),
               'scope': 'local diagnostics only; fresh compile per source, no ABI/server/P5/P6 gate proof; complete means finished; inspect exact_checks and data_mismatches'}
    save(run / 'summary.json', summary)
    started, results = time.monotonic(), []
    try:
        tc = rebuild.toolchain(21022)
        summary['compiler'] = str(tc['cl'])
        summary['compiler_sha256'] = sha(tc['cl'])
        with ThreadPoolExecutor(max_workers=workers) as pool:
            futures = {pool.submit(compile_job, job, run / f'unit-{index:03}', tc): index for index, job in enumerate(jobs)}
            for future in as_completed(futures):
                result = future.result()
                result['unit'] = futures[future]
                results.append(result)
                summary.update(completed_sources=len(results), **compact(results))
                summary['updated_at_ns'] = time.time_ns()
                save(run / 'summary.json', summary)
        drift = native_work.changed(headers, native_work.headers())
        for result in results:
            dependencies = result.get('dependencies', {})
            changed = [p for p, digest in dependencies.items() if not Path(p).exists() or sha(p) != digest]
            if drift or changed:
                result.update(status='failed', changed_inputs=sorted(set(drift + changed)),
                              error='inputs changed across batch; do not accept mixed-header evidence')
        summary.update(**compact(results), shared_headers_changed=drift)
        summary['state'] = 'failed' if any(r['status'] != 'complete' for r in results) else 'complete'
    except Exception as error:
        summary.update(state='failed', error=f'{type(error).__name__}: {error}')
    summary['seconds'] = round(time.monotonic() - started, 3)
    for result in results:
        native_work.log_checks(run, jobs[result['unit']], result)
    summary['results'] = str(run / 'results.json')
    save(run / 'results.json', sorted(results, key=lambda r: r['unit']))
    save(run / 'summary.json', summary)
    return summary


def alive(pid):
    if os.name != 'nt':
        try:
            os.kill(pid, 0)
            return True
        except ProcessLookupError:
            return False
        except PermissionError:
            return None
    import ctypes
    from ctypes import wintypes
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel.OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
    kernel.OpenProcess.restype = wintypes.HANDLE
    kernel.GetExitCodeProcess.argtypes = [wintypes.HANDLE, ctypes.POINTER(wintypes.DWORD)]
    kernel.CloseHandle.argtypes = [wintypes.HANDLE]
    handle = kernel.OpenProcess(0x1000, False, pid)
    if not handle:
        return None if ctypes.get_last_error() == 5 else False
    try:
        code = wintypes.DWORD()
        if not kernel.GetExitCodeProcess(handle, ctypes.byref(code)):
            return None
        return code.value == 259
    finally:
        kernel.CloseHandle(handle)


def display(run):
    summary = json.loads((run / 'summary.json').read_text())
    launcher = run / 'launcher.json'
    pid = summary.get('pid') or (json.loads(launcher.read_text())['pid'] if launcher.exists() else None)
    if summary['state'] in ('queued', 'running') and pid and alive(pid) is False:
        summary = json.loads((run / 'summary.json').read_text())
        if summary['state'] in ('queued', 'running'):
            summary.update(state='failed', error='worker exited without terminal receipt; inspect worker.log')
    print(json.dumps(summary, separators=(',', ':')))
    return summary


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('start', 'run', 'status', 'analyze', '_worker'))
    parser.add_argument('input', type=Path, help='manifest for start/run; run directory otherwise')
    parser.add_argument('--manifest', type=Path, help='analyze: replacement comparisons against existing objects')
    parser.add_argument('--workers', type=int, choices=range(1, 9), default=3)
    parser.add_argument('--require-proof', action='store_true', help='run/analyze: fail unless every explicit check has fresh exact bytes, data and reviewed call bindings')
    args = parser.parse_args()
    if args.require_proof and args.action not in ('run', 'analyze'):
        parser.error('--require-proof supports foreground run/analyze only')
    if args.action in ('start', 'run'):
        jobs = jobs_from(json.loads(args.input.read_text(encoding='utf-8-sig')))
        RUNS.mkdir(parents=True, exist_ok=True)
        run = RUNS / (time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
        run.mkdir()
        save(run / 'manifest.json', {'jobs': jobs})
        save(run / 'summary.json', {'state': 'queued', 'run': str(run), 'total_sources': len(jobs)})
        if args.action == 'start':
            try:
                with (run / 'worker.log').open('w') as log:
                    options = {'creationflags': subprocess.CREATE_NO_WINDOW | subprocess.CREATE_NEW_PROCESS_GROUP} if os.name == 'nt' else {'start_new_session': True}
                    child = subprocess.Popen([sys.executable, str(Path(__file__).resolve()), '_worker', str(run), '--workers', str(args.workers)], cwd=ROOT,
                                             stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT, close_fds=True, **options)
            except OSError as error:
                save(run / 'summary.json', {'state': 'failed', 'run': str(run), 'error': str(error)})
                raise
            save(run / 'launcher.json', {'pid': child.pid})
        else:
            execute(run, args.workers)
        summary = display(run)
    elif args.action == 'analyze':
        run = args.input.resolve()
        jobs = jobs_from(json.loads((args.manifest or run / 'manifest.json').read_text(encoding='utf-8-sig')))
        receipts = {r['source'].casefold(): r for r in json.loads((run / 'results.json').read_text())}
        results = []
        tc = rebuild.toolchain(21022)
        for job in jobs:
            receipt = receipts[job['source'].casefold()]
            obj = Path(receipt['object'])
            if receipt['status'] != 'complete' or sha(obj) != receipt['object_sha256']:
                raise ValueError('recorded object failed or changed: ' + str(obj))
            changed = [p for p, digest in receipt['dependencies'].items() if not Path(p).exists() or sha(p) != digest]
            changed += build_changes(receipt, tc)
            results.append({'source': job['source'], 'object': str(obj), 'changed_inputs': changed,
                            'scope': 'recorded object analysis only; not a fresh build', **analyze_object(job, obj)})
            native_work.log_checks(run, job, results[-1], mode='analyze')
        # Analysis can take seconds. Inputs must still match after the whole batch.
        for result in results:
            receipt = receipts[result['source'].casefold()]
            expected = dict(receipt['dependencies'])
            expected[receipt['object']] = receipt['object_sha256']
            result['changed_inputs'] = sorted(set(result['changed_inputs']) | set(build_changes(receipt, tc)) | {
                p for p, digest in expected.items() if not Path(p).exists() or sha(p) != digest})
        output = run / ('analysis-' + uuid.uuid4().hex[:8] + '.json')
        save(output, results)
        print(json.dumps({'state': 'analyzed', 'sources': len(results), 'changed_input_sources': sum(bool(r['changed_inputs']) for r in results), 'results': str(output)}))
        if args.require_proof:
            require_proof(results)
        return
    elif args.action == '_worker':
        execute(args.input.resolve(), args.workers)
        return
    else:
        summary = display(args.input.resolve())
    if summary['state'] == 'failed':
        raise SystemExit(1)
    if args.require_proof:
        require_proof(json.loads((Path(summary['run']) / 'results.json').read_text()))


def require_proof(results):
    checks = [row for result in results for row in result.get('checks', [])]
    if (not checks or any(result.get('status', 'complete') != 'complete' or result.get('changed_inputs') for result in results)
            or any(row['status'] != 'exact' or 'data_errors' not in row or row['data_errors']
                   or not row.get('call_identity', {}).get('passed', False) for row in checks)):
        raise SystemExit('proof incomplete; inspect saved receipt (no ABI/runtime/server credit)')


if __name__ == '__main__':
    main()
