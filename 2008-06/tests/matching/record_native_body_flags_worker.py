import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/body-order-worker';src=root/'rebuild/2008-06/out/native-layouts/part-layout-worker/PartContentBodyWorker.cpp'; target,refs,_=match.target('2008-06','006149c0'); rows=[]
for i,extra in enumerate([['/fp:fast'],['/favor:INTEL64'],['/favor:blend'],['/Os'],['/Ot'],['/Ob1'],['/fp:precise'],['/arch:SSE2']]):
 obj=work/('flag%d.obj'%i);flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD']+extra+['/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work)
 if c: print(i,'compile failed',log[-100:],flush=True);continue
 _,body,rel=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('??0Body@RBX@@'));exact=match.exact_match(target,refs,body,rel);print(extra,len(body),exact,flush=True);rows.append({'flags':extra,'size':len(body),'exact':exact})
 if exact: break
(work/'flag-results.json').write_text(json.dumps(rows,indent=2))
