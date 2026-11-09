"""Compile integrated native Workspace lifetime and verify original code bytes."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts/workspace-lifetime-integrated'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/WorkspaceLifetime.cpp'
headers = root / 'rebuild/2008-06/native-headers'
recipe = libs.RECIPES['rbxgs']
includes = [(libs.LIBS / x).resolve() for x in recipe['include'] if x != 'WINSDK']
includes = rebuild._overlaid(includes, [], (root / 'tools/rbxgs/Client', root / 'rebuild/2008-06/out/RbxgsApp/overlay'))[0]
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD']
flags += ['/D' + x for x in (recipe['defines'] + ' BOOST_ALL_NO_LIB').split() if x != '_RELEASEASSERT']
flags += ['/I' + str(headers)] + ['/I' + str(x) for x in includes]
obj = out / 'WorkspaceLifetime.obj'
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
if code:
    print(log)
    sys.exit(code)
rows = []
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
for prefix, address in [('??0Workspace@RBX@@', '005a4d90'), ('??1Workspace@RBX@@', '005a28c0')]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    start, section = definitions[name]
    table = sections[section]
    bindings = {}
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + index * 10)
        offset -= start
        if kind == 20 and 0 <= offset < len(body) - 3:
            value = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings.setdefault(symbols[symbol][0], set()).add(value)
    rows.append({'symbol': name, 'address': address, 'size': len(body), 'original_size': len(target), 'exact': match.exact_match(target, targetrefs, body, refs), 'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}})
for prefix, address in [('??0?$DescribedNonCreatable@VWorkspace@', 0x5a4280), ('??0VerbContainer@', 0x583460), ('??0IMovingManager@', 0x614dc0), ('??0?$Notifier@VWorkspace@', 0x5e9ec0), ('??$create@VCamera@', 0x45db40), ('??0CodeProfiler@', 0x5c43a0), ('?setName@Instance@', 0x55af90)]:
    assert any(name.startswith(prefix) and hex(address) in values for name, values in rows[0]['bindings'].items()), prefix
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
paths = [source, headers / 'v8datamodel/Workspace.h', headers / 'v8tree/Instance.h',
         headers / 'util/Profiling.h', Path(__file__)]
receipt = {'scope': 'Integrated source/header byte check only; dependencies, link, runtime and full layout remain unproven.', 'sources': {str(p.relative_to(root)): sha(p) for p in paths}, 'object_sha256': sha(obj), 'flags': flags, 'methods': rows}
(root / 'work/2008-06/shared-layouts/workspace-lifetime-integrated.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(rows)
if not all(row['exact'] for row in rows):
    sys.exit(1)
