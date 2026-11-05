import sys,json,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/instance-lifetime-audit-worker';work.mkdir(exist_ok=True);src=root/'rebuild/2008-06/native-classes/InstanceLifetime.cpp';obj=work/'NativeInstanceLifetimeAudit.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);assert c==0,log
raw=obj.read_bytes();rows=[]
for a,prefix in [('0055b7e0','??0Instance@RBX@@QAE@XZ'),('0055b960','??0Instance@RBX@@QAE@PBD@Z'),('0055a540','??1Instance@RBX@@')]:
 n,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06',a);exact=match.exact_match(t,tr,b,r);rows.append({'address':a,'symbol':n,'object_size':len(b),'target_size':len(t),'exact':exact});print(rows[-1])
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Isolated current-header lifetime compile; relocation-normalized bytes only. Not a runtime or full vtable ABI proof.','methods':rows,'source_sha256':sha(src),'instance_header_sha256':sha(root/'rebuild/2008-06/native-headers/v8tree/Instance.h'),'object_sha256':sha(obj),'flags':flags,'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/instance-lifetime-audit-worker.json').write_text(json.dumps(receipt,indent=2)+'\n')
