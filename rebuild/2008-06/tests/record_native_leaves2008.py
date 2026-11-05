"""Verify the inactive native 2008-06 RBX leaves: Log, IndexBox, StandardOut, Point, Link/RevoluteLink, NullController,
GuiTarget, BlockBlockContact.

Builds (document-swap flags plus /fp:fast /U_RELEASEASSERT, VS2008 RTM 21022):
  * tests/NativeLeaves2008Layout.cpp        offset / size probes (mov eax, imm32; ret) and the two emitters for the
                                            inline-only NullController / GuiTarget bodies;
  * native-classes/Leaves2008Log.cpp        RBX::Log (native-headers/leaves2008/Log2008.h), unit 005a6bb0..005a6fcb;
  * native-classes/Leaves2008IndexBox.cpp   RBX::IndexBox (leaves2008/IndexBox2008.h), 007bbe30 / 007bbed0 and tables;
  * native-classes/Leaves2008StandardOut.cpp  donor util/standardout.h, 00569260..00569866, 005e9ec0, 00416e10,
                                            atexit 007fd110;
  * native-classes/Leaves2008Point.cpp      donor v8kernel/Point.h: Point(Body*) 0064dc00, ??_G 0064dc50;
  * native-classes/Leaves2008RevoluteLink.cpp  donor v8kernel/Link.h: Link() 00613d20, Link::reset 00613da0;
  * native-classes/Leaves2008BlockBlockContact.cpp  RBX::BlockBlockContact (leaves2008/BlockBlockContact2008.h on the
                                            committed v8world/Contact2008.h): 0060d500, 0060d5a0, 0060d610, 00607c60,
                                            0060d580, 0060d590 and the vtable 00843714;
  * Leaves2008StandardOut.cpp again with NATIVE_STANDARDOUT_PENDING against out/native-layouts/leaves2008-pending/
    (generated copies, no shared header is edited): the donor util/standardout.h without the user-declared
    `virtual ~StandardOut();` (util/Events.h is copied unchanged now that `listeners.size() > 0` is adopted);
  * Leaves2008BlockBlockContact.cpp again with NATIVE_BLOCKBLOCKCONTACT_PENDING against
    out/native-layouts/leaves2008-pending-stages/v8kernel/IStage.h (2008 StageType values, KERNEL_STAGE 7).
    Rows exact only in a pending build are recorded exact=false (pending-build-only) and are not counted.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by bytes,
float constants by bits, type descriptors and vtables by original RTTI names, own symbols by the row proven here,
statics / tables by the DATA map (tables also byte-compared), ICF folds by the FOLDED map, and the remaining externals
by the EXTERNAL map (call sites read in the original disassembly). A symbol must bind to one address in every row.
Each class vtable of the main builds (never the pending one) is compared slot by slot with the original vtable it
binds to. Writes work/2008-06/shared-layouts/leaves2008-working.json.
"""
import json
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
HDRS = sorted((R / 'native-headers/leaves2008').glob('*.h'))
LAYOUT = R / 'tests/NativeLeaves2008Layout.cpp'
SOURCES = {name: R / ('native-classes/Leaves2008%s.cpp' % name)
           for name in ('Log', 'IndexBox', 'StandardOut', 'Point', 'RevoluteLink', 'BlockBlockContact')}
UNIT_FLAGS = ['/fp:fast',            # IndexBox() 007bbed0 chains the corner stores without spills
              '/U_RELEASEASSERT']    # ~KernelIndex (Point ??_G 0064dc50) asserts nothing in the original

# ---- generated header copies for the pending build (proposals; the shared headers are not edited) ----------
PENDING = OUT / 'leaves2008-pending'
(PENDING / 'util').mkdir(parents=True, exist_ok=True)
EVENTS_OLD = '\t\t\treturn !listeners.empty();\n'
EVENTS_NEW = '\t\t\treturn listeners.size() > 0;\n'
text = (R / 'native-headers/util/Events.h').read_text()
assert text.count(EVENTS_OLD) + text.count(EVENTS_NEW) == 1   # the proposal may already be adopted upstream
(PENDING / 'util/Events.h').write_text(text.replace(EVENTS_OLD, EVENTS_NEW))
STDOUT_OLD = '\t\tvirtual ~StandardOut();\n'
text = (ROOT / 'tools/rbxgs/Client/App/include/util/standardout.h').read_text()
assert text.count(STDOUT_OLD) == 1
(PENDING / 'util/standardout.h').write_text(text.replace(STDOUT_OLD, ''))
# BlockBlockContact pending build: the 2008 StageType values (getStageType bodies return CLEAN 0 .. SIMJOB 6, KERNEL 7,
# see tests/record_native_kernel_stages.py); the donor v8kernel/IStage.h numbers JOINT 0 .. KERNEL 8. Separate directory
# so that the StandardOut pending build keeps its own generated headers only.
PENDING_STAGES = OUT / 'leaves2008-pending-stages'
(PENDING_STAGES / 'v8kernel').mkdir(parents=True, exist_ok=True)
text = (ROOT / 'tools/rbxgs/Client/App/include/v8kernel/IStage.h').read_text()
DONOR_ENUM = text[text.index('JOINT_STAGE = 0x0,'):text.index('KERNEL_STAGE = 0x8,') + len('KERNEL_STAGE = 0x8,')]
STAGES_2008 = ['CLEAN_STAGE', 'JOINT_STAGE', 'CLUMP_STAGE', 'TREE_STAGE', 'ASSEMBLY_STAGE', 'SLEEP_STAGE',
               'SIMJOB_STAGE', 'KERNEL_STAGE']
assert text.count(DONOR_ENUM) == 1
(PENDING_STAGES / 'v8kernel/IStage.h').write_text(text.replace(
    DONOR_ENUM, '\n\t\t\t\t'.join('%s = 0x%x,' % (n, i) for i, n in enumerate(STAGES_2008))))


def build(name, src, extra=(), pre=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(pre) + flags[i:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeLeaves2008Layout', LAYOUT, UNIT_FLAGS)
objs, unit_flags = {}, {}
for name, src in SOURCES.items():
    objs[name], unit_flags[name] = build('NativeLeaves2008' + name, src, UNIT_FLAGS)
pend_obj, pend_flags = build('NativeLeaves2008StandardOutPending', SOURCES['StandardOut'],
                             UNIT_FLAGS + ['/DNATIVE_STANDARDOUT_PENDING'], ['/I' + str(PENDING)])
bbc_pend_obj, bbc_pend_flags = build('NativeLeaves2008BlockBlockContactPending', SOURCES['BlockBlockContact'],
                                     UNIT_FLAGS + ['/DNATIVE_BLOCKBLOCKCONTACT_PENDING'], ['/I' + str(PENDING_STAGES)])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
PROBES = (('?nativeLogNameOffset@@', 0x4), ('?nativeLogWorstSeverityOffset@@', 0x20), ('?nativeLogFileOffset@@', 0x24),
          ('?nativeLogStreamOffset@@', 0x40), ('?nativeIndexBoxCornerOffset@@', 0x4), ('?nativeIndexBoxSize@@', 0x64),
          ('?nativeNullControllerSize@@', 0xc), ('?nativeGuiResponseSize@@', 0x8), ('?nativePointSize@@', 0x34),
          ('?nativeRevoluteLinkSize@@', 0xd0), ('?nativeBlockBlockContactSize@@', 0x7c),
          ('?nativeBlockBlockContactConnectorsOffset@@', 0x34), ('?nativeBlockBlockContactMatchedOffset@@', 0x40),
          ('?nativeBlockBlockContactAxisIdOffset@@', 0x4c), ('?nativeBlockBlockContactSeparationOffset@@', 0x54),
          ('?nativeBlockBlockContactPlaneContactOffset@@', 0x5c), ('?nativeBlockBlockContactFeatureOffset@@', 0x64),
          ('?nativeBlockBlockContactOtherPlaneOffset@@', 0x78))
for prefix, value in PROBES:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '?getWorldBody@Body@RBX@@SAPAV12@XZ': 0x614bb0,                       # Point() 0064dc1f
    '?getNextStateIndex@Body@RBX@@SAHXZ': 0x613f20,                       # Link() 00613d4d (evidence name)
    '??0CoordinateFrame@G3D@@QAE@XZ': 0x4782d0,                           # Link() 00613d2d
    '?inverse@CoordinateFrame@G3D@@QBE?AV12@XZ': 0x478330,                # reset 00613df7
    '??$?6U?$char_traits@D@std@@@std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@0@AAV10@PBD@Z': 0x44a450,  # Log() 005a6e1d
    '??$?6U?$char_traits@D@std@@@std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@0@AAV10@D@Z': 0x44a640,    # writeEntry 005a6f8b
    '?vformat@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDPAD@Z': 0x5099f0,     # print 005693c4
    '?do_lock@mutex@boost@@AAEXXZ': 0x594ce0, '?do_unlock@mutex@boost@@AAEXXZ': 0x594d00,                    # print
    '??0mutex@boost@@QAE@XZ': 0x594c90,                                   # StandardOut() 0056956c
    '??1mutex@boost@@QAE@XZ': 0x594cb0,                                   # ~StandardOut 005695b8
    '??R?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@QBEXXZ': 0x42afc0,  # print_exception 0056971b
    '??1?$shared_ptr@VStandardOut@RBX@@@boost@@QAE@XZ': 0x600660,         # print_exception catch 00569759 (ICF)
    # BlockBlockContact (call sites in the original rows):
    '??0Contact@RBX@@QAE@PAVPrimitive@1@0@Z': 0x606c20,                   # 0060d525 (exact in record_native_world_shapes.py)
    '?getKernel@IPipelined@RBX@@QBEPAVKernel@2@XZ': 0x645850,             # deleteAllConnectors 00607c7c
    '?removeConnector@Kernel@RBX@@QAEXPAVConnector@2@@Z': 0x5fb1f0,       # 00607c83
    '?alignedFree@System@G3D@@SAXPAX@Z': 0x507d20,                        # ~Array, 0060d5c8 / 0060d5e2
    '__ftol2_sse': 0x6a17f0,                                              # Array::resize 00607996 (statically linked CRT)
    '?deleteUnmatchedConnectors@BlockBlockContact@RBX@@AAEXXZ': 0x607e00,  # 006087f3 / 00608812 (pending row)
    '?loadGeoPairEdgeEdge@BlockBlockContact@RBX@@AAEXHHHH@Z': 0x607ea0,    # 0060880a (pending row)
    '?computePlaneContact@BlockBlockContact@RBX@@AAEHXZ': 0x608580,        # 006087eb (pending row)
    # vtable 00843714 slots whose bodies are not built here (Contact slots are exact in record_native_world_shapes.py)
    '?putInKernel@Contact@RBX@@EAEXPAVKernel@2@@Z': 0x60cb10,
    '?removeFromKernel@Contact@RBX@@EAEXXZ': 0x60cb30,
    '?getEdgeType@Contact@RBX@@EBE?AW4EdgeType@Edge@2@XZ': 0x7286a0,
    '?setPrimitive@Edge@RBX@@UAEXHPAVPrimitive@2@@Z': 0x659290,
    '?stepContact@BlockBlockContact@RBX@@EAE_NXZ': 0x608830,
    '?computeIsColliding@BlockBlockContact@RBX@@EAE_NM@Z': 0x607c20,
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '_atexit': 0x6a17af,
}
# Statics and tables: address the original instruction uses; tables and string pointers are byte-checked below.
DATA = {
    '?provider@Log@RBX@@0PAVILogProvider@2@A': 0x976b4c,
    '_information': 0x94c420, '_warning': 0x94c424, '_error': 0x94c428,   # file-local `static const char*` (.data)
    '?INDEXBOX_FACE_TO_VERTEX@IndexBox@RBX@@2QAY03$$CBHA': 0x875de8,
    # G3D::Array<T>::resize function-local `static const int minSize` and its init guard (guard = minSize + 4)
    '?minSize@?3??resize@?$Array@PAVContactConnector@RBX@@@G3D@@QAEXH_N@Z@4HB': 0x97b898,
    '??_B?3??resize@?$Array@PAVContactConnector@RBX@@@G3D@@QAEXH_N@Z@53': 0x97b89c,
    '?minSize@?3??resize@?$Array@_N@G3D@@QAEXH_N@Z@4HB': 0x96f79c,
    '??_B?3??resize@?$Array@_N@G3D@@QAEXH_N@Z@53': 0x96f7a0,
}
TABLES = {   # IndexBox tables defined in Leaves2008IndexBox.cpp, compared byte for byte with the original .rdata
    '?INDEXBOX_FACE_TO_NORMAL@IndexBox@RBX@@2QAY02$$CBMA': (0x875da0, 0x48),
    '?INDEXBOX_FACE_TO_VERTEX@IndexBox@RBX@@2QAY03$$CBHA': (0x875de8, 0x60),
    '?INDEXBOX_EDGE_TO_VERTEX_AND_NORMALS@IndexBox@RBX@@2QAY03$$CBHA': (0x875e48, 0xc0),
    '?INDEXBOX_FACE_EDGE_TO_NORMAL@IndexBox@RBX@@2QAY03$$CBHA': (0x875f08, 0x60),
}

LOG = 'Log@RBX@@'
SO = 'StandardOut@RBX@@'
NTF = '?$Notifier@VStandardOut@RBX@@UStandardOutMessage@2@@RBX@@'
# ICF / trivial-wrapper folds: the original keeps one body where these units emit several identical ones.
FOLDED = {
    '?onAddListener@' + NTF + 'MBEXPAV?$Listener@VStandardOut@RBX@@UStandardOutMessage@2@@2@@Z': 0x70bdf0,
    '?onRemoveListener@' + NTF + 'MBEXPAV?$Listener@VStandardOut@RBX@@UStandardOutMessage@2@@2@@Z': 0x70bdf0,
}
# G3D::Array<T>::realloc has no statics, so pointer / byte instantiations fold: 00502080 and 00473740 are called by
# many resize copies (xref), so they are byte-checked folds of the BlockBlockContact unit's COMDATs, never counted.
BBC_FOLDED = {
    '?realloc@?$Array@PAVContactConnector@RBX@@@G3D@@AAEXH@Z': 0x502080,
    '?realloc@?$Array@_N@G3D@@AAEXH@Z': 0x473740,
}
FOLDED.update(BBC_FOLDED)

# (address | contiguous address tuple | ('slice', row, lo, hi), symbol or unique symbol prefix)
ROWS = {
    'Log': [
        (0x5a6bb0, '?setLogProvider@' + LOG),
        (0x5a6bc0, '?formatMem@' + LOG),
        (0x5a6c60, '?formatTime@' + LOG),
        (0x5a6d10, '?timeStamp@@YAXAAV?$basic_ofstream@DU?$char_traits@D@std@@@std@@_N@Z'),
        (0x5a6da0, '??0' + LOG + 'QAE@PBD0@Z'),
        (0x5a6e60, '??1' + LOG + 'UAE@XZ'),
        (0x5a6ef0, '?writeEntry@' + LOG),
        (0x5a6fb0, '??_G' + LOG + 'UAEPAXI@Z'),
    ],
    'IndexBox': [
        (0x7bbe30, '?getFaceCorners@IndexBox@RBX@@'),
        # The function list extent of 007bbed0 runs 7 bytes past the `ret 8` (int3 padding and the import thunk
        # 007bbf86 `jmp [mfc90 #3762]`); the body is compared on its first 0xb5 bytes and the tail is checked below.
        (('slice', 0x7bbed0, 0, 0xb5), '??0IndexBox@RBX@@QAE@ABVVector3@G3D@@0@Z'),
        (0x66f8d0, '??1IndexBox@RBX@@UAE@XZ'),
        (0x66f8e0, '??_GIndexBox@RBX@@UAEPAXI@Z'),
    ],
    'StandardOut': [
        ((0x569260, 0x5692ce), '??$?0VStandardOut@RBX@@@shared_count@detail@boost@@QAE@PAVStandardOut@RBX@@@Z'),
        (0x5692f0, '??$?0VStandardOut@RBX@@@?$shared_ptr@VStandardOut@RBX@@@boost@@QAE@PAVStandardOut@RBX@@@Z'),
        (0x569530, '??0' + SO + 'QAE@XZ'),
        (0x569620, '?singleton@' + SO),
        (0x5696d0, '??_G' + SO + 'UAEPAXI@Z'),
        ((0x5696f0, 0x569720, 0x569731), '?print_exception@' + SO),
        ((0x569780, 0x5697de, 0x569801), '?raise@' + NTF + 'IBEXUStandardOutMessage@2@PAV'),
        (0x5691b0, '?raise@' + NTF + 'IBEXUStandardOutMessage@2@@Z'),
        (0x416e10, '?print@' + SO + 'QAEXW4MessageType@2@ABVexception@std@@@Z'),
        (0x5693a0, '?print@' + SO + 'QAAXW4MessageType@2@PBDZZ'),   # exact since Events.h hasListeners is size() > 0
        (0x5e9ec0, '??0' + NTF + 'IAE@XZ'),
        (0x7fd110, '??__FstandardOut@?1??singleton@' + SO),
    ],
    'Point': [
        (0x64dc00, '??0Point@RBX@@QAE@PAVBody@1@@Z'),
        (0x64dc50, '??_GPoint@RBX@@UAEPAXI@Z'),
    ],
    'RevoluteLink': [
        (0x613d20, '??0Link@RBX@@QAE@XZ'),
        (0x613da0, '?reset@Link@RBX@@QAEXABVCoordinateFrame@G3D@@0@Z'),
    ],
    'BlockBlockContact': [
        (0x60d500, '??0BlockBlockContact@RBX@@QAE@PAVPrimitive@1@0@Z'),
        (0x60d5a0, '??1BlockBlockContact@RBX@@UAE@XZ'),
        (0x60d610, '??_GBlockBlockContact@RBX@@UAEPAXI@Z'),
        (0x607c60, '?deleteAllConnectors@BlockBlockContact@RBX@@EAEXXZ'),
        (0x60d580, '?numConnectors@BlockBlockContact@RBX@@EBEHXZ'),
        (0x60d590, '?getConnector@BlockBlockContact@RBX@@EAEPAVContactConnector@2@H@Z'),
        # G3D::Array<T>::resize(int, bool) instantiations of the donor G3D/Array.h, called by deleteAllConnectors
        # 00607caa / 00607cb6 (fastClear) and 006087ca; emitted as COMDATs by this unit.
        (0x6078f0, '?resize@?$Array@PAVContactConnector@RBX@@@G3D@@QAEXH_N@Z'),
        (0x47ff20, '?resize@?$Array@_N@G3D@@QAEXH_N@Z'),
    ],
}
# Inline-only bodies emitted by NativeLeaves2008Layout.cpp (the original copies are COMDATs of other units).
LAYOUT_ROWS = [
    (0x599e50, '?getStaticNullController@NullController@RBX@@SAPAV12@XZ'),
    (0x7fdbc0, '??__Fn@?1??getStaticNullController@NullController@RBX@@SAPAV12@XZ@YAXXZ'),
    (0x5732d0, '?process@GuiTarget@RBX@@UAE?AVGuiResponse@2@ABVGuiEvent@2@@Z'),
]
# NullController vtable slots: ICF-shared bodies (identical bytes; the original keeps one copy elsewhere).
LAYOUT_FOLD_ROWS = [
    (0x4729b0, '??_GNullController@RBX@@UAEPAXI@Z'),
    (0x598a50, '?getValue@Controller@RBX@@UBEMW4InputType@12@@Z'),
    (0x416690, '?getControllerType@NullController@RBX@@UBE?AW4ControllerType@Controller@2@XZ'),
    (0x60a2f0, '?hasIntelligence@NullController@RBX@@UBE_NXZ'),
    (0x60a2f0, '?isUserController@NullController@RBX@@UBE_NXZ'),
]
# boost::checked_delete<StandardOut> (shared_count catch funclet): ICF-shared body in another unit.
STANDARDOUT_FOLD_ROWS = [
    (0x427b70, '??$checked_delete@VStandardOut@RBX@@@boost@@YAXPAVStandardOut@RBX@@@Z'),
]
# Rows exact only in the NATIVE_STANDARDOUT_PENDING build (generated headers); recorded exact=false, not counted.
PENDING_ROWS = [
    (0x569590, '??1' + SO + 'UAE@XZ'),
]
BBC_PENDING_ROWS = [
    (0x6087a0, '?updateConnectors@BlockBlockContact@RBX@@AAEXXZ'),
]
PENDING_REASON = {
    '00569590': '~StandardOut: implicit in 2008 (no StandardOut vtable store); the donor declares virtual ~StandardOut()',
    '006087a0': 'BlockBlockContact::updateConnectors (analog name): inKernel() compares getStageType() with 7, the 2008 '
                'KERNEL_STAGE; the donor v8kernel/IStage.h has KERNEL_STAGE = 8 (generated copy with the 2008 values)',
}
PROPOSALS = [
    'util/standardout.h (donor path, reached through native-headers/util/Events.h by nearly every unit; no native header '
    'is created at that path): the 2008 StandardOut has no user-declared destructor (~StandardOut 00569590 never stores '
    'the StandardOut vtable 0082f510). The owner of util/* should take this into a native override when one exists; '
    'with the line removed in a generated copy 00569590 is exact and ??_G 005696d0 stays exact.',
    'v8kernel/Body.h (donor; no native header; world/kernel owner): Point::step 0064dc90 / setWorldPos 0064dd40 read '
    'the PV position at Body +0x94..+0xc0 after updatePV 00599360, forceToBody 0064dc70 reads root +0x10 -> +0x2c, and '
    'Link::getChildInParent 00613d60 reads parent +0x14 and stateIndex +0x90; the donor Body has pv +0x88, parent +0x08, '
    'stateIndex +0x84. A native 2008 Body layout would unlock these four rows.',
    'cdecl helper 005989d0 (const CoordinateFrame& a, const CoordinateFrame& b, CoordinateFrame& out), called by '
    'RevoluteLink::computeChildInParent 00613cc0 and 005991c0: no declaration in any native or donor header; its owner '
    '(PV / Math) should declare it, then 00613cc0 can be attempted.',
    'v8kernel/IStage.h (donor; the kernel-stages owner already proposes it in tests/record_native_kernel_stages.py): the '
    '2008 StageType values are CLEAN 0 .. SIMJOB 6, KERNEL 7. With that enum BlockBlockContact::updateConnectors 006087a0 '
    '(`cmp eax, 7` after currentStage->getStageType()) is exact (generated copy out/native-layouts/'
    'leaves2008-pending-stages/v8kernel/IStage.h).',
    'v8world/Primitive.h 2008 (world owner): BlockBlockContact::stepContact 00608830 and computeIsColliding 00607c20 call '
    'Extents::overlapsOrTouches 00606b60 on Primitive +0x80 of both edge primitives (`sub ecx, -0x80`); the only native '
    'Primitive declaration (native-headers/part-embedded/v8world/Primitive.h) includes the donor v8world/Contact.h and '
    'cannot share a unit with v8world/Contact2008.h. A 2008 Primitive header without the donor Contact.h (fuzzy extents '
    'at +0x80, readable inline) would unlock both rows; 00607280 (the separating-axis test they call) is also needed.',
]
BLOCKED = {
    'RBX::BlockBlockContact::stepContact/computeIsColliding': '00608830 / 00607c20 need Primitive +0x80 fuzzy extents '
                                                              '(2008 Primitive layout, see proposals) and 00607280',
    'RBX::BlockBlockContact geometry helpers': '00607280 (separating axis test, 1634 bytes), 00607cc0, 00607e00, 00607ea0, '
                                               '00607f90, 00608030, 00608160, 00608580 need the 2008 Primitive / Body / '
                                               'Block geometry and ContactConnector layouts',
    'RBX::Point::step/forceToBody/setWorldPos': '2008 Body layout (see proposals)',
    'RBX::Link::getChildInParent': '2008 Body layout (see proposals)',
    'RBX::RevoluteLink::computeChildInParent': 'undeclared helper 005989d0 (see proposals)',
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def target_of(address):
    """Original bytes and relocation offsets of one row, of contiguous rows concatenated, or of a slice of one row."""
    if isinstance(address, tuple) and address[0] == 'slice':
        _, row, lo, hi = address
        body, refs, _ = match.target('2008-06', '%08x' % row)
        assert len(body) >= hi, (hex(row), len(body), hi)
        return body[lo:hi], [r - lo for r in refs if lo <= r < hi]
    parts = address if isinstance(address, tuple) else (address,)
    code, relocs = b'', []
    for part in parts:
        assert part == parts[0] + len(code), ('rows not contiguous', [hex(p) for p in parts])
        body, refs, _ = match.target('2008-06', '%08x' % part)
        relocs += [r + len(code) for r in refs]
        code += body
    return code, relocs


def first(address):
    if isinstance(address, tuple) and address[0] == 'slice':
        return address[1] + address[2]
    return address[0] if isinstance(address, tuple) else address


def label(address):
    if isinstance(address, tuple) and address[0] == 'slice':
        return '%08x[%02x:%02x]' % address[1:]
    return '+'.join('%08x' % a for a in (address if isinstance(address, tuple) else (address,)))


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key)
                                                       and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (hex(first(address)), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def classify(symbol, value, own, raw, sections, definitions, where):
    """Return how a relocation target bound to `value` is verified, or None when unknown."""
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('__real@') and len(symbol) == 15:
        bits = struct.pack('<I', int(symbol[7:], 16))
        assert original.data(value, 4) == bits, (where, symbol, hex(value))
        return 'float constant %r' % struct.unpack('<f', bits)
    if symbol.startswith('__real@') and len(symbol) == 23:
        bits = struct.pack('<Q', int(symbol[7:], 16))
        assert original.data(value, 8) == bits, (where, symbol, hex(value))
        return 'double constant %r' % struct.unpack('<d', bits)
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    if symbol in FOLDED:
        assert FOLDED[symbol] == value, (where, symbol, hex(value))
        return 'folded'
    if symbol in DATA:
        assert DATA[symbol] == value, (where, symbol, hex(value), hex(DATA[symbol]))
        return 'data'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
    if symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?n@?1??') \
            or symbol.startswith('?standardOut@?1??'):
        return 'local static'
    return None


def verify(obj, rows, own):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        assert match.exact_match(target, target_refs, body, refs), (name, label(address), len(body), len(target))
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        base = first(address)
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:
                value = (base + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            how = classify(symbol, value, own, raw, sections, definitions, name)
            if how is None:
                UNBOUND.append('%s in %s -> %s' % (symbol, name, hex(value)))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        result.append({'address': label(address), 'symbol': name, 'size': len(body), 'exact': True,
                       'verified_targets': verified, 'local_eh': sorted(local)})
    return result


resolved = {cls: resolve(objs[cls], rows) for cls, rows in ROWS.items()}
layout_rows = resolve(layout_obj, LAYOUT_ROWS)
fold_rows = resolve(layout_obj, LAYOUT_FOLD_ROWS)
so_fold_rows = resolve(objs['StandardOut'], STANDARDOUT_FOLD_ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
bbc_pend_rows = resolve(bbc_pend_obj, BBC_PENDING_ROWS)
own = {}
for rows in list(resolved.values()) + [layout_rows, fold_rows, so_fold_rows, pend_rows, bbc_pend_rows]:
    for address, name in rows:
        own.setdefault(name, first(address))
methods = {cls: verify(objs[cls], rows, own) for cls, rows in resolved.items()}
methods['NullController/GuiTarget (layout emitters)'] = verify(layout_obj, layout_rows, own)
folds = verify(layout_obj, fold_rows, own) + verify(objs['StandardOut'], so_fold_rows, own)
for row in folds:
    row['folded'] = True
pend_out = verify(pend_obj, pend_rows, own) + verify(bbc_pend_obj, bbc_pend_rows, own)
for row in pend_out:  # exact only against the generated header copies: not counted as exact
    row['exact'] = False
    row['exact_pending_build_only'] = True
    row['what'] = PENDING_REASON[row['address']]
assert not UNBOUND, '\n'.join(UNBOUND)

# FOLDED targets: the body this unit emits is byte-identical (relocation-masked) to the shared original copy.
so_bodies = {n: (b, r) for n, b, r in match.coff_functions(objs['StandardOut'].read_bytes())}
so_bodies.update({n: (b, r) for n, b, r in match.coff_functions(objs['BlockBlockContact'].read_bytes())
                  if n in BBC_FOLDED})
for symbol, address in FOLDED.items():
    body, refs = so_bodies[symbol]
    target, target_refs = target_of(address)
    assert match.exact_match(target, target_refs, body, refs), ('fold', symbol, hex(address))

# IndexBox() extent tail: int3 padding, then the import thunk 007bbf86 (a separate function).
body, _, _ = match.target('2008-06', '007bbed0')
assert len(body) == 0xbc and body[0xb5] == 0xcc and body[0xb6:0xb8] == b'\xff\x25', body[0xb2:].hex()
assert original.imported(0x7bbf86) is not None

# IndexBox tables and Log severity strings: original bytes.
raw = objs['IndexBox'].read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
for symbol, (address, size) in TABLES.items():
    pos, sec = definitions[symbol]
    mine = raw[sections[sec][4] + pos:sections[sec][4] + pos + size]
    assert mine == original.data(address, size), (symbol, hex(address))
for address, text in ((0x94c420, '          '), (0x94c424, ' Warning: '), (0x94c428, ' Error:   ')):
    assert original.string(d(address)) == text, (hex(address), text)
for address, text in ((0x8341a8, 'Log "'), (0x8341bc, 'End Log\n'), (0x834180, '%02u:%02u:%02u.%03u '),
                      (0x834198, '%02u.%02u.%u ')):
    assert original.string(address) == text, (hex(address), text)

# ---- vtables of the main builds, slot by slot against the original vtable each one binds to -----------
VTABLES = {   # vtable symbol -> (object, original vtable, RTTI, slot count)
    '??_7Log@RBX@@6B@': ('Log', 0x8341b8, '.?AVLog@RBX@@', 1),
    '??_7IndexBox@RBX@@6B@': ('IndexBox', 0x84d1cc, '.?AVIndexBox@RBX@@', 1),
    '??_7StandardOut@RBX@@6B@': ('StandardOut', 0x82f510, '.?AVStandardOut@RBX@@', 3),
    '??_7Point@RBX@@6B@': ('Point', 0x84b24c, '.?AVPoint@RBX@@', 1),
    '??_7NullController@RBX@@6B@': (None, 0x832a04, '.?AVNullController@RBX@@', 5),
    '??_7GuiTarget@RBX@@6B@': (None, 0x82f848, '.?AVGuiTarget@RBX@@', 1),
    '??_7BlockBlockContact@RBX@@6B@': ('BlockBlockContact', 0x843714, '.?AVBlockBlockContact@RBX@@', 10),
}
vtables = {}
for symbol, (cls, vt, rtti_name, count) in VTABLES.items():
    obj = objs[cls] if cls else layout_obj
    raw = obj.read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    assert original.vtable_class(vt) == (rtti_name, 0), (hex(vt), original.vtable_class(vt))
    value, sec = definitions[symbol]
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    assert sorted(slots) == list(range(count)), (symbol, sorted(slots))
    checked = {}
    for slot, sym in sorted(slots.items()):
        value_orig = d(vt + 4 * slot)
        how = classify(sym, value_orig, own, raw, sections, definitions, symbol)
        if how is None:
            UNBOUND.append('vtable %s slot %d %s -> %s' % (symbol, slot, sym, hex(value_orig)))
            continue
        prev = binding.setdefault(sym, (value_orig, symbol))
        assert prev[0] == value_orig, ('inconsistent', sym, hex(prev[0]), prev[1], hex(value_orig), symbol)
        checked[slot] = '%s = %s (%s)' % (sym, hex(value_orig), how)
    vtables[symbol] = {'address': hex(vt), 'rtti': rtti_name, 'slots': checked}
assert not UNBOUND, '\n'.join(UNBOUND)
# RevoluteLink: Link is novtable and RevoluteLink() is inline (MotorJoint() 005e5bf0), so no vtable is emitted here;
# the original vtable is checked by RTTI and its one slot is the evidence-named computeChildInParent.
assert original.vtable_class(0x83f75c) == ('.?AVRevoluteLink@RBX@@', 0)
assert d(0x83f75c) == 0x613cc0 and names.get(0x613cc0, '').startswith('?computeChildInParent@RevoluteLink@RBX@@')


# ---- RTTI bases, allocation sizes ------------------------------------------------------------------------------
def bases(vt):
    locator = d(vt - 4)
    hierarchy = d(locator + 16)
    items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
    return [(original.string(d(item) + 8), struct.unpack('<i', original.data(item + 8, 4))[0]) for item in items]


assert bases(0x8341b8) == [('.?AVLog@RBX@@', 0)]
assert bases(0x84d1cc) == [('.?AVIndexBox@RBX@@', 0)]
assert bases(0x82f848) == [('.?AVGuiTarget@RBX@@', 0)]
assert bases(0x843714) == [('.?AVBlockBlockContact@RBX@@', 0), ('.?AVContact@RBX@@', 0), ('.?AVEdge@RBX@@', 0),
                           ('.?AVIPipelined@RBX@@', 0)]
assert bases(0x84b24c) == [('.?AVPoint@RBX@@', 0), ('.?AVKernelIndex@RBX@@', 4)]
assert bases(0x83f75c) == [('.?AVRevoluteLink@RBX@@', 0), ('.?AVLink@RBX@@', 0)]
assert bases(0x832a04) == [('.?AVNullController@RBX@@', 0), ('.?AVController@RBX@@', 0),
                           ('.?AVReferenceCountedObject@G3D@@', 0)]
assert bases(0x82f510) == [('.?AVStandardOut@RBX@@', 0), ('.?AV?$enable_shared_from_this@VStandardOut@RBX@@@boost@@', 0x20),
                           ('.?AV?$Notifier@VStandardOut@RBX@@UStandardOutMessage@2@@RBX@@', 0)]


def pushes_before(row, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % row)
    at = body.index(b'\x68' + struct.pack('<I', size)) if size >= 0x80 else body.index(b'\x6a' + bytes([size]))
    call = body.index(b'\xe8', at)
    while (row + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)


pushes_before(0x569620, 0x30, 0x569530)      # singleton: new(0x30) StandardOut()
pushes_before(0x5e5bf0, 0xd0, 0x613d20)      # MotorJoint(): new(0xd0) RevoluteLink -> Link()
pushes_before(0x60d770, 0x7c, 0x60d500)      # ContactManager::createContact: new(0x7c) BlockBlockContact
body, _, _ = match.target('2008-06', '00599e50')   # static NullController at 00976384, 0x0c bytes (+ guard 00976390)
for at in (0x976384, 0x976388, 0x97638c, 0x976390):
    assert struct.pack('<I', at) in body, hex(at)

exact = sorted({r['address'] for rows in methods.values() for r in rows})
sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + HDRS + list(SOURCES.values())
receipt = {
    'classes': ['RBX::Log', 'RBX::IndexBox', 'RBX::StandardOut', 'RBX::Point', 'RBX::Link / RBX::RevoluteLink',
                'RBX::NullController', 'RBX::GuiTarget', 'RBX::BlockBlockContact'],
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'units': unit_flags, 'pending': pend_flags, 'pending_stages': bbc_pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj, pend_obj, bbc_pend_obj] + list(objs.values())},
    'layout': {
        'Log': 'vtable; std::string name +0x04; worstSeverity +0x20; const std::string logFile +0x24; std::ofstream +0x40 '
               '(ctor 005a6da0)',
        'IndexBox': '0x64: vtable; Vector3 corner[8] +0x04 (ctor 007bbed0)',
        'StandardOut': '0x30 (singleton 00569620 news 0x30): Notifier +0, enable_shared_from_this +0x20, mutex +0x28',
        'Point': '0x34: vtable; KernelIndex +0x04; numOwners +0x08; body +0x0c; localPos/worldPos/force +0x10/+0x1c/+0x28',
        'RevoluteLink': '0xd0 (MotorJoint() news 0xd0): Link (novtable) body +0x04, four CoordinateFrames +0x08..+0xc7, '
                        'stateIndex +0xc8; jointAngle +0xcc',
        'NullController': '0x0c (ReferenceCountedObject only)',
        'GuiTarget': 'vtable only; GuiResponse 8 bytes',
        'BlockBlockContact': '0x7c (createContact news 0x7c): Contact 0x34; Array<ContactConnector*> connectors +0x34; '
                             'Array<bool> matched +0x40; int +0x4c / +0x50 (zeroed, no reader); float separation +0x54; '
                             'int +0x58; bool planeContact +0x5c; int +0x60; int feature[2] +0x64; int bPlane +0x6c / '
                             'bOther +0x70; NormalId planeID +0x74 / otherPlaneID +0x78 (ctor 0060d500, implicit dtor '
                             '0060d5a0)',
    },
    'methods': methods,
    'folded_rows': folds,
    'folded_bodies': {k: hex(v) for k, v in FOLDED.items()},   # byte-compared with the shared original copy
    'exact_count': sum(len(v) for v in methods.values()), 'exact_unique_addresses': len(exact),
    'exact_addresses': exact,
    'pending_methods': pend_out,
    'pending_note': 'Pending rows are exact only against generated header copies and are not counted as exact: '
                    '00569590 with NATIVE_STANDARDOUT_PENDING (out/native-layouts/leaves2008-pending/util/standardout.h '
                    'without the user-declared destructor), 006087a0 with NATIVE_BLOCKBLOCKCONTACT_PENDING '
                    '(out/native-layouts/leaves2008-pending-stages/v8kernel/IStage.h with the 2008 StageType values).',
    'non_exact': {},
    'blocked': BLOCKED,
    'proposals': PROPOSALS,
    'vtables': vtables,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/leaves2008-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native leaves2008: %d rows exact (%d unique addresses), %d folded, %d pending-only, %d vtables checked' % (
    receipt['exact_count'], len(exact), len(folds), len(pend_out), len(vtables)))
