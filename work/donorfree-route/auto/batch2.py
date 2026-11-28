import json, os
from pathlib import Path
R = Path(r'C:\Users\colin\RoConstruct')
NC = R / 'rebuild/2008-06/native-classes'
have = {os.path.normcase(j['source']) for j in json.load(open(R / 'work/donorfree-route/auto/rebuild_natives.json'))['jobs']}
src = [p for p in NC.glob('*.cpp') if not p.name.startswith('AutoRecover_') and os.path.normcase(str(p)) not in have]
src += list((NC / 'accepted').glob('*.cpp'))
for d in ('native-findings-new', 'native-findings-mew'):
    src += list((R / 'rebuild/2008-06' / d).glob('*.cpp'))
json.dump({'compiler_build': 21022, 'jobs': [{'source': str(p.resolve()), 'checks': [], 'ranges': [], 'layouts': []} for p in src]},
          open(R / 'work/donorfree-route/auto/rebuild_batch2.json', 'w'))
print(len(src), 'sources in batch 2')
