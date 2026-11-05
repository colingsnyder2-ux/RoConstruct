from pathlib import Path
import json,sys,os,subprocess,hashlib,struct
R=Path.cwd();sys.path.insert(0,str(R));from roc import libs,match
F=R/'work/2008-06/shared-layouts/sol-vista-final-20261105';V=R/'work/native-candidates/sol-vista-final-20261105'
F.mkdir(parents=True,exist_ok=True);V.mkdir(parents=True,exist_ok=True)
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(n,v):(F/n).write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8')
c=json.loads((R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/FileSystem.command.json').read_text());assert sha(c['source'])==c['source_sha256'];assert all(sha(p)==h for p,h in c['dependencies'].items())
t=(R/'work/native-candidates/sol-filesystem-owner-20261105/FileSystem.cpp').read_text()
key='inline HRESULT VistaAPIs::GetIntegrity(';start=t.index(key);a=t.index('{',start);b=a+1;depth=1
while depth:
 if t[b]=='{':depth+=1
 elif t[b]=='}':depth-=1
 b+=1
t=t[:start]+t[b:]
for key in ['inline VistaAPIs::~VistaAPIs()', 'inline VistaAPIs::VistaAPIs()', 'inline HRESULT VistaAPIs::SHGetKnownFolderPath(']:
 assert t.count(key)==1;t=t.replace(key,key.replace('inline ','__forceinline ',1))
s=V/'FileSystem.cpp';s.write_text(t,encoding='utf-8');args=[('/Fo'+str(F/'FileSystem.obj')) if a.startswith('/Fo') else str(s) if a==c['source'] else a for a in c['args']]
env=os.environ.copy();env.update(c['environment']);env['PATH']=str(Path(c['compiler']).parents[2]/'Common7/IDE')+os.pathsep+str(Path(c['compiler']).parent)+os.pathsep+env.get('PATH','')
save('compile-command.json',dict(c,args=args,source=str(s),source_sha256=sha(s),isolation_note='Immutable canonical command replay; only source/output substitutions. Runner synthesizes incompatible flags.'))
p=subprocess.run([c['compiler'],*args],cwd=F,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);(F/'compile.log').write_text(p.stdout.decode(errors='replace'));save('compile.json',{'exit':p.returncode,'distinct_compiles':1});assert p.returncode==0
archive=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib';assert sha(archive)=='0c597337028cf2cda5addf6ededafd11d546ec6205720401a5e1c166ab1b0836'
old=next(b for n,b in libs.archive_members(archive) if Path(n).name=='FileSystem.obj');new=(F/'FileSystem.obj').read_bytes()
def funcs(raw):return {n:(b,sorted(r)) for n,b,r in match.coff_functions(raw)}
a,b=funcs(old),funcs(new)
save('body-comparison.json',{'baseline_member_sha256':hashlib.sha256(old).hexdigest(),'retained':len(a.keys()&b.keys()),'changed':[n for n in a.keys()&b.keys() if a[n]!=b[n]],'removed':sorted(a.keys()-b.keys()),'new':sorted(b.keys()-a.keys()),'remaining_vista':[n for n in b if 'VistaAPIs' in n]})
print((F/'body-comparison.json').read_text())
