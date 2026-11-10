"""Run the StandardVerbs indirect-call ABI probe against the EditSelectionVerb provider unit."""
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
PROBE = ROOT / 'work/native-candidates/standard-verbs-iat-abi-20261106/probe_indirect_call_abi.py'
RUN = 'work/2008-06/native-check-runs/20261106-121512-f7611e2e'
SYMBOL = '??0EditSelectionVerb@RBX@@IAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVDataModel@1@@Z'

result = subprocess.run([sys.executable, str(PROBE), '--object', RUN + '/unit-000/candidate.obj',
                         '--receipt', str(HERE / 'bindings.json'), '0057e730:' + SYMBOL],
                        cwd=str(ROOT), capture_output=True, text=True)
print(result.stdout)
if result.stderr:
    print(result.stderr, file=sys.stderr)
raise SystemExit(result.returncode)
