"""Map each native source to its proposed original 2008 path, for the final restructure (no files move).

  python work/native-client/source_layout_map.py            -> writes work/native-client/source-layout-map.json, prints counts
  python work/native-client/source_layout_map.py --show 20  -> also prints 20 sample rows per evidence kind

The 2008 exe embeds paths such as d:\\Roblox\\Releases\\2008.06.17\\Client\\Rendering\\g3d\\include\\G3D/Table.h and
.\\glg3dcpp\\Texture.cpp, so the original tree is the rbxgs-style Client/... layout. Evidence, strongest first:
  exe-path       a source path string in the 2008 exe names this file
  line-directive the native file's own `#line "..."` (a verbatim upstream unit)
  upstream       the native file's header `upstream tools/libs/<lib>/<path>`, rebased onto the 2008 library root
  rbxgs          one file in tools/rbxgs/Client with the same unit name (2007/2008 Roblox tree)
  openrbx        one file in tools/openrbx/Client with the same unit name (Dec 2007 tree)
Rows with no evidence, or with several candidate files, are listed as unmapped/ambiguous for review. Several native
files mapping to one original path are merge groups (split units to rejoin).
"""
import argparse
import collections
import json
import re
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
NATIVE = ROOT / 'rebuild/2008-06/native-classes'
EXE = ROOT / 'clients/2008-06/Roblox.exe'
OUT = HERE / 'source-layout-map.json'
# upstream library tree -> where the 2008 build kept it (from exe path strings where known)
LIBRARY_ROOTS = {
    'g3d-6.09/source': 'Client/Rendering/g3d',
    'xtp-11.2.2': 'Client/3rdparty/XTP',
    'boost_1_34_1': 'Client/boost_1_34_1',
    'lua-5.1.4/src': 'Client/App/lua-5.1.4/src',
    'lua-5.1.1/src': 'Client/App/lua-5.1.1/src',
    'jpeg-6b': 'Client/Rendering/g3d/IJG',
    'zlib-1.2.3': 'Client/Rendering/g3d/zlib',
    'mfc-9.0-rtm/atlmfc/src/mfc': 'VC/atlmfc/src/mfc',
    'mfc-9.0/atlmfc/src/mfc': 'VC/atlmfc/src/mfc',
}
PREFIXES = ('G3D', 'XTP', 'Xtp', 'Ogre', 'Boost', 'Lua54', 'Lua', 'Png', 'Jpeg', 'Zlib', 'Mfc', 'Atl', 'Scint')
GUESSED = {'Client/3rdparty/XTP', 'Client/App/lua-5.1.4/src', 'Client/App/lua-5.1.1/src', 'Client/Rendering/g3d/IJG',
           'Client/Rendering/g3d/zlib', 'VC/atlmfc/src/mfc'}


VENDORED = re.compile(r'(?i)(^|/)(boost_\d|3rdparty|lua-5|sdl-|g3d/|png/|zlib/|raknet|ogresdk)')


def exe_paths():
    data = EXE.read_bytes() if EXE.exists() else b''
    found = {}
    for match in re.finditer(rb'[ -~]{4,200}\.(?:cpp|c)(?![A-Za-z])', data):
        text = match.group().decode('latin-1').lstrip('>')
        if '\\' in text or '/' in text:
            found.setdefault(Path(text.replace('\\', '/')).stem.lower(), text)
    return found


def tree_index(root):
    index = collections.defaultdict(list)
    if root.exists():
        for path in root.rglob('*.cpp'):
            if VENDORED.search(path.relative_to(root).as_posix()):
                continue     # bundled third-party trees are not Roblox units
            index[path.stem.lower()].append(path.relative_to(root.parent).as_posix())
    return index


def unit_names(stem):
    """Candidate original unit names for a native file stem (prefix and 2008/split suffixes removed)."""
    names = [stem]
    for prefix in PREFIXES:
        if stem.startswith(prefix) and len(stem) > len(prefix):
            names.append(stem[len(prefix):])
    out = []
    for name in names:
        out.append(name)
        trimmed = re.sub(r'(_?2008|_load|_\w+Trial)$', '', name)
        if trimmed != name:
            out.append(trimmed)
    if stem.startswith('C') and stem[1:2].isupper():
        out.append(stem[1:])     # MFC class CChildFrame -> ChildFrame.cpp
    return list(dict.fromkeys(n for n in out if n))


def split_of(stem, trees):
    """Longest leading CamelCase part of a split unit name that is one original unit (WorkspaceRaiseError -> Workspace)."""
    parts = re.findall(r'[A-Z][a-z0-9]*|[A-Z]+(?![a-z])', stem)
    for n in range(len(parts) - 1, 0, -1):
        head = ''.join(parts[:n])
        if len(head) < 5:
            break
        for tree, label in trees:
            hits = tree.get(head.lower(), [])
            if len(hits) == 1:
                return dict(path=hits[0], evidence='split-of-' + label)
    return None


def rebase(path, native_stem):
    """Relative ./G3Dcpp/X.cpp style paths (exe strings, #line) sit under the 2008 G3D root."""
    rel = re.sub(r'\\+', '/', path)
    rel = rel[2:] if rel.startswith('./') else rel
    if native_stem.startswith('G3D') and re.match(r'(?i)(g3dcpp|glg3dcpp)/', rel):
        return 'Client/Rendering/g3d/' + rel
    return rel


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--show', type=int, default=0)
    args = ap.parse_args()
    exe = exe_paths()
    rbxgs, openrbx = tree_index(ROOT / 'tools/rbxgs/Client'), tree_index(ROOT / 'tools/openrbx/Client')
    rows, unmapped, ambiguous = [], [], []
    for native in sorted(NATIVE.glob('*.cpp')):
        head = native.read_text(encoding='utf-8', errors='replace')[:1500]
        names = unit_names(native.stem)
        row = None
        for name in names:
            if name.lower() in exe:
                row = dict(path=rebase(exe[name.lower()], native.stem), evidence='exe-path')
                break
        if row is None and (line := re.search(r'^#line 1 "([^"]+\.(?:cpp|c))"', head, re.M)):
            row = dict(path=rebase(line.group(1), native.stem), evidence='line-directive')
        if row is None and (named := re.search(r'upstream (?:tools/libs/)?(\S+?\.(?:cpp|c))\b', head)):
            rel = named.group(1)
            base = next((k for k in sorted(LIBRARY_ROOTS, key=len, reverse=True) if rel.startswith(k + '/')), None)
            if base:
                row = dict(path=LIBRARY_ROOTS[base] + rel[len(base):], evidence='upstream',
                           guessed_root=LIBRARY_ROOTS[base] in GUESSED)
            else:
                row = dict(path='lib:' + rel, evidence='upstream', guessed_root=True)
        if row is None:
            for tree, label in ((rbxgs, 'rbxgs'), (openrbx, 'openrbx')):
                hits = sorted({p for name in names for p in tree.get(name.lower(), [])})
                if len(hits) == 1:
                    row = dict(path=hits[0], evidence=label)
                    break
                if hits:
                    ambiguous.append(dict(native=native.name, candidates=hits[:6]))
                    row = 'ambiguous'
                    break
        if row is not None and row['evidence'] == 'exe-path' and '/' not in row['path']:
            # a bare unit name in the exe (.\Workspace.cpp): its folder comes from the Roblox tree
            hits = sorted({p for name in names for p in rbxgs.get(name.lower(), []) + openrbx.get(name.lower(), [])})
            if len(set(hits)) >= 1:
                row['path'] = hits[0]
        if row is None:
            row = split_of(native.stem, ((rbxgs, 'rbxgs'), (openrbx, 'openrbx')))
        if row is None:
            unmapped.append(native.name)
        elif row != 'ambiguous':
            rows.append(dict(native=native.relative_to(ROOT).as_posix(), **row))
    targets = collections.defaultdict(list)
    for row in rows:
        targets[row['path'].lower()].append(row['native'])
    merges = {path: files for path, files in targets.items() if len(files) > 1}
    OUT.write_text(json.dumps({
        'scope': 'Proposed original 2008 path per native source; evidence-ranked; nothing is moved.',
        'original_root': 'd:/Roblox/Releases/2008.06.17/Client (exe path strings)',
        'library_roots': LIBRARY_ROOTS, 'guessed_library_roots': sorted(GUESSED),
        'rows': rows, 'merge_groups': merges, 'ambiguous': ambiguous, 'unmapped': unmapped}, indent=1) + '\n')
    counts = collections.Counter(r['evidence'] for r in rows)
    print(json.dumps({'native_files': len(rows) + len(unmapped) + len(ambiguous), 'mapped': len(rows),
                      'by_evidence': counts, 'ambiguous': len(ambiguous), 'unmapped': len(unmapped),
                      'merge_groups': len(merges), 'out': OUT.relative_to(ROOT).as_posix()}, indent=1))
    if args.show:
        for kind in counts:
            for row in [r for r in rows if r['evidence'] == kind][:args.show]:
                print('  %-14s %-45s -> %s' % (kind, Path(row['native']).name, row['path']))


if __name__ == '__main__':
    main()
