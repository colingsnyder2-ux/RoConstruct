"""P6 native-doc diagnostic build wrapper; never executes a rebuilt client.

CLI: preflight MANIFEST | start MANIFEST | run MANIFEST | status RUN | report RUN.
Manifest: {"extras":["rebuild/2008-06/native-classes/FlatTool.cpp"],"cache":false,
"snapshot":"rebuild/2008-06/out"}. All input paths relative to repo root (or
absolute). start launches a hidden worker; output, stdout/stderr, exit receipt
and blocker list live in its unique RUN. status is one compact read; report
lists failures without rebuilding. Cache is opt-in existing build-client cache.
Wrapper builds serialize because build_client also writes shared prerequisites;
unwrapped builds bypass this lock. Link success is not ABI/runtime/P5/P6 proof.
"""
import argparse
from contextlib import contextmanager
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
RUNS = ROOT / 'work/2008-06/p6-probe-runs'
BUILDER = BASE / 'p6/build_client.py'
sys.path.insert(0, str(Path(__file__).parent))
from native_check_runner import save, sha, alive, rebuild


def preflight(data):
    if not isinstance(data, dict):
        raise ValueError('manifest must be a JSON object')
    unknown = set(data) - {'extras', 'cache', 'snapshot'}
    if unknown:
        raise ValueError('unknown manifest keys: ' + ', '.join(sorted(unknown)))
    if not isinstance(data.get('cache', False), bool) or not isinstance(data.get('extras', []), list):
        raise ValueError('cache must be boolean; extras must be list')
    extras = []
    for name in data.get('extras', []):
        path = (ROOT / name).resolve()
        if not path.is_file() or path.suffix.lower() not in ('.cpp', '.cxx', '.c') or ';' in str(path):
            raise ValueError('invalid/missing extra C++ source: ' + str(path))
        if str(path) not in extras:
            extras.append(str(path))
    snapshot = (ROOT / data.get('snapshot', str(BASE / 'out'))).resolve()
    runtime = snapshot / 'tests/P2RecoveredPlayer'
    required = [BUILDER, runtime / 'Content', runtime / 'Places']
    required += [runtime / name for name in ('rgmain.dll', 'rgdx.dll', 'fmodex.dll')]
    required += [ROOT / 'clients/2008-06' / name for name in ('Roblox.exe', 'SciLexer.dll')]
    metadata = ROOT / 'clients/2008-06/ReflectionMetadata.xml'
    required.append(metadata if metadata.exists() else BASE / 'out/p6/ReflectionMetadata.xml')
    spec = rebuild.load_module('2008-06', 'player')
    pending, seen = [spec], set()
    while pending:
        module = pending.pop()
        if module['name'] in seen:
            continue
        seen.add(module['name'])
        required.append(snapshot / module['name'] / 'linked/linked.lib')
        pending.extend(rebuild.load_module('2008-06', name) for name in module.get('depends', []))
    required.append(snapshot / 'XTP/linked/linked.lib')
    tc = rebuild.toolchain()
    for key in ('cl', 'link', 'vc_include', 'sdk_include'):
        if not tc.get(key):
            raise ValueError('missing toolchain component: ' + key)
        required.append(Path(tc[key]))
    missing = [str(p) for p in required if not p.exists()]
    if missing:
        raise ValueError('missing prerequisites:\n' + '\n'.join(missing))
    return {'extras': extras, 'cache': data.get('cache', False), 'snapshot': str(snapshot),
            'extra_hashes': {p: sha(p) for p in extras}, 'builder_sha256': sha(BUILDER)}


@contextmanager
def build_lock(folder):
    folder.mkdir(parents=True, exist_ok=True)
    with (folder / 'build.lock').open('a+b') as lock:
        lock.seek(0, 2)
        if lock.tell() == 0:
            lock.write(b'0')
            lock.flush()
        lock.seek(0)
        try:
            if os.name == 'nt':
                import msvcrt
                msvcrt.locking(lock.fileno(), msvcrt.LK_NBLCK, 1)
            else:
                import fcntl
                fcntl.flock(lock.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError as error:
            raise BlockingIOError('shared build lock busy; reuse active run, retry after completion') from error
        try:
            yield
        finally:
            lock.seek(0)
            if os.name == 'nt':
                msvcrt.locking(lock.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(lock.fileno(), fcntl.LOCK_UN)


def classify(exit_code, stdout, stderr, link_text=None, exe_exists=False):
    combined = stdout + '\n' + stderr + '\n' + (link_text or '')
    # Keep complete diagnostics on disk; only the first eight are in summary.
    compiler_errors = list(dict.fromkeys(line for line in combined.splitlines() if re.search(r'\b(?:fatal )?error C\d+', line)))
    link_errors = list(dict.fromkeys(line for line in combined.splitlines() if re.search(r'\b(?:fatal )?error LNK\d+', line)))
    unresolved = {}
    for line in combined.splitlines():
        hit = re.search(r'^(.*?)\s*:\s*error LNK(?:2001|2019): unresolved external symbol (.*?)\s+\((\S+)\)(?= referenced|\s*$)', line)
        if hit:
            requester, display, symbol = hit.groups()
        else:
            hit = re.search(r'^(.*?)\s*:\s*error LNK(?:2001|2019): unresolved external symbol (\S+)(?= referenced|\s*$)', line)
            if not hit:
                continue
            requester, symbol = hit.groups()
            display = symbol
        row = unresolved.setdefault(symbol, {'symbol': symbol, 'display': display.strip('"'), 'requesters': []})
        if requester not in row['requesters']:
            row['requesters'].append(requester)
    duplicates = {}
    for line in link_errors:
        hit = re.search(r'^(.*?)\s*:\s*error LNK2005:\s*(.*?)\s+already defined in\s+(.*)$', line)
        if not hit:
            continue
        owner, definition, previous = hit.groups()
        decorated = re.search(r'\((\S+)\)\s*$', definition)
        symbol = decorated[1] if decorated else definition.strip('"')
        row = duplicates.setdefault(symbol, {'symbol': symbol, 'display': definition, 'providers': []})
        for provider in (owner, previous):
            if provider not in row['providers']:
                row['providers'].append(provider)
    if exit_code == 0 and exe_exists and link_text is not None and not compiler_errors and not link_errors:
        outcome = 'linked'
    elif compiler_errors:
        outcome = 'compile_failed'
    elif link_errors:
        outcome = 'link_failed'
    elif exit_code == 0:
        outcome = 'missing_link_receipt' if exe_exists else 'missing_output'
    else:
        outcome = 'build_failed_before_link' if link_text is None else 'build_failed'
    return {'outcome': outcome, 'exit_code': exit_code, 'link_log_present': link_text is not None,
            'compiler_errors': compiler_errors, 'link_errors': link_errors, 'blockers': list(unresolved.values()), 'duplicates': list(duplicates.values())}


def run_probe(run, builder=None, lock_folder=None):
    builder = Path(builder or BUILDER)
    lock_folder = Path(lock_folder or RUNS)
    with (run / 'claim').open('x') as claim:
        claim.write(str(os.getpid()))
    plan = json.loads((run / 'plan.json').read_text(encoding='utf-8'))
    output = run / 'output'
    output.mkdir()
    receipt = {'state': 'running', 'pid': os.getpid(), 'run': str(run), 'output': str(output),
               'exit_code': None,
               'stdout': str(run / 'stdout.log'), 'stderr': str(run / 'stderr.log'),
               'observer_sha256': sha(Path(__file__)), 'builder_sha256': sha(builder),
               'scope': 'native-doc diagnostic only; never runs client; link success is not ABI/runtime/P5/P6 proof'}
    save(run / 'summary.json', receipt)
    start = time.monotonic()
    try:
        with build_lock(lock_folder):
            for source, digest in plan['extra_hashes'].items():
                if sha(source) != digest:
                    raise ValueError('extra source changed since preflight: ' + source)
            if sha(builder) != plan['builder_sha256']:
                raise ValueError('builder changed since preflight; start new probe')
            command = [sys.executable, '-u', str(builder), plan['snapshot'], '--native-doc', '--native-doc-out', str(output)]
            if plan['cache']:
                command.append('--native-doc-cache')
            env = os.environ.copy()
            # Do not inherit unrelated probe selection from the calling shell.
            env['ROC_NATIVE_DOC_EXTRA'] = ';'.join(plan['extras'])
            receipt['command'] = command
            save(run / 'summary.json', receipt)
            with (run / 'stdout.log').open('w', encoding='utf-8') as stdout, (run / 'stderr.log').open('w', encoding='utf-8') as stderr:
                child = subprocess.Popen(command, cwd=ROOT, env=env, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr,
                                         creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0)
                receipt['build_pid'] = child.pid
                save(run / 'summary.json', receipt)
                exit_code = child.wait()
            log_path = output / 'native-doc-link.log'
            link = log_path.read_text(errors='replace') if log_path.exists() else None
            detail = classify(exit_code, (run / 'stdout.log').read_text(errors='replace'),
                              (run / 'stderr.log').read_text(errors='replace'), link, (output / 'RobloxNativeDoc.exe').is_file())
            detail['extra_sources_changed_during_build'] = [p for p, digest in plan['extra_hashes'].items() if not Path(p).exists() or sha(p) != digest]
            save(run / 'result.json', detail)
            receipt.update(state='complete' if detail['outcome'] == 'linked' else 'failed', outcome=detail['outcome'], exit_code=exit_code,
                           link_log_present=detail['link_log_present'],
                           unique_unresolved=len(detail['blockers']) if link is not None or detail['link_errors'] else None,
                           unique_duplicates=len(detail['duplicates']), link_error_count=len(detail['link_errors']),
                           compiler_errors=detail['compiler_errors'][:8], link_errors=detail['link_errors'][:8], result=str(run / 'result.json'),
                           changed_extra_sources=detail['extra_sources_changed_during_build'])
            if detail['extra_sources_changed_during_build']:
                receipt.update(state='failed', outcome='inputs_changed', link_outcome=detail['outcome'])
    except Exception as error:
        receipt.update(state='failed', outcome='busy' if isinstance(error, BlockingIOError) else 'wrapper_failed', error=f'{type(error).__name__}: {error}')
        # Even launch/lock/preflight-race failures have log paths and a terminal receipt.
        for name in ('stdout.log', 'stderr.log'):
            (run / name).touch(exist_ok=True)
    finally:
        receipt['seconds'] = round(time.monotonic() - start, 3)
        save(run / 'summary.json', receipt)
    return receipt


def status(run):
    receipt = json.loads((run / 'summary.json').read_text())
    launcher = run / 'launcher.json'
    pid = receipt.get('pid') or (json.loads(launcher.read_text())['pid'] if launcher.exists() else None)
    if receipt['state'] in ('running', 'queued') and pid and alive(pid) is False:
        receipt = json.loads((run / 'summary.json').read_text())
        if receipt['state'] in ('running', 'queued'):
            receipt.update(state='failed', outcome='worker_lost', error='worker exited without terminal receipt; inspect worker.log and build_pid')
    print(json.dumps(receipt, separators=(',', ':')))
    return receipt


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('preflight', 'start', 'run', 'status', 'report', '_worker'))
    parser.add_argument('input', type=Path, help='manifest or RUN directory')
    args = parser.parse_args(argv)
    if args.action in ('preflight', 'start', 'run'):
        try:
            plan = preflight(json.loads(args.input.read_text(encoding='utf-8-sig')))
        except (ValueError, OSError, TypeError) as error:
            parser.error(str(error))
        if args.action == 'preflight':
            print(json.dumps({'state': 'ready', **plan}, separators=(',', ':')))
            return
        RUNS.mkdir(parents=True, exist_ok=True)
        run = RUNS / (time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
        run.mkdir()
        save(run / 'plan.json', plan)
        save(run / 'summary.json', {'state': 'queued', 'run': str(run)})
        if args.action == 'run':
            run_probe(run)
        else:
            try:
                with (run / 'worker.log').open('w') as log:
                    options = {'creationflags': subprocess.CREATE_NO_WINDOW | subprocess.CREATE_NEW_PROCESS_GROUP} if os.name == 'nt' else {'start_new_session': True}
                    worker = subprocess.Popen([sys.executable, str(Path(__file__).resolve()), '_worker', str(run)], cwd=ROOT,
                                              stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT, close_fds=True, **options)
                save(run / 'launcher.json', {'pid': worker.pid})
            except OSError as error:
                save(run / 'summary.json', {'state': 'failed', 'outcome': 'launch_failed', 'error': str(error)})
        receipt = status(run)
    elif args.action == '_worker':
        run_probe(args.input.resolve())
        return
    elif args.action == 'report':
        receipt = status(args.input.resolve())
        if (args.input / 'result.json').exists():
            detail = json.loads((args.input / 'result.json').read_text())
            for row in detail['blockers'][:12]:
                print(row['symbol'] + ' <- ' + ', '.join(row['requesters']))
    else:
        receipt = status(args.input.resolve())
    if receipt['state'] == 'failed':
        raise SystemExit(1)


if __name__ == '__main__':
    main()
