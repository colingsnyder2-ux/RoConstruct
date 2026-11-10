import runpy,json,struct,hashlib
from pathlib import Path
O=Path('work/2008-06/shared-layouts/sol-archive-resolve-refresh-20261105');P=Path('work/2008-06/shared-layouts/sol-archive-resolve-owner-20261105')
# Load parser definitions only, without repeating the full audit.
ns={};exec((O/'audit.py').read_text().split('manifest=json.loads')[0],ns)
H=ns['H'];members=ns['members'];coff=ns['coff'];bodies=ns['bodies']
M=json.loads(Path('work/2008-06/native-doc-relinks/20261105-152734-3e8dd256/inputs.json').read_text())
base=Path('work/2008-06/shared-layouts/sol-cumulative-links-20261105/serializer-member-152732-82bc06/linked.lib'); mm=members(base.read_bytes());old=next(b for n,o,b in mm if n=='SerializerV2.obj');new=(P/'unit-000/candidate.obj').read_bytes();removed=set(bodies(coff(old)))-set(bodies(coff(new)))
def metadata(b):
 if b[:4]==b'\0\0\xff\xff':return []
 if len(b)<20 or struct.unpack_from('<H',b)[0]!=0x14c:return []
 _,nc,_,ps,nt,op,_=struct.unpack_from('<HHIIIHH',b);sy,secs=coff(b);out=[];i=0
 while i<nt:
  x=b[ps+i*18:ps+(i+1)*18];n,v,s,t,c=sy[i];a=x[17];aux=b[ps+(i+1)*18:ps+(i+1+a)*18]
  weak=None
  if c==105 and a:
   idx,search=struct.unpack_from('<II',aux);weak={'fallback':sy.get(idx), 'search':search}
  if n in removed or (weak and weak['fallback'] and weak['fallback'][0] in removed):
   sm=None
   if s>0:
    sn,raw,rels,ch=secs[s];sm={'name':sn,'characteristics':ch,'comdat':bool(ch&0x1000)}
   out.append({'name':n,'value':v,'section':s,'storage':c,'type':t,'aux_hex':aux.hex(),'weak':weak,'section_metadata':sm,'real_external_definition':s>0 and c==2})
  i+=1+a
 return out
rows=[]
for p,h in M.items():
 for n,o,b in members(Path(p).read_bytes()):
  if Path(p)==base.resolve() and n=='SerializerV2.obj':continue
  r=metadata(b)
  if r:rows.append({'input':p,'member':n,'offset':o,'sha256':H(b),'symbols':r})
rows.append({'input':'candidate','sha256':H(new),'symbols':metadata(new)})
(O/'symbol-metadata.json').write_text(json.dumps(rows,indent=2))
a=json.loads((P/'actual-command.json').read_text());r=json.loads((P/'unit-000/receipt.json').read_text()); norm=lambda p:str(Path(p).resolve()).lower();ad={norm(p):h for p,h in a['dependencies'].items()};rd={norm(p):h for p,h in r['dependencies'].items()}
g={'base_sha256':H(base.read_bytes()),'member_count':len(mm),'old_member_sha256':H(old),'candidate_sha256':H(new),'original_command_file_sha256':H((P/'actual-command.json').read_bytes()),'original_source_sha256':H(Path(a['source']).read_bytes()),'candidate_source_sha256':H(Path(r['source']).read_bytes()),'original_dependency_entries':len(a['dependencies']),'original_unique':len(ad),'candidate_unique':len(rd),'common_changed':[p for p in ad.keys()&rd.keys() if ad[p]!=rd[p]],'old_only':sorted(ad.keys()-rd.keys()),'new_only':sorted(rd.keys()-ad.keys()),'original_dependency_drift':[p for p,h in a['dependencies'].items() if H(Path(p).read_bytes())!=h], 'weak_mentions':[x for x in rows if any(y['weak'] for y in x['symbols'])]}
assert g['base_sha256']=='b9d0373b050bafb2c7e0d3eac3302adc3eb3fe2318c30670bac92448aa794ccf'
assert g['old_member_sha256']=='c6f555a65d89f48ff15b4d01fdb45b81698c63eb24031c547aa0dd8d231f35f0'
assert g['candidate_sha256']=='0d4820b91d2a4603291db857b1f7e15afb9404b279323c92d09ffd8718977fd9'
(O/'guards.json').write_text(json.dumps(g,indent=2));print(json.dumps(g,indent=2))
