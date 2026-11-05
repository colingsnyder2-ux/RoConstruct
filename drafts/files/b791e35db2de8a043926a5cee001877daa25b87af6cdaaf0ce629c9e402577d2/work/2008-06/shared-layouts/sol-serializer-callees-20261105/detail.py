import sys,json,struct
from pathlib import Path
sys.path.insert(0,str(Path.cwd()))
from roc import libs,match
import capstone,pefile
O=Path('work/2008-06/shared-layouts/sol-serializer-callees-20261105');j=json.loads((O/'inventory.json').read_text());md=capstone.Cs(3,4);out=[]
for r in j['providers']:
 if r['member'] in ('SerializerV2.obj','glue_serializer.obj','Instance.obj') or r['member'] is None:
  b=next(b for n,b in libs.archive_members(Path(r['path'])) if n==r['member']) if r['member'] else Path(r['path']).read_bytes()
  n,c,rr=next(x for x in match.coff_functions(b) if x[0]==r['symbol'])
  out.append({'provider':r,'asm':[f'{i.address:04x} {i.mnemonic} {i.op_str}' for i in md.disasm(c,0)]})
(O/'details.json').write_text(json.dumps(out,indent=2))
for x in out:
 print(x['provider']['member'],x['provider']['symbol'], 'data=',x['provider']['data_check'])
 if x['provider']['symbol'].startswith('?resolveRefs'):print('\n'.join(x['asm']))
pe=pefile.PE('clients/2008-06/Roblox.exe');print('original binder slots', [hex(x) for x in struct.unpack('<5I',pe.get_data(0x831ecc-pe.OPTIONAL_HEADER.ImageBase,20))])
