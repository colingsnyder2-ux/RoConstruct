"""Native recovery wall-time sessions and automatic diagnostic timing logs.

python -m roc.native_work start ADDRESS --hypothesis TEXT [--budget 600]
python -m roc.native_work finish ADDRESS --outcome blocked --note TEXT
python -m roc.native_work report
Times are local work/diagnostic measurements, never server credit or runtime proof.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import time
import uuid

ROOT = Path(__file__).resolve().parents[1]
LOGS = ROOT / 'work/2008-06/native-work'


def headers(root=None):
    root = Path(root or ROOT / 'rebuild/2008-06/native-headers')
    paths = [root / p for p in ('v8tree/Instance.h', 'v8tree/Service.h',
             'v8datamodel/DataModel.h', 'v8datamodel/PartInstance.h', 'util/Events.h',
             'util/Object.h', 'CWorkspace.h', 'CRobloxDoc.h')]
    paths += sorted((root / 'reflection').glob('*.h'))
    return {str(p): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths if p.is_file()}


def changed(before, after):
    return sorted(p for p in before.keys() | after.keys() if before.get(p) != after.get(p))


def address(value):
    number = int(value, 16)
    if not 0 <= number <= 0xffffffff:
        raise ValueError('address must fit 32 bits')
    return f'{number:08x}'


def active(addr):
    path = LOGS / 'active' / (address(addr) + '.json')
    return json.loads(path.read_text()) if path.exists() else None


def elapsed(row):
    return round(max(0, row.get('finished_at', time.time()) - row['started_at']), 3)


def over_budget(checks):
    return [row['addr'] for c in checks if (row := active(c['addr']))
            and elapsed(row) >= row['budget_seconds']]


def log_checks(run, job, result, mode='compile'):
    """Called by the runner's single collector, not by parallel compiler workers."""
    rows = {(c['addr'], c['requested_symbol']): c for c in result.get('checks', [])}
    for check in job.get('checks', []):
        addr = address(check['addr'])
        row = rows.get((addr, check['symbol']), {})
        status = row.get('status', 'failed')
        if result.get('status', 'complete') != 'complete':
            status = 'failed'
        elif result.get('changed_inputs'):
            status = 'stale'
        elif row.get('data_errors'):
            status = 'data_mismatch'
        session = active(addr)
        record = {'at': time.time(), 'addr': addr, 'symbol': check['symbol'],
                  'source': job['source'], 'run': str(run), 'mode': mode, 'status': status,
                  'check_seconds': row.get('check_seconds'),
                  'source_compile_seconds_shared': result.get('compile_seconds'),
                  'source_seconds': result.get('seconds'),
                  'error': result.get('error'),
                  'work_seconds': elapsed(session) if session else None,
                  'session': session['id'] if session else None,
                  'scope': 'local timings; shared compile time is not per-function recovery time'}
        line = json.dumps(record) + '\n'
        with (run / 'function-timings.jsonl').open('a', encoding='utf-8') as output:
            output.write(line)
        if session:
            folder = LOGS / 'trials' / session['id']
            folder.mkdir(parents=True, exist_ok=True)
            with (folder / (run.name + '.jsonl')).open('a', encoding='utf-8') as output:
                output.write(line)
        print(f"FUNCTION {addr} {status} check={record['check_seconds']}s "
              f"shared_compile={record['source_compile_seconds_shared']}s "
              f"work={record['work_seconds']}s", flush=True)


def start(addr, hypothesis, budget=600):
    addr = address(addr)
    if budget <= 0:
        raise ValueError('budget must be positive')
    folder = LOGS / 'active'
    folder.mkdir(parents=True, exist_ok=True)
    row = {'id': uuid.uuid4().hex, 'addr': addr, 'hypothesis': hypothesis,
           'started_at': time.time(), 'budget_seconds': budget, 'state': 'working'}
    try:
        with (folder / (addr + '.json')).open('x', encoding='utf-8') as output:
            json.dump(row, output, indent=2)
    except FileExistsError:
        row = active(addr)  # Resume the same clock; repeated starts never reset the budget.
    return {**row, 'seconds': elapsed(row)}


def finish(addr, outcome, note, receipt=None):
    addr = address(addr)
    row = active(addr)
    if row is None:
        raise ValueError('no active function: ' + addr)
    if outcome == 'local_exact' and receipt is None:
        raise ValueError('local_exact needs --receipt; no automatic acceptance claim')
    if receipt is not None:
        receipt = Path(receipt).resolve()
        row['receipt'] = str(receipt)
        row['receipt_sha256'] = hashlib.sha256(receipt.read_bytes()).hexdigest()
    row.update(finished_at=time.time(), state=outcome, note=note)
    row.update(seconds=elapsed(row), budget_exceeded=elapsed(row) >= row['budget_seconds'])
    folder = LOGS / 'history'
    folder.mkdir(parents=True, exist_ok=True)
    target = folder / (row['id'] + '.json')
    temporary = target.with_suffix('.tmp')
    temporary.write_text(json.dumps(row, indent=2) + '\n', encoding='utf-8')
    os.replace(temporary, target)
    (LOGS / 'active' / (addr + '.json')).unlink()
    return row


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='action', required=True)
    begin = commands.add_parser('start')
    begin.add_argument('addr')
    begin.add_argument('--hypothesis', required=True)
    begin.add_argument('--budget', type=int, default=600)
    end = commands.add_parser('finish')
    end.add_argument('addr')
    end.add_argument('--outcome', choices=('local_exact', 'partial', 'blocked', 'rejected'), required=True)
    end.add_argument('--note', required=True)
    end.add_argument('--receipt', type=Path)
    report = commands.add_parser('report')
    report.add_argument('--limit', type=int, default=20)
    report.add_argument('--sort', choices=('recent', 'seconds'), default='recent')
    args = parser.parse_args()
    try:
        if args.action == 'start':
            result = start(args.addr, args.hypothesis, args.budget)
        elif args.action == 'finish':
            result = finish(args.addr, args.outcome, args.note, args.receipt)
        else:
            rows = [json.loads(p.read_text()) for kind in ('active', 'history')
                    for p in (LOGS / kind).glob('*.json')]
            totals = {}
            for row in rows:
                total = totals.setdefault(row['addr'], {'addr': row['addr'], 'attempts': 0,
                                                        'work_seconds': 0, 'last_started_at': 0})
                total['attempts'] += 1
                total['work_seconds'] = round(total['work_seconds'] + elapsed(row), 3)
                total['last_started_at'] = max(total['last_started_at'], row['started_at'])
            key = elapsed if args.sort == 'seconds' else lambda r: r['started_at']
            result = {'sessions': [{**r, 'seconds': elapsed(r),
                       'budget_exceeded': elapsed(r) >= r['budget_seconds']}
                      for r in sorted(rows, key=key, reverse=True)[:args.limit]],
                      'function_totals': sorted(totals.values(),
                          key=lambda r: r['work_seconds'] if args.sort == 'seconds' else r['last_started_at'],
                          reverse=True)[:args.limit]}
    except (ValueError, OSError) as error:
        parser.error(str(error))
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
