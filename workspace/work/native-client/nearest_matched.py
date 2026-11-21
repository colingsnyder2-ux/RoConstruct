"""Nearest already-matched functions by instruction-shape similarity (no model).
  python work/native-client/nearest_matched.py ADDR [-k 3]     (builds the index on first use)
  python work/native-client/nearest_matched.py --build         (rebuild; ~minutes)
  python work/native-client/nearest_matched.py --validate 20   (hold-out check: same class/file in top-3)
Index: original bytes of each proved function (prove-out/OgreNativeFull/checks.json), 24..4096 bytes, skipping
Thunk_/TwinInst_/FunctorInst_/WF_ units and units that define local structs.  Signature = mnemonic + operand shape +
register class, relocations and address-like immediates masked; shingles = 4-grams of instructions (crc32 set);
similarity = Jaccard, candidates within 0.5x-2x size."""
import argparse
import json
import pickle
import random
import re
import sys
import time
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
IDX = HERE / 'nearest-index' / 'index.pkl'
CLIENT = '2008-06'
_cs = None


def sig(code, relocs=()):
    global _cs
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_OP_REG, CS_OP_IMM, CS_OP_MEM
    if _cs is None:
        _cs = Cs(CS_ARCH_X86, CS_MODE_32)
        _cs.detail = True
    z = bytearray(code)
    for r in relocs:
        z[r:r + 4] = b'\0\0\0\0'
    out = []
    for ins in _cs.disasm(bytes(z), 0):
        ops = []
        for o in ins.operands:
            if o.type == CS_OP_REG:
                n = ins.reg_name(o.reg)
                ops.append('r8' if len(n) == 2 and n[-1] in 'lh' else 'r16' if len(n) == 2 else
                           'x' if n.startswith(('xmm', 'st', 'mm')) else n if n in ('esp', 'ebp', 'eax', 'ecx') else 'r')
            elif o.type == CS_OP_IMM:
                v = o.imm & 0xffffffff
                ops.append('T' if ins.mnemonic[0] in 'jc' and ins.mnemonic != 'cmp' else 'A' if v >= 0x400000 else
                           str(v) if v < 32 else 'I')
            elif o.type == CS_OP_MEM:
                d = o.mem.disp & 0xffffffff
                ds = 'A' if 0x400000 <= d < 0xffff0000 else ('d%d' % (o.mem.disp if -64 < o.mem.disp < 64 else 0))
                ops.append('M[%s%s%s]' % ('b' if o.mem.base else '', 'i' if o.mem.index else '', ds))
        out.append(ins.mnemonic + ' ' + ','.join(ops))
    return out


def shingles(s, n=4):
    if len(s) < n:
        return frozenset([zlib.crc32('|'.join(s).encode())])
    return frozenset(zlib.crc32('|'.join(s[i:i + n]).encode()) for i in range(len(s) - n + 1))


_elig = {}


def eligible(src):
    name = Path(src).name
    if name.startswith(('Thunk_', 'TwinInst_', 'FunctorInst_', 'WF_')):
        return False
    if src not in _elig:
        try:
            t = Path(src).read_text(errors='replace')
        except OSError:
            t = ''
        _elig[src] = not re.search(r'^\s*(?:struct|class|union)\s+\w+[^;()]*\{', t, re.M)
    return _elig[src]


def build():
    from roc import match
    t0 = time.time()
    d = json.load(open(HERE / 'prove-out/OgreNativeFull/checks.json'))
    seen = {}
    for j in d['jobs']:
        for c in j['checks']:
            seen.setdefault(c['addr'], (j['source'], c['symbol']))
    idx, skipped = {}, 0
    for addr, (src, symbol) in seen.items():
        if not eligible(src):
            skipped += 1
            continue
        try:
            body, relocs, info = match.target(CLIENT, addr)
        except BaseException:
            skipped += 1
            continue
        if not 24 <= len(body) <= 4096:
            skipped += 1
            continue
        s = sig(body, relocs)
        idx[addr] = dict(sh=shingles(s), size=len(body), src=src, sym=symbol, n=len(s))
    IDX.parent.mkdir(exist_ok=True)
    pickle.dump(idx, open(IDX, 'wb'))
    print('indexed %d functions (%d skipped of %d) in %.0fs' % (len(idx), skipped, len(seen), time.time() - t0))
    return idx


def load():
    return pickle.load(open(IDX, 'rb')) if IDX.is_file() else build()


def query_sig(addr):
    from roc import match
    body, relocs, info = match.target(CLIENT, addr)
    return shingles(sig(body, relocs)), len(body)


def nearest(addr, k=3, idx=None):
    idx = idx or load()
    sh, size = (idx[addr]['sh'], idx[addr]['size']) if addr in idx else query_sig(addr)
    res = []
    for a, r in idx.items():
        if a == addr or not size / 2 <= r['size'] <= size * 2:
            continue
        inter = len(sh & r['sh'])
        if inter:
            res.append((inter / (len(sh) + len(r['sh']) - inter), a))
    res.sort(reverse=True)
    return [(s, a, idx[a]) for s, a in res[:k]]


def unqualified(symbol):
    """(unqualified name or None, class leaf) from a decorated MSVC symbol."""
    m = re.match(r'\?\??([0-9A-Z]?)([^@]*)@([^@]*)@', symbol)
    if not m:
        return None, None
    if symbol.startswith(('??0', '??1')):
        return ('~' if symbol[2] == '1' else '') + m.group(2), m.group(2)
    return (m.group(2) if not symbol.startswith('??') else None), m.group(3)


def function_text(src, symbol):
    try:
        t = Path(src).read_text(errors='replace')
    except OSError:
        return ''
    name, cls = unqualified(symbol)
    if name:
        pat = re.compile(r'^[^\n;{}]*\b%s\s*\(' % re.escape(name), re.M)
        for m in pat.finditer(t):
            i = t.find('{', m.end())
            semi = t.find(';', m.end())
            if i < 0 or (0 <= semi < i):
                continue
            depth, j = 0, i
            while j < len(t):
                depth += (t[j] == '{') - (t[j] == '}')
                j += 1
                if depth == 0:
                    break
            return t[m.start():j][:3000]
    return '\n'.join(t.splitlines()[:60])


def validate(n):
    idx = load()
    random.seed(1)
    ok = 0
    for a in random.sample(sorted(idx), n):
        top = nearest(a, 3, idx)
        cls = unqualified(idx[a]['sym'])[1]
        ok += any(idx[b]['src'] == idx[a]['src'] or (cls and unqualified(idx[b]['sym'])[1] == cls) for _, b, _ in top)
    print('hold-out: %d/%d (%.0f%%) top-3 contain same class or file' % (ok, n, 100.0 * ok / n))


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('addr', nargs='?')
    ap.add_argument('-k', type=int, default=3)
    ap.add_argument('--build', action='store_true')
    ap.add_argument('--validate', type=int)
    a = ap.parse_args()
    if a.build:
        build()
    elif a.validate:
        validate(a.validate)
    elif a.addr:
        for s, ad, r in nearest(a.addr.lower().zfill(8), a.k):
            print('=== %s sim=%.2f size=%d %s\n%s\n' % (ad, s, r['size'], r['src'], function_text(r['src'], r['sym'])))
    else:
        ap.print_help()
