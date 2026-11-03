"""Compile one native class source and report each listed method against the original.

usage: check_native_class.py native-classes/File.cpp ADDR=symbol-prefix [...]
A method is exact when its bytes match with relocated fields masked and every absolute field
of the original is a relocation in the native body (no hard-coded addresses).
Profile: the CMainFrame recorders' flags (rbxgs recipe, MFC DLL, XTP 11.2.2 static headers).
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild  # noqa: E402

source = ROOT / 'rebuild/2008-06' / sys.argv[1]
out = ROOT / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
recipe = libs.RECIPES['rbxgs']
import re
pinned = re.search(r'^// native-flags: (.*)$', source.read_text(encoding='utf-8-sig', errors='replace'), re.M)
import os
if os.environ.get('NATIVE_FLAGS'):  # trial override; pin a winner in the source afterwards
    pinned = re.match(r'(.*)', os.environ['NATIVE_FLAGS'])
headers = str(ROOT / 'rebuild/2008-06/native-headers')
flags = ['/nologo', '/c'] + (pinned.group(1).replace('{headers}', headers).split() if pinned else
                             ['/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS'])
flags += ['/DBOOST_ALL_NO_LIB']
flags += ['/D' + v for v in recipe['defines'].split()]
flags += ['/I' + str(ROOT / 'rebuild/2008-06/native-headers'), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags += ['/I' + str((libs.LIBS / v).resolve()) for v in recipe['include'] if v != 'WINSDK']
flags += ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK', '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]
obj = out / ('Check' + source.stem + '.obj')
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
if code:
    sys.exit(log[-3000:])
bodies = match.coff_functions(obj.read_bytes())
if len(sys.argv) > 2 and sys.argv[2].startswith('range='):  # auto: every body against a TU range
    import json
    lo, hi = (int(x, 16) for x in sys.argv[2][6:].split('-'))
    rows = [json.loads(l) for l in open(ROOT / 'work/2008-06/functions.jsonl')]
    cands = [r['addr'] for r in rows if lo <= int(r['addr'], 16) < hi and r.get('kind', 'code') == 'code']
    targets = {a: match.target('2008-06', a) for a in cands}
    hits = set()
    for n, b, r in bodies:
        for a, (t, tr, _) in targets.items():
            if len(t) == len(b) and set(tr) <= set(r) and match.exact_match(t, tr, b, r):
                print('%s %s' % (a, n[:90])); hits.add(a)
    print('%d range functions exact from this source' % len(hits))
    sys.exit(0)
exact = 0
for arg in sys.argv[2:]:
    addr, prefix = arg.split('=', 1)
    target, relocs, _ = match.target('2008-06', addr)
    found = [(n, b, r) for n, b, r in bodies if n.startswith(prefix)]
    if not found:
        print('%s %-40s MISSING' % (addr, prefix))
        continue
    best = max(found, key=lambda f: match.score(target, relocs, f[1], f[2]))
    ok = set(relocs) <= set(best[2]) and match.exact_match(target, relocs, best[1], best[2])
    exact += ok
    print('%s %-40s %s (%d/%d bytes, score %d)' % (addr, best[0][:40], 'EXACT' if ok else 'differs',
                                                 len(best[1]), len(target), match.score(target, relocs, best[1], best[2])))
print('%d/%d exact' % (exact, len(sys.argv) - 2))
