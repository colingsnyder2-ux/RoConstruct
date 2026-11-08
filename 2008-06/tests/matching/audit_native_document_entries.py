"""Read-only Doc entrypoint audit from original vtable/message map and selected objects."""
import argparse, ast, hashlib, json, struct, sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[4]
sys.path.insert(0,str(ROOT))
from roc import match, native_asm
parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('run',type=Path);run=ROOT/parser.parse_args().run;assert (run/'result.json').exists()
main=run/'output/NativeCRobloxDoc.obj';raw=main.read_bytes();secs,syms,defs,_=match._coff_data_index(raw)
base,image=match._image('2008-06');objects={};functions={}
for path in [main,*sorted((run/'output').glob('NativeDocument*Full.obj'))]:
 data=path.read_bytes();objects[path.name]=hashlib.sha256(data).hexdigest()
 for name,body,refs in match.coff_functions(data):functions.setdefault(name,[]).append((path,data,body,refs))
# MSVC emits a weak vector-deleting-destructor reference with scalar fallback.
# Audit available fallback code explicitly; this is not final PE selection proof.
weak={};ptr,num=struct.unpack_from('<II',raw,8);i=0
while i<num:
 off=ptr+18*i;storage,aux=struct.unpack_from('<BB',raw,off+16);name=syms[i][0]
 if storage==105 and aux:
  tag,search=struct.unpack_from('<II',raw,off+18);fallback=syms[tag][0]
  if name not in functions and fallback in functions:
   weak[name]={'fallback':fallback,'search_characteristic':search};functions[name]=functions[fallback]
 i+=1+aux
entries={}
def add(symbol,addr,origin):
 if symbol in entries:assert entries[symbol]['address']==addr,(symbol,entries[symbol],addr)
 else:entries[symbol]={'address':addr,'origins':[]}
 entries[symbol]['origins'].append(origin)
def prefix(name):
 hits=[n for n in functions if n.startswith(name)];assert len(hits)==1,(name,hits)
 return hits[0]
v,section=defs['??_7CRobloxDoc@@6B@'];table=secs[section];inherited=[]
for i in range(table[7]):
 off,idx,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);slot=(off-v)//4
 if off<v or not 0<=slot<46:continue
 name=syms[idx][0]
 if '@CRobloxDoc@@' in name or name.startswith(('??_ECRobloxDoc@@','??_GCRobloxDoc@@','?OnCmdMsg@?$VerbBinder@VCRobloxDoc')):
  add(name,struct.unpack_from('<I',image,0x817ce4-base+slot*4)[0],'vtable:'+str(slot))
 else:
  addr=struct.unpack_from('<I',image,0x817ce4-base+slot*4)[0];label=native_asm.thunk_label('2008-06',addr);item={'slot':slot,'symbol':name,'original_address':'%08x'%addr,'original_import':label}
  if label:item['verified']=label.removeprefix('MFC ')==name;item['proof']='exact MFC export binding'
  else:
   found=functions.get(name,[]);target,tr,_=match.target('2008-06','%08x'%addr);item['verified']=len(found)==1 and match.exact_match(target,tr,found[0][2],found[0][3]);item['proof']='historical inline MFC body'
  inherited.append(item)
msg=next(n for n in defs if n.startswith('?_messageEntries@?1??GetThisMessageMap@CRobloxDoc@@'))
v,section=defs[msg];table=secs[section];refs={}
for i in range(table[7]):
 off,idx,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);refs[off-v]=syms[idx][0]
for i in range(39):
 pos=i*24;original=struct.unpack_from('<6I',image,0x817f18-base+pos);candidate=struct.unpack_from('<6I',raw,table[4]+v+pos)
 assert original[:5]==candidate[:5] and candidate[5]==0
 add(refs[pos+20],original[5],'message:'+str(i))
assert struct.unpack_from('<6I',image,0x817f18-base+39*24)==(0,)*6
assert struct.unpack_from('<6I',raw,table[4]+v+39*24)==(0,)*6
tree=ast.parse((ROOT/'rebuild/2008-06/tests/record_native_document.py').read_text())
for node in ast.walk(tree):
 if isinstance(node,ast.For) and isinstance(node.target,ast.Tuple) and [getattr(n,'id',None) for n in node.target.elts]==['address','method']:
  for addr,method in ast.literal_eval(node.iter):add(prefix('?'+method+'@CRobloxDoc@@'),int(addr,16),'recorder')
for addr,symbol in [('00451ac0','??0CRobloxDoc@@'),('00451940','??1CRobloxDoc@@'),('00451b60','?initializeCommands@CRobloxDoc@@'),('00455a20','?loadFile@CRobloxDoc@@'),('00454ac0','?loadFromString@CRobloxDoc@@')]:add(prefix(symbol),int(addr,16),'class-helper')
runtime=struct.unpack_from('<I',image,0x44f201-base)[0]
base_getter=struct.unpack_from('<I',image,runtime-base+16)[0]
add(prefix('?GetThisClass@CRobloxDoc@@'),0x44f200,'folded-runtime-helper')
add(prefix('?GetThisMessageMap@CRobloxDoc@@'),0x455d20,'folded-message-helper')
add(prefix('?_GetBaseClass@CRobloxDoc@@'),base_getter,'original-runtime-descriptor')
rows=[]
for name,item in entries.items():
 addr=item['address'];found=functions.get(name,[]);row={'symbol':name,'original_address':'%08x'%addr,'origins':item['origins'],'providers':len(found)}
 if len(found)==1:
  path,data,body,refs=found[0];code_name=weak.get(name,{}).get('fallback',name);row['code_symbol']=code_name;row['weak_fallback']=weak.get(name);target,tr,_=match.target('2008-06','%08x'%addr)
  extended=False
  if addr==0x454ac0 and len(body)==459 and len(target)==385:
   assert addr+len(body)<=0x454c90
   extra=[r-addr for r in match._base_relocs('2008-06') if addr+len(target)<=r<addr+len(body)];assert extra==[0x189,0x1b2]
   target=bytes(image[addr-base:addr-base+len(body)]);tr+=extra;extended=True
  exact=set(tr)<=set(refs) and match.exact_match(target,tr,body,refs)
  dm,de=match.data_check('2008-06','%08x'%addr,target,match.coff_data_refs(data,code_name)) if exact else ([],[])
  row.update(object=path.name,size=len(body),target_size=len(target),body_exact=exact,data_errors=de,adjacent_catch_verified=extended)
 rows.append(row)
unmapped=sorted(n for n in functions if n.startswith('?') and ('@CRobloxDoc@@' in n or n.startswith(('??0CRobloxDoc@@','??1CRobloxDoc@@','??_ECRobloxDoc@@','??_GCRobloxDoc@@'))) and n not in entries and n not in {weak[x]['fallback'] for x in entries if x in weak})
result={'tool_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'original_sha256':hashlib.sha256((ROOT/'clients/2008-06/Roblox.exe').read_bytes()).hexdigest(),'run_result_sha256':hashlib.sha256((run/'result.json').read_bytes()).hexdigest(),'unique_original_entrypoints':len({item['address'] for item in entries.values()}),'inherited_vtable_slots':inherited,'inherited_bindings_verified':sum(x['verified'] for x in inherited),'message_entries_verified':39,'weak_reference_scope':'Fallback code availability only; final weak/linker selection remains unproven until clean native link.','unmapped_generated_or_helper_symbols':unmapped,'scope':'Original-owned Doc entrypoints and selected COFF bodies/data; not linked PE, all call identity, exception metadata, dependency ABI or runtime proof','run':str(run),'objects':objects,'methods':sorted(rows,key=lambda x:x['original_address']),'entrypoints':len(rows),'verified':sum(x.get('body_exact',False) and not x.get('data_errors') for x in rows)}
(run/'doc-own-entrypoints.json').write_text(json.dumps(result,indent=2)+'\n')
print('Doc native symbols',result['verified'],'/',result['entrypoints'],'unique original entrypoints',result['unique_original_entrypoints'],'inherited slots',result['inherited_bindings_verified'],'/',len(inherited))
for row in rows:
 if not row.get('body_exact') or row.get('data_errors'):print(row)

assert result["verified"]==result["entrypoints"]
assert all(x["verified"] for x in inherited)
assert not unmapped, unmapped
