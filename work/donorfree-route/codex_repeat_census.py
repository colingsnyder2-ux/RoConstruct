"""Serial repeated census runner: python codex_repeat_census.py EXE TAG N [--ids FILE]."""
import json
import shutil
import subprocess
import sys
from pathlib import Path

H = Path(__file__).parent
exe, tag, n = sys.argv[1], sys.argv[2], int(sys.argv[3])
ids = sys.argv[4] if len(sys.argv) > 4 else str(H / 'auto/crashcont_ids.json')
for i in range(n):
    subprocess.run([sys.executable, str(H / 'codex_fastcensus.py'), exe, '--ids', ids],
                   cwd=H, stdout=subprocess.DEVNULL, check=True)
    src = H / 'auto/codex_fastcensus.json'
    data = json.loads(src.read_text())
    shutil.copy(src, H / ('auto/codex_fastcensus_%s_%d.json' % (tag, i)))
    print('%s run %d: tested=%d relaunches=%d killers=%s' %
          (tag, i, data['tested'], data['relaunches'],
           [(k['id'], k['exit']) for k in data['killers']]), flush=True)
