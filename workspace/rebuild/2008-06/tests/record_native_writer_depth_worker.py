import json,sys,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts/writer-depth-worker';(out/'v8xml').mkdir(parents=True,exist_ok=True);(out/'v8xml/XmlSerializer.h').write_text((root/'rebuild/2008-06/out/native-layouts/write-worker/v8xml/XmlSerializer.h').read_text());orig=(root/'rebuild/2008-06/tests/NativeWorkspaceWriterNearWorker.cpp').read_text();assert orig.count('#pragma inline_depth(1)')==1
prior=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];flags[:0]=['/I'+str(out),'/I'+str(root/'rebuild/2008-06/tests')];t,tr,_=match.target('2008-06','0046b860');rows=[]
for depth in (0,2,3,4,5,8,12,16):
 text=orig.replace('#pragma inline_depth(1)','#pragma inline_depth(%d)'%depth);src=out/('depth%d.cpp'%depth);src.write_text(text);obj=out/('depth%d.obj'%depth);c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);row={'depth':depth,'exit':c}
 if c:row['errors']=[x for x in log.splitlines() if 'error C' in x][:3]
 else:
  raw=obj.read_bytes();n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith('?write@CWorkspace@@'));row.update(size=len(b),exact=match.exact_match(t,tr,b,r));ss,sy,defs,_=match._coff_data_index(raw);o,i=defs['__unwindtable$'+n];row['eh_states']=struct.unpack_from('<I',raw,ss[i][4]+o+12)[0]
 rows.append(row);print(row,flush=True)
 if row.get('exact'):break
(root/'work/2008-06/shared-layouts/writer-depth-worker.json').write_text(json.dumps({'scope':'Compiler inline-depth variants for typed genuine-shaped writer; no runtime claim.','variants':rows,'observer_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()},indent=2)+'\n')
