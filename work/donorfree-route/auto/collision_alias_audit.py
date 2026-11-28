"""Find raw converted data references to many-to-one alias targets.

Candidates require linked-image verification: later link passes may already fix them.
"""
import collections
import json
import re
import struct
from pathlib import Path
import pefile
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import datafix
root = Path(__file__).resolve().parents[1]
groups = collections.defaultdict(set)
for line in (root / 'aliases_renamed.txt').read_text().splitlines():
    match = re.fullmatch(r'(dat_[0-9a-f]{8})=(\S+)', line)
    if match and not match[2].startswith('__imp_'):
        groups[match[2]].add(match[1])
groups = {name: values for name, values in groups.items() if len(values) > 1}
records = json.loads((root / 'renamed/rename.json').read_text())
image = pefile.PE(str(root / 'run/RobloxOrig.exe'), fast_load=True).get_memory_mapped_image()
result = {}
for addr, record in records.items():
    candidates = set((record.get('renamed') or {}).values()) & groups.keys()
    obj = root / 'renamed/obj' / (addr + '.obj')
    if not candidates or not obj.exists():
        continue
    data = obj.read_bytes()
    symbols, opt = datafix._symtab(data)
    fn = next((v for v in symbols.values() if v[0] == record.get('symbol') and 0 < v[1] < 0xfffe), None)
    if not fn:
        continue
    _, _, _, _, raw, rel, _, count, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + opt + 40 * (fn[1] - 1))
    found = collections.defaultdict(set)
    for i in range(count):
        off, idx, kind = struct.unpack_from('<IIH', data, rel + 10 * i)
        symbol = symbols.get(idx)
        if kind != 6 or not symbol or symbol[0] not in candidates or symbol[1] != 0:
            continue
        origin = int(addr, 16) + off - fn[2]
        if not 0x401000 <= origin < 0x7c0000:
            continue
        word = struct.unpack_from('<I', image, origin - 0x400000)[0]
        addend = struct.unpack_from('<i', data, raw + off)[0]
        target = 'dat_%08x' % (word - addend)
        if 0x800000 <= word - addend < 0x9a0000:
            found[symbol[0]].add(target)
    if found:
        result[addr + '.obj'] = {k: sorted(v) for k, v in found.items() if v & groups[k]}
        if not result[addr + '.obj']:
            del result[addr + '.obj']
output = root / 'auto/collision_alias_audit.json'
output.write_text(json.dumps(result, indent=1))
print('objects:', len(result), 'unambiguous:', sum(len(v) == 1 for x in result.values() for v in x.values()), 'ambiguous:', sum(len(v) != 1 for x in result.values() for v in x.values()))
print('explosion:', result.get('00675360.obj'))
