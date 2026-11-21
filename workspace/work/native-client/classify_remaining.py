"""Classify every function the site still counts as remaining (no integrated or inactive/draft native code) into one
primary bucket = the lane / blocker that owns it.  Reads remaining-now.json ([addr, name, name_source]; refresh it with
--refresh after a census) and writes remaining-classified.json + a summary table.
  python work/native-client/classify_remaining.py [--refresh]"""
import argparse
import collections
import json
import re
import sys
from pathlib import Path

sys.argv, ARGS = sys.argv[:1], sys.argv[1:]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_llm as m                     # noqa: E402

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--refresh', action='store_true', help='recompute remaining-now.json from the site inventory')
args = ap.parse_args(ARGS)

reg = m.load_registry()
if args.refresh:
    from roc import integration_site
    inactive = integration_site.inactive_code(m.ROOT)
    left = [(a, (reg.get(a) or {}).get('name', ''), (reg.get(a) or {}).get('name_source', ''))
            for a in m.remaining_set() if a not in inactive]
    (HERE / 'remaining-now.json').write_text(json.dumps(left))
left = json.loads((HERE / 'remaining-now.json').read_text())

VENDOR_LIB = ('xtp-', 'g3d-', 'boost-', 'mfc-', 'atl-', 'msvc-', 'zlib', 'ogre-', 'scintilla', 'lua', 'raknet', 'jpeg',
              'png', 'fmod', 'wildmagic', 'sdl', 'tinyxml', 'curl', 'stl', 'crt')
rows = [json.loads(l) for l in m.LOG.read_text(encoding='utf-8').splitlines() if l.strip()]
tries = collections.Counter(r['addr'] for r in rows if r.get('model') not in ('cache', 'preflight', 'dest', 'audit', 'creator-gate')
                            and r.get('attempt', 0) >= 0)
drafted = {r['addr'] for r in rows if r.get('status') == 'draft'}
ph = json.loads((HERE / 'placeholder-lane/results.json').read_text()) if (HERE / 'placeholder-lane/results.json').is_file() else {}
names = collections.Counter(n for _, n, _ in left if n)
fns = {}
for line in (m.ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        f = json.loads(line)
        fns[f['addr']] = f


def lib_of(addr):
    path = m.ROOT / 'src/2008-06' / (addr + '.cpp')
    if not path.is_file():
        return None
    return (m.match.directives(path.read_text(errors='replace')[:3000]).get('lib') or '').split(' ')[0]


def classify(addr, name, source):
    lib = lib_of(addr)
    size = fns.get(addr, {}).get('size', 0)
    kind = ('initializer' if name.startswith(('??__E', '??__F')) else
            'template' if name.startswith('??$') or '?$' in name else
            'special-member' if re.match(r'\?\?[_0-9A-Z]', name) else 'function')
    if lib and lib.startswith(VENDOR_LIB):
        return 'vendor-library', lib.split('-')[0], kind
    if not name or name.startswith(('func_', 'sub_', 'FUN_')):
        tier = 'placeholder-lane' if addr in ph else 'unnamed'
        return 'unnamed (identity session)', '%s; %s' % (tier, 'size>2048' if size > 2048 else 'ok-size'), kind
    if names[name] > 1:
        return 'bogus duplicate name', source, kind
    if 'inferred' in str(source):
        return 'inferred name only', source, kind
    if lib and lib.startswith('rbxgs') or lib and lib.startswith('openrbx'):
        origin = 'donor-exact (%s)' % lib
    else:
        origin = 'app analog'
    if size > 2048:
        return 'too big for LLM lane (>2 KB)', origin, kind
    if kind == 'template':
        return 'template instantiation', origin, kind
    if kind == 'initializer':
        return 'static initializer', origin, kind
    t = tries[addr]
    state = ('parked: 4+ LLM tries' if t >= 4 else 'LLM tried 1-3 (draft)' if addr in drafted else
             'LLM tried 1-3' if t else 'never tried (no header/queue route)')
    return state, origin, kind


out = {}
for addr, name, source in left:
    bucket, detail, kind = classify(addr, name or '', source or '')
    out[addr] = dict(bucket=bucket, detail=detail, kind=kind, name=name, size=fns.get(addr, {}).get('size', 0))
(HERE / 'remaining-classified.json').write_text(json.dumps(out, indent=0))
by = collections.defaultdict(list)
for a, r in out.items():
    by[r['bucket']].append(r)
print('%d remaining functions, %d bytes' % (len(out), sum(r['size'] for r in out.values())))
for bucket, items in sorted(by.items(), key=lambda kv: -len(kv[1])):
    print('%5d  %7d B  %s' % (len(items), sum(r['size'] for r in items), bucket))
    for detail, n in collections.Counter(r['detail'] for r in items).most_common(4):
        print('         %5d  %s' % (n, detail))
