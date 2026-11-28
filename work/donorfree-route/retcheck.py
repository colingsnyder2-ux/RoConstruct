"""python retcheck.py: stack-balance check for every claimed pair (as bindcheck.py): the original function's ret
immediate (ret N = callee-popped bytes) must equal ours. A mismatch skews the caller's stack after every call: the
crash shows up far away. Static, seconds. Writes auto/retcheck.json [[name, orig, ret_orig, ret_ours, obj]]."""
import json, re, sys
from pathlib import Path
H = Path(__file__).parent
src = (H / 'bindcheck.py').read_text(encoding='utf-8')
g = {'__file__': str(H / 'bindcheck.py'), '__name__': 'x'}
exec(compile(src.split('osig = collections.defaultdict(list)')[0], 'bc', 'exec'), g)
exec(compile(src.split('claims = {}   # name -> set(A)')[1].split('ours_means')[0].join(['claims = {}\n', '']), 'bc2', 'exec'), g)
q, o, insns, sym, objof = g['q'], g['o'], g['insns'], g['sym'], g['objof']


def rets(img, va):
    out = set()
    for i in insns(img, va, 0x1800):
        if i.mnemonic == 'ret':
            out.add(int(i.op_str, 16) if i.op_str else 0)
    return out


bad = []
for n, As in g['claims'].items():
    ob = objof[n]
    if 'stubs' in ob or ':' in ob:
        continue
    rq = rets(q, sym[n])
    for A in As:
        if not 0x401000 <= A < 0x7c0000 or bytes(o[A - 0x400000:A - 0x400000 + 1]) in (b'\xe9', b'\xff'):
            continue
        ro = rets(o, A)
        if ro and rq and not (ro & rq):
            bad.append([n, '%08x' % A, sorted(ro), sorted(rq), ob])
(H / 'auto/retcheck.json').write_text(json.dumps(bad, indent=0))
conv = lambda ob: bool(re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', ob))
print('retcheck: pairs with different callee-popped bytes: %d (converted %d)' % (len(bad), sum(conv(b[4]) for b in bad)))
for b in bad[:25]:
    print('  ', b[1], b[0][:60], 'orig ret', b[2], 'ours', b[3], '|', b[4][:35])
