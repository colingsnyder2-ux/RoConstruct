"""Verify inactive Humanoid floor-state storage against original instructions."""
import hashlib,json,subprocess,sys
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import match,rebuild
out=ROOT/'rebuild/2008-06/out/native-layouts';src=ROOT/'rebuild/2008-06/tests/NativeHumanoidFloorLayout.cpp';header=ROOT/'rebuild/2008-06/native-headers/humanoid/HumanoidFloorFields.h'
base=json.loads((ROOT/'work/2008-06/shared-layouts/document-compile.json').read_text(encoding='utf8'));flags=base['flags'][:-2]+['/FoNativeHumanoidFloorLayout.obj',str(src)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
ctor,_,_=match.target('2008-06','00643e00');dtor,_,_=match.target('2008-06','006435c0');step,_,_=match.target('2008-06','006451c0');get,_,_=match.target('2008-06','00643d30')
for token in ('895e24','895e28','d9562c','d95630','d95634','8d4e40','8d4e70'):assert bytes.fromhex(token) in ctor,token
for token in ('8b7e28','f00fc108','f00fc111','8b4614','895e14','895e18','895e1c'):assert bytes.fromhex(token) in dtor,token
for token in ('c6432000','8d6b24','d95b2c','d95b30','d95b34','8d4340','8d6b70'):assert bytes.fromhex(token) in step,token
assert get==bytes.fromhex('8b412485c074060528020000c333c0c3')
ins=list(Cs(CS_ARCH_X86,CS_MODE_32).disasm(dtor,0x6435c0));assert any(i.mnemonic=='call' and i.op_str=='0x507d20' for i in ins)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();paths=[src,header,Path(__file__).resolve()]
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},compiler=21022,flags=flags,original_functions=['00643e00','006435c0','006451c0','00643d30'],offsets={'active':32,'floorPart':36,'floorTouchInWorld':44,'previous':64,'current':112},scope='Inactive relative floor-fields layout; strong/weak control, array allocation and state getter supported by code. PartInstance identity and exact field meanings are inferred, not independently proven. No full HumanoidState or runtime swap.')
(ROOT/'work/2008-06/shared-layouts/humanoid-floor-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: Humanoid floor fields and original constructor/destructor/step offsets')
