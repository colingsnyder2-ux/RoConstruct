"""Verify original selection-command constructors and RTTI bindings."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/tests/NativeSelectionCommandsTrial.cpp'
header = root / 'rebuild/2008-06/native-headers/StandardVerbs.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
obj = out / 'NativeSelectionCommandsTrial.obj'
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = match.coff_functions(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
readptr = lambda addr: struct.unpack('<I', pe.get_data(addr-image, 4))[0]
rows = []
for cls, address, label in [('GroupSelectionVerb',0x57e7e0,'Group'), ('WeldSelectionVerb',0x57e810,'WeldSelection'), ('SnapSelectionVerb',0x57e840,'SnapSelection'), ('UngroupSelectionVerb',0x57e870,'UnGroup'), ('DuplicateSelectionVerb',0x57e8a0,'Duplicate'), ('AttachCameraCommand',0x57e950,'AttachCamera'), ('TrackCameraCommand',0x57e980,'TrackCamera'), ('FollowCameraCommand',0x57e9b0,'FollowCamera'), ('WatchCameraCommand',0x57e9e0,'WatchCamera'), ('MoveDownSelectionVerb',0x57ea10,'SelectionDown')]:
    name, body, refs = next(x for x in functions if x[0].startswith('??0'+cls+'@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', f'{address:08x}')
    assert match.exact_match(target, targetrefs, body, refs), cls
    start, index = definitions[name]
    section = sections[index]
    edges = {}
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if not 0 <= offset < len(body)-3: continue
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        edges[symbols[symbol][0]] = value
    def lookup(prefix):
        vals = [v for k,v in edges.items() if k.startswith(prefix)]
        assert len(vals) == 1, (cls, prefix, edges)
        return vals[0]
    assert lookup('??0EditSelectionVerb@RBX@@') == 0x57e730
    literal = lookup('??_C@')
    assert pe.get_string_at_rva(literal-image) == label.encode('ascii')
    vtable = lookup('??_7'+cls+'@RBX@@')
    type_descriptor = readptr(readptr(vtable-4)+12)
    assert pe.get_string_at_rva(type_descriptor+8-image) == ('.?AV'+cls+'@RBX@@').encode('ascii')
    rows.append({'class':cls,'address':hex(address),'size':len(body),'label':label,'literal':hex(literal),'vtable':hex(vtable),'type_descriptor':hex(type_descriptor)})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),'flags':flags,'methods':rows,'scope':'Inactive trials. Original RTTI names checked; vtable slots, lifetime and runtime ABI remain unproven.'}
(root / 'work/2008-06/shared-layouts/selection-command-constructors-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS ten selection-command constructors, labels and RTTI')
