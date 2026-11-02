from pathlib import Path
import json,sys,struct
root=Path.cwd();sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts/instance-listener-override-trial';(out/'v8tree').mkdir(parents=True,exist_ok=True);header=(root/'rebuild/2008-06/native-headers/v8tree/Instance.h').read_text().replace('    virtual void onAncestorChanged(const AncestorChanged&);','    virtual void onAddListener(Listener<Instance, ChildAdded>*) const;\n    virtual void onAddListener(Listener<Instance, DescendantAdded>*) const;\n    virtual void onAncestorChanged(const AncestorChanged&);');(out/'v8tree/Instance.h').write_text(header);r=json.loads((root/'work/2008-06/shared-layouts/runservice-fresh-current.json').read_text());flags=['/I'+str(out)]+[x for x in r['flags'] if not x.startswith('/Fo') and not x.endswith('RunService.cpp')];src=root/'rebuild/2008-06/native-classes/RunService.cpp';obj=out/'trial.obj';c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert c==0,log
raw=obj.read_bytes();ss,sy,defs,_=match._coff_data_index(raw);f=match.coff_functions(raw);print('onAdd functions',[(n,len(b)) for n,b,r in f if 'onAddListener@Instance' in n]);
for v,(st,i) in defs.items():
 if v.startswith('??_7RunService@') and ('UChildAdded' in v or 'UDescendantAdded' in v):
  sec=ss[i];print(v,[(o-st,sy[si][0]) for o,si,k in [struct.unpack_from('<IIH',raw,sec[5]+j*10) for j in range(sec[7])] if o>=st])
