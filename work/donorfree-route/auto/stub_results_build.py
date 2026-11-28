import json,os,collections
R='C:/Users/colin/RoConstruct/'
BS=chr(92)
d=json.load(open('auto/stub_bindings.json'))
inq=set(os.path.normcase(l.strip()) for l in open('linkexp/qt_results.txt') if l.strip())
have=set()
for f in inq:
    try:j=json.load(open(f))
    except Exception: continue
    for r in (j if isinstance(j,list) else j['results']):
        if r.get('status')=='complete': have.add(os.path.normcase(r['source']))
ent={};c=collections.Counter()
for e in d:
    for k in e['cands']:
        if k['kind']!='autorecover' or not k.get('obj'): continue
        s=os.path.normcase(k['path'].replace('/',BS))
        a=int(k['addr'],16)
        if s in have: c['already']+=1;continue
        if 0x7c0000<=a<0x800000: c['quarantine_range']+=1;continue
        ent[s]={'source':k['path'].replace('/',BS),'status':'complete','object':k['obj'],'stub':e['stub'],'addr':k['addr']}
print(c,len(ent))
os.makedirs(R+'work/native-client/stub-results',exist_ok=True)
json.dump([{k:v for k,v in x.items() if k in('source','status','object')} for x in ent.values()],open(R+'work/native-client/stub-results/autorecover-bound.json','w'),indent=1)
json.dump(list(ent.values()),open(R+'work/native-client/stub-results/autorecover-bound.meta.json','w'),indent=1)
