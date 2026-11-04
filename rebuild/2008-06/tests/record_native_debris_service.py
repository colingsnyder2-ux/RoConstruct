"""Inactive DebrisService ctor/dtor proof; no provider selection."""
import sys,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT)); sys.path.insert(0,str(Path(__file__).parent))
from roc import match,libs,rebuild,clients
import native_bind as nb
import pefile
R=ROOT/'rebuild/2008-06'
# Use the registered original binary, rather than a machine-specific reference copy.
class Original(nb.Original):
 def __init__(self):
  self.pe=pefile.PE(str(clients.exe_path('2008-06',clients.load()['2008-06'])))
  self.image=self.pe.OPTIONAL_HEADER.ImageBase
  self.imports={x.address:(d.dll.decode().lower(),x.ordinal,x.name.decode() if x.name else None) for d in self.pe.DIRECTORY_ENTRY_IMPORT for x in d.imports}
  self.mfc={}
  import re
  for line in (ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='ignore').splitlines():
   m=re.match(r'\s*(\S+)\s+@\s*(\d+)',line)
   if m: self.mfc[int(m.group(2))]=m.group(1)
recipe=libs.RECIPES['rbxgs']
flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/D_AFXDLL','/DNDEBUG','/D_MBCS','/DBOOST_ALL_NO_LIB']
flags+=['/D'+v for v in recipe['defines'].split()]
flags+=['/I'+str(R/'native-headers'),'/I'+str(ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags+=['/I'+str((libs.LIBS/v).resolve()) for v in recipe['include'] if v!='WINSDK']
flags+=['/D_XTP_STATICLINK','/D_XTPLIB_NOAUTOLINK','/I'+str(ROOT/'tools/libs/xtp-11.2.2/Source')]
src=R/'native-classes/DebrisService.cpp'; header=R/'native-headers/v8datamodel/DebrisService.h'
obj=nb.OUT/'CheckDebrisService.obj'
for source,output in [(src,obj),(R/'tests/NativeDebrisServiceLayout.cpp',nb.OUT/'NativeDebrisServiceLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[('??0DebrisService@RBX@@QAE@XZ',0x63be90),('??1DebrisService@RBX@@UAE@XZ',0x63bfe0)]
prefix_rows=[('??$?0PBD@?$DescribedCreatable@VDebrisService',0x63bdb0),
             ('??$?0PBD@?$FactoryProduct@VDebrisService',0x63b490),
             ('?classDescriptor@?$Described@VDebrisService',0x5c06a0),
             ('?_Tidy@?$deque@V?$weak_ptr@VInstance',0x63b6d0),
             ('??1?$FactoryProduct@VDebrisService',0x63b340),
             ('??__Fdescriptor@?1??classDescriptor@?$Described@VDebrisService',0x7fe6c0)]
functions=list(match.coff_functions(obj.read_bytes()))
for prefix,address in prefix_rows:
 names=[n for n,b,r in functions if n.startswith(prefix)]
 assert len(names)==1,(prefix,names)
 methods.append((names[0],address))
internal=dict(methods)
# External bindings (orchestrator-verified 2026-11-04):
# Instance ctor(const char*) 0x55b960 and dtor 0x55a540 are exact in record_native_instance_lifetime.py;
# Described<Instance>::classDescriptor 0x40ad80, ClassDescriptor ctor 0x5708f0 and _atexit 0x6a17af match prior receipts.
internal['??0Instance@RBX@@QAE@PBD@Z']=0x55b960
internal['??1Instance@RBX@@UAE@XZ']=0x55a540
internal['?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ']=0x40ad80
internal['??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z']=0x5708f0
internal['_atexit']=0x6a17af
internal['??1ClassDescriptor@Reflection@RBX@@UAE@XZ']=0x40abc0  # matches prior receipts
# TU-owned statics: descriptor 0x978328 and its guard 0x9783e8 are used consistently by classDescriptor 005c06a0 and its exact atexit dtor 007fe6c0.
internal['?descriptor@?1??classDescriptor@?$Described@VDebrisService@RBX@@$1?sDebrisService@2@3PADAV?$FactoryProduct@VDebrisService@RBX@@VInstance@2@$1?sDebrisService@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A']=0x978328
internal['??_B?1??classDescriptor@?$Described@VDebrisService@RBX@@$1?sDebrisService@2@3PADAV?$FactoryProduct@VDebrisService@RBX@@VInstance@2@$1?sDebrisService@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51']=0x9783e8
rows=nb.verify(Original(),obj,methods,internal)
receipt=dict(class_name='RBX::DebrisService',inactive=True,compiler=21022,flags=flags,source_sha256=nb.sha(src),header_sha256=nb.sha(header),layout=dict(size=344,queue=304,maxItems=336,timer=340,allocation='005c2e10',constructor='0063be90'),methods=rows,blockers=['addItem/setMaxItems/onServiceProvider/cleanup and other virtuals pending'],findings=['implicit (compiler-generated) destructor: user-declared empty dtor adds 10 vptr stores (183 vs 105 B)','name array is non-const char (RTTI 3PADA), class name string is "Debris"'])
(ROOT/'work/2008-06/shared-layouts/debrisservice-working.json').write_text(json.dumps(receipt,indent=2))
print(json.dumps(receipt,indent=2))

