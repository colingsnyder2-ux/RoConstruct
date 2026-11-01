"""Verify typed native selection-grid behavior and original helper bindings."""
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
flags = json.loads((ROOT / 'work/2008-06/shared-layouts/property-grid-working-probe.json').read_text())['flags']
jobs = (
    ('CPropGridItem', (('0043a070', '??0Item@CPropGrid'), ('00439600', '?addClass@Item@CPropGrid'))),
    ('CPropGridRebuild', (('004391d0', '?rebuild@CPropGrid'), ('00438010', '??_9CPropGrid@@'))),
    ('CPropGridMap', (('004385f0', '?OnCreate@CPropGrid'), ('00440d20', '?GetMessageMap@CPropGrid'))),
    ('CPropGridRefresh', (('00439d70', '?OnUpdate@CPropGrid'),)),
    ('SelectionGroup', (('00442350', '?add@SelectionGroup'), ('00439660', '?remove@SelectionGroup'))),
    ('CPropGridInstances', (('00439cd0', '?removeInstance@CPropGrid'), ('004423f0', '?addInstance@CPropGrid'))),
    ('CPropGridEvents', (('00439370', '?onEvent@CPropGrid'),)),
    ('CSelectionPropGridEvents', (('00442490', '?onEvent@CSelectionPropGrid'),)),
    ('CSelectionPropGridSelection', (('00442650', '?setSelection@CSelectionPropGrid'),)),
)

def compile_job(job):
    name, targets = job
    obj = OUT / ('Native' + name + '.obj')
    source = CLASSES / (name + '.cpp')
    if name == 'CPropGridRefresh':
        source = OUT / 'NativePropGridRefreshCombined.cpp'
        source.write_text('#include "CPropGrid.h"\n' +
                          '#include "' + (CLASSES / 'DataModelLock.cpp').as_posix() + '"\n' +
                          '#include "' + (CLASSES / 'CPropGridRefresh.cpp').as_posix() + '"\n')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl',
                            flags + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    return obj, targets

methods = []
edges = []
helpers = []
with ThreadPoolExecutor(max_workers=3) as pool:
    results = list(pool.map(compile_job, jobs))
bindings = {'?add@SelectionGroup': 0x442350, '?remove@SelectionGroup': 0x439660,
            '?addInstance@CPropGrid': 0x4423f0, '?removeInstance@CPropGrid': 0x439cd0,
            '?removeListener@': 0x5e5a80, '?addListener@': 0x4218a0,
            '??$shared_from@': 0x618a40, '??4shared_count@': 0x4025b0,
            '?addClass@Item@CPropGrid@@': 0x439600,
            '?sync@Reflection@RBX@@': 0x438060, '??_9CPropGrid@@': 0x438010,
            '?rebuild@CPropGrid': 0x4391d0, '?rootDescriptor@ClassDescriptor@Reflection@RBX@@': 0x40ad20,
            '?doLock@Lock@DataModel@RBX@@': 0x576f00, '??1Lock@DataModel@RBX@@': 0x5773c0,
            '?SetTheme@CXTPPropertyGrid@@': 0x6fc0b0, '?SetImageManager@CXTPPropertyGrid@@': 0x6fa560,
            '?XTPImageManager@@': 0x6c0e80, '?Default@CWnd@@': 0x6a0c68,
            '?do_lock@recursive_mutex@': 0x563090, '?do_unlock@recursive_mutex@': 0x5630e0}
helper_addresses = ('00438d40', '00442100', '00442140', '00420110', '00439480')
for obj, targets in results:
    raw = obj.read_bytes()
    functions = match.coff_functions(raw)
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    for address, prefix in targets:
        name, body, refs = next((n, b, r) for n, b, r in functions if n.startswith(prefix))
        target, target_refs, _ = match.target('2008-06', address)
        assert match.exact_match(target, target_refs, body, refs), (address, name)
        methods.append(dict(address=address, symbol=name, size=len(body), object=obj.name,
                            relocation_masked_match=True))
        start, section = definitions[name]
        table = sections[section]
        for index in range(table[7]):
            offset, si, kind = struct.unpack_from('<IIH', raw, table[5] + index * 10)
            offset -= start
            if not 0 <= offset <= len(body) - 4:
                continue
            symbol = symbols[si][0]
            for beginning, destination in bindings.items():
                if symbol.startswith(beginning):
                    actual = struct.unpack_from('<I', target, offset)[0]
                    if kind == 20:
                        actual = (actual + int(address, 16) + offset + 4) & 0xffffffff
                    assert actual == destination, (address, symbol, hex(actual), hex(destination))
                    edges.append(dict(caller=address, offset=offset, symbol=symbol, target=hex(destination)))
    for address in helper_addresses:
        target, refs, _ = match.target('2008-06', address)
        for name, body, relocations in functions:
            if match.exact_match(target, refs, body, relocations):
                helpers.append(dict(address=address, symbol=name, object=obj.name, size=len(body)))
# Original CPropGrid map routes both messages through the actual native handlers.
original = pefile.PE(str(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = original.OPTIONAL_HEADER.ImageBase
obj = (OUT / 'NativeCPropGridMap.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(obj)
map_symbol = next(n for n in definitions if n.startswith('?messageMap@?1??GetThisMessageMap@CPropGrid@@'))
entries_symbol = next(n for n in definitions if n.startswith('?_messageEntries@?1??GetThisMessageMap@CPropGrid@@'))
for symbol, expected_va, expected_refs in (
    (map_symbol, 0x8145dc, {0: '?GetThisMessageMap@CXTPPropertyGrid@@', 4: '?_messageEntries@?1??GetThisMessageMap@CPropGrid@@'}),
    (entries_symbol, 0x8145e8, {20: '?OnCreate@CPropGrid@@', 44: '?OnUpdate@CPropGrid@@'}),
):
    start, section = definitions[symbol]
    table = sections[section]
    size = 8 if symbol == map_symbol else 72
    candidate = obj[table[4] + start:table[4] + start + size]
    target = bytearray(original.get_data(expected_va - base, size))
    refs = {}
    for index in range(table[7]):
        offset, si, kind = struct.unpack_from('<IIH', obj, table[5] + index * 10)
        if start <= offset < start + size:
            assert kind == 6
            refs[offset - start] = symbols[si][0]
    assert set(refs) == set(expected_refs)
    for offset, prefix in expected_refs.items():
        assert refs[offset].startswith(prefix), refs[offset]
        target[offset:offset + 4] = bytes(4)
    assert candidate == target
assert struct.unpack('<2I', original.get_data(0x8145dc - base, 8)) == (0x6fbf70, 0x8145e8)
assert struct.unpack('<I', original.get_data(0x8137a0 - base, 4))[0] == 0x8802e8
assert struct.unpack('<I', original.get_data(0x8802e8 + 12 - base, 4))[0] == 0x92f58c
assert original.get_string_at_rva(0x92f58c + 8 - base) == b'.?AVItem@CPropGrid@@'
assert struct.unpack('<2I', original.get_data(0x8137a4 - base, 8)) == (0x6a16be, 0x880404)
assert struct.unpack('<I', original.get_data(0x81564c + 90 * 4 - base, 4))[0] == 0x440e30

paths = [Path(__file__), HEADERS / 'SelectionGroup.h', HEADERS / 'CPropGrid.h',
         HEADERS / 'CSelectionPropGrid.h', HEADERS / 'v8tree/Instance.h',
         HEADERS / 'v8datamodel/Selection.h', HEADERS / 'v8datamodel/SelectionChanged.h',
         HEADERS / 'v8tree/PropertyChanged.h', HEADERS / 'v8datamodel/DataModel.h',
         CLASSES / 'DataModelLock.cpp']
paths += [CLASSES / (name + '.cpp') for name, _ in jobs]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): sha(p) for p in paths}, compiler=21022, flags=flags,
               methods=methods, verified_bindings=edges, helpers=helpers,
               compilation_pairing={"CPropGridRefresh": "DataModelLock.cpp definitions visible in same translation unit"},
               objects={obj.name: sha(obj) for obj, _ in results},
               scope='Inactive typed recovery. SelectionGroup is a recovery name. Descriptor-keyed map of '
                     'shared Instance vectors replaces disproven set<string> at CPropGrid+0x218. '
                     'Fourteen body matches, selected bindings, two-message map and original one-slot Item RTTI interface; full helper closure, other containers, '
                     'property-grid behavior, linking and runtime remain open. No game integration credit.')
(ROOT / 'work/2008-06/shared-layouts/selection-grid-working-probe.json').write_text(
    json.dumps(receipt, indent=2) + '\n')
print('PASS: fourteen native grid bodies; typed grouping/items, message map and selected bindings verified')
