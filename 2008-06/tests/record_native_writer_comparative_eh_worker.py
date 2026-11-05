import json,struct,hashlib,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match
exe=root/'work/2008-06/original-p4-reference/Roblox.exe';p=pefile.PE(str(exe));b=p.OPTIONAL_HEADER.ImageBase;rd=lambda a,n:p.get_data(a-b,n);u=lambda a:struct.unpack('<I',rd(a,4))[0];rows=[]
for addr,handler,count in [(0x46b860,0x7c39e8,2),(0x579c10,0x7d09a4,9)]:
 body,rel,_=match.target('2008-06','%08x'%addr);assert rd(handler,1)==b'\xb8';info=u(handler+1);magic,n,table=struct.unpack('<III',rd(info,12));assert magic==0x19930522 and n==count;states=[struct.unpack('<II',rd(table+i*8,8)) for i in range(n)]
 for target in (0x41eea0,0x46b550,0x58e810):assert any(body[i]==0xe8 and (addr+i+5+struct.unpack_from('<i',body,i+1)[0])&0xffffffff==target for i in range(len(body)-4)),hex(target)
 rows.append({'address':hex(addr),'size':len(body),'original_sha256':hashlib.sha256(body).hexdigest(),'handler':hex(handler),'states':[{'to':hex(x),'action':hex(y)} for x,y in states]})
assert rows[0]['states']==[{'to':'0xffffffff','action':'0x0'},{'to':'0xffffffff','action':'0x7c39e0'}];assert rows[1]['states'][3]=={'to':'0x2','action':'0x7d095f'}
receipt={'scope':'Original executable evidence only: the same provider+writer+serialize sequence appears with an already-active XML owner and no corresponding null-action writer predecessor; no source-level origin proven.','rows':rows,'observer_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()};(root/'work/2008-06/shared-layouts/writer-comparative-eh-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS original call targets and EH state comparison')
