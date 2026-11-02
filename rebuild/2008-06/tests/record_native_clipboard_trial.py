import hashlib,json,struct,sys
from pathlib import Path
import pefile
main=Path(__file__).resolve().parents[3]; here=main/'work/2008-06/worker-artifacts/copy-paste'; output=main/'rebuild/2008-06/out/native-layouts'; output.mkdir(parents=True,exist_ok=True)
sys.path.insert(0,str(main))
from roc import match,rebuild
base=json.loads((main/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags=['/I'+str(here/'overlay'),'/I'+str(main/'rebuild/2008-06/tests')]+[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
pe=pefile.PE(str(main/'work/2008-06/original-p4-reference/Roblox.exe')); baseaddr=pe.OPTIONAL_HEADER.ImageBase
imports={entry.address: (lib.dll.decode()+'!'+(entry.name.decode() if entry.name else '#'+str(entry.ordinal))) for lib in pe.DIRECTORY_ENTRY_IMPORT for entry in lib.imports}
rows=[]
for kind,addr,vt in [('copy',0x415800,0x80e960),('paste',0x415510,0x80e934)]:
 source=main/'rebuild/2008-06/tests'/('NativeClipboard'+kind.capitalize()+'Trial.cpp'); obj=output/('NativeClipboard'+kind.capitalize()+'Trial.obj')
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],here); assert code==0,log
 raw=obj.read_bytes(); name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?doIt@'+kind.capitalize()+'Verb@@'))
 target,trefs,_=match.target('2008-06','%08x'%addr); assert match.exact_match(target,trefs,body,refs)
 spans,bad=match.data_check('2008-06','%08x'%addr,target,match.coff_data_refs(raw,name)); assert not bad,bad
 linkobj=output/('NativeClipboard'+kind.capitalize()+'Link.obj'); linkobj.write_bytes(rebuild.strip_symbols(raw,keep={name})); linkname,linkbody,linkrefs=next(x for x in match.coff_functions(linkobj.read_bytes()) if x[0]==name); assert match.exact_match(target,trefs,linkbody,linkrefs)
 assert struct.unpack('<I',pe.get_data(vt+16-baseaddr,4))[0]==addr
 secs,syms,defs,_=match._coff_data_index(raw);start,idx=defs[name];section=secs[idx];bind=[]
 for i in range(section[7]):
  off,si,typ=struct.unpack_from('<IIH',raw,section[5]+10*i);off-=start
  if not 0<=off<len(body)-3:continue
  val=struct.unpack_from('<I',target,off)[0]
  if typ==20:val=(addr+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bind.append({'offset':hex(off),'symbol':syms[si][0],'target':hex(val),'import':imports.get(val)})
 cstr=[b for b in bind if b['symbol'].startswith('__imp_?c_str@?$basic_string')];assert len(cstr)==1 and cstr[0]['target']=='0x802464' and cstr[0]['import'].startswith('MSVCP90.dll!')
 for sym,address in ([('?newRootElement@SerializerV2@@',0x591a30),('??$for_each@',0x423ba0),('?serialize@TextXmlWriter@@',0x58e810)] if kind=='copy' else [('?findFirstChildByName@Instance@RBX@@',0x557950),('?loadInstances@SerializerV2@@',0x593250),('?insertInstances@RootInstance@RBX@@',0x5911d0),('??$setSelection@',0x413b00),('?recordCameraHistory@RBX@@',0x58c5c0)]):
  assert any(b['symbol'].startswith(sym) and b['target']==hex(address) for b in bind),(sym,address)
 rows.append({'method':name,'address':hex(addr),'vtable_slot':hex(vt+16),'length':len(body),'code_exact':True,'data_spans':spans,'data_mismatches':bad,'source_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),'object_sha256':hashlib.sha256(raw).hexdigest(),'link_object_sha256':hashlib.sha256(linkobj.read_bytes()).hexdigest(),'relocations':bind})
result={'scope':'Inactive diagnostic only. Compiler xstring overlay imports real MSVCP90 c_str; Instance header overlay declares target-inferred findFirstChildByName. Neither overlay is integrated. Relocations list original target destinations; listed key bindings, imports, vtable slots, literals and emitted bytes checked; remaining semantic bindings need independent proof. No linked/runtime or server verification.','methods':rows}
(main/'work/2008-06/shared-layouts/clipboard-trial.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS two code and referenced-data matches; inactive diagnostic, no server verification')
