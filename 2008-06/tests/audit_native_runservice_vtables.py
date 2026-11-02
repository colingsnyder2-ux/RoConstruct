"""Compare RunService candidate vtable slots against original constructor references."""
import hashlib,json,struct,sys
from collections import Counter
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match
proof=root/'work/2008-06/shared-layouts';receipt=json.loads((proof/'runservice-fresh-current.json').read_text());obj=root/'rebuild/2008-06/out/native-layouts/NativeRunService.obj';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(obj)==receipt['object_sha256'];raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);funcs={n:(b,r) for n,b,r in match.coff_functions(raw)};listener_receipt=json.loads((proof/'instance-child-listener-integrated.json').read_text());listener=root/'rebuild/2008-06/out/native-layouts/instance-child-listener-integrated/InstanceChildListener.obj';assert sha(listener)==listener_receipt['object_sha256'];funcs.update({n:(b,r) for n,b,r in match.coff_functions(listener.read_bytes()) if n in {listener_receipt['symbol']} | {x['symbol'] for x in listener_receipt['other_methods']}});target,_,_=match.target('2008-06','00556b00');ctor=next(k for k in defs if k.startswith('??0RunService@RBX@@'));start,index=defs[ctor];tab=sections[index];pepath=root/'work/2008-06/original-p4-reference/Roblox.exe';pe=pefile.PE(str(pepath),fast_load=True);base=pe.OPTIONAL_HEADER.ImageBase;known=match._functions('2008-06');tables=[]
for i in range(tab[7]):
 off,si,kind=struct.unpack_from('<IIH',raw,tab[5]+i*10);off-=start;name=symbols[si][0]
 if not (0<=off<len(target)-3 and name.startswith('??_7RunService@') and name in defs):continue
 address=struct.unpack_from('<I',target,off)[0];vstart,vindex=defs[name];vtab=sections[vindex];slots=[]
 for j in range(vtab[7]):
  offset,vi,vkind=struct.unpack_from('<IIH',raw,vtab[5]+j*10);offset-=vstart
  if offset<0:continue
  assert offset%4==0 and vkind==6;symbol=symbols[vi][0];orig=struct.unpack('<I',pe.get_data(address+offset-base,4))[0];key='%08x'%orig;status='external_or_not_emitted'
  if symbol in funcs:
   if key not in known:status='original_unindexed'
   else:
    body,refs=funcs[symbol];ob,or_,_=match.target('2008-06',key);status='masked_match' if match.exact_match(ob,or_,body,refs) else 'different'
  slots.append({'slot':offset//4,'symbol':symbol,'original':hex(orig),'status':status})
 tables.append({'symbol':name,'original_vtable':hex(address),'slots':slots})
rows=[s for t in tables for s in t['slots']];result={'scope':'Inactive candidate; relocation-masked COFF body comparison for constructor-referenced vtable slots only. External, aliased and indirect implementations remain unproved; no runtime or linked provider proof.','object_sha256':sha(obj),'original_sha256':sha(pepath),'observer_sha256':sha(Path(__file__)),'counts':dict(Counter(x['status'] for x in rows)),'vtables':tables};(proof/'runservice-vtable-audit.json').write_text(json.dumps(result,indent=2)+'\n');print('RunService vtables',len(tables),'slots',len(rows),'status',result['counts']);print('Different:',[(x['symbol'],x['original']) for x in rows if x['status']=='different'][:20])
