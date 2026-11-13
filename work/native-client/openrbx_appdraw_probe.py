"""Compile each openrbx Client/Rendering/AppDraw/*.cpp (the decompiled Roblox Ogre fork) as a whole TU on the 2008 compiler and
count the exe functions it reproduces byte-for-byte.  Inactive evidence.  python openrbx_appdraw_probe.py
Writes work/native-client/openrbx-appdraw/{wrappers/*.cpp,results.json}."""
import json, re, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
SRC = ROOT / 'tools/openrbx/Client/Rendering/AppDraw'
NC = ROOT / 'rebuild/2008-06/native-classes'
OUT = ROOT / 'work/native-client/openrbx-appdraw'
(OUT / 'wrappers').mkdir(parents=True, exist_ok=True)
root = SRC.parent.as_posix()
flags = ('/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include '
         '/I%s/AppDraw/include /I%s/AppDraw /I%s' % (root, root, (ROOT / 'tools/openrbx/util').as_posix()))
res = {}
for src in sorted(SRC.glob('*.cpp')):
    text = '// native-flags: %s\n#include "%s"\n' % (flags, src.as_posix())
    (OUT / 'wrappers' / ('Openrbx_' + src.name)).write_text(text)
    tmp = NC / ('ClaudeProbe_' + src.name)
    tmp.write_text(text)
    try:
        r = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/check_native_class.py'), 'native-classes/' + tmp.name,
                            'range=00401000-00800000'], cwd=ROOT, capture_output=True, text=True, timeout=1200)
        out = r.stdout + r.stderr
        m = re.search(r'(\d+) range functions exact', out)
        hits = sorted({l.split()[0] for l in out.splitlines() if re.match(r'^[0-9a-f]{8} \?', l) and '@Ogre@@' in l and ('Rbx' in l or 'TwoD' in l or 'Visual' in l or 'Unknown' in l or 'FUN_' in l)})
        err = '' if m else next((l.strip() for l in out.splitlines() if ' error C' in l or 'fatal' in l), out[-200:])
        res[src.name] = {'exact_total': int(m.group(1)) if m else None, 'ogre_class_exact': len(hits), 'addrs': hits, 'error': err[:240]}
    finally:
        tmp.unlink(missing_ok=True)
        (ROOT / 'rebuild/2008-06/out/native-layouts' / ('Check' + tmp.stem + '.obj')).unlink(missing_ok=True)
    print(src.name, res[src.name]['ogre_class_exact'], res[src.name]['error'][:90], flush=True)
(OUT / 'results.json').write_text(json.dumps(res, indent=1))
