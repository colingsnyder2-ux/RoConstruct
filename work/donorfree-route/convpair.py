"""python convpair.py: stubbed NAMES called by converted objects, bound through the original's call targets. A converted
object (renamed/obj/<A>.obj) is the original function's own code, so its relocated call at offset k goes where the
original's call at A+k goes. When our link stubs the symbol S (?throwable_lua_tostring@Lua@RBX@@ ... no registry name,
no definition: Lua property assignment passed NULL to std::string) and defines the original target T (func_<T> or T's
registry name), alias S -> that definition. Only E8 rel32 calls, only when the object body and the original agree in
length at that offset. Writes aliases_convpair.txt (grow-only)."""
import collections, json, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild as rb
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
nc = collections.Counter((v or {}).get('name') for v in reg.values())
stubs, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defs).add(p[1])
src = (H / 'codematch.py').read_text(encoding='latin-1')
exec(compile(src[src.index('def relsyms'):src.index('def orig_names')], 'relsyms', 'exec'))
want = {s for s in stubs if not re.match(r'^(func_|dat_|_g_|_fn_|@fn_|roc_str_)', s)}
votes = collections.defaultdict(collections.Counter)
for o in sorted((H / 'renamed/obj').glob('*.obj')):
    a = o.stem
    if not re.fullmatch(r'[0-9a-f]{8}', a):
        continue
    b = o.read_bytes()
    if not any((not d) and n in want for n, d in rb.coff_externals(b).items()):
        continue
    try:
        code, _, _ = match.target('2008-06', a)
    except BaseException:
        continue
    base = int(a, 16)
    bodies = {f: body for f, body, _ in match.coff_functions(b)}
    for fn, rel in relsyms(b).items():
        body = bodies.get(fn)
        if body is None or len(body) != len(code):   # the converted body must be the original's length (exact copy)
            continue
        for off, sym in rel.items():
            if sym not in want or off < 1 or off + 4 > len(code) or code[off - 1] != 0xE8 or body[off - 1] != 0xE8:
                continue   # a real CALL in both: the original's E8 and the object's E8 at the same offset
            if re.search(r'@@[0-9]', sym) or sym.startswith('??_C@'):
                continue   # data symbols (?x@@3...) are never call targets
            t = '%08x' % ((base + off + 4 + struct.unpack_from('<i', code, off)[0]) & 0xffffffff)
            n = (reg.get(t) or {}).get('name')
            tgt = next((c for c in ('func_' + t, n if n and nc[n] == 1 else None) if c and c in defs), None)
            if tgt:
                votes[sym][tgt] += 1
al = {s: c.most_common(1)[0][0] for s, c in votes.items() if len(c) == 1 or c.most_common(2)[0][1] > c.most_common(2)[1][1]}
old = {}
try:
    old = dict(l.strip().split('=', 1) for l in open(H / 'aliases_convpair.txt') if '=' in l)
except OSError:
    pass
old.update(al)
(H / 'aliases_convpair.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
print('convpair: stubbed names called from converted objects bound to the original target: %d (e.g. %s)' % (len(al), list(al.items())[:4]))
