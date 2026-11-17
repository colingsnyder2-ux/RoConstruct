"""Header-gap fill: declare queue methods that no native header declares, rebuilt from their decorated symbols.

Only the layout-neutral subset: non-virtual member and static member functions (MSVC access codes Q/A/I and S/C/K)
of a class defined by exactly one native header; vendor classes (Ogre::, G3D::, ...) stay in the vendor lane.  Each
line is `// INFERRED: <decorated symbol>` evidence, appended with its own access label before the class's closing
brace.  Applying leases each header, edits it, and keeps the edit only if a probe that includes it still compiles.
  python work/native-client/header_gap_fill.py            # dry run: what would be added, per header
  python work/native-client/header_gap_fill.py --apply [--limit-headers N]"""
import argparse
import collections
import json
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_llm as n

ROOT = n.ROOT
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
VENDOR = ('G3D::', 'std::', 'boost::', 'Ogre::', 'ATL::', 'Scintilla::')
ACCESS = {'Q': 'public', 'A': 'private', 'I': 'protected', 'S': 'public', 'C': 'private', 'K': 'protected'}


def undname(symbols):
    out = {}
    symbols = list(symbols)
    for i in range(0, len(symbols), 200):
        text = subprocess.run([str(n.UNDNAME), *symbols[i:i + 200]], capture_output=True, text=True).stdout
        out.update(re.findall(r'Undecoration of :- "(.*?)"\s*\n\s*is :- "(.*?)"', text))
    return out


def declaration(plain, owner):
    """'public: static bool __cdecl RBX::Math::fixDenorm(class G3D::Vector3 &)' -> 'static bool fixDenorm(G3D::Vector3 &);'"""
    body = re.sub(r'^(?:public|private|protected):\s*', '', plain)
    body = re.sub(r'\b(?:class|struct|union|enum)\s+', '', body)
    body = re.sub(r'\s*__thiscall\s*|\s*__cdecl\s*', ' ', body).strip()
    head, sep, tail = body.partition(owner + '::')
    if not sep:
        return None
    return re.sub(r'\s+', ' ', (head + tail).strip()).replace('( ', '(').replace(' )', ')') + ';'


def class_span(text, leaf):
    """(start, closing-brace index) of the one definition of class LEAF in TEXT, or None."""
    found = list(re.finditer(r'\b(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text))
    if len(found) != 1:
        return None
    depth = 0
    for i in range(found[0].end() - 1, len(text)):
        depth += {'{': 1, '}': -1}.get(text[i], 0)
        if depth == 0:
            return found[0].start(), i
    return None


# Core headers have one owner (CLAUDE.md): additions there become proposals (header-gap-proposals.json), not edits.
CORE = {'v8tree/Instance.h', 'v8datamodel/DataModel.h', 'util/Events.h', 'reflection/reflection.h',
        'reflection/property.h', 'reflection/type.h', 'reflection/member.h', 'reflection/function.h', 'reflection/event.h'}
PROPOSALS = []


def plan():
    queue = json.loads(n.QUEUE.read_text())
    n.declaring_header('')
    native = [(p, t) for p, t in n.DECL_FILES if HEADERS in p.parents]
    wanted = collections.defaultdict(list)          # (header, owner) -> [(symbol, access)]
    for cl in queue['classes']:
        owner = cl['owner']
        if cl['template'] or owner.startswith(VENDOR):
            continue
        leaf = owner.rsplit('::', 1)[-1]
        spaces = owner.split('::')[:-1]           # RBX::Math must not land in Ogre::Math (OgreMath.h)
        defs = [p for p, t in native if class_span(t, leaf)
                and all(re.search(r'\bnamespace\s+%s\b' % re.escape(ns), t) for ns in spaces)]
        if len(defs) != 1:
            continue
        for m in cl['methods']:
            if m.get('headers', cl.get('headers', [])) or '`' in m['declaration']:
                continue
            code = re.search(r'%s@(?:\w+@)*@([A-Z])' % re.escape(leaf), m['symbol'])
            if code and code.group(1) in ACCESS:
                wanted[(defs[0], owner)].append((m['symbol'], ACCESS[code.group(1)]))
    # Also every registry / identity-session name (load_registry: proven + inferred tiers) of a function the website
    # still counts as remaining, whose class lives in exactly one native header but does not declare the member.
    remaining = n.remaining_set()
    by_owner = collections.defaultdict(list)
    for addr, row in n.load_registry().items():
        name, owner = row.get('name') or '', row.get('owner_class') or ''
        if (addr not in remaining or row.get('kind') != 'code' or not owner or '<' in owner or owner.startswith(VENDOR)
                or not name.startswith('?') or name.startswith('??$')
                or row.get('inferred') or 'inferred' in str(row.get('name_source', ''))):   # proven names only
            continue
        by_owner[owner].append(name)
    for owner, symbols in by_owner.items():
        leaf = owner.rsplit('::', 1)[-1]
        spaces = owner.split('::')[:-1]
        defs = [p for p, t in native if class_span(t, leaf)
                and all(re.search(r'\bnamespace\s+%s\b' % re.escape(ns), t) for ns in spaces)]
        if len(defs) != 1:
            continue
        for symbol in symbols:
            code = re.search(r'%s@(?:\w+@)*@([A-Z])' % re.escape(leaf), symbol)
            if code and code.group(1) in ACCESS and (symbol, ACCESS[code.group(1)]) not in wanted[(defs[0], owner)]:
                wanted[(defs[0], owner)].append((symbol, ACCESS[code.group(1)]))
    plain = undname({s for rows in wanted.values() for s, _ in rows})
    edits = collections.defaultdict(list)           # header -> [(owner, access, decl, symbol)]
    for (header, owner), rows in wanted.items():
        text = header.read_text(errors='replace')
        span = class_span(text, owner.rsplit('::', 1)[-1])
        for symbol, access in rows:
            decl = declaration(plain.get(symbol, ''), owner)
            name = decl and re.search(r'(~?\w+)\s*\(', decl)
            # Skip names the class already mentions (overloads need judgement) and anything undname left mangled.
            if not decl or not name or '?' in decl or re.search(r'\b%s\s*\(' % re.escape(name.group(1)), text[span[0]:span[1]]):
                continue
            if name.group(1) in ('f', 'g', 'h', 'method', 'fn', 'func', 'call', 'helper') or name.group(1).startswith(('func_', 'sub_', 'FUN_')):
                continue                                     # analog placeholder names, not binary symbols
            if re.search(r'[\w>]::~?\w+\s*\(', decl):           # owner/class mismatch left a qualified name
                continue
            if header.relative_to(HEADERS).as_posix() in CORE:
                PROPOSALS.append(dict(header=header.relative_to(HEADERS).as_posix(), owner=owner, access=access,
                                      declaration=decl, symbol=symbol))
                continue
            edits[header].append((owner, access, decl, symbol))
    return edits


def apply_header(header, rows):
    text = header.read_text(errors='replace')
    by_owner = collections.defaultdict(list)
    for owner, access, decl, symbol in rows:
        by_owner[owner].append((access, decl, symbol))
    for owner, items in by_owner.items():
        start, end = class_span(text, owner.rsplit('::', 1)[-1])
        indent = re.match(r'[ \t]*', text[text.rfind('\n', 0, start) + 1:]).group(0)
        block = ''.join('%s%s:\n%s\t%s   // INFERRED: %s (header gap, header_gap_fill.py)\n' % (indent, access, indent, decl, symbol)
                        for access, decl, symbol in items)
        text = text[:end] + block + text[end:]
    return text


def compiles(header):
    """A probe including only HEADER compiles with the native gate's flags."""
    probe = ROOT / 'work/native-client/native-llm/header-fill-probe.cpp'
    rel = header.relative_to(HEADERS).as_posix()
    probe.write_text('#include "%s"\n' % rel)
    tc = n.match.setup.compilers()[21022]
    flags = ['/nologo', '/c', '/Zs', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/I' + str(HEADERS)]
    flags += n.header_include_flags(str(header.relative_to(ROOT)), '').split()
    run = subprocess.run([tc, *flags, str(probe)], capture_output=True, text=True, cwd=probe.parent,
                         env=dict(__import__('os').environ, **n.match.setup.toolchain_env(21022)) if hasattr(n.match.setup, 'toolchain_env') else None)
    return run.returncode == 0, (run.stdout + run.stderr)[-600:]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--limit-headers', type=int, default=0)
    args = ap.parse_args()
    edits = plan()
    (ROOT / 'work/native-client/header-gap-proposals.json').write_text(json.dumps(PROPOSALS, indent=1))
    print('%d core-header proposals -> work/native-client/header-gap-proposals.json' % len(PROPOSALS))
    total = sum(len(v) for v in edits.values())
    print('%d declarations in %d headers' % (total, len(edits)))
    for header, rows in sorted(edits.items(), key=lambda kv: -len(kv[1])):
        print('  %3d  %s' % (len(rows), header.relative_to(HEADERS).as_posix()))
        for owner, access, decl, symbol in rows[:3]:
            print('         %s %s: %s' % (owner, access, decl))
    if not args.apply:
        return
    done = 0
    for header, rows in sorted(edits.items(), key=lambda kv: -len(kv[1])):
        if args.limit_headers and done >= args.limit_headers:
            break
        rel = header.relative_to(ROOT).as_posix()
        lease = subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'take', 'header-gap:' + header.name, rel, '--hours', '2'],
                               cwd=ROOT, capture_output=True, text=True)
        if lease.returncode:
            print('LEASE REFUSED', rel, (lease.stdout + lease.stderr)[-200:])
            continue
        before = header.read_bytes()
        ok_before, _ = compiles(header)
        header.write_text(apply_header(header, rows), errors='replace')
        ok_after, log = compiles(header)
        if ok_before and not ok_after:
            header.write_bytes(before)
            print('REVERTED', rel, log.strip().splitlines()[-1] if log.strip() else '')
        else:
            done += 1
            print('ADDED %d to %s (standalone compile %s)' % (len(rows), rel, 'ok' if ok_after else 'was already failing'))
        subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'release', 'header-gap:' + header.name], cwd=ROOT, capture_output=True)


if __name__ == '__main__':
    main()
