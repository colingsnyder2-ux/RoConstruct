"""Verify the inactive native RBX::DebrisService and RBX::ForceField recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022), all from the current native headers:
  * tests/NativeDebrisForceFieldLayout.cpp  sizeof/offset probes (mov eax, imm32; ret) plus the explicit
                                            Creatable<Instance>::create<...> instantiations;
  * native-classes/DebrisService.cpp        the Debris unit 0063b330..0063c3a0 (+ class descriptor 005c06a0, doDeclare
                                            005bfe20 / callDoDeclare 005c0050, descriptor initializers 007f8b60 /
                                            007f8ba0 and their atexit functions). The static cleanup(weak_ptr) body
                                            includes its former split blocks 0063b63f and 0063b673 in the current 228-byte
                                            extent at 0063b5c0, compared in full once;
  * native-classes/ForceField.cpp           (/fp:fast) the ForceField unit 0062d0c0..0062d8d0 plus class descriptor
                                            005c0400, doDeclare 005bf9c0 / callDoDeclare 005bffb0 and atexit 007fe720
                                            (rows in tests/record_native_debris_forcefield_rows.py). The 0062d310 row of
                                            the function list holds two functions; hasForceField is compared against its
                                            bytes 00..70 and recorded as a slice, not as the whole row;
  * ForceField.cpp with NATIVE_FORCEFIELD_PENDING against out/native-layouts/debris-forcefield-pending/ (a copy of
    native v8tree/Instance.h plus Instance::visitDescendents, PROPOSAL_INSTANCE, and the declaration-only Workspace of
    tests/NativeDebrisForceFieldPendingWorkspace.h): askSetParent, the ancestor walk, isProtected, visitDescendents,
    render3dAdorn and renderPart. Rows exact only in this build are recorded exact=false (pending-build-only) and
    not counted; their symbols bind vtable slots only as UNPROVEN.
Trivial inline virtual bodies the original folds elsewhere (00565950, 0060a2f0, 0070bdf0, 00458e90) are compared so
the IRenderable vtable slots are proven, but kept in their own group and not counted.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, and the remaining
externals by the explicit EXTERNAL / DATA maps (call sites read in the original disassembly). A symbol binds to one
address across all rows. Vtables are compared slot by slot from the objects built with the current headers.
Writes work/2008-06/shared-layouts/debris-forcefield-working.json. Set NATIVE_DEBRIS_DISCOVER=1 to list unbound
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
LAYOUT = R / 'tests/NativeDebrisForceFieldLayout.cpp'
DEBRIS_SRC = R / 'native-classes/DebrisService.cpp'
DEBRIS_H = R / 'native-headers/v8datamodel/DebrisService.h'
FORCE_SRC = R / 'native-classes/ForceField.cpp'
FORCE_H = R / 'native-headers/v8datamodel/ForceField.h'
HAVE_FORCE = True
from record_native_debris_forcefield_rows import (FORCEFIELD_ROWS, FORCE_LAYOUT_ROWS, FORCE_PENDING_ROWS,  # noqa: E402
                                                 FORCE_EXTERNAL, FORCE_DATA, FORCE_FOLDED, PROPOSAL_INSTANCE,
                                                 FORCE_NON_EXACT_ROWS, FORCE_UNPROVEN, FORCE_TRIVIAL_ROWS, FORCE_PENDING_REASONS,
                                                 write_pending)
PENDING = OUT / 'debris-forcefield-pending'
write_pending(ROOT, PENDING)
DISCOVER = bool(os.environ.get('NATIVE_DEBRIS_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeDebrisForceFieldLayout', LAYOUT)
debris_obj, debris_flags = build('NativeDebrisService', DEBRIS_SRC)
if HAVE_FORCE:
    force_obj, force_flags = build('NativeForceField', FORCE_SRC, ['/fp:fast'])
    forcep_obj, forcep_flags = build('NativeForceFieldPending', FORCE_SRC,
                                     ['/fp:fast', '/I' + str(PENDING), '/DNATIVE_FORCEFIELD_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
SIZES = [('?nativeDebrisServiceSize@@', 0x158)]
if HAVE_FORCE:
    SIZES.append(('?nativeForceFieldSize@@', 0x148))
raw = layout_obj.read_bytes()
for prefix, value in SIZES:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
WPI = 'V?$weak_ptr@VInstance@RBX@@@boost@@'
SPI = 'V?$shared_ptr@VInstance@RBX@@@boost@@'
DEQ = '?$deque@' + WPI + 'V?$allocator@' + WPI + '@std@@@std@@'
BND = 'V?$bind_t@XP6AX' + WPI + '@ZV?$list1@V?$value@' + SPI + '@_bi@boost@@@_bi@2@@_bi@boost@@'
FPD = '?$FactoryProduct@VDebrisService@RBX@@VInstance@2@$1?sDebrisService@2@3PADA@RBX@@'
DCD = '?$DescribedCreatable@VDebrisService@RBX@@VInstance@2@$1?sDebrisService@2@3PADA@RBX@@'
DSD = '?$Described@VDebrisService@RBX@@$1?sDebrisService@2@3PADAV' + FPD[:-6] + '@2@@Reflection@RBX@@'
BFD = '?$BoundFuncDesc@VDebrisService@RBX@@$$A6AX' + SPI + 'N@Z$01@Reflection@RBX@@'
PDD = '?$PropDescriptor@VDebrisService@RBX@@H@Reflection@RBX@@'
GSD = '?$GetSetImpl@P8DebrisService@RBX@@BEHXZP812@AEXH@Z@' + PDD
DLR = 'VDeleter@?$Creatable@VInstance@RBX@@@'

# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': 0x405e30,  # catch funclets in complete shared_count extents
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                                   # 0063b340 tail jump
    '??0Instance@RBX@@QAE@PBD@Z': 0x55b960,                                # 0063b490
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,                     # cleanup 0063b606
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,   # 0063c40a
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a, '_atexit': 0x6a17af,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '?singleton@StandardOut@RBX@@SA?AV?$shared_ptr@VStandardOut@RBX@@@boost@@XZ': 0x569620,      # 0063b677
    '?print@StandardOut@RBX@@QAEXW4MessageType@2@ABVexception@std@@@Z': 0x416e10,                  # 0063b68d
    '??1?$shared_ptr@VStandardOut@RBX@@@boost@@QAE@XZ': 0x600660,                                  # 0063b699 (ICF-shared)
    '?lock@?$weak_ptr@VInstance@RBX@@@boost@@QBE?AV?$shared_ptr@VInstance@RBX@@@2@XZ': 0x5cab00,  # 0063b5f4 (evidence: PartInstance flavour, ICF)
    '?delay@TimerService@RBX@@QAEXV?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@N@Z': 0x5d6e10,  # 0063bc4b
    '??$create@VTimerService@RBX@@@ServiceProvider@RBX@@QBEPAVTimerService@1@XZ': 0x492020,     # 0063c378
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,  # 0063c3eb
    # TypedPropertyDescriptor<int> constructor called by the PropDescriptor ctor 0063bd73
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    # FunctionDescriptor plumbing called by the BoundFuncDesc ctor 0063c070 / declareSignature 0063b3a0 / execute 0063c130
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,   # 0063c09f (FuncDesc ctor inlined)
    '??$convert@N@Value@Reflection@RBX@@QAEAANXZ': 0x56ee50,                                          # execute 0063c130
    '??$convert@V?$shared_ptr@VInstance@RBX@@@boost@@@Value@Reflection@RBX@@QAEAAV?$shared_ptr@VInstance@RBX@@@boost@@XZ': 0x56f8c0,
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,
    '??$singleton@N@Type@Reflection@RBX@@SAABV012@XZ': 0x56cd10,
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,  # ~BoundFuncDesc 004a3d40
    # template instances ICF-shared with other instantiations (evidence names another flavour); call sites listed
    '??0?$list1@V?$value@V?$shared_ptr@VInstance@RBX@@@boost@@@_bi@boost@@@_bi@boost@@QAE@V?$value@V?$shared_ptr@VInstance@RBX@@@boost@@@12@@Z': 0x618830,   # bind 0063b770
    '??$_Allocate@PAV?$weak_ptr@VInstance@RBX@@@boost@@@std@@YAPAPAV?$weak_ptr@VInstance@RBX@@@boost@@IPAPAV12@@Z': 0x420b50,   # _Growmap 004af360
    '?_Xlen@' + DEQ + 'KAXXZ': 0x516a10,                                                          # _Growmap 004af360
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,
    '??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cae0,
    '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,
}
EXTERNAL = {k: v for k, v in EXTERNAL.items() if v is not None}
# Descriptor objects and class-name arrays: the `this` / pushes the original passes.
DATA = {
    '?sDebrisService@RBX@@3PADA': 0x9611f0,         # "Debris" (doDeclare 005bfe20, classDescriptor 005c06a0, ctor 0063beab)
    '?prop_MaxItems@@3V?$PropDescriptor@VDebrisService@RBX@@H@Reflection@RBX@@A': 0x97d4fc,   # initializer 007f8b7f
    '?func_AddItem@@3V' + BFD + 'A': 0x97d518,                                                  # initializer 007f8bc5
    '_prop_MaxItems': 0x97d4fc,      # internal-linkage name of prop_MaxItems (initializer 007f8b7f, setMaxItems 0063c3ff)
    '_func_AddItem': 0x97d518,       # internal-linkage name of func_AddItem (initializer 007f8bc5, atexit 00801080)
}
for address, text in ((0x9611f0, 'Debris'), (0x849b68, 'MaxItems'), (0x822490, 'Data'), (0x849b74, 'AddItem'),
                      (0x849b7c, 'item'), (0x849b84, 'lifetime'), (0x849b38, 'DebrisService MaxItems must be greater than 0')):
    assert original.string(address) == text, (hex(address), text)
assert struct.unpack('<d', original.data(0x8190b8, 8))[0] == 10.0   # AddItem default lifetime (007f8ba0)

# ICF / trivial-wrapper folds: the original keeps one body where this unit emits several identical ones.
FOLDED = {
    '??1' + DSD + 'UAE@XZ': 0x63b560, '??1' + DCD + 'UAE@XZ': 0x63b560,
    '??_G' + DCD + 'UAEPAXI@Z': 0x63b510,
    '?className@' + FPD + 'SAABVName@2@XZ': 0x63b6b0,
    '??$declare@$1?sDebrisService@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x63b6b0,
}
# Compiled, not exact: recorded with exact=false and the reason; their call targets bind only as UNPROVEN.
NON_EXACT_ROWS = [
    (0x63bb10, '??$assign_to@' + BND + '@?$function0@',
     'boost::function0::assign_to: the original constant-initializes the static stored_vtable (00849970 written directly, 82 bytes); '
     'this build keeps basic_vtable0 init out of line and guards the static (273 bytes)', 'debris'),
    (0x63bb70, '??$?0' + BND + '@?$function0@', 'boost::function0 constructor around the assign_to above (77 vs 175 bytes)', 'debris'),
]
UNPROVEN = {
    '??$?0' + BND + '@?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@QAE@V?$bind_t@XP6AX' + WPI + '@ZV?$list1@V?$value@' + SPI + '@_bi@boost@@@_bi@2@@_bi@1@H@Z': 0x63bb70,   # addItem 0063bc40
    '??$?0PAVDebrisService@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVDebrisService@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x5c2cd0,   # 005c2d91
}
NON_EXACT_ROWS += FORCE_NON_EXACT_ROWS
UNPROVEN.update(FORCE_UNPROVEN)

# Rows: (address or (contiguous addresses), symbol or unique symbol prefix)
LAYOUT_ROWS = [
    # Current extents include their catch funclets; verify every byte and relocation.
    (0x5c2cd0, '??$?0PAVDebrisService@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@'),
    (0x5c13e0, '??$?0PAVForceField@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@'),
    (0x5c2e10, '??$create@VDebrisService@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VDebrisService@RBX@@@boost@@XZ'),
    (0x5c2d60, '??$?0VDebrisService@RBX@@' + DLR + '1@@?$shared_ptr@VDebrisService@RBX@@@boost@@QAE@PAVDebrisService@RBX@@' + DLR + '3@@Z'),
]
DEBRIS_ROWS = [
    (0x63b330, '?getMaxItems@DebrisService@RBX@@QBEHXZ'),
    (0x63b340, '??1' + FPD + 'MAE@XZ'),
    (0x63b3a0, '?declareSignature@' + BFD),
    (0x63b400, '??D?$_Deque_const_iterator@' + WPI),
    (0x63b490, '??$?0PBD@' + FPD + 'IAE@PBD@Z'),
    (0x63b500, '??_E' + FPD + 'OCE@AEPAXI@Z'), (0x63b530, '??_E' + FPD + 'OGE@AEPAXI@Z'),
    (0x63b540, '??_E' + FPD + 'OBA@AEPAXI@Z'), (0x63b550, '??_E' + FPD + 'OBE@AEPAXI@Z'),
    (0x63b510, '??_G' + FPD + 'MAEPAXI@Z'),
    (0x63b560, '??1' + DSD + 'UAE@XZ'),
    (0x63b570, '??$getset@P8DebrisService@RBX@@BEHXZP812@AEXH@Z@' + PDD),
    (0x63b5c0, '?cleanup@@YAX' + WPI + '@Z'),
    (0x63b6b0, '?getClassName@' + FPD + 'UBEABVName@2@XZ'),
    (0x63b6d0, '?_Tidy@' + DEQ),
    (0x63b770, '??$bind@X' + WPI + 'V?$shared_ptr@VInstance@RBX@@@2@@boost@@'),
    (0x63b870, '?invoke@?$void_function_obj_invoker0@' + BND),
    (0x63b8a0, '?manager@?$functor_manager@' + BND + 'V?$allocator@Vfunction_base@boost@@@std@@@function@detail@boost@@CAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@U?$bool_@$00@mpl@4@@Z'),
    (0x63b940, '?push_back@' + DEQ),
    (0x63b9d0, '?cleanup@DebrisService@RBX@@AAEXXZ'),
    (0x63bad0, '?manage@?$functor_manager@' + BND),
    (0x63bbc0, '?addItem@DebrisService@RBX@@QAEXV?$shared_ptr@VInstance@RBX@@@boost@@N@Z'),
    (0x63bd00, '??$?0P8DebrisService@RBX@@BEHXZP801@AEXH@Z@' + PDD),
    (0x63bdb0, '??$?0PBD@' + DCD + 'IAE@PBD@Z'),
    (0x63be50, '??_E' + FPD + 'OEE@AEPAXI@Z'), (0x63be60, '??_E' + FPD + 'OIE@AEPAXI@Z'),
    (0x63be70, '??_E' + FPD + 'OKE@AEPAXI@Z'), (0x63be80, '??_E' + FPD + 'OME@AEPAXI@Z'),
    (0x63be90, '??0DebrisService@RBX@@QAE@XZ'),
    (0x63bf60, '??_EDebrisService@RBX@@WBE@AEPAXI@Z'), (0x63bf70, '??_EDebrisService@RBX@@WCE@AEPAXI@Z'),
    (0x63bf80, '??_EDebrisService@RBX@@WEE@AEPAXI@Z'), (0x63bf90, '??_EDebrisService@RBX@@WGE@AEPAXI@Z'),
    (0x63bfa0, '??_EDebrisService@RBX@@WIE@AEPAXI@Z'), (0x63bfb0, '??_EDebrisService@RBX@@WKE@AEPAXI@Z'),
    (0x63bfc0, '??_EDebrisService@RBX@@WME@AEPAXI@Z'), (0x63bfd0, '??_EDebrisService@RBX@@WBA@AEPAXI@Z'),
    (0x63bfe0, '??1DebrisService@RBX@@UAE@XZ'),
    (0x63c050, '??_GDebrisService@RBX@@UAEPAXI@Z'),
    (0x63c070, '??0' + BFD + 'QAE@'),
    (0x63c130, '?execute@' + BFD),
    (0x63c280, '?onServiceProvider@DebrisService@RBX@@MAEXPBVServiceProvider@2@0@Z'),
    (0x63c3a0, '?setMaxItems@DebrisService@RBX@@QAEXH@Z'),
    (0x5c06a0, '?classDescriptor@' + DSD + 'SAAAVClassDescriptor@23@XZ'),
    (0x5bfe20, '??$doDeclare@$1?sDebrisService@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x5c0050, '??$callDoDeclare@$1?sDebrisService@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x7fe6c0, '??__Ffoo@?1??classDescriptor@' + DSD),
    (0x7f8b60, '??__Eprop_MaxItems@@YAXXZ'),
    (0x7f8ba0, '??__Efunc_AddItem@@YAXXZ'),
    (0x801060, '??__Fprop_MaxItems@@YAXXZ'),
    (0x801080, '??__Ffunc_AddItem@@YAXXZ'),
    # template bodies the original keeps outside the unit (COMDAT / ICF-shared with other instantiations)
    (0x4a3d40, '??1' + BFD + 'UAE@XZ'),
    (0x4af360, '?_Growmap@' + DEQ),
]
LAYOUT_ROWS += FORCE_LAYOUT_ROWS
EXTERNAL.update(FORCE_EXTERNAL)
DATA.update(FORCE_DATA)
FOLDED.update(FORCE_FOLDED)

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def target_of(address):
    """Original bytes and relocation offsets of one row, of contiguous rows concatenated, or of a slice of one row
    (('slice', row, lo, hi): a function-list row that holds two functions)."""
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
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', hex(first(address)), key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, (hex(first(address)), key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': label(address),
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
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('__TI') or symbol.startswith('__CT') or symbol.startswith('__CTA'):
                # ThrowInfo: bound by consistency; its first catchable type is checked below
                how = 'throw info'
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
                    or symbol.startswith('?foo@') or symbol.startswith('?n@') or symbol.startswith('?root@'):
                how = 'local static'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


layout_rows = resolve(layout_obj, LAYOUT_ROWS)
debris_rows = resolve(debris_obj, DEBRIS_ROWS)
force_rows = resolve(force_obj, FORCEFIELD_ROWS) if HAVE_FORCE else []
forcep_rows = resolve(forcep_obj, FORCE_PENDING_ROWS)
trivial_rows = resolve(force_obj, FORCE_TRIVIAL_ROWS)
OBJ = {'layout': layout_obj, 'debris': debris_obj}
non_rows = [(resolve(OBJ[w], [(a, k)])[0], w) for a, k, _, w in NON_EXACT_ROWS]
own = {}
for address, name in layout_rows + debris_rows + force_rows + trivial_rows:
    own.setdefault(name, first(address))
# Pending-build rows: their symbols bind (for call targets and vtable slots) only as UNPROVEN, never as proof.
for address, name in forcep_rows:
    UNPROVEN.setdefault(name, first(address))
strict = not DISCOVER
layout_out = verify(layout_obj, layout_rows, own, strict)
debris_out = verify(debris_obj, debris_rows, own, strict)
force_out = verify(force_obj, force_rows, own, strict) if HAVE_FORCE else []
trivial_out = verify(force_obj, trivial_rows, own, strict)
pending_own = dict(own, **{n: first(a) for a, n in forcep_rows})
forcep_out = verify(forcep_obj, forcep_rows, pending_own, strict=False)
for row in forcep_out:  # exact only under NATIVE_FORCEFIELD_PENDING with generated shared-header copies: not counted
    row['exact_pending_build_only'] = row['exact']
    row['exact'] = False
    if row['address'] in FORCE_PENDING_REASONS:
        row['reason'] = FORCE_PENDING_REASONS[row['address']]
non_out = [verify(OBJ[w], [r], own, strict=False)[0] for r, w in non_rows]
for row, (_, _, why, _) in zip(non_out, NON_EXACT_ROWS):
    if row['exact'] and not DISCOVER:   # would need re-review
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in forcep_out:
        print('PENDING', r['address'], r['exact_pending_build_only'], r['symbol'][:100], r['size'], r['target_size'])
    for g in (layout_out, debris_out, force_out):
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
# ThrowInfo of setMaxItems 0063c3f0: first catchable type is std::runtime_error.
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
cta = d(0x8d1bc8 + 12)
assert original.string(d(d(cta + 4) + 4) + 8) == '.?AVruntime_error@std@@'

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN):
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


def check_vtable(obj, symbol, address, reference=None, own_class=''):
    """Each slot holds the address bound to its symbol, the evidence name, or (for an inherited slot) the same
    address as the base class's vtable at `reference`."""
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        else:
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value if expect is not None else norm(names.get(value, '')) == norm(slot)
        if expect is None:
            how = 'evidence name'
        if not ok and reference is not None:
            cls = slot.split('@')[1] if slot.startswith('?') and not slot.startswith('??') else ''
            if cls != own_class and value == d(reference + 4 * i):
                ok, how = True, 'inherited (same slot of the base vtable %08x)' % reference
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


# Instance's own vtable 0082d884 (Instance constructor 0055b7e0) is the reference for inherited slots.
assert original.vtable_class(0x82d884) == ('.?AVInstance@RBX@@', 0)
GI = '6B?$GuidItem@VInstance@RBX@@@1@@'
vt = {}
vt['DebrisService'] = check_vtable(debris_obj, '??_7DebrisService@RBX@@' + GI, 0x849aec, 0x82d884, 'DebrisService')
assert len(vt['DebrisService']) == 16
assert vt['DebrisService'][12]['symbol'].startswith('?onServiceProvider@DebrisService') and vt['DebrisService'][12]['original'] == '0063c280'
vt['DebrisService_FactoryProduct'] = check_vtable(debris_obj, '??_7' + FPD + GI, 0x84991c, 0x82d884, 'DebrisService')
vt['DebrisService_DescribedCreatable'] = check_vtable(debris_obj, '??_7' + DCD + GI, 0x849a2c, 0x82d884, 'DebrisService')
# The PropDescriptor<DebrisService,int>::GetSetImpl vtable 00849960 has the 2008 GetSet layout (isReadOnly, a second
# bool virtual folded to 0060a2f0, getValue, setValue): the current reflection headers lack the second slot (see the
# property.h proposal in tests/record_native_spawn.py), so that vtable is not compared here.
assert original.vtable_class(0x849960)[0] == '.?AV' + GSD and d(0x849960) == d(0x849964) == 0x60a2f0
if HAVE_FORCE:
    from record_native_debris_forcefield_rows import forcefield_vtables  # noqa: E402
    vt.update(forcefield_vtables(check_vtable, force_obj, GI))

# ---- RTTI bases, allocation sizes ------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


assert original.vtable_class(0x849aec) == ('.?AVDebrisService@RBX@@', 0)
db = bases(0x849aec)
assert db['.?AVService@RBX@@'] == 0x130 and db['.?AV' + DCD] == 0, db
factories = [(0x5c2e10, 0x158, 0x63be90)]
if HAVE_FORCE:
    from record_native_debris_forcefield_rows import FORCE_FACTORY, forcefield_rtti  # noqa: E402
    factories.append(FORCE_FACTORY)
    forcefield_rtti(original, bases)
for factory, size, ctor in factories:
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 5)
    while (factory + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, DEBRIS_H, DEBRIS_SRC]
objects = [layout_obj, debris_obj]
flags = {'layout': layout_flags, 'debris': debris_flags}
if HAVE_FORCE:
    paths += [R / 'tests/record_native_debris_forcefield_rows.py', FORCE_H, FORCE_SRC]
    paths.append(R / 'tests/NativeDebrisForceFieldPendingWorkspace.h')
    objects += [force_obj, forcep_obj]
    flags['forcefield'] = force_flags
    flags['forcefield_pending'] = forcep_flags
groups = {'layout': layout_out, 'debris': debris_out, 'forcefield': force_out}
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
groups['not_exact'] = non_out
groups['pending'] = forcep_out
groups['folded_trivial_not_counted'] = trivial_out
exact_rows = sorted({a for e in exact if '[' not in e for a in e.split('+')})
exact_slices = sorted(e for e in exact if '[' in e)   # one function of a two-function row: not a whole row
receipt = {
    'class': 'RBX::DebrisService, RBX::ForceField', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objects},
    'layout': {'DebrisService': '0x158 (005c2e10); Service empty base and std::queue<weak_ptr<Instance>> queue +0x130, maxItems +0x150, timer +0x154; class name "Debris" (char[] 009611f0)'},
    'rows': groups,
    'exact_function_rows': exact_rows,
    'exact_row_slices': exact_slices,
    'vtables': vt,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
if HAVE_FORCE:
    from record_native_debris_forcefield_rows import FORCE_LAYOUT_NOTE, FORCE_NOT_ATTEMPTED  # noqa: E402
    receipt['layout']['ForceField'] = FORCE_LAYOUT_NOTE
    receipt['not_attempted'] = FORCE_NOT_ATTEMPTED
    receipt['proposal_instance_h'] = PROPOSAL_INSTANCE
    receipt['pending_note'] = ('pending rows are exact only with a generated copy of native v8tree/Instance.h plus '
                               'Instance::visitDescendents (PROPOSAL_INSTANCE) and a declaration-only RBX::Workspace '
                               '(tests/NativeDebrisForceFieldPendingWorkspace.h) under out/native-layouts/debris-forcefield-pending.')
(ROOT / 'work/2008-06/shared-layouts/debris-forcefield-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native DebrisService/ForceField: %d distinct function addresses exact (layout %d, debris %d, forcefield %d); '
      '%d pending-build-only rows (%d exact there) and %d non-exact rows not counted; targets and %d vtables verified'
      % (len(exact_rows), sum(r['exact'] for r in layout_out), sum(r['exact'] for r in debris_out),
         sum(r['exact'] for r in force_out), len(forcep_out), sum(r['exact_pending_build_only'] for r in forcep_out),
         len(non_out), len(vt)))
