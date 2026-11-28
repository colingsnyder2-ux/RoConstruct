import json, os, re, sys, collections
os.chdir(r'C:\Users\colin\RoConstruct'); sys.path.insert(0, '.')
from roc import match
fx = match._functions('2008-06')   # addr -> row with 'kind', 'size'
ex = set()
for f in os.listdir('src/2008-06'):
    if f.endswith('.cpp') and len(f) == 12:
        try:
            if open('src/2008-06/' + f, errors='replace').readline().startswith('// from server: 100%'): ex.add(f[:8])
        except Exception: pass
cm = set()
for d in ('native-classes', 'native-findings', 'native-findings-new', 'native-findings-mew'):
    p = 'rebuild/2008-06/' + d
    if os.path.isdir(p):
        for f in os.listdir(p):
            if f.endswith('.cpp'):
                try: cm |= set(re.findall(r'\b00[4-7][0-9a-f]{5}\b', open(os.path.join(p, f), errors='replace').read()))
                except Exception: pass
cm |= set(json.load(open('work/donorfree-route/renamed/native_addrs.json')))
kinds = collections.Counter(r.get('kind') for r in fx.values())
print('analyzer: %d functions, kinds %s' % (len(fx), dict(kinds)))
code = {a for a, r in fx.items() if r.get('kind') == 'code'}
rest = code - ex - cm
sz = lambda a: fx[a].get('size') or 0
print('real code %d | exact %d | native-named %d | REAL CODE WITH NO CODE ANYWHERE %d (%.0f KB)' % (
    len(code), len(code & ex), len((code & cm) - ex), len(rest), sum(sz(a) for a in rest) / 1024))
b = collections.Counter('<=16 B' if sz(a) <= 16 else '17-64 B' if sz(a) <= 64 else '65-256 B' if sz(a) <= 256 else '>256 B' for a in rest)
print('  by size:', dict(b))
