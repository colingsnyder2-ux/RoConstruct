"""Verify native Instance Name descriptor initialization and accessors."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

import pefile
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match
out = ROOT/'work/2008-06/instance-name-descriptor'
out.mkdir(parents=True, exist_ok=True)
checks = ['007f2a90=??__E?desc_Name@Instance@RBX@@', '007fc8e0=??__F?desc_Name@Instance@RBX@@', '00559870=??$?0P8Instance@RBX@@', '004117b0=?getName@Instance@RBX@@', '00557630=??_9Instance@RBX@@']
proc = subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/check_native_class.py'), 'native-classes/InstanceNameDescriptor.cpp']+checks, cwd=ROOT, env=dict(os.environ, NATIVE_CHECK_OUT=str(out), NATIVE_FLAGS='/O2 /GS- /EHsc /MD /DWIN32 /DNDEBUG /D_MBCS /D_AFXDLL'), capture_output=True, text=True, check=True)
assert '5/5 exact' in proc.stdout, proc.stdout
obj = out/'CheckInstanceNameDescriptor.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = list(match.coff_functions(raw))
pe = pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'))
expected = {'??_9Instance@RBX@@': 0x557630, '?getName@Instance@RBX@@': 0x4117b0, '?desc_Name@Instance@RBX@@': 0x973d54, '??$?0P8Instance@RBX@@': 0x559870, '??__F?desc_Name@Instance@RBX@@': 0x7fc8e0, '_atexit': 0x6a17af}
name, body, refs = next(x for x in functions if x[0].startswith('??__E?desc_Name@Instance@RBX@@'))
target, _, _ = match.target('2008-06', '007f2a90')
start, section = definitions[name]
table = sections[section]
found = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5]+10*i)
    offset -= start
    symbol = symbols[index][0]
    prefix = next((p for p in expected if symbol.startswith(p)), None)
    if prefix and 0 <= offset <= len(body)-4:
        address = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            address = (0x7f2a90+offset+4+struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        assert address == expected[prefix], (symbol, hex(address))
        found[prefix] = hex(address)
assert set(found) == set(expected), found
strings = {offset:data.split(b'\0',1)[0] for offset,data,_ in match.coff_data_refs(raw, name)}
for offset, address in [(22,0x822490),(27,0x80f7cc)]:
    assert strings[offset] == pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase)
assert strings[22] == b'Data' and strings[27] == b'Name'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = ['rebuild/2008-06/native-classes/InstanceNameDescriptor.cpp','rebuild/2008-06/native-headers/v8tree/Instance.h','rebuild/2008-06/p6/build_client.py','rebuild/2008-06/tests/record_native_instance_name_descriptor.py']
receipt = {'scope':'Inactive native original Name descriptor, initializer, cleanup, accessor and selected targets; reflection ABI, linked ownership and runtime unproven.', 'targets':found, 'strings':{str(k):v.decode() for k,v in strings.items() if k in (22,27)}, 'inputs':{p:sha(ROOT/p) for p in paths}, 'object_sha256':sha(obj)}
(out/'result.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
print(proc.stdout, 'PASS Name descriptor targets and strings')
