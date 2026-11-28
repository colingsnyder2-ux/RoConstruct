import json,subprocess,os,sys
sys.path.insert(0,'C:/Users/colin/RoConstruct/work/donorfree-route/auto')
RC=os.path.abspath('roc.cmd');H='work/donorfree-route/'
rn=json.load(open(H+'renamed/rename.json'))
left=[a for a in open('work/native-client/stub-drafts/left.txt').read().split() if a not in('00472880','004815a0')]
out={}
for a in left:
    o=H+'renamed/obj/%s.obj'%a
    if not os.path.exists(o): continue
    sym=rn.get(a,{}).get('symbol','func_'+a)
    r=subprocess.run(['cmd','/c',RC,'native-asm','2008-06',a,'--obj',os.path.abspath(o),'--sym',sym,'--head','1'],capture_output=True,text=True)
    out[a]=(sym,(r.stdout+r.stderr).strip().replace('\n',' | ')[-170:])
    print(a,out[a],flush=True)
json.dump(out,open(H+'auto/stub_left_check.json','w'))
