"""Compile verified Instance providers into an isolated, non-runnable sound link."""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts/sound-native-instance-worker'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/sound-native-link-frozen-worker.json').read_text())
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
items = [
    ('InstanceBaseCallbacks.cpp', [], [('?askAddChild@Instance@', '0068e880'), ('?askSetParent@Instance@', '0068e880'), ('?onChildAdded@Instance@', '0070bdf0'), ('?onChildRemoving@Instance@', '0070bdf0'), ('?onChildRemoved@Instance@', '0070bdf0'), ('?onLastChildRemoved@Instance@', '0047d410'), ('?onChildChanged@Instance@', '00557490')]),
    ('InstanceAncestorChanged.cpp', [], [('?onAncestorChanged@Instance@', '0055acc0')]),
    ('InstanceLifetime.cpp', ['/DNATIVE_INSTANCE_EXTERNAL_CREATE_CHILD'], [('??0Instance@RBX@@', '0055b7e0'), ('??1Instance@RBX@@', '0055a540')]),
]
objects, rows = [], []
for filename, extra, checks in items:
    source = root / 'rebuild/2008-06/native-classes' / filename
    if filename == 'InstanceAncestorChanged.cpp':
        text = source.read_text()
        duplicate = 'struct AncestorChanged {\n    Instance* child;\n    Instance* oldParent;\n    Instance* newParent;\n};\n'
        assert text.count(duplicate) == 1
        source = out / filename
        source.write_text(text.replace(duplicate, '', 1))
    obj = out / (source.stem + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', extra + flags + ['/Fo' + str(obj), str(source)], out)
    if code:
        raise RuntimeError(log)
    raw = obj.read_bytes()
    functions = match.coff_functions(raw)
    for prefix, address in checks:
        name, body, refs = next(x for x in functions if x[0].startswith(prefix))
        target, targetrefs, _ = match.target('2008-06', address)
        assert match.exact_match(target, targetrefs, body, refs), (filename, name, address)
        rows.append({'symbol': name, 'address': address, 'size': len(body)})
    objects.append(str(obj))
source = root / 'rebuild/2008-06/native-classes/NativeClassNames.cpp'
obj = out / 'NativeClassNames.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
sections, _, definitions, _ = match._coff_data_index(raw)
offset, index = definitions['?sInstance@RBX@@3PADA']
section = sections[index]
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
assert raw[section[4] + offset:section[4] + offset + 9] == pe.get_data(0x82d6a0 - pe.OPTIONAL_HEADER.ImageBase, 9) == b'Instance\0'
assert struct.unpack('<I', pe.get_data(0x40ada9 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x82d6a0
objects.append(str(obj))
source = root / 'rebuild/2008-06/tests/NativeSoundProviderMemberWorker.cpp'
obj = out / 'NativeSoundProviderMemberWorker.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?findServiceProvider@ServiceProvider@RBX@@'))
target_body, target_refs, _ = match.target('2008-06', '004898d0')
assert match.exact_match(target_body, target_refs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
bindings = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if 0 <= offset < len(body)-3:
        value = struct.unpack_from('<I', target_body, offset)[0]
        if kind == 20:
            value = (0x4898d0 + offset + 4 + struct.unpack_from('<i', target_body, offset)[0]) & 0xffffffff
        bindings[symbols[symbol][0]] = value
for symbol, value in [('??_R0?AVServiceProvider@RBX@@@8', 0x92e15c), ('??_R0?AVInstance@RBX@@@8', 0x92907c), ('___RTDynamicCast', 0x6a17c6)]:
    assert bindings[symbol] == value
rows.append({'symbol': name, 'address': '004898d0', 'size': len(body), 'bindings': bindings})
objects.append(str(obj))
args = []
for arg in base['flags']:
    if arg.startswith('/OUT:'):
        arg = '/OUT:' + str(out / 'probe.exe')
    elif arg.startswith('/MAP:'):
        arg = '/MAP:' + str(out / 'probe.map')
    args.append(arg)
code, log = rebuild.run(rebuild.toolchain(21022), 'link', args + objects, out)
(out / 'probe.log').write_text(log, encoding='utf-8')
errors = [line.strip() for line in log.splitlines() if re.search(r'\berror LNK\d+', line)]
receipt = {'scope': 'NONRUNNABLE diagnostic: byte-matched bodies added to frozen mixed-ABI link; target bindings, layouts and COMDAT ownership require proof.',
           'baseline_receipt_sha256': hashlib.sha256((root / 'work/2008-06/shared-layouts/sound-native-link-frozen-worker.json').read_bytes()).hexdigest(),
           'objects': {p: hashlib.sha256(Path(p).read_bytes()).hexdigest() for p in objects},
           'methods': rows, 'link_exit': code, 'errors': errors}
target = root / 'work/2008-06/shared-layouts/sound-native-instance-worker.json'
target.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
print('matched', len(rows), 'link exit', code, 'errors', len(errors))
