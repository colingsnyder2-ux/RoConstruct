import sys,json,hashlib,struct
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root))
from roc import match
out=root/'work/2008-06/shared-layouts/sol-axis-lifetime-20261105'
inputs=json.loads((root/'work/2008-06/native-doc-relinks/20261105-135622-0161a2a8/inputs.json').read_text())
records=[];errors=[]
for filename,expected in inputs.items():
 p=Path(filename)
 if p.suffix.lower() not in ('.obj','.lib'):continue
 raw=p.read_bytes();digest=hashlib.sha256(raw).hexdigest();assert digest==expected,(p,digest)
 members=[]
 if raw[:8]==b'!<arch>\n':
  offset=8
  while offset+60<=len(raw):
   size=int(raw[offset+48:offset+58]);name=raw[offset:offset+16].decode(errors='replace').strip();data=raw[offset+60:offset+60+size];members.append((name,offset+60,data));offset+=60+size+(size&1)
 else:members=[('',0,raw)]
 for member,offset,data in members:
  if data[:2]!=b'\x4c\x01':continue
  try: funcs=match.coff_functions(data)
  except Exception as e:errors.append([filename,member,str(e)]);continue
  for symbol,body,refs in funcs:
   if any(s in symbol for s in ('MouseCommand@','MegaDragger@','AxisMoveTool@','IRenderable@','weak_release','weak_ptr@VPartInstance','joinAndStopDragging')):
    records.append(dict(path=filename,input_sha256=digest,member=member,archive_offset=offset,member_sha256=hashlib.sha256(data).hexdigest(),symbol=symbol,size=len(body),body_hex=body.hex(),refs=refs))
(out/'inventory.json').write_text(json.dumps(dict(inputs_count=len(inputs),records=records,errors=errors),indent=2))
for r in records:
 if r['symbol'].startswith(('??0','??1','??_G','??_E')):print(r['path'],r['member'],r['symbol'],r['size'])
print('records',len(records),'errors',len(errors))


