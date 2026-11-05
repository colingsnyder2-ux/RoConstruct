import json,hashlib,struct
from pathlib import Path
from roc import match
out=Path('work/2008-06/shared-layouts/sol-clone-helper-20261105');run=Path('work/2008-06/native-check-runs/20261105-144726-344e0b26');res=json.loads((run/'results.json').read_text());r=res[0];raw=Path(r['object']).read_bytes();sec,syms,defs,_=match._coff_data_index(raw)
name,body,rel=next(x for x in match.coff_functions(raw) if x[0].startswith('?fromXmlRoot@'))
start,s=defs[name];t=sec[s];refs=[]
for j in range(t[7]):
 off,idx,kind=struct.unpack_from('<IIH',raw,t[5]+j*10)
 if start<=off<start+len(body):refs.append({'offset':off-start,'symbol':syms[idx][0],'kind':kind})
print(json.dumps(refs,indent=2))
(out/'compile-receipt.json').write_text(json.dumps(res,indent=2));(out/'object-inventory.json').write_text(json.dumps({'object':r['object'],'sha256':hashlib.sha256(raw).hexdigest(),'definitions':list(defs),'helper_relocations':refs},indent=2))
