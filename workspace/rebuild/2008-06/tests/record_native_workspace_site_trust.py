"""Verify original workspace URL trust and zone checks under MFC import profile."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/native-classes/WorkspaceSiteTrust.cpp';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags=[x for x in base['flags'] if x!='/c' and not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]+['/P',str(src)]
pre=out/'site-trust-preprocess';pre.mkdir(exist_ok=True);code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,pre);assert code==0,log
text=(pre/'WorkspaceSiteTrust.i').read_text(errors='replace');inline='operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );\n\t}';assert text.count(inline)==1
text=text.replace(inline,'operator PCXSTR() const throw();',1);profile=out/'WorkspaceSiteTrustProfile.cpp';profile.write_text(text);obj=out/'WorkspaceSiteTrustProfile.obj'
compile_flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',compile_flags,out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for addr,prefix,expected in [('0041dcd0','?validateWorkspaceSiteUrl@@',('?trustCheck@Http@RBX@@',0x56a2e0)),('0041dd40','?validateWorkspaceSiteZone@@',('?validateWorkspaceSiteUrl@@',0x41dcd0))]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',addr);assert match.exact_match(target,targetrefs,body,refs)
 start,sec=defs[name];tab=sections[sec];edges={}
 for i in range(tab[7]):
  offset,index,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);offset-=start
  if 0<=offset<len(body)-4 and kind==20:edges[symbols[index][0]]=hex(int(addr,16)+offset+4+struct.unpack_from('<i',target,offset)[0])
 assert any(k.startswith(expected[0]) and v==hex(expected[1]) for k,v in edges.items()),(addr,edges)
 rows.append({'address':addr,'symbol':name,'size':len(body),'direct_calls':edges})
existing=root/'rebuild/2008-06/out/RbxgsApp/linked/Http.obj';http_name,http_body,http_refs=next(x for x in match.coff_functions(existing.read_bytes()) if x[0].startswith('?trustCheck@Http@RBX@@'));http_target,http_targetrefs,_=match.target('2008-06','0056a2e0')
checksrc=root/'rebuild/2008-06/native-classes/CWorkspaceSiteCheck.cpp';checkobj=out/'NativeWorkspaceSiteCheck.obj'
checkflags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]+['/Fo'+str(checkobj),str(checksrc)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',checkflags,out);assert code==0,log
check_name,check_body,check_refs=next(x for x in match.coff_functions(checkobj.read_bytes()) if x[0].startswith('?checkSite@?$IObjectSafetyRobloxImpl'));check_target,check_targetrefs,_=match.target('2008-06','00403b60')
assert match.exact_match(check_target,check_targetrefs,check_body,check_refs)
raw=checkobj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);start,sec=defs[check_name];tab=sections[sec];bindings={}
for i in range(tab[7]):
 offset,index,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);offset-=start
 if 0<=offset<len(check_body)-3:
  value=struct.unpack_from('<I',check_target,offset)[0]
  if kind==20:value=(0x403b60+offset+4+struct.unpack_from('<i',check_target,offset)[0])&0xffffffff
  bindings[symbols[index][0]]=value
for prefix,wanted in [('?getSiteUrl@',0x403210),('?validateWorkspaceSiteZone@@',0x41dd40),('?reportWorkspaceSiteError@@',0x429330),('?workspaceSiteErrorContext@@',0x8164f8),('_IID_IUnknown',0x8501cc),('__imp_??B?$CSimpleStringT@',0x803ee0),('__imp__SysFreeString@4',0x802944)]:
 assert any(k.startswith(prefix) and v==wanted for k,v in bindings.items()),(prefix,bindings)
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address,value in [(0x80b214,b'Failed to get SiteUrl'),(0x80b200,b'Untrusted Site: %s')]:
 assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase)==value
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[Path(__file__),src,checksrc,root/'rebuild/2008-06/native-headers/CWorkspace.h',root/'tools/rbxgs/Client/App/include/util/Http.h']
receipt={'scope':'Inactive original site/URL/zone checks match; linked error reporter/data, CWorkspace layout and existing Http::trustCheck remain unproven.', 'inputs':{str(p.relative_to(root)):sha(p) for p in paths},'preprocess_flags':flags,'profile_flags':compile_flags,'object_sha256':sha(obj),'methods':rows,'site_check_candidate':{'symbol':check_name,'candidate_size':len(check_body),'original_size':len(check_target),'relocation_normalized_exact':True,'bindings':{k:hex(v) for k,v in bindings.items()},'flags':checkflags,'object_sha256':sha(checkobj)},'linked_http':{'object':str(existing.relative_to(root)),'sha256':sha(existing),'symbol':http_name,'candidate_size':len(http_body),'original_size':len(http_target),'relocation_normalized_exact':match.exact_match(http_target,http_targetrefs,http_body,http_refs)}}
(root/'work/2008-06/shared-layouts/workspace-site-trust-working.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS native trust/zone checks; existing Http trust body differs')
