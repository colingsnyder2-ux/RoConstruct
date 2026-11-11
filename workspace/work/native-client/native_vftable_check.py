"""Check a header's virtual order against the original image, slot by slot.

Compiler side: `cl /Zs /d1reportAllClassLayout` vftable blocks for a native
source (what the real headers declare).  Binary side: bound `??_7` vftable
addresses and the named functions their slots point at.  Per slot verdict:
agree / differ / unnamed (slot target has no bound name) / thunk (skipped).
A `differ` row pinpoints a missing, extra or misordered virtual in a header.
"""
import argparse
import json
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import rebuild  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402
import native_class_layout as layout  # noqa: E402
from native_conversion_queue import undecorate  # noqa: E402

BLOCK = re.compile(r'^(.+)::\$vftable@(.*):\s*$')
SLOT = re.compile(r'^\s*(\d+)\t\| &(.*)$')
SYMBOL = re.compile(r'^\?\?_7(.+?)@@6B(.*)@$')


def blocks(log):
    return [b for b in list(_blocks(log)) if b['slots']]  # filled lazily; empty = repeated header


def _blocks(log):
    current = None
    for line in log.replace(chr(13), "").splitlines():
        head = BLOCK.match(line)
        if head:
            current = {'class': head[1], 'base': head[2].rstrip('@'), 'slots': []}
            yield current
        elif current is not None:
            slot = SLOT.match(line)
            if slot:
                current['slots'].append(slot[2].strip())
            elif not line.strip():
                current = None


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('source', type=Path)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--address-names', type=Path,
                    help='optional {address: decorated-symbol} identity map')
    ap.add_argument('--vtables', type=Path,
                    help='optional {address: vftable-symbol} identity map')
    ap.add_argument('--only-class', action='append', default=[],
                    help='check only these compiler class names')
    ap.add_argument('--include-first', action='append', default=[], type=Path,
                    help='test-only include roots before native headers')
    args = ap.parse_args()
    source = args.source.resolve()
    flags = [f for f in layout.runner().compiler_flags(source) if f != '/c']
    # This is a native-header gate, not a donor-header measurement.  Some
    # recovered sources carry a vendor /I before the shared build paths; force
    # the 2008 native-header mirror ahead of that profile so quoted includes
    # inspect the provider we would promote.
    native_include = '/I' + str(ROOT / 'rebuild/2008-06/native-headers')
    first_include = next((i for i, flag in enumerate(flags) if flag.startswith('/I')), len(flags))
    forced_includes = ['/I' + str(path.resolve()) for path in args.include_first]
    flags[first_include:first_include] = forced_includes + [native_include]
    args.output.parent.mkdir(parents=True, exist_ok=True)
    _, log = rebuild.run(rebuild.toolchain(21022), 'cl',
                         flags + ['/Zs', '/d1reportAllClassLayout', str(source)], args.output.parent)
    targets = Targets('2008-06')
    names, tables = defaultdict(list), defaultdict(list)
    for row in json.loads(args.closure.read_text())['bindings']:
        names[int(row['addr'], 16)].append(undecorate(row['symbol'], 0x1000))
        hit = SYMBOL.match(row['symbol'])
        if hit:
            tables[hit[1].split('@')[0]].append((hit[2].rstrip('@'), int(row['addr'], 16), row['symbol']))
    if args.address_names:
        for address, symbol in json.loads(args.address_names.read_text()).items():
            names[int(address, 16)].append(undecorate(symbol, 0x1000))
    if args.vtables:
        for address, symbol in json.loads(args.vtables.read_text()).items():
            hit = SYMBOL.match(symbol)
            if hit:
                tables[hit[1].split('@')[0]].append((hit[2].rstrip('@'), int(address, 16), symbol))
    results, totals = [], Counter()
    def check(block, va):
        rows = []
        for index, declared in enumerate(block['slots']):
            at = va + 4 * index
            if at not in targets.relocs:
                rows.append({'slot': index, 'declared': declared, 'verdict': 'beyond-table'})
                continue
            target = struct.unpack('<I', targets.data(at, 4))[0]
            bound = names.get(target, [])
            method = declared.split('::')[-1]
            if declared.startswith('thunk:'):
                verdict = 'thunk'
            elif not bound:
                verdict = 'unnamed'
            elif any(n.endswith('::' + method) or ('{dtor}' in method and 'destructor' in n) for n in bound):
                verdict = 'agree'
            else:
                try:
                    size = len(targets.body('%08x' % target)[0])
                except (KeyError, ValueError, SystemExit):
                    size = 0
                # ponytail: <=16-byte bodies are ICF-folded by the linker; name mismatch proves nothing
                verdict = 'folded' if 0 < size <= 16 else 'differ'
            rows.append({'slot': index, 'declared': declared, 'target': '%08x' % target,
                         'bound': bound[:3], 'verdict': verdict})
        return rows

    seen = set()
    for block in blocks(log):
        if args.only_class and block['class'] not in args.only_class:
            continue
        # Back-referenced mangled base names do not compare as text; the
        # bound table of this class whose slots agree most is the one, if unique.
        scored = sorted(((sum(r['verdict'] == 'agree' for r in rows), va, symbol, rows)
                         for _, va, symbol in tables.get(block['class'], ())
                         for rows in [check(block, va)]), key=lambda s: -s[0])
        if not scored or scored[0][0] == 0 or (len(scored) > 1 and scored[1][0] == scored[0][0]):
            continue
        _, va, symbol, rows = scored[0]
        if symbol in seen:
            continue
        seen.add(symbol)
        count = Counter(r['verdict'] for r in rows)
        totals.update(count)
        results.append({'class': block['class'], 'vftable': symbol, 'address': '%08x' % va,
                        'counts': dict(count), 'slots': rows})
    results.sort(key=lambda r: -r['counts'].get('differ', 0))
    out = {'source': source.relative_to(ROOT).as_posix(),
           'scope': 'header virtual order versus bound image vftables; identity evidence only',
           'summary': {'vftables_checked': len(results), **totals}, 'vftables': results}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))
    for r in results[:6]:
        print(r['class'], r['counts'], [(s['slot'], s['declared'], s['bound'][:1]) for s in r['slots'] if s['verdict'] == 'differ'][:3])


if __name__ == '__main__':
    main()
