"""Inactive Explosion ctor/dtor proof; no provider selection."""
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
assert nb.sha(clients.exe_path('2008-06',clients.load()['2008-06']))==clients.load()['2008-06']['sha256']
recipe=libs.RECIPES['rbxgs']
flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/D_AFXDLL','/DNDEBUG','/D_MBCS','/DBOOST_ALL_NO_LIB']
flags+=['/D'+v for v in recipe['defines'].split()]
flags+=['/I'+str(R/'native-headers'),'/I'+str(ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags+=['/I'+str((libs.LIBS/v).resolve()) for v in recipe['include'] if v!='WINSDK']
flags+=['/D_XTP_STATICLINK','/D_XTPLIB_NOAUTOLINK','/I'+str(ROOT/'tools/libs/xtp-11.2.2/Source')]
src=R/'native-classes/Explosion.cpp'; header=R/'native-headers/v8datamodel/Explosion.h'
obj=nb.OUT/'CheckExplosion.obj'
for source,output in [(src,obj),(R/'tests/NativeExplosionLayout.cpp',nb.OUT/'NativeExplosionLayout.obj')]:
 code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(output),str(source)],nb.OUT)
 assert code==0,log
methods=[(n,a) for prefix,a in [('??0Explosion',0x62adb0),('??1Explosion',0x62af60),('?shouldRender3dAdorn@Explosion',0x565950)] for n,b,r in match.coff_functions(obj.read_bytes()) if n.startswith(prefix)]
internal={}
for n,b,r in match.coff_functions(obj.read_bytes()):
 # Constructor call at 0062adcf proves the out-of-line DescribedCreatable target.
 if n.startswith('??0?$DescribedCreatable@VExplosion'): internal[n]=0x62ab80
 # Destructor tail call at 0062aff8 proves FactoryProduct cleanup.
 if n.startswith('??1?$FactoryProduct@VExplosion'): internal[n]=0x629c60
# 0062afe9 directly calls IRenderable cleanup.
internal['??1IRenderable@RBX@@QAE@XZ']=0x47d410
# 0062aea3 calls Instance::setName.
internal['?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z']=0x55af90
internal['__real@40800000']=0x826e6c  # orchestrator-verified: original dword 0x40800000 (4.0f)
internal['__real@48f42400']=0x845dec  # orchestrator-verified: original dword 0x48f42400 (500000.0f)
assert len(methods)==3, methods
original=Original()
assert original.data(0x826e6c,4)==bytes.fromhex('00008040')
assert original.data(0x845dec,4)==bytes.fromhex('0024f448')
rows=nb.verify(original,obj,methods,internal)
receipt=dict(class_name='RBX::Explosion',inactive=True,compiler=21022,flags=flags,source_sha256=nb.sha(src),header_sha256=nb.sha(header),layout=dict(size=348,age=324,position=328,blastRadius=340,blastPressure=344),methods=rows,blockers=['partial class: reflection statics, other methods, transitive callees and local EH metadata pending; no runtime or server credit'])
receipt.update(original_sha256=nb.sha(clients.exe_path('2008-06',clients.load()['2008-06'])),recorder_sha256=nb.sha(Path(__file__)),layout_sha256=nb.sha(R/'tests/NativeExplosionLayout.cpp'))
(ROOT/'work/2008-06/shared-layouts/explosion-working.json').write_text(json.dumps(receipt,indent=2))
print(json.dumps(receipt,indent=2))
