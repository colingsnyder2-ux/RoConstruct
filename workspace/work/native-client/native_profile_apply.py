"""Pin a proven better compiler profile in leased native sources.

For each source whose profile receipt selects an alternate profile as a superset
(more exact addresses, no exact symbol lost):

1. exact map BEFORE with the file as it is;
2. replace the existing `// native-flags:` line with that exact proven profile,
   or insert it after the leading comment block
   (the checker reads that line: rebuild/2008-06/tests/native_check_runner.py);
3. exact map AFTER with the checker's own flags; keep only if nothing was
   lost and at least one new address is exact, else write the original back.

Caller must hold the lease.  Never commits.
"""
import argparse
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc.native_bulk import Targets  # noqa: E402
import native_template_probe as probe  # noqa: E402
from native_profile_sweep import BASE  # noqa: E402

PIN = re.compile(r'^// native-flags: (.*)$', re.M)


def exact_map(check, source, folder, targets):
    code, _, _ = probe.compile_tu(probe.flags_for(check, source, folder), source, folder)
    if code:
        return None
    return {s: sorted(a) for s, a in probe.exact((folder / 'candidate.obj').read_bytes(), targets).items()}


def apply(source, check, targets, out, sweep_root):
    sweep = json.loads((sweep_root / source.stem / 'profile.json').read_text())
    profile_name = sweep.get('best')
    row = sweep.get('profiles', {}).get(profile_name)
    result = {'source': sweep['source'], 'applied': False}
    if not row or not row['gained_addresses'] or row['lost_symbols']:
        result['reason'] = 'no proven superset profile'
        return result
    profile = row['profile']
    original = source.read_bytes()
    text = original.decode('utf-8-sig', errors='surrogateescape')
    bom = original[:3] == b'\xef\xbb\xbf'
    pinned = PIN.search(text)
    if pinned and pinned[1].strip() == profile:
        result['reason'] = 'already pins selected profile'
        return result
    before = exact_map(check, source, out / source.stem / 'before', targets)
    if before is None:
        result['reason'] = 'does not compile before edit'
        return result
    newline = '\r\n' if '\r\n' in text else '\n'
    if pinned:
        edited = text[:pinned.start(1)] + profile + text[pinned.end(1):]
    else:
        lines = text.split(newline)
        at = 0
        while at < len(lines) and lines[at].startswith('//'):
            at += 1
        lines.insert(at, '// native-flags: %s' % profile)
        edited = newline.join(lines)
    source.write_bytes((b'\xef\xbb\xbf' if bom else b'') + edited.encode('utf-8', errors='surrogateescape'))
    after = exact_map(check, source, out / source.stem / 'after', targets)
    unique = lambda m: {a[0] for a in m.values() if len(a) == 1}  # noqa: E731
    lost = [] if after is None else sorted(s for s in before if after.get(s) != before[s])
    gained = [] if after is None else sorted(unique(after) - unique(before))
    if after is None or lost or not gained:
        source.write_bytes(original)
        result.update(reason='reverted', compile_failed=after is None, lost=lost[:20])
        return result
    result.update(applied=True, profile=profile_name, addresses=gained, new_exact_addresses=len(gained), exact_symbols_before=len(before),
                  exact_symbols_after=len(after))
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('sources', nargs='+', type=Path)
    ap.add_argument('--output', type=Path, default=HERE / 'claude-profile-applied')
    ap.add_argument('--sweep-root', type=Path, default=HERE / 'claude-profile-sweep')
    args = ap.parse_args()
    targets, check = Targets('2008-06'), probe.runner()
    for source in args.sources:
        result = apply(source.resolve(), check, targets, args.output.resolve(), args.sweep_root.resolve())
        (args.output / source.stem).mkdir(parents=True, exist_ok=True)
        (args.output / source.stem / 'applied.json').write_text(json.dumps(result, indent=1) + '\n')
        print(json.dumps({k: v for k, v in result.items() if k != 'addresses'}))


if __name__ == '__main__':
    main()
