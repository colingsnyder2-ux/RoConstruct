import json,sys
d=json.load(open(f'work/native-client/prove-out/prove-{sys.argv[1]}/manifest.json'))
for f in d['families']:
    for r in f['symbols']:
        if r['status']!='inactive_exact' and not r['symbol'].startswith(('__','$')):
            print(r['status'],r['symbol'][:90],r.get('candidates'),json.dumps(r.get('rejections'))[:600])
