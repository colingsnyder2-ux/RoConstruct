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
