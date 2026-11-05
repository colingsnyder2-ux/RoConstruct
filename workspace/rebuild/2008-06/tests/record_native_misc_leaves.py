"""Verify the inactive native RBX::MD5HasherImpl and RBX::MergeBinder recoveries (2008-06).

Builds (document-swap flags, VS2008 RTM 21022, current native headers only; no pending build):
  * tests/NativeMiscLeavesLayout.cpp   sizeof MD5HasherImpl 0x28, MergeBinder 0x1c, InstanceHandle 8;
  * native-classes/MD5Hasher.cpp       MD5HasherImpl ctor / 3 addData / toString / c_str, MD5Hasher::create, plus the
                                       ATL CString members the unit instantiates;
  * native-classes/MetadataMergeBinderConstructor.cpp  existing MergeBinder ctor/provider and its inline virtuals,
                                       std::vector<IDREFItem> / boost shared_from members they instantiate.

Every row must be relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by export name, literals by bytes, vtables by original RTTI
names, throw info by its first catchable type, own symbols by the row proven here, the remaining externals by the
EXTERNAL map below (each named so by evidence.json, or with the reason given), one address per symbol across all rows.
vector::_Insert_n is compared against its current full 638-byte extent, including the embedded catch funclets
(0044440d / 004444a8 are retired starts). Both vtables are slot-checked against the original from the
current-header objects; the RTTI base lists and the allocation size new(0x28) are asserted from the original bytes.
Writes work/2008-06/shared-layouts/misc-leaves-working.json.
"""
import argparse
import json
import re
import struct
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--out', type=Path, help='isolated output directory; receipt.json is stored here')
args = parser.parse_args()
OUT = args.out.resolve() if args.out else R / 'out/native-misc-leaves'
OUT.mkdir(parents=True, exist_ok=True)
MD5_UNIT = R / 'native-classes/MD5Hasher.cpp'
MB_UNIT = R / 'native-classes/MetadataMergeBinderConstructor.cpp'
HEADERS = [R / 'native-headers/util/MD5Hasher2008.h', R / 'native-headers/metadata-load/v8xml/SerializerV2.h']
LAYOUT = R / 'tests/NativeMiscLeavesLayout.cpp'
dependencies = {}
started_ns = time.time_ns()


def build(name, src):
    obj = OUT / (name + '.obj')
    # Reuse the existing metadata provider; never introduce a second MergeBinder
    # constructor/class. Original announceIDREF is a tail jump, without asserts.
    flags = ['/I' + str(R / 'native-headers/metadata-load')] + nb.flags() + ['/U_RELEASEASSERT', '/showIncludes', '/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    (OUT / (name + '.log')).write_text(log, encoding='utf-8')
    assert code == 0, log
    for line in log.splitlines():
        hit = re.match(r'\s*Note: including file:\s*(.*?)\s*$', line)
        if hit:
            path = Path(hit[1]).resolve()
            dependencies[str(path)] = nb.sha(path)
    return obj, flags


layout_obj, layout_flags = build('NativeMiscLeavesLayout', LAYOUT)
md5_obj, md5_flags = build('NativeMD5Hasher', MD5_UNIT)
mb_obj, mb_flags = build('NativeMergeBinder', MB_UNIT)

# ---- layout ---------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeMD5HasherImplSize@@', 0x28), ('?nativeMergeBinderSize@@', 0x1c),
                      ('?nativeInstanceHandleSize@@', 0x8)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

MD5 = 'MD5HasherImpl@RBX@@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
CST = '?$CSimpleStringT@D$0A@@ATL@@'
CSTR = '?$CStringT@DV?$StrTraitATL@DV?$ChTraitsCRT@D@ATL@@@ATL@@@ATL@@'
MB = 'MergeBinder@RBX@@'
IT = 'UIDREFItem@MergeBinder@RBX@@'
VEC = '?$vector@' + IT + 'V?$allocator@' + IT + '@std@@@std@@'

# (address or contiguous addresses, unique symbol or symbol prefix)
ROWS = {
    'md5': [
        (0x55c540, '??0' + MD5 + 'QAE@XZ'),
        (0x55c800, '?addData@' + MD5 + 'UAEXPBDI@Z'),
        (0x55c740, '?addData@' + MD5 + 'UAEXAB' + STR + '@Z'),
        (0x55c6a0, '?addData@' + MD5 + 'UAEXAAV?$basic_istream@DU?$char_traits@D@std@@@std@@@Z'),
        (0x55c710, '?toString@' + MD5 + 'UAE?A' + STR + 'XZ'),
        (0x55e320, '?c_str@' + MD5 + 'UAEPBDXZ'),
        (0x55c8b0, '?create@MD5Hasher@RBX@@SAPAV12@XZ'),
        # ATL CString members instantiated by c_str (COMDATs, one copy in the exe)
        (0x55e250, '?Format@' + CSTR + 'QAAXPBDZZ'),
        (0x55dae0, '?FormatV@' + CSTR + 'QAEXPBDPAD@Z'),
        (0x407400, '?PrepareWrite2@' + CST + 'AAEXH@Z'),
        (0x406d60, '?Reallocate@' + CST + 'AAEXH@Z'),
        (0x4066b0, '?ThrowMemoryException@' + CST + 'KAXXZ'),
        (0x406ce0, '?Fork@' + CST + 'AAEXH@Z'),
    ],
    'mb': [
        (0x443e50, '??0' + MB + 'QAE@XZ'),
        (0x63fad0, '?announceID@' + MB + 'UAEXPBVXmlNameValuePair@@PAVInstance@2@@Z'),
        (0x443eb0, '?announceIDREF@' + MB + 'UAEXPBVXmlNameValuePair@@PAVDescribedBase@Reflection@2@PBVIIDREF@2@@Z'),
        (0x443d60, '?resolveRefs@' + MB + 'UAE_NXZ'),
        (0x4440a0, '?processID@' + MB + 'MAE_NPBVXmlNameValuePair@@PAVInstance@2@@Z'),
        (0x444a70, '?processIDREF@' + MB + 'MAE_NPBVXmlNameValuePair@@PAVDescribedBase@Reflection@2@PBVIIDREF@2@@Z'),
        (0x4449f0, '?push_back@' + VEC),
        (0x4445c0, '?insert@' + VEC),
        (0x4442c0, '?_Insert_n@' + VEC),
        (0x444050, '??$_Uninit_fill_n@PA' + IT),
        (0x443c60, '?erase@' + VEC),
        (0x443a60, '??$_Destroy_range@V?$allocator@' + IT + '@std@@@std@@YAXPA' + IT + '0AAV?$allocator@' + IT
                   + '@0@U_Nonscalar_ptr_iterator_tag@0@@Z'),
        (0x443a10, '??$unchecked_copy@PA' + IT),
        (0x443400, '??$_Copy_opt@PA' + IT + 'PAU123@Uforward_iterator_tag@std@@@std@@'),
        (0x4c6d40, '?_Xlen@' + VEC),                       # folded with vector<weak_ptr<PartInstance>>::_Xlen
        (0x67c5e0, '??$_Allocate@' + IT),
        (0x444000, '??$_Uninit_copy@PA' + IT),
        (0x444250, '?_Ufill@' + VEC),
        (0x443c40, '?_Destroy@' + VEC),
        (0x443ec0, '??0IDREFItem@' + MB + 'QAE@ABU012@@Z'),
        (0x42b1e0, '??1IDREFItem@' + MB + 'QAE@XZ'),       # folded COMDAT outside the unit
        (0x444290, '??$_Umove@PA' + IT),
        (0x444200, '??$_Unchecked_move_backward@PA' + IT),
        (0x443f80, '??$_Fill@PA' + IT),
        (0x443ef0, '??$_Copy_backward_opt@PA' + IT + 'PAU123@Uforward_iterator_tag@std@@@std@@'),
        (0x618a40, '??$shared_from@VInstance@RBX@@@RBX@@YA'),
        (0x4a2070, '??$shared_static_cast@VInstance@RBX@@V12@@boost@@'),
        (0x42af90, '?shared_from_this@?$enable_shared_from_this@VInstance@RBX@@@boost@@'),
        (0x411ad0, '??0shared_count@detail@boost@@QAE@ABVweak_count@12@@Z'),
        (0x4116c0, '??$throw_exception@Vbad_weak_ptr@boost@@@boost@@'),
        (0x411120, '?add_ref_lock@sp_counted_base@detail@boost@@QAE_NXZ'),
    ],
}
# Externals: the address the original instruction uses (call sites read in the original disassembly).
EXTERNAL = {
    '?print@StandardOut@RBX@@QAAXW4MessageType@2@PBDZZ': (0x5693a0, 'evidence name'),
    '?singleton@StandardOut@RBX@@SA?AV?$shared_ptr@VStandardOut@RBX@@@boost@@XZ': (0x569620, 'evidence name'),
    '?g_strmgr@ATL@@3VCAtlStringMgr@1@A': (0x97f2ec, 'atls.lib CAtlStringMgr; same address as record_native_output_view'),
    '?AtlThrowImpl@ATL@@YGXJ@Z': (0x401000, 'atls.lib AtlThrowImpl (library body, not this unit); same address as '
                                            'record_native_output_view; ThrowMemoryException 004066b0 calls it'),
    '?empty@InstanceHandle@RBX@@QBE_NXZ': (0x4dc3d0, 'evidence name'),
    '?isValueEqual@XmlNameValuePair@@QBE_NPBVName@RBX@@@Z': (0x57c1b0, 'evidence name'),
    '?getValue@XmlNameValuePair@@QBE_NAAVInstanceHandle@RBX@@@Z': (0x57c6e0, 'evidence name'),
    '?linkTo@InstanceHandle@RBX@@QAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z': (0x594d60, 'evidence name'),
    '?value_IDREF_nil@@3ABVName@RBX@@B': (0x975384, 'reference slot read by processID 00444153 and processIDREF '
                                                     '00444b9e (consistency)'),
}
NOT_EXACT = [
    ('00443cf0', 'std::vector<IDREFItem>::~vector (111 bytes): not emitted here (no MergeBinder destructor is '
                 'instantiated by this unit; ArchiveBinder and stack users destroy it).'),
]

LOCAL_EH = nb.LOCAL_EH
binding = {}


def target_of(address):
    parts = address if isinstance(address, tuple) else (address,)
    code, relocs = b'', []
    for part in parts:
        assert part == parts[0] + len(code), ('extents not contiguous', [hex(p) for p in parts])
        body, refs, _ = match.target('2008-06', '%08x' % part)
        relocs += [r + len(code) for r in refs]
        code += body
    return code, relocs


def first(address):
    return address[0] if isinstance(address, tuple) else address


def throw_info_type(value):
    array = d(value + 12)
    assert d(array) >= 1
    return original.string(d(d(array + 4) + 4) + 8)


def verify(obj, rows, own):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    funcs = match.coff_functions(raw)
    bodies = {n: (b, r) for n, b, r in funcs}
    result = []
    for address, key in rows:
        hits = [x[0] for x in funcs if x[0] == key] or \
               [x[0] for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        assert len(hits) == 1, (key, hits)
        name = hits[0]
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        assert set(target_refs) <= set(refs), (name, 'missing original relocation')
        assert match.exact_match(target, target_refs, body, refs), (name, hex(first(address)), len(body), len(target))
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        base = first(address)
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            assert kind in (6, 20), (name, symbol, 'unsupported relocation', kind)
            if kind == 20:
                value = (base + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
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
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                assert rtti == '.?AV' + symbol[4:symbol.index('@@6B') + 2], (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol.startswith('__TI'):
                cls = symbol[symbol.index('?'):]
                assert throw_info_type(value) == '.' + cls, (name, symbol, hex(value), throw_info_type(value))
                how = 'throw info, first catchable type .%s' % cls
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            else:
                assert symbol in EXTERNAL and EXTERNAL[symbol][0] == value, (name, symbol, hex(value))
                why = EXTERNAL[symbol][1]
                if why == 'evidence name':
                    assert names.get(value) == symbol, (symbol, hex(value), names.get(value))
                how = 'external (%s)' % why
            assert binding.setdefault(symbol, value) == value, ('two addresses', symbol, hex(binding[symbol]), hex(value))
            verified[symbol] = '%s %s' % (hex(value), how)
        result.append({'address': '+'.join('%08x' % a for a in (address if isinstance(address, tuple) else (address,))),
                       'symbol': name, 'size': len(body), 'exact': True, 'verified_targets': verified,
                       'local_eh': sorted(local)})
    return result


def resolve_names(obj, rows):
    funcs = [x[0] for x in match.coff_functions(Path(obj).read_bytes())]
    out = {}
    for address, key in rows:
        hits = [n for n in funcs if n == key] or [n for n in funcs if n.startswith(key) and not LOCAL_EH.match(n)]
        assert len(hits) == 1, (key, hits)
        out[hits[0]] = first(address)
    return out


rows = []
for obj, group in ((md5_obj, 'md5'), (mb_obj, 'mb')):
    rows += verify(obj, ROWS[group], resolve_names(obj, ROWS[group]))
own = {r['symbol']: int(r['address'].split('+')[0], 16) for r in rows}

# ---- vtables (current-header objects) ---------------------------------------------------------------
text = next(x for x in original.pe.sections if x.Name.startswith(b'.text'))
TEXT = (original.image + text.VirtualAddress, original.image + text.VirtualAddress + text.Misc_VirtualSize)


def original_slots(vt):
    n = 0
    while TEXT[0] <= d(vt + 4 * n) < TEXT[1]:
        n += 1
    return n


def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, index = definitions[symbol]
    section = sections[index]
    slots = {}
    for i in range(section[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
        if offset >= start and kind == 6:
            slots[(offset - start) // 4] = symbols[sym][0]
    return slots


VTABLES = [(md5_obj, '??_7' + MD5 + '6B@', 0x82dc9c), (mb_obj, '??_7' + MB + '6B@', 0x81593c)]
vtables = []
for obj, symbol, vt in VTABLES:
    assert binding[symbol] == vt, (symbol, hex(binding[symbol]))
    assert original.vtable_class(vt) == ('.?AV' + symbol[4:-3], 0), (hex(vt), original.vtable_class(vt))
    slots = vtable_slots(obj, symbol)
    count = original_slots(vt)
    assert len(slots) == count == 5, (symbol, slots, count)
    entries = {}
    for slot, name in sorted(slots.items()):
        value = d(vt + 4 * slot)
        assert own.get(name) == value, (symbol, slot, name, hex(value))
        entries[slot] = '%s -> %s (own row)' % (name, hex(value))
    vtables.append({'vtable': hex(vt), 'symbol': symbol, 'rtti_offset': 0, 'original_slots': count, 'slots': entries})

# ---- RTTI base lists: Impl -> interface, single inheritance, no virtual base ---------------------------
for vt, cls, iface in ((0x82dc9c, MD5, 'MD5Hasher@RBX@@'), (0x81593c, MB, 'IReferenceBinder@RBX@@')):
    hierarchy = d(d(vt - 4) + 16)
    assert d(hierarchy + 4) == 0, hex(d(hierarchy + 4))
    items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
    bases = [(original.string(d(item) + 8), d(item + 4), struct.unpack('<i', original.data(item + 8, 4))[0])
             for item in items]
    assert bases == [('.?AV' + cls, 1, 0), ('.?AV' + iface, 0, 0)], bases

# ---- allocation size: MD5Hasher::create 0055c8b0 -> new(0x28); ArchiveBinder ctor calls ??0MergeBinder ------
body, _, _ = match.target('2008-06', '0055c8b0')
assert body[0x55c8c6 - 0x55c8b0:][:2] == b'\x6a\x28' and body[0x55c8c8 - 0x55c8b0] == 0xe8
body, _, _ = match.target('2008-06', '00592940')
at = body[0x59295f - 0x592940:]
assert at[0] == 0xe8 and (0x59295f + 5 + struct.unpack('<i', at[1:5])[0]) & 0xffffffff == 0x443e50
assert body[0x59296d - 0x592940:][:3] == b'\x8d\x4e\x1c'        # ArchiveBinder's own map starts at +0x1c

sha = nb.sha
paths = [Path(__file__).resolve(), MD5_UNIT, MB_UNIT, LAYOUT] + HEADERS
assert all(Path(p).stat().st_mtime_ns < started_ns and nb.sha(Path(p)) == digest
           for p, digest in dependencies.items()), 'included header changed during verification'
exact_addresses = sorted({a for r in rows for a in r['address'].split('+')})
receipt = {
    'class': 'RBX::MD5HasherImpl (MD5Hasher::create), RBX::MergeBinder',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'md5': md5_flags, 'mergebinder': mb_flags},
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'dependencies': dependencies,
    'provider_ownership': {'RBX::MergeBinder': str(MB_UNIT.relative_to(ROOT)),
                           'note': 'Existing metadata provider reused; fork duplicate source/header excluded. No runtime selection changed.'},
    'objects': {p.name: sha(p) for p in (layout_obj, md5_obj, mb_obj)},
    'layout': 'MD5HasherImpl 0x28 (hProv +4, hHash +8, std::string result +0xc); MergeBinder 0x1c (vector<IDREFItem> '
              '+4, IDREFItem 0x10); both 5-slot vtables without a destructor slot.',
    'methods': rows, 'not_exact': NOT_EXACT, 'vtables': vtables, 'proposals': [],
    'exact_distinct_addresses': exact_addresses,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(OUT / 'receipt.json' if args.out else ROOT / 'work/2008-06/shared-layouts/misc-leaves-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native MD5HasherImpl/MergeBinder: %d exact rows (%d distinct addresses), %d not-exact; %d vtables; '
      'targets verified' % (len(rows), len(exact_addresses), len(NOT_EXACT), len(vtables)))
