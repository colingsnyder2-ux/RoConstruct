"""Compare compiler class layouts with binary field evidence, offset by offset.

Inputs: a `native_class_layout.py` JSON (what the headers declare) and
`claude-field-evidence.json` (what the original code does: vftable stores at
this+N, named member calls on this+N).  Per class and offset:

  agree    compiler has a vfptr / a member or base of that type starting at N
  differ   binary proves something at N, compiler has nothing starting there,
           or a vfptr the compiler does not have
  unknown  compiler has a row at N but the type cannot be read from the dump

Non-template classes only (dump names templates in mangled form).  A `differ`
is a header defect; zero `differ` is necessary, not sufficient, layout proof.
"""
import argparse
import json
import re
from collections import Counter
from pathlib import Path


def short(name):
    return name.split('::')[-1]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('layout', type=Path)
    ap.add_argument('--fields', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    compiled = json.loads(args.layout.read_text())['classes']
    evidence = json.loads(args.fields.read_text())['classes']
    results, totals = [], Counter()
    for qualified, rows in sorted(evidence.items()):
        if '<' in qualified or short(qualified) not in compiled:
            continue
        layout = compiled[short(qualified)]
        starts = {}
        for m in layout['members']:
            starts.setdefault(m['offset'], []).append(m['name'])
        for b in layout['bases']:
            starts.setdefault(b['offset'], []).append('base ' + b['class'])
        vfptrs = {m['offset'] for m in layout['members'] if m['name'] == '{vfptr}'}
        checks = []
        for row in rows:
            n = row['offset']
            if row['vfptr_of']:
                checks.append({'offset': n, 'proof': 'vfptr', 'verdict': 'agree' if n in vfptrs else 'differ',
                               'compiler': starts.get(n, [])})
            for typ in row['object_of']:
                if short(typ) == short(qualified) or typ in (qualified,) or '<' in typ:
                    continue  # `this` itself or a template base: not a field claim
                here = starts.get(n, [])
                below = [o for o in starts if o < n]
                if not here and below and ' ' in ' '.join(starts[max(below)]):
                    verdict = 'inside'  # inside a class-typed member: dump does not expand members
                elif not here:
                    verdict = 'differ'
                elif any(re.search(r'\b%s\b' % re.escape(short(typ)), h) for h in here):
                    verdict = 'agree'
                else:
                    verdict = 'unknown'
                checks.append({'offset': n, 'proof': 'object ' + typ, 'verdict': verdict, 'compiler': here})
        if not checks:
            continue
        count = Counter(c['verdict'] for c in checks)
        totals.update(count)
        totals['classes'] += 1
        results.append({'class': qualified, 'size': layout['size'], 'counts': dict(count), 'checks': checks})
    results.sort(key=lambda r: -r['counts'].get('differ', 0))
    out = {'layout': str(args.layout), 'scope': __doc__.splitlines()[0], 'summary': dict(totals), 'classes': results}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))
    for r in results[:8]:
        if r['counts'].get('differ'):
            print(r['class'], r['counts'], [(c['offset'], c['proof'], c['compiler'][:2]) for c in r['checks'] if c['verdict'] == 'differ'][:3])


if __name__ == '__main__':
    main()
