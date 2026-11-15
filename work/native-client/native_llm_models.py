"""Per-model benchmark for the native LLM workers, from work/native-client/native-llm/attempts.jsonl.

For each model: tries, inactive-exact matches, match %, failure mix, mean LLM / gate seconds, exact bytes and
exact bytes per hour of that model's own time (LLM + gate seconds of its tries).  'cache' rows are regates of an
earlier answer (no model call); a regate that turns exact is credited to the model that wrote the answer.
  python work/native-client/native_llm_models.py [--since HOURS] [--json OUT]"""
import argparse
import collections
import json
import time
from pathlib import Path

LOG = Path(__file__).resolve().parent / 'native-llm/attempts.jsonl'


def report(since=0):
    """Per-model rows, best bytes/hour first (also used by the dashboard's Native LLM page)."""
    rows = [json.loads(line) for line in LOG.read_text().splitlines() if line.strip()] if LOG.is_file() else []
    if since:
        cutoff = time.time() - since * 3600
        rows = [r for r in rows if r.get('time', cutoff) >= cutoff]
    author = {}                                    # addr -> last model that wrote an answer for it
    stats = collections.defaultdict(lambda: dict(tries=0, exact=0, exact_bytes=0, llm=0.0, gate=0.0,
                                                 status=collections.Counter(), targets=set(), tool=collections.Counter(), tok_in=0, tok_out=0, tok_n=0, usd=0.0, tok_bytes=0, tok_s=0.0))
    credited = set()
    for r in rows:
        model = r['model']
        if model != 'cache':
            author[r['addr']] = model
        s = stats[model]
        s['tries'] += 1
        s['status'][r['status']] += 1
        s['llm'] += r.get('llm_seconds', 0) or 0
        s['gate'] += r.get('gate_seconds', 0) or 0
        s['targets'].add(r['addr'])
        if r.get('tokens'):
            s['tok_in'] += r['tokens'].get('in', 0); s['tok_out'] += r['tokens'].get('out', 0); s['tok_n'] += 1
            s['usd'] += r['tokens'].get('usd', 0)
            s['tok_s'] += (r.get('llm_seconds') or 0) + (r.get('gate_seconds') or 0)
        s['tool'].update({k: v for k, v in (r.get('tool') or {}).items()})
        if r['status'] == 'inactive_exact' and r['addr'] not in credited:
            credited.add(r['addr'])
            owner = stats[author.get(r['addr'], model)]
            owner['exact'] += 1
            owner['exact_bytes'] += r.get('size', 0)
            if r.get('tokens') or model == 'cache':   # token-logged era only, so tokens/byte compares like with like
                owner['tok_bytes'] += r.get('size', 0) if r.get('tokens') else 0
    out = []
    for model, s in stats.items():
        seconds = s['llm'] + s['gate']
        out.append(dict(model=model, tries=s['tries'], targets=len(s['targets']), exact=s['exact'],
                        match_pct=round(100.0 * s['exact'] / max(1, len(s['targets'])), 1),
                        compile_failed_pct=round(100.0 * s['status']['compile_failed'] / max(1, s['tries']), 1),
                        draft_pct=round(100.0 * s['status']['draft'] / max(1, s['tries']), 1),
                        no_reply_pct=round(100.0 * s['status']['no-reply'] / max(1, s['tries']), 1),
                        llm_s=round(s['llm'] / max(1, s['tries']), 1), gate_s=round(s['gate'] / max(1, s['tries']), 1),
                        compile_gate_s=round(s['tool']['compile_gate'] / max(1, s['tries']), 1),
                        asm_diff_s=round(s['tool']['asm_diff'] / max(1, s['tries']), 1),
                        include_retries=int(s['tool']['include_retries']),
                        exact_bytes=s['exact_bytes'],
                        avg_try_s=round(seconds / max(1, s['tries']), 1),                 # one worker, one try: LLM + gate
                        sec_per_exact=round(seconds / s['exact']) if s['exact'] else 0,     # worker time per exact function
                        tok_in=round(s['tok_in'] / max(1, s['tok_n'])), tok_out=round(s['tok_out'] / max(1, s['tok_n'])),
                        usd=round(s['usd'], 3), usd_per_kb=round(s['usd'] * 1024 / s['tok_bytes'], 2) if s['tok_bytes'] and s['usd'] else 0,
                        tokens_per_hour=round((s['tok_in'] + s['tok_out']) * 3600 / s['tok_s']) if s['tok_s'] else 0,
                        tokens_per_exact_byte=round((s['tok_in'] + s['tok_out']) / s['tok_bytes']) if s['tok_bytes'] and s['tok_n'] else 0,
                        bytes_per_hour=round(s['exact_bytes'] * 3600 / seconds, 1) if seconds else 0.0))
    out.sort(key=lambda r: (-r['bytes_per_hour'], -r['exact']))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--since', type=float, default=0, help='only attempts from the last N hours (0 = all)')
    ap.add_argument('--json', type=Path)
    args = ap.parse_args()
    out = report(args.since)
    print('%-46s %5s %5s %5s %6s %6s %6s %6s %6s %6s %6s %6s %5s %7s %8s %7s %7s %6s %8s %6s %6s' % ('model', 'tries', 'tgts', 'exact', 'match%', 'cfail%',
          'draft%', 'norep%', 'llm_s', 'tool_s', 'gate_s', 'diff_s', 'incl', 'bytes', 'B/hour', 'tok_in', 'tok_out', 'tok/B', 'tok/h', 'usd', '$/KB'))
    for r in out:
        print('%-46s %5d %5d %5d %6.1f %6.1f %6.1f %6.1f %6.1f %6.1f %6.1f %6.1f %5d %7d %8.1f %7d %7d %6d %8d %6.2f %6.2f' % (r['model'][-46:], r['tries'],
              r['targets'], r['exact'], r['match_pct'], r['compile_failed_pct'], r['draft_pct'], r['no_reply_pct'], r['llm_s'],
              r['gate_s'], r['compile_gate_s'], r['asm_diff_s'], r['include_retries'], r['exact_bytes'], r['bytes_per_hour'], r['tok_in'], r['tok_out'], r['tokens_per_exact_byte'], r['tokens_per_hour'], r['usd'], r['usd_per_kb']))
    if args.json:
        args.json.write_text(json.dumps(out, indent=1) + '\n')


if __name__ == '__main__':
    main()


def runs(rows=None, gap=900):
    """Per-run yield, newest first.  A run is a stretch of attempts with no gap over GAP seconds (older rows have no
    run id).  new_exact counts functions exact for the first time in that run, so a falling column means the queue
    is drying up or the remaining targets are beyond the current tools."""
    if rows is None:
        rows = [json.loads(line) for line in LOG.read_text().splitlines() if line.strip()] if LOG.is_file() else []
    rows = sorted((r for r in rows if r.get('time')), key=lambda r: r['time'])
    out, seen, current = [], set(), None
    for r in rows:
        if current is None or (r.get('run') or 0) != current['run'] or (not r.get('run') and r['time'] - current['end'] > gap):
            current = dict(run=r.get('run') or 0, start=r['time'], end=r['time'], tries=0, model_tries=0, targets=set(), new_exact=0, bytes=0,
                           models=collections.Counter(), usd=0.0)
            out.append(current)
        current['end'] = r['time']
        current['tries'] += 1
        current['targets'].add(r['addr'])
        current['usd'] += (r.get('tokens') or {}).get('usd', 0)
        if r['model'] != 'cache':
            current['model_tries'] += 1
            current['models'][r['model']] += 1
        if r['status'] == 'inactive_exact' and r['addr'] not in seen:
            seen.add(r['addr'])
            current['new_exact'] += 1
            current['bytes'] += r.get('size', 0)
    for run in out:
        hours = max(run['end'] - run['start'], 60) / 3600
        run.update(targets=len(run['targets']), minutes=round(hours * 60), bytes_per_hour=round(run['bytes'] / hours),
                   usd=round(run['usd'], 2), exact_per_10_tries=round(10 * run['new_exact'] / max(1, run['model_tries']), 2),
                   models=', '.join(m.split('/')[-1] for m, _ in run['models'].most_common(9)))
    return out[::-1]


def dashboard_state():
    """Everything the dashboard's Native LLM panel shows (roc/gui.py loads this file per request: no restart)."""
    rows = [json.loads(line) for line in LOG.read_text().splitlines() if line.strip()] if LOG.is_file() else []
    day = time.time() - 86400
    spend = lambda rs: round(sum((r.get('tokens') or {}).get('usd', 0) for r in rs), 3)
    tokens = lambda rs: sum((r.get('tokens') or {}).get('in', 0) + (r.get('tokens') or {}).get('out', 0) for r in rs)
    recent = [r for r in rows if r.get('time', 0) >= day]
    keep = ('addr', 'qual', 'size', 'model', 'attempt', 'status', 'time', 'tokens', 'tool', 'llm_seconds', 'gate_seconds')
    logs = sorted(LOG.parent.parent.glob('native-llm-run*.log'), key=lambda p: p.stat().st_mtime)
    return {'cost': {'usd_total': spend(rows), 'usd_24h': spend(recent), 'tokens_total': tokens(rows), 'tokens_24h': tokens(recent),
                     'since': min((r['time'] for r in rows if r.get('tokens')), default=None)},
            'models': report(), 'runs': runs(rows),
            'unique_exact': len({r['addr'] for r in rows if r['status'] == 'inactive_exact'}),
            'attempts': [{k: r.get(k) for k in keep} for r in rows[-40:]][::-1],
            'run': logs[-1].name if logs else '',
            'running': bool(rows) and time.time() - rows[-1].get('time', 0) < 600,
            'log': '\n'.join(logs[-1].read_text(errors='replace').splitlines()[-60:]) if logs else ''}
