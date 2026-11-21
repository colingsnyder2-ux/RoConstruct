"""ehbind.py FAMILY OUT.json : bind every '__ehhandler$...' rejected as 'unproven reference identity' to the
`push -1; push HANDLER` immediate of the original candidate body (same evidence rule as native_eh_handler_bind.py,
without the closure requirement); appends to the evidence file OUT (ROC_EXTRA_EVIDENCE for trials)."""
import gzip, json, re, subprocess, sys
from pathlib import Path
R = Path(__file__).resolve().parents[2]
fam, out = sys.argv[1], Path(sys.argv[2])
p = R / 'work/native-client/prove-out' / fam / 'ledger.json'
want = {}
for e in json.load(open(p)).values():
    rows = e.get('harvest_rows')
    if rows is None and e.get('harvest_ref'):
        rows = json.load(gzip.open(p.parent / 'rows' / e['harvest_ref'], 'rt'))
    for r in rows or []:
        for c in r.get('rejections', []):
            for x in c['errors']:
                m = re.match(r'unproven reference identity: (__ehhandler\$.*)', x)
                if m: want[(c['addr'], m.group(1))] = 1
addrs = sorted({a for a, _ in want})
txt = subprocess.run([str(R / 'roc.cmd'), 'native-asm', '2008-06'] + addrs, capture_output=True, text=True, shell=True).stdout
imm = {}
cur = None
for l in txt.splitlines():
    m = re.match(r'== ([0-9a-f]{8}) ', l)
    if m: cur = m.group(1); n = 0; continue
    m = re.match(r'[0-9a-f]{8}\s+push 0x([0-9a-f]+)', l)
    if cur and m and cur not in imm and 'push -1' in prev: imm[cur] = '%08x' % int(m.group(1), 16)
    prev = l
cur_e = json.load(open(out)) if out.is_file() else {'scope': 'EH handler identities from original prologues', 'identity_bindings': []}
have = {(b['symbol'], b['address']) for b in cur_e['identity_bindings']}
n = 0
for (a, s) in want:
    if a in imm and (s, imm[a]) not in have:
        cur_e['identity_bindings'].append({'symbol': s, 'address': imm[a], 'identity_evidence': 'push -1; push handler prologue immediate of original body ' + a, 'votes': 1}); n += 1
json.dump(cur_e, open(out, 'w'), indent=1)
print('bound', n, 'of', len(want))
