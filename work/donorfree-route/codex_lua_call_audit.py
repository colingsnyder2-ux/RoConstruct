"""Compare Lua helper direct-call target names with original registry identities."""
import json
import sys
from collections import defaultdict
from pathlib import Path

import capstone
import pefile

root = Path(__file__).resolve().parent
tag = sys.argv[1] if len(sys.argv) > 1 else 'CodexZ1'
original = pefile.PE(str(root.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
linked = pefile.PE(str(root / ('run/RobloxQT' + tag + '.exe')), fast_load=True)
registry = json.loads((root.parents[1] / 'work/2008-06/identity-registry.json').read_text())
symbols = defaultdict(set)
for line in (root / ('linkexp/qt' + tag + '.map')).read_text(errors='replace').splitlines():
    fields = line.split()
    if len(fields) >= 4:
        try:
            symbols[int(fields[2], 16)].add(fields[1])
        except ValueError:
            pass

addresses = [address for address, names in symbols.items() if 'func_0061fb20' in names]
if len(addresses) != 1 or addresses[0] == 0:
    raise SystemExit('Lua helper is missing or has ambiguous address')
disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def calls(pe, address):
    code = pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, 892)
    return {ins.address - address: int(ins.op_str, 16)
            for ins in disassembler.disasm(code, address)
            if ins.mnemonic == 'call' and ins.op_str.startswith('0x')}


expected, actual = calls(original, 0x61fb20), calls(linked, addresses[0])
errors = 0
for offset, target in expected.items():
    names = symbols.get(actual.get(offset), set())
    registered = (registry.get('%08x' % target) or {}).get('name')
    if 'func_%08x' % target not in names and registered not in names:
        print(f'offset {offset:#x}: original {target:#x}, linked {actual.get(offset)}, names {sorted(names)[:3]}')
        errors += 1
if expected.keys() != actual.keys():
    print('Direct-call offsets differ')
    errors += 1
print(f'{len(expected)} direct calls checked; {errors} need review (registry names are not ABI proof)')
raise SystemExit(bool(errors))
