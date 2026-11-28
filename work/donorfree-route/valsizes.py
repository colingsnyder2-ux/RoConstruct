"""python valsizes.py: by-value class argument sizes learned from the original binary -> auto/valsizes.json, read by
make_stubs._signature_ret_bytes. A stub for CMainFrame::onEvent(const RunService*, Heartbeat) popped 8 bytes (Heartbeat
assumed one word); the original's real onEvent overrides pop 12 -> Heartbeat is 8 bytes, and every heartbeat trashed
the RunService thread's saved registers. For every registry thiscall/stdcall function with an original address and
exactly ONE by-value class argument of unknown size: size = original ret bytes - the other arguments' bytes."""
import collections, json, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H))
import make_stubs as ms
rg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
cands = {}
for a, v in rg.items():
    n = (v or {}).get('name') or ''
    if v and v.get('kind') == 'code' and n.startswith('?') and re.search(r'@@[A-Z]?[A-Z]*[EG]', n) and re.search(r'[^PAQ]V[A-Za-z_]', n.split('@@', 1)[1]):
        cands[n] = int(a, 16)
names = sorted(cands)
UND = str(ms.ROOT / 'tools/msvc800sp1/VC/bin/undname.exe')
dem = {}
_batches, _cur, _ln = [], [], 0
for n in names:
    if _ln + len(n) + 3 > 28000:
        _batches.append(_cur); _cur, _ln = [], 0
    _cur.append(n); _ln += len(n) + 3
_batches.append(_cur)
for _bt in _batches:
    out = subprocess.run([UND] + _bt, capture_output=True, text=True).stdout
    for m in re.finditer(r'Undecoration of :- "(.*?)"\s*is :- "(.*?)"', out, re.S):
        dem[m.group(1)] = m.group(2)
votes = collections.defaultdict(collections.Counter)
for n, t in dem.items():
    if '__thiscall' not in t and '__stdcall' not in t:
        continue
    end = t.rfind(')'); d = 0; k = end
    while k >= 0:
        d += t[k] == ')'; d -= t[k] == '('
        if d == 0:
            break
        k -= 1
    args, d, cur = [], 0, ''
    for ch in t[k + 1:end]:
        d += ch in '<('; d -= ch in '>)'
        if ch == ',' and d == 0:
            args.append(cur.strip()); cur = ''
        else:
            cur += ch
    if cur.strip():
        args.append(cur.strip())
    unk = [a for a in args if a.startswith(('class ', 'struct ')) and not a.endswith(('*', '&')) and ' * ' not in a and ' & ' not in a and 'basic_string' not in a]
    if len(unk) != 1:
        continue
    other = 0
    for a in args:
        if a in unk or a == 'void':
            continue
        other += 8 if a.startswith(('double', '__int64', 'unsigned __int64')) else (0x1c if 'basic_string' in a else 4)
    head = t[:k]
    r = re.search(r'^(?:public|protected|private): (?:static |virtual )*(.*?) __(?:thiscall|stdcall)', head)
    if r and r.group(1).startswith(('class ', 'struct ')) and not r.group(1).rstrip().endswith(('*', '&')):
        other += 4
    sz = ms.addr_ret_bytes(cands[n]) - other
    if 0 < sz <= 0x400 and sz % 4 == 0:
        votes[unk[0].replace('const ', '').strip()][sz] += 1
out = {t: c.most_common(1)[0][0] for t, c in votes.items() if c.most_common(1)[0][0] != 4}
(H / 'auto/valsizes.json').write_text(json.dumps(out, indent=0, sort_keys=True))
print('by-value class sizes learned: %d (non-word); e.g. %s' % (len(out), sorted(out.items())[:6]))
