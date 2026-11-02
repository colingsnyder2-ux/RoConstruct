"""Check both createChild providers and compile the native lifetime link profile."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/native-classes/InstanceLifetime.cpp'
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeInstanceLifetimeLink.obj'
flags += ['/DNATIVE_INSTANCE_EXTERNAL_CREATE_CHILD', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
methods = []
for address, prefix in [('0055b7e0', '??0Instance@RBX@@'), ('0055a540', '??1Instance@RBX@@')]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, len(body), len(target))
    methods.append({'address': address, 'symbol': name, 'size': len(body)})
assert not any(n.startswith('?createChild@Instance@RBX@@') for n, _, _ in match.coff_functions(raw))
archive = root / 'rebuild/2008-06/out/RbxgsApp/linked/linked.lib'
archived = next(data for name, data in libs.archive_members(archive) if str(name) == 'Instance.obj')
normal = (out / 'NativeInstanceLifetime.obj').read_bytes()
providers = []
for label, data in [('native', normal), ('archive', archived)]:
    name, body, refs = next(x for x in match.coff_functions(data) if x[0].startswith('?createChild@Instance@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', '0055a470')
    assert match.exact_match(target, targetrefs, body, refs)
    sections, symbols, definitions, _ = match._coff_data_index(data)
    start, index = definitions[name]
    section = sections[index]
    calls = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', data, section[5] + 10*i)
        offset -= start
        if 0 <= offset < len(body)-4 and kind == 20:
            calls.append((symbols[symbol][0], 0x55a470 + offset + 4 + struct.unpack_from('<i', target, offset)[0]))
    assert len(calls) == 1 and calls[0][0].startswith('?create@?$AbstractFactoryProduct@') and calls[0][1] == 0x420190
    providers.append({'provider': label, 'object_sha256': hashlib.sha256(data).hexdigest(), 'size': len(body), 'target': hex(calls[0][1])})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'archive_sha256': sha(archive),
           'object_sha256': sha(obj), 'flags': flags, 'lifetime': methods, 'createChild_providers': providers,
           'scope': 'Diagnostic only. Existing archive createChild matches original body and direct target; full Instance ABI and runtime binding remain unverified.'}
(root / 'work/2008-06/shared-layouts/instance-link-profile.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS Instance lifetime link profile and duplicate createChild providers')
