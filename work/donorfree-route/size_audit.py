"""For every Creatable<Instance>::create<X> in the linked exe, compare the operator-new size it pushes with the size
pushed by every other copy in the link inputs (donor lib members, native objects). A copy whose size differs from
the chosen one means the object's ctor and its allocation can come from different layouts (heap overrun/underrun).

    python work/donorfree-route/size_audit.py
"""
import re, struct, sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import libs, match
import capstone

BASE = ROOT / 'rebuild/2008-06/out/native-current-audit'
CREATE = re.compile(r'^\?\?\$create@V(\w+)@RBX@@@\?\$Creatable@VInstance@RBX@@@RBX@@SA\?AV\?\$shared_ptr@V\1@RBX@@@boost@@XZ$')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def new_size(code):
    """First immediate pushed right before the first call (operator new)."""
    last = None
    for ins in md.disasm(code[:96], 0):
        if ins.mnemonic == 'push' and ins.op_str.startswith('0x'):
            last = int(ins.op_str, 16)
        elif ins.mnemonic == 'call':
            return last
    return None


def inputs():
    for line in (BASE / 'roblox_test.rsp').read_text().splitlines():
        p = Path(line.strip().strip('"'))
        if not p.is_absolute():
            p = BASE / p
        if p.suffix.lower() == '.obj' and p.exists():
            yield p.name, p.read_bytes()
        elif p.suffix.lower() == '.lib' and p.exists() and p.stat().st_size > 1_000_000:
            for name, raw in libs.archive_members(p):
                yield p.stem + ':' + name, raw


def main():
    mp = (BASE / 'roblox.map').read_text(errors='replace')
    chosen = {}
    for m in re.finditer(r'^\s*\S+\s+(\S+)\s+([0-9a-f]{8}) f? ?(?:i )?\s*(\S+)$', mp, re.M):
        if CREATE.match(m.group(1)):
            chosen[m.group(1)] = (int(m.group(2), 16), m.group(3))
    exe = (BASE / 'roblox.exe').read_bytes()
    pe = struct.unpack_from('<I', exe, 0x3c)[0]
    nsec, optsz = struct.unpack_from('<H', exe, pe + 6)[0], struct.unpack_from('<H', exe, pe + 20)[0]
    secs = [struct.unpack_from('<8sIIII', exe, pe + 24 + optsz + 40 * i) for i in range(nsec)]

    def at(va):
        rva = va - 0x400000
        for _, vsz, vaddr, rsz, rptr in secs:
            if vaddr <= rva < vaddr + rsz:
                return exe[rptr + rva - vaddr: rptr + rva - vaddr + 96]
    copies = defaultdict(list)
    for owner, raw in inputs():
        try:
            fns = match.coff_functions(raw)
        except Exception:
            continue
        for row in fns:
            if row[0] in chosen:
                copies[row[0]].append((owner, new_size(row[1])))
    bad = 0
    for sym, (va, owner) in sorted(chosen.items(), key=lambda x: CREATE.match(x[0]).group(1)):
        size = new_size(at(va))
        others = sorted({(o, s) for o, s in copies[sym] if s != size})
        cls = CREATE.match(sym).group(1)
        if others:
            bad += 1
            print('%-22s linked %s (from %s) vs %s' % (cls, hex(size or 0), owner, ', '.join('%s=%s' % (o, hex(s or 0)) for o, s in others)))
    print('mismatched classes:', bad, 'of', len(chosen))


if __name__ == '__main__':
    main()
