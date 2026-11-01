"""Check inactive HumanoidState prefix against original RTTI and constructor."""
import hashlib, json, subprocess, sys
from pathlib import Path
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
out = ROOT / 'rebuild/2008-06/out/native-layouts'
source = ROOT / 'rebuild/2008-06/tests/NativeHumanoidStatePrefix.cpp'
header = ROOT / 'rebuild/2008-06/native-headers/humanoid/HumanoidState.h'
evidence = ROOT / 'work/2008-06/shared-layouts/original-evidence.json'
baseline = json.loads((ROOT / 'work/2008-06/shared-layouts/document-compile.json').read_text(encoding='utf8'))
flags = baseline['flags'][:-2] + ['/FoNativeHumanoidStatePrefix.obj', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
obj = (out / 'NativeHumanoidStatePrefix.obj').read_bytes()
name, body, relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith('?humanoidFilter@@'))
assert body == bytes.fromhex('8b44240485c0740483c004c333c0c3') and not relocs
original = json.loads(evidence.read_text(encoding='utf8'))
bases = original['classes']['.?AVHumanoidState@HUMAN@RBX@@']['tables'][0]['hierarchy']['bases']
assert [(x['type'],x['member_displacement']) for x in bases[1:]] == [('.?AVINamed@RBX@@',0),('.?AVHitTestFilter@RBX@@',4)]
target, _, _ = match.target('2008-06','00643e00')
for sequence in ('c70600ad8400','c74604f8ac8400','897e08','d9560c','885e10','885e11','8d4e40','8d4e70'):
    assert bytes.fromhex(sequence) in target, sequence
calls = [int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(target,0x643e00) if i.mnemonic == 'call' and i.op_str.startswith('0x')]
assert calls.count(0x4782d0) == 2
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
paths=[header, source, evidence, Path(__file__).resolve()]
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},compiler_build=21022,flags=flags,base_offsets={'INamed':0,'HitTestFilter':4},prefix_offsets={'humanoid':8,'value0c':12,'flag10':16,'flag11':17},coordinate_frame_constructor_calls=[64,112],scope='Incomplete inactive prefix only; field semantics, remaining state storage, virtual methods, destructor and runtime linkage unverified. CoordinateFrame members are evidenced but not declared in the incomplete prefix.')
(ROOT/'work/2008-06/shared-layouts/humanoid-state-prefix-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: HumanoidState prefix, RTTI bases and two CoordinateFrame constructor sites')
