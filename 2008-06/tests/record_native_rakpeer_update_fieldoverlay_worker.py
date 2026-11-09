import sys,json,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild,match
work=root/'rebuild/2008-06/out/native-layouts/rakpeer-update-fieldoverlay-worker';work.mkdir(exist_ok=True);donor=root/'tools/openrbx/3rdparty/RakNet30/Source';h=(donor/'ReliabilityLayer.h').read_text();old='#ifndef _RELEASE\n\tstruct DataAndTime';assert h.count(old)==1;h=h.replace(old,'\tstruct DataAndTime',1);old='RakNetTime minExtraPing, extraPingVariance;\n#endif';assert h.count(old)==1;h=h.replace(old,'RakNetTime minExtraPing, extraPingVariance;',1);(work/'ReliabilityLayer.h').write_text(h);src=work/'RakPeer.cpp';src.write_text('#include <malloc.h>\n'+(donor/'RakPeer.cpp').read_text());prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')]+['/I'+str(donor),'/I'+str(root/'tools/openrbx/util'),'/I'+str(root/'tools/rbxgs/Client/Network')];flags.insert(next(i for i,x in enumerate(flags) if x.startswith('/I'))+1,'/I'+str(work));flags.insert(next(i for i,x in enumerate(flags) if x.startswith('/I'))+2,'/I'+str(donor));obj=work/'RakPeer.obj';c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);(work/'compile.log').write_text(log);rows=[]
if not c:
 fs=match.coff_functions(obj.read_bytes())
 for name,b,r in fs:
  if not name.startswith('?RunUpdateCycle@RakPeer@@'):continue
  t,tr,_=match.target('2008-06','004c5290');rows.append({'symbol':name,'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
print('compile',c,'errors',[x for x in log.splitlines() if 'error C' in x][:15]);print(rows)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Donor OpenRBX RakPeer source compiled isolated against current native headers; byte equality does not establish full ABI or runtime.','compile_exit':c,'errors':[x for x in log.splitlines() if 'error C' in x],'methods':rows,'donor_sha256':sha(donor/'RakPeer.cpp'),'header_sha256':sha(root/'rebuild/2008-06/native-headers/RakPeer.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/rakpeer-update-fieldoverlay-worker.json').write_text(json.dumps(receipt,indent=2)+'\n')

