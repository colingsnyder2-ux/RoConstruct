"""scripttest with a longer observation window: python scripttest_long.py EXE --lua FILE [SECS]."""
import json
import re
import sys
from pathlib import Path

import scripttest

H = Path(__file__).parent
args = sys.argv[1:]
exe = next((a for i, a in enumerate(args) if a.lower().endswith('.exe') and (i == 0 or args[i - 1] != '--orig')), str(H / 'run/RobloxQT.exe'))
orig = args[args.index('--orig') + 1] if '--orig' in args else str(H / 'run/RobloxOrig.exe')
lua_path = Path(args[args.index('--lua') + 1]) if '--lua' in args else H / 'feature_test.lua'
secs = float(args[-1]) if len(args) > 1 and args[-1].replace('.', '', 1).isdigit() else 60.0
print('scripttest_long: exe=%s orig=%s lua=%s secs=%s' % (exe, orig, lua_path, secs), flush=True)
lua = lua_path.read_text()
print('== original')
o = scripttest.run(orig, lua, wait=secs)
print(o)
print('== ours')
q = scripttest.run(exe, lua, wait=secs)
print(q)
of = set(sum((v['fail'] for kk, v in o.items() if not kk.startswith('_')), []))
qf = set(sum((v['fail'] for kk, v in q.items() if not kk.startswith('_')), []))
stages = sorted(set(re.findall(r'\bR\d(?=[\s\'"=])', lua)))
bad = sorted(qf - of) + ['%s stage %s missing' % (side, stage) for side, result in (('orig', o), ('ours', q)) for stage in stages if stage not in result]
if o.get('_exit'):
    bad.append('orig ' + o['_exit'])
if q.get('_exit'):
    bad.append(q['_exit'])
elif not q.get('_workspace'):
    bad.append('no Workspace results')
json.dump({'orig': o, 'ours': q, 'bad': bad}, open(H / 'auto/codex_scripttest.json', 'w'), indent=1)
print('scripttest_long: orig %s | ours %s | broken in ours: %s' % (
    {kk: v for kk, v in o.items() if kk[0] == 'R'},
    {kk: v for kk, v in q.items() if kk[0] == 'R'}, bad or q.get('_exit')))
