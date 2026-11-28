"""Run the full-feature R7 regression without touching unrelated browser windows."""
import json
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import scripttest
root = Path(__file__).resolve().parents[1]
scripttest.ieclean.clean = lambda *args: None
exe = sys.argv[1] if len(sys.argv) > 1 else str(root / 'run/RobloxQT.exe')
result = scripttest.run(exe, (root / 'auto/repro/ff.lua').read_text(), wait=60)
print(json.dumps(result, indent=2))
sys.exit(0 if 'R7' in result and not result['R7']['fail'] else 1)
