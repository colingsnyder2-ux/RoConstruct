"""Record the unit map of the 2008-06 application range 0069c000..006a0000 (inactive; no native unit is built).

The range holds three groups and no unrecovered Roblox code:
  * the tail of the exe-local Ogre::RbxSceneManager fork unit (RbxSceneManager.cpp, which starts at 0x0068b600):
    26 code rows 0x0069c5b0..0x0069eb1d (addRenderQueueListener .. ??_GRbxSceneManager), every one already counted by
    ogre-scene-manager-working.json (tests/record_native_ogre_scene_manager.py);
  * two DirectInput 8 data blocks the function list carries as `kind: data` rows: the DIOBJECTDATAFORMAT arrays of
    c_dfDIMouse2 (11 objects, 0x0069eb20) and c_dfDIKeyboard (256 objects, 0x0069ebd0), statically linked from the
    DirectX SDK dinput8.lib. Each is the rgodf of a DIDATAFORMAT in .rdata (dwSize 0x18, dwObjSize 0x10, DIDF_RELAXIS,
    data size 0x14 / 0x100, 11 / 256 objects) that DxUserInput passes to SetDataFormat. These are library data,
    not functions;
  * 179 linker import thunks (`jmp dword ptr [IAT]`, 6 bytes each) from the import libraries of rgmain.dll (Ogre
    1.4.5), fmodex.dll and dinput8.dll. They have no source; other receipts bind some of them as verified call or
    vtable-slot targets (support only, never counted).
Nothing in the range is an RBX class, a Reflection descriptor, a static initializer or a Roblox-only template
instantiation that no receipt counts, so nothing is built here and exact_function_rows is empty.

Checks, all against the original binary bytes: rows are disjoint and the gaps between them are int3/zero padding; the
26 code rows carry ogre-scene-manager's exact symbols and are counted there (top-level exact_function_rows rule, as in
record_native_app_unit474_2008.py); the data blocks decode as DIOBJECTDATAFORMAT arrays whose GUID pointers point at
the DirectInput GUID values (GUID_XAxis/YAxis/ZAxis, GUID_Key) and whose DIDATAFORMAT headers are referenced only by
DxUserInput rows; every thunk is ff 25 + an IAT slot of a named import.
Addresses of rows not counted here are written as 0x-prefixed or 'ADDR counted by RECEIPT' text, never as quoted bare
addresses (local_backpack / viewnew_brick_build / viewnew_part_mesh read any quoted bare address in a receipt as
counted there).
Writes work/2008-06/shared-layouts/app-unit69c-working.json.
"""
import glob
import json
import re
import struct
import sys
import uuid
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit69c-working.json'
LO, HI = 0x69c000, 0x6a0000
H = lambda a: '0x%08x' % a
SCENE_RECEIPT = 'ogre-scene-manager-working.json'

original = nb.Original()
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
rows = sorted(a for a in FUNCS if LO <= a < HI)
size = lambda a: FUNCS[a]['size']
u32 = lambda a: struct.unpack('<I', original.data(a, 4))[0]

# ---- row boundaries and padding ---------------------------------------------------------------------------------------
for a, b in zip(rows, rows[1:]):
    assert a + size(a) <= b, H(a)
    gap = original.data(a + size(a), b - a - size(a))
    assert set(gap) <= {0xcc, 0x00}, (H(a), gap.hex())
prev = max(a for a in FUNCS if a < LO)
assert prev + size(prev) <= rows[0] and set(original.data(prev + size(prev), rows[0] - prev - size(prev))) <= {0xcc}
nxt = min(a for a in FUNCS if a >= HI)

code_rows = [a for a in rows if FUNCS[a]['kind'] in ('code', 'gen')]   # 'gen': compiler-generated ??_G
data_rows = [a for a in rows if FUNCS[a]['kind'] == 'data']
thunk_rows = [a for a in rows if FUNCS[a]['kind'] == 'thunk']
assert len(code_rows) + len(data_rows) + len(thunk_rows) == len(rows)
assert max(code_rows) < min(data_rows) and max(data_rows) < min(thunk_rows)


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
assert sorted(range_counted) == code_rows, sorted(set(code_rows) ^ set(range_counted))
assert all(v == [SCENE_RECEIPT] for v in range_counted.values()), {H(a): v for a, v in range_counted.items()}

# ---- RbxSceneManager tail: symbols from the counting receipt ----------------------------------------------------------
scene = json.loads((ROOT / 'work/2008-06/shared-layouts' / SCENE_RECEIPT).read_text())
scene_sym = {int(r['address'], 16): r['symbol'] for r in scene['rows'] if r.get('exact') is True}
code_map = []
for a in code_rows:
    sym = scene_sym[a]
    assert '@Ogre@@' in sym, (H(a), sym)
    assert 'RbxSceneManager@Ogre@@' in sym or sym.startswith('??$'), (H(a), sym)   # members or std templates
    code_map.append({'row': H(a), 'size': size(a), 'symbol': sym, 'counted_by': SCENE_RECEIPT})
assert scene_sym[0x69eb00] == '??_GRbxSceneManager@Ogre@@UAEPAXI@Z'   # the unit's last row (scalar deleting dtor)


# ---- DirectInput data blocks ------------------------------------------------------------------------------------------
def guid(a):
    return str(uuid.UUID(bytes_le=original.data(a, 16))).upper()


DI_GUIDS = {'A36D02E0-C9F3-11CF-BFC7-444553540000': 'GUID_XAxis', 'A36D02E1-C9F3-11CF-BFC7-444553540000': 'GUID_YAxis',
            'A36D02E2-C9F3-11CF-BFC7-444553540000': 'GUID_ZAxis', '55728220-D33C-11CF-BFC7-444553540000': 'GUID_Key'}
# (rgodf row, data format name, dwDataSize, dwNumObjs, DIDATAFORMAT address, DxUserInput row referencing it)
FORMATS = [(0x69eb20, 'c_dfDIMouse2', 0x14, 11, 0x84ff0c, 0x467550),
           (0x69ebd0, 'c_dfDIKeyboard', 0x100, 256, 0x850114, 0x4675e0)]
assert [f[0] for f in FORMATS] == data_rows
data_map = []
for rgodf, name, data_size, count, fmt, user in FORMATS:
    assert size(rgodf) == 16 * count, (H(rgodf), size(rgodf))
    hdr = struct.unpack('<6I', original.data(fmt, 24))
    assert hdr == (0x18, 0x10, 2, data_size, count, rgodf), [hex(x) for x in hdr]   # DIDF_RELAXIS
    refs = sorted(a for a, r in FUNCS.items() if hex(fmt) in (r.get('data_refs') or []))
    assert refs == [user] and FUNCS[user]['unit'] == 'DxUserInput', ([H(a) for a in refs], FUNCS[user]['unit'])
    guids = {}
    for i in range(count):
        pguid, ofs, typ, flags = struct.unpack('<4I', original.data(rgodf + 16 * i, 16))
        if pguid:
            g = DI_GUIDS[guid(pguid)]
            guids[g] = H(pguid)
        if name == 'c_dfDIKeyboard':
            # { &GUID_Key, i, 0x8000000C | DIDFT_MAKEINSTANCE(i), 0 }
            assert pguid and DI_GUIDS[guid(pguid)] == 'GUID_Key' and ofs == i and typ == 0x8000000c | i << 8 \
                and flags == 0, (i, hex(typ))
        else:
            # X, Y, Z axes at 0/4/8 (Z DIDFT_OPTIONAL) then 8 buttons at 0x0c..0x13 with no GUID (buttons 2..7 optional)
            want = [('GUID_XAxis', 0, 0xffff03), ('GUID_YAxis', 4, 0xffff03), ('GUID_ZAxis', 8, 0x80ffff03)]
            if i < 3:
                assert DI_GUIDS[guid(pguid)] == want[i][0] and ofs == want[i][1] and typ == want[i][2] \
                    and flags == 0, (i, hex(typ))
            else:
                assert pguid == 0 and ofs == 0xc + i - 3 and typ == (0x00ffff0c if i < 5 else 0x80ffff0c) and flags == 0, (i, hex(typ))
    data_map.append({'row': H(rgodf), 'size': size(rgodf), 'object': '%s rgodf (DIOBJECTDATAFORMAT[%d])' % (name, count),
                     'didataformat': H(fmt), 'didataformat_fields': 'dwSize 0x18, dwObjSize 0x10, DIDF_RELAXIS, '
                     'dwDataSize %s, dwNumObjs %d' % (hex(data_size), count),
                     'referenced_by': 'DxUserInput row %s (SetDataFormat)' % H(user), 'guids': guids,
                     'library': 'DirectX SDK dinput8.lib (static data)', 'counted_by': []})

# ---- import thunks ----------------------------------------------------------------------------------------------------
support = {}
for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
    if Path(path).name == RECEIPT.name:
        continue
    text = Path(path).read_text(errors='replace')
    for a in thunk_rows:
        if '%08x' % a in text or H(a) in text:
            support.setdefault(a, set()).add(Path(path).name)
dlls = {}
thunk_map = []
for a in thunk_rows:
    raw = original.data(a, 6)
    assert size(a) == 6 and raw[:2] == b'\xff\x25', H(a)
    slot = struct.unpack_from('<I', raw, 2)[0]
    imp = original.imports.get(slot)
    assert imp and imp[2], (H(a), H(slot))
    dll = imp[0].lower()
    assert dll in ('rgmain.dll', 'fmodex.dll', 'dinput8.dll'), (H(a), dll)
    dlls[dll] = dlls.get(dll, 0) + 1
    thunk_map.append({'row': H(a), 'iat': H(slot), 'import': '%s!%s' % (dll, imp[2]),
                      'support_reference_in': sorted(support.get(a, []))})
assert nxt == thunk_rows[-1] + 6 and FUNCS[nxt]['kind'] == 'thunk'   # the thunk block continues past 0x006a0000

UNIT_MAP = {
    'ogre-rbx-scene-manager-tail %s..%s' % (H(code_rows[0]), H(code_rows[-1] + size(code_rows[-1]) - 1)): {
        'rows': len(code_rows),
        'unit': 'Ogre::RbxSceneManager fork, RbxSceneManager.cpp (exe-local Ogre 1.4.5 fork; the unit starts at '
                '0x0068b600, below the range)',
        'library': False, 'recovered': True,
        'counted_elsewhere': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    },
    'dinput8-data %s..%s' % (H(data_rows[0]), H(data_rows[-1] + size(data_rows[-1]) - 1)): {
        'rows': len(data_rows),
        'unit': 'DirectX SDK dinput8.lib static data: c_dfDIMouse2 / c_dfDIKeyboard object arrays',
        'library': True, 'recovered': False,
    },
    'import-thunks %s..%s' % (H(thunk_rows[0]), H(thunk_rows[-1] + 5)): {
        'rows': len(thunk_rows),
        'unit': 'linker import thunks from the import libraries (continues past 0x006a0000 at %s)' % H(nxt),
        'dlls': dlls,
        'library': True, 'recovered': False,
        'support_referenced_by_other_receipts': sum(1 for a in thunk_rows if a in support),
    },
}
NOTES = {
    'analog-labels': ('The analysis labels the data and thunk rows Ogre::RbxSceneManager / Ogre::RbxEntity by '
                      'proximity only: the data rows are dinput8.lib DIOBJECTDATAFORMAT arrays (the analysis kind is '
                      '"data") and the thunks are import stubs.'),
    'no-rbx-unit': ('No RBX class, Reflection descriptor, static initializer or Roblox-only template instantiation lies '
                    'in the range. The only Roblox code is the RbxSceneManager fork tail, fully counted by %s.'
                    % SCENE_RECEIPT),
    'thunk-support': ('Import thunks named in other receipts are verified call / vtable-slot targets there (support '
                      'only); no receipt counts a thunk and none is counted here.'),
}
receipt = {
    'class': 'unit map of the application range 0069c000..006a0000 (2008-06): RbxSceneManager tail, dinput8 data, '
             'import thunks; inactive',
    'result': ('No RBX translation unit to recover: the %d RbxSceneManager rows are already counted by %s, the %d '
               'data rows are dinput8.lib c_dfDIMouse2 / c_dfDIKeyboard object arrays and the %d rows are linker '
               'import thunks (%s). Nothing is recovered or counted here.'
               % (len(code_rows), SCENE_RECEIPT, len(data_rows), len(thunk_rows),
                  ', '.join('%s %d' % kv for kv in sorted(dlls.items())))),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'unit_map': UNIT_MAP,
    'row_map': {'rbx_scene_manager_tail': code_map, 'dinput8_data': data_map, 'import_thunks': thunk_map},
    'notes': NOTES,
    'range_functions': len(rows),
    'range_bytes': sum(size(a) for a in rows),
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'exact_function_rows': [],
    'scope': 'Inactive map receipt. No native source, no counted row, no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = sorted(set(re.findall(r'"([0-9a-f]{8})"', text)))
assert not bare, bare   # never a quoted bare address of a row not counted here
RECEIPT.write_text(text)
print('PASS app-unit69c: %d range rows (%d bytes): %d RbxSceneManager rows counted by %s, %d dinput8 data rows, '
      '%d import thunks (%s); 0 counted here'
      % (len(rows), receipt['range_bytes'], len(code_rows), SCENE_RECEIPT, len(data_rows), len(thunk_rows),
         ', '.join('%s %d' % kv for kv in sorted(dlls.items()))))
