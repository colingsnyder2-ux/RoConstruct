import hashlib,json,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match
archive=root/'rebuild/2008-06/out/native-layouts/document-swap-link-trial/RbxgsAppWithoutInstance.lib';raw=archive.read_bytes();assert raw[:8]==b'!<arch>\n';pos=8;member=None
while pos+60<=len(raw):
 header=raw[pos:pos+60];size=int(header[48:58].strip());name=header[:16].decode('ascii','replace').strip()
 if name=='Feature.obj/':
  assert member is None;member=raw[pos+60:pos+60+size]
 pos+=60+size+(size&1)
assert member is not None
rows=[]
for prefix,address in [('??$create@VVelocityMotor@',0x5804a0),('?setHole@VelocityMotor@',0x60c400)]:
 name,body,refs=next(x for x in match.coff_functions(member) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);rows.append({'symbol':name,'address':hex(address),'target_size':len(target),'candidate_size':len(body),'relocations_masked_exact':match.exact_match(target,targetrefs,body,refs)})
assert rows[0]['relocations_masked_exact'] and not rows[1]['relocations_masked_exact']
sha=lambda data:hashlib.sha256(data).hexdigest();receipt={'scope':'Audit of available filtered donor archive member, not proof of runtime selection, callee binding, or complete ABI. Factory bytes match; setHole differs.','archive_sha256':sha(raw),'member':'Feature.obj','member_sha256':sha(member),'methods':rows,'observer_sha256':sha(Path(__file__).read_bytes())};(root/'work/2008-06/shared-layouts/feature-provider-audit.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS archive audit: factory exact, setHole nonmatching')
