import json,os,subprocess
exec(open('work/donorfree-route/auto/stub_bind.py').read().split('d=json.load')[0])
RC=os.path.abspath('roc.cmd')
done=json.load(open('work/donorfree-route/auto/stub_done_cache.json'))
seen=set()
for src,(res,obj) in done.items():
    if not os.path.exists(obj): continue
    try: ss=syms(obj) or []
    except Exception: continue
    for s in ss:
        if 'visitDescendents' in s and 'bind_t' in s and s not in seen:
            seen.add(s)
            r=subprocess.run(['cmd','/c',RC,'native-asm','2008-06','005d8540','--obj',obj,'--sym',s,'--head','1'],capture_output=True,text=True)
            t=r.stdout
            print('IDENT' if 'IDENTICAL' in t else 'no',s[:110],obj if 'IDENTICAL' in t else t.strip().split('\n')[-1][-70:],flush=True)
print('done',len(seen))
