"""Build the compiled-object index used by identity_unlock_align.py (read-only over *.obj).

One parallel pass over every *.obj under work/, out/ and rebuild/.  Kept rows:
  funcs:   (symbol, body length, direct-call symbols in order, sorted string/data symbols)
           for every emitted function whose symbol is NOT already a registry name
           (a candidate name for an unnamed address) or IS a registry name
           (anchor caller, its call sequence aligns with the original).
  vtables: (??_7 symbol, ((slot offset, symbol), ...)) for original vtables only.
Rows are deduplicated.  Output: work/native-client/identity-unlock-objindex.pkl.gz
Usage: identity_unlock_objindex.py [--workers N]
"""
import argparse
import gzip
import hashlib
import os
import pickle
import subprocess
import sys
from multiprocessing import Pool
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / 'work/native-client/identity-unlock-objindex.pkl.gz'
VTABLES = None


def init(vts):
    global VTABLES
    VTABLES = vts


def scan(job):
    k, paths, shard = job
    if shard.exists():
        with gzip.open(shard, 'rb') as fh:
            f, t = pickle.load(fh)
        return f, t, len(paths)
    from native_identity_closure import functions, vtables
    funcs, tabs, hashes = set(), set(), set()
    for p in paths:
        try:
            raw = open(p, 'rb').read()
        except OSError:
            continue
        h = hashlib.sha1(raw).digest()[:10]
        hashes.add(h)
        try:
            for symbol, body, relocs, refs in functions(raw):
                calls = tuple(n for at, n, k, _ in refs if k == 20 and at >= 1 and body[at - 1] == 0xE8)
                data = tuple(sorted({n for at, n, k, _ in refs if k == 6}))
                if calls or data:
                    funcs.add((symbol, len(body), calls, data))
            if b'??_7' in raw:
                for name, slots in vtables(raw):
                    if name in VTABLES:
                        tabs.add((name, slots))
        except Exception:
            continue
    tmp = shard.with_suffix('.tmp')
    with gzip.open(tmp, 'wb') as fh:
        pickle.dump((funcs, tabs), fh, protocol=4)
    os.replace(tmp, shard)
    return funcs, tabs, len(paths)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--workers', type=int, default=12)
    ap.add_argument('--exclude', action='append', default=[], help='path substring to skip')
    ap.add_argument('--only', action='append', default=[], help='keep only paths with this substring')
    ap.add_argument('--output', type=Path, default=OUT)
    args = ap.parse_args()
    import json
    reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
    vts = {v['name'] for v in reg.values() if v['kind'] == 'vtable'}
    files = subprocess.run(['rg', '--files', '-uu', '-g', '*.obj'] + [str(ROOT / d) for d in ('work', 'out', 'rebuild')],
                           capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout.splitlines()
    norm = [f.replace(chr(92), '/') for f in files]
    files = [f for f, n in zip(files, norm) if not any(x in n for x in args.exclude)
             and (not args.only or any(x in n for x in args.only))]
    files.sort()
    shards = args.output.with_name(args.output.name.replace('.pkl.gz', '-shards'))
    shards.mkdir(exist_ok=True)
    # resumable: one shard per 200-object chunk, reused on rerun (files are sorted)
    chunks = [(i, files[i:i + 200], shards / ('%07d.pkl.gz' % i)) for i in range(0, len(files), 200)]
    funcs, tabs, done = set(), set(), 0
    with Pool(args.workers, initializer=init, initargs=(vts,)) as pool:
        for f, t, n in pool.imap_unordered(scan, chunks, chunksize=1):
            funcs |= f
            tabs |= t
            done += n
            if done % 10000 < 200:
                print('objects', done, '/', len(files), 'funcs', len(funcs), 'vtables', len(tabs), flush=True)
    with gzip.open(args.output, 'wb') as fh:
        pickle.dump({'funcs': sorted(funcs), 'vtables': sorted(tabs), 'objects': len(files)}, fh, protocol=4)
    print('done funcs', len(funcs), 'vtables', len(tabs))


if __name__ == '__main__':
    main()
