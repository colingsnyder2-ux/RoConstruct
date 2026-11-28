"""python dtorslots.py: vt_orig deleting-destructor slots that point at a STUB while the native class defines its own
??_G / ??_E. CXTPHookManager::CHookSink's slot was func_0071c700 (`return 0`): `delete pSink` never ran ~CHookSink, the
window procedure was never restored, HookWndProc found no sink and swallowed WM_PAINT for the Untitled frame (100% CPU,
WM_TIMER starved -> empty Explorer, hidden modal dialogs). A slot qualifies when the ORIGINAL slot target has the
scalar-deleting-destructor shape, our slot is a stub, and a linked native object defines ??_G<Class> or ??_E<Class>.
Appends [vtable, slot, stub, 0, 0, target] rows to auto/vtfix_list.json (vtfix.py repoints them)."""
import json, os, pickle, re, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[1]))
from roc.rebuild import coff_externals
_, vo = pickle.load(open(H / 'auto/orig_vt.pkl', 'rb'))
byva = {va: sl for (c, off), (va, sl) in vo.items()}
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
gpat = re.compile(rb'^\x56\x8b\xf1\xe8....\xf6\x44\x24\x08\x01\x74.\x56\xe8....\x83\xc4\x04\x8b\xc6\x5e\xc2\x04\x00', re.S)
epat = re.compile(rb'^\x56\x8b\xf1\xf6\x44\x24\x08\x02', re.S)   # vector deleting destructor prologue
stubs, vt, names = set(), {}, {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        names.setdefault(v, p[1])
        if 'stubs' in p[-1]:
            stubs.add(v)
        if p[1].startswith('??_7') and p[-1] == 'vt_orig.obj':
            vt[p[1]] = v
defs = set()
for l in open(H / 'linkexp/qt.rsp', errors='replace'):
    pth = l.strip().strip('"')
    if not pth.lower().endswith('.obj') or re.search(r'[\\/](?:ca_)?[0-9a-f]{8}\.obj$', pth) or not os.path.exists(pth):
        continue
    d = open(pth, 'rb').read()
    if b'??_G' in d or b'??_E' in d:
        defs |= {k for k, v in coff_externals(d).items() if v and k.startswith(('??_G', '??_E'))}
tables = json.loads((H / 'auto/natret_tables.json').read_text())
rows = []
for n, a in vt.items():
    m = re.match(r'^\?\?_7(.+?)@@6B', n)
    if not m or n not in tables:
        continue
    sl = byva.get(int(tables[n], 16))
    if not sl:
        continue
    for i, ot in enumerate(sl):
        t = struct.unpack_from('<I', q, a - B + 4 * i)[0]
        if t not in stubs or not 0x401000 <= ot < 0x7c0000:
            continue
        b = bytes(o[ot - B:ot - B + 40])
        for pre, ok in (('??_G', gpat.match(b)), ('??_E', epat.match(b))):
            tgt = '%s%s@@UAEPAXI@Z' % (pre, m.group(1))
            if ok and tgt in defs:
                rows.append([n, i, names.get(t, ''), 0, 0, tgt]); break
        else:
            for pre in ('??_G', '??_E'):   # the shape is the other kind: either deleting destructor works for delete
                tgt = '%s%s@@UAEPAXI@Z' % (pre, m.group(1))
                if (gpat.match(b) or epat.match(b)) and tgt in defs:
                    rows.append([n, i, names.get(t, ''), 0, 0, tgt]); break
vl = H / 'auto/vtfix_list.json'
cur = json.loads(vl.read_text()) if vl.exists() else []
seen = {(r[0], r[1]) for r in cur}
cur += [r for r in rows if (r[0], r[1]) not in seen]
vl.write_text(json.dumps(cur, indent=0))
print('dtorslots: deleting-destructor slots repointed to the native ??_G/??_E: %d (e.g. %s)' % (len(rows), [r[0][:50] for r in rows[:3]]))
print('  CHookSink:', [r for r in rows if 'CHookSink' in r[0]])
