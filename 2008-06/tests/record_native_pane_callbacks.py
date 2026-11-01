"""Verify typed pane lifecycle, document/selection callbacks and caption text."""
import hashlib
import json
from pathlib import Path
import subprocess
import struct
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/O2', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS',
         '/DBOOST_ALL_NO_LIB', '/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
         '/I' + str(HEADERS), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include'),
         '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]
flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']
methods = []
for name, targets in (
    ('ActiveDocument', (('00405aa0', '?setActiveDocument@@'),)),
    ('ActiveDocViewRefresh', (('00420bd0', '?refresh@ActiveDocView'),)),
    ('CDataModelPropGridUpdate', (('00442900', '?update@CDataModelPropGrid'),)),
    ('CSelectionCaptionUpdate', (('00466940', '?update@CSelectionCaption'), ('00466510', '??1CSelectionCaption'))),
    ('CSelectionCaption', (('00466880', '??0CSelectionCaption'), ('00465de0', '?GetRuntimeClass@CSelectionCaption'),
                           ('00466670', '?filter@CSelectionCaption'), ('00465df0', '?PreCreateWindow@CSelectionCaption'),
                           ('00466680', '?Create@CSelectionCaption'), ('00465e00', '?OnCreate@CSelectionCaption'),
                           ('004666b0', '?onMarshaledEvent@CSelectionCaption'), ('00465e30', '?GetMessageMap@CSelectionCaption'))),
    ('CSelectionCaptionText', (('00465e40', '?updateCaption@CSelectionCaption'),)),
):
    source = CLASSES / (name + '.cpp')
    obj = OUT / ('Native' + name + '.obj')
    compile_flags = flags + ['/c', '/Fo' + str(obj), str(source)]
    if name == 'CSelectionCaptionText':
        code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], OUT)
        assert code == 0, log
        body = (OUT / (name + '.i')).read_text(encoding='utf8', errors='replace')
        for needle in ('\t basic_string()', '~basic_string()', 'const _Elem * c_str() const',
                       'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
            assert body.count(needle) == 1, needle
            body = body.replace(needle, '__declspec(noinline) ' + needle)
        translation = OUT / 'NativeSelectionCaptionText.cpp'
        translation.write_text(body, encoding='utf8')
        compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                         '/Fo' + str(obj), str(translation)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, OUT)
    assert code == 0, log
    functions = match.coff_functions(obj.read_bytes())
    for address, prefix in targets:
        symbol, body, refs = next((n,b,r) for n,b,r in functions if n.startswith(prefix))
        target, target_refs, _ = match.target('2008-06', address)
        assert match.exact_match(target, target_refs, body, refs), (address, symbol)
        methods.append(dict(address=address, symbol=symbol, size=len(body), object=obj.name,
                            relocation_masked_match=True))

# Check data and actual imported parent, not only relocation-masked bodies.
pe = pefile.PE(str(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase

def object_record(obj, prefix):
    sections, symbols, definitions, _ = match._coff_data_index(obj)
    name = next(n for n in definitions if n.startswith(prefix))
    start, section = definitions[name]
    table = sections[section]
    refs = {}
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', obj, table[5] + index * 10)
        if offset >= start:
            assert kind in (6, 20), kind
            refs[offset - start] = symbols[symbol][0]
    return obj[table[4] + start:table[4] + table[3]], refs

obj = (OUT / 'NativeCSelectionCaption.obj').read_bytes()
map_body, map_refs = object_record(obj, '?messageMap@?1??GetThisMessageMap@CSelectionCaption@@')
entry_body, entry_refs = object_record(obj, '?_messageEntries@?1??GetThisMessageMap@CSelectionCaption@@')
assert len(map_body) == 8 and not any(map_body)
assert map_refs[0].startswith('?GetThisMessageMap@CWnd@@')
assert map_refs[4].startswith('?_messageEntries@?1??GetThisMessageMap@CSelectionCaption@@')
assert struct.unpack('<2I', pe.get_data(0x81bb1c - base, 8)) == (0x6a1082, 0x81bb24)
assert len(entry_body) == 48
expected = bytearray(pe.get_data(0x81bb24 - base, 48))
assert struct.unpack_from('<I', expected, 20)[0] == 0x465e00
expected[20:24] = bytes(4)
assert entry_body == expected
assert set(entry_refs) == {20} and entry_refs[20].startswith('?OnCreate@CSelectionCaption@@')
assert pe.get_data(0x6a1082 - base, 2) == bytes.fromhex('ff25')
iat = struct.unpack('<I', pe.get_data(0x6a1084 - base, 4))[0]
pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
assert any(dll.dll.lower() == b'mfc90.dll' and imp.address == iat and imp.ordinal == 4030
           for dll in pe.DIRECTORY_ENTRY_IMPORT for imp in dll.imports)
definition = (ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='replace')
assert '?GetThisMessageMap@CWnd@@' in next(line for line in definition.splitlines() if ' @ 4030 NONAME' in line)
refresh, refresh_refs = object_record((OUT / 'NativeActiveDocViewRefresh.obj').read_bytes(), '?refresh@ActiveDocView@@')
assert set(refresh_refs) == {0x15, 0x26}
assert all(n.startswith('?activeDocDataModel@@3V?$shared_ptr@VDataModel@RBX@@') for n in refresh_refs.values())
assert struct.unpack_from('<I', refresh, 0x15)[0] == 0
assert struct.unpack_from('<I', refresh, 0x26)[0] == 4
original, _, _ = match.target('2008-06', '00420bd0')
assert struct.unpack_from('<I', original, 0x15)[0] == 0x96c25c
assert struct.unpack_from('<I', original, 0x26)[0] == 0x96c260
# Verify selected direct edges and storage addends in activation/creation.
verified_edges = []
for address, checks in (
    ('00405aa0', ((0x5d, '?getDataModel@CRobloxDoc@@', 0x403040),
                  (0xd1, '?getDataModel@CRobloxDoc@@', 0x403040),
                  (0x78, '??4shared_count@detail@boost@@', 0x4025b0),
                  (0x11c, '?reset@?$shared_ptr@VDataModel@RBX@@', 0x456e80),
                  (0x1d9, '?_Inc@const_iterator@?$_Tree@', 0x5e9340))),
    ('00465e00', ((0x4, '?Default@CWnd@@', 0x6a0c68), (0x1a, '?refresh@ActiveDocView@@', 0x420bd0))),
    ('00465df0', ((0x1, '?PreCreateWindow@CWnd@@', 0x6a070a),)),
    ('00466680', ((0x1, '?Create@CStatic@@', 0x6a1490),)),
    ('004666b0', ((0x24, '?updateCaption@CSelectionCaption@@', 0x465e40),
                  (0x35, '??1SelectionChanged@RBX@@', 0x422c60))),
):
    method = next(row for row in methods if row['address'] == address)
    candidate, refs = object_record((OUT / method['object']).read_bytes(), method['symbol'])
    original, _, _ = match.target('2008-06', address)
    for offset, prefix, destination in checks:
        assert refs[offset].startswith(prefix), (address, offset, refs[offset])
        assert original[offset - 1] in (0xe8, 0xe9)
        assert int(address, 16) + offset + 4 + struct.unpack_from('<i', original, offset)[0] == destination
        verified_edges.append(dict(caller=address, offset=offset, symbol=refs[offset], target=hex(destination)))
    if address == '00405aa0':
        for offset, symbol in refs.items():
            if offset >= method['size']:
                continue
            for prefix, storage in (('?activeDocDataModel@@', 0x96c25c),
                                    ('?activeRobloxDoc@@', 0x96c238), ('?activeDocViews@@', 0x96c23c)):
                if symbol.startswith(prefix):
                    assert struct.unpack_from('<I', original, offset)[0] == storage + struct.unpack_from('<I', candidate, offset)[0]

bindings = dict(caption_message_map='0081bb1c', parent='CWnd::GetThisMessageMap (mfc90 ordinal 4030)',
                create_message='WM_CREATE -> 00465e00', refresh_model_storage='0096c25c/0096c260',
                callback_types='00405aa0 gets both current/previous models through 00403040')

paths = [Path(__file__), HEADERS / 'ActiveDocView.h', HEADERS / 'CSelectionCaption.h',
         HEADERS / 'v8tree/Service.h', HEADERS / 'v8datamodel/Selection.h',
         HEADERS / 'v8datamodel/SelectionChanged.h', HEADERS / 'CDataModelPropGrid.h',
         HEADERS / 'util/MarshaledListener.h', HEADERS / 'util/EventDataBase.h',
         HEADERS / 'util/MarshalWindow.h', HEADERS / 'CPropGrid.h', HEADERS / 'SelectionGroup.h']
paths += [CLASSES / (name + '.cpp') for name in ('ActiveDocument', 'ActiveDocViewRefresh', 'CDataModelPropGridUpdate', 'CSelectionCaptionUpdate',
                                               'CSelectionCaption', 'CSelectionCaptionText')]
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, methods=methods, bindings=bindings, verified_edges=verified_edges,
               scope='Inactive typed recovery. Native caption uses AbstractFactoryProduct::getClassName/Name, not the mined fake reflection descriptor. Caption message map/parent ordinal and refresh global references verified. Global storage initialization, remaining bindings, marshal framework and runtime remain open.')
(ROOT / 'work/2008-06/shared-layouts/pane-callbacks-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('Pane callbacks: %d recovered bodies match; no runtime credit' % len(methods))
