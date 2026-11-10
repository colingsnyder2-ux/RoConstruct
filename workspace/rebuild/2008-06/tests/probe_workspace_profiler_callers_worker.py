"""Frozen mixed-ABI link and object comparison; never execute output."""
import hashlib, json, re, struct, subprocess, sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import libs, match, rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'workspace-profiler-callers-worker';work.mkdir(parents=True,exist_ok=True)
old=out/'workspace-integrated-names-fullobj-worker';base=old/'donor-no-profiling.lib';candidates=out/'profiler-callers-worker'
proof=root/'work/2008-06/shared-layouts';receipt=json.loads((proof/'workspace-integrated-names-fullobj-worker.json').read_text())
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
assert sha(base)==receipt['filtered_archive_sha256']
members={str(n):data for n,data in libs.archive_members(base) if str(n) in ('SleepStage.obj','World.obj','Kernel.obj')}
assert len(members)==3
comparison={};objects=[]
def relocations(raw, functions):
    sections,symbols,defs,_=match._coff_data_index(raw); result={}
    for name,body,_ in functions:
        if name not in defs:continue
        start,index=defs[name];section=sections[index];items=[]
        for i in range(section[7]):
            off,sym,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
            if 0<=off<len(body):items.append((off,kind,symbols[sym][0]))
        result[name]=sorted(items)
    return result
for name,data in members.items():
    obj=candidates/name; objects.append(obj)
    donor_functions=match.coff_functions(data); candidate_raw=obj.read_bytes(); candidate_functions=match.coff_functions(candidate_raw)
    oldf={n:(b,r) for n,b,r in donor_functions};newf={n:(b,r) for n,b,r in candidate_functions};oldrel=relocations(data,donor_functions);newrel=relocations(candidate_raw,candidate_functions)
    shared=oldf.keys() & newf.keys(); same=[]; different=[]
    for symbol in sorted(shared):
        a,ar=oldf[symbol];b,br=newf[symbol]
        (same if match.exact_match(a,ar,b,br) else different).append(symbol)
    comparison[name]={'donor_sha256':hashlib.sha256(data).hexdigest(),'candidate_sha256':sha(obj),'same_normalized':same,'different_normalized':different,'different_relocations':[s for s in sorted(shared) if oldrel.get(s)!=newrel.get(s)],'donor_only':sorted(oldf.keys()-newf.keys()),'candidate_only':sorted(newf.keys()-oldf.keys())}
archive=work/'replaced.lib';args=['/nologo','/OUT:'+str(archive),'/REMOVE:SleepStage.obj','/REMOVE:World.obj','/REMOVE:Kernel.obj',str(base)]+list(map(str,objects))
code,log=rebuild.run(rebuild.toolchain(21022),'lib',args,work);assert code==0,log
args=[]
for line in (old/'candidate.rsp').read_text().splitlines():
    arg=line.strip().strip(chr(34))
    if arg.upper().startswith('/OUT:'):arg='/OUT:'+str(work/'candidate.exe')
    elif arg.upper().startswith('/MAP:'):arg='/MAP:'+str(work/'candidate.map')
    elif arg.lower()==str(base).lower():arg=str(archive)
    args.append(arg)
rsp=work/'candidate.rsp';rsp.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args)+'\n');code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);(work/'candidate.log').write_text(log)
errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)\b',x)]
result={'scope':'Diagnostic only; mixed ABI and original method identity unproven, never execute. Comparison masks relocated values; callee identities are not compared.', 'baseline_receipt_sha256':sha(proof/'workspace-integrated-names-fullobj-worker.json'),'archive_sha256':sha(archive),'comparison':comparison,'baseline_errors':receipt['candidate_errors'],'candidate_errors':errors,'candidate_exit':code}
(proof/'workspace-profiler-callers-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('baseline',len(receipt['candidate_errors']),'candidate',len(errors));
for n,v in comparison.items():print(n,'same',len(v['same_normalized']),'different',len(v['different_normalized']),'donor-only',len(v['donor_only']),'candidate-only',len(v['candidate_only']))
