"""rows_for.py FAMILY SUBSTR...: print ledger rows of a prove family whose symbol contains any SUBSTR."""
import json,gzip,sys
fam=sys.argv[1]; subs=sys.argv[2:]
d=f'work/native-client/prove-out/{fam}'
for e in json.load(open(d+'/ledger.json')).values():
    rows=e.get('harvest_rows')
    if rows is None and e.get('harvest_ref'): rows=json.load(gzip.open(d+'/rows/'+e['harvest_ref'],'rt'))
    for r in rows or []:
        if any(s in r['symbol'] for s in subs):
            print(r['status'], r['symbol'][:120], r.get('candidates'))
            for c in r.get('rejections',[])[:3]: print('   ',c['addr'],c['errors'][:2])
