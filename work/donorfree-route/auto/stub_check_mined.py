import subprocess,os,json
RC=os.path.abspath('roc.cmd')
left=[a for a in open('work/native-client/stub-drafts/left.txt').read().split()]
done={f[8:16] for f in os.listdir('work/native-client/stub-drafts') if f.startswith('StubDD') and f.endswith('.cpp')}|{'00403610','004b4640','0063b5c0','006426f0','007fb0c0','008014e0'}
out={}
for a in left:
    if a in done or not os.path.exists('src/2008-06/%s.cpp'%a): continue
    r=subprocess.run(['cmd','/c',RC,'check','2008-06',a],capture_output=True,text=True)
    t=(r.stdout+r.stderr).strip().replace('\n',' | ')
    out[a]=t[-260:];print(a,out[a],flush=True)
json.dump(out,open('work/donorfree-route/auto/stub_check_mined.json','w'))
