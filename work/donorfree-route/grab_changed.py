"""python grab_changed.py BRANCH...: native class files a branch CHANGED (same name, different content from ours) ->
rebuild/2008-06/native-findings-<tag>/ for gap-fill linking after our natives (they never replace our objects).
Only files whose branch version differs from our working copy; our in-flight edits stay untouched."""
import hashlib, os, subprocess, sys
from pathlib import Path
R = Path(__file__).resolve().parents[2]
os.chdir(R)
for br in sys.argv[1:]:
    tag = br.split('/')[0]
    out = Path('rebuild/2008-06/native-findings-' + tag); out.mkdir(exist_ok=True)
    n = 0
    for p in subprocess.run(['git', 'ls-tree', '-r', '--name-only', br, '--', 'rebuild/2008-06/native-classes'], capture_output=True, text=True).stdout.split('\n'):
        b = os.path.basename(p)
        mine = Path('rebuild/2008-06/native-classes') / b
        if not b.endswith('.cpp') or not mine.exists():
            continue
        data = subprocess.run(['git', 'show', '%s:%s' % (br, p)], capture_output=True).stdout
        if data and data.replace(b'\r\n', b'\n') != mine.read_bytes().replace(b'\r\n', b'\n'):
            (out / b).write_bytes(data); n += 1
    print('%s: %d changed native files staged in %s' % (br, n, out))
