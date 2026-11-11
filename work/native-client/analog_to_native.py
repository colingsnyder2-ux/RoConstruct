"""Convert server-exact (100%) mined analogs of placeholder classes into native header + source, then prove them.

A 100% analog carries the real body, a receiver "view" class (fields + method declarations) and offsetof checks that
pin its layout. This keeps the receiver class, the helper types the body uses, its macros and the bodies; drops the
analog's re-declared Ogre views in favour of the real Ogre 1.4.5 headers; writes
  rebuild/2008-06/native-headers/OgreAuto/<Class>2008.h  and  rebuild/2008-06/native-classes/OgreAuto<Class>.cpp
then runs prove.py --infer-names on the file. A compile failure moves the pair to work/native-client/converter-failed/
and reports the first error. Classes that already have a native header are reported for a manual merge, never edited.

  python work/native-client/analog_to_native.py ADDR [ADDR ...]
  python work/native-client/analog_to_native.py --fingerprint     # placeholders with a high-confidence port origin
  python work/native-client/analog_to_native.py --scan            # list convertible groups, change nothing
"""
import argparse
import collections
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE / 'ogre'))
from roc import match  # noqa: E402
import fingerprint  # noqa: E402

ANALOGS = ROOT / 'src/2008-06'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
OGRE_INC = ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include'
FAILED = HERE / 'converter-failed'
REGISTRY = HERE / 'ogre-names-registry.json'
DEF = re.compile(r'^([\w][\w\s\*&:<>,]*?)\b((?:\w+::)*)(\w+)::(~?\w+)\s*\(([^;{]*)\)\s*(const\s*)?\{', re.M)
TYPE = re.compile(r'\b(class|struct)\s+(\w+)\b([^;{()]*)\{')


def block(text, at):
    """text[at:] from a '{'-bearing head to its matching '}' (+ trailing ';' for type definitions)."""
    j = text.index('{', at)
    depth = 0
    for k in range(j, len(text)):
        depth += {'{': 1, '}': -1}.get(text[k], 0)
        if depth == 0:
            end = k + 1
            return text[at:end + 1] if text[end:end + 1] == ';' else text[at:end]
    raise ValueError('unbalanced')


def real_ogre(name):
    return (OGRE_INC / ('Ogre%s.h' % name)).is_file()


def parse(addr):
    """-> dict(class, ns, method, flags, body, types{name: text}, macros, checks) or a reason string."""
    path = ANALOGS / (addr + '.cpp')
    if not path.is_file():
        return 'no analog'
    text = path.read_text(errors='replace')
    if '// from server: 100%' not in text[:400]:
        return 'analog not 100%'
    if re.search(r'^// roc-lib:', text, re.M):
        return 'library recipe analog (vendor lane)'
    flags = re.search(r'^// roc-flags:\s*(.*)$', text, re.M)
    defs = [m for m in DEF.finditer(text) if m.group(3) not in ('std', 'boost')]
    if not defs:
        return 'no member definition'
    d = defs[-1]                                       # the target body is the last definition in the analog
    cls, method = d.group(3), d.group(4)
    ns = d.group(2).rstrip(':') or ('Ogre' if re.search(r'namespace\s+Ogre\s*\{[^}]*\b(class|struct)\s+%s\b' % cls, text) else '')
    body = block(text, d.start())
    types = {}
    for m in TYPE.finditer(text):
        name = m.group(2)
        if real_ogre(name) or name in types:
            continue
        try:
            types[name] = block(text, m.start())
        except ValueError:
            continue
    if cls not in types:
        return 'receiver %s not defined in analog' % cls
    if re.search(r'\bchar\s+\w*(pad|unk|gap)\w*\s*\[', types[cls], re.I):
        return 'receiver has raw padding view'
    used = set(re.findall(r'\b\w+\b', body + types[cls]))
    helpers = {n: t for n, t in types.items() if n != cls and n in used}
    macros = re.findall(r'^#define (?!_)\w+.*?(?<!\\)$', text, re.M | re.S)
    checks = re.findall(r'^typedef char \w+\[.*\];$', text, re.M)
    return dict(addr=addr, cls=cls, ns=ns, method=method, flags=flags.group(1).strip() if flags else '/O2 /GS- /EHsc /MD',
                body=body, view=types[cls], helpers=helpers, macros=[m for m in macros if m.split()[1].split('(')[0] in used],
                checks=checks, text=text)


def ogre_includes(code):
    names = sorted({n for n in set(re.findall(r'\b([A-Z]\w+)\b', code)) if real_ogre(n)})
    g3d = sorted({n for n in set(re.findall(r'\bG3D::(\w+)', code)) if (HEADERS / 'G3D' / (n + '.h')).is_file() or (ROOT / 'tools/libs/g3d-6.09/source/include/G3D' / (n + '.h')).is_file()})
    return ''.join('#include <Ogre%s.h>\n' % n for n in names) + ''.join('#include "G3D/%s.h"\n' % n for n in g3d)


def plausible_names():
    """Class names with outside evidence: proven registry names and RTTI type descriptors."""
    from roc import rtti
    names = set()
    for row in (json.loads(REGISTRY.read_text()) if REGISTRY.is_file() else {}).values():
        if isinstance(row, dict) and not row.get('placeholder'):
            names.update(re.findall(r'(\w+)@', row.get('name', '')))
    for t in rtti.descriptors('2008-06').values():
        names.update(re.findall(r'(\w+)@', t))
    return names


def existing_header(cls):
    for path in HEADERS.rglob('*.h'):
        if re.search(r'\b(class|struct)\s+%s\b[^;]*\{' % re.escape(cls), path.read_text(errors='replace')):
            return path
    return None


def write_group(cls, parts, origins):
    ns = parts[0]['ns']
    flags = collections.Counter(p['flags'] for p in parts).most_common(1)[0][0]
    view = parts[0]['view']
    helpers = {}
    for p in parts:
        helpers.update(p['helpers'])
    origin = ''.join('// port origin (fingerprint, triage only): %s\n' % o for o in sorted(set(origins)) if o)
    header_rel = 'OgreAuto/%s2008.h' % cls
    hdr = ('// 2008-06 native %s%s (inactive), converted from server-exact analogs: %s.\n'
           '// INFERRED (owner rule 2026-11-11): class/member names come from the analog author unless the identity registry\n'
           '// proves them; the layout is the analog\'s, pinned by its offsetof checks (kept in the source).\n%s'
           '#pragma once\n#undef OGRE_NONCLIENT_BUILD\n%s#include <string>\n#include <vector>\n\n%s%s\n%s%s'
           % (ns + '::' if ns else '', cls, ', '.join(p['addr'] for p in parts), origin, ogre_includes(view),
              'namespace %s\n{\n' % ns if ns else '', '\n'.join(helpers[n] for n in sorted(helpers) if n in view) + '\n',
              view, '\n}\n' if ns else '\n'))
    bodies = '\n\n'.join(p['body'] for p in parts)
    macros = sorted({m for p in parts for m in p['macros']})
    checks = sorted({c for p in parts for c in p['checks'] if cls in c or 'Vector3' in c})
    src = ('// native-flags: %s /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include\n'
           '// 2008-06 native %s (inactive): bodies of the server-exact analogs %s.\n'
           '#undef OGRE_NONCLIENT_BUILD\n#include "%s"\n%s#include <stddef.h>\n#include <cmath>\n\n%s%s\n%s\n%s\n%s'
           % (flags, cls, ', '.join(p['addr'] for p in parts), header_rel, ogre_includes(bodies),
              'namespace %s\n{\n' % ns if ns else '',
              '\n'.join(helpers[n] for n in sorted(helpers) if n not in view), '\n'.join(macros), bodies,
              '}\n' if ns else '')) + '\n' + '\n'.join(checks) + '\n'
    hpath, cpath = HEADERS / header_rel, CLASSES / ('OgreAuto%s.cpp' % cls)
    hpath.parent.mkdir(parents=True, exist_ok=True)
    hpath.write_text(hdr.replace('\r\n', '\n'), newline='\r\n')
    cpath.write_text(src.replace('\r\n', '\n'), newline='\r\n')
    return hpath, cpath


def prove(cpath):
    run = subprocess.run([sys.executable, str(HERE / 'prove.py'), str(cpath), '--infer-names', '--rounds', '2'],
                         cwd=ROOT, capture_output=True, text=True)
    return run.returncode, (run.stdout + run.stderr).strip().splitlines()


def compile_error(cpath):
    family = 'prove-' + cpath.stem
    for log in sorted((HERE / 'prove-out' / family / 'objects').rglob('*.log'), key=lambda p: -p.stat().st_mtime)[:1]:
        lines = [l for l in log.read_text(errors='replace').splitlines() if ' error ' in l or 'fatal error' in l]
        if lines:
            return lines[0][-200:]
    return None


def targets_from_fingerprint():
    data = json.loads(fingerprint.OUT.read_text()) if fingerprint.OUT.is_file() else {'matches': {}}
    return {a: '%s %s' % (m[0]['file'], m[0]['function']) for a, m in data['matches'].items()
            if m and m[0].get('confidence') == 'high'}


def beautify(*paths):
    """Formatting-only pass; beautify.py reverts any file whose proof changes."""
    subprocess.run([sys.executable, str(HERE / 'beautify.py'), *map(str, paths)], cwd=ROOT, capture_output=True)


def exact_addrs(cpath):
    manifest = HERE / 'prove-out' / ('prove-' + Path(cpath).stem) / 'manifest.json'
    data = json.loads(manifest.read_text()) if manifest.is_file() else {'families': []}
    return {c for f in data['families'] for r in f['symbols'] if r['status'] == 'inactive_exact'
            for c in (r.get('candidates') or [])}


def transplant_targets(addrs):
    """Proven-name methods whose class header declares them and whose class .cpp lacks a body: (addr, row, dest)."""
    import native_llm as nl
    import ogre_llm_lane as ol
    registry = json.loads(REGISTRY.read_text())
    out = []
    for a in addrs:
        row = registry.get(a) or {}
        sig, owner = row.get('signature'), row.get('owner_class')
        if row.get('placeholder', True) or not sig or not owner or '<' in owner or '`' in sig:
            continue
        qual = re.sub(r'\s+const$', '', sig.split('(')[0]).split()[-1]
        method, leaf = qual.rsplit('::', 1)[-1], owner.rsplit('::', 1)[-1]
        dest, new = nl.destination_for(owner)
        if not ol.class_header(leaf, method) or not dest or new:
            continue
        if re.search(r'\b%s::%s\s*\(' % (leaf, re.escape(method)), (ROOT / dest).read_text(errors='replace')):
            continue
        out.append((a, owner, leaf, method, dest))
    return out


def transplant(a, owner, leaf, method, dest):
    """Append the analog body to dest inside owner's namespaces; keep only if `a` becomes exact and nothing is lost."""
    text = (ANALOGS / (a + '.cpp')).read_text(errors='replace') if (ANALOGS / (a + '.cpp')).is_file() else ''
    if '// from server: 100%' not in text[:400]:
        return 'no 100% analog'
    lib = re.search(r'^// roc-lib:\s*(\S+)\s+(\S+)', text, re.M)
    if lib:                                           # fork/recipe analog: the body is in the recipe's source file
        from roc import libs
        recipe = libs.RECIPES.get(lib.group(1)) or libs.RECIPES.get(lib.group(1).replace('-dll', ''))
        source = recipe and libs.LIBS / recipe['src'] / lib.group(2)
        if not source or not source.is_file():
            return 'recipe source missing'
        text = source.read_text(errors='replace')
    defs = [m for m in DEF.finditer(text) if m.group(3) == leaf and m.group(4) == method]
    if not defs:
        return 'analog defines no %s::%s' % (leaf, method)
    d = defs[-1]
    body = block(text, d.start())
    body = body[:d.start(2) - d.start()] + body[d.start(3) - d.start():]       # drop namespace qualifiers
    spaces = owner.split('::')[:-1]
    code = ''.join('namespace %s {\n' % n for n in spaces) + body + '\n' + '}\n' * len(spaces)
    path = ROOT / dest
    before = path.read_bytes()
    baseline = exact_addrs(path)
    if not baseline:
        prove(path)
        baseline = exact_addrs(path)
    path.write_bytes(before + ('\r\n// %s: transplanted from the server-exact analog (analog_to_native --transplant)\r\n'
                               % a).encode() + code.replace('\r\n', '\n').replace('\n', '\r\n').encode())
    prove(path)
    after = exact_addrs(path)
    if a in after and baseline <= after:
        beautify(path)
        return 'exact (+%d addrs)' % len(after - baseline)
    path.write_bytes(before)
    err = compile_error(path)
    return 'reverted: ' + (err or ('lost %d' % len(baseline - after) if not baseline <= after else 'not exact'))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('addrs', nargs='*')
    ap.add_argument('--fingerprint', action='store_true')
    ap.add_argument('--scan', action='store_true')
    ap.add_argument('--transplant', action='store_true', help='proven-name methods into their existing class .cpp')
    args = ap.parse_args()
    if args.transplant:
        from roc import leases  # noqa: F401  (lease taken per dest below)
        todo = transplant_targets([x.lower() for x in args.addrs] or fingerprint.default_targets(16))
        sizes = match._functions('2008-06')
        for a, owner, leaf, method, dest in sorted(todo, key=lambda t: -sizes[t[0]]['size']):
            if args.scan:
                print('%s %5d %s::%s -> %s' % (a, sizes[a]['size'], owner, method, dest))
                continue
            lease = subprocess.run([sys.executable, 'roc.py', 'lease', 'take', 'transplant-' + Path(dest).stem, dest,
                                    '--hours', '1'], cwd=ROOT, capture_output=True, text=True)
            if lease.returncode:
                print('%s %s::%s: lease refused (%s)' % (a, owner, method, dest))
                continue
            print('%s %5d %s::%s: %s' % (a, sizes[a]['size'], owner, method, transplant(a, owner, leaf, method, dest)),
                  flush=True)
        return
    origins = targets_from_fingerprint()
    registry = json.loads(REGISTRY.read_text()) if REGISTRY.is_file() else {}
    if args.addrs:
        addrs = [a.lower() for a in args.addrs]
    elif args.fingerprint:
        addrs = sorted(origins)
    else:
        addrs = fingerprint.default_targets(16)
    groups, skipped = collections.defaultdict(list), collections.Counter()
    known = plausible_names()
    for a in addrs:
        if not (registry.get(a) or {}).get('placeholder', True):
            skipped['proven name: ogre_convert/LLM lane'] += 1
            continue
        p = parse(a)
        if isinstance(p, str):
            skipped[p] += 1
            continue
        if p['cls'] not in known and not origins.get(a):
            skipped['class name has no outside evidence (analog placeholder)'] += 1
            continue
        groups[(p['ns'], p['cls'])].append(p)
    for (ns, cls), parts in sorted(groups.items(), key=lambda g: -sum(match._functions('2008-06')[p['addr']]['size'] for p in g[1])):
        size = sum(match._functions('2008-06')[p['addr']]['size'] for p in parts)
        exists = existing_header(cls)
        tag = 'exists %s (manual merge)' % exists.relative_to(ROOT).as_posix() if exists else 'new'
        if args.scan or exists:
            print('%-28s %6d B %2d fn  %s' % (cls, size, len(parts), tag))
            continue
        hpath, cpath = write_group(cls, parts, [origins.get(p['addr']) for p in parts])
        code, lines = prove(cpath)
        err = compile_error(cpath)
        if code or err:
            dest = FAILED / cls
            dest.mkdir(parents=True, exist_ok=True)
            for f in (hpath, cpath):
                shutil.move(str(f), str(dest / f.name))
            print('%-28s %6d B  FAILED %s' % (cls, size, err or (lines[-1] if lines else 'prove failed')))
        else:
            beautify(cpath, hpath)
            print('%-28s %6d B  %s' % (cls, size, next((l for l in lines if l.startswith('rebuild/')), lines[-1] if lines else '')))
    print('skipped:', dict(skipped))


if __name__ == '__main__':
    main()
