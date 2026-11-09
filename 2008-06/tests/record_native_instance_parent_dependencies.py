"""Verify recovered parenting helpers against original calls, imports and EH."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

run = Path(sys.argv[1])
rows = json.loads((run / 'results.json').read_text())
sha = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
pe = pefile.PE(str(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'))
imports = {entry.address: entry.name.decode() for dll in pe.DIRECTORY_ENTRY_IMPORT
           for entry in dll.imports if entry.name}
targets = {
    '?getFullName@Instance@': (0x5574d0, {'?getFullName@Instance@': 0x5574d0}),
    '?signalDescendentAdded@Instance@': (0x558220, {'?isAncestorOf@Instance@': 0x4c9c50, '?read@?$CopyOnWrite@': 0x4915b0, '?signalDescendentAdded@Instance@': 0x558220}),
    '?signalDescendentRemoving@Instance@': (0x558370, {'?isAncestorOf@Instance@': 0x4c9c50, '?read@?$CopyOnWrite@': 0x4915b0, '?signalDescendentRemoving@Instance@': 0x558370}),
}
verified = []
for filename in ('InstanceFullName.cpp', 'InstanceDescendantPropagation.cpp'):
    row = next(item for item in rows if item['source'].endswith(filename))
    assert sha(row['source']) == row['source_sha256'] and sha(row['object']) == row['object_sha256']
    for path, digest in row['dependencies'].items():
        assert sha(path) == digest, path
    assert all(check['status'] == 'exact' for check in row['checks'])
    raw = Path(row['object']).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    for name, body, refs in match.coff_functions(raw):
        key = next ( (prefix for prefix in targets if name.startswith(prefix)), None)
        if not key:
            continue
        address, expected = targets[key]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs)
        start, section = definitions[name]
        table = sections[section]
        seen = set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset <= len(body) - 4:
                continue
            symbol = symbols[index][0]
            if kind == 20:
                prefix = next((p for p in expected if symbol.startswith(p)), None)
                assert prefix, ('unexpected direct call', symbol)
                actual = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                assert actual == expected[prefix], (symbol, hex(actual))
                seen.add(prefix)
            elif kind == 6 and symbol.startswith('__imp_'):
                actual = struct.unpack_from('<I', target, offset)[0]
                imported = symbol[len('__imp_'):]
                if imported == '__invalid_parameter_noinfo':
                    imported = '_invalid_parameter_noinfo'
                assert imports.get(actual) == imported, (symbol, hex(actual), imports.get(actual))
        assert seen == set(expected), (name, seen)
        for offset, value, _ in match.coff_data_refs(raw, name):
            actual = struct.unpack_from('<I', target, offset)[0]
            assert pe.get_data(actual - pe.OPTIONAL_HEADER.ImageBase, len(value)) == value
        eh = ROOT / ('work/2008-06/instance-dependency-eh-%08x.json' % address)
        subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/audit_native_eh_graph.py'), row['object'], '%08x' % address, name, '--output', str(eh)], cwd=ROOT, check=True)
        verified.append({'address': hex(address), 'name': name, 'object_sha256': sha(row['object']), 'eh_sha256': sha(eh)})
assert len(verified) == len(targets)
output = ROOT / 'work/2008-06/instance-parent-dependencies-proof.json'
output.write_text(json.dumps({'run': str(run), 'scope': 'Local bodies, direct calls, imports, local literals and EH; indirect calls, selected providers, full ABI and runtime unproven.', 'verified': verified}, indent=2) + '\n', encoding='utf-8')
print('PASS parenting helpers: direct calls, imports, literals and EH')
