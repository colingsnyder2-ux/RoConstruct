"""Shortcut loop (owner-authorized): link; for each unresolved symbol add the native object (obj-engine-abi) that defines
it, even when not byte-exact; stub whatever has no native definition.  python grow.py [rounds]"""
import json, os, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc.rebuild import coff_externals
HERE = ROOT / 'work/native-client/shortcut'
OBJDIR = ROOT / 'work/native-client/obj-engine-abi'
index = {}
for o in sorted(OBJDIR.glob('*.obj')) + sorted((ROOT / 'work/native-client/obj').glob('*.obj')):
    if 'Trial' in o.name: continue
    for s, d in coff_externals(o.read_bytes()).items():
        if d: index.setdefault(s, []).append(o)
chosen = json.loads((HERE / 'chosen.json').read_text()) if (HERE / 'chosen.json').exists() else []
rounds = int(sys.argv[1]) if len(sys.argv) > 1 else 6
env = dict(os.environ, ROC_ENGINE_ABI='1', ROC_LINK_RES=os.path.normpath(str(HERE / 'Roblox2008.res')))
for r in range(rounds):
    receipt = {'selected': [{'object': c} for c in chosen]}
    (HERE / 'receipt.json').write_text(json.dumps(receipt))
    base = (ROOT / 'work/native-client/link/selected-engine-cumulative.json').as_posix()
    env['ROC_LINK_EXTRA'] = base + ';' + (HERE / 'receipt.json').as_posix()
    out = subprocess.run([sys.executable, 'work/native-client/linkprobe.py'], cwd=ROOT, env=env, capture_output=True, text=True)
    probe = json.loads((ROOT / 'work/native-client/link/probe.json').read_text())
    un = probe['unresolved']
    print('round', r, 'chosen', len(chosen), 'unresolved', len(un), 'dups', len(probe['duplicates']), 'exit', probe['link_exit_code'], flush=True)
    if not un: break
    added = 0
    nodef = []
    for s in un:
        cands = [p.as_posix() for p in index.get(s, []) if p.as_posix() not in chosen]
        if cands:
            chosen.append(cands[0]); added += 1
        else:
            nodef.append(s)
    (HERE / 'chosen.json').write_text(json.dumps(chosen, indent=0))
    (HERE / 'stubs-needed.json').write_text(json.dumps(nodef, indent=0))
    if not added:
        print('no native definitions left; stubs needed', len(nodef)); break
