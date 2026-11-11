"""Record inactive BrickColor provider byte matches; runtime remains unverified."""
import hashlib, json, os, struct, subprocess, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify
base = root / 'rebuild/2008-06'
checks = ['005b5c80=?colorPalette@BrickColor@RBX@@', '005b5c90=?getClosestPaletteIndex@BrickColor@RBX@@', '005b5cb0=?parse@BrickColor@RBX@@', '005b5ee0=?random@BrickColor@RBX@@', '005b5f30=?closest@BrickColor@RBX@@SA?AV12@VColor4@G3D@@', '005b6090=??0BrickColor@RBX@@QAE@H@Z', '005b61b0=?name@BrickColor@RBX@@', '005b6200=?color4@BrickColor@RBX@@', '005b62e0=?closest@BrickColor@RBX@@SA?AV12@VColor3@G3D@@']
out = base / 'out/native-brickcolor-providers-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
p = subprocess.run([sys.executable, str(base/'tests/check_native_class.py'), 'native-classes/BrickColorProviders.cpp'] + checks, cwd=root, env=env, capture_output=True, text=True, check=True)
assert '9/9 exact' in p.stdout, p.stdout
providers_obj = out/'CheckBrickColorProviders.obj'
providers_raw = providers_obj.read_bytes()
provider_names = [n for n, _, _ in match.coff_functions(providers_raw)]
methods = [(next(n for n in provider_names if n.startswith(c.split('=', 1)[1])), int(c.split('=', 1)[0], 16)) for c in checks]
_, provider_symbols, _, _ = match._coff_data_index(providers_raw)
mapping = [('?singleton@BrickMap@BrickColor@RBX@@', 0x5b5c20),
           ('??A?$map@W4Number@BrickColor@RBX@@H', 0x46d3d0),
           ('?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@V?$basic_string', 0x68d1a0),
           ('?iRandom@G3D@@', 0x515780),
           ('?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@VColor4@', 0x4d7240),
           ('?find@?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@VColor4uint8', 0x5b3990),
           ('?find@?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@VColor4@', 0x5b3b10),
           ('?find@?$_Tree@V?$_Tmap_traits@W4Number@BrickColor@RBX@@V?$basic_string', 0x5b3c90),
           ('__real@461c4000', 0x82746c)]
internal = {next(s[0] for s in provider_symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
original = Original()
assert original.data(0x82746c, 4) == struct.pack('<f', 10000.0)
provider_rows = verify(original, providers_obj, methods, internal)
q = subprocess.run([sys.executable, str(base/'tests/check_native_class.py'), 'native-classes/BrickColorColor3.cpp', '005b6270=?color3@BrickColor@RBX@@'], cwd=root, env=env, capture_output=True, text=True, check=True)
assert '1/1 exact' in q.stdout, q.stdout
obj = out/'CheckBrickColorColor3.obj'
raw = obj.read_bytes()
name = next(n for n, _, _ in match.coff_functions(raw) if n.startswith('?color3@BrickColor@RBX@@'))
_, symbols, _, _ = match._coff_data_index(raw)
callee = next(s[0] for s in symbols.values() if s[0].startswith('?color4@BrickColor@RBX@@'))
rows = verify(Original(), obj, [(name, 0x5b6270)], {callee: 0x5b6200})
paths = [base/'native-classes/BrickColorProviders.cpp', base/'native-classes/BrickColorColor3.cpp', root/'tools/rbxgs/Client/App/include/v8datamodel/BrickColor.h', base/'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git','rev-parse','HEAD'], cwd=root, text=True).strip(), 'sources': {str(x.relative_to(root)): hashlib.sha256(x.read_bytes()).hexdigest() for x in paths}, 'object_sha256': hashlib.sha256(providers_raw).hexdigest(), 'color3_object_sha256': hashlib.sha256(raw).hexdigest(), 'checks': p.stdout + q.stdout, 'provider_bindings': provider_rows, 'color3_bindings': rows, 'scope': 'Inactive exact bytes and relocations; indirect calls, ABI, provider selection and runtime unverified.'}
(root/'work/2008-06/native-brickcolor-providers.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(p.stdout + q.stdout,end='')
