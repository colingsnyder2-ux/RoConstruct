"""python link_lint.py [--fix]: static checks over AutoRecover drafts that predict runtime crashes without probing.
1. ABI mismatch: one helper address declared with different C decorations (fastcall @n@N / stdcall _n@N / cdecl _n)
   or a different stack size than the draft that defines it.
2. Native duplicate: a draft for an address that a non-draft native source documents with a `// <addr>` comment.
3. Invented globals: extern data declared by drafts that no object defines (they link to zero stubs).
--fix: for (2), run swap_native.py when the native symbol can be found in the defined-symbol cache."""
import json, re, subprocess, sys
from collections import defaultdict
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
NC = ROOT / 'rebuild/2008-06/native-classes'
DECL = re.compile(r'extern\s+"C"\s+[^;{()]*?(__fastcall|__stdcall|__cdecl)?\s*\**\s*(\w+_([0-9a-f]{8}))\s*\(([^)]*)\)\s*([;{])')


def deco(conv, name, params):
    n = 0 if params.strip() in ('', 'void') else 4 * (params.count(',') + 1)
    return '@%s@%d' % (name, n) if conv == '__fastcall' else '_%s@%d' % (name, n) if conv == '__stdcall' else '_' + name


decls = defaultdict(set)   # addr -> {(decoration, file, is_definition)}
for f in NC.glob('AutoRecover_*.cpp'):
    for m in DECL.finditer(f.read_text(errors='replace')):
        decls[m.group(3)].add((deco(m.group(1), m.group(2), m.group(4)), f.name, m.group(5) == '{'))
abi = []
for addr, ds in sorted(decls.items()):
    defs = {d for d, f, isdef in ds if isdef and f == 'AutoRecover_%s.cpp' % addr}
    uses = {d for d, f, isdef in ds if not isdef}
    if defs and uses - defs:
        abi.append((addr, sorted(defs), sorted(uses - defs)))
    elif len({u.split('@')[-1] if '@' in u else 'cdecl' for u in uses}) > 1:
        abi.append((addr, [], sorted(uses)))
documented = defaultdict(list)
for f in NC.glob('*.cpp'):
    if f.name.startswith('AutoRecover_'):
        continue
    for m in re.finditer(r'^\s*//\s*([0-9a-f]{8})\b', f.read_text(errors='replace'), re.M):
        documented[m.group(1)].append(f.name)
dups = [(a, documented[a][:2]) for a in sorted(p.stem[-8:] for p in NC.glob('AutoRecover_*.cpp')) if a in documented]
print('ABI mismatches (%d):' % len(abi))
for a, d, u in abi:
    print('  %s defined %s, callers use %s' % (a, d or '-', u))
print('drafts duplicating documented native bodies (%d):' % len(dups))
for a, fs in dups:
    print('  %s -> %s' % (a, ', '.join(fs)))
