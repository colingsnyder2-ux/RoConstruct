"""Original source-tree evidence from every reference we hold, normalised to 'client/<area>/<folder>/<file>' (lower case).

Sources (tag letter):
  p  2007 server build PDB path list (webservice-pdb-source-paths.txt)
  i  iOS 2.132 (Dec 2013) linker debug map: the build agent's source paths for every compiled file
  a  Android 2.155 (Jun 2014) libroblox.so: __FILE__ strings of its asserts
  o  OpenRBX (Dec 2007 decompilation) tree: a decompiler's arrangement, weak; counts for nothing on its own
  e  Roblox.exe (2008) own file-name strings (file_strings.py)
  l  2016 source leak mirror (Artifaqt/ROBLOX2016): file names from the GitHub trees API (fetch_leak_paths.py), no contents

Run: python work/native-client/layout/source_tree_sources.py   -> prints counts, writes source-tree-sources.json
"""
import collections
import json
import re
import sqlite3
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
EXT = ('.cpp', '.cc', '.c', '.h', '.hpp', '.inl', '.mm', '.m')


def norm(path):
    """Everything after the last '/Client/' segment, lower case, under 'client/'."""
    path = path.replace('\\', '/')
    low = path.lower()
    at = low.rfind('/client/')
    if at >= 0:
        rest = path[at + 8:]
    elif low.startswith('client/'):
        rest = path[7:]
    else:
        return None
    parts = []
    for part in rest.split('/'):
        if part == '..':
            if parts:
                parts.pop()
        elif part and part != '.':
            parts.append(part)
    return 'client/' + '/'.join(parts).lower() if parts else None


def pdb():
    out = set()
    for line in (ROOT / 'work/native-client/webservice-pdb-source-paths.txt').read_text(encoding='utf-8').splitlines():
        n = norm(line.strip()) if line.strip().lower().startswith('client') else None
        if n:
            out.add(n)
    return out


def ios():
    path = ROOT / 'local/references/mobile-index/symbols.sqlite'
    if not path.exists():
        return set()
    db = sqlite3.connect(path.resolve().as_uri() + '?mode=ro', uri=True)
    out = set()
    for (source,) in db.execute("select distinct source from symbols where source != ''"):
        n = norm(source)
        if n and n.endswith(EXT):
            out.add(n)
    return out


def android():
    path = ROOT / 'local/references/android-2014-06_2.155.47886/libroblox.so'
    if not path.exists():
        return set()
    out = set()
    for m in re.finditer(rb'/Client/[ -~]{3,200}?\.(?:cpp|cc|c|h|hpp|inl)\b', path.read_bytes()):
        n = norm(m.group().decode('latin-1'))
        if n:
            out.add(n)
    return out


def openrbx():
    base = ROOT / 'tools/openrbx/Client'
    # roc_*.cpp files in that folder are our own mining outputs, not part of the decompilation
    return {'client/' + p.relative_to(base).as_posix().lower() for p in base.rglob('*')
            if p.is_file() and p.suffix.lower() in EXT and not p.name.lower().startswith('roc_')} if base.exists() else set()


def leak():
    path = HERE / 'leak2016-paths.json'
    out = set()
    if path.exists():
        for top, files in json.loads(path.read_text(encoding='utf-8')).items():
            for f in files:
                if f.lower().endswith(EXT):
                    out.add('client/' + top.lower() + '/' + f.lower())
    return out


def exe():
    path = HERE / 'file-strings.json'
    out = set()
    if path.exists():
        for row in json.loads(path.read_text(encoding='utf-8')):
            n = norm(row['file'])
            if n:
                out.add(n)
    return out


def build():
    tagged = {'p': pdb(), 'i': ios(), 'a': android(), 'o': openrbx(), 'e': exe(), 'l': leak()}
    union = collections.defaultdict(str)
    for tag, paths in tagged.items():
        for p in paths:
            union[p] += tag
    return tagged, union


if __name__ == '__main__':
    tagged, union = build()
    for tag, paths in tagged.items():
        print(tag, len(paths), 'source files' if tag != 'p' else 'paths', sum(1 for p in paths if p.endswith(('.cpp', '.cc', '.c', '.mm', '.m'))), 'compiled')
    print('union', len(union), 'compiled', sum(1 for p in union if p.endswith(('.cpp', '.cc', '.c', '.mm', '.m'))))
    multi = collections.Counter(len(v) for v in union.values())
    print('seen by n sources:', sorted(multi.items()))
    (HERE / 'source-tree-sources.json').write_text(json.dumps(dict(sorted(union.items())), indent=0), encoding='utf-8')
