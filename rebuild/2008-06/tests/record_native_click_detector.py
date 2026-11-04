"""Inactive ClickDetector ctor/dtor proof; no provider selection."""
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
src=R/'native-classes/ClickDetector.cpp'; header=R/'native-headers/v8datamodel/ClickDetector.h'
obj=nb.OUT/'CheckClickDetector.obj'
for source,output in [(src,obj),(R/'tests/NativeClickDetectorLayout.cpp',nb.OUT/'NativeClickDetectorLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[(n,a) for prefix,a in [('??0ClickDetector',0x6297e0),('??1ClickDetector',0x6299a0),('??$?0VClickDetector@RBX@@@?$BoundProp@M$00@',0x629610),('??__E?prop_MaxActivationDistance@ClickDetector@RBX@@',0x7f7d90),('??__F?prop_MaxActivationDistance@ClickDetector@RBX@@',0x800330),('?askSetParent@ClickDetector',0x6298d0),('?shouldRender2d@ClickDetector',0x60a2f0),('?shouldRender3dAdorn@ClickDetector',0x565950)] for n,b,r in match.coff_functions(obj.read_bytes()) if n.startswith(prefix)]
bodies=match.coff_functions(obj.read_bytes())
internal={}
for n,b,r in bodies:
 if n.startswith('??0?$DescribedCreatable@VClickDetector'): internal[n]=0x6296e0
 if n.startswith('??1?$FactoryProduct@VClickDetector'): internal[n]=0x629340
internal['??1IRenderable@RBX@@QAE@XZ']=0x47d410
internal['?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z']=0x55af90
internal['__real@42000000']=0x833eac  # orchestrator-verified: original dword at 0x833eac == 0x42000000 (32.0f)
# Orchestrator-verified 2026-11-04: emitted reflection helper rows (bodies exact)
methods.append(('?classDescriptor@?$Described@VClickDetector@RBX@@$1?sClickDetector@2@3PADAV?$FactoryProduct@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ',0x5c02b0)); internal['?classDescriptor@?$Described@VClickDetector@RBX@@$1?sClickDetector@2@3PADAV?$FactoryProduct@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ']=0x5c02b0
methods.append(('??0?$TypedPropertyDescriptor@M@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z',0x445610)); internal['??0?$TypedPropertyDescriptor@M@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z']=0x445610
methods.append(('?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ',0x40ad80)); internal['?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ']=0x40ad80
methods.append(('??__Ffoo@?1??classDescriptor@?$Described@VClickDetector@RBX@@$1?sClickDetector@2@3PADAV?$FactoryProduct@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ',0x7fe800)); internal['??__Ffoo@?1??classDescriptor@?$Described@VClickDetector@RBX@@$1?sClickDetector@2@3PADAV?$FactoryProduct@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ']=0x7fe800
methods.append(('?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ',0x40ad20)); internal['?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ']=0x40ad20
methods.append(('??__Ffoo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ',0x7fa2a0)); internal['??__Ffoo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ']=0x7fa2a0
methods.append(('??1ClassDescriptor@Reflection@RBX@@UAE@XZ',0x40abc0)); internal['??1ClassDescriptor@Reflection@RBX@@UAE@XZ']=0x40abc0
methods.append(('??__Froot@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@YAXXZ',0x7fa300)); internal['??__Froot@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@YAXXZ']=0x7fa300
methods.append(('??1?$MemberDescriptorContainer@VFunctionDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30)); internal['??1?$MemberDescriptorContainer@VFunctionDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ']=0x40ab30
methods.append(('??1?$MemberDescriptorContainer@VSignalDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30)); internal['??1?$MemberDescriptorContainer@VSignalDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ']=0x40ab30
methods.append(('??1?$MemberDescriptorContainer@VPropertyDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30)); internal['??1?$MemberDescriptorContainer@VPropertyDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ']=0x40ab30
# Data/external bindings: sClickDetector 0x95b3c8=='ClickDetector', sInstance 0x82d6a0=='Instance'; prop_MaxActivationDistance storage 0x97bfb4 and
# classDescriptor statics are used consistently by exact rows; ClassDescriptor/PropertyDescriptor ctors, Type::singleton<float>, _atexit match prior receipts.
internal['?prop_MaxActivationDistance@ClickDetector@RBX@@2V?$BoundProp@M$00@Reflection@2@A']=0x97bfb4
internal['_atexit']=0x6a17af
internal['??_B?1??classDescriptor@?$Described@VClickDetector@RBX@@$1?sClickDetector@2@3PADAV?$FactoryProduct@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51']=0x977ce0
internal['?sClickDetector@RBX@@3PADA']=0x95b3c8
internal['?foo@?1??classDescriptor@?$Described@VClickDetector@RBX@@$1?sClickDetector@2@3PADAV?$FactoryProduct@VClickDetector@RBX@@VInstance@2@$1?sClickDetector@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A']=0x977c20
internal['??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z']=0x5708f0
internal['??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ']=0x56cca0
internal['??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z']=0x56c650
internal['??_B?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51']=0x96c528
internal['?sInstance@RBX@@3PADA']=0x82d6a0
internal['?foo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A']=0x96c468
internal['??_B?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@51']=0x96c460
internal['?root@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV234@XZ@4V234@A']=0x96c3a0
internal['??0ClassDescriptor@Reflection@RBX@@AAE@XZ']=0x570820
rows=nb.verify(Original(),obj,methods,internal)
receipt=dict(class_name='RBX::ClickDetector',inactive=True,compiler=21022,flags=flags,source_sha256=nb.sha(src),header_sha256=nb.sha(header),layout=dict(size=332,field_140=320,maxActivationDistance=324,allocation='005c0b60',constructor='006297e0'),methods=rows,blockers=['property accessors and render virtuals pending; untested first draft'])
(ROOT/'work/2008-06/shared-layouts/clickdetector-working.json').write_text(json.dumps(receipt,indent=2))
print(json.dumps(receipt,indent=2))

