import hashlib,json,struct,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';src=root/'rebuild/2008-06/experiments/trials/NativeBoolPropertyActionsTrial.cpp';obj=out/'NativeBoolPropertyActionsTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);assert code==0,log
raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);functions=match.coff_functions(raw);rows=[]
for prefix,address,expected in [('?isChecked@BoolPropertyVerb@',0x582180,[('?createService@',0x581cc0),('?testBooleanProperty@',0x57f810),('??$_Find_if@',0x57ee60)]),('?doIt@BoolPropertyVerb@',0x582230,[('?checkRunPermissions@',0x57d250),('?createService@',0x581cc0),('??$for_each@',0x57fab0),('?recordCameraHistory@',0x58c5c0)])]:
 name,body,refs=next(x for x in functions if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,targetrefs,body,refs);start,index=defs[name];table=sections[index];bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+i*10);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bindings[symbols[sym][0]]=value
 for key,value in expected:assert any(k.startswith(key) and v==value for k,v in bindings.items()),(key,bindings)
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'));assert struct.unpack('<2I',pe.get_data(0x830a84+12-pe.OPTIONAL_HEADER.ImageBase,8))==(0x582180,0x582230)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt={'scope':'Inactive property methods match byte shapes and targets; predicate and setter signatures and object lifetime remain provisional, runtime unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/bool-property-actions-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS property actions bytes and target bindings')
