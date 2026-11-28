"""python bindsrc.py SRC.cpp [SRC2.cpp ...]: compile the sources with native_check_runner (one run), then make that run the
only qt_results.txt line for each source (older runs of the same source are removed; later lines win anyway)."""
import json, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
srcs = [str(Path(s).resolve()) for s in sys.argv[1:]]
man = H / 'auto/bindsrc.json'
man.write_text(json.dumps({'compiler_build': 21022, 'compiler_variant': 'default',
                           'jobs': [{'source': s, 'checks': [], 'ranges': [], 'layouts': []} for s in srcs]}))
out = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/native_check_runner.py'), 'run', str(man)],
                     capture_output=True, text=True).stdout
res = json.loads(re.findall(r'^\{.*\}$', out, re.M)[-1])['results']
rows = json.loads(Path(res).read_text())
bad = [Path(r['source']).name for r in rows if r.get('status') != 'complete']
if bad:
    sys.exit('compile failed: %s (see %s)' % (bad, Path(res).parent))
q = H / 'linkexp/qt_results.txt'
keep = []
for l in q.read_text().splitlines():
    try:   # drop earlier single-source runs of any of these sources
        old = json.loads(Path(l.strip()).read_text()) if l.strip() else []
        if isinstance(old, list) and len(old) == 1 and isinstance(old[0], dict) and old[0].get('source') in srcs:
            continue
    except (OSError, ValueError):
        pass
    keep.append(l)
q.write_text('\n'.join(keep + [res]) + '\n')
print('bound', res)
