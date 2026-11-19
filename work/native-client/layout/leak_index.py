"""Method definitions of the 2016 source leak (local sparse checkout), as (Class, method) -> files.

The leak is real source: `void Instance::setParent(...)` in App/v8tree/Instance.cpp. A 2008 function with the same
(Class, method) name is evidence for the same file, five years of reorganisation away from the 2008 tree. Used as tier M
of the function map, below the iOS 2013 debug map (closer in time). Also records string literals per method so
name_match.py can use them. The checkout lives in local/references/roblox2016-src (git-ignored, never published).

Run: python work/native-client/layout/leak_index.py   -> leak-index.json
"""
import collections
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
SRC = ROOT / 'local/references/roblox2016-src'
OUT = HERE / 'leak-index.json'
DIRS = ('App', 'Base', 'Network', 'Rendering', 'ClientBase', 'ClientShared', 'Win')
DEF = re.compile(r'^[ \t]*(?:[\w:<>,\*&~\s]+?[\s\*&])?((?:[A-Za-z_]\w*(?:<[^<>()]*>)?::)+~?[A-Za-z_]\w*)\s*\(', re.M)
STRING = re.compile(r'"((?:[^"\\\n]|\\.){4,60})"')
SKIP = ('if', 'for', 'while', 'switch', 'return', 'else', 'catch', 'sizeof')


def methods(text):
    """[(Class, method, strings)] for each function definition in a source file."""
    out = []
    for m in DEF.finditer(text):
        qualified = re.sub(r'<[^<>()]*>', '', m.group(1))
        parts = qualified.split('::')
        if len(parts) < 2 or parts[-1] in SKIP:
            continue
        # a definition: the parameter list is followed by { (maybe after const / an initializer list), not by ;
        depth, i = 1, m.end()
        while i < len(text) and depth:
            depth += {'(': 1, ')': -1}.get(text[i], 0)
            i += 1
        tail = text[i:i + 200]
        if re.match(r'\s*(?:const\s*)?(?:throw\s*\(\s*\)\s*)?(?:\{|:(?!:))', tail):
            body = text[i:i + 4000]
            out.append((parts[-2], parts[-1], sorted(set(STRING.findall(body)))[:8]))
    return out


def client_path(rel):
    return 'client/' + rel.replace('\\', '/').lower()


def main():
    if not SRC.exists():
        sys.exit('no checkout at %s' % SRC)
    files = collections.defaultdict(set)
    strings = collections.defaultdict(list)
    count = 0
    for d in DIRS:
        for path in (SRC / d).rglob('*.cpp') if (SRC / d).exists() else []:
            rel = path.relative_to(SRC).as_posix()
            if '/UnitTest' in rel or rel.startswith(('App.UnitTest', 'Base.UnitTest')):
                continue
            text = path.read_text(encoding='utf-8', errors='replace')
            for cls, name, strs in methods(text):
                key = '%s::%s' % (cls, name)
                files[key].add(client_path(rel))
                count += 1
                if strs:
                    strings[key].append(strs)
    result = {'files': {k: sorted(v) for k, v in files.items()}, 'strings': {k: v[0] for k, v in strings.items() if len(v) == 1}}
    OUT.write_text(json.dumps(result, separators=(',', ':')), encoding='utf-8')
    unique = sum(1 for v in files.values() if len(v) == 1)
    print('%d definitions, %d (Class, method) names, %d with one file' % (count, len(files), unique))


if __name__ == '__main__':
    main()
