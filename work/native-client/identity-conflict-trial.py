"""Trial fail-closed per-symbol conflict handling without modifying the verifier."""
import inspect
import json
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import native_bulk

source = inspect.getsource(native_bulk.seed_evidence)
before = '''        if symbol in bindings and bindings[symbol] != target:
            blockers.append('conflicting reference identity: ' + symbol)
        else:
            bindings[symbol] = target'''
after = '''        if symbol in bindings and bindings[symbol] != target:
            bindings[symbol] = None
        else:
            bindings[symbol] = target'''
assert before in source
source = source.replace(before, after).replace('    return symbols, bindings, blockers, inputs',
    '    for symbol, target in bindings.items():\n        if target is None:\n            symbols.pop(symbol, None)\n    return symbols, bindings, blockers, inputs')
scope = dict(native_bulk.__dict__)
exec(source, scope)
seed = scope['seed_evidence']

audit_source = inspect.getsource(native_bulk.audit_references)
old = '        known = bindings.get(name)\n'
new = (old + "        if name in bindings and known is None:\n"
       "            errors.append('conflicting reference identity: ' + name)\n"
       "            return\n")
assert old in audit_source
exec(audit_source.replace(old, new), scope)
audit = scope['audit_references']

with tempfile.TemporaryDirectory(dir=ROOT / 'work/native-client') as tmp:
    folder = Path(tmp)
    for index, target in enumerate(('00400001', '00400002', '00400001')):
        (folder / f'{index}.json').write_text(json.dumps({'rows': [
            {'symbol': 'conflict', 'address': target},
            {'symbol': 'independent', 'address': '00400003'}]}))
    paths = [str(folder / f'{i}.json') for i in range(3)]
    for order in (paths, paths[::-1]):
        names, bindings, blockers, _ = seed(ROOT, order)
        assert not blockers and names == {'independent': {'00400003'}}
        assert bindings == {'conflict': None, 'independent': '00400003'}
        print('order-independent ambiguity:', bindings)

import test_native_onepast
from unittest.mock import patch
with patch.object(native_bulk, 'audit_references', audit):
    errors = test_native_onepast.check(bindings={'array': None})
    assert errors == ['conflicting reference identity: array'], errors
    assert test_native_onepast.check(bindings={'array': '00001000'}) == []
print('ambiguous data references rejected; independent data still verified')

inventory = json.loads((ROOT/'work/native-client/ogre-native-full-inventory-all.json').read_text())
names, bindings, blockers, _ = seed(ROOT, inventory['families'][0]['evidence'])
print('ambiguous symbols:', sum(value is None for value in bindings.values()))
print('other evidence blockers:', len(blockers))
print('remaining uniquely bound:', sum(value is not None for value in bindings.values()))
