import json,struct,hashlib,sys
from pathlib import Path
from roc import match
root=Path.cwd(); out=root/'work/2008-06/shared-layouts/sol-drag-abi-20261105'
sha=lambda b:hashlib.sha256(b).hexdigest()
manifest=root/'work/2008-06/native-doc-relinks/20261105-135622-0161a2a8/inputs.json'
inputs=json.loads(manifest.read_text()); rows=[]; errors=[]; count=0
need={'anyPartAlive':'0060ead0','partsToPrimitives':'0060eb30','collectPrimitives':'0060f340','getPrimitives':'0060f3d0'}
def members(b):
 if not b.startswith(b'!<arch>\n'):yield None,0,b;return
 pos=8; names=b''
 while pos+60<=len(b):
  h=b[pos:pos+60]; size=int(h[48:58]); name=h[:16].decode().strip(); data=b[pos+60:pos+60+size]
  if name=='//':names=data
  elif name not in ('/','/SYM64/'):
   if name.startswith('/') and name[1:].isdigit():
    off=int(name[1:]); name=names[off:].split(b'\0')[0].split(b'\n')[0].rstrip(b'/\0').decode(errors='replace')
   yield name,pos,data
  pos+=60+size;pos+=pos%2
for path,expected in inputs.items():
 p=Path(path)
 if p.suffix.lower() not in ('.obj','.lib'):continue
 b=p.read_bytes(); count+=1
 if sha(b)!=expected:errors.append({'path':path,'error':'hash drift'});continue
 for member,offset,raw in members(b):
  if not any(k.encode() in raw for k in need):continue
  try:
   ix=match._coff_data_index(raw)
   for sym,code,rels in match.coff_functions(raw):
    key=next((k for k in need if sym.startswith('?'+k+'@')),None)
    if not key:continue
    target,tr,_=match.target('2008-06',need[key]); start,sec=ix[2][sym]; table=ix[0][sec]; refs=[]
    for i in range(table[7]):
     ro,si,kind=struct.unpack_from('<IIH',raw,table[5]+10*i)
     if start<=ro<start+len(code):refs.append({'offset':ro-start,'kind':kind,'symbol':ix[1][si][0],'addend_hex':raw[table[4]+ro:table[4]+ro+4].hex()})
    rows.append(dict(helper=key,address=need[key],input=path,input_sha256=expected,member=member,member_offset=offset,member_sha256=sha(raw),symbol=sym,body_size=len(code),body_sha256=sha(code),original_size=len(target),body_exact=match.exact_match(target,tr,code,rels),data=match.data_check('2008-06',need[key],code,match.coff_data_refs(raw,sym)),relocations=refs))
  except Exception as e:errors.append(dict(path=path,member=member,error=str(e)))
result=dict(manifest=str(manifest),manifest_sha256=sha(manifest.read_bytes()),scanned_inputs=count,providers=rows,errors=errors,scope='Static actual input providers; no linker selection or transitive ABI claim')
(out/'providers.json').write_text(json.dumps(result,indent=2,default=str)+'\n')
print(json.dumps(result,indent=2,default=str))

