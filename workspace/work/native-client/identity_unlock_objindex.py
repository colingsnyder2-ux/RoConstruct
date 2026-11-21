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
BODIES = False


def init(vts, bodies=False):
    global VTABLES, BODIES
    VTABLES, BODIES = vts, bodies


def scan(job):
    k, paths, shard = job
    if shard.exists():
        with gzip.open(shard, 'rb') as fh:
            f, t = pickle.load(fh)
        return f, t, len(paths)
    from native_identity_closure import functions, vtables
    funcs, tabs, hashes = set(), set(), set()
    for p in paths:
        # delinked slices of the original exe carry only registry names and parse very slowly
        if p.replace(chr(92), '/').endswith('/orig.obj') and '/delink-' in p.replace(chr(92), '/'):
            continue
        if '/CMakeFiles/' in p.replace(chr(92), '/'):  # compiler toolchain builds (clang/LLVM), not client code
            continue
        try:
            raw = open(p, 'rb').read()
        except OSError:
            continue
        h = hashlib.sha1(raw).digest()[:10]
        hashes.add(h)
        try:
            for symbol, body, relocs, refs in functions(raw):
                if BODIES:  # reloc-masked body hash (Function-ID style exact match)
                    b = bytearray(body)
                    for at in relocs:
                        b[at:at + 4] = b'\0\0\0\0'
                    funcs.add((len(body), hashlib.sha1(b).digest()[:12], symbol))
                    continue
                calls = tuple(n for at, n, k, _ in refs if k == 20 and at >= 1 and body[at - 1] == 0xE8)
                data = tuple(sorted({n for at, n, k, _ in refs if k == 6}))
                if calls or data:
                    funcs.add((symbol, len(body), calls, data))
            if b'??_7' in raw and not BODIES:
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


def digest(path):
    try:
        with open(path, 'rb') as fh:
            return path, hashlib.sha1(fh.read()).digest()
    except OSError:
        return path, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--workers', type=int, default=12)
    ap.add_argument('--exclude', action='append', default=[], help='path substring to skip')
    ap.add_argument('--only', action='append', default=[], help='keep only paths with this substring')
    ap.add_argument('--output', type=Path, default=OUT)
    ap.add_argument('--bodies', action='store_true', help='store (length, masked-body hash, symbol) rows instead')
    ap.add_argument('--newer-than', type=Path, help='only objects modified after this file (incremental delta index)')
    args = ap.parse_args()
    import json
    reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
    vts = {v['name'] for v in reg.values() if v['kind'] == 'vtable'}
    files = subprocess.run(['rg', '--files', '-uu', '-g', '*.obj'] + [str(ROOT / d) for d in ('work', 'out', 'rebuild')],
                           capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout.splitlines()
    norm = [f.replace(chr(92), '/') for f in files]
    files = [f for f, n in zip(files, norm) if not any(x in n for x in args.exclude)
             and (not args.only or any(x in n for x in args.only))]
    if args.newer_than:
        cut = args.newer_than.stat().st_mtime
        files = [f for f in files if os.path.exists(f) and os.path.getmtime(f) > cut]
        print('newer objects', len(files), flush=True)
    files.sort()
    shards = args.output.with_name(args.output.name.replace('.pkl.gz', '-shards'))
    shards.mkdir(exist_ok=True)
    # resumable: one shard per 200-object chunk, reused on rerun (files are sorted)
    chunks = [(i, files[i:i + 200], shards / ('%07d.pkl.gz' % i)) for i in range(0, len(files), 200)]
    # objects added/removed since an earlier run shift chunk boundaries; an unfinished chunk
    # after a finished one also takes the 600 files before it (rows are a set, overlap is harmless)
    chunks = [(i, files[max(0, i - 600):i + 200] if i and (shards / ('%07d.pkl.gz' % (i - 200))).exists()
               and not p.exists() else ps, p) for i, ps, p in chunks]
    funcs, tabs, done = set(), set(), 0
    with Pool(args.workers, initializer=init, initargs=(vts, args.bodies)) as pool:
        # unfinished chunks: byte-identical objects are parsed once (first occurrence wins)
        todo = [c for c in chunks if not c[2].exists()]
        seen, keep = set(), set()
        for path, h in pool.imap(digest, [f for c in todo for f in c[1]], chunksize=64):
            if h is not None and h not in seen:
                seen.add(h)
                keep.add(path)
        print('unfinished objects', sum(len(c[1]) for c in todo), 'unique', len(keep), flush=True)
        chunks = [c if c[2].exists() else (c[0], [f for f in c[1] if f in keep], c[2]) for c in chunks]
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
