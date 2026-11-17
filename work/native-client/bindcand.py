"""bindcand.py FAMILY OUT.json ADDR...: bind the symbol of the (single) row of FAMILY whose candidates include ADDR and whose
only rejection for ADDR is 'symbol identity not established' to ADDR (the object body is byte-identical to the original ADDR; the
name tables disagree with the compiled mangling, e.g. a misattributed class). Same evidence kind as mkbind.py."""
import gzip, json, subprocess, sys
fam, out = sys.argv[1], sys.argv[2]
d = f'work/native-client/prove-out/{fam}'
args = []
for e in json.load(open(d + '/ledger.json')).values():
    rows = e.get('harvest_rows')
    if rows is None and e.get('harvest_ref'): rows = json.load(gzip.open(d + '/rows/' + e['harvest_ref'], 'rt'))
    for r in rows or []:
        for a in sys.argv[3:]:
            if a in (r.get('candidates') or []):
                errs = [x['errors'] for x in r.get('rejections', []) if x['addr'] == a]
                if errs and all(x.startswith('symbol identity not established') for x in errs[0]):
                    args.append(a + '=' + r['symbol'])
print(len(args), 'bindings')
subprocess.run([sys.executable, 'work/native-client/mkbind.py', out] + sorted(set(args)))
