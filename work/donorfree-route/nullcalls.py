"""python nullcalls.py [EXE MAP]: static scan of our linked exe for calls that can only crash: direct call/jmp targets
below the code section (address 0, the image header: unresolved symbols, bogus aliases), absolute call [mem] through
import slots that hold 0 / the image base, and pointers in .data/.rdata tables that equal the image base.
File->New-reachable callers first (auto/reach.json). Output auto/nullcalls.json; seconds, no run."""
import json, re, struct, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 2 else str(H / 'link/donorfree.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'link/donorfree.map')
pe = pefile.PE(exe)
img = bytes(pe.get_memory_mapped_image())
base = pe.OPTIONAL_HEADER.ImageBase
text = next(s for s in pe.sections if s.Name.startswith(b'.text'))
lo, hi = base + text.VirtualAddress, base + text.VirtualAddress + text.Misc_VirtualSize
syms = []
for l in open(mp, errors='replace'):
    m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s+(?:f\s+)?(?:i\s+)?(\S+)', l)
    if m:
        syms.append((int(m.group(2), 16), m.group(1), m.group(3)))
syms.sort()
import bisect
ks = [s[0] for s in syms]
def owner(a):
    i = bisect.bisect_right(ks, a) - 1
    return syms[i] if i >= 0 else (0, '?', '?')
try:
    reach = {r['name'][:100] for r in json.load(open(H / 'auto/reach.json'))}
except Exception:
    reach = set()
iat = {}
if hasattr(pe, 'DIRECTORY_ENTRY_IMPORT'):
    for d in pe.DIRECTORY_ENTRY_IMPORT:
        for i in d.imports:
            iat[i.address] = '%s!%s' % (d.dll.decode(), (i.name or b'#%d' % i.ordinal).decode() if i.name else '#%d' % i.ordinal)
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.skipdata = True
bad = []
code = img[lo - base:hi - base]
for ins in md.disasm(code, lo):
    if ins.mnemonic not in ('call', 'jmp'):
        continue
    op = ins.op_str
    if op.startswith('0x'):
        t = int(op, 16)
        if t < lo or t >= hi:
            if t < base + 0x1000:
                o = owner(ins.address)
                bad.append({'at': '%08x' % ins.address, 'in': o[1], 'obj': o[2], 'target': '%08x' % t, 'kind': 'direct-null',
                            'reach': o[1][:100] in reach})
    else:
        m = re.fullmatch(r'dword ptr \[0x([0-9a-f]+)\]', op)
        if m:
            slot = int(m.group(1), 16)
            if base <= slot < base + len(img) - 4:
                v = struct.unpack_from('<I', img, slot - base)[0]
                _sec = next((s for s in pe.sections if s.VirtualAddress <= slot - base < s.VirtualAddress + s.Misc_VirtualSize), None)
                _bss = _sec is None or (slot - base - _sec.VirtualAddress) >= _sec.SizeOfRawData   # runtime-filled (GL entry points)
                if slot not in iat and not _bss and (v == 0 or v == base) and owner(ins.address)[2] != 'stubs.obj':
                    o = owner(ins.address)
                    bad.append({'at': '%08x' % ins.address, 'in': o[1], 'obj': o[2], 'target': 'slot %08x=%08x' % (slot, v),
                                'kind': 'slot-null', 'reach': o[1][:100] in reach})
(H / 'auto/nullcalls.json').write_text(json.dumps(bad, indent=0))
from collections import Counter
print('null calls: %d (File->New-reachable %d) | %s' % (len(bad), sum(b['reach'] for b in bad), dict(Counter(b['kind'] for b in bad))))
for b in sorted(bad, key=lambda b: not b['reach'])[:15]:
    print('  %s %-11s %-60s %s %s' % (b['at'], b['kind'], b['in'][:60], b['target'], b['obj'][:20]))
