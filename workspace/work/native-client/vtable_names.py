"""Name unnamed 2008-06 virtual overrides from RTTI vtables: slot k of Derived's primary vtable overrides the method
a base class names at the same slot, so `?leaf@Base@NS@@rest` -> `?leaf@Derived@NS@@rest` (same namespace depth only,
non-template classes only).  Writes work/native-client/vtable-names.json as extra identity-registry rows; every
native gate still compiles and byte/reference-proves the body, so a wrong guess can only fail, never pass."""
import json
import struct
import subprocess
from pathlib import Path

import pefile

ROOT = Path(__file__).resolve().parents[2]
REGISTRY = ROOT / 'work/2008-06/identity-registry.json'
UNDNAME = ROOT / 'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/bin/undname.exe'
OUT = ROOT / 'work/native-client/vtable-names.json'

pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
B = pe.OPTIONAL_HEADER.ImageBase
rd = next(s for s in pe.sections if s.Name.rstrip(b'\0') == b'.rdata')
data, base = rd.get_data(), B + rd.VirtualAddress
words = struct.unpack('<%dI' % (len(data) // 4), data[:len(data) // 4 * 4])
registry = json.loads(REGISTRY.read_text())


def dword(va):
    return struct.unpack('<I', pe.get_data(va - B, 4))[0]


def type_name(td):
    return pe.get_data(td + 8 - B, 200).split(b'\0')[0].decode('latin1')


def in_rdata(va):
    return base <= va < base + len(data)


def is_code(va):
    return 0x401000 <= va < 0x802000


# Primary vtables: [COL][fn0][fn1]... with COL.offset == 0.  class mangled name -> (slots, bases nearest-first)
vtables = {}
for i in range(1, len(words)):
    col = words[i - 1]
    if not (in_rdata(col) and is_code(words[i])) or (i > 1 and is_code(words[i - 2])):
        continue
    try:
        if dword(col) != 0 or dword(col + 4) != 0:
            continue
        name = type_name(dword(col + 12))
        chd = dword(col + 16)
        count, array = dword(chd + 8), dword(chd + 12)
        bases = [type_name(dword(dword(array + 4 * k))) for k in range(1, count)]
    except Exception:
        continue
    if not name.startswith('.?AV'):
        continue
    slots = []
    for w in words[i:]:
        if not is_code(w):
            break
        slots.append('%08x' % w)
    vtables.setdefault(name, (slots, bases))


def named(addr):
    row = registry.get(addr) or {}
    name = row.get('name') or ''
    return name if name and not row.get('placeholder') and not name.startswith('func_') else ''


out = {}
for cls, (slots, bases) in vtables.items():
    q = cls[4:]                                         # Derived@NS@@
    if '?$' in q:
        continue                                        # template classes: the template lane
    for k, addr in enumerate(slots):
        if named(addr) or addr in out:
            continue
        for b in bases:
            bq = b[4:]
            if b not in vtables or '?$' in bq or bq.count('@') != q.count('@') or k >= len(vtables[b][0]):
                continue
            base_name = named(vtables[b][0][k])
            leaf = base_name[1:].split('@', 1)[0] if base_name.startswith('?') and not base_name.startswith('??') else ''
            if leaf and base_name.startswith('?%s@%s' % (leaf, bq)):
                out[addr] = '?%s@%s%s' % (leaf, q, base_name[len('?%s@%s' % (leaf, bq)):])
                break
if out:
    undec = subprocess.run([str(UNDNAME), *out.values()], capture_output=True, text=True).stdout
    sigs = dict(zip(out.values(), [line.split('is :- "', 1)[1].rstrip('"') for line in undec.splitlines()
                                  if 'is :- "' in line]))
rows = {}
for addr, name in out.items():
    sig = sigs.get(name, '')
    qual = sig.split('(')[0].split()[-1] if sig else ''
    rows[addr] = dict(kind='code', name=name, name_source='vtable-slot', placeholder=False,
                      owner_class=qual.rsplit('::', 1)[0] if '::' in qual else '', signature=sig,
                      evidence=[{'kind': 'vtable-slot-override'}])
OUT.write_text(json.dumps(rows, indent=1))
print('vtables', len(vtables), 'named overrides', len(rows), '->', OUT.relative_to(ROOT))
