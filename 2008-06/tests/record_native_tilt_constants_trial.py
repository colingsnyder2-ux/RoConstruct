import json,sys,struct,hashlib
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeTiltConstantsTrial.cpp';obj=out/'NativeTiltConstantsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));image=pe.OPTIONAL_HEADER.ImageBase;rows=[]
for prefix,addr,size in [('?nativeTiltOffset@',0x83db50,4),('?nativeTiltScale@',0x826e6c,4),('?nativeTiltSectorScale@',0x83db48,8)]:
 sym=next(n for n in defs if n.startswith(prefix));start,idx=defs[sym];sec=sections[idx];data=raw[sec[4]+start:sec[4]+start+size];target=pe.get_data(addr-image,size);assert data==target,(sym,data.hex(),target.hex());rows.append({'symbol':sym,'original_address':hex(addr),'bytes':data.hex()})
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Diagnostic constants reproduce original bytes; original pooling, ownership and cross-object identity unproven.','constants':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/tilt-constants-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS three original tilt constant values')
