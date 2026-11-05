"""Inactive SpecialShape lifetime/layout proof; no provider selection."""
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
src=R/'native-classes/SpecialShape.cpp'; header=R/'native-headers/v8datamodel/SpecialShape.h'
obj=nb.OUT/'CheckSpecialShape.obj'
for source,output in [(src,obj),(R/'tests/NativeSpecialShapeLayout.cpp',nb.OUT/'NativeSpecialShapeLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[('??0SpecialShape@RBX@@QAE@XZ',0x59fbb0),('??1SpecialShape@RBX@@UAE@XZ',0x59fd70)]
prefix_rows=[('??0?$DescribedCreatable@VSpecialShape',0x59fad0),('??1?$FactoryProduct@VSpecialShape',0x59ece0),('??0?$FactoryProduct@VSpecialShape',0x59ed40)]
functions=list(match.coff_functions(obj.read_bytes()))
for prefix,address in prefix_rows:
 names=[n for n,b,r in functions if n.startswith(prefix)]
 assert len(names)==1,(prefix,names)
 methods.append((names[0],address))
# Additional exact rows (TU-emitted helpers and inline reflection functions), orchestrator-verified 2026-11-04
methods.append(('?classDescriptor@?$Described@VSpecialShape@RBX@@$1?sSpecialShape@2@3PADAV?$FactoryProduct@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ',0x59f7e0))
methods.append(('?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ',0x40ad80))
methods.append(('??__Ffoo@?1??classDescriptor@?$Described@VSpecialShape@RBX@@$1?sSpecialShape@2@3PADAV?$FactoryProduct@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ',0x7fe080))
methods.append(('?rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ',0x40ad20))
methods.append(('??__Ffoo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@YAXXZ',0x7fa2a0))
methods.append(('??1ClassDescriptor@Reflection@RBX@@UAE@XZ',0x40abc0))
methods.append(('??__Froot@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@YAXXZ',0x7fa300))
methods.append(('??1?$MemberDescriptorContainer@VFunctionDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30))
methods.append(('??1?$MemberDescriptorContainer@VSignalDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30))
methods.append(('??1?$MemberDescriptorContainer@VPropertyDescriptor@Reflection@RBX@@@Reflection@RBX@@QAE@XZ',0x40ab30))
internal=dict(methods)
# Data/external bindings, orchestrator-verified 2026-11-04: sSpecialShape 0x94afac=='SpecialMesh', sInstance 0x82d6a0=='Instance';
# ClassDescriptor ctors 0x5708f0/0x570820 and _atexit 0x6a17af match prior receipts; function-local statics/guards are used consistently by exact rows.
internal['??_B?1??classDescriptor@?$Described@VSpecialShape@RBX@@$1?sSpecialShape@2@3PADAV?$FactoryProduct@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51']=0x976708
internal['?sSpecialShape@RBX@@3PADA']=0x94afac
internal['?foo@?1??classDescriptor@?$Described@VSpecialShape@RBX@@$1?sSpecialShape@2@3PADAV?$FactoryProduct@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A']=0x976648
internal['??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z']=0x5708f0
internal['_atexit']=0x6a17af
internal['??_B?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ@51']=0x96c528
internal['?sInstance@RBX@@3PADA']=0x82d6a0
internal['?foo@?1??classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@34@XZ@4V534@A']=0x96c468
internal['??_B?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV123@XZ@51']=0x96c460
internal['?root@?1??rootDescriptor@ClassDescriptor@Reflection@RBX@@SAAAV234@XZ@4V234@A']=0x96c3a0
internal['??0ClassDescriptor@Reflection@RBX@@AAE@XZ']=0x570820
# External bindings (orchestrator-verified 2026-11-04; consistent with prior receipts):
# Instance ctor/dtor 0x55b7e0/0x55a540 are exact in record_native_instance_lifetime.py
internal['??0Instance@RBX@@QAE@XZ']=0x55b7e0
internal['??1Instance@RBX@@UAE@XZ']=0x55a540
internal['?getNullName@Name@RBX@@SAABV12@XZ']=0x554270
internal['?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z']=0x55af90
rows=nb.verify(Original(),obj,methods,internal)
receipt=dict(class_name='RBX::SpecialShape',inactive=True,compiler=21022,flags=flags,source_sha256=nb.sha(src),header_sha256=nb.sha(header),layout=dict(size=0x18c,scale=0x134,meshId=0x140,textureId=0x160,vertColor=0x180,allocation='0041ec30',constructor='0059fbb0'),methods=rows,blockers=['remaining SpecialShape methods pending'],findings=['implicit (compiler-generated) destructor','name array non-const char (RTTI 3PADA)','meshId/textureId are donor MeshId/TextureId (ContentId)'])
(ROOT/'work/2008-06/shared-layouts/specialshape-working.json').write_text(json.dumps(receipt,indent=2))
print(json.dumps(receipt,indent=2))
