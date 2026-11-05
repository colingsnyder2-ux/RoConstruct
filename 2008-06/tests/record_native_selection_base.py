"""Verify Selection base providers, original direct calls and class-name vtable slot."""
import hashlib
import json
from pathlib import Path
import struct
import sys
import pefile

ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match
run=Path(sys.argv[1]);rows=json.loads((run/'results.json').read_text());row=next(x for x in rows if x['source'].endswith('SelectionBase.cpp'));lifetime=next(x for x in rows if x['source'].endswith('SelectionLifetime.cpp'))
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
for item in (row,lifetime):
    assert sha(item['source'])==item['source_sha256'] and sha(item['object'])==item['object_sha256']
    for path,digest in item['dependencies'].items():assert sha(path)==digest,path
    assert all(x['status']=='exact' for x in item['checks'])
raw=Path(row['object']).read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=list(match.coff_functions(raw));result=[]
checks=[(0x567e20,'??0?$DescribedCreatable@VSelection@',{'??0?$FactoryProduct@VSelection@':0x5667b0,'?classDescriptor@?$Described@VSelection@':0x5671a0}),(0x5667b0,'??0?$FactoryProduct@VSelection@',{'??0Instance@RBX@@':0x55b7e0}),(0x5671a0,'?classDescriptor@?$Described@VSelection@',{'?classDescriptor@?$Described@VInstance@':0x40ad80,'??0ClassDescriptor@Reflection@RBX@@':0x5708f0,'_atexit':0x6a17af}),(0x566b80,'?getClassName@?$FactoryProduct@VSelection@',{'?call_once@boost@@':0x557330,'??$doDeclare@$1?sSelection@':0x4068c0})]
for address,prefix,expected in checks:
    name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,tr,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,tr,body,refs)
    start,section=defs[name];table=sections[section];found={}
    for i in range(table[7]):
        offset,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
        if kind==20 and 0<=offset<=len(body)-4:
            symbol=symbols[index][0];key=next((p for p in expected if symbol.startswith(p)),None)
            if key:
                value=(address+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
                assert value==expected[key] and struct.unpack_from('<I',body,offset)[0]==0,(symbol,hex(value))
                found[key]=hex(value)
    assert set(found)==set(expected),(name,found)
    result.append({'address':hex(address),'symbol':name,'targets':found})
raw2=Path(lifetime['object']).read_bytes();sec2,sy2,defs2,_=match._coff_data_index(raw2)
vtable=next(n for n in defs2 if n.startswith('??_7Selection@RBX@@6B?$AbstractFactoryProduct@VInstance@'))
start,section=defs2[vtable];table=sec2[section];slot={}
for i in range(table[7]):
    offset,index,kind=struct.unpack_from('<IIH',raw2,table[5]+10*i);offset-=start
    if offset>=0:slot[offset]=sy2[index][0]
assert slot[4]==result[3]['symbol']
pe=pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'));assert struct.unpack('<I',pe.get_data(0x82edb8-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x566b80
out={'scope':'Inactive Selection base code, selected calls and class-name vtable slot; complete ABI, selected executable, link and runtime unproven.','methods':result,'vtable':vtable,'slot':1,'original_slot_target':'0x566b80','object_sha256':sha(row['object']),'lifetime_object_sha256':sha(lifetime['object']),'run':str(run)}
(ROOT/'work/2008-06/selection-base-proof.json').write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
print('PASS Selection base providers, selected calls and class-name vtable slot')
