import sys,json,re
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
work=root/'rebuild/2008-06/out/native-layouts/instance-access-audit-worker';overlay=work/'v8tree';overlay.mkdir(parents=True,exist_ok=True)
h=(root/'rebuild/2008-06/native-headers/v8tree/Instance.h').read_text();names=['Instance();','explicit Instance(const char*);','virtual ~Instance();','virtual bool askAddChild(const Instance*) const;','virtual bool askSetParent(const Instance*) const;','virtual void onAncestorChanged(const AncestorChanged&);','virtual void onDescendentAdded(Instance*);','virtual void onDescendentRemoving(const boost::shared_ptr<Instance>&);','virtual void onChildAdded(Instance*);','virtual void onChildRemoving(Instance*);','virtual void onChildRemoved(Instance*);','virtual void readProperty(const XmlElement*, IReferenceBinder&);','virtual void onChildChanged(Instance*, const PropertyChanged&);']
for n in names:
 assert h.count('    '+n)==1,n
 h=h.replace('    '+n,'protected:\n    '+n+'\npublic:')
n='virtual void onLastChildRemoved();';assert h.count('    '+n)==1;h=h.replace('    '+n,'private:\n    '+n+'\npublic:');(overlay/'Instance.h').write_text(h)
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(root/'tools/openrbx/3rdparty/fmod/api/inc'));files=['PlayerNativeSound.cpp','PlayerNativeSoundService.cpp','PlayerNativeSoundStats.cpp','PlayerNativeSoundReflection.cpp','PlayerNativeSoundGC.cpp','PlayerNativeSoundChannel.cpp','NativeInstancePropertyChangedWorker.cpp'];rows=[]
for f in files:
 for protected in [False,True]:
  obj=work/(f+('.protected.obj' if protected else '.baseline.obj'));ff=(['/I'+str(work)] if protected else [])+flags+['/Fo'+str(obj),str(root/'rebuild/2008-06/tests'/f)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',ff,work); errors=[line.strip() for line in log.splitlines() if 'error C' in line];rows.append({'source':f,'protected':protected,'exit':c,'errors':errors});print(f,protected,c,errors[:2],flush=True)
(work/'results.json').write_text(json.dumps(rows,indent=2))

