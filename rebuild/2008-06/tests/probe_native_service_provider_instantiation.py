import json,sys
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import match,rebuild
r=json.loads((root/'work/2008-06/shared-layouts/service-provider-fresh-current.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/service-provider-instantiation-inline-probe';out.mkdir(parents=True,exist_ok=True);source=(root/'rebuild/2008-06/native-classes/ServiceProvider.cpp').read_text();flags=[f for f in r['flags'] if not f.startswith('/Fo') and not f.endswith('ServiceProvider.cpp')];rows=[]
for depth in range(1,7):
 text=source.replace('template RunService* ServiceProvider::find<RunService>() const;','#pragma inline_depth(%d)\ntemplate RunService* ServiceProvider::find<RunService>() const;\n#pragma inline_depth(255)'%depth);src=out/('trial%d.cpp'%depth);src.write_text(text);obj=out/('trial%d.obj'%depth);code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log;functions=match.coff_functions(obj.read_bytes());row={'depth':depth}
 for prefix,address,label in [('??$find@VRunService@RBX@@@ServiceProvider',0x452c80,'find'),('??$create@VRunService@RBX@@@ServiceProvider',0x4530f0,'create')]:
  n,b,r=next(x for x in functions if x[0].startswith(prefix));t,tr,_=match.target('2008-06','%08x'%address);row[label]={'size':len(b),'target':len(t),'exact':match.exact_match(t,tr,b,r)}
 rows.append(row);print(row,flush=True)
(root/'work/2008-06/shared-layouts/service-provider-instantiation-inline-probe.json').write_text(json.dumps({'scope':'Inactive inline-depth variants; no runtime or relocation target proof.','profiles':rows},indent=2)+'\n')
