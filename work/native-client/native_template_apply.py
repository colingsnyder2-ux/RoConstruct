"""Append gate-proven explicit template instantiations to leased native sources.

For each source with a promotable `claude-template-promote/<Stem>/promotion.json`:

1. skip lines another source already owns (registry) or the file already has;
2. compile the file as it is now -> exact map BEFORE;
3. append the lines, compile -> exact map AFTER;
4. keep the edit only if no BEFORE symbol was lost or moved and every line
   contributes at least one symbol exact at exactly one original address;
   otherwise the original bytes are written back.

The caller must hold a lease on the sources (`roc.cmd lease take`).  Only
appends; never commits.  Proof is relocation-masked body equality, not layout,
link or runtime proof.
"""
import argparse
import json
import os
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc.native_bulk import Targets  # noqa: E402
import native_template_probe as probe  # noqa: E402

HEADER = '// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).'
REGISTRY = HERE / 'claude-template-applied.json'
PROMOTE = HERE / os.environ.get('CLAUDE_PROMOTE_DIR', 'claude-template-promote')  # round N gate output


def exact_map(source, folder, flags, targets):
    code, _, seconds = probe.compile_tu(flags, source, folder)
    if code:
        return None, seconds
    return probe.exact((folder / 'candidate.obj').read_bytes(), targets), seconds


def apply(source, targets, check, registry, out):
    stem = source.stem
    promo = json.loads((PROMOTE / stem / 'promotion.json').read_text())
    result = {'source': promo['source'], 'applied': False}
    if not promo.get('promotable'):
        result['reason'] = 'not promotable'
        return result
    original = source.read_bytes()
    text = original.decode('utf-8', errors='surrogateescape')
    wanted = [l for l in promo['lines'] if registry.get(l['line'], promo['source']) == promo['source']
              and l['line'] not in text]
    if not wanted:
        result['reason'] = 'every line already owned elsewhere or present'
        return result
    flags = probe.flags_for(check, source, out / stem)
    before, _ = exact_map(source, out / stem / 'before', flags, targets)
    if before is None:
        result['reason'] = 'source does not compile before edit'
        return result
    newline = '\r\n' if b'\r\n' in original else '\n'
    block = newline.join([HEADER] + [l['line'] for l in wanted])
    source.write_bytes((text.rstrip() + newline + newline + block + newline).encode('utf-8', errors='surrogateescape'))
    after, seconds = exact_map(source, out / stem / 'after', flags, targets)
    lost = [] if after is None else sorted(s for s, a in before.items() if sorted(after.get(s, [])) != sorted(a))
    proven = {} if after is None else {l['line']: sorted((after[s][0], s) for _, s in l['symbols']
                                                         if s not in before and len(after.get(s, [])) == 1)
                                       for l in wanted}
    if after is None or lost or not all(proven.values()):
        source.write_bytes(original)  # revert: the edit is not proven
        result.update(reason='reverted', compile_failed=after is None, lost=lost[:20],
                      lines_without_proof=[l for l, v in proven.items() if not v][:20])
        return result
    for line in proven:
        registry[line] = promo['source']
    addresses = {a for v in proven.values() for a, _ in v}
    result.update(applied=True, lines=len(proven), new_exact_symbols=sum(map(len, proven.values())),
                  new_exact_addresses=len(addresses), addresses=sorted(addresses), compile_seconds=seconds,
                  baseline_exact_symbols=len(before), proof=proven)
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('sources', nargs='+', type=Path)
    ap.add_argument('--output', type=Path, default=HERE / 'claude-template-applied')
    ap.add_argument('--tag', default='applied', help='receipt file stem (applied, applied-r2, ...)')
    args = ap.parse_args()
    targets, check = Targets('2008-06'), probe.runner()
    registry = json.loads(REGISTRY.read_text()) if REGISTRY.exists() else {}
    for source in args.sources:
        result = apply(source.resolve(), targets, check, registry, args.output.resolve())
        (args.output / source.stem).mkdir(parents=True, exist_ok=True)
        (args.output / source.stem / (args.tag + '.json')).write_text(json.dumps(result, indent=1) + '\n')
        REGISTRY.write_text(json.dumps(registry, indent=1, sort_keys=True) + '\n')
        print(json.dumps({k: v for k, v in result.items() if k not in ('proof', 'addresses')}))


if __name__ == '__main__':
    main()
