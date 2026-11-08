import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/instance-property-worker';overlay=work/'v8tree';overlay.mkdir(parents=True,exist_ok=True)
h=(root/'rebuild/2008-06/native-headers/v8tree/Instance.h').read_text()
for decl in ['static Reflection::BoundProp<bool, 1> propArchivable;', 'static Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> event_propertyChanged;', 'void raisePropertyChanged(const Reflection::PropertyDescriptor&']:
 if decl not in h: h=h.replace('    void setParent(Instance*);','    '+decl+'\n    void setParent(Instance*);')
(overlay/'Instance.h').write_text(h)
(work/'reflection').mkdir(exist_ok=True); p=(root/'tools/rbxgs/Client/App/include/reflection/property.h').read_text().replace('Property(const Property&);','Property(const Property& other) : ConstProperty(other) {}');(work/'reflection/property.h').write_text(p);e=(root/'rebuild/2008-06/native-headers/v8tree/PropertyChanged.h').read_text().replace('PropertyChanged(const PropertyChanged&);','PropertyChanged(const PropertyChanged& other) : property(Reflection::Property(other.property.getDescriptor(), other.property.getInstance())) {}');(overlay/'PropertyChanged.h').write_text(e)
src=root/'rebuild/2008-06/tests/NativeInstancePropertyChangedWorker.cpp';obj=work/'NativeInstancePropertyChangedWorker.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];flags=[x for x in flags if x != '/D_RELEASEASSERT'];flags.insert(0,'/I'+str(work));c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);print('compile',c,log[-4000:]);
if c:sys.exit(c)
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?raisePropertyChanged@Instance@'));target,trefs,_=match.target('2008-06','0040db00');print('size',len(body),len(target),'exact',match.exact_match(target,trefs,body,refs))




src=root/'rebuild/2008-06/tests/NativeInstanceArchivableWorker.cpp';obj=work/'NativeInstanceArchivableWorker.obj';c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],work);print('descriptor compile',c,log[-2000:]);print([x[0] for x in match.coff_functions(obj.read_bytes()) if 'propArchivable' in x[0]]) if not c else None

import struct,hashlib
outrows=[]
for fname,prefix,address in [('NativeInstancePropertyChangedWorker.obj','?raisePropertyChanged@Instance@',0x40db00),('NativeInstanceArchivableWorker.obj','??__E?propArchivable@',0x7f28e0)]:
 raw=(work/fname).read_bytes();secs,syms,defs,_=match._coff_data_index(raw);name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));target,trefs,_=match.target('2008-06','%08x'%address);assert match.exact_match(target,trefs,body,refs);start,idx=defs[name];t=secs[idx];bind={}
 for i in range(t[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,t[5]+10*i);off-=start
  if 0<=off<len(body)-3:
   value=struct.unpack_from('<I',target,off)[0]
   if kind==20:value=(address+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
   bind[syms[sym][0]]=hex(value)
 expected=([('?raise@',0x40a530),('?event_propertyChanged@',0x973f48),('?findSignalInstance@',0x56b620),('?empty@signal_base_impl@',0x56ab90),('??R?',0x6390a0)] if address==0x40db00 else [('?propArchivable@',0x973e74),('??$?0VInstance@',0x559700),('??__F?propArchivable@',0x7fc8c0),('_atexit',0x6a17af)])
 for key,value in expected: assert any(k.startswith(key) and v==hex(value) for k,v in bind.items()),(key,bind)
 outrows.append({'address':hex(address),'size':len(body),'symbol':name,'bindings':bind})
 print(hex(address),bind)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'scope':'Inactive isolated worker; exact bytes and mapped relocations only, ABI and runtime integration not proven. _RELEASEASSERT disabled for original release behavior.','methods':outrows,'property_source_sha256':sha(root/'rebuild/2008-06/tests/NativeInstancePropertyChangedWorker.cpp'),'descriptor_source_sha256':sha(root/'rebuild/2008-06/tests/NativeInstanceArchivableWorker.cpp'),'overlay_instance_sha256':sha(overlay/'Instance.h'),'overlay_propertychanged_sha256':sha(overlay/'PropertyChanged.h'),'overlay_property_sha256':sha(work/'reflection/property.h'),'observer_sha256':sha(Path(__file__)),'flags':flags};(root/'work/2008-06/shared-layouts/instance-property-worker.json').write_text(json.dumps(receipt,indent=2)+'\n')


