"""Record shared-header constructor mismatch; keep trial out of link."""
import hashlib,json,struct,sys
import pefile
from pathlib import Path
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts'; source=root/'rebuild/2008-06/tests/NativeHumanoidConstructorTrial.cpp'; obj=out/'NativeHumanoidConstructorTrial.obj'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text()); flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
overlay=out/'humanoid-strafe-overlay/humanoid';overlay.mkdir(parents=True,exist_ok=True)
header=root/'tools/rbxgs/Client/App/include/humanoid/roc_Humanoid_2008.h'; text=header.read_text(); assert text.count('bool sit : 1;')==1
assert text.count('extern const char* sHumanoid;')==1 and text.count('&sHumanoid>')==1
(overlay/'roc_Humanoid_2008.h').write_text(text.replace('extern const char* sHumanoid;', 'extern char sHumanoid[];').replace('&sHumanoid>', 'sHumanoid>').replace('bool sit : 1;', 'bool sit : 1;\n        bool strafe : 1;').replace('void setJump(bool value);','bool getStrafe() const;\n        void setStrafe(bool);\n        void setJump(bool value);'))
instance_dir=overlay.parent/'v8tree';instance_dir.mkdir(exist_ok=True)
instance_header=root/'rebuild/2008-06/native-headers/v8tree/Instance.h'
instance_text=instance_header.read_text();assert instance_text.count('void raisePropertyChanged(const Reflection::PropertyDescriptor&')==1
(instance_dir/'Instance.h').write_text(instance_text)
flags.insert(0,'/I'+str(overlay.parent))
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out);assert code==0,log
name,body,refs=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('??0Humanoid@RBX@@')); target,targetrefs,_=match.target('2008-06','005db280')
assert len(body)==len(target)==565 and match.exact_match(target,targetrefs,body,refs)
assert target[0x190:0x197]==body[0x190:0x197]==bytes.fromhex('80a6e8010000e0')
sections,symbols,definitions,_=match._coff_data_index(obj.read_bytes());start,idx=definitions[name];section=sections[idx];raw=obj.read_bytes();edges={}
for i in range(section[7]):
 offset,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+i*10);offset-=start
 if not 0<=offset<len(body)-3:continue
 value=struct.unpack_from('<I',target,offset)[0]
 if kind==20:value=(0x5db280+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
 edges[symbols[symbol][0]]=value
assert any(k.startswith('??0ICharacterSubject@RBX@@') and v==0x641320 for k,v in edges.items()),edges
assert any(k.startswith('??_7Humanoid@RBX@@6BICameraSubject') and v==0x83d388 for k,v in edges.items()),edges
assert any('UDescendantAdded@' in k for k in edges) and any('UDescendantRemoving@' in k for k in edges),edges
assert not any('UDescendentAdded@' in k or 'UDescendentRemoving@' in k for k in edges),edges
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase
initializer,_,_=match.target('2008-06','007f6690')
for address in (0x5dc230,0x5d7540,0x83d828,0x83d87c,0x97a5c0):assert struct.pack('<I',address) in initializer
assert pe.get_string_at_rva(0x83d828-image)==b'Control' and pe.get_string_at_rva(0x83d87c-image)==b'Strafe'
getter,_,_=match.target('2008-06','005d7540');assert getter==bytes.fromhex('8a81e8010000c0e8042401c3')
getter_source=root/'rebuild/2008-06/tests/NativeHumanoidStrafeTrial.cpp';getter_obj=out/'NativeHumanoidStrafeTrial.obj'
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(getter_obj),str(getter_source)],out);assert code==0,log
name_get,get_body,get_refs=next(x for x in match.coff_functions(getter_obj.read_bytes()) if x[0].startswith('?getStrafe@Humanoid@RBX@@'))
assert match.exact_match(getter,[],get_body,get_refs)
descriptor_source=root/'rebuild/2008-06/tests/NativeHumanoidStrafeDescriptorTrial.cpp';descriptor_obj=out/'NativeHumanoidStrafeDescriptorTrial.obj'
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(descriptor_obj),str(descriptor_source)],out);assert code==0,log
descriptor_raw=descriptor_obj.read_bytes();init_name,init_body,init_refs=next(x for x in match.coff_functions(descriptor_raw) if x[0].startswith('??__EpropStrafe@RBX@@'))
init_target,init_targetrefs,_=match.target('2008-06','007f6690');assert match.exact_match(init_target,init_targetrefs,init_body,init_refs)
sections,symbols,definitions,_=match._coff_data_index(descriptor_raw);start,idx=definitions[init_name];section=sections[idx];init_edges={}
for i in range(section[7]):
 offset,symbol,kind=struct.unpack_from('<IIH',descriptor_raw,section[5]+i*10);offset-=start
 if not 0<=offset<len(init_body)-3:continue
 value=struct.unpack_from('<I',init_target,offset)[0]
 if kind==20:value=(0x7f6690+offset+4+struct.unpack_from('<i',init_target,offset)[0])&0xffffffff
 init_edges[symbols[symbol][0]]=value
for token,address in [('getStrafe',0x5d7540),('setStrafe',0x5dc230),('propStrafe',0x97a5c0)]:
 assert any(token in k and v==address for k,v in init_edges.items()),(token,init_edges)
readptr=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0]
for vtable,typename in [(0x83d688,b'.?AV?$PropDescriptor@VHumanoid@RBX@@_N@Reflection@RBX@@'),(0x80b730,b'.?AVDescriptor@Reflection@RBX@@')]:
 assert pe.get_string_at_rva(readptr(readptr(vtable-4)+12)+8-image)==typename
descriptor_lifetime=[]
for prefix,address in [('??$?0P8Humanoid@',0x5da8b0),('??__FpropStrafe@',0x7ff340)]:
 name_life,body_life,refs_life=next(x for x in match.coff_functions(descriptor_raw) if x[0].startswith(prefix))
 target_life,target_refs,_=match.target('2008-06',f'{address:08x}')
 assert match.exact_match(target_life,target_refs,body_life,refs_life),(prefix,len(body_life))
 sections,symbols,definitions,_=match._coff_data_index(descriptor_raw);start,idx=definitions[name_life];section=sections[idx];bindings=[]
 for i in range(section[7]):
  offset,symbol,kind=struct.unpack_from('<IIH',descriptor_raw,section[5]+i*10);offset-=start
  if not 0<=offset<len(body_life)-3:continue
  value=struct.unpack_from('<I',target_life,offset)[0]
  if kind==20:value=(address+offset+4+struct.unpack_from('<i',target_life,offset)[0])&0xffffffff
  bindings.append({'symbol':symbols[symbol][0],'target':value})
 def has(token,value):return any(token in edge['symbol'] and edge['target']==value for edge in bindings)
 if address==0x5da8b0:
  for token,value in [('getset@',0x5d8290),('classDescriptor@',0x5c0860),('TypedPropertyDescriptor',0x40a290),('??_7?$PropDescriptor',0x83d688)]:assert has(token,value),(token,bindings)
 else:
  for token,value in [('propStrafe',0x97a5c0),('propStrafe',0x97a5d8),('??_7Descriptor',0x80b730)]:assert has(token,value),(token,bindings)
 descriptor_lifetime.append({'address':hex(address),'size':len(body_life),'exact':True,'symbol':name_life,'bindings':bindings})
setter, setter_refs,_=match.target('2008-06','005dc230')
setter_name,set_body,set_refs=next(x for x in match.coff_functions(getter_obj.read_bytes()) if x[0].startswith('?setStrafe@Humanoid@RBX@@'))
assert match.exact_match(setter,setter_refs,set_body,set_refs), ('setStrafe',len(set_body),len(setter))
set_raw=getter_obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(set_raw);start,idx=definitions[setter_name];section=sections[idx];set_edges={}
for i in range(section[7]):
 offset,symbol,kind=struct.unpack_from('<IIH',set_raw,section[5]+i*10);offset-=start
 if not 0<=offset<len(set_body)-3:continue
 value=struct.unpack_from('<I',setter,offset)[0]
 if kind==20:value=(0x5dc230+offset+4+struct.unpack_from('<i',setter,offset)[0])&0xffffffff
 set_edges[symbols[symbol][0]]=value
assert any('raisePropertyChanged' in k and v==0x40db00 for k,v in set_edges.items()),set_edges
assert any('propStrafe' in k and v==0x97a5c0 for k,v in set_edges.items()),set_edges
assert bytes.fromhex('c0eb0480e301') in setter and bytes.fromhex('2410') in setter
moving,_,_=match.target('2008-06','0066f2c0')
assert bytes.fromhex('f680e801000010') in moving
controller,_,_=match.target('2008-06','005cb530')
controller_calls=[i.address for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(controller,0x5cb530) if i.mnemonic=='call' and i.op_str=='0x5dc230']
assert controller_calls==[0x5cb723,0x5cb7de],controller_calls
dtor_source=root/'rebuild/2008-06/tests/NativeHumanoidDestructorTrial.cpp';dtor_obj=out/'NativeHumanoidDestructorStrafe.obj'
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(dtor_obj),str(dtor_source)],out);assert code==0,log
dtor_raw=dtor_obj.read_bytes();dtor_name,dtor,dtor_refs=next(x for x in match.coff_functions(dtor_raw) if x[0].startswith('??1Humanoid@RBX@@'))
dtor_target,dtor_targetrefs,_=match.target('2008-06','005d7d20');assert match.exact_match(dtor_target,dtor_targetrefs,dtor,dtor_refs)
sections,symbols,definitions,_=match._coff_data_index(dtor_raw)
vt=next(n for n in definitions if n.startswith('??_7Humanoid@RBX@@6B?$GuidItem'));pos,idx=definitions[vt];section=sections[idx]
slots={}
for i in range(section[7]):
 offset,symbol,kind=struct.unpack_from('<IIH',dtor_raw,section[5]+i*10)
 if pos<=offset<pos+52:slots[(offset-pos)//4]=symbols[symbol][0]
assert slots[11].startswith('?readProperty@'),slots
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'address':'005db280','size':565,'exact':True,'original_and_mask':'0xe0','candidate_and_mask':'0xe0','constructor_bindings':edges,'destructor':{'address':'005d7d20','size':len(dtor),'exact':True,'object_sha256':sha(dtor_obj),'source_sha256':sha(dtor_source),'read_property_slot':11},'offset':'0x1e8','descriptor_lifetime':descriptor_lifetime,'property_initializer':'007f6690','property_initializer_size':len(init_body),'property_initializer_bindings':init_edges,'descriptor_source_sha256':hashlib.sha256(descriptor_source.read_bytes()).hexdigest(),'descriptor_object_sha256':hashlib.sha256(descriptor_obj.read_bytes()).hexdigest(),'property_descriptor':'0x97a5c0','getter':'005d7540','getter_source_sha256':hashlib.sha256(getter_source.read_bytes()).hexdigest(),'getter_object_sha256':hashlib.sha256(getter_obj.read_bytes()).hexdigest(),'setter':'005dc230','setter_size':len(set_body),'setter_bindings':set_edges,'movement_reader':'0066f2c0','controller_setter_calls':[hex(x) for x in controller_calls],'source_sha256':sha(source),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'scope':'Inactive overlay: fifth flag matches native setStrafe bit, constructor exact with relocations masked. Full RTTI, bindings, lifetime ownership and runtime require verification.'}
(root/'work/2008-06/shared-layouts/humanoid-constructor-mismatch.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS constructor and destructor exact with provisional strafe overlay; readProperty slot 11')

