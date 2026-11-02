"""Rebuild donor Workspace without duplicate default-command definition for link diagnosis."""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts/workspace-source-probe'
out.mkdir(parents=True, exist_ok=True)
original = root / 'rebuild/2008-06/out/RbxgsApp/overlay/App/v8datamodel/Workspace.cpp'
archive_obj = root / 'rebuild/2008-06/out/RbxgsApp/linked/Workspace.obj'
text = original.read_text()
renames={'setDefaultMouseCommand':'setDefaultMouseCommandDonorProfile'}
patched=text
for old,new in renames.items(): patched=patched.replace(old,new)
header=root/'rebuild/2008-06/out/RbxgsApp/overlay/App/include/v8datamodel/Workspace.h'
if not header.exists(): header=root/'tools/rbxgs/Client/App/include/v8datamodel/Workspace.h'
header_text=header.read_text()
for old,new in renames.items(): header_text=header_text.replace(old,new)
header_out=out/'include/v8datamodel/Workspace.h';header_out.parent.mkdir(parents=True,exist_ok=True);header_out.write_text(header_text)
baseline_source = out / 'Workspace.cpp'
filtered_source = out / 'WorkspaceWithoutDefault.cpp'
baseline_source.write_text(text)
filtered_source.write_text(patched)
overlay = (root / 'tools/rbxgs/Client', root / 'rebuild/2008-06/out/RbxgsApp/overlay')
recipe = libs.RECIPES['rbxgs']
includes = [(libs.LIBS / x).resolve() for x in recipe['include'] if x != 'WINSDK']
includes = rebuild._overlaid(includes, [], overlay)[0]
common = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD']
common += ['/D' + x for x in (recipe['defines'] + ' BOOST_ALL_NO_LIB').split()]
common += ['/I' + str(x) for x in includes]
objects = []
for src in (baseline_source, filtered_source):
    obj = out / (src.stem + '.obj')
    flags = (['/I' + str(header_out.parents[1])] if src == filtered_source else []) + common + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
    assert code == 0, log
    objects.append(obj)
norm = lambda name: re.sub(r'\?A0x[0-9a-fA-F]+', '?ANON', name)
def functions(raw):
    return {norm(name): (name, body, refs) for name, body, refs in match.coff_functions(raw)}
def relocations(raw, name, size):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[name]
    section = sections[index]
    values = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if 0 <= offset < size:
            values.append((offset, kind, norm(symbols[symbol][0])))
    return sorted(values)
archive_raw, baseline_raw, filtered_raw = archive_obj.read_bytes(), objects[0].read_bytes(), objects[1].read_bytes()
archive_f, baseline_f, filtered_f = map(functions, (archive_raw, baseline_raw, filtered_raw))
assert archive_f.keys() == baseline_f.keys()
for key in archive_f:
    a, b = archive_f[key], baseline_f[key]
    assert match.exact_match(a[1], a[2], b[1], b[2]), key
    assert relocations(archive_raw, a[0], len(a[1])) == relocations(baseline_raw, b[0], len(b[1])), key
removed = baseline_f.keys() - filtered_f.keys()
assert all(any(k.startswith('?'+name+'@Workspace@RBX@@') for k in removed) for name in renames), removed
added=filtered_f.keys()-baseline_f.keys()
assert all(any(name in k for name in renames.values()) for k in added), added
for key in filtered_f.keys() & baseline_f.keys():
    a, b = baseline_f[key], filtered_f[key]
    assert match.exact_match(a[1], a[2], b[1], b[2]), key
    assert relocations(baseline_raw, a[0], len(a[1])) == relocations(filtered_raw, b[0], len(b[1])), key
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(original), 'observer_sha256': sha(Path(__file__)),
           'donor_header_sha256': sha(header), 'renamed_header_sha256': sha(header_out),
           'archive_object_sha256': sha(archive_obj), 'baseline_object_sha256': sha(objects[0]),
           'filtered_source_sha256': sha(filtered_source), 'filtered_object_sha256': sha(objects[1]),
           'flags': common, 'baseline_functions': len(baseline_f), 'retained_functions': len(filtered_f),
           'removed_functions': sorted(removed),
           'scope': 'Inactive donor ABI diagnostic. Default-command function renamed in local donor profile. All unchanged function bytes and relocation symbols match rebuilt baseline; untouched data, linker selection and runtime compatibility remain unproven.'}
(root / 'work/2008-06/shared-layouts/workspace-filtered-donor-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS donor Workspace rebuild with default-command renamed profile')
