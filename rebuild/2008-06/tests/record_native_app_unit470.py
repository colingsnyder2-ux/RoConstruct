"""Record the unit map of the 2008-06 application range 00470000..00474000 (inactive; no native unit is built).

The range lies inside two G3D 6.09 library objects from Roblox's Rendering/g3d tree (library recipes g3d-6.09,
g3d-6.09-rbx2008, rbxgs-g3d in roc/libs.py): the end of GLG3Dcpp/GLCaps.cpp (its contribution starts at 0046fc10,
see app-unit46c / app-unit468-2008) and the start of GLG3Dcpp/Texture.cpp (continues to 00475b4f, see
app-unit474-2008). Between them lie G3D header COMDATs (Table/Set<std::string> destructors, GImage::Error,
ReferenceCountedObject). There is no RBX translation unit, RBX descriptor, static initializer or Roblox-only template
instantiation, so nothing is recovered and nothing is counted here (exact_function_rows is empty). Library code is
never recovered in native-classes.

Boundary and per-row evidence, all checked against the original binary bytes (not the analog server labels, which put
rows of this range under RBX::LDraw2Lua::LuaWriter, G3D::GImage::Error or G3D::ReferenceCountedObject):
  * __FILE__ strings '.\\glg3dcpp\\GLCaps.cpp' / '.\\glg3dcpp\\Texture.cpp'; no row of the range cites another
    source-file name, an RBX RTTI vtable or an RBX evidence name;
  * G3D-only messages, each also found in the upstream G3D 6.09 GLCaps.cpp / Texture.cpp text when that tree is
    unpacked under tools/libs (the check is recorded, and skipped only if the tree is absent);
  * OpenGL32 imports called through the IAT; G3D RTTI vtables (Table, Set, GImage::Error, ReferenceCountedObject,
    Texture) written or used as slot 0; the G3D evidence name Array<bool>::realloc;
  * the Texture::Settings constructor / defaults() / video() constant pattern (wrap/interpolate codes, 1000 / -1000
    mip-map bounds), with function statics referenced only by those rows;
  * capstone REL32 call/jmp or base-relocation DIR32 edges to other proven rows of the G3D GLG3Dcpp contributions
    0046fc10..0047ea1f (GLCaps, Texture, VARArea, RenderDevice, TextureManager as mapped by app-unit468-2008,
    app-unit46c and app-unit474-2008).
Rows other receipts count are listed (top-level exact_function_rows rule, as in record_native_app_unit478.py).
Addresses of rows not counted here are written as 0x-prefixed or 'ADDR counted by RECEIPT' text, never as quoted bare
addresses (local_backpack / viewnew_brick_build / viewnew_part_mesh read any quoted bare address as counted).
Writes work/2008-06/shared-layouts/app-unit470-working.json.
"""
import glob
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
import capstone  # noqa: E402
from roc import match  # noqa: E402

CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

R = ROOT / 'rebuild/2008-06'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit470-working.json'
LO, HI = 0x470000, 0x474000
G3D_LO, G3D_HI = 0x46fc10, 0x47ea20      # GLG3Dcpp contributions mapped by the neighbouring receipts
GLCAPS = '.\\glg3dcpp\\GLCaps.cpp'
TEXTURE = '.\\glg3dcpp\\Texture.cpp'
UPSTREAM = ROOT / 'tools/libs/g3d-6.09/source/GLG3Dcpp'
H = lambda a: '0x%08x' % a

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
rows = sorted(a for a in FUNCS if LO <= a < HI)
g3d_rows = sorted(a for a in FUNCS if G3D_LO <= a < G3D_HI)
body = lambda a: original.data(a, FUNCS[a]['size'])


def dwords(a):
    """DIR32 operands of the row: the image base-relocation offsets inside the row's bytes."""
    code, relocs, _ = match.target('2008-06', '%08x' % a)
    return {struct.unpack_from('<I', code, i)[0] for i in relocs if i + 4 <= len(code)}


def rel32_targets(a):
    out = set()
    for ins in CS.disasm(body(a), a):
        if ins.mnemonic in ('call', 'jmp') and ins.op_str.startswith('0x'):
            t = int(ins.op_str, 16)
            if not a <= t < a + FUNCS[a]['size']:
                out.add(t)
    return out


def string_at(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        raw = original.data(v, 256)
    except Exception:
        return None
    end = raw.find(b'\0')
    if end <= 0:
        return None
    return raw[:end].decode('latin-1')


def strings_of(a):
    return {s for s in (string_at(v) for v in dwords(a)) if s}


def gl_imports(a):
    return {original.imports[v][2] for v in dwords(a)
            if v in original.imports and original.imports[v][0] == 'opengl32.dll'}


def rtti_of(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        name, offset = original.vtable_class(v)
    except Exception:
        return None
    return name if name.startswith('.?A') else None


def text_refs(v):
    """Rows whose bytes hold the 4-byte value v at a base-relocation offset (scan of the original .text)."""
    pat = struct.pack('<I', v)
    out = set()
    for a in FUNCS:
        if pat in body(a) and v in dwords(a):
            out.add(a)
    return sorted(out)


checks = []
# ---- boundary: contiguous rows; the range opens inside GLCaps.cpp and closes inside Texture.cpp ---------------------
prev = max(a for a in FUNCS if a < LO)
assert prev == 0x46fff0 and prev + FUNCS[prev]['size'] <= rows[0] == 0x4704a0, (hex(prev), hex(rows[0]))
assert set(original.data(prev + FUNCS[prev]['size'], rows[0] - prev - FUNCS[prev]['size'])) == {0xcc}
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)
last = rows[-1]
assert last == 0x473fc0 and last + FUNCS[last]['size'] > HI
# below: the row before the range is an OpenGL helper whose only caller is the GLCaps.cpp row 00471590
assert gl_imports(prev) and [int(c, 16) for c in FUNCS[prev]['callers']] == [0x471590]
assert prev in rel32_targets(0x471590) and GLCAPS in strings_of(0x471590)
checks.append({'row': H(prev), 'kind': 'anchor-below', 'opengl_imports': sorted(gl_imports(prev))[:4],
               'only_caller': H(0x471590), 'caller_file': GLCAPS})
# above: the last row runs past 00474000 and is called only by 00474690 / 00474c60, the Texture.cpp rows of
# app-unit474-2008 (00474690 is called by the Texture.cpp-string row 004747f0)
assert sorted(int(c, 16) for c in FUNCS[last]['callers']) == [0x474690, 0x474c60]
assert 0x474690 in rel32_targets(0x4747f0) and TEXTURE in strings_of(0x4747f0)
checks.append({'row': H(last), 'kind': 'anchor-above', 'runs_to': H(last + FUNCS[last]['size']),
               'callers': [H(0x474690), H(0x474c60)], 'texture_file_row': H(0x4747f0)})

# ---- no foreign evidence in the range -----------------------------------------------------------------------------------
for a in rows:
    for s in strings_of(a):
        if re.search(r'\.(cpp|h|inl)$', s, re.I) and ('\\' in s or '/' in s):
            assert s in (GLCAPS, TEXTURE), (hex(a), s)
    for v in dwords(a):
        n = rtti_of(v)
        assert not (n and '@RBX@@' in n), (hex(a), hex(v), n)
assert [H(a) for a in rows if '@RBX@@' in names.get(a, '')] == []

# ---- per-row evidence -------------------------------------------------------------------------------------------------
proof = {}


def prove(a, kind, **kw):
    proof.setdefault(a, []).append(dict(kind=kind, **kw))


FILE_ROWS = {0x470770: GLCAPS, 0x470880: GLCAPS, 0x4709a0: GLCAPS, 0x471070: GLCAPS, 0x471590: GLCAPS,
             0x4716f0: GLCAPS, 0x473250: TEXTURE, 0x473510: TEXTURE, 0x4739f0: TEXTURE}
for a in rows:
    for f in (GLCAPS, TEXTURE):
        if f in strings_of(a):
            prove(a, 'file-string', text=f)
assert {a: p[0]['text'] for a, p in proof.items()} == FILE_ROWS, {H(a): p for a, p in proof.items()}
first_texture = min(a for a, f in FILE_ROWS.items() if f == TEXTURE)
assert max(a for a, f in FILE_ROWS.items() if f == GLCAPS) < first_texture

# G3D-only messages: (row, string in the row, upstream G3D 6.09 file that holds the text)
MESSAGES = [
    (0x470770, 'Cannot call GLCaps::glVersion before GLCaps::init().', 'GLCaps.cpp'),
    (0x470880, 'Cannot call GLCaps::vendor before GLCaps::init().', 'GLCaps.cpp'),
    (0x4709a0, 'Cannot call GLCaps::renderer before GLCaps::init().', 'GLCaps.cpp'),
    (0x470ab0, 'MOBILITY RADEON 7500', 'GLCaps.cpp'),
    (0x470bf0, 'Brian Paul', 'GLCaps.cpp'),
    (0x470cf0, '\\nv4_disp.dll', 'GLCaps.cpp'),
    (0x471070, 'Cannot call GLCaps::driverVersion before GLCaps::init().', 'GLCaps.cpp'),
    (0x4711a0, 'Intel 854G', 'GLCaps.cpp'),
    (0x471590, 'Cannot check for OpenGL bugs before extensions are loaded.', 'GLCaps.cpp'),
    (0x4716f0, 'wglAllocateMemoryNV', 'GLCaps.cpp'),
    (0x4704a0, 'GL_SGIS_generate_mipmap', 'GLCaps.cpp'),
    (0x4729d0, 'GL_SGIS_generate_mipmap', 'Texture.cpp'),
    (0x472f10, 'GL_EXT_texture_filter_anisotropic', 'Texture.cpp'),
    (0x473250, 'Illegal interpolate mode', 'Texture.cpp'),
    (0x473350, 'Cube map filenames must contain', 'Texture.cpp'),
    (0x4739f0, 'Error encountered during glBindTexture: ', 'Texture.cpp'),
]
upstream_checked = UPSTREAM.is_dir()
for a, text, upfile in MESSAGES:
    assert any(text in s for s in strings_of(a)), (hex(a), text)
    entry = {'text': text}
    if upstream_checked:
        src = (UPSTREAM / upfile).read_text(encoding='latin-1').replace('\\\\', '\\')
        assert text in src, (upfile, text)
        entry['upstream'] = 'g3d-6.09 GLG3Dcpp/' + upfile
    prove(a, 'g3d-message', **entry)
checks.append({'kind': 'upstream-text', 'tree': 'tools/libs/g3d-6.09/source/GLG3Dcpp',
               'checked': upstream_checked, 'messages': len(MESSAGES)})

for a in rows:
    g = sorted(gl_imports(a))
    if g:
        prove(a, 'opengl-import', imports=g[:8])

# G3D RTTI vtables: rows that store or are slot 0 of them (one vtable per class; RTTI checked by COL)
VTABLES = {
    0x81ce24: ('.?AV?$Table@PBVTextureFormat@G3D@@_N@G3D@@', 0x4713c0),
    0x81ce1c: ('.?AV?$Table@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@G3D@@', 0x472820),
    0x81e194: ('.?AV?$Set@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@G3D@@', 0x472880),
    0x81e1d4: ('.?AVError@GImage@G3D@@', 0x473790),
    0x81e1e0: ('.?AVReferenceCountedObject@G3D@@', 0x4729b0),
    0x81e36c: ('.?AVTexture@G3D@@', 0x473ed0),
}
for vt, (rtti, slot0) in VTABLES.items():
    assert original.vtable_class(vt) == (rtti, 0) and d(vt) == slot0, hex(vt)
    checks.append({'kind': 'g3d-vtable', 'vtable': H(vt), 'rtti': rtti, 'slot0': H(slot0)})
    prove(slot0, 'g3d-vtable-slot0', vtable=H(vt), rtti=rtti)
for a in rows:
    for v in sorted(dwords(a)):
        if v in VTABLES:
            prove(a, 'g3d-vtable-ref', vtable=H(v), rtti=VTABLES[v][0])
# GImage::Error derives std::runtime_error in this build (RTTI base list), unlike upstream 6.09
checks.append({'kind': 'rtti-bases', 'vtable': H(0x81e1d4),
               'note': 'GImage::Error -> std::runtime_error -> std::exception (Roblox G3D tree)'})
assert names.get(0x409d50, '').startswith('??0runtime_error@std@@') and 0x409d50 in rel32_targets(0x4728b0)
assert names.get(0x409e90, '').startswith('??0runtime_error@std@@') and 0x409e90 in rel32_targets(0x4734a0)

EVIDENCE_NAMES = {0x473740: '?realloc@?$Array@_N@G3D@@AAEXH@Z'}
for a, sym in EVIDENCE_NAMES.items():
    assert names.get(a) == sym, (hex(a), names.get(a))
    prove(a, 'evidence-name', symbol=sym)
assert {a for a in rows if names.get(a)} == set(EVIDENCE_NAMES), [H(a) for a in rows if names.get(a)]

# Texture::Settings() / defaults() / video(): the same constant pattern (interpolate 3, wrap 1, depth-read 0,
# maxAnisotropy from the float 0x0081c434, autoMipMap true, max/min mip-map 1000 / -1000); the two function statics
# 0096ef4c / 0096ef70 are referenced by those rows only
for a, base in ((0x472a80, None), (0x472ac0, 0x96ef4c), (0x472b20, 0x96ef70)):
    b = body(a)
    assert 0x81c434 in dwords(a) and struct.pack('<I', 0x3e8) in b and struct.pack('<I', 0xfffffc18) in b, hex(a)
    kw = {'constants': ['0x3e8', '0xfffffc18'], 'float': H(0x81c434)}
    if base is not None:
        assert base in dwords(a)
        assert sorted({r for r in text_refs(base)}) == [a], (hex(a), hex(base))
        kw['static'] = H(base)
    prove(a, 'texture-settings-pattern', **kw)

# G3D template / static data shared with proven rows
assert 0x9336b0 in dwords(0x471060) and 0x9336b0 in dwords(0x4711a0) and 0x9336b0 in dwords(0x4716f0)
prove(0x471060, 'shared-static', static=H(0x9336b0), with_rows=[H(0x4711a0), H(0x4716f0)],
      what='GLCaps extension Table<std::string,bool>')
# Texture members +0x58 (dimension), +0x64 / +0x68 (width / height) shared with the Texture rows 00473670 / 004737b0
for a, pats in ((0x473700, [b'\x8b\x49\x58']), (0x473670, [b'\x83\x79\x58\x05', b'\x8b\x79\x64', b'\x8b\x59\x68']),
                (0x473f90, [b'\xdb\x41\x68', b'\xdb\x41\x64'])):
    for p in pats:
        assert p in body(a), (hex(a), p.hex())
    prove(a, 'texture-member', patterns=[p.hex(' ') for p in pats])
assert names.get(0x45b950, '').startswith('?xyxy@Rect2D@G3D@@') and 0x45b950 in rel32_targets(0x473f90)
prove(0x473f90, 'g3d-callee', callee=H(0x45b950), symbol=names[0x45b950])

# 00470700: an out-of-line G3D destructor (std::string members +0xc / +0x54, G3D array buffer +0x28 freed through
# 0x00507d20, the same free the evidence-named Array<bool>::realloc 00473740 calls); its callers are the G3D GImage
# PPM writer 0x0050eaf0 ('P3\n%d %d\n255\n') and 0x00509840
assert 0x507d20 in rel32_targets(0x470700) and 0x507d20 in rel32_targets(0x473740)
assert 'P3\n%d %d\n255\n' in strings_of(0x50eaf0) and 0x470700 in rel32_targets(0x50eaf0)
prove(0x470700, 'g3d-free-callee', callee=H(0x507d20), shared_with=H(0x473740),
      caller=H(0x50eaf0), caller_string='P3\n%d %d\n255\n')

# graph closure over the GLG3Dcpp contributions: REL32 call/jmp and DIR32 edges decoded from the original bytes
proven = set(proof) | {prev}
edges = {a: (rel32_targets(a) | dwords(a)) for a in g3d_rows}
# seeds outside the range: rows proven by their own G3D strings / evidence names / OpenGL imports
for a in g3d_rows:
    if LO <= a < HI:
        continue
    s = strings_of(a)
    if (GLCAPS in s or TEXTURE in s or gl_imports(a) or '@G3D@@' in names.get(a, '')
            or any(x.startswith('.\\glg3dcpp\\') for x in s)):
        proven.add(a)
via = {}
changed = True
while changed:
    changed = False
    for a in g3d_rows:
        if a in proven:
            continue
        out = sorted(b for b in edges[a] if b in proven and b != a)
        inn = sorted(b for b in g3d_rows if b in proven and a in edges[b] and b != a)
        if out or inn:
            via[a] = (out, inn)
            proven.add(a)
            changed = True
for a in rows:
    if a in via:
        out, inn = via[a]
        prove(a, 'graph-edge', to=[H(b) for b in out[:4]], from_rows=[H(b) for b in inn[:4]])
missing = [H(a) for a in rows if a not in proof]
assert not missing, missing


# ---- counting rules (same as record_native_app_unit478.py) ------------------------------------------------------------
def counted_elsewhere():
    out = {}
    for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
        if Path(path).name == RECEIPT.name:
            continue
        try:
            data = json.loads(Path(path).read_text())
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        found = []
        if 'exact_function_rows' in data:
            found = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            found = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            found = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        found.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(found, dict):
            found = list(found)
        for r in found:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault(int(m.group(1), 16), set()).add(Path(path).name)
    return out


elsewhere = counted_elsewhere()
range_counted = {a: sorted(v) for a, v in sorted(elsewhere.items()) if LO <= a < HI}

GLCAPS_END = 0x472850          # GLCaps::init() wrapper, last GLCaps member (calls loadExtensions 004716f0)
SEAM = (0x472860, 0x4729b0)    # G3D header COMDATs between the two objects
TEX_START = 0x4729d0           # hasAutoMipMap (GL_SGIS_generate_mipmap), called only by Texture rows
assert sorted(int(c, 16) for c in FUNCS[TEX_START]['callers']) == [0x472f10, 0x473fc0]
assert 0x4716f0 in rel32_targets(GLCAPS_END)


def block(a):
    if a <= GLCAPS_END:
        return 'g3d-glcaps'
    if a < TEX_START:
        return 'g3d-header-comdats'
    return 'g3d-texture'


ROLES = {   # upstream-shape hints only; identity in this receipt rests on the evidence lists, not these names
    0x4704a0: 'GLCaps static: GL_SGIS_generate_mipmap probe (glGenTextures/glBindTexture/glDeleteTextures)',
    0x470600: 'G3D::Table<std::string,bool>::containsKey (GLCaps extension table)',
    0x470700: 'G3D destructor with two std::string members and an Array buffer (likely TextOutput, header COMDAT)',
    0x470770: 'G3D::GLCaps::glVersion', 0x470880: 'G3D::GLCaps::vendor', 0x4709a0: 'G3D::GLCaps::renderer',
    0x470ab0: 'G3D::GLCaps slow-VBO / Radeon bug check', 0x470bf0: 'G3D::GLCaps::computeVendor',
    0x470cf0: 'G3D::GLCaps::getDriverVersion', 0x471060: 'G3D::GLCaps::supports(const std::string&)',
    0x471070: 'G3D::GLCaps::driverVersion', 0x4711a0: 'G3D::GLCaps mipmap-generation bug check',
    0x4713b0: 'G3D::Table<const TextureFormat*,bool> dtor', 0x4713c0: 'G3D::Table<const TextureFormat*,bool> ??_G',
    0x471590: 'G3D::GLCaps::checkAllBugs', 0x4716f0: 'G3D::GLCaps::loadExtensions',
    0x472820: 'G3D::Table<std::string,bool> ??_G', 0x472850: 'G3D::GLCaps::init',
    0x472860: 'G3D::Set<std::string> dtor', 0x472880: 'G3D::Set<std::string> ??_G',
    0x4728b0: 'G3D::GImage::Error ctor (std::runtime_error base)', 0x472920: 'G3D::GImage::Error dtor',
    0x472990: 'G3D::ReferenceCountedObject ctor', 0x4729b0: 'G3D::ReferenceCountedObject ??_G',
    0x4729d0: 'Texture.cpp static hasAutoMipMap', 0x472a80: 'G3D::Texture::Settings::Settings',
    0x472ac0: 'G3D::Texture::Settings::defaults', 0x472b20: 'G3D::Texture::Settings::video',
    0x472bb0: 'Texture.cpp static createTexture (glTexImage2D)', 0x472da0: 'Texture.cpp static createMipMapTexture',
    0x472f10: 'Texture.cpp static setTexParameters', 0x4731c0: 'Texture.cpp static brightenImage',
    0x473250: 'Texture.cpp static isMipMapformat', 0x473350: 'G3D::Texture::splitFilenameAtWildCard',
    0x4734a0: 'G3D::GImage::Error copy ctor', 0x473510: 'G3D::Texture::newGLTextureID',
    0x473600: 'Texture.cpp static getCurrentBuffer', 0x473670: 'G3D::Texture::sizeInMemory',
    0x473700: 'G3D::Texture::getOpenGLTextureTarget', 0x473740: 'G3D::Array<bool>::realloc',
    0x473790: 'G3D::GImage::Error ??_G', 0x4737b0: 'G3D::Texture::Texture', 0x473980: 'G3D::Texture::~Texture',
    0x4739f0: 'G3D::Texture::copyFromScreen', 0x473cd0: 'G3D::Array<uint8>::resize (Texture.cpp instance)',
    0x473dd0: 'G3D::Array<bool>::resize', 0x473ed0: 'G3D::Texture ??_G',
    0x473ef0: 'G3D::Texture::fromGLTexture (new 0x74 + Texture ctor)', 0x473f90: 'G3D::Texture::rect2DBounds',
    0x473fc0: 'G3D::Texture::fromMemory',
}
blocks = {}
for a in rows:
    blocks.setdefault(block(a), []).append(a)
UNIT_TEXT = {
    'g3d-glcaps': ('G3D 6.09 GLG3Dcpp/GLCaps.cpp (library; starts at 0x0046fc10 below this range): members, the '
                   'extension Table<std::string,bool> / Table<const TextureFormat*,bool> instances and init()'),
    'g3d-header-comdats': ('G3D header COMDATs between GLCaps.obj and Texture.obj (Set<std::string>, GImage::Error, '
                           'ReferenceCountedObject). Which of the two objects emitted them is not decided by the '
                           'bytes; they are G3D library code either way'),
    'g3d-texture': ('G3D 6.09 GLG3Dcpp/Texture.cpp (library; continues past 0x00474000 to 0x00475b4f, see '
                    'app-unit474-2008-working.json): file statics, Texture::Settings, Texture members'),
}
UNIT_MAP = {}
for k, lst in blocks.items():
    UNIT_MAP['%s %s..%s' % (k, H(lst[0]), H(lst[-1]))] = {
        'rows': len(lst), 'bytes': sum(FUNCS[a]['size'] for a in lst),
        'unit': UNIT_TEXT[k], 'library': True, 'recovered': False,
        'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(range_counted[a])) for a in lst if a in range_counted],
    }
row_map = [{'row': H(a), 'size': FUNCS[a]['size'], 'block': block(a), 'role_hint': ROLES.get(a, ''),
            'evidence': proof[a], 'counted_by': range_counted.get(a, [])} for a in rows]
NOTES = {
    'analog-labels': ('The analog unit labels RBX::LDraw2Lua::LuaWriter (0x00470600, 0x00471060), '
                      'G3D::GImage::Error (0x004737b0..0x00473cd0) and G3D::ReferenceCountedObject (0x00472a80..'
                      '0x00473700) are wrong for these rows: they are GLCaps.cpp / Texture.cpp code.'),
    'no-rbx-unit': ('No RBX class, Reflection descriptor, static initializer or Roblox-only template instantiation '
                    'lies in the range. RBX callers (MegaTexture 0x007b9000 / 0x007b8610, DepthBlur::allocateTextures '
                    '0x005071d0) only call the G3D Texture::Settings rows.'),
    'gimage-error': ('GImage::Error derives std::runtime_error here (RTTI 0x0081e1d4 base list; ctors call '
                     'runtime_error(const string&) 0x00409d50 / runtime_error(const runtime_error&) 0x00409e90), a '
                     'Roblox G3D-tree change against upstream 6.09; relevant to the g3d-6.09-rbx2008 recipe only.'),
    'neighbour-maps': ('Agrees with app-unit468-2008 / app-unit46c (GLCaps 0x0046fc10..0x004729cf, Texture '
                       '0x004729d0..) and app-unit474-2008 (Texture to 0x00475b4f); this receipt adds per-row '
                       'evidence and splits out the header-COMDAT seam.'),
}
receipt = {
    'class': 'unit map of the application range 00470000..00474000 (2008-06): G3D 6.09 GLCaps.cpp / Texture.cpp, inactive',
    'result': ('No RBX translation unit and no Roblox-only template instantiation in the range: all %d rows are G3D '
               '6.09 library code (GLCaps.cpp tail, G3D header COMDATs, Texture.cpp head). Nothing is recovered or '
               'counted here.' % len(rows)),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'unit_map': UNIT_MAP,
    'row_map': row_map,
    'evidence_checks': checks,
    'notes': NOTES,
    'range_functions': len(rows),
    'range_bytes': sum(FUNCS[a]['size'] for a in rows),
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'exact_function_rows': [],
    'library_recipes': ['g3d-6.09', 'g3d-6.09-rbx2008', 'rbxgs-g3d (roc/libs.py)'],
    'scope': 'Inactive map receipt. No native source, no counted row, no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = sorted(set(re.findall(r'"([0-9a-f]{8})"', text)))
assert not bare, bare
RECEIPT.write_text(text)
kinds = {}
for a in rows:
    for p in proof[a]:
        kinds[p['kind']] = kinds.get(p['kind'], 0) + 1
print('PASS app-unit470: %d range rows (%d bytes), blocks %s, evidence %s, %d counted elsewhere (%s); 0 counted here'
      % (len(rows), receipt['range_bytes'], {k: len(v) for k, v in blocks.items()}, kinds, len(range_counted),
         ' '.join('%08x' % a for a in range_counted)))
