import sys,json,os
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root/'rebuild/2008-06/tests'));import native_check_runner as r
out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105'; guards=json.loads((out/'source-guards.json').read_text())
commands={x['variant']:json.loads(Path(x['command']).read_text()) for x in guards}
def flags(source):
 c=commands[str(source)];return [x for x in c['args'] if x!=c['source'] and not x.lower().startswith('/fo')]
r.compiler_flags=flags
original=r.rebuild.run
def run(tc,tool,args,cwd):
 src=next(x for x in args if x in commands);c=commands[src]; old={k:os.environ.get(k) for k in c['environment']}
 try:
  os.environ.update(c['environment']);return original(tc,tool,args,cwd)
 finally:
  for k,v in old.items():
   if v is None:os.environ.pop(k,None)
   else:os.environ[k]=v
r.rebuild.run=run
for x in guards:
 assert not x['dependency_changes']; assert r.sha(Path(x['source']))==x['recorded_source_sha256']
 folder=out/(Path(x['member']).stem+'-compile'); assert not folder.exists(), 'compile once guard'
 result=r.compile_job(dict(source=x['variant'],checks=[],ranges=[],layouts=[]),folder,r.rebuild.toolchain(21022));print(json.dumps(result))
