"""python callpair.py: bind func_<T> stubs through native functions PROVEN exact against the original. In an exact native
body each relocated call/jmp names a symbol S, and the original calls address T at the same offset, so func_<T> is S.
(The original Lua API at 00612f60 = lua_newthread stayed a stub: executeInNewThread got a NULL thread, sandboxThread
crashed on every -script.) Proven pairs: auto/alias_drop_falsepos.json and aliases_srcaddr.txt (func_A=S). S resolves
through auto/luaunify.json (C++ Lua name -> C name) and the alias files to a name our link defines.
Writes aliases_callpair.txt (grow-only)."""
import collections, json, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import match
stubs, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defs).add(p[1])
pairs = []
for line in json.load(open(H / 'auto/alias_drop_falsepos.json')) if (H / 'auto/alias_drop_falsepos.json').exists() else []:
    pairs.append(line.split('=', 1))
for f in ('aliases_srcaddr.txt',):
    try:
        pairs += [l.strip().split('=', 1) for l in open(H / f) if '=' in l]
    except OSError:
        pass
lu = json.load(open(H / 'auto/luaunify.json')) if (H / 'auto/luaunify.json').exists() else {}
ALIAS = {}
for f in H.glob('aliases*.txt'):
    for l in open(f, errors='replace'):
        if '=' in l:
            k, v = l.strip().split('=', 1); ALIAS.setdefault(k, v)


def resolve(s):
    for _ in range(4):
        if s in defs:
            return s
        s = lu.get(s) or ALIAS.get(s)
        if not s:
            return None
    return None


src = (H / 'codematch.py').read_text(encoding='latin-1')
i, j = src.index('def relsyms'), src.index('def orig_names')
exec(compile(src[i:j], 'codematch_relsyms', 'exec'))
want = {s for _, s in pairs}
found = {}
for l in open(H / 'linkexp/qt.final.rsp'):
    o = l.strip().strip('"')
    if not o.lower().endswith('.obj') or 'renamed' in o:
        continue
    try:
        b = Path(o).read_bytes()
    except OSError:
        continue
    if not any(s.encode('latin-1') in b for s in want if s.encode('latin-1')[:12] in b):
        continue
    rs = relsyms(b)
    for s in want:
        if s in rs and s not in found:
            found[s] = rs[s]
pairs_out = {}
al = {}
for k, s in pairs:
    m = re.fullmatch(r'func_([0-9a-f]{8})', k)
    if not m or s not in found:
        continue
    a = int(m.group(1), 16)
    try:
        code, _, _ = match.target('2008-06', m.group(1))
    except BaseException:
        continue
    for off, sym in found[s].items():
        if off < 1 or off + 4 > len(code) or code[off - 1] not in (0xE8, 0xE9):
            continue
        t = (a + off + 4 + struct.unpack_from('<i', code, off)[0]) & 0xffffffff
        ft = 'func_%08x' % t
        if ft in defs or ft in stubs:
            pairs_out.setdefault(sym, ft)   # every proven (symbol -> original address) pairing, for luaunify
        if ft in stubs:
            r = resolve(sym)
            if r and r != ft:
                al[ft] = r
json.dump(pairs_out, open(H / 'auto/callpair_pairs.json', 'w'), indent=0)
old = {}
try:
    old = dict(l.strip().split('=', 1) for l in open(H / 'aliases_callpair.txt') if '=' in l)
except OSError:
    pass
old.update(al)
(H / 'aliases_callpair.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
print('callpair: proven exact native functions %d (bodies found %d), stub callees bound %d (e.g. %s)' % (len(pairs), len(found), len(al), list(al.items())[:4]))
