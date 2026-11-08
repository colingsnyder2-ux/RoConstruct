"""Document original Arrow factory versus donor class layout."""
import hashlib,json,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';source=root/'rebuild/2008-06/experiments/trials/NativeArrowFactoryTrial.cpp'
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
donor=root/'tools/rbxgs/Client/App/include/v8datamodel/MouseCommand.h'
overlay=out/'arrow-donor-profile/v8datamodel';overlay.mkdir(parents=True,exist_ok=True)
(overlay/'MouseCommand.h').write_bytes(donor.read_bytes())
obj=out/'NativeArrowFactoryDonorTrial.obj';flags=['/I'+str(overlay.parent),'/DDONOR_LAYOUT_TRIAL']+[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]+['/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?newMouseCommand@?$TToolVerb@VArrowTool'))
target,targetrefs,_=match.target('2008-06','005c6270')
assert len(body)==len(target)==126 and not match.exact_match(target,targetrefs,body,refs)
assert (body[0x19],target[0x19],body[0x4a],target[0x4a])==(0x24,0x20,0x20,0x1c)
normalized=bytearray(body);normalized[0x19]=0x20;normalized[0x4a]=0x1c
assert match.exact_match(target,targetrefs,bytes(normalized),refs)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
headers=[root/'rebuild/2008-06/native-headers/StandardVerbs.h',root/'tools/rbxgs/Client/App/include/tool/ToolsArrow.h',root/'tools/rbxgs/Client/App/include/v8datamodel/MouseCommand.h']
receipt={'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),'headers':{str(p.relative_to(root)):sha(p) for p in headers},'flags':flags,'address':'005c6270','size':len(body),'original_allocation':'0x20','donor_allocation':'0x24','original_field_offset':'0x1c','donor_field_offset':'0x20','scope':'Mismatch evidence only: normalized comparison is never compiled or linked. Full original ArrowTool/MouseCommand constructors, destructors and inheritance remain unproven.'}
(root/'work/2008-06/shared-layouts/arrow-factory-donor-mismatch.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS mismatch detection: original ArrowTool 0x20, donor 0x24')
