"""python createinst.py: Creatable<Instance>::create<C>() instances our link only has as stubs (Insert Object's
Creator<BodyPosition>::create called func_005c2150 -> `return 0` -> NULL deref). A stub whose ORIGINAL body is the
create<C> shape (EH frame, operator new(N), call C::C()) names C by the constructor's registry name; the instance is
compiled from the NATIVE header (explicit instantiation; no original bytes) with the natives' flags, and sizeof(C) must
equal N. Writes linkexp/createinst.obj + aliases_createinst.txt (func_X=mangled create<C>), grow-only list in
auto/createinst.json. quicktest links the object and reads the aliases."""
import json, re, struct, subprocess, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT)); sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import rebuild
o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
HDR = {}   # class -> native header (first header declaring `class C`)
for h in (ROOT / 'rebuild/2008-06/native-headers').rglob('*.h'):
    if any(seg in h.parts for seg in ('creatable-n-params', 'nullable-class-name')):
        continue
    t = h.read_text(errors='replace')
    for m in re.finditer(r'^\s*class\s+(\w+)\s*(?::|\{|$)', t, re.M):
        HDR.setdefault(m.group(1), h.relative_to(ROOT / 'rebuild/2008-06/native-headers').as_posix())
found = {}
pf = H / 'auto/createinst.json'
try:
    found.update(json.loads(pf.read_text()))
except (OSError, ValueError):
    pass
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if not (len(p) >= 4 and p[0].startswith('0001:') and 'stubs' in p[-1] and re.fullmatch(r'func_[0-9a-f]{8}', p[1])):
        continue
    x = int(p[1][5:], 16)
    ins = list(md.disasm(bytes(o[x - 0x400000:x - 0x400000 + 0x80]), x))[:30]
    if not any('fs:[0]' in i.op_str for i in ins[:6]):
        continue
    size = next((int(i.op_str, 16) for i in ins[:14] if i.mnemonic == 'push' and i.op_str.startswith('0x') and int(i.op_str, 16) < 0x4000), None)
    calls = [int(i.op_str, 16) for i in ins if i.mnemonic == 'call' and i.op_str.startswith('0x')]
    if not size or not calls:
        continue
    mm = re.match(r'^\?\?0(\w+)@RBX@@QAE@XZ$', (reg.get('%08x' % calls[0]) or {}).get('name', ''))
    if not mm:   # folded/inlined ctor (Pants: the registry calls it FactoryProduct<Hole>): the class whose primary vtable it stores
        for i2 in md.disasm(bytes(o[calls[0] - 0x400000:calls[0] - 0x400000 + 0x60]), calls[0]):
            if i2.mnemonic == 'mov' and i2.op_str.startswith(('dword ptr [esi], 0x', 'dword ptr [eax], 0x', 'dword ptr [ecx], 0x')):
                mm = re.match(r'^\?\?_7(\w+)@RBX@@6B@$', (reg.get('%08x' % int(i2.op_str.split(', ')[1], 16)) or {}).get('name', ''))
                break
            if i2.mnemonic == 'ret':
                break
    if mm and mm.group(1) in HDR:
        found[p[1]] = [mm.group(1), size]
pf.write_text(json.dumps(found, indent=0))
if not found:
    raise SystemExit(0)
src = H / 'linkexp/createinst.cpp'
cls = sorted({c for c, _ in found.values()})
lines = ['// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS', '#include "util/Object.h"']
lines += ['#include "%s"' % HDR[c] for c in cls]
for c in cls:
    sz = next(s for k, (c2, s) in found.items() if c2 == c)
    lines.append('typedef char roc_size_%s[sizeof(RBX::%s) == %d ? 1 : -1];   // the original passes operator new(%d)' % (c, c, sz, sz))
    lines.append('template boost::shared_ptr<RBX::%s> RBX::Creatable<RBX::Instance>::create<RBX::%s>();' % (c, c))
src.write_text('\n'.join(lines) + '\n')
import native_check_runner as _ncr
tc = rebuild.toolchain(21022)
obj = H / 'linkexp/createinst.obj'
code_, text = rebuild.run(tc, 'cl', _ncr.compiler_flags(src) + ['/Fo' + str(obj), str(src)], H / 'linkexp')
if code_:
    print('compile failed:', '\n'.join(l for l in text.splitlines() if 'error' in l)[:800]); obj.unlink(missing_ok=True); raise SystemExit(1)
defs = {k for k, d in rebuild.coff_externals(obj.read_bytes()).items() if d}
al = []
for f_, (c, _) in sorted(found.items()):
    n = next((d for d in defs if d.startswith('??$create@V%s@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA' % c)), None)
    if n:
        al.append('%s=%s' % (f_, n))
(H / 'aliases_createinst.txt').write_text('\n'.join(al) + '\n')
print('createinst: %d create<C> instances (%s) -> %d aliases' % (len(cls), ', '.join(cls), len(al)))
