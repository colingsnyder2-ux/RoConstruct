"""Verify native null Name provider and original singleton references."""
import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
proof=root/'work/2008-06/shared-layouts';prior=json.loads((proof/'runservice-fresh-current.json').read_text());out=root/'rebuild/2008-06/out/native-layouts/name-whole-integrated';out.mkdir(parents=True,exist_ok=True);src=root/'rebuild/2008-06/native-classes/accepted/App/util/Name.cpp';obj=out/'NameNative.obj';flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.endswith('RunService.cpp')]+['/Fo'+str(obj),str(src)];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log;raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?getNullName@Name@RBX@@',0x554270,{'0x973a2c','0x554160','0x557330','0x9739d0'}),('?initNullName@@',0x554160,{'0x80b716','0x553f90','0x9739d0'}),('?declare@Name@RBX@@SAABV12@PBDH',0x553f90,{'0x554160','0x557330','0x9739d0','0x553f20','0x553df0','0x594ce0','0x594d00'}),('?initMoo@@',0x553970,{'0x553910'}),('?moo2@@',0x553910,{'0x9739d8','0x9739e0','0x594c90','0x6a17af'}),('?namMap@Name@RBX@@',0x553f20,{'0x973a08','0x973a28','0x699b30','0x6a17af'}),('?dictionary@Name@RBX@@',0x553df0,{'0x9739e4','0x973a04','0x446110','0x6a17af'}),('?lookup@Name@RBX@@SAABV12@ABV?',0x554180,{'0x553970','0x557330','0x553910','0x594ce0','0x553f20','0x554160','0x9739d0','0x594d00'}),('?lookup@Name@RBX@@SAABV12@PBD',0x554290,{'0x554160','0x557330','0x9739d0','0x554180','0x802458','0x802468'})]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,tr,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,tr,body,refs),(name,len(body),len(target));start,idx=defs[name];tab=sections[idx];bindings={}
 for i in range(tab[7]):
  off,si,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[si][0]]=hex(value)
 assert expected <= set(bindings.values()),bindings;rows.append({'address':hex(address),'symbol':name,'size':len(body),'bindings':bindings})
assert all(row['bindings'].get('_nullName') == '0x9739d0' for row in rows[:3]), rows
assert any(k.startswith('?initNullName@@') and v == '0x554160' for k,v in rows[0]['bindings'].items())
assert any(k.startswith('?declare@Name@RBX@@') and v == '0x553f90' for k,v in rows[1]['bindings'].items())
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,root/'rebuild/2008-06/native-headers/util/Name.h',root/'rebuild/2008-06/native-classes/accepted/App/util/Name.cpp',Path(__file__)];result={'scope':'Inactive recovered Name provider; nine bodies and selected targets match, full ABI and runtime unproven.','methods':rows,'sources':{str(p.relative_to(root)):sha(p) for p in paths},'object_sha256':sha(obj),'flags':flags};(proof/'name-whole-integrated.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS nine native Name provider bodies and selected targets')
