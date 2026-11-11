"""Deterministic Ogre recovery scheduler. No model calls, mining, or runtime execution.

Plan by default. --run enables leased, transactional native transplants and mechanical
repairs. Missing source/layout evidence parks a target; it never creates a stub.
Successful source changes stay inactive and uncommitted for a normal batch commit.
"""
import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

HERE = Path(__file__).resolve().parent
NATIVE = HERE.parent
ROOT = NATIVE.parents[1]
sys.path.insert(0, str(NATIVE))
import fix_loop
import run_all


def accepted(manifest):
    return {r['addr'] for f in manifest.get('families', []) for r in f['symbols']
            if r['status'] == 'inactive_exact' and r.get('addr')}


def fingerprint(address, destination, header_digest=None):
    digest = hashlib.sha256()
    files = [NATIVE / 'fix_loop.py', NATIVE / 'analog_to_native.py',
             ROOT / 'src/2008-06' / (address + '.cpp'), ROOT / destination]
    # A changed authentic header can supply the evidence a previous run lacked.
    if header_digest is None:
        files += sorted((ROOT / 'rebuild/2008-06/native-headers').rglob('*.h'))
    else:
        digest.update(header_digest)
    packet = files[2].read_text(errors='replace') if files[2].is_file() else ''
    recipe = re.search(r'^// roc-lib:\s*(\S+)\s+(\S+)', packet, re.M)
    if recipe:
        from roc import libs
        spec = libs.RECIPES.get(recipe[1]) or libs.RECIPES.get(recipe[1].replace('-dll', ''))
        if spec:
            files.append(libs.LIBS / spec['src'] / recipe[2])
    for path in files:
        digest.update(str(path).encode())
        digest.update(path.read_bytes() if path.is_file() else b'<missing>')
    return digest.hexdigest()


def active_proofs():
    """Read live processes; a stale lock file is never proof of a running census."""
    if sys.platform == 'win32':
        command = [
            'powershell', '-NoProfile', '-Command',
            "@(Get-CimInstance Win32_Process | Where-Object { $_.Name -match '^python' "
            "-and $_.CommandLine -match 'prove[.]py|roc[.]native_bulk' } | "
            "Select-Object ProcessId,CommandLine) | ConvertTo-Json -Compress"]
        result = subprocess.run(command, capture_output=True, text=True, check=True)
        rows = json.loads(result.stdout or '[]')
        return rows if isinstance(rows, list) else [rows]
    result = subprocess.run(['ps', '-eo', 'pid,args'], capture_output=True, text=True, check=True)
    return [line for line in result.stdout.splitlines()
            if re.search(r'python\S* .*?(?:prove\.py|roc\.native_bulk)', line)]


def save(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(data, indent=1))
    os.replace(temporary, path)


def queue(manifest, state, addresses=None, retry=False):
    scope = set(run_all.roots(('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew')))
    targets = set(addresses) if addresses else scope
    unknown = targets - scope
    if unknown:
        raise ValueError('addresses outside Ogre scope: ' + ', '.join(sorted(unknown)))
    targets -= accepted(manifest)
    ordered = sorted(targets, key=lambda a: (-len(run_all.match.target('2008-06', a)[0]), a))
    eligible = {r[0]: r for r in fix_loop.transplant.transplant_targets(ordered)}
    headers = hashlib.sha256()
    for path in sorted((ROOT / 'rebuild/2008-06/native-headers').rglob('*.h')):
        headers.update(str(path).encode())
        headers.update(path.read_bytes())
    parked = set()
    for path in (NATIVE / 'fix-loop-parked').glob('*.cpp'):
        if re.fullmatch('[0-9a-fA-F]{8}', path.stem):
            parked.add(path.stem.lower())
    handoff = NATIVE / 'CLAUDE_HANDOFF.md'
    if handoff.is_file():
        parked.update(a.lower() for a in re.findall(r'PARKED[^\n]{0,100}?([0-9a-fA-F]{8})\b',
                                                    handoff.read_text(errors='replace')))
    result = []
    for address in ordered:
        if address in parked and not retry:
            result.append({'address': address, 'status': 'parked_evidence',
                           'reason': 'existing PARKED trial/handoff; explicit retry or new owner evidence required'})
            continue
        if address not in eligible:
            result.append({'address': address, 'status': 'needs_evidence',
                           'reason': 'no declared native destination with an eligible donor method'})
            continue
        _, owner, leaf, method, destination = eligible[address]
        # Use the same fingerprint representation when recording the final outcome.
        signature = fingerprint(address, destination, headers.digest())
        previous = state.get('targets', {}).get(address, {})
        if not retry and previous.get('fingerprint') == signature and previous.get('status') != 'interrupted':
            continue
        result.append({'address': address, 'bytes': len(run_all.match.target('2008-06', address)[0]),
                       'owner': owner, 'destination': destination, 'fingerprint': signature,
                       'status': 'ready'})
    return result


def execute(target, minutes):
    # Existing transaction owns leases, CRLF, header dependency reproof and rollback.
    return fix_loop.run_target(target['address'], budget_seconds=minutes * 60,
                               allow_models=False)


def acquire_lock(path):
    handle = path.open('a+b')
    if handle.tell() == 0:
        handle.write(b' ')
        handle.flush()
    handle.seek(0)
    try:
        if sys.platform == 'win32':
            import msvcrt
            msvcrt.locking(handle.fileno(), msvcrt.LK_NBLCK, 1)
        else:
            import fcntl
            fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except OSError:
        handle.close()
        raise SystemExit('Another deterministic workflow holds the lock.')
    return handle


def native_snapshot():
    return {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest()
            for directory in ('native-classes', 'native-headers')
            for p in (ROOT / 'rebuild/2008-06' / directory).rglob('*') if p.is_file()}


def require_branch():
    branch = subprocess.run(['git', 'branch', '--show-current'], cwd=ROOT,
                            capture_output=True, text=True, check=True).stdout.strip()
    if branch != 'codex/native-partial-search-20261029':
        raise RuntimeError('refused other branch: ' + branch)


def commit_survivors(receipts):
    """Only stage paths explicitly emitted by successful leased transactions."""
    require_branch()
    staged = subprocess.run(['git', 'diff', '--cached', '--name-only'], cwd=ROOT,
                            capture_output=True, text=True, check=True).stdout.strip()
    if staged:
        raise RuntimeError('automatic commit refused: index contains pre-existing staged changes')
    paths = {}
    originals = {}
    for receipt in receipts:
        paths.update(receipt['sha256'])
        for name, digest in receipt.get('original_sha256', {}).items():
            originals.setdefault(name, digest)
    for name, digest in paths.items():
        path = ROOT / name
        if not path.resolve().is_relative_to((ROOT / 'rebuild/2008-06').resolve()):
            raise RuntimeError('refused non-native survivor path: ' + name)
        if hashlib.sha256(path.read_bytes()).hexdigest() != digest:
            raise RuntimeError('survivor changed after proof: ' + name)
        previous = subprocess.run(['git', 'show', 'HEAD:' + name], cwd=ROOT, capture_output=True)
        if previous.returncode or hashlib.sha256(previous.stdout).hexdigest() != originals.get(name):
            raise RuntimeError('automatic commit refused: path had pre-existing edits: ' + name)
    if paths:
        program = ("import sys;sys.path.insert(0,'work/native-client');import native_commit;"
                   "native_commit.TRAILER='\\n\\nCo-Authored-By: Codex <noreply@openai.com>\\n';"
                   "sys.argv=['native_commit.py','-m','Recover deterministic Ogre native batch']+sys.argv[1:];"
                   "native_commit.main()")
        subprocess.run([sys.executable, '-c', program, *sorted(paths)], cwd=ROOT, check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', type=Path, required=True,
                        help='completed native_bulk manifest; accepted addresses only are skipped')
    parser.add_argument('--state', type=Path, default=NATIVE / 'deterministic-workflow/state.json')
    parser.add_argument('--address', action='append')
    parser.add_argument('--limit', type=int, default=10)
    parser.add_argument('--minutes', type=float, default=25, help='per-target ceiling, maximum25')
    parser.add_argument('--run', action='store_true', help='apply proved survivors; default only writes plan')
    parser.add_argument('--retry-parked', action='store_true', help='explicitly revisit unchanged failed evidence')
    parser.add_argument('--census', action='store_true', help='run one final full census after the batch')
    parser.add_argument('--commit', action='store_true', help='commit/push only unchanged proved survivors, once per batch')
    args = parser.parse_args()
    if not 0 < args.minutes <= 25 or args.limit <= 0:
        parser.error('positive limit and per-target time in (0,25] required')
    if any(not re.fullmatch('[0-9a-fA-F]{8}', a) for a in args.address or []):
        parser.error('addresses need eight hexadecimal digits')
    if (args.census or args.commit) and not args.run:
        parser.error('--census/--commit require --run')
    state = json.loads(args.state.read_text()) if args.state.is_file() else {'targets': {}}
    manifest = json.loads(args.manifest.read_text())
    tasks = queue(manifest, state, [a.lower() for a in args.address] if args.address else None,
                  args.retry_parked)
    plan = {'timestamp': datetime.now(timezone.utc).isoformat(), 'llm_calls': 0,
            'mode': 'run' if args.run else 'plan', 'tasks': tasks}
    save(args.state.parent / 'plan.json', plan)
    if not args.run:
        print(json.dumps({'mode': 'plan', 'ready': sum(t['status'] == 'ready' for t in tasks),
                          'needs_evidence': sum(t['status'] == 'needs_evidence' for t in tasks), 'llm_calls': 0}))
        return
    require_branch()
    # Refuse to overlap ANY proof transaction, including an unrelated scoped one.
    if active_proofs():
        raise SystemExit('Deferred: live proof process found; native files remain untouched.')
    handle = acquire_lock(args.state.parent / 'workflow.lock')
    try:
        count = 0
        survivors = []
        for target in tasks:
            if target['status'] != 'ready':
                state['targets'][target['address']] = target
                continue
            if count >= args.limit:
                break
            if active_proofs():
                raise SystemExit('Deferred: another proof started between targets.')
            count += 1
            event = dict(target, status='interrupted')
            state['targets'][target['address']] = event
            save(args.state, state)
            try:
                proof_log = NATIVE / 'fix-loop.jsonl'
                offset = proof_log.stat().st_size if proof_log.exists() else 0
                outcome = execute(target, args.minutes)
                event.update(status='inactive_exact' if outcome.startswith('exact') else 'parked', reason=outcome)
                if event['status'] == 'inactive_exact':
                    with proof_log.open('rb') as log:
                        log.seek(offset)
                        receipts = [json.loads(line) for line in log if line.strip()]
                    receipts = [r for r in receipts if r.get('addr') == target['address']
                                and r.get('status') == 'inactive_exact' and r.get('sha256')]
                    if not receipts:
                        raise RuntimeError('worker returned exact without a survivor receipt')
                    survivors.extend(receipts)
            except (RuntimeError, OSError, subprocess.TimeoutExpired) as error:
                event.update(status='parked', reason=str(error))
            # queue uses the same header digest convention; this also accounts for kept header edits.
            headers = hashlib.sha256()
            for path in sorted((ROOT / 'rebuild/2008-06/native-headers').rglob('*.h')):
                headers.update(str(path).encode())
                headers.update(path.read_bytes())
            event['fingerprint'] = fingerprint(target['address'], target['destination'], headers.digest())
            event['timestamp'] = datetime.now(timezone.utc).isoformat()
            save(args.state, state)
            with (args.state.parent / 'events.jsonl').open('a') as log:
                log.write(json.dumps(event) + '\n')
            print(target['address'], event['status'], event.get('reason'), flush=True)
        save(args.state, state)
        summary = {'timestamp': datetime.now(timezone.utc).isoformat(), 'llm_calls': 0,
                   'attempted': count, 'survivors': len(survivors),
                   'scope': 'Inactive proof only; no runtime/server credit.', 'census_requested': args.census}
        save(args.state.parent / 'summary.json', summary)
        with (NATIVE / 'CLAUDE_HANDOFF.md').open('a') as handoff:
            handoff.write('\n- Deterministic workflow: %d targets attempted, %d accepted survivor receipts; '
                          '0 model calls. State/events in %s; inactive only.\n' %
                          (count, len(survivors), args.state.parent))
        if args.commit:
            commit_survivors(survivors)
        if args.census:
            if active_proofs():
                raise SystemExit('Census deferred: live proof process found.')
            pins = args.state.parent / 'census-inputs-before.json'
            save(pins, native_snapshot())
            subprocess.run([sys.executable, str(NATIVE / 'prove.py'), '--all', '--rounds', '6',
                            '--infer-names', '--quiet'], cwd=ROOT, check=True)
            subprocess.run([sys.executable, str(HERE / 'scope_audit.py'),
                str(NATIVE / 'prove-out/OgreNativeFull/manifest.json'), '--pinned-native', str(pins),
                '--out', str(args.state.parent / 'census-audit.json')], cwd=ROOT, check=True)
    finally:
        handle.close()  # OS releases the lock even after a crash; no stale-file dead end.


if __name__ == '__main__':
    main()
