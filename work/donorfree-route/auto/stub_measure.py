import json,os,glob,re,collections
R='C:/Users/colin/RoConstruct/'
H=R+'work/donorfree-route/'
rs=json.load(open(H+'auto/real_stubs.json'))
reg=json.load(open(R+'work/2008-06/identity-registry.json'))
n2a=collections.defaultdict(set)
for a,v in reg.items(): n2a[v['name']].add(a)
bc=json.load(open(H+'auto/bindcheck.json'))['stubs']
for n,a in bc: n2a[n].add(a)
fa={}
for n in rs:
    m=re.fullmatch(r'_?(?:func|fn)_([0-9a-f]{8})',n) or re.fullmatch(r'@fn_([0-9a-f]{8})@\d+',n)
    if m:n2a[n].add(m.group(1))
stub_addr={n:sorted(n2a[n]) for n in rs if n in n2a}
# sources
nat={}
for p in glob.glob(R+'rebuild/2008-06/native-classes/*.cpp'):
    m=re.match(r'AutoRecover_([0-9a-f]{8})\.cpp',os.path.basename(p))
    if m:nat.setdefault(m.group(1),[]).append(p)
src={os.path.basename(p)[:-4]:p for p in glob.glob(R+'src/2008-06/*.cpp')}
res=json.load(open(H+'renamed/results.json'))
linked={os.path.basename(r['object'])[:-4] for r in res}
objs={f[:-4] for f in os.listdir(H+'renamed/obj') if f.endswith('.obj')}
# native-check complete results by source
done={}
for f in glob.glob(R+'work/2008-06/native-check-runs/*/results.json'):
    try: j=json.load(open(f))
    except Exception: continue
    for r in (j if isinstance(j,list) else j.get('results',[])):
        if r.get('status')=='complete' and r.get('object') and os.path.exists(r['object']):
            done[os.path.normcase(r['source'])]=(f,r['object'])
json.dump({k:v for k,v in done.items()},open(H+'auto/stub_done_cache.json','w'))
out=[];cat=collections.Counter()
for n,addrs in stub_addr.items():
    e={'stub':n,'addrs':addrs,'cands':[]}
    for a in addrs:
        if a in objs: e['cands'].append({'kind':'renamed_obj','addr':a,'obj':H+'renamed/obj/%s.obj'%a,'linked':a in linked})
        if a in src: e['cands'].append({'kind':'src','addr':a,'path':src[a]})
        for p in nat.get(a,[]):
            d=done.get(os.path.normcase(p.replace('/', chr(92))))
            e['cands'].append({'kind':'autorecover','addr':a,'path':p,'result':d[0] if d else None,'obj':d[1] if d else None})
    out.append(e)
    for c in e['cands']: cat[c['kind']+('_linked' if c.get('linked') else '')+('_done' if c.get('obj') else '')]+=1
    cat['stubs_with_cand' if e['cands'] else 'stubs_no_cand']+=1
json.dump(out,open(H+'auto/stub_candidates.json','w'),indent=0)
print(len(stub_addr),cat)
