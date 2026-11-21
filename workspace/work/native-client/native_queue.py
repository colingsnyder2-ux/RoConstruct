"""Live queue of remaining native functions for contributors (no model).  Writes work/native-queue.json, which the server
serves at GET /v1/native-queue with its age.  Refreshed every 20 s from: remaining-classified.json (re-classified every
10 min by lane_runner.py classify), the lease table (claims), the draft inbox events (submissions), owner/twin facts.
  python work/native-client/native_queue.py            # loop
  python work/native-client/native_queue.py --once"""
import collections
import json
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
OUT = ROOT / 'work' / 'native-queue.json'
EVENTS = ROOT / 'work' / 'agent-inbox' / 'events.jsonl'
CLASSIFY_EVERY = 600


def load(path, default):
    try:
        return json.loads(Path(path).read_text(encoding='utf-8'))
    except (OSError, ValueError):
        return default


def tail_events(limit=400):
    try:
        size = EVENTS.stat().st_size
        with EVENTS.open('rb') as stream:
            stream.seek(max(0, size - 200_000))
            lines = stream.read().decode('utf-8', 'replace').splitlines()
    except OSError:
        return []
    rows = []
    for line in lines[-limit:]:
        try:
            rows.append(json.loads(line))
        except ValueError:
            pass
    return rows


def leases():
    try:
        import urllib.request
        data = json.load(urllib.request.urlopen('http://127.0.0.1:8765/v1/leases', timeout=5))
        return data.get('leases', [])
    except Exception:                                            # noqa: BLE001
        return []


def build():
    remaining = load(HERE / 'remaining-classified.json', {})
    owners = load(HERE / 'research-owners/owners.json', {})
    twins = load(HERE / 'research-twins/identities.json', {}).get('unique', {})
    needs_header = set(load(HERE / 'header-requests.json', []))
    known = load(HERE / 'family-known-failures.json', {})
    groups = collections.defaultdict(lambda: {'functions': 0, 'bytes': 0, 'addresses': []})
    for addr, row in remaining.items():
        if addr in twins:
            fam = 'template family: ' + re.sub(r'<.*', '', re.sub(r'^(?:class|struct) ', '', twins[addr]['identity'])).rsplit('::', 1)[-1]
        elif addr in owners:
            fam = 'class ' + re.sub(r'<.*', '', owners[addr]['owner'])
        else:
            fam = 'ownerless'
        g = groups[fam]
        g['functions'] += 1
        g['bytes'] += row['size']
        g['addresses'].append(addr)
    active = leases()
    claim = {}
    for lease in active:
        claim[lease.get('name', '')] = {'user': lease.get('user'), 'until': lease.get('expires'), 'paths': lease.get('patterns')}
    families = []
    for name, g in groups.items():
        status = 'blocked: no native header for the class (header lane first)' if name[6:] in {re.sub(r'<.*', '', n) for n in needs_header} else \
            'known failure: ' + next((v for k, v in known.items() if k in name), '')[:120] if any(k in name for k in known) else 'open'
        families.append({'family': name, 'functions': g['functions'], 'bytes': g['bytes'], 'status': status,
                         'addresses': sorted(g['addresses'], key=lambda a: -remaining[a]['size'])[:60]})
    families.sort(key=lambda f: -f['bytes'])
    events = tail_events()
    recent = [{'time': e.get('time'), 'user': e.get('user'), 'model': e.get('model'), 'kind': e.get('kind'),
               'exact_credits': e.get('exact_credits'), 'verified': e.get('verified')} for e in events[-25:]]
    today = collections.Counter(e.get('user') for e in events if time.time() - (e.get('time') or 0) < 86400)
    return {
        'generated_at': time.time(),
        'remaining': {'functions': len(remaining), 'bytes': sum(r['size'] for r in remaining.values()),
                      'classified_at': (HERE / 'remaining-classified.json').stat().st_mtime if (HERE / 'remaining-classified.json').exists() else None},
        'families': families[:120],
        'claims': claim,
        'submissions_last_24h_by_user': dict(today.most_common(20)),
        'recent_submissions': recent,
        'note': 'A draft upload proves durable storage only. Counts here are local proofs on the owner machine; server credit needs the independent verifier.',
    }


def main():
    once = '--once' in sys.argv
    last_classify = 0
    while True:
        if time.time() - last_classify > CLASSIFY_EVERY and not once:
            subprocess.run([sys.executable, str(HERE / 'lane_runner.py'), 'classify'], cwd=ROOT, capture_output=True)
            last_classify = time.time()
        try:
            tmp = OUT.with_suffix('.tmp')
            tmp.write_text(json.dumps(build(), indent=1), encoding='utf-8')
            tmp.replace(OUT)
        except OSError:
            pass
        if once:
            return
        time.sleep(20)


if __name__ == '__main__':
    main()
