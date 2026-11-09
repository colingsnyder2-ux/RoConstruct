import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/native-classes/NativeClassNames.cpp';obj=out/'NativeClassNames.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rows=[]
# Original Instance RTTI names a const array template argument (3QBDB).
u=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0]
chd=u(u(0x8318bc-4)+16)
names=[]
for i in range(u(chd+8)):
    td=u(u(u(chd+12)+4*i))
    names.append(pe.get_string_at_rva(td+8-image).decode())
assert '.?AV?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@' in names
for symbol,address,value,reference in [('?sInstance@RBX@@3QBDB',0x82d6a0,b'Instance\0',0x40ada9),('?sSelection@RBX@@3PADA',0x82ec58,b'Selection\0',0x5671c9),('?sTexture@RBX@@3PADA',0x949c70,b'Texture\0',0x41debb),('?sRunService@RBX@@3PADA',0x82d328,b'RunService\0',0x556459)]:
 start,sec=defs[symbol];table=sections[sec];actual=raw[table[4]+start:table[4]+start+len(value)];assert actual==value and pe.get_data(address-image,len(value))==value;assert struct.unpack('<I',pe.get_data(reference-image,4))[0]==address;rows.append({'symbol':symbol,'original_address':hex(address),'bytes':value.hex(),'original_reference':hex(reference)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Class-name byte arrays match original descriptor name strings; storage placement, pooling, complete ABI and runtime remain unproven.','names':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/native-class-names-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS native Instance, Selection, Texture and RunService class-name data')
