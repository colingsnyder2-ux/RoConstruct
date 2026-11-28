"""python rates.py [HOURS=24]: rates from work/donorfree-route/auto/metrics.jsonl (autorecover.py) and metrics.jsonl (boot.py).
Exact bytes/hour (function bytes whose draft matched exactly), drafts and approx tokens (chars/4) per backend, compile/exact rates,
LLM seconds per exact byte, boot cycle times. Append-only logs; safe to run any time."""
import json, sys, time
from collections import defaultdict
from pathlib import Path

H = Path(__file__).parent
hours = float(sys.argv[1]) if len(sys.argv) > 1 else 24.0
since = time.time() - hours * 3600


def rows(p):
    if not p.exists():
        return []
    out = []
    for l in p.read_text().splitlines():
        try:
            r = json.loads(l)
        except ValueError:
            continue
        if r.get('ts', 0) >= since:
            out.append(r)
    return out


auto = rows(H / 'auto/metrics.jsonl')
boot = rows(H / 'metrics.jsonl')
res = [r for r in auto if r['kind'] == 'result']
drafts = [r for r in auto if r['kind'] == 'draft']
span = max(1e-9, (max([r['ts'] for r in auto + boot] or [since]) - min([r['ts'] for r in auto + boot] or [since])) / 3600) if (auto or boot) else 0
print('window: last %.0f h; active span %.2f h' % (hours, span))
if res:
    exact = sum(r['exact'] for r in res)
    nbytes = sum(r['bytes'] for r in res)
    print('targets: %d, compiled %d, exact %d (%.0f%%), exact bytes %d%s' % (
        len(res), sum(r['compiled'] for r in res), exact, 100.0 * exact / len(res), nbytes,
        ('  => %.0f B/h over the active span' % (nbytes / span)) if span else ''))
by = defaultdict(lambda: [0, 0, 0, 0.0, 0, 0])
for r in drafts:
    b = by[r['backend']]
    b[0] += 1
    b[1] += r['prompt_chars']
    b[2] += r['out_chars']
    b[3] += r['secs']
for r in res:
    b = by[r['backend']]
    b[4] += r['exact']
    b[5] += r['bytes']
for k, (n, pc, oc, s, ex, by_) in sorted(by.items()):
    print('  %-7s drafts %3d  ~tokens in %7d out %6d  llm %5.0fs  exact %d (%d B)%s' % (
        k, n, pc // 4, oc // 4, s, ex, by_, ('  %.0f tokens/exact byte' % ((pc + oc) / 4 / by_)) if by_ else ''))
if boot:
    link = [r['link_s'] for r in boot if r.get('link_s') is not None]
    probe = [r['probe_s'] for r in boot if r.get('probe_s') is not None]
    print('boot cycles: %d, mean link %.0fs, mean probe %.0fs, stubs now %s' % (
        len(boot), sum(link) / max(1, len(link)), sum(probe) / max(1, len(probe)), boot[-1].get('stubs')))
