import hashlib,json,struct,sys
import pefile
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';overlay=out/'join-include/v8datamodel';overlay.mkdir(parents=True,exist_ok=True);source=root/'rebuild/2008-06/native-headers/v8datamodel/Selection.h';data=source.read_text();assert data.count('    boost::shared_ptr<Instance> front() const;')==1;(overlay/'Selection.h').write_text(data.replace('    boost::shared_ptr<Instance> front() const;','    boost::shared_ptr<Instance> front() const;\n    boost::shared_ptr<Instance> back() const;'))
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags.insert(0,'/I'+str(overlay.parent));code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(out/'NativeJoinCommandTrial.obj'),str(root/'rebuild/2008-06/experiments/trials/NativeJoinCommandTrial.cpp')],out);assert code==0,log
obj=out/'NativeJoinCommandTrial.obj';backsrc=root/'rebuild/2008-06/experiments/trials/NativeSelectionBackTrial.cpp';backobj=out/'NativeSelectionBackTrial.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(backobj),str(backsrc)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);rows=[]
for prefix,address,expected in [('?isEnabled@JoinCommand@',0x580850,[('?front@Selection@',0x413c20),('?back@Selection@',0x57e660),('?canJoin@MotorFeature@',0x609a60)]),('?doIt@JoinCommand@',0x5809d0,[('?checkRunPermissions@',0x57d250),('?front@Selection@',0x413c20),('?back@Selection@',0x57e660),('?join@MotorFeature@',0x60ca00)]),('?checkRunPermissions@RBX@@',0x57d250,[('?clientIsPresent@Client@',0x495e60),('?serverIsPresent@Server@',0x495e70)])]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target));start,sec=defs[name];table=sections[sec];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
 for token,value in expected:assert any(k.startswith(token) and v==value for k,v in bindings.items()),(token,bindings)
 if address in (0x580850,0x5809d0):assert any('create@VSelection@RBX@@' in k and v==0x4153b0 for k,v in bindings.items()),bindings
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
backraw=backobj.read_bytes();backname,backbody,backrefs=next(x for x in match.coff_functions(backraw) if x[0].startswith('?back@Selection@'));backtarget,backtargetrefs,_=match.target('2008-06','0057e660');assert match.exact_match(backtarget,backtargetrefs,backbody,backrefs)
bsections,bsymbols,bdefs,_=match._coff_data_index(backraw);bstart,bsec=bdefs[backname];btable=bsections[bsec];bbindings={}
for i in range(btable[7]):
 off,sym,kind=struct.unpack_from('<IIH',backraw,btable[5]+10*i);off-=bstart
 if not 0<=off<len(backbody)-3:continue
 value=struct.unpack_from('<I',backtarget,off)[0]
 if kind==20:value=(0x57e660+off+4+struct.unpack_from('<i',backtarget,off)[0])&0xffffffff
 bbindings[bsymbols[sym][0]]=value
assert 0x5587c0 in bbindings.values(),bbindings
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));baseaddr=pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<I',pe.get_data(0x83069c-baseaddr,4))[0]==0x580850 and struct.unpack('<I',pe.get_data(0x8306a4-baseaddr,4))[0]==0x5809d0
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();src=root/'rebuild/2008-06/experiments/trials/NativeJoinCommandTrial.cpp';receipt={'scope':'Join command methods match; MotorFeature declaration and Selection back method require native providers, layouts/runtime ABI unproven.','methods':rows,'selection_back':{'address':'0x57e660','size':len(backbody),'bindings':{k:hex(v) for k,v in bbindings.items()},'source_sha256':sha(backsrc),'object_sha256':sha(backobj)},'source_sha256':sha(src),'selection_header_sha256':sha(source),'overlay_sha256':sha(overlay/'Selection.h'),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/join-command-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS JoinCommand methods, vtable and bindings')
