from pathlib import Path
import sys,json,hashlib,os,subprocess,struct
from collections import Counter
R=Path.cwd();sys.path.insert(0,str(R));from roc import libs,match
F=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105';V=R/'work/native-candidates/sol-filesystem-owner-20261105';V.mkdir(exist_ok=True,parents=True)
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(n,v):(F/n).write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8')
c=json.loads((R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/FileSystem.command.json').read_text());source=Path(c['source']);assert sha(source)==c['source_sha256']
drift=[p for p,h in c['dependencies'].items() if not Path(p).exists() or sha(p)!=h];save('dependency-check.json',{'changed':drift});assert not drift
text=source.read_text();keys=['VistaAPIs::~VistaAPIs()', 'HRESULT VistaAPIs::GetIntegrity(', 'VistaAPIs::VistaAPIs()', 'HRESULT VistaAPIs::SHGetKnownFolderPath(', 'std::string FileSystem::getUserAppDataDirectory(']
for k in keys:
 assert text.count(k)==1
 text=text.replace(k,'inline '+k)
s=V/'FileSystem.cpp';s.write_text(text,encoding='utf-8');args=[('/Fo'+str(F/'FileSystem.obj')) if a.startswith('/Fo') else str(s) if a==c['source'] else a for a in c['args']]
env=os.environ.copy();env.update(c['environment']);env['PATH']=str(Path(c['compiler']).parents[2]/'Common7/IDE')+os.pathsep+str(Path(c['compiler']).parent)+os.pathsep+env.get('PATH','')
save('compile-command.json',dict(c, args=args,source=str(s),source_sha256=sha(s)))
p=subprocess.run([c['compiler'],*args],cwd=F,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);(F/'compile.log').write_text(p.stdout.decode(errors='replace'));save('compile.json',{'exit':p.returncode,'distinct_compiles':1});assert p.returncode==0
archive=R/'work/2008-06/shared-layouts/sol-cumulative-links-20261105/member-step-1/linked.lib';assert sha(archive)=='8ef9dbeb5d4f5bc7699aa28e662638e286e431086b5b6a0229aaa1237ca1d580'
ms=list(libs.archive_members(archive));name,old=next((n,b) for n,b in ms if Path(n).name=='FileSystem.obj');new=(F/'FileSystem.obj').read_bytes()
def funcs(raw):return {n:(b,sorted(r)) for n,b,r in match.coff_functions(raw)}
a,b=funcs(old),funcs(new);removed=set(a)-set(b);changed=[n for n in a.keys()&b.keys() if a[n]!=b[n]];save('body-comparison.json',{'removed':sorted(removed),'changed':changed,'retained':len(a.keys()&b.keys()),'new':sorted(b.keys()-a.keys())})
print('removed',len(removed),'changed',len(changed),'retained',len(a.keys()&b.keys()))
