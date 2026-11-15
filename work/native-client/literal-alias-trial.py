"""Trial compiler-owned literal alias verification against original relocation/data."""
import inspect
import json
import pathlib
import runpy
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'work/native-client'))
from roc import native_bulk, match

identity = runpy.run_path(str(ROOT/'work/native-client/identity-conflict-trial.py'))
source = inspect.getsource(native_bulk.audit_references)
known_line = '        known = bindings.get(name)\n'
source = source.replace(known_line, known_line +
    "        if name in bindings and known is None:\n"
    "            errors.append('conflicting reference identity: ' + name)\n"
    "            return\n")
old = "        if known is not None and int(known, 16) != base:\n"
new = '''        literal = re.fullmatch(r'__real@([0-9a-fA-F]{8}|[0-9a-fA-F]{16})', name)
        is_local_literal = False
        if literal and stored == 0 and number > 0:
            table = sections[number - 1]
            encoded = bytes.fromhex(literal.group(1))[::-1]
            is_local_literal = (table[0].rstrip(b'\\0') == b'.rdata' and
                                not table[9] & 0x80000000 and value == 0 and
                                table[3] == len(encoded) and table[4] and
                                raw[table[4]:table[4] + len(encoded)] == encoded and
                                table[7] == 0)
        if known is not None and int(known, 16) != base and not is_local_literal:
'''
assert old in source
scope = dict(native_bulk.__dict__)
exec(source.replace(old, new), scope)
audit = scope['audit_references']

inventory = json.loads((ROOT/'work/native-client/ogre-native-full-inventory-all.json').read_text())
_, bindings, blockers, _ = identity['seed'](ROOT, inventory['families'][0]['evidence'])
assert not blockers
p = ROOT/'work/native-client/partchunk-invalidate-trial/decal-ctor-proof3/manifest.json'
manifest = json.loads(p.read_text())
raw = pathlib.Path(manifest['families'][0]['jobs'][0]['object']).read_bytes()
row = next(r for r in manifest['families'][0]['symbols'] if r['symbol'].startswith('??0Texture@ViewNew'))
body = next(b for n,b,_ in match.coff_functions(raw) if n == row['symbol'])
target, relocs, _ = match.target('2008-06', '004eafd0')
targets = native_bulk.Targets('2008-06', ['004eafd0'])
for file in ('ctor-inferred.json','ctor-bindings.json','decal-ctor-inferred.json','decal-ctor-bindings.json'):
    extra = json.loads((ROOT/'work/native-client/partchunk-invalidate-trial'/file).read_text())
    bindings.update({r['symbol']:r['address'] for r in extra['rows']})
args = (raw,row['symbol'],body,target,relocs,0x4eafd0,targets,bindings)
_, errors = audit(*args)
print('texture original references:', errors)
assert errors == []

class Corrupt:
    def __getattr__(self, key): return getattr(targets, key)
    def data(self, va, size):
        value = bytearray(targets.data(va,size))
        if va == 0x82d1cc and value: value[0] ^= 1
        return bytes(value)

_, errors = audit(*(args[:-2]+(Corrupt(),bindings)))
assert any('referenced data differs: __real@bdcccccd' in e for e in errors), errors
print('corrupt original constant rejected')
