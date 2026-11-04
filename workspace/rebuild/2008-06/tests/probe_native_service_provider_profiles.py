import json,sys
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import match,rebuild
r=json.loads((root/'work/2008-06/shared-layouts/service-provider-fresh-current.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/service-provider-profile-probe';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/ServiceProvider.cpp';base=[f for f in r['flags'] if f not in ('/Ob2','/Oy','/GF') and not f.startswith('/Fo') and not f.endswith('ServiceProvider.cpp')];rows=[]
for opts in [('/Ob0','/Oy','/GF'),('/Ob1','/Oy','/GF'),('/Ob2','/Oy','/GF'),('/Ob1','/Oy-','/GF'),('/Ob2','/Oy-','/GF')]:
 obj=out/('trial%d.obj'%len(rows));code,log=rebuild.run(rebuild.toolchain(21022),'cl',base+list(opts)+['/Fo'+str(obj),str(src)],out);assert code==0,log;functions=match.coff_functions(obj.read_bytes());row={'flags':opts}
 for prefix,address,label in [('??$find@VRunService@RBX@@@ServiceProvider',0x452c80,'find'),('??$create@VRunService@RBX@@@ServiceProvider',0x4530f0,'create')]:
  n,b,r=next(x for x in functions if x[0].startswith(prefix));t,tr,_=match.target('2008-06','%08x'%address);row[label]={'size':len(b),'target':len(t),'exact':match.exact_match(t,tr,b,r)}
 rows.append(row);print(row,flush=True)
(root/'work/2008-06/shared-layouts/service-provider-profile-probe.json').write_text(json.dumps({'scope':'Native source compiler profiles, no runtime or relocation target proof.','profiles':rows},indent=2)+'\n')
