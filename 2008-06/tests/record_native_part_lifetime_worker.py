import hashlib,json,re,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import libs,match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'part-layout-worker';work.mkdir(exist_ok=True);unit='roc_part_grouped_tail_constructor_9b19d0716f31ff52.cpp';pre=libs.unit('rbxgs-dll',unit,21022);assert pre.count('~NativeStringScope();')==1
s=pre.replace('~NativeStringScope();','').replace('const char** ClassName','const char* ClassName').replace('DerivedClass::classDescriptor(), *ClassName','DerivedClass::classDescriptor(), ClassName');s=re.sub(r'extern const char\* (s(?:Instance|PVInstance|Part));',r'extern char \1[];',s);s=re.sub(r'&\s*(s(?:Instance|PVInstance|Part))\b',r'\1',s);assert 'extern char sPart[];' in s and 'DescribedCreatable<PartInstance, PVInstance, sPart>' in s and 'sizeof(Primitive)==0xfc' in s and 'sizeof(PartInstance)==0x404' in s
inc=root/'rebuild/2008-06/tests/NativePartLifetimeWorker.inc';src=work/'PartLifetimeWorker.cpp';src.write_text(s+'\n'+inc.read_text());obj=work/'PartLifetimeWorker.obj';flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('??0PartInstance@RBX@@',0x59d4d0,[('??0Primitive@RBX@@',0x5e8770),('??0Surfaces@RBX@@',0x5ecbb0),('??_7PartInstance@RBX@@6B?$GuidItem',0x832d4c)]),('??1PartInstance@RBX@@',0x59b970,[('??1Primitive@RBX@@',0x5e7df0),('__imp_??1?$basic_string@',0x802468),('??_7PartInstance@RBX@@6B?$GuidItem',0x832d4c)]),('??1Primitive@RBX@@',0x5e7df0,[('??_7Primitive@RBX@@',0x83f83c),('??1Body@RBX@@',0x614ac0),('?alignedFree@System@G3D@@',0x507d20)]),('??$create@VPartInstance@RBX@@',0x41e9c0,[('__imp__malloc',0x8028b0),('??0PartInstance@RBX@@',0x59d4d0),('??$?0VPartInstance@',0x41e910)]),('??$?0VPartInstance@RBX@@VDeleter@',0x41e910,[('??$?0PAVPartInstance@',0x41e880)])]:
 name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target));start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;u=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0]
for vt,typename in [(0x832d4c,b'.?AVPartInstance@RBX@@'),(0x83f83c,b'.?AVPrimitive@RBX@@'),(0x80f1cc,b'.?AV?$sp_counted_impl_pd@PAVPartInstance@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@2@@detail@boost@@')]:
 loc=u(vt-4);desc=u(loc+12);assert pe.get_string_at_rva(desc+8-image)==typename
assert u(0x80f1cc+4)==0x48ee50
ctor,_,_=match.target('2008-06','0059d4d0');dtor,_,_=match.target('2008-06','0059b970');assert b'\x8d\xbe\x28\x02\x00\x00' in ctor and b'\x8d\x8e\x28\x02\x00\x00' in dtor
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive preprocessed 2008-name typed profile: same TU Part ctor/dtor, Primitive dtor, Part factory and shared_ptr constructor match; selected bindings and original RTTI verified. Primitive ctor, Body 0xdc layout, NativeStringScope true identity, complete virtual/data ABI and runtime remain unproven. Shared PartInstance still incorrectly uses scoped pointer. Never run diagnostic.','part_size':'0x404','primitive_size':'0xfc','primitive_offset':'0x228','part_vtable':'0x832d4c','primitive_vtable':'0x83f83c','control_block_vtable':'0x80f1cc','control_block_dispose':'0x48ee50','methods':rows,'profile_unit':unit,'original_preprocessed_sha256':hashlib.sha256(pre.encode()).hexdigest(),'generated_source_sha256':sha(src),'object_sha256':sha(obj),'inc_sha256':sha(inc),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/part-lifetime-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS same-TU Part lifetime, Primitive destructor, factory and control block')
