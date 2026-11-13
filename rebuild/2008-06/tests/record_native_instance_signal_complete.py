"""Verify original Instance signal descriptors and their registration strings."""
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
out = ROOT/'work/2008-06/instance-signal-complete'
out.mkdir(parents=True, exist_ok=True)
events = [
    ('childAdded', 0x7f2b10, 0x7fcb90, 'ChildAdded', 'child', 0x559b10),
    ('childRemoved', 0x7f2b30, 0x7fca40, 'ChildRemoved', 'child', 0x559b10),
    ('descendentAdded', 0x7f2b50, 0x7fca80, 'DescendantAdded', 'descendant', 0x559b10),
    ('descendentRemoving', 0x7f2b70, 0x7fcac0, 'DescendantRemoving', 'descendant', 0x559b10),
    ('ancestryChanged', 0x7f2b90, 0x7fcb00, 'AncestryChanged', 'child', 0x559b10),
    ('propertyChanged', 0x7f2bb0, 0x7fcb40, 'Changed', 'property', 0x559be0),
]
checks = []
for name, init, fini, _, _, _ in events:
    checks.extend([f'{init:08x}=??__E?event_{name}@Instance@RBX@@', f'{fini:08x}=??__F?event_{name}@Instance@RBX@@'])
checks += ['00559be0=??0?$SignalDesc@VInstance@RBX@@$$A6AXPBVPropertyDescriptor@', '00559b10=??0?$SignalDesc@VInstance@RBX@@$$A6AXV?$shared_ptr@']
proc = subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/check_native_class.py'), 'native-classes/InstanceSignalDescriptors.cpp']+checks, cwd=ROOT, env=dict(os.environ, NATIVE_CHECK_OUT=str(out), NATIVE_FLAGS='/O2 /GS- /EHsc /MD /DWIN32 /DNDEBUG /D_MBCS /D_AFXDLL'), capture_output=True, text=True, check=True)
assert '14/14 exact' in proc.stdout, proc.stdout
obj = out/'CheckInstanceSignalDescriptors.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = list(match.coff_functions(raw))
pe = pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'))
rows = []
for name, init, fini, label, arg, ctor in events:
    symbol, body, refs = next(x for x in functions if x[0].startswith('??__E?event_'+name+'@Instance@RBX@@'))
    target, _, _ = match.target('2008-06',f'{init:08x}')
    data = {offset:value.split(b'\0',1)[0].decode() for offset,value,_ in match.coff_data_refs(raw,symbol) if offset in (1,6)}
    assert data == {1:arg,6:label}, (name,data)
    assert pe.get_string_at_rva(struct.unpack_from('<I',target,1)[0]-pe.OPTIONAL_HEADER.ImageBase).decode() == arg
    assert pe.get_string_at_rva(struct.unpack_from('<I',target,6)[0]-pe.OPTIONAL_HEADER.ImageBase).decode() == label
    start, section = definitions[symbol]
    table = sections[section]
    bound = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH',raw,table[5]+10*i)
        offset -= start
        if 0 <= offset <= len(body)-4:
            sym = symbols[index][0]
            address = struct.unpack_from('<I',target,offset)[0]
            if kind == 20: address = (init+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
            for prefix, want in [('??0?$SignalDesc@VInstance@',ctor), ('??__F?event_'+name+'@Instance@',fini), ('_atexit',0x6a17af)]:
                if sym.startswith(prefix): assert address == want, (sym,hex(address)); bound[prefix]=hex(address)
    assert len(bound) == 3, (name,bound)
    rows.append({'signal':name,'initializer':hex(init),'cleanup':hex(fini),'label':label,'argument':arg,'targets':bound})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = ['rebuild/2008-06/native-classes/InstanceSignalDescriptors.cpp','rebuild/2008-06/native-headers/v8tree/Instance.h','rebuild/2008-06/p6/build_client.py','rebuild/2008-06/tests/record_native_instance_signal_complete.py']
result = {'scope':'Inactive signal bodies, strings and selected direct targets. Reflection ABI, linked ownership, startup and runtime unproven.','signals':rows,'inputs':{p:sha(ROOT/p) for p in paths},'object_sha256':sha(obj)}
(out/'result.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS 6 Instance signals: 14 bodies, original names and selected targets')
