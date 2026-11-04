import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild,match
w=root/'rebuild/2008-06/out/native-layouts/rakpeer-update-fieldoverlay-worker';donor=root/'tools/openrbx/3rdparty/RakNet30/Source';src=w/'ReliabilityLayer.cpp';original=(donor/'ReliabilityLayer.cpp').read_text();before='#ifndef _RELEASE\n\tmaxSendBPS=minExtraPing=extraPingVariance=0;\n#endif';assert original.count(before)==1;src.write_text('#include <malloc.h>\n'+original.replace(before,'\tmaxSendBPS=minExtraPing=extraPingVariance=0;',1));prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];idx=next(i for i,x in enumerate(flags) if x.startswith('/I'));flags[idx+1:idx+1]=['/I'+str(w),'/I'+str(donor),'/I'+str(root/'tools/openrbx/util')];obj=w/'ReliabilityLayer.obj';c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],w);(w/'reliability-compile.log').write_text(log);print('compile',c,'errors',[x for x in log.splitlines() if 'error C' in x][:10]);rows=[]
if not c:
 for pre,a in [('??0ReliabilityLayer@@',0x4d25d0),('??1ReliabilityLayer@@',0x4d3b40)]:
  n,b,r=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%a);rows.append({'symbol':n,'address':hex(a),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
print(rows);(w/'reliability-result.json').write_text(json.dumps(rows,indent=2))
