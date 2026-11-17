"""Route 8: C-linkage names for vendor C library functions.

The exe links Lua (and other vendor C code) with C linkage: the registry already names
hundreds of them '_name' (e.g. _lua_replace, _block).  Native drafts sometimes compile the
same sources as C++, so an exact reloc-masked body twin carries '?name@@YA...'.  When an
unnamed function's body twins include '?f@@YA...' and f is defined in a vendor .c file under
tools/libs whose other functions the registry already names '_g', the real name is '_f'.
Cross-check: on already-named functions every such miss of the body route was this case.
Output: work/native-client/identity-unlock-clink.json
"""
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-clink.json'
DEF = re.compile(r'^[A-Za-z_][\w \t\*]*?\b([A-Za-z_]\w*)\s*\([^;]*$')


def c_definitions():
    """function name -> set of vendor .c files defining it"""
    files = subprocess.run(['rg', '--files', '-uu', '-g', '*.c', str(ROOT / 'tools/libs')],
                           capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout.splitlines()
    out = defaultdict(set)
    for f in files:
        try:
            lines = open(f, errors='ignore').read().splitlines()
        except OSError:
            continue
        for i, line in enumerate(lines):
            m = DEF.match(line)
            if m and not line.startswith(('return', 'else', 'if', 'for', 'while', 'switch', 'case', 'typedef')):
                nxt = ' '.join(lines[i:i + 3])
                if '{' in nxt:
                    out[m.group(1)].add(Path(f).parent.name)
    return out


def main():
    inf = json.load(open(NC / 'unnamed-identities-inferred.json'))
    raw = json.load(open(NC / 'identity-unlock-bodyhash-candidates.json'))
    defs = c_definitions()
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    real = json.load(open(NC / 'unnamed-identities.json'))
    taken |= {r['name'] for r in real.values()}
    # vendor dirs whose functions the binary links as C (registry '_name' rows)
    c_dirs = defaultdict(int)
    for n in taken:
        if re.match(r'_[A-Za-z]\w*$', n):
            for d in defs.get(n[1:], ()):
                c_dirs[d] += 1
    out = {}
    for a, cands in raw.items():
        if a not in inf:
            continue
        hits = set()
        for s in cands:
            m = re.match(r'\?(\w+)@@YA', s)
            if m and '_' + m.group(1) not in taken and any(c_dirs[d] >= 5 for d in defs.get(m.group(1), ())):
                hits.add(m.group(1))
        if len(hits) == 1:
            f = hits.pop()
            out[a] = {'name': '_' + f, 'owner_class': None, 'signature': 'C function ' + f, 'kind': 'code',
                      'name_source': 'identity-unlock-clink',
                      'evidence': [{'kind': 'exact-masked-body-cpp-twin', 'cpp_symbols': [s for s in cands if s.startswith('?' + f + '@@YA')],
                                    'vendor_c_dirs': sorted(d for d in defs[f] if c_dirs[d] >= 5)}]}
    used = defaultdict(list)
    for a, r in out.items():
        used[r['name']].append(a)
    out = {a: r for a, r in out.items() if len(used[r['name']]) == 1}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('C-linkage names', len(out))


if __name__ == '__main__':
    main()
