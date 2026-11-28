"""python xcusweep.py: every ORIGINAL C++ static initializer (.CRT$XCU table 0x804f74..0x80aa08, from _initterm in
__tmainCRTStartup) classified against our link. Tonight's classes (factory creators, class descriptors, BoundProp
descriptors) were all initializers the original ran and ours did not. Per entry A:
  native   - a native ??__E initializer in our link builds the same global(s) (natinit literal pairing / creator set)
  xcu      - our extra .CRT$XCU objects (xcu_creators.obj / xcu_init.obj) already run func_<A>
  conv     - a converted body for A exists (renamed/obj/A.obj) but nothing runs it   <- candidates
  missing  - no body at all
Globals written (mov [abs], ... / mov ecx, abs) name what each initializer builds. Writes auto/xcusweep.json."""
import collections, json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
rr = json.loads((H / 'renamed/rename.json').read_text())
ents = [struct.unpack_from('<I', o, a - B)[0] for a in range(0x804f74, 0x80aa08, 4)]
ents = [e for e in ents if 0x401000 <= e < 0x900000]
running = set()
for f in ('linkexp/xcu_creators.obj', 'linkexp/xcu_init.obj'):
    p = H / f
    if p.exists():
        running |= {int(m.group(1), 16) for m in re.finditer(rb'func_([0-9a-f]{8})', p.read_bytes())}
natinit = json.loads((H / 'auto/natinit_plan.json').read_text()) if (H / 'auto/natinit_plan.json').exists() else {}
nat_globals = {int(k[4:], 16) for k in natinit}
syms = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        syms.setdefault(p[1], p[-1])
native_reg = {re.sub(r'^\?\?__E', '', n).rsplit('@@YAXXZ', 1)[0] for n, ob in syms.items() if n.startswith('??__E') and not re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', ob)}
rows, cnt = [], collections.Counter()
for e in ents:
    gl = set()
    for i in md.disasm(bytes(o[e - B:e - B + 0x80]), e):
        for h in re.findall(r'0x[0-9a-f]{6,}', i.op_str):
            v = int(h, 16)
            if 0x928000 <= v < 0x980000:
                gl.add(v)
        if i.mnemonic in ('ret', 'int3'):
            break
    gnames = sorted({(reg.get('%08x' % g) or {}).get('name') or '' for g in gl} - {''})
    x = rr.get('%08x' % e) or {}
    if e in running:
        k = 'xcu'
    elif gl & nat_globals or any(g in native_reg for g in gnames):
        k = 'native'
    elif x.get('status') == 'renamed' and (H / 'renamed/obj' / ('%08x.obj' % e)).exists():
        k = 'conv'
    else:
        k = 'missing'
    cnt[k] += 1
    rows.append({'init': '%08x' % e, 'kind': k, 'globals': ['%08x' % g for g in sorted(gl)][:6], 'names': gnames[:3],
                 'reg': ((reg.get('%08x' % e) or {}).get('name') or '')[:120]})
(H / 'auto/xcusweep.json').write_text(json.dumps(rows, indent=0))
print('xcusweep: original initializers %d: %s' % (len(rows), dict(cnt)))
fam = collections.Counter(re.sub(r'[0-9a-f]{8}', '', (r_['reg'] or 'func_')[:40]) for r_ in rows if r_['kind'] in ('conv', 'missing'))
print('  uncovered families:', fam.most_common(12))
