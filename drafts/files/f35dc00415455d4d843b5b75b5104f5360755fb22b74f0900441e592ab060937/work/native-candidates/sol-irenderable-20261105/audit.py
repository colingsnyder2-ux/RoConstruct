from pathlib import Path
import sys,json,hashlib,struct
R=Path.cwd();sys.path.insert(0,str(R));from roc import match,libs
F=R/'work/2008-06/shared-layouts/sol-irenderable-20261105'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(n,v):(F/n).write_text(json.dumps(v,indent=2)+'\n')
base=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib';assert sha(base)=='0c597337028cf2cda5addf6ededafd11d546ec6205720401a5e1c166ab1b0836'
ms=list(libs.archive_members(base));name,old=next((n,b) for n,b in ms if Path(n).name=='IRenderable.obj');new=(F/'run/unit-001/candidate.obj').read_bytes()
def signatures(raw):
 secs,syms,defs,starts=match._coff_data_index(raw);out={}
 for n,(start,idx) in defs.items():
  if n.startswith('.'):continue
  sec=secs[idx];end=min([v for v in starts[idx+1] if v>start]+[sec[3]]);data=raw[sec[4]+start:sec[4]+end] if sec[4] else bytes(end-start);rel=[]
  for i in range(sec[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i)
   if start<=off<end:rel.append((off-start,syms[sym][0],kind))
  out[n]=(data.hex(),rel)
 return out
a,b=signatures(old),signatures(new);lost=set(a)-set(b);changed=[n for n in a.keys()&b.keys() if a[n]!=b[n]]
fa={n:(v.hex(),sorted(r)) for n,v,r in match.coff_functions(old)};fb={n:(v.hex(),sorted(r)) for n,v,r in match.coff_functions(new)}
save('comparison.json',{'archive':str(base),'archive_sha256':sha(base),'member':name,'member_sha256':hashlib.sha256(old).hexdigest(),'candidate_sha256':hashlib.sha256(new).hexdigest(),'all_symbols_removed':sorted(lost),'all_symbols_changed':changed,'all_symbols_added':sorted(b.keys()-a.keys()),'functions_removed':sorted(fa.keys()-fb.keys()),'functions_changed':[n for n in fa.keys()&fb.keys() if fa[n]!=fb[n]],'retained_functions':len(fa.keys()&fb.keys()),'differences':{n:{'old':a[n],'new':b[n]} for n in changed}})
inputs=json.loads((R/'work/2008-06/native-doc-relinks/20261105-135622-0161a2a8/inputs.json').read_text());inv=[];cons=[];providers={};count=0
for p,h in inputs.items():
 path=Path(p);assert sha(path)==h,(p,'drift');inv.append({'path':p,'sha256':h});objects=list(libs.archive_members(path)) if path.suffix.lower()=='.lib' else [(str(path),path.read_bytes())] if path.suffix.lower()=='.obj' else []
 for member,raw in objects:
  if path==base and member==name:raw=new
  try:secs,syms,defs,_=match._coff_data_index(raw)
  except (struct.error,IndexError,ValueError):continue
  count+=1
  for n in lost&set(defs):providers.setdefault(n,[]).append(p+'('+member+')')
  used=set()
  for sec in secs:
   for i in range(sec[7]):
    off,idx,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i)
    if syms[idx][0] in lost:used.add(syms[idx][0])
  if used:cons.append({'input':p,'member':member,'symbols':sorted(used)})
save('consumer-audit.json',{'explicit_inputs':len(inv),'inputs':inv,'objects':count,'consumers':cons,'providers_without_native':providers,'missing_without_native':sorted(set(n for c in cons for n in c['symbols'])-set(providers))})
# independent genuine Mouse adjustment evidence, full bounded instructions
import capstone
ib,img=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
save('mouse-original.json',{'00615780':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(bytes(img[0x615780-ib:0x61579b-ib]),0x615780)]})
c=json.loads((R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/IRenderable.command.json').read_text());drift=[p for p,h in c['dependencies'].items() if not Path(p).exists() or sha(p)!=h];save('donor-dependency-check.json',{'drift':drift,'command_sha256':sha(R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/IRenderable.command.json')})
print('changed',changed,'lost',sorted(lost),'inputs',len(inv),'objects',count,'dependency drift',drift)
