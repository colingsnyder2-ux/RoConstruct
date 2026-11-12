"""Verify the inactive native RBX gui HUD recovery (2008-06): ScoreHud, ChatOutput and ChatLine.

Builds (document-swap flags, VS2008 RTM 21022, native headers only):
  * tests/NativeHudLayout.cpp         layout probes (mov eax, imm32; ret) against allocation sizes and constructor stores;
  * native-classes/ScoreHud.cpp       ScoreHud 00650f80..00656488 (constructor, destructor, onServiceProvider,
                                      DetermineBoardType, render2d);
  * native-classes/ChatOutput.cpp     ChatOutput 0064f8c0..00650560 (ChatLine destructor, constructor, removeOldest,
                                      onEvent(Heartbeat), destructor, onServiceProvider); unit profile + /fp:fast
                                      (onEvent 0064fe10 x87 compare order).
Pending build (NATIVE_SCOREHUD_PENDING; rows recorded exact=false, pending-build-only, never counted, vtables never
walked) against out/native-layouts/hud-pending, a generated copy of the native v8tree/Instance.h (owned by others) with
one change: ChildRemoved defined (a const-less boost::shared_ptr<Instance> child plus the out-of-line copy constructor,
the shape native v8tree/InstanceEvents.h gives ChildAdded from 004116f0). With it the ScoreHud ChildRemoved onEvent body
compiles to 00651210 too. The ChildAdded body is in the main build (native v8tree/InstanceEvents.h, included only).

Rows are found by closure from seeds (constructors named by the allocating call sites): every REL32/DIR32 relocation of
an exact row is bound to the address the original instruction uses. A target defined in the compiled object becomes a
row at that address; a vtable target is checked by original RTTI (class name and subobject offset) and walked slot by
slot, each slot symbol bound to the original slot value (main builds only). Every other target is verified: imports by
DLL export name, string literals by bytes, float constants (__real@) by bytes, type descriptors by RTTI name, external
functions by the evidence name or the EXTERNAL map (call sites read in the original disassembly), own functions not
compiled here by the UNPROVEN map (the original reference). A symbol binds to one address. Writes
work/2008-06/shared-layouts/hud-family-working.json.
"""
import json
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
SOURCES = {name: R / 'native-classes' / (name + '.cpp') for name in ('ScoreHud', 'ChatOutput')}
POST = {'ChatOutput': ['/fp:fast']}
HEADERS = [R / 'native-headers/gui' / n for n in ('ScoreHud.h', 'ChatOutput.h')]
PENDING_UNITS = ('ScoreHud',)
LAYOUT = R / 'tests/NativeHudLayout.cpp'

# ---- pending overlay ------------------------------------------------------------------------------------------
pending = OUT / 'native-layouts/hud-pending'
(pending / 'v8tree').mkdir(parents=True, exist_ok=True)


def overlay(source, relative, old, new):
    text = Path(source).read_text()
    assert text.count(old) == 1, (relative, old)
    (pending / relative).write_text(text.replace(old, new))


overlay(R / 'native-headers/v8tree/Instance.h', 'v8tree/Instance.h',
        'struct ChildRemoved;\n',
        'struct ChildRemoved {\n    boost::shared_ptr<Instance> child;\n    ChildRemoved(const ChildRemoved&);\n};\n')


def build(name, src, extra=(), post=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(post) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeHudLayout', LAYOUT)
objs, all_flags = {}, {'layout': layout_flags}
for name, src in SOURCES.items():
    objs[name], all_flags[name] = build('NativeHud_' + name, src, post=POST.get(name, ()))
    if name in PENDING_UNITS:
        objs[name + '-pending'], all_flags[name + '-pending'] = build(
            'NativeHud_' + name + 'Pending', src, ['/I' + str(pending)], ['/DNATIVE_SCOREHUD_PENDING'] + POST.get(name, []))

# ---- layout ---------------------------------------------------------------------------------------------------
LAYOUT_VALUES = {
    'nativeScoreHudRunService': 0x14c, 'nativeScoreHudPlayers': 0x150, 'nativeScoreHudSize': 0x154,
    'nativeChatOutputRunService': 0x14c, 'nativeChatOutputPlayers': 0x150, 'nativeChatOutputFilter': 0x154,
    'nativeChatOutputFifo': 0x174, 'nativeChatOutputTime': 0x194, 'nativeChatOutputSize': 0x198,
    'nativeChatLineUser': 0xc, 'nativeChatLineMessage': 0x28, 'nativeChatLineDieTime': 0x44,
    'nativeChatLineProfane': 0x48, 'nativeChatLineSize': 0x4c,
}
raw = layout_obj.read_bytes()
for prefix, value in LAYOUT_VALUES.items():
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + prefix + '@@'))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
pe = original.pe
TEXT = next(s for s in pe.sections if s.Name.startswith(b'.text'))
TEXT_LO = pe.OPTIONAL_HEADER.ImageBase + TEXT.VirtualAddress
TEXT_HI = TEXT_LO + TEXT.Misc_VirtualSize


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


def call_target(site):
    """Target of the direct call instruction at `site` in the original."""
    assert original.data(site, 1) == b'\xe8', hex(site)
    return (site + 5 + struct.unpack('<i', original.data(site + 1, 4))[0]) & 0xffffffff


# Allocation sizes: each call site pushes the size, calls malloc (operator new), then the constructor.
for factory, size, site, ctor in ((0x602350, 0x154, 0x602399, 0x652510),     # ScoreHud
                                  (0x6020a0, 0x198, 0x6020e4, 0x64fb60),     # ChatOutput
                                  (0x650cc0, 0x4c, 0x650dc8, 0x650560)):     # ChatLine (ChatOutput::onEvent)
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size) if size > 0x7f else b'\x6a' + bytes([size]))
    assert at < site - factory and call_target(site) == ctor, (hex(factory), hex(size), hex(ctor))
# Base / member constructor and destructor chains read from the constructors and destructors (call site -> callee).
for site, callee in ((0x65252e, 0x5739d0), (0x64fb7f, 0x5739d0), (0x64fc08, 0x66a340), (0x650513, 0x66a060),
                     (0x650522, 0x411540), (0x6504e2, 0x64fd70), (0x6511f3, 0x650f80), (0x650543, 0x650440),
                     (0x64fded, 0x64f8c0), (0x656433, 0x6512e0), (0x41272b, 0x4125d0)):
    assert call_target(site) == callee, (hex(site), hex(callee))
# ServiceProvider::create<Players>() 00412710 starts with the find<Players>() call 004125d0 (create = find, else make):
# the member find<Players> binding below.
assert original.data(0x650fec, 1) == b'\xe9' and (0x650ff1 + struct.unpack('<i', original.data(0x650fed, 4))[0]) == 0x411540


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


PARENT = {'ScoreHud': 'GuiItem', 'ChatOutput': 'GuiItem'}
VTABLE = {'ScoreHud': 0x84bcb4, 'ChatOutput': 0x84bb84}
LISTENERS = {'ScoreHud': {'.?AV?$Listener@VInstance@RBX@@UChildAdded@2@@RBX@@': 0x144,
                          '.?AV?$Listener@VInstance@RBX@@UChildRemoved@2@@RBX@@': 0x148},
             'ChatOutput': {'.?AV?$Listener@VPlayers@Network@RBX@@VChatMessage@23@@RBX@@': 0x144,
                            '.?AV?$Listener@VRunService@RBX@@VHeartbeat@2@@RBX@@': 0x148}}
for cls, vt in VTABLE.items():
    assert original.vtable_class(vt) == ('.?AV%s@RBX@@' % cls, 0), (hex(vt), cls)
    b = bases(vt)
    assert b['.?AV%s@RBX@@' % PARENT[cls]] == 0 and b['.?AVGuiTarget@RBX@@'] == 0x130, (cls, b)
    for listener, offset in LISTENERS[cls].items():
        assert b[listener] == offset, (cls, listener, b)
    hierarchy = d(d(vt - 4) + 16)
    assert original.string(d(d(d(hierarchy + 12) + 4)) + 8) == '.?AV%s@RBX@@' % PARENT[cls], cls


# ---- verification maps ----------------------------------------------------------------------------------------
# Externals whose evidence name differs from the compiled symbol (or has none): the address the original call site
# uses, with the site it was read from.
EXTERNAL = {
    '??0GuiItem@RBX@@QAE@XZ': 0x5739d0,                                                      # ScoreHud() 0065252e
    '??1GuiItem@RBX@@UAE@XZ': 0x411540,                                                      # ~ScoreHud 00650fec
    '??$find@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ': 0x452c80,        # ScoreHud() 006525c5
    '??$find@VPlayers@Network@RBX@@@ServiceProvider@RBX@@QBEPAVPlayers@Network@1@XZ': 0x4125d0,  # 006525da; 0041272b
    '??$create@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ': 0x4530f0,      # 00650c56
    '??$create@VPlayers@Network@RBX@@@ServiceProvider@RBX@@QBEPAVPlayers@Network@1@XZ': 0x412710,  # 00650c6b
    '??0ProfanityFilter@RBX@@QAE@XZ': 0x66a340,                                              # ChatOutput() 0064fc08
    '??1ProfanityFilter@RBX@@QAE@XZ': 0x66a060,                                              # ~ChatOutput 00650513
    '?zero@Vector2@G3D@@SAABV12@XZ': 0x509ba0,                                               # GuiItem::getChildPosition 00411810
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                                                     # ~GuiItem 00411540
    # std exception vtables reached from the units (bound by RTTI name): slot 0 values read from the original vtable.
    '??_Ebad_alloc@std@@UAEPAXI@Z': 0x4023c0,                                                # bad_alloc vtable slot 0
    '??_Elength_error@std@@UAEPAXI@Z': 0x55c390,                                             # ICF logic_error (record_native_mouse)
    '??_Eout_of_range@std@@UAEPAXI@Z': 0x55c390,                                             # ICF logic_error
    '??_E?$SignalDesc': None,
}
EXTERNAL = {k: v for k, v in EXTERNAL.items() if v is not None}
# Own functions that are not compiled in the main builds: bound by the original reference that uses them.
UNPROVEN = {
    # ChildRemoved is only forward-declared in native v8tree/Instance.h: its body is pending, so its vtable slot binds
    # by address to the ChildAdded body 00651210 (identical codegen; both slots hold it).
    '?onEvent@ScoreHud@RBX@@MAEXPBVInstance@2@UChildRemoved@2@@Z': 0x651210,                 # vtable 0084bc14 slot 0 (pending)
    '?renderFFALeaderboard@ScoreHud@RBX@@IAEXPAVAdorn@2@@Z': 0x6551e0,                       # call at 0065646f
    '?renderTeamDeathmatchLeaderboard@ScoreHud@RBX@@IAEXPAVAdorn@2@W4BoardType@12@@Z': 0x655a20,  # call at 0065644d
    '?onEvent@ChatOutput@RBX@@EAEXPBVPlayers@Network@2@VChatMessage@42@@Z': 0x650cc0,        # vtable 0084baf4 slot 0
    '?render2d@ChatOutput@RBX@@EAEXPAVAdorn@2@@Z': 0x64fe90,                                 # vtable 0084bb84 slot 24
}
CLASS_NAMES = {'sInstance': b'Instance'}
EXTENT_SPLITS = {}
DATA = {}
FOLDED = {}


# Seeds: (address, compiled symbol). Constructors are named by the allocating call sites above.
SEEDS = {
    'ScoreHud': [(0x652510, '??0ScoreHud@RBX@@QAE@PBVServiceProvider@1@@Z')],
    'ChatOutput': [(0x64fb60, '??0ChatOutput@RBX@@QAE@XZ')],
}
PENDING_SEEDS = {
    'ScoreHud': [(0x651210, '?onEvent@ScoreHud@RBX@@MAEXPBVInstance@2@UChildRemoved@2@@Z')],
}
# Vtable-slot evidence for the pending seeds.
assert d(0x84bc20) == 0x651210 and d(0x84bc14) == 0x651210
OWN_CLASSES = 'ScoreHud|ChatOutput|ChatLine'
OWN = re.compile(r'(?:^|[^A-Za-z]|\?\?_[EG])(%s)@RBX@@' % OWN_CLASSES)
NOT_ATTEMPTED = {
    '006551e0 / 00655a20 / 00652640..00655a20': 'ScoreHud::renderFFALeaderboard, renderTeamDeathmatchLeaderboard, '
                                                'BoardData / LeaderboardData and their std::map / vector instances: '
                                                'native-classes/ScoreHudLeaderboard2008.cpp, verified by '
                                                'tests/record_native_scorehud_leaderboard.py',
    '00650560': 'ChatLine(Player*, const std::string&, float): name colour through 00669f60 (string hash, unit '
                'unknown) and 0064f830 (palette switch); no evidence names for either',
    '00650cc0': 'ChatOutput::onEvent(ChatMessage) (0044bee0 settings singleton, ProfanityFilter::ContainsProfanity '
                '0066a350, ParseCommand 00650660)',
    '00650660': 'ChatOutput::ParseCommand (1439 bytes)',
    '0064fe90': 'ChatOutput::render2d (1452 bytes)',
    '0064fd00': 'string lower-case helper shared with the ProfanityFilter unit (0066a39d) and ParseCommand',
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
SLOTS = []   # (build, own vtable, symbol, original value, where)
HEADER_GAPS = []


def own_vtable(rtti):
    if any(rtti.startswith('.?AV%s@RBX@@' % c) for c in OWN_CLASSES.split('|')):
        return True
    return False


class Build:
    def __init__(self, name, obj, walk_vtables):
        self.name, self.obj, self.walk = name, Path(obj), walk_vtables
        self.raw = self.obj.read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.binding = {}     # symbol -> (address, origin)
        self.rows = {}        # address -> row
        self.vtables = {}
        self.queue = []

    def bind(self, symbol, value, origin):
        prev = self.binding.setdefault(symbol, (value, origin))
        assert prev[0] == value, (self.name, 'inconsistent', symbol, hex(prev[0]), prev[1], hex(value), origin)

    def literal(self, symbol):
        pos, at = self.definitions[symbol]
        table = self.sections[at]
        return self.raw[table[4] + pos:table[4] + table[3]].split(b'\0')[0] + b'\0'

    def classify(self, symbol, value, where):
        if symbol in self.bodies and not LOCAL_EH.match(symbol):
            self.bind(symbol, value, where)
            self.queue.append((value, symbol))
            return 'own row'
        if symbol.startswith('??_E') and '??_G' + symbol[4:] in self.bodies:
            # vector deleting destructor referenced, scalar one compiled: the same body in the original
            self.bind('??_G' + symbol[4:], value, where)
            self.queue.append((value, '??_G' + symbol[4:]))
            return 'own row (??_G)'
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
            return '%s!%s' % hit
        if symbol.startswith('??_C@'):
            lit = self.literal(symbol)
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'literal %r' % lit[:-1].decode()
        if re.match(r'^\?s[A-Z]\w*@RBX@@3QBDB$', symbol):
            lit = self.literal(symbol) if symbol in self.definitions else CLASS_NAMES[symbol[1:symbol.index('@')]] + b'\0'
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'class name %r' % lit[:-1].decode()
        if symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
            return 'RTTI %s' % rtti
        if symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
            if self.walk and symbol in self.definitions:
                self.bind(symbol, value, where)
                self.queue.append((value, symbol))
            return 'vtable RTTI %s offset %#x' % (rtti, at)
        if symbol.startswith('??_8'):
            return 'vbtable (bound by consistency)'
        if symbol in FOLDED:
            assert FOLDED[symbol] == value, (where, symbol, hex(value))
            return 'folded'
        if symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
            return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
        if symbol in DATA:
            assert DATA[symbol][0] == value and original.data(value, len(DATA[symbol][1])) == DATA[symbol][1], (where, symbol)
            return 'constant %s' % DATA[symbol][1].hex()
        if symbol in CROSS:
            assert CROSS[symbol] == value, (where, symbol, hex(value), hex(CROSS[symbol]))
            return 'own row exact in another main build of this recorder'
        if symbol in UNPROVEN:
            assert UNPROVEN[symbol] == value, (where, symbol, hex(value))
            return 'own function not attempted (bound by the original reference)'
        if norm(names.get(value, '')) == norm(symbol) and symbol not in self.definitions:
            return 'external (evidence name)'
        if (symbol.startswith('__real@') or symbol.startswith('__xmm@')) and symbol in self.definitions:
            # floating-point constants: the original operand must hold the same bytes
            pos, at = self.definitions[symbol]
            table = self.sections[at]
            size = 8 if symbol.startswith('__real@') and len(symbol) == 7 + 16 else 4 if symbol.startswith('__real@') else 16
            data = self.raw[table[4] + pos:table[4] + pos + size]
            assert original.data(value, size) == data, (where, symbol, hex(value), original.data(value, size).hex())
            return 'constant %s' % data.hex()
        if symbol in self.definitions and symbol not in self.bodies:
            # own static data (descriptor objects, local statics, guard flags): bound by consistency across rows
            return 'own static'
        return None

    def vtable(self, symbol, value):
        start, sec = self.definitions[symbol]
        table = self.sections[sec]
        end = min([x for x in self.starts[sec + 1] if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = self.symbols[index][0]
        assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
        rtti, at = original.vtable_class(value)
        own = own_vtable(rtti)
        after = d(value + 4 * len(slots))
        longer = TEXT_LO <= after < TEXT_HI
        info = {'address': hex(value), 'rtti': rtti, 'offset': hex(at), 'own_class': own}
        self.vtables[symbol] = info
        if longer:
            # The dword after the compiled length is a code address in the original. For the classes' own
            # most-derived vtables (offset 0) that would be a missing virtual: asserted. Elsewhere it can also be
            # unrelated .rdata that follows the vtable (FactoryProduct<Tool> 00841904 is followed by a boost::function
            # manager table 005fdec0 / 00618cd0): recorded only.
            assert not (own and at == 0 and any(rtti == '.?AV%s@RBX@@' % c for c in OWN_CLASSES.split('|'))), \
                (symbol, hex(value), 'original vtable longer', hex(after))
            info['next_dword_is_code'] = 'slot %d position holds %s in the original' % (len(slots), hex(after))
            if not own:
                info['not_walked'] = 'shared template vtable; length not proven'
                return
        checked = {}
        for slot, sym in sorted(slots.items()):
            orig = d(value + 4 * slot)
            where = '%s slot %d' % (symbol, slot)
            if sym in self.bodies or sym.startswith('??_7') or sym.startswith('??_R'):
                how = self.classify(sym, orig, where)
                if how is None:
                    UNBOUND.append('%s: vtable %s slot %d %s -> %s' % (self.name, symbol, slot, sym, hex(orig)))
                    continue
                self.bind(sym, orig, where)
            else:
                # Inherited external virtual: verified after all builds (evidence name, EXTERNAL map, or the same
                # address at every other place the symbol occurs).
                SLOTS.append((self.name, own, sym, orig, where))
                how = 'external slot'
            checked[slot] = '%s = %s (%s)' % (sym, hex(orig), how)
        info['slots'] = checked

    def row(self, address, name):
        if address in self.rows and self.rows[address]['symbol'] == name:
            return
        body, refs = self.bodies[name]
        split = next(((parent, start) for parent, pieces in EXTENT_SPLITS.items() for start, size in pieces
                      if start == address and size == len(body)), None)
        if split:
            # One evidence extent covers several compiled functions (bounds): compare the piece of the parent extent.
            parent, start = split
            whole, whole_refs, _ = match.target('2008-06', '%08x' % parent)
            off = start - parent
            target = whole[off:off + len(body)]
            target_refs = [x - off for x in whole_refs if off <= x < off + len(body)]
        else:
            try:
                target, target_refs, _ = match.target('2008-06', '%08x' % address)
            except SystemExit as error:
                # the original evidence has no function start here (extent covers it): recorded, never exact
                key = address if address not in self.rows else (address, name)
                self.rows[key] = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': None,
                                  'exact': False, 'counted_class': bool(OWN.search(name)), 'bounds': str(error)}
                return
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact, 'counted_class': bool(OWN.search(name))}
        if split:
            entry['extent_split'] = 'piece %s+%#x of the evidence extent %s (bounds; not counted)' % (
                '%08x' % split[0], split[1] - split[0], '%08x' % split[0])
        key = address if address not in self.rows else (address, name)
        self.rows[key] = entry
        if not exact:
            return
        start, section = self.definitions[name]
        table = self.sections[section]
        code = self.raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = self.symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            how = self.classify(symbol, value, name)
            if how is None:
                UNBOUND.append('%s: %s in %s -> %s' % (self.name, symbol, name, hex(value)))
                continue
            self.bind(symbol, value, name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})

    def run(self, seeds):
        for address, name in seeds:
            assert name in self.bodies, (self.name, name)
            self.bind(name, address, 'seed')
            self.queue.append((address, name))
        while self.queue:
            value, symbol = self.queue.pop(0)
            if symbol.startswith('??_7'):
                if symbol not in self.vtables:
                    self.vtable(symbol, value)
            else:
                self.row(value, symbol)
        return self



CROSS = {}   # symbol -> address of an exact row of an earlier main build
builds = {}
for name in SOURCES:
    builds[name] = Build(name, objs[name], True).run(SEEDS[name])
    for row in builds[name].rows.values():
        if row['exact']:
            CROSS.setdefault(row['symbol'], int(row['address'], 16))
pending_builds = [Build(name + '-pending', objs[name + '-pending'], False).run(PENDING_SEEDS[name])
                  for name in PENDING_UNITS]
main = list(builds.values())
# External vtable slots: one address per symbol across every vtable and relocation binding of the main builds.
occurrences = {}
for build in main:
    for symbol, (value, origin) in build.binding.items():
        occurrences.setdefault(symbol, set()).add((value, build.name + ': ' + origin))
for build, own, symbol, value, where in SLOTS:
    occurrences.setdefault(symbol, set()).add((value, build + ': ' + where))
SLOT_CHECK = {}
for build, own, symbol, value, where in SLOTS:
    values = {v for v, _ in occurrences[symbol]}
    if len(values) > 1:
        assert not own, ('inconsistent external slot in an own vtable', symbol, sorted(occurrences[symbol]))
        HEADER_GAPS.append('%s: %s -> %s, but %s elsewhere (the shared header lacks an override)'
                           % (where, symbol, hex(value), sorted(hex(v) for v in values - {value})))
        continue
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (symbol, hex(value))
        how = 'external'
    elif symbol in UNPROVEN:
        assert UNPROVEN[symbol] == value, (symbol, hex(value))
        how = 'own function not compiled here (bound by the original slot)'
    elif norm(names.get(value, '')) == norm(symbol):
        how = 'evidence name'
    elif original.imported(value) is not None and original.imported(value)[1] == nb.plain(symbol):
        how = 'import %s!%s' % original.imported(value)
    elif len({w for _, w in occurrences[symbol]}) > 1:
        how = 'same address at %d places' % len({w for _, w in occurrences[symbol]})
    else:
        UNBOUND.append('%s: unverified external slot %s -> %s (%s)' % (build, symbol, hex(value), where))
        continue
    SLOT_CHECK['%s | %s' % (where, symbol)] = '%s (%s)' % (hex(value), how)
assert not UNBOUND, '\n'.join(sorted(set(UNBOUND)))

# The same symbol compiled in two main units (shared inline / template instances) must bind to the same address.
for a in main:
    for b in main:
        for symbol, (value, _) in a.binding.items():
            if symbol in b.binding:
                assert b.binding[symbol][0] == value, (symbol, hex(value), hex(b.binding[symbol][0]))
for cls, vt in VTABLE.items():
    assert any(info['address'] == hex(vt) for build in main for info in build.vtables.values()), cls

pending_rows = []
main_rows = [r for build in main for r in build.rows.values()]
for build in pending_builds:  # noqa: E501
    for row in build.rows.values():
        if any(r['address'] == row['address'] and r['symbol'] == row['symbol'] and r['exact'] for r in main_rows):
            continue   # also exact in a main build: counted there
        row['exact_pending_build_only'] = row['exact']
        row['exact'] = False
        pending_rows.append(dict(row, build=build.name))

# Unit ranges of the original ChatOutput unit (0064f6b0.. after the Button unit; the ChatLine destructor 0064f8c0 is
# in it) and ScoreHud unit. Rows outside them are exact support rows, not counted (GuiItem inline virtuals, ICF-shared
# Notifier add/removeListener bodies 004218a0 / 005e5a80, std::deque helpers, ...).
UNIT_RANGES = ((0x64f6b0, 0x651000), (0x651000, 0x656490))


def counts(address):
    a = int(address, 16)
    rows = [r for r in main_rows if r['address'] == address]
    if not rows or not all(r['exact'] for r in rows) or any(r.get('extent_split') for r in rows):
        return False
    syms = [r['symbol'] for r in rows]
    if any(lo <= a < hi for lo, hi in UNIT_RANGES):
        return any(OWN.search(x) for x in syms)
    return False


counted = sorted({r['address'] for r in main_rows if counts(r['address'])})
support = sorted({r['address'] for r in main_rows if r['exact'] and not r.get('extent_split')} - set(counted))
inexact = list({(r['address'], r['symbol']): r for r in main_rows if not r['exact']}.values())
sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX::ScoreHud, ChatOutput, ChatLine',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': all_flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(objs.values())},
    'layout': {k: hex(v) for k, v in LAYOUT_VALUES.items()},
    'exact_function_rows': counted,
    'exact_support_rows': support,
    'exact_extent_split_rows': sorted({r['address'] for r in main_rows if r['exact'] and r.get('extent_split')}),
    'rows': {b.name: list(b.rows.values()) for b in main},
    'not_exact_rows': [{'address': r['address'], 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size'], 'bounds': r.get('bounds'),
                        'evidence_name': names.get(int(r['address'], 16)) or None} for r in inexact],
    'pending_rows': pending_rows,
    'vtables': {k: v for b in main for k, v in b.vtables.items()},
    'external_slots': SLOT_CHECK,
    'shared_header_gaps': HEADER_GAPS,
    'pending_note': 'pending_rows are exact only against out/native-layouts/hud-pending (v8tree/Instance.h with '
                    'ChildRemoved defined). Not counted; their vtables are not walked.',
    'not_attempted': NOT_ATTEMPTED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/hud-family-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native HUD family (ScoreHud, ChatOutput): %d distinct class addresses exact (+%d support rows), %d compiled rows not exact, '
      '%d pending-build-only rows not counted; %d vtables walked'
      % (len(counted), len(support), len(inexact), sum(1 for r in pending_rows if r.get('exact_pending_build_only')),
         len(receipt['vtables'])))
