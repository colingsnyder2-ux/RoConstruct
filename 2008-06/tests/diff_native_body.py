"""Side-by-side instruction diff of one native body against the original.
usage: diff_native_body.py out/native-layouts/Check<File>.obj ADDR symbol-prefix [context]"""
import difflib, sys
from pathlib import Path
import capstone
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402

obj, addr, prefix = Path(sys.argv[1]), sys.argv[2], sys.argv[3]
context = int(sys.argv[4]) if len(sys.argv) > 4 else 3
target, relocs, _ = match.target('2008-06', addr)
name, body, brelocs = next(f for f in match.coff_functions(obj.read_bytes()) if f[0].startswith(prefix))
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

def lines(code, masked):
    out = []
    for i in md.disasm(code, 0):
        hit = any(i.address <= r < i.address + i.size for r in masked)
        ops = i.op_str
        if hit:  # every number in a relocated instruction is a link-time value
            import re
            ops = re.sub(r'\b(0x[0-9a-f]+|\d+)\b', '<r>', ops)
        out.append('%s %s' % (i.mnemonic, ops))
    return out

a, b = lines(target, set(relocs) | set(brelocs)), lines(body, set(relocs) | set(brelocs))
print(name, len(target), len(body))
for group in difflib.SequenceMatcher(None, a, b, autojunk=False).get_grouped_opcodes(context):
    for tag, i1, i2, j1, j2 in group:
        if tag == 'equal':
            for x in a[i1:i2]:
                print('    ', x)
        else:
            for x in a[i1:i2]:
                print('  - ', x)
            for x in b[j1:j2]:
                print('  + ', x)
    print('  ...')
