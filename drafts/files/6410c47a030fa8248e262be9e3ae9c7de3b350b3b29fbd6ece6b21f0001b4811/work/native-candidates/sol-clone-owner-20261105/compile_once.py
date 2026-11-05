from pathlib import Path
import json,hashlib,importlib.util,os,subprocess,sys
ROOT=Path.cwd();sys.path.insert(0,str(ROOT));out=ROOT/'work/2008-06/shared-layouts/sol-clone-owner-20261105';src=ROOT/'work/native-candidates/sol-clone-owner-20261105/glue_instance_core.cpp'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
cp=ROOT/'rebuild/2008-06/out/RbxgsApp/layer-glue/glue_instance_core.command.json';c=json.loads(cp.read_text());assert sha(c['source'])==c['source_sha256'];assert all(sha(p)==h for p,h in c['dependencies'].items())
text=Path(c['source']).read_bytes();needle=b'boost::shared_ptr<Instance> Instance::clone()';assert text.count(needle)==1
src.write_bytes(text.replace(needle,b'inline '+needle));(out/'actual-command.json').write_text(json.dumps(c,indent=2))
spec=importlib.util.spec_from_file_location('runner',ROOT/'rebuild/2008-06/tests/native_check_runner.py');r=importlib.util.module_from_spec(spec);spec.loader.exec_module(r)
args=[a for a in c['args'] if not a.lower().startswith(('/fo','/fd')) and a!=c['source'] and a!='/showIncludes'];r.compiler_flags=lambda source:args
original_run=r.rebuild.run
def exact_run(tc,tool,argv,cwd,timeout=None):
 env=r.rebuild.env(tc);env.update(c['environment']);command=[c['compiler']]+argv
 (out/'executed-command.json').write_text(json.dumps({'command':command,'environment':c['environment'],'compiler_sha256':sha(c['compiler']),'cwd':str(cwd),'original_command_sha256':sha(cp),'original_object_sha256':sha(cp.with_suffix('').with_suffix('.obj'))},indent=2))
 p=subprocess.run(command,cwd=cwd,env=env,capture_output=True,text=True,errors='replace',timeout=180);return p.returncode,p.stdout+p.stderr
r.rebuild.run=exact_run
assert not (out/'unit-000').exists(),'one compile only'
result=r.compile_job({'source':str(src),'checks':[],'ranges':[],'layouts':[]},out/'unit-000',r.rebuild.toolchain(21022));print(json.dumps(result,indent=2)[:1400])
