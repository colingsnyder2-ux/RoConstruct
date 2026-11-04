"""Verify the inactive native RBX::ControllerService / controller family recovery (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast for the unit), all from the current native headers unless noted:
  * tests/NativeUserControllerLayout.cpp  sizeof probes (mov eax, imm32; ret) and compile-time offset asserts;
  * native-classes/UserController.cpp     the UserController unit 005ca370..005cbd10: ControllerService constructor,
                                          destructor, thunks, getController, its FactoryProduct/DescribedCreatable
                                          chain and class descriptor 005c0630, HardwareController::getHardwareDevice,
                                          the Stepping/Player/AI controllers' constructors and destructors,
                                          AIController getValue/chaseTarget/getLocalTargetPosition/updateTarget,
                                          AIChaseController::updateBuffer, and the folded one-line virtuals;
  * UserController.cpp with NATIVE_USER_CONTROLLER_PENDING against a generated copy of the donor util/UserInputBase.h
    under out/native-layouts/user-controller-pending/ that defines altKeyDown inline (PROPOSAL_INPUT
    below): KeyboardPrimaryController::getValue 005ca500, KeyboardSecondaryController::getValue 005ca760 and the
    unit's out-of-line UserInputBase::altKeyDown copy 005ca390. Rows exact only in this build are recorded exact=false
    (pending-build-only) and not counted.

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, type descriptors and
vtables by original RTTI names, own symbols by the row proven here, folded bodies by their address, switch jump tables
entry by entry against the row's own labels, and the remaining externals by the explicit EXTERNAL / DATA maps (call
sites read in the original disassembly). A symbol binds to one address across all rows. Vtables are compared slot by
slot from the object built with the current headers (never the pending one). The weak_ptr<const PVInstance>::lock body
spans two rows of the function list (its catch funclet 005cab7a starts a row of its own): it is compared against the
concatenation of both rows, which are contiguous. Writes work/2008-06/shared-layouts/user-controller-working.json.
"""
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
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
SRC = R / 'native-classes/UserController.cpp'
HEADER = R / 'native-headers/v8datamodel/UserController.h'
LAYOUT = R / 'tests/NativeUserControllerLayout.cpp'
DISCOVER = bool(os.environ.get('NATIVE_USER_CONTROLLER_DISCOVER'))

# Proposed declarations for util/UserInputBase.h (not edited here; generated copy for the pending build only). The 2008
# unit keeps an out-of-line altKeyDown copy (005ca390: keyDown(SDLK_RALT) || keyDown(SDLK_LALT), called by
# PlayerController::onEvent 005cb80d) and both keyboard getValue bodies inline the same test, so altKeyDown was an inline
# header member; ctrlKeyDown stays out of line (getValue calls 0045aec0: keyDown(SDLK_RCTRL) || keyDown(SDLK_LCTRL)).
PROPOSAL_INPUT = {
    '\t\tbool altKeyDown() const;\n': '\t\tbool altKeyDown() const { return keyDown(SDLK_RALT) || keyDown(SDLK_LALT); }\n',
}
pending = OUT / 'user-controller-pending'
(pending / 'util').mkdir(parents=True, exist_ok=True)
text = (ROOT / 'tools/rbxgs/Client/App/include/util/UserInputBase.h').read_text()
for old, new in PROPOSAL_INPUT.items():
    assert text.count(old) == 1, old
    text = text.replace(old, new)
(pending / 'util/UserInputBase.h').write_text(text)

UNIT_FLAGS = ['/fp:fast']


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeUserControllerLayout', LAYOUT)
unit_obj, unit_flags = build('NativeUserController', SRC, UNIT_FLAGS)
pend_obj, pend_flags = build('NativeUserControllerPending', SRC,
                             UNIT_FLAGS + ['/I' + str(pending), '/DNATIVE_USER_CONTROLLER_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------
SIZES = [('?nativeControllerServiceSize@@', 0x144), ('?nativeKeyboardPrimaryControllerSize@@', 0x10),
         ('?nativeKeyboardSecondaryControllerSize@@', 0x10), ('?nativeNullControllerSize@@', 0xc),
         ('?nativePlayerControllerSize@@', 0x2c), ('?nativeAIChaseControllerSize@@', 0x64),
         ('?nativeAIFleeControllerSize@@', 0x64)]
raw = layout_obj.read_bytes()
for prefix, value in SIZES:
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


STR = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
CS = '@VControllerService@RBX@@VInstance@2@$1?sControllerService@2@3PADA@RBX@@'
FP = '?$FactoryProduct' + CS
DC = '?$DescribedCreatable' + CS
DSC = '?$Described@VControllerService@RBX@@$1?sControllerService@2@3PADAV' + FP[:-6] + '@2@@Reflection@RBX@@'
WPV = '?$weak_ptr@$$CBVPVInstance@RBX@@@boost@@'

# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # 005ca9a3
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # 005ca98e
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,     # atexit 007fe6d0
    '?ctrlKeyDown@UserInputBase@RBX@@QBE_NXZ': 0x45aec0,       # 005ca5c7, 005ca7cb (out of line, other unit)
    '??2@YAPAXI@Z': 0x6a0920,                                  # 005cba6a, 005cbd49
    '??3@YAXPAX@Z': 0x6a067a,                                  # 004729c1, 005cb2c0
    '_atexit': 0x6a17af,                                       # 005c067a
    '___RTDynamicCast': 0x6a17c6,                              # 005caf40
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,              # 005cadaa
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,             # doDeclare 0045b160
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,  # 005c0670
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '?ReferenceCountedObject_zeroWeakPointers@ReferenceCountedObject@G3D@@QAEXXZ': 0x45ad90,  # 005cbbf9
    '?setPointer@?$ReferenceCountedPointer@VController@RBX@@@G3D@@AAEXPAVController@RBX@@@Z': 0x598fa0,  # 005cba98 (ICF)
    '??$shared_from@VRunService@RBX@@@RBX@@YA?AV?$shared_ptr@VRunService@RBX@@@boost@@PAVRunService@0@@Z': 0x618a40,  # 005cb343 (ICF shared_from<Instance>)
    '??$shared_from@$$CBVPVInstance@RBX@@@RBX@@YA?AV?$shared_ptr@$$CBVPVInstance@RBX@@@boost@@PBVPVInstance@0@@Z': 0x618a40,  # 005cb353
    '??$shared_from@VControllerService@RBX@@@RBX@@YA?AV?$shared_ptr@VControllerService@RBX@@@boost@@PAVControllerService@0@@Z': 0x618a40,  # 005cb428
    '??$create@VRunService@RBX@@@ServiceProvider@RBX@@SAPAVRunService@1@PBVInstance@1@@Z': 0x492e00,  # 005cb33c
    '?addListener@?$Notifier@VRunService@RBX@@VHeartbeat@2@@RBX@@QBEXPAV?$Listener@VRunService@RBX@@VHeartbeat@2@@2@@Z': 0x4218a0,  # 005cb3ba (ICF)
    '?removeListener@?$Notifier@VRunService@RBX@@VHeartbeat@2@@RBX@@QBEXPAV?$Listener@VRunService@RBX@@VHeartbeat@2@@2@@Z': 0x5e5a80,  # 005cb183 (ICF)
    '??0shared_count@detail@boost@@QAE@ABVweak_count@12@@Z': 0x411ad0,              # 005cab5c
    '??$getTypedRoot@VPVInstance@RBX@@@Instance@RBX@@QBEPBVPVInstance@1@XZ': 0x5836d0,  # 005cae9b
    '?numChildren@Instance@RBX@@QBEIXZ': 0x48ae20,              # 005caefd
    '??1?$shared_ptr@$$CBVPVInstance@RBX@@@boost@@QAE@XZ': 0x600660,  # 005caeb5 (ICF ~shared_ptr<Instance>)
    '?getTopPVController@PVInstance@RBX@@QBEPAVController@2@XZ': 0x59a9e0,  # 005caf6d
    '?pointToObjectSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z': 0x501ca0,  # 005cacf7
    '?pi@Math@RBX@@SAMXZ': None,
}
EXTERNAL = {k: v for k, v in EXTERNAL.items() if v is not None}
DATA = {
    '?sControllerService@RBX@@3PADA': 0x9510b4,  # "ControllerService" (.data)
}
# One-line virtuals and deleting destructors folded (ICF) with identical bodies elsewhere; rows compare their bytes.
FOLDED = {
    '??_GNullController@RBX@@UAEPAXI@Z': 0x4729b0,
    '??_GKeyboardPrimaryController@RBX@@UAEPAXI@Z': 0x4729b0,
    '??_GKeyboardSecondaryController@RBX@@UAEPAXI@Z': 0x4729b0,
    '?getValue@Controller@RBX@@UBEMW4InputType@12@@Z': 0x598a50,
    '?getControllerType@NullController@RBX@@UBE?AW4ControllerType@Controller@2@XZ': 0x416690,
    '?hasIntelligence@NullController@RBX@@UBE_NXZ': 0x60a2f0,
    '?isUserController@NullController@RBX@@UBE_NXZ': 0x60a2f0,
    '?isUserController@AIController@RBX@@MBE_NXZ': 0x60a2f0,
    '?hasIntelligence@HardwareController@RBX@@MBE_NXZ': 0x565950,
    '?isUserController@HardwareController@RBX@@MBE_NXZ': 0x565950,
    '?hasIntelligence@AIController@RBX@@MBE_NXZ': 0x565950,
    '?hasIntelligence@PlayerController@RBX@@EBE_NXZ': 0x565950,
    '?isUserController@PlayerController@RBX@@EBE_NXZ': 0x565950,
    '?getControllerType@KeyboardPrimaryController@RBX@@UBE?AW4ControllerType@Controller@2@XZ': 0x7286a0,
    '?getControllerType@KeyboardSecondaryController@RBX@@UBE?AW4ControllerType@Controller@2@XZ': 0x77d810,
    '?getControllerType@PlayerController@RBX@@EBE?AW4ControllerType@Controller@2@XZ': 0x77d800,
    '?getControllerType@AIChaseController@RBX@@UBE?AW4ControllerType@Controller@2@XZ': 0x7359e0,
    '??_GAIChaseController@RBX@@UAEPAXI@Z': 0x5cb2d0,     # same body as ??_GAIController (calls ~AIController 005cb210)
    '??_GAIFleeController@RBX@@UAEPAXI@Z': 0x5cb2d0,
    '??_EAIChaseController@RBX@@WM@AEPAXI@Z': 0x5cb2a0,   # Listener thunk, same body as ??_EAIController@@OM@
    '??_EAIFleeController@RBX@@WM@AEPAXI@Z': 0x5cb2a0,
    '__purecall': 0x6a16be,
}
UNPROVEN = {
    '?updateBuffer@AIFleeController@RBX@@MAEXM@Z': 0x5cb0e0,   # vtable slot 5 of 0083a224; body not exact (x87 order)
    '?onEvent@PlayerController@RBX@@EAEXPBVRunService@2@VHeartbeat@2@@Z': 0x5cb530,  # not attempted
    '?getValue@KeyboardPrimaryController@RBX@@UBEMW4InputType@Controller@2@@Z': 0x5ca500,    # pending-build-only
    '?getValue@KeyboardSecondaryController@RBX@@UBEMW4InputType@Controller@2@@Z': 0x5ca760,  # pending-build-only
}

# Rows: (address or contiguous address tuple, symbol or unique symbol prefix)
UNIT_ROWS = [
    (0x5ca370, '?getHardwareDevice@HardwareController@RBX@@IBEPBVUserInputBase@2@XZ'),
    (0x5ca420, '?getValue@AIController@RBX@@MBEMW4InputType@Controller@2@@Z'),
    (0x5ca430, '?chaseTarget@AIController@RBX@@IAEXABVVector3@G3D@@@Z'),
    (0x5ca940, '??1' + FP + 'MAE@XZ'),
    (0x5ca9a0, '??0' + FP + 'IAE@XZ'),
    (0x5caa00, '??$?4$$CBVPVInstance@RBX@@@' + WPV),
    (0x5caa50, '??_E' + FP + 'OGE@AEPAXI@Z'), (0x5caa60, '??_E' + FP + 'OIE@AEPAXI@Z'),
    (0x5caa70, '??_E' + FP + 'OBE@AEPAXI@Z'),
    (0x5caa50, '??_E' + DC + 'WGE@AEPAXI@Z'), (0x5caa60, '??_E' + DC + 'WIE@AEPAXI@Z'),
    (0x5caa70, '??_E' + DC + 'WBE@AEPAXI@Z'),
    (0x5caa80, '?isChaseable@PVInstance@RBX@@QBE_NXZ'),
    (0x5caaf0, '??1' + DC + 'UAE@XZ'),                    # jmp ~FactoryProduct 005ca940
    ((0x5cab00, 0x5cab7a), '?lock@' + WPV + 'QBE?AV?$shared_ptr@$$CBVPVInstance@RBX@@@2@XZ'),
    (0x5cac20, '?getLocalTargetPosition@AIController@RBX@@IBE?AVVector3@G3D@@XZ'),
    (0x5cada0, '?getClassName@' + FP + 'UBEABVName@2@XZ'),
    (0x5cadc0, '?updateTarget@AIController@RBX@@IAEXW4ControllerType@Controller@2@M@Z'),
    (0x5cb080, '?updateBuffer@AIChaseController@RBX@@MAEXM@Z'),
    (0x5cb140, '??1SteppingController@RBX@@MAE@XZ'),
    (0x5cb200, '??_ESteppingController@RBX@@OM@AEPAXI@Z'),
    (0x5cb210, '??1AIController@RBX@@MAE@XZ'),
    (0x5cb280, '?onEvent@AIController@RBX@@MAEXPBVRunService@2@VHeartbeat@2@@Z'),
    (0x5cb2a0, '??_EAIController@RBX@@OM@AEPAXI@Z'),
    (0x5cb2b0, '??_GSteppingController@RBX@@MAEPAXI@Z'),
    (0x5cb2d0, '??_GAIController@RBX@@MAEPAXI@Z'),
    (0x5cb2f0, '??0SteppingController@RBX@@IAE@PBVPVInstance@1@@Z'),
    (0x5cb3e0, '??0PlayerController@RBX@@QAE@PAVControllerService@1@PBVPVInstance@1@@Z'),
    (0x5cb4a0, '??_EPlayerController@RBX@@WM@AEPAXI@Z'),
    (0x5cb4b0, '??1PlayerController@RBX@@UAE@XZ'),
    (0x5cb510, '??_GPlayerController@RBX@@UAEPAXI@Z'),
    (0x5cb820, '??0AIController@RBX@@IAE@PBVPVInstance@1@@Z'),
    (0x5cb880, '??0' + DC + 'IAE@XZ'),
    (0x5cb920, '??_E' + FP + 'OCE@AEPAXI@Z'), (0x5cb930, '??_E' + FP + 'OEE@AEPAXI@Z'),
    (0x5cb940, '??_E' + FP + 'OKE@AEPAXI@Z'), (0x5cb950, '??_E' + FP + 'OME@AEPAXI@Z'),
    (0x5cb960, '??_E' + FP + 'OBA@AEPAXI@Z'),
    (0x5cb920, '??_E' + DC + 'WCE@AEPAXI@Z'), (0x5cb930, '??_E' + DC + 'WEE@AEPAXI@Z'),
    (0x5cb940, '??_E' + DC + 'WKE@AEPAXI@Z'), (0x5cb950, '??_E' + DC + 'WME@AEPAXI@Z'),
    (0x5cb960, '??_E' + DC + 'WBA@AEPAXI@Z'),
    (0x5cb970, '??_G' + FP + 'MAEPAXI@Z'),
    (0x5cb970, '??_G' + DC + 'UAEPAXI@Z'),
    (0x5cb990, '??0AIChaseController@RBX@@QAE@PBVPVInstance@1@@Z'),
    (0x5cb9b0, '??0AIFleeController@RBX@@QAE@PBVPVInstance@1@@Z'),
    (0x5cb9d0, '?getControllerType@AIFleeController@RBX@@UBE?AW4ControllerType@Controller@2@XZ'),
    (0x5cb9e0, '??0ControllerService@RBX@@QAE@XZ'),
    (0x5cbb30, '??_EControllerService@RBX@@WCE@AEPAXI@Z'), (0x5cbb40, '??_EControllerService@RBX@@WEE@AEPAXI@Z'),
    (0x5cbb50, '??_EControllerService@RBX@@WGE@AEPAXI@Z'), (0x5cbb60, '??_EControllerService@RBX@@WIE@AEPAXI@Z'),
    (0x5cbb70, '??_EControllerService@RBX@@WKE@AEPAXI@Z'), (0x5cbb80, '??_EControllerService@RBX@@WME@AEPAXI@Z'),
    (0x5cbb90, '??_EControllerService@RBX@@WBA@AEPAXI@Z'), (0x5cbba0, '??_EControllerService@RBX@@WBE@AEPAXI@Z'),
    (0x5cbbb0, '??1ControllerService@RBX@@UAE@XZ'),
    (0x5cbcf0, '??_GControllerService@RBX@@UAEPAXI@Z'),
    (0x5cbd10, '?getController@ControllerService@RBX@@QAE?AV?$ReferenceCountedPointer@VController@RBX@@@G3D@@W4ControllerType@Controller@2@PBVPVInstance@2@@Z'),
    (0x5c0630, '?classDescriptor@' + DSC + 'SAAAVClassDescriptor@23@XZ'),
    (0x7fe6d0, '??__Ffoo@?1??classDescriptor@' + DSC),
    # Name::declare<sControllerService> COMDATs kept in the creating unit (getClassName 005cada0 calls both)
    (0x45b160, '??$doDeclare@$1?sControllerService@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x45b6d0, '??$callDoDeclare@$1?sControllerService@RBX@@3PADA@Name@RBX@@CAXXZ'),
]
UNIT_ROWS += [(address, symbol) for symbol, address in FOLDED.items() if symbol != '__purecall']
PENDING_ROWS = [
    (0x5ca390, '?altKeyDown@UserInputBase@RBX@@QBE_NXZ'),
    (0x5ca500, '?getValue@KeyboardPrimaryController@RBX@@UBEMW4InputType@Controller@2@@Z'),
    (0x5ca760, '?getValue@KeyboardSecondaryController@RBX@@UBEMW4InputType@Controller@2@@Z'),
]
NOT_EXACT = {
    '005cb0e0': 'AIFleeController::updateBuffer: chaseTarget(-getLocalTargetPosition()); the original negates and '
                'stores x, y, z in order, the compile loads y and z first (91 vs 93 bytes under /fp:fast; tried a named '
                'local, *= -1, -1 * v, member-wise construction)',
}
NOT_ATTEMPTED = {
    '005cb530': 'PlayerController::onEvent (748 bytes): needs native Workspace/Camera/Humanoid/Network::Players and the '
                '2008 NavKeys input structure (UserInputBase::getNavKeys)',
    '005caba0': 'weak_ptr<ControllerService>::lock instance used only by PlayerController::onEvent',
    '005ca3c0/005ca3e0/005ca400': 'NavKeys axis helpers (bytes +2..+7 of the 2008 NavKeys) used only by PlayerController::onEvent',
    '0045c580': 'Creatable/ServiceProvider creator of ControllerService (other unit; allocates 0x144 through the imported operator new)',
    '005cbe70/005cbec0': 'Vector2 unit helper and Math::radWrap COMDATs placed after the unit (other owners)',
}

LOCAL_EH = nb.LOCAL_EH
LABEL = re.compile(r'^\$LN\d+')
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def first(address):
    return address[0] if isinstance(address, tuple) else address


def target_of(address):
    """Original bytes and relocation offsets of one row, or of contiguous rows concatenated."""
    parts = address if isinstance(address, tuple) else (address,)
    code, relocs = b'', []
    for part in parts:
        assert part == parts[0] + len(code), ('rows not contiguous', [hex(p) for p in parts])
        body, refs, _ = match.target('2008-06', '%08x' % part)
        relocs += [r + len(code) for r in refs]
        code += body
    return code, relocs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (address, key, [h[0] for h in hits])
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
        entry = {'address': '+'.join('%08x' % a for a in (address if isinstance(address, tuple) else (address,))),
                 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local, labels = {}, set(), 0
        base = first(address)
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol, sym_value, sym_section, _ = symbols[index]
            if kind == 20:
                value = (base + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if kind == 6 and LABEL.match(symbol) and sym_section - 1 == section:
                # switch jump table entry: the original entry must point at the same offset inside this row
                expect = base + sym_value - start
                assert value == expect, (name, 'jump table', offset, hex(value), hex(expect))
                labels += 1
                continue
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
            elif symbol.startswith('__real@'):
                literal = bytes.fromhex(symbol[7:])[::-1]
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'float constant'
            elif symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
                assert own['??_G' + symbol[4:]] == value, (name, symbol, hex(value))
                how = 'own row (??_G)'
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in FOLDED:
                assert FOLDED[symbol] == value, (name, symbol, hex(value))
                how = 'folded'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
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
        if labels:
            entry['jump_table_entries_verified'] = labels
        result.append(entry)
    return result


unit_rows = resolve(unit_obj, UNIT_ROWS)
pend_rows = resolve(pend_obj, PENDING_ROWS)
own = {}
for address, name in unit_rows:
    own.setdefault(name, first(address))
strict = not DISCOVER
unit_out = verify(unit_obj, unit_rows, own, strict)
pend_out = verify(pend_obj, pend_rows, own, strict)
for row in pend_out:  # exact only under NATIVE_USER_CONTROLLER_PENDING with a generated UserInputBase.h copy
    row['exact'] = False
    row['exact_pending_build_only'] = True
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in (unit_out, pend_out):
        for r in g:
            if not r.get('exact') and not r.get('exact_pending_build_only'):
                print('NOT EXACT', r['address'], r['symbol'][:100], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)

# ---- vtables from the object built with the current headers, slot by slot ---------------------------------
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
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
    assert norm(original.vtable_class(address)[0]) == norm('.?AV' + symbol[4:symbol.index('@@6B') + 2]), (symbol, hex(address))
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
HB = '6B?$Listener@VRunService@RBX@@VHeartbeat@2@@1@@'
vt = {}
vt['ControllerService'] = check_vtable(unit_obj, '??_7ControllerService@RBX@@' + GI, 0x83a2bc, 0x82d884, 'ControllerService')
# Instance's sub-object vtables (constructor 0055b7e0) are the references for inherited Notifier slots.
for key, offset_name, address, reference in (
        ('10', '?$AbstractFactoryProduct@VInstance@RBX@@@1@@', 0x83a2b0, 0x82d878),
        ('14', '?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@1@@', 0x83a2a8, 0x82d870),
        ('20', 'Debugable@1@@', 0x83a2a0, 0x82d868),
        ('24', '?$Notifier@VInstance@RBX@@UChildAdded@2@@1@@', 0x83a290, 0x82d858),
        ('44', '?$Notifier@VInstance@RBX@@UChildRemoved@2@@1@@', 0x83a280, 0x82d848),
        ('64', '?$Notifier@VInstance@RBX@@UDescendantAdded@2@@1@@', 0x83a270, 0x82d838),
        ('84', '?$Notifier@VInstance@RBX@@UDescendantRemoving@2@@1@@', 0x83a260, 0x82d828),
        ('a4', '?$Notifier@VInstance@RBX@@UAncestorChanged@2@@1@@', 0x83a250, 0x82d818),
        ('c4', '?$Notifier@VInstance@RBX@@VPropertyChanged@2@@1@@', 0x83a240, 0x82d808)):
    symbol = '??_7ControllerService@RBX@@6B' + offset_name
    assert symbol in match._coff_data_index(unit_obj.read_bytes())[2], symbol
    vt['ControllerService_' + key] = check_vtable(unit_obj, symbol, address, reference)
vt['DescribedCreatable'] = check_vtable(unit_obj, '??_7' + DC + GI, 0x83a1ac, 0x82d884)
vt['FactoryProduct'] = check_vtable(unit_obj, '??_7' + FP + GI, 0x83a074, 0x82d884)
vt['NullController'] = check_vtable(unit_obj, '??_7NullController@RBX@@6B@', 0x832a04)
vt['KeyboardPrimaryController'] = check_vtable(unit_obj, '??_7KeyboardPrimaryController@RBX@@6B@', 0x839fa4)
vt['KeyboardSecondaryController'] = check_vtable(unit_obj, '??_7KeyboardSecondaryController@RBX@@6B@', 0x839fbc)
vt['SteppingController'] = check_vtable(unit_obj, '??_7SteppingController@RBX@@6BController@1@@', 0x83a0c8)
vt['SteppingController_heartbeat'] = check_vtable(unit_obj, '??_7SteppingController@RBX@@' + HB, 0x83a0bc)
vt['AIController'] = check_vtable(unit_obj, '??_7AIController@RBX@@6BController@1@@', 0x83a0ec)
vt['AIController_heartbeat'] = check_vtable(unit_obj, '??_7AIController@RBX@@' + HB, 0x83a0e0)
vt['PlayerController'] = check_vtable(unit_obj, '??_7PlayerController@RBX@@6BController@1@@', 0x83a114)
vt['PlayerController_heartbeat'] = check_vtable(unit_obj, '??_7PlayerController@RBX@@' + HB, 0x83a108)
vt['AIChaseController'] = check_vtable(unit_obj, '??_7AIChaseController@RBX@@6BController@1@@', 0x83a1fc)
vt['AIChaseController_heartbeat'] = check_vtable(unit_obj, '??_7AIChaseController@RBX@@' + HB, 0x83a1f0)
vt['AIFleeController'] = check_vtable(unit_obj, '??_7AIFleeController@RBX@@6BController@1@@', 0x83a224)
vt['AIFleeController_heartbeat'] = check_vtable(unit_obj, '??_7AIFleeController@RBX@@' + HB, 0x83a218)
assert vt['ControllerService'][12]['original'] == '00458e90'   # onServiceProvider: Instance's (not overridden in 2008)

# ---- RTTI bases, allocation sizes and strings ------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


cb = bases(0x83a2bc)
assert cb['.?AVService@RBX@@'] == 0x130, cb
for vtable in (0x83a0c8, 0x83a0ec, 0x83a114, 0x83a1fc, 0x83a224):
    b = bases(vtable)
    assert b['.?AVController@RBX@@'] == 0 and b['.?AVReferenceCountedObject@G3D@@'] == 0, b
    assert b['.?AV?$Listener@VRunService@RBX@@VHeartbeat@2@@RBX@@'] == 0xc, b
for vtable in (0x832a04, 0x839fa4, 0x839fbc):
    assert '.?AV?$Listener@VRunService@RBX@@VHeartbeat@2@@RBX@@' not in bases(vtable)
assert '.?AVHardwareController@RBX@@' in bases(0x839fa4) and '.?AVHardwareController@RBX@@' in bases(0x839fbc)


def pushes(address, size, ctor):
    body, _, _ = match.target('2008-06', '%08x' % address)
    at = body.index(b'\x6a' + bytes([size])) if size < 0x80 else body.index(b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 2)
    while (address + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != ctor:
        call = body.index(b'\xe8', call + 1)


pushes(0x45c580, 0x144, 0x5cb9e0)          # creator: new(0x144) then ControllerService()
pushes(0x5cbd10, 0x2c, 0x5cb3e0)           # getController: new(0x2c) PlayerController
pushes(0x5cbd10, 0x64, 0x5cb990)           # new(0x64) AIChaseController (and AIFleeController 005cb9b0)
assert original.string(0x9510b4) == 'ControllerService'

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT, HEADER, SRC]
objects = [layout_obj, unit_obj, pend_obj]
exact_rows = sorted({r['address'] for r in unit_out if r['exact']})
receipt = {
    'class': 'RBX::ControllerService, RBX::HardwareController/KeyboardPrimaryController/KeyboardSecondaryController, '
             'RBX::SteppingController/PlayerController/AIController/AIChaseController/AIFleeController',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'unit': unit_flags, 'pending': pend_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objects},
    'layout': {'ControllerService': '0x144 (creator 0045c580); Service +0x130 (empty); hardwareDevice +0x130, '
                                    'playerController +0x134, keyboardPrimary +0x138, keyboardSecondary +0x13c, '
                                    'nullController +0x140; class name char[] "ControllerService" at 009510b4',
               'NullController': '0xc (G3D::ReferenceCountedObject only)',
               'KeyboardPrimary/SecondaryController': '0x10; HardwareController::controllerService +0xc',
               'SteppingController': 'Listener<RunService,Heartbeat> +0xc, runService +0x10, controlledInstance +0x18',
               'PlayerController': '0x2c; controllerService weak_ptr +0x20, stepsRotating +0x28',
               'AIController': '0x64; retargetTime +0x20, buffer[14] +0x24, target weak_ptr +0x5c'},
    'rows': {'unit': unit_out, 'pending': pend_out},
    'exact_function_rows': exact_rows,
    'vtables': vt,
    'pending_note': 'pending rows are exact only with a generated copy of the donor util/UserInputBase.h that defines '
                    'altKeyDown inline (PROPOSAL_INPUT) under out/native-layouts/user-controller-pending.',
    'not_exact': NOT_EXACT,
    'not_attempted': NOT_ATTEMPTED,
    'proposal_user_input_base_h': PROPOSAL_INPUT,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/user-controller-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ControllerService/controllers: %d distinct function addresses exact (%d rows); %d pending-build-only '
      'rows not counted; %d not exact; targets and %d vtables verified'
      % (len(exact_rows), sum(r['exact'] for r in unit_out), len(pend_out), len(NOT_EXACT), len(vt)))
