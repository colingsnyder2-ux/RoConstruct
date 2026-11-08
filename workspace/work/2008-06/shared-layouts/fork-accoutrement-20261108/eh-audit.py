"""Compare existing native x86 EH metadata graph to the original; never compile/run."""
from pathlib import Path
import argparse,capstone,hashlib,json,struct,sys
ROOT=Path('C:\\Users\\colin\\RoConstruct');sys.path.insert(0,str(ROOT))
from roc import match,native_asm,rebuild
parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('object',type=Path);parser.add_argument('address',type=lambda x:int(x,16));parser.add_argument('symbol');parser.add_argument('--output',type=Path);parser.add_argument('--provider',nargs=2,action='append',default=[],metavar=('SYMBOL','OBJECT'));args=parser.parse_args();path=args.object;raw=path.read_bytes();secs,syms,defs,starts=match._coff_data_index(raw);funcs={n:(b,r) for n,b,r in match.coff_functions(raw)};base,image=match._image('2008-06');address=args.address
name=next(n for n in funcs if n.startswith(args.symbol));body,refs=funcs[name];fv,fs=defs[name];full=bytes(image[address-base:address-base+len(body)]);bindings={};events=[];seen=set();errors=[]
# Candidate relocation fields must correspond to original absolute or direct-branch operands.
# The mined function index can stop before a compiler-owned catch/cleanup tail.
primary_disassembler=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
def address_fields(data,va):
 return {x-va for x in match._base_relocs('2008-06') if va<=x<va+len(data)}|{i.address-va+1 for i in primary_disassembler.disasm(data,va) if i.size==5 and i.bytes[0] in (0xe8,0xe9)}
primary_refs=address_fields(full,address)
if not set(refs)<=primary_refs:
 raise SystemExit('candidate relocation is not an original address operand; EH proof refused')
# Resolve only COFF-declared weak fallbacks; availability is not final PE selection.
weak={};symbol_offset,symbol_count=struct.unpack_from('<II',raw,8);symbol_index=0
while symbol_index<symbol_count:
 offset=symbol_offset+symbol_index*18;storage,aux=struct.unpack_from('<BB',raw,offset+16)
 if storage==105 and aux:
  tag,search=struct.unpack_from('<II',raw,offset+18)
  weak[syms[symbol_index][0]]={'fallback':syms[tag][0],'search_characteristic':search}
 symbol_index+=1+aux

object_id=hashlib.sha256(raw).hexdigest()
providers={};used_providers=set()
for symbol,filename in args.provider:
 provider_path=Path(filename);provider_raw=provider_path.read_bytes()
 _,_,provider_defs,_=match._coff_data_index(provider_raw)
 if symbol not in provider_defs:raise ValueError('exact provider symbol missing: '+symbol)
 if symbol in providers:raise ValueError('duplicate provider symbol: '+symbol)
 providers[symbol]=(provider_path,provider_raw,hashlib.sha256(provider_raw).hexdigest())

def u(va):return struct.unpack_from('<I',image,va-base)[0]
def relocs(sec):
 s=secs[sec];return [struct.unpack_from('<IIH',raw,s[5]+i*10) for i in range(s[7])]
def bind(symbol,va):
 if symbol in bindings:assert bindings[symbol]==va,(symbol,bindings[symbol],va)
 bindings[symbol]=va
for off,idx,kind in relocs(fs):
 if fv<=off<fv+len(body):
  delta=off-fv;value=struct.unpack_from('<I',full,delta)[0]
  if kind==20:value=(address+delta+4+struct.unpack_from('<i',full,delta)[0])&0xffffffff
  # DIR32 operands include member offsets; bind the symbol base.
  if kind==6:value=(value-struct.unpack_from('<i',body,delta)[0])&0xffffffff
  bind(syms[idx][0],value)
original_relocs=[x-address for x in match._base_relocs('2008-06') if address<=x<address+len(body)]
assert set(original_relocs)<=set(refs) and match.exact_match(full,original_relocs,body,refs),'primary body must already match before EH graph audit'
handler=next(n for n in bindings if n=='__ehhandler$'+name)
import_aliases={};import_inputs=[]
crt_library=ROOT/'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/lib'
for archive in (crt_library/'msvcrt.lib',crt_library/'msvcprt.lib',rebuild.toolchain(21022)['sdk_lib']/'kernel32.lib'):
 blob=archive.read_bytes();import_inputs.append((archive,hashlib.sha256(blob).hexdigest()));assert blob[:8]==b'!<arch>\n';offset=8
 while offset+60<=len(blob):
  size=int(blob[offset+48:offset+58]);member=blob[offset+60:offset+60+size];offset+=60+size+(size&1)
  if member[:4]!=b'\0\0\xff\xff':continue
  name,dll=member[20:].split(b'\0')[:2];name=name.decode();dll=dll.decode().lower();name_type=(struct.unpack_from('<H',member,18)[0]>>2)&7
  if name_type==1:export=name
  elif name_type in (2,3):
   export=name[1:] if name[:1] in ('_','@','?') else name
   if name_type==3:export=export.split('@',1)[0]
  else:continue
  import_aliases[(dll,export)]=name

def external(symbol,va):
 if symbol=='??_7type_info@@6B@':
  # The compiler's common type_info vtable is independently anchored by
  # original RTTI descriptors whose class hierarchies were already checked.
  anchors=[]
  for typename in (b'.?AVCWorkspace@@\0',b'.?AVInstance@RBX@@\0'):
   at=image.find(typename);assert at>=8
   descriptor=base+at-8;assert u(descriptor+4)==0
   anchors.append({'type':typename[:-1].decode(),'descriptor':hex(descriptor),'vtable':hex(u(descriptor))})
  ok=all(int(x['vtable'],16)==va for x in anchors)
  events.append({'kind':'canonical type_info vtable binding','original':hex(va),'anchors':anchors,'exact':ok})
  return ok
 if symbol in bindings:return bindings[symbol]==va
 label=native_asm.thunk_label('2008-06',va)
 if symbol.startswith('__imp_'):
  label=native_asm.names('2008-06').get(va)
  symbol=symbol[len('__imp_'):]
  if label and label.lower().startswith('mfc90.dll!#'):
   label=native_asm.mfc_ordinals().get(int(label.rsplit('#',1)[1]))
 if not label:return False
 export=label.removeprefix('MFC ') if label.startswith('MFC ') else label.split('!',1)[-1]
 if '!' in label:
  dll=label.split('!',1)[0].lower()
  if import_aliases.get((dll,export))==symbol:return True
 return symbol in (export,'_'+export)
def walk(symbol,va,addend=0):
 global raw,secs,syms,defs,starts,funcs,weak,fs,fv,body,object_id
 if symbol not in defs and symbol in providers:
  provider_path,provider_raw,provider_id=providers[symbol]
  saved=(raw,secs,syms,defs,starts,funcs,weak,fs,fv,body,object_id)
  raw=provider_raw;secs,syms,defs,starts=match._coff_data_index(raw)
  funcs={n:(b,r) for n,b,r in match.coff_functions(raw)};weak={};fs=-1;fv=0;body=b'';object_id=provider_id
  offset,count=struct.unpack_from('<II',raw,8);index=0
  while index<count:
   position=offset+index*18;storage,aux=struct.unpack_from('<BB',raw,position+16)
   if storage==105 and aux:
    tag,search=struct.unpack_from('<II',raw,position+18)
    weak[syms[index][0]]={'fallback':syms[tag][0],'search_characteristic':search}
   index+=1+aux
  used_providers.add(symbol)
  events.append({'kind':'explicit object provider','symbol':symbol,'object':str(provider_path),'object_sha256':provider_id,'scope':'Availability only; traversed bytes/operands must independently match original. Final PE selection/ABI unproven.'})
  try:walk(symbol,va,addend)
  finally:raw,secs,syms,defs,starts,funcs,weak,fs,fv,body,object_id=saved
  return
 key=(object_id,symbol,va,addend)
 if key in seen:return
 seen.add(key)
 if symbol in weak and symbol not in defs:
  alias=weak[symbol];assert alias['search_characteristic']==2,alias
  events.append({'kind':'COFF weak fallback availability','symbol':symbol,'fallback':alias['fallback'],'original':hex(va),'scope':'Final PE weak selection unproven'})
  walk(alias['fallback'],va,addend);return
 if symbol not in defs:
  ok=external(symbol,va);events.append({'symbol':symbol,'original':hex(va),'kind':'external','exact':ok});assert ok,events[-1];return
 value,sec=defs[symbol];value+=addend;s=secs[sec]
 if sec==fs and fv<=value<fv+len(body):
  ok=va==address+value-fv;events.append({'symbol':symbol,'original':hex(va),'kind':'in-function continuation','exact':ok});assert ok;return
 code=bool(s[9]&0x20)
 if code:
  assert addend==0 and symbol in funcs,(symbol,addend)
  data,mask=funcs[symbol];other=bytes(image[va-base:va-base+len(data)]);assert set(mask)<=address_fields(other,va),(symbol,'non-address relocation');ok=match.exact_match(other,[],data,mask);events.append({'symbol':symbol,'original':hex(va),'kind':'cleanup/handler code','size':len(data),'exact':ok});assert ok,events[-1]
  for off,idx,kind in relocs(sec):
   if value<=off<value+len(data):
    delta=off-value;dest=syms[idx][0];original=u(va+delta)
    if kind==20:
     original=(va+delta+4+struct.unpack_from('<i',other,delta)[0])&0xffffffff
     if dest in defs or dest in weak or dest in providers:walk(dest,original)
     else:assert external(dest,original),(symbol,dest,hex(original))
    elif kind==6:
     bias=struct.unpack_from('<i',data,delta)[0];walk(dest,original,bias)
  return
 end=next((x for x in starts[sec+1] if x>value),s[3]);assert 0<=value<end<=s[3],(symbol,'invalid data range',value,end,s[3])
 rels=[(o-value,i,k) for o,i,k in relocs(sec) if value<=o<end];zero_initialized=bool(s[9]&0x80)
 if zero_initialized:
  assert not rels,(symbol,'relocations in uninitialized storage');data=bytes(end-value)
 else:
  assert s[4]>0 and s[4]+end<=len(raw),(symbol,'truncated initialized data');data=raw[s[4]+value:s[4]+end]
 other=bytes(image[va-base:va-base+len(data)]);mask=[o for o,i,k in rels];ok=match.exact_match(other,mask,data,mask);events.append({'symbol':symbol,'original':hex(va),'kind':'EH data','size':len(data),'exact':ok,'zero_initialized':zero_initialized,'original_bytes':other.hex(),'native_bytes':data.hex()});assert ok,events[-1]
 for off,idx,kind in rels:
  assert kind==6;dest=syms[idx][0];pointer=u(va+off);assert base<=pointer<base+len(image),(symbol,off,pointer);bias=struct.unpack_from('<i',data,off)[0];walk(dest,pointer,bias)
try:walk(handler,bindings[handler])
except AssertionError as error:errors.append(str(error))
for provider_path,provider_raw,provider_id in providers.values():
 if hashlib.sha256(provider_path.read_bytes()).hexdigest()!=provider_id:errors.append('provider input changed: '+str(provider_path))
if hashlib.sha256(path.read_bytes()).hexdigest()!=object_id:errors.append('primary object input changed')
for archive,digest in import_inputs:
 if hashlib.sha256(archive.read_bytes()).hexdigest()!=digest:errors.append('import library input changed: '+str(archive))
out=args.output or ROOT/('work/2008-06/eh-graph-%08x.json'%address);out.parent.mkdir(parents=True,exist_ok=True);out.write_text(json.dumps({'scope':__doc__+' Pointer bindings in cleanup are checked against normal-body references/imports; not whole dependency ABI/runtime proof.','address':'%08x'%address,'primary_body_size':len(body),'primary_body_exact':True,'tool_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'original_sha256':hashlib.sha256((ROOT/'clients/2008-06/Roblox.exe').read_bytes()).hexdigest(),'object':str(path),'object_sha256':hashlib.sha256(raw).hexdigest(),'import_library_inputs':[{'library':str(p),'sha256':h} for p,h in import_inputs],'provider_inputs':[{'symbol':n,'object':str(v[0]),'sha256':v[2],'used':n in used_providers} for n,v in providers.items()],'events':events,'errors':errors},indent=2)+'\n');print('EH graph nodes',len(events),'errors',len(errors));print(errors[:1]);assert not errors
