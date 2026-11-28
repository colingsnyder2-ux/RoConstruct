"""python msgmapaudit.py: every MFC message-map entry in our exe whose handler is a STUB. A stubbed WM_PAINT handler
returned without BeginPaint: the window stayed invalid, ~4k WM_PAINT/s, 100% CPU, no idle -> WM_TIMER never fired
(Explorer stayed empty) and modal dialogs never showed. Finds AFX_MSGMAP {pfnGetBaseMap, lpEntries} pairs via the
map's ?messageMap@?1??GetThisMessageMap@ statics / dat_ copies, walks their AFX_MSGMAP_ENTRY arrays (24 bytes: nMessage,
nCode, nID, nLastID, nSig, pfn) to the zero terminator, and reports entries whose pfn is a stub symbol. For each,
the ORIGINAL map (same message/id at the dat_ / registry address) gives the original handler address.
Writes auto/msgmapaudit.json [[map symbol, msg, id, stub name, original handler]]."""
import bisect, json, re, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
syms, obj, byname = {}, {}, {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        if v:
            syms.setdefault(v, p[1]); obj.setdefault(v, p[-1]); byname.setdefault(p[1], v)
stubaddr = {v for v, ob in obj.items() if 'stubs' in ob and bytes(q[v - B:v - B + 5]) == b'\xb8\0\0\0\0'}   # glue bodies are real
maps = []
for n, v in byname.items():
    if '?messageMap@' in n or (re.fullmatch(r'dat_[0-9a-f]{8}', n) and 'stubs' in obj.get(v, '')):
        try:
            gb, ent = struct.unpack_from('<II', q, v - B)
        except struct.error:
            continue
        if 0x401000 <= gb < 0x900000 and B < ent < 0x3000000:
            maps.append((n, v, ent))
bad = []
for n, v, ent in maps:
    orig_ent = None
    m = re.fullmatch(r'dat_([0-9a-f]{8})', n)
    if m:
        orig_ent = struct.unpack_from('<I', o, int(m.group(1), 16) - B + 4)[0]
    for i in range(300):
        try:
            msg, code, id_, last, sig, pfn = struct.unpack_from('<6I', q, ent - B + 24 * i)
        except struct.error:
            break
        if msg == 0 and pfn == 0:
            break
        if msg > 0xffff or sig > 0x100:
            break
        if pfn in stubaddr:
            op = None
            if orig_ent and 0x7c0000 <= orig_ent < 0x9a0000:
                op = '%08x' % struct.unpack_from('<6I', o, orig_ent - B + 24 * i)[5]
            bad.append([n, '0x%x' % msg, '0x%x' % id_, syms.get(pfn, '%08x' % pfn), op])
(H / 'auto/msgmapaudit.json').write_text(json.dumps(bad, indent=0))
print('message maps %d, entries whose handler is a stub: %d' % (len(maps), len(bad)))
for b in bad:
    if b[1] in ('0xf', '0x14', '0x113', '0x85'):
        print('  ', b)
print('  e.g.', bad[:6])
