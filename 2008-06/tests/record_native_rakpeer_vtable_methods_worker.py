import json,sys,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts/rakpeer-vtable-methods-worker';out.mkdir(parents=True,exist_ok=True);donor=root/'tools/rbxgs/Client/Network/raknet30/Source';defines=(donor/'RakNetDefines.h').read_text().replace('#define USE_WAIT_FOR_MULTIPLE_EVENTS','// 2008 target excludes recvEvent');(out/'RakNetDefines.h').write_text(defines);src=out/'RakPeer.cpp';original=(donor/'RakPeer.cpp').read_text(); prefix=original[:original.index('RakPeer::RakPeer()')]; chunks=[]; recovered=(root/'tools/openrbx/3rdparty/RakNet30/Source/roc_espclaude_74a6e31c3da6b639.cpp').read_text()
for needle in ['bool RakPeer::RPC( const char* uniqueID, const char *data', 'bool RakPeer::RPC( const char* uniqueID, const RakNet::BitStream *bitStream', 'float RakPeer::GetCompressionRatio(', 'float RakPeer::GetDecompressionRatio(']:
 candidate=recovered if 'const char *data' in needle else original
 start=candidate.index(needle); left=candidate.index('{',start);depth=1;end=left+1
 while depth:
  if candidate[end]=='{':depth+=1
  elif candidate[end]=='}':depth-=1
  end+=1
 chunks.append(candidate[start:end])
src.write_text('#include <malloc.h>\n'+prefix+'\n'.join(chunks));prior=json.loads((root/'work/2008-06/shared-layouts/profiling-integrated.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];flags+=['/I'+str(donor),'/I'+str(root/'tools/rbxgs/Client/Network'),'/fp:fast'];obj=out/'RakPeer.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);(out/'compile.log').write_text(log);assert code==0,log
fs=match.coff_functions(obj.read_bytes());rows=[]
for pre,addr in [('?GetCompressionRatio@RakPeer@@',0x4bbd90),('?GetDecompressionRatio@RakPeer@@',0x4bbdd0),('?RPC@RakPeer@@UAE_NPBD0I',0x4c42c0),('?RPC@RakPeer@@UAE_NPBDPBVBitStream',0x4bcf30)]:
 n,b,r=next(x for x in fs if x[0].startswith(pre));t,tr,_=match.target('2008-06','%08x'%addr);rows.append({'symbol':n,'address':hex(addr),'size':len(b),'target_size':len(t),'exact':match.exact_match(t,tr,b,r)})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();res={'scope':'Original donor RakPeer.cpp compiled against current native RakPeer.h with /fp:fast; matching masks relocations and does not validate vtable insertion/complete ABI/runtime.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'native_header_sha256':sha(root/'rebuild/2008-06/native-headers/RakPeer.h')};(root/'work/2008-06/shared-layouts/rakpeer-vtable-methods-worker.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(rows,indent=2))
