import json,os,re
os.chdir(r'C:\Users\colin\RoConstruct')
ff=json.load(open('work/native-client/layout/function-files.json'))
ex=set()
for f in os.listdir('src/2008-06'):
    if f.endswith('.cpp') and len(f)==12:
        try:
            if open('src/2008-06/'+f,errors='replace').readline().startswith('// from server: 100%'): ex.add(f[:8])
        except Exception: pass
na=set(json.load(open('work/donorfree-route/renamed/native_addrs.json')))
cm=set()
for d in ('native-classes','native-findings','native-findings-new','native-findings-mew'):
    p='rebuild/2008-06/'+d
    if os.path.isdir(p):
        for f in os.listdir(p):
            if f.endswith('.cpp'):
                try: cm|=set(re.findall(r'\b00[4-7][0-9a-f]{5}\b',open(os.path.join(p,f),errors='replace').read()))
                except Exception: pass
tot=set(ff); rest=tot-ex-na-cm
out=['registry functions %d' % len(tot), 'exact source %d' % len(ex&tot), 'native-named (no exact) %d' % len(((na|cm)&tot)-ex),
     'NO code anywhere %d' % len(rest),
     '  library-named %d' % sum(1 for a in rest if re.search(r'XTP|Ogre|boost|lua|png|zlib|inflate|deflate|Rak|G3D|Scintilla|jpeg', (ff[a] or {}).get('name') or '')),
     '  unnamed func_ %d' % sum(1 for a in rest if ((ff[a] or {}).get('name') or 'func_').startswith('func_'))]
open('work/donorfree-route/auto/coverage.txt','w').write('\n'.join(out)); print('\n'.join(out))
import collections
def kind(a):
    r = ff[a] or {}; n = r.get('name') or ''; z = r.get('size') or 0
    if z and z <= 8: return 'tiny <=8 B (thunk/ret/jmp)'
    if n.startswith(('??_G', '??_E')): return 'compiler deleting-dtor'
    if n.startswith(('??_R', '??_7', '??__E', '??__F', '__ehhandler', '__unwind', '__catch')): return 'compiler EH/RTTI/init'
    if '?$' in n.split('@@')[0] or n.startswith('??$'): return 'template instance'
    if z and z <= 32: return 'small 9-32 B'
    return 'real code >32 B' if z else 'unknown size'
c = collections.Counter(kind(a) for a in rest)
sz = collections.Counter(kind(a) for a in rest for _ in [0])
bytes_ = collections.Counter()
for a in rest: bytes_[kind(a)] += (ff[a] or {}).get('size') or 0
print('--- the %d no-code functions by kind (count, total bytes)' % len(rest))
for k, v in c.most_common(): print('  %-30s %6d  %8d B' % (k, v, bytes_[k]))
