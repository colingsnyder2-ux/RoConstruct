"""Rebuild donor content provider without duplicate getContent for link diagnosis."""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import libs, match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts/content-source-probe'
out.mkdir(parents=True, exist_ok=True)
original = root / 'rebuild/2008-06/glue/rbxgs/glue_content_provider.cpp'
archive_obj = root / 'rebuild/2008-06/out/RbxgsApp/linked/glue_content_provider.obj'
text = original.read_text()
start = text.index('\tstd::auto_ptr<std::istream> ContentProvider::getContent(ContentId id)')
assert text.endswith('\n}\n')
patched = text[:start] + '}\n'
start = patched.index('\tstd::string FileSystem::getCacheDirectory(bool create)')
end = patched.index('\n\t// Cached content', start)
patched = patched[:start] + patched[end:]
baseline_source = out / 'glue_content_provider.cpp'
filtered_source = out / 'glue_without_content_get.cpp'
baseline_source.write_text(text)
filtered_source.write_text(patched)
overlay = (root / 'tools/rbxgs/Client', root / 'rebuild/2008-06/out/RbxgsApp/overlay')
recipe = libs.RECIPES['rbxgs']
include_recipe = libs.RECIPES['rbxgs-net']
includes = [(libs.LIBS / x).resolve() for x in include_recipe['include'] if x != 'WINSDK']
includes = rebuild._overlaid(includes, [], overlay)[0]
includes += [root / 'tools/rbxgs/Client/Network', root / 'tools/rbxgs/Client/RbxView/include']
common = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD']
common += ['/D' + x for x in (recipe['defines'] + ' BOOST_ALL_NO_LIB').split()]
common += ['/I' + str(x) for x in includes]
objects = []
for src in (baseline_source, filtered_source):
    obj = out / (src.stem + '.obj')
    flags = common + ['/Fo' + str(obj), str(src)]
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
assert sum(key.startswith('?getContent@ContentProvider@RBX@@') for key in removed) == 1, removed
assert sum(key.startswith('?getCacheDirectory@FileSystem@RBX@@') for key in removed) == 1, removed
assert not filtered_f.keys() - baseline_f.keys()
for key in filtered_f:
    a, b = baseline_f[key], filtered_f[key]
    assert match.exact_match(a[1], a[2], b[1], b[2]), key
    assert relocations(baseline_raw, a[0], len(a[1])) == relocations(filtered_raw, b[0], len(b[1])), key
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(original), 'observer_sha256': sha(Path(__file__)),
           'archive_object_sha256': sha(archive_obj), 'baseline_object_sha256': sha(objects[0]),
           'filtered_source_sha256': sha(filtered_source), 'filtered_object_sha256': sha(objects[1]),
           'flags': common, 'baseline_functions': len(baseline_f), 'retained_functions': len(filtered_f),
           'removed_functions': sorted(removed),
           'scope': 'Inactive donor ABI diagnostic. All retained function bytes and relocation symbols match rebuilt baseline; untouched data and native runtime compatibility remain unproven.'}
(root / 'work/2008-06/shared-layouts/content-filtered-donor-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS donor content rebuild and getContent removal')
