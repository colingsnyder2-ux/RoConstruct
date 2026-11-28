"""python shard_libs.py [--rsp linkexp/qt.final.rsp] [--build | --dry-run] [--avg 256] [--out-dir DIR]
(old flags: --dry-run is the default; --shards N is accepted and ignored, the old default --out-dir
work/native-client/lib-shards is now linkexp/shards; the old default --rsp was linkexp/qt.rsp)
       python shard_libs.py --compare-exe A.exe B.exe   |   --compare-map A.map B.map
OPT-IN .lib packing of the converted objects (renamed/obj/*.obj) for the lld link: lld_link.py uses it when
QT_SHARD_LIBS=1 (quicktest.py passes its environment on). Default links never touch it. See LINK_SPEED.md.

Why the old plan (shards as ordinary .lib inputs after the loose objects) was NOT equivalent:
  * an archive member is loaded only when it resolves a symbol that is still undefined when lld reaches it. Under
    /FORCE:MULTIPLE the FIRST loaded definition wins, and quicktest.py puts the converted objects first on purpose
    (first_wins.json, "exact definitions win"). As lazy members they would lose to every native object that defines
    the same name, and COMDAT 'any' picks would change;
  * members nothing references are never loaded: their bodies leave the image (layout and map change, the map-based
    audits lose their func_ names), and their .drectve /alternatename, /INCLUDE, /DEFAULTLIB directives vanish;
  * .CRT$XC* was only one kind of side-effect-only content (.CRT$XI/XP/XT/XL, .tls, directives are others);
  * the old manifest hashed object NAMES only (a reconverted object kept a stale shard) and the round-robin buckets
    reordered the objects.
What this version does instead (every member loads, at the same place, in the same order):
  * each contiguous run of converted objects in the final response file becomes consecutive shards, members in their
    original order, passed as "/WHOLEARCHIVE:<shard>" at the run's position. lld-link handles /WHOLEARCHIVE:file
    positionally (one input loop over INPUT and wholearchive_file args) and loads every member in archive order, so
    the load order -- and with it every /FORCE:MULTIPLE first-definition and COMDAT choice -- is unchanged;
  * objects with any .CRT$* or .tls section stay loose anyway (belt and braces);
  * shard names are a hash of (path, mtime_ns, size) of every member: a changed object rebuilds only its own shard.
    Chunk boundaries are content-defined (crc32 of the member name), so one object entering or leaving a run changes
    one shard, not every shard after it;
  * lld's map names a member's owner "<lib>:<member>"; unshard_map_text() rewrites shard owners back to the member
    name so quicktest's map heuristics (':' in owner = library) see what a loose link shows.
  * the response file the other tools read (qt.final.rsp) keeps the loose object list; lld runs on a separate
    <rsp>.sharded.rsp.
Still to verify on the Windows machine (LINK_SPEED.md): exe and map identical (--compare-exe / --compare-map against a
QT_SHARD_LIBS=0 link of the same inputs), and that it is actually faster (lldprof.py --shards)."""
import argparse, concurrent.futures, hashlib, json, os, re, struct, subprocess, sys, zlib
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
RSP_DEFAULT = H / 'linkexp/qt.final.rsp'
PREFIX = 'qtshard_'
MIN_CHUNK = 8        # shorter runs stay loose: a shard of 1-7 objects saves nothing
LLVM_LIB = r'C:\Program Files\LLVM\bin\llvm-lib.exe'


def is_shardable_path(p: str) -> bool:
    q = p.replace('/', '\\').lower()
    return '\\renamed\\obj\\' in q and q.endswith('.obj')


def has_side_effect_section(obj_path) -> bool:
    """True if the COFF object has a .CRT$* (initializers/terminators/TLS callbacks) or .tls* section, or cannot be
    read: such objects stay loose."""
    try:
        with open(obj_path, 'rb') as f:
            head = f.read(20)
            if len(head) < 20:
                return True
            _, nsec, _, _, _, opt_sz, _ = struct.unpack_from('<HHIIIHH', head, 0)
            f.seek(20 + opt_sz)
            secs = f.read(nsec * 40)
        for i in range(nsec):
            s = i * 40
            if s + 8 > len(secs):
                return True
            name = secs[s:s + 8].split(b'\x00', 1)[0]
            if name.startswith((b'.CRT$', b'.tls')):
                return True
        return False
    except OSError:
        return True


has_crt_init_section = has_side_effect_section   # old name


def _stamp(p):
    st = os.stat(p)
    return (st.st_mtime_ns, st.st_size)


def _boundary(path: str, avg: int) -> bool:
    name = re.split(r'[\\/]', path)[-1].lower()
    return zlib.crc32(name.encode('utf-8', 'replace')) % avg == avg - 1


def plan(lines, avg=256, max_chunk=2048, stamp=_stamp, side_effect=has_side_effect_section, min_chunk=MIN_CHUNK):
    """lines of a response file -> list of ('line', text) / ('shard', [(path, stamp), ...]) in the original order.
    Only contiguous runs of shardable objects are grouped; every other line keeps its place."""
    out, run = [], []

    def flush():
        chunks, chunk = [], []
        for m in run:
            chunk.append(m)
            if len(chunk) >= max_chunk or _boundary(m[0], avg):
                chunks.append(chunk); chunk = []
        if chunk:
            chunks.append(chunk)
        for c in chunks:
            if len(c) < min_chunk:
                out.extend(('line', m[2]) for m in c)
            else:
                out.append(('shard', [(m[0], m[1]) for m in c]))
        run.clear()

    for raw in lines:
        p = raw.strip().strip('"')
        st = None
        if p and not re.match(r'^[/-][A-Za-z_?]+(?::|$)', p) and is_shardable_path(p):   # not a /FLAG[:value] line
            try:
                st = stamp(p)
            except OSError:
                st = None
        if st is not None and not side_effect(p):
            run.append((p, st, raw))
            continue
        flush()
        out.append(('line', raw))
    flush()
    return out


def shard_name(members) -> str:
    h = hashlib.md5()
    for p, (mt, sz) in members:
        h.update(('%s|%d|%d\n' % (os.path.normcase(p), mt, sz)).encode('utf-8', 'replace'))
    return PREFIX + h.hexdigest()[:16] + '.lib'


def find_lib_tool() -> Path:
    for cand in [os.environ.get('QT_SHARD_LIBTOOL'), LLVM_LIB,
                 ROOT / 'tools/msvc800sp1/VC/bin/lib.exe',
                 ROOT / 'tools/vc2005/Program Files/Microsoft Visual Studio 8/VC/bin/lib.exe',
                 ROOT / 'tools/vc2005/VC/bin/lib.exe']:
        if cand and Path(cand).exists():
            return Path(cand)
    raise FileNotFoundError('no llvm-lib.exe / lib.exe (set QT_SHARD_LIBTOOL)')


def _pack(tool, lib: Path, members):
    tmp = lib.with_name(lib.stem + '.tmp.lib')
    rsp = lib.with_suffix('.rsp')
    rsp.write_text('/NOLOGO\n/OUT:"%s"\n' % tmp + ''.join('"%s"\n' % p for p, _ in members))
    r = subprocess.run([str(tool), '@' + str(rsp)], capture_output=True, text=True, errors='replace')
    if r.returncode != 0 or not tmp.exists():
        raise RuntimeError('%s failed for %s: %s' % (tool.name, lib.name, (r.stdout + r.stderr)[-600:]))
    os.replace(tmp, lib)
    return lib


def build(items, out_dir: Path, jobs=8, tool=None, packer=None):
    """make every shard of the plan that does not exist yet (content-named, so existing ones are current).
    Returns (lines with '"/WHOLEARCHIVE:<lib>"' in place of each chunk, number built)."""
    out_dir.mkdir(parents=True, exist_ok=True)
    todo, lines, names = [], [], []
    for kind, v in items:
        if kind == 'line':
            lines.append(v)
            continue
        lib = out_dir / shard_name(v)
        names.append(lib.name)
        if not lib.exists():
            todo.append((lib, v))
        lines.append('"/WHOLEARCHIVE:%s"' % lib)
    if todo:
        pk = packer or (lambda lib, m: _pack(tool or find_lib_tool(), lib, m))
        with concurrent.futures.ThreadPoolExecutor(max_workers=max(1, min(jobs, len(todo)))) as ex:
            list(ex.map(lambda a: pk(*a), todo))
    _gc(out_dir, names)
    return lines, len(todo)


def _gc(out_dir: Path, names, keep_plans=3):
    """remove shards no recent plan uses (the last keep_plans plans stay: lld_link.py rounds and variants)."""
    mf = out_dir / 'recent.json'
    try:
        recent = json.loads(mf.read_text())
    except (OSError, ValueError):
        recent = []
    recent = ([sorted(names)] + [r for r in recent if r != sorted(names)])[:keep_plans]
    mf.write_text(json.dumps(recent))
    keep = {n for r in recent for n in r}
    for f in out_dir.glob(PREFIX + '*'):
        base = f.name.split('.', 1)[0] + '.lib'
        if base not in keep:
            try:
                f.unlink()
            except OSError:
                pass


class _SideCache:
    """has_side_effect_section results keyed by (path, mtime_ns, size): 16k header reads per lld round otherwise."""
    def __init__(self, f: Path):
        self.f = f
        try:
            self.d = json.loads(f.read_text())
        except (OSError, ValueError):
            self.d = {}
        self.dirty = False

    def __call__(self, p):
        st = _stamp(p)
        k = os.path.normcase(p)
        e = self.d.get(k)
        if e and e[0] == list(st):
            return e[1]
        v = has_side_effect_section(p)
        self.d[k] = [list(st), v]; self.dirty = True
        return v

    def save(self):
        if self.dirty:
            self.f.parent.mkdir(parents=True, exist_ok=True)
            self.f.write_text(json.dumps(self.d))


def write_sharded_rsp(lines, out_rsp: Path, out_dir: Path, avg=256, jobs=8, packer=None, min_chunk=MIN_CHUNK):
    """lld_link.py's hook: shard the converted-object runs of LINES, write out_rsp, return (path, stats)."""
    sc = _SideCache(out_dir / 'side_effects.json')
    items = plan(lines, avg=avg, side_effect=sc, min_chunk=min_chunk)
    sc.save()
    new, built = build(items, out_dir, jobs=jobs, packer=packer)
    out_rsp.write_text('\n'.join(new) + '\n')
    n_sh = sum(1 for k, _ in items if k == 'shard')
    n_mem = sum(len(v) for k, v in items if k == 'shard')
    return out_rsp, {'shards': n_sh, 'members': n_mem, 'built': built, 'inputs_before': sum(1 for l in lines if l.strip('"').lower().endswith(('.obj', '.lib'))),
                     'inputs_after': sum(1 for l in new if l.strip('"').lower().endswith(('.obj', '.lib')))}


_OWNER = re.compile(r'(?<=\s)(?:[^\s()]*[\\/])?' + PREFIX + r'[0-9a-f]{16}(?:\.lib)?(?::|\()([^\s()]+?)\)?(?=\s|$)', re.M)


def unshard_map_text(t: str) -> str:
    """'<shard>:<member>' / '<shard>.lib(<member>)' owners -> '<member file name>', as a loose object shows."""
    return _OWNER.sub(lambda m: re.split(r'[\\/]', m.group(1))[-1], t)


def unshard_map(path):
    p = Path(path)
    t = p.read_text(errors='replace')
    if PREFIX in t:
        t2 = unshard_map_text(t)
        if t2 != t:
            p.write_text(t2)
            return True
    return False


def compare_exes(a, b):
    """byte compare two PE files ignoring the COFF TimeDateStamp and the optional-header CheckSum.
    -> None when identical, else a short description of the first difference."""
    x, y = bytearray(Path(a).read_bytes()), bytearray(Path(b).read_bytes())
    for d in (x, y):
        if d[:2] == b'MZ' and len(d) > 0x40:
            pe = struct.unpack_from('<I', d, 0x3c)[0]
            if d[pe:pe + 4] == b'PE\0\0':
                d[pe + 8:pe + 12] = b'\0\0\0\0'            # TimeDateStamp
                d[pe + 24 + 64:pe + 24 + 68] = b'\0\0\0\0'  # CheckSum (PE32 and PE32+ alike)
    if x == y:
        return None
    if len(x) != len(y):
        return 'sizes differ: %d vs %d' % (len(x), len(y))
    i = next(i for i in range(len(x)) if x[i] != y[i])
    return 'first difference at file offset 0x%x' % i


def compare_maps(a, b):
    """compare the symbol rows (address, name, owner) of two lld maps; -> list of up to 20 differences."""
    def rows(p):
        out = set()
        for l in Path(p).read_text(errors='replace').splitlines():
            q = l.split()
            if len(q) >= 4 and re.match(r'^[0-9a-f]{4}:[0-9a-f]{8}$', q[0]):
                out.add((q[0], q[1], q[2], q[-1]))
        return out
    ra, rb = rows(a), rows(b)
    return sorted(('only A',) + r for r in ra - rb)[:10] + sorted(('only B',) + r for r in rb - ra)[:10]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--rsp', type=Path, default=RSP_DEFAULT)
    ap.add_argument('--out-dir', type=Path, default=H / 'linkexp/shards')
    ap.add_argument('--avg', type=int, default=256)
    ap.add_argument('--build', action='store_true', help='pack the shards and write <rsp>.sharded.rsp (default: plan only)')
    ap.add_argument('--dry-run', action='store_true', help='old flag: plan only (the default)')
    ap.add_argument('--shards', type=int, help='old flag (fixed shard count): ignored, the count now follows --avg')
    ap.add_argument('--compare-exe', nargs=2)
    ap.add_argument('--compare-map', nargs=2)
    a = ap.parse_args()
    if a.shards is not None:
        print('shard_libs: --shards %d ignored: shards are now content-defined runs of about --avg %d members each '
              '(order-preserving, /WHOLEARCHIVE); see LINK_SPEED.md' % (a.shards, a.avg))
    if a.dry_run and a.build:
        ap.error('--dry-run and --build exclude each other')
    if a.compare_exe:
        d = compare_exes(*a.compare_exe)
        print('exe: identical (timestamp/checksum ignored)' if d is None else 'exe: DIFFERENT, ' + d)
        sys.exit(0 if d is None else 1)
    if a.compare_map:
        d = compare_maps(*a.compare_map)
        print('map: identical symbol rows' if not d else 'map: DIFFERENT\n' + '\n'.join('  %s' % (x,) for x in d))
        sys.exit(0 if not d else 1)
    lines = a.rsp.read_text(errors='ignore').splitlines()
    if not a.build:
        items = plan(lines, avg=a.avg)
        sh = [v for k, v in items if k == 'shard']
        before = sum(1 for l in lines if l.strip('"').lower().endswith(('.obj', '.lib')))
        after = before - sum(len(v) for v in sh) + len(sh)
        print('shard_libs: %d shards holding %d converted objects; inputs %d -> %d' % (len(sh), sum(map(len, sh)), before, after))
        return
    out, st = write_sharded_rsp(lines, a.rsp.with_name(a.rsp.stem + '.sharded.rsp'), a.out_dir, avg=a.avg)
    print('shard_libs: %s -> %s' % (st, out))


if __name__ == '__main__':
    main()
