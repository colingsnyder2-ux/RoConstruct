"""Which bound member functions never touch memory through `this`.

Read-only.  A __thiscall body that never reads or writes [this+N] (it only
passes `this` on, or ignores it) compiles the same whatever the class layout
is, so it can be converted against a declaration-only owner: method
signatures from the mangled names, no fields.  Verdicts:

  fieldless  no memory operand based on a register holding `this`
  touches    at least one [this+N] access (needs proven layout)
  spilled    `this` saved to the stack; not tracked further (treated as unknown)

Linear walk, conservative: registers are dropped from the this-set when
overwritten and after every call (ecx/eax/edx).  Evidence for choosing
conversion candidates only; the byte-exact compile is still the proof.
"""
import argparse
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

import capstone
from capstone import x86 as X

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match  # noqa: E402
from native_conversion_queue import owner, undecorate  # noqa: E402

VOLATILE = {X.X86_REG_EAX, X.X86_REG_ECX, X.X86_REG_EDX}


def classify(md, code, va):
    this, spilled = {X.X86_REG_ECX}, False
    for insn in md.disasm(code, va):
        ops = insn.operands
        for op in ops:
            if op.type == X.X86_OP_MEM and (op.mem.base in this or op.mem.index in this):
                return 'touches'
        if insn.id == X.X86_INS_CALL:
            this -= VOLATILE
        elif insn.id == X.X86_INS_PUSH and ops and ops[0].type == X.X86_OP_REG:
            pass  # passing `this` as an argument, or saving a callee-saved register
        elif len(ops) == 2 and ops[0].type == X.X86_OP_REG:
            dst = ops[0].reg
            if insn.id == X.X86_INS_MOV and ops[1].type == X.X86_OP_REG and ops[1].reg in this:
                this.add(dst)
            elif insn.id not in (X.X86_INS_CMP, X.X86_INS_TEST):
                this.discard(dst)
        elif len(ops) == 2 and ops[0].type == X.X86_OP_MEM and ops[1].type == X.X86_OP_REG and ops[1].reg in this:
            spilled = True
        elif insn.id == X.X86_INS_POP and ops and ops[0].type == X.X86_OP_REG:
            this.discard(ops[0].reg)
    return 'spilled' if spilled else 'fieldless'


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--gate', type=Path, help='native-transplant-gate.json: report its rows separately')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    base, image = match._image('2008-06')
    image = bytes(image)
    funcs = match._functions('2008-06')
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    gate = {}
    if args.gate:
        gate = {r['addr']: r['status'] for r in json.loads(args.gate.read_text())['rows']}
    rows, totals, owners = [], Counter(), defaultdict(Counter)
    seen = set()
    for row in json.loads(args.closure.read_text())['bindings']:
        addr = row['addr']
        if addr in seen or not row['function_start'] or addr not in funcs:
            continue
        full = undecorate(row['symbol'], 0)
        if '__thiscall' not in full:
            continue
        seen.add(addr)
        va = int(addr, 16)
        verdict = classify(md, image[va - base:va - base + funcs[addr]['size']], va)
        state = 'exact' if row['body_exact'] else 'named-not-exact'
        cls = owner(row['symbol'])
        totals[state + ':' + verdict] += 1
        owners[cls][verdict] += 1
        if addr in gate:
            totals['gate:%s:%s' % (gate[addr], verdict)] += 1
        rows.append({'address': addr, 'symbol': row['symbol'], 'owner': cls, 'verdict': verdict,
                     'state': state, 'gate': gate.get(addr), 'size': funcs[addr]['size']})
    whole = sorted(c for c, v in owners.items() if set(v) == {'fieldless'})
    out = {'scope': __doc__.splitlines()[0] + ' Candidate selection only.',
           'summary': dict(sorted(totals.items())), 'owners_entirely_fieldless': len(whole),
           'owners': {c: dict(v) for c, v in sorted(owners.items())}, 'functions': rows}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary'], indent=1), 'owners entirely fieldless', len(whole), 'of', len(owners))


if __name__ == '__main__':
    main()
