"""Inactive ForceField ctor/dtor proof; no provider selection."""
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
recipe=libs.RECIPES['rbxgs']
flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/D_AFXDLL','/DNDEBUG','/D_MBCS','/DBOOST_ALL_NO_LIB']
flags+=['/D'+v for v in recipe['defines'].split()]
flags+=['/I'+str(R/'native-headers'),'/I'+str(ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags+=['/I'+str((libs.LIBS/v).resolve()) for v in recipe['include'] if v!='WINSDK']
flags+=['/D_XTP_STATICLINK','/D_XTPLIB_NOAUTOLINK','/I'+str(ROOT/'tools/libs/xtp-11.2.2/Source')]
src=R/'native-classes/ForceField.cpp'; header=R/'native-headers/v8datamodel/ForceField.h'
obj=nb.OUT/'CheckForceField.obj'
for source,output in [(src,obj),(R/'tests/NativeForceFieldLayout.cpp',nb.OUT/'NativeForceFieldLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[(n,a) for prefix,a in [('??0ForceField',0x62d6b0),('??1ForceField',0x62d820)] for n,b,r in match.coff_functions(obj.read_bytes()) if n.startswith(prefix)]
bodies=match.coff_functions(obj.read_bytes())
internal={}
for n,b,r in bodies:
 if n.startswith('??0?$DescribedCreatable@VForceField'): internal[n]=0x62d5f0
 if n.startswith('??1?$FactoryProduct@VForceField'): internal[n]=0x62d0c0
internal['??1IRenderable@RBX@@QAE@XZ']=0x47d410
internal['?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z']=0x55af90
rows=nb.verify(Original(),obj,methods,internal)
receipt=dict(class_name='RBX::ForceField',inactive=True,compiler=21022,flags=flags,source_sha256=nb.sha(src),header_sha256=nb.sha(header),layout=dict(size=328,field_140=320,field_144=324,allocation='005c1520',constructor='0062d6b0'),methods=rows,blockers=['askSetParent requires corrected native Workspace hierarchy; donor headers fail compilation','render3dAdorn 0062d570 pending'])
(ROOT/'work/2008-06/shared-layouts/forcefield-working.json').write_text(json.dumps(receipt,indent=2))
print(json.dumps(receipt,indent=2))

