"""Record the unit map of the 2008-06 application range 00478000..0047c000 (inactive; no native unit is built).

The whole range lies inside one translation unit: G3D 6.09 GLG3Dcpp/RenderDevice.cpp from Roblox's Rendering/g3d
tree (library recipes g3d-6.09, g3d-6.09-rbx2008, rbxgs-g3d in roc/libs.py), together with the G3D header inlines and
compiler helpers that object file contributes out of line. The RenderDevice.cpp contribution starts below the range
(the row before 00478000 runs exactly up to the first row of the range) and ends above it (the last row of the range
runs past 0047c000 and is called only by RenderDevice rows). There is no RBX translation unit and no Roblox-only
template instantiation here, so no row is recovered and none is counted (exact_function_rows is empty). Library code
is never recovered in native-classes.

Boundary evidence, all checked against the original binary bytes (not the analog server labels, which put
004781c0..0047bfc0 under CInstanceRecord::CNameItem because the ICF-shared getter 004781c0 is also slot 63 of the XTP
report-record-item vtables):
  * __FILE__ evidence: rows holding a DIR32 pointer to '.\\glg3dcpp\\RenderDevice.cpp' bracket the range on both
    sides, and no row of the range points to any other source-file name (so no second object file lies between);
  * per-row evidence (every row has at least one): the RenderDevice.cpp file string or a RenderDevice-only message,
    a G3D evidence name (offline/evidence.json), an OpenGL32 import called through the IAT, the RenderDevice members
    shared with other proven rows (+0x3e8 framebuffer, +0x6c..+0x7c state-change counters, the zero-vector static),
    the ICF-shared getter slot of the XTP vtables (by RTTI), or a call / function-pointer edge to another proven row
    of the RenderDevice.cpp block, re-decoded from the original bytes (REL32 call or DIR32 operand);
  * no row refers to an RBX vtable (by RTTI) and no evidence name in the range is an RBX symbol.
It also lists the rows other receipts count (top-level exact_function_rows rule, as in
record_native_app_unit474_2008.py). Addresses of rows not counted here are written as 0x-prefixed or 'ADDR counted by
RECEIPT' text, never as quoted bare addresses (local_backpack / viewnew_brick_build / viewnew_part_mesh read any quoted
bare address in a receipt as counted there).
Writes work/2008-06/shared-layouts/app-unit478-working.json.
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
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit478-working.json'
LO, HI = 0x478000, 0x47c000
# RenderDevice.cpp contribution as mapped by app-unit474-2008 (inf 00476520 .. the ICF ret 0047d410); used here only
# as the set of rows a graph edge may reach. Rows outside the range used as anchors are proven below by their own
# strings.
RD_LO, RD_HI = 0x476520, 0x47d410
FILE = '.\\glg3dcpp\\RenderDevice.cpp'
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
rd_rows = sorted(a for a in FUNCS if RD_LO <= a < RD_HI)
body = lambda a: original.data(a, FUNCS[a]['size'])


def dwords(a):
    """DIR32 operands of the row: the image base-relocation offsets inside the row's bytes."""
    code, relocs, _ = match.target('2008-06', '%08x' % a)
    return {struct.unpack_from('<I', code, i)[0] for i in relocs if i + 4 <= len(code)}


def rel32_targets(a):
    """Direct call / jmp targets of the row, decoded with capstone from the original bytes."""
    out = set()
    for ins in CS.disasm(body(a), a):
        if ins.mnemonic in ('call', 'jmp') and ins.op_str.startswith('0x'):
            out.add(int(ins.op_str, 16))
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
    try:
        return raw[:end].decode('latin-1')
    except Exception:
        return None


def strings_of(a):
    return {s for s in (string_at(v) for v in dwords(a)) if s}


def gl_imports(a):
    out = set()
    for v in dwords(a):
        if v in original.imports and original.imports[v][0] == 'opengl32.dll':
            out.add(original.imports[v][2])
    return out


def rtti_of(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        name, offset = original.vtable_class(v)
    except Exception:
        return None
    return name if name.startswith('.?A') else None


# ---- boundary: contiguous rows, the range opens and closes inside RenderDevice.cpp ------------------------------------
prev = max(a for a in FUNCS if a < LO)
assert prev + FUNCS[prev]['size'] == rows[0] == 0x4781b0, (hex(prev), hex(rows[0]))
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)
last = rows[-1]
assert last == 0x47bfc0 and last + FUNCS[last]['size'] > HI
checks = []
# anchors outside the range, each proven by its own RenderDevice.cpp string (below / above the range)
ANCHORS = [
    (0x477970, 'GL_ARB_texture_env_combine'),            # below: RenderDevice::init extension probe
    (0x4774f0, 'GL_EXT_blend_minmax'),
    (0x47c0c0, 'wglSwapIntervalEXT(0);\n'),              # above: the caller of 0047b5f0 and 0047bfc0
    (0x47c3e0, 'Shutting down RenderDevice.'),            # above: RenderDevice::cleanup, caller of 0047bfc0
]
for a, text in ANCHORS:
    assert text in strings_of(a), (hex(a), text)
    checks.append({'row': H(a), 'kind': 'anchor-string', 'text': text, 'inside_range': False})

# ---- no foreign evidence in the range -----------------------------------------------------------------------------------
for a in rows:
    for s in strings_of(a):
        if re.search(r'\.(cpp|h|inl)$', s, re.I) and ('\\' in s or '/' in s):
            assert s == FILE, (hex(a), s)
    for v in dwords(a):
        n = rtti_of(v)
        assert not (n and '@RBX@@' in n), (hex(a), hex(v), n)
rbx_named = [H(a) for a in rows if '@RBX@@' in names.get(a, '')]
assert rbx_named == [], rbx_named

# ---- per-row evidence -------------------------------------------------------------------------------------------------
proof = {}


def prove(a, kind, **kw):
    proof.setdefault(a, []).append(dict(kind=kind, **kw))


MESSAGES = {   # rows whose bytes point to RenderDevice.cpp-only messages (besides the file name)
    0x478690: 'Drawing to a color buffer is only supported by application-created framebuffers!',
    0x478f80: 's->ok()',
    0x479700: 'All vertex arrays used within a single begin/endIndexedPrimitive block must share the same VARArea.',
    0x479c30: 'VAR Milestone',
    0x47b5f0: 'Setting initial rendering state.\n',
}
for a in rows:
    s = strings_of(a)
    if FILE in s:
        prove(a, 'file-string', text=FILE)
    if a in MESSAGES:
        assert MESSAGES[a] in s, (hex(a), MESSAGES[a])
        prove(a, 'message-string', text=MESSAGES[a])
file_rows = [a for a in rows if any(p['kind'] == 'file-string' for p in proof.get(a, []))]
assert file_rows == [0x478690, 0x478f80, 0x479700], [H(a) for a in file_rows]

EVIDENCE_NAMES = {
    0x478230: '??A?$Array@G@G3D@@QAEAAGH@Z',
    0x478240: '?realloc@?$Array@G@G3D@@AAEXH@Z',
    0x4782d0: '??0CoordinateFrame@G3D@@QAE@XZ',
    0x478330: '?inverse@CoordinateFrame@G3D@@QBE?AV12@XZ',
}
for a, sym in EVIDENCE_NAMES.items():
    assert names.get(a) == sym, (hex(a), names.get(a))
    prove(a, 'evidence-name', symbol=sym)
assert {a for a in rows if names.get(a)} == set(EVIDENCE_NAMES), [H(a) for a in rows if names.get(a)]

for a in rows:
    g = sorted(gl_imports(a))
    if g:
        prove(a, 'opengl-import', imports=g)

# ICF-shared RenderDevice counter getters: `mov eax,[ecx+disp8]; ret`, the same members the proven rows 004789e0 /
# 00478f20 / 00478f40 increment (+0x78/+0x70, +0x74, +0x6c)
GETTERS = {0x4781b0: 0x7c, 0x4781c0: 0x70, 0x4781d0: 0x74, 0x4781e0: 0x78}
for a, disp in GETTERS.items():
    assert body(a) == bytes([0x8b, 0x41, disp, 0xc3]), hex(a)
    prove(a, 'counter-getter', member='+0x%x' % disp)
COUNTERS = {0x4789e0: (b'\x01\x41\x78', b'\x01\x41\x70'), 0x478f20: (b'\xff\x41\x74',), 0x478f40: (b'\xff\x46\x6c',)}
for a, pats in COUNTERS.items():
    for p in pats:
        assert p in body(a), (hex(a), p)
    prove(a, 'counter-increment', patterns=[p.hex() for p in pats])
XTP_SLOT = {0x80f65c: '.?AVCNameItem@CInstanceRecord@@', 0x8532e4: '.?AVCXTPReportRecordItem@@'}
for vt, rtti in XTP_SLOT.items():
    assert original.vtable_class(vt) == (rtti, 0) and d(vt + 4 * 63) == 0x4781c0, hex(vt)
    checks.append({'row': H(0x4781c0), 'kind': 'icf-vtable-slot', 'vtable': H(vt), 'rtti': rtti, 'slot': 63})

# +0x3e8 framebuffer (null: ask the window through its vtable): width/height getters and readDepth (glReadPixels)
for a in (0x478450, 0x478cd0, 0x479650):
    assert b'\x8b\x81\xe8\x03\x00\x00' in body(a), hex(a)
    prove(a, 'framebuffer-member', member='+0x3e8')
# Vector3::zero() function-static (guard 0096f050, value 0096f044..0096f04c), shared with CoordinateFrame() 004782d0
for a in (0x4782a0, 0x4782d0):
    assert {0x96f044, 0x96f048, 0x96f04c} <= dwords(a), hex(a)
assert 0x96f050 in dwords(0x4782a0)
prove(0x4782a0, 'shared-static', with_row=H(0x4782d0), statics=['0x0096f044', '0x0096f050'])
# compiler-generated vector copy-constructor iterator (stdcall, 5 arguments, `ret 0x14`), called by 00478900 with the
# GLight copy constructor 00477c50 (evidence name ??0GLight@G3D@@QAE@ABV01@@Z)
assert body(0x4781f0).endswith(b'\xc2\x14\x00') and b'\xff\x54\x24\x28' in body(0x4781f0)
assert names.get(0x477c50) == '??0GLight@G3D@@QAE@ABV01@@Z' and 0x477c50 in dwords(0x478900)
prove(0x4781f0, 'compiler-helper', what='vector copy-constructor iterator used with GLight(const GLight&) 0x00477c50')

# +0x488 member (the current framebuffer / state object): the proven row 00478f20 compares against it
assert b'\x81\xc1\x88\x04\x00\x00' in body(0x478f20) and b'\x8b\x8e\x88\x04\x00\x00' in body(0x478620)
prove(0x478620, 'shared-member', member='+0x488', with_row=H(0x478f20))
# direct callees that themselves call OpenGL32 imports (e.g. 00483550, the glGetDoublev projection helper)
for a in rows:
    gl_callees = sorted(b for b in rel32_targets(a) if b in FUNCS and b != a and gl_imports(b))
    if gl_callees:
        prove(a, 'opengl-callee', callees=[H(b) for b in gl_callees[:4]],
              imports=sorted(set().union(*(gl_imports(b) for b in gl_callees)))[:6])

# graph closure: direct call / jmp (capstone) or DIR32 (base relocation) edges, decoded from the original bytes,
# between rows of the RenderDevice.cpp contribution; it starts from the rows proven above, the string anchors and the
# G3D evidence-name rows of the contribution below the range
BELOW = {a for a in rd_rows if a < LO and '@G3D@@' in names.get(a, '')}
proven = set(proof) | {a for a, _ in ANCHORS} | BELOW
edges = {a: (rel32_targets(a) | dwords(a)) for a in rd_rows}
via = {}
changed = True
while changed:
    changed = False
    for a in rd_rows:
        if a in proven:
            continue
        out = sorted(b for b in edges[a] if b in proven and b != a)
        inn = sorted(b for b in rd_rows if b in proven and a in edges[b] and b != a)
        if out or inn:
            via[a] = (out, inn)
            proven.add(a)
            changed = True
for a in rows:
    if a in via:
        out, inn = via[a]
        prove(a, 'graph-edge', to=[H(b) for b in out[:4]], from_rows=[H(b) for b in inn[:4]],
              through=[H(b) for b in out[:4] + inn[:4] if not LO <= b < HI and b in via])
missing = [H(a) for a in rows if a not in proof]
assert not missing, missing
# the row that runs past 0047c000 is called only by RenderDevice rows (the anchors 0047c0c0 / 0047c3e0)
assert sorted(int(c, 16) for c in FUNCS[last]['callers']) == [0x47c0c0, 0x47c3e0]
assert all(last in rel32_targets(b) for b in (0x47c0c0, 0x47c3e0))


# ---- counting rules (same as record_native_app_unit474_2008.py) -------------------------------------------------------
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

ROLES = {
    0x4781b0: 'RenderDevice counter getter (+0x7c), ICF-shared',
    0x4781c0: 'RenderDevice counter getter (+0x70), ICF-shared; also XTP report-record-item vtable slot 63',
    0x4781d0: 'RenderDevice counter getter (+0x74), ICF-shared',
    0x4781e0: 'RenderDevice counter getter (+0x78), ICF-shared',
    0x4781f0: 'compiler-generated vector copy-constructor iterator (GLight array copy)',
    0x478230: 'G3D::Array<uint16>::operator[] (G3D header inline)',
    0x478240: 'G3D::Array<uint16>::realloc (G3D header inline)',
    0x4782a0: 'G3D::Vector3::zero() (G3D header inline, function static)',
    0x4782d0: 'G3D::CoordinateFrame::CoordinateFrame() (G3D header inline)',
    0x478330: 'G3D::CoordinateFrame::inverse (G3D header inline)',
}
UNIT_MAP = {
    'g3d-renderdevice 0x00478000..0x0047bfff': {
        'rows': len(rows),
        'bytes': sum(FUNCS[a]['size'] for a in rows),
        'first': H(rows[0]),
        'last': '%s (runs to %s, past the range end)' % (H(last), H(last + FUNCS[last]['size'])),
        'unit': ('G3D 6.09 GLG3Dcpp/RenderDevice.cpp (contribution 0x00476520..0x0047d40f, starts and ends outside '
                 'this range), with the G3D header inlines and compiler helpers it emits out of line'),
        'library': True,
        'recovered': False,
        'counted_elsewhere': ['%s counted by %s' % ('%08x' % a, ', '.join(v)) for a, v in range_counted.items()],
    },
}
row_map = [{'row': H(a), 'size': FUNCS[a]['size'], 'unit': 'G3D 6.09 RenderDevice.cpp (library)',
            'role': ROLES.get(a, 'G3D::RenderDevice member or RenderDevice.cpp local'),
            'evidence': proof[a],
            'counted_by': range_counted.get(a, [])} for a in rows]
NOTES = {
    'analog-labels': ('The analog labels CInstanceRecord::CNameItem (0x004781c0..0x0047bfc0) and G3D::VARArea '
                      '(0x004781b0) are wrong: every row is RenderDevice.cpp code; 0x004781c0 is an ICF-shared getter '
                      'that the XTP report-record-item vtables also use as slot 63.'),
    'no-rbx-unit': ('No RBX class, Reflection descriptor, static initializer or Roblox-only template instantiation '
                    'lies in the range. The G3D template rows (Array<uint16>, CoordinateFrame, Vector3) are library '
                    'header inlines emitted by RenderDevice.obj; RBX callers (e.g. 0x00552300) only use them.'),
}
exact_rows = []
receipt = {
    'class': 'unit map of the application range 00478000..0047c000 (2008-06): G3D 6.09 RenderDevice.cpp, inactive',
    'result': ('No RBX translation unit and no Roblox-only template instantiation in the range: all %d rows are G3D '
               '6.09 RenderDevice.cpp library code (members, header inlines, ICF-shared getters, one compiler '
               'helper). Nothing is recovered or counted here.' % len(rows)),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'unit_map': UNIT_MAP,
    'row_map': row_map,
    'evidence_checks': checks,
    'notes': NOTES,
    'range_functions': len(rows),
    'range_bytes': sum(FUNCS[a]['size'] for a in rows),
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % ('%08x' % a, ', '.join(v))
                                             for a, v in range_counted.items()],
    'exact_function_rows': exact_rows,
    'library_recipes': ['g3d-6.09', 'g3d-6.09-rbx2008', 'rbxgs-g3d (roc/libs.py)'],
    'scope': 'Inactive map receipt. No native source, no counted row, no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = sorted(set(re.findall(r'"([0-9a-f]{8})"', text)))
assert not bare, bare   # never a quoted bare address of a row not counted here
RECEIPT.write_text(text)
kinds = {}
for a in rows:
    for p in proof[a]:
        kinds[p['kind']] = kinds.get(p['kind'], 0) + 1
print('PASS app-unit478: %d range rows (%d bytes), one library unit (RenderDevice.cpp), evidence %s, '
      '%d counted elsewhere (%s); 0 counted here'
      % (len(rows), receipt['range_bytes'], kinds, len(range_counted),
         ' '.join('%08x' % a for a in range_counted)))
