import sys,json,hashlib,struct,importlib.util
from pathlib import Path
import pefile
from capstone import *
from roc import match
out=Path('work/2008-06/shared-layouts/sol-drag-calls-20261105'); sha=lambda b:hashlib.sha256(b).hexdigest()
p=Path('work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib'); b=p.read_bytes(); assert sha(b)=='5e468dd4a346f252ce853c68ee416f1df833eddb23c0ab80e15194c623d19f4c'
pos=8; names=b''; hits=[]
while pos+60<=len(b):
 h=b[pos:pos+60]; n=int(h[48:58]); name=h[:16].decode().strip(); raw=b[pos+60:pos+60+n]
 if name=='//':names=raw
 elif name not in ('/','/SYM64/'):
  if name.startswith('/') and name[1:].isdigit():name=names[int(name[1:]):].split(b'\0')[0].split(b'\n')[0].rstrip(b'/').decode()
  if name.rstrip('/')=='DragUtilities.obj':hits.append((pos,raw))
 pos+=60+n;pos+=pos%2
assert len(hits)==1
pos,raw=hits[0]; assert sha(raw)=='400206004ed3d01dfa715c8cc9f9aef7dd2d0f1b70ae05530f4bdd12890aa62a'
(out/'DragUtilities.obj').write_bytes(raw)
ix=match._coff_data_index(raw); result={'archive':str(p),'archive_sha256':sha(b),'member_header_offset':pos,'member_sha256':sha(raw),'functions':{}}
md=Cs(CS_ARCH_X86,CS_MODE_32); md.detail=True
for a,key in [('0060ead0','anyPartAlive'),('0060eb30','partsToPrimitives')]:
 sym,code,rels=next(x for x in match.coff_functions(raw) if x[0].startswith('?'+key+'@')); t,tr,_=match.target('2008-06',a); start,sec=ix[2][sym]; tab=ix[0][sec]; rr=[]
 for i in range(tab[7]):
  off,si,k=struct.unpack_from('<IIH',raw,tab[5]+10*i)
  if start<=off<start+len(code):rr.append({'offset':off-start,'symbol':ix[1][si][0],'kind':k,'addend':raw[tab[4]+off:tab[4]+off+4].hex()})
 result['functions'][a]={'symbol':sym,'relocations':rr,'original':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(t,int(a,16))]}
(out/'raw-evidence.json').write_text(json.dumps(result,indent=2)); print(json.dumps(result,indent=2))
peb=Path('clients/2008-06/Roblox.exe').read_bytes(); assert sha(peb)=='2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
pe=pefile.PE(data=peb); rd=lambda a,n:pe.get_data(a-pe.OPTIONAL_HEADER.ImageBase,n)
for a,n in [(0x5cab00,160),(0x5995f0,180),(0x59a190,100),(0x5a0560,80),(0x7d9168,16)]:
 print(hex(a));print('\n'.join(f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(rd(a,n),a)))
print('EH COFF')
for sym,(off,sec) in ix[2].items():
 if 'partsToPrimitives' not in sym or sym==result['functions']['0060eb30']['symbol']:continue
 tab=ix[0][sec]; print(sym, 'section',sec,'offset',off,'size',tab[3], 'hex',raw[tab[4]:tab[4]+tab[3]].hex())
 for i in range(tab[7]):
  ro,si,k=struct.unpack_from('<IIH',raw,tab[5]+i*10);print(ro,k,ix[1][si][0])
sys.path.insert(0,str(Path('rebuild/2008-06/tests').resolve()))
import native_check_runner as runner
checks=[]
# Original destinations independently decoded above. Symbols reviewed against genuine declarations.
expected={'0060ead0':[(50,'005cab00'),(55,'005995f0')], '0060eb30':[(78,'005cab00'),(129,'005995f0'),(160,'0059a190'),(173,'005a0560')]}
for a,sites in expected.items():
 f=result['functions'][a]; calls=[]
 for off,dest in sites:
  rel=next(r for r in f['relocations'] if r['offset']==off+1); assert rel['kind']==20 and rel['addend']=='00000000'
  calls.append({'offset':off,'target':dest,'symbol':rel['symbol']})
 checks.append({'addr':a,'symbol':f['symbol'],'calls':calls})
job={'checks':checks,'ranges':[],'layouts':[]}
diagnostic=runner.analyze_object(job,out/'DragUtilities.obj')
try:runner.require_proof([diagnostic]); strict='PASS'
except SystemExit as e:strict='FAIL: '+str(e)
ehinfo=struct.unpack('<9I',rd(0x8f93dc,36)); print('original funcinfo',ehinfo)
unwind=ehinfo[2]; uw=struct.unpack('<2I',rd(unwind,8)); print('original unwind',hex(unwind),uw)
print('original cleanup', '\n'.join(f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(rd(uw[1],12),uw[1])))
receipt={'provenance':'Direct use of existing runner analyze_object + require_proof on extracted immutable archive member; no synthetic compile-run provenance and no compile. CLI analyze requires a prior compiler results.json, unavailable for this archive member.','inputs':{str(p):sha(p.read_bytes()),'clients/2008-06/Roblox.exe':sha(peb),'DragUtilities.obj':sha(raw)},'manifest':job,'diagnostic':diagnostic,'require_proof':strict,'original_eh':{'handler':'007d9168','funcinfo_address':'008f93dc','funcinfo_words':ehinfo,'unwind_address':hex(unwind),'unwind_words':uw,'cleanup_asm':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(rd(uw[1],8),uw[1])]}}
(out/'strict-receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(diagnostic,indent=2));print(strict)

