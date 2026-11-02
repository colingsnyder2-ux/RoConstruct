"""Verify native Selection service cache and underlying lookups."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());common=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
src=root/'rebuild/2008-06/native-classes/ServiceSelection.cpp';pre=out/'service-selection-preprocess';pre.mkdir(exist_ok=True);pre_flags=[x for x in common if x!='/c']+['/P',str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',pre_flags,pre);assert code==0,log
text=(pre/'ServiceSelection.i').read_text(errors='replace');needle='template<class T> class shared_ptr\n{\nprivate:';assert text.count(needle)==1
text=text.replace(needle,'template<class T> class shared_ptr\n{\npublic:\n    __declspec(noinline) ~shared_ptr() {}\nprivate:',1);profile=out/'ServiceSelectionProfile.cpp';profile.write_text(text);profile_obj=out/'ServiceSelectionProfile.obj';profile_flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(profile_obj),str(profile)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',profile_flags,out);assert code==0,log
lookupsrc=root/'rebuild/2008-06/native-classes/ServiceLookup.cpp';lookup_obj=out/'NativeServiceLookup.obj';lookup_flags=common+['/Fo'+str(lookup_obj),str(lookupsrc)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',lookup_flags,out);assert code==0,log
methods=[(profile_obj,'00415200','??$find@VSelection@RBX@@@ServiceProvider@RBX@@',[('?call_once@boost@@',0x557330),('??$doGetClassIndex@VSelection',0x413810),('?findServiceByClassName@ServiceProvider@RBX@@',0x572a90),('??1?$shared_ptr@VInstance@RBX@@',0x600660)]),(profile_obj,'00413810','??$doGetClassIndex@VSelection@RBX@@@ServiceProvider@RBX@@',[('?newIndex@ServiceProvider@RBX@@',0x572690)]),(profile_obj,'00600660','??1?$shared_ptr@VInstance@RBX@@@boost@@',[]),(lookup_obj,'00572690','?newIndex@ServiceProvider@RBX@@',[]),(lookup_obj,'00572a90','?findServiceByClassName@ServiceProvider@RBX@@',[])];rows=[]
for obj,address,prefix,expected in methods:
 raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address);assert match.exact_match(target,targetrefs,body,refs),(address,len(body),len(target))
 sec,sy,defs,_=match._coff_data_index(raw);start,idx=defs[name];tab=sec[idx];edges={}
 for i in range(tab[7]):
  offset,index,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);offset-=start
  if 0<=offset<len(body)-4 and kind==20:edges[sy[index][0]]=hex(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])
 for symbol,dest in expected:assert any(k.startswith(symbol) and v==hex(dest) for k,v in edges.items()),(address,symbol,edges)
 rows.append({'address':address,'symbol':name,'size':len(body),'direct_calls':edges})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[Path(__file__),src,lookupsrc,root/'rebuild/2008-06/native-headers/util/Name.h',root/'rebuild/2008-06/native-headers/v8tree/Service.h',root/'rebuild/2008-06/native-headers/v8datamodel/Selection.h']
receipt={'scope':'Inactive Selection cache and lookup methods; original data identity, linked cache sharing and runtime remain unverified.', 'inputs':{str(p.relative_to(root)):sha(p) for p in paths},'profile_object_sha256':sha(profile_obj),'lookup_object_sha256':sha(lookup_obj),'preprocess_flags':pre_flags,'profile_flags':profile_flags,'lookup_flags':lookup_flags,'methods':rows}
(root/'work/2008-06/shared-layouts/service-selection-working.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS Selection service cache, lookup and original direct targets')
