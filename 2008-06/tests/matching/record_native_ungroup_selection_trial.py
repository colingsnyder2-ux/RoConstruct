"""Verify Ungroup selection trial with provisional filtered-selection helper."""
import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';overlay=out/'ungroup-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True)
header=root/'rebuild/2008-06/native-headers/v8datamodel/Selection.h';text=header.read_text();assert text.count('T* findFirst(bool (*predicate)(T*));')==1
(overlay/'Selection.h').write_text(text)
source=root/'rebuild/2008-06/experiments/trials/NativeUngroupSelectionTrial.cpp';obj=out/'NativeUngroupSelectionTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(overlay.parent))
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out);assert code==0,log
raw=obj.read_bytes();rows=[]
for prefix,addr,exact in [('?isEnabled@UngroupSelectionVerb','00582b50',True),('?hasChildren@RBX@@','0057e110',True),('?findFirst@?$FilteredSelection','0057edb0',True)]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06',addr);observed=match.exact_match(target,targetrefs,body,refs);assert observed==exact,(prefix,len(body),len(target))
 rows.append({'symbol':name,'address':addr,'size':len(body),'target_size':len(target),'exact':observed})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase
rd=lambda a:struct.unpack('<I',pe.get_data(a-base,4))[0];vt=0x830a0c;assert pe.get_string_at_rva(rd(rd(vt-4)+12)+8-base)==b'.?AV?$FilteredSelection@VModelInstance@RBX@@@RBX@@'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
(root/'work/2008-06/shared-layouts/ungroup-selection-trial.json').write_text(json.dumps({'methods':rows,'source_sha256':sha(source),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'scope':'Inactive trial; predicate and command match, findFirst name is provisional and full lifetime unproven; no promotion.'},indent=2)+'\n')
print('PASS Ungroup predicate and model child test; findFirst matches')
