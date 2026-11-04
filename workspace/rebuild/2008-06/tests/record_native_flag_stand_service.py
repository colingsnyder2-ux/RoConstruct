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
assert nb.sha(clients.exe_path('2008-06',clients.load()['2008-06']))==clients.load()['2008-06']['sha256']
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
# Compare const-name RTTI exactly, including every secondary-base offset.
# native_bind's legacy one-sided const-name normalization rejects these tables.
original=Original()
prefix='??_7?$FactoryProduct@VFlagStandService@RBX@@VInstance@2@$1?sFlagStandService@2@3QBDB@RBX@@6B'
vtable_proofs={}
for suffix,address,offset in [
 ('?$GuidItem@VInstance@RBX@@@1@@',0x846104,0),
 ('?$AbstractFactoryProduct@VInstance@RBX@@@1@@',0x8460f8,16),
 ('?$Described@VInstance@RBX@@$1?sInstance@2@3PADAVDescribedBase@Reflection@2@@Reflection@1@@',0x8460f0,20),
 ('Debugable@1@@',0x8460e8,32),
 ('?$Notifier@VInstance@RBX@@UChildAdded@2@@1@@',0x8460d8,36),
 ('?$Notifier@VInstance@RBX@@UChildRemoved@2@@1@@',0x8460c8,68),
 ('?$Notifier@VInstance@RBX@@UDescendantAdded@2@@1@@',0x8460b8,100),
 ('?$Notifier@VInstance@RBX@@UDescendantRemoving@2@@1@@',0x8460a8,132),
 ('?$Notifier@VInstance@RBX@@UAncestorChanged@2@@1@@',0x846098,164),
 ('?$Notifier@VInstance@RBX@@VPropertyChanged@2@@1@@',0x846088,196)]:
 symbol=prefix+suffix
 assert original.vtable_class(address)==('.?AV'+prefix[4:prefix.index('@@6B')+2],offset)
 internal[symbol]=address
 vtable_proofs[symbol]=dict(address=hex(address),offset=offset,exact_rtti=True)
rows=nb.verify(original,obj,methods,internal)
receipt=dict(class_name='RBX::FlagStandService',inactive=True,compiler=21022,flags=flags,
 source_sha256=nb.sha(src),header_sha256=nb.sha(header),methods=rows,vtable_proofs=vtable_proofs,
 blockers=['constructor and remaining methods pending','FlagStand::GetFlag call-site identity only; stand-in declaration has no layout proof','local EH metadata and transitive callee proofs remain separate','no provider selection, runtime gates or server credit'])
receipt.update(scope='inactive partial class; code/relocation checks only, no runtime or server credit',
 original_sha256=nb.sha(clients.exe_path('2008-06',clients.load()['2008-06'])),
 recorder_sha256=nb.sha(Path(__file__)),layout_sha256=nb.sha(R/'tests/NativeFlagStandServiceLayout.cpp'))
(ROOT/'work/2008-06/shared-layouts/flagstandservice-working.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps(receipt,indent=2))
