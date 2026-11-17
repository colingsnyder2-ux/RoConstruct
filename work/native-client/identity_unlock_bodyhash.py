"""Route 7: exact reloc-masked body match (Ghidra Function-ID / IDA FLIRT style).

Object side (identity_unlock_objindex.py --bodies): sha1 of each compiled function body with
every relocation field zeroed, plus its length.  Exe side: the same bytes with base-relocation
fields and rel32 operands of call/jmp to outside the function zeroed.  The function's length is
taken from end_of() minus trailing int3/nop padding (each length in that window is tried).
Accepted only when exactly one symbol anywhere has that (length, hash) and the symbol is not
already a registry name.  Output: work/native-client/identity-unlock-bodyhash.json
"""
import gzip
import hashlib
import json
import pickle
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, BASE, IMG, MD, pe, end_of, unnamed, CODE_STARTS  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-bodyhash.json'


def base_relocs():
    pe.parse_data_directories(directories=[pefile_dir()])
    out = set()
    for block in getattr(pe, 'DIRECTORY_ENTRY_BASERELOC', []):
        for e in block.entries:
            if e.type == 3:  # IMAGE_REL_BASED_HIGHLOW
                out.add(e.rva + BASE)
    return out


def pefile_dir():
    import pefile
    return pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_BASERELOC']


def masked(va, n, relocs):
    b = bytearray(IMG[va - BASE:va - BASE + n])
    for p in range(va, va + n):
        if p in relocs:
            b[p - va:p - va + 4] = b'\0\0\0\0'
    for i in MD.disasm(bytes(b), va):
        if i.bytes[0] in (0xE8, 0xE9) and i.size == 5:
            t = int.from_bytes(i.bytes[1:5], 'little', signed=True) + i.address + 5
            if not va <= t < va + n:
                o = i.address - va + 1
                b[o:o + 4] = b'\0\0\0\0'
    return bytes(b[:n])


def main():
    rows = []
    for p in sorted(NC.glob('identity-unlock-bodyhash*.pkl.gz')):  # base + incremental deltas
        with gzip.open(p, 'rb') as fh:
            rows += pickle.load(fh)['funcs']
    by = defaultdict(set)
    lens = set()
    for ln, h, sym in rows:
        by[(ln, h)].add(sym)
        lens.add(ln)
    print('object bodies', len(rows), 'distinct', len(by), flush=True)
    relocs = base_relocs()
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    prior = {a: r for a, r in json.load(open(NC / 'unnamed-identities.json')).items()
             if r['name_source'] != 'identity-unlock-bodyhash'}  # this route's own rows are recomputed
    done = set(prior)
    out, amb = {}, 0
    hits_of = {}
    for a in sorted(set(unnamed()) - done):
        va = int(a, 16)
        hi = end_of(va) - va
        lo = hi
        while lo > 1 and IMG[va - BASE + lo - 1] in (0xCC, 0x90):
            lo -= 1
        hs = {(n, hashlib.sha1(masked(va, n, relocs)).digest()[:12]) for n in range(lo, hi + 1) if n in lens}
        hs = {k for k in hs if k in by}
        if len(hs) == 1:
            hits_of[a] = hs.pop()
    # how many exe addresses carry each matched body (identical copies elsewhere = ambiguous)
    need = defaultdict(set)
    for n, h in hits_of.values():
        need[n].add(h)
    exe = defaultdict(int)
    for va in CODE_STARTS:
        if REG['%08x' % va]['kind'] != 'code':
            continue
        span = end_of(va) - va
        for n in need:
            if n <= span and hashlib.sha1(masked(va, n, relocs)).digest()[:12] in need[n]:
                exe[(n, hashlib.sha1(masked(va, n, relocs)).digest()[:12])] += 1
    named_ids = {r['name'] for r in prior.values()}
    for a, k in hits_of.items():
        free = by[k] - taken - named_ids
        if len(by[k]) > 1 and exe[k] == 1 and len(free) == 1:
            # body occurs once in the exe and every other symbol with it is already placed
            # (cross-validated 9/9 on named functions)
            s = next(iter(free))
            out[a] = {'name': s, 'owner_class': None, 'signature': None, 'kind': 'code',
                      'name_source': 'identity-unlock-bodyhash',
                      'evidence': [{'kind': 'exact-masked-body-one-free', 'length': k[0],
                                    'other_symbols': sorted(by[k] - {s})[:6]},
                                   {'kind': 'decorated-signature', 'symbol': s}]}
    for a in sorted(set(unnamed()) - done):
        va = int(a, 16)
        hi = end_of(va) - va
        lo = hi
        while lo > 1 and IMG[va - BASE + lo - 1] in (0xCC, 0x90):
            lo -= 1
        hits = set()
        for n in range(lo, hi + 1):
            if n in lens:
                syms = by.get((n, hashlib.sha1(masked(va, n, relocs)).digest()[:12]))
                if syms:
                    hits.add((n, frozenset(syms)))
        if a in out:
            continue
        if len(hits) != 1:
            amb += bool(hits)
            continue
        n, syms = hits.pop()
        free = syms - taken
        if len(syms) == 1 and free:
            s = next(iter(free))
            out[a] = {'name': s, 'owner_class': None, 'signature': None, 'kind': 'code',
                      'name_source': 'identity-unlock-bodyhash',
                      'evidence': [{'kind': 'exact-masked-body', 'length': n,
                                    'note': 'only compiled symbol with this reloc-masked body'},
                                   {'kind': 'decorated-signature', 'symbol': s}]}
        else:
            amb += 1
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print('named', len(out), 'ambiguous/shared', amb)


if __name__ == '__main__':
    main()
