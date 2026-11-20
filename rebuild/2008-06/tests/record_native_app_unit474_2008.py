"""Record the unit map of the 2008-06 application range 00474000..00480000 (inactive; no native unit is built).

The whole range is G3D 6.09 GLG3D library code from Roblox's Rendering/g3d tree (recipes g3d-6.09, g3d-6.09-rbx2008,
rbxgs-g3d in roc/libs.py), in this link order: the tail of Texture.cpp, then VARArea.cpp, RenderDevice.cpp (with the
G3D header inlines it emits out of line), one ICF-shared `ret`, TextureManager.cpp and Win32Window.cpp (with the
GWindow.h inline defaults). It continues past 00480000. There is no RBX translation unit and no Roblox-only template
instantiation here, so no row is recovered and none is counted (exact_function_rows is empty). Library code is never
recovered in native-classes.

Every block is checked against the original binary, not the analog server labels (which put 004781b0..0047c0c0 under
CInstanceRecord::CNameItem through an ICF-shared getter):
  * string evidence: the row's bytes hold a DIR32 pointer to that exact NUL-terminated string (__FILE__ names
    .\\glg3dcpp\\X.cpp and messages that occur only in that upstream G3D 6.09 file);
  * vtable evidence: the slot of the vtable (identified by its RTTI complete-object-locator name) holds the row;
  * RTTI evidence: the row's bytes hold a DIR32 pointer to a vtable whose RTTI name is the G3D class;
  * evidence names (offline/evidence.json) of G3D symbols.
It also checks that the blocks tile the range without gaps, and it lists the rows that other receipts count (the
top-level exact_function_rows rule, as in record_native_app_unit660_2008.py).
Writes work/2008-06/shared-layouts/app-unit474-2008-working.json.
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

R = ROOT / 'rebuild/2008-06'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit474-2008-working.json'
RANGE = ('00474000', '00480000')

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
lo, hi = int(RANGE[0], 16), int(RANGE[1], 16)
range_functions = sorted(a for a in FUNCS if lo <= a < hi)

# ---- blocks: [start, end) with the library unit and the evidence checked below ----------------------------------------
BLOCKS = [
    ('g3d-texture', 0x474000, 0x475b50, 'G3D 6.09 GLG3Dcpp/Texture.cpp (starts before 00474000: G3D::Texture vtable '
     '0081e36c slot 0 is 00473ed0)'),
    ('g3d-vararea', 0x475b50, 0x476520, 'G3D 6.09 GLG3Dcpp/VARArea.cpp (VARArea ctor 00475d60 stores vtable 0081e43c; '
     'the deleting dtor 00476130 is its only slot)'),
    ('g3d-renderdevice', 0x476520, 0x47d410, 'G3D 6.09 GLG3Dcpp/RenderDevice.cpp, with the G3D header inlines it '
     'emits out of line (inf, Color4, Matrix3 / CoordinateFrame operators, GLight, Array<uint16>) and the '
     'Table<const TextureFormat*, bool> instantiation'),
    ('icf-ret', 0x47d410, 0x47d420, 'the 1-byte `ret` shared by identical-code folding (GWindow vtable 0081f104 '
     'slot 38 and >100 callers; counted by other receipts)'),
    ('g3d-texturemanager', 0x47d420, 0x47ea20, 'G3D 6.09 GLG3Dcpp/TextureManager.cpp (TextureArgs, '
     'Table<TextureArgs, ReferenceCountedPointer<Texture> >)'),
    ('g3d-win32window', 0x47ea20, hi, 'G3D 6.09 GLG3Dcpp/Win32Window.cpp with the GWindow.h inline defaults; runs '
     'past 00480000 (Table.h remove 004802a0)'),
]
STRINGS = [   # (row, exact string the row points to, block)
    (0x4747f0, '.\\glg3dcpp\\Texture.cpp', 'g3d-texture'),
    (0x4747f0, 'GImage has an unexpected number of channels (%d)', 'g3d-texture'),
    (0x4759ef, '\n**************************\n\nLoading "%s" failed. %s\n', 'g3d-texture'),   # catch funclet of 00475510
    (0x475b50, '.\\glg3dcpp\\VARArea.cpp', 'g3d-vararea'),
    (0x475d60, '.\\glg3dcpp\\VARArea.cpp', 'g3d-vararea'),
    (0x4774f0, 'GL_EXT_blend_minmax', 'g3d-renderdevice'),
    (0x477970, 'GL_ARB_texture_env_combine', 'g3d-renderdevice'),
    (0x478690, '.\\glg3dcpp\\RenderDevice.cpp', 'g3d-renderdevice'),
    (0x478690, 'Drawing to a color buffer is only supported by application-created framebuffers!', 'g3d-renderdevice'),
    (0x478f80, '.\\glg3dcpp\\RenderDevice.cpp', 'g3d-renderdevice'),
    (0x479700, 'All vertex arrays used within a single begin/endIndexedPrimitive block must share the same VARArea.',
     'g3d-renderdevice'),
    (0x479c30, 'VAR Milestone', 'g3d-renderdevice'),
    (0x47b5f0, 'Setting initial rendering state.\n', 'g3d-renderdevice'),
    (0x47c0c0, 'wglSwapIntervalEXT(0);\n', 'g3d-renderdevice'),
    (0x47c3e0, 'Shutting down RenderDevice.', 'g3d-renderdevice'),
    (0x47c530, 'GL_NV_fragment_program', 'g3d-renderdevice'),
    (0x47e1d0, 'Tried to remove a key that was not in the table.', 'g3d-texturemanager'),
    (0x47e450, ' CheckCacheSize is removing %s   \n', 'g3d-texturemanager'),
    (0x47e6e0, 'Texture not found ', 'g3d-texturemanager'),
    (0x47e6e0, '.\\glg3dcpp\\TextureManager.cpp', 'g3d-texturemanager'),
    (0x47fa00, 'This GWindow implementation failed to overwrite runMainLoop even though it requires a main loop.',
     'g3d-win32window'),
    (0x47fbe0, 'Gamma ramp must have at least 256 entries', 'g3d-win32window'),
    (0x47fbe0, '.\\glg3dcpp\\Win32Window.cpp', 'g3d-win32window'),
]
RTTI_REFS = [   # (row, vtable the row stores / reads, RTTI name)
    (0x475d60, 0x81e43c, '.?AVVARArea@G3D@@'),
    (0x47bec0, 0x81ce24, '.?AV?$Table@PBVTextureFormat@G3D@@_N@G3D@@'),
    (0x47d0d0, 0x81ce24, '.?AV?$Table@PBVTextureFormat@G3D@@_N@G3D@@'),
    (0x47d640, 0x819770, '.?AVTextureArgs@TextureManager@G3D@@'),
    (0x47dcc0, 0x819750, '.?AVHashable@G3D@@'),
    (0x47e400, 0x819cd8, '.?AV?$Table@VTextureArgs@TextureManager@G3D@@V?$ReferenceCountedPointer@VTexture@G3D@@@3@@G3D@@'),
    (0x47f860, 0x81f104, '.?AVGWindow@G3D@@'),
    (0x47faf0, 0x81f104, '.?AVGWindow@G3D@@'),
]
VTABLE_SLOTS = {   # vtable: (RTTI name, {slot: row in the range})
    0x81e43c: ('.?AVVARArea@G3D@@', {0: 0x476130}),
    0x819770: ('.?AVTextureArgs@TextureManager@G3D@@', {0: 0x47d420}),
    0x81f104: ('.?AVGWindow@G3D@@', {14: 0x47f8a0, 26: 0x47f900, 27: 0x47f940, 31: 0x47f980, 32: 0x47f9c0,
                                      37: 0x47fa00, 38: 0x47d410, 39: 0x47faf0}),
    # Win32Window: slot order of G3D 6.09 GWindow.h (17 notifyResize, evidence name; 28 inputCapture reads
    # _inputCapture +0xad; 30 mouseVisible reads _mouseVisible +0xac, Win32Window.cpp 707 / 718)
    0x81f52c: ('.?AVWin32Window@G3D@@', {0: 0x47ecc0, 4: 0x47eb60, 6: 0x47ec20, 7: 0x47ec50, 8: 0x47ec80,
                                          9: 0x47fbe0, 10: 0x47ecd0, 13: 0x47ed30, 14: 0x47f8a0, 16: 0x47ecb0,
                                          17: 0x47edd0, 18: 0x47ee50, 19: 0x47ee00, 21: 0x47ef10, 22: 0x47eea0,
                                          23: 0x47ee70, 25: 0x47ef40, 26: 0x47f900, 27: 0x47f940, 28: 0x47edf0,
                                          29: 0x47ed60, 30: 0x47edc0, 31: 0x47f980, 32: 0x47f9c0, 37: 0x47fa00,
                                          38: 0x47f010}),
}
EVIDENCE_NAMES = {   # G3D symbols the offline evidence names in the range
    0x476520: '?inf@G3D@@YAABNXZ',
    0x476580: '??DMatrix3@G3D@@QBE?AVVector3@1@ABV21@@Z',
    0x4765e0: '??9CoordinateFrame@G3D@@QBE_NABV01@@Z',
    0x476640: '??0CoordinateFrame@G3D@@QAE@ABVMatrix3@1@ABVVector3@1@@Z',
    0x476670: '??0CoordinateFrame@G3D@@QAE@ABV01@@Z',
    0x4766a0: '?pointToWorldSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z',
    0x476700: '??DCoordinateFrame@G3D@@QBE?AV01@ABV01@@Z',
    0x4769a0: '??4GLight@G3D@@QAEAAV01@ABV01@@Z',
    0x477c50: '??0GLight@G3D@@QAE@ABV01@@Z',
    0x478230: '??A?$Array@G@G3D@@QAEAAGH@Z',
    0x478240: '?realloc@?$Array@G@G3D@@AAEXH@Z',
    0x4782d0: '??0CoordinateFrame@G3D@@QAE@XZ',
    0x478330: '?inverse@CoordinateFrame@G3D@@QBE?AV12@XZ',
}
# Rows with misleading labels, explained (not counted anywhere by this receipt).
NOTES = {
    '0047edc0': ('evidence name ?getCanCollide@Primitive@RBX@@QBE?B_NXZ is a shape coincidence: the only reference is '
                 'Win32Window vtable 0081f52c slot 30 (G3D::Win32Window::mouseVisible, `mov al,[ecx+0xac]`); no '
                 'call reaches it, so the 2008 Primitive::getCanCollide is never out of line. Library row.'),
    '0047edf0': 'Win32Window vtable slot 28 (G3D::Win32Window::inputCapture, +0xad). Library row.',
    '004781c0': ('ICF-shared `mov eax,[ecx+0x70]; ret` (siblings 004781b0 / 004781d0 / 004781e0 read +0x7c / +0x74 / '
                 '+0x78; callers 00504f50..00504faf and 00703a55..00705e0f) that is also '
                 'slot 63 of the XTP report-record-item vtables (CInstanceRecord::CNameItem 0080f65c, '
                 'CXTPReportRecordItem 008532e4), hence the analog CInstanceRecord::CNameItem labels of '
                 '004781b0..0047c0c0. Library row.'),
    '00475f20': ('counted by render-scene-working.json as ~Array<ReferenceCountedPointer<RenderBase::Chunk>> (an ICF '
                 'body with the G3D Array dtor of this block).'),
    '0047ff20': 'counted by leaves2008-working.json as G3D::Array<bool>::resize.',
    '004782d0': 'counted by humanoid2008-working.json as G3D::CoordinateFrame().',
    '0047d410': 'ICF `ret`, counted by humanoid2008 / network-physics / stats receipts.',
}


def block_of(address):
    hits = [b for b in BLOCKS if b[1] <= address < b[2]]
    assert len(hits) == 1, hex(address)
    return hits[0][0]


# tiling of the range
assert BLOCKS[0][1] == lo and BLOCKS[-1][2] == hi
for a, b in zip(BLOCKS, BLOCKS[1:]):
    assert a[2] == b[1], (a[0], b[0])

checks = []


def points_to(row, text):
    """The row's original bytes hold a DIR32 pointer to the NUL-terminated `text`."""
    size = FUNCS[row]['size']
    body = original.data(row, size)
    want = text.encode('latin-1') + b'\0'
    for i in range(size - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if 0x7c0000 <= v < 0x980000:
            try:
                if original.data(v, len(want)) == want:
                    return v
            except Exception:
                pass
    return None


for row, text, block in STRINGS:
    assert row in FUNCS and block_of(row) == block, (hex(row), block)
    at = points_to(row, text)
    assert at is not None, (hex(row), text)
    checks.append({'row': '%08x' % row, 'block': block, 'kind': 'string', 'at': '%08x' % at, 'text': text})

for row, vtable, rtti in RTTI_REFS:
    assert original.vtable_class(vtable)[0] == rtti, (hex(vtable), original.vtable_class(vtable))
    body = original.data(row, FUNCS[row]['size'])
    assert struct.pack('<I', vtable) in body, (hex(row), hex(vtable))
    checks.append({'row': '%08x' % row, 'block': block_of(row), 'kind': 'rtti-ref', 'vtable': '%08x' % vtable,
                   'rtti': rtti})

for vtable, (rtti, slots) in VTABLE_SLOTS.items():
    assert original.vtable_class(vtable) == (rtti, 0), (hex(vtable), original.vtable_class(vtable))
    for slot, row in slots.items():
        assert d(vtable + 4 * slot) == row, (hex(vtable), slot, hex(d(vtable + 4 * slot)), hex(row))
        if lo <= row < hi:
            assert row in FUNCS
            checks.append({'row': '%08x' % row, 'block': block_of(row), 'kind': 'vtable-slot',
                           'vtable': '%08x' % vtable, 'rtti': rtti, 'slot': slot})

for row, symbol in EVIDENCE_NAMES.items():
    assert names.get(row) == symbol and '@G3D@@' in symbol, (hex(row), names.get(row))
    checks.append({'row': '%08x' % row, 'block': block_of(row), 'kind': 'evidence-name', 'symbol': symbol})
assert names.get(0x47edc0) == '?getCanCollide@Primitive@RBX@@QBE?B_NXZ'
assert names.get(0x47edd0, '') in ('', '?notifyResize@Win32Window@G3D@@UAEXHH@Z')

# no evidence name in the range belongs to an RBX symbol except the shape-coincidence 0047edc0 explained above
rbx_named = sorted('%08x' % a for a in range_functions if '@RBX@@' in names.get(a, ''))
assert rbx_named == ['0047edc0'], rbx_named
# every block has evidence of its own
for name, _, _, _ in BLOCKS:
    assert any(c['block'] == name for c in checks), name


# ---- counting rules (same as record_native_app_unit660_2008.py) ------------------------------------------------------
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
        rows = []
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
per_block = {}
for a in range_functions:
    b = block_of(a)
    e = per_block.setdefault(b, {'rows': 0, 'bytes': 0, 'first': '%08x' % a, 'counted_elsewhere': []})
    e['rows'] += 1
    e['bytes'] += FUNCS[a]['size']
    e['last'] = '%08x' % a
    if '%08x' % a in range_counted:
        e['counted_elsewhere'].append('%08x' % a)

UNIT_MAP = {}
for name, start, end, what in BLOCKS:
    e = per_block.get(name, {'rows': 0, 'bytes': 0})
    UNIT_MAP['%s %08x..%08x' % (name, start, end - 1)] = dict(e, unit=what, library=name != 'icf-ret',
                                                               recovered=False)

exact_rows = []
receipt = {
    'class': 'unit map of the application range 00474000..00480000 (2008-06): G3D 6.09 GLG3D library, inactive',
    'result': ('No RBX translation unit and no Roblox-only template instantiation in the range: every row is G3D '
               'library code (Texture.cpp, VARArea.cpp, RenderDevice.cpp, TextureManager.cpp, Win32Window.cpp and '
               'their header inlines) or an ICF-shared body. Nothing is recovered or counted here.'),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'unit_map': UNIT_MAP,
    'evidence_checks': checks,
    'notes': NOTES,
    'range_functions': len(range_functions),
    'range_bytes': sum(FUNCS[a]['size'] for a in range_functions),
    'range_rows_counted_by_other_receipts': range_counted,
    'exact_function_rows': exact_rows,
    'library_recipes': ['g3d-6.09', 'g3d-6.09-rbx2008', 'rbxgs-g3d (roc/libs.py)'],
    'scope': 'Inactive map receipt. No native source, no counted row, no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit474-2008: %d range rows (%d bytes) in %d blocks, %d evidence checks, %d counted elsewhere (%s); '
      '0 counted here (G3D library range)'
      % (len(range_functions), receipt['range_bytes'], len(BLOCKS), len(checks), len(range_counted),
         ' '.join(range_counted)))
