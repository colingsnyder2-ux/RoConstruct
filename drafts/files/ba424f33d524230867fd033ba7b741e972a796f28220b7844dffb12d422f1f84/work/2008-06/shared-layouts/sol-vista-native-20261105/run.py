from pathlib import Path
import importlib.util,json,sys
R=Path.cwd();F=R/'work/2008-06/shared-layouts/sol-vista-native-20261105'
spec=importlib.util.spec_from_file_location('vista_runner',R/'rebuild/2008-06/tests/native_check_runner.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
flags=json.loads((F/'profile.json').read_text())['flags'];m.compiler_flags=lambda source:flags
sys.argv=['native_check_runner.py','run',str(F/'batch.json'),'--workers','1'];m.main()
