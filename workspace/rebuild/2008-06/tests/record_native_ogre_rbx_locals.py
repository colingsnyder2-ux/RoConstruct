"""Verify the exe-local parts of the Ogre 1.4.5 classes the June 2008 client constructs from rgmain.dll (inactive; 2008-06).

ManualObject, Rectangle2D, InstancedGeometry, StaticGeometry, SceneNode, MemoryDataStream, FileStreamDataStream,
RenderQueue and Animation are _OgreExport classes of rgmain.dll: their constructors, destructors and members are imports.
Roblox code constructs them (`new X(...)`, imported constructor through the IAT, then the local vptr stores), so MSVC
emitted local copies of their vftables (??_S), scalar deleting destructors (??_G) and the this-adjusting ??_E thunks of
the secondary vftables into the exe. Those ??_G / ??_E functions are the rows here.

Builds (document-swap flags plus the Ogre 1.4.5 client headers, VS2008 RTM 21022, /fp:fast) from the current header
native-headers/OgreRbxLocals/OgreLocals2008.h (new, non-colliding path: no donor or native header of that path exists and
no other unit includes it, so nothing is shadowed):
  * tests/NativeOgreRbxLocalsLayout.cpp   sizeof / base-offset probes (mov eax, imm32; ret) and nativeNew* scaffolding
                                          that constructs each class with the imported constructor the client calls,
                                          which emits the vftables, ??_G and ??_E thunks.
No native-classes unit: no exe body of these classes is source code (the compiler-generated rows are emitted by the
constructing Roblox units in a client build).

Rows: nine ??_G and three ??_E adjustor thunks (ManualObject +4, Rectangle2D +4 / +0xc8). Every row is relocation-masked
exact against the original and every REL32/DIR32 target is verified: imports by DLL export name, own rows by address (one
address per symbol; the ??_E vector deleting destructor a thunk jumps to is the linker alias of the class's ??_G, checked
against the primary vftable's destructor slot). All twelve vftables are compared slot by slot with the compiled ones
(the original RTTI complete-object locators name the class at the expected offset; every other slot is an rgmain import
thunk), and the RTTI hierarchies are checked. The construction sites prove the allocation sizes, the imported
constructors and the vptr stores; the vftables are referenced only from those sites.
ManualObject's ??_G 00681160 / ??_E 00681180 also appear in ogre-rbx-sky-working.json, but only as pending-build-only
(not counted) rows; they are counted here, from a current-header object.
Writes work/2008-06/shared-layouts/ogre-rbx-locals-working.json. NATIVE_OGRE_RBX_LOCALS_DISCOVER=1 lists unbound targets
and non-exact rows instead of asserting.
"""
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
OGRE = '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
LAYOUT = R / 'tests/NativeOgreRbxLocalsLayout.cpp'
HEADER = R / 'native-headers/OgreRbxLocals/OgreLocals2008.h'
DISCOVER = bool(os.environ.get('NATIVE_OGRE_RBX_LOCALS_DISCOVER'))
NEW = 0x6a0920                          # operator new thunk (mfc90 ??2@YAPAXI@Z)


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i + 1] + [OGRE] + flags[i + 1:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeOgreRbxLocalsLayout', LAYOUT, ['/fp:fast'])
raw = layout_obj.read_bytes()
FUNCS = {n: (b, r) for n, b, r in match.coff_functions(raw)}

STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
# class -> new size, probe key, ??_G, constructor sites [(call address, IAT slot, imported ctor)],
#          vftables [(address, compiled ??_S symbol, RTTI offset, slot holding ??_G or the ??_E thunk, that row)],
#          ??_E thunks [(address, symbol)], expected RTTI bases {name: mdisp}
CLASSES = {
    'ManualObject': dict(
        size=0x1d4, probe='manualObject', ddel=0x681160,
        sites=[(0x680f04, 0x8045e8, '??0ManualObject@Ogre@@QAE@ABV%s@Z' % STR)],
        vtables=[(0x84e58c, '??_SManualObject@Ogre@@6BShadowCaster@1@@', 0, 0, 0x681160),
                 (0x84e574, '??_SManualObject@Ogre@@6BAnimableObject@1@@', 4, 2, 0x681180)],
        thunks=[(0x681180, '??_EManualObject@Ogre@@W3AEPAXI@Z')],
        bases={'ManualObject': 0, 'MovableObject': 0, 'ShadowCaster': 0, 'AnimableObject': 4}),
    'Rectangle2D': dict(
        size=0x194, probe='rectangle2D', ddel=0x6918c0,
        sites=[(0x69127e, 0x804ef4, '??0Rectangle2D@Ogre@@QAE@_N@Z')],
        vtables=[(0x84f24c, '??_SRectangle2D@Ogre@@6BShadowCaster@1@@', 0, 0, 0x6918c0),
                 (0x84f238, '??_SRectangle2D@Ogre@@6BAnimableObject@1@@', 4, 2, 0x6918e0),
                 (0x84f1f4, '??_SRectangle2D@Ogre@@6B@', 0xc8, 0, 0x6918f0)],
        thunks=[(0x6918e0, '??_ERectangle2D@Ogre@@W3AEPAXI@Z'), (0x6918f0, '??_ERectangle2D@Ogre@@WMI@AEPAXI@Z')],
        bases={'Rectangle2D': 0, 'SimpleRenderable': 0, 'MovableObject': 0, 'ShadowCaster': 0, 'AnimableObject': 4,
               'Renderable': 0xc8}),
    'InstancedGeometry': dict(
        size=0x104, probe='instancedGeometry', ddel=0x69af30,
        sites=[(0x69aee6, 0x804a18, '??0InstancedGeometry@Ogre@@QAE@PAVSceneManager@1@ABV%s@Z' % STR)],
        vtables=[(0x84fc0c, '??_SInstancedGeometry@Ogre@@6B@', 0, 11, 0x69af30)],
        thunks=[], bases={'InstancedGeometry': 0}),
    'StaticGeometry': dict(
        size=0xd0, probe='staticGeometry', ddel=0x69adb0,
        sites=[(0x69ad63, 0x804a94, '??0StaticGeometry@Ogre@@QAE@PAVSceneManager@1@ABV%s@Z' % STR)],
        vtables=[(0x84fb7c, '??_SStaticGeometry@Ogre@@6B@', 0, 10, 0x69adb0)],
        thunks=[], bases={'StaticGeometry': 0}),
    'SceneNode': dict(
        size=0x228, probe='sceneNode', ddel=0x69a2e0,
        sites=[(0x69a29c, 0x8046c4, '??0SceneNode@Ogre@@QAE@PAVSceneManager@1@@Z'),
               (0x69a41c, 0x80447c, '??0SceneNode@Ogre@@QAE@PAVSceneManager@1@ABV%s@Z' % STR)],
        vtables=[(0x84f934, '??_SSceneNode@Ogre@@6B@', 0, 0, 0x69a2e0)],
        thunks=[], bases={'SceneNode': 0, 'Node': 0, 'Renderable': 0}),
    'MemoryDataStream': dict(
        size=0x34, probe='memoryDataStream', ddel=0x4dab30,
        sites=[(0x684dfc, 0x804e5c, '??0MemoryDataStream@Ogre@@QAE@PAXI_N@Z'),
               (0x691709, 0x804e5c, '??0MemoryDataStream@Ogre@@QAE@PAXI_N@Z')],
        vtables=[(0x826cc4, '??_SMemoryDataStream@Ogre@@6B@', 0, 0, 0x4dab30)],
        thunks=[], bases={'MemoryDataStream': 0, 'DataStream': 0}),
    'FileStreamDataStream': dict(
        size=0x2c, probe='fileStreamDataStream', ddel=0x6700c0,
        sites=[(0x7ae290, 0x804c50, '??0FileStreamDataStream@Ogre@@QAE@PAV?$basic_ifstream@DU?$char_traits@D@std@@'
                                    '@std@@_N@Z')],
        vtables=[(0x84d1e8, '??_SFileStreamDataStream@Ogre@@6B@', 0, 0, 0x6700c0)],
        thunks=[], bases={'FileStreamDataStream': 0, 'DataStream': 0}),
    'RenderQueue': dict(
        size=0x30, probe='renderQueue', ddel=0x68b780,
        sites=[(0x68b727, 0x80479c, '??0RenderQueue@Ogre@@QAE@XZ')],
        vtables=[(0x84e9b8, '??_SRenderQueue@Ogre@@6B@', 0, 0, 0x68b780)],
        thunks=[], bases={'RenderQueue': 0}),
    'Animation': dict(
        size=0xa8, probe='animation', ddel=0x69a930,
        sites=[(0x69a8ed, 0x804aa0, '??0Animation@Ogre@@QAE@ABV%sM@Z' % STR)],
        vtables=[(0x84fb30, '??_SAnimation@Ogre@@6B@', 0, 0, 0x69a930)],
        thunks=[], bases={'Animation': 0}),
}
# Text references of each vftable (the vptr stores right after the imported constructor calls). The other
# MemoryDataStream stores (references 004da7a0 / 00674c62 / 00674f32 / 00675b37 / 00675f4e) follow further calls of the
# same imported constructor (direct `call [00804e5c]` at 004da798 / 00675f46, `call edi` at 00674c5e / 00674f2e) and
# are listed, not decoded.
VTABLE_REFS = {
    0x84e58c: [0x680f0e], 0x84e574: [0x680f15], 0x84f24c: [0x691286], 0x84f238: [0x69128d], 0x84f1f4: [0x691297],
    0x84fc0c: [0x69aeef], 0x84fb7c: [0x69ad6c], 0x84f934: [0x69a2a4, 0x69a425],
    0x826cc4: [0x4da7a0, 0x674c62, 0x674f32, 0x675b37, 0x675f4e, 0x684e04, 0x691711],
    0x84d1e8: [0x7ae298], 0x84e9b8: [0x68b72f], 0x84fb30: [0x69a8f5],
}
BASE_PROBES = [('manualObjectAnimable', 4), ('rectangle2DAnimable', 4), ('rectangle2DRenderable', 0xc8)]

# ---- layout -------------------------------------------------------------------------------------------------------
probes = [(c['probe'] + 'Size', c['size']) for c in CLASSES.values()] + BASE_PROBES
for probe, value in probes:
    body_, _ = FUNCS['?nativeOgreRbxLocals_%s@@YAHXZ' % probe]
    assert body_ == b'\xb8' + struct.pack('<I', value) + b'\xc3', (probe, body_.hex())

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


ROWS = []
for cls, c in CLASSES.items():
    ROWS.append((c['ddel'], '??_G%s@Ogre@@UAEPAXI@Z' % cls))
    ROWS.extend(c['thunks'])
own = {name: address for address, name in ROWS}
# The vector deleting destructor ??_E<cls>@@UAEPAXI@Z (destructor slot of the primary vftable, target of the adjustor
# thunks) is not emitted: the class is never allocated with new[], so the linker resolves it to the scalar ??_G (weak
# alias). It is bound to the ??_G row; the primary vftable destructor-slot check below confirms the same address.
ALIAS = {'??_E%s@Ogre@@UAEPAXI@Z' % cls: c['ddel'] for cls, c in CLASSES.items()}


def weak_default(symbol):
    """The default symbol of an IMAGE_SYM_CLASS_WEAK_EXTERNAL (105) symbol of the compiled object."""
    pointer, count = struct.unpack_from('<II', raw, 8)
    strings = pointer + 18 * count
    i = 0
    names = []
    while i < count:
        entry = raw[pointer + 18 * i:pointer + 18 * i + 18]
        if entry[:4] == b'\0\0\0\0':
            offset = struct.unpack_from('<I', entry, 4)[0]
            name = raw[strings + offset:raw.index(b'\0', strings + offset)].decode('latin-1')
        else:
            name = entry[:8].rstrip(b'\0').decode('latin-1')
        names.append((i, name, entry[16], entry[17]))
        i += 1 + entry[17]
    index = {i: n for i, n, _, _ in names}
    for i, name, klass, aux in names:
        if name == symbol:
            assert klass == 105 and aux == 1, (symbol, klass, aux)
            return index[struct.unpack_from('<I', raw, pointer + 18 * (i + 1))[0]]
    raise AssertionError(symbol)


for symbol in ALIAS:
    assert weak_default(symbol) == '??_G' + symbol[4:], symbol
UNBOUND = []
binding = {}


def verify(rows, strict=True):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    result = []
    for address, name in rows:
        body, refs = FUNCS[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if nb.LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in ALIAS:
                assert ALIAS[symbol] == value, (name, symbol, hex(value), hex(ALIAS[symbol]))
                how = 'own row (??_E resolved to ??_G)'
            else:
                UNBOUND.append('    %r: %#x,   # in %s' % (symbol, value, name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local': sorted(local)})
        result.append(entry)
    return result


rows = verify(ROWS, not DISCOVER)
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in rows:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert all(r['exact'] for r in rows)

# ---- vftables from the object built with the current header, slot by slot ------------------------------------------
# A __declspec(dllimport) class's exe-local vftables are the ??_S local vftables (with their own ??_R4 locators).


def compiled_vtable(symbol):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


VTABLE_SYMBOLS = sorted(s for s in match._coff_data_index(raw)[2] if s.startswith('??_S'))
assert len(VTABLE_SYMBOLS) == sum(len(c['vtables']) for c in CLASSES.values()), VTABLE_SYMBOLS


def check_vtable(symbol, address, own_slot, own_value):
    out, bad = [], []
    slots = compiled_vtable(symbol)
    # the dword after the last slot is not another slot (an import thunk or a row): the original vftable is not longer
    following = d(address + 4 * len(slots))
    try:
        following_import = original.imported(following)
    except Exception:
        following_import = None
    assert following_import is None and following not in own.values(), (symbol, 'original vftable is longer')
    for i, slot in enumerate(slots):
        value = d(address + 4 * i)
        hit = original.imported(value)
        if slot in own:
            ok, how = own[slot] == value and i == own_slot, 'own row'
        elif slot in ALIAS:
            ok, how = ALIAS[slot] == value and i == own_slot, 'own row (??_E resolved to ??_G)'
        elif hit is not None:
            ok, how = i != own_slot and hit[1] == nb.plain(slot), 'import thunk %s!%s' % hit
        else:
            ok, how = False, 'unbound'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value), how))
    assert not bad, (symbol, bad)
    assert out[own_slot]['original'] == '%08x' % own_value, (symbol, out[own_slot])
    return out


def col(vtable):
    locator = d(vtable - 4)
    return original.string(d(locator + 12) + 8), d(locator + 4)


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


text = next(s for s in original.pe.sections if s.Name.startswith(b'.text'))
text_data, text_va = text.get_data(), original.image + text.VirtualAddress


def text_refs(value):
    hits, start, pattern = [], 0, struct.pack('<I', value)
    while True:
        start = text_data.find(pattern, start)
        if start < 0:
            return hits
        hits.append(text_va + start)
        start += 1


vt, layout = {}, {}
for cls, c in CLASSES.items():
    vt[cls] = {}
    for address, symbol, offset, slot, value in c['vtables']:
        assert symbol in VTABLE_SYMBOLS, (cls, symbol, VTABLE_SYMBOLS)
        vt[cls]['%08x' % address] = check_vtable(symbol, address, slot, value)
        assert col(address) == ('.?AV%s@Ogre@@' % cls, offset), (cls, hex(address), col(address))
        assert text_refs(address) == VTABLE_REFS[address], (cls, hex(address), [hex(h) for h in text_refs(address)])
    primary = c['vtables'][0][0]
    expect = {'.?AV%s@Ogre@@' % name: off for name, off in c['bases'].items()}
    assert bases(primary) == expect, (cls, bases(primary))
    # construction: operator new(size) ... call [__imp_ctor]; mov [reg], primary vftable (+ secondary stores)
    for site, iat, ctor in c['sites']:
        assert original.data(site, 2) == b'\xff\x15' and d(site + 2) == iat, (cls, hex(site))
        assert original.imported(iat)[1] == ctor, (cls, original.imported(iat))
        for address, _, offset, _, _ in c['vtables']:
            assert any(r - (site + 6) in range(0x20) and d(r) == address for r in VTABLE_REFS[address]), (cls, hex(site))
        window = original.data(site - 0x60, 0x60)
        push = (b'\x6a' + bytes([c['size']])) if c['size'] < 0x80 else (b'\x68' + struct.pack('<I', c['size']))
        calls = [k for k in range(len(window) - 4) if window[k] == 0xe8
                 and site - 0x60 + k + 5 + struct.unpack_from('<i', window, k + 1)[0] == NEW]
        assert calls, (cls, hex(site))
        k = calls[-1]
        assert push in window[max(0, k - 8):k], (cls, hex(site), window[max(0, k - 8):k].hex())
    layout[cls] = {'size': hex(c['size']), 'bases': {k: hex(v) for k, v in c['bases'].items()},
                   'construction_sites': ['%08x' % s for s, _, _ in c['sites']],
                   'ctor_imports': sorted({'%08x %s' % (i, n) for _, i, n in c['sites']})}

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, HEADER]
exact = sorted({r['address'] for r in rows if r['exact']})
receipt = {
    'class': 'Ogre::{ManualObject,Rectangle2D,InstancedGeometry,StaticGeometry,SceneNode,MemoryDataStream,'
             'FileStreamDataStream,RenderQueue,Animation} (rgmain.dll _OgreExport classes; exe-local compiler-generated '
             'parts)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': {'layout': layout_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {layout_obj.name: sha(layout_obj)},
    'layout': layout,
    'rows': rows,
    'exact_function_rows': exact,
    'vtables': vt,
    'imports_not_rows': 'constructors, destructors and every other vftable entry are rgmain.dll imports (import thunks '
                        'verified by export name above)',
    'not_double_counted': 'ManualObject ??_G 00681160 / ??_E 00681180 are listed in ogre-rbx-sky-working.json only as '
                          'pending_build_only (exact=false, not counted); none of the other rows appears in any receipt. '
                          'The vftables are bound targets (not rows) in ogre-scene-manager / ogre-rbx-sky / ogre-rbx-node.',
    'proposals': {},
    'scope': 'Inactive. Compiler-generated ??_G / ??_E thunk rows, exact with verified targets; no active build, swap '
             'or credit. nativeNew* are probe scaffolding, not recovered functions.',
}
(ROOT / 'work/2008-06/shared-layouts/ogre-rbx-locals-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Ogre dllimport locals: %d distinct function rows exact (%s); %d vftables verified slot by slot'
      % (len(exact), ', '.join(exact), sum(len(v) for v in vt.values())))
