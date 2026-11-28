"""python namediff.py [EXE MAP]: compare every function that has the same mangled name in the original 2008-06 exe
(function-files.json) and in our linked exe (map): instruction streams with address operands masked. Writes
auto/namediff.json {name: {orig, ours, at, o, n}} for the ones that differ and prints counts, File->New-reachable first."""
import json, re, sys
from pathlib import Path
import capstone, pefile
from origcache import orig_body

H = Path(__file__).parent
ROOT = H.parents[1]
exe = sys.argv[1] if len(sys.argv) > 2 else str(H / 'link/donorfree.exe')
mp = sys.argv[2] if len(sys.argv) > 2 else str(H / 'link/donorfree.map')
bo = bytes(pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe')).get_memory_mapped_image())
bn = bytes(pefile.PE(exe).get_memory_mapped_image())
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
orig = {}
for a, v in ff.items():
    n = (v or {}).get('name') or ''
    if n.startswith('?'):
        orig.setdefault(n, int(a, 16))
ours, stub = {}, set()
for l in open(mp, errors='replace'):
    m = re.match(r'\s*0001:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s+(?:f\s+)?(?:i\s+)?(\S+)', l)
    if m:
        ours.setdefault(m.group(1), int(m.group(2), 16))
        if m.group(3) == 'stubs.obj':
            stub.add(m.group(1))
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
MASK = re.compile(r'0x[0-9a-f]{5,8}')


def body(b, a):
    out = []
    for i in md.disasm(b[a - 0x400000:a - 0x400000 + 0x600], a):
        out.append(i.mnemonic + ' ' + MASK.sub('X', i.op_str))
        if i.mnemonic in ('ret', 'int3') or (i.mnemonic == 'jmp' and len(out) > 2 and not i.op_str.startswith('0x')) or len(out) >= 120:
            break
    return out


try:
    _rr = json.load(open(H / 'auto/reach.json'))
    reach = {r['name'] for r in _rr}
    reach_addr = {r['addr'] for r in _rr}
except Exception:
    reach, reach_addr = set(), set()
diff, same, stubbed = {}, 0, 0
for n, a in orig.items():
    c = ours.get(n)
    if c is None:
        continue
    if n in stub:
        stubbed += 1
        continue
    A, B = orig_body(body, bo, a, 'nd'), body(bn, c)
    if A == B:
        same += 1
        continue
    k = next((j for j in range(min(len(A), len(B))) if A[j] != B[j]), min(len(A), len(B)))
    diff[n] = {'orig': '%08x' % a, 'ours': '%08x' % c, 'at': k, 'o': A[k] if k < len(A) else '-', 'n': B[k] if k < len(B) else '-', 'reach': n[:100] in reach}
# address-named functions (fn_<addr> LLM drafts, func_<addr> conversions): the address is in the name
for n, c in ours.items():
    m = re.search(r'(?:^|[_@])f(?:n|unc)_([0-9a-f]{8})(?:@\d+)?$', n)
    if not m or n in stub or n in diff:
        continue
    a = int(m.group(1), 16)
    A, B = orig_body(body, bo, a, 'nd'), body(bn, c)
    if A == B:
        same += 1
        continue
    k = next((j for j in range(min(len(A), len(B))) if A[j] != B[j]), min(len(A), len(B)))
    diff[n] = {'orig': '%08x' % a, 'ours': '%08x' % c, 'at': k, 'o': A[k] if k < len(A) else '-', 'n': B[k] if k < len(B) else '-',
               'reach': ('%08x' % a) in reach_addr, 'draft': n.lstrip('_@').startswith('fn_')}
# call-target check: instruction streams can match while a direct call lands on the wrong function (an analog's invented
# name colliding with an unrelated real one, a stub). For each identical pair compare the bodies of the direct call targets.
CALL = re.compile(r'^(?:call|jmp) 0x([0-9a-f]{5,8})$')
name_at = {}
for n_, c_ in ours.items():
    name_at.setdefault(c_, n_)
stub_at = {ours[n_] for n_ in stub if n_ in ours}
_bc = {}
def _b(img, key, a):
    if (key, a) not in _bc:
        _bc[(key, a)] = body(img, a)
    return _bc[(key, a)]
def targets(b, a):
    out = []
    for i in md.disasm(b[a - 0x400000:a - 0x400000 + 0x600], a):
        m_ = CALL.match(i.mnemonic + ' ' + i.op_str)
        out.append(int(m_.group(1), 16) if m_ and i.mnemonic == 'call' else None)
        if i.mnemonic in ('ret', 'int3') or (i.mnemonic == 'jmp' and len(out) > 2 and not i.op_str.startswith('0x')) or len(out) >= 120:
            break
    return out
pairs = [(n_, a_, ours[n_]) for n_, a_ in orig.items() if n_ in ours and n_ not in stub and n_ not in diff]
for n_, c_ in ours.items():
    m_ = re.search(r'(?:^|[_@])f(?:n|unc)_([0-9a-f]{8})(?:@\d+)?$', n_)
    if m_ and n_ not in stub and n_ not in diff:
        pairs.append((n_, int(m_.group(1), 16), c_))
calls = []
for n_, a_, c_ in pairs:
    for t_, u_ in zip(orig_body(targets, bo, a_, 'tg'), targets(bn, c_)):
        if t_ is None or u_ is None or not (0x401000 <= t_ < 0x7c0000) or u_ - 0x400000 >= len(bn):
            continue
        if u_ in stub_at:
            kind = 'stub'
        elif orig_body(body, bo, t_, 'nd') != _b(bn, 'n', u_):
            kind = 'wrong'
        else:
            continue
        calls.append({'caller': n_, 'orig': '%08x' % a_, 'target': '%08x' % t_, 'ours': name_at.get(u_, '%08x' % u_), 'kind': kind,
                      'reach': ('%08x' % a_) in reach_addr or n_[:100] in reach})
(H / 'auto/calldiff.json').write_text(json.dumps(calls, indent=0))
from collections import Counter
print('call targets in identical functions:', dict(Counter((c_['kind'], c_['reach']) for c_ in calls)),
      '| distinct wrong targets %d, stub targets %d' % (len({c_['target'] for c_ in calls if c_['kind'] == 'wrong'}), len({c_['target'] for c_ in calls if c_['kind'] == 'stub'})))
(H / 'auto/namediff.json').write_text(json.dumps(diff, indent=0))
r = [n for n, d in diff.items() if d['reach']]
print('same-named pairs: identical %d, different %d (File->New-reachable %d; drafts %d), stubbed %d' % (same, len(diff), len(r), sum(1 for d_ in diff.values() if d_.get('draft')), stubbed))
for n in r[:25]:
    d = diff[n]
    print('%s %-70s insn %d: %s | %s' % (d['orig'], n[:70], d['at'], d['o'][:30], d['n'][:30]))
