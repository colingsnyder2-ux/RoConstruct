"""Which compiler profile makes a native source emit the most byte-exact bodies.

Writes only under --output.  For each source: compile with its current
profile (pinned `// native-flags:` or the checker default) and with each
alternate profile; map exact symbols -> original addresses per profile.

  superset  alternate keeps every currently exact symbol and adds more:
            safe to pin for the whole file
  split     alternate adds exact symbols but loses others: the file mixes
            code from two profiles (needs a file split, review)
  none      no alternate adds anything

Relocation-masked body proof only.
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

BASE = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS'
ALTERNATES = {
    'fp-fast': BASE + ' /fp:fast',
    'ox': BASE.replace('/O2', '/Ox'),
    'ox-fp-fast': BASE.replace('/O2', '/Ox') + ' /fp:fast',
    'o1': BASE.replace('/O2', '/O1'),
    'gs': BASE.replace(' /GS-', ''),
    'oy-': BASE.replace('/Oy', '/Oy-'),
    'eha': BASE.replace('/EHsc', '/EHa'),
}


ONLY = os.environ.get('CLAUDE_PROFILES')  # comma list to limit the sweep
if ONLY:
    ALTERNATES = {k: v for k, v in ALTERNATES.items() if k in ONLY.split(',')}


def exact_with(check, source, folder, profile, targets):
    old = os.environ.pop('NATIVE_FLAGS', None)
    if profile:
        os.environ['NATIVE_FLAGS'] = profile
    try:
        flags = probe.flags_for(check, source, folder)
    finally:
        os.environ.pop('NATIVE_FLAGS', None)
        if old:
            os.environ['NATIVE_FLAGS'] = old
    code, _, _ = probe.compile_tu(flags, source, folder)
    if code:
        return None
    return {s: sorted(a) for s, a in probe.exact((folder / 'candidate.obj').read_bytes(), targets).items()}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('sources', nargs='+', type=Path)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    targets, check = Targets('2008-06'), probe.runner()
    for source in args.sources:
        source = source.resolve()
        folder = args.output.resolve() / source.stem
        current = exact_with(check, source, folder / 'current', None, targets)
        result = {'source': source.relative_to(ROOT).as_posix(), 'verdict': 'current-compile-failed'}
        if current is not None:
            unique = lambda m: {a[0] for a in m.values() if len(a) == 1}  # noqa: E731
            rows = {}
            for name, profile in ALTERNATES.items():
                got = exact_with(check, source, folder / name, profile, targets)
                if got is None:
                    continue
                gained = sorted(unique(got) - unique(current))
                lost = sorted(s for s in current if got.get(s) != current[s])
                # Keep per-symbol evidence too.  A mixed-profile splitter must
                # move only bodies directly proved by this alternate object.
                rows[name] = {
                    'profile': profile,
                    'gained_addresses': gained,
                    'gained_symbols': [
                        {'symbol': symbol, 'address': got[symbol][0]}
                        for symbol in sorted(got)
                        if len(got[symbol]) == 1 and got[symbol][0] in gained
                    ],
                    'lost_symbols': len(lost),
                    'lost_symbol_names': lost,
                }
            best = max(rows.items(), key=lambda kv: (not kv[1]['lost_symbols'], len(kv[1]['gained_addresses'])), default=None)
            gains = {n: r for n, r in rows.items() if r['gained_addresses']}
            verdict = 'none'
            if gains:
                verdict = 'superset' if any(not r['lost_symbols'] for r in gains.values()) else 'split'
            result.update(verdict=verdict, current_exact_symbols=len(current), profiles=rows,
                          best=best[0] if best and best[1]['gained_addresses'] else None)
        folder.mkdir(parents=True, exist_ok=True)
        (folder / 'profile.json').write_text(json.dumps(result, indent=1) + '\n')
        print(json.dumps({'source': result['source'].split('/')[-1], 'verdict': result['verdict'], 'best': result.get('best'),
                          'gain': {n: (len(r['gained_addresses']), r['lost_symbols'])
                                   for n, r in result.get('profiles', {}).items() if r['gained_addresses']}}))


if __name__ == '__main__':
    main()
