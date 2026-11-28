"""python natbody_check.py: registry-misnamed converted bodies. A converted func_<A> took symbol S (rename), and the link
picked it over a NATIVE object's own S. When the native S, compiled alone, matches a DIFFERENT original address A'
(masked body equality, unique) and not A, the registry name of A is wrong: boost::mutex::do_lock (0x594ce0) was named
recursive_mutex::do_lock, so native GlobalSettingsItem::singleton locked without counting, unlocked with counting ->
the recursive mutex count went negative, never released -> Run deadlocked.
Builds [[addr, S, analog, owner]] from rename.json + the map and reads native objects from linkexp/qt.rsp; writes
auto/natbody_misnamed.json [[A, S, A', native object]]."""
import collections, hashlib, json, os, re, struct, sys
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[1]))
from roc.rebuild import coff_externals
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000


def sig(code, va=0):
    s = bytearray()
    for ins in md.disasm(code, va):
        raw = bytearray(ins.bytes)
        if raw[0] in (0xe8, 0xe9) and len(raw) == 5:
            raw[1:] = bytes(4)
        elif len(raw) >= 5:   # any dword operand (relocations / image addresses) masked
            for k in range(len(raw) - 3):
                v = struct.unpack_from('<I', raw, k)[0]
                if v > 0xffff or v == 0:
                    pass
            raw[-4:] = bytes(4) if ins.mnemonic in ('mov', 'push', 'call', 'jmp', 'cmp', 'lea', 'test', 'add', 'sub', 'or', 'and') and len(raw) >= 6 else raw[-4:]
        s += raw
        if ins.mnemonic in ('ret', 'int3'):
            break
    return hashlib.sha1(bytes(s)).hexdigest() if len(s) >= 8 else None


def obj_funcs(path, want):
    d = open(path, 'rb').read()
    _, nsec, _, sp, ns, opt, _ = struct.unpack_from('<HHIIIHH', d, 0)
    st = sp + ns * 18; out = {}; i = 0
    while i < ns:
        raw, val, sec, typ, cls, naux = struct.unpack_from('<8sIHHBB', d, sp + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            q = st + struct.unpack_from('<I', raw, 4)[0]; nm = d[q:d.index(b'\0', q)].decode('latin-1')
        else:
            nm = raw.rstrip(b'\0').decode('latin-1')
        if nm in want and 0 < sec <= nsec:
            sh = 20 + opt + 40 * (sec - 1)
            size, ptr = struct.unpack_from('<II', d, sh + 16)
            out[nm] = d[ptr + val:ptr + size]
        i += 1 + naux
    return out


import pickle
rr = json.loads((H / 'renamed/rename.json').read_text())
from shardcache import ShardCache
xc = ShardCache(H / 'link/obj_ext_cache.pkl')
nat = set()
for l in open(H / 'linkexp/qt.rsp', errors='replace'):
    p = l.strip().strip('"')
    if p.lower().endswith('.obj') and 'renamed' not in p and not re.search(r'[\/](?:ca_)?[0-9a-f]{8}\.obj$', p):
        v = xc.get(p)
        try:
            nat |= {n for n, d_ in (v[2] if v else coff_externals(open(p, 'rb').read())).items() if d_}
        except OSError:
            pass
owner = {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    q_ = l.split()
    if len(q_) >= 4 and ':' in q_[0]:
        owner.setdefault(q_[1], q_[-1])
won = [[a, x['symbol'], x.get('analog'), owner.get(x['symbol'])] for a, x in rr.items()
       if x.get('status') == 'renamed' and x.get('symbol') in nat and x.get('analog') != x['symbol']
       and re.fullmatch(r'(?:ca_)?[0-9a-f]{8}\.obj', owner.get(x['symbol']) or '')]
want = {w[1] for w in won}
ff = sorted(int(a, 16) for a in json.load(open(H.parents[0] / 'native-client/layout/function-files.json')))
osig = collections.defaultdict(list)
for i, a in enumerate(ff):
    if 0x401000 <= a < 0x7c0000:
        s = sig(bytes(o[a - B:a - B + min((ff[i + 1] if i + 1 < len(ff) else a + 0x200) - a, 0x1800)]), a)
        if s:
            osig[s].append(a)
natbody = {}
for l in open(H / 'linkexp/qt.rsp', errors='replace'):
    p = l.strip().strip('"')
    if p.lower().endswith('.obj') and 'renamed' not in p and not re.search(r'[\/](?:ca_)?[0-9a-f]{8}\.obj$', p):
        try:
            d = open(p, 'rb').read()
        except OSError:
            continue
        if not any(w.encode('latin-1') in d for w in want):
            continue
        for nm, code in obj_funcs(p, want).items():
            natbody.setdefault(nm, (p, code))
bad = []
for a, s, an, ow in won:
    if s not in natbody:
        continue
    ns_ = sig(natbody[s][1])
    c = osig.get(ns_, [])
    nlen = sum(len(i_.bytes) for i_ in md.disasm(natbody[s][1][:0x1800], 0) if True) if False else 0
    for i_ in md.disasm(natbody[s][1][:0x1800], 0):
        nlen += len(i_.bytes)
        if i_.mnemonic in ('ret', 'int3'):
            break
    if c and int(a, 16) not in c and len(c) <= 3 and nlen >= 24:   # pilot: distinctive bodies only
        bad.append([a, s, ','.join('%08x' % x for x in c[:4]), Path(natbody[s][0]).name])
(H / 'auto/natbody_misnamed.json').write_text(json.dumps(bad, indent=0))
# quicktest renames the converted DEFINITION S -> func_<A> (natbody_defrename.json): the native S wins, func_<A> keeps
# the converted body; callaudit retargets converted callers that meant A
_dr = H / 'auto/natbody_defrename.json'
prev = json.loads(_dr.read_text()) if _dr.exists() else {}
# curated: a candidate is promoted only after a pilot link proves it (the 6-entry batch crashed ContentProvider);
# NATBODY_PROMOTE=1 promotes all current candidates
if os.environ.get('NATBODY_PROMOTE'):
    for b in bad:
        prev.setdefault(b[0] + '.obj', {})[b[1]] = 'func_' + b[0]
    _dr.write_text(json.dumps(prev, indent=0))
print('natbody_check: foreign converted wins %d, native body present %d, native body matches ANOTHER original address: %d'
      % (len(won), sum(1 for w in won if w[1] in natbody), len(bad)))
for b in bad[:20]:
    print('  ', b[0], '->', b[2], b[1][:70])
