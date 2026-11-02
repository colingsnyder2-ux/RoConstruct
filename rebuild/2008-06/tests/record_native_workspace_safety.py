"""Verify workspace safety methods, vtable slots, constructor and destructor."""
import hashlib,json,struct,sys,uuid
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());common=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
units=[('safety','CWorkspaceObjectSafety.cpp','NativeWorkspaceObjectSafety.obj','/Ob2'),('destructor','../tests/NativeWorkspaceDestructor.cpp','NativeWorkspaceDestructor.obj','/Ob1'),('siteurl','CWorkspaceSiteUrl.cpp','NativeWorkspaceSiteUrl.obj','/Ob2')];objects={};flags={}
for name,filename,objname,ob in units:
 src=(root/'rebuild/2008-06/native-classes'/filename).resolve();obj=out/objname;f=[ob if x in ('/Ob1','/Ob2') else x for x in common]+['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',f,out);assert code==0,log;objects[name]=obj;flags[name]=f
methods=[('safety','00404d20','?GetInterfaceSafetyOptions@?$IObjectSafetyRobloxImpl'),('safety','00404db0','?SetInterfaceSafetyOptions@?$IObjectSafetyRobloxImpl'),('destructor','0046a9b0','??1CWorkspace@@'),('siteurl','00403210','?getSiteUrl@?$IObjectSafetyRobloxImpl')];rows=[]
site_guids={}
for unit,address,prefix in methods:
 raw=objects[unit].read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',address);assert match.exact_match(target,targetrefs,body,refs),(address,len(body),len(target))
 sec,sy,defs,_=match._coff_data_index(raw);start,idx=defs[name];tab=sec[idx];edges={}
 for i in range(tab[7]):
  offset,index,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);offset-=start
  if 0<=offset<len(body)-4 and kind==20:edges[sy[index][0]]=hex(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])
  if unit=='siteurl' and 0<=offset<len(body)-4 and kind==6 and sy[index][0].startswith('_IID_'):
   original_ptr=struct.unpack_from('<I',target,offset)[0];site_guids[sy[index][0]]=hex(original_ptr)
 if unit=='safety':assert any(k.startswith('?checkSite@') and v=='0x403b60' for k,v in edges.items()),edges
 rows.append({'address':address,'symbol':name,'size':len(body),'direct_calls':edges})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));vtable=struct.unpack('<5I',pe.get_data(0x80ae40-pe.OPTIONAL_HEADER.ImageBase,20));assert vtable[3:]==(0x404d20,0x404db0)
expected={'_IID_IServiceProvider':'6d5140c1-7436-11ce-8034-00aa006009fa','_IID_IWebBrowser2':'d30c1661-cdaf-11d0-8a3e-00c04fc9e26e','_IID_IWebBrowserApp':'0002df05-0000-0000-c000-000000000046','_IID_IInternetSecurityManager':'79eac9ee-baf9-11ce-8c82-00aa004ba90b'}
assert set(site_guids)==set(expected)
for symbol,value in expected.items():assert str(uuid.UUID(bytes_le=pe.get_data(int(site_guids[symbol],16)-pe.OPTIONAL_HEADER.ImageBase,16)))==value
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();workspace=root/'work/2008-06/shared-layouts/workspace-revalidated.json';workspace_receipt=json.loads(workspace.read_text());assert any(m['address']=='0046ab60' and m['relocation_normalized_exact'] for m in workspace_receipt['methods']);header=root/'rebuild/2008-06/native-headers/CWorkspace.h';assert workspace_receipt['sources'][str(header.relative_to(root))]==sha(header)
inputs=[Path(__file__),root/'rebuild/2008-06/native-classes/CWorkspaceObjectSafety.cpp',root/'rebuild/2008-06/native-classes/CWorkspaceSiteUrl.cpp',root/'rebuild/2008-06/tests/NativeWorkspaceDestructor.cpp',root/'rebuild/2008-06/native-headers/CWorkspace.h',workspace]
receipt={'scope':'Inactive workspace ctor/dtor, safety slots and site URL/zone lookup match. Domain validation and runtime linking remain open.', 'inputs':{str(p.relative_to(root)):sha(p) for p in inputs},'objects':{k:sha(v) for k,v in objects.items()},'flags':flags,'methods':rows,'site_guid_addresses':site_guids,'original_safety_vtable':'0x80ae40','safety_slots':[hex(x) for x in vtable]}
(root/'work/2008-06/shared-layouts/workspace-safety-working.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS workspace safety methods, original slots, constructor and destructor')
