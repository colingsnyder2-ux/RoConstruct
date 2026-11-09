"""Record native DataModel constructor member writes and calls."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_MEM, X86_OP_IMM, X86_REG_ESI

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

exe = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(exe), fast_load=True)
address = 0x57b9f0
body, relocs, row = match.target('2008-06', '%08x' % address)
assert body == pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, len(body))
decoder = Cs(CS_ARCH_X86, CS_MODE_32)
decoder.detail = True
writes, calls = [], []
for instruction in decoder.disasm(body, address):
    if instruction.mnemonic == 'mov' and instruction.operands[0].type == X86_OP_MEM:
        memory = instruction.operands[0].mem
        if memory.base == X86_REG_ESI and memory.disp >= 0x1c8:
            writes.append(dict(address=hex(instruction.address), offset=hex(memory.disp),
                               width=instruction.operands[0].size, instruction=instruction.op_str))
    if instruction.mnemonic == 'call':
        calls.append(dict(address=hex(instruction.address), target=instruction.op_str))

assert any(entry['offset'] == '0x1fc' for entry in writes)
assert any(entry['offset'] == '0x25c' for entry in writes)
assert any(entry['target'] == '0x576ff0' for entry in calls)
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               original_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(),
               observer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
               constructor=hex(address), body_sha256=hashlib.sha256(body).hexdigest(),
               size=0x264, writes=writes, calls=calls,
               scope='Original constructor instructions; member types require separate evidence. No active ABI change.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('DataModel constructor:', len(writes), 'member writes,', len(calls), 'calls')
