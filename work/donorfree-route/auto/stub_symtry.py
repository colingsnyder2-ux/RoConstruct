import json,os,re,subprocess,sys
exec(open('work/donorfree-route/auto/stub_bind.py').read().split('d=json.load')[0])
RC=os.path.abspath('roc.cmd')
done=json.load(open('work/donorfree-route/auto/stub_done_cache.json'))
Q={'005b6ed0':(['SoundServiceFmod.cpp'],['clamp','toFmod']),'005e2490':(['LightingRecovery_005e22c0.cpp'],['setAmbient']),
 '005b8880':(['PlayerNativeReverb','roc_reverb_room'],['']),'00449460':(['AppUnit448_2008Services.cpp'],['']),
 '00639880':(['DebrisService.cpp'],['create']),'004b6890':(['Replicator'],['serialize','Property','Replicator']),'0061f900':(['LuaSignalBridge','Signal'],['TGenericSlotWrapper','??_G'])}
for a,(files,keys) in Q.items():
    for src,(res,obj) in done.items():
        if not any(f.lower() in src.lower() for f in files): continue
        if not os.path.exists(obj): continue
        ss=syms(obj) or []
        cand=[s for s in ss if any(k in s for k in keys)][:25]
        for s in cand:
            r=subprocess.run(['cmd','/c',RC,'native-asm','2008-06',a,'--obj',obj,'--sym',s,'--head','1'],capture_output=True,text=True)
            t=(r.stdout+r.stderr)
            if 'IDENTICAL' in t: print('IDENT',a,s,res,obj,flush=True)
print('done')
