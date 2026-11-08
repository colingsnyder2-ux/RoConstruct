"""Verify original axis-command constructors and RTTI bindings."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeAxisCommandsTrial.cpp'
header = root / 'rebuild/2008-06/native-headers/StandardVerbs.h'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
obj = out / 'NativeAxisCommandsTrial.obj'
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
for cls, address, label in [('RotateSelectionVerb',0x57f650,'SelectionRotate'), ('TiltSelectionVerb',0x57f680,'SelectionTilt'), ('PrimaryControllerCommand',0x57f6b0,'Controller1'), ('SecondaryControllerCommand',0x57f6e0,'Controller2')]:
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
    assert lookup('??0RotateAxisCommand@RBX@@' if 'SelectionVerb' in cls else '??0ControllerCommand@RBX@@') == (0x57f450 if 'SelectionVerb' in cls else 0x57f4c0)
    literal = lookup('??_C@')
    assert pe.get_string_at_rva(literal-image) == label.encode('ascii')
    vtable = lookup('??_7'+cls+'@RBX@@')
    type_descriptor = readptr(readptr(vtable-4)+12)
    assert pe.get_string_at_rva(type_descriptor+8-image) == ('.?AV'+cls+'@RBX@@').encode('ascii')
    rows.append({'class':cls,'address':hex(address),'size':len(body),'label':label,'literal':hex(literal),'vtable':hex(vtable),'type_descriptor':hex(type_descriptor)})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'header_sha256':sha(header),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),'flags':flags,'methods':rows,'scope':'Inactive trials. Original RTTI names checked; vtable slots, lifetime and runtime ABI remain unproven.'}
(root / 'work/2008-06/shared-layouts/axis-command-constructors-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS four axis-command constructors, labels and RTTI')
