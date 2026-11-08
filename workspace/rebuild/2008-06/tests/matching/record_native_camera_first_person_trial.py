"""Verify inactive camera predicate against original with provisional inline getter."""
import hashlib, json, struct, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
overlay = out / 'camera-character-include/v8datamodel'
overlay.mkdir(parents=True, exist_ok=True)
header = root / 'tools/rbxgs/Client/App/include/v8datamodel/ICharacterSubject.h'
text = header.read_text()
assert text.count('bool getCursorCenterLocked() const;') == 1
patched = overlay / 'ICharacterSubject.h'
patched.write_text(text.replace('bool getCursorCenterLocked() const;', 'bool getCursorCenterLocked() const { return cursorLocked; }'))
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(overlay.parent))
source = root / 'rebuild/2008-06/experiments/trials/NativeCameraFirstPersonTrial.cpp'
obj = out / 'NativeCameraFirstPersonTrial.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(source)], out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?isFirstPersonCamera@Camera@RBX@@'))
target, targetrefs, _ = match.target('2008-06', '005ccb00')
assert match.exact_match(target, targetrefs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + i*10)
    offset -= start
    if not 0 <= offset < len(body)-3: continue
    value = struct.unpack_from('<I', target, offset)[0]
    if kind == 20: value = (0x5ccb00 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    edges[symbols[symbol][0]] = value
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
for label, address in [('Instance',0x92907c), ('ICameraSubject',0x948304), ('ICharacterSubject',0x9516c8)]:
    assert pe.get_string_at_rva(address+8-image) == ('.?AV'+label+'@RBX@@').encode()
    assert any(label in k and v == address for k,v in edges.items()), (label, edges)
assert any('RTDynamicCast' in k and v == 0x6a17c6 for k,v in edges.items()), edges
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'address':'005ccb00','size':len(body),'exact':True,'edges':edges,'source_sha256':sha(source),'header_sha256':sha(header),'overlay_sha256':sha(patched),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'scope':'Inactive isolated profile; getter inlined provisionally. Character constructor/destructor, field semantics, whole layout, data identity and runtime remain unproven. Selected for isolated diagnostic link only.'}
(root / 'work/2008-06/shared-layouts/camera-first-person-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS camera predicate: 71 bytes, three RTTI types, dynamic cast')
