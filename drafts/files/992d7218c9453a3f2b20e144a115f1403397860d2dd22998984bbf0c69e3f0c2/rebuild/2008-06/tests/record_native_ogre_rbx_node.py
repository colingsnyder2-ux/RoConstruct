"""Verify the inactive native Ogre::RbxSceneNode and Ogre::TwoDManager (2008-06; Roblox's exe-local Ogre forks).

Builds (document-swap flags plus the Ogre 1.4.5 client headers, VS2008 RTM 21022, /fp:fast), all from the current native
headers native-headers/OgreRbxNode/RbxSceneNode2008.h and TwoDManager2008.h (new, non-colliding paths: no donor or
native header of these names exists, so nothing is shadowed):
  * tests/NativeOgreRbxNodeLayout.cpp         sizeof/offset probes (mov eax, imm32; ret) and nativeNewRbxSceneNode, which
                                              instantiates the header-inline constructor so that the object carries the
                                              RbxSceneNode vtable and ??_G;
  * native-classes/OgreRbxNodeSceneNode.cpp   RbxSceneNode bodies and the map COMDATs of its block (00681190..006823ff);
  * native-classes/OgreRbxNodeTwoDManager.cpp TwoDManager bodies and the list COMDATs of its block, except render.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports (and import thunks) by DLL export name, string literals by bytes,
vtables by original RTTI names, own symbols by the row proven here, throw infos by their catchable type names, data by
address, bodies folded by the linker onto identical code elsewhere by an exact comparison of the body compiled here,
and the remaining externals by the explicit EXTERNAL map (call sites read in the original disassembly, structure
checked below). One address per symbol. Folded rows are compared and recorded, not counted. Both vtables (RbxSceneNode
0084d30c, 116 slots; TwoDManager 0084e7b4, 3 slots) are compared slot by slot with the objects built here.
Writes work/2008-06/shared-layouts/ogre-rbx-node-working.json. Set NATIVE_OGRE_RBX_NODE_DISCOVER=1 to list unbound
targets and non-exact rows instead of asserting.
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
LAYOUT = R / 'tests/NativeOgreRbxNodeLayout.cpp'
NODE_UNIT = R / 'native-classes/OgreRbxNodeSceneNode.cpp'
TWOD_UNIT = R / 'native-classes/OgreRbxNodeTwoDManager.cpp'
HEADERS = [R / 'native-headers/OgreRbxNode/RbxSceneNode2008.h', R / 'native-headers/OgreRbxNode/TwoDManager2008.h']
DISCOVER = bool(os.environ.get('NATIVE_OGRE_RBX_NODE_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i + 1] + [OGRE] + flags[i + 1:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeOgreRbxNodeLayout', LAYOUT, ['/fp:fast'])
node_obj, node_flags = build('NativeOgreRbxNode_scene_node', NODE_UNIT, ['/fp:fast'])
twod_obj, twod_flags = build('NativeOgreRbxNode_twod', TWOD_UNIT, ['/fp:fast'])
OBJ = {'layout': layout_obj, 'scene_node': node_obj, 'twod': twod_obj}
FLAGS = {'layout': layout_flags, 'scene_node': node_flags, 'twod': twod_flags}

# ---- layout -------------------------------------------------------------------------------------------------------
# RbxSceneNode: new(0x248) at 00674474 / 007ab230; the imported SceneNode is 0x228 (the map constructor runs on +0x228
# in 00674160, the destructor walks +0x228 / head +0x240 / size +0x244). Sphere is the 16-byte value at node +0x10.
# TwoDManager: new(0x58) in 0067bb22; constructor 006831d0 / setup 00682560 / list ctor 00683170 (head +0x50, size
# +0x54); element 0x30 (_Buynode 00682b20 news 0x38 = 2 links + 0x30), colour +0x20, texture +0x24, type +0x28, +0x2c.
SIZES = {'size': 0x248, 'sceneNodeSize': 0x228, 'transforms': 0x228, 'transformMapSize': 0x20, 'sphereSize': 0x10,
         'twoDSize': 0x58, 'twoDSceneManager': 0x4, 'twoDQueueId': 0x8, 'twoDAfterQueue': 0x9, 'twoDFlag': 0xa,
         'twoDTarget': 0xc, 'twoDRenderOp': 0x10, 'twoDVertexBuffer': 0x24, 'twoDIndexBuffer': 0x30, 'twoDQuads': 0x3c,
         'quadSize': 0x30, 'quadColour': 0x20, 'quadTexture': 0x24, 'quadOperationType': 0x28, 'quadMode': 0x2c}
raw = layout_obj.read_bytes()
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?nativeOgreRbxNode_' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def pick(obj, prefix, *contains, suffix=''):
    found = [n for n, _, _ in match.coff_functions(Path(obj).read_bytes())
             if n.startswith(prefix) and n.endswith(suffix) and all(c in n for c in contains)]
    assert len(found) == 1, (prefix, contains, suffix, [x[:100] for x in found])
    return found[0]


TMAP = 'KPAVMatrix4@Ogre@@U?$less@K@std@@'    # std::map<unsigned long, Ogre::Matrix4*>   (+0x228)
SMAP = 'PBXVSphere@Ogre@@U?$less@PBX@std@@'   # std::map<const void*, Ogre::Sphere>       (static, 0097dbc4)
QLIST = '?$list@UQuad@TwoDManager@Ogre@@'     # std::list<TwoDManager::Quad>              (+0x3c)
N, T = node_obj, twod_obj

LAYOUT_ROWS = [
    (0x6741d0, '??_GRbxSceneNode@Ogre@@UAEPAXI@Z'),
]
NODE_ROWS = [
    (0x681190, '?_update@RbxSceneNode@Ogre@@UAEX_N0@Z'),
    (0x6817e0, '?_updateBounds@RbxSceneNode@Ogre@@UAEXXZ'),
    (0x681560, '?_findVisibleObjects@RbxSceneNode@Ogre@@UAEXPAVCamera@2@PAVRenderQueue@2@'
               'PAUVisibleObjectsBoundsInfo@2@_N33@Z'),
    (0x681250, '?merge@VisibleObjectsBoundsInfo@Ogre@@QAEXABVAxisAlignedBox@2@ABVSphere@2@PBVCamera@2@@Z'),
    (0x681f90, '?setTransform@RbxSceneNode@Ogre@@UAEXIABVMatrix4@2@@Z'),
    (0x6818e0, '?getTransform@RbxSceneNode@Ogre@@UBEABVMatrix4@2@K@Z'),
    (0x681a00, '?hasTransform@RbxSceneNode@Ogre@@UBE_NK@Z'),
    (0x682350, '?setSphere@RbxSceneNode@Ogre@@UAEXPAVSubMesh@2@ABVSphere@2@@Z'),
    (0x682040, '?getSphere@RbxSceneNode@Ogre@@UBEABVSphere@2@PBX@Z'),
    (0x682100, '?hasSphere@RbxSceneNode@Ogre@@UBE_NPBX@Z'),
    (0x6822e0, '?initializeSpheres@RbxSceneNode@Ogre@@KAXXZ'),
    (0x6821c0, '??1RbxSceneNode@Ogre@@UAE@XZ'),
    (0x681a50, pick(N, '?insert@?$_Tree@', TMAP, 'QAE?AU?$pair@Viterator')),
    (0x681b40, pick(N, '?insert@?$_Tree@', SMAP, 'QAE?AU?$pair@Viterator')),
    (0x681f00, pick(N, '?find@?$_Tree@', SMAP, 'QAE?AViterator')),
    (0x681360, pick(N, '?_Insert@?$_Tree@', SMAP)),
    (0x681c30, pick(N, '?erase@?$_Tree@', SMAP, suffix='QAE?AViterator@12@Vconst_iterator@12@@Z')),
    (0x681300, pick(N, '?_Buynode@?$_Tree@', SMAP, suffix='@D@Z')),
]
TWOD_ROWS = [
    (0x6831d0, '??0TwoDManager@Ogre@@QAE@XZ'),
    (0x683240, '??1TwoDManager@Ogre@@UAE@XZ'),
    (0x684390, '??_GTwoDManager@Ogre@@UAEPAXI@Z'),
    (0x6843b0, '?renderQueueStarted@TwoDManager@Ogre@@UAEXEABV?$basic_string@DU?$char_traits@D@std@@'
               'V?$allocator@D@2@@std@@AA_N@Z'),
    (0x6843d0, '?renderQueueEnded@TwoDManager@Ogre@@UAEXEABV?$basic_string@DU?$char_traits@D@std@@'
               'V?$allocator@D@2@@std@@AA_N@Z'),
    (0x682560, '?setup@TwoDManager@Ogre@@QAEXPAVSceneManager@2@PAVRenderTarget@2@E_N2@Z'),
    (0x682d60, '?addQuad@TwoDManager@Ogre@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
               'ABVColor4@G3D@@MMMMMMMM@Z'),
    (0x683000, '?primitive@TwoDManager@Ogre@@QAEXW4OperationType@RenderOperation@2@MMMMABVColor4@G3D@@@Z'),
    (0x6830b0, '?outlineRectangle@TwoDManager@Ogre@@QAEXMMMMABVColor4@G3D@@@Z'),
    (0x682b20, pick(T, '?_Buynode@' + QLIST, suffix='@XZ')),
    (0x682b40, pick(T, '?_Tidy@' + QLIST)),
    (0x682b90, pick(T, '?_Buynode@' + QLIST, 'ABUQuad@TwoDManager@Ogre@@@Z')),
    (0x682bd0, pick(T, '?_Incsize@' + QLIST)),
    (0x683170, pick(T, '??0' + QLIST, 'QAE@XZ')),
]
ROWS = {'layout': LAYOUT_ROWS, 'scene_node': NODE_ROWS, 'twod': TWOD_ROWS}

EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    '__CxxThrowException@8': 0x6a158c,
    # TwoDManager::render (4309 bytes, not built here): called by renderQueueStarted 006843bf / renderQueueEnded 006843df.
    '?render@TwoDManager@Ogre@@AAEXXZ': 0x6832b0,
}
DATA = {
    '?spheres@RbxSceneNode@Ogre@@1PAV?$map@PBXVSphere@Ogre@@U?$less@PBX@std@@V?$allocator@U?$pair@QBXVSphere@Ogre@@@std@@@4@@std@@A':
        0x97dbc4,                                                 # initializeSpheres 006822f8 / 00682333
}
THROW_INFO = {}                                                   # symbol -> (address, catchable type), checked below
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
FOLDED = {}                                                       # symbol -> address (bodies compared below)
binding = {}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def throw_info_type(ti):
    array = d(ti + 12)                                            # CatchableTypeArray
    return original.string(d(d(array + 4) + 4) + 8)              # first CatchableType -> TypeDescriptor name


FUNCTIONS = {int(json.loads(l)['addr'], 16) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}
BODIES = {}
for key, obj in OBJ.items():
    for n, b, r in match.coff_functions(Path(obj).read_bytes()):
        BODIES.setdefault(n, (b, r, key))


def try_fold(symbol, value):
    """Bind a call to a body that the linker folded elsewhere: the body compiled here must equal the target exactly."""
    if symbol not in BODIES or value not in FUNCTIONS:
        return False
    body, refs, _ = BODIES[symbol]
    target, target_refs = target_of(value)
    if not match.exact_match(target, target_refs, body, refs):
        return False
    FOLDED.setdefault(symbol, value)
    return FOLDED[symbol] == value


def verify(obj, rows, own, strict=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
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
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'string %r' % literal[:-1].decode('latin-1')
            elif symbol.startswith('__TI'):
                cls = '.?AV' + symbol[symbol.index('?AV') + 3:]
                assert throw_info_type(value) == cls, (name, symbol, hex(value), throw_info_type(value))
                THROW_INFO[symbol] = (value, cls)
                how = 'throw info %s' % cls
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif try_fold(symbol, value):
                how = 'folded body, compared exact'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local': sorted(local)})
        result.append(entry)
    return result


own = {}
for rows in ROWS.values():
    for address, name in rows:
        own.setdefault(name, address)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict) for k, rows in ROWS.items()}

# Folded bodies reached through calls: verify each one's own targets too (exact compare, recorded, not counted).
folded_out, seen = [], set()
while True:
    todo = [(a, s) for s, a in FOLDED.items() if s not in seen]
    if not todo:
        break
    for address, symbol in todo:
        seen.add(symbol)
        obj = OBJ[BODIES[symbol][2]]
        for row in verify(obj, [(address, symbol)], own, strict):
            row['folded_exact'], row['exact'] = row['exact'], False
            row['reason'] = 'folded by the linker onto an identical body outside this block; compared, not counted'
            folded_out.append(row)

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [folded_out]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'], r.get('folded_exact'))
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
assert all(r['folded_exact'] for r in folded_out)

# ---- externals and data: structure of what they bind to -------------------------------------------------------------


def body(address):
    return match.target('2008-06', '%08x' % address)[0]


def calls(address, target):
    code = body(address)
    return any(code[i] == 0xe8 and address + i + 5 + struct.unpack_from('<i', code, i + 1)[0] == target
               for i in range(len(code) - 4))


for symbol, address in list(EXTERNAL.items()) + list(FOLDED.items()):
    assert address in FUNCTIONS, (symbol, hex(address))
assert calls(0x6843b0, 0x6832b0) and calls(0x6843d0, 0x6832b0)          # render
assert body(0x6832b0)[:3] == bytes.fromhex('558bec')                     # render: aligned frame (push ebp; mov ebp, esp)
assert any(v == (0x8d1bc8, '.?AVruntime_error@std@@') for v in THROW_INFO.values())   # getTransform / getSphere
assert original.string(0x84e778) == 'Transform map error' and original.string(0x84e78c) == 'bsphere map error'
# Allocation sizes and constructor calls: operator new(size) shortly before each constructor call site.


def new_before(call_site, ctor, size):
    window = original.data(call_site - 0x60, 0x65)
    assert window[-5] == 0xe8 and call_site + 5 + struct.unpack_from('<i', window, 0x61)[0] == ctor, hex(call_site)
    push = (b'\x6a' + bytes([size])) if size < 0x80 else (b'\x68' + struct.pack('<I', size))
    assert push + b'\xe8' in window and call_site - 0x60 + window.index(push + b'\xe8') + len(push) + 5 + \
        struct.unpack_from('<i', window, window.index(push + b'\xe8') + len(push) + 1)[0] == 0x6a0920, hex(call_site)


new_before(0x67bb39, 0x6831d0, 0x58)                                    # VisualEngine: new(0x58) TwoDManager
assert calls(0x67a7e0, 0x682560)                                        # then setup(sceneManager, target, 100, ...)
for site in (0x6744d1, 0x7ab280):                                       # AdornRbxGfx / 007ab...: new(0x248) RbxSceneNode
    new_before(site, 0x674160, 0x248)

# ---- vtables from the objects built with the current headers, slot by slot ------------------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


def check_vtable(obj, symbol, address):
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        hit = original.imported(value)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            ok, how = slot_names['??_G' + slot[4:]] == value, 'bound (??_G)'
        elif slot in slot_names:
            ok, how = slot_names[slot] == value, 'bound'
        elif hit is not None:
            ok, how = hit[1] == nb.plain(slot), 'import thunk %s!%s' % hit
        else:
            ok, how = False, 'unbound'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value), how))
    assert not bad, (symbol, bad)
    return out


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


vt = {'RbxSceneNode@Ogre': check_vtable(OBJ['layout'], '??_7RbxSceneNode@Ogre@@6B@', 0x84d30c),
      'TwoDManager@Ogre': check_vtable(OBJ['twod'], '??_7TwoDManager@Ogre@@6B@', 0x84e7b4)}
assert len(vt['RbxSceneNode@Ogre']) == 116 and len(vt['TwoDManager@Ogre']) == 3
assert bases(0x84d30c) == {'.?AVRbxSceneNode@Ogre@@': 0, '.?AVSceneNode@Ogre@@': 0, '.?AVNode@Ogre@@': 0,
                           '.?AVRenderable@Ogre@@': 0}
assert bases(0x84e7b4) == {'.?AVTwoDManager@Ogre@@': 0, '.?AVRenderQueueListener@Ogre@@': 0}
# The exe's own Ogre::SceneNode vtable 0084f934 (110 slots, emitted by RbxSceneManager::createSceneNode 0069a260 /
# 0069a300 with ??_G 0069a2e0) is the client-import copy, not a fork: every slot except ??_G is an rgmain.dll import
# thunk, and its slots equal RbxSceneNode's except the four overridden here (0, 64, 86, 87).
scene_node_slots = [d(0x84f934 + 4 * i) for i in range(110)]
assert all(original.imported(v) is not None for i, v in enumerate(scene_node_slots) if i)
assert [i for i in range(110) if scene_node_slots[i] != d(0x84d30c + 4 * i)] == [0, 64, 86, 87]

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, NODE_UNIT, TWOD_UNIT] + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['folded_not_counted'] = folded_out
PROPOSALS = {
    'RbxGraphics/AdornRbxGfx2008.h (owner: Adorn / AdornRbxGfx)':
        'Ogre::RbxSceneNode is now declared in native-headers/OgreRbxNode/RbxSceneNode2008.h (0x248, header-inline '
        'constructor 00674160 (SceneManager*, const String&), vtable 0084d30c with setTransform / getTransform / '
        'hasTransform / setSphere / getSphere / hasSphere at slots 110..115). AdornRbxGfx2008.h can include it in place '
        'of its forward declaration once its units add the Ogre include path (they already do).',
    'Ogre::VisualEngine (exe-local, unowned)':
        'VisualEngine +0x14 is the Ogre::TwoDManager* (new(0x58) 0067bb22, then setup(+0x4 scene manager, +0xc render '
        'target, 100, true, false) 00682560); AdornRbxGfx 0066f920 / 0066f9c0 / 0066fa50 call addQuad 00682d60, '
        'primitive 00683000 and outlineRectangle 006830b0 on it; all declared in OgreRbxNode/TwoDManager2008.h.',
}
receipt = {
    'class': 'Ogre::RbxSceneNode, Ogre::TwoDManager (exe-local Ogre 1.4.5 subclasses)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in OBJ.values()},
    'layout': {k: hex(v) for k, v in SIZES.items()},
    'rows': groups,
    'exact_function_rows': exact,
    'vtables': vt,
    'scene_node_exe_vtable_0084f934': 'client-import copy (import thunks), not a fork; emitted by RbxSceneManager',
    'open': 'Not built: RbxSceneNode constructor 00674160 (header-inline; emitted with AdornRbxGfx, inlined into the '
            'layout probe here), TwoDManager::render 006832b0 (4309 bytes). Ogre::RbxSky (0xd4, ctor 0067fd60 5120 bytes '
            '/ dtor 0067fb50 / ??_G 0067fd40) and Ogre::VisualEngine (0x808, ctor 006786c0, dtor 0067a130, ??_G '
            '0067c4b0) have layout evidence only: RbxSky +0x4c..+0x53 and VisualEngine +0x8 / most of +0x18..+0x7f7 are '
            'not derived, so no declaration is written (no placeholder members).',
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; folded rows not counted; no active build, swap '
             'or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/ogre-rbx-node-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Ogre RbxSceneNode/TwoDManager: %d distinct function rows exact (%s); %d folded rows exact, not '
      'counted; targets and %d vtables verified'
      % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g)) for k, g in groups.items()
                               if k != 'folded_not_counted'),
         sum(1 for r in folded_out if r['folded_exact']), len(vt)))
