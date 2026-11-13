"""Local object types and catch types per function, from MSVC x86 EH tables.

Read-only.  Every C++ function with destructible locals or try/catch owns a
FuncInfo (magic 0x19930520..22).  Its __ehhandler$ stub loads the FuncInfo
(`mov eax, FuncInfo`) and the owner pushes that stub in its prologue.

  unwind map  -> cleanup funclets -> the destructor each one calls
               = types of the function's destructible locals / temporaries
  try map     -> HandlerType -> TypeDescriptor name = caught types

Destructor names come from the identity closure (bound addresses only).
This is local-type evidence for writing a body; it proves no signature,
layout or ownership by itself.
"""
import argparse
import json
import struct
import sys
from bisect import bisect_right
from collections import Counter, defaultdict
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match  # noqa: E402
from native_conversion_queue import undecorate  # noqa: E402

MAGIC = {0x19930520, 0x19930521, 0x19930522}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    base, image = match._image('2008-06')
    image = bytes(image)
    funcs = sorted((int(a, 16), r['size']) for a, r in match._functions('2008-06').items() if r.get('kind') != 'data')
    starts = [s for s, _ in funcs]

    def owner_of(va):
        i = bisect_right(starts, va) - 1
        return funcs[i][0] if i >= 0 and va < funcs[i][0] + funcs[i][1] else None

    def u32(va):
        return struct.unpack_from('<I', image, va - base)[0]

    def inside(va, size=4):
        return base <= va and va - base + size <= len(image)

    names = defaultdict(list)
    for row in json.loads(args.closure.read_text())['bindings']:
        names[int(row['addr'], 16)].append(row['symbol'])

    # Prologue `push -1; push __ehhandler$X`; the stub then does `mov eax, FuncInfo`.
    funcinfo, owners = {}, defaultdict(list)
    at = image.find(b'\x6a\xff\x68')
    while at != -1:
        stub = struct.unpack_from('<I', image, at + 3)[0]
        fn = owner_of(base + at)
        if fn is not None and inside(stub, 64):
            for k in range(stub - base, stub - base + 59):
                if image[k] == 0xb8:
                    va = struct.unpack_from('<I', image, k + 1)[0]
                    if inside(va, 20) and u32(va) in MAGIC:
                        funcinfo[stub] = va
                        owners[fn].append(va)
                        break
        at = image.find(b'\x6a\xff\x68', at + 1)

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

    def funclet_target(va):
        for insn in md.disasm(image[va - base:va - base + 48], va):
            if insn.mnemonic in ('jmp', 'call') and insn.op_str.startswith('0x'):
                return int(insn.op_str, 16)
            if insn.mnemonic == 'ret':
                break
        return None

    def type_name(td):
        if not td or not inside(td + 8, 1):
            return '...'
        raw = image[td + 8 - base:td + 8 - base + 256].split(b'\0')[0].decode('latin-1')
        text = undecorate('??_R0' + raw[1:] + '@8', 0) if raw.startswith('.') else ''
        return text.replace(" `RTTI Type Descriptor'", '') or raw

    rows, totals = [], Counter()
    for fn, infos in sorted(owners.items()):
        locals_, catches = [], []
        for info in sorted(set(infos)):
            max_state, unwind, ntry, trymap = (u32(info + 4), u32(info + 8), u32(info + 12), u32(info + 16))
            for state in range(min(max_state, 512)):
                entry = unwind + 8 * state
                if not inside(entry, 8):
                    break
                action = u32(entry + 4)
                if not action:
                    continue
                callee = funclet_target(action)
                bound = names.get(callee, [])
                locals_.append({'state': state, 'funclet': '%08x' % action,
                                'calls': '%08x' % callee if callee else None,
                                'callee': [undecorate(s, 0x1000) or s for s in bound[:3]]})
            for t in range(min(ntry, 64)):
                entry = trymap + 20 * t
                if not inside(entry, 20):
                    break
                ncatch, handlers = u32(entry + 12), u32(entry + 16)
                for c in range(min(ncatch, 32)):
                    h = handlers + 16 * c
                    if inside(h, 16):
                        catches.append({'try': t, 'type': type_name(u32(h + 4)), 'handler': '%08x' % u32(h + 12)})
        dtors = sorted({n for l in locals_ for n in l['callee'] if 'destructor' in n or '~' in n})
        totals.update(functions=1, unwind_entries=len(locals_), named_cleanups=sum(bool(l['callee']) for l in locals_),
                      catches=len(catches), owner_named=bool(names.get(fn)))
        rows.append({'function': '%08x' % fn, 'names': names.get(fn, [])[:3], 'local_destructors': dtors,
                     'catch_types': sorted({c['type'] for c in catches}), 'unwind': locals_, 'catches': catches})
    out = {'scope': __doc__.splitlines()[0] + ' Local-type evidence only.',
           'summary': {'funcinfo_found': len(funcinfo), **totals}, 'functions': rows}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
