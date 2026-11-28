"""python accessalias.py: stubbed C++ names whose twin differing ONLY in the access letter is defined.
Converted analogs declared members with another access (doDeclare<sStarterPackService> public `SAABV01` vs the native
private `CAABV01`; Instance's protected ctor `IAE` vs public `QAE`): the spelling links to a `return 0` stub. Access does
not change the ABI within a kind (A/I/Q member, B/J/R far member, C/K/S static, E/M/U virtual, ...), so the stub name
is aliased to the defined twin. Same for template string-argument spellings (char* 3PADA vs const char* const
3QBDB): Described<Hint,...,sHint>::classDescriptor via 3PADA was a stub -> null descriptor. Adjustor thunks (??_E/??_G with G/O/W codes) are skipped.
Writes aliases_access.txt (grow-only, targets re-checked)."""
import re
from pathlib import Path
H = Path(__file__).parent
TW = {}
for grp in ('AIQ', 'BJR', 'CKS', 'DLT', 'EMU', 'FNV'):
    for c in grp:
        TW[c] = grp.replace(c, '')
defs, stubs = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and p[1].startswith('?'):
        (stubs if 'stubs' in p[-1] else defs).add(p[1])
al = {}
for s in stubs - defs:
    tw = set()
    for m in re.finditer(r'@@([A-X])', s):   # template args hold @@ too: try every position
        i, c = m.start(1), m.group(1)
        if s.startswith(('??_E', '??_G')) and c in 'GOW':
            continue
        tw |= {s[:i] + d + s[i + 1:] for d in TW.get(c, '')} & defs
    if not tw:   # template string-arg spelling twins: char* (3PADA) vs const char* const (3QBDB) vs const char* (3PBDA)
        for x, ys in (('3PADA', ('3QBDB', '3PBDA')), ('3QBDB', ('3PADA', '3PBDA')), ('3PBDA', ('3QBDB', '3PADA'))):
            if x in s:
                tw |= {s.replace(x, y) for y in ys} & defs
    if len(tw) == 1:
        al[s] = tw.pop()
_af = H / 'aliases_access.txt'   # grow-only: an aliased stub leaves the stub list; keep entries whose target is still defined
for l_ in (_af.read_text().splitlines() if _af.exists() else []):
    k_, _, v_ = l_.partition('=')
    if v_ in defs:
        al.setdefault(k_, v_)
_af.write_text(''.join('%s=%s\n' % kv for kv in sorted(al.items())))
print('accessalias: stubbed names aliased to their defined access twin: %d (e.g. %s)' % (len(al), sorted(al)[:3]))
