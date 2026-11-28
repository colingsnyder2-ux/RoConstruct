"""Sharded pickle cache for the per-object symbol caches (link/obj_ext_cache.pkl, linkexp/qt_ext_cache.pkl: ~2 GB each).
A single pickle was rewritten whole whenever one object changed (~25 s of dump per link). ShardCache keeps 64 shard
files in <path>.d/ keyed by crc32(path) and rewrites only the shards whose keys changed. Migrates the old single file
on first use. Usage: c = ShardCache(path); v = c.get(k); c[k] = v (marks dirty); c.save()."""
import os, pickle, zlib
from pathlib import Path

N = 64


class ShardCache(dict):
    def __init__(self, path):
        super().__init__()
        self.dir = Path(str(path) + '.d')
        self.dirty = set()
        import gc
        _ge = gc.isenabled(); gc.disable()   # millions of small objects: the collector doubled the load time
        try:
            if self.dir.exists():
                for f in self.dir.glob('*.pkl'):
                    try:
                        super().update(pickle.load(open(f, 'rb')))
                    except Exception:
                        pass
            elif Path(path).exists():   # migrate the single-file cache once
                try:
                    super().update(pickle.load(open(path, 'rb')))
                except Exception:
                    pass
                self.dirty = set(range(N))
        finally:
            if _ge:
                gc.enable()

    @staticmethod
    def shard(k):
        return zlib.crc32(str(k).encode('utf-8', 'replace')) % N

    def __setitem__(self, k, v):
        super().__setitem__(k, v)
        self.dirty.add(self.shard(k))

    def __delitem__(self, k):
        super().__delitem__(k)
        self.dirty.add(self.shard(k))

    def save(self):
        if not self.dirty:
            return
        self.dir.mkdir(parents=True, exist_ok=True)
        parts = {i: {} for i in self.dirty}
        for k, v in self.items():
            s = self.shard(k)
            if s in parts:
                parts[s][k] = v
        for i, d in parts.items():
            tmp = self.dir / ('%02d.tmp' % i)
            pickle.dump(d, open(tmp, 'wb'), protocol=pickle.HIGHEST_PROTOCOL)
            os.replace(tmp, self.dir / ('%02d.pkl' % i))
        self.dirty = set()



def _fstamp(st):
    """identity of one shard file version: ShardCache.save writes a new temp file and os.replace()s it, so the file id
    (st_ino: the NTFS file index on Windows) changes on every save even within one mtime tick at the same size"""
    return (st.st_mtime_ns, st.st_size, st.st_ino)


class ShardView:
    """Read-through view of a ShardCache directory (<path>.d/NN.pkl) that unpickles only the main shards it needs.

    get(k) returns exactly what ShardCache(path).get(k) returns. An entry is served from a small sidecar copy
    (<sidecar>.d/NN.pkl, only the keys looked up in recent runs) while the main shard file that holds k still has the
    (mtime_ns, size, file id) it had when the entry was copied; otherwise that one main shard (~1/64 of 2 GB) is unpickled.
    view[k] = v loads k's main shard, sets k and marks it dirty; save() rewrites only dirty main shards (the same files
    and format as ShardCache.save) and then the changed sidecar shards.

    Falls back to a full ShardCache (identical behaviour, full load) when the layout cannot be trusted: no <path>.d yet
    (single-file cache still to migrate), a file in <path>.d that is not NN.pkl with NN < N, or a main shard holding a
    key that does not hash to it. The first run with a new sidecar loads and checks every main shard once.
    sidecar_keep(k) -> False keeps k out of the sidecar (it is still read exactly, from its main shard)."""
    def __init__(self, path, sidecar, sidecar_keep=None):
        import re as _re
        self.path = Path(path)
        self.dir = Path(str(path) + '.d')
        self.sdir = Path(str(sidecar) + '.d')
        self.keep = sidecar_keep or (lambda k: True)
        self._full = None
        self._main = {}        # shard index -> dict (loaded main shards)
        self._mdirty = set()
        self._used = {}        # key -> (stamp, present, value) as served this run
        self._writes = {}      # key -> value set through this view (replayed if it has to fall back to a full load)
        self.stats = {'side_hits': 0, 'main_loads': 0, 'full': False}
        if not self.dir.is_dir():
            self._go_full()
            return
        self._stamp = {}
        for f in self.dir.glob('*.pkl'):
            m = _re.match(r'^(\d\d)\.pkl$', f.name)
            if not m or int(m.group(1)) >= N:
                self._go_full()
                return
            st = f.stat()
            self._stamp[int(m.group(1))] = _fstamp(st)
        self._side = {}
        self._sdirty = set()
        meta = None
        try:
            import json as _js
            meta = _js.loads((self.sdir / 'meta.json').read_text())
        except Exception:
            meta = None
        import gc
        _ge = gc.isenabled(); gc.disable()
        try:
            if meta and meta.get('N') == N and meta.get('verified') and meta.get('main') == os.path.normcase(str(self.dir.resolve())):
                for f in self.sdir.glob('*.pkl'):
                    try:
                        with open(f, 'rb') as fh:
                            self._side.update(pickle.load(fh))
                    except Exception:
                        pass
            else:   # first run (or another N / main path): load and check every main shard once
                for i in sorted(self._stamp):
                    self._load(i)
                    if self._full is not None:
                        return
                self._verified_now = True
        finally:
            if _ge:
                gc.enable()

    def _go_full(self):
        self._full = ShardCache(self.path)
        for k, v in self._writes.items():
            self._full[k] = v
        self._main = {}
        self.stats['full'] = True

    def _load(self, i):
        d = self._main.get(i)
        if d is not None:
            return d
        f = self.dir / ('%02d.pkl' % i)
        d = {}
        if i in self._stamp:
            import gc
            _ge = gc.isenabled(); gc.disable()
            try:
                with open(f, 'rb') as fh:
                    d = pickle.load(fh)
            except Exception:
                d = {}
            finally:
                if _ge:
                    gc.enable()
            self.stats['main_loads'] += 1
            if any(ShardCache.shard(k) != i for k in d):   # a key in the wrong shard: only a full load is exact
                self._go_full()
                return None
        self._main[i] = d
        return d

    def _lookup(self, k):
        if self._full is not None:
            return (True, self._full[k]) if k in self._full else (False, None)
        i = ShardCache.shard(k)
        st = self._stamp.get(i)
        e = self._side.get(k)
        if i not in self._main and e is not None and e[0] == st:
            self.stats['side_hits'] += 1
            self._used[k] = e
            return e[1], e[2]
        d = self._load(i)
        if d is None:   # switched to a full load
            return self._lookup(k)
        r = (k in d, d.get(k))
        self._used[k] = (st, r[0], r[1])
        return r

    def get(self, k, default=None):
        present, v = self._lookup(k)
        return v if present else default

    def __contains__(self, k):
        return self._lookup(k)[0]

    def __getitem__(self, k):
        present, v = self._lookup(k)
        if not present:
            raise KeyError(k)
        return v

    def __setitem__(self, k, v):
        if self._full is not None:
            self._full[k] = v
            return
        i = ShardCache.shard(k)
        d = self._load(i)
        if d is None:
            self._full[k] = v
            return
        d[k] = v
        self._writes[k] = v
        self._mdirty.add(i)
        self._used[k] = (self._stamp.get(i), True, v)

    def save(self):
        if self._full is not None:
            self._full.save()
            return
        if self._mdirty:
            self.dir.mkdir(parents=True, exist_ok=True)
            for i in sorted(self._mdirty):
                tmp = self.dir / ('%02d.tmp' % i)
                with open(tmp, 'wb') as fh:
                    pickle.dump(self._main[i], fh, protocol=pickle.HIGHEST_PROTOCOL)
                os.replace(tmp, self.dir / ('%02d.pkl' % i))
                self._stamp[i] = _fstamp(os.stat(self.dir / ('%02d.pkl' % i)))
            for k in list(self._used):   # what we wrote is exactly what the entries hold: restamp them
                i = ShardCache.shard(k)
                if i in self._mdirty:
                    d = self._main[i]
                    self._used[k] = (self._stamp[i], k in d, d.get(k))
            self._mdirty = set()
        self._save_side()

    def _side_changes(self):
        """(changed sidecar entries, stale keys to prune or [])"""
        new = {k: e for k, e in self._used.items() if self.keep(k)}
        changed = {}
        for k, e in new.items():
            o = self._side.get(k)
            if o is None or o[0] != e[0] or o[1] != e[1]:   # same main-shard stamp = same file = same value
                changed[k] = e
        stale = [k for k in self._side if k not in new]
        if len(stale) <= max(1000, len(self._side) // 4):   # prune keys no longer looked up (stale native paths)
            stale = []
        return changed, stale

    def pending(self):
        """True when save() would write the view's own changes (main shards set through it, sidecar, first-run
        meta). In full-load fallback it is False: the caller's own dirty flag decides, as with a plain ShardCache
        (so a never-migrated single-file cache is not migrated just because it was read)."""
        if self._full is not None:
            return False
        if self._mdirty or getattr(self, '_verified_now', False):
            return True
        changed, stale = self._side_changes()
        return bool(changed or stale)

    def _save_side(self):
        changed, stale = self._side_changes()
        for k, e in changed.items():
            self._side[k] = e
            self._sdirty.add(ShardCache.shard(k))
        for k in stale:
            del self._side[k]
            self._sdirty.add(ShardCache.shard(k))
        first = getattr(self, '_verified_now', False)
        if not self._sdirty and not first:
            return
        self.sdir.mkdir(parents=True, exist_ok=True)
        parts = {i: {} for i in self._sdirty}
        for k, e in self._side.items():
            s = ShardCache.shard(k)
            if s in parts:
                parts[s][k] = e
        for i, d in parts.items():
            tmp = self.sdir / ('%02d.tmp' % i)
            with open(tmp, 'wb') as fh:
                pickle.dump(d, fh, protocol=pickle.HIGHEST_PROTOCOL)
            os.replace(tmp, self.sdir / ('%02d.pkl' % i))
        if first:
            import json as _js
            (self.sdir / 'meta.json').write_text(_js.dumps({'N': N, 'verified': True, 'main': os.path.normcase(str(self.dir.resolve()))}))
            self._verified_now = False
        self._sdirty = set()


if __name__ == '__main__':
    import tempfile
    d = tempfile.mkdtemp()
    c = ShardCache(os.path.join(d, 'x.pkl'))
    c['a'] = 1; c['b'] = 2; c.save()
    c2 = ShardCache(os.path.join(d, 'x.pkl'))
    assert c2 == {'a': 1, 'b': 2} and not c2.dirty
    c2['a'] = 3; assert len(c2.dirty) == 1; c2.save()
    assert ShardCache(os.path.join(d, 'x.pkl'))['a'] == 3
    print('shardcache ok')
