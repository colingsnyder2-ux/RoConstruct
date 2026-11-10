import json,struct,hashlib,capstone
from pathlib import Path
from roc import match,libs
out=Path('work/2008-06/shared-layouts/sol-clone-native-20261105')
base,img=match._image('2008-06'); md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
rows={r['addr']:r for r in map(json.loads,Path('work/2008-06/functions.jsonl').read_text().splitlines())}
def asm(a):
 r=rows.get('%08x'%a); n=r['size'] if r else 300
 return ['%08x %s %s'%(i.address,i.mnemonic,i.op_str) for i in md.disasm(bytes(img[a-base:a-base+n]),a)]
a=asm(0x59d4d0)
p={'constructor':a,'recipe_include':libs.RECIPES['rbxgs']['include']}
(out/'initial.json').write_text(json.dumps(p,indent=2));print(json.dumps(p,indent=2))
def u(a):return struct.unpack_from('<I',img,a-base)[0]
t=0x832d3c;col=u(t-4);td=u(col+12)
p={'vtable':hex(t),'col':hex(col),'subobject_offset':u(col+4),'rtti':bytes(img[td-base+8:td-base+300]).split(b'\0')[0].decode(),'slots':[hex(u(t+i*4)) for i in range(20)],'target_38':asm(u(t+0x38))}
(out/'virtual.json').write_text(json.dumps(p,indent=2));print(json.dumps(p,indent=2))
for t in [0x832d4c,0x832d3c,0x832d34]:
 col=u(t-4);td=u(col+12)
 p={'vtable':hex(t),'col':hex(col),'subobject_offset':u(col+4),'rtti':bytes(img[td-base+8:td-base+200]).split(b'\0')[0].decode(),'slots':[hex(u(t+i*4)) for i in range(18)],'target_38':asm(u(t+0x38))}
 (out/('table-%x.json'%t)).write_text(json.dumps(p,indent=2)); print(json.dumps(p,indent=2))
p=Path('work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib');raw=p.read_bytes();o=8;found=[]
while o+60<=len(raw):
 n=int(raw[o+48:o+58]);member=raw[o:o+16].decode().strip();d=raw[o+60:o+60+n];o+=60+n+(n&1)
 if d[:2]!=b'\x4c\x01':continue
 try:fs=match.coff_functions(d)
 except Exception:continue
 for s,b,r in fs:
  if not any(k in s for k in ['fromXmlRoot@Instance','newRootElement@SerializerV2','writeChildren@Instance','?write@Instance']):continue
  hits=[]
  for addr in ['00559250','00591a30','00558c50','00558110']:
   t,tr,_=match.target('2008-06',addr)
   if match.exact_match(t,tr,b,r):hits.append(addr)
  found.append({'symbol':s,'member':member,'member_sha256':hashlib.sha256(d).hexdigest(),'size':len(b),'hits':hits,'asm':['%x %s %s'%(i.address,i.mnemonic,i.op_str) for i in md.disasm(b,0)]})
(out/'archive-evidence.json').write_text(json.dumps(found,indent=2))
for f in found:print(f['symbol'],f['member'],f['size'],f['hits']);print('\n'.join(f['asm']) if 'writeChildren' in f['symbol'] else '')
print('SLOT0', '\n'.join(asm(0x59d370)))
print('HELPER','\n'.join(asm(0x559250)))
helper=[];o=8;t,tr,_=match.target('2008-06','00559250')
while o+60<=len(raw):
 n=int(raw[o+48:o+58]);member=raw[o:o+16].decode().strip();d=raw[o+60:o+60+n];o+=60+n+(n&1)
 if d[:2]!=b'\x4c\x01':continue
 try:fs=match.coff_functions(d)
 except Exception:continue
 for s,b,r in fs:
  if len(b)==len(t) and match.exact_match(t,tr,b,r):helper.append({'member':member,'symbol':s})
report={'status':'parked pending absent helper provider guidance','compile_count':0,'original_sha256':hashlib.sha256(Path('clients/2008-06/Roblox.exe').read_bytes()).hexdigest(),'archive_sha256':hashlib.sha256(raw).hexdigest(),'canonical_header_sha256':hashlib.sha256(Path('rebuild/2008-06/native-headers/v8tree/Instance.h').read_bytes()).hexdigest(),'original_virtual_binding':{'constructor_store':'0059d55d ->00832d4c','COL':'0089a210','RTTI':'PartInstance','offset':0,'slot_38':'00558c50','genuine_symbol':'?write@Instance@RBX@@UAEPAVXmlElement@@XZ','donor_member_sha256':'947583b50f1108dae75be8368843c52c5cd6be382a1ce88a99ae13b6b5f49460','normalized_body_exact':True},'canonical_abi':'XmlElement* write() nonconst thiscall; expected primary slot14/+38 from declarations, secondary overrides excluded. No fresh compiled current canonical slot proof.','helper_normalized_matches':helper,'helper_named_provider_found':False,'root_provider':'/903 normalized exact00591a30; c6f555a65d89f48ff15b4d01fdb45b81698c63eb24031c547aa0dd8d231f35f0','missing':['native Instance::fromXmlRoot provider for00559250','fresh current canonical virtual slot COFF evidence','transitive ABI/EH/data and selected provider proof'],'next_gate':'Parent supply/recover genuine fromXmlRoot provider or authorize wrapper-only compile with unresolved helper recorded. No speculative helper body.','hypotheses_rejected':0,'source_edits':0}
(out/'handoff.json').write_text(json.dumps(report,indent=2)); print(json.dumps(report,indent=2))

