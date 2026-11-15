"""Isolated experiment; no canonical verifier changes."""
import inspect
import json
import struct
import sys
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import native_bulk, match

manifest = json.loads((ROOT / 'work/native-client/prove-out/prove-G3DToneMap/manifest.json').read_text())
job = manifest['families'][0]['jobs'][0]
raw = Path(job['object']).read_bytes()
symbol = next(r['symbol'] for r in manifest['families'][0]['symbols']
              if r['symbol'].startswith('?makeShadersPS20@ToneMap'))
body = next(body for name, body, _ in match.coff_functions(raw) if name == symbol)
target, relocs, _ = match.target('2008-06', '007b2690')
inventory = json.loads((ROOT / 'work/native-client/ogre-native-full-inventory-all.json').read_text())
_, bindings, _, _ = native_bulk.seed_evidence(ROOT, inventory['families'][0]['evidence'])
if '--bound' in sys.argv:
    receipt = json.loads((ROOT / 'work/native-client/tonemap-priority/bindings.json').read_text())
    bindings.update({r['symbol']: r['address'] for r in receipt['identity_bindings']})
targets = native_bulk.Targets('2008-06', ['007b2690'])
source = inspect.getsource(native_bulk.audit_references)
old = "        if depth > 6 or not value <= begin < end:\n"
new = ("        if begin == end and stored > 0 and value < end and depth <= 6:\n"
       "            reference(index, 0, base, depth + 1)\n"
       "            return\n" + old)
assert source.count(old) == 1
namespace = dict(native_bulk.__dict__)
exec(source.replace(old, new), namespace)
trial = namespace['audit_references']
args = (raw, symbol, body, target, relocs, 0x7b2690, targets, bindings)
_, before = native_bulk.audit_references(*args)
_, after = trial(*args)
print('before:', before)
print('after:', after)
wrong = dict(bindings)
name = next(r['symbol'] for r in manifest['families'][0]['symbols']
            if r['symbol'].startswith('?makeShadersPS20@ToneMap'))
_, refs_symbols, _, _ = match._coff_data_index(raw)
name = next(n for n, _, _, _ in refs_symbols.values() if n.startswith('?bloomShader@ToneMap'))
wrong[name] = '00000001'
_, errors = trial(*(args[:-1] + (wrong,)))
assert any('reference identity differs' in e for e in errors), errors

class CorruptTarget:
    def __getattr__(self, key):
        return getattr(targets, key)
    def data(self, va, size):
        result = bytearray(targets.data(va, size))
        if va == 0x97f3dc and result:
            result[0] ^= 1
        return bytes(result)

_, errors = trial(*(args[:-2] + (CorruptTarget(), bindings)))
assert any('referenced data differs' in e for e in errors), errors
print('wrong identity and corrupted data both rejected')

# Isolate the one-past relocation: no earlier reference can prime the visited set.
sections, symbols, definitions, extra = match._coff_data_index(raw)
start, section = definitions[symbol]
table = list(sections[section])
index = next(i for i in range(table[7])
             if struct.unpack_from('<IIH', raw, table[5] + i * 10)[0] - start == 772)
table[5] += index * 10
table[7] = 1
isolated = list(sections)
isolated[section] = tuple(table)
with patch.object(match, '_coff_data_index', return_value=(isolated, symbols, definitions, extra)):
    single = (raw, symbol, body, target, {772}, 0x7b2690, targets, bindings)
    _, errors = trial(*single)
    assert not errors, errors
    _, errors = trial(*(single[:-2] + (CorruptTarget(), bindings)))
    assert any('referenced data differs' in e for e in errors), errors
    _, errors = trial(*(single[:-1] + (wrong,)))
    assert any('reference identity differs' in e for e in errors), errors
    empty = list(isolated)
    data_section = list(empty[3])
    data_section[3] = 4
    empty[3] = tuple(data_section)
    with patch.object(match, '_coff_data_index', return_value=(empty, symbols, definitions, extra)):
        _, errors = trial(*single)
        assert any('unproven data span' in e for e in errors), errors
print('isolated one-past verifies full data; wrong identity, corrupt bytes, and empty spans rejected')
