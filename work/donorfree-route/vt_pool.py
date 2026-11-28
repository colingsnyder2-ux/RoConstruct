"""python vt_pool.py JOBS.json [N]: the per-object write phase of vt_strip.py on N processes (it ran single-core: 10+
minutes when every object changed). Each job: full (pre-strip object), out (linked copy), drop (names to make
undefined), ren ({old: new}), main (symbol to make external). Writes JOBS.result.json {out: [md5, renamed, externalized]}."""
import hashlib, json, os, struct, sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[1]))


def _strtab_name(data, raw, strtab):
    return bytes(data[strtab + struct.unpack_from('<I', raw, 4)[0]:]).split(b'\0', 1)[0] if raw[:4] == b'\0\0\0\0' else raw.rstrip(b'\0')


def _rename(data, ren):
    """rename external symbols by name (new strings appended to the string table) - same as vt_strip._rename"""
    data = bytearray(data)
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    size = struct.unpack_from('<I', data, strtab)[0]
    extra = bytearray()
    i = 0
    while i < nsym:
        at = symptr + 18 * i
        raw = bytes(data[at:at + 8])
        naux = data[at + 17]
        nm = _strtab_name(data, raw, strtab).decode('latin-1')
        if nm in ren:
            struct.pack_into('<II', data, at, 0, size + len(extra))
            extra += ren[nm].encode('latin-1') + b'\0'
        i += 1 + naux
    data = data[:strtab + size] + extra
    struct.pack_into('<I', data, strtab, size + len(extra))
    return bytes(data)


def _externalize(data, name):
    """STATIC (3) -> EXTERNAL (2) for the named function symbol. The symbol table is scanned as fixed 18-byte records in C
    (struct.iter_unpack); names are matched by string-table offset (long names) or the inline 8 bytes (short)."""
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    nb = name.encode('latin-1')
    if len(nb) > 8:
        k = data.find(b'\0' + nb + b'\0', strtab + 3)
        if k < 0:
            return data, 0
        key = (0, k + 1 - strtab)
    else:
        key = None
    data = bytearray(data)
    hit, skip = 0, 0
    for i, (z, off, val, sec, typ, cls, naux) in enumerate(struct.iter_unpack('<IIIhHBB', bytes(data[symptr:strtab]))):
        if skip:
            skip -= 1; continue
        skip = naux
        if cls == 3 and sec > 0 and val == 0 and typ == 0x20:
            if (key is not None and (z, off) == key) or (key is None and bytes(data[symptr + 18 * i:symptr + 18 * i + 8]).rstrip(b'\0') == nb):
                data[symptr + 18 * i + 16] = 2; hit += 1
    return bytes(data), hit


def work(job):
    from roc import rebuild
    data = Path(job['full']).read_bytes()
    out = bytes(rebuild.strip_symbols(data, drop=set(job['drop']))) if job['drop'] else data
    if job['ren']:
        out = _rename(out, job['ren'])
    hit = 0
    if job.get('main'):
        out, hit = _externalize(out, job['ren'].get(job['main'], job['main']))
    o = Path(job['out'])
    if not o.exists() or o.read_bytes() != out:
        o.write_bytes(out)
    return job['out'], hashlib.md5(out).hexdigest(), bool(job['ren']), hit


if __name__ == '__main__':
    jobs = json.load(open(sys.argv[1]))
    n = int(sys.argv[2]) if len(sys.argv) > 2 else max(2, (os.cpu_count() or 4) - 2)
    with ProcessPoolExecutor(max_workers=n) as ex:
        res = list(ex.map(work, jobs, chunksize=max(1, len(jobs) // (n * 8) or 1)))
    Path(sys.argv[1] + '.result.json').write_text(json.dumps({r[0]: list(r[1:]) for r in res}))
    print('vt_pool: %d objects on %d processes' % (len(jobs), n))
