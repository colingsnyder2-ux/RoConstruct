"""python donor_try.py NAME [keep]  -- build donor v8datamodel/NAME.cpp as a native TU and list exact functions whose symbol mentions NAME."""
import re, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
name = sys.argv[1]
src = (ROOT / 'tools/rbxgs/Client/App' / __import__('os').environ.get('DDIR', 'v8datamodel') / (name + '.cpp')).read_text(errors='replace')
src = re.sub(r'^(\s*)(?:const\s+)?char\s*\*\s*(?:const\s+)?(s[A-Z]\w*)\s*=\s*("[^"\n]*")\s*;', r'\1%s \2[] = \3;' % (sys.argv[3] if len(sys.argv) > 3 else 'char'), src, flags=re.M)
dst = ROOT / 'rebuild/2008-06/native-classes' / ('Claude%s.cpp' % name)
dst.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD\n' + src)
r = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/check_native_class.py'), 'native-classes/' + dst.name,
                    'range=00401000-00800000'], cwd=ROOT, capture_output=True, text=True, timeout=900)
text = r.stdout + r.stderr
hits = [l for l in text.splitlines() if re.match(r'^[0-9a-f]{8} \?\??[A-Za-z_0-9]+@' + name + '@RBX@@', l)]
err = [l for l in text.splitlines() if ' error C' in l][:3]
print(name, 'class-named exact:', len(hits), '|', re.findall(r'\d+ range functions exact', text))
for l in hits[:60]:
    print(' ', l[:110])
for l in err:
    print(' ERR', l[:230])
if len(sys.argv) < 3 or sys.argv[2] != 'keep':
    dst.unlink()
