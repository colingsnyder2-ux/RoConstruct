import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'rocket-worker';frozen=out/'rocket-frozen-probe';capture=root/'rebuild/2008-06/tests/NativeMouseCaptureRocketWorker.cpp';obj=work/'NativeMouseCaptureRocketWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags[:0]=['/I'+str(out/'workspace-model-vector-include'),'/I'+str(root/'rebuild/2008-06/tests')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(capture)],work);assert code==0,log
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rd=lambda a:struct.unpack('<I',pe.get_data(a-image,4))[0];req={};rows=[]
for typ,slot,path,surface,count in [('Rocket',0x839aec,frozen/'candidate/00/NativeRocketWorkerTrial.obj','INamed',19),('Slingshot',0x839a64,frozen/'candidate/03/NativeSlingshotWorkerTrial.obj','INamed',19),('Rocket',0x839ad0,frozen/'candidate/00/NativeRocketWorkerTrial.obj','IRenderable',5),('Slingshot',0x839a4c,frozen/'candidate/03/NativeSlingshotWorkerTrial.obj','IRenderable',5)]:
 raw=path.read_bytes();sec,syms,defs,_=match._coff_data_index(raw);name=next(k for k in defs if k.startswith('??_7'+typ+'Tool@RBX@@6B'+surface+'@'));start,index=defs[name];table=sec[index];assert table[3]-start==count*4
 for j in range(table[7]):
  off,index,kind=struct.unpack_from('<IIH',raw,table[5]+10*j);i=(off-start)//4
  if 0<=i<count:
   symbol=syms[index][0];symbol=('??_G'+symbol[4:]) if symbol.startswith('??_E') else symbol;req[(typ+'/'+surface,i)]=(symbol,rd(slot+4*i))
 locator=rd(slot-4);descriptor=rd(locator+12);assert pe.get_string_at_rva(descriptor+8-image)==('.?AV'+typ+'Tool@RBX@@').encode()
assert len(req)==48
resolved={};paths=list(frozen.glob('**/*.obj'))+[obj]
for p in paths:
 try:funcs=match.coff_functions(p.read_bytes())
 except Exception:continue
 for name,body,refs in funcs:
  for key,(symbol,address) in req.items():
   if name!=symbol or key in resolved:continue
   try:target,targetrefs,_=match.target('2008-06','%08x'%address)
   except:continue
   if match.exact_match(target,targetrefs,body,refs):resolved[key]=p
assert len(resolved)==len(req),[(key,hex(v[1]),v[0]) for key,v in req.items() if key not in resolved]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
for key,(symbol,address) in req.items():rows.append({'class':key[0],'slot':key[1],'original_address':hex(address),'symbol':symbol,'object':str(resolved[key].relative_to(root)),'object_sha256':sha(resolved[key])})
receipt={'scope':'Frozen objects contain byte-matched implementation for every Rocket and Slingshot primary and secondary vtable slots; not proof linker selects these bodies, complete data/secondary ABI, layout/lifetimes, static init, or runtime. capture compiled separately and not linked.','slots':rows,'capture_source_sha256':sha(capture),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/rocket-slingshot-vtable-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS 48 original Rocket/Slingshot primary and secondary vtable slots in frozen objects')
