import json,sys,hashlib,struct
from pathlib import Path
ROOT=Path.cwd()
sys.path.insert(0,str(ROOT));sys.path.insert(0,str(ROOT/'rebuild/2008-06/tests'))
from roc import match,rebuild
import native_bind as nb
out=ROOT/'work/fork-integration/mew-rest-root-20261104/signal-destructor-proof'
recipes=[('signal','tools/rbxgs/Client/App/reflection/signal.cpp','??1SignalInstance@Reflection@RBX@@UAE@XZ','0056b4f0'),('signal_base','tools/rbxgs/Client/boost_1_34_1/libs/signals/src/signal_base.cpp','??1signal_base@detail@signals@boost@@QAE@XZ','00600660'),('trackable','tools/rbxgs/Client/boost_1_34_1/libs/signals/src/trackable.cpp','??1trackable@signals@boost@@IAE@XZ','005950e0')]
flags=nb.flags()+['/O2','/GS-','/EHsc','/MD']
rows=[]
for tag,src,sym,addr in recipes:
 obj=out/(tag+'.obj'); clflags=[x for x in flags if not x.startswith('/Fo') and not x.endswith('.cpp')]+['/Fo'+str(obj),str(ROOT/src)]
 rc,log=rebuild.run(rebuild.toolchain(21022),'cl',clflags,out)
 if rc: raise RuntimeError(f'{tag} compile failed\n{log}')
 bodies={n:(b,r) for n,b,r in match.coff_functions(obj.read_bytes())}
 assert sym in bodies,(tag,'symbol missing',list(n for n in bodies if 'SignalInstance' in n or 'signal_base' in n or 'trackable' in n))
 body,refs=bodies[sym]; target,trefs,_=match.target('2008-06',addr)
 raw=obj.read_bytes(); sections,symbols,definitions,_=match._coff_data_index(raw); start,section=definitions[sym]; table=sections[section]; code=raw[table[4]+start:]
 relocations=[]
 for i in range(table[7]):
  offset,index,kind=__import__('struct').unpack_from('<IIH',raw,table[5]+10*i)
  rel=offset-start
  if 0<=rel<len(body):
   if kind==20: value=(int(addr,16)+rel+4+struct.unpack_from('<i',target,rel)[0])&0xffffffff
   else: value=(struct.unpack_from('<I',target,rel)[0]-struct.unpack_from('<i',code,rel)[0])&0xffffffff
   relocations.append({'offset':rel,'kind':kind,'symbol':symbols[index][0],'target':'0x%08x'%value})
 rows.append({'tag':tag,'source':src,'symbol':sym,'address':'0x'+addr,'body_size':len(body),'target_size':len(target),'body_sha256':hashlib.sha256(body).hexdigest(),'target_sha256':hashlib.sha256(target).hexdigest(),'body_relocs':refs,'target_relocs':trefs,'relocation_bindings':relocations,'exact':match.exact_match(target,trefs,body,refs),'object_sha256':hashlib.sha256(raw).hexdigest()})
list_src=out/'list_connection.cpp'
list_src.write_text('#include <list>\n#include <boost/signals/connection.hpp>\ntemplate class std::list<boost::signals::connection>;\n')
list_obj=out/'list_connection.obj'
list_flags=[x for x in flags if not x.startswith('/Fo') and not x.endswith('.cpp')]+['/Fo'+str(list_obj),str(list_src)]
rc,log=rebuild.run(rebuild.toolchain(21022),'cl',list_flags,out)
if rc: raise RuntimeError(f'list destructor compile failed\n{log}')
list_raw=list_obj.read_bytes(); list_bodies={n:(b,r) for n,b,r in match.coff_functions(list_raw)}
list_sym='??1?$list@Vconnection@signals@boost@@V?$allocator@Vconnection@signals@boost@@@std@@@std@@QAE@XZ'
assert list_sym in list_bodies,(list_sym,[n for n in list_bodies if n.startswith('??1?$list@Vconnection')])
list_body,list_refs=list_bodies[list_sym]; list_target,list_trefs,_=match.target('2008-06','0041abc0')
assert match.exact_match(list_target,list_trefs,list_body,list_refs),('std::list<connection> destructor mismatch',len(list_body),len(list_target),list_refs,list_trefs)
list_sections,list_symbols,list_defs,_=match._coff_data_index(list_raw); list_start,list_section=list_defs[list_sym]; list_table=list_sections[list_section]
list_relocs=[]
for i in range(list_table[7]):
 offset,index,kind=struct.unpack_from('<IIH',list_raw,list_table[5]+10*i); rel=offset-list_start
 if 0<=rel<len(list_body):
  if kind==20: value=(0x41abc0+rel+4+struct.unpack_from('<i',list_target,rel)[0])&0xffffffff
  else: value=(struct.unpack_from('<I',list_target,rel)[0]-struct.unpack_from('<i',list_raw,list_table[4]+list_start+rel)[0])&0xffffffff
  list_relocs.append({'offset':rel,'kind':kind,'symbol':list_symbols[index][0],'target':'0x%08x'%value})
rows.append({'tag':'std_list_connection','source':'generated explicit std::list<boost::signals::connection> instantiation','symbol':list_sym,'address':'0x0041abc0','body_size':len(list_body),'target_size':len(list_target),'body_sha256':hashlib.sha256(list_body).hexdigest(),'target_sha256':hashlib.sha256(list_target).hexdigest(),'body_relocs':list_refs,'target_relocs':list_trefs,'relocation_bindings':list_relocs,'exact':True,'object_sha256':hashlib.sha256(list_raw).hexdigest()})
sources={src:hashlib.sha256((ROOT/src).read_bytes()).hexdigest() for _,src,_,_ in recipes}
original=ROOT/'work/2008-06/original-p4-reference/Roblox.exe'
exe=nb.Original()
assert all(r['exact'] and r['body_size']==r['target_size'] for r in rows), rows
signal_row=next(r for r in rows if r['tag']=='signal')
assert signal_row['relocation_bindings']==[{'offset':2,'kind':6,'symbol':'??_7SignalInstance@Reflection@RBX@@6B@','target':'0x0080ece0'}]
assert exe.vtable_class(0x80ece0)==('.?AVSignalInstance@Reflection@RBX@@',0)
base_row=next(r for r in rows if r['tag']=='signal_base')
assert not base_row['relocation_bindings'] and base_row['exact']
track_row=next(r for r in rows if r['tag']=='trackable')
assert track_row['relocation_bindings']==[{'offset':5,'kind':20,'symbol':'??1?$list@Vconnection@signals@boost@@V?$allocator@Vconnection@signals@boost@@@std@@@std@@QAE@XZ','target':'0x0041abc0'}]
list_row=next(r for r in rows if r['tag']=='std_list_connection')
assert list_row['exact'] and list_row['symbol']==track_row['relocation_bindings'][0]['symbol']
track_bytes=exe.data(0x5950e0,track_row['target_size'])
assert track_bytes[4]==0xe9 and (0x5950e0+9+struct.unpack_from('<i',track_bytes,5)[0])&0xffffffff==0x41abc0
def require_binding(actual, expected):
 assert actual==expected,(hex(actual),hex(expected))
signal_vtable_target=int(signal_row['relocation_bindings'][0]['target'],16)
track_callee=(0x5950e0+9+struct.unpack_from('<i',track_bytes,5)[0])&0xffffffff
require_binding(signal_vtable_target,0x80ece0)
require_binding(track_callee,0x41abc0)
negative_rejected=[]
for actual,wrong in ((signal_vtable_target,0x80ece4),(track_callee,0x41abc1)):
 try: require_binding(actual,wrong)
 except AssertionError: negative_rejected.append(True)
 else: negative_rejected.append(False)
assert all(negative_rejected),negative_rejected
header=ROOT/'rebuild/2008-06/native-headers/reflection/signal.h'
receipt={'compiler':'MSVC 15.00.21022','flags':clflags[:-2],'sources':sources,'original_sha256':hashlib.sha256(original.read_bytes()).hexdigest(),'relocation_identity_checks':{'SignalInstance destructor DIR32 resolves to RTTI-verified SignalInstance vtable 0x80ece0':True,'signal_base destructor has no relocations':True,'trackable destructor REL32 binds to independently exact std::list<connection> destructor at 0x41abc0':True,'negative_wrong_vtable_and_callee_targets_rejected':all(negative_rejected)},'rows':rows}
receipt['native_signal_header_sha256']=hashlib.sha256(header.read_bytes()).hexdigest()
receipt['generated_list_instantiation_sha256']=hashlib.sha256(list_src.read_bytes()).hexdigest()
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))
