"""Field and base-subobject evidence from named callees and vftable stores.

For every bound non-static member function, follow `this` (ecx at entry and
registers copied from it) through a linear disassembly of the original body:

  lea ecx,[this+N] ; ... call  C::member      -> a C lives at offset N
  mov dword ptr [this+N], offset C::`vftable'  -> a vfptr of C at offset N

Evidence is aggregated per owner class with vote counts.  The linear walk
ignores control flow, so single votes are weak; rows whose votes disagree are
reported as conflicts.  Binary-derived layout evidence, not a header.
"""
import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc.native_bulk import Targets  # noqa: E402
from native_conversion_queue import owner, undecorate  # noqa: E402

REGS = {'eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp'}
MEM = re.compile(r'^(?:dword ptr )?\[(e\w\w)(?: \+ (0x[0-9a-f]+|\d+))?\]$')
READ_ONLY = {'cmp', 'test', 'push', 'call', 'jmp', 'ret', 'nop'}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    targets = Targets('2008-06')
    symbols = defaultdict(set)
    for row in json.loads(args.closure.read_text())['bindings']:
        symbols[int(row['addr'], 16)].add(row['symbol'])
    this_owner, vftable = {}, {}
    for addr, names in symbols.items():
        scopes = {owner(n) for n in names if '__thiscall' in undecorate(n)}
        if len(scopes) == 1 and len(names) == len([n for n in names if '__thiscall' in undecorate(n)]):
            this_owner[addr] = scopes.pop()
        tables = {owner(n) for n in names if n.startswith('??_7')}
        if len(tables) == 1:
            vftable[addr] = tables.pop()
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    evidence = defaultdict(lambda: defaultdict(Counter))  # class -> offset -> Counter((kind, type))
    walked = 0
    for addr, scope in this_owner.items():
        try:
            code, _ = targets.body('%08x' % addr)
        except (KeyError, ValueError, SystemExit):
            continue
        walked += 1
        this, pending = {'ecx'}, None  # pending: offset loaded into ecx by lea
        for _, _, mnemonic, ops in md.disasm_lite(bytes(code), addr):
            parts = [p.strip() for p in ops.split(',', 1)]
            dst, src = parts[0], parts[1] if len(parts) > 1 else ''
            if mnemonic == 'call':
                target = int(dst, 16) if dst.startswith('0x') else None
                if pending is not None and target in this_owner:
                    evidence[scope][pending][('member-or-base', this_owner[target])] += 1
                pending = None
                this -= {'eax', 'ecx', 'edx'}
                continue
            if mnemonic == 'mov' and src.startswith('0x') and MEM.match(dst):
                base, offset = MEM.match(dst).groups()
                if base in this and int(src, 16) in vftable:
                    evidence[scope][int(offset or '0', 0)][('vfptr', vftable[int(src, 16)])] += 1
                continue
            if mnemonic == 'lea' and dst == 'ecx' and MEM.match(src) and MEM.match(src)[1] in this:
                pending = int(MEM.match(src)[2] or '0', 0)
                this.discard('ecx')
                continue
            if mnemonic == 'mov' and dst in REGS and src in this:
                this.add(dst)
                if dst == 'ecx':
                    pending = 0
                continue
            if dst in REGS and mnemonic not in READ_ONLY:
                this.discard(dst)
                if dst == 'ecx':
                    pending = None
    classes, conflicts, rows = {}, 0, 0
    for scope, offsets in evidence.items():
        fields = []
        for offset, votes in sorted(offsets.items()):
            if offset == 0 and all(t == scope for (_, t) in votes):
                continue  # this passed on to own methods / own primary vfptr
            kinds = {k: dict(Counter({t: n for (kk, t), n in votes.items() if kk == k}))
                     for k in ('vfptr', 'member-or-base')}
            members = kinds['member-or-base']
            agreed = len(members) <= 1
            conflicts += not agreed
            rows += 1
            fields.append({'offset': offset, 'vfptr_of': kinds['vfptr'], 'object_of': members, 'agreed': agreed})
        if fields:
            classes[scope] = fields
    out = {'scope': 'binary-derived field/base evidence; linear walk, votes not proof',
           'summary': {'functions_walked': walked, 'classes': len(classes), 'offset_rows': rows,
                       'rows_with_disagreeing_types': conflicts}, 'classes': classes}
    args.output.write_text(json.dumps(out, indent=1, sort_keys=True) + '\n')
    print(json.dumps(out['summary']))
    for name in ('RBX::Instance', 'RBX::PartInstance', 'RBX::Humanoid'):
        print(name, [(f['offset'], list(f['vfptr_of']) or list(f['object_of'])) for f in classes.get(name, [])][:14])


if __name__ == '__main__':
    main()
