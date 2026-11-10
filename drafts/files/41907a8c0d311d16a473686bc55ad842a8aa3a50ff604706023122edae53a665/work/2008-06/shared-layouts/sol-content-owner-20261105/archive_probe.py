from pathlib import Path
import sys,json,hashlib,struct,subprocess,os
ROOT=Path.cwd(); sys.path.insert(0,str(ROOT)); from roc import libs,match
F=ROOT/'work/2008-06/shared-layouts/sol-content-owner-20261105'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(n,v):(F/n).write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8')
archive=ROOT/'rebuild/2008-06/out/RbxgsApp/linked/linked.lib'; manifest=ROOT/'work/2008-06/shared-layouts/sol-snapshot-20261105/rbxgs-app-inputs.json'
archive_hash=sha(archive); members=list(libs.archive_members(archive)); baseline=ROOT/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/ContentProvider.obj'
hits=[(n,r) for n,r in members if Path(n).name=='ContentProvider.obj']; assert len(hits)==1; name,raw=hits[0]; assert raw==baseline.read_bytes()
comparison=json.loads((F/'comparison.json').read_text()); removed=set(comparison['removed_bodies']+comparison['removed_data']); providers={}; consumers=[]
for member,data in members:
 if member==name:continue
 sections,symbols,defs,_=match._coff_data_index(data)
 for n in removed & set(defs):providers.setdefault(n,[]).append(member)
 refs=set()
 for sec in sections:
  for i in range(sec[7]):
   off,idx,kind=struct.unpack_from('<IIH',data,sec[5]+10*i); n=symbols[idx][0]
   if n in removed:refs.add(n)
 if refs:consumers.append({'member':member,'symbols':sorted(refs)})
used=set(n for r in consumers for n in r['symbols']); missing=used-set(providers)
proof=dict(scope='Entire CURRENT RbxgsApp archive only; partial final diagnostic inputs. Same-name providers are availability evidence, not selected link or ABI proof.',archive_sha256=archive_hash,input_manifest_sha256=sha(manifest),actual_member=name,baseline_member_identity=True,members=len(members),removed_bodies=len(comparison['removed_bodies']),removed_data=len(comparison['removed_data']),consumers=consumers,alternate_providers=providers,referenced_without_alternate=sorted(missing))
save('archive-audit.json',proof)
print('members',len(members),'consumer members',len(consumers),'referenced removed',len(used),'without alternate',len(missing)); print(sorted(missing))
native=ROOT/'work/2008-06/native-check-runs/20261105-122951-04c3d3fa/unit-000/candidate.obj'
assert sha(native)=='25cced223266b6af736734dea98ed134216d710c371edc24169224850d6b0860'
nraw=native.read_bytes(); native_symbols={n:(b,r) for n,b,r in match.coff_functions(nraw)}
load=[n for n in native_symbols if n.startswith('?load@ContentProvider')]; assert len(load)==1 and missing==set(load)
n=load[0]; target,refs,_=match.target('2008-06','005628e0');body,relocs=native_symbols[n]
assert match.exact_match(target,refs,body,relocs) and set(refs)<=set(relocs)
data_ok,errors=match.data_check('2008-06','005628e0',target,match.coff_data_refs(nraw,n));assert not errors
save('native-provider.json',dict(object=str(native),object_sha256=sha(native),symbol=n,original='005628e0',size=len(body),code_exact=True,data_errors=errors,scope='Existing native object reused; 4 indirect calls remain strict-runner blockers; static contracts are separate evidence; no selected/runtime claim'))
c=json.loads((F/'canonical-command.json').read_text()); librarian=Path(c['compiler']).with_name('lib.exe'); target=F/'linked.lib'; env=os.environ.copy();env['PATH']=str(Path(c['compiler']).parents[2]/'Common7/IDE')+os.pathsep+str(librarian.parent)+os.pathsep+env.get('PATH','')
args=['/nologo','/OUT:'+str(target),str(archive),'ContentProvider.obj'];save('librarian-command.json',dict(tool=str(librarian),tool_sha256=sha(librarian),args=args,cwd=str(F)))
p=subprocess.run([str(librarian),*args],cwd=F,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);(F/'librarian.log').write_text(p.stdout.decode(errors='replace'),encoding='utf-8');assert p.returncode==0
from collections import Counter
def inv(ms):return Counter((n,hashlib.sha256(r).hexdigest()) for n,r in ms)
before=inv(members); after=inv(libs.archive_members(target));assert list((before-after).elements())==[(name,sha(baseline))];assert list((after-before).elements())==[(name,sha(F/'ContentProvider.obj'))];assert sha(archive)==archive_hash
save('replacement.json',dict(original_archive_sha256=archive_hash,replacement_archive_sha256=sha(target),unchanged_other_members=len(members)-1,changed_member=name,normal_librarian=True,scope='inactive archive; final diagnostic selected link and complete external consumers remain unproven'))
