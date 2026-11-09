"""Verify inactive native frame destructor with provisional pane ownership."""
import hashlib,json,struct,subprocess,sys
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
import pefile
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match,rebuild
out=ROOT/'rebuild/2008-06/out/native-layouts';constructor=ROOT/'rebuild/2008-06/tests/record_native_main_frame_constructor_trial.py'
subprocess.run([sys.executable,str(constructor)],cwd=ROOT,check=True)
source=ROOT/'rebuild/2008-06/native-classes/CMainFrameDestructor.cpp'
baseline=json.loads((ROOT/'work/2008-06/shared-layouts/main-frame-create-working-probe.json').read_text(encoding='utf8'));flags=baseline['flags'][:-2]+['/FoNativeMainFrameDestructorTrial.obj',str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
obj=(out/'NativeMainFrameDestructorTrial.obj').read_bytes();name,body,refs=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith('??1CMainFrame@@'));target,tr,_=match.target('2008-06','00432000');assert match.exact_match(target,tr,body,refs)
sections,symbols,defs,_=match._coff_data_index(obj);start,sec=defs[name];table=sections[sec];rel={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',obj,table[5]+i*10)
 if start<=off<start+len(body):rel[off-start]=symbols[sym][0]
calls={i.address-0x432000+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(target,0x432000) if i.mnemonic=='call' and i.op_str.startswith('0x')}
for off,prefix,addr in ((0x43,'?InternalRelease@CCmdTarget@@',0x6a0be4),(0x58,'?removeListener@',0x5e5a80),(0x68,'??1CXTPStatusBar@@',0x70fe40),(0x78,'??1CXTThemeManager@@',0x70d980),(0xd0,'??1CXTPTabClientWnd@@',0x7052f0),(0xe0,'??1CXTPDockingPaneManager@@',0x6e4da0),(0x102,'??1worker_thread@RBX@@',0x4273a0),(0x120,'??1?$CXTPCommandBarsSiteBase@',0x430490)):
 assert rel[off].startswith(prefix) and calls[off]==addr,(off,rel.get(off),calls.get(off))
pe=pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'));assert any(x.address==0x803100 and x.ordinal==4262 and d.dll.lower()==b'mfc90.dll' for d in pe.DIRECTORY_ENTRY_IMPORT for x in d.imports)
assert '?InternalRelease@CCmdTarget@@' in next(x for x in (ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='replace').splitlines() if ' @ 4262 NONAME' in x)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[source,constructor,ROOT/'rebuild/2008-06/native-headers/CMainFrame.h',Path(__file__).resolve()]
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},flags=flags,method=dict(address='00432000',symbol=name,size=len(body),relocation_normalized_exact=True),scope='Inactive trial with shared typed scoped pane owners and recovered caption/property-grid layouts; selected destructor targets and MFC ordinal verified. Actual pane types/ownership template, global data, exception metadata and runtime remain open.')
(ROOT/'work/2008-06/shared-layouts/main-frame-destructor-trial-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: inactive frame destructor trial 309 bytes; selected calls verified')
