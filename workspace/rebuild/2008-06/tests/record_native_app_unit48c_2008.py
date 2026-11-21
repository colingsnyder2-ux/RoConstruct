"""Verify the inactive 2008-06 native rows of the application range 0048c000..00498000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`, checked below; rows counted by other receipts are listed as
'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * 0048c000..00495e4f  the RBX::Network::Player translation unit (Network/Player.cpp), continued from
    00480000..0048c000 (app-unit480): the characterAppearance parser's boost::algorithm split / is_any_of and
    std::set<char> / vector<string> instances, the Creatable / FactoryProduct instances of the classes the unit
    creates (0048e650..004907ff, 00494860..00494a9f), the DescribedCreatable / Clothing thunks, Player members
    (network-player counts them) and the reflection signal / property instances.
  * 00495e50..00498000  the RBX::Network::Players translation unit (Network/Players.cpp; network-players counts most
    rows), continuing past 00498000.
  No library unit starts inside the range: the STL / boost rows are template instances emitted in these RBX units
  (first in link order), not separately compiled library code.

Builds (VS2008 RTM 21022, document-swap flags, /fp:fast), current native headers only (read-only):
  * native-classes/AppUnit48C_2008Creators.cpp          FactoryProduct<C, D, N>::Creator::create() const,
    Creatable<Instance>::create<C>() and shared_ptr<C>(C*, Creatable<Instance>::Deleter) for the hopper, spawn,
    clothing, body-colors, teams and timer classes;
  * native-classes/AppUnit48C_2008CreatorsHumanoid.cpp  the same three for RBX::Humanoid (humanoid/Humanoid2008.h);
  * native-classes/AppUnit48C_2008ClothingThunks.cpp    the FactoryProduct<Clothing> adjustor thunks; with
    NATIVE_APPUNIT48C_PENDING and a generated v8datamodel/Clothing.h copy (inline Pants() / Shirt(), out/app-unit48c-
    2008/pending/) the Pants / Shirt thunks, recorded exact=false (pending-build-only) and never counted;
  * native-classes/AppUnit48C_2008Services.cpp          ServiceProvider::find / create (const Instance*) lookups,
    create<TimerService>() const, FactoryProduct<Player>::getClassName, Player::getPlayerBackpack;
  * native-classes/AppUnit48C_2008Signals.cpp           the void(float) / void(std::string, shared_ptr<Instance>)
    reflection-signal instances and boost::any::holder<shared_ptr<Instance> >.
No native header is created or edited (no shadowing).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified, one address per symbol over all rows: imports by DLL export name,
string literals by bytes, type descriptors by RTTI name, vtables by the original complete-object locator class, own
rows by their row address, rows counted by other receipts by that receipt (and the compiled body must be exact
there), constructors by evidence name, by the receipt that counts them with that symbol, or by the vtable of their
class that they store. Every Creator::create row is slot 0 of the original Creator vtable whose RTTI names the class.
A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit48c-2008-working.json. NATIVE_APP_UNIT48C_DISCOVER=1 lists unbound
targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit48c-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {
    'creators': R / 'native-classes/AppUnit48C_2008Creators.cpp',
    'humanoid': R / 'native-classes/AppUnit48C_2008CreatorsHumanoid.cpp',
    'thunks': R / 'native-classes/AppUnit48C_2008ClothingThunks.cpp',
    'services': R / 'native-classes/AppUnit48C_2008Services.cpp',
    'signals': R / 'native-classes/AppUnit48C_2008Signals.cpp',
}
UNIT_FLAGS = {'creators': ['/fp:fast'], 'humanoid': ['/fp:fast', '/U_RELEASEASSERT'], 'thunks': ['/fp:fast'],
              'services': ['/fp:fast'], 'signals': ['/fp:fast']}
HEADERS = [R / 'native-headers' / h for h in (
    'util/Object.h', 'v8datamodel/Hopper.h', 'v8datamodel/Backpack.h', 'v8datamodel/SpawnLocation.h',
    'v8datamodel/SpawnerService.h', 'v8datamodel/Clothing.h', 'v8datamodel/BodyColors.h', 'v8datamodel/Teams.h',
    'v8datamodel/TimerService.h', 'humanoid/Humanoid2008.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit48c-2008-working.json'
LO, HI = 0x48c000, 0x498000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT48C_DISCOVER'))


# ---- pending header copy: v8datamodel/Clothing.h with the inline Pants() / Shirt() constructors -----------------------
PENDING = OUT / 'pending'
(PENDING / 'v8datamodel').mkdir(parents=True, exist_ok=True)
_clothing = (R / 'native-headers/v8datamodel/Clothing.h').read_text()
for _ctor in ('Shirt();', 'Pants();'):
    assert _clothing.count('\t\t' + _ctor) == 1, _ctor
    _clothing = _clothing.replace('\t\t' + _ctor, '\t\t' + _ctor[:-1] + ' {}')
(PENDING / 'v8datamodel/Clothing.h').write_text(
    '// generated by tests/record_native_app_unit48c_2008.py (pending build only; proposal for v8datamodel/Clothing.h)\n'
    + _clothing)


def build(name, src, extra=(), pre=()):
    obj = OUT / (name + '.obj')
    flags = list(pre) + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build(_src.stem, _src, UNIT_FLAGS[_k])
OBJ['thunks_pending'], FLAGS['thunks_pending'] = build(
    'AppUnit48C_2008ClothingThunks_pending', SOURCES['thunks'], UNIT_FLAGS['thunks'] + ['/DNATIVE_APPUNIT48C_PENDING'],
    ['/I' + str(PENDING)])

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    return s.replace('3QBDB', '3PBDB')


# ---- rows --------------------------------------------------------------------------------------------------------
CI = '?$Creatable@VInstance@RBX@@@'
DEL = 'VDeleter@' + CI


def creator(c, base, mangle):
    return '?create@Creator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@%s@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ' % (
        c, base, c, mangle)


def create(c):
    return '??$create@V%s@RBX@@@%sRBX@@SA?AV?$shared_ptr@V%s@RBX@@@boost@@XZ' % (c, CI, c)


def sptr(c):
    return '??$?0V%s@RBX@@%s1@@?$shared_ptr@V%s@RBX@@@boost@@QAE@PAV%s@RBX@@%s3@@Z' % (c, DEL, c, c, DEL)


def scount(c):
    return '??$?0PAV%s@RBX@@%s1@@shared_count@detail@boost@@QAE@PAV%s@RBX@@%s4@@Z' % (c, DEL, c, DEL)


# Class -> (unit, FactoryProduct base, name mangling, Creator::create, shared_ptr ctor, create<C>, shared_count,
#           constructor C(), Creator vtable, sizeof from the malloc in create<C>)
# The Creator vtables and their RTTI (.?AVCreator@?$FactoryProduct@...) are read from the original below.
CREATORS = {
    'HopperBin': ('creators', 'BackpackItem', '3QBDB', 0x48e810, 0x48e6e0, 0x48e790, 0x48e650, 0x5d15a0, 0x821768, 0x1a8),
    'StarterPackService': ('creators', 'Hopper', '3QBDB', 0x48ea80, 0x48e950, 0x48ea00, 0x48e8c0, 0x5d0fc0, 0x821784, 0x168),
    'LegacyHopperService': ('creators', 'Hopper', '3QBDB', 0x48ecf0, 0x48ebc0, 0x48ec70, 0x48eb30, 0x5d10a0, 0x8217a0, None),
    'Backpack': ('creators', 'Hopper', '3QBDB', 0x48eda0, None, 0x48bc20, None, None, 0x8217bc, None),
    'SpawnLocation': ('creators', 'PartInstance', '3PADA', 0x48f030, 0x48ef00, 0x48efb0, 0x48ee70, 0x5d3490, 0x8217c4, None),
    'SpawnerService': ('creators', 'Instance', '3QBDB', 0x48f2a0, 0x48f170, 0x48f220, 0x48f0e0, 0x5d30c0, 0x8217e0, None),
    'ShirtGraphic': ('creators', 'CharacterAppearance', '3QBDB', 0x48f510, 0x48f3e0, 0x48f490, 0x48f350, 0x5d5510, 0x8217fc, 0x154),
    'Clothing': ('creators', 'CharacterAppearance', '3QBDB', 0x48f780, 0x48f650, 0x48f700, 0x48f5c0, 0x5d5700, 0x821818, 0x174),
    'Pants': ('creators', 'Clothing', '3QBDB', 0x494940, 0x48f9a0, 0x4941d0, 0x48f900, 0x493920, 0x821834, 0x174),
    'Shirt': ('creators', 'Clothing', '3QBDB', 0x4949f0, 0x48fc90, 0x494250, 0x48fc00, 0x4939b0, 0x8219ec, 0x174),
    'BodyColors': ('creators', 'CharacterAppearance', '3QBDB', 0x48fff0, 0x48fec0, 0x48ff70, 0x48fe30, 0x5d59c0, 0x821ad4, None),
    'Skin': ('creators', 'CharacterAppearance', '3QBDB', 0x490260, 0x490130, 0x4901e0, 0x4900a0, 0x5d58c0, 0x821af0, 0x138),
    'Teams': ('creators', 'Instance', '3QBDB', 0x4904d0, 0x4903a0, 0x490450, 0x490310, 0x5d6850, 0x821b0c, None),
    'TimerService': ('creators', 'Instance', '3PADA', 0x490580, None, 0x48bcf0, None, None, 0x821b28, None),
    'Humanoid': ('humanoid', 'Instance', '3PADA', 0x4907f0, 0x4906c0, 0x490770, 0x490630, 0x5db280, 0x821b30, 0x22c),
}
# create<Backpack> / create<TimerService> are counted by app-unit480 (they sit below this range).
COUNTED_CREATE = {'Backpack': 'app-unit480-2008-working.json', 'TimerService': 'app-unit480-2008-working.json'}
# create<SpawnLocation> 0048efb0 is not exact: it mallocs 0x424, the native SpawnLocation.h (over the native
# PartInstance.h, other owners) gives sizeof 0x30c. Its Creator / shared_ptr rows do not depend on the size; their call
# to it is bound by identity (it calls SpawnLocation() 005d3490, evidence name) and the row is not counted.
NOT_COUNTED_CREATE = {'SpawnLocation': 0x5d3490}
FIND_CONST = {}        # symbol -> (address, identity proof); open rows, bound by identity where counted rows call them
IDENTIFIED = {}        # symbol -> (address, constructor the original body calls); open rows of this range
ROWS = {k: [] for k in SOURCES}
COUNTED_TARGETS = {}   # symbol -> (address, receipt)
EXTERNAL = {}
for c, (unit, base, mangle, cr, sp, cc, sc, ctor, vt, size) in CREATORS.items():
    ROWS[unit].append((cr, creator(c, base, mangle)))
    if c in COUNTED_CREATE:
        COUNTED_TARGETS[create(c)] = (cc, COUNTED_CREATE[c])
        continue
    ROWS[unit].append((sp, sptr(c)))
    if c in NOT_COUNTED_CREATE:
        IDENTIFIED[create(c)] = (cc, NOT_COUNTED_CREATE[c])
    else:
        ROWS[unit].append((cc, create(c)))
    COUNTED_TARGETS[scount(c)] = (sc, 'creatable-shared-count-working.json')
    EXTERNAL['??0%s@RBX@@QAE@XZ' % c] = ctor

# ServiceProvider lookups (AppUnit48C_2008Services.cpp). find<C>() const 00490af0 / 00490c30 / 00490d70 / 00490f10 are
# not exact (the native boost shared_ptr<Instance> destructor is inlined there; the original calls it out of line at
# 00600660): they are open rows of this range, bound by identity where the counted rows tail-call them: each pushes
# the callDoGetClassIndex<C> row counted by app-unit480 for call_once.
SP = '@ServiceProvider@RBX@@'
SERVICES = {'Workspace': (0x490af0, 0x48ad60, 0x491e50), 'SpawnerService': (0x490c30, 0x48ad70, 0x491ea0),
            'StarterPackService': (0x490d70, 0x48ad80, 0x491ef0), 'TimerService': (0x490f10, 0x48ad50, None)}
for c, (fc, calldo, fctx) in SERVICES.items():
    FIND_CONST[('??$find@V%s@RBX@@' % c) + SP + 'QBEPAV%s@1@XZ' % c] = (
        fc, ('push-counted', calldo, '??$callDoGetClassIndex@V%s@RBX@@' % c + SP + 'SAXXZ', 'app-unit480-2008-working.json'))
    if fctx:
        ROWS['services'].append((fctx, ('??$find@V%s@RBX@@' % c) + SP + 'SAPAV%s@1@PBVInstance@1@@Z' % c))
# find<Players>() const 004125d0 and create<RunService>() const 004530f0 (outside the range; no receipt counts them):
# identified by the class name their Name::doDeclare callee pushes ("Players") and by their call to the evidence-named
# create<RunService> 00405fa0.
FIND_CONST['??$find@VPlayers@Network@RBX@@' + SP + 'QBEPAVPlayers@Network@1@XZ'] = (0x4125d0, ('declares', 'Players'))
FIND_CONST['??$create@VRunService@RBX@@' + SP + 'QBEPAVRunService@1@XZ'] = (
    0x4530f0, ('calls-named', 0x405fa0, create('RunService')))
ROWS['services'] += [
    (0x491d50, '??$find@VPlayers@Network@RBX@@' + SP + 'SAPAVPlayers@Network@1@PBVInstance@1@@Z'),
    (0x492e00, '??$create@VRunService@RBX@@' + SP + 'SAPAVRunService@1@PBVInstance@1@@Z'),
    (0x48c480, '?getClassName@?$FactoryProduct@VPlayer@Network@RBX@@VInstance@3@$1?sPlayer@23@3PADA@RBX@@UBEABVName@2@XZ'),
    (0x48c470, '?getPlayerBackpack@Player@Network@RBX@@QBEPAVBackpack@3@XZ'),
]
COUNTED_TARGETS['??$findFirstChildOfType@VBackpack@RBX@@@Instance@RBX@@QBEPAVBackpack@1@XZ'] = (
    0x48bb80, 'app-unit480-2008-working.json')
ROWS['services'] += [(0x492020, '??$create@VTimerService@RBX@@' + SP + 'QBEPAVTimerService@1@XZ'),
                     (0x492e50, '??$create@VTimerService@RBX@@' + SP + 'SAPAVTimerService@1@PBVInstance@1@@Z')]
# boost.thread call_once (thread library; every getClassIndex / Name::declare instance calls it) and Instance::setParent
EXTERNAL['?call_once@boost@@YAXP6AXXZAAJ@Z'] = 0x557330
EXTERNAL['?setParent@Instance@RBX@@QAEXPAV12@@Z'] = 0x55a8f0
for _c, _do, _call in (('Workspace', 0x48a460, 0x48ad60), ('SpawnerService', 0x48a4c0, 0x48ad70),
                       ('StarterPackService', 0x48a520, 0x48ad80), ('TimerService', 0x48a400, 0x48ad50)):
    COUNTED_TARGETS['??$doGetClassIndex@V%s@RBX@@' % _c + SP + 'SAIXZ'] = (_do, 'app-unit480-2008-working.json')
    COUNTED_TARGETS['??$callDoGetClassIndex@V%s@RBX@@' % _c + SP + 'SAXXZ'] = (_call, 'app-unit480-2008-working.json')

# Reflection-signal instances (AppUnit48C_2008Signals.cpp), resolved by symbol prefix in the compiled object:
# (row, prefix, required substrings)
STR_SIG = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@VInstance@RBX@@@boost@@'
SIGNAL_ROWS = [
    # void(std::string, shared_ptr<Instance>)
    (0x48dc30, '??0?$holder@V?$function@$$A6AX' + STR_SIG, ()),
    (0x48dc90, '?type@?$holder@V?$function@$$A6AX' + STR_SIG, ()),
    (0x48dca0, '?clone@?$holder@V?$function@$$A6AX' + STR_SIG, ()),
    (0x48ddf0, '??$?0V?$function@$$A6AX' + STR_SIG, ('@any@boost@@QAE@',)),
    (0x48de50, '?connect@?$signal2@X' + STR_SIG, ('signals@2@ABV?$slot@',)),
    (0x48e2d0, '??0TSignalInstance@?$TSignalDesc@$$A6AX' + STR_SIG, ()),
    (0x48e4f0, '?newSignalInstance@?$TSignalDesc@$$A6AX' + STR_SIG, ()),
    (0x496740, '??1?$args2@' + STR_SIG, ()),
    (0x4967c0, '??0?$args2@' + STR_SIG, ()),
    (0x496ac0, '??R?$function2@X' + STR_SIG, ()),
    (0x497430, '??$?RUconnection_slot_pair@detail@signals@boost@@@?$caller@' + STR_SIG, ()),
    # void(float)
    (0x48dfb0, '??0?$holder@V?$function@$$A6AXM@Z', ()),
    (0x48e010, '?type@?$holder@V?$function@$$A6AXM@Z', ()),
    (0x48e020, '?clone@?$holder@V?$function@$$A6AXM@Z', ()),
    (0x48e110, '??$?0V?$function@$$A6AXM@Z', ('@any@boost@@QAE@',)),
    (0x48e170, '?connect@?$signal1@XM', ('signals@2@ABV?$slot@',)),
    (0x4934a0, '??$?RV?$slot_call_iterator@U?$caller@MV', ()),
    (0x4937f0, '??R?$signal1@XM', ()),
    (0x4940e0, '?fire@?$SignalDescImpl@$00$$A6AXM@Z', ()),
    # boost::any::holder<shared_ptr<Instance> > (vtable 00821718) and any::operator=<shared_ptr<Instance> >
    (0x48dc10, '??_G?$holder@V?$shared_ptr@VInstance@RBX@@@boost@@@any@boost@@', ()),
    (0x48db50, '?type@?$holder@V?$shared_ptr@VInstance@RBX@@@boost@@@any@boost@@', ()),
    (0x48db60, '?clone@?$holder@V?$shared_ptr@VInstance@RBX@@@boost@@@any@boost@@', ()),
    (0x48dba0, '??1?$holder@V?$shared_ptr@VInstance@RBX@@@boost@@@any@boost@@', ()),
    (0x48dd00, '??$?4V?$shared_ptr@VInstance@RBX@@@boost@@@any@boost@@', ()),
]
# boost.signals library bodies (signal_base.cpp / named_slot_map.cpp, not instantiated on RBX types) and the reflection
# SignalDescriptor lookup, bound by their call sites in connect 0048de50 / 0048e170, signal1::operator() 004937f0 and
# fire 004940e0 (the same addresses record_native_app_unit4b0_2008.py binds).
for _sym, _value in (
        ('?connect_slot@signal_base_impl@detail@signals@boost@@QAE?AVconnection@34@ABVany@4@ABVstored_group@234@V?$shared_'
         'ptr@Udata_t@slot_base@detail@signals@boost@@@4@W4connect_position@34@@Z', 0x56a900),
        ('??0call_notification@detail@signals@boost@@QAE@ABV?$shared_ptr@Vsignal_base_impl@detail@signals@boost@@@3@@Z',
         0x56a760),
        ('??1call_notification@detail@signals@boost@@QAE@XZ', 0x56a650),
        ('?begin@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ', 0x571380),
        ('?end@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ', 0x5713b0),
        ('?findSignalInstance@SignalDescriptor@Reflection@RBX@@IBEPAVSignalInstance@23@PBVSignalSource@23@@Z', 0x56b620)):
    EXTERNAL[_sym] = _value
_signal_funcs = [n for n, _, _ in match.coff_functions(Path(OBJ['signals']).read_bytes()) if not nb.LOCAL_EH.match(n)]
for _a, _prefix, _contains in SIGNAL_ROWS:
    _hits = [n for n in _signal_funcs if n.startswith(_prefix) and all(c in n for c in _contains)]
    assert len(_hits) == 1, (hex(_a), _prefix, _hits)
    ROWS['signals'].append((_a, _hits[0]))

# Adjustor thunks of the clothing classes (AppUnit48C_2008ClothingThunks.cpp): (row, this-adjustment)
ADJ = {0x10: 'BA', 0x14: 'BE', 0x24: 'CE', 0x44: 'EE', 0x64: 'GE', 0x84: 'IE', 0xa4: 'KE', 0xc4: 'ME', 0x130: 'BDA'}
FPC = '?$FactoryProduct@VClothing@RBX@@VCharacterAppearance@2@$1?sClothing@2@3QBDB@RBX@@'
THUNKS = {'FactoryProduct<Clothing>': ('??_E' + FPC + 'O%s@AEPAXI@Z', 0x48f8e0, '??_G' + FPC + 'MAEPAXI@Z',
                                       [(0x48f890, 0x10), (0x48f8a0, 0x130), (0x48f8b0, 0x64), (0x48f8c0, 0x84),
                                        (0x48f8d0, 0xa4)]),
          'Pants': ('??_EPants@RBX@@W%s@AEPAXI@Z', 0x4933a0, '??_GPants@RBX@@UAEPAXI@Z',
                    [(0x48fb30, 0x44), (0x48fb40, 0xa4), (0x48fb50, 0xc4), (0x493360, 0x64), (0x493370, 0x84),
                     (0x493380, 0x10), (0x493390, 0x14), (0x493990, 0x24), (0x4939a0, 0x130)]),
          'Shirt': ('??_EShirt@RBX@@W%s@AEPAXI@Z', 0x493a70, '??_GShirt@RBX@@UAEPAXI@Z',
                    [(0x493460, 0x130), (0x493470, 0x24), (0x493480, 0x44), (0x493490, 0xa4), (0x493a20, 0x64),
                     (0x493a30, 0x84), (0x493a40, 0xc4), (0x493a50, 0x10), (0x493a60, 0x14)])}
PENDING_ROWS = []
for cls, (pattern, g, gsym, rows) in THUNKS.items():
    COUNTED_TARGETS[gsym] = (g, 'clothing-working.json')
    # the thunks jump to the vector deleting destructor; the original slot holds the ??_G row (no array delete)
    COUNTED_TARGETS['??_E' + gsym[4:]] = (g, 'clothing-working.json', gsym)
    for address, adj in rows:
        b = original.data(address, 11)
        # the original row is exactly `sub ecx, adj; jmp ??_G`
        if adj < 0x80:
            assert b[:3] == bytes([0x83, 0xe9, adj]) and b[3] == 0xe9, (cls, hex(address))
            assert address + 8 + struct.unpack_from('<i', b, 4)[0] == g, (cls, hex(address))
        else:
            assert b[:2] == b'\x81\xe9' and struct.unpack_from('<I', b, 2)[0] == adj and b[6] == 0xe9, (cls, hex(address))
            assert address + 11 + struct.unpack_from('<i', b, 7)[0] == g, (cls, hex(address))
        if cls == 'FactoryProduct<Clothing>':
            ROWS['thunks'].append((address, pattern % ADJ[adj]))
        else:
            PENDING_ROWS.append((address, pattern % ADJ[adj]))

DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING = {}
UNBOUND = []
HELPERS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def receipt_symbols(name, address):
    """Symbols another receipt records as counted exact at `address` (top-level exact_function_rows, else exact rows)."""
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / name).read_text())
    if 'exact_function_rows' in data and '%08x' % address not in [str(r) for r in data['exact_function_rows']]:
        return []
    found = []

    def walk(o):
        if isinstance(o, dict):
            if o.get('address') == '%08x' % address and o.get('symbol') and o.get('exact') is True:
                found.append(o['symbol'])
            for v in o.values():
                walk(v)
        elif isinstance(o, list):
            for v in o:
                walk(v)
    walk(data)
    return found


def ctor_vtables(address):
    """Vtables a constructor body stores (C7 /0 imm32 into a register base), with their original RTTI class."""
    body, _, _ = match.target('2008-06', '%08x' % address)
    found = []
    for i in range(len(body) - 6):
        if body[i] == 0xc7 and (body[i + 1] & 0xf8) in (0x00, 0x40, 0x80):
            off = {0x00: 0, 0x40: 1, 0x80: 4}[body[i + 1] & 0xc0]
            v = struct.unpack_from('<I', body, i + 2 + off)[0]
            try:
                c = original.vtable_class(v)
            except Exception:
                continue
            if c and c[0]:
                found.append((v, c))
    return found


CONSTRUCTOR_PROOF = {}
IDENTITY_PROOF = {}


def prove_identity(value, proof):
    x = FUNCTIONS[value]
    if proof[0] == 'push-counted':
        _, pushed, rsym, receipt = proof
        body, _, _ = match.target('2008-06', '%08x' % value)
        assert b'\x68' + struct.pack('<I', pushed) in body, (hex(value), hex(pushed))
        assert rsym in receipt_symbols(receipt, pushed), (hex(value), hex(pushed), rsym)
        return 'its call_once push of %s %#x (counted by %s)' % (rsym[3:rsym.index('@')], pushed, receipt)
    if proof[0] == 'declares':
        hits = [t for t in x['call_targets'] if FUNCTIONS[int(t, 16)]['strings'] == [proof[1]]]
        assert len(hits) == 1, (hex(value), proof, hits)
        return 'its Name::doDeclare callee %s, which declares %r' % (hits[0], proof[1])
    if proof[0] == 'calls-named':
        _, callee, sym = proof
        assert '%08x' % callee in x['call_targets'] and names.get(callee) == sym, (hex(value), proof)
        return 'its call to %s %#x (evidence name)' % (sym[:40], callee)
    raise AssertionError(proof)


def prove_constructor(symbol, value):
    cls = symbol[3:-len('@RBX@@QAE@XZ')]
    if names.get(value, '') == symbol:
        return 'evidence name'
    for receipt in ('clothing-working.json', 'hopper-family-working.json', 'appearance-working.json',
                    'team-working.json', 'humanoid2008-working.json'):
        if symbol in receipt_symbols(receipt, value):
            return 'exact constructor row of %s' % receipt
    stores = [v for v, c in ctor_vtables(value) if c == ('.?AV%s@RBX@@' % cls, 0)]
    assert stores, (symbol, hex(value), ctor_vtables(value))
    return 'stores the .?AV%s@RBX@@ complete-object vtable %s' % (cls, hex(stores[0]))


def verify(build, obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    own = {s: a for a, s in rows}
    out = []
    for address, name in rows:
        assert name in bodies, (build, hex(address), name)
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'build': build, 'verified_targets': {}, 'local_eh': []}
        out.append(row)
        if not exact:
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
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
            where = '%08x+%#x' % (address, offset)
            if nb.LOCAL_EH.match(symbol):
                row['local_eh'].append(symbol)
                continue
            how = None
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in own:
                assert own[symbol] == value, (where, symbol, hex(value))
                how = 'own row'
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                lit = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
                how = 'literal %r' % lit[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in COUNTED_TARGETS:
                other, receipt, rsym = (COUNTED_TARGETS[symbol] + (symbol,))[:3]
                assert other == value, (where, symbol, hex(value), hex(other))
                assert rsym in receipt_symbols(receipt, value), (receipt, hex(value), rsym)
                if symbol in bodies:
                    hb, hr = bodies[symbol]
                    ht, htr, _ = match.target('2008-06', '%08x' % value)
                    assert match.exact_match(ht, htr, hb, hr), ('counted-elsewhere body not exact', symbol, hex(value))
                how = 'row counted by %s as %s (body exact at the bound address)' % (receipt, rsym[:24])
            elif symbol in FIND_CONST:
                other, proof = FIND_CONST[symbol]
                assert other == value, (where, symbol, hex(value), hex(other))
                how = 'open row (not counted), identified by ' + IDENTITY_PROOF.setdefault(symbol, prove_identity(value, proof))
            elif symbol in IDENTIFIED:
                other, ctor = IDENTIFIED[symbol]
                assert other == value, (where, symbol, hex(value), hex(other))
                cls = symbol[len('??$create@V'):symbol.index('@RBX@@@')]
                assert names.get(ctor) == '??0%s@RBX@@QAE@XZ' % cls, (symbol, hex(ctor))
                assert '%08x' % ctor in FUNCTIONS[value]['call_targets'], (symbol, hex(value), hex(ctor))
                how = 'open row of this range (not counted), identified by its call to ??0%s@RBX@@QAE@XZ %#x ' \
                      '(evidence name)' % (cls, ctor)
            elif re.match(r'\?\?0\?\$signal[12]@X', symbol) and symbol.endswith('@QAE@ABU?$last_value@X@1@ABU?$less@H@std@@@Z'):
                # boost signal constructor: one ICF-shared body 00499c00 for every signature (record_native_app_unit4b0
                # and humanoid2008 bind it the same way); bound by the call site, its body is not compared (the
                # original calls 0060a2f0 there, a boost.function configuration difference not built here)
                assert value == 0x499c00, (where, symbol, hex(value))
                how = 'external (ICF-shared boost signal constructor, body not compared)'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                if symbol.startswith('??0') and symbol.endswith('@RBX@@QAE@XZ'):
                    how = 'constructor: ' + CONSTRUCTOR_PROOF.setdefault(symbol, prove_constructor(symbol, value))
                else:
                    how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in bodies:
                # helper / COMDAT body compiled here but not a row: exact at the bound address, never counted
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr) or DISCOVER, (where, symbol, hex(value))
                HELPERS.setdefault(symbol, '%#x' % value)
                how = 'helper body exact at the bound address (not counted)'
            elif symbol in definitions and symbol not in bodies:
                assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
                how = 'own static (bound by consistency)'
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


groups = {k: verify(k, OBJ[k], ROWS[k]) for k in SOURCES}
pending = verify('thunks_pending', OBJ['thunks_pending'], PENDING_ROWS)
assert all(r['exact'] for r in pending) or DISCOVER, [r['address'] for r in pending if not r['exact']]
# the pending rows are not emitted by the current-header build (no Pants / Shirt vtable without the inline ctors)
_current = {n for n, _, _ in match.coff_functions(Path(OBJ['thunks']).read_bytes())}
assert not any(name in _current for _, name in PENDING_ROWS), 'pending thunk emitted by the current-header build'
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]

# ---- virtual rows: original vtable slot = the slot the current-header object gives the symbol ------------------------
def compiled_vtables(obj):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    out = {}
    for name, (start, sec) in definitions.items():
        if not name.startswith('??_7'):
            continue
        table = sections[sec]
        end = min([x for x in starts.get(sec + 1, ()) if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = symbols[index][0]
        out[name] = slots
    return out


RDATA = [s for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.rdata'][0]
RDATA_VA = original.image + RDATA.VirtualAddress
RDATA_BYTES = RDATA.get_data()


def rdata_refs(value):
    pat = struct.pack('<I', value)
    return [RDATA_VA + m.start() for m in re.finditer(re.escape(pat), RDATA_BYTES) if m.start() % 4 == 0]


def derived_signal_desc(cls, rtti):
    """A compiled TSignalDesc<Sig> / SignalDescImpl<N, Sig> vtable slot found in an original SignalDesc<Class, Sig>
    vtable (the per-class derived template, not built here) of the same signature."""
    m = re.match(r'\?\$(?:TSignalDesc@|SignalDescImpl@\$0\d)\$\$A6A(.+)@Reflection@RBX@@$', cls)
    r = re.match(r'\.\?AV\?\$SignalDesc@V\w+@(?:\w+@)*?(?:RBX@@|\d)\$\$A6A(.+)@Reflection@RBX@@$', rtti)
    return bool(m and r and m.group(1) == r.group(1))


def slot_hits(obj, rows):
    compiled = compiled_vtables(obj)
    out = []
    for row in rows:
        symbol, address = row['symbol'], int(row['address'], 16)
        places = [(vt, i) for vt, slots in compiled.items() for i, s in slots.items() if s == symbol]
        if not places:
            continue
        hits = []
        for vt, i in places:
            cls = vt[4:vt.index('@@6B') + 2]
            for ref in rdata_refs(address):
                try:
                    rtti, at = original.vtable_class(ref - 4 * i)
                except Exception:
                    continue
                if norm(rtti) == norm('.?AV' + cls) or derived_signal_desc(cls, rtti):
                    hits.append({'vtable': hex(ref - 4 * i), 'rtti': rtti, 'offset': hex(at), 'slot': i, 'compiled': vt})
        assert hits or DISCOVER, (row['address'], symbol, places)
        row['vtable_slots'] = hits
        out.append((row['address'], len(hits)))
    return out


# counted rows: slots from the current-header objects only
SLOTS = []
for k in SOURCES:
    SLOTS += slot_hits(OBJ[k], groups[k])
assert all(int(r['address'], 16) in {a for a, _ in ROWS['thunks']} and r.get('vtable_slots') for r in groups['thunks'])
# FactoryProduct<Player>::getClassName 0048c480: no Player vtable is built here, so its slot is taken from the
# primary FactoryProduct<Clothing> vtable of the current-header thunks object (the same Instance slot) and checked
# in the original Player-family vtables.
_gcn = [i for vt, slots in compiled_vtables(OBJ['thunks']).items() if vt.startswith('??_7' + FPC)
        for i, x in slots.items() if x.startswith('?getClassName@' + FPC)]
assert len(_gcn) == 1, _gcn
assert d(0x8218c8 + 4 * _gcn[0]) == 0x48fb60 and original.vtable_class(0x8218c8)[1] == 0x10
_row = next(r for r in groups['services'] if r['address'] == '0048c480')
_row['vtable_slots'] = []
for ref in rdata_refs(0x48c480):
    try:
        rtti, at = original.vtable_class(ref - 4 * _gcn[0])
    except Exception:
        continue
    # the AbstractFactoryProduct subobject vtable at +0x10 (the compiled vtable holding getClassName is the
    # FactoryProduct<Clothing> one named for that base; its original, 008218c8 slot 1, holds Clothing's 0048fb60)
    if 'Player@Network@RBX@@' in rtti and at == 0x10:
        _row['vtable_slots'].append({'vtable': hex(ref - 4 * _gcn[0]), 'rtti': rtti, 'offset': hex(at), 'slot': _gcn[0],
                                     'compiled': 'slot of getClassName in the compiled primary FactoryProduct<Clothing> '
                                                 'vtable (current headers)'})
assert _row['vtable_slots'], 'getClassName 0048c480 not in a Player vtable at slot %d' % _gcn[0]
SLOTS.append(('0048c480', len(_row['vtable_slots'])))

# pending rows (never counted): slots from the pending object, informational
slot_hits(OBJ['thunks_pending'], pending)

# ---- Creator vtables (original): slot 0 is the counted Creator::create row; the RTTI names the class ---------------
creator_vtables = []
for c, (unit, base, mangle, cr, sp, cc, sc, ctor, vt, size) in CREATORS.items():
    rtti, at = original.vtable_class(vt)
    want = '.?AVCreator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?s%s@2@%s@RBX@@' % (c, base, c, mangle)
    assert (rtti, at) == (want, 0), (c, hex(vt), rtti, at)
    assert d(vt) == cr, (c, hex(vt), hex(d(vt)), hex(cr))
    slots = 0
    while TEXT[0] <= d(vt + 4 * slots) < TEXT[1]:
        slots += 1
    assert slots == 1, (c, hex(vt), slots)
    creator_vtables.append({'vtable': hex(vt), 'rtti': rtti, 'original_slots': slots,
                            'slot0': '%s (Creator::create row)' % hex(cr)})


# ---- sizeof(C): the malloc size each counted create<C> passes ------------------------------------------------------
def malloc_size(address):
    body, _, _ = match.target('2008-06', '%08x' % address)
    m = re.search(rb'\x68(....)', body)
    sizes = [struct.unpack_from('<I', body, k.start() + 1)[0] for k in re.finditer(rb'\x68', body)]
    return [s for s in sizes if 0x40 <= s < 0x4000]


SIZES = {}
for c, (unit, base, mangle, cr, sp, cc, sc, ctor, vt, size) in CREATORS.items():
    if c in COUNTED_CREATE:
        continue
    got = malloc_size(cc)
    assert len(got) == 1 and (size is None or got[0] == size), (c, hex(cc), [hex(x) for x in got], size)
    if c in NOT_COUNTED_CREATE:
        SIZES[c] = ('sizeof %#x in the original (malloc in create<%s> %#x); the native SpawnLocation.h gives 0x30c, so '
                    'that row is not exact and not counted' % (got[0], c, cc))
    else:
        SIZES[c] = 'sizeof %#x (malloc %#x in the exact create<%s> %#x; native header layout)' % (got[0], got[0], c, cc)


# ---- unit map evidence -------------------------------------------------------------------------------------------
def holds_string(address, text):
    """The row's bytes hold a DIR32 pointer to that exact NUL-terminated string."""
    x = FUNCTIONS[address]
    body = original.data(address, x['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if any(lo <= v < hi for lo, hi in DATA_SECTIONS):
            try:
                if original.string(v) == text:
                    return True
            except Exception:
                pass
    return False


BLOCKS = [
    ('rbx-network-player (continued)', LO, 0x495e50, 'rbx', [
        (0x48c3e0, 'RemoveCharacterAppearance can only be called by the backend server'),
        (0x4925c0, 'rebuildBackpack can only be called by the backend server'),
        (0x493da0, 'create a Player'),
        (0x495380, 'LoadCharacterAppearance can only be called by the backend server'),
        (0x4957a0, 'LoadCharacter can only be called by the backend server')]),
    ('rbx-network-players (continues past the range)', 0x495e50, HI, 'rbx', [
        (0x4961d0, 'NetworkClient'), (0x496240, 'NetworkServer'), (0x497620, 'userID')]),
]
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, kind, ev in BLOCKS:
    for a, text in ev:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
assert names.get(0x48c3e0) == '?removeCharacterAppearance@Player@Network@RBX@@QAEXXZ'
assert names.get(0x493da0) == '??0Player@Network@RBX@@QAE@XZ'
assert names.get(0x495e50) == '?getMaxPlayers@Players@Network@RBX@@QBEHXZ'


# ---- counting rules ------------------------------------------------------------------------------------------------
def counted_elsewhere():
    """Rows other receipts count: their top-level exact_function_rows (or an equivalent key); for receipts without
    one, every row object marked exact anywhere in the receipt (a conservative reading of their counted lists)."""
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
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(data.get(key), (list, dict)):
                rows = list(data[key])
                break
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    for v in o.values():
                        walk(v)
            walk(data)
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
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
open_rows = ['%08x' % a for a in range_rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted]

def category(a):
    n = names.get(a, '')
    if not n:
        return 'unnamed'
    head = n.split('@@')[0]
    if re.search(r'@(std|boost)$|@(algorithm|detail|signals|_bi|any|function)@', head) or n.startswith('??$_') or \
            '@std@@' in head or '@boost@@' in head:
        return 'STL/boost template instance'
    return 'RBX'


OPEN_CATEGORIES = {}
for a in open_rows:
    OPEN_CATEGORIES.setdefault(category(int(a, 16)), []).append('%#x' % int(a, 16))

UNIT_MAP = {
    'rbx Network/Player.cpp 0048c000..00495e4f (continued from app-unit480)': (
        'The RBX::Network::Player translation unit, continued from 00480000..0048c000 (app-unit480-2008). In link '
        'order: the characterAppearance parser instances (boost::algorithm split_iterator / is_any_of / token_finder, '
        'std::set<char>, vector<string>, transform_iterator copy_range: 0x48c0f0..0x48d9ff, 0x490eb0, 0x491270.., '
        '0x492110.., 0x492f30, 0x493bf0, 0x494390.., 0x494b80..0x4952f0) and Player members '
        'removeCharacterAppearance 0x48c3e0 / getPlayerBackpack 0x48c470 (evidence names); the bind / for_each '
        'instances of loadCharacter / rebuildBackpack (0x48c4d0.., 0x48d0f0, 0x48d370); the reflection-signal instances '
        'of the Player signals SignalDesc<Player, void(std::string, shared_ptr<Instance>)> (vtable 0x821db0) and '
        'SignalDesc<Player, void(float)> (0x821dd8): any::holder / connect / TSignalInstance / newSignalInstance '
        '0x48dc30..0x48e5cf, signal1<float> call path 0x4934a0 / 0x4937f0 / fire 0x4940e0, GenericSlotAdapter / '
        'invokers 0x491090 / 0x4911b0 / 0x4921b0 / 0x492280; the Creatable / FactoryProduct block 0x48e650..0x4907ff '
        'and 0x4941d0..0x494a9f (Creator::create, shared_ptr(T*, Deleter), create<T>, shared_count: HopperBin, '
        'StarterPackService, LegacyHopperService, Backpack, SpawnLocation, SpawnerService, ShirtGraphic, Clothing, '
        'Pants, Shirt, BodyColors, Skin, Teams, TimerService, Humanoid; Creator vtables 0x821768..0x821b30) with the '
        'Clothing / Pants / Shirt destructors, thunks and inline constructors (clothing-working.json counts most); '
        'ServiceProvider::find<C>() const 0x490af0..0x490f10 / create<TimerService>() const 0x492020 and the const '
        'Instance* lookups 0x491d50..0x491ef0 / 0x492e00 / 0x492e50; the reflection property / descriptor instances '
        '(0x490a60, 0x492ea0, 0x493590, 0x493620 and their static-descriptor wrappers 0x491da0 / 0x493210 / 0x493a90 / '
        '0x493b40 / 0x494110 / 0x4942d0 / 0x494860 / 0x494aa0); the Player members (network-player counts the ctor '
        'chain, setters, onServiceProvider, thunks; open: onCharacterChangedFrontend 0x4924e0, rebuildBackpack '
        '0x4925c0, the constructor 0x493da0, doPeriodicIdleCheck 0x494650, loadCharacterAppearance 0x495380, '
        'loadCharacter 0x4957a0) and the XmlNameValuePair::setValue instances 0x4915e0 / 0x495dd0.'),
    'rbx Network/Players.cpp 00495e50..00498000 (continues past the range)': (
        'The RBX::Network::Players translation unit (getMaxPlayers 0x495e50, evidence name; the NetworkClient / '
        'NetworkServer class-name users 0x4961d0 / 0x496240; ChatMessage / AbuseReporter / Guid-map instances '
        '0x4963c0..0x497f40). network-players-working.json and network-client-server2008-working.json count most of '
        'it; this receipt adds the void(std::string, shared_ptr<Instance>) signal helpers args2 0x496740 / 0x4967c0, '
        'function2::operator() 0x496ac0 and the caller 0x497430.'),
    'library code': (
        'No separately compiled library unit starts in the range. The STL / boost rows are template instances emitted '
        'in these RBX units; the generic ones (std::set<char>, vector<string>, boost::algorithm split, the '
        'boost.signals call path) are not recovered here except where they are instantiated on this unit\'s signal '
        'signatures and every caller is a counted row (the void(float) / void(string, shared_ptr<Instance>) signal '
        'instances, boost::any::holder<shared_ptr<Instance> >).'),
}
NOT_EXACT = {
    '0x48efb0 Creatable<Instance>::create<SpawnLocation>()': (
        'mallocs 0x424 in the original; the native SpawnLocation.h (over the native PartInstance.h of other owners) '
        'gives sizeof 0x30c. Its Creator 0x48f030 and shared_ptr 0x48ef00 rows are exact and counted; this row is open '
        '(PartInstance layout; see the Humanoid2008 Primitive-at-+0x228 proposal).'),
    '0x490af0 / 0x490c30 / 0x490d70 / 0x490f10 ServiceProvider::find<C>() const (320 B)': (
        'the native boost shared_ptr<Instance> destructor is inlined there (386 / 404 B); the original calls it out of '
        'line at 0x600660. Earlier receipts only matched this template with a generated noinline-destructor profile '
        '(not used here). Open; the counted const Instance* lookups bind them by identity.'),
    '0x4911b0 GenericSlotAdapter<SignalDescImpl<1, void(float)> >::operator()': (
        '231 B against 179 B in the original (the native reflection/signal.h body); open.'),
    'Pants / Shirt adjustor thunks (18 rows)': (
        'pending-build-only: the current Clothing.h declares Pants() / Shirt() out of line, so no Pants / Shirt vtable '
        'is emitted by a current-header build; exact with a generated Clothing.h copy that makes them inline '
        '(proposal).'),
    '0x48f990': 'a 5-byte jmp to ~FactoryProduct<Clothing> 0x48f830: the ICF-folded ~Described / ~DescribedCreatable '
                '<Clothing>; which symbol it is cannot be derived; open.',
    '0x48d0a0 / 0x48c9c0': 'ICF-folded 8 / 9-byte adjustor / iterator helpers with several candidate symbols; open.',
}
REJECTED = {
    'Pants / Shirt thunks through a non-virtual call of the implicit destructor (p->Pants::~Pants())': (
        'the implicit ~Pants is a 5-byte jump to the DescribedCreatable destructor and stores no vtable, so no Pants '
        'vtable or thunk is emitted; replaced by the pending Clothing.h copy'),
}
PROPOSALS = {
    'v8datamodel/Clothing.h (owner of the clothing family)': (
        'declare the Shirt and Pants constructors inline: `Shirt() {}` / `Pants() {}` (native-classes/Clothing.cpp '
        'defines them empty). Evidence: their bodies 0x4939b0 / 0x493920 are COMDAT copies inside the Network/'
        'Player.cpp unit (create<Shirt> 0x494250 / create<Pants> 0x4941d0 call them out of line), next to ??_GShirt '
        '0x493a70 / ??_GPants 0x4933a0 and the 18 adjustor thunks of their vtables (0x48fb30..0x4939a0, '
        '0x493460..0x493a60; evidence names ??_EShirt@RBX@@W...). With the generated copy out/app-unit48c-2008/'
        'pending/v8datamodel/Clothing.h the 18 thunks are byte-exact with their ??_G targets and vtable slots '
        'verified; they are recorded as pending_build_only (exact=false) and not counted. Re-run '
        'record_native_clothing.py (and every recorder that compiles Clothing.h) before applying.'),
    'v8datamodel/SpawnLocation.h / PartInstance.h (owners)': (
        'sizeof(SpawnLocation) is 0x424 in 2008 (malloc in create<SpawnLocation> 0x48efb0); the native headers give '
        '0x30c (0x118 short, consistent with the missing embedded Primitive of the PartInstance proposal).'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX Network::Player / Players unit rows of the application range 0048c000..00498000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': SIZES,
    'unit_map': UNIT_MAP,
    'unit_blocks': ['%#x..%#x %s (%s)' % (lo, hi, n, k) for n, lo, hi, k, _ in BLOCKS],
    'range_functions': len(range_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_open': ['%#x (open)' % int(a, 16) for a in open_rows],
    'range_rows_open_by_category': OPEN_CATEGORIES,
    'rows': groups,
    'creator_vtables': creator_vtables,
    'helper_bodies_not_counted': HELPERS,
    'pending_build_only': [{'row': '%#x (pending-build-only, exact=false)' % int(r['address'], 16),
                            'symbol': r['symbol'], 'exact': False, 'pending_exact': r['exact'],
                            'verified_targets': r['verified_targets'],
                            'vtable_slots_in_pending_object': [dict(h, vtable=h['vtable'] + ' (pending object)')
                                                               for h in r.get('vtable_slots', [])]}
                           for r in pending],
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact_rows), sorted(bare - set(exact_rows))
if DISCOVER:
    print('DISCOVER: receipt not written; %d exact rows' % len(exact_rows))
    sys.exit(0)
RECEIPT.write_text(text)
print('PASS app-unit48c-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d open; %d Creator '
      'vtables checked' % (len(exact_rows), ' '.join(exact_rows), len(range_rows), len(range_counted), len(open_rows),
                           len(creator_vtables)))
