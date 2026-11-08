"""Test whether profiler virtual destruction explains Workspace lifetime mismatch."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
base = out / 'NativeWorkspaceSharedLifetime.cpp'
text = base.read_text()
before = 'CodeProfiler(const char* name);\n\tchar data[0xc040];'
after = 'CodeProfiler(const char* name);\n\tvirtual ~CodeProfiler();\n\tchar data[0xc03c];'
assert text.count(before) == 1
text = text.replace(before, after, 1)
if '--notifier' in sys.argv:
    before = 'template<class Class, class Event> class Notifier {\npublic:\n\tNotifier();\n\tvirtual ~Notifier();\n\tchar pad[0x1c];\n};'
    after = 'template<class Class, class Event> class Listener;\nstruct RaiseRange;\ntemplate<class Class, class Event> class __declspec(novtable) Notifier {\n    std::vector<Listener<Class, Event>*> listeners;\n    RaiseRange* raiseRange;\npublic:\n    Notifier();\n    virtual ~Notifier() {}\n    virtual void onAddListener(Listener<Class, Event>*) const {}\n    virtual void onRemoveListener(Listener<Class, Event>*) const {}\n};'
    assert text.count(before) == 1
    text = text.replace(before, after, 1)
source = out / 'NativeWorkspaceLifetimeVariant.cpp'
source.write_text(text)
obj = out / 'NativeWorkspaceLifetimeVariant.obj'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
functions = match.coff_functions(obj.read_bytes())
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address in [('??0Workspace@RBX@@', '005a4d90'), ('??1Workspace@RBX@@', '005a28c0')]:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            calls.setdefault(symbols[index][0], set()).add(value)
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'original_size': len(target), 'exact': match.exact_match(target, targetrefs, body, refs), 'calls': {k: [hex(v) for v in sorted(values)] for k, values in calls.items()}})
if '--notifier' in sys.argv:
    assert all(row['exact'] for row in rows), rows
    for prefix, address in [('??1IMovingManager@RBX@@', '0x614db0'), ('??1IRenderableBucket@RBX@@', '0x5dd2c0'), ('??1VerbContainer@RBX@@', '0x5832e0'), ('??1RootInstance@RBX@@', '0x590630')]:
        assert any(k.startswith(prefix) and v == [address] for k, v in rows[1]['calls'].items()), (prefix, rows[1]['calls'])
receipt = {'scope': 'Inactive hypothesis only: provisional profiler and notifier declarations, not a proven full class layout; no runtime selection.', 'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), 'base_sha256': hashlib.sha256(base.read_bytes()).hexdigest(), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest(), 'methods': rows, 'flags': flags}
suffix = 'profiler-notifier' if '--notifier' in sys.argv else 'profiler'
(root / ('work/2008-06/shared-layouts/workspace-lifetime-' + suffix + '-variant.json')).write_text(json.dumps(receipt, indent=2) + '\n')
print([(row['address'], row['size'], row['original_size'], row['exact']) for row in rows])
