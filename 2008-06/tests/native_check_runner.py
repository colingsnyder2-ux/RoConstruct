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
import sys
import time
import uuid

ROOT = Path(__file__).resolve().parents[3]
BASE = ROOT / 'rebuild/2008-06'
RUNS = ROOT / 'work/2008-06/native-check-runs'
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild


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


def compiler_flags(source):
    recipe = libs.RECIPES['rbxgs']
    headers = str(BASE / 'native-headers')
    pinned = re.search(r'^// native-flags: (.*)$', source.read_text(encoding='utf-8-sig'), re.M)
    profile = os.environ.get('NATIVE_FLAGS') or (pinned[1] if pinned else '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS')
    flags = ['/nologo', '/c'] + profile.replace('{headers}', headers).split()
    # Runner owns output paths; reject overrides that could collide with other work.
    if any(flag.lower().startswith(('/fo', '/fd', '/yc', '/yu'))
           or flag.lower().startswith('/fp') and not flag.lower().startswith('/fp:')
           or flag.lower().startswith('/fa') and not flag.lower().startswith('/favor:')
           or flag.startswith('@') for flag in flags):
        raise ValueError('profile output/PCH/response flags unsupported in isolated runner')
    flags += ['/DBOOST_ALL_NO_LIB'] + ['/D' + v for v in recipe['defines'].split()]
    flags += ['/I' + headers, '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
    flags += ['/I' + str((libs.LIBS / v).resolve()) for v in recipe['include'] if v != 'WINSDK']
    return flags + ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK', '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]


def analyze_object(job, obj):
    raw = obj.read_bytes()
    bodies = match.coff_functions(raw)
    checks, coverage, layouts = [], [], []
    for check in job['checks']:
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
            if exact:
                data_matches, data_errors = match.data_check('2008-06', addr, target, match.coff_data_refs(raw, name))
                row.update(data_matches=data_matches, data_errors=data_errors)
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


def compile_job(job, folder, tc):
    folder.mkdir()
    started = time.time_ns()
    source = Path(job['source'])
    result = {'source': str(source), 'status': 'failed', 'object': str(folder / 'candidate.obj')}
    try:
        before = sha(source)
        flags = compiler_flags(source)
        code, log = rebuild.run(tc, 'cl', flags + ['/showIncludes', '/Fo' + result['object'], '/Fd' + str(folder / 'compiler.pdb'), str(source)], folder)
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
        if sha(source) != before or changed:
            result.update(error='inputs changed during compile; rerun', changed_inputs=changed)
            return result
        obj = Path(result['object'])
        result['object_sha256'] = sha(obj)
        result.update(analyze_object(job, obj), status='complete')
        return result
    except Exception as error:
        result['error'] = f'{type(error).__name__}: {error}'
        return result
    finally:
        result['seconds'] = round((time.time_ns() - started) / 1e9, 3)
        save(folder / 'receipt.json', result)


def compact(results):
    checks = [row for result in results for row in result.get('checks', [])]
    ranges = {}
    for result in results:
        for coverage in result.get('coverage', []):
            group = ranges.setdefault(coverage['range'], {'functions': {}, 'hits': set()})
            for row in coverage['hits'] + coverage['missing']:
                group['functions'][row['addr']] = row['size']
            group['hits'].update(row['addr'] for row in coverage['hits'])
    return {'compiled_sources': len(results), 'failed_sources': sum(r['status'] != 'complete' for r in results),
            'exact_checks': sum(r['status'] == 'exact' for r in checks), 'checks': len(checks),
            'data_checked': sum('data_errors' in r for r in checks),
            'verified_checks': sum(r['status'] == 'exact' and 'data_errors' in r and not r['data_errors'] for r in checks),
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
    summary = {'state': 'running', 'pid': os.getpid(), 'run': str(run), 'total_sources': len(jobs), 'completed_sources': 0,
               'observer_sha256': sha(Path(__file__)), 'manifest_sha256': sha(run / 'manifest.json'),
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
        summary['state'] = 'failed' if any(r['status'] != 'complete' for r in results) else 'complete'
    except Exception as error:
        summary.update(state='failed', error=f'{type(error).__name__}: {error}')
    summary['seconds'] = round(time.monotonic() - started, 3)
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
    args = parser.parse_args()
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
        for job in jobs:
            receipt = receipts[job['source'].casefold()]
            obj = Path(receipt['object'])
            if receipt['status'] != 'complete' or sha(obj) != receipt['object_sha256']:
                raise ValueError('recorded object failed or changed: ' + str(obj))
            changed = [p for p, digest in receipt['dependencies'].items() if not Path(p).exists() or sha(p) != digest]
            results.append({'source': job['source'], 'object': str(obj), 'changed_inputs': changed,
                            'scope': 'recorded object analysis only; not a fresh build', **analyze_object(job, obj)})
        output = run / ('analysis-' + uuid.uuid4().hex[:8] + '.json')
        save(output, results)
        print(json.dumps({'state': 'analyzed', 'sources': len(results), 'changed_input_sources': sum(bool(r['changed_inputs']) for r in results), 'results': str(output)}))
        return
    elif args.action == '_worker':
        execute(args.input.resolve(), args.workers)
        return
    else:
        summary = display(args.input.resolve())
    if summary['state'] == 'failed':
        raise SystemExit(1)


if __name__ == '__main__':
    main()
