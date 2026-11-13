"""Verify the inactive 2008-06 native rows of the application range 005f0000..005f8000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as text).

Unit map summary (details in UNIT_MAP below):
  * the 6698-byte G3D TextInput user row that starts at 005ef840 (below the range, mapped by app-unit5e8-2008) ends at
    005f126a; the first row of the range is 005f1270.
  * Surface.cpp 005f1270..005f1b2f: built here from native-classes/AppUnit5F0_2008Surface.cpp (ctor, getters, setters)
    against the read-only native v8datamodel/Surface.h and the 2008 PartInstance / Primitive of
    native-headers/part-embedded; Surface::flat 005f1690 from the committed native-classes/SurfaceFlat.cpp compiled
    unchanged (read-only). Surface::readValue 005f17a0 is not recovered (EnumDesc call_once singleton, see UNIT_MAP).
  * boost.thread 1.34.1 libs/thread/src/condition.cpp (library) 005f1b30..005f1fff.
  * util/Timer.cpp 005f2000: RBX::getRealTime, built here from native-classes/AppUnit5F0_2008Timer.cpp with the new
    native-headers/AppUnit5F0_2008/RealTime2008.h (a new path: it shadows no donor header).
  * boost.iostreams gzip / zlib / indirect_streambuf / stream_buffer / chain instantiations (library) 005f2030 to past
    005f8000.

Builds (document-swap flags, VS2008 RTM 21022):
  * surface: AppUnit5F0_2008Surface.cpp, /fp:fast, native-headers/part-embedded first on the include path;
  * flat:    the committed native-classes/SurfaceFlat.cpp (read-only), its own native-flags (no /fp:fast),
             native-headers/part-embedded first;
  * timer:   AppUnit5F0_2008Timer.cpp (no extra flags).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, constants by bytes, own symbols by the
row proven here, externals by the explicit EXTERNAL map (evidence name or call-site identification), and the
SurfaceData::empty() local static and its guard by one address per symbol. A row is counted only when no other
receipt counts it. The receipt never writes a quoted bare address for a row it does not count.
Writes work/2008-06/shared-layouts/app-unit5f0-2008-working.json.
Set NATIVE_APP_UNIT5F0_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit5f0-2008'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT5F0_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit5f0-2008-working.json'
SURFACE_SRC = R / 'native-classes/AppUnit5F0_2008Surface.cpp'
FLAT_SRC = R / 'native-classes/SurfaceFlat.cpp'          # committed, another owner: compiled read-only
TIMER_SRC = R / 'native-classes/AppUnit5F0_2008Timer.cpp'
TIMER_H = R / 'native-headers/AppUnit5F0_2008/RealTime2008.h'
PART_EMBEDDED = R / 'native-headers/part-embedded'


def build(name, src, extra=(), first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + ['/I' + str(p) for p in first] + flags[i:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['surface'], FLAGS['surface'] = build('NativeAppUnit5F0_2008_surface', SURFACE_SRC, ['/fp:fast'], [PART_EMBEDDED])
OBJ['flat'], FLAGS['flat'] = build('NativeAppUnit5F0_2008_flat', FLAT_SRC, [], [PART_EMBEDDED])
OBJ['timer'], FLAGS['timer'] = build('NativeAppUnit5F0_2008_timer', TIMER_SRC)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    # evidence names
    '?setSurfaceType@Primitive@RBX@@QAEXW4NormalId@2@W4SurfaceType@2@@Z': 0x5e7850,         # 005f13fd / 005f16ac
    '?onSurfaceChanged@PartInstance@RBX@@AAEXW4NormalId@2@@Z': 0x5997c0,                    # 005f1408 / 005f14c1 / ...
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,  # 005f1422 / ...
    # call-site identification (no evidence name; the callee is the only out-of-line body the source calls there)
    # Primitive::setSurfaceData(NormalId, const SurfaceData&): compares/replaces surfaceData[id] at Primitive +0xd0
    '?setSurfaceData@Primitive@RBX@@QAEXW4NormalId@2@ABVSurfaceData@2@@Z': 0x5e7770,         # 005f14b6 / 005f157d / 005f164d
    # PartInstance::getSurfaces() (non-const; the surface-flat-trial receipt binds the same call at 005f16c2)
    '?getSurfaces@PartInstance@RBX@@QAEAAVSurfaces@2@XZ': 0x598de0,                          # 005f1413 / 005f14cc / ...
    # Surfaces::getSurfaceType / getSurfaceInput / getParamA / getParamB(NormalId): six-way face switches returning
    # the per-face property descriptor statics
    '?getSurfaceType@Surfaces@RBX@@QBEABVPropertyDescriptor@Reflection@2@W4NormalId@2@@Z': 0x5eca30,   # 005f141a
    '?getSurfaceInput@Surfaces@RBX@@QBEABVPropertyDescriptor@Reflection@2@W4NormalId@2@@Z': 0x5eca90,  # 005f14d3
    '?getParamA@Surfaces@RBX@@QBEABVPropertyDescriptor@Reflection@2@W4NormalId@2@@Z': 0x5ecaf0,        # 005f159a
    '?getParamB@Surfaces@RBX@@QBEABVPropertyDescriptor@Reflection@2@W4NormalId@2@@Z': 0x5ecb50,        # 005f166a
}
# function-local statics of the inline SurfaceData::empty() (one address per symbol)
LOCAL_STATIC_AT = {
    '?s@?1??empty@SurfaceData@RBX@@SAABV23@XZ@4V23@A': 0x97abc4,      # inputType +0, paramA +4, paramB +8
    '??_B?1??empty@SurfaceData@RBX@@SAABV12@XZ@51': 0x97abd0,          # guard bit 1
}
ALIAS = {}
UNBOUND = []
binding = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'surface': [
        (0x005f1270, '??0Surface@RBX@@QAE@PAVPartInstance@1@W4NormalId@1@@Z'),
        (0x005f1290, '?getSurfaceType@Surface@RBX@@QBE?AW4SurfaceType@2@XZ'),
        (0x005f12a0, '?getInput@Surface@RBX@@QBE?AW4InputType@Controller@2@XZ'),
        (0x005f1300, '?getParamA@Surface@RBX@@QBEMXZ'),
        (0x005f1360, '?getParamB@Surface@RBX@@QBEMXZ'),
        (0x005f13c0, '?isControllable@Surface@RBX@@QBE_NXZ'),
        (0x005f13e0, '?setSurfaceType@Surface@RBX@@QAEXW4SurfaceType@2@@Z'),
        (0x005f1430, '?setSurfaceInput@Surface@RBX@@QAEXW4InputType@Controller@2@@Z'),
        (0x005f14f0, '?setParamA@Surface@RBX@@QAEXM@Z'),
        (0x005f15c0, '?setParamB@Surface@RBX@@QAEXM@Z'),
    ],
    'flat': [
        (0x005f1690, '?flat@Surface@RBX@@QAEXXZ'),
    ],
    'timer': [
        (0x005f2000, '?getRealTime@RBX@@YANXZ'),
    ],
}
REJECTED = {
    'setParamA / setParamB without /fp:fast': '205/199 B each (x87 compare order); /fp:fast gives 199/199 exact and '
                                             'leaves the other eight Surface rows exact',
}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def bind_value(raw, sections, symbols, definitions, name, body, target, address, own):
    start, section = definitions[name]
    table = sections[section]
    code = raw[table[4] + start:]
    verified, local = {}, set()
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
        if nb.LOCAL_EH.match(symbol):
            local.add(symbol)
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
            how = '%s!%s' % hit
        elif symbol.startswith('__real@'):
            assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
            how = 'constant %s' % symbol[7:]
        elif symbol in ALIAS:
            assert ALIAS[symbol] == value, (name, symbol, hex(value), hex(ALIAS[symbol]))
            how = 'ICF-folded body (alias of a row proven here)'
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else ' (call-site identification)')
        elif symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'static data (one address per symbol)'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert DISCOVER, (name, entry['address'], len(body), len(target))
            entry['address'] = '%08x (not exact)' % address
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, name, body, target, address, own)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in groups.items():
        for r in rows:
            if not r['exact']:
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND

# every Surface row's partInstance / surfId accesses are the two dwords the 18-byte constructor stores (+0 / +4); the
# ctor target bytes are checked here explicitly as the layout evidence (mov [eax], ecx / mov [eax+4], edx / ret 8)
ctor = original.data(0x5f1270, 18)
assert ctor[10:12] == bytes.fromhex('8908') and ctor[12:15] == bytes.fromhex('895004') and ctor[15:18] == bytes.fromhex('c20800'), ctor.hex()


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
            # conservative: any entry marked exact anywhere in the receipt
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
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '005f0000' <= a < '005f8000'}

# ---- unit map --------------------------------------------------------------------------------------------------
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if 0x5f0000 <= int(r['addr'], 16) < 0x5f8000]
UNITS = [
    ('Surface.cpp', 0x5f1270, 0x5f1b30),
    ('boost.thread condition.cpp (library)', 0x5f1b30, 0x5f2000),
    ('util/Timer.cpp', 0x5f2000, 0x5f2030),
    ('boost.iostreams instantiations (library)', 0x5f2030, 0x5f8000),
]
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r)

UNIT_MAP = {
    'Surface.cpp 005f1270..005f1b2f': (
        'v8datamodel/Surface.cpp (native v8datamodel/Surface.h, read-only). Layout: Surface is {PartInstance* +0, '
        'NormalId +4}; the constructor 005f1270 (evidence name) stores both and returns 8; Surfaces(PartInstance*) '
        '005ecbb0 holds six of them. The 2008 PartInstance embeds its Primitive at +0x228 (native-headers/'
        'part-embedded): surfaceType[6] at Primitive +0xb8 (setSurfaceType 005f13e0 compares [part + id*4 + 0x2e0]) '
        'and surfaceData[6] at +0xd0 (getInput 005f12a0, SurfaceData::empty() static 0097abc4 / guard 0097abd0). '
        'Evidence names getSurfaceType 005f1290, getInput 005f12a0, isControllable 005f13c0; getParamA 005f1300 / '
        'getParamB 005f1360 read +4 / +8 of the same SurfaceData; setSurfaceType 005f13e0, setSurfaceInput 005f1430, '
        'setParamA 005f14f0, setParamB 005f15c0 (each: Primitive::setSurfaceType 005e7850 or setSurfaceData '
        '005e7770, onSurfaceChanged 005997c0, getSurfaces 00598de0, Surfaces::get* descriptor switch 005eca30 / '
        '005eca90 / 005ecaf0 / 005ecb50, raisePropertyChanged 0040db00); flat 005f1690 (calls the three setters and '
        'the SurfaceData::empty() values; built from the committed SurfaceFlat.cpp, whose surface-flat-trial receipt '
        'counts no row); readValue(const XmlElement*, IReferenceBinder&) 005f17a0 (ret 8; called by the six '
        'SurfaceDescriptor<face> readValue rows 005eece0..005eef11): declares the Names "Type" 0080f7d4, '
        '"SurfaceInput" 00840814, "ParamA" 0084080c, "ParamB" 00840804, "Constraint" 008407f8 (Name::declare '
        '00553f90, statics 0097b5a0..0097b5b0, guard 0097b5b4), walks the child elements (isXsiNil 0057c810, '
        'findAttribute 0057c2b0 with name_name 00975338, XmlNameValuePair getValue 0057c360 / 0057c210 / 0057c610) '
        'and converts with EnumDesc<SurfaceType> / EnumDesc<Controller::InputType>: boost::call_once(005ed620 / '
        '005ed690, flags 0097b11c / 0097b120) then the out-of-line static-instance getters 005ed5c0 / 005ed630, '
        'Name::lookup 00554290 and convertToValue 005ed300; the Constraint branch calls the out-of-line singleton '
        '005ed6a0 and convertToValue(const char*) 005ed800. Not recovered: the native reflection/enumconverter.h '
        'EnumDesc::singleton() is a plain function static (no call_once), so the 2008 call shape cannot be produced '
        'without the reflection-core proposal below. Built here: 11 counted rows.'),
    'boost.thread condition.cpp (library) 005f1b30..005f1fff': (
        'boost 1.34.1 libs/thread/src/condition.cpp (Win32 condition_impl {m_gate, m_queue, m_mutex, m_gone, '
        'm_blocked, m_waiting}): to_duration (timeconv.inl, xtime_get 005a6b40, 1000000000 / 500000 rounding) '
        '005f1b30, condition_impl() 005f1bd0 (CreateSemaphoreA x2, CreateMutexA, throws lock_error 00568430), '
        '~condition_impl 005f1c70, notify_one 005f1c90, notify_all 005f1d30, enter_wait 005f1dd0, do_wait '
        '005f1df0, do_timed_wait 005f1ea0. Library code (roc/libs.py boost thread sources); not recovered.'),
    'util/Timer.cpp 005f2000..005f202f': (
        'RBX::getRealTime 005f2000 (QueryPerformanceCounter / QueryPerformanceFrequency through the IAT, x87 '
        'divide; ten callers 005548a3..00575d66). The name is the later openrbx-client attribution of the matched '
        'analog; declared in the new native-headers/AppUnit5F0_2008/RealTime2008.h. Built here: 1 counted row.'),
    'boost.iostreams instantiations (library) 005f2030..': (
        'boost 1.34.1 iostreams code continuing from the app-unit5e8 range: gzip_params ctor / dtor / copy '
        '005f2030 / 005f20f0 / 005f2160, basic_gzip_compressor / basic_gzip_decompressor (normalize_params '
        '005f21f0, make_params 005f2270, read_string / write_long / prepare_footer / read_header / read_footer, '
        'copy constructors 005f4350 / 005f43e0, ctors 005f6990 / 005f6bc0, gzip_error 005f5970 / 005f5a00 / '
        '005f6420), zlib_compressor_impl / zlib_decompressor_impl and symmetric_filter, basic_buffer, '
        'indirect_streambuf / stream_buffer / chain_base / filtering_stream_base, cant_read / cant_seek / '
        'cant_write, std::list<linked_streambuf*> helpers, instantiated for basic_null_device, the gzip filters and '
        'the Http unit\'s String_sink / HttpRequest_source (indirect_streambuf<String_sink> open 005f2a50 / '
        'underflow 005f2ab0 / overflow 005f4080 / sync_impl 005f3700, indirect_streambuf<HttpRequest_source> open '
        '005f2d20 / overflow 005f3580, device_wrapper_impl write 005f5b70). Continues past 005f8000 (005f802f..). '
        'Library templates (boost); the String_sink / HttpRequest_source instantiations would need native Http '
        'declarations and the boost.iostreams library profile. Not recovered.'),
}
unit_map = []
for u, lo, hi in UNITS:
    key = [k for k in UNIT_MAP if k.startswith(u)][0]
    rows = unit_rows.get(u, [])
    unit_map.append({'unit': key, 'rows': len(rows), 'bytes': sum(r['size'] for r in rows),
                     'counted_elsewhere': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()
                                           if lo <= int(a, 16) < hi],
                     'counted_here': len([a for a in exact_rows if lo <= int(a, 16) < hi]),
                     'evidence': UNIT_MAP[key]})
assert sum(u['rows'] for u in unit_map) == len(RANGE_ROWS)

PROPOSALS = [
    'Owner of native-headers/reflection/enumconverter.h (reflection core; not edited): the 2008 EnumDesc<Enum>::'
    'singleton() is boost::call_once(&<thunk>, <static once_flag>) followed by an out-of-line function-static '
    'instance getter. SurfaceType: call_once(005ed620 `jmp 005ed5c0`, flag 0097b11c), getter 005ed5c0 (guard bit '
    '0097b028, object 0097af40, ctor 0064d750, atexit); Controller::InputType: 005ed690 / 0097b120 / 005ed630. '
    'convertToValue(const char*, Enum&) is out of line at 005ed800 (Name::lookup 00554290, then convertToValue(const '
    'Name&) 005ed300). This is the same call_once shape as the open EnumPropDescriptor proposals (TANDEM 2026-11-04/06: '
    '0060bd80.., 00609590, 005d0d80). With it, Surface::readValue 005f17a0 becomes a candidate.',
    'FYI owner of native-classes/SurfaceFlat.cpp / surface-flat-trial: Surface::flat 005f1690 is now counted by '
    'app-unit5f0-2008-working.json (the file is compiled unchanged here); please do not count it again.',
]

receipt = {
    'scope': ('Inactive 2008-06 native recovery of the application range 005f0000..005f8000: unit map of every row, '
              'Surface.cpp rows against the native v8datamodel/Surface.h and the part-embedded PartInstance / '
              'Primitive, and util/Timer.cpp getRealTime. No runtime, link or class-swap claim.'),
    'exact_function_rows': exact_rows,
    'exact_function_row_count': len(exact_rows),
    'range_rows': len(RANGE_ROWS),
    'rows': groups,
    'unit_map': unit_map,
    'proposals': PROPOSALS,
    'rejected': REJECTED,
    'flags': FLAGS,
    'sources': {k: nb.sha(p) for k, p in [('surface', SURFACE_SRC), ('flat', FLAT_SRC), ('timer', TIMER_SRC),
                                          ('timer_header', TIMER_H)]},
    'headers_read_only': ['native-headers/v8datamodel/Surface.h', 'native-headers/v8datamodel/Surfaces.h',
                          'native-headers/part-embedded/v8datamodel/PartInstance.h',
                          'native-headers/part-embedded/v8world/Primitive.h'],
    'new_headers': ['native-headers/AppUnit5F0_2008/RealTime2008.h (new path; shadows no donor header)'],
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit5f0-2008: %d counted rows (%d range rows)' % (len(exact_rows), len(RANGE_ROWS)))
