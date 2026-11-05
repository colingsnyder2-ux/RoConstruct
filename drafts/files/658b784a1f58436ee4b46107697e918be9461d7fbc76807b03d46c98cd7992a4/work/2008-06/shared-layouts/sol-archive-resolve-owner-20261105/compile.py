import json,sys,importlib.util
from pathlib import Path
R=Path.cwd();sys.path.insert(0,str(R));O=R/'work/2008-06/shared-layouts/sol-archive-resolve-owner-20261105';c=json.loads((O/'actual-command.json').read_text())
spec=importlib.util.spec_from_file_location('runner',R/'rebuild/2008-06/tests/native_check_runner.py');runner=importlib.util.module_from_spec(spec);spec.loader.exec_module(runner)
flags=[a for a in c['args'] if not a.startswith('/Fo') and a!=c['source'] and a!='/showIncludes']
runner.compiler_flags=lambda source:flags
original_env=runner.rebuild.env
runner.rebuild.env=lambda tc:dict(original_env(tc),**c['environment'])
original_run=runner.rebuild.run
def run(tc,tool,args,cwd,timeout=None):
 assert str(tc['cl'])==c['compiler'];assert '/showIncludes' in args
 (O/'executed-command.json').write_text(json.dumps(dict(command=[str(tc['cl'])]+args,environment=runner.rebuild.env(tc)),indent=2))
 return original_run(tc,tool,args,cwd,timeout)
runner.rebuild.run=run
job=dict(source=str(R/'work/native-candidates/sol-archive-resolve-owner-20261105/SerializerV2.cpp'),checks=[],ranges=[],layouts=[])
r=runner.compile_job(job,O/'unit-000',runner.rebuild.toolchain(21022));print(json.dumps(r,default=str)[:1000])
