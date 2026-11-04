"""Verify the inactive native RBX::Stats recovery (2008-06): Stats::Item, TypedStatsItem<unsigned int>, TypedMemItem,
StatsService, the global ProfilingItem descriptors, and the WorkspaceStatsItem declaration.

Builds (document-swap flags, VS2008 RTM 21022), all from the current native headers unless noted:
  * tests/NativeStatsServiceLayout.cpp  sizeof/offset probes (mov eax, imm32; ret);
  * native-classes/StatsService.cpp     the Stats unit 005c8e50..005ca365 without the Profiler-dependent bodies
                                        (initializers 007f5c50/007f5c80/007f5cb0, atexit 007fed90..007fedf0), the
                                        StatsService template instances the original keeps in another unit
                                        (00455dc0..00458580, 00457af0, 007faf10) and the Item COMDAT bodies
                                        (0045b100..0045f720, 004ac430..004b4e50, 007faf30);
  * StatsService.cpp with /DNATIVE_STATS_PENDING against generated header copies in out/native-layouts/stats-pending/:
    reflection/type.h with RBX::Reflection::Tuple (PROPOSAL_TUPLE: the GetTimes descriptor returns a Tuple, RTTI of
    vtable 00839c2c) and reflection/reflection.h whose 0-argument BoundFuncDesc::call assigns through
    Value::operator= instead of Value::set (PROPOSAL_REFLECTION; call<double> 005e17f0). Rows exact only in this
    build are recorded exact=false (pending-build-only) and not counted.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol binds to one
address across all rows. Vtables are compared slot by slot from the object built with the current headers.
Writes work/2008-06/shared-layouts/stats-service-working.json.
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
SRC = R / 'native-classes/StatsService.cpp'
STATS_H = R / 'native-headers/stats/Stats.h'
WSI_H = R / 'native-headers/stats/WorkspaceStatsItem.h'
LAYOUT = R / 'tests/NativeStatsServiceLayout.cpp'

# Proposed change to a shared header (not edited here; generated copy for the pending build only).
PROPOSAL_REFLECTION_ANCHOR = '\t\t\t\treturnValue.set<ReturnType>((o->*function)());\n'
PROPOSAL_REFLECTION = '\t\t\t\treturnValue = (o->*function)(); // 2008: Value::operator= (call<double> 005e17f0)\n'

# RBX::Reflection::Tuple: struct (RTTI .?AUTuple@Reflection@RBX@@); 0x18 bytes, a vector<Value> at +0 (005ad6d0
# new(0x18) + vector(size_t); ProfilingItem::getTimes 005c9440 builds its result with vector(3) and fills begin()
# at +0xc); Type::singleton<Tuple> 0056d020, boost::any holder<Tuple> (any ctor 0058b220), destructor 0042d630.
PROPOSAL_TUPLE_ANCHOR = '\t\tclass SignatureDescriptor\n'
PROPOSAL_TUPLE = ('\t\tstruct Tuple // proposal (2008 RTTI .?AUTuple@Reflection@RBX@@, size 0x18)\n\t\t{\n'
                  '\t\t\tValueCollection values;\n\t\t\texplicit Tuple(size_t count) : values(count) {}\n\t\t};\n\n')

pending = OUT / 'stats-pending'
(pending / 'reflection').mkdir(parents=True, exist_ok=True)
text = (R / 'native-headers/reflection/reflection.h').read_text()
assert text.count(PROPOSAL_REFLECTION_ANCHOR) == 1
(pending / 'reflection/reflection.h').write_text(text.replace(PROPOSAL_REFLECTION_ANCHOR, PROPOSAL_REFLECTION))
text = (R / 'native-headers/reflection/type.h').read_text()
assert text.count(PROPOSAL_TUPLE_ANCHOR) == 1
(pending / 'reflection/type.h').write_text(text.replace(PROPOSAL_TUPLE_ANCHOR, PROPOSAL_TUPLE + PROPOSAL_TUPLE_ANCHOR))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeStatsServiceLayout', LAYOUT)
main_obj, main_flags = build('NativeStatsService', SRC)
pend_obj, pend_flags = build('NativeStatsServicePending', SRC, ['/I' + str(pending), '/DNATIVE_STATS_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeStatsItemSize@@', 0x158), ('?nativeStatsTypedMemItemSize@@', 0x178),
                      ('?nativeStatsServiceSize@@', 0x130), ('?nativeWorkspaceStatsItemSize@@', 0x158)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
VEC = '?$vector@VValue@Reflection@RBX@@V?$allocator@VValue@Reflection@RBX@@@std@@@std@@'
TUP = 'UTuple@Reflection@RBX@@'
NFI = '?$NonFactoryProduct@VInstance@RBX@@$1?sStatsItem@Stats@2@3PADA@RBX@@'
NFS = '?$NonFactoryProduct@VInstance@RBX@@$1?sStats@Stats@2@3PADA@RBX@@'
DNI = '?$DescribedNonCreatable@VItem@Stats@RBX@@VInstance@3@$1?sStatsItem@23@3PADA@RBX@@'
DNS = '?$DescribedNonCreatable@VStatsService@Stats@RBX@@VInstance@3@$1?sStats@23@3PADA@RBX@@'
DI = '?$Described@VItem@Stats@RBX@@$1?sStatsItem@23@3PADAV?$NonFactoryProduct@VInstance@RBX@@$1?sStatsItem@Stats@2@3PADA@3@@Reflection@RBX@@'
DS = '?$Described@VStatsService@Stats@RBX@@$1?sStats@23@3PADAV?$NonFactoryProduct@VInstance@RBX@@$1?sStats@Stats@2@3PADA@3@@Reflection@RBX@@'
DP = '?$Described@VProfilingItem@@$1?sProfilingItem@@3QBDBV?$NonFactoryProduct@VItem@Stats@RBX@@$1?sProfilingItem@@3QBDB@RBX@@@Reflection@RBX@@'
TSI = '?$TypedStatsItem@I@Stats@RBX@@'
BFS = '?$BoundFuncDesc@VItem@Stats@RBX@@$$A6A?AV' + STR + 'XZ$0A@@Reflection@RBX@@'
BFD = '?$BoundFuncDesc@VItem@Stats@RBX@@$$A6ANXZ$0A@@Reflection@RBX@@'
BFT = '?$BoundFuncDesc@VProfilingItem@@$$A6A?A' + TUP + 'N@Z$00@Reflection@RBX@@'
SPI = '?$sp_counted_impl_pd@PAVItem@Stats@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@detail@boost@@'
SPM = '?$sp_counted_impl_pd@PAVTypedMemItem@Stats@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@detail@boost@@'

# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                      # 0045b100
    '??0Instance@RBX@@QAE@PBD@Z': 0x55b960,                   # 00455e30
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                      # 0045ba10, 00455f00
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,        # 005c9c70, 005c9dc0
    '??2@YAPAXI@Z': 0x6a0920, '_atexit': 0x6a17af,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,            # 0045b1d0, 00455dc0
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,             # 0045c660, 00457030
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,   # 005c9650
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,  # 005c9880
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,  # 007fedf0
    '??$singleton@N@Type@Reflection@RBX@@SAABV012@XZ': 0x56cd10,
    '??$singleton@V' + STR + '@Type@Reflection@RBX@@SAABV012@XZ': 0x56cdf0,
    '??$singleton@' + TUP + '@Type@Reflection@RBX@@SAABV012@XZ': 0x56d020,   # 005c9880, 005c9950
    '??$convert@N@Value@Reflection@RBX@@QAEAANXZ': 0x56ee50,   # 005c9950
    '??$?0V' + STR + '@any@boost@@QAE@ABV' + STR + '@Z': 0x417230,   # 005c96c0
    '??$?0' + TUP + '@any@boost@@QAE@AB' + TUP + '@Z': 0x58b220,   # 005c9950 (any holding the result Tuple)
    '??1' + VEC + 'QAE@XZ': 0x42d630,                          # 005c9950 (result Tuple's vector destructor)
    '?formatMem@Log@RBX@@SA?AV' + STR + 'I@Z': 0x5a6bc0,      # 005c8ea0
    '?vformat@G3D@@YA?AV' + STR + 'PBDPAD@Z': 0x5099f0,       # 005c8f20
    '??R?$function0@IV?$allocator@Vfunction_base@boost@@@std@@@boost@@QBEIXZ': 0x42afc0,   # 005c9c50 (ICF function0<bool>)
    '?has_empty_target@function@detail@boost@@YA_NZZ': 0x60a2f0,
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,   # catch funclets 004ac49e / 005c92ae
    '__TI2?AVbad_cast@std@@': 0x8d362c,                       # 005c9750 throw
}
# Descriptor objects and class-name arrays: the `this` / pushes the original passes.
DATA = {
    '?sStatsItem@Stats@RBX@@3PADA': 0x950c6c,        # "StatsItem" (doDeclare 0045b1d0, classDescriptor 0045dc70)
    '?sStats@Stats@RBX@@3PADA': 0x950c64,            # "Stats" (doDeclare 00455dc0, classDescriptor 00457af0)
    '?sProfilingItem@@3QBDB': 0x839bc8,              # "ProfilingItem" (classDescriptor 005c95e0)
    '_func_GetValueString': 0x9797e0,                # static descriptors (initializers 007f5c50 / 007f5c80 / 007f5cb0)
    '_func_GetValue': 0x979820,
    '_func_GetTimes': 0x979860,
    '__real@41f0000000000000': 0x811240,              # 2^32 (unsigned -> double, 005c8ea0 / 005c9140)
}
for address, text in ((0x950c6c, 'StatsItem'), (0x950c64, 'Stats'), (0x839bc8, 'ProfilingItem')):
    assert original.string(address) == text, (hex(address), text)
assert struct.unpack('<d', original.data(0x811240, 8))[0] == 4294967296.0

# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    '??_GStatsService@Stats@RBX@@UAEPAXI@Z': 0x455f00, '??_G' + DNS + 'UAEPAXI@Z': 0x455f00,
    '??_G' + NFS + 'UAEPAXI@Z': 0x455f00, '??_G' + DNI + 'UAEPAXI@Z': 0x455f00, '??_G' + NFI + 'UAEPAXI@Z': 0x455f00,
    '??_GTypedMemItem@Stats@RBX@@UAEPAXI@Z': 0x45eed0,
    '?className@' + NFI + 'SAABVName@2@XZ': 0x45c660, '??$declare@$1?sStatsItem@Stats@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x45c660,
    '?className@' + NFS + 'SAABVName@2@XZ': 0x457030, '??$declare@$1?sStats@Stats@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x457030,
    '?update@Item@Stats@RBX@@MAEXXZ': 0x47d410,
    '?askAddChild@StatsService@Stats@RBX@@MBE_NPBVInstance@3@@Z': 0x45ec80,
    '?write@StatsService@Stats@RBX@@MAEPAVXmlElement@@XZ': 0x416690,
}
# Call / vtable targets whose own rows are not exact here: bound by the address the original uses; never proof.
UNPROVEN = {
    '??0' + TSI + 'QAE@PBI@Z': 0x5bc860,             # TypedMemItem ctor 005c9bd0 calls it (row compiled, not exact)
    '?update@' + TSI + 'MAEXXZ': 0x5bc930,           # vtable 00837f1c slot 16 (row compiled, not exact)
    '??$call@N@' + BFD + 'ABEXPAVItem@Stats@2@AAVValue@12@@Z': 0x5e17f0,   # pending-build-only row
    '?execute@' + BFD + 'UBEXPAVDescribedBase@23@AAVArguments@FunctionDescriptor@23@@Z': 0x5c9820,  # pending-build-only
    # sp_counted_impl_pd::dispose 0048ee50 inlines Creatable<Instance>::Deleter::operator() (0055b770 + virtual delete),
    # whose body the shared util/Object.h only declares; vtable slot 1 of 00824780 / 00839c00.
    '?dispose@' + SPI + 'UAEXXZ': 0x48ee50, '?dispose@' + SPM + 'UAEXXZ': 0x48ee50,
    '?getTimes@ProfilingItem@@QAE?A' + TUP + 'N@Z': 0x5c9440,     # GetTimes initializer 007f5cb0 (body not recovered)
}

# Rows: (address or (contiguous addresses), symbol or unique symbol prefix)
ROWS = [
    # Stats unit 005c8e50..005ca365
    (0x5c8e50, '?getValue@Item@Stats@RBX@@'),
    (0x5c8e70, '?getStringValue2@Item@Stats@RBX@@'),
    (0x5c8ea0, '?formatMem@Item@Stats@RBX@@'),
    (0x5c8f20, '?formatValue@Item@Stats@RBX@@QAAXNPBDZZ'),
    (0x5c90b0, '??$formatValue@N@Item@Stats@RBX@@'), (0x5c90e0, '??$formatValue@M@Item@Stats@RBX@@'),
    (0x5c9110, '??$formatValue@H@Item@Stats@RBX@@'), (0x5c9140, '??$formatValue@I@Item@Stats@RBX@@'),
    (0x5c9170, '??$formatValue@_N@Item@Stats@RBX@@'),
    ((0x5c9240, 0x5c92ae), '??$?0PAVTypedMemItem@Stats@RBX@@VDeleter@'),
    (0x5c9390, '??$?0VTypedMemItem@Stats@RBX@@VDeleter@'),
    (0x5c9650, '??0' + BFS), (0x5c96c0, '??$call@V' + STR + '@' + BFS), (0x5c9750, '?execute@' + BFS),
    (0x5c97b0, '??0' + BFD),
    (0x41bdf0, '??_G' + BFS), (0x41bdf0, '??_G' + BFD),   # ICF-shared deleting destructors
    (0x5c9b90, '??_EItem@Stats@RBX@@WCE@AEPAXI@Z'),
    (0x5c9bd0, '??0TypedMemItem@Stats@RBX@@'), (0x5c9c50, '?update@TypedMemItem@Stats@RBX@@'),
    (0x5c9c70, '?createChildItem@Item@Stats@RBX@@'),
    (0x5c9d40, '??$create@VTypedMemItem@Stats@RBX@@PBI@'),
    (0x5c9dc0, '?createBoundMemChildItem@Item@Stats@RBX@@'),
    (0x5ca170, '??_EItem@Stats@RBX@@WBA@AEPAXI@Z'), (0x5ca180, '??_EItem@Stats@RBX@@WGE@AEPAXI@Z'),
    (0x5ca190, '??_EItem@Stats@RBX@@WIE@AEPAXI@Z'),
    (0x5ca1a0, '??_GItem@Stats@RBX@@UAEPAXI@Z'),
    (0x7f5c50, '??__Efunc_GetValueString@'), (0x7f5c80, '??__Efunc_GetValue@'),
    (0x7fedf0, '??__Ffunc_GetValueString@'), (0x7feda0, '??__Ffunc_GetValue@'),
    # Item / TypedStatsItem<unsigned int> COMDAT and ICF-shared bodies the original keeps outside the unit
    (0x45ebe0, '??0Item@Stats@RBX@@QAE@XZ'),
    (0x45eb30, '??0' + DNI + 'IAE@XZ'),
    (0x45b100, '??0' + NFI + 'QAE@XZ'),
    (0x45dc70, '?classDescriptor@' + DI),
    (0x7faf30, '??__Ffoo@?1??classDescriptor@' + DI),
    (0x45ba10, '??1Item@Stats@RBX@@UAE@XZ'),
    (0x45ec80, '?askAddChild@Item@Stats@RBX@@'),
    (0x45ec80, '?askAddChild@StatsService@Stats@RBX@@'),
    (0x416690, '?write@StatsService@Stats@RBX@@'),
    (0x47d410, '?update@Item@Stats@RBX@@'),
    (0x45f720, '??_EItem@Stats@RBX@@WBE@AEPAXI@Z'), (0x5bcd70, '??_EItem@Stats@RBX@@WEE@AEPAXI@Z'),
    (0x45ecb0, '??_EItem@Stats@RBX@@WKE@AEPAXI@Z'), (0x5a6610, '??_EItem@Stats@RBX@@WME@AEPAXI@Z'),
    (0x45c660, '?getClassName@' + NFI),
    (0x45b1d0, '??$doDeclare@$1?sStatsItem@Stats@RBX@@3PADA@'), (0x45b6e0, '??$callDoDeclare@$1?sStatsItem@Stats@RBX@@3PADA@'),
    (0x4b4e50, '??$create@VItem@Stats@RBX@@@'),
    (0x4ad3c0, '??$?0VItem@Stats@RBX@@VDeleter@'),
    ((0x4ac430, 0x4ac49e), '??$?0PAVItem@Stats@RBX@@VDeleter@'),
    (0x415000, '??_G' + SPI), (0x5a0460, '?get_deleter@' + SPI),
    (0x415000, '??_G' + SPM), (0x5a0460, '?get_deleter@' + SPM),
    (0x45ee60, '??1' + TSI + 'UAE@XZ'), (0x45eed0, '??_G' + TSI + 'UAEPAXI@Z'),
    (0x45eda0, '??_E' + TSI + 'WBA@AEPAXI@Z'), (0x5a4150, '??_E' + TSI + 'WBE@AEPAXI@Z'),
    (0x5a4140, '??_E' + TSI + 'WCE@AEPAXI@Z'), (0x45ed90, '??_E' + TSI + 'WEE@AEPAXI@Z'),
    (0x45efd0, '??_E' + TSI + 'WGE@AEPAXI@Z'), (0x45efe0, '??_E' + TSI + 'WIE@AEPAXI@Z'),
    (0x5c9c40, '??_E' + TSI + 'WKE@AEPAXI@Z'), (0x45efc0, '??_E' + TSI + 'WME@AEPAXI@Z'),
    (0x45eda0, '??_ETypedMemItem@Stats@RBX@@WBA@AEPAXI@Z'), (0x5a4150, '??_ETypedMemItem@Stats@RBX@@WBE@AEPAXI@Z'),
    (0x5a4140, '??_ETypedMemItem@Stats@RBX@@WCE@AEPAXI@Z'), (0x45ed90, '??_ETypedMemItem@Stats@RBX@@WEE@AEPAXI@Z'),
    (0x45efd0, '??_ETypedMemItem@Stats@RBX@@WGE@AEPAXI@Z'), (0x45efe0, '??_ETypedMemItem@Stats@RBX@@WIE@AEPAXI@Z'),
    (0x5c9c40, '??_ETypedMemItem@Stats@RBX@@WKE@AEPAXI@Z'), (0x45efc0, '??_ETypedMemItem@Stats@RBX@@WME@AEPAXI@Z'),
    (0x5ec170, '?deref@' + TSI),
    # StatsService (constructor and template instances live in another unit in the original)
    (0x458520, '??0StatsService@Stats@RBX@@QAE@XZ'),
    (0x458480, '??$?0PBD@' + DNS),
    (0x455e30, '??$?0PBD@' + NFS),
    (0x457af0, '?classDescriptor@' + DS),
    (0x7faf10, '??__Ffoo@?1??classDescriptor@' + DS),
    (0x455f00, '??_GStatsService@Stats@RBX@@UAEPAXI@Z'),
    (0x455f30, '??_EStatsService@Stats@RBX@@WBA@AEPAXI@Z'), (0x409d40, '??_EStatsService@Stats@RBX@@WBE@AEPAXI@Z'),
    (0x5e28b0, '??_EStatsService@Stats@RBX@@WCE@AEPAXI@Z'), (0x609d90, '??_EStatsService@Stats@RBX@@WEE@AEPAXI@Z'),
    (0x4c9c40, '??_EStatsService@Stats@RBX@@WGE@AEPAXI@Z'), (0x458580, '??_EStatsService@Stats@RBX@@WIE@AEPAXI@Z'),
    (0x45ebd0, '??_EStatsService@Stats@RBX@@WKE@AEPAXI@Z'), (0x455f20, '??_EStatsService@Stats@RBX@@WME@AEPAXI@Z'),
    (0x457030, '?getClassName@' + NFS),
    (0x455dc0, '??$doDeclare@$1?sStats@Stats@RBX@@3PADA@'), (0x4563f0, '??$callDoDeclare@$1?sStats@Stats@RBX@@3PADA@'),
]
PENDING_ROWS = [
    (0x5e17f0, '??$call@N@' + BFD),
    (0x5c9820, '?execute@' + BFD),
    (0x5c95e0, '?classDescriptor@' + DP),
    (0x5c9880, '??0' + BFT), (0x5c9950, '??$call@' + TUP + '@' + BFT), (0x5c99f0, '?execute@' + BFT),
    (0x7f5cb0, '??__Efunc_GetTimes@'), (0x7fede0, '??__Ffunc_GetTimes@'),
    (0x7fed90, '??__Ffoo@?1??classDescriptor@' + DP),
    (0x4a34e0, '??1' + BFT + 'UAE@XZ'),
]
# Compiled, not exact; recorded with exact=false and the reason.
NONEXACT_ROWS = [
    (0x5bc860, '??0' + TSI + 'QAE@PBI@Z', 'COMDAT from another unit: there boost::function0 assign_to and the vtable '
     'assign_to are inlined down to has_empty_target (194 bytes); this unit keeps the inner assign_to out of line (120)'),
    (0x5bc930, '?update@' + TSI + 'MAEXXZ', 'COMDAT from another unit where formatValue<unsigned int> 005c9140 is out '
     'of line; here the specialization body is visible and gets inlined (57 vs 34 bytes)'),
]
NOT_ATTEMPTED = {
    '005c9440': 'ProfilingItem::getTimes (Profiler::getData 005c4120 returning a 2008 {double, double, int} Bucket); needs a native 2008 util/Profiling.h',
    '005c9fe0': 'ProfilingItem::update (getData, bucket helpers 005c3f40/005c3f60, "%.3g/s", "%s, %.3gfps (%.3g%%)"); needs util/Profiling.h',
    '005ca240': 'Item::createBoundChildItem(const Profiler&) (setName(profiler.name.c_str()), name at +0xc020); needs util/Profiling.h',
    '005c9ac0/005c9ed0/005c9f70/005ca1c0/005c91b0/005c92e0/005c9b20/005c9ba0/005c9bb0/005c92d0/005c921e':
        'ProfilingItem constructor chain, create<ProfilingItem>(reference_wrapper), its shared_count/shared_ptr and '
        'Name::declare<sProfilingItem> instances: only emitted once createBoundChildItem is recovered',
    '005c8fa0': 'formatValue specialization for a type with a double at +0x48 ("%s (%.3gfps)", Log::formatTime); called from 0045ee49; type not identified',
    '005a5c90': 'WorkspaceStatsItem constructor (2431 bytes, Workspace unit): needs native Workspace/World/RunService headers and createChildItem<T>(name, function0<T>) templates 005a52c0/005a5430/005a55a0',
    '005ad810/005ad770/005a8dd0': 'Item(const char*) chain: COMDATs of the script unit (create<Item, const char*> 005adb70); not instantiated here',
    '00458590/00458610/00455ea0/00457b60': 'Creatable<Instance>::create<StatsService> and ServiceProvider::create/getClassIndex<StatsService> instances (need native ServiceProvider create/find bodies)',
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}


def target_of(address):
    parts = address if isinstance(address, tuple) else (address,)
    code, relocs = b'', []
    for part in parts:
        assert part == parts[0] + len(code), ('rows not contiguous', [hex(p) for p in parts])
        body, refs, _ = match.target('2008-06', '%08x' % part)
        relocs += [r + len(code) for r in refs]
        code += body
    return code, relocs


def resolve(obj, rows):
    raw = Path(obj).read_bytes()
    funcs = match.coff_functions(raw)
    out = []
    for row in rows:
        address, key = row[0], row[1]
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def first(address):
    return address[0] if isinstance(address, tuple) else address


def verify(obj, rows, own, strict=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '+'.join('%08x' % a for a in (address if isinstance(address, tuple) else (address,))),
                 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        base = first(address)
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
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'literal %r' % literal[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own row (??_G)'
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in FOLDED:
                assert FOLDED['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'folded (??_G)'
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in FOLDED:
                assert FOLDED[symbol] == value, (name, symbol, hex(value))
                how = 'folded'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol.startswith('??_B?1??') or symbol.startswith('?$S') or '?$TSS' in symbol or symbol.startswith('?flag@') \
                    or symbol.startswith('?foo@') or symbol.startswith('?n@') or symbol.startswith('?root@') \
                    or symbol.startswith('?stored_vtable@'):
                how = 'local static'
            else:
                UNBOUND.append('%s in %s -> %s' % (symbol, name, hex(value)))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


rows = resolve(main_obj, ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
nonexact_rows = resolve(main_obj, NONEXACT_ROWS)
own = {}
for address, name in rows + pend_rows:
    own.setdefault(name, first(address))
main_out = verify(main_obj, rows, own)
pend_out = verify(pend_obj, pend_rows, own)
for row in pend_out:   # exact only with the generated reflection.h copy: not counted
    row['exact'] = False
    row['exact_pending_build_only'] = True
nonexact_out = verify(main_obj, nonexact_rows, own, strict=False)
for row, (_, _, why) in zip(nonexact_out, NONEXACT_ROWS):
    if row['exact']:
        raise AssertionError('row unexpectedly exact, re-review: %s' % row['address'])
    row['reason'] = why
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables from the object built with the current headers, slot by slot ---------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, prefix):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    hits = [s for s in definitions if s.startswith(prefix)]
    assert len(hits) == 1, (prefix, hits)
    start, section = definitions[hits[0]]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return hits[0], [slots[i] for i in range(len(slots))]


INSTANCE_VT = 0x82d884
assert original.vtable_class(INSTANCE_VT) == ('.?AVInstance@RBX@@', 0)


def check_vtable(prefix, address, rtti, inherit=None):
    symbol, slots = compiled_vtable(main_obj, prefix)
    assert norm(original.vtable_class(address)[0]) == norm(rtti), (hex(address), original.vtable_class(address), rtti)
    out, bad = [], []
    for i, slot in enumerate(slots):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        else:
            expect, how = slot_names.get(slot), 'bound'
        if expect is not None:
            ok = expect == value
        elif norm(names.get(value, '')) == norm(slot):
            ok, how = True, 'evidence name'
        elif inherit is not None and value == d(inherit + 4 * i) and 'Stats@RBX' not in slot.split('@@')[0] \
                and 'ProfilingItem' not in slot:
            ok, how = True, 'inherited (slot of the base vtable %08x)' % inherit
        else:
            ok, how = False, 'unbound'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return {'symbol': symbol, 'address': '%08x' % address, 'slots': out}


GUID = '6B?$GuidItem@VInstance@RBX@@@'
AFP = '6B?$AbstractFactoryProduct@VInstance@RBX@@@'
vt = {
    'Item': check_vtable('??_7Item@Stats@RBX@@' + GUID, 0x819fc4, '.?AVItem@Stats@RBX@@', INSTANCE_VT),
    'Item_factory': check_vtable('??_7Item@Stats@RBX@@' + AFP, 0x819fb8, '.?AVItem@Stats@RBX@@'),
    'TypedStatsItem<unsigned int>': check_vtable('??_7' + TSI + GUID, 0x837f1c, '.?AV' + TSI, INSTANCE_VT),
    'TypedMemItem': check_vtable('??_7TypedMemItem@Stats@RBX@@' + GUID, 0x839d7c, '.?AVTypedMemItem@Stats@RBX@@', INSTANCE_VT),
    'TypedMemItem_factory': check_vtable('??_7TypedMemItem@Stats@RBX@@' + AFP, 0x839d6c, '.?AVTypedMemItem@Stats@RBX@@'),
    'StatsService': check_vtable('??_7StatsService@Stats@RBX@@' + GUID, 0x818c1c, '.?AVStatsService@Stats@RBX@@', INSTANCE_VT),
    'StatsService_factory': check_vtable('??_7StatsService@Stats@RBX@@' + AFP, 0x818c10, '.?AVStatsService@Stats@RBX@@'),
    'DescribedNonCreatable<Item>': check_vtable('??_7' + DNI + GUID, 0x819f04, '.?AV' + DNI, INSTANCE_VT),
    'NonFactoryProduct<sStatsItem>': check_vtable('??_7' + NFI + GUID, 0x8197fc, '.?AV' + NFI, INSTANCE_VT),
    'DescribedNonCreatable<StatsService>': check_vtable('??_7' + DNS + GUID, 0x818b5c, '.?AV' + DNS, INSTANCE_VT),
    'NonFactoryProduct<sStats>': check_vtable('??_7' + NFS + GUID, 0x818424, '.?AV' + NFS, INSTANCE_VT),
    'BoundFuncDesc GetValueString': check_vtable('??_7' + BFS, 0x839c14, '.?AV' + BFS),
    'BoundFuncDesc GetValue': check_vtable('??_7' + BFD, 0x839c20, '.?AV' + BFD),
    'sp_counted_impl_pd<Item*>': check_vtable('??_7' + SPI, 0x824780, '.?AV' + SPI),
    'sp_counted_impl_pd<TypedMemItem*>': check_vtable('??_7' + SPM, 0x839c00, '.?AV' + SPM),
}
assert vt['Item']['slots'][16]['original'] == '0047d410' and vt['TypedMemItem']['slots'][16]['original'] == '005c9c50'
assert vt['StatsService']['slots'][14]['original'] == '00416690' and len(vt['StatsService']['slots']) == 16
assert len(vt['Item']['slots']) == len(vt['TypedMemItem']['slots']) == 17

# ---- RTTI bases, allocation sizes and strings -----------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert bases(0x818c1c)['.?AVService@RBX@@'] == 0x130
assert '.?AV' + TSI in bases(0x839d7c) and '.?AVItem@Stats@RBX@@' in bases(0x839d7c)
assert '.?AVItem@Stats@RBX@@' in bases(0x8340ac) and original.vtable_class(0x8340ac) == ('.?AVWorkspaceStatsItem@RBX@@', 0)
assert original.vtable_class(0x839f0c) == ('.?AVProfilingItem@@', 0)
for factory, size, ctor in ((0x458590, 0x130, 0x458520), (0x5c9d40, 0x178, 0x5c9bd0), (0x4b4e50, 0x158, 0x45ebe0),
                            (0x5a6620, 0x158, 0x5a5c90), (0x5ca1c0, 0x160, 0x5c9f70)):
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)
# The one call target bound without an exact row of its own: 005bc860 is TypedStatsItem<unsigned int>(const unsigned int*)
# (it stores the primary vtable 00837f1c, RTTI .?AV?$TypedStatsItem@I@Stats@RBX@@, after calling Item() 0045ebe0).
body, _, _ = match.target('2008-06', '005bc860')
assert b'\xc7\x06' + struct.pack('<I', 0x837f1c) in body and original.vtable_class(0x837f1c) == ('.?AV' + TSI, 0)
for address, text in ((0x818c5c, 'Stats'), (0x839f70, 'GetValueString'), (0x839f80, 'GetValue'),
                      (0x839f8c, 'GetTimes'), (0x81f3c0, 'window'), (0x833e2c, 'Workspace')):
    assert original.string(address) == text, (hex(address), text)

sha = nb.sha
paths = [Path(__file__).resolve(), STATS_H, WSI_H, SRC, LAYOUT]
groups = {'main': main_out, 'pending': pend_out, 'compiled_not_exact': nonexact_out}
exact_rows = sorted({a for r in main_out if r['exact'] for a in r['address'].split('+')})
receipt = {
    'class': 'RBX::Stats::Item, TypedStatsItem<unsigned int>, TypedMemItem, StatsService, ::ProfilingItem descriptors; '
             'RBX::WorkspaceStatsItem (declaration and layout only)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'main': main_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in (layout_obj, main_obj, pend_obj)},
    'layout': {'Item': '0x158 (004b4e50); val double +0x130, sValue std::string +0x138; new virtual update at slot 16',
               'TypedStatsItem<unsigned int>': 'func boost::function0<unsigned int> +0x158',
               'TypedMemItem': '0x178 (005c9d40)',
               'StatsService': '0x130 (00458590); Service empty base at +0x130',
               'WorkspaceStatsItem': '0x158 (005a6620), no own fields',
               'ProfilingItem': '0x160 (005ca1c0); const Profiler& +0x158; global namespace (RTTI .?AVProfilingItem@@)'},
    'rows': groups,
    'exact_function_rows': exact_rows,
    'vtables': vt,
    'pending_note': 'pending rows are exact only under NATIVE_STATS_PENDING with generated copies of '
                    'native-headers/reflection/type.h (RBX::Reflection::Tuple) and reflection.h (0-argument '
                    'BoundFuncDesc::call assigns with Value::operator=) in out/native-layouts/stats-pending. The GetTimes '
                    'descriptor vtable 00839c2c is therefore not slot-checked (it exists only in the pending object).',
    'not_attempted': NOT_ATTEMPTED,
    'proposal_reflection_h': {'replace': PROPOSAL_REFLECTION_ANCHOR.strip(), 'with': PROPOSAL_REFLECTION.strip()},
    'proposal_type_h': PROPOSAL_TUPLE,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/stats-service-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Stats/StatsService: %d rows exact (%d distinct function addresses); %d pending-build-only, '
      '%d compiled-not-exact rows not counted; targets and %d vtables verified'
      % (sum(r['exact'] for r in main_out), len(exact_rows), len(pend_out), len(nonexact_out), len(vt)))
