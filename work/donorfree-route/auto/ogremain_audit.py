import json,os,re,sys,collections,glob; sys.path.insert(0,'../..')
from roc import rebuild as rb
sys.path.insert(0, '.')
import defined_now as dn
runs={}
def source_of(q):
    m=re.search(r'([0-9a-f]{8})_unit[-_](\d{3})',os.path.basename(q))
    if not m: return ''
    rid,u=m.group(1),int(m.group(2))
    if rid not in runs:
        g=glob.glob('../2008-06/native-check-runs/*-%s/results.json'%rid)
        try: runs[rid]=json.load(open(g[0])) if g else []
        except Exception: runs[rid]=[]
    r=runs[rid]
    return r[u].get('source','') if isinstance(r,list) and u<len(r) else ''
exp=set()
for l in open('linkexp/qt.final.rsp'):
    q=l.strip().strip('"')
    if q.lower().endswith('.lib') and 'rgmain' in q.lower(): exp |= {x[6:] for x in dn.lib_symbols(q) if x.startswith('__imp_')}
og={}; odef=collections.Counter(); oref=set()
for l in open('linkexp/qt.final.rsp'):
    q=l.strip().strip('"')
    if not q.lower().endswith('.obj') or not os.path.exists(q): continue
    ext=rb.coff_externals(open(q,'rb').read())
    if os.path.basename(source_of(q)).startswith('OgreMain'): og[q]={n for n,d in ext.items() if d}
    else:
        for n,d in ext.items(): (odef.update([n]) if d else oref.add(n))
print('OgreMain objects in link:',len(og))
need=collections.defaultdict(list)
for q,ds in og.items():
    for n in ds:
        if n in oref and n not in exp and not odef[n]: need[os.path.basename(source_of(q))].append(n)
print('unique non-exported names others need:',sum(map(len,need.values())))
for k,v in sorted(need.items(),key=lambda x:-len(x[1]))[:12]: print(len(v),k,[x[:70] for x in v[:3]])
json.dump({'objs':sorted(os.path.basename(q) for q in og),'need':need},open('auto/ogremain_objs.json','w'),indent=0)
