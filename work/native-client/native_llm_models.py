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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--since', type=float, default=0, help='only attempts from the last N hours (0 = all)')
    ap.add_argument('--json', type=Path)
    args = ap.parse_args()
    rows = [json.loads(line) for line in LOG.read_text().splitlines() if line.strip()]
    if args.since:
        cutoff = time.time() - args.since * 3600
        rows = [r for r in rows if r.get('time', cutoff) >= cutoff]
    author = {}                                    # addr -> last model that wrote an answer for it
    stats = collections.defaultdict(lambda: dict(tries=0, exact=0, exact_bytes=0, llm=0.0, gate=0.0,
                                                 status=collections.Counter(), targets=set()))
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
        if r['status'] == 'inactive_exact' and r['addr'] not in credited:
            credited.add(r['addr'])
            owner = stats[author.get(r['addr'], model)]
            owner['exact'] += 1
            owner['exact_bytes'] += r.get('size', 0)
    out = []
    for model, s in stats.items():
        seconds = s['llm'] + s['gate']
        out.append(dict(model=model, tries=s['tries'], targets=len(s['targets']), exact=s['exact'],
                        match_pct=round(100.0 * s['exact'] / max(1, len(s['targets'])), 1),
                        compile_failed_pct=round(100.0 * s['status']['compile_failed'] / max(1, s['tries']), 1),
                        draft_pct=round(100.0 * s['status']['draft'] / max(1, s['tries']), 1),
                        no_reply_pct=round(100.0 * s['status']['no-reply'] / max(1, s['tries']), 1),
                        llm_s=round(s['llm'] / max(1, s['tries']), 1), gate_s=round(s['gate'] / max(1, s['tries']), 1),
                        exact_bytes=s['exact_bytes'],
                        bytes_per_hour=round(s['exact_bytes'] * 3600 / seconds, 1) if seconds else 0.0))
    out.sort(key=lambda r: (-r['bytes_per_hour'], -r['exact']))
    print('%-46s %5s %5s %5s %6s %6s %6s %6s %6s %6s %7s %8s' % ('model', 'tries', 'tgts', 'exact', 'match%', 'cfail%',
          'draft%', 'norep%', 'llm_s', 'gate_s', 'bytes', 'B/hour'))
    for r in out:
        print('%-46s %5d %5d %5d %6.1f %6.1f %6.1f %6.1f %6.1f %6.1f %7d %8.1f' % (r['model'][-46:], r['tries'], r['targets'],
              r['exact'], r['match_pct'], r['compile_failed_pct'], r['draft_pct'], r['no_reply_pct'], r['llm_s'],
              r['gate_s'], r['exact_bytes'], r['bytes_per_hour']))
    if args.json:
        args.json.write_text(json.dumps(out, indent=1) + '\n')


if __name__ == '__main__':
    main()
