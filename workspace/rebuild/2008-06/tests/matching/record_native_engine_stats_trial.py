import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeEngineStatsTrial.cpp';obj=out/'NativeEngineStatsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@EngineStatsCommand@'));target,targetrefs,_=match.target('2008-06','0057dc40');assert match.exact_match(target,targetrefs,body,refs),(len(body),len(target))
sections,symbols,defs,_=match._coff_data_index(raw);start,section=defs[name];table=sections[section];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if not 0<=off<len(body)-3:continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20:value=(0x57dc40+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings[symbols[sym][0]]=value
assert any(k.startswith('?doStats@ContactManager@') and v==0x60cbf0 for k,v in bindings.items()),bindings
name2,body2,refs2=next(x for x in match.coff_functions(raw) if x[0].startswith('?doStats@ContactManager@'));target2,targetrefs2,_=match.target('2008-06','0060cbf0');assert match.exact_match(target2,targetrefs2,body2,refs2)
start2,sec2=defs[name2]; t=sections[sec2]; bindings2={}
for i in range(t[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,t[5]+10*i);off-=start2
 if not 0<=off<len(body2)-3:continue
 v=struct.unpack_from('<I',target2,off)[0]
 if kind==20:v=(0x60cbf0+off+4+struct.unpack_from('<i',target2,off)[0])&0xffffffff
 bindings2[symbols[sym][0]]=v
assert any(k.startswith('?doStats@SpatialHash@') and v==0x47d410 for k,v in bindings2.items()),bindings2
leafsrc=root/'rebuild/2008-06/experiments/trials/NativeSpatialStatsTrial.cpp';leafobj=out/'NativeSpatialStatsTrial.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(leafobj),str(leafsrc)],out);assert code==0,log
leafraw=leafobj.read_bytes();leafname,leafbody,leafrefs=next(x for x in match.coff_functions(leafraw) if x[0].startswith('?doStats@SpatialHash@'));leaftarget,leaftargetrefs,_=match.target('2008-06','0047d410');assert match.exact_match(leaftarget,leaftargetrefs,leafbody,leafrefs)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'EngineStats action exact; World and Workspace definitions are incomplete diagnostic overlays and cannot be run.','method':{'address':'0x57dc40','size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}},'wrapper':{'address':'0x60cbf0','size':len(body2),'bindings':{k:hex(v) for k,v in bindings2.items()}},'leaf':{'address':'0x47d410','size':len(leafbody),'source_sha256':sha(leafsrc),'object_sha256':sha(leafobj)},'source_sha256':sha(src),'object_sha256':sha(obj),'evidence_sha256':sha(root/'work/2008-06/shared-layouts/engine-stats-chain.json'),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/engine-stats-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS EngineStats action and target')
