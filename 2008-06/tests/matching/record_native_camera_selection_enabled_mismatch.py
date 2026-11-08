"""Record selection-enabled command mismatches; isolated, never linked."""
import hashlib,json,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';source=root/'rebuild/2008-06/experiments/trials/NativeCameraSelectionEnabledTrial.cpp';obj=out/'NativeCameraSelectionEnabledTrial.obj'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out);assert code==0,log
rows=[]
for cls,addr,vt in [('FollowCameraCommand','00582ea0',0x830860),('WatchCameraCommand','00582ea0',0x830878)]:
 name,body,refs=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?isEnabled@'+cls+'@RBX@@'))
 target,targetrefs,_=match.target('2008-06',addr);assert not match.exact_match(target,targetrefs,body,refs)
 rows.append({'class':cls,'address':addr,'candidate_size':len(body),'target_size':len(target),'exact':False,'vtable':hex(vt)})
grid=[]
baseflags=[x for x in flags if x not in ['/Ob2','/O2']]
for mode in ['/O2 /Ob0','/O2 /Ob1','/O2 /Ob2','/O1 /Ob2','/O1 /Ob1']:
    variant=out/('camera-selection-'+mode.replace('/','').replace(' ','-')+'.obj')
    result,log=rebuild.run(rebuild.toolchain(21022),'cl',baseflags+mode.split()+['/Fo'+str(variant),str(source)],out);assert result==0,log
    name,body,refs=next(x for x in match.coff_functions(variant.read_bytes()) if x[0].startswith('?isEnabled@FollowCameraCommand@RBX@@'))
    target,targetrefs,_=match.target('2008-06','00582ea0');assert not match.exact_match(target,targetrefs,body,refs)
    grid.append({'flags':mode,'candidate_size':len(body),'exact':False})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
(root/'work/2008-06/shared-layouts/camera-selection-enabled-mismatch.json').write_text(json.dumps({'source_sha256':sha(source),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'methods':rows,'compiler_grid':grid,'scope':'Inactive experiment; service selection and lifetime ABI unproven, no diagnostic promotion.'},indent=2)+'\n')
print('PASS recorded two nonmatching camera-enabled candidates')
