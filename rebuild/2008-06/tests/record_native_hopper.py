"""Inactive Hopper ctor/dtor proof; no provider selection."""
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
src=R/'native-classes/Hopper.cpp'; header=R/'native-headers/v8datamodel/Hopper.h'
obj=nb.OUT/'CheckHopper.obj'
for source,output in [(src,obj),(R/'tests/NativeHopperLayout.cpp',nb.OUT/'NativeHopperLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[('??0Hopper@RBX@@QAE@XZ',0x5cf900)]
prefix_rows=[]
functions=list(match.coff_functions(obj.read_bytes()))
for prefix,address in prefix_rows:
 names=[n for n,b,r in functions if n.startswith(prefix)]
 assert len(names)==1,(prefix,names)
 methods.append((names[0],address))
internal=dict(methods)
# native-asm 005cf900 directly calls RelativePanel constructor 005cf770.
internal['??0RelativePanel@RBX@@QAE@XZ']=0x5cf770
rows=nb.verify(Original(),obj,methods,internal)
# LegacyHopperService: ctor 005d10a0 (vtable RTTI .?AVLegacyHopperService@RBX@@), orchestrator-verified 2026-11-04
src2=R/'native-classes/LegacyHopperService.cpp'; obj2=nb.OUT/'CheckLegacyHopperService.obj'
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj2),str(src2)],nb.OUT)
assert code==0,log
methods2=[('??0LegacyHopperService@RBX@@QAE@XZ',0x5d10a0)]
internal2=dict(methods2)
internal2['??0Hopper@RBX@@QAE@XZ']=0x5cf900  # exact above
# Emitted helper rows (bodies exact) and external/data bindings, orchestrator-verified 2026-11-04:
# sLegacyHopperService 0x83a758 == 'Hopper' (also the setName literal); sInstance 0x82d6a0 == 'Instance'; ClassDescriptor ctors,
# setName 0x55af90 and _atexit match prior receipts; classDescriptor statics are used consistently by exact rows.
methods2.append(('??0?$DescribedCreatable@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@RBX@@IAE@XZ',0x5d0a80)); internal2['??0?$DescribedCreatable@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@RBX@@IAE@XZ']=0x5d0a80
methods2.append(('??0?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@RBX@@IAE@XZ',0x5cf9e0)); internal2['??0?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@RBX@@IAE@XZ']=0x5cf9e0
methods2.append(('?classDescriptor@?$Described@VLegacyHopperService@RBX@@$1?sLegacyHopperService@2@3QBDBV?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ',0x5c00f0)); internal2['?classDescriptor@?$Described@VLegacyHopperService@RBX@@$1?sLegacyHopperService@2@3QBDBV?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ']=0x5c00f0
methods2.append(('?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ',0x40ad80)); internal2['?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ']=0x40ad80
methods2.append(('??__Ffoo@?1??classDescriptor@?$Described@VLegacyHopperService@RBX@@$1?sLegacyHopperService@2@3QBDBV?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ',0x7fe840)); internal2['??__Ffoo@?1??classDescriptor@?$Described@VLegacyHopperService@RBX@@$1?sLegacyHopperService@2@3QBDBV?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ']=0x7fe840
methods2.append(('?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ',0x40ad20)); internal2['?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ']=0x40ad20
methods2.append(('??__Ffoo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ',0x7fa2a0)); internal2['??__Ffoo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ']=0x7fa2a0
methods2.append(('??1ClassDescriptor@Reflection@RBX@@UAE@XZ',0x40abc0)); internal2['??1ClassDescriptor@Reflection@RBX@@UAE@XZ']=0x40abc0
methods2.append(('??__Froot@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@YAXXZ',0x7fa300)); internal2['??__Froot@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@YAXXZ']=0x7fa300
methods2.append(('??1?$MemberDescriptorContainer@VFunctionDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30)); internal2['??1?$MemberDescriptorContainer@VFunctionDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ']=0x40ab30
methods2.append(('??1?$MemberDescriptorContainer@VSignalDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30)); internal2['??1?$MemberDescriptorContainer@VSignalDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ']=0x40ab30
methods2.append(('??1?$MemberDescriptorContainer@VPropertyDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30)); internal2['??1?$MemberDescriptorContainer@VPropertyDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ']=0x40ab30
internal2['?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z']=0x55af90
internal2['??_B?1??classDescriptor@?$Described@VLegacyHopperService@RBX@@$1?sLegacyHopperService@2@3QBDBV?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51']=0x9779c0
internal2['?sLegacyHopperService@RBX@@3QBDB']=0x83a758
internal2['?foo@?1??classDescriptor@?$Described@VLegacyHopperService@RBX@@$1?sLegacyHopperService@2@3QBDBV?$FactoryProduct@VLegacyHopperService@RBX@@VHopper@2@$1?sLegacyHopperService@2@3QBDB@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A']=0x977900
internal2['??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z']=0x5708f0
internal2['_atexit']=0x6a17af
internal2['??_B?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51']=0x96c528
internal2['?sInstance@RBX@@3PADA']=0x82d6a0
internal2['?foo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A']=0x96c468
internal2['??_B?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@51']=0x96c460
internal2['?root@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV234@XZ@4V234@A']=0x96c3a0
internal2['??0ClassDescriptor@Reflection@RBX@@AAE@XZ']=0x570820
rows2=nb.verify(Original(),obj2,methods2,internal2)
receipt=dict(class_name='RBX::Hopper',inactive=True,compiler=21022,flags=flags,source_sha256=nb.sha(src),header_sha256=nb.sha(header),layout=dict(size=360,allocation='0048ec70 (LegacyHopperService, ctor 005d10a0)',constructor='005cf900'),methods=rows+rows2,blockers=['Native GUI base layout pending; StarterPackService forwarding template definitions pending'])
print(json.dumps(receipt,indent=2))
