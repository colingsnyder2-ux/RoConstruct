"""Verify inactive typed frame-pane marshalling layouts and recovered bodies."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import struct
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
TESTS = ROOT / 'rebuild/2008-06/tests'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/c', '/O2', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS',
         '/DBOOST_ALL_NO_LIB', '/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
         '/I' + str(HEADERS), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include'),
         '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]
flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']

methods = []
for name, source, fixture, targets in (
    ('MarshalWindow', CLASSES / 'CMarshalWindow.cpp', TESTS / 'NativeMarshalWindowLayout.cpp', (
        ('00432c50', '??0CMarshalWindow'), ('00432950', '?post@CMarshalWindow'),
        ('004328c0', '??0CCriticalSection@ATL'), ('00432a70', '?OnFinalMessage@CMarshalWindow'),
        ('00432970', '?OnDestroy@CMarshalWindow'), ('00432a90', '?ProcessWindowMessage@CMarshalWindow'),
        ('0041a400', '?GetWindowProc@?$CWindowImplBaseT'),
        ('00432b50', '?Create@?$CWindowImpl@VCMarshalWindow'), ('00432b10', '??_GCMarshalWindow'))),
    ('MarshaledListener', TESTS / 'NativeMarshaledListener.cpp', None, (
        ('004661e0', '??0?$MarshaledListener'), ('004663c0', '??1?$MarshaledListener'),
        ('004211b0', '?onEvent@?$MarshaledListener'), ('00466440', '?marshal@?$MarshaledListener'),
        ('004574b0', '?remove@?$MarshaledListener'), ('00457710', '?detach@?$MarshaledListener'),
        ('00466700', '?marshal@?$FilteredListener'), ('00466260', '??0EventData@?$MarshaledListener'),
        ('00466310', '??1EventData@?$MarshaledListener'), ('00421530', '?execute@EventData@?$MarshaledListener'),
        ('004571d0', '?setSource@EventData@?$MarshaledListener'), ('00421110', '??_GEventDataBase'),
        ('00422c60', '??1SelectionChanged'))),
    ('MarshalWindowRegistry', CLASSES / 'MarshalWindowRegistry.cpp', None, (
        ('00432ce0', '?acquireMarshalWindow'), ('00432bd0', '?releaseMarshalWindow'))),
    ('SelectionCaption', CLASSES / 'CSelectionCaption.cpp', TESTS / 'NativeSelectionCaptionLayout.cpp', (
        ('00466880', '??0CSelectionCaption'), ('00465de0', '?GetRuntimeClass@CSelectionCaption'),
        ('00466670', '?filter@CSelectionCaption'))),
):
    translation = OUT / (name + 'LayoutProbe.cpp')
    body = '#include "' + source.as_posix() + '"\n'
    if fixture:
        body += '#include "' + fixture.as_posix() + '"\n'
    translation.write_text(body, encoding='utf8')
    obj = OUT / ('Native' + name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(translation)], OUT)
    assert code == 0, log
    functions = match.coff_functions(obj.read_bytes())
    for address, prefix in targets:
        symbol, data, refs = next((n,b,r) for n,b,r in functions if n.startswith(prefix))
        target, target_refs, _ = match.target('2008-06', address)
        exact = match.exact_match(target, target_refs, data, refs)
        assert exact, (address, symbol, len(data), len(target))
        methods.append(dict(address=address, symbol=symbol, size=len(data), target_size=len(target),
                            object=obj.name, relocation_masked_match=exact))

# Validate selected bindings separately from relocation-masked bodies.
pe = pefile.PE(str(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
imports = {item.address: item.name for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports}
edges = []
storage = {'?marshalWindows@RBX@@': 0x96d15c, '?marshalRegistryLock@RBX@@': 0x96d17c}
callees = {'?acquireMarshalWindow@': 0x432ce0, '?releaseMarshalWindow@': 0x432bd0,
           '??0CMarshalWindow@': 0x432c50, '?post@CMarshalWindow@': 0x432950,
           '?remove@?$MarshaledListener': 0x4574b0, '?detach@?$MarshaledListener': 0x457710,
           '??0EventData@?$MarshaledListener': 0x466260, '?setSource@EventData@?$MarshaledListener': 0x4571d0,
           '??1SelectionChanged@': 0x422c60, '?marshal@?$MarshaledListener': 0x466440,
           '?find@?$_Tree@': 0x451600, '??A?$map@': 0x5644a0, '?erase@?$_Tree@': 0x405ce0}
for row in methods:
    obj = (OUT / row['object']).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(obj)
    start, section = definitions[row['symbol']]
    table = sections[section]
    candidate = obj[table[4] + start:table[4] + start + row['size']]
    target, _, _ = match.target('2008-06', row['address'])
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', obj, table[5] + index * 10)
        offset -= start
        if not 0 <= offset <= min(row['size'], len(target)) - 4:
            continue
        name = symbols[symbol][0]
        for prefix, address in storage.items():
            if name.startswith(prefix):
                assert kind == 6
                assert struct.unpack_from('<I', target, offset)[0] == address + struct.unpack_from('<I', candidate, offset)[0]
                edges.append(dict(caller=row['address'], offset=offset, symbol=name, storage=hex(address)))
        if name.startswith('__imp__') and row['relocation_masked_match']:
            original_iat = struct.unpack_from('<I', target, offset)[0]
            expected = name[len('__imp__'):].split('@')[0].encode()
            assert imports.get(original_iat) == expected, (row['address'], name, imports.get(original_iat))
        if row['relocation_masked_match']:
            for prefix, address in callees.items():
                if name.startswith(prefix) and kind == 20:
                    assert int(row['address'], 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0] == address, (row['address'], name)
                    edges.append(dict(caller=row['address'], offset=offset, symbol=name, target=hex(address)))
assert struct.unpack('<2I', pe.get_data(0x80f860 - base, 8)) == (0x6a16be, 0x421110)
assert struct.unpack('<2I', pe.get_data(0x81bb6c - base, 8)) == (0x421530, 0x4663a0)

paths = [Path(__file__), CLASSES / 'CMarshalWindow.cpp', CLASSES / 'CSelectionCaption.cpp', CLASSES / 'MarshalWindowRegistry.cpp',
         HEADERS / 'v8datamodel/SelectionChanged.h',
         HEADERS / 'util/MarshalWindow.h', HEADERS / 'util/MarshaledListener.h',
         HEADERS / 'util/EventDataBase.h', HEADERS / 'CSelectionCaption.h', HEADERS / 'ActiveDocView.h',
         TESTS / 'NativeMarshalWindowLayout.cpp', TESTS / 'NativeMarshaledListener.cpp',
         TESTS / 'NativeSelectionCaptionLayout.cpp']
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, methods=methods, verified_bindings=edges,
               layouts=dict(CMarshalWindow=0x44, EventDataBase=4, EventData=0x20, MarshaledListener=0x24,
                            FilteredListener=0x24, CSelectionCaption=0x1c8),
               scope='Inactive recovery. Typed lifecycle/dispatch/queue/filter and window-registry recovery. Old EventDataBase 0xc/weak-pointer hypothesis disproven by destructor 00421110; source strong owner is in derived EventData. All selected bodies match: correcting EventDataBase lifetime also resolves OnDestroy, and exposing the real remove body resolves EventData destructor unwind states. Selected call/import/storage bindings verified separately. Global initialization, remaining data/virtual ABI and runtime integration remain open.')
(ROOT / 'work/2008-06/shared-layouts/frame-marshalling-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('Frame marshalling: %d/%d body matches; six typed layouts verified' %
      (sum(m['relocation_masked_match'] for m in methods),len(methods)))
