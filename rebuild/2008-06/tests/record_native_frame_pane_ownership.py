"""Compare native pane replacement with real Boost and standard ownership."""
import hashlib,json,subprocess,sys
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match,rebuild
out=ROOT/'rebuild/2008-06/out/native-layouts';src=ROOT/'rebuild/2008-06/tests/NativeFramePaneOwnership.cpp'
base=json.loads((ROOT/'work/2008-06/shared-layouts/main-frame-create-working-probe.json').read_text(encoding='utf8'));flags=base['flags'][:-2]+['/FoNativeFramePaneOwnership.obj',str(src)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
obj=(out/'NativeFramePaneOwnership.obj').read_bytes();target,tr,_=match.target('2008-06','00430440');rows=[]
for prefix,expected in (('?reset@ScopedWindow@@',True),('?reset@AutoWindow@@',False)):
 name,body,refs=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix));equal=bool(match.exact_match(target,tr,body,refs));assert equal==expected
 rows.append(dict(symbol=name,size=len(body),relocation_normalized_exact=equal))
handler,_,_=match.target('2008-06','004314e0');calls=[i.address for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(handler,0x4314e0) if i.mnemonic=='call' and i.op_str=='0x430440'];assert calls==[0x431587,0x4315f5,0x431699]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,ROOT/'tools/rbxgs/Client/boost_1_34_1/src/boost/scoped_ptr.hpp',Path(__file__).resolve()]
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},compiler=21022,flags=flags,target='00430440',comparisons=rows,frame_calls=[hex(x) for x in calls],scope='Boost scoped_ptr<CWnd> reset emits same 32-byte code; std::auto_ptr reset differs. Identical compiled behavior does not prove original template identity or complete pane ABI. Inactive only.')
(ROOT/'work/2008-06/shared-layouts/frame-pane-ownership-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: pane reset matches Boost scoped_ptr, differs from std::auto_ptr')
