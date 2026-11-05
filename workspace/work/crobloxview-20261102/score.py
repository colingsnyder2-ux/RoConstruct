"""Exactness of each named CRobloxView method in the trial object. usage: score.py [obj]"""
import sys; sys.path.insert(0, '.')
from pathlib import Path
from roc import match
obj = Path(sys.argv[1] if len(sys.argv) > 1 else 'rebuild/2008-06/out/native-layouts/NativeViewTrial.cvtrial.obj').read_bytes()
want = [('004591e0','?OnActivateFrame@CRobloxView'),('00459210','?OnSetFocus@CRobloxView'),('00459250','?OnUpdateToolboxCheck@CRobloxView'),
 ('00459270','?getDataModel@CRobloxView'),('004592b0','?layout@CRobloxView'),('00459390','?OnSize@CRobloxView'),('004593b0','?OnActivateView@CRobloxView'),
 ('00458ea0','?onEvent@CRobloxView@@UAEXPBVPlayers@Network@RBX@@VSuperSafeChanged'),('0045a030','?onEvent@CRobloxView@@UAEXPBVServiceProvider@RBX@@UServiceAdded'),
 ('00459d60','?onEvent@CRobloxView@@UAEXPBVServiceProvider@RBX@@UServiceRemoving'),('004596a0','?showToolbox@CRobloxView'),('004597c0','?closeToolbox@CRobloxView'),
 ('004597f0','?toggleToolbox@CRobloxView'),('00459810','?openToolboxPage@CRobloxView'),('0045a2f0','?detachDataModel@CRobloxView'),('0045ac20','?OnDestroy@CRobloxView'),
 ('0045a140','?updateReflector@CRobloxView'),('00459570','?showHelp@CRobloxView'),('00459eb0','??0CRobloxView@@'),('00459ba0','??1CRobloxView@@'),('0045a4a0','?OnInitialUpdate@CRobloxView')]
funcs = match.coff_functions(obj)
for a, pre in want:
    hit = next((f for f in funcs if f[0].startswith(pre)), None)
    if not hit: print(a, 'MISSING', pre); continue
    t, tr, _ = match.target('2008-06', a)
    print(a, 'EXACT' if match.exact_match(t, tr, hit[1], hit[2]) else 'diff (%d vs %d)' % (len(hit[1]), len(t)), pre[1:30])
