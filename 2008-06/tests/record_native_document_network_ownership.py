"""Verify Doc network calls bind to the original Players wrappers."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

receipt = 'doc-network-ownership-layout.json'
subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/record_native_document.py'), receipt], check=True, cwd=ROOT)
objpath = ROOT / 'rebuild/2008-06/out/native-layouts/NativeDocumentLayout.obj'
obj = objpath.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(obj)
functions = list(match.coff_functions(obj))
result = []
for address, method, expected in (
    ('0044f8d0', 'DoSave', {0x495e60, 0x495e70}),
    ('0044f9b0', 'OnSaveDocument', {0x495e60, 0x495e70}),
    ('00454300', 'handle_454300', {0x495e60}),
):
    name, body, relocs = next(x for x in functions if x[0].startswith('?' + method + '@CRobloxDoc@@'))
    original, original_relocs, _ = match.target('2008-06', address)
    assert match.exact_match(original, original_relocs, body, relocs), method
    start, section = definitions[name]
    table = sections[section]
    calls = {i.address - int(address, 16) + 1: int(i.op_str, 16)
             for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(original, int(address, 16))
             if i.mnemonic == 'call' and i.op_str.startswith('0x')}
    found = []
    for index in range(table[7]):
        offset, symindex, _ = struct.unpack_from('<IIH', obj, table[5] + index * 10)
        symbol = symbols[symindex][0]
        if symbol.startswith(('?clientIsPresent@Players@Network@RBX@@', '?serverIsPresent@Players@Network@RBX@@')):
            target = calls.get(offset - start)
            expected_target = 0x495e60 if symbol.startswith('?clientIsPresent@') else 0x495e70
            assert target == expected_target and target in expected, (method, symbol, target)
            assert struct.unpack_from('<I', body, offset - start)[0] == 0, (method, symbol, 'nonzero addend')
            found.append({'offset': offset - start, 'symbol': symbol, 'original_target': hex(target)})
    assert len(found) == len(expected) and {int(x['original_target'], 16) for x in found} == expected, (method, found)
    result.append({'address': address, 'method': method, 'masked_bytes_match': True, 'calls': found})
paths = ['rebuild/2008-06/native-classes/CRobloxDoc.cpp', 'rebuild/2008-06/native-headers/Network/Players.h', 'rebuild/2008-06/tests/NativeDocumentLayout.cpp', 'rebuild/2008-06/tests/record_native_document.py', 'rebuild/2008-06/tests/record_native_document_network_ownership.py']
output = {'methods': result, 'object_sha256': hashlib.sha256(obj).hexdigest(), 'inputs': {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest() for p in paths}, 'proof': 'relocation-normalized bodies and network call identities only; not linked or runtime tested'}
out = ROOT / 'work/2008-06/doc-network-ownership.json'
out.write_text(json.dumps(output, indent=2) + '\n', encoding='utf-8')
print(json.dumps(output, indent=2))
