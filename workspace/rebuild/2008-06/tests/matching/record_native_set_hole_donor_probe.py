import hashlib,json,re,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'document-swap-link-trial';proof=root/'work/2008-06/shared-layouts';basepath=proof/'document-swap-provider-trial.json';base=json.loads(basepath.read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
for path,h in base['objects'].items():assert sha(root/path)==h,('stale baseline',path)
source=work/'RbxgsAppWithoutInstance.lib';raw=source.read_bytes();assert raw[:8]==b'!<arch>\n';pos=8;member=None
while pos+60<=len(raw):
 header=raw[pos:pos+60];n=int(header[48:58].strip());name=header[:16].decode('ascii','replace').strip()
 if name=='Feature.obj/':assert member is None;member=bytearray(raw[pos+60:pos+60+n])
 pos+=60+n+(n&1)
assert member is not None
sections,symbols,defs,_=match._coff_data_index(bytes(member));ptr=struct.unpack_from('<I',member,8)[0];names={v[0]:i for i,v in symbols.items()};fn='?setHole@VelocityMotor@RBX@@QAEXPAVHole@2@@Z';data='_prop_Hole';fi=names[fn];di=names[data];fp=ptr+18*fi;dp=ptr+18*di
assert member[fp+16]==2 and member[dp+16]==3 and struct.unpack_from('<h',member,fp+12)[0]>0 and struct.unpack_from('<h',member,dp+12)[0]>0
# Keep donor COMDAT definition under a distinct name; redirect all COFF relocations
# that referenced it to a new undefined original symbol. No input archive is changed.
count=struct.unpack_from('<I',member,12)[0]; end=ptr+18*count; strings=member[end:]; strlen=struct.unpack_from('<I',strings,0)[0]; assert len(strings)==strlen
newname=b'?donor_setHole@VelocityMotor@RBX@@QAEXPAVHole@2@@Z\0'; original=bytes(member[fp:fp+18]); assert original[17]==0
struct.pack_into('<II',member,fp,0,strlen); member[dp+16]=2
redirected=0
for section in sections.values() if isinstance(sections,dict) else sections:
 for j in range(section[7]):
  at=section[5]+10*j; sym=struct.unpack_from('<I',member,at+4)[0]
  if sym==fi:
   struct.pack_into('<I',member,at+4,count);redirected+=1
assert redirected>0
new=bytearray(original);struct.pack_into('<Ih',new,8,0,0)
struct.pack_into('<I',member,12,count+1);struct.pack_into('<I',strings,0,strlen+len(newname));member=member[:end]+new+strings+newname
patched=work/'FeatureNativeSetHole.obj';patched.write_bytes(member);filtered=work/'RbxgsSetHoleProbe.lib';code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/REMOVE:Feature.obj','/OUT:'+str(filtered),str(source)],work);assert code==0,log
code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/OUT:'+str(filtered),str(filtered),str(patched)],work);assert code==0,log
trial=json.loads((proof/'velocity-set-hole-trial.json').read_text());obj=out/'NativeVelocitySetHoleTrial.obj';assert sha(obj)==trial['object_sha256']
args=[('/OUT:NativeDocSetHoleDonorProbe.exe' if x.upper().startswith('/OUT:') else '/MAP:NativeDocSetHoleDonorProbe.map' if x.upper().startswith('/MAP:') else str(filtered) if x.lower()==str(source).lower() else x) for x in base['link_flags']]+[str(obj)];code,log=rebuild.run(rebuild.toolchain(21022),'link',args,work);(work/'NativeDocSetHoleDonorProbe.log').write_text(log);errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b',x)];receipt={'scope':'Experimental diagnostic-only patched donor archive; runtime, section redirection, property identity and ABI unproven.','baseline_errors':len(base['errors']),'link_exit':code,'errors':errors,'archive_source_sha256':sha(source),'patched_archive_sha256':sha(filtered),'patched_member_sha256':sha(patched),'trial_object_sha256':sha(obj),'redirected_relocations':redirected,'observer_sha256':sha(Path(__file__))};(proof/'set-hole-donor-probe.json').write_text(json.dumps(receipt,indent=2)+'\n');print('SetHole donor probe: exit',code,'errors',len(errors),'baseline',len(base['errors']))
