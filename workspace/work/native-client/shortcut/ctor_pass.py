"""Targeted analog pass: give every still-stubbed RBX constructor/destructor (??0 / ??1 names with a known exe address) its server
analog, strip the analog's 2007 vtables, fix __imp_ names, and add it to a chosen list.  Repeat a few rounds (base ctors).
python ctor_pass.py chosen_verbs.json [rounds] [prefix-regex]"""
import json, os, re, subprocess, sys
from pathlib import Path
sys.path.insert(0, '.')
sys.path.insert(0, 'work/native-client')
import rename as rn
H = Path('work/native-client/shortcut'); C = H / 'closure'
chosen_name = sys.argv[1]; rounds = int(sys.argv[2]) if len(sys.argv) > 2 else 3
pat = re.compile(sys.argv[3] if len(sys.argv) > 3 else r'^\?\?[01][A-Za-z_0-9]+@RBX@@')
cb = json.load(open('work/native-client/claude-identity-closure-v5.json'))
addr = {x['symbol']: x['addr'] for x in cb['bindings'] if x.get('addr')}
h = C / 'helper_addrs.json'
if h.exists():
    for s, a in json.load(open(h)).items():
        addr.setdefault(s, a)


def relink():
    r = subprocess.run([sys.executable, str(H / 'relink_big.py'), chosen_name], capture_output=True, text=True)
    return [l for l in r.stdout.splitlines() if l.startswith(('unstubbed', 'final link'))]


for rd in range(rounds):
    un = json.load(open(H / 'unresolved12.json'))
    want = {s: addr[s] for s in un if pat.match(s) and s in addr and int(addr[s], 16) < 0x7c0000}
    print('round', rd, 'stubbed ctor/dtor with address', len(want), flush=True)
    if not want:
        break
    json.dump({s: {'exact': [a]} for s, a in want.items()}, open(C / 'addrmap_ctor.json', 'w'))
    env = dict(os.environ, ROC_RENAME_PLACEHOLDER='1', ROC_RENAME_KEEP_HELPERS='1', ROC_ADDRMAP=str((C / 'addrmap_ctor.json').resolve()),
               ROC_RENAME_OUT=str((C / 'renamed').resolve()), ROC_RENAME_JSON=str((C / 'rename.json').resolve()))
    subprocess.run([sys.executable, 'work/native-client/rename.py', *sorted(set(want.values()))], env=env, capture_output=True, text=True)
    res = json.load(open(C / 'rename.json'))
    good = sorted({a for a in want.values() if res.get(a, {}).get('status') == 'renamed'})
    print('  renamed', len(good), 'of', len(set(want.values())), flush=True)
    for a in good:   # __imp_ fix
        o = C / 'renamed' / (a + '.obj')
        data = o.read_bytes(); syms = rn.symtab(data)[0]
        mp = {i: '__imp_' + n.split('!', 1)[1] for i, n, sec, cls, v in syms if '.dll!' in n and sec == 0}
        if mp:
            o.write_bytes(rn.rename(data, mp))
    subprocess.run([sys.executable, str(H / 'strip_analog_vtables.py')], capture_output=True)
    c = json.load(open(H / chosen_name))
    have = {os.path.basename(x) for x in c}
    c += [(C / 'renamed' / (a + '.obj')).resolve().as_posix() for a in good if a + '.obj' not in have]
    json.dump(c, open(H / chosen_name, 'w'), indent=0)
    print(' ', relink(), flush=True)
