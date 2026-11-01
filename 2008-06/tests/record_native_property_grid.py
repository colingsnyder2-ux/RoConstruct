"""Compile shared property-grid layouts and lifecycle sources as separate TUs."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import struct

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/c', '/O2', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS',
         '/DBOOST_ALL_NO_LIB', '/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
         '/I' + str(HEADERS), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include'),
         '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]
flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']
fixture = ROOT / 'rebuild/2008-06/tests/NativePropertyGridLayout.cpp'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/FoNativePropertyGridLayout.obj', str(fixture)], OUT)
assert code == 0, log
methods = []
tree_calls = []
for name, targets in (
    ('CPropGrid', (('00442b20', '??0CPropGrid'), ('00442a30', '??1CPropGrid'),
                   ('00437820', '?GetRuntimeClass@CPropGrid'))),
    ('CSelectionPropGrid', (('00430700', '??1CSelectionPropGrid'),
                            ('00437830', '?GetRuntimeClass@CSelectionPropGrid'))),
    ('CDataModelPropGrid', (('00431040', '??0CDataModelPropGrid'), ('004310f0', '??1CDataModelPropGrid'),
                            ('00437840', '?GetRuntimeClass@CDataModelPropGrid'))),
):
    source = CLASSES / (name + '.cpp')
    obj = OUT / ('Native' + name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    functions = match.coff_functions(obj.read_bytes())
    if name == 'CPropGrid':
        data = obj.read_bytes()
        sections, symbols, definitions, _ = match._coff_data_index(data)
        ctor = next(n for n in definitions if n.startswith('??0CPropGrid'))
        start, index = definitions[ctor]
        section = sections[index]
        refs = {}
        for i in range(section[7]):
            offset, symbol, kind = struct.unpack_from('<IIH', data, section[5] + i * 10)
            if start <= offset < start + 258:
                refs[offset - start] = symbols[symbol][0]
        native, _, _ = match.target('2008-06', '00442b20')
        for offset, address in ((0x8d, 0x446110), (0xa7, 0x446110), (0xcd, 0x64b2a0), (0xe7, 0x4d8680)):
            assert 0x442b20 + offset + 4 + struct.unpack_from('<i', native, offset)[0] == address
            symbol = refs[offset]
            body, relocations = next((b,r) for n,b,r in functions if n == symbol)
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
            assert match.exact_match(target, target_refs, body, relocations), symbol
            tree_calls.append(dict(offset=offset, address=hex(address), symbol=symbol, size=len(body)))
    for address, prefix in targets:
        symbol, data, refs = next((n,b,r) for n,b,r in functions if n.startswith(prefix))
        target, target_refs, _ = match.target('2008-06', address)
        assert match.exact_match(target, target_refs, data, refs), (address, symbol)
        methods.append(dict(address=address, symbol=symbol, size=len(data), object=obj.name,
                            relocation_masked_match=True))

paths = [Path(__file__), fixture, HEADERS / 'CMainFrame.h']
for name in ('CPropGrid', 'CSelectionPropGrid', 'CDataModelPropGrid'):
    paths += [HEADERS / (name + '.h'), CLASSES / (name + '.cpp')]
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, methods=methods, verified_tree_calls=tree_calls,
               layouts=dict(CPropGrid=0x238, CSelectionPropGrid=0x244, CDataModelPropGrid=0x248),
               scope='Inactive separate-TU lifecycle/layout evidence. Pointer-map key/value identities, full message/virtual ABI and selection/property behavior remain open; no runtime credit.')
(ROOT / 'work/2008-06/shared-layouts/property-grid-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('Property grids: eight separate-TU body matches; layouts/offsets verified')
