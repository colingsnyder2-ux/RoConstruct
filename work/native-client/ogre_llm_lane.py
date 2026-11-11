"""LLM lane for Ogre root functions with a proved name but no native body yet (registry-driven, not queue-driven).

Target: Ogre-scope root, proved registry name + owner class, a native header that declares the class and the
method (not defined inline), one existing native .cpp for the class, no current exact proof. Prompt gets the real
header, the server-exact analog or the exact 2007 donor function body, and the original asm. Gate: native_llm.prove
(native_convert_run byte + reference gates) with the combined Ogre closure. --apply promotes exact survivors through
native_autorecover.py (lease, draft, vtable/layout gates, destination reproof).

  python work/native-client/ogre_llm_lane.py --limit 20 [--apply]
"""
import argparse
import json
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE / 'ogre'))
from roc import libs, match  # noqa: E402
import native_llm as nl  # noqa: E402
import native_transplant_probe as tp  # noqa: E402
import run_all  # noqa: E402
import fingerprint  # noqa: E402

CENSUS = HERE / 'ogre-native-full-census-loop6/manifest.json'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
SCOPE = ('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew')
LOG = HERE / 'ogre-llm-lane.jsonl'


def class_header(leaf, method):
    """The one native header that declares `class leaf { ... }` and names the method; else None."""
    hits = []
    for path in HEADERS.rglob('*.h'):
        text = path.read_text(errors='replace')
        if re.search(r'\b(?:class|struct)\s+%s\b[^;{]*\{' % re.escape(leaf), text) and re.search(r'\b%s\s*\(' % re.escape(method), text):
            hits.append((path, text))
    if len(hits) != 1:
        return None
    path, text = hits[0]
    if re.search(r'\b%s\s*\([^;{}]*\)[^;{}]*\{' % re.escape(method), text):
        return None                                   # already defined inline in the header
    return str(path.relative_to(ROOT)).replace('\\', '/')


def donor_body(addr, qual):
    packet = (ROOT / 'src/2008-06' / (addr + '.cpp')).read_text(errors='replace')
    lib = re.search(r'^// roc-lib:\s*(\S+)\s+(\S+)', packet, re.M)
    if not lib:
        return None
    recipe = libs.RECIPES.get(lib.group(1)) or libs.RECIPES.get(lib.group(1).replace('-dll', ''))
    if not recipe:
        return None
    path = libs.LIBS / recipe['src'] / lib.group(2)
    if not path.is_file():
        return None
    text = path.read_text(errors='replace')
    parts = qual.split('::')
    for depth in range(2, len(parts) + 1):           # Class::method first, then more qualified
        try:
            return tp.body_at(text, '::'.join(parts[-depth:]))
        except ValueError:
            continue
    return None


def refresh_fingerprints():
    """Rerun the fingerprint pass when a newer census exists (cached corpus index: seconds)."""
    census = sorted(HERE.glob('ogre-native-full-census-loop*/manifest.json'), key=lambda p: p.stat().st_mtime)
    if census and (not fingerprint.OUT.is_file() or fingerprint.OUT.stat().st_mtime < census[-1].stat().st_mtime):
        subprocess.run([sys.executable, str(HERE / 'fingerprint.py')], cwd=ROOT, capture_output=True, text=True)


def targets(limit_size):
    roots = set(run_all.roots(SCOPE))
    exact = set()
    data = json.loads(CENSUS.read_text())
    for family in data['families']:
        for row in family['symbols']:
            if row.get('status') == 'inactive_exact' and row.get('addr'):
                exact.add(row['addr'])
    registry = json.loads((HERE / 'ogre-names-registry.json').read_text())
    tried = {json.loads(l)['addr'] for l in LOG.open()} if LOG.is_file() else set()
    out = []
    for addr, row in sorted(registry.items() if isinstance(registry, dict) else ((r['addr'], r) for r in registry)):
        if (addr not in roots or addr in exact or addr in tried or not isinstance(row, dict) or row.get('placeholder')
                or not row.get('signature') or not row.get('owner_class') or "`" in row['signature']
                or '<' in row['owner_class']):
            continue
        sig = row['signature']
        qual = re.sub(r'\s+const$', '', sig.split('(')[0]).split()[-1]
        method = qual.rsplit('::', 1)[-1]
        leaf = row['owner_class'].rsplit('::', 1)[-1]
        header = class_header(leaf, method)
        dest, is_new = nl.destination_for(row['owner_class'])
        size = len(match.target('2008-06', addr)[0])
        if not header or not dest or is_new or not 16 <= size <= limit_size:
            continue
        cls_method = '%s::%s' % (leaf, method)
        if re.search(r'\b%s\s*\(' % re.escape(cls_method), (ROOT / dest).read_text(errors='replace')):
            continue                                  # already defined natively: a proof/identity problem, not a rewrite
        t = dict(addr=addr, symbol=row['name'], decl=sig, owner=row['owner_class'], qual=qual, header=header,
                 dest=dest, size=size, name_source=row.get('name_source'), placeholder=False, new_source=False)
        body = donor_body(addr, qual)
        if not body:                                  # no recipe donor: the upstream function it was ported from
            hit = fingerprint.lookup(addr)
            body = hit and '// %s:%d %s (fingerprint %.2f; port origin, not identity)\n%s' % (
                hit['file'], hit['lines'][0], hit['function'], hit['score'], hit['body'])
        if body:
            t['donor_body'] = body
        out.append(t)
    return sorted(out, key=lambda t: t['size'])


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--limit', type=int, default=20)
    ap.add_argument('--max-size', type=int, default=2048)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--tries', type=int, default=4)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()
    nl.CLOSURE = HERE / 'ogre-combined-closure.json'     # thunks + binder identities, not only the base closure
    nl.HERE.mkdir(parents=True, exist_ok=True)
    refresh_fingerprints()
    todo = targets(args.max_size)
    print('%d eligible (%d B, %d with donor body); running %d' % (
        len(todo), sum(t['size'] for t in todo), sum('donor_body' in t for t in todo), min(args.limit, len(todo))),
        flush=True)
    if args.dry_run:
        for t in todo[:args.limit]:
            print(t['addr'], t['size'], t['qual'], t['dest'].split('/')[-1], 'donor' if 'donor_body' in t else 'analog')
        return
    todo = todo[:args.limit]
    started = time.time()
    with ThreadPoolExecutor(args.jobs) as pool:
        done = list(pool.map(lambda it: nl.work(it[1], nl.LADDER, args.tries, it[0]), enumerate(todo)))
    exact = [(t, d) for t, d in done if d]
    for t, d in done:
        with LOG.open('a') as log:
            log.write(json.dumps({'addr': t['addr'], 'qual': t['qual'], 'size': t['size'], 'exact': bool(d)}) + '\n')
    wall = time.time() - started
    print('exact %d/%d, %d B, %.0f B/hour' % (len(exact), len(done), sum(t['size'] for t, _ in exact),
                                             sum(t['size'] for t, _ in exact) * 3600 / max(wall, 1)), flush=True)
    for t, d in exact if args.apply else []:
        run = subprocess.run([sys.executable, str(HERE / 'native_autorecover.py'), '--plan-file', str(d / 'plan.json'),
                              '--closure', str(nl.CLOSURE), '--out', str(d / 'apply'), '--apply'],
                             cwd=ROOT, capture_output=True, text=True)
        print(t['addr'], 'apply:', (run.stdout.strip().splitlines() or [run.stderr[-300:]])[-1], flush=True)


if __name__ == '__main__':
    main()
