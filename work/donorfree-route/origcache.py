"""Original-exe disassembly cache shared by namediff/vtdiff: masked bodies never change, so they are computed once
(auto/orig_body.pkl). Use: from origcache import orig_body; orig_body(body_fn, img, addr, tag)."""
import atexit, pickle
from pathlib import Path
_F = Path(__file__).parent / 'auto/orig_body.pkl'
try:
    _C = pickle.load(open(_F, 'rb'))
except Exception:
    _C = {}
_dirty = [False]
def orig_body(fn, img, a, tag):
    k = (tag, a)
    v = _C.get(k)
    if v is None:
        v = _C[k] = fn(img, a); _dirty[0] = True
    return v
atexit.register(lambda: _dirty[0] and pickle.dump(_C, open(_F, 'wb'), protocol=4))
