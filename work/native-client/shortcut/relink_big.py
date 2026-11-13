"""Link chosen.json objects + glue; stub every symbol still undefined; run crashsite.  python relink_big.py [chosen.json]"""
import json, subprocess, sys, os
from pathlib import Path
H = Path('work/native-client/shortcut')
chosen = json.load(open(H / (sys.argv[1] if len(sys.argv) > 1 else 'chosen.json')))
glue = [(H / o).resolve().as_posix() for o in json.load(open(H / 'glue.json'))]
base = Path('work/native-client/link/selected-engine-cumulative.json').resolve().as_posix()
import re
DUPS = H / 'dups.json'
def link(objs):
    json.dump({'selected': [{'object': c} for c in objs]}, open(H / 'receipt-final.json', 'w'))
    env = dict(os.environ, ROC_STRONG_OWN='1', ROC_ENGINE_ABI='1', ROC_LINK_RES=os.path.normpath(str((H / 'Roblox2008.res').resolve())),
               ROC_LINK_EXTRA=base + ';' + (H / 'receipt-final.json').resolve().as_posix())
    if DUPS.exists(): env['ROC_DEDUPE'] = str(DUPS.resolve())
    for _ in range(4):
        subprocess.run([sys.executable, 'work/native-client/linkprobe.py'], env=env, capture_output=True)
        pr = json.load(open('work/native-client/link/probe.json'))
        if not pr['duplicates']: break
        found = set(json.load(open(DUPS))) if DUPS.exists() else set()
        found |= {m.group(1) for d in pr['duplicates'] for m in [re.search(r'\((\?[^)]*)\)\s*$', d)] if m}
        json.dump(sorted(found), open(DUPS, 'w')); env['ROC_DEDUPE'] = str(DUPS.resolve())
    return pr
p = link(chosen + glue)
print('unstubbed link: unresolved', len(p['unresolved']), 'dups', len(p['duplicates']), flush=True)
json.dump(p['unresolved'], open(H / 'unresolved12.json', 'w'))
subprocess.run([sys.executable, str(H / 'mkstub.py'), str(H)], check=True)
p = link(chosen + glue + [(H / 'stubs.obj').resolve().as_posix()])
print('final link', p['link_exit_code'], len(p['unresolved']), len(p['duplicates']), flush=True)
L = Path('work/native-client/link').resolve()
subprocess.run([sys.executable, str(H / 'crashsite.py'), str(L / 'Roblox2008.exe'), str(L / 'Roblox2008.map'), '20'])
