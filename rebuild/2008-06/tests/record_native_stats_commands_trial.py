import hashlib, json, struct, sys
import pefile
from pathlib import Path
root=Path(__file__).resolve().parents[3]; sys.path.insert(0,str(root)); from roc import match, rebuild
out=root/'rebuild/2008-06/out/native-layouts'; overlay=out/'stats-include'; (overlay/'v8tree').mkdir(parents=True,exist_ok=True); (overlay/'v8datamodel').mkdir(parents=True,exist_ok=True)
(overlay/'gui').mkdir(parents=True,exist_ok=True); gui=(root/'rebuild/2008-06/native-headers/gui/Gui.h').read_text(); assert gui.count('void setVisible(bool);')==1; (overlay/'gui/Gui.h').write_text(gui.replace('void setVisible(bool);','void setVisible(bool value) { visible = value; }'))
instance=(root/'rebuild/2008-06/native-headers/v8tree/Instance.h').read_text(); instance=instance.replace('    Instance* findFirstChildByClassName', '    Instance* findFirstChildByName(const std::string&) const;\n    Instance* findFirstChildByClassName'); (overlay/'v8tree/Instance.h').write_text(instance)
data=(root/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h').read_text(); data=data.replace('    Workspace* getWorkspace()', '    GuiRoot* getGuiRoot() const { return guiRoot.get(); }\n    Workspace* getWorkspace()'); (overlay/'v8datamodel/DataModel.h').write_text(data)
base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text()); flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]; flags.insert(0,'/I'+str(overlay)); obj=out/'NativeStatsCommandsTrial.obj'; code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(root/'rebuild/2008-06/tests/NativeStatsCommandsTrial.cpp')],out); assert code==0,log
raw=obj.read_bytes(); sections,symbols,defs,_=match._coff_data_index(raw); rows=[]
for prefix,address in [('?isEnabled@StatsCommand@',0x57db00),('?isChecked@StatsCommand@',0x57db90),('?doIt@StatsCommand@',0x57d9f0)]:
 name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix)); target,targetrefs,_=match.target('2008-06','%08x'%address); assert match.exact_match(target,targetrefs,body,refs),(prefix,len(body),len(target))
 start,section=defs[name]; table=sections[section]; bindings={}
 for i in range(table[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i); off-=start
  if not 0<=off<len(body)-3: continue
  value=struct.unpack_from('<I',target,off)[0]
  if kind==20: value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
  bindings[symbols[sym][0]]=value
 assert any(k.startswith('?findFirstChildByName@Instance@') and v==0x557950 for k,v in bindings.items()),bindings
 assert any('__RTDynamicCast' in k and v==0x6a17c6 for k,v in bindings.items()),bindings
 if address==0x57d9f0: assert {0x83073c,0x830730}.issubset(bindings.values()),bindings
 rows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe')); assert struct.unpack('<II',pe.get_data(0x830638-pe.OPTIONAL_HEADER.ImageBase,8))==(0x57db00,0x57db90); assert struct.unpack('<I',pe.get_data(0x830640-pe.OPTIONAL_HEADER.ImageBase,4))[0]==0x57d9f0
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest(); src=root/'rebuild/2008-06/tests/NativeStatsCommandsTrial.cpp'; receipt={'scope':'Inactive Stats command methods match original; GuiRoot and TopMenuBar layout, vtable and runtime ABI remain unproven.','methods':rows,'source_sha256':sha(src),'object_sha256':sha(obj),'instance_overlay_sha256':sha(overlay/'v8tree/Instance.h'),'datamodel_overlay_sha256':sha(overlay/'v8datamodel/DataModel.h'),'gui_overlay_sha256':sha(overlay/'gui/Gui.h'),'observer_sha256':sha(Path(__file__))}; (root/'work/2008-06/shared-layouts/stats-commands-trial.json').write_text(json.dumps(receipt,indent=2)+'\n'); print('PASS StatsCommand methods, vtable and call targets')
