"""python shard_libs.py [--dry-run | --build] [--shards 16] [--out-dir work/native-client/lib-shards]
Standalone .lib-packing tool for linkexp/qt.rsp (does NOT edit quicktest.py or linkexp/).
Partitions unchanging renamed/obj/*.obj inputs (excluding any with .CRT$XC* static initializers,
which must stay loose so link.exe does not drop unreferenced initializers) into N .lib shards
via VC2005 lib.exe /NOLOGO in parallel.

Proposed quicktest.py patch (for Claude to wire in):
  1. Call shard_libs.build_shards(rsp_objs, out_dir=..., shards=16) when renamed_obj set changes
     (hash-keyed manifest in out_dir/manifest.json skips rebuild when unchanged).
  2. Replace shardable renamed_obj paths in qt.rsp with the N shard .lib paths; keep all
     linkexp/*, native-check-runs/*, and .CRT$XC*-bearing .obj files loose before the shards.
  3. Expected speedup: cuts link.exe file opens from ~21,400 to ~5,300 (~75% fewer opens).
"""
import argparse, concurrent.futures, hashlib, json, struct, subprocess, sys
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
RSP_DEFAULT = H / 'linkexp/qt.rsp'
OUT_DEFAULT = ROOT / 'work/native-client/lib-shards'


def has_crt_init_section(obj_path: Path) -> bool:
    """Fast COFF section header scan: True if object has any .CRT$XC* section."""
    try:
        with obj_path.open('rb') as f:
            head = f.read(20)
            if len(head) < 20:
                return False
            _, nsec, _, _, _, opt_sz, _ = struct.unpack_from('<HHIIIHH', head, 0)
            f.seek(20 + opt_sz)
            secs = f.read(nsec * 40)
        for i in range(nsec):
            s = i * 40
            if s + 8 > len(secs):
                break
            name = secs[s:s + 8].split(b'\x00', 1)[0]
            if name.startswith(b'.CRT$XC'):
                return True
        return False
    except OSError:
        return True


def classify_rsp(rsp_path: Path):
    flags, shardable, loose, libs, xcu_kept = [], [], [], [], []
    for raw in rsp_path.read_text(errors='ignore').splitlines():
        s = raw.strip()
        if not s:
            continue
        p = s.strip('"')
        pl = p.lower()
        if pl.startswith('/') or pl.startswith('-'):
            flags.append(s)
        elif pl.endswith('.lib'):
            libs.append(p)
        elif '\\renamed\\obj\\' in pl and pl.endswith('.obj'):
            op = Path(p)
            if has_crt_init_section(op):
                xcu_kept.append(p)
                loose.append(p)
            else:
                shardable.append(p)
        else:
            loose.append(p)
    return {'flags': flags, 'shardable': shardable, 'loose': loose, 'libs': libs, 'xcu_kept': xcu_kept}


def find_lib_exe() -> Path:
    for cand in [
        ROOT / 'tools/msvc800sp1/VC/bin/lib.exe',
        ROOT / 'tools/vc2005/Program Files/Microsoft Visual Studio 8/VC/bin/lib.exe',
        ROOT / 'tools/vc2005/VC/bin/lib.exe',
    ]:
        if cand.exists():
            return cand
    raise FileNotFoundError('VC2005 lib.exe not found under tools/')


def build_shards(shardable, out_dir: Path, shards: int = 16):
    out_dir.mkdir(parents=True, exist_ok=True)
    digest = hashlib.sha256('\n'.join(sorted(shardable)).encode()).hexdigest()[:16]
    man_path = out_dir / 'manifest.json'
    if man_path.exists():
        old = json.loads(man_path.read_text())
        if old.get('digest') == digest and old.get('shards') == shards:
            if all(Path(p).exists() for p in old.get('libs', [])):
                return old['libs'], True
    lib_exe = find_lib_exe()
    buckets = [shardable[i::shards] for i in range(shards)]
    out_libs = []

    def _pack(idx_objs):
        idx, objs = idx_objs
        if not objs:
            return None
        rsp = out_dir / f'shard_{idx:02d}.rsp'
        lib = out_dir / f'shard_{idx:02d}.lib'
        rsp.write_text('/NOLOGO\n/OUT:"%s"\n' % lib + '\n'.join(f'"{o}"' for o in objs) + '\n')
        r = subprocess.run([str(lib_exe), f'@{rsp}'], capture_output=True, text=True)
        if r.returncode != 0:
            raise RuntimeError(f'lib.exe shard {idx} failed: {r.stderr or r.stdout}')
        return str(lib)

    with concurrent.futures.ThreadPoolExecutor(max_workers=min(8, shards)) as ex:
        for res in ex.map(_pack, enumerate(buckets)):
            if res:
                out_libs.append(res)
    man_path.write_text(json.dumps({'digest': digest, 'shards': shards, 'count': len(shardable), 'libs': out_libs}, indent=2))
    return out_libs, False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--rsp', type=Path, default=RSP_DEFAULT)
    ap.add_argument('--out-dir', type=Path, default=OUT_DEFAULT)
    ap.add_argument('--shards', type=int, default=16)
    ap.add_argument('--build', action='store_true', help='Actually pack .lib shards (default: dry-run)')
    args = ap.parse_args()

    c = classify_rsp(args.rsp)
    before = len(c['shardable']) + len(c['loose']) + len(c['libs'])
    after = args.shards + len(c['loose']) + len(c['libs'])
    print(f"shard_libs: rsp={args.rsp.name} flags={len(c['flags'])} shardable={len(c['shardable'])} "
          f"xcu_kept_loose={len(c['xcu_kept'])} loose_total={len(c['loose'])} libs={len(c['libs'])}")
    print(f"shard_libs: link.exe file opens {before} -> {after} ({100.0*(before-after)/max(before,1):.1f}% reduction with {args.shards} shards)")
    if args.build:
        out_libs, cached = build_shards(c['shardable'], args.out_dir, args.shards)
        print(f"shard_libs: {'cached' if cached else 'built'} {len(out_libs)} libs in {args.out_dir}")


if __name__ == '__main__':
    main()
