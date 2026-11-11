"""Original source-file and assert-text evidence from strings each function references.

Every absolute relocation in a function body that points at a C string is
read from the original image.  Strings that look like source paths
(`...\PartInstance.cpp`, `Foo.h`) name the file an assert/log macro expanded
in; a `.cpp` path names the function's translation unit, a `.h` path names an
inlined header.  Other short strings are kept as assert/log text.  Evidence
for grouping and naming only.
"""
import argparse
import json
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402

PATH = re.compile(r'^[\w .:\/+-]+\.(cpp|c|h|hpp|inl)$', re.I)
TEXT = re.compile(r'^[\x20-\x7e]{4,200}$')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    targets = Targets('2008-06')
    end = targets.base + len(targets.image)
    cache, functions, files = {}, {}, defaultdict(list)

    def string(va):
        if va not in cache:
            value = None
            if targets.base <= va < end - 1:
                raw = bytes(targets.image[va - targets.base:va - targets.base + 260])
                cut = raw.find(b'\0')
                text = raw[:cut].decode('latin-1') if cut > 3 else ''
                value = text if TEXT.match(text) else None
            cache[va] = value
        return cache[va]

    for addr, info in sorted(match._functions('2008-06').items()):
        if info.get('kind', 'code') != 'code':
            continue
        try:
            code, relocs, _ = match.target('2008-06', addr)
        except (KeyError, ValueError, SystemExit):
            continue
        paths, texts = [], []
        for at in relocs:
            if at + 4 > len(code):
                continue
            text = string(struct.unpack_from('<I', code, at)[0])
            if text:
                (paths if PATH.match(text) else texts).append(text)
        if paths or texts:
            functions[addr] = {'files': sorted(set(paths)), 'strings': sorted(set(texts))[:12]}
            for path in set(paths):
                files[path].append(addr)
    units = Counter()
    for row in functions.values():
        sources = [f for f in row['files'] if f.lower().endswith(('.cpp', '.c'))]
        if len(sources) == 1:
            row['translation_unit'] = sources[0]
            units[sources[0]] += 1
    out = {'scope': 'string-reference evidence for file grouping; not owner proof',
           'summary': {'functions_with_strings': len(functions),
                       'functions_with_file_path': sum(bool(r['files']) for r in functions.values()),
                       'functions_with_unique_cpp': sum(units.values()), 'distinct_paths': len(files)},
           'files': {k: v for k, v in sorted(files.items(), key=lambda kv: -len(kv[1]))}, 'functions': functions}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))
    print(units.most_common(15))
    print([(k, len(v)) for k, v in list(out['files'].items())[:10]])


if __name__ == '__main__':
    main()
