"""Check value deserialization, references, Lua mutations and change signals."""
import csv, hashlib, json, pathlib, subprocess, sys
root=pathlib.Path(__file__).resolve().parents[3]
exe=root/'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
fixture=root/'rebuild/2008-06/tests/fixtures/p5-values.rbxl'
out=root/'work/2008-06'/sys.argv[1]; out.mkdir(exist_ok=False)
run=subprocess.run([str(exe),'--p5-play','--frames','10','--inspect-place',str(fixture)],cwd=out,capture_output=True,text=True,timeout=90)
assert run.returncode==0 and '[output] VALUES_PASS' in run.stdout, run.stdout+run.stderr
assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in run.stdout
with (out/'place_snapshot.csv').open() as f: rows=list(csv.DictReader(f))
assert len(rows)==1 and [float(rows[0][x]) for x in ('x','y','z')]==[3,4,5]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt={'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),'exe_sha256':sha(exe),'fixture_sha256':sha(fixture),'test_sha256':sha(pathlib.Path(__file__)),'exit':run.returncode,'lua_values_pass':True,'part_position':[3,4,5],'scope':'Behavioral reconstruction; not native parity or complete Value-class coverage.'}
(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('value fixture PASS')
