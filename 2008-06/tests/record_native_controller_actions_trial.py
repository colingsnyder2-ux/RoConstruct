"""Verify inactive controller actions with provisional helper declaration."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';overlay=out/'controller-action-overlay';overlay.mkdir(exist_ok=True);header=root/'rebuild/2008-06/native-headers/StandardVerbs.h';text=header.read_text();assert text.count('void applyController(int);')==1
(overlay/'StandardVerbs.h').write_text(text)
source=root/'rebuild/2008-06/tests/NativeControllerActionsTrial.cpp';obj=out/'NativeControllerActionsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(overlay));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rows=[]
for cls,address,vt in [('PrimaryControllerCommand',0x581920,0x830ad4),('SecondaryControllerCommand',0x581960,0x830af8)]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@'+cls+'@RBX@@'));target,targetrefs,_=match.target('2008-06',f'{address:08x}');assert match.exact_match(target,targetrefs,body,refs)
 assert struct.unpack('<I',pe.get_data(vt+16-image,4))[0]==address
 start,index=definitions[name];section=sections[index];edges={}
 for i in range(section[7]):
  off,symbol,kind=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
  if kind==20 and 0<=off<len(body)-3:edges[symbols[symbol][0]]=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 for token,want in [('applyController',0x581890),('recordCameraHistory',0x58c5c0)]:assert any(token in k and v==want for k,v in edges.items()),(token,edges)
 rows.append({'class':cls,'address':hex(address),'size':len(body),'vtable':hex(vt),'calls':edges})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
(root/'work/2008-06/shared-layouts/controller-actions-trial.json').write_text(json.dumps({'methods':rows,'source_sha256':sha(source),'header_sha256':sha(header),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'scope':'Inactive trial; helper signature/name provisional, implementation, class lifetime and runtime unproven.'},indent=2)+'\n')
print('PASS two controller action bodies and original targets')
