"""Check relative Instance descriptor initializer order against original PE."""
import hashlib
import json
from pathlib import Path
import struct
import sys
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match
entries = [
    ('NativeInstanceArchivableDescriptorFull.obj', 'work/2008-06/instance-archivable/CheckInstanceArchivableDescriptor.obj', [('??__E?propArchivable@Instance@', 0x7f28e0)]),
    ('NativeInstanceNameDescriptorFull.obj', 'work/2008-06/instance-name-descriptor/CheckInstanceNameDescriptor.obj', [('??__E?desc_Name@Instance@', 0x7f2a90)]),
    ('NativeInstanceParentDescriptorFull.obj', 'work/2008-06/instance-parent-descriptor/CheckInstanceParentDescriptor.obj', [('??__E?propParent@Instance@', 0x7f2ad0)]),
    ('NativeInstanceSignalDescriptorsFull.obj', 'work/2008-06/instance-signal-complete/CheckInstanceSignalDescriptors.obj', [('??__E?event_childAdded@Instance@', 0x7f2b10), ('??__E?event_childRemoved@Instance@', 0x7f2b30), ('??__E?event_descendentAdded@Instance@', 0x7f2b50), ('??__E?event_descendentRemoving@Instance@', 0x7f2b70), ('??__E?event_ancestryChanged@Instance@', 0x7f2b90), ('??__E?event_propertyChanged@Instance@', 0x7f2bb0)]),
]
exe = ROOT/'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(exe))
rows = []
for build_name, path, expected in entries:
    data = (ROOT/path).read_bytes()
    sections, symbols, _, _ = match._coff_data_index(data)
    actual = []
    for section in sections:
        if section[0] != b'.CRT$XCU':
            continue
        for index in range(section[7]):
            offset, symbol_index, kind = struct.unpack_from('<IIH', data, section[5]+10*index)
            symbol = symbols[symbol_index][0]
            if any(symbol.startswith(prefix) for prefix,_ in expected):
                assert kind == 6
                actual.append((offset, symbol))
    actual.sort()
    assert len(actual) == len(expected)
    for (_, symbol), (prefix, original) in zip(actual, expected):
        assert symbol.startswith(prefix)
        hits = []
        needle = struct.pack('<I', original)
        for section in pe.sections:
            if section.Characteristics & 0x20000000:
                continue
            blob = section.get_data()
            at = 0
            while (index := blob.find(needle, at)) >= 0:
                hits.append(pe.OPTIONAL_HEADER.ImageBase + section.VirtualAddress + index)
                at = index+1
        assert len(hits) == 1, (symbol, hits)
        rows.append({'symbol':symbol, 'initializer':hex(original), 'original_pointer':hex(hits[0]), 'object':build_name})
assert all(int(a['original_pointer'],16) < int(b['original_pointer'],16) for a,b in zip(rows,rows[1:]))
source = (ROOT/'rebuild/2008-06/p6/build_client.py').read_text()
source_section = source[source.index('doc_sources ='):source.index('for index,',source.index('doc_sources ='))]
link_section = source[source.index('native_doc_objects ='):]
for section in (source_section,link_section):
    indexes = [section.index("'"+name+"'") for name,_,_ in entries]
    assert indexes == sorted(indexes), indexes
sha = lambda p: hashlib.sha256((ROOT/p).read_bytes()).hexdigest()
result = {'scope':'Original PE initializer pointer order, native object CRT entries and configured object order only; final linker order and runtime not tested.', 'entries':rows, 'objects':{path:sha(path) for _,path,_ in entries}, 'build_script_sha256':sha('rebuild/2008-06/p6/build_client.py'), 'original_sha256':sha('work/2008-06/original-p4-reference/Roblox.exe')}
out = ROOT/'work/2008-06/instance-init-order.json'
out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print('PASS original and configured native Instance initializer order')
