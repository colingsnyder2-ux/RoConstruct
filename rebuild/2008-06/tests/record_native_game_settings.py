"""Inactive GameSettings ctor/layout proof (orchestrator-written recorder); no provider selection."""
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
src=R/'native-classes/GameSettings.cpp'; header=R/'native-headers/v8datamodel/GameSettings.h'
obj=nb.OUT/'CheckGameSettings.obj'
for source,output in [(src,obj),(R/'tests/NativeGameSettingsLayout.cpp',nb.OUT/'NativeGameSettingsLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[('??0GameSettings@RBX@@QAE@XZ',0x5bf680)]
functions=list(match.coff_functions(obj.read_bytes()))
internal=dict(methods)
# External bindings, orchestrator-verified 2026-11-04:
# 0x5bf580 stores vtable 0x8385f4 whose RTTI is .?AV?$GlobalSettingsItem@VGameSettings@RBX@@$1?sGameSettings@2@3QBDB@RBX@@
internal['??0?$GlobalSettingsItem@VGameSettings@RBX@@$1?sGameSettings@2@3QBDB@RBX@@IAE@XZ']=0x5bf580
internal['?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z']=0x55af90  # matches prior receipts
rows=nb.verify(Original(),obj,methods,internal)
receipt=dict(class_name='RBX::GameSettings',inactive=True,compiler=21022,flags=flags,source_sha256=nb.sha(src),header_sha256=nb.sha(header),layout=dict(size=0x13c,allocation='0044bdc0 (push 0x13c at 0044bddf, ctor call 0044be04)',constructor='005bf680'),methods=rows,blockers=['dtor, property initializers and accessors pending'])
(ROOT/'work/2008-06/shared-layouts/gamesettings-working.json').write_text(json.dumps(receipt,indent=2))
print(json.dumps(receipt,indent=2))
