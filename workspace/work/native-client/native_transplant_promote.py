"""Promote only exact, address-tagged generated bodies into one leased class file."""
import argparse
import json
import os
import re
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
TAG = re.compile(r'^// native-transplant: ([0-9a-fA-F]{8})\s*$', re.M)
SUPPORT = re.compile(r'^// native-support-global\s*$\r?\n([^\r\n]+)$', re.M)


def body_at(text, start):
    brace = text.find('{', start)
    if brace < 0:
        raise ValueError('tag has no definition')
    depth = 0
    for pos in range(brace, len(text)):
        if text[pos] == '{':
            depth += 1
        elif text[pos] == '}':
            depth -= 1
            if depth == 0:
                return text[start:pos + 1].strip()
    raise ValueError('unterminated tagged definition')


def add_support_globals(text, additions):
    """Place source-owned file globals after destination includes."""
    if not additions:
        return text
    includes = list(re.finditer(r'^\s*#include\s+[<"][^>"]+[>"]\s*$', text, re.M))
    if not includes:
        raise ValueError('existing destination has no include block for support globals')
    at = includes[-1].end()
    return text[:at] + '\n\n' + '\n'.join(additions) + text[at:]


def same_include(left, right, source):
    """Compare a probe's quoted include with a repo-relative provider path."""
    try:
        lhs = Path(left)
        if not lhs.is_absolute():
            lhs = source.parent / lhs
        rhs = Path(right)
        if not rhs.is_absolute():
            rhs = ROOT / rhs
        return lhs.resolve() == rhs.resolve()
    except OSError:
        return False


def portable_include(value, destination):
    """Never put a workstation-absolute repository header in native source."""
    path = Path(value)
    if not path.is_absolute():
        return value
    try:
        path.resolve().relative_to(ROOT)
    except ValueError:
        return value
    return os.path.relpath(str(path.resolve()), str(destination.parent)).replace('\\', '/')


def _native_or_root(root, rel):
    first = (root / rel).resolve()
    alt = (ROOT / 'rebuild/2008-06/native-headers' / rel).resolve()
    return first if first.is_file() or not alt.is_file() else alt


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--source', type=Path, required=True)
    ap.add_argument('--manifest', type=Path, required=True)
    ap.add_argument('--destination', type=Path, required=True)
    ap.add_argument('--include', default='')
    ap.add_argument('--namespace', default='')
    ap.add_argument('--flags', default='')
    ap.add_argument('--source-includes', action='store_true',
                    help='retain quoted donor includes needed by transplanted bodies')
    ap.add_argument('--source-root', type=Path,
                    help='real donor directory for relative includes in generated probe source')
    ap.add_argument('--addr', action='append', required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--render', type=Path,
                    help='write candidate destination only; never changes destination')
    ap.add_argument('--apply', action='store_true')
    args = ap.parse_args()
    requested = {f'{int(value, 16):08x}' for value in args.addr}
    manifest = json.loads(args.manifest.read_text())
    exact = {row['addr'] for family in manifest.get('families', [])
             for row in family.get('symbols', []) if row.get('status') == 'inactive_exact'}
    if not requested <= exact:
        raise ValueError('not exact: ' + ', '.join(sorted(requested - exact)))
    source = args.source.read_text(errors='replace')
    probe_includes = list(dict.fromkeys(re.findall(r'^\s*#include\s+"([^"]+)"', source, re.M)))
    donor_paths = []
    skipped_donor_includes = []
    if args.source_root:
        include_root = args.source_root.resolve()
        for value in probe_includes:
            path = Path(value)
            path = path.resolve() if path.is_absolute() else _native_or_root(include_root, path)
            if path.is_file():
                if path not in donor_paths:
                    donor_paths.append(path)
            else:
                skipped_donor_includes.append(value)
    supports = [match.group(1).strip() for match in SUPPORT.finditer(source)]
    tags = list(TAG.finditer(source))
    tagged = {match.group(1).lower(): body_at(source, match.end()) for match in tags}
    if not requested <= tagged.keys():
        raise ValueError('source lacks tags: ' + ', '.join(sorted(requested - tagged.keys())))
    destination = args.destination.resolve()
    try:
        rel = destination.relative_to(ROOT).as_posix()
    except ValueError:
        raise ValueError('destination outside repository')
    old = destination.read_text(errors='replace') if destination.exists() else ''
    old_includes = list(dict.fromkeys(re.findall(r'^\s*#include\s+"([^"]+)"', old, re.M)))
    donor_includes = []
    if args.source_includes and old.strip():
        existing = {((destination.parent / value).resolve() if not Path(value).is_absolute()
                    else Path(value).resolve()) for value in old_includes}
        include_root = args.source_root.resolve() if args.source_root else args.source.parent.resolve()
        for value in probe_includes:
            path = Path(value)
            path = path.resolve() if path.is_absolute() else _native_or_root(include_root, path)
            if path not in existing:
                donor_includes.append(portable_include(str(path), destination))
    additions = [(addr, tagged[addr]) for addr in sorted(requested) if tagged[addr] not in old]
    support_additions = [line for line in supports if line not in old]
    profile = '// native-flags: %s\n' % args.flags if args.flags else ''
    needs_profile = bool(old.strip() and profile and not re.search(r'^// native-flags:', old, re.M))
    # Existing sources own their compiler profile.  A transplant profile only
    # seeds a new source or one that has no declared profile; otherwise it
    # would silently change every pre-existing body in the destination TU.
    rendered_profile = profile if not old.strip() or needs_profile else ''
    result = {'source': str(args.source), 'manifest': str(args.manifest), 'destination': rel,
              'requested': sorted(requested), 'exact': sorted(requested & exact),
              'added': [addr for addr, _ in additions],
              'already_present': sorted(requested - {addr for addr, _ in additions}),
              'support_globals': supports,
              'support_globals_added': support_additions,
              'source_includes_added': donor_includes,
              'source_includes_skipped': skipped_donor_includes,
              'profile_added': needs_profile,
              'applied': False}
    if old.strip():
        base = add_support_globals(old.rstrip(), support_additions)
        if donor_includes:
            includes = list(re.finditer(r'^\s*#include\s+[<"][^>"]+[>"]\s*$', base, re.M))
            if not includes:
                raise ValueError('existing destination has no include block for donor includes')
            at = includes[-1].end()
            base = base[:at] + '\n' + ''.join('#include "%s"\n' % value for value in donor_includes) + base[at:]
        rendered = rendered_profile + base + ('\n\n' + '\n\n'.join(body for _, body in additions) if additions else '') + '\n'
    else:
        if not args.include:
            raise ValueError('new native source needs --include')
        scopes = [name for name in args.namespace.split('::') if name]
        opened = ''.join('namespace %s {\n' % name for name in scopes)
        closed = ''.join('}\n' for _ in scopes)
        # The isolated probe records provider headers as absolute paths.  A
        # repo-relative plan include is the same file, not a second include;
        # emitting it verbatim from native-classes would also make MSVC search
        # an invalid `native-classes/tools/...` path.  If it is needed, write
        # a portable path relative to the destination source instead.
        already_included = (any(path.resolve() == (ROOT / args.include).resolve() for path in donor_paths)
                            if args.source_root and args.include else
                            any(same_include(value, args.include, args.source) for value in probe_includes))
        if args.include and not already_included:
            target = (ROOT / args.include).resolve()
            probe_includes.insert(0, os.path.relpath(str(target), str(destination.parent)).replace('\\', '/'))
        if args.source_root:
            probe_includes = [portable_include(str(path), destination) for path in donor_paths]
        else:
            probe_includes = [portable_include(value, destination) for value in probe_includes]
        rendered = rendered_profile + ''.join('#include "%s"\n' % value for value in probe_includes) + '\n%s%s%s\n%s' % (
                                                       '\n'.join(supports) + ('\n\n' if supports else ''), opened,
                                                       '\n\n'.join(body for _, body in additions), closed)
    if args.render:
        args.render.parent.mkdir(parents=True, exist_ok=True)
        args.render.write_text(rendered)
        result['rendered'] = str(args.render.resolve())
    if args.apply and (additions or needs_profile):
        check = subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'check', rel], cwd=ROOT,
                               capture_output=True, text=True)
        if check.returncode:
            raise ValueError('lease check failed: ' + check.stdout + check.stderr)
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text(rendered)
        result['applied'] = True
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=1) + '\n')
    print(json.dumps(result))


if __name__ == '__main__':
    main()
