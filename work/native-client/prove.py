"""Prove native sources: native_bulk <-> reference binder fixpoint, cached objects, one-line summaries.

  python work/native-client/prove.py FILE [FILE ...]      # one family per call, full Ogre evidence
  python work/native-client/prove.py --all                # the whole inventory (former ogre_identity_loop)
  options: --rounds N (default 4), --infer-names, --quiet

Every round compiles only sources whose compile inputs changed: the ledger of every earlier run is kept in
prove-cache/ (one file per source) (native_bulk's control digest has no family name, so reuse is safe), then the
binder reads references of the now-exact owners from the ORIGINAL relocations and adds them as evidence until a
round binds nothing new. Receipts: reference-bindings-prove-<n>.json (appended to the inventory evidence).

--infer-names: a draft whose only rejection is "symbol identity not established", with exactly one byte-exact
candidate that the identity registry marks as a placeholder, gets an INFERRED-name row (owner rule 2026-11-11) in
inferred-name-identities.json. Those rows are labeled inferred and reported separately; they are not proven symbols.
"""
import argparse
import collections
import json
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE / 'ogre'))
from roc import match  # noqa: E402

INVENTORY = HERE / 'ogre-native-full-inventory-all.json'
CACHE = HERE / 'prove-cache'            # one ledger row per source (the full ledger is >100 MB)
INFERRED = HERE / 'inferred-name-identities.json'
REGISTRY = ROOT / 'work/2008-06/identity-registry.json'   # authoritative placeholder flags
LOG = HERE / 'prove-log.jsonl'
SCOPE = ('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew')


def rel(path):
    return Path(path).resolve().relative_to(ROOT).as_posix()


def load(path, default):
    return json.loads(Path(path).read_text()) if Path(path).is_file() else default


def cache_file(source):
    import hashlib
    return CACHE / (hashlib.sha1(source.encode()).hexdigest()[:20] + '.json')


def seed_ledger(out, family, sources):
    """Write out/ledger.json from the per-source cache, keys renamed to this family."""
    ledger = {}
    for s in sources:
        row = load(cache_file(s), None)
        if row:
            ledger[family + ':' + s] = row
    out.mkdir(parents=True, exist_ok=True)
    (out / 'ledger.json').write_text(json.dumps(ledger))


def save_ledger(out, sources):
    CACHE.mkdir(exist_ok=True)
    ledger = load(out / 'ledger.json', {})
    for key, row in ledger.items():
        source = key.split(':', 1)[1]
        if source in sources:
            cache_file(source).write_text(json.dumps(row))


def rows(manifest):
    for family in load(manifest, {}).get('families', []):
        for row in family['symbols']:
            if not row['symbol'].startswith(('__', '$')):
                yield row


def source_of(manifest):
    """{(addr, symbol): source} from the jobs' checks."""
    out = {}
    for family in load(manifest, {}).get('families', []):
        for job in family.get('jobs', []):
            for check in job.get('checks', []):
                out[(check['addr'], check['symbol'])] = rel(job['source'])
    return out


def infer_names(manifest):
    registry = load(REGISTRY, {})
    receipt = load(INFERRED, {'scope': 'Inferred-name identities (placeholder names; NOT proven symbols)', 'rows': []})
    have = {r['symbol'] for r in receipt['rows']}
    added = 0
    for row in rows(manifest):
        errors = {e for r in row.get('rejections', []) for e in r.get('errors', [])}
        cands = row.get('candidates') or []
        if (row['status'] == 'draft' and len(cands) == 1 and errors == {'symbol identity not established by current reference evidence'}
                and row['symbol'] not in have and (registry.get(cands[0]) or {}).get('placeholder', True)):
            receipt['rows'].append({'symbol': row['symbol'], 'address': cands[0], 'inferred_name': True,
                                    'evidence': 'INFERRED name: body byte-exact at its single candidate; registry has no proven name'})
            have.add(row['symbol'])
            added += 1
    INFERRED.write_text(json.dumps(receipt, indent=1))
    return added


def summary(manifest, roots, sources=None):
    by_file = collections.defaultdict(lambda: [0, 0, collections.Counter()])
    where = source_of(manifest)
    inferred = {r['symbol'] for r in load(INFERRED, {'rows': []})['rows']}
    exact = set()
    for row in rows(manifest):
        src = where.get((row.get('addr'), row['symbol'])) or (sources[0] if sources and len(sources) == 1 else '?')
        if row['status'] == 'inactive_exact':
            by_file[src][0] += 1
            by_file[src][1] += row.get('size', 0)
            exact.add((row.get('addr'), row['symbol'] in inferred))
        elif row['status'] == 'draft':
            first = next((e for r in row.get('rejections', []) for e in r.get('errors', [])), 'no candidate')
            by_file[src][2][first.split(':')[0][:60]] += 1
    return by_file, exact


def report(out, args):
    manifest = out / 'manifest.json'
    for row in rows(manifest):
        if args.why is not None and row['status'] != 'inactive_exact' and args.why in row['symbol'] and (row.get('candidates') or args.why):
            err = next((e for r in row.get('rejections', []) for e in r.get('errors', [])), '-')
            print('  %s %s %sB cand=%s %s' % (row['status'][:5], row['symbol'][:60], row.get('size'), (row.get('candidates') or [])[:2], err[:110]))
    if args.diff:
        objs = sorted(out.glob('objects/*/*.obj'), key=lambda p: p.stat().st_mtime)
        sym = getattr(args, 'objdiff_symbol', None) or next((r['symbol'] for r in rows(manifest) if args.diff in (r.get('candidates') or [])), None)
        if objs and sym:
            run = subprocess.run([sys.executable, 'roc.py', 'native-asm', '2008-06', args.diff, '--obj', str(objs[-1]), '--sym', sym,
                                  '--context', '1', '--head', '40'], cwd=ROOT, capture_output=True, text=True)
            print(run.stdout[-3000:])
            if getattr(args, 'objdiff_symbol', None):
                import native_repair_tools as tools
                try:
                    directory = tools.run_dir('objdiff', args.diff)
                    print(json.dumps({'objdiff': tools.diff_object(args.diff, sym, objs[-1], directory)}))
                except (OSError, ValueError, RuntimeError, subprocess.TimeoutExpired) as error:
                    print('objdiff unavailable: ' + str(error)[:500])
        else:
            logs = sorted(out.glob('objects/*/*.log'), key=lambda p: p.stat().st_mtime)
            print('no object/symbol; last compile errors:' if logs else 'nothing to diff')
            if logs:
                for line in [l[-200:] for l in logs[-1].read_text(errors='replace').splitlines() if ' error ' in l][:6]:
                    print(line)


def size(addrs):
    return sum(len(match.target('2008-06', a)[0]) for a in addrs)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('files', nargs='*')
    ap.add_argument('--all', action='store_true')
    ap.add_argument('--rounds', type=int, default=4)
    ap.add_argument('--infer-names', action='store_true')
    ap.add_argument('--quiet', action='store_true')
    ap.add_argument('--no-register', action='store_true', help='do not add trial sources or evidence to the shared inventory')
    ap.add_argument('--why', metavar='FILTER', help='after the proof, list non-exact symbols whose name contains FILTER ("" = all named)')
    ap.add_argument('--diff', metavar='ADDR', help='after the proof, assembly diff of ADDR against the file newest object')
    ap.add_argument('--objdiff-symbol', metavar='SYMBOL', help='also generate an objdiff report for this decorated symbol; requires --diff and one source')
    args = ap.parse_args()
    if not args.files and not args.all:
        ap.error('give FILE(s) or --all')
    if args.no_register and (args.all or args.infer_names):
        ap.error('--no-register cannot be combined with --all or --infer-names')
    if args.objdiff_symbol and (not args.diff or args.all or len(args.files) != 1):
        ap.error('--objdiff-symbol requires --diff and exactly one source')
    import run_all
    roots = set(run_all.roots(SCOPE))
    inventory = load(INVENTORY, None)
    master = inventory['families'][0]
    if args.all:
        family, sources = master['name'] if 'name' in master else 'ogre', master['sources']
    else:
        sources = [rel(f) for f in args.files]
        family = 'prove-' + Path(sources[0]).stem
        for s in sources:                                           # every proved file joins the census
            if s not in master['sources']:
                master['sources'].append(s)
    evidence = master['evidence']
    out = HERE / ('prove-out/%s' % family)
    for rnd in range(1, args.rounds + 1):
        started = time.time()
        spec = {'client': '2008-06', 'families': [dict(master, name=family, sources=sources, evidence=evidence)]}
        inv = out.with_suffix('.inventory.json')
        out.parent.mkdir(parents=True, exist_ok=True)
        inv.write_text(json.dumps(spec, indent=1))
        if out.exists():
            (out / 'manifest.json').unlink(missing_ok=True)
        seed_ledger(out, family, sources)
        bulk = subprocess.run([sys.executable, '-m', 'roc.native_bulk', '--out', str(out), str(inv)], cwd=ROOT,
                              capture_output=True, text=True)
        if bulk.returncode:
            sys.exit('native_bulk failed:\n' + (bulk.stdout + bulk.stderr)[-2000:])
        save_ledger(out, set(sources))
        manifest = out / 'manifest.json'
        metrics = load(manifest, {}).get('metrics', {})
        added = infer_names(manifest) if args.infer_names else 0
        if added:
            if rel(INFERRED) not in evidence:
                evidence.append(rel(INFERRED))
        receipt = HERE / ('reference-bindings-prove-%s-%d.json' % (family, int(time.time())))
        known = sum((['--known', str(ROOT / e)] for e in evidence if 'bindings' in e), [])
        bind = subprocess.run([sys.executable, str(HERE / 'batch_reference_bind.py'), str(manifest), '--out', str(receipt),
                               *known], cwd=ROOT, capture_output=True, text=True)
        found = json.loads(bind.stdout.strip().splitlines()[-1]) if bind.returncode == 0 else {'bindings': 0}
        if found['bindings']:
            evidence.append(rel(receipt))
        elif receipt.exists():
            receipt.unlink()
        by_file, exact = summary(manifest, roots, sources)
        addrs = {a for a, _ in exact if a}
        row = {'family': family, 'round': rnd, 'exact': len(addrs), 'exact_bytes': size(addrs),
               'inferred_name_addrs': len({a for a, inf in exact if inf}), 'root_bytes': size(addrs & roots),
               'new_bindings': found['bindings'], 'inferred_added': added, 'compiles': metrics.get('compile_invocations'),
               'reused': metrics.get('reused_objects'), 'seconds': round(time.time() - started, 1)}
        with LOG.open('a') as log:
            log.write(json.dumps(row) + '\n')
        print(json.dumps(row), flush=True)
        if not found['bindings'] and not added:
            break
    if args.why is not None or args.diff:
        report(out, args)
    # Persist new sources/evidence; merge with the file as it is now (another prove run may have added its own).
    if not args.no_register:
        current = load(INVENTORY, inventory)
        disk = current['families'][0]
        for key in ('sources', 'evidence'):
            disk[key] += [x for x in master[key] if x not in disk[key]]
        INVENTORY.write_text(json.dumps(current, indent=1))
    if not args.quiet:
        for src, (n, b, why) in sorted(by_file.items()):
            if args.all and not why:
                continue
            print('%s: %d exact %d B%s' % (src, n, b, ''.join('; %d %s' % (c, w) for w, c in why.most_common(3))))


if __name__ == '__main__':
    main()
