"""Verify the inactive 2008-06 native rows of the application range 00588000..00594000.

Unit map (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there):
  * ChangeHistoryService unit ..0058c91f: Reflection descriptors, HistoryRecord / ChangeHistoryService members
    (change-history-layout-working.json and the history trials hold matched bodies without counted rows; the
    ChangeHistory* native-classes belong to their owners and are not rebuilt here).
  * TextXmlParser / TextXmlWriter unit 0058c920..0059001f (native v8xml/XmlSerializer.h owner; not built here).
  * RootInstance unit 00590020..005917bb: native-classes/AppUnit588_2008RootInstance.cpp against the committed
    native v8datamodel/RootInstance.h (read-only). Built here.
  * SerializerV2 / ArchiveBinder unit 005917c0..00593bab (metadata-load/v8xml/SerializerV2.h owner; not built).
  * Lua ThreadRef / FunctionRef unit from 00593bb0 (LuaBridge2008 owner; not built here).

Builds: document-swap flags, VS2008 RTM 21022, /fp:fast /U_RELEASEASSERT (see `rejected`). A second, pending build
adds native-headers/part-embedded (the 2008 PartInstance with the embedded Primitive) ahead of the include path and
/DNATIVE_APPUNIT588_PENDING; rows exact only there are recorded exact=false (pending-build-only) and never counted.
Vtable / RTTI checks use the object built from the current headers only.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants and string literals by
bytes, RTTI type descriptors by name, vtables by the complete-object locator class, own symbols by the row proven
here, COMDAT support bodies by exactness at the bound address, the remaining externals by the explicit EXTERNAL map
(evidence name or a row counted by another receipt), local statics by one address per symbol.
A row is counted only when no other receipt counts it (top-level exact_function_rows, or exact_addresses /
exact_unique_addresses / exact method entries for older receipts).
Writes work/2008-06/shared-layouts/app-unit588-2008-working.json.
Set NATIVE_APP_UNIT588_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT / 'app-unit588-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'root': R / 'native-classes/AppUnit588_2008RootInstance.cpp',
}
UNIT = {'root': ['/fp:fast', '/U_RELEASEASSERT']}
PART_EMBEDDED = R / 'native-headers/part-embedded'   # existing opt-in 2008 PartInstance (embedded Primitive at +0x228)
PENDING_INCLUDE = ['/I' + str(PART_EMBEDDED)]
PENDING_DEFINE = ['/DNATIVE_APPUNIT588_PENDING']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT588_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit588-2008-working.json'


def build(name, src, extra=(), include_first=()):
    obj = OUT / (name + '.obj')
    flags = list(include_first) + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS, PENDING_OBJ, PENDING_FLAGS_USED = {}, {}, {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit588_2008_' + key, src, UNIT[key])
    PENDING_OBJ[key], PENDING_FLAGS_USED[key] = build('NativeAppUnit588_2008_' + key + '_pending', src,
                                                      UNIT[key] + PENDING_DEFINE, PENDING_INCLUDE)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

WPV = 'V?$vector@V?$weak_ptr@VPartInstance@RBX@@@boost@@V?$allocator@V?$weak_ptr@VPartInstance@RBX@@@boost@@@std@@@std@@'
SPV = 'V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@'
# ---- externals: address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # Instance / Network (evidence names, or rows of the Players unit: findLocalPlayer 0049ac80 is counted by
    # network-players-working.json)
    '?numChildren@Instance@RBX@@QBEIXZ': 0x48ae20,                                      # computeControllersUsed 00590313
    '?contains@Instance@RBX@@QBE_NPBV12@@Z': 0x5574b0,                                  # moveToPoint
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,                                  # insertRaw / insertCharacterView
    '?getPlayerBackpack@Player@Network@RBX@@QBEPAVBackpack@3@XZ': 0x48c470,             # insertCharacterView 00590d45
    '?findLocalPlayer@Players@Network@RBX@@SAPAVPlayer@23@PBVInstance@3@@Z': 0x49ac80,  # insertCharacterView 00590d37
    '?findLocalCharacter@Players@Network@RBX@@SAPAVModelInstance@3@PBVInstance@3@@Z': 0x49aca0,   # 00590820
    # ModelInstance unit (evidence names)
    '?onDescendentAdded@ModelInstance@RBX@@MAEXPAVInstance@2@@Z': 0x584620,              # 00590168
    '?onDescendentRemoving@ModelInstance@RBX@@MAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x584670,   # 00590187
    '??1ModelInstance@RBX@@UAE@XZ': 0x584790,                                           # ~RootInstance 0059076b
    '?getCameraIgnorePrimitives@ModelInstance@RBX@@UAEXAAV?$vector@PBVPrimitive@RBX@@V?$allocator@PBVPrimitive@RBX@@@std@@@std@@@Z': 0x583570,
    '?getLocation@ModelInstance@RBX@@UBE?BVCoordinateFrame@G3D@@XZ': 0x583cf0,          # vtordisp thunk 005907d0
    '?onCameraNear@ModelInstance@RBX@@UAEXM@Z': 0x5843c0,                               # vtordisp thunk 005907c0
    # Described<ModelInstance>::classDescriptor 00585100 (ModelInstance unit; called first by every Described
    # classDescriptor of a ModelInstance subclass) and ClassDescriptor(ClassDescriptor& base, const char*) 005708f0
    # (Reflection unit, 117 callers).
    '?classDescriptor@?$Described@VModelInstance@RBX@@$1?sModel@2@3PADAV?$FactoryProduct@VModelInstance@RBX@@VPVInstance@2@$1?sModel@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x585100,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,                    # 00591549
    '_atexit': 0x6a17af,                                                                # CRT atexit (915 callers)
    # G3D out of line (call sites in computeCharacterInsertPoint / computeIdeInsertPoint)
    '?clamp@Vector3@G3D@@QBE?AV12@ABV12@0@Z': 0x4a6100,                                 # 005901de (evidence name)
    '?getCoordinateFrame@GCamera@G3D@@QBE?AVCoordinateFrame@2@XZ': 0x5107b0,            # 0059084a
    '?getColumn@Matrix3@G3D@@QBE?AVVector3@2@H@Z': 0x513240,                            # 00590862 (push 2: lookVector)
    '?unitize@Vector3@G3D@@QAEMM@Z': 0x518470,                                          # 00590890 (tolerance argument)
    # tool / Dragger / DragUtilities / MegaDragger (evidence names; toGrid 0060fea0 is counted by app-unit609)
    '?toGrid@Dragger@RBX@@SA?AVVector3@G3D@@ABV34@@Z': 0x60fea0,
    '?computeExtents@DragUtilities@RBX@@SA?AVExtents@2@AB' + WPV + '@Z': 0x60f2d0,
    '?join@DragUtilities@RBX@@SAXAB' + WPV + '@Z': 0x60ed40,                             # insertRaw (only caller)
    '?startDragging@MegaDragger@RBX@@QAEXXZ': 0x60de00,
    '?alignAndCleanParts@MegaDragger@RBX@@QAEXXZ': 0x60df80,
    '?safeMoveYDrop@MegaDragger@RBX@@QAE?AVVector3@G3D@@ABV34@@Z': 0x60e100,
    '?safeMoveNoDrop@MegaDragger@RBX@@QAE?AVVector3@G3D@@ABV34@@Z': 0x60e180,
    '?finishDragging@MegaDragger@RBX@@QAEXXZ': 0x60e780,
    '??1MegaDragger@RBX@@QAE@XZ': 0x60e700,
    '??0MegaDragger@RBX@@QAE@PAVPartInstance@1@AB' + WPV + 'PAVRootInstance@1@@Z': 0x60e630,
    '??0MegaDragger@RBX@@QAE@PAVPartInstance@1@ABV?$vector@PAVPVInstance@RBX@@V?$allocator@PAVPVInstance@RBX@@@std@@@std@@PAVRootInstance@1@@Z': 0x60e540,   # moveToPoint
    '?findParts@PartInstance@RBX@@SAXPAVInstance@2@AA' + WPV + '@Z': 0x59c640,
    # Camera (evidence names)
    '?lookAt@Camera@RBX@@QAEXABVVector3@G3D@@@Z': 0x5cc010,                             # insertIdeView
    '?zoomExtents@Camera@RBX@@QAEXVExtents@2@ABVRect2D@G3D@@W4ZoomType@12@@Z': 0x5ce0d0, # insert3dView
    # STL shared COMDATs placed in other units (ICF: one body for several element types)
    '??0?$vector@PAVPVInstance@RBX@@V?$allocator@PAVPVInstance@RBX@@@std@@@std@@QAE@XZ': 0x4293d0,
    '??0' + WPV[1:] + 'QAE@XZ': 0x4293d0,
    '?push_back@?$vector@PAVPVInstance@RBX@@V?$allocator@PAVPVInstance@RBX@@@std@@@std@@QAEXABQAVPVInstance@RBX@@@Z': 0x4213a0,
    # ServiceProvider::create<T>() const (ServiceProvider-instantiation block 004b3xxx; tail calls 00590db9 /
    # 00590e09 / 00590e59 of the create<T>(const Instance*) rows)
    '??$create@VStarterPackService@RBX@@@ServiceProvider@RBX@@QBEPAVStarterPackService@1@XZ': 0x4b3960,
    '??$create@VTeams@RBX@@@ServiceProvider@RBX@@QBEPAVTeams@1@XZ': 0x4b3b40,
    '??$create@VLighting@RBX@@@ServiceProvider@RBX@@QBEPAVLighting@1@XZ': 0x4b3870,
    # pending-build rows only (insertSpawnLocation)
    '??$create@VTeam@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VTeam@RBX@@@boost@@XZ': 0x409140,
    '?getTeamColor@SpawnLocation@RBX@@QBE?AVBrickColor@2@XZ': 0x5d1ba0,
    '?teamExists@Teams@RBX@@QAE_NVBrickColor@2@@Z': 0x5d5f20,
    '?setTeamColor@Team@RBX@@QAEXVBrickColor@2@@Z': 0x566700,
    '?name@BrickColor@RBX@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x5b61b0,
    # the vector deleting destructor the ??_E adjustor thunks jump to: one body at 005a0910 (??_E and ??_G folded),
    # proven by the ??_G support check below
    '??_ERootInstance@RBX@@MAEPAXI@Z': 0x5a0910,
}
# data symbols verified by their bytes in the original
DATA_BYTES = {
    '?sRootInstance@RBX@@3PADA': (0x9495e4, b'RootInstance\0'),          # classDescriptor 0059152f
    '?zLookDirection@CoordinateFrame@G3D@@2MB': (0x828b60, struct.pack('<f', -1.0)),   # 0059084f
}
# COMDAT bodies emitted in the unit object whose call target is out of line in the original (STL helpers shared with
# other units, the classDescriptor exit destructor): accepted only when the compiled body is relocation-masked exact
# at the bound address (support rows, never counted here). Keys are unique symbol prefixes.
SUPPORT = {
    '??$for_each@V?$_Vector_const_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@': 0x5903f0,   # insertRaw 00590468
    '??1' + WPV[1:] + 'QAE@XZ': 0x590550,                                                  # ~ICameraOwner 00590623
    '??__Ffoo@?1??classDescriptor@?$Described@VRootInstance@RBX@@': 0x7fda60,                # atexit 00591546
}
UNBOUND = []
binding = {}
support_out = {}
# function-local statics: the address each original instruction uses (guard / value)
LOCAL_STATIC_AT = {
    '??_B?1??zero@Vector3@G3D@@SAABV12@XZ@51': 0x96f050, '?v@?1??zero@Vector3@G3D@@SAABV23@XZ@4V23@A': 0x96f044,
    '??_B?1??classDescriptor@?$Described@VRootInstance@RBX@@$1?sRootInstance@2@3PADAVModelInstance@2@@Reflection@RBX@@'
    'SAAAVClassDescriptor@23@XZ@51': 0x975c48,
    '?foo@?1??classDescriptor@?$Described@VRootInstance@RBX@@$1?sRootInstance@2@3PADAVModelInstance@2@@Reflection@RBX@@'
    'SAAAVClassDescriptor@34@XZ@4V534@A': 0x975b88,
}
LOCAL_STATIC = re.compile(r'^(\?\$S\d+@|\?\w+@\?\d+\?\?|\?\?_B\?\d+\?\?)')

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'root': [
        (0x590030, '?setInsertPoint@RootInstance@RBX@@QAEXABVVector3@G3D@@@Z'),
        (0x590070, '?moveSafe@RootInstance@RBX@@AAEXAAVMegaDragger@2@VVector3@G3D@@W4MoveType@12@@Z'),
        (0x5900d0, '?moveSafe@RootInstance@RBX@@AAEXAA' + WPV + 'VVector3@G3D@@W4MoveType@12@@Z'),
        (0x590160, '?onDescendentAdded@RootInstance@RBX@@MAEXPAVInstance@2@@Z'),
        (0x590180, '?onDescendentRemoving@RootInstance@RBX@@MAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z'),
        (0x590190, '?computeIdeInsertPoint@RootInstance@RBX@@ABE?AVVector3@G3D@@XZ'),
        (0x590240, '?moveToIdeInsertPoint@RootInstance@RBX@@AAEXAA' + WPV + '@Z'),
        (0x590300, '?computeControllersUsed@RootInstance@RBX@@ABE?AVControllerTypeArray@2@XZ'),
        (0x590440, '?insertRaw@RootInstance@RBX@@'),
        (0x5905c0, '??0ICameraOwner@RBX@@QAE@XZ'),
        (0x590620, '??1ICameraOwner@RBX@@UAE@XZ'),
        (0x590630, '??1RootInstance@RBX@@MAE@XZ'),
        (0x590780, '??_ERootInstance@RBX@@OBE@AEPAXI@Z'),
        (0x590790, '?getCameraIgnorePrimitives@ModelInstance@RBX@@$4PPPPPPPM@GA@AEX'),
        (0x5907a0, '??_ERootInstance@RBX@@OCE@AEPAXI@Z'),
        (0x5907b0, '??_ERootInstance@RBX@@OEE@AEPAXI@Z'),
        (0x5907c0, '?onCameraNear@ModelInstance@RBX@@$4PPPPPPPM@GA@AEXM@Z'),
        (0x5907d0, '?getLocation@ModelInstance@RBX@@$4PPPPPPPM@GA@BE?BVCoordinateFrame@G3D@@XZ'),
        (0x5907f0, '?onChildControllerChanged@RootInstance@RBX@@MAEXXZ'),
        (0x590800, '?computeCharacterInsertPoint@RootInstance@RBX@@ABE?AVVector3@G3D@@ABVExtents@2@@Z'),
        (0x5909e0, '?moveToPoint@RootInstance@RBX@@QAEXPAVPVInstance@2@VVector3@G3D@@@Z'),
        (0x590b50, '?moveToCharacterInsertPoint@RootInstance@RBX@@'),
        (0x590c10, '?insertToTree@RootInstance@RBX@@'),
        (0x590d00, '?insertCharacterView@RootInstance@RBX@@'),
        (0x590d80, '??$create@VStarterPackService@RBX@@@ServiceProvider@RBX@@SAPAVStarterPackService@1@PBVInstance@1@@Z'),
        (0x590dd0, '??$create@VTeams@RBX@@@ServiceProvider@RBX@@SAPAVTeams@1@PBVInstance@1@@Z'),
        (0x590e20, '??$create@VLighting@RBX@@@ServiceProvider@RBX@@SAPAVLighting@1@PBVInstance@1@@Z'),
        (0x590e70, '?insertIdeView@RootInstance@RBX@@'),
        (0x590f90, '?insert3dView@RootInstance@RBX@@'),
        (0x591510, '?classDescriptor@?$Described@VRootInstance@RBX@@$1?sRootInstance@2@3PADAVModelInstance@2@@'
                   'Reflection@RBX@@SAAAVClassDescriptor@23@XZ'),
    ],
}
# rows that are only exact in the pending build (never counted)
PENDING_ROWS = {
    'root': [
        (0x5910a0, '?insertSpawnLocation@RootInstance@RBX@@AAEXPAVSpawnLocation@2@@Z',
         'SpawnLocation::neutral is read at +0x400 (005910b5 cmp byte ptr [edi+0x400]); the committed '
         'v8datamodel/SpawnLocation.h states +0x400 but compiles to +0x2e8 over the donor PartInstance. Exact only '
         'with native-headers/part-embedded (2008 PartInstance, embedded Primitive at +0x228) ahead of the path.'),
    ],
}
NON_EXACT_ROWS = [
    (0x591580, '??0RootInstance@RBX@@IAE@XZ', 'root',
     '572 / 572 B: identical except the World allocation size: the original passes 0x114 to operator new at 00591739 '
     'before World::World 005ea920, the donor v8world/World.h gives sizeof(World) = 0xb8. Needs a 2008 World '
     'declaration (owner proposal in the receipt); the World layout itself is not derived here.'),
]
REJECTED = {
    'AppUnit588_2008RootInstance.cpp without /U_RELEASEASSERT': (
        'RBXASSERT bodies stay in: insertRaw 217/185, insertCharacterView 143/116, insertIdeView 308/282, '
        'insert3dView 313/270, moveToPoint 402/363'),
    'AppUnit588_2008RootInstance.cpp without /fp:fast': 'computeIdeInsertPoint 181/167, moveToIdeInsertPoint 225/177',
    'moveToIdeInsertPoint / moveToCharacterInsertPoint / insert3dView with `!partArray.empty()`': (
        '177/177 and 182/182 B, test eax,0xfffffff8 instead of sar eax,3 / test eax,eax'),
    'insertToTree / insertIdeView with `partArray.size() > 0`': '234/234 and 282/282 B, sar/test instead of test 0xfffffff8',
    'computeCharacterInsertPoint with the donor getCamera()->getCameraCoordinateFrame() and `(halfSize * cameraLook) '
    '* Vector3(1,0,1)`': '539/478 (slot 1 getCamera instead of slot 2 getGCamera)',
    'computeCharacterInsertPoint without the halfY / lookY reads (y zeroed directly)': (
        '478/478 B: lookVector product scheduled fld [eax]; fld [esp+8]; fmul st(1) instead of fld [esp+8]; fld st(0); '
        'fmul [eax]. Variants tried: halfSize * cameraLook (480), cameraLook * halfSize (480), donor * Vector3(1,0,1) '
        '(478/496), Vector3 cameraLook(look.x, 0, look.z) (478), a CoordinateFrame local (480), lookY read only (478), '
        'halfY read only (478)'),
}


def support_key(symbol):
    keys = [k for k in SUPPORT if symbol == k or symbol.startswith(k)]
    assert len(keys) <= 1, (symbol, keys)
    return keys[0] if keys else None


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for row in rows:
        address, key = row[0], row[1]
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record=True):
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
        elif symbol.startswith('__real@'):
            assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
            how = 'constant %s' % symbol[7:]
        elif symbol.startswith('??_C@'):
            pos, at = definitions[symbol]
            literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
            how = 'string %r' % literal[:-1].decode('latin-1')[:40]
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
            how = 'RTTI type %s' % rtti
        elif symbol.startswith('??_7'):
            rtti, offset_in_object = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (name, symbol, hex(value), rtti)
            how = 'vtable (RTTI %s, offset %#x)' % (rtti, offset_in_object)
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif support_key(symbol):
            assert SUPPORT[support_key(symbol)] == value, (name, symbol, hex(value))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out[symbol] = '%08x' % value
            how = 'support body exact at the bound address'
        elif symbol in DATA_BYTES:
            where, expect = DATA_BYTES[symbol]
            assert where == value and original.data(value, len(expect)) == expect, (name, symbol, hex(value))
            how = 'data bytes %s' % expect.hex()
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
        elif symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'static data (one address per symbol)'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(objs, which, rows, own, strict=True, record=True):
    raw = Path(objs[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own, record)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(OBJ, k, rows, own) for k, rows in resolved.items()}
# the folded ??_E / ??_G body the adjustor thunks jump to (005a0910, outside this range): support row
for row in verify(OBJ, 'root', [(0x5a0910, '??_GRootInstance@RBX@@MAEPAXI@Z')], own):
    assert row['exact'] or DISCOVER, row
    support_out['??_GRootInstance@RBX@@MAEPAXI@Z'] = {'address': row['address'], 'exact': row['exact'],
                                                     'verified_targets': row.get('verified_targets')}



def vtable_slots(obj_path, vtable_address):
    """Compare every slot of each RootInstance vtable in the current-header object with the original vtable whose
    address the vptr stores of the counted rows use; slots whose function is bound here must agree."""
    raw = Path(obj_path).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    out = {}
    for symbol, address in sorted(vtable_address.items()):
        start, sec = definitions[symbol]
        table = sections[sec]
        relocs = sorted((struct.unpack_from('<IIH', raw, table[5] + 10 * k)) for k in range(table[7]))
        slots = [(off - start, symbols[idx][0]) for off, idx, kind in relocs if kind == 6 and off >= start]
        slots = [x for x in slots if x[0] < table[3] - start]
        known = dict(own)
        known.update(EXTERNAL)
        checked, unbound = [], []
        for off, target_symbol in slots:
            value = struct.unpack('<I', original.data(address + off, 4))[0]
            expect = known.get(target_symbol)
            if expect is None and support_key(target_symbol):
                expect = SUPPORT[support_key(target_symbol)]
            if expect is None:
                unbound.append('%d %s' % (off // 4, target_symbol[:80]))
                continue
            assert expect == value, ('vtable slot', symbol, off // 4, target_symbol, hex(value), hex(expect))
            checked.append('%d %s = %#x' % (off // 4, target_symbol[:80], value))
        # slot count: every original slot is a code address and the dword after the last slot is not
        code_range = range(0x401000, 0x7e0000)
        originals = [struct.unpack('<I', original.data(address + 4 * k, 4))[0] for k in range(len(slots) + 1)]
        assert all(v in code_range for v in originals[:-1]) and originals[-1] not in code_range, (
            'vtable slot count', symbol, hex(address), [hex(v) for v in originals])
        out[symbol] = {'address': '%08x' % address, 'slots': len(slots), 'checked': checked,
                       'not_bound_here': len(unbound)}
    return out


VTABLE_ADDRESS = {}
for rows in groups.values():
    for r in rows:
        for sym, how in r.get('verified_targets', {}).items():
            if sym.startswith('??_7RootInstance@RBX@@6B'):
                VTABLE_ADDRESS[sym] = int(how.split()[0], 16)
vtables = vtable_slots(OBJ['root'], VTABLE_ADDRESS)
assert len(vtables) == 16 or DISCOVER, sorted(vtables)

pending_out = []
for which, rows in PENDING_ROWS.items():
    for address, key, why in rows:
        main = verify(OBJ, which, resolve(OBJ[which], [(address, key)]), own, strict=False, record=False)[0]
        assert not main['exact'] or DISCOVER, ('pending row exact in the main build', main['address'])
        row = verify(PENDING_OBJ, which, resolve(PENDING_OBJ[which], [(address, key)]), own, strict=False, record=False)[0]
        assert row['exact'] or DISCOVER, ('pending row not exact in the pending build', row['address'])
        row.update({'exact': False, 'pending_build_exact': True, 'main_build_size': main['size'],
                    'status': 'pending-build-only', 'reason': why})
        pending_out.append(row)

non_out = []
for address, key, which, why in NON_EXACT_ROWS:
    row = verify(OBJ, which, resolve(OBJ[which], [(address, key)]), own, strict=False, record=False)[0]
    assert not row['exact'] or DISCOVER, ('non-exact row unexpectedly exact', row['address'])
    row.update({'exact': False, 'reason': why})
    non_out.append(row)

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in groups.items():
        for r in rows:
            if not r['exact']:
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND


def counted_elsewhere():
    out = {}
    for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
        if Path(path).name == RECEIPT.name:
            continue
        try:
            data = json.loads(Path(path).read_text())
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        rows = []
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '00588000' <= a < '00594000'}

UNIT_MAP = {
    'change-history ..0058c91f (109 rows from 00588000)': (
        'ChangeHistoryService.cpp: the unit starts before 00588000 (00587eb0, 730 B, ends 00588192). Strings '
        '"ChangeHistoryService is currently ..." 00588780 / 0058a130, create<ChangeHistoryService> 0058a2a0 and '
        'FactoryProduct ctor 0058a8d0 (change-history-factory-working.json), ChangeHistoryService() 0058ab90, leaf '
        'virtuals 0058aca0..0058ad10, BoundFuncDesc / UTuple holder instantiations 0058adc0..0058c3c0, members '
        '0058c4f0..0058c620 and the static initializer 0058c8b0 ("ChangeHistoryService.enabled"). Matched bodies '
        'for many rows exist in change-history-layout-working.json and the history-* trials (method lists without '
        'exact flags, so not counted); their sources belong to the ChangeHistory* native-class owners and are not '
        'rebuilt here. Counted by camera-history-trial.json: 0058a9e0, 0058c5c0.'),
    'xml-serializer 0058c920..0059001f (42 rows from 0058c990)': (
        'XmlSerializer.cpp (native v8xml/XmlSerializer.h owner): 0058c920 (string-holding name/value ctor, callers '
        'TextXmlWriterWithEmbeddedContent::serializeNode 0058f270 and 00591970), isCloseTag 0058c990, endsWithClose, '
        'TextXmlParser skipWhitespace / readTag / removeTag / findNextToken / parse 0058f6c0 ("TextXmlParser::parse '
        'empty file"), base64 / istreambuf_iterator helpers 0058d4b0..0058d900, TextXmlWriter serialize 0058e810 / '
        'writeOpenTag 0058eb10 / serializeNode 0058ecb0 / encodedWrite 0058e4a0, XmlParser() 0058f230, '
        'TextXmlWriterWithEmbeddedContent::serializeNode 0058f270, XmlWriter() 0058fff0. Not built here.'),
    'root-instance 00590020..005917bb (39 rows from 00590030)': (
        'RootInstance.cpp: 00590020 (5 B jmp ~ModelInstance 00584790, called only from the RootInstance unwind '
        'funclets 007d1b83 / 007d1c7b) .. RootInstance() 00591580 (572 B, ends 005917bb); vtables 00831c64..00831d4c '
        '(RTTI .?AVRootInstance@RBX@@, 34 bases, ICameraOwner at +0x288), ~RootInstance 00590630, deleting dtor '
        '005a0910 (placed in the Workspace range, only reached through the vtable thunks). Built here: 30 counted '
        'rows, including ServiceProvider::create<StarterPackService / Teams / Lighting>(const Instance*) 00590d80 / '
        '00590dd0 / 00590e20 (create<T>(const Instance*) defined in the unit, Service.h proposal). Shared STL COMDATs emitted here (00590390 _Destroy_range, 005903d0 _Destroy, 005903f0 for_each, '
        '00590500 _Tidy, 00590550 ~vector<weak_ptr<PartInstance>>) are library templates called from other units: '
        '005903f0 / 00590550 are support rows, the others are not counted. Not counted: vtordisp thunk 005907e0 (jmp 00584b10, an adjustor in the ModelInstance '
        'unit: which getPrimaryPart thunk it is cannot be told apart), insertSpawnLocation 005910a0 '
        '(pending-build-only), insertInstances 005911d0 (2008 shape), RootInstance() 00591580 (World size).'),
    'serializer-v2 005917c0..00593baf (40 rows)': (
        'SerializerV2.cpp (metadata-load/v8xml/SerializerV2.h owner): map<string, InstanceHandle> tree helpers '
        '005917c0..00591930 (first caller 00591e60), IDREFBinding list helpers 005919f0 / 00591e00, the xmlns '
        'writer 00591a30 ("xmlns:xmime"), replaceHandles 00591c60 / isolate 00591d30, ArchiveBinder resolveRefs '
        '00592720 / ArchiveBinder() 00592940 / processID 005930c0 / processIDREF 00593170 / ~ArchiveBinder 005931e0, '
        'buildIsolationMap 00592780, 00593250 ("Unknown object class"), isolateHandles 00593480, load 00593500, '
        'loadXML 00593570, load(istream) 00593730 ("SerializerV2::load can\'t read"). Not built here.'),
    'lua-thread-ref 00593bb0.. (11 rows below 00594000)': (
        'Lua ThreadRef / FunctionRef unit (LuaBridge2008 owner): ThreadRef::removeRef 00593bb0, FunctionRef::removeRef '
        '00593c60, lua_pushfunction 00593c40, ThreadRef::Node::get 00593cb0, shared_count<mutex> 00593d90, ThreadRef '
        'ctors 00593e40 / 00593f70; continues past 00594000 (reset 00594060, ~ThreadRef 00594380). Not built here.'),
    'library code': (
        'No standalone library unit lies in 00588000..00594000. The STL / boost template instantiations listed above '
        '(map/set trees, list, vector helpers, istreambuf_iterator, base64, sp_counted_impl_p) are instantiated by the '
        'RBX units they sit in; only those the built RootInstance unit references are bound, as support rows.'),
}

PROPOSALS = {
    'v8world/World.h (World owner)': (
        'The 2008 World is 0x114 bytes: RootInstance() 00591580 passes 0x114 to operator new (00591739) before '
        'World::World 005ea920; the donor World.h gives 0xb8. With a 2008 World declaration of that size the '
        'RootInstance constructor of this unit is exact (only the push immediate differs).'),
    'v8tree/Service.h (core owner)': (
        'Define template<class Class> static Class* ServiceProvider::create(const Instance* context) in the header: '
        'walk context->getParent() (+0x104) with dynamic_cast<const ServiceProvider*> and tail-call '
        'provider->create<Class>(). Evidence: 00590d80 / 00590dd0 / 00590e20 (this unit, exact with that body), the '
        'same definition is repeated in LocalBackpack2008.cpp, SoundServiceProvider.cpp and '
        'AppUnit4C8_2008PhysicsServiceCreate.cpp.'),
    'v8datamodel/Workspace.h (Workspace owner)': (
        'insertInstances 005911d0 needs a Workspace member taking a Decal*: 005a3d40 (ret 4, ecx = the result of the '
        'ServiceProvider::find helper 00491e50 whose tail call is 00490af0) builds a 0x50-byte MouseCommand (new 0x50 '
        'at 005a3d92) and calls Workspace::setMouseCommand 005a1fc0. insertInstances 005911d0 reaches it for a '
        'dynamic_cast<Decal*> (RTTI 00940dbc) instance only when insertMode == INSERT_TO_3D_VIEW (00591472), and then '
        'returns without inserting the rest. Its other 2008-only steps: an early for_each(setParent) return when '
        'requestedParent is not in this tree (005911fa..00591282), requestedParent defaulting to this (0059141e), '
        'and a final 0058c5c0("Insert" 00831e18, this) (camera-history-trial names it recordCameraHistory).'),
    'v8datamodel/SpawnLocation.h (SpawnLocation owner), FYI': (
        'insertSpawnLocation 005910a0 is exact once the 2008 PartInstance (native-headers/part-embedded) is used: '
        'neutral is read at +0x400 (005910b5), as the header comment says; over the default PartInstance it compiles '
        'to +0x2e8. No change to SpawnLocation.h is needed; the PartInstance owner proposal stands.'),
}

receipt = {
    'class': 'RBX RootInstance unit of the application range 00588000..00594000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'pending_flags': PENDING_FLAGS_USED,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve(),
                R / 'native-headers/v8datamodel/RootInstance.h', R / 'native-headers/v8datamodel/ModelInstance.h']},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'range_rows_counted_by_other_receipts': range_counted,
    'rows': groups,
    'support_rows': support_out,
    'vtables_current_headers': vtables,
    'pending_build_only': pending_out,
    'not_exact': non_out,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit588-2008: %d counted exact rows (%s); %d pending-build-only, %d not exact, %d support rows'
      % (len(exact_rows), ' '.join(exact_rows), len(pending_out), len(non_out), len(support_out)))
