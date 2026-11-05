import json,struct,hashlib,sys
from pathlib import Path
import capstone
sys.path.insert(0,str(Path.cwd()))
from roc import match
out=Path('work/2008-06/shared-layouts/sol-axis-data-20261105')
h=lambda b:hashlib.sha256(b).hexdigest()
base,img=match._image('2008-06')
u=lambda a:struct.unpack_from('<I',img,a-base)[0]
b=lambda a,n:bytes(img[a-base:a-base+n])
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=True
original={'exe_sha256':h(Path('clients/2008-06/Roblox.exe').read_bytes()),'constructors':[],'tables':[],'rtti':{}}
def rtti(a,kind):
 key=hex(a)
 if key in original['rtti']:return
 n={'COL':20,'CHD':16,'BCD':24}.get(kind,8)
 row={'kind':kind,'bytes':b(a,n).hex()};original['rtti'][key]=row
 if kind=='COL':
  row['words']=[u(a+i*4) for i in range(5)];rtti(u(a+12),'TD');rtti(u(a+16),'CHD')
 elif kind=='CHD':
  row['words']=[u(a+i*4) for i in range(4)];arr=u(a+12);cnt=u(a+8);assert cnt<30
  original['rtti'][hex(arr)]={'kind':'base_array','bytes':b(arr,cnt*4).hex(),'targets':[hex(u(arr+4*i)) for i in range(cnt)]}
  for i in range(cnt):rtti(u(arr+4*i),'BCD')
 elif kind=='BCD':
  row['words']=[u(a+i*4) for i in range(6)];rtti(u(a),'TD')
 else:
  s=b(a+8,300).split(b'\0')[0];row['name']=s.decode('latin1');row['bytes']=b(a,8+len(s)+1).hex()
for va,n in [(0x640560,139),(0x6159f0,48)]:
 ins=list(md.disasm(b(va,n),va));row={'address':hex(va),'bytes':b(va,n).hex(),'disassembly':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in ins],'vptr_stores':[]}
 for i in ins:
  ops=i.operands
  if i.mnemonic=='mov' and len(ops)==2 and ops[0].type==capstone.x86.X86_OP_MEM and ops[1].type==capstone.x86.X86_OP_IMM:
   target=ops[1].imm&0xffffffff
   if base<target<base+len(img) and 0x800000<target<0x900000:
    cnt=5 if ops[0].mem.disp==4 else 16
    t={'constructor':hex(va),'store':hex(i.address),'operand':i.op_str,'address':hex(target),'subobject_offset':ops[0].mem.disp,'col':hex(u(target-4)),'bytes':b(target,cnt*4).hex(),'slots':[]}
    for j in range(cnt):
     dest=u(target+j*4);di=list(md.disasm(b(dest,16),dest))[:3]
     t['slots'].append({'index':j,'offset':j*4,'target':hex(dest),'entry_bytes':b(dest,16).hex(),'entry_disassembly':[f'{x.mnemonic} {x.op_str}' for x in di]})
    original['tables'].append(t);row['vptr_stores'].append(t['address']);rtti(u(target-4),'COL')
 original['constructors'].append(row)
(out/'original.json').write_text(json.dumps(original,indent=2))
print(json.dumps(original['constructors'],indent=2));print([(t['address'],[s['target'] for s in t['slots']]) for t in original['tables']])
# Original-only extraction above completes before any COFF names are read.
objpath=Path('work/2008-06/native-check-runs/20261105-131546-668ff08d/unit-000/candidate.obj')
raw=objpath.read_bytes();assert h(raw)=='e9f53666cd11d3c15c7985b8b24c11821d448840c2df2d3d66f28dda6bdbac7c'
inputs=json.loads(Path('work/2008-06/native-doc-relinks/20261105-141437-a0617a57/inputs.json').read_text())
report={'object':str(objpath),'object_sha256':h(raw),'input_count':len(inputs),'original_precedes_coff':True,'data':[],'weak_externals':[],'providers':[],'input_drift':[]}
primary=['const Name& getName() const','MouseCommand* onMouseDown(const UIEvent&)','void onMouseIdle(const UIEvent&)','void onMouseHover(const UIEvent&)','MouseCommand* onKeyDown(const UIEvent&)','MouseCommand* onPeekKeyDown(const UIEvent&)','void onMouseMove(const UIEvent&)','void onMouseDelta(const UIEvent&)','MouseCommand* onMouseUp(const UIEvent&)','void capture()','void releaseCapture()','void cancel()','virtual ~MouseCommand() deleting wrapper void*(unsigned int)','MouseCommand* isSticky() const','TextureId getCursorId() const','const std::string getCursorName() const']
secondary=['bool shouldRender2d() const','bool shouldRender3dAdorn() const','void render2d(Adorn*)','void render3dAdorn(Adorn*)','void render3dSelect(Adorn*, SelectState)']
needed=set();visited=set()
def examine(data,label,tables):
 secs,syms,defs,starts=match._coff_data_index(data);_,_,_,sp,ns,_,_=struct.unpack_from('<HHIIIHH',data)
 weak={}
 for idx,(name,val,sn,typ) in syms.items():
  storage,naux=struct.unpack_from('<BB',data,sp+idx*18+16)
  if storage==105 and naux:
   fallback,search=struct.unpack_from('<II',data,sp+(idx+1)*18);row={'input':label,'index':idx,'symbol':name,'aux_bytes':data[sp+(idx+1)*18:sp+(idx+2)*18].hex(),'fallback_index':fallback,'fallback_symbol':syms.get(fallback,[None])[0],'search':search,'rule':{1:'NOLIBRARY',2:'LIBRARY',3:'ALIAS'}.get(search,'unknown')};report['weak_externals'].append(row);weak[name]=row
 def walk(sym,addr):
  if (label,sym,addr) in visited:return
  visited.add((label,sym,addr))
  if sym not in defs:return
  v,s=defs[sym];sec=secs[s];following=[x for x in starts[s+1] if x>v];end=min(following) if following else sec[3];size=end-v
  if size<=0 or size>10000:return
  native=data[sec[4]+v:sec[4]+end];orig=b(addr,size);rels=[]
  for j in range(sec[7]):
   off,idx,kind=struct.unpack_from('<IIH',data,sec[5]+10*j)
   if v<=off<end:
    name=syms[idx][0];delta=off-v;add=struct.unpack_from('<i',native,delta)[0];target=u(addr+delta)
    if kind==20:target=(target+addr+delta+4)&0xffffffff
    target=(target-add)&0xffffffff
    rels.append({'offset':delta,'name':name,'kind':kind,'addend':add,'original_pointer':hex(u(addr+delta)),'original_target_minus_addend':hex(target),'identity_status':'independent original RTTI/slot record plus current declaration; body/provider gate separate','weak':weak.get(name)})
    needed.add(name)
    if kind==6 and name in defs and not secs[defs[name][1]][9]&0x20:walk(name,target)
  report['data'].append({'input':label,'symbol':sym,'address':hex(addr),'size':size,'native_hex':native.hex(),'original_hex':orig.hex(),'pointer_masked_equal':match.masked(native,[r['offset'] for r in rels])==match.masked(orig,[r['offset'] for r in rels]),'relocations':rels})
 for t in tables:
  offset=t['subobject_offset'];names=[n for n in defs if n.startswith('??_7') and (n.startswith('??_7AxisMoveTool@RBX@@6B') if t['constructor']=='0x640560' else 'MouseCommand@RBX@@6B' in n) and ('IRenderable' in n)==(offset==4)]
  for name in names:
   walk(name,int(t['address'],16));v,s=defs[name];sec=secs[s]
   # COL lives immediately before vftable symbol.
   for j in range(sec[7]):
    off,idx,kind=struct.unpack_from('<IIH',data,sec[5]+j*10)
    if off==v-4:walk(syms[idx][0],int(t['col'],16))
   rows=[x for x in report['data'] if x['input']==label and x['symbol']==name]
   if rows:
    byoff={r['offset']:r for r in rows[0]['relocations']}
    for slot in t['slots']:
     slot['prototype']=(secondary if offset==4 else primary)[slot['index']];slot['coff']=byoff.get(slot['offset']);slot['this_adjustment']='0 (primary full object)' if offset==0 else 'secondary ECX = full object +4; override entry adjustment must be established from original entry disassembly'
examine(raw,str(objpath),original['tables'][:2])
# Mouse vtables come from an actual current provider object, not candidate-generated addresses.
inv=json.loads(Path('work/2008-06/shared-layouts/sol-axis-lifetime-20261105/inventory.json').read_text())
r=next(r for r in inv['records'] if r['symbol']=='??0MouseCommand@RBX@@IAE@PAVWorkspace@1@@Z')
p=Path(r['path']);ar=p.read_bytes();off=r['archive_offset'];size=int(ar[off-12:off-2]) if off else len(ar);data=ar[off:off+size] if off else ar
examine(data,str(p)+'::'+r['member'],original['tables'][2:])
report['mouse_table_provider']={k:r[k] for k in ('path','member','input_sha256','member_sha256')};report['mouse_table_provider']['actual_input_sha256']=h(ar);report['mouse_table_provider']['actual_member_sha256']=h(data)
# Current inputs: verify every hash, inspect symbol definitions without compiling or linking.
for filename,expected in inputs.items():
 p=Path(filename);ar=p.read_bytes();digest=h(ar)
 if digest!=expected:report['input_drift'].append([filename,expected,digest])
 if p.suffix.lower() not in ('.obj','.lib'):continue
 members=[]
 if ar[:8]==b'!<arch>\n':
  off=8
  while off+60<=len(ar):
   size=int(ar[off+48:off+58]);members.append((ar[off:off+16].decode().strip(),ar[off+60:off+60+size]));off+=60+size+(size&1)
 else:members=[('',ar)]
 for member,data in members:
  if data[:2]!=b'\x4c\x01':continue
  secs,syms,defs,starts=match._coff_data_index(data)
  wanted=needed|{x['fallback_symbol'] for x in report['weak_externals']}
  for name in wanted & defs.keys():
   v,s=defs[name];sec=secs[s];end=min([x for x in starts[s+1] if x>v]+[sec[3]]);body=data[sec[4]+v:sec[4]+end]
   report['providers'].append({'symbol':name,'input':filename,'input_sha256':digest,'member':member,'member_sha256':h(data),'size':len(body),'body_hex':body.hex() if sec[9]&0x20 else None,'proof':'definition only; shared ICF body address cannot establish unique source identity'})
(out/'bindings.json').write_text(json.dumps(report,indent=2));(out/'original.json').write_text(json.dumps(original,indent=2))
print('data',len(report['data']),'weak',len(report['weak_externals']),'providers',len(report['providers']),'drift',len(report['input_drift']))

# Supplement: provider body evidence is conditional, never address discovery.
for t in original['tables']:
 for slot in t['slots']:
  edge=slot.get('coff')
  if not edge:continue
  name=edge['name'];fallback=edge.get('weak');names={name}
  if fallback:names.add(fallback['fallback_symbol'])
  matches=[]
  for p in report['providers']:
   if p['symbol'] not in names or p['body_hex'] is None:continue
   # Obtain relocation masks directly from actual object/member again.
   ar=Path(p['input']).read_bytes();data=ar
   if ar[:8]==b'!<arch>\n':
    off=8
    while off+60<len(ar):
     size=int(ar[off+48:off+58]);mn=ar[off:off+16].decode().strip()
     if mn==p['member'] and h(ar[off+60:off+60+size])==p['member_sha256']:data=ar[off+60:off+60+size];break
     off+=60+size+(size&1)
   for sym,body,refs in match.coff_functions(data):
    if sym==p['symbol']:
     matches.append({'provider_symbol':sym,'input':p['input'],'member':p['member'],'member_sha256':p['member_sha256'],'size':len(body),'normalized_code_equal':match.exact_match(b(int(slot['target'],16),len(body)),[],body,refs),'proof_limit':'code shape only; reloc identity, EH, ABI, selected ownership separate'})
  slot['providers']=matches
  if t['subobject_offset']==4:
   slot['this_adjustment']='0 at entry; ECX is IRenderable subobject (+4); original body uses this basis, no entry adjustor thunk'
  if not matches:slot['provider_status']='unresolved current input definition'
report['weak_rules']={'source':'https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#auxiliary-format-3-weak-externals','interpretation':'search=2 permits library search for _E; if absent linked, fallback auxiliary indexed _G is used. search=3 alias not observed. Failed link has no selected-PE confirmation.'}
report['identity_caveat']='COFF name paired with independently extracted pointer is a binding obligation. Masked equality, identical leaf bodies and ICF cannot uniquely identify original declaration. RTTI names/PMDs are independently recorded; Named intermediate vtables must not be assigned Axis constructor addresses.'
report['source_hashes']={str(p):h(p.read_bytes()) for p in [Path('rebuild/2008-06/native-headers/tool/AxisMoveTool.h'),Path('rebuild/2008-06/native-headers/tool/ToolsArrow.h'),Path('rebuild/2008-06/native-headers/v8datamodel/MouseCommand.h'),Path('rebuild/2008-06/native-headers/util/Name.h'),Path('rebuild/2008-06/native-headers/util/IRenderable.h')]}
report['extra_original_disassembly']={hex(va):[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(b(va,96),va)] for va in (0x640f30,0x641040,0x640780,0x5c6230)}
report['preserved_generic_eh']={'path':'work/2008-06/shared-layouts/sol-axis-ctor-20261105/eh.json','sha256':h(Path('work/2008-06/shared-layouts/sol-axis-ctor-20261105/eh.json').read_bytes()),'errors':json.loads(Path('work/2008-06/shared-layouts/sol-axis-ctor-20261105/eh.json').read_text())['errors']}
(out/'bindings.json').write_text(json.dumps(report,indent=2));(out/'original.json').write_text(json.dumps(original,indent=2))
print(json.dumps(report['extra_original_disassembly'],indent=2))
