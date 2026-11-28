"""Compare converted Lock cleanup targets with original EH unwind maps."""
import collections, re, struct, sys
from pathlib import Path
import capstone, pefile

root = Path(__file__).resolve().parent.parent
ours = pefile.PE(str(root / 'run/RobloxQT.exe')).get_memory_mapped_image()
orig = pefile.PE(str(root / 'run/RobloxOrig.exe')).get_memory_mapped_image()
base = 0x400000
u32 = lambda image, addr: struct.unpack_from('<I', image, addr - base)[0]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True
def insns(image, addr, size):
    result = []
    for i in md.disasm(image[addr-base:addr-base+size], addr):
        result.append(i)
        if i.mnemonic in ('jmp', 'ret'):
            break
    return result

results = collections.defaultdict(list)
stub_names = collections.defaultdict(list)
lines = (root / 'linkexp/qt.map').read_text(errors='replace').splitlines()
stub_targets = {0x7ca2d8}
if '--all-stubs' in sys.argv:
    stub_targets = {int(p[2], 16) for line in lines if len(p := line.split()) >= 4 and p[0].startswith('0001:') and 'stubs' in p[-1]}
    for line in lines:
        p = line.split()
        if len(p) >= 4 and p[0].startswith('0001:') and 'stubs' in p[-1]:
            stub_names[int(p[2], 16)].append(p[1])
for line in lines:
    parts = line.split()
    if len(parts) < 4 or not parts[1].startswith('__ehfuncinfo$'):
        continue
    match = re.search(r'(?:^|_)([0-9a-f]{8})\.obj$', parts[-1], re.I)
    if not match:
        continue
    original = int(match.group(1), 16)
    info = int(parts[2], 16)
    try:
        count, unwind = u32(ours, info+4), u32(ours, info+8)
        affected = []
        for index in range(min(count, 100)):
            action = u32(ours, unwind+8*index+4)
            jumps = [i.operands[0].imm for i in insns(ours, action, 16) if i.mnemonic == 'jmp' and i.operands[0].type == capstone.x86.X86_OP_IMM and i.operands[0].imm in stub_targets] if action else []
            if jumps:
                affected.append((index, jumps[0]))
        if not affected:
            continue
        handlers = [i.operands[0].imm for i in insns(orig, original, 96) if i.mnemonic == 'push' and i.operands[0].type == capstone.x86.X86_OP_IMM and base <= i.operands[0].imm < base+len(orig)]
        orig_info = next(u32(orig, h+1) for h in handlers if orig[h-base] == 0xb8 and u32(orig, u32(orig, h+1)) in (0x19930520, 0x19930521, 0x19930522))
        orig_map = u32(orig, orig_info+8)
        for index, stub in affected:
            action = u32(orig, orig_map+8*index+4)
            targets = [i.operands[0].imm for i in insns(orig, action, 16) if i.mnemonic in ('jmp', 'call') and i.operands[0].type == capstone.x86.X86_OP_IMM]
            if not targets and '--all-stubs' not in sys.argv:
                print('unresolved action', parts[-1], index, hex(action), '; '.join(i.mnemonic + ' ' + i.op_str for i in insns(orig, action, 24)))
            results[','.join('%08x' % x for x in targets) or '?'].append(parts[-1])
            if '--details' in sys.argv and targets:
                print('DETAIL', parts[-1], '%08x' % targets[0], '|'.join(stub_names[stub][:3]))
    except (ValueError, IndexError, struct.error, StopIteration):
        results['unresolved'].append(parts[-1])
for target, objects in sorted(results.items(), key=lambda row: -len(row[1])):
    print(target, len(objects), ' '.join(objects[:20]))
