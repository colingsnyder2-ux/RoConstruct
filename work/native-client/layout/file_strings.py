"""Source file names that the 2008 exe carries in its own strings, with the functions that reference them.

Asserts, OGRE_EXCEPT, logging and exception macros push __FILE__, so a string such as ".\\RbxSceneManager.cpp"
names the original translation unit of every function that uses it. Evidence for a file name and for which
functions (and so which native pieces) belong together; it is not a PDB path and not proof of the directory.

Output: work/native-client/layout/file-strings.json
Run:    python work/native-client/layout/file_strings.py
"""
import collections
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
EXE = ROOT / 'clients/2008-06/Roblox.exe'
OUT = Path(__file__).resolve().parent / 'file-strings.json'
NAME = re.compile(rb'[ -~]{4,200}?\.(?:cpp|c|cc|h|hpp|inl)(?![A-Za-z0-9_])', re.I)


def sections(data):
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    count = struct.unpack_from('<H', data, pe + 6)[0]
    optional = struct.unpack_from('<H', data, pe + 20)[0]
    base = struct.unpack_from('<I', data, pe + 24 + 28)[0]
    out = []
    table = pe + 24 + optional
    for i in range(count):
        name, vsize, va, rsize, raw = struct.unpack_from('<8sIIII', data, table + 40 * i)
        out.append((name.rstrip(b'\0').decode(), base + va, vsize, raw, rsize))
    return base, out


def clean(raw):
    text = raw.decode('latin-1').replace('\\', '/')
    return re.sub(r'^(?:\./|(?:\.\./)+)', '', text)


def build():
    data = EXE.read_bytes()
    _base, secs = sections(data)
    funcs = []
    with open(ROOT / 'work/2008-06/functions.jsonl', encoding='utf-8') as lines:
        for line in lines:
            row = json.loads(line)
            if row.get('kind') == 'code':
                funcs.append((int(row['addr'], 16), row['size']))
    funcs.sort()
    starts = [a for a, _ in funcs]

    def owner(addr):
        import bisect
        i = bisect.bisect_right(starts, addr) - 1
        return funcs[i][0] if i >= 0 and addr < funcs[i][0] + funcs[i][1] else None

    code = next(s for s in secs if s[0] == '.text')
    text = data[code[3]:code[3] + code[4]]
    found = collections.defaultdict(set)         # string -> {string VA}
    for name, va, vsize, raw, rsize in secs:
        if name == '.text':
            continue
        blob = data[raw:raw + min(rsize, vsize)]
        for m in NAME.finditer(blob):
            # the whole C string: back up to its start
            start = m.start()
            while start > 0 and 32 <= blob[start - 1] < 127:
                start -= 1
            found[clean(blob[start:m.end()])].add(va + start)
    refs = {}
    for name, vas in found.items():
        users = collections.Counter()
        for va in vas:
            needle = struct.pack('<I', va)
            at = text.find(needle)
            while at != -1:
                f = owner(code[1] + at)
                if f is not None:
                    users[f] += 1
                at = text.find(needle, at + 1)
        refs[name] = users
    rows = [{'file': name, 'functions': sorted('%08x' % f for f in users), 'refs': sum(users.values())}
            for name, users in refs.items() if users]
    rows.sort(key=lambda r: -len(r['functions']))
    return rows


if __name__ == '__main__':
    rows = build()
    OUT.write_text(json.dumps(rows, indent=0), encoding='utf-8')
    print(len(rows), 'file names referenced by code;', sum(len(r['functions']) for r in rows), 'function references')
    for r in rows[:15]:
        print('%4d  %s' % (len(r['functions']), r['file']))
