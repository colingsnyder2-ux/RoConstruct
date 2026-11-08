"""Verify inactive camera history lookup and dispatch against original."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/native-classes/CameraHistory.cpp'
obj = out / 'NativeCameraHistory.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix, address, expected in [
        ('??$find@VChangeHistoryService@RBX@@@ServiceProvider@RBX@@SAPAV', 0x58a9e0, [('___RTDynamicCast', 0x6a17c6), ('??_R0?AVInstance@RBX@@@8', 0x92907c), ('??_R0?AVServiceProvider@RBX@@@8', 0x92e15c), ('??$find@VChangeHistoryService@RBX@@@ServiceProvider@RBX@@QBE', 0x452a00)]),
        ('?recordCameraHistory@RBX@@', 0x58c5c0, [('??$find@VChangeHistoryService@RBX@@@ServiceProvider@RBX@@SAPAV', 0x58a9e0), ('?commit@ChangeHistoryService@RBX@@', 0x58c2c0)])]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, targetrefs, body, refs)
    start, section = definitions[name]
    table = sections[section]
    bindings = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i)
        offset -= start
        if 0 <= offset < len(body) - 3:
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings[symbols[index][0]] = value
    for key, value in expected:
        assert any(k.startswith(key) and v == value for k, v in bindings.items()), (key, bindings)
    rows.append({'address': hex(address), 'symbol': name, 'size': len(body), 'exact': True, 'bindings': {k: hex(v) for k, v in bindings.items()}})
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
for address, expected in [(0x92907c, b'.?AVInstance@RBX@@'), (0x92e15c, b'.?AVServiceProvider@RBX@@')]:
    assert pe.get_string_at_rva(address + 8 - pe.OPTIONAL_HEADER.ImageBase) == expected
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive lookup and history dispatch match; history ownership, class lifetimes and runtime remain unproven.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/camera-history-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native camera history lookup and dispatch')
