"""Verify the inactive 2008-06 native rows of the application range 005f8000..005fc000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as text).

Unit map summary (details in UNIT_MAP below):
  * 005f802f..005f943f: the tail of the WinHttp transport unit of util/Http.cpp (its boost.iostreams instantiations
    start in the app-unit5f0 range at 005f2030). Built here from native-classes/AppUnit5F8WinHttp.cpp.
  * 005f9440..005fa60f: the WinINet transport unit of util/Http.cpp. Built here from
    native-classes/AppUnit5F8WinInet.cpp. The two transports cannot share a unit: <winhttp.h> and <wininet.h>
    redefine each other's types (C2371), and each unit has its own copy of the handle destructor and request source.
  * 005fa610..005fb70f: v8kernel/Kernel.cpp (kernel-stages owner; Kernel2008.h); not built here.
  * 005fb710..: LocalBackpack (local-backpack owner); not built here.

Builds (document-swap flags, VS2008 RTM 21022, no extra flags): the new header native-headers/AppUnit5F8/
HttpTransport.h declares the 2008 RBX::Http (a new path: it shadows no donor header).

Row matching: every compiled function (and, for owners with an embedded catch block, each piece between the
compiler's own __catch$ funclet labels: a proven funclet split, never a truncation) is compared with the rows of its
unit. A row is counted only when its piece is relocation-masked exact AND every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, string literals by their bytes,
constants by bytes, RTTI descriptors / vtables by the original RTTI, functions by a counted row of this receipt or
by an equal compiled body at that address (out-of-scope COMDAT instances; one address per symbol), the remaining
externals by evidence name or call-site identification, and statics by one address per symbol. Virtual-function
symbols are bound through the original vtables found by RTTI, slot by slot. A row is counted only when no other
receipt counts it. The receipt never writes a quoted bare address for a row it does not count.
Writes work/2008-06/shared-layouts/app-unit5f8-working.json.
Set NATIVE_APP_UNIT5F8_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5f8'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5F8_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5f8-working.json'
SOURCES = {
    'winhttp': R / 'native-classes/AppUnit5F8WinHttp.cpp',
    'wininet': R / 'native-classes/AppUnit5F8WinInet.cpp',
    'kernelarrays': R / 'native-classes/AppUnit5F8KernelArrays.cpp',
}
EXTRA_FLAGS = {'kernelarrays': ['/fp:fast']}
HEADER = R / 'native-headers/AppUnit5F8/HttpTransport.h'


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit5F8_' + key, src, EXTRA_FLAGS.get(key, ()))

original = nb.Original()
EVIDENCE = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {int(json.loads(l)['addr'], 16): json.loads(l) for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}
IMAGE = original.pe.get_memory_mapped_image()
BASE = original.image


def d(address):
    return struct.unpack_from('<I', IMAGE, address - BASE)[0]


# ---- scope ------------------------------------------------------------------------------------------------------
LO, HI = 0x5f8000, 0x5fc000
UNIT_OF = [  # (unit key or None, lo, hi): rows of the range in address order
    ('winhttp', 0x5f8000, 0x5f9440),
    ('wininet', 0x5f9440, 0x5fa610),
    (None, 0x5fa610, 0x5fb710),
    (None, 0x5fb710, 0x5fc000),
]
# Roblox-authored rows of the WinHttp unit below the range (app-unit5f0 maps them inside its boost.iostreams block
# and counts no row there): WinHttpRequest_source::read and the WinHttp handle destructor.
EXTRA_ROWS = {0x5f2c40: 'winhttp', 0x5f20e0: 'winhttp'}
SCOPE = {}
for a in sorted(FUNCTIONS):
    for unit, lo, hi in UNIT_OF:
        if unit and lo <= a < hi:
            SCOPE[a] = unit
SCOPE.update(EXTRA_ROWS)
# G3D::Array<T*> instances of the Kernel.cpp unit: byte-identical bodies (each with its own function-local static),
# so each row is assigned to the instance its callers prove (see native-classes/AppUnit5F8KernelArrays.cpp). The
# Array<Body*> pair 005fa770 / 005fabc0 is also called by Body.cpp (body-primitive2008 binds it by name): not here.
KERNEL_ARRAYS = {
    0x5fa670: '?resize@?$Array@PAVConnector@RBX@@@G3D@@QAEXH_N@Z',
    0x5fab50: '?append@?$Array@PAVConnector@RBX@@@G3D@@QAEXABQAVConnector@RBX@@@Z',
    0x5fa870: '?resize@?$Array@PAVPoint@RBX@@@G3D@@QAEXH_N@Z',
    0x5fac30: '?append@?$Array@PAVPoint@RBX@@@G3D@@QAEXABQAVPoint@RBX@@@Z',
}
for _a in KERNEL_ARRAYS:
    SCOPE[_a] = 'kernelarrays'


# ---- compiled pieces ----------------------------------------------------------------------------------------------
class Obj:
    def __init__(self, path):
        self.raw = Path(path).read_bytes()
        self.sections, self.symbols, self.definitions, _ = match._coff_data_index(self.raw)
        self.funcs = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}

    def relocs(self, name, lo, hi):
        """[(offset relative to lo, symbol, kind)] of the relocations of function `name` inside [lo, hi)."""
        start, sec = self.definitions[name]
        table = self.sections[sec]
        out = []
        for i in range(table[7]):
            off, idx, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            off -= start
            if lo <= off < hi:
                out.append((off - lo, self.symbols[idx][0], kind))
        return out

    def code(self, name):
        start, sec = self.definitions[name]
        return self.raw[self.sections[sec][4] + start:]

    def catch_offsets(self, name):
        start, sec = self.definitions[name]
        body = self.funcs[name][0]
        offs = []
        for sym, (value, s) in self.definitions.items():
            if s == sec and sym.startswith('__catch$' + name + '$') and start < value < start + len(body):
                offs.append(value - start)
        return sorted(set(offs))


O = {k: Obj(p) for k, p in OBJ.items()}


def pieces(unit):
    """{bytes length: [(symbol, piece index, lo, hi)]} for every function of the unit object."""
    o = O[unit]
    out = []
    for name, (body, refs) in o.funcs.items():
        if nb.LOCAL_EH.match(name):
            continue
        out.append((name, 'whole', 0, len(body)))
        cuts = [0] + o.catch_offsets(name) + [len(body)]
        if len(cuts) > 2:
            for k, (lo, hi) in enumerate(zip(cuts, cuts[1:])):
                out.append((name, k, lo, hi))
    return out


PIECES = {k: pieces(k) for k in O}


def piece_bytes(unit, name, lo, hi):
    body, refs = O[unit].funcs[name]
    return body[lo:hi], [r - lo for r in refs if lo <= r < hi]


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


TARGET = {a: target_of(a) for a in SCOPE}


def candidates(unit, t, tr):
    return [(n, k, lo, hi) for n, k, lo, hi in PIECES[unit]
            if hi - lo == len(t) and match.exact_match(t, tr, *piece_bytes(unit, n, lo, hi))]


CAND = {a: candidates(unit, *TARGET[a]) for a, unit in SCOPE.items()}
for _a, _sym in KERNEL_ARRAYS.items():
    CAND[_a] = [c for c in CAND[_a] if c[0] == _sym]
    assert len(CAND[_a]) == 1, (hex(_a), _sym)
# Rows that the analysis cut inside one body at a branch target (no catch label there): a row with no candidate is
# joined with the following contiguous row(s) of the same unit when the joined bytes equal one compiled piece. The
# join is recorded as BOUNDS evidence; both rows are then compared as one body.
JOINED = {}
for a in sorted(SCOPE):
    if CAND[a] or a in {m for v in JOINED.values() for m in v}:
        continue
    members, body, refs = [a], bytearray(TARGET[a][0]), list(TARGET[a][1])
    while True:
        nxt = members[-1] + len(TARGET[members[-1]][0])
        if nxt not in SCOPE or SCOPE[nxt] != SCOPE[a] or CAND[nxt] or len(members) > 3:
            break
        refs += [r + len(body) for r in TARGET[nxt][1]]
        body += TARGET[nxt][0]
        members.append(nxt)
        hits = candidates(SCOPE[a], bytes(body), refs)
        if hits:
            JOINED[a] = members
            TARGET[a] = (bytes(body), refs)
            CAND[a] = hits
            break
for a, members in JOINED.items():
    for m in members[1:]:
        del CAND[m]


# ---- original vtables by RTTI ---------------------------------------------------------------------------------------
def original_vtables(rtti):
    """[(vtable address, subobject offset)] whose complete-object locator names `rtti`."""
    pat = rtti.encode() + b'\0'
    out = []
    pos = IMAGE.find(pat)
    while pos >= 0:
        td = BASE + pos - 8
        for m in re.finditer(re.escape(struct.pack('<I', td)), IMAGE):
            col = BASE + m.start() - 12
            if col < BASE or d(col) != 0:
                continue
            for v in re.finditer(re.escape(struct.pack('<I', col)), IMAGE):
                if v.start() % 4 == 0:
                    out.append((BASE + v.start() + 4, d(col + 4)))
        pos = IMAGE.find(pat, pos + 1)
    return sorted(set(out))


def compiled_vtables(unit):
    o = O[unit]
    out = {}
    for symbol in sorted(s for s in o.definitions if s.startswith('??_7')):
        start, sec = o.definitions[symbol]
        table = o.sections[sec]
        relocs = sorted(struct.unpack_from('<IIH', o.raw, table[5] + 10 * k) for k in range(table[7]))
        slots = {(off - start) // 4: o.symbols[idx][0] for off, idx, kind in relocs
                 if kind == 6 and off >= start and (off - start) % 4 == 0}
        col = [o.symbols[idx][0] for off, idx, kind in relocs if kind == 6 and off == start - 4]
        if len(col) != 1:
            continue
        cstart, csec = o.definitions[col[0]]
        sub = struct.unpack_from('<I', o.raw, o.sections[csec][4] + cstart + 4)[0]
        tdsym = [o.symbols[idx][0] for off, idx, kind in sorted(
            struct.unpack_from('<IIH', o.raw, o.sections[csec][5] + 10 * k) for k in range(o.sections[csec][7]))
            if kind == 6 and off == cstart + 12]
        out[symbol] = (sub, slots, tdsym[0] if tdsym else None)
    return out


VT_BIND = {}       # symbol -> address, from original vtable slots
VT_REPORT = {}
for unit in O:
    for symbol, (sub, slots, td) in compiled_vtables(unit).items():
        if not td or not td.startswith('??_R0'):
            continue
        rtti = '.' + td[5:-2]
        hits = [vt for vt, off in original_vtables(rtti) if off == sub]
        if len(hits) != 1:
            VT_REPORT[symbol] = {'rtti': rtti, 'original': [hex(h) for h in hits], 'bound': False}
            continue
        vt = hits[0]
        bound = {}
        for k, s in sorted(slots.items()):
            value = d(vt + 4 * k)
            prev = VT_BIND.setdefault(s, value)
            assert prev == value, ('vtable slot binds a symbol twice', symbol, k, s, hex(prev), hex(value))
            bound[k] = '%s = %#x' % (s[:90], value)
        VT_BIND.setdefault(symbol, vt)
        VT_REPORT[symbol] = {'rtti': rtti, 'address': '%#x' % vt, 'subobject_offset': '%#x' % sub, 'slots': len(slots),
                             'bound': True, 'slot_bindings': bound}


# ---- binding --------------------------------------------------------------------------------------------------------
DATA_SECTIONS = [(BASE + x.VirtualAddress, BASE + x.VirtualAddress + x.Misc_VirtualSize)
                 for x in original.pe.sections if x.Name.rstrip(b'\0') in (b'.rdata', b'.data')]
# Externals the objects reference but do not define, bound by evidence name or call-site identification.
EXTERNAL = {
    # util/Http.cpp members of the Http.cpp unit (00569870..0056a55f, app-unit568 map): the failure helper
    # (thiscall, `ret 8`: GetLastError / FormatMessageA and runtime_error(format(.., url, message, ..))) and the static
    # trust check (cdecl, `add esp, 4` at the call; the http-trust-trial receipt binds the same address to this name)
    '?throwIfFailure@Http@RBX@@AAEX_NPBD@Z': 0x569920,
    '?trustCheck@Http@RBX@@SA_NPBD@Z': 0x56a2e0,
    # G3D::format(const char*, ...): the 38-byte va_list forwarder every 'format' call site of the app uses
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,
    # CRT stack probe (both transports allocate more than a page of locals: `mov eax, 0x1740; call`)
    '__chkstk': 0x6a1520,
    # CRT float-to-long (G3D::Array::resize growth factor; the same call every /fp:fast float->int conversion uses)
    '__ftol2_sse': 0x6a17f0,
}
# boost.iostreams zlib.cpp constants (library data, defined outside these units): bound by their values
DATA_VALUE = {
    '?default_compression@zlib@iostreams@boost@@3HB': (0x84b1f8, -1),   # Z_DEFAULT_COMPRESSION
    '?deflated@zlib@iostreams@boost@@3HB': (0x84b1fc, 8),               # Z_DEFLATED
    '?default_strategy@zlib@iostreams@boost@@3HB': (0x84b200, 0),       # Z_DEFAULT_STRATEGY
}
_TCACHE = {}


def target_cached(address):
    if address not in _TCACHE:
        try:
            _TCACHE[address] = target_of(address)
        except Exception:
            _TCACHE[address] = None
    return _TCACHE[address]


def body_equal_at(unit, sym, value):
    """The compiled body of `sym` equals the original at `value` (consecutive analysis rows joined if needed)."""
    if sym not in O[unit].funcs or value not in FUNCTIONS:
        return False
    body, refs = O[unit].funcs[sym]
    t, tr, at = b'', [], value
    while len(t) < len(body):
        row = target_cached(at)
        if row is None or at not in FUNCTIONS:
            return False
        tr += [r + len(t) for r in row[1]]
        t += row[0]
        at += len(row[0])
    return len(t) == len(body) and match.exact_match(t, tr, body, refs)


def literal_bytes(unit, symbol):
    o = O[unit]
    pos, at = o.definitions[symbol]
    sec = o.sections[at]
    return o.raw[sec[4] + pos:sec[4] + sec[3]].split(b'\0')[0] + b'\0'


def check_piece(unit, name, lo, hi, address, binding):
    """Relocation targets of a piece placed at `address`: (ok, {symbol: value} to bind, {symbol: proof}, local)."""
    o = O[unit]
    t = TARGET[address][0] if address in TARGET else target_of(address)[0]
    code = o.code(name)
    need, proofs, local = {}, {}, set()
    for off, sym, kind in o.relocs(name, lo, hi):
        if kind == 20:
            value = (address + off + 4 + struct.unpack_from('<i', t, off)[0]) & 0xffffffff
        elif kind == 6:
            value = (struct.unpack_from('<I', t, off)[0] - struct.unpack_from('<i', code, lo + off)[0]) & 0xffffffff
        else:
            return False, {}, {sym: 'unsupported relocation kind %d' % kind}, local
        if nb.LOCAL_EH.match(sym):
            local.add(sym)
            continue
        hit = original.imported(value)
        if hit is not None:
            if hit[1] != nb.plain(sym):
                return False, {}, {sym: 'import %s!%s' % hit}, local
            proofs[sym] = '%#x (%s!%s)' % ((value,) + hit)
            continue
        if sym.startswith('??_C@'):
            lit = literal_bytes(unit, sym)
            if original.data(value, len(lit)) != lit:
                return False, {}, {sym: 'literal differs at %#x' % value}, local
            proofs[sym] = '%#x (string literal bytes)' % value
            continue
        if sym.startswith('__real@'):
            raw = bytes.fromhex(sym[7:])[::-1]
            if original.data(value, len(raw)) != raw:
                return False, {}, {sym: 'constant differs'}, local
            proofs[sym] = '%#x (constant bytes)' % value
            continue
        if sym.startswith('??_R0') and sym.endswith('@8'):
            if original.string(value + 8) != '.' + sym[5:-2]:
                return False, {}, {sym: 'RTTI differs'}, local
            proofs[sym] = '%#x (RTTI %s)' % (value, original.string(value + 8))
            continue
        if sym.startswith('??_7') and sym not in VT_BIND:
            rtti, at = original.vtable_class(value)
            if rtti[4:] != sym[4:sym.index('@@6B') + 2]:
                return False, {}, {sym: 'vtable RTTI %s' % rtti}, local
            proofs[sym] = '%#x (vtable, RTTI %s, offset %#x)' % (value, rtti, at)
            continue
        prev = binding.get(sym, need.get(sym))
        if prev is not None and prev != value:
            return False, {}, {sym: 'bound to %#x, used as %#x' % (prev, value)}, local
        if sym in O[unit].funcs and value not in SCOPE and not body_equal_at(unit, sym, value) \
                and EVIDENCE.get(value) != sym:
            return False, {}, {sym: 'compiled body differs at %#x' % value}, local
        need[sym] = value
    return True, need, proofs, local


binding = dict(VT_BIND)
assigned, aliases, ambiguous = {}, {}, {}
for _ in range(30):
    changed = False
    for a in sorted(CAND):
        if a in assigned:
            continue
        unit = SCOPE[a]
        ok = []
        for name, k, lo, hi in CAND[a]:
            if binding.get(name, a - lo) != a - lo:
                continue
            good, need, proofs, local = check_piece(unit, name, lo, hi, a, binding)
            if good:
                ok.append((name, k, lo, hi, need))
        bound_here = [c for c in ok if binding.get(c[0]) == a - c[2]]
        if unit == 'wininet' and not bound_here:
            # an instance the WinHttp unit also compiles keeps its COMDAT copy there (that unit is linked first)
            # unless an original vtable slot binds it here
            only_here = [c for c in ok if c[0] not in O['winhttp'].funcs]
            if only_here:
                ok = only_here
        pick = bound_here[0] if bound_here else (ok[0] if len(ok) == 1 else None)
        if pick is None:
            ambiguous[a] = [(n, k) for n, k, lo, hi, need in ok]
            continue
        name, k, lo, hi, need = pick
        assigned[a] = (unit, name, k, lo, hi)
        aliases[a] = sorted(c[0] for c in bound_here if c[0] != name)
        binding.setdefault(name, a - lo)
        for sym, value in need.items():
            binding.setdefault(sym, value)
        ambiguous.pop(a, None)
        changed = True
    if not changed:
        break

ROW_OF = {}
for a, (unit, name, k, lo, hi) in assigned.items():
    ROW_OF.setdefault(name, a - lo)


# ---- final verification ---------------------------------------------------------------------------------------------
UNBOUND = []
groups = {'winhttp': [], 'wininet': [], 'kernelarrays': []}
for a in sorted(set(CAND) | set(assigned)):
    unit = SCOPE[a]
    members = JOINED.get(a, [a])
    if a not in assigned:
        groups[unit].append({'row': '%08x (not exact)' % a, 'size': len(TARGET[a][0]), 'exact': False,
                             'candidates': [n for n, k in ambiguous.get(a, [])][:6] or
                             'no compiled piece equals the original bytes'})
        continue
    _, name, k, lo, hi = assigned[a]
    good, need, proofs, local = check_piece(unit, name, lo, hi, a, binding)
    assert good, (hex(a), name, proofs)
    for sym, value in need.items():
        if sym in VT_BIND and VT_BIND[sym] == value:
            proofs[sym] = '%#x (original vtable slot, by RTTI)' % value
        elif ROW_OF.get(sym) == value:
            proofs[sym] = '%#x (row proven here)' % value
        elif sym in O[unit].funcs and body_equal_at(unit, sym, value):
            proofs[sym] = '%#x (compiled body equal at that address; not counted)' % value
        elif EVIDENCE.get(value) == sym:
            proofs[sym] = '%#x (evidence name)' % value
        elif EXTERNAL.get(sym) == value:
            proofs[sym] = '%#x (call-site identification)' % value
        elif sym in DATA_VALUE and DATA_VALUE[sym][0] == value and \
                struct.unpack('<i', original.data(value, 4))[0] == DATA_VALUE[sym][1]:
            proofs[sym] = '%#x (library constant, value %d)' % (value, DATA_VALUE[sym][1])
        elif sym not in O[unit].funcs and sym in O[unit].definitions and \
                any(lo_ <= value < hi_ for lo_, hi_ in DATA_SECTIONS):
            proofs[sym] = '%#x (static data, one address per symbol)' % value
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s at %08x" % (sym, value, EVIDENCE.get(value, '')[:50], name[:50], a))
            proofs[sym] = 'UNBOUND %#x' % value
    entry = {'row': '%08x' % a, 'symbol': name, 'piece': k, 'piece_range': [lo, hi], 'size': hi - lo,
             'exact': True, 'verified_targets': proofs, 'local_eh': sorted(local)}
    if len(members) > 1:
        entry['joined_rows'] = ['%08x' % m for m in members]
    if aliases.get(a):
        entry['icf_folded_symbols'] = aliases[a]
    groups[unit].append(entry)

if DISCOVER:
    for unit, rows in groups.items():
        for r in rows:
            print(unit, r['row'], r.get('symbol', '')[:90], r.get('piece', ''), r.get('joined_rows', ''),
                  len(r.get('icf_folded_symbols', [])), '' if r['exact'] else r['candidates'])
    print('\n'.join(sorted(set(UNBOUND))))
    sys.exit(0)
assert not UNBOUND, UNBOUND

# every counted library-template row is referenced only from the two transport units (callers inside the WinHttp
# unit 005f2030.. and the WinINet unit ..005fa60f), or, for the transports themselves, from Http::post / Http::get
HTTP_UNITS = (0x5f2030, 0x5fa610)
HTTP_CALLERS = {0x569a40, 0x569ae0, 0x569ba3}   # post 00569a40, get 00569ae0 (and its second call block)
KERNEL_UNIT = (0x5fa610, 0x5fb710)
for unit, rows in groups.items():
    for r in rows:
        if not r['exact']:
            continue
        for m in r.get('joined_rows', [r['row']]):
            for c in FUNCTIONS[int(m, 16)]['callers']:
                c = int(c, 16)
                if unit == 'kernelarrays':
                    assert KERNEL_UNIT[0] <= c < KERNEL_UNIT[1], (m, hex(c))
                else:
                    assert HTTP_UNITS[0] <= c < HTTP_UNITS[1] or c in HTTP_CALLERS, (m, hex(c))


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
        rows = []
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    a = o.get('address') or o.get('addr')
                    if a and o.get('exact') is True:
                        rows.append(a)
                    for v in o.values():
                        if isinstance(v, (list, dict)):
                            walk(v)
            walk(data)
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = (r.get('address') or r.get('addr') or '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({m for rows in groups.values() for r in rows if r['exact'] for m in r.get('joined_rows', [r['row']])})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '%08x' % LO <= a < '%08x' % HI}

# ---- unit map --------------------------------------------------------------------------------------------------
RANGE_ROWS = [FUNCTIONS[a] for a in sorted(FUNCTIONS) if LO <= a < HI]
UNITS = [
    ('util/Http.cpp WinHttp transport unit (tail)', 0x5f8000, 0x5f9440),
    ('util/Http.cpp WinINet transport unit', 0x5f9440, 0x5fa610),
    ('v8kernel/Kernel.cpp', 0x5fa610, 0x5fb710),
    ('LocalBackpack.cpp', 0x5fb710, 0x5fc000),
]
UNIT_MAP = {
    'util/Http.cpp WinHttp transport unit (tail)': (
        'The WinHttp half of util/Http.cpp, compiled as its own unit (it includes <winhttp.h>, which cannot share a '
        'unit with <wininet.h>: C2371 on HTTP_VERSION_INFO / INTERNET_SCHEME / URL_COMPONENTS). It starts below the '
        'range at 005f2030 (app-unit5f0 maps 005f2030.. as boost.iostreams instantiations; the Roblox rows there are '
        'the WinHttp handle destructor 005f20e0 and WinHttpRequest_source::read 005f2c40, both counted here). In the '
        'range: the catch funclet of ~chain_impl<input> (005f802f), indirect_streambuf<basic_gzip_compressor> '
        'strict_sync (rows 005f8060 + 005f809d are one body, BOUNDS) with its catch 005f80b0, overflow, sync (+catch '
        '005f81c0), init_get_area, symmetric_filter read (+catch), close (+catch) of the gzip compressor / '
        'decompressor buffers, checked_delete / shared_count / sp_counted_impl_p dispose of chain_impl<output|input>, '
        'chain_base ctors, filtering_stream_base / filtering_stream ctors and their ??_E / ??_G, and '
        'Http::httpGetPostWinHttp 005f8b60 (2261 B: WinHttpOpen "Roblox/WinHttp", WinHttpConnect, OpenRequest, '
        'Roblox-Content-Size / Roblox-Content-Hash headers via MD5Hasher::create, ReceiveResponse, gzip / zlib error '
        'handlers, status text). Class names from RTTI: .?AV?$indirect_streambuf@VWinHttpRequest_source@@ / '
        '.?AV?$stream_buffer@UString_sink@@. Callers: Http::post 00569a40 / Http::get 00569ae0 choose this transport '
        'when the static at 00946274 is 1. Built here: native-classes/AppUnit5F8WinHttp.cpp.'),
    'util/Http.cpp WinINet transport unit': (
        'The WinINet half of util/Http.cpp (<wininet.h>): WinInetHandle destructor 005f9440 (InternetCloseHandle), '
        'WiniInetRequest_source::read 005f9450 (InternetQueryDataAvailable / InternetReadFile, "InternetReadFile '
        'failed"), the indirect_streambuf / stream_buffer / chain push_impl / device_wrapper / concept_adapter '
        'instantiations for WiniInetRequest_source (RTTI .?AV?$indirect_streambuf@VWiniInetRequest_source@@ and '
        '.?AV?$stream_buffer@VWiniInetRequest_source@@, vtable 00840eac; some bodies are ICF-folded with the '
        'String_sink instances, whose vtable slots point here) and Http::httpGetPostWinInet 005f9c30 (2515 B: '
        'InternetOpenA "Roblox/WinInet", HttpOpenRequestA, Roblox-Content-Size / -First / -Last / -Hash headers, '
        'HttpSendRequestExA / InternetWriteFile / HttpEndRequestA, status code / text). Callers: Http::post / '
        'Http::get when the static at 00946274 is 0. Built here: native-classes/AppUnit5F8WinInet.cpp.'),
    'v8kernel/Kernel.cpp': (
        'Kernel.cpp of the kernel-stages owner (native-headers/v8kernel/Kernel2008.h, native-classes/Kernel2008.cpp): '
        'the leaf-body index accessor (lea eax, [ecx + 4]; used by the IndexArray<Body> helpers) and numLeafBodies '
        '(kernelData +0x28), connectorSpringEnergy-like sum over kernelData +0x24 (virtual slot 5), three '
        'G3D::Array<T*>::resize instances (256 B each, function-local minSize static 0097b5bc / guard 0097b5c0) and '
        'three Array<T*>::append instances (101 B), ~KernelData (out of line, five arrays at +0x0 / +0xc / +0x18 / '
        '+0x24 / +0x30), numBodies / numPoints / numConnectors and ~Kernel (counted by kernel-stages), '
        'bodyKineticEnergy (Body 00614670), numContacts-like readers, the PV integrator over leaf bodies '
        '(updatePV 00599360, orthonormalizeIfNecessary 005df0a0, setCoordinateFrame 00614400), the threshold '
        'sqrt(sqrt(..)) + 1 iteration count, insert / remove Body, Point and Connector helpers, newPoint / '
        'deletePoint, stepWorld (slot 2, 502 B), the KernelData constructor (0x3c) and Kernel(IStage*) (0x24). Not '
        'built here: the Kernel members are not declared in Kernel2008.h and KernelData has no native declaration '
        '(owner proposals in the kernel-stages receipt and below). Built here: G3D::Array<T*> resize / append '
        'instances (library templates instantiated only by this unit), from native-classes/AppUnit5F8KernelArrays.cpp '
        '(explicit member instantiations, /fp:fast); the element type of each byte-identical pair is the one its '
        'callers prove: Connector* (stepWorld on Kernel +0x14 realTimeConnectors) and Point* (newPoint appends the '
        'new 0x34 Point to KernelData +0x18). Only four of them: the Array<Body*> pair (resize at 005fa770, append at '
        '005fabc0) is also called by Body.cpp (onChildAdded / onChildRemoved; body-primitive2008 binds both by name), '
        'so it is not a template only this unit references and is not counted.'),
    'LocalBackpack.cpp': (
        'LocalBackpack rows of the local-backpack owner (LocalBackpack2008.h): mapped and counted there; render2d '
        '(external slot) and the remaining uncounted rows are that owner\'s.'),
}
unit_map = []
for u, lo, hi in UNITS:
    rows = [r for r in RANGE_ROWS if lo <= int(r['addr'], 16) < hi]
    unit_map.append({'unit': '%s %08x..%08x' % (u, lo, hi - 1), 'rows': len(rows), 'bytes': sum(r['size'] for r in rows),
                     'counted_elsewhere': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()
                                           if lo <= int(a, 16) < hi],
                     'counted_here': len([a for a in exact_rows if lo <= int(a, 16) < hi]),
                     'evidence': UNIT_MAP[u]})
assert sum(u['rows'] for u in unit_map) == len(RANGE_ROWS)

BOUNDS = [
    'Rows 005f8060 and 005f809d are one body: indirect_streambuf<basic_gzip_compressor>::strict_sync (80 B; '
    'the analysis cut it at the branch target 005f809d). Its catch funclet is the next row 005f80b0.',
    'Rows 005f8350 and 005f83a0 are one body: indirect_streambuf<basic_gzip_decompressor>::close (99 B; cut at the '
    'branch target 005f83a0). Its catch funclet is the next row 005f83b3.',
    'Owner bodies whose embedded catch block is a separate analysis row (compared piecewise at the compiler\'s '
    '__catch$ label, not truncated): sync<gzip_compressor> 005f8170 / 005f81c0, symmetric_filter read 005f8200 / '
    '005f82d3, close<gzip_compressor> 005f82f0 / 005f8348, shared_count<chain_impl> ctors 005f84f0 / 005f855e and '
    '005f8580 / 005f85ee, ~stream_buffer<WiniInetRequest_source> 005f9880 / 005f98d0, sync<WiniInetRequest_source> '
    '005f99f0 / 005f9a57, and ~chain_impl<input> (owner below the range) with its catch 005f802f.',
]
REJECTED = {
    'one unit with both transports': '<winhttp.h> and <wininet.h> in one unit: C2371 (HTTP_VERSION_INFO, '
                                      'INTERNET_SCHEME, URL_COMPONENTS); the image has two copies of the handle '
                                      'destructor and of the request source, one per unit',
    'request source read: two early `return -1`': '179/179 B (175/175 B for WinHttp) but separate epilogues; the '
                                                   'original shares one failure block',
    'request source read: `if (!query || numBytes == 0) return -1;`': 'failure block placed after the success path',
    'request source read: `if (query && numBytes != 0) { ... } return -1;`': 'not exact (block order)',
    'request source read: `numBytes <= 0` form': 'not exact (block order)',
    'request source read: `throw std::runtime_error("InternetReadFile failed")`': 'temporary string: different EH '
                                                                                  'state layout; a named local '
                                                                                  'string is exact',
    'WinINet accept header as `static const char[]`': '2499/2515 B: strlen of the array is folded; the original '
                                                       'runs the strlen loop on 00840ff8 (local const char* is exact)',
}
PROPOSALS = [
    'util/Http.h (donor path; no native owner yet): the 2008 RBX::Http declared in native-headers/AppUnit5F8/'
    'HttpTransport.h: url +0x0 and additionalHeaders +0x1c (post 00569a40 reads +0x30 / +0x34 / +0x20), private '
    'thiscall transports (bool isPost, std::istream&, bool compress, const char* headers, std::string& response) at '
    '005f8b60 (WinHttp) and 005f9c30 (WinINet), the failure helper (bool, const char*) 00569920 and static '
    'trustCheck 0056a2e0. Http::post / Http::get select the transport with a static int at 00946274 (0 WinINet, '
    '1 WinHttp); a future native util/Http.h should carry these members (names are analog names).',
    'FYI app-unit5f0 owner: its boost.iostreams block from 005f2030 is the WinHttp transport unit of util/Http.cpp; '
    'the Roblox rows WinHttpRequest_source::read 005f2c40 and the WinHttp handle destructor 005f20e0 are now counted '
    'by app-unit5f8-working.json (built from native-classes/AppUnit5F8WinHttp.cpp); please do not count them again.',
    'v8kernel/Kernel2008.h (kernel-stages owner): the Kernel.cpp rows 005fa610..005fb70f stay unbuilt until Kernel2008.h '
    'declares the 2008 members (insert / remove Body, Point, Connector, newPoint, deletePoint, the energy sums, the '
    'leaf-body integrator) and a native KernelData (0x3c, five G3D arrays at +0x0 / +0xc / +0x18 / +0x24 / +0x30, '
    'from ~KernelData 005fa970) exists; see that receipt\'s proposals.',
]
VT_USED = {k: v for k, v in VT_REPORT.items() if v.get('bound')}

receipt = {
    'scope': ('Inactive 2008-06 native recovery of the application range 005f8000..005fc000: unit map of every row, '
              'and the two util/Http.cpp transport units (WinHttp, WinINet) built from new native sources against '
              'the new native-headers/AppUnit5F8/HttpTransport.h, plus four G3D::Array<T*> instances of the '
              'Kernel.cpp unit. No runtime, link or class-swap claim.'),
    'exact_function_rows': exact_rows,
    'exact_function_row_count': len(exact_rows),
    'exact_rows_in_range': len([a for a in exact_rows if '%08x' % LO <= a < '%08x' % HI]),
    'range_rows': len(RANGE_ROWS),
    'rows': groups,
    'unit_map': unit_map,
    'vtables_by_rtti': VT_USED,
    'bounds_evidence': BOUNDS,
    'proposals': PROPOSALS,
    'rejected': dict(REJECTED, **{'G3D::Array<T*>::resize without /fp:fast': '264/256 B (x87 growth-factor '
                                                                             'code); /fp:fast is exact'}),
    'flags': FLAGS,
    'sources': {k: nb.sha(p) for k, p in list(SOURCES.items()) + [('header', HEADER)]},
    'headers_read_only': ['donor util/ContentProvider.h (RBX::MD5Hasher, unchanged in 2008-06)'],
    'new_headers': ['native-headers/AppUnit5F8/HttpTransport.h (new path; shadows no donor header)'],
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5f8: %d counted rows (%d in range of %d range rows)' % (
    len(exact_rows), receipt['exact_rows_in_range'], len(RANGE_ROWS)))
