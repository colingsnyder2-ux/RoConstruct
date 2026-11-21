"""docs/library-files.json: upstream source files of the libraries in the 2008 exe, for the site's Libraries map.

A file is 'm' (matched) when at least one exe function is byte-identical to code built from that upstream file
(the mining recipes record recipe + file per function in docs/data/2008-06.json). 'n' is a file of the upstream
tree with no match. 'o' is a matched file that the listed base tree does not have (it came from another version).
This is byte evidence for library code. It says nothing about Roblox's own source paths.

Run:  python work/native-client/layout/site_libs.py
"""
import collections
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
LIBS = ROOT / 'tools/libs'
SRC = ('.cpp', '.c', '.cc')

# library -> (recipe prefixes, upstream tree, glob under it)
TABLE = {
    'Ogre': (('ogre',), 'ogre-1.4.5/ogrenew/OgreMain/src', '*.cpp'),
    'XTP (Codejock)': (('xtp',), 'xtp-11.2.2/Source', '**/*.cpp'),
    'G3D': (('g3d',), 'g3d-6.09', '**/*.cpp'),
    'Lua': (('lua',), 'lua-5.1.4', '*.c'),
    'boost': (('boost',), 'boost_1_34_1/libs', '**/src/**/*.cpp'),
    'MFC / ATL': (('mfc', 'atl'), 'mfc-9.0/atlmfc/src', '**/*.cpp'),
    'libjpeg': (('jpeg',), 'jpeg-6b', '*.c'),
    'libpng': (('libpng',), 'libpng-1.2.5', '*.c'),
    'zlib': (('zlib',), 'zlib-1.2.3', '*.c'),
}


def norm(name):
    return name.replace('\\', '/')


def build():
    data = json.loads((ROOT / 'docs/data/2008-06.json').read_text(encoding='utf-8'))
    matched = collections.defaultdict(lambda: collections.defaultdict(lambda: [0, 0, '']))   # lib -> base -> [bytes, funcs, shown]
    for f in data['funcs']:
        src = f[5]
        if not src or f[2] != 100:
            continue
        recipe, file = src[0].lower(), norm(src[1])
        for lib, (prefixes, _tree, _glob) in TABLE.items():
            if recipe.startswith(prefixes):
                rec = matched[lib][file.rsplit('/', 1)[-1].lower()]
                rec[0] += f[1]
                rec[1] += 1
                rec[2] = rec[2] or file
                break
    libs = []
    for lib, (_prefixes, tree, glob) in TABLE.items():
        root = LIBS / tree
        rows, seen = [], set()
        for path in sorted(root.glob(glob)) if root.exists() else []:
            if path.name.lower().startswith('roc_') or path.suffix.lower() not in SRC:
                continue
            base = path.name.lower()
            if base in seen:
                continue
            seen.add(base)
            rel = path.relative_to(LIBS / tree.split('/')[0]).as_posix()
            hit = matched[lib].get(base)
            rows.append([rel, 'm' if hit else 'n', hit[0] if hit else 0, hit[1] if hit else 0])
        mined = [0, 0]
        for base, hit in sorted(matched[lib].items()):
            if base.startswith('roc_'):
                mined[0] += hit[0]
                mined[1] += hit[1]
            elif base not in seen:
                rows.append([hit[2], 'o', hit[0], hit[1]])
        if mined[1]:
            rows.append(['(mined fork units, no upstream file name)', 'k', mined[0], mined[1]])
        libs.append({'name': lib, 'tree': tree, 'files': rows,
                     'matched': sum(1 for r in rows if r[1] != 'n'), 'bytes': sum(r[2] for r in rows)})
    return {'note': 'upstream source files of exe libraries; matched = an exe function is byte-identical to code built from the file',
            'libs': libs}


if __name__ == '__main__':
    result = build()
    (ROOT / 'docs/library-files.json').write_text(json.dumps(result, separators=(',', ':')), encoding='utf-8')
    for lib in result['libs']:
        print('%-16s %5d files, %4d matched, %8d bytes' % (lib['name'], len(lib['files']), lib['matched'], lib['bytes']))
