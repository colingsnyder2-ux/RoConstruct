import sys,json,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild,match
w=root/'rebuild/2008-06/out/native-layouts/writer-context2-worker';(w/'v8xml').mkdir(parents=True,exist_ok=True);(w/'v8xml/XmlSerializer.h').write_text((root/'rebuild/2008-06/out/native-layouts/write-worker/v8xml/XmlSerializer.h').read_text());writer=(root/'rebuild/2008-06/tests/NativeWorkspaceWriterNearWorker.cpp').read_text();writes=(root/'rebuild/2008-06/tests/NativeWorkspaceWriteTrial.cpp').read_text();base=(root/'rebuild/2008-06/native-classes/CWorkspace.cpp').read_text().replace('../native-headers/CWorkspace.h','CWorkspace.h').replace('../native-headers/v8datamodel/','v8datamodel/');variants=[('writer_then_base',writer+'\n'+base),('writer_then_all',writer+'\n'+base+'\n'+writes)]
prior=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];flags[:0]=['/I'+str(w),'/I'+str(root/'rebuild/2008-06/tests')];t,tr,_=match.target('2008-06','0046b860');rows=[]
for name,text in variants:
 src=w/(name+'.cpp');src.write_text(text);obj=w/(name+'.obj');c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],w);row={'variant':name,'exit':c}
 if c:row['errors']=[x for x in log.splitlines() if 'error C' in x][:5]
 else:
  raw=obj.read_bytes();n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith('?write@CWorkspace@@'));row.update(size=len(b),exact=match.exact_match(t,tr,b,r));ss,sy,defs,_=match._coff_data_index(raw);o,i=defs['__unwindtable$'+n];row['eh_states']=struct.unpack_from('<I',raw,ss[i][4]+o+12)[0]
 rows.append(row);print(row,flush=True)
(root/'work/2008-06/shared-layouts/writer-context2-worker.json').write_text(json.dumps({'scope':'Isolated genuine Workspace-related translation-unit context, no synthetic helpers; runtime unproven.','rows':rows,'observer_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()},indent=2)+'\n')
