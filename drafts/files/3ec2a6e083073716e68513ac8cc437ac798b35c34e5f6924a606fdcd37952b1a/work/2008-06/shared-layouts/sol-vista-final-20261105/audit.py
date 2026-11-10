from pathlib import Path
import sys,json,struct,hashlib
R=Path.cwd();sys.path.insert(0,str(R));from roc import libs,match
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
F=R/'work/2008-06/shared-layouts/sol-vista-final-20261105'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(n,v):(F/n).write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8')
archive=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib';old=next(b for n,b in libs.archive_members(archive) if Path(n).name=='FileSystem.obj');new=(F/'FileSystem.obj').read_bytes()
def signatures(raw):
 secs,syms,defs,starts=match._coff_data_index(raw);out={}
 for n,(start,idx) in defs.items():
  if n.startswith('.'):continue
  sec=secs[idx];end=min([v for v in starts[idx+1] if v>start]+[sec[3]]);data=raw[sec[4]+start:sec[4]+end] if sec[4] else bytes(end-start);rel=[]
  for i in range(sec[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i)
   if start<=off<end:rel.append((off-start,syms[sym][0],kind))
  out[n]=(data,rel)
 return out
a,b=signatures(old),signatures(new);changed=[{'symbol':n,'old_size':len(a[n][0]),'new_size':len(b[n][0]),'old_relocations':a[n][1],'new_relocations':b[n][1]} for n in sorted(a.keys()&b.keys()) if a[n]!=b[n]]
save('symbol-deltas.json',{'retained':len(a.keys()&b.keys()),'unchanged':sum(a[n]==b[n] for n in a.keys()&b.keys()),'changed':changed,'removed':sorted(a.keys()-b.keys()),'new':sorted(b.keys()-a.keys())})
md=Cs(CS_ARCH_X86,CS_MODE_32);lines=[]
for label,raw in [('current',old),('variant',new)]:
 for n,body,refs in match.coff_functions(raw):
  if 'getCacheDirectory' in n or 'VistaAPIs' in n:lines.extend([label+' '+n,'reloc offsets '+str(refs)]+[f'{i.address:04x} {i.mnemonic} {i.op_str}' for i in md.disasm(body,0)])
(F/'affected-disassembly.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8')
inputs={str(p):sha(p) for p in [archive,F/'FileSystem.obj',R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/FileSystem.command.json',R/'work/native-candidates/sol-vista-final-20261105/FileSystem.cpp',R/'work/2008-06/shared-layouts/sol-vista-owner-20261105/original-asm.txt']};save('guard-inputs.json',inputs)
save('campaign.json',{'swap_target':'CRobloxDoc diagnostic closure','baseline_receipt':'work/2008-06/native-doc-relinks/20261105-133846-f21c78c7/result.json','hypotheses':[{'id':1,'status':'rejected carried over','reason':'inline retains four duplicate COMDATs'},{'id':2,'status':'rejected carried over','reason':'remove four bodies regresses retained caller and EH/data'},{'id':3,'status':'rejected','compile_count':1,'reason':'forceinline ctor/dtor/wrapper, remove only GetIntegrity: three Vista definitions still emitted, caller and unwind changed'}],'status':'parked after three rejections','no_archive_produced':True,'no_loss_guard':False,'original_contract':{'cache':'005a7ea0 size548','ctor':'inlined 005a7ec5..005a7eee LoadLibraryA/GetProcAddress','GetIntegrity':'direct 005a7f07 to005a7780; explicit this pushed; header __stdcall','wrapper':'inlined null test005a7f2f indirect005a7f48','dtor':'inline FreeLibrary cleanup; standalone005a7770 size15 thiscall'},'missing_contract':'Source ownership mechanism retaining original cache+EH while suppressing three emitted standalone definitions; original standalone ctor/wrapper identity remains unproved. No ABI/layout changes permitted.','resume_queue':['Parent choose independently evidenced alternative provider ownership strategy; no further compile on this blocker without new evidence','Prove ctor/wrapper standalone targets and actual native provider identities independently','Parent retains cumulative link ownership; no global or canonical edits'], 'metrics':{'distinct_compiles':1,'retained_bodies':72,'unchanged_retained_bodies':70,'changed_retained_bodies':2,'remaining_vista_definitions':3,'new_inactive_exact':0,'selected_executable':0,'gated_swaps':0,'server_credit':0},'inputs':inputs})
print('named retained',len(a.keys()&b.keys()),'changed',len(changed));print(json.dumps(changed,indent=2))
