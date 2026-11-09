"""Verify native Instance archivable descriptor and original initialization."""
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
out = ROOT/'work/2008-06/instance-archivable'
out.mkdir(parents=True, exist_ok=True)
checks = ['007f28e0=??__E?propArchivable@Instance@RBX@@','007fc8c0=??__F?propArchivable@Instance@RBX@@','00559700=??$?0VInstance@RBX@@@?$BoundProp@_N$00@Reflection@RBX@@']
proc = subprocess.run([sys.executable,str(ROOT/'rebuild/2008-06/tests/check_native_class.py'),'native-classes/InstanceArchivableDescriptor.cpp']+checks, cwd=ROOT, env=dict(os.environ,NATIVE_CHECK_OUT=str(out),NATIVE_FLAGS='/O2 /GS- /EHsc /MD /DWIN32 /DNDEBUG /D_MBCS /D_AFXDLL'),capture_output=True,text=True,check=True)
assert '3/3 exact' in proc.stdout, proc.stdout
obj=out/'CheckInstanceArchivableDescriptor.obj';raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw)
name,body,_=next(x for x in match.coff_functions(raw) if x[0].startswith('??__E?propArchivable@Instance@'))
target,_,_=match.target('2008-06','007f28e0');assert target[:7] == bytes.fromhex('6a 05 68 2c 01 00 00')
start,section=definitions[name];table=sections[section]
expected={'?propArchivable@Instance@RBX@@':0x973e74,'??$?0VInstance@RBX@@@?$BoundProp':0x559700,'??__F?propArchivable@Instance@':0x7fc8c0,'_atexit':0x6a17af};found={}
for i in range(table[7]):
    offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
    if 0<=offset<=len(body)-4:
        symbol=symbols[index][0];prefix=next((p for p in expected if symbol.startswith(p)),None)
        if prefix:
            address=struct.unpack_from('<I',target,offset)[0]
            if kind==20: address=(0x7f28e0+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
            assert address==expected[prefix],(symbol,hex(address));found[prefix]=hex(address)
assert set(found)==set(expected),found
pe=pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'))
strings={offset:data.split(b'\0',1)[0].decode() for offset,data,_ in match.coff_data_refs(raw,name) if offset in (8,13)}
assert strings=={8:'Behavior',13:'archivable'}
for offset in (8,13):assert pe.get_string_at_rva(struct.unpack_from('<I',target,offset)[0]-pe.OPTIONAL_HEADER.ImageBase).decode()==strings[offset]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
paths=['rebuild/2008-06/native-classes/InstanceArchivableDescriptor.cpp','rebuild/2008-06/native-headers/v8tree/Instance.h','rebuild/2008-06/p6/build_client.py','rebuild/2008-06/tests/record_native_instance_archivable.py']
result={'scope':'Inactive descriptor initializer, cleanup, constructor, original strings and field offset only; reflection ABI, linked selection and runtime unproven.','field_offset':'0x12c','targets':found,'strings':strings,'inputs':{p:sha(ROOT/p) for p in paths},'object_sha256':sha(obj)}
(out/'result.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS archivable descriptor: 3 bodies, field offset, strings and selected targets')
