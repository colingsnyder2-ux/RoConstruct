"""Verify the inactive native CDeclarationView (object browser declaration pane, CHtmlView subclass): layout test,
exact bodies, every call/data target, the vtable, the CRuntimeClass record and the (empty) message map.
Profile: document-swap flags through the noinline profile for CString operator PCXSTR / IsEmpty and
std::string::c_str (all imported in the original), see declaration_view_profile.py.
Writes work/2008-06/shared-layouts/declaration-view-working.json.
showDescriptor 00435860 stays open: the original reads FunctionDescriptor::signature and SignalDescriptor::signature
inline, the donor reflection/function.h and signal.h declare getSignature() out of line (same blocker as
CMemberTreeView::addFunction); with getSignature inline it is exact (scratch experiment only, not proposed).
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
import native_bind  # noqa: E402
from native_bind import Original, match, rebuild, sha, verify  # noqa: E402
import declaration_view_profile as probe  # noqa: E402

OUT = probe.OUT
tool = rebuild.toolchain(21022)

# 1. layout test
layout = OUT / 'NativeDeclarationViewLayout.obj'
code, log = rebuild.run(tool, 'cl', probe.FLAGS + ['/Fo' + str(layout),
                                                   str(HERE / 'NativeDeclarationViewLayout.cpp')], OUT)
assert code == 0, log[-3000:]

# 2. unit
obj = probe.build()
original = Original()
INTERNAL = {
    '?classCDeclarationView@CDeclarationView@@2UCRuntimeClass@@B': 0x8124e8,
    '?messageMap@?1??GetThisMessageMap@CDeclarationView@@KGPBUAFX_MSGMAP@@XZ@4U3@B': 0x812558,
    '??_7CDeclarationView@@6B@': 0x812bc4,
    '__GUID_332c4425_26cb_11d0_b483_00c04fd90119': 0x81056c,  # IID_IHTMLDocument2 (bytes checked below)
    '__GUID_3050f1ff_98b5_11cf_bb82_00aa00bdce0b': 0x812b54,  # IID_IHTMLElement (bytes checked below)
    # Value::get<std::string> instance, declared only in reflection/type.h; bound by appendArgument's call site.
    '??$get@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Value@Reflection@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x434f20,
    '?showDescriptor@CDeclarationView@@QAEXPBVDescriptor@Reflection@RBX@@@Z': 0x435860,
    '?singleton@Reflection@Metadata@RBX@@SA?AV?$shared_ptr@VReflection@Metadata@RBX@@@boost@@XZ': 0x445020,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVMember@213@ABVPropertyDescriptor@13@@Z': 0x443ab0,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVMember@213@ABVFunctionDescriptor@13@@Z': 0x443b00,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVMember@213@ABVSignalDescriptor@13@@Z': 0x443b50,
    '?lookup@Reflection@Metadata@RBX@@QBEPAVClass@213@ABVClassDescriptor@13@_N@Z': 0x443210,
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,
    '??1?$shared_ptr@VReflection@Metadata@RBX@@@boost@@QAE@XZ': 0x600660,
}
METHODS = [
    ('??0CDeclarationView@@QAE@XZ', 0x434500),
    ('??1CDeclarationView@@UAE@XZ', 0x434570),
    ('??_GCDeclarationView@@UAEPAXI@Z', 0x434620),
    ('?CreateObject@CDeclarationView@@SGPAVCObject@@XZ', 0x434640),
    ('?GetRuntimeClass@CDeclarationView@@UBEPAUCRuntimeClass@@XZ', 0x433380),
    ('?_GetBaseClass@CDeclarationView@@KGPAUCRuntimeClass@@XZ', 0x433370),
    ('?GetMessageMap@CDeclarationView@@MBEPBUAFX_MSGMAP@@XZ', 0x4338c0),
    ('?OnInitialUpdate@CDeclarationView@@UAEXXZ', 0x434550),
    ('?OnDocumentComplete@CDeclarationView@@UAEXPBD@Z', 0x4346b0),
    ('?setContent@CDeclarationView@@QAEXPBVItem@Metadata@Reflection@RBX@@PBD1@Z', 0x434020),
    ('?showDescriptor@CDeclarationView@@QAEXPBVDescriptor@Reflection@RBX@@@Z', 0x435860),
    ('?appendArgument@@YAXAAHAAV?$basic_string', 0x435550),
    ('??$for_each@V?$_Const_iterator@$00@?$list@UItem@SignatureDescriptor', 0x435630),
]
present = {n for n, b, r in match.coff_functions(obj.read_bytes())}
def resolve(rows):
    return [(n if n in present else next(p for p in sorted(present) if p.startswith(n)), a) for n, a in rows]
METHODS = resolve(METHODS)
OWN = dict(METHODS)
OWN['??_ECDeclarationView@@UAEPAXI@Z'] = 0x434620  # weak alias of ??_G (no array new of the class)
# ATL bodies owned by other units in the original, emitted here as COMDATs: exact copies prove the binding.
DEPENDENCIES = [('??0CComBSTR@ATL@@QAE@PBD@Z', 0x401180), ('??4CComVariant@ATL@@QAEAAV01@PBD@Z', 0x415d70)]
OWN.update(DEPENDENCIES)
rows = verify(original, obj, METHODS, INTERNAL, OWN)
dependency_rows = []
for name, address in DEPENDENCIES:
    site_only = {}
    for _ in range(8):
        try:
            r = verify(original, obj, [(name, address)], dict(INTERNAL, **site_only), OWN)
            break
        except AssertionError as e:
            _, symbol, value = e.args[0]
            site_only[symbol] = int(value, 16)
    r[0].update(role='dependency body (binding proof; owned by another unit)', call_site_only={k: hex(v) for k, v in site_only.items()})
    dependency_rows += r

# GUID data behind the two __uuidof references
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
for name in ('__GUID_332c4425_26cb_11d0_b483_00c04fd90119', '__GUID_3050f1ff_98b5_11cf_bb82_00aa00bdce0b'):
    hexs = name[7:].split('_')
    guid = struct.pack('<IHH', int(hexs[0], 16), int(hexs[1], 16), int(hexs[2], 16)) + bytes.fromhex(hexs[3] + hexs[4])
    assert original.data(INTERNAL[name], 16) == guid, name

# 3. vtable 00812bc4 (140 slots): own slots 0, 1, 12, 91, 127; the rest CHtmlView/CView imports or shared bodies
def relocations(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]
count = 140
name = '??_7CDeclarationView@@6B@'
start, section = definitions[name]
slots = {(offset - start) // 4: symbols[index][0] for offset, index, _ in relocations(section) if start <= offset < start + count * 4}
values = struct.unpack('<%dI' % count, original.data(0x812bc4, count * 4))
assert len(slots) == count, len(slots)
vt = {'verified': 0, 'imported': 0, 'shared_bodies': {}, 'unverified': {}}
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
for slot, symbol in sorted(slots.items()):
    value = values[slot]
    if symbol in OWN:
        assert OWN[symbol] == value, (slot, symbol, hex(value))
        vt['verified'] += 1
        continue
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == native_bind.plain(symbol), (slot, symbol, hit)
        vt['verified'] += 1; vt['imported'] += 1
        continue
    t, tr, _ = match.target('2008-06', '%08x' % value)
    b = bodies.get(symbol)
    if b and match.exact_match(t, tr, b[0], b[1]):
        vt['shared_bodies'][slot] = (symbol, hex(value)); vt['verified'] += 1
    else:
        vt['unverified'][slot] = (symbol, hex(value))
rtti, off = original.vtable_class(0x812bc4)
assert rtti == '.?AVCDeclarationView@@' and off == 0, (rtti, off)

# 4. CRuntimeClass 008124e8: name, size 0x114, schema 0xffff, CreateObject 00434640, base getter 00433370
rec = struct.unpack('<IiIIII', original.data(0x8124e8, 24))
assert original.string(rec[0]) == 'CDeclarationView' and rec[1:5] == (0x114, 0xffff, 0x434640, 0x433370), rec
assert original.imported(0x6a10c4)[1] == '?GetThisClass@CHtmlView@@SGPAUCRuntimeClass@@XZ'
start, section = definitions['?classCDeclarationView@CDeclarationView@@2UCRuntimeClass@@B']
mine = struct.unpack_from('<IiIIII', raw, sections[section][4] + start)
assert mine[1:3] == (0x114, 0xffff), mine

# 5. message map 00812558: CHtmlView::GetThisMessageMap import, no entries (terminator only)
base_getter, entries = struct.unpack('<II', original.data(0x812558, 8))
assert original.imported(base_getter)[1] == '?GetThisMessageMap@CHtmlView@@KGPBUAFX_MSGMAP@@XZ'
assert struct.unpack('<6I', original.data(entries, 24)) == (0,) * 6
start, section = definitions['?_messageEntries@?1??GetThisMessageMap@CDeclarationView@@KGPBUAFX_MSGMAP@@XZ@4QBUAFX_MSGMAP_ENTRY@@B']
assert struct.unpack_from('<6I', raw, sections[section][4] + start) == (0,) * 6

paths = [Path(__file__), HERE / 'declaration_view_profile.py', ROOT / 'rebuild/2008-06/native-classes/CDeclarationView.cpp',
         ROOT / 'rebuild/2008-06/native-headers/CDeclarationView.h', HERE / 'NativeDeclarationViewLayout.cpp',
         ROOT / 'rebuild/2008-06/native-headers/reflection/function.h',
         ROOT / 'rebuild/2008-06/native-headers/reflection/signal.h',
         ROOT / 'rebuild/2008-06/native-headers/reflection/enumconverter.h']
result = {'class': 'CDeclarationView', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'original_sha256': sha(original.path),
          'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
          'layout_obj': sha(layout), 'unit_obj': sha(obj), 'methods': rows, 'dependencies': dependency_rows,
          'vtable': dict(vt, address='00812bc4', slots=count), 'runtime_class': '008124e8', 'message_map': '00812558',
          'layout': {'sizeof': '0x114', 'base': 'CHtmlView (0xf4)', 'document': '0xf4 (CComQIPtr<IHTMLDocument2>)',
                     'declaration': '0xf8', 'ownerDiv': '0xfc', 'owner': '0x100', 'summaryDiv': '0x104', 'summary': '0x108',
                     'deprecatedElement': '0x10c', 'preliminaryElement': '0x110 (CComQIPtr<IHTMLElement>)'},
          'open': ['Metadata lookup providers and Value::get<std::string> remain unresolved in the diagnostic link.']}
(ROOT / 'work/2008-06/shared-layouts/declaration-view-working.json').write_text(json.dumps(result, indent=1) + '\n')
print('PASS native CDeclarationView: %d exact bodies, targets verified' % len(rows))
print(json.dumps({'exact': [r['address'] for r in rows], 'dependencies': [(r['address'], r['exact']) for r in dependency_rows],
                  'vtable': {k: vt[k] for k in ('verified', 'imported')}, 'vtable_shared': vt['shared_bodies'],
                  'vtable_unverified': vt['unverified']}, indent=1))
