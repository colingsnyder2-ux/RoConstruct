import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/body-order-worker';s=(root/'rebuild/2008-06/out/native-layouts/part-layout-worker/PartContentBodyWorker.cpp').read_text();needle='stateIndex(getNextStateIndex()), moment(G3D::Matrix3::identity()), mass(0.0f) {'
variants=[s.replace(needle,'moment(G3D::Matrix3::identity()) { mass = 0.0f; stateIndex = getNextStateIndex();'),s.replace(needle,'stateIndex(getNextStateIndex()), moment(G3D::Matrix3::identity()) { mass = 0.0f;'),s.replace(needle,'moment(G3D::Matrix3::identity()), mass(0.0f) { stateIndex = getNextStateIndex();'),s.replace('float mass;\n\t\t\tmutable int stateIndex;','float mass;\n\t\t\tmutable int stateIndex;').replace('mass(0.0f)','mass()')]
target,refs,_=match.target('2008-06','006149c0');rows=[]
for i,v in enumerate(variants):
 src=work/('body%d.cpp'%i);obj=work/('body%d.obj'%i);src.write_text(v);flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work)
 if c: print(i,'compile failed',log[-300:],flush=True);continue
 name,body,rel=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('??0Body@RBX@@'));exact=match.exact_match(target,refs,body,rel);print(i,len(body),exact,flush=True);rows.append({'variant':i,'size':len(body),'exact':exact})
 if exact: break
(work/'body-results.json').write_text(json.dumps(rows,indent=2))
