import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'worker-slingshot';overlay=work/'include/util';overlay.mkdir(parents=True,exist_ok=True);provider=root/'tools/rbxgs/Client/App/include/util/ContentProvider.h';data=provider.read_text();needle='static ContentId fromAssets(const std::string& filePath);';assert data.count(needle)==1;(overlay/'ContentProvider.h').write_text(data.replace(needle,'static ContentId fromAssets(const char* filePath);'))
provider_trial=root/'rebuild/2008-06/experiments/trials/NativeContentProviderTrial.cpp';data=provider_trial.read_text();needle='    ContentProvider();';assert data.count(needle)==1;(work/'NativeContentProviderSlingshotOverlay.cpp').write_text(data.replace(needle,'    void load(ContentId, std::vector<boost::shared_ptr<Instance> >&);\n'+needle))
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(work/'include'),'/I'+str(work),'/I'+str(out/'workspace-model-vector-include')];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();rows=[];objects=[]
checks=[('NativeSlingshotProviderWorkerTrial','??$create@VContentProvider@RBX@@@ServiceProvider@RBX@@SA',0x465210,[],[('??_R0?AVServiceProvider@',0x92e15c),('??_R0?AVInstance@',0x92907c),('___RTDynamicCast',0x6a17c6),('??$create@VContentProvider@RBX@@@ServiceProvider@RBX@@QBE',0x41eea0)]),('NativeSlingshotContentIdWorkerTrial','?fromAssets@ContentId@',0x55bd80,[],[('??_C@',0x82da68),('?getNullName@Name@',0x554270)]),('NativeSlingshotBallisticWorkerTrial','?ballisticAngle@',0x5ded80,['/fp:fast'],[('__real@3f490fdb',0x8271b0)])]
for stem,prefix,address,extra,expected in checks:
 src=root/('rebuild/2008-06/experiments/trials/'+stem+'.cpp');src=src if src.is_file() else root/('rebuild/2008-06/tests/'+stem+'.cpp');obj=work/(stem+'.obj');code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+extra+['/Fo'+str(obj),str(src)],work);assert code==0,log;objects.append({'source':str(src.relative_to(root)),'source_sha256':sha(src),'object':str(obj.relative_to(root)),'object_sha256':sha(obj)});raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target));start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;assert pe.get_string_at_rva(0x82da68-image)==b'rbxasset://';assert pe.get_data(0x8271b0-image,4)==bytes.fromhex('db0f493f')
receipt={'scope':'Inactive provider traversal, ContentId::fromAssets and ballistic math match bytes, calls, original RTTI/data; class identities, global data pooling and runtime ABI unproven.','methods':rows,'objects':objects,'provider_overlay_sha256':sha(overlay/'ContentProvider.h'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/slingshot-dependencies-worker-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Slingshot provider, asset URI and ballistic dependencies')
