"""Route 17: WebService.pdb fingerprint match (RBXGS 0.3.676 shares the 2008 engine source).

Fingerprint of a function = (ordered direct callees, ordered pushed string literals), where a
callee counts by name only if the exe registry already names it (else '*', on both sides).
An exe function whose fingerprint is unique in the exe and unique among WebService.dll publics
(with >= 2 named callees, or >= 1 string literal and >= 1 named callee) takes that public's
name.  --validate measures the rule on already-named exe functions.
Measured: plain names with string literals 102 right / 1 wrong -> real tier; plain names with
call sequence only 320 / 19 -> inferred tier; template names 73-80% -> not used.
Outputs: identity-unlock-wsfp.json (real), identity-unlock-wsfp-inferred.json
"""
import gzip
import json
import re
import pickle
import sys
from collections import Counter, defaultdict
from pathlib import Path

import capstone
import pefile

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, CODE_STARTS, insns, refs, unnamed, dump_json  # noqa: E402

NC = ROOT / 'work/native-client'
DLL = ROOT / 'tools/rbxgs_msi/WebService.dll'
PUB = NC / 'identity-unlock-wspublics.json'


def cstr(img, base, va, lo, hi):
    if not lo <= va < hi:
        return None
    o = va - base
    end = img.find(b'\0', o, o + 200)
    s = img[o:end] if end > o else b''
    return s.decode('latin-1') if len(s) >= 3 and all(32 <= c < 127 for c in s) else None


def exe_fp(va, name, known):
    from identity_unlock_common import IMG, BASE
    calls, strs = [], []
    for i in insns(va):
        r = refs(i)
        if i.mnemonic == 'call' and i.op_str.startswith('0x'):
            n = name.get('%08x' % r[0])
            calls.append(n if n in known else '*')
        elif i.mnemonic == 'push' and r:
            s = cstr(IMG, BASE, r[0], 0x800000, 0x900000)
            if s:
                strs.append(s)
    return tuple(calls), tuple(strs)


def static_names():
    """WebService static functions (PDB module S_LPROC32, undecorated) -> decorated symbol when
    exactly one compiled-object symbol with that leaf undecorates to that qualified name."""
    p = NC / 'identity-unlock-wspublics-procs.json'
    if not p.exists():
        return {}
    from identity_unlock_common import undname_many
    pub = json.load(open(PUB))
    st = {a: v[0][0] for a, v in json.load(open(p)).items() if a not in pub and len(v) == 1}
    leaves = {re.sub(r'<.*', '', n).split('::')[-1] for n in st.values()}
    uni = set()
    for q in sorted(NC.glob('identity-unlock-objindex*.pkl.gz')):
        for r in pickle.load(gzip.open(q))['funcs']:
            uni.add(r[0])
            uni.update(r[2])
    pick = [x for x in uni if x.startswith('?') and not x.startswith('??') and x[1:x.find('@')] in leaves]
    U = undname_many(sorted(pick))
    byq = defaultdict(set)
    for x, sig in U.items():
        m = re.search(r'(?:__cdecl|__thiscall|__stdcall|__fastcall) ([^(]+)\(', sig)
        if m:
            byq[m.group(1)].add(x)
    out = {}
    for a, n in st.items():
        d = byq.get(n, set())
        out[a] = next(iter(d)) if len(d) == 1 else 'static:' + n
    return out


def ws_fps(known):
    pub = json.load(open(PUB))
    pub.update(static_names())
    pe = pefile.PE(str(DLL), fast_load=True)
    base, img = pe.OPTIONAL_HEADER.ImageBase, bytes(pe.get_memory_mapped_image())
    rd = next(s for s in pe.sections if s.Name.startswith(b'.rdata'))
    lo, hi = base + rd.VirtualAddress, base + rd.VirtualAddress + rd.Misc_VirtualSize
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    addrs = sorted(int(a, 16) for a in pub)
    out = {}
    for k, va in enumerate(addrs):
        end = min(addrs[k + 1] if k + 1 < len(addrs) else va + 0x400, va + 0x4000)
        calls, strs = [], []
        for i in md.disasm(img[va - base:end - base], va):
            if i.mnemonic == 'call' and i.op_str.startswith('0x'):
                n = pub.get('%08x' % int(i.op_str, 16))
                calls.append(n if n in known else '*')
            elif i.mnemonic == 'push' and i.op_str.startswith('0x'):
                s = cstr(img, base, int(i.op_str, 16), lo, hi)
                if s:
                    strs.append(s)
        out[pub['%08x' % va]] = (tuple(calls), tuple(strs))
    return out


def strong(fp):
    named = sum(1 for c in fp[0] if c != '*')
    return named >= 2 or (fp[1] and named >= 1)


def main(validate=False):
    real = json.load(open(NC / 'unnamed-identities.json'))
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    name.update({a: r['name'] for a, r in real.items() if r['name_source'] != 'identity-unlock-wsfp'})
    known = set(name.values())
    ws = ws_fps(known)
    ws_by = defaultdict(set)
    for s, fp in ws.items():
        if strong(fp):
            ws_by[fp].add(s)
    exe = {}
    for va in CODE_STARTS:
        a = '%08x' % va
        if 0x7e0000 <= va < 0x7fa000:
            continue
        exe[a] = exe_fp(va, name, known)
    exe_by = Counter(fp for fp in exe.values())
    targets = set(unnamed()) - set(real)
    st, out, inf = Counter(), {}, {}
    for a, fp in exe.items():
        if not strong(fp) or exe_by[fp] != 1 or len(ws_by.get(fp, ())) != 1:
            continue
        s = next(iter(ws_by[fp]))
        if validate:
            if a in name:
                tm = '?$' in s or s.startswith('??$')
                st[('right' if s == name[a] else 'wrong', 'tmpl' if tm else 'plain', 'str' if fp[1] else 'nostr')] += 1
            continue
        if a in targets and s not in known and '?$' not in s and not s.startswith('??$') and                 not (s.startswith('static:') and '<' in s):
            ev = [{'kind': 'webservice-pdb-fingerprint', 'pdb': 'WebService.pdb (RBXGS 0.3.676)',
                   'named_callees': [c for c in fp[0] if c != '*'][:8], 'strings': list(fp[1])[:6]}]
            row = {'name': s, 'signature': None, 'kind': 'code', 'name_source': 'identity-unlock-wsfp',
                   'owner_class': None, 'evidence': ev}
            if s.startswith('static:'):  # undecorated (no compiled object defines it yet)
                inf[a] = dict(row, name=s[7:], inferred=True, confidence='webservice-pdb-static',
                              alternatives=[])
            elif fp[1]:  # with string literals: 102 right / 1 wrong on named functions
                out[a] = row
            else:  # call sequence only: 320 / 19 -> inferred tier
                inf[a] = dict(row, inferred=True, confidence='webservice-pdb-fingerprint', alternatives=[])
    if validate:
        print(dict(st))
        return
    per = Counter(r['name'] for r in list(out.values()) + list(inf.values()))
    out = {a: r for a, r in out.items() if per[r['name']] == 1}
    inf = {a: r for a, r in inf.items() if per[r['name']] == 1}
    dump_json(out, NC / 'identity-unlock-wsfp.json')
    dump_json(inf, NC / 'identity-unlock-wsfp-inferred.json')
    print('wsfp real', len(out), 'inferred', len(inf))


if __name__ == '__main__':
    main('--validate' in sys.argv)
