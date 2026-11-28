"""python srcaddr_alias.py: func_<A> stubs whose body a NATIVE draft already defines under its real name. Converted callers
reference the placeholder (executeInNewThread -> func_005aefa0) while the native object defines
?openState@ScriptContext@RBX@@AAEXXZ, which nothing references, so the linker drops it and the placeholder stays a
`return 0` stub (ScriptContext never opened its Lua state: every -script / Script crashed in lua_newthread(NULL)).
Native sources state the address they recover ("RBX::ScriptContext::openState 005aefa0"). For every func_<A> stub, the
qualified names written next to A in rebuild/2008-06/native-classes/*.cpp are matched to the decorated names the linked
native objects (linkexp/qt.final.rsp) define (?f@C@NS@@ prefix; one definition only); writes aliases_srcaddr.txt
(grow-only) func_<A>=<decorated>. Ctors/dtors/operators are skipped (their decoration differs)."""
import collections, re, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild as rb
stubs, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defs).add(p[1])
want = {s[5:].lower() for s in stubs if re.fullmatch(r'func_[0-9a-fA-F]{8}', s)}
claims = collections.defaultdict(set)   # address -> qualified names
QN = re.compile(r'((?:[A-Za-z_]\w*::)+~?[A-Za-z_]\w*)')
for f in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'):
    for line in f.read_text(errors='replace').splitlines():
        if '//' not in line:
            continue
        c = line.split('//', 1)[1]
        for m in re.finditer(r'\b([0-9a-f]{8})\b', c):
            a = m.group(1)
            if a not in want:
                continue
            before = c[max(0, m.start() - 90):m.start()]
            q = QN.findall(before)
            if q:
                claims[a].add(q[-1])
# defined names of the linked native objects (dropped ones included: that is the point)
natdefs = collections.Counter()
for l in open(H / 'linkexp/qt.final.rsp'):
    o = l.strip().strip('"')
    if o.lower().endswith('.obj') and ('_ns_' in o or 'native' in o or 'candidate' in o):
        try:
            for n, d in rb.coff_externals(Path(o).read_bytes()).items():
                if d and n.startswith('?') and not n.startswith('??'):
                    natdefs[n] += 1
        except OSError:
            pass
byprefix = collections.defaultdict(set)
for n in natdefs:
    m = re.match(r'^(\?[^@?]+@(?:[^@?]+@)*@)', n)
    if m:
        byprefix[m.group(1)].add(n)
al, amb = {}, 0
for a, qs in claims.items():
    qs = {q for q in qs if not any(o != q and o.endswith('::' + q) for o in qs)}   # 'ScriptContext::f' inside 'RBX::ScriptContext::f'
    if len(qs) != 1:
        amb += 1; continue
    parts = next(iter(qs)).split('::')
    if parts[-1].startswith('~') or parts[-1] == parts[-2] or parts[-1].startswith('operator'):
        continue
    pre = '?' + '@'.join(reversed(parts)) + '@@'
    c = byprefix.get(pre, set())
    if len(c) == 1:
        al['func_' + a] = next(iter(c))
old = {}
try:
    old = dict(l.strip().split('=', 1) for l in open(H / 'aliases_srcaddr.txt') if '=' in l)
except OSError:
    pass
old.update(al)
(H / 'aliases_srcaddr.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
print('srcaddr_alias: func_ stubs %d, claimed by a native source %d (ambiguous %d), aliased %d (e.g. %s)'
      % (len(want), len(claims), amb, len(al), list(al.items())[:3]))

# ---- reverse direction: a NAMED stub whose original body is linked as func_<A> -------------------------------------
# Native sources put the original address in the comment block right above a definition
#   // 0061c0e0: the closure pushed by on_index ...
#   int ObjectBridge::callMemberFunction(lua_State* L)
# while the converted original (renamed/obj/0061c0e0.obj, func_0061c0e0) is linked but unreferenced and the bridge's
# call to ?callMemberFunction@ObjectBridge@Lua@RBX@@ is a `return 0` stub (every obj:method() from Lua). Alias
# name -> func_<A> when the name is a stub and func_<A> is defined.
DEF = re.compile(r'^[\w][\w\s\*&:<>,]*?[\s\*&]((?:\w+::)+~?\w+)\s*\(')
claims2 = collections.defaultdict(set)
for f in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'):
    lines = f.read_text(errors='replace').splitlines()
    for i, line in enumerate(lines):
        m = re.match(r'^\s*//\s*([0-9a-f]{8})\b', line)
        if not m:
            continue
        for j in range(i + 1, min(i + 10, len(lines))):
            d = DEF.match(lines[j])
            if d:
                claims2[d.group(1)].add(m.group(1))
                break
            if lines[j].strip() and not lines[j].strip().startswith('//'):
                break
stubnames = collections.defaultdict(list)
for s in stubs:
    m = re.match(r'^\?(\w+)@((?:\w+@)+)@', s)
    if m and not s.startswith('??'):
        q = '::'.join(reversed([x for x in m.group(2).split('@') if x])) + '::' + m.group(1)
        stubnames[q].append(s)
al2 = {}
for q, addrs in claims2.items():
    if len(addrs) != 1:
        continue
    a = next(iter(addrs))
    if 'func_' + a not in defs and not (H / 'renamed/obj' / (a + '.obj')).exists():   # unreferenced bodies leave the map
        continue
    for full in [k for k in stubnames if k == q or k.endswith('::' + q)]:
        for s in stubnames[full]:
            al2[s] = 'func_' + a
old.update(al2)
(H / 'aliases_srcaddr.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
print('srcaddr_alias (named stubs -> linked original): %d (e.g. %s)' % (len(al2), list(al2.items())[:3]))
