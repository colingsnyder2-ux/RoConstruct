"""Record the unit map of the 2008-06 application range 00624000..00628000 (inactive; no native unit is built).

The whole range is Lua 5.1 standard-library code (recipes lua-5.1* in roc/libs.py; Roblox's App/lua-5.1.1 tree,
compiled as C++: the evidence names are C++-mangled, e.g. ?io_type@@YAHPAUlua_State@@@Z). In link order:
  * lstate.c tail: no row starts in 00624000..0062407f (the lstate.c row 00623f40, 319 B, ends at 0062407f);
  * liolib.c   00624080..0062526f (fileerror .. luaopen_io, f_lines, io_lines);
  * ltablib.c  00625270..00625b2f (foreachi .. sort, luaopen_table);
  * lmathlib.c 00625b30..006262df (math_abs .. math_randomseed, luaopen_math);
  * lstrlib.c  006262e0..00627e2f (str_len .. createmetatable, luaopen_string);
  * lbaselib.c 00627e30.. (luaB_print, luaB_tonumber; the file continues past 00628000 to luaopen_base 00628f50).
There is no RBX translation unit, no RTTI / vtable / static initializer and no Roblox-only template instantiation in
the range, so no row is recovered and none is counted (exact_function_rows is empty). Library code is never recovered
in native-classes.

Evidence (checked here against the original binary, not taken from the analog server labels): every row is compiled
from the unmodified upstream Lua 5.1.x file named by its block (VS2008 RTM 21022, /O2 /GS- /MD, some rows /fp:fast,
through roc.match.compile_text with the recipe's roc-lib pointer, the same path the server uses) and must be
relocation-masked byte-identical to one function of that object. Two rows, luaopen_math 00626280 and luaopen_string
00627e00, match only the stored generated units of the same files with Roblox's luaconf choices (LUA_COMPAT_MOD and
LUA_COMPAT_GFIND not defined: no math.mod / string.gfind alias, gfind_nodef kept). Where several compiled functions
are byte-identical under relocation masking (math_sin .. math_exp, io_open / io_popen, str_lower / str_upper,
math_deg / math_rad, math_fmod / math_pow), the chosen symbol is the unique candidate whose relocations all agree with
the original operands: imports by DLL export name, string literals and __real constants by their bytes, in-range
targets by the symbol this map assigns. Every other relocation target must resolve to one address per symbol across
all rows. The blocks must tile the range and every range row must be mapped. Rows other receipts count are listed
(top-level exact_function_rows rule, as in record_native_app_unit4d0_2008.py).
Writes work/2008-06/shared-layouts/app-unit624-working.json. NATIVE_APP_UNIT624_DISCOVER=1 prints candidates.
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
OUT = R / 'out/app-unit624'
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit624-working.json'
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT624_DISCOVER'))
RANGE = ('00624000', '00628000')
BASE = '/O2 /GS- /MD'
FAST = BASE + ' /fp:fast'

original = nb.Original()
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
lo, hi = int(RANGE[0], 16), int(RANGE[1], 16)
range_functions = sorted(a for a in FUNCS if lo <= a < hi)
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- blocks: [start, end) by row start, with the upstream Lua file each block is compiled from -------------------------
BLOCKS = [
    ('lua-liolib', 0x624000, 0x625270, 'liolib.c',
     'Lua 5.1 liolib.c (the lstate.c row 00623f40 runs to 0062407f; no row starts before 00624080)'),
    ('lua-ltablib', 0x625270, 0x625b30, 'ltablib.c', 'Lua 5.1 ltablib.c (foreachi .. sort, luaopen_table)'),
    ('lua-lmathlib', 0x625b30, 0x6262e0, 'lmathlib.c', 'Lua 5.1 lmathlib.c (math_abs .. luaopen_math)'),
    ('lua-lstrlib', 0x6262e0, 0x627e30, 'lstrlib.c', 'Lua 5.1 lstrlib.c (str_len .. luaopen_string)'),
    ('lua-lbaselib', 0x627e30, 0x628000, 'lbaselib.c',
     'Lua 5.1 lbaselib.c head (luaB_print, luaB_tonumber; continues past 00628000 to luaopen_base 00628f50)'),
]
GEN_MATH = 'roc_unit_9835aad68266b897.cpp'                 # lmathlib.c without the LUA_COMPAT_MOD alias
GEN_STRING = 'roc_espeon_luastringnogfind_92071a0221e9258a.cpp'   # lstrlib.c with LUA_COMPAT_GFIND undefined

# row -> (symbol, recipe, flags, file or generated unit, lang). Recipe variants are the first upstream 5.1.x files
# that reproduce the row; Roblox's tree is a 5.1.x mix, so single rows need 5.1 / 5.1.2 / 5.1.3 bodies.
L4 = 'lua-5.1.4-dll'
ROWS = {
    0x624080: ('_fileerror', L4, BASE, 'liolib.c'),
    0x6240c0: ('_io_type', L4, BASE, 'liolib.c'),
    0x624160: ('_io_pclose', L4, BASE, 'liolib.c'),
    0x6241e0: ('_io_fclose', L4, BASE, 'liolib.c'),
    0x624260: ('_aux_close', L4, BASE, 'liolib.c'),
    0x624290: ('_io_close', L4, BASE, 'liolib.c'),
    0x624310: ('_io_gc', 'lua-5.1-dll', BASE, 'liolib.c'),
    0x624360: ('_io_tostring', 'lua-5.1.2', BASE, 'liolib.c'),
    0x6243b0: ('_io_open', L4, BASE, 'liolib.c'),
    0x624480: ('_io_popen', L4, BASE, 'liolib.c'),
    0x624550: ('_io_tmpfile', L4, BASE, 'liolib.c'),
    0x6245d0: ('_g_iofile', L4, BASE, 'liolib.c'),
    0x6246a0: ('_io_input', L4, BASE, 'liolib.c'),
    0x6246c0: ('_io_output', L4, BASE, 'liolib.c'),
    0x6246e0: ('_read_number', L4, BASE, 'liolib.c'),
    0x624720: ('_read_line', L4, BASE, 'liolib.c'),
    0x6247f0: ('_read_chars', L4, BASE, 'liolib.c'),
    0x624890: ('_g_read', L4, BASE, 'liolib.c'),
    0x624a30: ('_io_read', L4, BASE, 'liolib.c'),
    0x624a80: ('_f_read', L4, BASE, 'liolib.c'),
    0x624ac0: ('_io_readline', L4, BASE, 'liolib.c'),
    0x624b70: ('_g_write', L4, BASE, 'liolib.c'),
    0x624c60: ('_io_write', L4, BASE, 'liolib.c'),
    0x624cb0: ('_f_write', L4, BASE, 'liolib.c'),
    0x624cf0: ('_f_seek', L4, BASE, 'liolib.c'),
    0x624da0: ('_f_setvbuf', L4, BASE, 'liolib.c'),
    0x624e50: ('_io_flush', L4, BASE, 'liolib.c'),
    0x624ef0: ('_f_flush', L4, BASE, 'liolib.c'),
    0x624f80: ('_luaopen_io', 'lua-5.1-dll', BASE, 'liolib.c'),
    0x625140: ('_f_lines', L4, BASE, 'liolib.c'),
    0x625190: ('_io_lines', L4, BASE, 'liolib.c'),
    0x625270: ('_foreachi', L4, BASE, 'ltablib.c'),
    0x625300: ('_foreach', L4, BASE, 'ltablib.c'),
    0x625390: ('_maxn', L4, BASE, 'ltablib.c'),
    0x625430: ('_getn', L4, BASE, 'ltablib.c'),
    0x625460: ('_setn', L4, BASE, 'ltablib.c'),
    0x625490: ('_tinsert', L4, BASE, 'ltablib.c'),
    0x625540: ('_tremove', 'lua-5.1.2', BASE, 'ltablib.c'),
    0x6255c0: ('_tconcat', 'lua-5.1.3', BASE, 'ltablib.c'),
    0x6256b0: ('_auxsort', L4, BASE, 'ltablib.c'),
    0x625ab0: ('_sort', L4, BASE, 'ltablib.c'),
    0x625b10: ('_luaopen_table', L4, BASE, 'ltablib.c'),
    0x625b30: ('_math_abs', L4, BASE, 'lmathlib.c'),
    0x625b60: ('_math_sin', L4, FAST, 'lmathlib.c'),
    0x625b90: ('_math_sinh', L4, BASE, 'lmathlib.c'),
    0x625bc0: ('_math_cos', L4, FAST, 'lmathlib.c'),
    0x625bf0: ('_math_cosh', L4, BASE, 'lmathlib.c'),
    0x625c20: ('_math_tan', L4, FAST, 'lmathlib.c'),
    0x625c50: ('_math_tanh', L4, BASE, 'lmathlib.c'),
    0x625c80: ('_math_asin', L4, BASE, 'lmathlib.c'),
    0x625cb0: ('_math_acos', L4, BASE, 'lmathlib.c'),
    0x625ce0: ('_math_atan', L4, FAST, 'lmathlib.c'),
    0x625d10: ('_math_atan2', L4, FAST, 'lmathlib.c'),
    0x625d50: ('_math_ceil', L4, BASE, 'lmathlib.c'),
    0x625d80: ('_math_floor', L4, BASE, 'lmathlib.c'),
    0x625db0: ('_math_fmod', L4, BASE, 'lmathlib.c'),
    0x625e00: ('_math_modf', L4, BASE, 'lmathlib.c'),
    0x625e50: ('_math_sqrt', L4, FAST, 'lmathlib.c'),
    0x625e80: ('_math_pow', L4, BASE, 'lmathlib.c'),
    0x625ed0: ('_math_log', L4, FAST, 'lmathlib.c'),
    0x625f00: ('_math_log10', L4, FAST, 'lmathlib.c'),
    0x625f30: ('_math_exp', L4, FAST, 'lmathlib.c'),
    0x625f70: ('_math_deg', L4, FAST, 'lmathlib.c'),
    0x625fa0: ('_math_rad', L4, BASE, 'lmathlib.c'),
    0x625fd0: ('_math_frexp', L4, BASE, 'lmathlib.c'),
    0x626010: ('_math_ldexp', L4, BASE, 'lmathlib.c'),
    0x626050: ('_math_min', L4, BASE, 'lmathlib.c'),
    0x6260d0: ('_math_max', L4, BASE, 'lmathlib.c'),
    0x626150: ('_math_random', L4, FAST, 'lmathlib.c'),
    0x626260: ('_math_randomseed', L4, BASE, 'lmathlib.c'),
    0x626280: ('?luaopen_math@@YAHPAUlua_State@@@Z', L4, BASE, GEN_MATH),
    0x6262e0: ('_str_len', L4, BASE, 'lstrlib.c'),
    0x626310: ('_str_sub', 'lua-5.1.3', BASE, 'lstrlib.c'),
    0x6263b0: ('_str_reverse', L4, BASE, 'lstrlib.c'),
    0x626450: ('_str_lower', L4, BASE, 'lstrlib.c'),
    0x6264f0: ('_str_upper', L4, BASE, 'lstrlib.c'),
    0x626590: ('_str_rep', L4, BASE, 'lstrlib.c'),
    0x626610: ('_str_byte', 'lua-5.1.3', BASE, 'lstrlib.c'),
    0x6266e0: ('_str_char', L4, BASE, 'lstrlib.c'),
    0x626780: ('_writer', L4, BASE, 'lstrlib.c'),
    0x6267a0: ('_str_dump', L4, BASE, 'lstrlib.c'),
    0x626810: ('_classend', L4, BASE, 'lstrlib.c'),
    0x626880: ('_match_class', L4, BASE, 'lstrlib.c'),
    0x6269a0: ('_matchbracketclass', L4, BASE, 'lstrlib.c'),
    0x626a40: ('_matchbalance', L4, BASE, 'lstrlib.c'),
    0x626ab0: ('_max_expand', L4, BASE, 'lstrlib.c'),
    0x626b50: ('_min_expand', L4, BASE, 'lstrlib.c'),
    0x626be0: ('_start_capture', L4, BASE, 'lstrlib.c'),
    0x626c30: ('_end_capture', L4, BASE, 'lstrlib.c'),
    0x626c90: ('_match_capture', L4, BASE, 'lstrlib.c'),
    0x626d20: ('_match', L4, BASE, 'lstrlib.c'),
    0x626ff0: ('_lmemfind', L4, BASE, 'lstrlib.c'),
    0x6270a0: ('_push_onecapture', L4, BASE, 'lstrlib.c'),
    0x627120: ('_push_captures', L4, BASE, 'lstrlib.c'),
    0x627170: ('_str_find_aux', 'lua-5.1-dll', BASE, 'lstrlib.c'),
    0x627320: ('_str_find', L4, BASE, 'lstrlib.c'),
    0x627330: ('_str_match', L4, BASE, 'lstrlib.c'),
    0x627340: ('_gmatch_aux', L4, BASE, 'lstrlib.c'),
    0x6274b0: ('_gmatch', L4, BASE, 'lstrlib.c'),
    0x6274f0: ('_gfind_nodef', L4, BASE, 'lstrlib.c'),
    0x627510: ('_add_s', L4, BASE, 'lstrlib.c'),
    0x6275f0: ('_add_value', 'lua-5.1.2', BASE, 'lstrlib.c'),
    0x627710: ('_str_gsub', 'lua-5.1.2', BASE, 'lstrlib.c'),
    0x627870: ('_addquoted', L4, BASE, 'lstrlib.c'),
    0x6279d0: ('_scanformat', 'lua-5.1-dll', BASE, 'lstrlib.c'),
    0x627ab0: ('_str_format', L4, BASE, 'lstrlib.c'),
    0x627da0: ('_createmetatable', L4, BASE, 'lstrlib.c'),
    0x627e00: ('?luaopen_string@@YAHPAUlua_State@@@Z', L4, BASE, GEN_STRING),
    0x627e30: ('_luaB_print', L4, BASE, 'lbaselib.c'),
    0x627f00: ('_luaB_tonumber', L4, BASE, 'lbaselib.c'),
}

NOTES = {
    'language': ('The evidence names are C++-mangled (Roblox built its Lua tree as C++, so lua_error throws; see the '
                 'ldo.c luaD_throw row mapped by script-app2008). The upstream .c files compiled as C reproduce every '
                 'row here relocation-masked; only the two luaopen rows are matched from C++ generated units.'),
    'version mix': ('No single upstream 5.1.x release reproduces every row: lua-5.1.4(-dll) covers most, io_gc / '
                    'luaopen_io / str_find_aux / scanformat need the 5.1 bodies, io_tostring / tremove / add_value / '
                    'str_gsub the 5.1.2 bodies and tconcat / str_sub / str_byte the 5.1.3 bodies. This is Roblox\'s '
                    'own 5.1.x library tree (App/lua-5.1.1 in later sources), not Roblox application code.'),
    'luaconf': ('luaopen_math 00626280 has no math.mod alias and luaopen_string 00627e00 no string.gfind alias, while '
                'gfind_nodef 006274f0 is linked: Roblox\'s luaconf.h leaves LUA_COMPAT_MOD and LUA_COMPAT_GFIND '
                'undefined. Both rows match the stored generated units %s / %s.' % (GEN_MATH, GEN_STRING)),
    'callers': ('No row of the range is called from outside it (checked below from functions.jsonl); the luaopen_* '
                'rows are reached only through the linit.c luaL_Reg table. No RBX class, RTTI, vtable or static '
                'initializer references the range.'),
}

for a in range_functions:
    assert a in ROWS, ('unmapped range row', hex(a))
assert set(ROWS) == set(range_functions), sorted(hex(a) for a in set(ROWS) - set(range_functions))
assert BLOCKS[0][1] == lo and BLOCKS[-1][2] == hi
for x, y in zip(BLOCKS, BLOCKS[1:]):
    assert x[2] == y[1], (x[0], y[0])
outside_callers = sorted({c for a in range_functions for c in FUNCS[a].get('callers', []) if not lo <= int(c, 16) < hi})
assert not outside_callers, outside_callers
# the row before the range is the lstate.c row that ends at 0062407f
assert 0x623f40 in FUNCS and 0x623f40 + FUNCS[0x623f40]['size'] == 0x624000 + 0x7f
# the evidence names agree with the chosen symbols (C++ names of the same functions)
for a, (symbol, *_rest) in ROWS.items():
    ev = names.get(a, '')
    plain = symbol[1:] if symbol.startswith('_') else symbol.split('@')[0].lstrip('?')
    if ev:
        assert ev.split('@')[0].lstrip('?') == plain, (hex(a), ev, symbol)


def block_of(address):
    hits = [b for b in BLOCKS if b[1] <= address < b[2]]
    assert len(hits) == 1, hex(address)
    return hits[0]


OBJECTS = {}


def compiled(recipe, flags, file):
    key = (recipe, flags, file)
    if key not in OBJECTS:
        lang = 'cpp' if file.endswith('.cpp') else 'c'
        text = '// roc-lang: %s\n// roc-cl: 21022\n// roc-flags: %s\n// roc-lib: %s %s\n' % (lang, flags, recipe, file)
        raw = match.compile_text('2008-06', text)
        stem = '%s_%s%s' % (recipe, Path(file).stem, flags.replace(' ', '').replace('/', '_').replace(':', ''))
        path = OUT / (stem.replace('.', '_') + '.obj')
        path.write_bytes(raw)
        OBJECTS[key] = (raw, text, path)
    return OBJECTS[key]


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


REG_TABLES = {'_iolib': 0, '_flib': 0, '_tab_funcs': 0, '_mathlib': 0, '_strlib': 0}
REG_RENAMED = set()
rows, addr_of, candidates_of = [], {}, {}
for address in range_functions:
    symbol, recipe, flags, file = ROWS[address]
    block = block_of(address)
    raw, text, path = compiled(recipe, flags, file)
    index = match._coff_data_index(raw)
    target, target_relocs, _ = match.target('2008-06', '%08x' % address)
    bodies = match.coff_functions(raw)
    exact = sorted({n for n, b, r in bodies if match.exact_match(target, target_relocs, b, r)})
    agreeing = []
    for name in exact:
        ok, _ = local_checks(raw, index, relocs(raw, index, name, address, target))
        if ok:
            agreeing.append(name)
    if DISCOVER:
        print('%08x' % address, symbol, 'exact:', exact, 'agreeing:', agreeing)
        continue
    assert agreeing == [symbol], ('%08x' % address, symbol, exact, agreeing)
    rows.append({'row': '%08x' % address, 'block': block[0], 'file': file, 'recipe': recipe, 'flags': flags,
                 'symbol': symbol, 'evidence_name': names.get(address, ''), 'size': len(target),
                 'masked_equivalents_rejected_by_targets': [s for s in exact if s != symbol]})
    assert addr_of.setdefault(symbol, address) == address
if DISCOVER:
    sys.exit(0)

# ---- relocation targets ----------------------------------------------------------------------------------------------
bound = {}
for row in rows:
    address = int(row['row'], 16)
    raw = compiled(row['recipe'], row['flags'], row['file'])[0]
    index = match._coff_data_index(raw)
    target, _, _ = match.target('2008-06', '%08x' % address)
    relocations = relocs(raw, index, row['symbol'], address, target)
    ok, checks = local_checks(raw, index, relocations)
    assert ok, (row['row'], checks)
    defined = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    for offset, kind, name, value in relocations:
        if nb.LOCAL_EH.match(name):
            checks.setdefault('local_eh', []).append(name)
            continue
        if name in checks:
            # imports by name, literals / constants by their bytes (without /GF the per-use string copies differ in
            # address, e.g. "FILE*" at 00844bc8 and 00844bdc, so they are checked by content, not by address)
            continue
        # one address per symbol (generated C++ units name the same functions with C++ mangling)
        m = re.match(r'\?([A-Za-z_]\w*)@@[YZ]', name)
        key = '_' + m.group(1) if m else name
        assert bound.setdefault(key, value) == value, ('one address per symbol', name, hex(value), hex(bound[key]))
        mapped = addr_of.get(name) or addr_of.get(key)
        if mapped is not None:
            assert mapped == value, (row['row'], name, hex(value), hex(mapped))
            checks[name] = 'in-range row %08x' % value
        elif name in defined and value in FUNCS:
            tcode, trel, _ = match.target('2008-06', '%08x' % value)
            body, refs = defined[name]
            assert match.exact_match(tcode, trel, body, refs), (row['row'], name, hex(value))
            checks[name] = 'out-of-range row %08x, body exact from the same object' % value
        else:
            assert not lo <= value < hi or value not in FUNCS, (row['row'], name, hex(value), 'unmapped in-range target')
            ev = names.get(value, '')
            if ev:
                # the evidence name of the target is the C++ name of the same function
                assert ev.split('@')[0].lstrip('?') == key.lstrip('_'), (row['row'], name, hex(value), ev)
                checks[name] = 'Lua row %08x (evidence name %s)' % (value, ev)
            elif value in FUNCS:
                checks[name] = 'function row %08x (one address per symbol)' % value
            else:
                assert not name.startswith('_lua') or name in ('_mathlib', '_strlib'), (row['row'], name, hex(value))
                checks[name] = 'data at %08x (one address per symbol)' % value
                if name in REG_TABLES:
                    REG_TABLES[name] = value
    row['targets'] = checks

# the luaL_Reg tables the luaopen rows register: every entry is a (name, function) pair whose function is a mapped row
# of this range (or, for the base library, a row past it); the per-table name prefix agrees with the mapped symbol
REG_PREFIX = {'_iolib': 'io_', '_flib': '', '_tab_funcs': '', '_mathlib': 'math_', '_strlib': ''}
reg_tables = {}
for table, value in sorted(REG_TABLES.items()):
    assert value, ('luaL_Reg table not referenced', table)
    entries, at = [], value
    while True:
        name_ptr, func = struct.unpack('<II', original.data(at, 8))
        if not name_ptr:
            assert not func
            break
        reg = original.string(name_ptr)
        assert lo <= func < hi and func in ROWS, (table, reg, hex(func))
        symbol = ROWS[func][0]
        if REG_PREFIX[table]:
            plain = symbol.lstrip('_') if not symbol.startswith('?') else symbol.split('@')[0].lstrip('?')
            assert plain == REG_PREFIX[table] + reg or (table, reg) in REG_RENAMED, (table, reg, symbol)
        entries.append('%s -> %s (row %08x)' % (reg, symbol, func))
        at += 8
    reg_tables['%s at %08x' % (table, value)] = entries
for row in rows:
    row['row'] = 'row ' + row['row']   # never a quoted bare address: nothing is counted here


# ---- counting rules (same as record_native_app_unit4d0_2008.py) ------------------------------------------------------
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
range_counted = ['%s counted by %s' % (a, ', '.join(sorted(set(v))))
                 for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]]

UNIT_MAP = {}
for name, start, end, file, what in BLOCKS:
    mine = [r for r in rows if r['block'] == name]
    UNIT_MAP['%s %08x..%08x' % (name, start, end - 1)] = {
        'unit': what, 'upstream_file': file, 'library': True, 'recovered': False, 'rows': len(mine),
        'bytes': sum(r['size'] for r in mine)}

exact_rows = []
receipt = {
    'class': 'unit map of the application range 00624000..00628000 (2008-06): Lua 5.1 standard library, inactive',
    'result': ('No RBX translation unit and no Roblox-only template instantiation in the range: every row is Lua 5.1 '
               'library code (liolib.c, ltablib.c, lmathlib.c, lstrlib.c, the lbaselib.c head), each reproduced '
               'byte-identically (relocation-masked, every target bound) from the upstream file or, for the two '
               'luaopen rows, from the stored generated unit with Roblox\'s luaconf choices. Nothing is recovered or '
               'counted here.'),
    'compiler': 'VS2008 RTM 21022',
    'library_recipes': sorted({'%s %s (%s)' % (r['recipe'], r['file'], r['flags']) for r in rows}),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'objects': {p.name: hashlib.sha256(raw).hexdigest() for raw, _, p in OBJECTS.values()},
    'unit_map': UNIT_MAP,
    'library_rows': rows,
    'lual_reg_tables': reg_tables,
    'notes': NOTES,
    'range_functions': len(range_functions),
    'range_bytes': sum(FUNCS[a]['size'] for a in range_functions),
    'range_rows_counted_by_other_receipts': range_counted,
    'bounds_evidence': 'none: every row start and size is reproduced by one compiled function',
    'exact_function_rows': exact_rows,
    'scope': 'Inactive map receipt. No native source, no counted row, no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit624: %d range rows (%d bytes) in %d blocks, all byte-identical to upstream Lua 5.1 library files, '
      '%d relocation targets bound; %d counted elsewhere; 0 counted here (Lua library range)'
      % (len(range_functions), receipt['range_bytes'], len(BLOCKS), len(bound), len(range_counted)))
