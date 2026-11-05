"""Probe inactive CMainFrame constructor using shared typed pane owners."""
import hashlib,json,struct,subprocess,sys
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match,rebuild
out=ROOT/'rebuild/2008-06/out/native-layouts';header=ROOT/'rebuild/2008-06/native-headers/CMainFrame.h';source=ROOT/'rebuild/2008-06/native-classes/CMainFrameConstructor.cpp'
baseline=json.loads((ROOT/'work/2008-06/shared-layouts/main-frame-create-working-probe.json').read_text(encoding='utf8'));pre=[f for f in baseline['flags'][:-2] if f!='/c']+['/P',str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',pre,out);assert code==0,log
body=(out/'CMainFrameConstructor.i').read_text(encoding='utf8',errors='replace')
for needle in ('const _Elem * c_str() const','size_type  size() const'):
 assert body.count(needle)==1;body=body.replace(needle,'__declspec(noinline) '+needle)
translation=out/'CMainFrameConstructorNoInline.cpp';translation.write_text(body,encoding='utf8')
flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/FoNativeMainFrameConstructorNoInline.obj',str(translation)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
obj=(out/'NativeMainFrameConstructorNoInline.obj').read_bytes();name,candidate,refs=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith('??0CMainFrame@@'));target,tr,_=match.target('2008-06','004321f0');assert match.exact_match(target,tr,candidate,refs)
sections,symbols,definitions,_=match._coff_data_index(obj);start,sec=definitions[name];table=sections[sec];references={}
for i in range(table[7]):
 offset,symbol,kind=struct.unpack_from('<IIH',obj,table[5]+i*10)
 if start<=offset<start+len(candidate):references[offset-start]=symbols[symbol][0]
calls={i.address-0x4321f0+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(target,0x4321f0) if i.mnemonic=='call' and i.op_str.startswith('0x')}
for off,prefix,addr in ((0x23,'??0CXTPMDIFrameWnd@@',0x6e1980),(0x88,'??0CXTWindowPos@@',0x6e4a80),(0x93,'??0CXTPDockingPaneManager@@',0x6e6b80),(0xa3,'??0CXTPTabClientWnd@@',0x703600),(0xc5,'??0CXTThemeManager@@',0x70dbb0),(0xd5,'??0CXTPStatusBar@@',0x70ea60),(0x15a,'?getUserAppDataDirectory@FileSystem@RBX@@',0x5a7ac0),(0x19b,'?addListener@',0x4218a0),(0x1a0,'?XTPImageManager@@',0x6c0e80),(0x1bb,'?SetImageManager@CXTPDockingPaneManager@@',0x6e4f50)):
 assert references[off].startswith(prefix) and calls[off]==addr,(off,references.get(off),calls.get(off))
assert references[0x16c].startswith('__imp_?size@?$basic_string') and references[0x17a].startswith('__imp_?c_str@?$basic_string')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[header,source,ROOT/'rebuild/2008-06/native-headers/CDataModelPropGrid.h',ROOT/'rebuild/2008-06/native-headers/CSelectionPropGrid.h',ROOT/'rebuild/2008-06/native-headers/CPropGrid.h',ROOT/'rebuild/2008-06/native-headers/CSelectionCaption.h',ROOT/'rebuild/2008-06/native-headers/util/MarshaledListener.h',ROOT/'roc/libs.py',Path(__file__).resolve()]
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},compiler=21022,preprocess_flags=pre,compile_flags=flags,method=dict(address='004321f0',symbol=name,size=len(candidate),relocation_normalized_exact=True),scope='Shared frame declaration uses typed scoped pane owners and recovered 0x1c8 caption/0x248 property-grid layouts; body and selected calls match. Owner template identity, class layouts, global identities, exception/unwind tables, data relocations and runtime remain unverified; not an active swap.')
(ROOT/'work/2008-06/shared-layouts/main-frame-constructor-trial-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: inactive frame constructor trial 483 bytes; selected calls verified')
