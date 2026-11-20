import json

cache = json.load(open('work/native-client/scope-cache.json'))
funcs = cache['functions']
exact = set(cache.get('exact', []))

def inspect_class(cls_name):
    matches = [(addr, name) for addr, (c, name) in funcs.items() if c.lower() == cls_name.lower()]
    print(f"=== {cls_name} ({len(matches)} functions) ===")
    for addr, name in matches:
        is_ex = addr.lower().zfill(8) in exact
        print(f"  {addr} {'[EXACT]' if is_ex else '[TODO] '} {name}")

for c in ['TreeStage', 'HitTest', 'PrimIterator', 'Cofm', 'BrickColor', 'CUIntArray', 'Geometry', 'PBBBuilder']:
    inspect_class(c)
