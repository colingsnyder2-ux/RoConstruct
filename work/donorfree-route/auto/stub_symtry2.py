import json,os,subprocess,sys
exec(open('work/donorfree-route/auto/stub_bind.py').read().split('d=json.load')[0])
RC=os.path.abspath('roc.cmd')
done=json.load(open('work/donorfree-route/auto/stub_done_cache.json'))
Q={'005d8540':['visitChildren','visitDescendants','forEach'],'0061c2c0':['LuaArguments','getInstance','pushInstance','toInstance']}
seen=set()
for a,keys in Q.items():
    for src,(res,obj) in done.items():
        if not os.path.exists(obj): continue
        try: ss=syms(obj) or []
        except Exception: continue
        for s in ss:
            if any(k in s for k in keys) and (a,s) not in seen:
                seen.add((a,s))
                r=subprocess.run(['cmd','/c',RC,'native-asm','2008-06',a,'--obj',obj,'--sym',s,'--head','1'],capture_output=True,text=True)
                if 'IDENTICAL' in r.stdout: print('IDENT',a,s,res,obj,flush=True)
print('done')
