"""Verify native document history handlers with their MSVC noinline profile."""
import hashlib, json, struct, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
BASE = json.loads((ROOT / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [f for f in BASE['flags'] if f != '/c' and not f.startswith('/Fo')] + ['/P']
pre = OUT / 'document-history-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
body = (pre / 'NativeDocumentLayout.i').read_text(errors='replace')
assert 'setActiveDocument(bool, CRobloxDoc*)' in body
assert 'activeRobloxDoc' in body
profile = ('const _Elem * c_str() const', 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );')
for needle in profile:
    assert body.count(needle) == 1
    body = body.replace(needle, '__declspec(noinline) ' + needle)
source = OUT / 'NativeDocumentHistoryProfile.cpp'
source.write_text(body)
obj = OUT / 'NativeDocumentHistoryProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, OUT)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
delete_name, delete_body, delete_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?DeleteContents@CRobloxDoc'))
delete_target, delete_target_refs, _ = match.target('2008-06', '004513c0')
assert match.exact_match(delete_target, delete_target_refs, delete_body, delete_refs)
delete_start, delete_section = definitions[delete_name]
delete_table = sections[delete_section]
delete_bindings = {}
for i in range(delete_table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', raw, delete_table[5] + i * 10)
    offset -= delete_start
    if not 0 <= offset < len(delete_body) - 3:
        continue
    symbol = symbols[symbol_index][0]
    if symbol.startswith('?activeRobloxDoc@@'):
        delete_bindings['active_document'] = hex(struct.unpack_from('<I', delete_target, offset)[0])
    if symbol.startswith('?setActiveDocument@@') and kind == 20:
        delete_bindings['activation'] = hex((0x4513c0 + offset + 4 + struct.unpack_from('<i', delete_target, offset)[0]) & 0xffffffff)
assert delete_bindings == {'active_document': '0x96c238', 'activation': '0x405aa0'}, delete_bindings
rows = []
for address, destination in [('00453670',0x58a130),('004538b0',0x588780),('00453750',0x587b70),('00453990',0x587a90),('00453af0',0x4153b0),('00454040',0x4530f0),('00454300',0x495e60),('00454170',0x49ac80),('00450a70',0x5757d0),('00450c00',0x5757e0),('00454490',0x42de90),('004547b0',0x5a9120),('00450d90',0x5757f0),('00454920',0x5a6bc0),('004545d0',0x5a86c0),('0044f7c0',0x401180),('0044fc50',0x44f500),('0044fcc0',0x44f660),('0044fd30',0x44eeb0),('00455580',0x5a0de0),('00450f30',0x46b9d0)]:
    name, candidate, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?handle_'+address[2:]+'@CRobloxDoc'))
    target, target_refs, _ = match.target('2008-06', address)
    assert match.exact_match(target, target_refs, candidate, refs), address
    start, section = definitions[name]
    table = sections[section]
    edges = {}
    for i in range(table[7]):
        offset, symbol_index, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
        offset -= start
        if 0 <= offset <= len(candidate)-4 and kind == 20:
            edges[symbols[symbol_index][0]] = hex((int(address,16) + offset + 4 + struct.unpack_from('<i',target,offset)[0]) & 0xffffffff)
    assert hex(destination) in edges.values(), address
    if address == '00455580': assert {'0x554da0','0x578ef0','0x593500','0x5a0de0'} <= set(edges.values())
    if address == '004545d0': assert {'0x5a86c0','0x5c8940','0x5a6bc0','0x5a9120','0x569620','0x5693a0'} <= set(edges.values())
    if address == '0044fd30': assert '0x4060d0' in edges.values()
    if address == '0044f7c0':
        assert target[0xc3:0xc6] == bytes.fromhex('8b 51 20')  # IWorkspace slot 8
    rows.append(dict(address=address,size=len(candidate),direct_calls=edges))
gc_name, gc_body, gc_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?gc@ScriptContext@RBX@@'))
gc_target, gc_target_refs, _ = match.target('2008-06','005a86c0')
assert match.exact_match(gc_target,gc_target_refs,gc_body,gc_refs)
allocator_source = ROOT/'rebuild/2008-06/native-classes/LuaAllocatorStats.cpp'
allocator_obj = OUT/'NativeLuaAllocatorStats.obj'
allocator_flags = [f for f in BASE['flags'] if not f.startswith('/Fo') and not f.endswith('NativeDocumentLayout.cpp')] + ['/Fo'+str(allocator_obj),str(allocator_source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', allocator_flags, OUT)
assert code == 0, log
allocator_name, allocator_body, allocator_refs = next(x for x in match.coff_functions(allocator_obj.read_bytes()) if x[0].startswith('?getHeapStats@LuaAllocator@@'))
allocator_target, allocator_target_refs, _ = match.target('2008-06','005c8940')
assert match.exact_match(allocator_target,allocator_target_refs,allocator_body,allocator_refs)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
inputs = [Path(__file__), ROOT/'rebuild/2008-06/native-classes/CRobloxDoc.cpp', ROOT/'rebuild/2008-06/native-headers/CRobloxDoc.h', ROOT/'rebuild/2008-06/native-headers/CWorkspace.h', ROOT/'rebuild/2008-06/native-headers/RobloxLib.h', ROOT/'rebuild/2008-06/native-headers/CSaveToRobloxDialog.h', ROOT/'rebuild/2008-06/native-headers/v8datamodel/ChangeHistoryService.h', ROOT/'rebuild/2008-06/native-headers/v8datamodel/Selection.h', ROOT/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h', ROOT/'rebuild/2008-06/native-headers/script/ScriptContext.h', ROOT/'tools/rbxgs/Client/App/include/util/Log.h', ROOT/'tools/rbxgs/Client/App/include/v8datamodel/Workspace.h', ROOT/'tools/rbxgs/Client/App/include/v8xml/SerializerV2.h', ROOT/'rebuild/2008-06/tests/NativeDocumentLayout.cpp']
inputs.append(allocator_source)
receipt = dict(sources={str(p.relative_to(ROOT)):sha(p) for p in inputs},object_sha256=sha(obj),profile=profile,preprocess_flags=flags,compile_flags=compile_flags,methods=rows,delete_contents_binding=delete_bindings,heap_dependencies={'gc':{'address':'005a86c0','symbol':gc_name,'size':len(gc_body)},'allocator':{'address':'005c8940','symbol':allocator_name,'size':len(allocator_body),'object_sha256':sha(allocator_obj),'flags':allocator_flags}},scope='Inactive compiler proof with provisional Doc names normalized to existing ActiveDocument symbols; no runtime integration credit.')
(ROOT/'work/2008-06/shared-layouts/document-history-working.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS: twenty-one Doc command bodies and direct targets')
