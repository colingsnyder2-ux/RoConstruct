"""Owner and signature of functions passed as member-function-pointer arguments.

Read-only.  For every call to a bound function whose mangled parameters include
member function pointers (reflection BoundFuncDesc / BoundProp / ComputeProp
constructors and similar), recover the pushed arguments at each call site.  A
pushed function address in a parameter typed `R (__thiscall C::*)(A...)` is
proven to be a member of C with that signature (the compiler would not
convert it otherwise).  String arguments at the same call are reported too
(reflection names: the registered name is not the C++ method name).

Only call sites where every parameter is one 4-byte push are used.
"""
import argparse
import json
import re
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

MEMFN = re.compile(r'^(.*)\((?:__thiscall (.+)::|__cdecl ?|__stdcall ?|__fastcall ?)\*\)\((.*)\)(\s*const)?$')


def params(full):
    """Top-level parameter list of an undecorated function signature."""
    depth, start, out = 0, None, []
    end = full.rfind(')')
    for i in range(end, -1, -1):  # matching '(' of the final parameter list
        depth += full[i] == ')'
        depth -= full[i] == '('
        if depth == 0:
            start = i
            break
    text, depth, cur = full[start + 1:end], 0, ''
    for ch in text:
        depth += ch in '<('
        depth -= ch in '>)'
        if ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip() and cur.strip() != 'void':
        out.append(cur.strip())
    return out


def one_slot(p):
    return '*' in p or '&' in p or p in ('int', 'unsigned int', 'bool', 'long', 'unsigned long', 'float') \
        or p.startswith('enum ')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--strict-first-argument', action='store_true',
                    help='accept only a direct immediate push immediately before the call for the first parameter')
    args = ap.parse_args()
    base, image = match._image('2008-06')
    image = bytes(image)
    funcs = sorted((int(a, 16), r['size']) for a, r in match._functions('2008-06').items() if r.get('kind') != 'data')
    starts = [s for s, _ in funcs]
    names = defaultdict(list)
    callees = {}
    for row in json.loads(args.closure.read_text())['bindings']:
        va = int(row['addr'], 16)
        names[va].append(row['symbol'])
        if ('P8' in row['symbol'] or 'P6' in row['symbol']) and row['symbol'].startswith('?'):
            full = undecorate(row['symbol'], 0)
            ps = params(full)
            if any(MEMFN.match(p) for p in ps):
                callees[va] = (row['symbol'], ps)

    def owner_of(va):
        i = bisect_right(starts, va) - 1
        return funcs[i] if i >= 0 and va < funcs[i][0] + funcs[i][1] else None

    def cstring(va):
        off = va - base
        if not 0 <= off < len(image):
            return None
        raw = image[off:off + 128].split(b'\0')[0]
        return raw.decode('latin-1') if raw and all(32 <= c < 127 for c in raw) else None

    # Call sites: E8 rel32 into a selected callee.
    sites = defaultdict(list)
    for at in range(len(image) - 5):
        if image[at] == 0xe8:
            target = (base + at + 5 + struct.unpack_from('<i', image, at + 1)[0]) & 0xffffffff
            if target in callees:
                fn = owner_of(base + at)
                if fn:
                    sites[fn].append(base + at)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    proofs, totals = defaultdict(list), Counter()
    for (start, size), calls in sites.items():
        # Member pointers may be 4, 8 or 12 bytes (`push imm` or `mov [esp+n], imm`), so take
        # immediates since the previous call; accept only one memfn param and one code immediate.
        imms, wanted, known = [], set(calls), set(starts)
        previous = None
        for insn in md.disasm(image[start - base:start - base + size], start):
            if insn.mnemonic in ('push', 'mov') and insn.op_str.split(', ')[-1].startswith('0x'):
                imms.append(int(insn.op_str.split(', ')[-1], 16))
            elif insn.mnemonic == 'call':
                if insn.address in wanted:
                    symbol, ps = callees[int(insn.op_str, 16)]
                    totals['call_sites'] += 1
                    memfn = [MEMFN.match(p) for p in ps if MEMFN.match(p)]
                    code = sorted({v for v in imms if v in known})
                    if args.strict_first_argument:
                        first = MEMFN.match(ps[0]) if ps else None
                        pushed = (int(previous.op_str, 16) if previous and previous.mnemonic == 'push' and
                                  previous.address + previous.size == insn.address and previous.op_str.startswith('0x') else None)
                        if not first or first[2] is not None or pushed not in known:
                            imms = []
                            previous = insn
                            continue
                        memfn, code = [first], [pushed]
                    if len(memfn) == 1 and len(code) == 1:
                        m = memfn[0]
                        totals['member_pointers'] += 1
                        proofs[code[0]].append({'owner': m[2], 'signature': m[0], 'const': bool(m[4]),
                                                'via': symbol, 'site': '%08x' % insn.address,
                                                'strings': [s for s in map(cstring, imms) if s]})
                    else:
                        totals['skipped_ambiguous_site'] += 1
                imms = []
            previous = insn
    rows = []
    for va, evidence in sorted(proofs.items()):
        owners = sorted({e['owner'] for e in evidence})
        sigs = sorted({e['signature'] for e in evidence})
        rows.append({'address': '%08x' % va, 'bound': names.get(va, [])[:3], 'owner': owners[0] if len(owners) == 1 else None,
                     'signatures': sigs, 'consistent': len(owners) == 1 and len(sigs) == 1, 'evidence': evidence})
    totals.update(functions=len(rows), unnamed=sum(not r['bound'] for r in rows),
                  consistent=sum(r['consistent'] for r in rows), selected_callees=len(callees))
    out = {'scope': __doc__.splitlines()[0] + ' Owner/signature evidence; method names are not implied.',
           'summary': dict(totals), 'functions': rows}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
