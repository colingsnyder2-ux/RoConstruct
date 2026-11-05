from pathlib import Path
import json,sys
sys.path.insert(0,str(Path.cwd()))
sys.path.insert(0,str(Path('rebuild/2008-06/p6').resolve()))
from script_context_owner import references
root=Path.cwd(); folder=root/'work/2008-06/shared-layouts/sol-content-20261105'
m=json.loads((folder/'native.json').read_text(encoding='utf-8-sig'))
# Original 005628e0 disassembly, independently identified by content_get,
# workspace_insert, clipboard and document source probes. Offsets name CALL opcodes.
bindings=[(82,'00561f20','?getContent@ContentProvider'),(142,'00415350','??0TextXmlParser'),(161,'0058f6c0','?parse@TextXmlParser'),(193,'00413a70','??1XmlElement'),(199,'006a067a','??3@'),(223,'00593250','?loadInstances@SerializerV2'),(239,'00413a70','??1XmlElement'),(245,'006a067a','??3@'),(262,'004147c0','??1TextXmlParser')]
raw=(root/'work/2008-06/native-check-runs/20261105-122951-04c3d3fa/unit-000/candidate.obj').read_bytes()
refs=next(r for n,r in references(raw).items() if n.startswith('?load@ContentProvider'))
calls=[]
for off,target,prefix in bindings:
 names=[n for o,n,k in refs if o==off+1 and n.startswith(prefix)]
 assert len(names)==1
 calls.append(dict(offset=off,target=target,symbol=names[0]))
m['jobs'][0]['checks'][0]['calls']=calls
(folder/'proof.json').write_text(json.dumps(m,indent=2),encoding='utf-8')

