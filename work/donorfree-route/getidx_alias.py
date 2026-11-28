"""python getidx_alias.py: ServiceProvider::getClassIndex<T>() stubs (return 0: every such service shared slot 0 of
serviceArray, so a newly created JointsService/Teams/SpawnerService overwrote Workspace and find<Workspace> handed
ScriptContext::openState a foreign object). The original bodies exist as converted code but are unnamed: each one is
the function whose code references its own call_once flag ?flag@?1???$getClassIndex@<T>@ServiceProvider@RBX@@SAIXZ@4JA.
For every stubbed getClassIndex<T> (any access spelling), find the converted object (renamed/obj/<A>.obj) whose main
body relocates that flag and alias the stub name to func_<A>. Writes aliases_getidx.txt (grow-only)."""
import collections, json, re, struct, sys
from pathlib import Path
H = Path(__file__).parent
src = (H / 'codematch.py').read_text(encoding='latin-1')
exec(compile(src[src.index('def relsyms'):src.index('def orig_names')], 'relsyms', 'exec'))
stubs, defs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else defs).add(p[1])
want = {}   # T mangled -> [stub names]
for s in stubs:
    m = re.match(r'^\?\?\$getClassIndex@(.+)@ServiceProvider@RBX@@[CS]AIXZ$', s)
    if m:
        want.setdefault(m.group(1), []).append(s)
flag_of = {'?flag@?1???$getClassIndex@%s@ServiceProvider@RBX@@SAIXZ@4JA' % t: t for t in want}
flag_of.update({'?flag@?1???$getClassIndex@%s@ServiceProvider@RBX@@CAIXZ@4JA' % t: t for t in want})
al = {}
for o in sorted((H / 'renamed/obj').glob('*.obj')):
    X = o.stem
    if not re.fullmatch(r'[0-9a-f]{8}', X):
        continue
    b = o.read_bytes()
    if b'getClassIndex' not in b:
        continue
    body = relsyms(b).get('func_' + X) or {}
    hits = {flag_of[s] for s in body.values() if s in flag_of}
    if len(hits) == 1 and len(body) <= 6 and 'func_' + X in defs:   # a small function using exactly one such flag
        t = hits.pop()
        for s in want[t]:
            al.setdefault(s, 'func_' + X)
af = H / 'aliases_getidx.txt'
old = dict(l.strip().split('=', 1) for l in open(af) if '=' in l) if af.exists() else {}
old.update(al)
af.write_text(''.join('%s=%s\n' % kv for kv in sorted(old.items())))
print('getidx_alias: stubbed getClassIndex<T> %d classes, bound to their original body %d (e.g. %s)' % (len(want), len(al), list(al.items())[:2]))
