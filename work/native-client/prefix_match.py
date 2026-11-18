"""Graded signal for big functions: how much of the target does the candidate reproduce?
  python work/native-client/prefix_match.py FILE.cpp ADDR[=name]
Compiles FILE.cpp (native toolchain, ~5 s), takes the symbol containing `name` (default sub_ADDR, else the one
closest in size), compares it to the original instruction by instruction (relocations masked) and prints the
matching prefix (insns/bytes of the target), the first divergence with 3 lines of context on both sides, and
score = matched prefix bytes / target bytes.  A partial candidate is fine: it is compared up to where it stops.
As a module: prefix_match.score(file, addr, name) -> dict (used by evolve.py)."""
import re
import sys
import time
import uuid
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import match, native_asm as na, native_bulk, rebuild  # noqa: E402

CLIENT = '2008-06'
_RT = {}


def _rt():
    if not _RT:
        _RT['runner'], _RT['tc'] = native_bulk.checker(), rebuild.toolchain(21022)
    return _RT['runner'], _RT['tc']


def compile_obj(source):
    runner, tc = _rt()
    folder = HERE / 'workflow-compile' / ('pm-%s-%s' % (Path(source).stem, uuid.uuid4().hex[:6]))
    folder.parent.mkdir(exist_ok=True)
    job = runner.compile_job({'source': str(Path(source).resolve()), 'checks': [], 'ranges': [], 'layouts': []}, folder, tc)
    obj = str(job.get('object') or '')
    if not Path(obj).is_file():
        import agent_prove
        return None, '\n'.join(agent_prove.compile_errors(folder, ''))[:1500]
    return obj, ''


def score(source, addr, name=''):
    """dict(ok, error, total_insns, total_bytes, prefix_insns, prefix_bytes, score, i, t, c, sym, cand_bytes)"""
    addr = addr.lower().replace('0x', '').zfill(8)
    obj, err = compile_obj(source)
    if not obj:
        return {'ok': False, 'error': 'COMPILE FAILED\n' + err}
    code, relocs, _ = match.target(CLIENT, addr)
    base = int(addr, 16)
    funcs = match.coff_functions(Path(obj).read_bytes())
    needle = (name or 'sub_' + addr).lower()
    hits = [f for f in funcs if needle in f[0].lower()] or sorted(funcs, key=lambda f: abs(len(f[1]) - len(code)))[:1]
    if not hits:
        return {'ok': False, 'error': 'no function emitted'}
    sym, body, crel = hits[0]
    t, c = na.lines(code, base, relocs), na.lines(body, base, crel)
    n = 0
    while n < min(len(t), len(c)) and t[n][2] == c[n][2]:
        n += 1
    pbytes = (t[n][0] - base) if n < len(t) else len(code)
    return {'ok': True, 'sym': sym, 'total_insns': len(t), 'total_bytes': len(code), 'prefix_insns': n,
            'prefix_bytes': pbytes, 'score': pbytes / len(code), 'i': n, 't': t, 'c': c, 'cand_bytes': len(body),
            'exact': n == len(t) == len(c)}


def report(r, addr, ctx=3):
    if not r['ok']:
        return r['error']
    t, c, n = r['t'], r['c'], r['i']
    out = ['%s: prefix %d/%d insns, %d/%d bytes, score %.1f%% (candidate %d bytes) %s' % (
        addr, r['prefix_insns'], r['total_insns'], r['prefix_bytes'], r['total_bytes'], 100 * r['score'],
        r['cand_bytes'], r['sym'][:70])]
    if r['exact']:
        out.append('IDENTICAL (relocs masked)')
        return '\n'.join(out)
    out.append('first divergence at insn %d (%08x)%s' % (n, t[n][0] if n < len(t) else t[-1][0],
               '  [candidate stops here]' if n >= len(c) else ''))
    lo = max(0, n - ctx)
    for tag, rows in (('target', t), ('cand  ', c)):
        out.append('--- %s' % tag)
        for k in range(lo, min(len(rows), n + ctx + 1)):
            out.append('%s %4d %08x  %s' % ('>' if k == n else ' ', k, rows[k][0], rows[k][1][:70]))
    return '\n'.join(out)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    a, _, nm = sys.argv[2].partition('=')
    t0 = time.time()
    res = score(sys.argv[1], a, nm)
    print(report(res, a))
    print('(%.1fs)' % (time.time() - t0))
