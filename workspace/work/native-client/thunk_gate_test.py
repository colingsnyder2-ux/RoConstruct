"""Trial: judge a generated thunk with the fast native gate (resident gate server) instead of a 3-minute full proof.
  python work/native-client/thunk_gate_test.py ADDR [ADDR ...]"""
import json
import os
import re
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
addrs = sys.argv[1:]
sys.argv = [sys.argv[0]]
src = (HERE / 'thunk_lane.py').read_text(encoding='utf-8')
ns = {'__file__': str(HERE / 'thunk_lane.py'), '__name__': 'thunk_gate_test'}
head = src[:src.index("rows = [r for r in json.loads((HERE / 'jmp-thunks.json')")].replace('args = ap.parse_args()', 'args = ap.parse_args([])')
exec(compile(head, str(HERE / 'thunk_lane.py'), 'exec'), ns)
import native_creator_gate as cg  # noqa: E402

HDR = ROOT / 'rebuild/2008-06/native-headers'
ANY = str(HDR / 'util/Name.h')
rows = {r['addr']: r for r in json.loads((HERE / 'jmp-thunks.json').read_text())}
for addr in addrs:
    row = rows[addr]
    symbol, source = ns['proven'](row['target'])
    if not symbol:
        print(addr, 'target symbol unknown')
        continue
    code, kind = ns['forwarder'](addr, symbol)
    if not code:
        print(addr, 'skip', kind)
        continue
    variants = code if isinstance(code, list) else [(code, kind)]
    first = Path(source).read_text(errors='replace').split('\n', 1)[0]
    toks = first[len('// native-flags:'):].split() if first.startswith('// native-flags:') else []
    roots = [t[2:].replace('{headers}', str(HDR)) for t in toks if t.startswith('/I')]
    defines = [t[2:] for t in toks if t.startswith('/D')]
    for text, kind in variants:
        body = '#include "%s"\n%s' % (Path(source).resolve().as_posix(), text)
        needle = 'callDoDeclare' if kind == 'callDoDeclare' else ('Thunk_' + addr) if kind.startswith('destructor') else 'sub_' + addr
        work = HERE / 'thunk-gate' / addr
        work.mkdir(parents=True, exist_ok=True)
        started = time.time()
        sym = cg.discover_symbol(work, [ANY], body, addr, needle, include_first=roots, raw_includes=[], defines=defines)
        if not sym:
            print(addr, kind, 'no symbol', (cg.LAST_ERRORS.get(addr) or [''])[:2], '%.0fs' % (time.time() - started))
            continue
        status, detail = cg.gate_code(work, [ANY], body, {addr: sym}, include_first=roots, raw_includes=[], defines=defines)
        print(addr, kind, status.get(addr), sym[:70], str(detail)[:200].replace('\n', ' | '), '%.0fs' % (time.time() - started), flush=True)
