"""python dropcheck.py: re-verify auto/alias_drop.json. aliasaudit drops func_<A>=S when it decides our S is another
original function; it dropped func_005aefa0=?openState@ScriptContext@RBX@@AAEXXZ although the native openState is a
100% match of 005aefa0 (prefix_match: 619/619 insns), leaving ScriptContext without a Lua state. Every drop whose S, as
compiled in a linked native object, is EXACT at A (bytes with relocations masked, and the same relocation targets:
codematch.targets_ok) is removed from the drop list (auto/alias_drop_falsepos.json records them; aliasaudit keeps them
out). Prints counts."""
import json, re, sys
from pathlib import Path
H = Path(__file__).parent
sys.argv = [sys.argv[0], '--defs-only']
src = (H / 'codematch.py').read_text(encoding='latin-1')
g = {'__file__': str(H / 'codematch.py'), '__name__': 'codematch_lib'}
exec(compile(src.split('al, tried = {}, 0')[0], 'codematch_head', 'exec'), g)
match, na, bylen, targets_ok = g['match'], g['na'], g['bylen'], g['targets_ok']
bysym = {}
for L, lst in bylen.items():
    for row in lst:
        bysym.setdefault(row[0], row)
drops = json.load(open(H / 'auto/alias_drop.json'))
fp = []
for line in drops:
    k, s = line.split('=', 1)
    m = re.fullmatch(r'func_([0-9a-f]{8})', k)
    if not m or s not in bysym:
        continue
    a = m.group(1)
    try:
        code, relocs, _ = match.target('2008-06', a)
    except BaseException:
        continue
    sym, body, crel, rmap = bysym[s]
    base = int(a, 16)
    if len(body) == len(code) and [r[2] for r in na.lines(body, base, crel)] == [r[2] for r in na.lines(code, base, relocs)] and targets_ok(a, code, rmap):
        fp.append(line)
keep = [d for d in drops if d not in fp]
json.dump(keep, open(H / 'auto/alias_drop.json', 'w'), indent=0)
old = []
try:
    old = json.load(open(H / 'auto/alias_drop_falsepos.json'))
except (OSError, ValueError):
    pass
json.dump(sorted(set(old) | set(fp)), open(H / 'auto/alias_drop_falsepos.json', 'w'), indent=0)
print('dropcheck: drops %d, proven exact (false positives, un-dropped) %d: %s' % (len(drops), len(fp), fp[:5]))
