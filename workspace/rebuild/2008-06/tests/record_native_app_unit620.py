"""Record the unit map of the 2008-06 application range 00620000..00624000 (inactive; no native unit is built).

In link order (row starts; no row starts in 00620000..0062018f: FunctionScriptSlot::operator() 0061ff70, 543 B,
counted by lua-bridge2008, ends at 0062018f):
  * Lua signal bridge tail 00620190..0062096f (WaitScriptSlot, connectGeneric, TGenericSlotWrapper::execute,
    SignalBridge::wait / connect, Bridge<shared_ptr<SignalInstance>>::on_index) and the ICF-folded
    std::_Allocate<0x18-byte element> 00620910;
  * Lua YieldingThreads unit 00620970..006217ef (shared_ptr<ThreadRef> pieces, std::vector<WaitingThread>,
    YieldingThreads ctor / queueWaiter / resume);
  * Lua 5.1 library compiled by Roblox as C++ (C++-mangled evidence names): ldo.c 006217f0..006225ef,
    lobject.c 006225f0..00622c2f, ldebug.c 00622c30..00623b4f, lstate.c 00623b50.. (lua_newstate 00623f40 runs
    to 0062407f; liolib.c follows, mapped by app-unit624).
Every RBX row is counted by lua-bridge2008-working.json (top-level counting rule) or is a funclet / tail piece that
lua-bridge2008 compares as part of its parent row (each piece is checked here to tile the parent's whole compared
extent). The one RBX-range row that no receipt counts is the ICF-folded std::_Allocate<0x18-byte element> 00620910:
it is a std template instance whose callers are in three units (lua-bridge 00620f40 / 00621050, ScoreHud 00652e90,
00697510), so it is not a template only this unit references and is not recovered here (lua-bridge2008 and
scorehud-leaderboard compare it only as an instance / support row; see the proposal in the receipt).
The Lua rows are library code and are never recovered in native-classes. As map evidence, each Lua row that an
unmodified upstream file reproduces is compiled here (VS2008 RTM 21022, /O2 /GS- /MD, lua-5.1.1 or the
lua-5.1.2-rbx luaconf recipe, through roc.match.compile_text with the recipe's roc-lib pointer) and must be
relocation-masked byte-identical with every relocation target bound (imports by name, literals by bytes, in-range
rows by this map, others one address per symbol with agreeing evidence names). The remaining Lua rows are Roblox's
C++ modifications of ldo.c / lstate.c / lobject.c / ldebug.c (lua_exception thrown by luaD_throw, try/catch in
luaD_rawrunprotected, the RobloxExtraSpace luaconf hooks) and are mapped by evidence name, vtable RTTI and extent.
Writes work/2008-06/shared-layouts/app-unit620-working.json. NATIVE_APP_UNIT620_DISCOVER=1 prints candidates.
"""
import glob
import hashlib
import json
import os
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/app-unit620'
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit620-working.json'
BRIDGE = 'lua-bridge2008-working.json'
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT620_DISCOVER'))
RANGE = ('00620000', '00624000')
BASE = '/O2 /GS- /MD'

original = nb.Original()
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
lo, hi = int(RANGE[0], 16), int(RANGE[1], 16)
range_functions = sorted(a for a in FUNCS if lo <= a < hi)
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

BLOCKS = [
    ('rbx-lua-signal-bridge', 0x620000, 0x620970, False,
     'RBX Lua signal bridge tail (lua-bridge2008 LuaBridge2008Signal.cpp) and the ICF-folded _Allocate 00620910'),
    ('rbx-lua-yielding-threads', 0x620970, 0x6217f0, False,
     'RBX Lua YieldingThreads unit (lua-bridge2008 LuaBridge2008Yield.cpp)'),
    ('lua-ldo', 0x6217f0, 0x6225f0, True, 'Lua 5.1 ldo.c as C++ (luaD_seterrorobj .. luaD_protectedparser)'),
    ('lua-lobject', 0x6225f0, 0x622c30, True, 'Lua 5.1 lobject.c (luaO_int2fb .. luaO_chunkid)'),
    ('lua-ldebug', 0x622c30, 0x623b50, True, 'Lua 5.1 ldebug.c (currentline .. luaG_ordererror)'),
    ('lua-lstate', 0x623b50, 0x624000, True,
     'Lua 5.1 lstate.c (stack_init .. lua_newstate 00623f40, which runs to 0062407f)'),
]

# RBX rows that lua-bridge2008 compares as part of a parent row: piece -> (parent, whole compared extent in bytes)
PIECES = {
    0x620344: (0x620310, 134, 'TGenericSlotWrapper<FunctionScriptSlot>::execute tail'),
    0x620357: (0x620310, 134, 'TGenericSlotWrapper<FunctionScriptSlot>::execute catch funclet'),
    0x620422: (0x6203a0, 193, 'TGenericSlotWrapper<WaitScriptSlot>::execute catch funclet'),
    0x620a3e: (0x6209d0, 131, 'shared_count<ThreadRef*> catch funclet'),
    0x62102f: (0x620f40, 256, 'vector<WaitingThread>(const vector&) catch funclet'),
    0x621284: (0x621050, 723, 'vector<WaitingThread>::_Insert_n second catch funclet and copy-insert tail'),
}
FOLDED = {0x620910: ('std::_Allocate<0x18-byte element> (ICF-folded; lua-bridge2008 emits it as '
                     '_Allocate<WaitingThread>, scorehud-leaderboard as _Allocate<vector<string>>; both compare it '
                     'as an instance / support row, neither counts it)')}

L1, RBX2 = 'lua-5.1.1', 'lua-5.1.2-rbx'
# Lua rows an unmodified upstream file reproduces: row -> (symbol, recipe, file)
LUA_ROWS = {
    0x6217f0: ('_luaD_seterrorobj', L1, 'ldo.c'), 0x6219e0: ('_correctstack', L1, 'ldo.c'),
    0x621a70: ('_luaD_reallocstack', L1, 'ldo.c'), 0x621ad0: ('_luaD_reallocCI', L1, 'ldo.c'),
    0x621b50: ('_luaD_growstack', L1, 'ldo.c'), 0x621b80: ('_luaD_callhook', L1, 'ldo.c'),
    0x621cd0: ('_tryfuncTM', L1, 'ldo.c'), 0x621d60: ('_callrethooks', L1, 'ldo.c'),
    0x621db0: ('_luaD_poscall', L1, 'ldo.c'), 0x621e40: ('_resume_error', L1, 'ldo.c'),
    0x621ec0: ('_lua_yield', L1, 'ldo.c'), 0x621f00: ('_f_parser', L1, 'ldo.c'),
    0x621fe0: ('_resetstack', L1, 'ldo.c'), 0x622100: ('_growCI', L1, 'ldo.c'),
    0x622300: ('_luaD_call', L1, 'ldo.c'), 0x622380: ('_resume', L1, 'ldo.c'),
    0x622480: ('_luaD_pcall', L1, 'ldo.c'), 0x622580: ('_luaD_protectedparser', L1, 'ldo.c'),
    0x6225f0: ('_luaO_int2fb', L1, 'lobject.c'), 0x622620: ('_luaO_fb2int', L1, 'lobject.c'),
    0x622640: ('_luaO_log2', L1, 'lobject.c'), 0x622670: ('_luaO_rawequalObj', L1, 'lobject.c'),
    0x622780: ('_pushstr', L1, 'lobject.c'), 0x622ac0: ('_luaO_pushfstring', L1, 'lobject.c'),
    0x622c30: ('_currentline', L1, 'ldebug.c'), 0x622c80: ('_lua_sethook', L1, 'ldebug.c'),
    0x622cb0: ('_lua_gethook', L1, 'ldebug.c'), 0x622cc0: ('_lua_gethookmask', L1, 'ldebug.c'),
    0x622cd0: ('_lua_gethookcount', L1, 'ldebug.c'), 0x622ce0: ('_lua_getstack', L1, 'ldebug.c'),
    0x622d60: ('_findlocal', L1, 'ldebug.c'), 0x622dd0: ('_lua_getlocal', L1, 'ldebug.c'),
    0x622e20: ('_lua_setlocal', L1, 'ldebug.c'), 0x622e70: ('_funcinfo', L1, 'ldebug.c'),
    0x622ef0: ('_collectvalidlines', L1, 'ldebug.c'), 0x622f80: ('_luaG_checkopenop', L1, 'ldebug.c'),
    0x622fb0: ('_checkArgMode', L1, 'ldebug.c'), 0x623000: ('_symbexec', L1, 'ldebug.c'),
    0x623460: ('_luaG_checkcode', L1, 'ldebug.c'), 0x623480: ('_kname', L1, 'ldebug.c'),
    0x6234b0: ('_getobjname', L1, 'ldebug.c'), 0x623630: ('_getfuncname', L1, 'ldebug.c'),
    0x6236d0: ('_addinfo', L1, 'ldebug.c'), 0x623740: ('_luaG_errormsg', L1, 'ldebug.c'),
    0x6237d0: ('_luaG_runerror', L1, 'ldebug.c'), 0x623800: ('_auxgetinfo', L1, 'ldebug.c'),
    0x623a00: ('_luaG_typeerror', L1, 'ldebug.c'), 0x623a90: ('_luaG_concaterror', L1, 'ldebug.c'),
    0x623ab0: ('_luaG_aritherror', L1, 'ldebug.c'), 0x623af0: ('_luaG_ordererror', L1, 'ldebug.c'),
    0x623b50: ('_stack_init', L1, 'lstate.c'), 0x623bd0: ('_f_luaopen', L1, 'lstate.c'),
    0x623c50: ('_close_state', RBX2, 'lstate.c'), 0x623ce0: ('_luaE_newthread', RBX2, 'lstate.c'),
    0x623d80: ('_callallgcTM', L1, 'lstate.c'), 0x623f40: ('_lua_newstate', RBX2, 'lstate.c'),
}
# Lua rows not reproduced by lua-5.1 .. 5.1.4 or the -rbx luaconf recipes (/O2 /GS- /MD, C; 5.1.1 also as C++):
# Roblox's C++ modifications (lua_exception, try/catch, RobloxExtraSpace hooks) or bodies of another tree
LUA_MODIFIED = {
    0x621870: 'lua_exception::what (vtable 008447cc slot 1): lua_tolstring(L, -1, NULL) of the thrown state',
    0x621890: 'lua_exception::~lua_exception (stores vtable 008447cc; if the +0x14 flag is clear, clears +8 of the +0x10 object and lua_settop(L, -2))',
    0x621900: 'lua_exception scalar deleting destructor (vtable 008447cc slot 0)',
    0x621920: 'luaD_rawrunprotected with a C++ try block (EH frame; catch funclets 00621965 .. 006219a4)',
    0x621965: 'luaD_rawrunprotected catch funclet (sets the exception +0x14 handled flag, status -1 if 0)',
    0x621980: 'luaD_rawrunprotected catch funclet (luaG_runerror(L, e.what()) through vtable slot 1)',
    0x6219a4: 'luaD_rawrunprotected catch funclet (sets the +0x14 handled flag, status -1 if 0)',
    0x6219bf: 'luaD_rawrunprotected tail (restores L->errorJmp, returns status)',
    0x621c60: 'ldo.c adjust_varargs kept out of line with a register-argument convention (only caller luaD_precall)',
    0x622050: 'luaD_throw: throws lua_exception (vtable 008447cc) through _CxxThrowException',
    0x6220d0: 'lua_exception copy constructor (stores vtable 008447cc, takes ownership of the handled flag)',
    0x622140: 'luaD_precall calling the out-of-line adjust_varargs 00621c60',
    0x622400: 'lua_resume with the RobloxExtraSpace userstateresume hook',
    0x6226d0: 'luaO_str2d: not reproduced by any tried upstream 5.1.x file',
    0x6227d0: 'luaO_pushvfstring: not reproduced by any tried upstream 5.1.x file',
    0x622ae0: 'luaO_chunkid: not reproduced by any tried upstream 5.1.x file',
    0x623950: 'lua_getinfo: not reproduced by any tried upstream 5.1.x file',
    0x623d90: 'luaE_freethread with the RobloxExtraSpace userstatefree hook',
    0x623e30: 'lua_close with the RobloxExtraSpace userstateclose hook',
    0x623ec0: ('RobloxExtraSpace::construct(L, NULL) emitted out of line in lstate.c (luai_userstateopen: '
               'L-0xc, threadCount.reset(new int(1)) via shared_ptr<int>::reset 00612de0; only caller lua_newstate)'),
}

RBX_ROWS = [a for a in range_functions if a < 0x6217f0]
assert set(range_functions) == set(RBX_ROWS) | set(LUA_ROWS) | set(LUA_MODIFIED), sorted(
    hex(a) for a in set(range_functions) ^ (set(RBX_ROWS) | set(LUA_ROWS) | set(LUA_MODIFIED)))
assert not set(LUA_ROWS) & set(LUA_MODIFIED)
assert BLOCKS[0][1] == lo and BLOCKS[-1][2] == hi
for x, y in zip(BLOCKS, BLOCKS[1:]):
    assert x[2] == y[1], (x[0], y[0])
# the row before the range ends at 0062018f, the last row runs to 0062407f (liolib.c starts at 00624080)
assert 0x61ff70 + FUNCS[0x61ff70]['size'] == 0x620190 - 1 and min(range_functions) == 0x620190
assert 0x623f40 + FUNCS[0x623f40]['size'] == 0x62407f and 0x624080 in FUNCS


def block_of(address):
    hits = [b for b in BLOCKS if b[1] <= address < b[2]]
    assert len(hits) == 1, hex(address)
    return hits[0]


for a in RBX_ROWS:
    assert not block_of(a)[3]
for a in list(LUA_ROWS) + list(LUA_MODIFIED):
    assert block_of(a)[3]
# evidence names agree with the chosen / described names (C++ names of the same Lua functions)
for a, (symbol, _recipe, _file) in LUA_ROWS.items():
    ev = names.get(a, '')
    assert not ev or ev.split('@')[0].lstrip('?') == symbol[1:], (hex(a), ev, symbol)
for a, what in LUA_MODIFIED.items():
    ev = names.get(a, '')
    if ev:
        base = ev.split('@')[0].lstrip('?')
        assert what.startswith(base), (hex(a), ev, what)

# ---- counting rules (same as record_native_app_unit4d0_2008.py / app_unit624.py) -------------------------------------

def literal(raw, index, symbol):
    """Bytes of an object-defined data COMDAT (string literal or __real constant), or None."""
    sections, symbols, definitions, starts = index
    if symbol not in definitions:
        return None
    value, section = definitions[symbol]
    table = sections[section]
    following = [v for v in starts.get(section + 1, ()) if v > value]
    end = min(following) if following else table[3]
    return raw[table[4] + value:table[4] + end]


def relocs(raw, index, symbol, address, target_code):
    sections, symbols, definitions, _ = index
    start, section = definitions[symbol]
    table = sections[section]
    code = raw[table[4] + start:]
    out = []
    for i in range(table[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < len(target_code):
            continue
        name = symbols[sym][0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target_code, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target_code, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        out.append((offset, 'REL32' if kind == 20 else 'DIR32', name, value))
    return out


def local_checks(raw, index, relocations):
    """Checks that need no map: imports by name, literals / constants by bytes. Returns (ok, checks)."""
    checks = {}
    for offset, kind, name, value in relocations:
        hit = original.imported(value)
        if hit is not None:
            if hit[1] != nb.plain(name):
                return False, {name: 'import mismatch %s!%s' % hit}
            checks[name] = 'import %s!%s' % hit
            continue
        data = literal(raw, index, name)
        if data is not None and (name.startswith('??_C@') or name.startswith('__real@')):
            if name.startswith('??_C@'):
                text = data.split(b'\0')[0] + b'\0'
                if original.data(value, len(text)) != text:
                    return False, {name: 'literal mismatch at %08x' % value}
                checks[name] = 'string %r at %08x' % (text[:-1].decode('latin-1'), value)
            else:
                want = bytes.fromhex(name[7:])[::-1]
                if original.data(value, len(want)) != want:
                    return False, {name: 'constant mismatch at %08x' % value}
                checks[name] = 'constant %s at %08x' % (name[7:], value)
    return True, checks




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
        found = []
        if 'exact_function_rows' in data:
            found = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            found = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            found = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        found.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(found, dict):
            found = list(found)
        for r in found:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
bridge_receipt = (ROOT / 'work/2008-06/shared-layouts' / BRIDGE).read_text()

# ---- RBX rows: counted by lua-bridge2008, or pieces it compares inside a counted parent, or the folded instance ------
rbx_map = []
for a in RBX_ROWS:
    who = sorted(set(elsewhere.get('%08x' % a, [])))
    if a in PIECES:
        parent, whole, what = PIECES[a]
        assert not who, (hex(a), who)
        assert BRIDGE in elsewhere.get('%08x' % parent, []), hex(parent)
        assert '%08x' % a in bridge_receipt, ('piece not described by lua-bridge2008', hex(a))
        rbx_map.append('row %08x: %s, compared by %s as part of its counted parent %08x (%d B whole)'
                       % (a, what, BRIDGE, parent, whole))
    elif a in FOLDED:
        assert not who, (hex(a), who)
        rbx_map.append('row %08x: %s; counted by no receipt; not recovered here (callers in three units)'
                       % (a, FOLDED[a]))
    else:
        assert who == [BRIDGE], (hex(a), who)
        rbx_map.append('%08x counted by %s (%s)' % (a, BRIDGE, names.get(a, '') or 'no evidence name'))
# each parent and its pieces tile the whole extent lua-bridge2008 compares
for parent in sorted({p for p, _w, _x in PIECES.values()}):
    whole = {w for p, w, _x in PIECES.values() if p == parent}.pop()
    at = parent + FUNCS[parent]['size']
    for piece in sorted(a for a, (p, _w, _x) in PIECES.items() if p == parent):
        assert piece == at, (hex(parent), hex(piece), hex(at))
        at = piece + FUNCS[piece]['size']
    assert at == parent + whole, (hex(parent), hex(at), whole)
# the folded _Allocate: callers outside this unit (not a template only this unit references)
fold_callers = sorted(FUNCS[0x620910].get('callers', []))
assert any(not 0x620190 <= int(c, 16) < 0x6217f0 for c in fold_callers), fold_callers

# ---- Lua rows reproduced from the upstream files ----------------------------------------------------------------------
OBJECTS = {}


def compiled(recipe, file):
    key = (recipe, file)
    if key not in OBJECTS:
        text = '// roc-lang: c\n// roc-cl: 21022\n// roc-flags: %s\n// roc-lib: %s %s\n' % (BASE, recipe, file)
        raw = match.compile_text('2008-06', text)
        path = OUT / ('%s_%s.obj' % (recipe.replace('.', '_'), Path(file).stem))
        path.write_bytes(raw)
        OBJECTS[key] = (raw, path)
    return OBJECTS[key]


addr_of = {symbol: a for a, (symbol, _r, _f) in LUA_ROWS.items()}
lua_rows, bound = [], {}
for address in sorted(LUA_ROWS):
    symbol, recipe, file = LUA_ROWS[address]
    raw, _path = compiled(recipe, file)
    index = match._coff_data_index(raw)
    target, target_relocs, _ = match.target('2008-06', '%08x' % address)
    bodies = match.coff_functions(raw)
    exact = sorted({n for n, b, r in bodies if match.exact_match(target, target_relocs, b, r)})
    agreeing = [n for n in exact if local_checks(raw, index, relocs(raw, index, n, address, target))[0]]
    if DISCOVER:
        print('%08x' % address, symbol, 'exact:', exact, 'agreeing:', agreeing)
        continue
    assert symbol in agreeing, ('%08x' % address, symbol, exact, agreeing)
    relocations = relocs(raw, index, symbol, address, target)
    ok, checks = local_checks(raw, index, relocations)
    assert ok, ('%08x' % address, checks)
    defined = {n: (b, r) for n, b, r in bodies}
    for offset, kind, name, value in relocations:
        if nb.LOCAL_EH.match(name):
            checks.setdefault('local_eh', []).append(name)
            continue
        if name in checks:
            continue
        assert bound.setdefault(name, value) == value, ('one address per symbol', name, hex(value), hex(bound[name]))
        if name in addr_of:
            assert addr_of[name] == value, ('%08x' % address, name, hex(value))
            checks[name] = 'mapped row %08x' % value
            continue
        assert not (lo <= value < hi and value in FUNCS and value not in LUA_MODIFIED), (
            '%08x' % address, name, hex(value), 'unmapped in-range target')
        ev = names.get(value, '')
        if ev:
            assert ev.split('@')[0].lstrip('?') == nb.plain(name), ('%08x' % address, name, hex(value), ev)
            checks[name] = 'Lua row %08x (evidence name %s)' % (value, ev)
        elif value in LUA_MODIFIED:
            checks[name] = 'in-range Lua row %08x (%s)' % (value, LUA_MODIFIED[value])
        elif name in defined and value in FUNCS:
            tcode, trel, _ = match.target('2008-06', '%08x' % value)
            assert match.exact_match(tcode, trel, *defined[name]), ('%08x' % address, name, hex(value))
            checks[name] = 'row %08x, body exact from the same object' % value
        elif value in FUNCS:
            checks[name] = 'function row %08x (one address per symbol)' % value
        else:
            own = literal(raw, index, name) if name in index[2] and name not in defined else None
            if own:
                # a static table the object defines (e.g. luaO_log2's log_2): its bytes must equal the image
                assert original.data(value, len(own)) == own, ('%08x' % address, name, hex(value))
                checks[name] = 'own static data at %08x (%d bytes equal)' % (value, len(own))
            else:
                checks[name] = 'external data at %08x (one address per symbol)' % value
    lua_rows.append({'row': 'row %08x' % address, 'block': block_of(address)[0], 'recipe': recipe, 'file': file,
                     'flags': BASE, 'symbol': symbol, 'evidence_name': names.get(address, ''),
                     'size': len(target), 'masked_equivalents': [n for n in exact if n != symbol],
                     'targets': checks})
if DISCOVER:
    sys.exit(0)
# lua_newstate calls the out-of-line RobloxExtraSpace::construct row through the rbx luaconf hook symbol
assert bound.get('_rbx_luai_userstateopen') == 0x623ec0, bound.get('_rbx_luai_userstateopen')

# ---- Lua rows Roblox modified: structure checks ------------------------------------------------------------------------
VT = 0x8447cc
assert original.vtable_class(VT)[0] == '.?AVlua_exception@@', original.vtable_class(VT)
assert struct.unpack('<II', original.data(VT, 8)) == (0x621900, 0x621870)
for a in (0x621890, 0x6220d0, 0x622050):
    assert struct.pack('<I', VT) in match.target('2008-06', '%08x' % a)[0], hex(a)
at = 0x621920
for a in (0x621920, 0x621965, 0x621980, 0x6219a4, 0x6219bf):
    assert a == at, (hex(a), hex(at))
    at = a + FUNCS[a]['size']
assert at <= 0x6219e0
assert sorted(FUNCS[0x621c60].get('callers', [])) == ['00622140']
assert sorted(FUNCS[0x623ec0].get('callers', [])) == ['00623f40']
assert '00612de0' in FUNCS[0x623ec0].get('call_targets', [])
modified_rows = ['row %08x (%d B): %s%s' % (a, FUNCS[a]['size'], what,
                                             ' [evidence name %s]' % names[a] if names.get(a) else '')
                 for a, what in sorted(LUA_MODIFIED.items())]

lua_counted = sorted(a for a in elsewhere if lo <= int(a, 16) < hi and int(a, 16) >= 0x6217f0)
assert not lua_counted, lua_counted
range_counted = ['%s counted by %s' % (a, ', '.join(sorted(set(v))))
                 for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]]

UNIT_MAP = {}
for name, start, end, library, what in BLOCKS:
    mine = [a for a in range_functions if start <= a < end]
    UNIT_MAP['%s %08x..%08x' % (name, start, end - 1)] = {
        'unit': what, 'library': library, 'recovered': False, 'rows': len(mine),
        'bytes': sum(FUNCS[a]['size'] for a in mine),
        'counted_by_other_receipts': sum(1 for a in mine if '%08x' % a in elsewhere)}

receipt = {
    'class': 'unit map of the application range 00620000..00624000 (2008-06): Lua bridge tail and Lua 5.1 core, inactive',
    'result': ('No row is recovered or counted here. The RBX rows 00620190..006217e2 are the lua-bridge2008 signal '
               'bridge tail and YieldingThreads unit: %d are counted by %s, %d are funclet / tail pieces it compares '
               'inside counted parents, and the ICF-folded std::_Allocate<0x18-byte element> is counted by no receipt '
               '(std template instance with callers in three units: not recovered). The other %d rows are Lua 5.1 '
               'library code compiled by Roblox as C++ (ldo, lobject, ldebug, lstate): %d are reproduced '
               'byte-identically from upstream files with every target bound, %d are Roblox C++ modifications '
               'mapped by evidence name, RTTI and extent.'
               % (sum(1 for a in RBX_ROWS if a not in PIECES and a not in FOLDED), BRIDGE, len(PIECES),
                  len(LUA_ROWS) + len(LUA_MODIFIED), len(LUA_ROWS), len(LUA_MODIFIED))),
    'compiler': 'VS2008 RTM 21022',
    'library_recipes': sorted({'%s %s (%s)' % (r['recipe'], r['file'], r['flags']) for r in lua_rows}),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'objects': {p.name: hashlib.sha256(raw).hexdigest() for raw, p in OBJECTS.values()},
    'unit_map': UNIT_MAP,
    'rbx_rows': rbx_map,
    'library_rows_reproduced': lua_rows,
    'library_rows_modified': modified_rows,
    'lua_exception_vtable': 'vtable 008447cc: RTTI .?AVlua_exception@@ (bases lua_exception, std::exception); '
                            'slot 0 scalar deleting dtor row 00621900, slot 1 what row 00621870',
    'range_functions': len(range_functions),
    'range_bytes': sum(FUNCS[a]['size'] for a in range_functions),
    'range_rows_counted_by_other_receipts': range_counted,
    'bounds_evidence': ('No new extent evidence. The piece rows tile the whole extents lua-bridge2008 already records '
                        'as BOUNDS evidence (00620310 134 B, 006203a0 193 B, 006209d0 131 B, 00620f40 256 B, '
                        '00621050 723 B); luaD_rawrunprotected row 00621920 with its catch funclets and tail tiles '
                        '00621920..006219db, not reproduced (library).'),
    'proposals': [
        ('Owner of lua-bridge2008 (record_native_lua_bridge2008.py): its left note says the folded _Allocate row '
         '00620910 is counted by scorehud-leaderboard-working.json, but that receipt lists it only in '
         'exact_support_rows (not exact_function_rows), so no receipt counts it. Either correct the note, or, if '
         'maintainers accept an ICF-folded std instance whose first COMDAT sits in the YieldingThreads unit '
         '(callers 00620f40 / 00621050 here, 00652e90 and 00697510 elsewhere), count it once in lua-bridge2008, '
         'which already emits it as _Allocate<WaitingThread> with bytes and targets verified.'),
    ],
    'exact_function_rows': [],
    'scope': 'Inactive map receipt. No native source, no header, no counted row, no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit620: %d range rows (%d bytes) in %d blocks; RBX %d rows (%d counted by %s, %d pieces, 1 folded '
      'instance uncounted); Lua %d rows (%d reproduced from upstream, %d targets bound; %d Roblox-modified); '
      '0 counted here' % (len(range_functions), receipt['range_bytes'], len(BLOCKS), len(RBX_ROWS),
                          len(RBX_ROWS) - len(PIECES) - len(FOLDED), BRIDGE, len(PIECES),
                          len(LUA_ROWS) + len(LUA_MODIFIED), len(LUA_ROWS), len(bound), len(LUA_MODIFIED)))
