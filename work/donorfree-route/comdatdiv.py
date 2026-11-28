"""python comdatdiv.py [RSP] [--jobs 8] [--top 60]: COMDAT divergence audit (static, no link).
Every COMDAT (inline function, template, vtable, string literal...) defined by more than one object in the link
response file (default linkexp/qt.final.rsp) is compared across its copies: section bytes with relocation fields
masked, plus the relocation target names. lld keeps the FIRST copy in input order, so a divergent copy can win
silently when link order changes (the AtlThrowImpl bug: plain-ATL RaiseException copy vs MFC throw copy).
Classes: 'targets' = the copies call/reference different symbols (strong: different code paths), 'size' = same
targets, different length, 'bytes' = same targets and length, different bytes (usually optimisation noise).
Per-object results are cached by (mtime, size) in auto/comdatdiv_cache.pkl. Writes auto/comdatdiv.json."""
import collections, hashlib, re, json, mmap, os, pickle, struct, sys
from multiprocessing import Pool
from pathlib import Path
H = Path(__file__).parent
RELOC_MASK = {0x6: 4, 0x7: 4, 0x14: 4, 0xB: 4, 0xA: 2}   # i386 DIR32, DIR32NB, REL32, SECREL, SECTION


def parse(path):
    """[(comdat_symbol, sig_hex, size, targets_tuple)] for one COFF object."""
    out = []
    with open(path, 'rb') as f:
        m = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
    try:
        sig1, sig2 = struct.unpack_from('<HH', m, 0)
        if sig1 == 0 and sig2 == 0xFFFF:   # /bigobj
            nsec, psym, nsym = struct.unpack_from('<III', m, 44); shdr = 56; ssz = 20; secfmt = '<i'
        else:
            nsec, _, psym, nsym = struct.unpack_from('<HIII', m, 2)
            opt = struct.unpack_from('<H', m, 16)[0]; shdr = 20 + opt; ssz = 18; secfmt = '<h'
        strtab = psym + nsym * ssz
        secs = [struct.unpack_from('<8sIIIIIIHHI', m, shdr + 40 * i) for i in range(nsec)]

        def sname(i):
            o = psym + i * ssz
            if m[o:o + 4] == b'\0\0\0\0':
                off = struct.unpack_from('<I', m, o + 4)[0] + strtab
                return m[off:m.find(b'\0', off)].decode('latin1')
            return m[o:o + 8].rstrip(b'\0').decode('latin1')
        syms = {}   # index -> (name, secnum, storage class)
        sel = {}    # comdat section number -> selection
        key = {}    # comdat section number -> first external symbol
        i = 0
        while i < nsym:
            o = psym + i * ssz
            sec = struct.unpack_from(secfmt, m, o + 12)[0]
            val = struct.unpack_from('<I', m, o + 8)[0]
            cls, naux = m[o + ssz - 2], m[o + ssz - 1]
            nm = sname(i)
            syms[i] = (nm, sec, cls)
            if 0 < sec <= nsec and secs[sec - 1][9] & 0x1000:
                if cls == 3 and naux and val == 0 and sec not in sel:
                    sel[sec] = m[psym + (i + 1) * ssz + 14]
                elif cls == 2 and sec not in key:
                    key[sec] = nm
            i += 1 + naux
        for sec, nm in key.items():
            if sel.get(sec) == 5:   # associative: follows its parent
                continue
            _, _, _, size, praw, prel, _, nrel, _, ch = secs[sec - 1]
            data = bytearray(m[praw:praw + size]) if praw and not ch & 0x80 else bytearray(size)
            tg = []
            for r in range(nrel):
                va, si, ty = struct.unpack_from('<IIH', m, prel + 10 * r)
                n = RELOC_MASK.get(ty, 4)
                data[va:va + n] = b'\0' * n
                tn, ts, tc = syms.get(si, ('?', 0, 0))
                tg.append('<static>' if tc == 3 else tn)
            h = hashlib.blake2b(bytes(data), digest_size=8)
            h.update('\0'.join(tg).encode('latin1'))
            out.append((nm, h.hexdigest(), size, tuple(sorted(set(tg)))))
    finally:
        m.close()
    return out


def work(p):
    try:
        st = os.stat(p)
        return p, (st.st_mtime, st.st_size), parse(p)
    except Exception as e:
        return p, None, repr(e)


if __name__ == '__main__':
    args = sys.argv[1:]
    rsp = next((a for a in args if a.endswith('.rsp')), str(H / 'linkexp/qt.final.rsp'))
    jobs = int(args[args.index('--jobs') + 1]) if '--jobs' in args else 8
    top = int(args[args.index('--top') + 1]) if '--top' in args else 60
    objs = [l.strip().strip('"') for l in open(rsp) if l.strip().strip('"').lower().endswith('.obj')]
    cf = H / 'auto/comdatdiv_cache.pkl'
    cache = pickle.load(open(cf, 'rb')) if cf.exists() else {}
    todo = []
    for p in objs:
        try:
            st = os.stat(p)
        except OSError:
            continue
        c = cache.get(p)
        if not c or c[0] != (st.st_mtime, st.st_size):
            todo.append(p)
    errs = []
    if todo:
        with Pool(jobs) as pool:
            for n, (p, stamp, res) in enumerate(pool.imap_unordered(work, todo, chunksize=40)):
                if stamp is None:
                    errs.append((p, res))
                else:
                    cache[p] = (stamp, res)
                if n % 2000 == 0:
                    print('  parsed %d/%d' % (n, len(todo)), flush=True)
        pickle.dump(cache, open(cf, 'wb'), protocol=pickle.HIGHEST_PROTOCOL)
    by = collections.defaultdict(list)   # symbol -> [(order, sig, size, targets)]
    for idx, p in enumerate(objs):
        for nm, sig, size, tg in (cache.get(p) or (None, []))[1]:
            by[nm].append((idx, sig, size, tg))
    rows = []
    for nm, cp in by.items():
        sigs = {c[1] for c in cp}
        if len(sigs) < 2:
            continue
        cp.sort()
        win = cp[0]
        norm = lambda t: tuple(sorted({re.sub(r'_roc[0-9a-f]{6,8}$', '', x) for x in t}))
        tsets = {norm(c[3]) for c in cp}
        kind = lambda p: 'converted' if os.path.normpath(p).lower().endswith(os.path.join('renamed', 'obj', os.path.basename(p)).lower()) else 'draft'
        conv_sigs = {c[1] for c in cp if kind(objs[c[0]]) == 'converted'}
        cls = 'targets' if len(tsets) > 1 else ('size' if len({c[2] for c in cp}) > 1 else 'bytes')
        n_win = sum(1 for c in cp if c[1] == win[1])
        row = {'sym': nm, 'class': cls, 'copies': len(cp), 'variants': len(sigs), 'winner': objs[win[0]],
               'data': nm.startswith(('??_R', '??_7', '??_C', '??_8', '??_9')), 'winner_kind': kind(objs[win[0]]),
               'draft_beats_converted': kind(objs[win[0]]) == 'draft' and bool(conv_sigs) and win[1] not in conv_sigs,
               'winner_share': '%d/%d' % (n_win, len(cp)), 'winner_minority': n_win * 2 < len(cp)}
        if cls == 'targets':
            cp = [(c[0], c[1], c[2], norm(c[3])) for c in cp]; win = cp[0]
            allt = collections.Counter(t for c in cp for t in set(c[3]))
            row['winner_only'] = sorted(t for t in win[3] if allt[t] < len(cp) and allt[t] == sum(1 for c in cp if t in c[3] and c[3] == win[3]))[:8]
            row['missing_in_winner'] = sorted(t for t in allt if t not in win[3])[:8]
            other = next((c for c in cp if c[3] != win[3] and kind(objs[c[0]]) == 'converted'), None) or next(c for c in cp if c[3] != win[3])
            row['other_example'] = objs[other[0]]
        rows.append(row)
    order = {'targets': 0, 'size': 1, 'bytes': 2}
    rows.sort(key=lambda r: (r['data'], order[r['class']], not r['draft_beats_converted'], not r['winner_minority'], -r['variants'], r['sym']))
    (H / 'auto/comdatdiv.json').write_text(json.dumps({'objects': len(objs), 'comdat_symbols': len(by), 'errors': errs[:50], 'rows': rows}, indent=0))
    cnt = collections.Counter(r['class'] for r in rows)
    print('comdatdiv: objects %d, comdat symbols %d, divergent %d (targets %d, size %d, bytes %d), data %d, winner-is-minority %d, '
          'DRAFT BEATS EXACT CONVERTED %d (code+targets %d), parse errors %d'
          % (len(objs), len(by), len(rows), cnt['targets'], cnt['size'], cnt['bytes'], sum(r['data'] for r in rows), sum(r['winner_minority'] for r in rows),
             sum(r['draft_beats_converted'] for r in rows), sum(r['draft_beats_converted'] and r['class'] == 'targets' and not r['data'] for r in rows), len(errs)))
    for r in [r for r in rows if r['class'] == 'targets' and not r['data']][:top]:
        print('  %-60s %s win %s %s | winner lacks %s' % (r['sym'][:60], r['winner_share'], Path(r['winner']).parent.name + '/' + Path(r['winner']).name,
                                                       ('DRAFT>EXACT ' if r['draft_beats_converted'] else '') + ('MINORITY' if r['winner_minority'] else ''), ','.join(x[:30] for x in r['missing_in_winner'][:3])))
