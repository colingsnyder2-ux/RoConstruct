"""Audit native Log layout and selected code/data bindings; not a runtime gate."""
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

BASE = ROOT / 'rebuild/2008-06'
OUT = BASE / 'out/native-log-audit'
OUT.mkdir(parents=True, exist_ok=True)
jobs = [
    ('tests/NativeLogLayout.cpp', []),
    ('native-classes/LogLifetime.cpp', ['005a6da0=??0Log@RBX', '005a6e60=??1Log@RBX',
     '005a6d10=?logTimeStamp', '005a6fb0=??_GLog@RBX']),
    ('native-classes/LogWriteEntry.cpp', ['005a6ef0=?writeEntry@Log@RBX']),
    ('native-classes/LogFormatTime.cpp', ['005a6c60=?formatTime@Log@RBX']),
    ('native-classes/LogFormatMemory.cpp', ['005a6bc0=?formatMem@Log@RBX']),
]

def compile_job(job):
    source, checks = job
    env = dict(os.environ, NATIVE_CHECK_OUT=str(OUT))
    run = subprocess.run([sys.executable, str(BASE / 'tests/check_native_class.py'), source] + checks,
                         cwd=ROOT, capture_output=True, text=True, env=env)
    assert run.returncode == 0 and ('%d/%d exact' % (len(checks), len(checks))) in run.stdout, run.stdout + run.stderr
    return run.stdout

with ThreadPoolExecutor(max_workers=3) as pool:
    results = list(pool.map(compile_job, jobs))

pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
u32 = lambda address: struct.unpack('<I', pe.get_data(address - base, 4))[0]
string = lambda address: pe.get_string_at_rva(address - base)
vtable = 0x8341b8
assert string(u32(u32(vtable - 4) + 12) + 8) == b'.?AVLog@RBX@@'
assert u32(vtable) == 0x5a6fb0
prefixes = [(0x94c420, b'          ', '_information'),
            (0x94c424, b' Warning: ', '_warning'),
            (0x94c428, b' Error:   ', '_error')]
raw = (OUT / 'CheckLogWriteEntry.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
writer = next(n for n in definitions if n.startswith('?writeEntry@Log@RBX'))
writer_start, writer_section = definitions[writer]
writer_table = sections[writer_section]
writer_refs = {location - writer_start: symbols[index][0] for location, index, kind in
               (struct.unpack_from('<IIH', raw, writer_table[5] + 10 * i) for i in range(writer_table[7]))}
writer_original, _, _ = match.target('2008-06', '005a6ef0')
for address, value, symbol in prefixes:
    assert string(u32(address)) == value
    operand = writer_original.find(struct.pack('<I', address))
    assert operand >= 0 and writer_refs[operand] == symbol
    offset, section = definitions[symbol]
    table = sections[section]
    relocs = [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]
    target = next(symbols[index][0] for location, index, kind in relocs if location == offset)
    literal_offset, literal_section = definitions[target]
    assert raw[sections[literal_section][4] + literal_offset:][:len(value) + 1] == value + b'\0'

raw = (OUT / 'CheckLogLifetime.obj').read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
vtable_start, vtable_section = definitions['??_7Log@RBX@@6B@']
table = sections[vtable_section]
vtable_relocs = {location - vtable_start: symbols[index][0] for location, index, kind in
                 (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7]))}
assert vtable_relocs[0].startswith('??_ELog@RBX@@')
symbol_table, symbol_count = struct.unpack_from('<II', raw, 8)
weak_index = next(i for i, value in symbols.items() if value[0] == vtable_relocs[0])
entry = symbol_table + weak_index * 18
assert raw[entry + 16] == 105 and raw[entry + 17] >= 1
alias_index = struct.unpack_from('<I', raw, entry + 18)[0]
assert symbols[alias_index][0].startswith('??_GLog@RBX@@')

direct = [(OUT / 'CheckLogLifetime.obj', '005a6da0', '??0Log@RBX',
           {0x5a6d10: '?logTimeStamp', 0x44a450: '??$?6'}),
          (OUT / 'CheckLogLifetime.obj', '005a6e60', '??1Log@RBX',
           {0x5a6d10: '?logTimeStamp', 0x44a450: '??$?6'}),
          (OUT / 'CheckLogWriteEntry.obj', '005a6ef0', '?writeEntry@Log@RBX',
           {0x44a450: '??$?6', 0x44a640: '??$?6'})]
for path, address, prefix, expected in direct:
    raw = path.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    name = next(n for n in definitions if n.startswith(prefix))
    start, section = definitions[name]
    table = sections[section]
    refs = {location - start: symbols[index][0] for location, index, kind in
            (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7]))}
    target, _, _ = match.target('2008-06', address)
    calls = [i for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, int(address, 16))
             if i.mnemonic == 'call' and i.bytes[0] == 0xe8]
    assert {int(i.op_str, 16) for i in calls} == set(expected)
    for instruction in calls:
        assert refs[instruction.address - int(address, 16) + 1].startswith(expected[int(instruction.op_str, 16)])

paths = [BASE / source for source, _ in jobs] + [BASE / 'native-headers/util/Log.h', Path(__file__).resolve()]
objects = [OUT / ('Check' + Path(source).stem + '.obj') for source, _ in jobs]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'sources': {str(p.relative_to(ROOT)): sha(p) for p in paths},
           'objects': {str(p.relative_to(ROOT)): sha(p) for p in objects},
           'checks': results, 'layout_offsets': {'name': 4, 'worstSeverity': 0x20, 'logFile': 0x24, 'stream': 0x40},
           'original_vtable': hex(vtable), 'original_deleting_destructor': '0x5a6fb0',
           'scope': 'Diagnostic layout, bodies, selected direct calls and prefix literals only; full ABI, EH, link selection and runtime unproven.'}
dest = ROOT / 'work/2008-06/shared-layouts/native-log-current.json'
dest.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Log layout, lifetime, 4 methods, original RTTI, prefix data and selected calls')
