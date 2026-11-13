"""Map unresolved shell-link symbols to 2008-06 addresses, so each can be rebuilt from its exact server source.
Sources of evidence: address comments in native-headers / native-classes ('// 0045ead0' on or above a declaration),
and the exact analog files in src/2008-06/ADDR.cpp. Writes work/native-client/link/addrmap.json:
  {symbol: {"class", "member", "addrs": [...], "exact": [addr with src/2008-06/ADDR.cpp]}}
usage: python work/native-client/addrmap.py"""
import json, re, sys
from pathlib import Path
sys.path.insert(0, '.')
from roc import rebuild

ROOT = rebuild.ROOT
OUT = ROOT / 'work/native-client/link'
SRC = ROOT / 'src/2008-06'


def parse(sym):
    """('Class','member') from a mangled name; ctor/dtor give ('Class','Class'); free names give ('', name)."""
    m = re.match(r'\?\?([01])(\w+)@', sym)
    if m:
        return m.group(2), m.group(2)
    m = re.match(r'\?(\w+)@(\w+)@', sym)
    if m:
        return m.group(2), m.group(1)
    m = re.match(r'\?(\w+)@@', sym)
    if m:
        return '', m.group(1)
    return None

ADDR = re.compile(r'\b(00[4-7][0-9a-f]{5})\b')
CLASS = re.compile(r'^\s*(?:class|struct)\s+(?:__declspec\([^)]*\)\s*)?(\w+)\b[^;]*$')
found = {}   # (class, member) -> set(addr)
NAMES = {}   # addr -> mangled (namer.py)
where = {}   # (class, member) -> header that declares it


def scan(path, default_class=None):
    cls = default_class
    pending = []
    for line in path.read_text(errors='replace').splitlines():
        m = CLASS.match(line)
        if m:
            cls = m.group(1)
        addrs = ADDR.findall(line)
        qual = re.search(r'(\w+)::(~?\w+)\s*\(', line)
        decl = re.search(r'(~?\w+)\s*\([^;{]*\)\s*(?:const)?\s*[;{]', line)
        if qual:
            key = (qual.group(1), qual.group(2))
        elif decl and cls:
            key = (cls, decl.group(1))
        else:
            # an address comment binds only to the immediately following declaration line
            pending = addrs if (addrs and line.strip().startswith('//')) else []
            continue
        a = addrs or pending
        pending = []
        for x in a:
            found.setdefault(key, set()).add(x)
        if a and path.suffix == '.h':
            where.setdefault(key, (path, line))


def scan_all():
    for p in list((ROOT / 'rebuild/2008-06/native-headers').rglob('*.h')) + list((ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp')):
        scan(p)
    return found, where


def main():
    scan_all()
    NAMES.update(json.load(open(OUT / 'names.json')) if (OUT / 'names.json').exists() else {})

    unres = json.load(open(OUT / 'probe.json'))['unresolved']
    res, hit, exact = {}, 0, 0
    for s in unres:
        p = parse(s)
        if not p:
            continue
        cls, mem = p
        if s.startswith('??0'):
            mem = cls
        elif s.startswith('??1'):
            mem = '~' + cls
        addrs = sorted(set(found.get((cls, mem), ())) | {a for a, n in NAMES.items() if n == s})
        ex = [a for a in addrs if (SRC / (a + '.cpp')).exists()]
        res[s] = {'class': cls, 'member': mem, 'addrs': addrs, 'exact': ex}
        hit += bool(addrs)
        exact += bool(ex)
    json.dump(res, open(OUT / 'addrmap.json', 'w'), indent=1)
    print('unresolved', len(unres), '| with 2008 address', hit, '| with exact server source', exact)


if __name__ == '__main__':
    main()
