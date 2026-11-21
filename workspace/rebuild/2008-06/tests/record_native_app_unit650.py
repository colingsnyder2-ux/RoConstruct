"""Map and verify the 2008-06 application range 00650000..00654000 (inactive native recovery, app unit 650).

Unit map (written to the receipt's unit_map with the evidence):
  * gui/ChatOutput.cpp object ..00650e0f: the ChatOutput rows of native-classes/ChatOutput.cpp (hud-family receipt) and
    ChatLine(Player*, const string&, float) 00650560, ParseCommand 00650660, onEvent(ChatMessage) 00650cc0;
  * gui/ScoreHud.cpp object 00650e10..0065648f: the std map / vector instances of the ScoreHud leaderboard tables
    (BoardData / LeaderboardData of the read-only native gui/ScoreHud.h), interleaved with the ScoreHud members that
    hud-family counts (~ScoreHud 00650f80, the ??_E thunks, DetermineBoardType, ScoreHud(), onServiceProvider).
No library unit (Ogre, G3D, boost, CRT, MFC/ATL, XTP, zlib, Lua, RakNet) and no excluded MFC class is in the range.

Builds (document-swap flags, VS2008 RTM 21022, /fp:fast as the owners' ChatOutput.cpp / ScoreHudLeaderboard2008.cpp):
  * native-classes/AppUnit650LeaderboardTemplates.cpp  explicit instantiations of the leaderboard containers;
  * native-classes/AppUnit650ChatOutput.cpp            ChatLine(), and (NATIVE_APPUNIT650_PENDING) onEvent(ChatMessage);
  * AppUnit650ChatOutput-pending: the same unit with /DNATIVE_APPUNIT650_PENDING against a generated copy of the
    native Network/Player.h with an inline getSuperSafeChat() (out/native-layouts/app-unit650-pending; proposal).
    Its rows are recorded exact=false (pending-build-only) and never counted.

Rows are reached by closure from call-site seeds read in the original (and from the EH unwind funclets of ScoreHud unit
functions). Every REL32/DIR32 target of an exact row is bound to the address the original instruction uses, one
address per symbol, and verified (own rows, imports by name, literals / float constants by bytes, RTTI by name,
externals by evidence name or the EXTERNAL map with the call site it was read from). A compiled body longer than its
evidence extent is compared over the extent plus the adjacent catch funclet row(s) only when the lengths add up exactly
(the catch block is part of the function; BOUNDS evidence). A row is counted only when it is exact in a main build,
lies in the ChatOutput or ScoreHud object, every direct caller / DIR32 reference in .text lies in that same object
(or in an unwind funclet of one of its functions), and no other receipt counts it. ICF-shared bodies stay support rows.
Writes work/2008-06/shared-layouts/app-unit650-working.json.
"""
import json
import re
import struct
import sys
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit650-working.json'
RANGE = (0x650000, 0x654000)
SOURCES = {
    'AppUnit650LeaderboardTemplates': R / 'native-classes/AppUnit650LeaderboardTemplates.cpp',
    'AppUnit650ChatOutput': R / 'native-classes/AppUnit650ChatOutput.cpp',
}
POST = ['/fp:fast']
HEADERS = [R / 'native-headers/gui/ScoreHud.h', R / 'native-headers/gui/ChatOutput.h', R / 'native-headers/Network/Player.h']

# ---- pending header copy (proposal for the Network/Player.h owner) -----------------------------------------------
PENDING_DIR = OUT / 'app-unit650-pending'
(PENDING_DIR / 'Network').mkdir(parents=True, exist_ok=True)
player_h = (R / 'native-headers/Network/Player.h').read_text()
ANCHOR = '\t\t\tvoid setNeutral(bool value);                              // 00494620\n'
assert player_h.count(ANCHOR) == 1 and 'getSuperSafeChat' not in player_h
PROPOSAL_PLAYER = ('\t\t\tbool getSuperSafeChat() const                             // inlined into 00650cc0 (proposal)\n'
                   '\t\t\t{\n\t\t\t\treturn superSafeChat;\n\t\t\t}\n')
(PENDING_DIR / 'Network/Player.h').write_text(player_h.replace(ANCHOR, ANCHOR + PROPOSAL_PLAYER))


def build(name, src, extra=(), post=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(post) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


objs, all_flags = {}, {}
for name, src in SOURCES.items():
    objs[name], all_flags[name] = build('NativeU650_' + name, src, post=POST)
objs['AppUnit650ChatOutput-pending'], all_flags['AppUnit650ChatOutput-pending'] = build(
    'NativeU650_AppUnit650ChatOutputPending', SOURCES['AppUnit650ChatOutput'], ['/I' + str(PENDING_DIR)],
    ['/DNATIVE_APPUNIT650_PENDING'] + POST)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
pe = original.pe
TEXT = next(s for s in pe.sections if s.Name.startswith(b'.text'))
TEXT_LO = pe.OPTIONAL_HEADER.ImageBase + TEXT.VirtualAddress
TEXT_HI = TEXT_LO + TEXT.Misc_VirtualSize
TEXT_DATA = TEXT.get_data()
FUNCS = sorted((int(x['addr'], 16), x['size'], x['kind']) for x in map(json.loads, (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()))
FUNC_AT = {a: (s, k) for a, s, k in FUNCS}
CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


def call_target(site):
    assert original.data(site, 1) in (b'\xe8', b'\xe9'), hex(site)
    return (site + 5 + struct.unpack('<i', original.data(site + 1, 4))[0]) & 0xffffffff


def site(caller, callee):
    """The single direct call from the evidence row `caller` to `callee` (asserted to exist)."""
    size = FUNC_AT[caller][0]
    hits = [i.address for i in CS.disasm(original.data(caller, size), caller)
            if i.mnemonic in ('call', 'jmp') and i.op_str == hex(callee)]
    assert hits, (hex(caller), hex(callee))
    return hits[0]


# ---- object extents (unit map) ----------------------------------------------------------------------------------
CHAT_UNIT = (0x64f6b0, 0x650e10)     # Color statics (util/Color.h) + ChatLine / ChatOutput rows
SCORE_UNIT = (0x650e10, 0x656490)    # ScoreHud.cpp: leaderboard template instances + ScoreHud members + render2d
UNITS = {'gui/ChatOutput.cpp object': CHAT_UNIT, 'gui/ScoreHud.cpp object': SCORE_UNIT}
# Boundary evidence: onEvent(ChatMessage) 00650cc0 (ChatOutput Listener<Players, ChatMessage> slot 0, vtable 0084baf4)
# is the last ChatOutput member and ends at 00650e10; the next row 00650e10 is a _Tree<Team*, map<string,int>> member
# (a ScoreHud leaderboard type); ScoreHud render2d 00656430 (slot 24 of 0084bcb4) is the last ScoreHud row (88 bytes);
# 00656490 is the next object's first row.
assert d(0x84baf4) == 0x650cc0 and FUNC_AT[0x650cc0][0] == 0x650e10 - 0x650cc0
assert d(0x84bcb4 + 24 * 4) == 0x656430 and 0x656430 + FUNC_AT[0x656430][0] <= 0x656490 and 0x656490 in FUNC_AT
assert not any(0x656430 < a < 0x656490 for a in FUNC_AT)
assert original.vtable_class(0x84baf4) == ('.?AVChatOutput@RBX@@', 0x144)   # ChatOutput's Listener<Players, ChatMessage> subobject
assert original.vtable_class(0x84bcb4)[0] == '.?AVScoreHud@RBX@@'


def handler_funclets(address):
    """Unwind funclet starts of the evidence function at `address` (push handler -> mov eax, funcinfo -> unwind map)."""
    head = original.data(address, 24)
    out = set()
    for i in range(len(head) - 4):
        if head[i] != 0x68:
            continue
        h = struct.unpack_from('<I', head, i + 1)[0]
        if not TEXT_LO <= h < TEXT_HI:
            continue
        code = original.data(h, 24)
        j = code.find(b'\xb8')
        if j < 0:
            continue
        fi = d(h + j + 1)
        try:
            magic = d(fi)
        except Exception:
            continue
        if magic not in (0x19930520, 0x19930521, 0x19930522):
            continue
        n, um = d(fi + 4), d(fi + 8)
        out |= {d(um + 8 * k + 4) for k in range(n)} - {0}
        break
    return out


FUNCLETS = {}   # funclet start -> (unit name, owning function)
for unit, (lo, hi) in UNITS.items():
    for a, size, kind in FUNCS:
        if lo <= a < hi and kind == 'code':
            for f in handler_funclets(a):
                FUNCLETS.setdefault(f, (unit, a))


def funclet_jump(f):
    """The call/jmp target of a short unwind funclet (lea/mov ecx, ...; jmp target)."""
    for i in CS.disasm(original.data(f, 16), f):
        if i.mnemonic in ('jmp', 'call'):
            return int(i.op_str, 16) if i.op_str.startswith('0x') else None
    return None


REFS = {}   # target -> set of referencing instruction addresses (E8/E9 rel32 and DIR32 in .text)
for m in re.finditer(b'[\xe8\xe9]', TEXT_DATA):
    i = m.start()
    if i + 5 > len(TEXT_DATA):
        break
    t = (TEXT_LO + i + 5 + struct.unpack_from('<i', TEXT_DATA, i + 1)[0]) & 0xffffffff
    if 0x64f000 <= t < 0x657000:
        REFS.setdefault(t, set()).add(TEXT_LO + i)

def dir32_refs(value):
    pat = struct.pack('<I', value)
    return {TEXT_LO + m.start() for m in re.finditer(re.escape(pat), TEXT_DATA)}


def owner_of(address):
    lo = max((a for a, s, k in FUNCS if a <= address), default=None)
    if lo is not None and address < lo + FUNC_AT[lo][0]:
        return lo
    return None


def unit_of(address):
    return next((u for u, (lo, hi) in UNITS.items() if lo <= address < hi), None)


def referenced_only_from_unit(address, unit):
    """Every rel32 call/jmp and every DIR32 in .text that targets `address` lies in `unit` or in its unwind funclets."""
    where = []
    for ref in sorted(REFS.get(address, set()) | dir32_refs(address)):
        lo, hi = UNITS[unit]
        if lo <= ref < hi:
            where.append('%08x' % ref)
            continue
        f = next((x for x in FUNCLETS if x <= ref < x + 16 and FUNCLETS[x][0] == unit), None)
        if f is not None:
            where.append('%08x (unwind funclet of %08x)' % (ref, FUNCLETS[f][1]))
            continue
        return False, '%08x (outside %s)' % (ref, unit)
    return True, where


# ---- verification maps ----------------------------------------------------------------------------------------
EXTERNAL = {
    # Call sites read in ChatLine() 00650560 / onEvent 00650cc0 (record_native_scorehud_leaderboard binds the same).
    '??$find@VTeams@RBX@@@ServiceProvider@RBX@@SAPAVTeams@1@PBVInstance@1@@Z': 0x49ab50,     # 006505c7
    '?isTeamGame@Teams@RBX@@QAE_NXZ': 0x5d6070,                                              # 006505d7; native Teams.h
    '?getTeamFromPlayer@Teams@RBX@@QAEPAVTeam@2@PAVPlayer@Network@2@@Z': 0x5d5ea0,          # 006505ec; native Teams.h
    '?black@Color3@G3D@@SAABV12@XZ': 0x5149f0,                                               # 0065060f (fldz body)
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,                                               # 00650616 (fld1 body)
    '?stringHash@RBX@@YAIABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x669f60,  # 0065061e
    '?removeOldest@ChatOutput@RBX@@AAEXXZ': 0x64fd70,                                        # 00650d02; hud-family row
    '?ParseCommand@ChatOutput@RBX@@AAE_NVChatMessage@Network@2@@Z': 0x650660,                # 00650d4b; not attempted
    '?ContainsProfanity@ProfanityFilter@RBX@@QAE_NV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x66a350,  # 00650d85
    '?singleton@?$GlobalSettingsItem@VGameSettings@RBX@@$1?sGameSettings@2@3QBDB@RBX@@SAAAVGameSettings@2@XZ': 0x44bee0,  # 00650ce6
}
for at, callee in ((0x6505c7, 0x49ab50), (0x6505d7, 0x5d6070), (0x6505ec, 0x5d5ea0), (0x65060f, 0x5149f0),
                   (0x650616, 0x514a60), (0x65061e, 0x669f60), (0x650d02, 0x64fd70), (0x650d4b, 0x650660),
                   (0x650d85, 0x66a350), (0x650ce6, 0x44bee0), (0x650a82, 0x650560), (0x650dc8, 0x650560)):
    assert call_target(at) == callee, (hex(at), hex(callee))
assert original.data(0x5149fd, 2) == b'\xd9\xee' and original.data(0x514a6d, 2) == b'\xd9\xe8'
# GameSettings::singleton 0044bee0 is the GlobalSettingsItem<GameSettings> body (record_native_gamesettings_singleton_*);
# isTeamGame / getTeamFromPlayer are the native Teams.h declarations at those addresses.
UNPROVEN = {}
CLASS_NAMES = {}
FOLDED = {}
DATA = {}
CROSS = {}
LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
SLOTS = []
HEADER_GAPS = []
# One evidence extent covering two functions (as record_native_scorehud_leaderboard.py): 00655870 (117 bytes) is
# ~_Tree<Team*, map<string, int>> (112 bytes, ends in ret) followed by the 5-byte thunk 006558e0 (jmp 00655800).
EXTENT_SPLITS = {0x655870: [(0x655870, 112)]}
assert original.data(0x6558df, 2) == b'\xc3\xe9'


class Build:
    def __init__(self, name, obj, pending=False):
        self.name, self.obj, self.pending = name, Path(obj), pending
        self.raw = self.obj.read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.binding = {}
        self.rows = {}
        self.queue = []

    def sym(self, prefix, *parts, size=None, suffix=None):
        hits = [n for n, (b, r) in self.bodies.items() if n.startswith(prefix) and all(p in n for p in parts)
                and (size is None or len(b) == size) and (suffix is None or n.endswith(suffix))
                and not LOCAL_EH.match(n)]
        assert len(hits) == 1, (self.name, prefix, parts, hits)
        return hits[0]

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
            return 'vtable RTTI %s offset %#x' % (rtti, at)
        if symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
            return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
        if norm(names.get(value, '')) == norm(symbol) and symbol not in self.definitions:
            return 'external (evidence name)'
        if (symbol.startswith('__real@') or symbol.startswith('__xmm@')) and symbol in self.definitions:
            pos, at = self.definitions[symbol]
            table = self.sections[at]
            size = 8 if symbol.startswith('__real@') and len(symbol) == 7 + 16 else 4 if symbol.startswith('__real@') else 16
            data = self.raw[table[4] + pos:table[4] + pos + size]
            assert original.data(value, size) == data, (where, symbol, hex(value), original.data(value, size).hex())
            return 'constant %s' % data.hex()
        if symbol in self.definitions and symbol not in self.bodies:
            return 'own static'
        return None

    def target_for(self, address, body):
        """Original bytes / relocation offsets to compare `body` with, and how (None if the row has no start)."""
        split = next(((parent, start) for parent, pieces in EXTENT_SPLITS.items() for start, size in pieces
                      if start == address and size == len(body)), None)
        if split:
            whole, whole_refs, _ = match.target('2008-06', '%08x' % split[0])
            return whole[:len(body)], [x for x in whole_refs if x < len(body)], {'extent_split': 'first %d bytes of the '
                   'evidence extent (the rest is the separate 5-byte thunk 006558e0); not counted' % len(body)}
        try:
            target, refs, _ = match.target('2008-06', '%08x' % address)
        except SystemExit as error:
            return None, None, {'bounds': str(error)}
        extra = {}
        if len(body) > len(target):
            # The catch block(s) MSVC compiles into this function: evidence rows of kind 'eh' starting exactly at the
            # end of the extent; only when the lengths add up to the compiled body.
            end, pieces = address + len(target), []
            while end < address + len(body) and end in FUNC_AT and FUNC_AT[end][1] == 'eh':
                pieces.append(end)
                end += FUNC_AT[end][0]
            if pieces and end == address + len(body):
                refs = list(refs)
                for p in pieces:
                    t2, r2, _ = match.target('2008-06', '%08x' % p)
                    refs += [x + (p - address) for x in r2]
                target = original.data(address, len(body))
                extra = {'eh_extended': 'compared over the evidence extent %d B + catch funclet row(s) %s (%d B): '
                         'BOUNDS' % (FUNC_AT[address][0], ', '.join('%08x' % p for p in pieces),
                                     len(body) - FUNC_AT[address][0])}
        return target, refs, extra

    def row(self, address, name):
        if address in self.rows and self.rows[address]['symbol'] == name:
            return
        body, refs = self.bodies[name]
        target, target_refs, extra = self.target_for(address, body)
        if target is None:
            self.rows[address] = dict({'address': '%08x' % address, 'symbol': name, 'size': len(body),
                                       'target_size': None, 'exact': False}, **extra)
            return
        exact = len(target) == len(body) and match.exact_match(target, target_refs, body, refs)
        entry = dict({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                      'exact': exact}, **extra)
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

    def drain(self):
        while self.queue:
            value, symbol = self.queue.pop(0)
            self.row(value, symbol)

    def run(self, seeds):
        for address, name, origin in seeds:
            self.bind(name, address, origin)
            self.queue.append((address, name))
        self.drain()
        return self

    def seed_funclet_targets(self, unit):
        """Rows reached only from unwind funclets of `unit`: bind the unique compiled body that is exact there and whose
        already-bound relocation symbols agree with the original operands."""
        added = True
        while added:
            added = False
            bound = {v for v, _ in self.binding.values()}
            for f, (u, fn) in sorted(FUNCLETS.items()):
                t = funclet_jump(f)
                if u != unit or t is None or t in bound or t not in FUNC_AT or not UNITS[unit][0] <= t < UNITS[unit][1]:
                    continue
                cands = []
                for n, (b, r) in self.bodies.items():
                    if LOCAL_EH.match(n) or n in self.binding:
                        continue
                    target, refs, _ = self.target_for(t, b)
                    if target is None or len(target) != len(b) or not match.exact_match(target, refs, b, r):
                        continue
                    if self.consistent(n, t, target):
                        cands.append(n)
                if len(cands) > 1:
                    # prefer the bodies whose every relocation symbol is already bound (and agrees, checked above)
                    full = [n for n in cands if self.all_bound(n)]
                    if len(full) == 1:
                        cands = full
                if len(cands) == 1:
                    self.bind(cands[0], t, 'unique exact body at the target of unwind funclet %08x (of %08x)' % (f, fn))
                    self.queue.append((t, cands[0]))
                    self.drain()
                    added = True
                    bound = {v for v, _ in self.binding.values()}
                elif cands:
                    UNSEEDED.append('%08x (funclet %08x): %d candidate bodies' % (t, f, len(cands)))

    def all_bound(self, name):
        body, _ = self.bodies[name]
        start, section = self.definitions[name]
        table = self.sections[section]
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            if 0 <= offset - start < len(body):
                symbol = self.symbols[index][0]
                if not LOCAL_EH.match(symbol) and symbol not in self.binding:
                    return False
        return True

    def consistent(self, name, address, target):
        body, _ = self.bodies[name]
        start, section = self.definitions[name]
        table = self.sections[section]
        code = self.raw[table[4] + start:]
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = self.symbols[index][0]
            if symbol not in self.binding:
                continue
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if self.binding[symbol][0] != value:
                return False
        return True


UNSEEDED = []
builds = {name: Build(name, obj, pending=name.endswith('-pending')) for name, obj in objs.items()}

# Seeds: call sites in the original (callers are leaderboard / ChatOutput rows verified by their owners' recorders).
T = builds['AppUnit650LeaderboardTemplates']
MAP_TV = 'PAVTeam@RBX@@V?$vector@'
MAP_TM = 'PAVTeam@RBX@@V?$map@'
MAP_SM = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$map@'
template_seeds = [
    (0x6546d0, 0x652c80, T.sym('??A?$map@' + MAP_TV)),                        # AddTuple: playersByTeamList[team]
    (0x6546d0, 0x650eb0, T.sym('??$_Find@')),                                 # AddTuple: std::find
    (0x6546d0, 0x654250, T.sym('??A?$map@' + MAP_SM)),                        # AddTuple: statMap[playerName]
    (0x654860, 0x654360, T.sym('??A?$map@' + MAP_TM)),                        # CompileData: teamTotals[team]
    (0x654630, 0x654170, T.sym('?resize@?$vector@V?$vector@', suffix='@QAEXI@Z')),  # SetSize: data.resize(n)
    (0x654100, 0x653ae0, T.sym('??1?$vector@V?$vector@')),                    # ~BoardData: ~data
    (0x6558f0, 0x6541e0, T.sym('??1?$_Tree@V?$_Tmap_traits@' + MAP_TV)),      # ~LeaderboardData
    (0x6558f0, 0x655800, T.sym('??1?$_Tree@V?$_Tmap_traits@' + MAP_SM)),
    (0x6558f0, 0x655870, T.sym('??1?$_Tree@V?$_Tmap_traits@' + MAP_TM)),
]
T.run([(callee, sym, 'call %08x in %08x' % (site(caller, callee), caller)) for caller, callee, sym in template_seeds])
T.seed_funclet_targets('gui/ScoreHud.cpp object')

C = builds['AppUnit650ChatOutput']
C.run([(0x650560, C.sym('??0ChatLine@RBX@@'), 'call 00650dc8 in 00650cc0')])
P = builds['AppUnit650ChatOutput-pending']
P.run([(0x650560, P.sym('??0ChatLine@RBX@@'), 'call 00650dc8 in 00650cc0'),
       (0x650cc0, P.sym('?onEvent@ChatOutput@RBX@@EAEXPBVPlayers@'),
        'Listener<Players, ChatMessage> vtable 0084baf4 slot 0')])
assert not UNBOUND, '\n'.join(sorted(set(UNBOUND)))

# ---- counting -----------------------------------------------------------------------------------------------------
def walk_methods(o, out):
    if isinstance(o, list):
        for e in o:
            walk_methods(e, out)
    elif isinstance(o, dict):
        if 'address' in o and o.get('exact') is True:
            out.append(o['address'])
        else:
            for v in o.values():
                walk_methods(v, out)


def addr_of(x):
    if isinstance(x, dict):
        x = x.get('address') or x.get('addr') or ''
    m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', str(x))
    return int(m.group(1), 16) if m else None


OTHER = {}   # address -> receipts that count it (top-level exact_function_rows rule)
for path in sorted((ROOT / 'work/2008-06/shared-layouts').glob('*.json')):
    if path == RECEIPT:
        continue
    try:
        data = json.loads(path.read_text())
    except Exception:
        continue
    if not isinstance(data, dict):
        continue
    if 'exact_function_rows' in data:
        rows = data['exact_function_rows']
    elif isinstance(data.get('exact_addresses'), list):
        rows = data['exact_addresses']
    elif isinstance(data.get('exact_unique_addresses'), list):
        rows = data['exact_unique_addresses']
    else:
        rows = []
        walk_methods(data.get('methods', []), rows)
    for r in (list(rows) if isinstance(rows, (list, dict)) else []):
        a = addr_of(r)
        if a is not None:
            OTHER.setdefault(a, set()).add(path.name)

main = [b for b in builds.values() if not b.pending]
main_rows = [r for b in main for r in b.rows.values()]
pending_rows = []
for r in builds['AppUnit650ChatOutput-pending'].rows.values():
    if any(m['address'] == r['address'] and m['symbol'] == r['symbol'] and m['exact'] for m in main_rows):
        continue
    pending_rows.append(dict(r, exact_pending_build_only=r['exact'], exact=False, build='AppUnit650ChatOutput-pending'))
assert any(r['address'] == '00650cc0' and r['exact_pending_build_only'] for r in pending_rows), 'onEvent pending row'

COUNT_NOTES = {}


def counts(address):
    a = int(address, 16)
    rows = [r for r in main_rows if r['address'] == address]
    if not rows or not all(r['exact'] for r in rows) or any(r.get('extent_split') for r in rows):
        return False
    if a in OTHER:
        COUNT_NOTES[address] = 'counted by ' + ', '.join(sorted(OTHER[a]))
        return False
    unit = unit_of(a)
    if not (RANGE[0] <= a < RANGE[1] or unit == 'gui/ScoreHud.cpp object'):
        # e.g. the util/Color.h statics 0064f6b0..0064f7f0 of the ChatOutput object: below this range, left to its
        # range owner
        COUNT_NOTES[address] = 'exact, outside the range and the ScoreHud object (not counted here)'
        return False
    if unit is None:
        COUNT_NOTES[address] = 'outside the ChatOutput / ScoreHud objects (shared body)'
        return False
    ok, where = referenced_only_from_unit(a, unit)
    if not ok:
        COUNT_NOTES[address] = 'referenced from ' + where + ' (ICF-shared body)'
        return False
    COUNT_NOTES[address] = '%s; referenced from %s' % (unit, ', '.join(where))
    return True


counted = sorted({r['address'] for r in main_rows if counts(r['address'])})
assert all(int(a, 16) not in OTHER for a in counted)


def hexed(a):
    return '0x' + a   # non-counted rows never appear as a quoted bare address (bare-address recorders)


def row_out(r, count):
    out = dict(r)
    out['address'] = r['address'] if count else hexed(r['address'])
    return out


groups = {b.name: [row_out(r, r['address'] in counted) for r in b.rows.values()] for b in main}
support = sorted({r['address'] for r in main_rows if r['exact']} - set(counted))
inexact = list({(r['address'], r['symbol']): r for r in main_rows if not r['exact']}.values())

# ---- range map --------------------------------------------------------------------------------------------------
REASON = {
    0x650660: 'ChatOutput::ParseCommand (1439 B): not attempted; needs SafeChat::getMessage (006584e0) declared in the '
              'read-only GuiHud2008/GuiBuilder2008.h, the boost tokenizer / char_separator inline expansion and the '
              'lower-case helper 0064fd00',
    0x651250: 'vector<shared_ptr<Instance>>::at: ICF-shared (also called from 005ad6d0); not compiled here (exact '
              'support row of hud-family / scorehud-leaderboard)',
    0x650ef0: 'BoardData::AddField, inline in the read-only gui/ScoreHud.h and emitted only by the owner\'s '
              'ScoreHudLeaderboard2008.cpp (exact support row there); called only from BuildBoardData 00654d20 '
              '(proposal to the ScoreHud owner)',
}
range_map = []
for a, size, kind in FUNCS:
    if not RANGE[0] <= a < RANGE[1]:
        continue
    key = '%08x' % a
    if key in counted:
        status = 'counted here'
    elif a in OTHER:
        status = 'counted by ' + ', '.join(sorted(OTHER[a]))
    elif any(r['address'] == key and r.get('exact_pending_build_only') for r in pending_rows):
        status = 'pending-build-only (not counted)'
    elif kind == 'eh':
        status = 'catch funclet row (compared as part of its function)'
    elif key in COUNT_NOTES:
        status = 'exact support row, not counted: ' + COUNT_NOTES[key]
    elif a in REASON:
        status = REASON[a]
    elif any(r['address'] == key for r in main_rows):
        status = 'compiled, not exact'
    else:
        status = 'not reached'
    range_map.append('%s %d %s [%s]: %s' % (key, size, kind, unit_of(a) or '-', status))

range_rows = [x for x in FUNCS if RANGE[0] <= x[0] < RANGE[1]]
in_range_counted = [a for a in counted if RANGE[0] <= int(a, 16) < RANGE[1]]
in_range_other = [a for a, s, k in range_rows if a in OTHER]

receipt = {
    'class': 'App unit 650: ChatLine / ChatOutput and the ScoreHud leaderboard std instances of 00650000..00654000 '
             '(2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': all_flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS},
    'objects': {p.name: nb.sha(p) for p in objs.values()},
    'unit_map': {
        'gui/ChatOutput.cpp object ..0x00650e0f': 'ChatOutput rows (hud-family receipt), ChatLine() 0x00650560, '
            'ParseCommand 0x00650660, onEvent(ChatMessage) 0x00650cc0 (Listener<Players, ChatMessage> vtable 0084baf4 '
            'slot 0, ends at 00650e10). Starts at the util/Color.h statics 0064f6b0 (colorFromIndex8 0064f830 is '
            'called by ChatLine 0065061e).',
        'gui/ScoreHud.cpp object 0x00650e10..0x0065648f': 'std map / vector instances of the leaderboard types '
            '(first row 00650e10, a _Tree<Team*, map<string,int>> member), ScoreHud members counted by hud-family, '
            'leaderboard members counted by scorehud-leaderboard, render2d 00656430 last (vtable 0084bcb4 slot 24).',
        'library code': 'none in the range (the std instances are Roblox instantiations over ScoreHud.h types)',
        'excluded classes': 'none (no CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView rows)',
    },
    'range': '0x00650000..0x00654000',
    'range_functions': len(range_rows),
    'range_rows_counted_by_other_receipts': len(in_range_other),
    'range_rows_counted_here': len(in_range_counted),
    'range_map': range_map,
    'exact_function_rows': counted,
    'count_evidence': {a: COUNT_NOTES[a] for a in counted},
    'exact_support_rows': [hexed(a) + ': ' + COUNT_NOTES.get(a, 'support') for a in support],
    'rows': groups,
    'pending_build_only': [row_out(r, False) for r in pending_rows],
    'not_exact_rows': [{'address': hexed(r['address']), 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size']} for r in inexact],
    'funclet_seeding_ambiguous': UNSEEDED,
    'proposals': {
        'native-headers/Network/Player.h': 'add `bool getSuperSafeChat() const { return superSafeChat; }` (inline): '
            'ChatOutput::onEvent(ChatMessage) 00650cc0 reads Player +0x1b1 directly (00650d65 cmp byte ptr '
            '[edi + 0x1b1], 0); the member is private and the header has no getter. With it, 00650cc0 is exact.',
        'native-classes/ScoreHudLeaderboard2008.cpp / record_native_scorehud_leaderboard.py (ScoreHud owner)':
            'BoardData::AddField 00650ef0 is called only by BuildBoardData 00654d20 (no other rel32/DIR32 reference '
            'in .text) and lies in the ScoreHud object (00650e10..0065648f), not in an ICF-shared body: it can be '
            'counted with UNIT_RANGES starting at 00650e10.',
    },
    'rejected': {
        '00650cc0 `if (ParseCommand(event))`': 'test al, al / jne; the original compares cmp al, 1 / je '
                                              '(`== true`), otherwise identical (pending build)',
    },
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit650: %d counted exact rows (%d in range; range %d rows, %d counted elsewhere), %d support rows, '
      '%d pending-build-only, %d compiled rows not exact, %d ambiguous funclet seeds'
      % (len(counted), len(in_range_counted), len(range_rows), len(in_range_other), len(support), len(pending_rows),
         len(inexact), len(UNSEEDED)))
print('counted:', ' '.join(counted))
