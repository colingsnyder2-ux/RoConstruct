"""Inactive JointsService ctor/dtor proof; no provider selection."""
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
src=R/'native-classes/JointsService.cpp'; header=R/'native-headers/v8datamodel/JointsService.h'
obj=nb.OUT/'CheckJointsService.obj'
# Layout test omitted: allocation size not yet proven (NativeJointsServiceLayout.cpp is provisional, uncommitted).
for source,output in [(src,obj)]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[('?askAddChild@JointsService@RBX@@EBE_NPBVInstance@2@@Z',0x4afb30)]
# No additional TU-emitted helpers expected for the two small bodies.
prefix_rows=[]
internal=dict(methods)
rows=nb.verify(Original(),obj,methods,internal)
receipt=dict(class_name='RBX::JointsService',inactive=True,compiler=21022,source_sha256=nb.sha(src),methods=rows,blockers=['ctor/allocation size unproven','onDescendentAdded/Removing, onServiceProvider, onEvent pending'])
(ROOT/'work/2008-06/shared-layouts/jointsservice-working.json').write_text(json.dumps(receipt,indent=2))
print(json.dumps(receipt,indent=2))
