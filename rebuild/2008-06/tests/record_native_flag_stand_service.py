"""Inactive FlagStandService ctor/dtor proof; no provider selection."""
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
src=R/'native-classes/FlagStandService.cpp'; header=R/'native-headers/v8datamodel/FlagStandService.h'
obj=nb.OUT/'CheckFlagStandService.obj'
for source,output in [(src,obj),(R/'tests/NativeFlagStandServiceLayout.cpp',nb.OUT/'NativeFlagStandServiceLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[('??1FlagStandService@RBX@@UAE@XZ',0x62c1c0)]  # ctor 0062ccd0 parked (header proposal)
prefix_rows=[('?FindStandWithFlag@FlagStandService@RBX@@',0x62bfc0),('??1?$FactoryProduct@VFlagStandService',0x62ba70)]
# Parked with ctor 0062ccd0 (emitted only by it): classDescriptor 005c0390, DescribedCreatable ctor 0062c820, descriptor atexit 007fe730
functions=list(match.coff_functions(obj.read_bytes()))
for prefix,address in prefix_rows:
 names=[n for n,b,r in functions if n.startswith(prefix)]
 assert len(names)==1,(prefix,names)
 methods.append((names[0],address))
internal=dict(methods)
# 0062c026 calls donor FlagStand::GetFlag.
internal['?GetFlag@FlagStand@RBX@@QAEPAVFlag@2@XZ']=0x62b900  # orchestrator: 0062b900 body = donor GetFlag (getPrimitive at this+0x228, rigid-joint loop)
# 0062ba70 tail-calls Instance destructor.
internal['??1Instance@RBX@@UAE@XZ']=0x55a540
# 005c0390 calls Instance descriptor, descriptor constructor, and atexit.
internal['?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ']=0x40ad80
internal['??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z']=0x5708f0
internal['_atexit']=0x6a17af
# Descriptor destructor binding inherited from the verified DebrisService recorder.
internal['??1ClassDescriptor@Reflection@RBX@@UAE@XZ']=0x40abc0
methods.append(('?_Tidy@?$list@PAVFlagStand@RBX@@V?$allocator@PAVFlagStand@RBX@@@std@@@std@@IAEXXZ',0x682b40)); internal['?_Tidy@?$list@PAVFlagStand@RBX@@V?$allocator@PAVFlagStand@RBX@@@std@@@std@@IAEXXZ']=0x682b40  # emitted helper, body exact
rows=nb.verify(Original(),obj,methods,internal)
print(json.dumps(dict(class_name='RBX::FlagStandService',inactive=True,methods=rows),indent=2))
