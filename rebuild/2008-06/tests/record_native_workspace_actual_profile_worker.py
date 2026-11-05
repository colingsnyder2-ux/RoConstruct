import sys,json,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild,libs,match
worker=root/'rebuild/2008-06/out/native-layouts/workspace-actual-profile-worker';inc=worker/'include';(inc/'util').mkdir(parents=True,exist_ok=True);(inc/'v8datamodel').mkdir(parents=True,exist_ok=True)
integrator=root/'local/integrators/2a123e330b53448e9566d39326dd8372';overlay=integrator/'rebuild/2008-06/out/RbxgsApp/overlay/App';proposal=json.loads((integrator/'partial-handoff/Profiling/proposal.json').read_text());prof=(overlay/'include/util/Profiling.h').read_text()
for old,new in proposal['related_headers']['App/include/util/Profiling.h']:
 assert prof.count(old)==1,(old[:100],prof.count(old));prof=prof.replace(old,new,1)
(inc/'util/Profiling.h').write_text(prof)
source=(overlay/'v8datamodel/Workspace.cpp').read_text();wh=(overlay/'include/v8datamodel/Workspace.h').read_text();
for old,new in {'setDefaultMouseCommand':'setDefaultMouseCommandDonorProfile','setNullMouseCommand':'setNullMouseCommandDonorProfile'}.items():source=source.replace(old,new);wh=wh.replace(old,new)
wh=wh.replace('double unknown0x410[3]; // 0x410..0x428, zeroed by the constructor; names unknown','double unknown0x410, unknown0x418, unknown0x420; // original ctor zeroes these fields')
source=source.replace('unknown0x410[0] = unknown0x410[1] = unknown0x410[2] = 0.0;', '')
source=source.replace('cameraTemplate(Creatable::create<Camera>()),','cameraTemplate(Creatable::create<Camera>()),\n          unknown0x410(0.0), unknown0x418(0.0), unknown0x420(0.0),')
source=source.replace('world->getProfileWorldStep().parent = profileWorkspaceStep.get();','profileWorkspaceStepInner->parent = profileWorkspaceStep.get();\n        world->getProfileWorldStep().parent = profileWorkspaceStepInner.get();\n        profileWorkspaceAssemble->parent = profileWorkspaceStep.get();')
(inc/'v8datamodel/Workspace.h').write_text(wh);src=worker/'Workspace.cpp';src.write_text(source);obj=worker/'Workspace.obj';recipe=libs.RECIPES['rbxgs'];includes=[(libs.LIBS/x).resolve() for x in recipe['include'] if x!='WINSDK'];includes=rebuild._overlaid(includes,[],(root/'tools/rbxgs/Client',root/'rebuild/2008-06/out/RbxgsApp/overlay'))[0]
flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD']+['/D'+x for x in (recipe['defines']+' BOOST_ALL_NO_LIB').split()]+['/I'+str(inc),'/I'+str(overlay/'include')]+['/I'+str(x) for x in includes]+['/Fo'+str(obj),str(src)]
flags=[x for x in flags if x!='/D_RELEASEASSERT'];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,worker);(worker/'compile.log').write_text(log);print('compile',c,log[-4000:],flush=True)
if c:sys.exit(c)
rows=[]
for pre,a in [('??0Workspace@RBX@@',0x5a4d90),('??1Workspace@RBX@@',0x5a28c0)]:
 n,b,r=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%a);row={'address':hex(a),'symbol':n,'size':len(b),'original_size':len(t),'exact':match.exact_match(t,tr,b,r)};rows.append(row);print(row,flush=True)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();(worker/'result.json').write_text(json.dumps({'methods':rows,'object_sha256':sha(obj),'source_sha256':sha(src),'workspace_header_sha256':sha(inc/'v8datamodel/Workspace.h'),'profiling_header_sha256':sha(inc/'util/Profiling.h'),'flags':flags},indent=2))
