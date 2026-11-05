"""Check MainLogManager's original RTTI bases and candidate x86 offsets."""
import hashlib
import json
import os
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import struct
import subprocess
import sys
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

base = ROOT / 'rebuild/2008-06'
out = base / 'out/native-main-log-abi'
out.mkdir(parents=True, exist_ok=True)
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
jobs = [
    ('tests/NativeMainLogLayout.cpp', []),
    ('tests/NativeAppEntryLinkProbe.cpp', ['0044c3d0=??0CRobloxApp', '0044c440=??1CRobloxApp',
     '0044d810=?InitInstance@CRobloxApp']),
    ('native-classes/ApplicationExceptionLog.cpp', ['00428850=?ReportException@LogManager']),
    ('native-classes/MainLogProvider.cpp', ['0042a5c0=?provideLog@MainLogManager']),
    ('native-classes/LogManagerGet.cpp', ['00427950=?getLog@LogManager']),
    ('native-classes/LogManagerState.cpp', []),
    ('native-classes/ThreadLogFactory.cpp', ['0042a4f0=?currentThreadLogManager',
     '0042a490=?initializeThreadLogs', '00428cf0=??_GLogManager', '00429300=??_GThreadLogManager']),
    ('native-classes/ThreadLogPath.cpp', ['00427890=?getLogPath@ThreadLogManager']),
    ('native-classes/MainLogManagerState.cpp', []),
    ('native-classes/ThreadName.cpp', ['00596e60=?currentThreadName']),
    ('native-classes/ThreadNameStorage.cpp', ['00596d50=?init_foo@boost_detail@RBX']),
    ('native-classes/ThreadNameState.cpp', []),
]
assert len({Path(source).stem for source, _ in jobs}) == len(jobs)
def compile_job(job):
    source, checks = job
    run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'), source] + checks,
                         env=env, cwd=ROOT, capture_output=True, text=True)
    assert run.returncode == 0 and '%d/%d exact' % (len(checks), len(checks)) in run.stdout, run.stdout + run.stderr

with ThreadPoolExecutor(max_workers=3) as pool:
    list(pool.map(compile_job, jobs))

raw = (out / 'CheckNativeMainLogLayout.obj').read_bytes()
bodies = {name: body for name, body, refs in match.coff_functions(raw)}
assert next(body for name, body in bodies.items() if name.startswith('?asProvider@@')).hex() == '8b442404c3'
assert next(body for name, body in bodies.items() if name.startswith('?asLogManager@@')).hex() == '8b44240485c0740483c004c333c0c3'

pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
u32 = lambda address: struct.unpack('<I', pe.get_data(address - image, 4))[0]
def hierarchy(vtable):
    locator = u32(vtable - 4)
    descriptor = u32(locator + 16)
    count, array = u32(descriptor + 8), u32(descriptor + 12)
    result = []
    for index in range(count):
        entry = u32(array + 4 * index)
        name = pe.get_string_at_rva(u32(entry) - image + 8).decode('ascii')
        offset = struct.unpack('<i', pe.get_data(entry - image + 8, 4))[0]
        result.append((name, offset))
    return u32(locator + 4), result

expected = [('.?AVMainLogManager@@', 0), ('.?AVILogProvider@RBX@@', 0), ('.?AVLogManager@@', 4)]
assert hierarchy(0x8104cc) == (0, expected)
assert hierarchy(0x8104c0) == (4, expected)
assert hierarchy(0x81030c) == (0, [('.?AVLogManager@@', 0)])
assert hierarchy(0x8104b4) == (0, [('.?AVThreadLogManager@@', 0), ('.?AVLogManager@@', 0)])
assert u32(0x8104cc) == 0x42a5c0
assert u32(0x8104c0) == 0x428e40
assert u32(0x81030c + 4) == 0x6a16be
assert u32(0x8104c0 + 4) == 0x427f30
assert u32(0x8104b4 + 4) == 0x427890

raw = (out / 'CheckMainLogProvider.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?provideLog@MainLogManager'))
start, section = definitions[name]
table = sections[section]
refs = {location - start: symbols[index][0] for location, index, kind in
        (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7]))}
assert refs[0x13].startswith('?getLog@LogManager@@')
assert refs[0x18].startswith('?currentThreadLogManager@@')
assert refs[0x20].startswith('?getLog@LogManager@@')
original, _, _ = match.target('2008-06', '0042a5c0')
for displacement, target in ((0x13, 0x427950), (0x18, 0x42a4f0), (0x20, 0x427950)):
    assert 0x42a5c0 + displacement + 4 + struct.unpack_from('<i', original, displacement)[0] == target

raw = (out / 'CheckLogManagerGet.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?getLog@LogManager'))
start, section = definitions[name]
table = sections[section]
refs = {location - start: symbols[index][0] for location, index, kind in
        (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7]))}
original, _, _ = match.target('2008-06', '00427950')
global_offset = original.find(struct.pack('<I', 0x92e486))
assert global_offset >= 0 and refs[global_offset] == '?loggingEnabled@@3_NA'
constructor_offset = 0x4279e2 - 0x427950 + 1
assert refs[constructor_offset].startswith('??0Log@RBX@@')
assert 0x427950 + constructor_offset + 4 + struct.unpack_from('<i', original, constructor_offset)[0] == 0x5a6da0

raw = (out / 'CheckLogManagerState.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
offset, section = definitions['?loggingEnabled@@3_NA']
assert raw[sections[section][4] + offset] == 1
assert pe.get_data(0x92e486 - image, 1) == b'\x01'
references = []
needle = struct.pack('<I', 0x92e486)
for section in pe.sections:
    if not section.Characteristics & 0x20000000:
        continue
    data = section.get_data()
    position = data.find(needle)
    while position >= 0:
        references.append(image + section.VirtualAddress + position)
        position = data.find(needle, position + 1)
assert references == [0x427974], references

raw = (out / 'CheckThreadLogPath.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?getLogPath@ThreadLogManager'))
start, section = definitions[name]
table = sections[section]
refs = {location - start: symbols[index][0] for location, index, kind in
        (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7]))}
original, _, _ = match.target('2008-06', '00427890')
global_offset = original.find(struct.pack('<I', 0x96d0fc))
assert global_offset >= 0 and refs[global_offset] == '?mainLogManager@@3PAVMainLogManager@@A'
assert pe.get_memory_mapped_image()[0x96d0fc - image:0x96d100 - image] == b'\0' * 4
raw = (out / 'CheckMainLogManagerState.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
offset, section = definitions['?mainLogManager@@3PAVMainLogManager@@A']
assert sections[section][0].startswith(b'.bss') and sections[section][3] >= offset + 4
assert pe.get_string_at_rva(0x810314 - image) == b'_%s_%d'

raw = (out / 'CheckThreadName.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?currentThreadName@@'))
start, section = definitions[name]
table = sections[section]
refs = {location - start: symbols[index][0] for location, index, kind in
        (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7]))}
original, _, _ = match.target('2008-06', '00596e60')
for address, symbol in ((0x975c94, '?once_init_foo@boost_detail@RBX@@'),
                        (0x975c90, '?foo@boost_detail@RBX@@'),
                        (0x949c60, '?defaultThreadName@@')):
    offset = original.find(struct.pack('<I', address))
    assert offset >= 0 and refs[offset].startswith(symbol)
assert pe.get_string_at_rva(u32(0x949c60) - image) == b'rbx_thread'
raw = (out / 'CheckThreadNameState.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
offset, section = definitions['?defaultThreadName@@3PBDB']
table = sections[section]
target = next(symbols[index][0] for location, index, kind in
              (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])) if location == offset)
literal_offset, literal_section = definitions[target]
assert raw[sections[literal_section][4] + literal_offset:][:11] == b'rbx_thread\0'

paths = [base / source for source, _ in jobs] + [base / 'native-headers/CRobloxApp.h',
         base / 'native-headers/util/Log.h', base / 'native-classes/CRobloxApp.cpp', Path(__file__).resolve()]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'sources': {str(p.relative_to(ROOT)): sha(p) for p in paths},
           'objects': {str(p.relative_to(ROOT)): sha(p) for p in out.glob('Check*.obj')},
           'bases': expected, 'original_vtables': ['0x8104cc', '0x8104c0', '0x81030c', '0x8104b4'],
           'scope': 'RTTI bases, offsets, App callers, original vtable targets and initial logging flag; indirect writes, lifetime and runtime remain unproven.'}
(ROOT / 'work/2008-06/shared-layouts/main-log-abi-current.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS MainLogManager RTTI bases, subobject offsets and App caller bodies')
