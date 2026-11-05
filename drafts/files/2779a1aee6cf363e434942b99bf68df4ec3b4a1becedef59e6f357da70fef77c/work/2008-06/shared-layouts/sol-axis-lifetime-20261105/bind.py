import sys,json,hashlib,struct,capstone
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import match
out=root/'work/2008-06/shared-layouts/sol-axis-lifetime-20261105';packet=json.loads((out/'inventory.json').read_text());base,image=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
records=packet['records'];by={}
for r in records:by.setdefault(r['symbol'],[]).append(r)
queue=[('??0MouseCommand@RBX@@IAE@PAVWorkspace@1@@Z',0x6159f0),('??1MouseCommand@RBX@@UAE@XZ',0x615780),('??1?$Named@VArrowToolBase@RBX@@$1?sAxisMoveTool@2@3PADA@RBX@@UAE@XZ',0x617dd0),('??0AxisMoveTool@RBX@@QAE@PAVWorkspace@1@@Z',0x640560)];queue += [('??_GMouseCommand@RBX@@UAEPAXI@Z',0x615a20),('??_GAxisMoveTool@RBX@@UAEPAXI@Z',0x640760)];seen=set();results=[]
def u(a):return struct.unpack_from('<I',image,a-base)[0]
while queue:
 sym,va=queue.pop(0)
 if (sym,va) in seen:continue
 seen.add((sym,va))
 providers=by.get(sym,[])
 if not providers:results.append(dict(symbol=sym,address=hex(va),missing=True));continue
 for r in providers:
  raw=Path(r['path']).read_bytes();raw=raw[r['archive_offset']: ] if r['archive_offset'] else raw
  secs,syms,defs,starts=match._coff_data_index(raw);v,s=defs[sym];sec=secs[s];body=bytes.fromhex(r['body_hex']);original=bytes(image[va-base:va-base+len(body)])
  rel=[]
  for i in range(sec[7]):
   off,idx,kind=struct.unpack_from('<IIH',raw,sec[5]+i*10)
   if v<=off<v+len(body):
    delta=off-v;dest=syms[idx][0];target=u(va+delta)
    if kind==20:target=(va+delta+4+struct.unpack_from('<i',original,delta)[0])&0xffffffff
    elif kind==6:target-=struct.unpack_from('<i',body,delta)[0]
    rel.append(dict(offset=delta,symbol=dest,kind=kind,original_target=hex(target)))
  exact=match.exact_match(original,[],body,r['refs'])
  result={k:r[k] for k in ('path','input_sha256','member','member_sha256','symbol','size')};result.update(address=hex(va),normalized_body_exact=exact,edges=rel if exact else [],original_disassembly=[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(original,va)])
  results.append(result)
  if exact:
   for e in rel:
    dest=e['symbol'];target=int(e['original_target'],16)
    if e['kind']==20 and (dest.startswith(('??1','??_G','??0')) or 'weak_release' in dest or 'joinAndStopDragging' in dest):queue.append((dest,target))
    if e['kind']==6 and dest.startswith('??_7'):
     # Independently read original vtable entries, then COFF vtable symbol relocation names.
     if dest in defs:
      dv,ds=defs[dest];dsec=secs[ds]
      for j in range(dsec[7]):
       off,idx,kind=struct.unpack_from('<IIH',raw,dsec[5]+j*10)
       if dv<=off<dv+120 and kind==6:
        dn=syms[idx][0]
        if dn.startswith(('??_G','??_E')):queue.append((dn,u(target+off-dv)))
(out/'bindings.json').write_text(json.dumps(dict(scope='Conditional sidecar. Original instruction destinations and original vtable entries precede provider comparison; normalized body only, no referenced-data/EH/selection/runtime closure.',original_sha256=hashlib.sha256((root/'clients/2008-06/Roblox.exe').read_bytes()).hexdigest(),results=results),indent=2))
for r in results:print(r['symbol'],r['address'],r.get('normalized_body_exact'),r.get('size'),r.get('member'))


