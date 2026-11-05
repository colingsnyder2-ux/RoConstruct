from pathlib import Path
import sys,json,struct,hashlib
R=Path.cwd();sys.path.insert(0,str(R));from roc import libs,match
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
F=R/'work/2008-06/shared-layouts/sol-vista-owner-20261105'
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
a,b=signatures(old),signatures(new);changed=[]
for n in a.keys()&b.keys():
 if a[n]!=b[n]:
  x,y=a[n],b[n];changed.append({'symbol':n,'old_size':len(x[0]),'new_size':len(y[0]),'first_byte_difference':next((i for i,(p,q) in enumerate(zip(x[0],y[0])) if p!=q),None),'old_relocations':x[1],'new_relocations':y[1]})
save('symbol-deltas.json',{'retained':len(a.keys()&b.keys()),'unchanged':sum(a[n]==b[n] for n in a.keys()&b.keys()),'changed':changed,'removed':sorted(a.keys()-b.keys()),'new':sorted(b.keys()-a.keys())})
md=Cs(CS_ARCH_X86,CS_MODE_32)
lines=[]
for label,raw in [('current',old),('variant',new)]:
 for n,body,refs in match.coff_functions(raw):
  if 'getCacheDirectory' in n or 'VistaAPIs' in n:
   lines.extend([label+' '+n,'reloc offsets '+str(refs)]+[f'{i.address:04x} {i.mnemonic} {i.op_str}' for i in md.disasm(body,0)])
(F/'affected-disassembly.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8')
rows=[]
for line in (R/'work/2008-06/functions.jsonl').read_text().splitlines():
 row=json.loads(line)
 if row['addr'] in ['005a7770','005a7780','005a7ac0'] or ('Roblox\\Cache' in row.get('strings',[]) and 'SHGetKnownFolderPath' in row.get('strings',[])):rows.append(row)
save('original-evidence.json',rows)
inputs={str(p):sha(p) for p in [archive,F/'FileSystem.obj',R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/FileSystem.command.json',R/'work/native-candidates/sol-vista-owner-20261105/FileSystem.cpp']};save('guard-inputs.json',inputs)
save('campaign.json',{'swap_target':'CRobloxDoc diagnostic closure','baseline_receipt':'work/2008-06/native-doc-relinks/20261105-133112-e038d1b8/result.json','hypotheses':[{'id':1,'status':'rejected upstream','reason':'inline annotations retain four duplicate COMDAT definitions'},{'id':2,'status':'rejected retained-code regression','compile_count':1,'change':'remove only four Vista method definitions; authentic header and canonical flags unchanged','remaining_duplicate_definitions':0,'retained_bodies':69,'unchanged_retained_bodies':66,'changed_bodies':3}],'next_gate':'Parent guidance required before another compile; original cache caller embeds Vista ctor/wrapper/dtor and removing definitions changes body and EH. No archive replacement permitted by no-loss guard.','metrics':{'new_inactive_exact':0,'selected_executable':0,'gated_swaps':0,'server_credit':0},'inputs':inputs})
print('named retained',len(a.keys()&b.keys()),'changed',len(changed));print([(r['addr'],r['size']) for r in rows])
