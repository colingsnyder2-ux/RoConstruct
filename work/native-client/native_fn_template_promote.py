"""Promotion gate for explicit instantiations of function / member-function templates.

Companion of native_template_promote.py (class templates).  Candidates are
closure-bound `??$` symbols (a template function with a proven name and
original address) that no native source owns yet.  The instantiation line is
the undecorated declaration:  `template <ret> Owner::name<Args>(params);`

Per source: baseline exact map -> source + candidate lines whose owner the
unit already mentions (compiler-rejected lines dropped) -> keep lines whose
own symbol is exact at its closure address -> recompile with kept lines only,
require no baseline exact symbol lost.  Output is promotion.json in the same
shape native_template_apply.py reads (CLAUDE_PROMOTE_DIR).
"""
import argparse
import glob
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import match  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402
from native_conversion_queue import owner, undecorate  # noqa: E402
import native_template_probe as probe  # noqa: E402

# no access specifiers (0x80), no calling convention keywords (0x2), no static/virtual (0x200)
DECLARATION = 0x282


def candidates(closure):
    native = set()
    for path in glob.glob(str(HERE / 'claude-*-applied/*/applied*.json')):
        d = json.loads(Path(path).read_text())
        if d.get('applied'):
            native |= set(d['addresses'])
    out = {}
    for row in json.loads(closure.read_text())['bindings']:
        s = row['symbol']
        if s.startswith('??$') and row['function_start'] and row['addr'] not in native:
            text = undecorate(s, DECLARATION).strip()
            # pointer non-type argument: `<&char * RBX::sX>` is printed with its type; C++ wants `<&RBX::sX>`
            text = re.sub(r'&[^,<>&()]*?((?:\w+::)*\w+)(?=[,>])', r'&\1', text)
            if text and '`' not in text:
                out[s] = (row['addr'], 'template %s;' % text, owner(s))
    return out


def promote(source, output, targets, check, cands):
    source = source.resolve()
    result = {'source': source.relative_to(ROOT).as_posix(), 'promotable': False}
    flags = probe.flags_for(check, source, output)
    code, _, _ = probe.compile_tu(flags, source, output / 'baseline')
    if code:
        result['probe_status'] = 'baseline-compile-failed'
        return result
    result['probe_status'] = 'ok'
    raw = (output / 'baseline/candidate.obj').read_bytes()
    base = probe.exact(raw, targets)
    _, symbols, definitions, _ = match._coff_data_index(raw)
    # Only classes the unit uses as classes: owners of member functions (access specifier present).
    owners = {owner(name) for name, *_ in symbols.values()
              if name.startswith('?') and re.match(r'(public|private|protected):', undecorate(name, 0))}
    wanted = sorted((line, s, addr) for s, (addr, line, own) in cands.items()
                    if s not in definitions and own in owners)
    result['candidate_lines'] = len(wanted)
    if not wanted:
        return result
    lines, tu = wanted, output / 'probe.cpp'
    for _ in range(120):  # ponytail: cl stops at 100 errors per run; bounded, no source repair
        tu.write_text('#include "%s"\n' % source.as_posix() + '\n'.join(l for l, _, _ in lines) + '\n', encoding='utf-8')
        code, log, _ = probe.compile_tu(flags, tu, output / 'probe')
        bad = {int(n) for n in re.findall(r'probe\.cpp\((\d+)\)', log) if int(n) >= 2}
        if not code or not bad:
            break
        lines = [row for number, row in enumerate(lines, 2) if number not in bad]
    if code or not lines:
        result['probe_status'] = 'probe-compile-failed' if code else 'ok'
        return result
    grown = probe.exact((output / 'probe/candidate.obj').read_bytes(), targets)
    kept = [(l, s, a) for l, s, a in lines if s not in base and grown.get(s) == [a]]
    result['kept_lines'] = len(kept)
    if not kept:
        return result
    final_tu = output / 'final.cpp'
    final_tu.write_text('#include "%s"\n' % source.as_posix() + '\n'.join(l for l, _, _ in kept) + '\n', encoding='utf-8')
    code, _, seconds = probe.compile_tu(flags, final_tu, output / 'final')
    result['final_compile'] = {'exit': code, 'seconds': seconds}
    if code:
        return result
    final = probe.exact((output / 'final/candidate.obj').read_bytes(), targets)
    lost = sorted(s for s, a in base.items() if sorted(final.get(s, [])) != sorted(a))
    proven = [(l, s, a) for l, s, a in kept if final.get(s) == [a]]
    result.update(lost_baseline_symbols=lost, new_exact_symbols=len(proven),
                  new_exact_addresses=len({a for _, _, a in proven}),
                  promotable=not lost and len(proven) == len(kept),
                  lines=[{'line': l, 'symbols': [(a, s)]} for l, s, a in proven])
    if result['promotable']:
        (output / 'promotion.lines.txt').write_text('\n'.join(l for l, _, _ in proven) + '\n', encoding='utf-8')
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('sources', nargs='+', type=Path)
    ap.add_argument('--closure', type=Path, default=HERE / 'claude-identity-closure.json')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    targets, check = Targets('2008-06'), probe.runner()
    cands = candidates(args.closure)
    for source in args.sources:
        folder = args.output.resolve() / source.stem
        folder.mkdir(parents=True, exist_ok=True)
        result = promote(source, folder, targets, check, cands)
        (folder / 'promotion.json').write_text(json.dumps(result, indent=1) + '\n')
        print(json.dumps({k: v for k, v in result.items() if k != 'lines'}))


if __name__ == '__main__':
    main()
