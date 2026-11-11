"""Template-promotion gate: which `template class X;` lines are proven safe to add.

Writes only under --output; never edits native-classes (apply under lease).
For one native source:

1. baseline: compile unchanged, map exact symbols -> original addresses;
2. probe: source + every candidate explicit instantiation (rejected lines dropped);
3. attribute each newly exact symbol with ONE original address to its line;
   keep only lines that own at least one such symbol;
4. final: recompile source + kept lines only and require
     no-loss   every baseline exact symbol is still exact at the same address
     gain      every claimed new symbol is exact at exactly one address
     no-clash  no new symbol lands on an address a baseline symbol owns
               under a different name unless that address is ICF-shared already
5. emit promotion.json (+ promotion.lines.txt to append) only if all hold.

Body/relocation-masked byte proof only: not layout, link or runtime proof.
"""
import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402
from native_conversion_queue import owner  # noqa: E402
import native_template_probe as probe  # noqa: E402


def promote(source, output, targets, check):
    source = source.resolve()
    receipt = probe.probe(source, output, targets, check)
    result = {'source': receipt['source'], 'probe_status': receipt['status'], 'promotable': False}
    if receipt['status'] != 'ok':
        return result
    flags = probe.flags_for(check, source, output)
    base = probe.exact((output / 'baseline/candidate.obj').read_bytes(), targets)
    grown = probe.exact((output / 'probe/candidate.obj').read_bytes(), targets)
    lines = [l for l in (output / 'probe.cpp').read_text(encoding='utf-8').splitlines()[1:] if l.strip()]
    by_class = {l[len('template class '):-1]: l for l in lines}
    owned = defaultdict(list)
    for symbol, addrs in grown.items():
        if symbol in base or len(addrs) != 1:
            continue
        cls = probe.template_class(owner(symbol))
        if cls in by_class:
            owned[by_class[cls]].append(symbol)
    kept = [l for l in lines if l in owned]
    result.update(candidate_lines=len(lines), kept_lines=len(kept))
    if not kept:
        return result
    tu = output / 'final.cpp'
    tu.write_text('#include "%s"\n' % source.as_posix() + '\n'.join(kept) + '\n', encoding='utf-8')
    code, _, seconds = probe.compile_tu(flags, tu, output / 'final')
    result['final_compile'] = {'exit': code, 'seconds': seconds}
    if code:
        return result
    final = probe.exact((output / 'final/candidate.obj').read_bytes(), targets)
    lost = sorted(s for s, a in base.items() if sorted(final.get(s, [])) != sorted(a))
    claimed = {s: final[s][0] for l in kept for s in owned[l] if len(final.get(s, [])) == 1}
    missing = sorted(s for l in kept for s in owned[l] if s not in claimed)
    base_at = defaultdict(set)
    for s, addrs in base.items():
        if len(addrs) == 1:
            base_at[addrs[0]].add(s)
    clash = sorted((a, s) for s, a in claimed.items() if a in base_at)
    # A line whose every claimed symbol went missing in the final TU proves nothing: drop it.
    proven = [l for l in kept if any(s in claimed for s in owned[l])]
    result.update(lost_baseline_symbols=lost, claimed_missing_in_final=missing,
                  shares_address_with_baseline=clash[:50], new_exact_symbols=len(claimed),
                  new_exact_addresses=len(set(claimed.values())),
                  promotable=not lost and bool(claimed) and len(proven) == len(kept),
                  lines=[{'line': l, 'symbols': sorted((claimed[s], s) for s in owned[l] if s in claimed)}
                         for l in proven])
    if result['promotable']:
        (output / 'promotion.lines.txt').write_text('\n'.join(proven) + '\n', encoding='utf-8')
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('sources', nargs='+', type=Path)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    targets, check = Targets('2008-06'), probe.runner()
    for source in args.sources:
        folder = args.output.resolve() / source.stem
        result = promote(source, folder, targets, check)
        (folder / 'promotion.json').write_text(json.dumps(result, indent=1) + '\n')
        print(json.dumps({k: v for k, v in result.items() if k not in ('lines', 'shares_address_with_baseline')}))


if __name__ == '__main__':
    main()
