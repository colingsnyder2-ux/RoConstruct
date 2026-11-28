"""python ttdq.py "<cdb commands; separated by ;>" [RUN]: replay a TTD trace headless (cdb -z) and print the output.
Default trace: newest auto/ttd/*.run. Addresses: use linkexp/qt.map (no PDB); `ln` resolves nothing, so print raw.
Typical: "g; r; k 30" (to the crash), then "ba w4 <addr>; g-; r; k 30" (back to the last write)."""
import glob, os, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
CDB = r'C:\Program Files\WindowsApps\Microsoft.WinDbg_1.2611.4001.0_x64__8wekyb3d8bbwe\x86\cdb.exe'
cmds = sys.argv[1]
run = sys.argv[2] if len(sys.argv) > 2 else max(glob.glob(str(H / 'auto/ttd/*.run')), key=os.path.getmtime)
r = subprocess.run([CDB, '-z', run, '-c', cmds + '; q'], capture_output=True, text=True, timeout=1800)
print(r.stdout[-20000:]); print(r.stderr[-2000:])
