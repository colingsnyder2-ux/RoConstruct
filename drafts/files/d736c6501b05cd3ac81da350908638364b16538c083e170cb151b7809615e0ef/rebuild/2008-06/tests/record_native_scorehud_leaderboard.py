"""Verify the inactive native RBX::ScoreHud leaderboards (2008-06): BoardData, LeaderboardData, BuildBoardData,
renderFFALeaderboard and renderTeamDeathmatchLeaderboard, with the std::map / vector instances they use.

Builds (document-swap flags, VS2008 RTM 21022, native headers only):
  * out/native-layouts/NativeScoreHudLeaderboardLayout.cpp (generated) layout probes against the constructor stores;
  * native-classes/ScoreHudLeaderboard2008.cpp  the ScoreHud unit's leaderboard half (00652640..00655a20 and
                                                 renderTeamDeathmatchLeaderboard 00655a20); unit profile + /fp:fast
                                                 (renderFFALeaderboard 006551e0 x87 order; the other rows are the same
                                                 with or without it).

Rows are found by closure from seeds (the two render functions, named by render2d's calls 0065646f / 0065644d, which
record_native_hud.py already checks): every REL32/DIR32 relocation of an exact row is bound to the address the original
instruction uses. A target defined in the compiled object becomes a row at that address. Every other target is
verified: imports by DLL export name, string literals by bytes, float constants (__real@) by bytes, type descriptors by
RTTI name, external functions by the evidence name or the EXTERNAL map (call sites read in the original disassembly).
A symbol binds to one address. No vtable is compiled in this unit. Rows already counted by another receipt
(work/2008-06/shared-layouts) are never counted here. Writes work/2008-06/shared-layouts/scorehud-leaderboard-working.json.
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
SOURCES = {'ScoreHudLeaderboard2008': R / 'native-classes/ScoreHudLeaderboard2008.cpp'}
POST = {'ScoreHudLeaderboard2008': ['/fp:fast']}
HEADERS = [R / 'native-headers/gui/ScoreHud.h']
# Layout probes (each compiles to mov eax, imm32; ret), generated under out/ next to the objects.
LAYOUT = OUT / 'NativeScoreHudLeaderboardLayout.cpp'
LAYOUT.write_text(
    '#include "gui/ScoreHud.h"\n#include <cstddef>\n'
    'struct NativeScoreHudLeaderboardLayout\n{\n'
    '    static unsigned context() { return offsetof(RBX::LeaderboardData, context); }\n};\n'
    'unsigned nativeBoardDataData() { return offsetof(RBX::BoardData, data); }\n'
    'unsigned nativeBoardDataFields() { return offsetof(RBX::BoardData, fields); }\n'
    'unsigned nativeBoardDataSize() { return sizeof(RBX::BoardData); }\n'
    'unsigned nativeLeaderboardStatNames() { return offsetof(RBX::LeaderboardData, statNamesList); }\n'
    'unsigned nativeLeaderboardPlayersByTeam() { return offsetof(RBX::LeaderboardData, playersByTeamList); }\n'
    'unsigned nativeLeaderboardStatMap() { return offsetof(RBX::LeaderboardData, statMap); }\n'
    'unsigned nativeLeaderboardTeamTotals() { return offsetof(RBX::LeaderboardData, teamTotals); }\n'
    'unsigned nativeLeaderboardContext() { return NativeScoreHudLeaderboardLayout::context(); }\n'
    'unsigned nativeLeaderboardSize() { return sizeof(RBX::LeaderboardData); }\n')
RECEIPT = ROOT / 'work/2008-06/shared-layouts/scorehud-leaderboard-working.json'


def build(name, src, extra=(), post=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(post) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeScoreHudLeaderboardLayout', LAYOUT)
objs, all_flags = {}, {'layout': layout_flags}
for name, src in SOURCES.items():
    objs[name], all_flags[name] = build('NativeSHL_' + name, src, post=POST.get(name, ()))

# ---- layout ---------------------------------------------------------------------------------------------------
LAYOUT_VALUES = {
    'nativeBoardDataData': 0x0, 'nativeBoardDataFields': 0x18, 'nativeBoardDataSize': 0x30,
    'nativeLeaderboardStatNames': 0x0, 'nativeLeaderboardPlayersByTeam': 0x18, 'nativeLeaderboardStatMap': 0x38,
    'nativeLeaderboardTeamTotals': 0x58, 'nativeLeaderboardContext': 0x78, 'nativeLeaderboardSize': 0x7c,
}
raw = layout_obj.read_bytes()
for prefix, value in LAYOUT_VALUES.items():
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + prefix + '@@'))
    expected = b'\x33\xc0\xc3' if value == 0 else b'\xb8' + struct.pack('<I', value) + b'\xc3'   # xor eax, eax for 0
    assert body == expected, (prefix, body.hex())

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


# Seeds and layout evidence read from the original call sites / constructors.
for site, callee in ((0x65646f, 0x6551e0),     # render2d -> renderFFALeaderboard
                     (0x65644d, 0x655a20),     # render2d -> renderTeamDeathmatchLeaderboard
                     (0x65520c, 0x654080),     # renderFFALeaderboard -> BoardData() (stack object)
                     (0x655254, 0x654100),     # renderFFALeaderboard -> ~BoardData (early return)
                     (0x655223, 0x654d20),     # renderFFALeaderboard -> BuildBoardData
                     (0x655a4e, 0x655970),     # renderTeamDeathmatchLeaderboard -> LeaderboardData(Instance*)
                     (0x655a65, 0x654860),     # -> LeaderboardData::CompileData
                     (0x656412, 0x6558f0),     # -> ~LeaderboardData
                     (0x654a0b, 0x6546d0),     # CompileData -> AddTuple
                     (0x654df0, 0x654630)):    # BuildBoardData -> BoardData::SetSize
    assert call_target(site) == callee, (hex(site), hex(callee))
# BoardData() 00654080 stores data's members at +0x00/+0x0c..+0x14 and fields' at +0x18 (lea edi, [esi + 0x18]); the
# LeaderboardData members are read by CompileData 00654860: context [esi + 0x78], statNamesList +0x00 (+0x0c/+0x10),
# playersByTeamList lea [esi + 0x18], statMap lea [esi + 0x38], teamTotals lea [esi + 0x58].
assert original.data(0x6540cc, 3) == b'\x8d\x7e\x18'
assert original.data(0x65487d, 3) == b'\x8b\x46\x78'
assert original.data(0x654b8f, 3) == b'\x8d\x4e\x18' and original.data(0x654bc5, 3) == b'\x8d\x4e\x38'
assert original.data(0x654c08, 3) == b'\x8d\x4e\x58'


# ---- verification maps ----------------------------------------------------------------------------------------
# Externals whose evidence name differs from the compiled symbol (or has none): the address the original call site
# uses, with the site it was read from.
EXTERNAL = {
    # std exception vtables reached from the unit (bound by RTTI name): slot 0 values read from the original vtable.
    '??_Ebad_alloc@std@@UAEPAXI@Z': 0x4023c0,                                                # bad_alloc vtable slot 0
    '??_Elength_error@std@@UAEPAXI@Z': 0x55c390,                                             # ICF logic_error (record_native_hud)
    '??_Eout_of_range@std@@UAEPAXI@Z': 0x55c390,                                             # ICF logic_error
    '??_Elogic_error@std@@UAEPAXI@Z': 0x55c390,                                              # logic_error vtable slot 0
    '??_Ebad_lexical_cast@boost@@UAEPAXI@Z': 0x5011a0,                                       # bad_lexical_cast vtable slot 0
    # G3D static accessors (bodies asserted below): white() -> (1,1,1); Color4::zero() -> (0,0,0,0), the body other
    # recorders bind as Color4::clear() (identical G3D bodies folded by the linker).
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,                                               # 006553c5; record_native_hopper
    '?zero@Color4@G3D@@SAABV12@XZ': 0x7baf10,                                                # 0065542e
    # ServiceProvider helpers (record_native_network_players / record_native_team bind the same addresses).
    '??$find@VPlayers@Network@RBX@@@ServiceProvider@RBX@@SAPAVPlayers@Network@1@PBVInstance@1@@Z': 0x491d50,  # 00654882
    '??$find@VTeams@RBX@@@ServiceProvider@RBX@@SAPAVTeams@1@PBVInstance@1@@Z': 0x49ab50,     # 00655a6b
    '??$create@VTeams@RBX@@@ServiceProvider@RBX@@SAPAVTeams@1@PBVInstance@1@@Z': 0x590dd0,   # 0065488d (asserted below)
    '?getTeamFromPlayer@Teams@RBX@@QAEPAVTeam@2@PAVPlayer@Network@2@@Z': 0x5d5ea0,          # 006548f3; native Teams.h
    # IntValue::desc_Value (BoundProp<int, 1>): 007f85b0 constructs it at 0097d384 (BoundProp constructor 006372d0,
    # name "Value" 00818478, member offset 0x130); BuildBoardData / CompileData read its getset (+0x18) right after the
    # dynamic_cast to .?AV?$Value@H$1?sIntValue@RBX@@3PADA@RBX@@ (00960f78).
    '?desc_Value@?$Value@H$1?sIntValue@RBX@@3PADA@RBX@@2V?$BoundProp@H$00@Reflection@2@A': 0x97d384,
    # Player-name hash (no evidence name; ScoreHud.h stringHash): called at 0065556e and by ChatLine() 0065061e.
    '?stringHash@RBX@@YAIABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x669f60,
}
assert original.data(0x7f85ca, 5) == b'\xb9' + struct.pack('<I', 0x97d384) and call_target(0x7f85cf) == 0x6372d0
assert original.data(0x7f85c5, 5) == b'\x68' + struct.pack('<I', 0x818478) and original.data(0x818478, 6) == b'Value\0'
assert original.data(0x7f85bb, 5) == b'\x68' + struct.pack('<I', 0x130)
assert original.string(0x960f78 + 8) == '.?AV?$Value@H$1?sIntValue@RBX@@3PADA@RBX@@'
assert original.data(0x654f4b, 6) == b'\x8b\x0d' + struct.pack('<I', 0x97d39c)
# create<Teams>(const Instance*) 00590dd0: walks parents with dynamic_cast to ServiceProvider, then tail-jumps to the
# member ServiceProvider::create<Teams>() 004b3b40 (member find<Teams> 0049a580, else Creatable create<Teams> 00490450,
# the 0x138-byte Teams allocation native Teams.h cites).
assert original.string(0x92e15c + 8) == '.?AVServiceProvider@RBX@@'
assert original.data(0x590e0c, 1) == b'\xe9' and (0x590e11 + struct.unpack('<i', original.data(0x590e0d, 4))[0]) == 0x4b3b40
assert call_target(0x4b3b5b) == 0x49a580 and call_target(0x4b3b6f) == 0x490450
for site in (0x65556e, 0x65061e):
    assert call_target(site) == 0x669f60, hex(site)
assert original.data(0x669f17, 5) == b'\xb8\xc9\xf8\x00\x00' and original.data(0x669f39, 6) == b'\x69\xc0\xb7\xc6\x05\x00'
# G3D static bodies: guard bit, fld1 / fldz, three / four stores, return the static.
assert original.data(0x514a6d, 2) == b'\xd9\xe8' and original.data(0x7baf1d, 2) == b'\xd9\xee'
UNPROVEN = {}
CLASS_NAMES = {}
# One evidence extent covering two functions: 00655870 (117 bytes) is ~_Tree<map<Team*, map<string, int>>> (112 bytes,
# ends in ret) followed by the 5-byte thunk 006558e0 (jmp 00655800; referenced only by the EH unwind funclets 007dbaa9
# / 007dbae1, so a separate function).
EXTENT_SPLITS = {0x655870: [(0x655870, 112)]}
assert original.data(0x6558df, 2) == b'\xc3\xe9'
DATA = {}
FOLDED = {}
CROSS = {}
# Evidence extents that stop inside a function (BOUNDS proofs; bounds.json is not changed here): address ->
# (compiled size, proof). Rows compared this way are recorded with 'bounds_extended' and never counted.
BOUNDS_EXTENDED = {
    0x652e90: (729, 'vector<vector<string>>::_Insert_n: the evidence extent is 570 bytes, but its last instruction '
                    '006530c5 jmps back to 0065314a inside the same body (the catch/rethrow tail), and the next '
                    'evidence function starts at 00653170 = 00652e90 + 729 rounded to 16'),
}
assert original.data(0x6530c5, 1) == b'\xe9' and (0x6530ca + struct.unpack('<i', original.data(0x6530c6, 4))[0]) == 0x65314a
assert match.target('2008-06', '00653170')[0] and len(match.target('2008-06', '00652e90')[0]) == 570

SEEDS = {
    'ScoreHudLeaderboard2008': [(0x6551e0, '?renderFFALeaderboard@ScoreHud@RBX@@IAEXPAVAdorn@2@@Z'),
                                (0x655a20, '?renderTeamDeathmatchLeaderboard@ScoreHud@RBX@@IAEXPAVAdorn@2@W4BoardType@12@@Z')],
}
OWN_CLASSES = 'ScoreHud|BoardData|LeaderboardData'
OWN = re.compile(r'(?:^|[^A-Za-z]|\?\?_[EG])(%s)@RBX@@' % OWN_CLASSES)
NOT_ATTEMPTED = {
    '006546c0 / 006558e0': 'std vector / map destructor thunks (jmp 006541e0 / 00655800) referenced only by EH unwind '
                           'funclets (007dba9e, 007dbaa9, ...); EH funclets are not walked',
    'std _Buynode / _Uninit_* / vector _Insert_n rows listed under not_exact_rows': 'std instances shared with other '
                           'units; most differ only by evidence extents that stop early (catch funclet tails)',
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
        elif address in BOUNDS_EXTENDED and BOUNDS_EXTENDED[address][0] == len(body):
            # The evidence extent stops early, but the function continues (proof in BOUNDS_EXTENDED): compare the
            # original bytes over the compiled length; the evidence relocations stay masked.
            _, target_refs, _ = match.target('2008-06', '%08x' % address)
            target = original.data(address, len(body))
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
        if address in BOUNDS_EXTENDED and BOUNDS_EXTENDED[address][0] == len(body):
            entry['bounds_extended'] = BOUNDS_EXTENDED[address][1]
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




builds = {}
for name in SOURCES:
    builds[name] = Build(name, objs[name], True).run(SEEDS[name])
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

main_rows = [r for build in main for r in build.rows.values()]
# The original ScoreHud unit (record_native_hud.py UNIT_RANGES): only own-class rows inside it are counted; std
# instances and rows outside it (ICF-shared bodies such as AddField 00650ef0) are exact support rows.
UNIT_RANGES = ((0x651000, 0x656490),)
# Rows another receipt already counts are never counted here.
OTHER = {}
for path in sorted((ROOT / 'work/2008-06/shared-layouts').glob('*.json')):
    if path == RECEIPT:
        continue
    try:
        rows = json.loads(path.read_text()).get('exact_function_rows', [])
    except Exception:
        continue
    for a in rows if isinstance(rows, list) else []:
        if isinstance(a, str):
            OTHER.setdefault(a, path.name)


def counts(address):
    a = int(address, 16)
    rows = [r for r in main_rows if r['address'] == address]
    if not rows or not all(r['exact'] for r in rows) or address in OTHER or any(r.get('bounds_extended') or r.get('extent_split') for r in rows):
        return False
    if any(lo <= a < hi for lo, hi in UNIT_RANGES):
        return any(OWN.search(r['symbol']) for r in rows)
    return False


counted = sorted({r['address'] for r in main_rows if counts(r['address'])})
support = sorted({r['address'] for r in main_rows if r['exact'] and not r.get('bounds_extended')
                  and not r.get('extent_split')} - set(counted))
split_rows = sorted({r['address'] for r in main_rows if r['exact'] and r.get('extent_split')})
bounds_rows = sorted({r['address'] for r in main_rows if r['exact'] and r.get('bounds_extended')})
inexact = list({(r['address'], r['symbol']): r for r in main_rows if not r['exact']}.values())
sha = nb.sha
paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX::ScoreHud leaderboards, BoardData, LeaderboardData',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': all_flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(objs.values())},
    'layout': {k: hex(v) for k, v in LAYOUT_VALUES.items()},
    'exact_function_rows': counted,
    'exact_support_rows': support,
    'exact_bounds_extended_rows': bounds_rows,
    'exact_extent_split_rows': split_rows,
    'support_rows_counted_elsewhere': {a: OTHER[a] for a in support if a in OTHER},
    'rows': {b.name: list(b.rows.values()) for b in main},
    'not_exact_rows': [{'address': r['address'], 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size'], 'bounds': r.get('bounds'),
                        'evidence_name': names.get(int(r['address'], 16)) or None} for r in inexact],
    'external_slots': SLOT_CHECK,
    'shared_header_gaps': HEADER_GAPS,
    'not_attempted': NOT_ATTEMPTED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native ScoreHud leaderboards: %d distinct class addresses exact (+%d support rows, %d exact only over a '
      'proven longer extent, %d extent-split pieces), %d compiled rows not exact'
      % (len(counted), len(support), len(bounds_rows), len(split_rows), len(inexact)))
