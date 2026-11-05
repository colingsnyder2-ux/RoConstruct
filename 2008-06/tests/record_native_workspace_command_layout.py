"""Verify Workspace command members across native initialization and destruction."""
import hashlib
import json
import sys
from pathlib import Path

import capstone

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match

decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
expected = {
    '005a4d90': [('0x5a4f8f', 'mov', 'dword ptr [esi + 0x3b0], ebx'), ('0x5a4f95', 'mov', 'dword ptr [esi + 0x3b4], ebx')],
    '005a28c0': [('0x5a2b10', 'mov', 'ecx, dword ptr [esi + 0x3b4]'), ('0x5a2b28', 'mov', 'ecx, dword ptr [esi + 0x3b0]')],
    '005a0610': [('0x5a0613', 'mov', 'ecx, dword ptr [esi + 0x3b4]'), ('0x5a0637', 'mov', 'ecx, dword ptr [esi + 0x3b0]'), ('0x5a0653', 'mov', 'dword ptr [esi + 0x3b0], edi')],
    '005c6240': [('0x5c6249', 'mov', 'eax, dword ptr [ecx + 0x3b0]')],
}
rows = []
for address, required in expected.items():
    body, _, _ = match.target('2008-06', address)
    instructions = {(hex(ins.address), ins.mnemonic, ins.op_str) for ins in decoder.disasm(body, int(address, 16))}
    assert set(required) <= instructions, (address, set(required) - instructions)
    rows.append({'address': address, 'sha256': hashlib.sha256(body).hexdigest(), 'instructions': [list(item) for item in required]})
profile = root / 'work/2008-06/shared-layouts/workspace-lifetime-profiler-notifier-variant.json'
data = json.loads(profile.read_text())
assert all(row['exact'] for row in data['methods'])
receipt = {'scope': 'Original constructor, destructor, default-command setter and RTTI predicate corroborate two command-pointer offsets. Complete Workspace ABI remains unproven.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'lifetime_profile_sha256': hashlib.sha256(profile.read_bytes()).hexdigest(), 'current_command_offset': '0x3b0', 'sticky_command_offset': '0x3b4', 'methods': rows}
(root / 'work/2008-06/shared-layouts/workspace-command-layout-evidence.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Workspace command ownership at +0x3b0/+0x3b4')
