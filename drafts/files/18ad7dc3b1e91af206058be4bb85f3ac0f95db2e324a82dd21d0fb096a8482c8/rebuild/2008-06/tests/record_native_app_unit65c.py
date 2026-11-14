"""Record the unit map of the 2008-06 application range 0065c000..00660000 (inactive; no native unit is built).

The range holds two translation-unit groups:
  * Lua 5.1 library code (Roblox's lua-5.1.1 tree, built as C++: the evidence names are C++-mangled Lua symbols such
    as ?luaV_execute@@YAXPAUlua_State@@H@Z): the tail of lgc.c (markmt .. luaC_linkupval), then ltm.c, lvm.c, ltable.c,
    lstring.c, lfunc.c, lzio.c and ldump.c (DumpString .. luaU_dump). lgc.c starts below the range (reallymarkobject
    0x0065b5d0, mapped by app-unit658-working.json);
  * the head of RBX v8kernel/Cofm.cpp (Cofm(Body*), getMass, updateIfDirty), which runs past 00660000 and is already
    counted by body-primitive2008-working.json.
Library code is never recovered in native-classes and the only RBX rows are already counted elsewhere, so nothing is
built here and exact_function_rows is empty.

Boundary evidence, all checked against the original binary bytes and the read-only Roblox Lua tree
tools/rbxgs/Client/App/lua-5.1.1/src (function definitions parsed from the .c files of the 5.1 library list):
  * every Lua row carries a Lua evidence name (offline/evidence.json) whose base name is defined in exactly one Lua
    library .c file; the rows form contiguous per-file blocks in the order lgc, ltm, lvm, ltable, lstring, lfunc,
    lzio, ldump (file order inside the block differs from the source order, as MSVC emits it);
  * every string a Lua row points to (DIR32 operand) occurs as a literal in the same .c file;
  * every direct call / jmp target of a Lua row is a Lua-named row (in this range or outside it: ldo/lobject/ldebug/
    lmem/lundump) or an MSVCR90 IAT thunk (memcpy, floor, _CIpow); no DIR32 operand is an RBX RTTI vtable and every
    import is an MSVCR90 export;
  * the Cofm rows carry the RBX Cofm evidence names, call only Cofm / Body / Math / G3D rows, and are counted by
    body-primitive2008-working.json.
Rows other receipts count are listed (top-level exact_function_rows rule, as in record_native_app_unit474_2008.py).
Addresses of rows not counted here are written as 0x-prefixed or 'ADDR counted by RECEIPT' text, never as quoted bare
addresses (local_backpack / viewnew_brick_build / viewnew_part_mesh read any quoted bare address in a receipt as
counted there).
Writes work/2008-06/shared-layouts/app-unit65c-working.json.
"""
import glob
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
import capstone  # noqa: E402
from roc import match  # noqa: E402

CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

R = ROOT / 'rebuild/2008-06'
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit65c-working.json'
LO, HI = 0x65c000, 0x660000
LUA_SRC = ROOT / 'tools/rbxgs/Client/App/lua-5.1.1/src'
# the Lua 5.1 library file list (roc/libs.py _LUA)
LUA_FILES = ('lapi lcode ldebug ldo ldump lfunc lgc llex lmem lobject lopcodes lparser lstate lstring ltable ltm '
             'lundump lvm lzio lauxlib lbaselib ldblib liolib lmathlib loslib ltablib lstrlib loadlib linit').split()
BLOCK_ORDER = ['lgc', 'ltm', 'lvm', 'ltable', 'lstring', 'lfunc', 'lzio', 'ldump']
H = lambda a: '0x%08x' % a

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        row = json.loads(line)
        FUNCS[int(row['addr'], 16)] = row
rows = sorted(a for a in FUNCS if LO <= a < HI)
body = lambda a: original.data(a, FUNCS[a]['size'])


def dwords(a):
    """DIR32 operands of the row: the image base-relocation offsets inside the row's bytes."""
    code, relocs, _ = match.target('2008-06', '%08x' % a)
    return {struct.unpack_from('<I', code, i)[0] for i in relocs if i + 4 <= len(code)}


def rel32_targets(a):
    """Direct call / jmp targets outside the row, decoded with capstone from the original bytes."""
    out = set()
    end = a + FUNCS[a]['size']
    for ins in CS.disasm(body(a), a):
        if ins.mnemonic in ('call', 'jmp') and ins.op_str.startswith('0x'):
            v = int(ins.op_str, 16)
            if not a <= v < end:
                out.add(v)
    return out


def string_at(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        raw = original.data(v, 256)
    except Exception:
        return None
    end = raw.find(b'\0')
    if end <= 0 or not all(32 <= c < 127 or c in (9, 10) for c in raw[:end]):
        return None
    return raw[:end].decode('latin-1')


def rtti_of(v):
    if not 0x7c0000 <= v < 0x980000:
        return None
    try:
        name, offset = original.vtable_class(v)
    except Exception:
        return None
    return name if name.startswith('.?A') else None


def base_name(sym):
    m = re.match(r'\?(\w+)@@', sym)
    return m.group(1) if m else None


# ---- Lua function definitions from the Roblox lua-5.1.1 tree ----------------------------------------------------------
DEF = re.compile(r'^(?!typedef|return|#|extern)[A-Za-z_][\w \t\*]*?\b(\w+)\s*\(([^;]*)$', re.M)
lua_text = {f: (LUA_SRC / (f + '.c')).read_text(errors='replace') for f in LUA_FILES}
LUACONF = (LUA_SRC / 'luaconf.h').read_text(errors='replace')   # LUAI_NUMFMT "%.14g" (lua_number2str)
defined = {}
for f, text in lua_text.items():
    for m in DEF.finditer(text):
        defined.setdefault(m.group(1), set()).add(f)


def lua_file(a):
    """The Lua library file defining the row's evidence name (None when the row is not a Lua symbol)."""
    sym = names.get(a, '')
    b = base_name(sym)
    if not b or '@RBX@@' in sym or '@G3D@@' in sym:
        return None
    files = defined.get(b, set())
    assert len(files) <= 1, (hex(a), b, files)
    return next(iter(files)) if files else None


def is_crt_thunk(v):
    """MSVCR90 IAT thunk: `jmp dword ptr [IAT]` whose slot is an msvcr90.dll import."""
    if v not in FUNCS or FUNCS[v]['size'] != 6:
        return None
    raw = original.data(v, 6)
    if raw[:2] != b'\xff\x25':
        return None
    slot = struct.unpack_from('<I', raw, 2)[0]
    imp = original.imports.get(slot)
    return imp[2] if imp and imp[0].lower() == 'msvcr90.dll' else None


# ---- boundary and per-row evidence ------------------------------------------------------------------------------------
for a, b in zip(rows, rows[1:]):
    assert a + FUNCS[a]['size'] <= b, hex(a)
prev = max(a for a in FUNCS if a < LO)
assert prev == 0x65bfe0 and lua_file(prev) == 'lgc' and prev + FUNCS[prev]['size'] <= rows[0], hex(prev)
lgc_start = 0x65b5d0
assert base_name(names[lgc_start]) == 'reallymarkobject' and lua_file(lgc_start) == 'lgc'

proof = {}


def prove(a, kind, **kw):
    proof.setdefault(a, []).append(dict(kind=kind, **kw))


lua_rows = [a for a in rows if lua_file(a)]
other_rows = [a for a in rows if a not in lua_rows]
COFM = {0x65fef0: '??0Cofm@RBX@@QAE@PAVBody@1@@Z', 0x65ff10: '?getMass@Cofm@RBX@@QBE?BMXZ',
        0x65ff20: '?updateIfDirty@Cofm@RBX@@ABEXXZ'}
assert other_rows == sorted(COFM), [H(a) for a in other_rows]
for a, sym in COFM.items():
    assert names.get(a) == sym, (hex(a), names.get(a))
last = rows[-1]
assert last == 0x65ff20 and last + FUNCS[last]['size'] > HI
assert lua_rows[-1] < min(COFM) and lua_rows[-1] + FUNCS[lua_rows[-1]]['size'] <= min(COFM)

# contiguous per-file blocks in the expected order
blocks = []
for a in lua_rows:
    f = lua_file(a)
    if not blocks or blocks[-1][0] != f:
        blocks.append([f, a, a])
    blocks[-1][2] = a
assert [b[0] for b in blocks] == BLOCK_ORDER, [b[0] for b in blocks]

crt_calls = {}
lua_outside = {}
for a in lua_rows:
    f = lua_file(a)
    prove(a, 'evidence-name', symbol=names[a], defined_in='lua-5.1.1/src/%s.c' % f)
    strs = sorted({s for s in (string_at(v) for v in dwords(a)) if s})
    where = {}
    for s in strs:
        lit = '"%s"' % s.replace('\n', '\\n')
        # LUA_QL("for") " initial value ...": the quoted words come from the LUA_QL macro, the rest is literal
        frags = [x for x in re.split(r"'[^']*'", s.replace('\n', '\\n')) if x.strip()]
        if lit in lua_text[f] or s in lua_text[f] or ("'" in s and frags and all(x in lua_text[f] for x in frags)):
            where[s] = '%s.c' % f
        else:
            assert lit in LUACONF, (hex(a), s, f)
            where[s] = 'luaconf.h'
    if strs:
        prove(a, 'lua-string', strings=strs[:4], found_in=sorted(set(where.values())))
    for v in sorted(rel32_targets(a)):
        crt = is_crt_thunk(v)
        if crt:
            crt_calls.setdefault(crt, set()).add(a)
            continue
        g = lua_file(v)
        assert g, (hex(a), hex(v), names.get(v))
        if not LO <= v < HI:
            lua_outside.setdefault('%s %s' % (base_name(names[v]), g), set()).add(a)
    for v in dwords(a):
        n = rtti_of(v)
        assert not n, (hex(a), hex(v), n)
        if v in original.imports:
            assert original.imports[v][0].lower() == 'msvcr90.dll', (hex(a), original.imports[v])
callees = {}
for a in lua_rows:
    t = sorted(v for v in rel32_targets(a) if lua_file(v))
    if t:
        prove(a, 'lua-callees', callees=['%s %s' % (H(v), base_name(names[v])) for v in t[:6]])
missing = [H(a) for a in lua_rows if len(proof.get(a, [])) < 1]
assert not missing, missing
# every Lua row is reached from or reaches another Lua row (no stray non-Lua row hidden under a Lua name)
callers_of = {}
for a in lua_rows:
    for v in rel32_targets(a):
        callers_of.setdefault(v, set()).add(a)
isolated = [H(a) for a in lua_rows
            if not any(lua_file(v) for v in rel32_targets(a)) and not callers_of.get(a)
            and not any(lua_file(int(c, 16)) for c in FUNCS[a].get('callers', []))]
for a in rows:
    if a in COFM:
        prove(a, 'evidence-name', symbol=COFM[a], unit='RBX v8kernel/Cofm.cpp')
        for v in rel32_targets(a):
            sym = names.get(v, '')
            assert v in COFM or '@RBX@@' in sym or not sym, (hex(a), hex(v), sym)


# ---- counting rules (same as record_native_app_unit474_2008.py) -------------------------------------------------------
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
                out.setdefault(int(m.group(1), 16), set()).add(Path(path).name)
    return out


elsewhere = counted_elsewhere()
range_counted = {a: sorted(v) for a, v in sorted(elsewhere.items()) if LO <= a < HI}
assert set(range_counted) == set(COFM) and all(v == ['body-primitive2008-working.json'] for v in range_counted.values()), \
    {H(a): v for a, v in range_counted.items()}

UNIT_MAP = {}
for f, first, lastf in blocks:
    k = 'lua-%s %s..%s' % (f, H(first), H(lastf + FUNCS[lastf]['size'] - 1))
    UNIT_MAP[k] = {
        'rows': sum(1 for a in lua_rows if lua_file(a) == f),
        'unit': 'Lua 5.1 %s.c (Roblox lua-5.1.1 tree, built as C++)%s' % (
            f, '; starts below the range at reallymarkobject 0x0065b5d0 (mapped by app-unit658-working.json)'
            if f == 'lgc' else ''),
        'first': '%s %s' % (H(first), base_name(names[first])),
        'last': '%s %s' % (H(lastf), base_name(names[lastf])),
        'library': True, 'recovered': False,
    }
UNIT_MAP['cofm %s..' % H(min(COFM))] = {
    'rows': len(COFM),
    'unit': 'RBX v8kernel/Cofm.cpp (runs past 0x00660000: getCofmInBody 0x00660160 ...)',
    'library': False, 'recovered': False,
    'counted_elsewhere': ['%s counted by %s' % ('%08x' % a, ', '.join(v)) for a, v in range_counted.items()],
}
row_map = [{'row': H(a), 'size': FUNCS[a]['size'],
            'unit': ('Lua 5.1 %s.c (library)' % lua_file(a)) if a in lua_rows else 'RBX Cofm.cpp',
            'name': base_name(names[a]) if a in lua_rows else COFM[a],
            'evidence': proof[a],
            'counted_by': range_counted.get(a, [])} for a in rows]
NOTES = {
    'analog-labels': ('The analog labels RBX::BallBallContact (0x0065c020..0x0065d100) and seg_00650000 are not units: '
                      'every row up to 0x0065fee2 is Lua library code by evidence name, string and call graph.'),
    'no-rbx-unit': ('No RBX class, Reflection descriptor, static initializer or Roblox-only template instantiation lies '
                    'in the range besides the counted Cofm.cpp head. The Lua rows call only Lua internals (in range and '
                    'ldo/lobject/ldebug/lmem/lundump outside it) and MSVCR90 thunks.'),
    'lua-callees-outside-range': sorted(lua_outside),
    'crt-thunks': {k: len(v) for k, v in sorted(crt_calls.items())},
    'rows-without-lua-call-edge': isolated,
}
exact_rows = []
receipt = {
    'class': 'unit map of the application range 0065c000..00660000 (2008-06): Lua 5.1 library + Cofm.cpp head, inactive',
    'result': ('No RBX translation unit to recover: %d rows are Lua 5.1 library code (lgc.c tail, ltm.c, lvm.c, '
               'ltable.c, lstring.c, lfunc.c, lzio.c, ldump.c) and the %d Cofm.cpp rows are already counted by '
               'body-primitive2008-working.json. Nothing is recovered or counted here.' % (len(lua_rows), len(COFM))),
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'unit_map': UNIT_MAP,
    'row_map': row_map,
    'notes': NOTES,
    'range_functions': len(rows),
    'range_bytes': sum(FUNCS[a]['size'] for a in rows),
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % ('%08x' % a, ', '.join(v))
                                             for a, v in range_counted.items()],
    'exact_function_rows': exact_rows,
    'library_recipes': ['lua-5.1 .. lua-5.1.4, lua-5.1.2-rbx (roc/libs.py)'],
    'scope': 'Inactive map receipt. No native source, no counted row, no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = sorted(set(re.findall(r'"([0-9a-f]{8})"', text)))
assert not bare, bare   # never a quoted bare address of a row not counted here
RECEIPT.write_text(text)
print('PASS app-unit65c: %d range rows (%d bytes): %d Lua 5.1 library rows in %d file blocks (%s), %d Cofm rows '
      'counted elsewhere (%s); CRT thunks %s; 0 counted here'
      % (len(rows), receipt['range_bytes'], len(lua_rows), len(blocks), ' '.join(b[0] for b in blocks), len(COFM),
         ' '.join('%08x' % a for a in range_counted), sorted(crt_calls)))
