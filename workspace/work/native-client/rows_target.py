"""rows_target.py FAMILY ADDR...: for each target address list the rows (symbol head) that name it as candidate + rejection errors."""
import json,gzip,sys
fam=sys.argv[1]; want=set(sys.argv[2:])
d=f'work/native-client/prove-out/{fam}'
for e in json.load(open(d+'/ledger.json')).values():
    rows=e.get('harvest_rows')
    if rows is None and e.get('harvest_ref'): rows=json.load(gzip.open(d+'/rows/'+e['harvest_ref'],'rt'))
    for r in rows or []:
        c=set(r.get('candidates') or [])
        if c&want or r['status']=='inactive_exact' and False:
            print(r['status'], r['symbol'][:100], sorted(c&want))
            for x in r.get('rejections',[]):
                if x['addr'] in want: print('   ',x['addr'],[y[:260] for y in x['errors']])
