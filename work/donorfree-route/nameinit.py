"""python nameinit.py: real definitions for `const RBX::Name&` globals our link only has as zero base stubs.
The original constructs each at startup (`push idx; push "version"; call Name::declare; mov [addr], eax` in the
0x7c0000-0x800000 initializers). With a zero stub the reference is NULL: XmlElement::findAttribute(tag_version) matched
the FIRST attribute (xmlns:xsi URL) -> lexical_cast<int> threw -> Camera clone failed -> "circular reference" on File->New.
For each base-stubbed Name global with an original address: the literal + index from its initializer -> one TU
`const RBX::Name& name = RBX::Name::declare("lit", idx);` compiled with the natives' flags (its dynamic initializer runs
before main like the original's). Writes linkexp/nameinit.obj; quicktest.py links it."""
import json, re, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import rebuild
pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
img = pe.get_memory_mapped_image(); base = pe.OPTIONAL_HEADER.ImageBase
NAME_T = re.compile(r'@3ABVName@RBX@@B$')
stubbed = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    # names a previous nameinit.obj already supplies stay in: the set only grows (else a rerun dropped the 37 tags)
    if len(p) >= 4 and p[-1] in ('qt_base_stubs.obj', 'nameinit.obj') and NAME_T.search(p[1]):
        stubbed.add(p[1])
ren = json.loads((H / 'renamed/rename.json').read_text())
addr = {}
for x in ren.values():
    for k, v in (x.get('refs') or {}).items():
        if k in stubbed:
            addr.setdefault(k, set()).add(v)
# `const Name*` globals whose analog name carries the original address (?g_00973cd4@@3PBVName@RBX@@B, in qt_stubs):
# the same startup pattern (Name::declare then mov [addr], eax)
PTR_T = re.compile(r'^\?g_([0-9a-f]{8})@@3PBVName@RBX@@B$')
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and 'stubs' in p[-1]:
        m_ = PTR_T.match(p[1])
        if m_:
            stubbed.add(p[1]); addr[p[1]] = {m_.group(1)}


def cstr(va):
    o = va - base
    if not 0 <= o < len(img):
        return None
    e = img.find(b'\0', o, o + 200)
    s = bytes(img[o:e]) if e > o else b''
    return s.decode('latin-1') if s and all(32 <= c < 127 for c in s) else None


code = bytes(img[0x7c0000 - base:0x800000 - base])
# no unique address from callers (name_DeleteItem, tag_binary): the literal is the name's suffix -- find the initializer
# that pushes that string and stores the declare result (`push offset "binary" ... mov [addr], eax`)
for n in sorted(stubbed - set(addr)):
    m_ = re.match(r'^\?(?:tag|name)_(\w+)@@3ABVName@RBX@@B$', n)
    if not m_:
        continue
    so = img.find(b'\0' + m_.group(1).encode() + b'\0')
    while so >= 0:
        sva = base + so + 1
        po = code.find(b'\x68' + struct.pack('<I', sva))
        if po >= 0:
            st_ = code.find(b'\xa3', po, po + 40)
            if st_ >= 0:
                addr[n] = {'%08x' % struct.unpack_from('<I', code, st_ + 1)[0]}
                break
        so = img.find(b'\0' + m_.group(1).encode() + b'\0', so + 1)
found = {}
for n, vs in sorted(addr.items()):
    if len(vs) != 1:
        continue
    v = int(next(iter(vs)), 16)
    pat = b'\xa3' + struct.pack('<I', v)   # mov [v], eax after the declare call
    o = code.find(pat)
    if o < 0:
        continue
    lit, idx = None, -1
    w = code[max(0, o - 24):o]
    for k in range(len(w) - 5, -1, -1):   # nearest string push before the store, and the push right before it (index)
        if w[k] == 0x68:
            s_ = cstr(struct.unpack_from('<I', w, k + 1)[0])
            if s_:
                lit = s_
                if k >= 2 and w[k - 2] == 0x6a:
                    idx = struct.unpack_from('<b', w, k - 1)[0]
                elif k >= 5 and w[k - 5] == 0x68:
                    idx = struct.unpack_from('<i', w, k - 4)[0]
                break
    if lit is not None:
        found[n] = (lit, idx)
print('Name globals on the zero stub: %d, original address known: %d, literal found: %d' % (len(stubbed), len(addr), len(found)))
for n, (l_, i_) in list(found.items())[:8]:
    print('  %-40s "%s" %d' % (n[:40], l_, i_))
# EVERY Name::declare store in the original's initializers, whatever our side calls the global: an analog declared
# the "X"/"Y" tags as `void* xKey` (?xKey@@3PAXA), renamed to the placeholder dat_00975334 -> a zero pointer, so
# TypedPropertyDescriptor<Vector2int16>::readValue's child lookup returned NULL (getValue read address 4).
# Pattern: push idx; push "lit"; call Name::declare (00553f90); mov [addr], eax. A store target our link only has as a
# stub dat_<addr> gets a real `const Name*` under that name (C symbol _dat_<addr> + alias dat_<addr>=_dat_<addr>).
DECLARE = 0x553f90
stubn = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and ('stubs' in p[-1] or p[-1] == 'nameinit.obj'):
        stubn.add(p[1])
dfound = {}
for o in range(len(code) - 5):
    if code[o] != 0xe8 or 0x7c0000 + o + 5 + struct.unpack_from('<i', code, o + 1)[0] != DECLARE:
        continue
    st_ = code.find(b'\xa3', o + 5, o + 24)
    if st_ < 0:
        continue
    a_ = struct.unpack_from('<I', code, st_ + 1)[0]
    w = code[max(0, o - 16):o]
    lit, idx = None, -1
    for k in range(len(w) - 5, -1, -1):
        if w[k] == 0x68:
            s_ = cstr(struct.unpack_from('<I', w, k + 1)[0])
            if s_:
                lit = s_
                if k >= 2 and w[k - 2] == 0x6a:
                    idx = struct.unpack_from('<b', w, k - 1)[0]
                elif k >= 5 and w[k - 5] == 0x68:
                    idx = struct.unpack_from('<i', w, k - 4)[0]
                break
    dn = 'dat_%08x' % a_
    if lit is not None and dn in stubn:
        dfound[dn] = (lit, idx)
print('Name::declare stores into stub placeholders (dat_<addr>): %d %s' % (len(dfound), sorted(dfound.items())[:4]))
# the set only GROWS: once defined, a name is no longer a stub (or survives only as an alias spelling), so a re-scan
# cannot see it -- merge with everything earlier runs found (the 4 g_ pointers vanished on a rerun otherwise)
_pf = H / 'auto/nameinit_found.json'
try:
    _prev = json.loads(_pf.read_text())
except (OSError, ValueError):
    _prev = {'found': {}, 'dfound': {}}
for k_, v_ in _prev.get('found', {}).items():
    found.setdefault(k_, tuple(v_))
for k_, v_ in _prev.get('dfound', {}).items():
    dfound.setdefault(k_, tuple(v_))
_pf.write_text(json.dumps({'found': found, 'dfound': dfound}, indent=0))
if not found and not dfound:
    raise SystemExit(0)
src = H / 'linkexp/nameinit.cpp'
lines = ['// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS', '#include "util/Name.h"']
for n, (l_, i_) in sorted(found.items()):
    ident = re.match(r'^\?(\w+)@@', n).group(1)
    lit_ = l_.replace('\\', '\\\\').replace('"', '\\"')
    if PTR_T.match(n):   # const Name* const g_<addr>
        lines.append('extern const RBX::Name* const %s = &RBX::Name::declare("%s", %d);' % (ident, lit_, i_))
    else:
        lines.append('extern const RBX::Name& %s = RBX::Name::declare("%s", %d);' % (ident, lit_, i_))
for dn, (l_, i_) in sorted(dfound.items()):
    lit_ = l_.replace('\\', '\\\\').replace('"', '\\"')
    lines.append('extern "C" const RBX::Name* %s = &RBX::Name::declare("%s", %d);' % (dn, lit_, i_))
src.write_text('\n'.join(lines) + '\n')
import native_check_runner as _ncr
flags = _ncr.compiler_flags(src)
tc = rebuild.toolchain(21022)
obj = H / 'linkexp/nameinit.obj'
code_, text = rebuild.run(tc, 'cl', flags + ['/Fo' + str(obj), str(src)], H / 'linkexp')
if code_:
    print('compile failed:', '\n'.join(l for l in text.splitlines() if 'error' in l)[:600])
    obj.unlink(missing_ok=True)
    raise SystemExit(1)
defs = {k for k, d in rebuild.coff_externals(obj.read_bytes()).items() if d}
# callers spell the const Name* pointers ?g_X@@3PBVName@RBX@@B, VS2008 defines ?g_X@@3QBVName@RBX@@B: alias wanted -> defined
_al = ['%s=%s' % (n, n.replace('@@3PBVName@RBX@@B', '@@3QBVName@RBX@@B')) for n in found if PTR_T.match(n)
       and n.replace('@@3PBVName@RBX@@B', '@@3QBVName@RBX@@B') in defs]
_al += ['%s=_%s' % (dn, dn) for dn in sorted(dfound) if '_' + dn in defs]   # dat_<addr> -> the C symbol _dat_<addr>
(H / 'aliases_nameinit.txt').write_text(chr(10).join(_al) + (chr(10) if _al else ''))
print('dat_ Name pointers defined: %d of %d' % (sum(1 for dn in dfound if '_' + dn in defs), len(dfound)))
defs |= {n for n in found if PTR_T.match(n) and n.replace('@@3PBVName@RBX@@B', '@@3QBVName@RBX@@B') in defs}
print('nameinit.obj defines %d of %d (e.g. %s)' % (len(defs & set(found)), len(found), sorted(defs & set(found))[:2]))
