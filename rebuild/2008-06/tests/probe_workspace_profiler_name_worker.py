"""Combine frozen diagnostic candidates; output must never be run."""
import hashlib,json,re,subprocess,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts';old=out/'workspace-profiler-callers-worker';work=out/'workspace-profiler-name-worker';work.mkdir(parents=True,exist_ok=True);proof=root/'work/2008-06/shared-layouts'
base=json.loads((proof/'workspace-profiler-callers-worker.json').read_text());name=json.loads((proof/'workspace-name-provider-integrated.json').read_text());provider=out/'workspace-name-provider-integrated/WorkspaceClassName.obj';source=root/'rebuild/2008-06/native-classes/WorkspaceClassName.cpp';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
assert sha(provider)==name['object_sha256'] and sha(source)==name['source_sha256'] and sha(old/'replaced.lib')==base['archive_sha256']
args=[]
for line in (old/'candidate.rsp').read_text().splitlines():
 arg=line.strip().strip(chr(34))
 if arg.upper().startswith('/OUT:'):arg='/OUT:'+str(work/'candidate.exe')
 elif arg.upper().startswith('/MAP:'):arg='/MAP:'+str(work/'candidate.map')
 args.append(arg)
args.append(str(provider));rsp=work/'candidate.rsp';rsp.write_text('\n'.join(subprocess.list2cmdline([a]) for a in args)+'\n');code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);(work/'candidate.log').write_text(log)
errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)\b',x)];symbols=sorted(set(m.group(1) for x in errors if (m:=re.search(r'unresolved external symbol .*? \((\?[^)]+)\)',x))))
result={'scope':'Frozen mixed-ABI diagnostic, nonexact profiler and writer; never execute.','baseline_receipt_sha256':sha(proof/'workspace-profiler-callers-worker.json'),'provider_sha256':sha(provider),'source_sha256':sha(source),'archive_sha256':sha(old/'replaced.lib'),'baseline_errors':base['candidate_errors'],'candidate_errors':errors,'unique_unresolved':symbols,'exit':code}
(proof/'workspace-profiler-name-worker.json').write_text(json.dumps(result,indent=2)+'\n');print('baseline',len(base['candidate_errors']),'candidate',len(errors),'unique unresolved',len(symbols));print('\n'.join(symbols))
