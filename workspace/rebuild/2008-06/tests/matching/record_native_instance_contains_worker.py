import sys,json,hashlib
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts/instance-contains-worker';overlay=out/'v8tree';overlay.mkdir(parents=True,exist_ok=True);orig=root/'rebuild/2008-06/native-headers/v8tree/Instance.h';s=orig.read_text();assert s.count('    bool contains(const Instance*) const;')==1;(overlay/'Instance.h').write_text(s)
src=root/'rebuild/2008-06/tests/NativeInstanceContainsWorker.cpp';obj=out/'NativeInstanceContainsWorker.obj';prior=json.loads((root/'work/2008-06/shared-layouts/instance-ancestor-trial.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];flags.insert(7,'/I'+str(out));flags+=['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?contains@Instance@RBX@@'));assert not refs,refs
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));hits=[]
for section in pe.sections:
 if not section.Characteristics & 0x20000000:continue
 data=section.get_data();pos=data.find(body)
 while pos!=-1:
  hits.append(hex(pe.OPTIONAL_HEADER.ImageBase+section.VirtualAddress+pos));pos=data.find(body,pos+1)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Donor contains includes self, original sound ancestor callback uses strict descendant helper 0x422ae0 after explicit self check; these differ. Byte sequence search only; unaligned matches possible.','candidate_symbol':name,'size':len(body),'candidate_bytes':body.hex(),'exact_text_byte_hits':hits,'relocations':len(refs),'source_sha256':sha(src),'object_sha256':sha(obj),'shadow_header_sha256':sha(overlay/'Instance.h'),'recorder_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/instance-contains-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(receipt,indent=2))
target,targetrefs,_=match.target('2008-06','005574b0');assert match.exact_match(target,targetrefs,body,refs) and len(target)==32
print('PASS original function boundary 0x5574b0; no call/relocation bindings')
