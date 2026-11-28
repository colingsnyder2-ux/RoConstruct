"""python -m unittest test_link_speed (or python test_link_speed.py): the link-speed changes on small synthetic
inputs, runnable on any OS (no lld, no objects from the real link). See LINK_SPEED.md."""
import ast
import json
import os
import pickle
import re
import struct
import sys
import tempfile
import time
import unittest
from pathlib import Path

H = Path(__file__).parent
sys.path.insert(0, str(H))
import shardcache  # noqa: E402
from shardcache import ShardCache, ShardView  # noqa: E402
import shard_libs  # noqa: E402


def _touch_later(p):
    """make sure a rewrite gets a different mtime_ns even on coarse clocks"""
    st = os.stat(p)
    os.utime(p, ns=(st.st_atime_ns, st.st_mtime_ns + 1_000_000))


class ShardViewExact(unittest.TestCase):
    """ShardView.get must equal ShardCache.get in every state of the main cache."""

    def setUp(self):
        self.d = Path(tempfile.mkdtemp())
        self.main = self.d / 'x.pkl'
        self.side = self.d / 'x_side.pkl'
        c = ShardCache(self.main)
        for i in range(500):
            c['obj%d' % i] = ((i, i * 3), frozenset({'a%d' % i}), {'n%d' % i: bool(i % 2)})
        c.save()
        self.keys = ['obj%d' % i for i in range(0, 600, 7)]   # includes absent keys (>= 500)

    def check_equal(self, view=None):
        ref = ShardCache(self.main)
        v = view or ShardView(self.main, self.side)
        for k in self.keys:
            self.assertEqual(v.get(k), ref.get(k), k)
            self.assertEqual(k in v, k in ref)
        return v

    def test_first_run_verifies_then_serves_from_sidecar(self):
        v = self.check_equal()
        self.assertEqual(v.stats['main_loads'], 64)   # first run: every main shard loaded once and checked
        v.save()
        self.assertTrue((Path(str(self.side) + '.d') / 'meta.json').exists())
        v2 = self.check_equal()
        self.assertEqual(v2.stats['main_loads'], 0)
        self.assertEqual(v2.stats['side_hits'], 2 * len(self.keys))

    def test_main_changed_by_another_writer(self):
        v = self.check_equal(); v.save()
        c = ShardCache(self.main)
        c['obj7'] = 'changed'
        del c['obj14']
        c['obj595'] = 'new'
        c.save()
        v2 = self.check_equal()
        self.assertEqual(v2.get('obj7'), 'changed')
        self.assertIsNone(v2.get('obj14'))
        self.assertEqual(v2.get('obj595'), 'new')
        self.assertLessEqual(v2.stats['main_loads'], 3)   # only the rewritten shards
        v2.save()
        self.check_equal()

    def test_writes_through_view(self):
        v = ShardView(self.main, self.side); v.save()
        v = ShardView(self.main, self.side)
        v['obj21'] = 'mine'
        v['newkey'] = 'fresh'
        self.assertEqual(v.get('obj21'), 'mine')
        v.save()
        ref = ShardCache(self.main)
        self.assertEqual(ref['obj21'], 'mine')
        self.assertEqual(ref['newkey'], 'fresh')
        self.assertEqual(len(ref), 501)
        v3 = ShardView(self.main, self.side)
        self.assertEqual(v3.get('obj21'), 'mine')
        self.assertEqual(v3.stats['main_loads'], 0)   # restamped after our own save: no reload
        self.keys += ['newkey']
        self.check_equal()

    def test_single_file_cache_falls_back(self):
        f = self.d / 'single.pkl'
        pickle.dump({'a': 1, 'b': 2}, open(f, 'wb'))
        v = ShardView(f, self.d / 'single_side.pkl')
        self.assertTrue(v.stats['full'])
        self.assertEqual(v.get('a'), 1)
        self.assertIsNone(v.get('zz'))

    def test_foreign_file_falls_back(self):
        pickle.dump({'obj3': 'odd'}, open(Path(str(self.main) + '.d') / 'extra.pkl', 'wb'))
        v = ShardView(self.main, self.side)
        self.assertTrue(v.stats['full'])
        self.assertEqual(v.get('obj3'), ShardCache(self.main).get('obj3'))

    def test_misplaced_key_falls_back(self):
        d = Path(str(self.main) + '.d')
        wrong = (ShardCache.shard('misplaced') + 1) % shardcache.N
        f = d / ('%02d.pkl' % wrong)
        x = pickle.load(open(f, 'rb')); x['misplaced'] = 'here'
        pickle.dump(x, open(f, 'wb'))
        self.keys.append('misplaced')
        v = self.check_equal()
        self.assertTrue(v.stats['full'])

    def test_sidecar_keep_predicate_and_prune(self):
        v = ShardView(self.main, self.side, sidecar_keep=lambda k: k.endswith('7'))
        for k in self.keys:
            v.get(k)
        v.save()
        side = {}
        for f in (Path(str(self.side) + '.d')).glob('*.pkl'):
            side.update(pickle.load(open(f, 'rb')))
        self.assertTrue(side and all(k.endswith('7') for k in side))
        self.check_equal(ShardView(self.main, self.side, sidecar_keep=lambda k: k.endswith('7')))

    def test_pending(self):
        v = ShardView(self.main, self.side)
        for k in self.keys:
            v.get(k)
        self.assertTrue(v.pending())   # first run: sidecar + meta to write
        v.save()
        v2 = ShardView(self.main, self.side)
        for k in self.keys:
            v2.get(k)
        self.assertFalse(v2.pending())   # same lookups, nothing changed: no write
        v2['obj0'] = 'x'
        self.assertTrue(v2.pending())
        f = self.d / 'single.pkl'
        pickle.dump({'a': 1}, open(f, 'wb'))
        self.assertFalse(ShardView(f, self.d / 's2').pending())   # full fallback: the caller's dirty flag decides

    def test_sidecar_corrupt_is_harmless(self):
        v = self.check_equal(); v.save()
        for f in (Path(str(self.side) + '.d')).glob('*.pkl'):
            f.write_bytes(b'garbage')
        self.check_equal()


def _coff(sections):
    """minimal i386 COFF header + section table with the given names"""
    b = struct.pack('<HHIIIHH', 0x14c, len(sections), 0, 0, 0, 0, 0)
    for n in sections:
        b += n.encode().ljust(8, b'\0') + bytes(32)
    return b


class ShardPlan(unittest.TestCase):
    def setUp(self):
        self.d = Path(tempfile.mkdtemp())
        ro = self.d / 'renamed' / 'obj'
        ro.mkdir(parents=True)
        self.objs = []
        for i in range(60):
            p = ro / ('%08x.obj' % (0x400000 + i * 16))
            p.write_bytes(_coff(['.text', '.CRT$XCU'] if i == 30 else ['.text', '.data']))
            self.objs.append(str(p))
        nat = self.d / 'native.obj'; nat.write_bytes(_coff(['.text']))
        self.lines = (['"/OUT:x.exe"', '"/FORCE:MULTIPLE"', '"%s"' % nat] + ['"%s"' % o for o in self.objs[:45]]
                      + ['"%s"' % (self.d / 'patched_cf.obj')] + ['"%s"' % o for o in self.objs[45:]]
                      + ['"/alternatename:a=b"', '"C:\\lib\\mfc90.lib"'])

    def flatten(self, items):
        out = []
        for k, v in items:
            out += [m for m, _ in v] if k == 'shard' else [v.strip().strip('"')]
        return out

    def test_order_and_content_preserved(self):
        items = shard_libs.plan(self.lines, avg=8, min_chunk=2)
        self.assertEqual(self.flatten(items), [l.strip('"') for l in self.lines])
        shards = [v for k, v in items if k == 'shard']
        self.assertTrue(shards)
        crt = self.objs[30]
        self.assertNotIn(crt, [m for v in shards for m, _ in v])   # side-effect object stays loose
        for v in shards:
            self.assertGreaterEqual(len(v), 2)
        # no shard spans a non-shardable line (patched copy, CRT object)
        idx = {o: i for i, o in enumerate(self.objs)}
        for v in shards:
            ii = [idx[m] for m, _ in v]
            self.assertEqual(ii, list(range(ii[0], ii[0] + len(ii))))
            self.assertFalse(ii[0] < 30 < ii[-1] or ii[0] < 45 <= ii[-1] and ii[0] < 45)

    def test_windows_style_paths(self):
        self.assertTrue(shard_libs.is_shardable_path(r'C:\w\donorfree-route\renamed\obj\0042d280.obj'))
        self.assertFalse(shard_libs.is_shardable_path(r'C:\w\donorfree-route\linkexp\callfix\cf_0042d280.obj'))
        self.assertFalse(shard_libs.is_shardable_path(r'C:\w\donorfree-route\renamed\obj\x.lib'))

    def test_content_defined_chunks_are_local(self):
        a = shard_libs.plan(self.lines, avg=8, min_chunk=2)
        lines2 = [l for l in self.lines if self.objs[12] not in l]
        b = shard_libs.plan(lines2, avg=8, min_chunk=2)
        na = [shard_libs.shard_name(v) for k, v in a if k == 'shard']
        nb = [shard_libs.shard_name(v) for k, v in b if k == 'shard']
        self.assertGreaterEqual(len(set(na) & set(nb)), len(na) - 2)   # one object left: at most its chunk(s) change

    def test_name_changes_with_member_stamp(self):
        items = shard_libs.plan(self.lines, avg=8, min_chunk=2)
        v = next(v for k, v in items if k == 'shard')
        n0 = shard_libs.shard_name(v)
        p = v[0][0]
        time.sleep(0.01); Path(p).write_bytes(Path(p).read_bytes()); _touch_later(p)
        v2 = next(v for k, v in shard_libs.plan(self.lines, avg=8, min_chunk=2) if k == 'shard')
        self.assertNotEqual(shard_libs.shard_name(v2), n0)

    def test_build_and_reuse(self):
        out = self.d / 'shards'
        packed = []

        def fake(lib, members):
            packed.append(lib.name)
            lib.write_text('\n'.join(m for m, _ in members))
        rsp = self.d / 'qt.final.sharded.rsp'
        r, st = shard_libs.write_sharded_rsp(self.lines, rsp, out, avg=8, packer=fake, min_chunk=2)
        self.assertEqual(st['built'], st['shards'])
        txt = rsp.read_text().splitlines()
        self.assertTrue(any(l.startswith('"/WHOLEARCHIVE:') for l in txt))
        # expanding every shard gives the original input list back, in order
        exp = []
        for l in txt:
            m = re.match(r'^"/WHOLEARCHIVE:(.+)"$', l)
            exp += Path(m.group(1)).read_text().split('\n') if m else [l.strip('"')]
        self.assertEqual(exp, [l.strip('"') for l in self.lines])
        packed.clear()
        r, st = shard_libs.write_sharded_rsp(self.lines, rsp, out, avg=8, packer=fake, min_chunk=2)
        self.assertEqual((st['built'], packed), (0, []))
        # a removed object: only the shards that changed are built, unused ones are collected after 3 plans
        lines2 = [l for l in self.lines if self.objs[3] not in l]
        r, st = shard_libs.write_sharded_rsp(lines2, rsp, out, avg=8, packer=fake, min_chunk=2)
        self.assertLessEqual(st['built'], 2)

    def test_unshard_map(self):
        t = ('  0001:00001000       func_00401000              00401000 f   qtshard_0123456789abcdef:00401000.obj\n'
             '  0001:00001010       _x                         00401010 f   qtshard_0123456789abcdef.lib(00401010.obj)\n'
             '  0001:00001020       _y                         00401020 f   C:\\w\\qtshard_0123456789abcdef:C:\\w\\renamed\\obj\\00401020.obj\n'
             '  0001:00001030       _z                         00401030 f   LIBCMT:crt0.obj\n')
        u = shard_libs.unshard_map_text(t).splitlines()
        self.assertEqual([l.split()[-1] for l in u], ['00401000.obj', '00401010.obj', '00401020.obj', 'LIBCMT:crt0.obj'])
        self.assertEqual(shard_libs.unshard_map_text(u[3]), u[3])

    def test_compare_exes_ignores_timestamp(self):
        def pe(ts, body):
            b = bytearray(0x200)
            b[:2] = b'MZ'; struct.pack_into('<I', b, 0x3c, 0x80); b[0x80:0x84] = b'PE\0\0'
            struct.pack_into('<I', b, 0x88, ts); struct.pack_into('<I', b, 0x80 + 24 + 64, ts ^ 0x5a5a)
            b[0x180:0x180 + len(body)] = body
            return bytes(b)
        a, b, c = self.d / 'a.exe', self.d / 'b.exe', self.d / 'c.exe'
        a.write_bytes(pe(1, b'code')); b.write_bytes(pe(2, b'code')); c.write_bytes(pe(1, b'cod3'))
        self.assertIsNone(shard_libs.compare_exes(a, b))
        self.assertIn('0x183', shard_libs.compare_exes(a, c))


def _load_funcs(path, names, scope):
    tree = ast.parse(Path(path).read_text())
    body = [n for n in tree.body if isinstance(n, (ast.FunctionDef, ast.Assign)) and
            (getattr(n, 'name', None) in names or (isinstance(n, ast.Assign) and any(getattr(t, 'id', None) in names for t in n.targets)))]
    exec(compile(ast.Module(body=body, type_ignores=[]), str(path), 'exec'), scope)
    return scope


class QuicktestMapRows(unittest.TestCase):
    def test_same_rows_and_invalidation(self):
        sc = _load_funcs(H / 'quicktest.py', {'_map_rows', '_MAPROWS'}, {'os': os, 'Path': Path})
        d = Path(tempfile.mkdtemp())
        m = d / 'qt.map'
        m.write_text(' Address  Publics\n  0001:00000000  func_00401000  00401000 f  00401000.obj\n\n  0000:00000000  ___ImageBase  00400000  <linker-defined>\n')
        rows = sc['_map_rows'](m)
        self.assertEqual(rows, [l.split() for l in m.read_text(errors='replace').splitlines()])
        self.assertIs(sc['_map_rows'](m), rows)   # second call: cached
        time.sleep(0.01)
        m.write_text(m.read_text() + '  0001:00000010  func_00401010  00401010 f  00401010.obj\n'); _touch_later(m)
        rows2 = sc['_map_rows'](m)
        self.assertEqual(len(rows2), len(rows) + 1)
        self.assertEqual(len(sc['_MAPROWS']), 1)   # the old version was dropped


class _Env:
    def __init__(self, **kv):
        self.kv = kv

    def __enter__(self):
        self.old = {k: os.environ.get(k) for k in self.kv}
        for k, v in self.kv.items():
            if v is None:
                os.environ.pop(k, None)
            else:
                os.environ[k] = v

    def __exit__(self, *a):
        for k, v in self.old.items():
            if v is None:
                os.environ.pop(k, None)
            else:
                os.environ[k] = v


class LldBlankCache(unittest.TestCase):
    """lld_link._preresolve_aliases: same blanked bytes; rewritten every call by default; reused only with
    LLD_REUSE_BLANKS=1 / QT_REUSE_COPIES=1, and then rebuilt when source, copy bytes or lld_link code change"""

    def setUp(self):
        self.d = Path(tempfile.mkdtemp())
        self.code = self.d / 'lld_link_copy.py'
        self.code.write_text('# v1')
        self.a = self.d / 'a.obj'; self.b = self.d / 'b.obj'
        self.a.write_bytes(b'xx /alternatename:K=T1 yy')
        self.b.write_bytes(b'zz /alternatename:K=T2 /alternatename:Q=R ww')
        self.out = ['"/alternatename:Q=S"', '"%s"' % self.a, '"%s"' % self.b]

    def run_pre(self):
        import shutil
        d = self.d
        sc = {'re': re, 'os': os, 'json': json, 'Path': Path, 'shutil': shutil, 'H': d, 'P': d / 'linkexp/patched', '_TAG': '',
              '__file__': str(self.code)}
        (d / 'linkexp/patched').mkdir(parents=True, exist_ok=True)
        _load_funcs(H / 'lld_link.py', {'_preresolve_aliases'}, sc)
        return sc['_preresolve_aliases'](list(self.out))

    def expect(self, r):
        copy = Path(r[2].strip('"'))
        self.assertEqual(copy.read_bytes(), b'zz ' + b' ' * len('/alternatename:K=T2') + b' ' + b' ' * len('/alternatename:Q=R') + b' ww')
        return copy

    def test_default_rewrites_every_time(self):
        with _Env(LLD_REUSE_BLANKS=None, QT_REUSE_COPIES=None):
            copy = self.expect(self.run_pre())
            copy.write_bytes(b'tampered')
            self.expect(self.run_pre())   # rewritten regardless of any cache
            self.assertFalse((self.d / 'linkexp/patched/_blank_cache.json').exists())

    def test_opt_in_reuse_and_invalidation(self):
        with _Env(LLD_REUSE_BLANKS='1', QT_REUSE_COPIES=None):
            r1 = self.run_pre(); copy = self.expect(r1)
            os.utime(copy, ns=(1, 1_000_000_000))
            r2 = self.run_pre()
            self.assertEqual(r1, r2)
            self.assertGreater(os.stat(copy).st_mtime_ns, 1_000_000_000)   # reused: mtime refreshed for mtime-gated readers
            copy.write_bytes(b'zz' + b' ' * 40)   # same name, other bytes (another source wrote it): rebuilt
            self.expect(self.run_pre())
            self.code.write_text('# v2')   # lld_link code changed: rebuilt
            copy.write_bytes(b'stale-but-same-key')
            self.expect(self.run_pre())
            self.b.write_bytes(b'zz /alternatename:K=T3 ww'); _touch_later(self.b)
            r3 = self.run_pre()
            self.assertEqual(Path(r3[2].strip('"')).read_bytes(), b'zz ' + b' ' * len('/alternatename:K=T3') + b' ww')


class QuicktestReuseHelpers(unittest.TestCase):
    def test_reuse_copy_checks_digest_and_refreshes_mtime(self):
        import hashlib
        sc = _load_funcs(H / 'quicktest.py', {'_fmd5', '_reuse_copy'}, {'os': os, 'Path': Path})
        d = Path(tempfile.mkdtemp()); q = d / 'ni_candidate.obj'
        q.write_bytes(b'copy of A')
        os.utime(q, ns=(1, 1_000_000_000))
        self.assertTrue(sc['_reuse_copy'](q, hashlib.md5(b'copy of A').hexdigest()))
        self.assertGreater(os.stat(q).st_mtime_ns, 1_000_000_000)
        self.assertFalse(sc['_reuse_copy'](q, hashlib.md5(b'copy of B').hexdigest()))
        self.assertFalse(sc['_reuse_copy'](d / 'missing.obj', 'x'))
        self.assertFalse(sc['_reuse_copy'](q, None))

    def test_copy_reuse_is_opt_in(self):
        t = (H / 'quicktest.py').read_text()
        self.assertIn("_REUSE = os.environ.get('QT_REUSE_COPIES') == '1'", t)
        # every cache entry / reuse of a written copy sits behind _REUSE
        for pat in (r"_dcc\[\('pc'", r"_scc\[\('ni'", r"(?<!def )_reuse_copy\(", r"_bsf\.write_text"):
            for m in re.finditer(pat, t):
                block = t[:m.start()].split('\n')
                ctx = '\n'.join(block[-14:])
                self.assertIn('_REUSE', ctx, pat)
        self.assertIn('_codev()', t)
        self.assertIn("'roc/rebuild.py'", t)


class LldprofEnv(unittest.TestCase):
    def test_roc_env_is_opt_in(self):
        t = (H / 'lldprof.py').read_text()
        self.assertIn('ENV = None   # default', t)
        self.assertIn('--env roc', t)


class ShardLibsCli(unittest.TestCase):
    def test_old_flags_accepted(self):
        import subprocess
        d = Path(tempfile.mkdtemp()); rsp = d / 'x.rsp'; rsp.write_text('"/OUT:x.exe"\n')
        r = subprocess.run([sys.executable, str(H / 'shard_libs.py'), '--dry-run', '--shards', '16', '--out-dir', str(d / 'o'),
                            '--rsp', str(rsp)], capture_output=True, text=True)
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertIn('--shards 16 ignored', r.stdout)
        self.assertIn('0 shards', r.stdout)


class Compiles(unittest.TestCase):
    def test_edited_files_compile(self):
        import py_compile
        for f in ('quicktest.py', 'shard_libs.py', 'shardcache.py', 'fastlink.py', 'lld_link.py', 'lldprof.py', 'audits_all.py'):
            py_compile.compile(str(H / f), doraise=True)

    def test_quicktest_kill_switches_documented(self):
        t = (H / 'quicktest.py').read_text()
        for env in ('QT_NO_EARLY_PREPROCS', 'QT_NO_SIDECAR', 'QT_NO_MAPCACHE', 'QT_REUSE_COPIES'):
            self.assertIn(env, t)
            self.assertIn(env, (H / 'LINK_SPEED.md').read_text())


if __name__ == '__main__':
    unittest.main()
