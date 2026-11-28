import json,os,re,subprocess,collections
R=os.getcwd();RC=os.path.abspath('roc.cmd')
reg=json.load(open('work/2008-06/identity-registry.json'))
done={os.path.normcase(k):v for k,v in json.load(open('work/donorfree-route/auto/stub_done_cache.json')).items()}
left=['00449460','004b6890','004b6ab0','005aefa0','005b6ed0','005b8880','005e2490','00657c00','0061f900','0061fac0','00639880','006426f0','0063b5c0','00420900','00420910','0042c2b0','005f7000','006a14c6','006a1f8a','006d0e90','006e9360','0078c560','007a6380','007a64f0','007a7c40','008042e8']
t=open('C:/Users/colin/AppData/Local/Temp/claude/6c3f7ef10573ab06/1e7282be-e085-4f19-8a5f-044c66309bb3/tasks/bye4ngcip.output').read()
cand=collections.defaultdict(list)
for l in t.split('\n'):
    m=re.match(r'([0-9a-f]{8}) (\[.*\])',l)
    if m: cand[m.group(1)]=eval(m.group(2))
for a in left:
    nm=reg.get(a,{}).get('name','?')
    for p in cand.get(a,[]):
        if not p.endswith('.cpp') or 'native-classes' not in p.replace(chr(92),'/'): continue
        full=os.path.normcase(os.path.join(R,p.replace('/',chr(92))))
        d=done.get(full)
        if not d: continue
        r=subprocess.run(['cmd','/c',RC,'native-asm','2008-06',a,'--obj',d[1],'--sym',nm,'--head','1'],capture_output=True,text=True)
        t2=(r.stdout+r.stderr).strip().replace('\n',' | ')
        if 'IDENTICAL' in t2: print('IDENT',a,nm[:50],p,d[0],flush=True)
        else: print('no',a,p[-50:],t2[-90:],flush=True)
