"""Compare original Instance signal initialization with the linked donor object."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

archive = root / 'rebuild/2008-06/out/RbxgsApp/linked/linked.lib'
raw = next(data for name, data in libs.archive_members(archive) if str(name) == 'Instance.obj')
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
base = pe.OPTIONAL_HEADER.ImageBase
events = [
    ('event_descendentAdded', '007f2b50', '007fca80', 0x973e40, 0x82da04, 0x82d9c0),
    ('event_descendentRemoving', '007f2b70', '007fcac0', 0x973ca0, 0x82da14, 0x82d9c0),
    ('event_ancestryChanged', '007f2b90', '007fcb00', 0x973c38, 0x82da28, 0x82d9ec),
]
rows = []
for event, initializer, destructor, storage, name_addr, arg_addr in events:
    item = {'symbol': event, 'storage': hex(storage)}
    for marker, address in [('??__E?', initializer), ('??__F?', destructor)]:
        symbol, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(marker + event + '@Instance@'))
        target, targetrefs, _ = match.target('2008-06', address)
        assert match.exact_match(target, targetrefs, body, refs), address
        item['initializer' if marker == '??__E?' else 'destructor'] = {'address': address, 'size': len(body)}
        if marker != '??__E?':
            continue
        strings = {offset: data.split(b'\0', 1)[0].decode('ascii')
                   for offset, data, _ in match.coff_data_refs(raw, symbol) if offset in (1, 6)}
        original_name = pe.get_string_at_rva(name_addr - base).decode('ascii')
        original_arg = pe.get_string_at_rva(arg_addr - base).decode('ascii')
        assert struct.unpack_from('<I', target, 0xb)[0] == storage
        assert struct.unpack_from('<I', target, 1)[0] == arg_addr
        assert struct.unpack_from('<I', target, 6)[0] == name_addr
        assert 0x7f2b50 <= int(address, 16) <= 0x7f2b90
        item.update(original_name=original_name, archive_name=strings[6],
                    original_argument=original_arg, archive_argument=strings[1],
                    strings_match=(strings[6] == original_name and strings[1] == original_arg))
    rows.append(item)
assert [row['strings_match'] for row in rows] == [False, False, True]
source = root / 'rebuild/2008-06/native-classes/InstanceSignalDescriptors.cpp'
out = root / 'rebuild/2008-06/out/native-layouts'
previous = json.loads((root / 'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
flags = [x for x in previous['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
obj = out / 'NativeInstanceSignalDescriptors.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
native = obj.read_bytes()
native_rows = []
for event, initializer, destructor, storage, name_addr, arg_addr in events:
    for marker, address in [('??__E?', initializer), ('??__F?', destructor)]:
        symbol, body, refs = next(x for x in match.coff_functions(native) if x[0].startswith(marker + event + '@Instance@'))
        target, targetrefs, _ = match.target('2008-06', address)
        assert match.exact_match(target, targetrefs, body, refs), address
        if marker == '??__E?':
            strings = {offset: data.split(b'\0', 1)[0].decode('ascii')
                       for offset, data, _ in match.coff_data_refs(native, symbol) if offset in (1, 6)}
            assert strings[1] == pe.get_string_at_rva(arg_addr - base).decode('ascii')
            assert strings[6] == pe.get_string_at_rva(name_addr - base).decode('ascii')
            assert struct.unpack_from('<I', target, 0xb)[0] == storage
            assert int(address, 16) + 0x14 + struct.unpack_from('<i', target, 0x10)[0] == 0x559b10
        native_rows.append({'symbol': symbol, 'address': address, 'size': len(body)})
symbol, body, refs = next(x for x in match.coff_functions(native) if x[0].startswith('??0?$SignalDesc@VInstance@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '00559b10')
assert match.exact_match(target, targetrefs, body, refs)
native_rows.append({'symbol': symbol, 'address': '00559b10', 'size': len(body)})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'archive_sha256': sha(archive), 'instance_object_sha256': hashlib.sha256(raw).hexdigest(),
           'observer_sha256': sha(Path(__file__)), 'events': rows, 'native_source_sha256': sha(source),
           'native_object_sha256': sha(obj), 'native_methods': native_rows, 'native_flags': flags,
           'scope': 'Native candidate matches initializers, cleanup, constructor and strings. Archive defines duplicate globals with wrong strings; runtime ABI and ownership remain unproven.'}
(root / 'work/2008-06/shared-layouts/instance-signal-archive-audit.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native signal data; archive uses two incorrect signal names and argument names')
