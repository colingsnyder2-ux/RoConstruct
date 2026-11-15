"""Routes 2b + 3: name unnamed functions by aligning compiled objects with the original.

Input: identity_unlock_objindex.py output(s).  Names known = registry names plus names
accepted in earlier rounds; repeated to a fixpoint.
  vtable  - an object emitting the same ??_7 symbol as an original vtable names the
            symbol at each slot (compiler-reported virtual order).
  caller  - an object body of a named caller C with the same number of direct calls as
            the original C, agreeing at every named callee (>=1 anchor), names the
            callee symbol at an unnamed position.
  callee  - an object function (symbol not yet a registry name) whose direct-call list has
            the original's length and agrees at every named position, with >=3 anchors
            counting call and string/data references, is a candidate for the unnamed
            function itself.  Only a single surviving candidate symbol is accepted.
A symbol voted to two addresses, or an address with two symbols, is rejected.
Output: work/native-client/identity-unlock-align.json
"""
import gzip
import json
import pickle
import sys
from collections import defaultdict, Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, BASE, IMG, MD, end_of, unnamed, CODE_STARTS  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-align.json'
CODESET = set(CODE_STARTS)


def target_refs(va):
    """(direct call targets in order, registry names of referenced non-code data)"""
    o = va - BASE
    calls, data = [], set()
    for i in MD.disasm(bytes(IMG[o:o + (end_of(va) - va)]), va):
        if i.mnemonic == 'call' and i.op_str.startswith('0x'):
            t = int(i.op_str, 16)
            if t in CODESET:
                calls.append('%08x' % t)
            continue
        for op in i.operands:
            v = op.imm if op.type == 2 else (op.mem.disp if op.type == 3 and op.mem.base == 0 else None)
            if v is None:
                continue
            row = REG.get('%08x' % (v & 0xffffffff))
            if row and not row.get('placeholder'):
                data.add(row['name'])
    return calls, data


def load(paths):
    funcs, tabs = set(), set()
    for p in paths:
        with gzip.open(p, 'rb') as fh:
            d = pickle.load(fh)
        funcs.update(d['funcs'])
        tabs.update(d['vtables'])
    return funcs, tabs


def main():
    idx = sys.argv[1:] or [str(NC / 'identity-unlock-objindex.pkl.gz')]
    funcs, tabs = load(idx)
    print('index funcs', len(funcs), 'vtables', len(tabs), flush=True)
    targets = set(unnamed())
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder')}
    regnames = set(name.values())
    by_symbol = defaultdict(list)
    by_ref = defaultdict(list)
    for row in funcs:
        by_symbol[row[0]].append(row)
        if row[0] not in regnames:
            for r in set(row[2]) | set(row[3]):
                by_ref[r].append(row)
    seq = {}
    for va in CODE_STARTS:
        a = '%08x' % va
        if REG[a]['kind'] == 'code':
            seq[a] = target_refs(va)
    callers_of = defaultdict(set)
    for a, (c, _) in seq.items():
        for t in c:
            callers_of[t].add(a)
    vt_slots = {}
    for a, v in REG.items():
        if v['kind'] == 'vtable':
            vt_slots[v['name']] = int(a, 16)
    accepted = {}

    def known(a):
        return name.get(a) or (accepted[a][0] if a in accepted else None)

    rnd = 0
    while True:
        rnd += 1
        votes = defaultdict(lambda: defaultdict(list))
        # vtable slots
        if rnd == 1:
            for vname, slots in tabs:
                base = vt_slots[vname]
                at = {off: '%08x' % int.from_bytes(IMG[base + off - BASE:base + off - BASE + 4], 'little')
                      for off, _ in slots if off >= 0}
                # a compiled vtable whose virtual order differs from the original (imperfect
                # header) shifts every slot: require agreement at every already-named slot
                named_slots = [(at[off], sym) for off, sym in slots if off >= 0 and at[off] in name]
                if not named_slots or any(name[t] != sym for t, sym in named_slots):
                    continue
                for off, sym in slots:
                    if off >= 0 and at[off] in targets:
                        votes[at[off]][sym].append(('vtable', vname, off // 4))
        # caller alignment
        work = {t for t in targets if t not in accepted}
        callers = {c for t in work for c in callers_of.get(t, ()) if known(c)}
        for c in callers:
            tc, _ = seq[c]
            for row in by_symbol.get(known(c), ()):
                oc = row[2]
                if len(oc) != len(tc):
                    continue
                anchors = 0
                for t, o in zip(tc, oc):
                    k = known(t)
                    if k is not None:
                        if k != o:
                            break
                        anchors += 1
                else:
                    if anchors:
                        for t, o in zip(tc, oc):
                            if t in work:
                                votes[t][o].append(('caller', c, known(c)))
        # callee alignment
        for t in work:
            tc, td = seq.get(t, ([], set()))
            if not tc and not td:
                continue
            named_calls = [(i, known(x)) for i, x in enumerate(tc) if known(x)]
            keys = [k for _, k in named_calls] + sorted(td)
            if len(keys) < 2:
                continue
            pool = min((by_ref.get(k, ()) for k in keys), key=len)
            if len(pool) > 20000:
                continue
            size = end_of(int(t, 16)) - int(t, 16)
            for row in pool:
                sym, ln, oc, od = row
                if len(oc) != len(tc) or not (size * 3 // 4 <= ln <= size * 4 // 3):
                    continue
                if any(oc[i] != k for i, k in named_calls):
                    continue
                anchors = len(named_calls) + len(td & set(od))
                if anchors >= 3 and sym not in regnames:
                    votes[t][sym].append(('callee', anchors))
        # resolve
        used = Counter(s for v in accepted.values() for s in [v[0]])
        cand = {}
        for t, syms in votes.items():
            syms = {s: e for s, e in syms.items() if s not in regnames and s[:1] in '?_' and not s.startswith('??_C@')}
            if len(syms) == 1:
                cand[t] = next(iter(syms.items()))
        per_sym = Counter(s for s, _ in cand.values())
        new = 0
        for t, (s, ev) in cand.items():
            if per_sym[s] == 1 and not used[s] and t not in accepted:
                accepted[t] = (s, ev, rnd)
                new += 1
        print('round', rnd, 'new', new, 'total', len(accepted), flush=True)
        if not new:
            break
    out = {}
    for t, (s, ev, r) in accepted.items():
        kinds = Counter(e[0] for e in ev)
        out[t] = {'name': s, 'owner_class': None, 'signature': None, 'kind': 'code',
                  'name_source': 'identity-unlock-align',
                  'evidence': [{'kind': 'object-alignment-' + kinds.most_common(1)[0][0], 'round': r,
                                'votes': dict(kinds), 'sample': [list(map(str, e)) for e in ev[:3]]},
                               {'kind': 'decorated-signature', 'symbol': s}]}
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('bound', len(out), Counter(v['evidence'][0]['kind'] for v in out.values()))


if __name__ == '__main__':
    main()
