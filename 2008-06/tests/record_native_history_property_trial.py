"""Test history property operations against the isolated 2008 descriptor candidate."""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/property-abi-trial'
(out / 'reflection').mkdir(parents=True, exist_ok=True)
candidate = root / 'tools/rbxgs/Client/App/roc_property_genuine_all_variant_overrides_header4b48a3f3f80fea74.cpp'
overlay = out / 'reflection/property.h'
property_text = re.sub(r'\bVariant\b', 'Value', candidate.read_text())
getset_start = property_text.index('class GetSet\n')
at = property_text.index('virtual bool isReadOnly() const = 0;', getset_start)
at += len('virtual bool isReadOnly() const = 0;')
property_text = property_text[:at] + '\n                virtual bool isWriteOnly() const = 0;' + property_text[at:]
overlay.write_text(property_text)
reflection_header = root / 'tools/rbxgs/Client/App/include/reflection/reflection.h'
reflection_overlay = out / 'reflection/reflection.h'
original_reflection = reflection_header.read_text()
assert original_reflection.count('class IIDREF') == 1
reflection_text = original_reflection.replace('class IIDREF', 'class __declspec(novtable) IIDREF')
getset_start = reflection_text.index('class GetSetImpl : public GetSet')
at = reflection_text.index('virtual ReturnType getValue(', getset_start)
reflection_text = reflection_text[:at] + 'virtual bool isWriteOnly() const { return false; }\n\t\t\t\t' + reflection_text[at:]
ref_start = reflection_text.index('class RefPropDescriptor : public RefPropertyDescriptor')
at = reflection_text.index('virtual bool isReadOnly() const;', ref_start) + len('virtual bool isReadOnly() const;')
reflection_text = reflection_text[:at] + '''
            virtual bool isWriteOnly() const { return getset->isWriteOnly(); }
            virtual void getVariant(const DescribedBase*, Value&) const;
            virtual void setVariant(DescribedBase*, const Value&) const;''' + reflection_text[at:]
reflection_overlay.write_text(reflection_text)
source = root / 'rebuild/2008-06/native-classes/HistoryItemPropertyTrial.cpp'
obj = out / 'HistoryItemPropertyTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/change-history-layout-working.json').read_text())
flags = [x for x in base['flags']['state'] if not x.startswith('/Fo') and not x.endswith('HistoryItemState.cpp')]
flags.insert(0, '/I' + str(out))
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for address, prefix, expected in [
    ('00589410', '?captureProperty@HistoryItem@', [('??0Value@Reflection@RBX@@', 0x594ac0), ('??A?$map@', 0x589000), ('??4Value@Reflection@RBX@@', 0x42d0a0)]),
    ('005872a0', '?applyProperty@HistoryItem@', []),
    ('005884d0', '?unplayProperty@HistoryItem@', [('?find@?$_Tree@V?$_Tmap_traits@PAVInstance', 0x587ce0), ('?find@?$_Tree@V?$_Tmap_traits@PBVPropertyDescriptor', 0x591bd0), ('?setParent@Instance@RBX@@', 0x55a8f0)]),
]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, len(body), len(target))
    start, index = definitions[name]
    section = sections[index]
    edges = {}
    parent_refs = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if 0 <= offset < len(body)-4 and kind == 20:
            edges[symbols[symbol][0]] = int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]
        if address == '005884d0' and 0 <= offset < len(body)-4 and kind == 6 and symbols[symbol][0].startswith('?propParent@Instance@RBX@@'):
            parent_refs.append(struct.unpack_from('<I', target, offset)[0])
    if address == '005884d0':
        assert parent_refs == [0x973d34]
    for symbol, destination in expected:
        assert any(k.startswith(symbol) and v == destination for k, v in edges.items()), (address, symbol, edges)
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'direct_calls': {k: hex(v) for k, v in edges.items()}})

fixture = root / 'rebuild/2008-06/tests/NativeParentDescriptorTrial.cpp'
fixture_obj = out / 'NativeParentDescriptorTrial.obj'
fixture_flags = flags[:-2] + ['/Fo' + str(fixture_obj), str(fixture)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', fixture_flags, out)
assert code == 0, log
raw = fixture_obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
for address, prefix, required in [
    ('00559920', '??$?0P8Instance@', [('??$singleton@PAVInstance@', 0x557700), ('?classDescriptor@', 0x40ad80), ('??0PropertyDescriptor@', 0x56c650), ('??$getset@', 0x557fe0)]),
    ('00631180', '??_G?$RefPropDescriptor@VInstance', [('??3@', 0x6a067a)]),
    ('00565960', '?isWriteOnly@?$RefPropDescriptor@VInstance', []),
]:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix) and 'RefPropDescriptor@VInstance' in x[0])
    target, targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(target, targetrefs, body, refs), (address, len(body), len(target))
    start, index = definitions[name]
    section = sections[index]
    edges = {}
    vtables = []
    for i in range(section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
        offset -= start
        if 0 <= offset < len(body)-4 and kind == 20:
            edges[symbols[symbol][0]] = int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]
        if address == '00559920' and 0 <= offset < len(body)-4 and kind == 6 and symbols[symbol][0].startswith('??_7?$RefPropDescriptor@'):
            vtables.append(struct.unpack_from('<I', target, offset)[0])
    for symbol, destination in required:
        assert any(k.startswith(symbol) and v == destination for k, v in edges.items()), (address, symbol, edges)
    if address == '00559920':
        assert vtables == [0x82d768, 0x82d760]
    rows.append({'address': address, 'symbol': name, 'size': len(body), 'direct_calls': {k: hex(v) for k, v in edges.items()}})

vname = next(n for n in definitions if n.startswith('??_7?$RefPropDescriptor@VInstance@RBX@@V12@@Reflection@RBX@@6BRefPropertyDescriptor'))
start, index = definitions[vname]
section = sections[index]
slots = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    if offset >= start and kind == 6:
        slots[(offset-start)//4] = symbols[symbol][0]
for index, method in [(2, 'isWriteOnly'), (4, 'getVariant'), (5, 'setVariant')]:
    assert slots[index].startswith('?' + method + '@?$RefPropDescriptor@VInstance')
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
baseaddr = pe.OPTIONAL_HEADER.ImageBase
original_slots = [struct.unpack('<I', pe.get_data(0x82d768 + 4*i - baseaddr, 4))[0] for i in range(14)]
assert [original_slots[i] for i in (2, 4, 5)] == [0x565960, 0x585420, 0x5da5b0]
getset_slots = [struct.unpack('<I', pe.get_data(0x82d6f4 + 4*i - baseaddr, 4))[0] for i in range(4)]
assert getset_slots == [0x60a2f0, 0x60a2f0, 0x5cf660, 0x563b00]

sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'candidate_sha256': sha(candidate), 'overlay_sha256': sha(overlay), 'source_sha256': sha(source),
           'observer_sha256': sha(Path(__file__)), 'object_sha256': sha(obj), 'flags': flags, 'methods': rows,
           'reflection_overlay_sha256': sha(reflection_overlay), 'fixture_sha256': sha(fixture), 'fixture_object_sha256': sha(fixture_obj),
           'candidate_slots': slots, 'original_slots': [hex(x) for x in original_slots], 'original_parent_getset_slots': [hex(x) for x in getset_slots],
           'scope': 'Isolated descriptor ABI candidate only. Parent descriptor ctor, deleting dtor and isWriteOnly match; concrete getVariant/setVariant bodies, other descriptor specializations, data bindings and cross-module ABI remain unproven. Never link into live client.'}
(root / 'work/2008-06/shared-layouts/history-property-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS isolated history property methods, parent descriptor lifetime and write-only slot; other ABI remains open')
