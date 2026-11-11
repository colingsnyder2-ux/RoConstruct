import json
with open('work/native-client/link/probe.json') as f:
    data = json.load(f)
unresolved = len(data['unresolved'])
dups = len(data['duplicates'])
print('Unresolved:', unresolved)
print('Duplicates:', dups)
with open('work/native-client/inventory.json') as f:
    inv = json.load(f)
ok = sum(1 for v in inv.values() if v['ok'])
print('Inventory:', ok, 'of', len(inv), 'objects compile')
