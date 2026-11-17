"""Route 18: iterative call-graph matching of Roblox.exe against WebService.dll + WebService.pdb.

Nodes: exe functions and WebService functions (PDB publics, plus statics from module streams).
Seed pairs: exe registry name == WebService public name (both unique).  Each round, a node's
fingerprint is (ordered callees as pair ids or '*', ordered string literals, ordered callers'
pair ids as a sorted tuple); an unmatched exe node whose fingerprint is unique among unmatched
exe nodes and among unmatched WebService nodes, and carries >= 2 paired callees/callers or a
string literal plus one pair, is paired.  Repeats until no new pairs.
  --validate  hide a deterministic 20% of named exe functions, match, report right/wrong by tier
Measured (20% holdout): ~65% right overall, 88% for string-backed plain names, so every
match goes to the inferred tier and only replaces placeholder rows there.
Outputs: identity-unlock-wsgraph.json, identity-unlock-wsgraph-inferred.json
"""
import json
import re
import sys
import zlib
from collections import Counter, defaultdict
from pathlib import Path

import capstone
import pefile

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, CODE_STARTS, IMG, BASE, insns, refs, unnamed, dump_json  # noqa: E402

NC = ROOT / 'work/native-client'
DLL = ROOT / 'tools/rbxgs_msi/WebService.dll'


def cstr(img, base, va, lo, hi):
    if not lo <= va < hi:
        return None
    o = va - base
    end = img.find(b'\0', o, o + 200)
    s = img[o:end] if end > o else b''
    return s.decode('latin-1') if len(s) >= 3 and all(32 <= c < 127 for c in s) else None


def exe_graph():
    calls, strs = {}, {}
    code = set(CODE_STARTS)
    for va in CODE_STARTS:
        c, s = [], []
        for i in insns(va):
            r = refs(i)
            if i.mnemonic == 'call' and i.op_str.startswith('0x') and r[0] in code:
                c.append(r[0])
            elif i.mnemonic == 'push' and r:
                x = cstr(IMG, BASE, r[0], 0x800000, 0x900000)
                if x:
                    s.append(x)
        calls[va], strs[va] = c, tuple(s)
    return calls, strs


def ws_graph():
    pub = json.load(open(NC / 'identity-unlock-wspublics.json'))
    procs = json.load(open(NC / 'identity-unlock-wspublics-procs.json'))
    names = {int(a, 16): n for a, n in pub.items()}
    size = {}
    for a, v in procs.items():
        size[int(a, 16)] = max(x[1] for x in v)
        if int(a, 16) not in names and len(v) == 1:
            names[int(a, 16)] = 'static:' + v[0][0]
    pe = pefile.PE(str(DLL), fast_load=True)
    base, img = pe.OPTIONAL_HEADER.ImageBase, bytes(pe.get_memory_mapped_image())
    rd = next(s for s in pe.sections if s.Name.startswith(b'.rdata'))
    lo, hi = base + rd.VirtualAddress, base + rd.VirtualAddress + rd.Misc_VirtualSize
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    addrs = sorted(names)
    calls, strs = {}, {}
    for k, va in enumerate(addrs):
        end = va + size[va] if va in size else min(addrs[k + 1] if k + 1 < len(addrs) else va + 0x400, va + 0x4000)
        c, s = [], []
        for i in md.disasm(img[va - base:end - base], va):
            if i.mnemonic == 'call' and i.op_str.startswith('0x'):
                t = int(i.op_str, 16)
                if t in names:
                    c.append(t)
            elif i.mnemonic == 'push' and i.op_str.startswith('0x'):
                x = cstr(img, base, int(i.op_str, 16), lo, hi)
                if x:
                    s.append(x)
        calls[va], strs[va] = c, tuple(s)
    return names, calls, strs


def match(ecalls, estrs, enames, wnames, wcalls, wstrs, esize, wsize):
    """enames: exe va -> name (seeds).  Returns exe va -> (ws va, used string literal)."""
    wby = defaultdict(list)
    for va, n in wnames.items():
        wby[n].append(va)
    eby = defaultdict(list)
    for va, n in enames.items():
        eby[n].append(va)
    pair, rpair = {}, {}
    for n, ev in eby.items():
        if len(ev) == 1 and len(wby.get(n, ())) == 1:
            pair[ev[0]], rpair[wby[n][0]] = wby[n][0], ev[0]
    seeds = set(pair)
    ecallers, wcallers = defaultdict(list), defaultdict(list)
    for va, c in ecalls.items():
        for t in c:
            ecallers[t].append(va)
    for va, c in wcalls.items():
        for t in c:
            wcallers[t].append(va)
    how = {}
    while True:
        def fps(nodes, calls, callers, strs, pid):
            out = {}
            for va in nodes:
                cs = tuple(pid(t) for t in calls[va])
                cr = tuple(sorted(x for x in (pid(t) for t in callers.get(va, ())) if x != '*'))
                n = sum(1 for x in cs if x != '*') + len(cr)
                if n >= 3 or (strs[va] and n >= 2):
                    out[va] = (cs, cr, strs[va])
            return out
        efp = fps([v for v in ecalls if v not in pair], ecalls, ecallers, estrs,
                  lambda t: pair.get(t, '*'))
        wfp = fps([v for v in wcalls if v not in rpair], wcalls, wcallers, wstrs,
                  lambda t: t if t in rpair else '*')
        ecount, wmap = Counter(efp.values()), defaultdict(list)
        for va, f in wfp.items():
            wmap[f].append(va)
        new = 0
        for va, f in efp.items():
            if ecount[f] == 1 and len(wmap.get(f, ())) == 1:
                w = wmap[f][0]
                r = esize[va] / max(1, wsize.get(w, esize[va]))
                if not 0.6 <= r <= 1.6:
                    continue
                pair[va], rpair[w] = w, va
                how[va] = bool(f[2])
                new += 1
        if not new:
            break
    return {va: (pair[va], how[va]) for va in pair if va not in seeds}


def tier(n, used_str):
    # measured on hidden named functions: string-backed plain names 22 right / 3 wrong, others
    # ~65%: never real tier; inferred tier only replaces placeholders (identity_unlock_inferred)
    return 'inferred'


def main(validate=False):
    real = json.load(open(NC / 'unnamed-identities.json'))
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    name.update({a: r['name'] for a, r in real.items() if r['name_source'] != 'identity-unlock-wsgraph'})
    ecalls, estrs = exe_graph()
    wnames, wcalls, wstrs = ws_graph()
    from identity_unlock_common import end_of
    esize = {va: end_of(va) - va for va in ecalls}
    wsize = {int(a, 16): max(x[1] for x in v) for a, v in json.load(open(NC / 'identity-unlock-wspublics-procs.json')).items()}
    enames = {int(a, 16): n for a, n in name.items() if int(a, 16) in ecalls}
    if validate:
        hidden = {va for va in enames if zlib.crc32(b'%x' % va) % 5 == 0}
        got = match(ecalls, estrs, {v: n for v, n in enames.items() if v not in hidden}, wnames, wcalls, wstrs, esize, wsize)
        st = Counter()
        for va, (w, s) in got.items():
            if va in hidden:
                n = wnames[w]
                st[(tier(n, s), 'tmpl' if ('?$' in n or n.startswith('??$')) else 'plain',
                    'right' if n == enames[va] else 'wrong')] += 1
        print(dict(st))
        return
    got = match(ecalls, estrs, enames, wnames, wcalls, wstrs, esize, wsize)
    targets = set(unnamed()) - set(real)
    taken = set(name.values())
    out, inf = {}, {}
    for va, (w, s) in got.items():
        a, n = '%08x' % va, wnames[w]
        if a not in targets or n in taken:
            continue
        ev = [{'kind': 'webservice-pdb-graph-match', 'pdb': 'WebService.pdb (RBXGS 0.3.676)',
               'webservice_va': '%08x' % w, 'string_literal': s}]
        if tier(n, s) == 'real':
            out[a] = {'name': n, 'owner_class': None, 'signature': None, 'kind': 'code',
                      'name_source': 'identity-unlock-wsgraph', 'evidence': ev}
        else:
            inf[a] = {'name': n[7:] if n.startswith('static:') else n, 'signature': None, 'kind': 'code',
                      'inferred': True, 'confidence': 'webservice-pdb-graph-match',
                      'name_source': 'identity-unlock-wsgraph', 'alternatives': [], 'evidence': ev}
    dump_json(out, NC / 'identity-unlock-wsgraph.json')
    dump_json(inf, NC / 'identity-unlock-wsgraph-inferred.json')
    print('wsgraph matched', len(got), 'real', len(out), 'inferred', len(inf))


if __name__ == '__main__':
    main('--validate' in sys.argv)
