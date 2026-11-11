"""Promote strictly proved explicit class-template instantiations into Ogre native sources (generalizes Codex's
R3 two-file pilot, 2026-11-10).

  1. probe:  native_template_probe.py --per-line per source (parallel, own output dir each)
  2. strict: one roc.native_bulk run over every per-line probe TU (reference-proof gate, not byte-only)
  3. select: per source, lines whose strict exact addresses are new vs the census; each address owned by one file
  4. apply:  lease file -> append lines -> native_bulk the real file -> keep only if no census address of that file
             is lost and >= 1 selected address is now exact; else restore the original bytes. Release lease.

  python work/native-client/ogre_template_promote.py --out work/native-client/ogre-template-promote-all [--apply]

Writes native sources only with --apply. Never commits. Scratch probe bytes are never counted as recovery.
"""
import argparse
import json
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
CENSUS = HERE / 'ogre-native-full-census-current/manifest.json'      # Codex baseline (kept for comparisons)
BASELINE = HERE / 'ogre-native-full-census-loop2/manifest.json'      # latest fixpoint census
# Same evidence as that census, so before/after compare like with like.
EVIDENCE = json.loads((HERE / 'ogre-native-full-inventory-all.json').read_text())['families'][0]['evidence']
SWEEP = HERE / 'ogre-template-class-sweep-20261110'
HEADER = '// Explicit template instantiations: each line strict-proved (body + references) against the 2008-06 client.'


def norm(path):
    return os.path.normcase(str(Path(path).resolve()))


def exact_by_source(manifest):
    """{normcase source: {addr: symbol}} from a native_bulk manifest (strict inactive_exact only)."""
    data = json.loads(Path(manifest).read_text())
    out = {}
    for family in data.get('families', []):
        good = {(row['addr'], row['symbol']) for row in family.get('symbols', [])
                if row.get('status') == 'inactive_exact' and isinstance(row.get('addr'), str)}
        for job in family.get('jobs', []):
            mine = out.setdefault(norm(job['source']), {})
            for check in job.get('checks', []):
                if (check['addr'], check['symbol']) in good:
                    mine[check['addr']] = check['symbol']
    return out


def bulk(inventory, out):
    run = subprocess.run([sys.executable, '-m', 'roc.native_bulk', '--out', str(out), str(inventory)],
                         cwd=ROOT, capture_output=True, text=True)
    if run.returncode or not (out / 'manifest.json').is_file():
        raise RuntimeError('native_bulk failed: ' + (run.stdout + run.stderr)[-600:])
    return out / 'manifest.json'


def probe(source, out):
    folder = out / 'probe' / Path(source).stem
    if (folder / 'receipt.json').is_file():
        return folder
    folder.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([sys.executable, str(HERE / 'native_template_probe.py'), '--per-line', '--output',
                    str(folder.parent), str(ROOT / source)], cwd=ROOT, capture_output=True, text=True)
    return folder


def roc(*args):
    return subprocess.run([str(ROOT / 'roc.cmd'), *args], cwd=ROOT, capture_output=True, text=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--jobs', type=int, default=5)
    ap.add_argument('--apply', action='store_true')
    args = ap.parse_args()
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    census = exact_by_source(BASELINE)            # before-state must use the same evidence as every proof here
    census_addrs = {a for rows in census.values() for a in rows}
    sources = sorted(json.loads(p.read_text())['source'] for p in SWEEP.glob('*/receipt.json')
                     if json.loads(p.read_text()).get('new_exact_addresses'))

    # 1. per-line probes
    with ThreadPoolExecutor(args.jobs) as pool:
        folders = dict(zip(sources, pool.map(lambda s: probe(s, out), sources)))
    lines = {}                                   # line file -> (source, directive text)
    for source, folder in folders.items():
        receipt = folder / 'receipt.json'
        if not receipt.is_file() or json.loads(receipt.read_text()).get('status') != 'ok':
            continue
        for number, row in enumerate(json.loads(receipt.read_text()).get('per_line', [])):
            if row.get('raw_unique'):
                lines[norm(folder / ('line-%03d.cpp' % number))] = (source, row['line'])
    inventory = out / 'line-inventory.json'
    inventory.write_text(json.dumps({'client': '2008-06', 'families': [
        {'name': 'OgreTemplatePromoteLines', 'sources': sorted(lines), 'evidence': EVIDENCE}]}, indent=1))

    # 2. strict gate over every line TU
    strict = exact_by_source(bulk(inventory, out / 'strict'))

    # 3. select: new addresses only, one owning source per address (first by source order)
    owner, plan = {}, {}
    for line_file, (source, text) in sorted(lines.items(), key=lambda kv: (kv[1][0], kv[0])):
        new = {a: s for a, s in strict.get(line_file, {}).items() if a not in census_addrs and a not in owner}
        if new:
            for a in new:
                owner[a] = source
            plan.setdefault(source, []).append({'line': text, 'new': new})
    summary = {'sources_probed': len(folders), 'line_tus': len(lines), 'sources_with_new': len(plan),
               'new_addresses': len(owner), 'apply': args.apply, 'results': []}

    # 4. apply, one leased file at a time
    for source, rows in plan.items() if args.apply else []:
        path = ROOT / source
        lease = 'ogre-template-' + path.stem
        taken = roc('lease', 'take', lease, source, '--hours', '1')
        if taken.returncode:
            summary['results'].append({'source': source, 'state': 'lease-refused'})
            continue
        original = path.read_bytes()
        try:
            text = original.decode('utf-8', errors='surrogateescape')
            wanted = [r for r in rows if r['line'] not in text]
            nl = '\r\n' if b'\r\n' in original else '\n'
            block = nl.join([HEADER] + [r['line'] for r in wanted])
            path.write_bytes((text.rstrip() + nl + nl + block + nl).encode('utf-8', errors='surrogateescape'))
            inv = out / 'apply' / (path.stem + '.json')
            inv.parent.mkdir(parents=True, exist_ok=True)
            inv.write_text(json.dumps({'client': '2008-06', 'families': [
                {'name': 'OgreTemplatePromote:' + path.stem, 'sources': [str(path)], 'evidence': EVIDENCE}]}))
            after = exact_by_source(bulk(inv, out / 'apply' / path.stem)).get(norm(path), {})
            before = census.get(norm(path), {})
            lost = sorted(set(before) - set(after))
            gained = sorted(a for r in wanted for a in r['new'] if a in after)
            if lost or not gained:
                path.write_bytes(original)
                summary['results'].append({'source': source, 'state': 'reverted', 'lost': lost[:20],
                                           'gained': len(gained)})
            else:
                summary['results'].append({'source': source, 'state': 'applied', 'lines': len(wanted),
                                           'gained': len(gained), 'addresses': gained})
        except Exception as error:               # never leave a half-edited file behind
            path.write_bytes(original)
            summary['results'].append({'source': source, 'state': 'error', 'error': str(error)[-400:]})
        finally:
            roc('lease', 'release', lease)
        (out / 'summary.json').write_text(json.dumps(summary, indent=1) + '\n')
    (out / 'summary.json').write_text(json.dumps(summary, indent=1) + '\n')
    print(json.dumps({k: v for k, v in summary.items() if k != 'results'}))
    for row in summary['results']:
        print(json.dumps({k: v for k, v in row.items() if k != 'addresses'}))


if __name__ == '__main__':
    main()
