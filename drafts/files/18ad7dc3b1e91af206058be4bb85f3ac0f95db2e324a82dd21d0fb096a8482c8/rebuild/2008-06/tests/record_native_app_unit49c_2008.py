"""Verify the inactive 2008-06 native rows of the application range 0049c000..004a8000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map`; rows counted by other receipts in
`range_rows_counted_by_other_receipts`, written as 'ADDR counted by RECEIPT' text, never as quoted bare addresses):
  * Network/Players.cpp tail ..0049e28f (AbuseReporter, Players::OnReceive / reportAbuse): network-players owner.
  * Network/CrashReporter.cpp 0049e290..0049e50f, the services / settings descriptors 0049e510..0049ed2f,
    Network/Client.cpp 0049ed30..004a156f, ClientProxy / Server.cpp 004a1570..004a37af with the Message / Hint
    COMDATs 004a37a0..004a4d9f (effects owner) and Server.cpp continued ..004a504f: other owners, not built here.
  * RakNet 3.x BitStream.cpp library code 004a5090..004a593f and the G3D inline bodies isFinite 004a5940 /
    Vector3::isFinite 004a59e0 / Vector3::clamp 004a6100: library, never counted here (verified as library evidence
    or support bodies where this unit calls them).
  * Network/Streaming.cpp 004a5a30..004a7fff (continues past 004a8000): the RBX::Network BitStream operators,
    brick-vector / CoordinateFrame streaming, enum / string / BrickColor property streaming
    (native-classes/AppUnit49C_2008Streaming.cpp against the new native-headers/AppUnit49C_2008/Streaming2008.h),
    and the STL instances on the IdSerializer / StringSender element types
    (native-classes/AppUnit49C_2008IdSerializerTemplates.cpp, explicit instantiations against the read-only
    native-headers/Network/IdSerializer.h).

Builds (document-swap flags, VS2008 RTM 21022, RakNet 3.x headers tools/rbxgs/Client/Network/raknet30/Source):
  * streaming: AppUnit49C_2008Streaming.cpp with /fp:fast (isBrickLocation's x87 compares need it);
  * templates: AppUnit49C_2008IdSerializerTemplates.cpp;
  * library evidence (never counted): the RakNet 3.x BitStream.cpp and StringCompressor.cpp sources and the G3D
    Matrix3.cpp source (all read-only under tools/rbxgs), to prove the bodies the counted rows call (WriteBits,
    ReadBits, Write0/1, StringCompressor::Instance/EncodeString/DecodeString, Matrix3 copy) exact at the addresses the
    original calls.
There is no pending build. No unit declares a class with a vtable, so there is no vtable slot check.

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, constants and string literals by bytes, RTTI
type descriptors by name, throw infos by their catchable type names, own symbols by the row proven here, COMDAT
support bodies and library bodies by exactness at the bound address, rows counted by other receipts by that receipt,
the remaining externals by evidence name. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit49c-2008-working.json.
Set NATIVE_APP_UNIT49C_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit49c-2008'
OUT.mkdir(parents=True, exist_ok=True)
RAKNET = ROOT / 'tools/rbxgs/Client/Network/raknet30/Source'
SOURCES = {'streaming': R / 'native-classes/AppUnit49C_2008Streaming.cpp',
           'templates': R / 'native-classes/AppUnit49C_2008IdSerializerTemplates.cpp'}
LIBRARY_SOURCES = {'bitstream': RAKNET / 'BitStream.cpp', 'compressor': RAKNET / 'StringCompressor.cpp',
                   'matrix3': ROOT / 'tools/rbxgs/Client/Rendering/g3d/G3Dcpp/Matrix3.cpp'}
HEADERS = [R / 'native-headers' / h for h in ('AppUnit49C_2008/Streaming2008.h', 'Network/IdSerializer.h',
                                               'reflection/property.h', 'reflection/enumconverter.h')]
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT49C_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit49c-2008-working.json'
UNIT_FLAGS = {'streaming': ['/fp:fast'], 'templates': []}
LO, HI = 0x49c000, 0x4a8000


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = ['/I' + str(RAKNET)] + nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('NativeAppUnit49C_2008_' + _k, _src, UNIT_FLAGS[_k])
LIB_OBJ = {}
for _k, _src in LIBRARY_SOURCES.items():
    LIB_OBJ[_k], FLAGS['library-' + _k] = build('Library_' + _k, _src)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]

N = 'Network@RBX@@YAAAVBitStream@RakNet@@AAV23@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
CP = 'ABVConstProperty@Reflection@1@AAVBitStream@RakNet@@@Z'
PP = 'AAVProperty@Reflection@1@AAVBitStream@RakNet@@@Z'
STREAMING_ROWS = [
    (0x4a5a30, '?serializeEnum@Network@RBX@@YAXABVConstProperty@Reflection@2@AAVBitStream@RakNet@@@Z'),
    (0x4a5a70, '?deserializeEnum@Network@RBX@@YAXAAVProperty@Reflection@2@AAVBitStream@RakNet@@@Z'),
    (0x4a5b10, '??6' + N + '_N@Z'),
    (0x4a5b30, '??5' + N + 'AA_N@Z'),
    (0x4a5bc0, '?brickEq@Network@RBX@@YA_NMM@Z'),
    (0x4a5c00, '?isBrickLocation@Network@RBX@@YA_NABVVector3@G3D@@AAFAAG1@Z'),
    (0x4a61a0, '??6' + N + 'H@Z'),
    (0x4a61d0, '??5' + N + 'AAJ@Z'),
    (0x4a6250, '??5' + N + 'AAH@Z'),
    (0x4a62d0, '??5' + N + 'AAI@Z'),
    (0x4a6350, '??6' + N + 'E@Z'),
    (0x4a6380, '??5' + N + 'AAE@Z'),
    (0x4a6400, '??6' + N + 'M@Z'),
    (0x4a6430, '??5' + N + 'AAM@Z'),
    (0x4a64b0, '??6' + N + 'N@Z'),
    (0x4a64e0, '??5' + N + 'AAN@Z'),
    (0x4a6560, '??6' + N + 'AB' + STR + '@Z'),
    (0x4a6610, '??5' + N + 'AA' + STR + '@Z'),
    (0x4a6700, '?writeBrickVector@Network@RBX@@YAXAAVBitStream@RakNet@@ABVVector3@G3D@@@Z'),
    (0x4a67c0, '?readBrickVector@Network@RBX@@YAXAAVBitStream@RakNet@@AAVVector3@G3D@@@Z'),
    (0x4a69a0, '??6' + N + 'ABVVector3@G3D@@@Z'),
    (0x4a6a00, '?rationalize@Network@RBX@@YAXAAVCoordinateFrame@G3D@@@Z'),
    (0x4a6ab0, '??6' + N + 'ABVCoordinateFrame@G3D@@@Z'),
    (0x4a6cd0, '??5' + N + 'AAVVector3@G3D@@@Z'),
    (0x4a6d00, '??$serialize@' + STR + '@Network@RBX@@YAX' + CP),
    (0x4a6d60, '??$deserialize@' + STR + '@Network@RBX@@YAX' + PP),
    (0x4a7000, '??5' + N + 'AAVBrickColor@1@@Z'),
    (0x4a7460, '??$getValue@VBrickColor@RBX@@@ConstProperty@Reflection@RBX@@QBE?AVBrickColor@2@XZ'),
    (0x4a74c0, '??$setValue@VBrickColor@RBX@@@Property@Reflection@RBX@@QAEXABVBrickColor@2@@Z'),
    (0x4a75b0, '??$deserialize@VBrickColor@RBX@@@Network@RBX@@YAX' + PP),
]
# exact bytes but not counted (see NOT_EXACT): operator>>(CoordinateFrame&) 004a6b80 calls ReadNormQuat<float>
# 004a5f20, whose body is a later RakNet BitStream.h shape than the raknet30 header builds (461/466 B).
UNCOUNTED_EXACT = [(0x4a6b80, '??5' + N + 'AAVCoordinateFrame@G3D@@@Z')]

W = 'UWaitItem@IdSerializer@Network@RBX@@'
VWC = '?$vector@' + W + 'V?$allocator@' + W + '@std@@@std@@'   # class scope
VW = 'V' + VWC                                                     # as a template argument
GT = '?$_Tree@V?$_Tmap_traits@UData@Guid@RBX@@' + VW
ST = '?$_Tree@V?$_Tmap_traits@' + STR + 'EU?$less@'
# (address, symbol prefix, contains): when ICF-identical symbols of this unit share the address, the one the original
# call site uses is named (the binding of the callers' relocations checks it).
TEMPLATE_ROWS = [
    (0x4a6ea0, '?_Lbound@' + GT, ''),
    (0x4a6ee0, '??$_Copy_backward_opt@PA' + W + 'PAU1234@Uforward_iterator_tag@std@@@std@@', ''),
    (0x4a7280, '??$_Distance2@Viterator@' + ST, ''),
    (0x4a72c0, '??$_Fill@PA' + W + 'U1234@@std@@', ''),
    (0x4a7340, '??$_Copy_backward_opt@PA' + W + 'PAU1234@@std@@', ''),
    (0x4a73a0, '?_Eqrange@' + ST, 'AU?$pair@Viterator'),
    (0x4a7520, '??$_Uninit_copy@PB' + W, ''),
    (0x4a7720, '?_Insert@' + ST, ''),
    (0x4a7960, '??$_Unchecked_move_backward@PA' + W, ''),
    (0x4a7990, '??$_Uninit_fill_n@PA' + W, ''),
    (0x4a79e0, '??$_Destroy_range@V?$allocator@' + W, '_Nonscalar_ptr_iterator_tag'),
    (0x4a7a30, '?insert@' + ST, 'QAE?AU?$pair@Viterator'),
    (0x4a7b20, '?find@' + GT, 'QAE?AViterator'),
    (0x4a7c60, '?_Ufill@' + VWC, ''),
    (0x4a7d10, '?_Destroy@' + VWC, ''),
    (0x4a7d30, '?erase@' + ST, 'QAEIAB'),
    (0x4a7da0, '?_Tidy@' + VWC, ''),
    (0x4a7df0, '??$_Ucopy@PA' + W + '@' + VWC, ''),
    (0x4a7fa0, '??1' + VWC + 'QAE@XZ', ''),
]

# ---- externals ---------------------------------------------------------------------------------------------------
EXTERNAL = {
    '?colorPalette@BrickColor@RBX@@SAABV?$vector@VBrickColor@RBX@@V?$allocator@VBrickColor@RBX@@@std@@@std@@XZ': 0x5b5c80,
    '?getClosestPaletteIndex@BrickColor@RBX@@QBEIXZ': 0x5b5c90,
    '??MData@Guid@RBX@@QBE_NABU012@@Z': 0x5a8210,
}
# CRT helpers the original calls directly (not imports): bound by the call site; the body is the CRT's.
CRT = {'__alloca_probe_16': 0x6a1560, '__chkstk': 0x6a1560, '__ftol2_sse': 0x6a17f0}
# rows counted by other receipts (bound by the call site; the receipt must count the address)
COUNTED_ELSEWHERE = {
    '??0Quaternion@RBX@@QAE@ABVMatrix3@G3D@@@Z': (0x5dd570, 'app-unit5dc-2008-working.json'),
    '?toRotationMatrix@Quaternion@RBX@@QBEXAAVMatrix3@G3D@@@Z': (0x5dd6d0, 'app-unit5dc-2008-working.json'),
    '?isAxisAligned@Math@RBX@@SA_NABVMatrix3@G3D@@@Z': (0x5ddc20, 'app-unit5dc-2008-working.json'),
    '?getOrientId@Math@RBX@@SAHABVMatrix3@G3D@@@Z': (0x5ddc90, 'app-unit5dc-2008-working.json'),
    '?idToMatrix3@Math@RBX@@SAXHAAVMatrix3@G3D@@@Z': (0x5ddce0, 'app-unit5dc-2008-working.json'),
    '?orthonormalizeIfNecessary@Math@RBX@@SA_NAAVMatrix3@G3D@@@Z': (0x5df0a0, 'app-unit5dc-2008-working.json'),
}
# RakNet 3.x library bodies (BitStream.cpp / StringCompressor.cpp): proven exact at the address by the library build.
LIBRARY = {
    '?WriteBits@BitStream@RakNet@@QAEXPBEH_N@Z': (0x4a5600, 'bitstream'),
    '?ReadBits@BitStream@RakNet@@QAE_NPAEH_N@Z': (0x4a5210, 'bitstream'),
    '?Write0@BitStream@RakNet@@QAEXXZ': (0x4a5540, 'bitstream'),
    '?Write1@BitStream@RakNet@@QAEXXZ': (0x4a5560, 'bitstream'),
    '?Instance@StringCompressor@@SAPAV1@XZ': (0x4ba230, 'compressor'),
    '?EncodeString@StringCompressor@@QAEXPBDHPAVBitStream@RakNet@@H@Z': (0x4ba4f0, 'compressor'),
    '?DecodeString@StringCompressor@@QAE_NPADHPAVBitStream@RakNet@@H@Z': (0x4ba650, 'compressor'),
    # operator<<(CoordinateFrame) 004a6abd copies the rotation through 00513220 (evidence name: Matrix3::operator=;
    # the G3D Matrix3.cpp copy constructor builds to the identical body, one ICF-folded copy)
    '??0Matrix3@G3D@@QAE@ABV01@@Z': (0x513220, 'matrix3'),
}
# COMDAT bodies this build also emits (library inline / header templates or ICF-shared): exact at the bound address;
# support rows, never counted here.
SUPPORT = {
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,
    '??$Read@_N@BitStream@RakNet@@QAE_NAA_N@Z': 0x4a5050,                 # RakNet BitStream.h template
    '?isFinite@G3D@@YA_NN@Z': 0x4a5940,                                   # G3D inline
    '?clamp@Vector3@G3D@@QBE?AV12@ABV12@0@Z': 0x4a6100,                   # G3D inline
    '??$WriteNormQuat@M@BitStream@RakNet@@QAEXMMMM@Z': 0x4a5dd0,          # RakNet BitStream.h template
    '?getStringValue@ConstProperty@Reflection@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x449410,
    '??0CoordinateFrame@G3D@@QAE@ABV01@@Z': 0x476670,
}
# The map<std::string, unsigned char> _Buynode 004a71e0 keeps its catch block as the separate row 004a7267: the built
# body is compared split at the original extent (135 + 21 bytes). Support, not counted.
SPLIT = {}
STR_TREE_TAIL = ('U?$less@' + STR + '@std@@V?$allocator@U?$pair@$$CB' + STR + 'E@std@@@4@$0A@@std@@')
UNBOUND = []
binding = {}
support_out = {}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for row in rows:
        address, key = row[0], row[1]
        contains = row[2] if len(row) > 2 else ''
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and contains in x[0]
                                                      and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:160] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def throw_info_names(value):
    """Catchable type names of a ThrowInfo (attributes, unwind, forward-compat, CatchableTypeArray)."""
    array = d(value + 12)
    return [original.string(d(d(array + 4 + 4 * i) + 4) + 8) for i in range(d(array))]


LIB_BODIES = {k: {n: (b, r) for n, b, r in match.coff_functions(Path(v).read_bytes())} for k, v in LIB_OBJ.items()}
lib_out = {}


def bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own):
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
        elif symbol.startswith('??_C@'):
            pos, at = definitions[symbol]
            literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
            how = 'string %r' % literal[:-1].decode('latin-1')[:48]
        elif symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
            how = 'RTTI type %s' % rtti
        elif symbol.startswith('__TI'):
            got = throw_info_names(value)
            cls = symbol[symbol.index('?'):]
            assert got and got[0] == '.' + cls, (name, symbol, hex(value), got)
            how = 'throw info, catchable types %s' % ' '.join(got)
        elif symbol.startswith('??_7') and symbol.endswith('@@6B@'):
            rtti, offset_in_object = original.vtable_class(value)
            assert rtti == '.?AV' + symbol[4:-3] and offset_in_object == 0, (name, symbol, hex(value), rtti)
            how = 'vtable (RTTI %s)' % rtti
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in LIBRARY:
            at, lib = LIBRARY[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            lbody, lrefs = LIB_BODIES[lib][symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, lbody, lrefs), ('library body not exact', symbol, hex(value))
            lib_out[symbol] = '%s (library %s, body exact here; not counted)' % (hex(value), LIBRARY_SOURCES[lib].name)
            how = 'library body exact at the bound address (%s)' % LIBRARY_SOURCES[lib].name
        elif symbol in SUPPORT:
            assert SUPPORT[symbol] == value, (name, symbol, hex(value), hex(SUPPORT[symbol]))
            sbody, srefs = bodies[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out.setdefault(symbol, {'address': hex(value), 'reached_from': name,
                                            'note': 'COMDAT support body, exact at the bound address; not counted'})
            how = 'support body exact at the bound address'
        elif symbol in SPLIT:
            at, tail_at = SPLIT[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            sbody, srefs = bodies[symbol]
            head, head_refs = target_of(at)
            tail, tail_refs = target_of(tail_at)
            assert len(head) + len(tail) == len(sbody), (symbol, len(head), len(tail), len(sbody))
            hrefs = [x for x in srefs if x < len(head)]
            trefs = [x - len(head) for x in srefs if x >= len(head)]
            assert match.exact_match(head, head_refs, sbody[:len(head)], hrefs), ('split head not exact', symbol)
            assert match.exact_match(tail, tail_refs, sbody[len(head):], trefs), ('split tail not exact', symbol)
            support_out.setdefault(symbol, {'address': hex(value), 'reached_from': name,
                                            'note': 'body exact split at the original extent, catch block at %s; '
                                                    'not counted' % hex(tail_at)})
            how = 'support body exact split at the original extent (catch block %s)' % hex(tail_at)
        elif symbol in COUNTED_ELSEWHERE:
            at, receipt = COUNTED_ELSEWHERE[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
            assert '%08x' % value in data['exact_function_rows'], (symbol, receipt)
            how = 'row counted by %s' % receipt
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else ' (call site)')
        elif symbol in CRT:
            assert CRT[symbol] == value, (name, symbol, hex(value))
            how = 'CRT helper (call site)'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own, count=True):
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
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, bodies, name, body, target, address, own)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


# the string-map _Buynode (symbol of this build) for the SPLIT check
_tpl_funcs = [x[0] for x in match.coff_functions(Path(OBJ['templates']).read_bytes())]
_buy = [n for n in _tpl_funcs if n.startswith('?_Buynode@' + ST) and 'PAU_Node' in n and n.count('@') > 30]
_buy = [n for n in _buy if 'ABU?$pair' in n]
assert len(_buy) == 1, _buy
SPLIT[_buy[0]] = (0x4a71e0, 0x4a7267)
# ICF-shared tree rotations: the original's copies carry the map<Guid::Data, vector<WaitItem> > evidence names
for _n in _tpl_funcs:
    if _n.startswith('?_Lrotate@' + ST):
        SUPPORT[_n] = 0x68df00
    if _n.startswith('?_Rrotate@' + ST):
        SUPPORT[_n] = 0x68cfd0
    if _n.startswith('?_Dec@const_iterator@' + ST):
        SUPPORT[_n] = 0x68d350
    if _n.startswith('?_Inc@const_iterator@' + ST) or _n.startswith('?_Inc@const_iterator@' + GT):
        SUPPORT[_n] = 0x68d1a0
    if _n.startswith('?erase@' + ST) and _n.endswith('QAE?AViterator@12@Vconst_iterator@12@0@Z'):
        SUPPORT.setdefault(_n, 0x46af90)   # ICF-shared with set<ContentId>::erase(first, last) (evidence name)
    if _n.startswith('??$_Uninit_copy@PA' + W):
        SUPPORT[_n] = 0x4a7520   # ICF-identical to the counted _Uninit_copy<const WaitItem*> row
    if _n.startswith('??$_Destroy_range@V?$allocator@' + W) and '_Nonscalar' not in _n:
        SUPPORT[_n] = 0x4a79e0   # the forwarding overload, inlined in the original: never called there

ROWS_BY_OBJ = {'streaming': STREAMING_ROWS, 'templates': TEMPLATE_ROWS}
resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS_BY_OBJ.items()}
uncounted_resolved = resolve(OBJ['streaming'], UNCOUNTED_EXACT)
counted = []
for k, rows in resolved.items():
    own = {name: address for address, name in rows}
    if k == 'streaming':
        own.update({name: address for address, name in uncounted_resolved})
    for r in verify(k, rows, own):
        r['unit'] = k
        counted.append(r)
# 004a6b80: bytes exact; every target but ReadNormQuat<float> verified (that one is bound by the call site only)
_raw = Path(OBJ['streaming']).read_bytes()
_bodies = {n: (b, r) for n, b, r in match.coff_functions(_raw)}
uncounted_rows = []
for address, name in uncounted_resolved:
    body, refs = _bodies[name]
    target, target_refs = target_of(address)
    uncounted_rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                           'bytes_exact': match.exact_match(target, target_refs, body, refs), 'counted': False})
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in counted:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in counted)


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
            # older receipts: any entry marked exact outside pending sections (methods, rows, *_methods, trials)
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk({k: v for k, v in data.items() if 'pending' not in k})
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for r in counted})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '%08x' % LO <= a < '%08x' % HI}
FUNCTIONS = [json.loads(x) for x in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()]
RANGE_ROWS = sorted(x['addr'] for x in FUNCTIONS if LO <= int(x['addr'], 16) < HI)
assert set(exact_rows) <= set(RANGE_ROWS), sorted(set(exact_rows) - set(RANGE_ROWS))


# ---- unit-map evidence checks (strings, RTTI) ------------------------------------------------------------------------
def cstr(a, n=96):
    return original.data(a, n).split(b'\0')[0].decode('latin-1')


MAP_CHECKS = []
for at, want in ((0x823d2c, 'BitStream string write: String too long'),
                 (0x823d80, 'BitStream >> std::string: failed to read length'),
                 (0x823e40, 'BitStream >> CoordinateFrame orientId failed'),
                 (0x823e70, 'BitStream >> BrickColor failed')):
    assert cstr(at) == want, (hex(at), cstr(at))
    MAP_CHECKS.append('string %s %r' % (hex(at), want))
for vt, want in ((0x823b6c, '.?AVHint@RBX@@'), (0x82534c, '.?AVIdSerializer@Network@RBX@@')):
    rtti = original.vtable_class(vt)
    assert rtti and rtti[0] == want, (hex(vt), rtti)
    MAP_CHECKS.append('vtable %s RTTI %s' % (hex(vt), want))
for at, want in ((0x49e290, '?ProcessException@CrashReporter@@UAEJPAU_EXCEPTION_POINTERS@@@Z'),
                 (0x49e040, '??0AbuseReporter@Network@RBX@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
                 (0x4a1070, '?OnReceive@Client@Network@RBX@@UAE?AW4PluginReceiveResult@@PAVRakPeerInterface@@PAUPacket@@@Z'),
                 (0x4a4dc0, '?OnReceive@Server@Network@RBX@@UAE?AW4PluginReceiveResult@@PAVRakPeerInterface@@PAUPacket@@@Z'),
                 (0x4a5940, '?isFinite@G3D@@YA_NN@Z')):
    assert names.get(at) == want, (hex(at), names.get(at))
    MAP_CHECKS.append('evidence name %s %s' % (hex(at), want[:70]))

UNIT_MAP = {
    'players ..0049e28f': (
        'Network/Players.cpp (starts below 0049c000): AbuseReporter (data ctor/dtor 0049d1a0 / 0049d140, '
        'shared_count<data> 0049df90, AbuseReporter(std::string) 0049e040, add 0049c710, the worker_thread bind '
        'holder 0049c440), Players::reportAbuse 0049c7b0 / 0049ca70, OnReceive 0049d770 and the signal2<void(string, '
        'shared_ptr<Instance>)> instance 0049cec0 / fire 0049d2b0. Owner: native Network/Players.h '
        '(network-players receipt); not rebuilt here.'),
    'crash-reporter 0049e290..0049e50f': (
        'Network/CrashReporter.cpp: CrashReporter::ProcessException 0049e290, CrashExceptionFilter 0049e490, '
        'PreventSetUnhandledExceptionFilter 0049e4a0, Start 0049e500 (evidence names). No native header; not built.'),
    'settings 0049e510..0049ed2f': (
        'Described<GlobalSettings> / NetworkSettings classDescriptor bodies (0049ec10, 0049ec80), shared_count rows '
        '(creatable-shared-count) and services rows; other owners.'),
    'client 0049ed30..004a156f': (
        'Network/Client.cpp: FactoryProduct<Client> / Client dtor and thunks, BoundFuncDesc<Client> 0049ee50 / '
        '0049fbb0, Client::onServiceProvider 0049fe50, OnReceive 004a1070, onEvent(Closing) 0049f130 (pending in '
        'network-client-server2008). Owner: native Network/Client2008.h.'),
    'server 004a1570..004a504f': (
        'Network/Server.cpp with ClientProxy (isReplicator 004a17f0, Server::stop 004a1880, ClientProxy thunks '
        '004a19a0.., getClientCount 004a2250, visitDescendents 004a27e0, ClientProxy::OnReceive 004a2c20, '
        'Server::onServiceProvider 004a4100, OnReceive 004a4dc0), with the Message / Hint COMDATs 004a37a0..004a4d9f '
        '(~FactoryProduct<Message> 004a3980, ~Message 004a3a90, Hint thunks, getClassName, classDescriptor, '
        'create<Message> 004a3850 / create<Hint> 004a4d40; vtable 00823b6c .?AVHint@RBX@@): owners of '
        'Network/Server2008.h / ClientProxy2008.h and v8datamodel/Message.h (effects receipt).'),
    'raknet-bitstream 004a5050..004a593f': (
        'RakNet 3.x BitStream.cpp library code (BitStream ctors/dtor 004a5090 / 004a5120 / 004a51a0, ReadBits '
        '004a5210, ReadCompressed 004a52c0, AddBitsAndReallocate 004a53b0, Write0/Write1 004a5540 / 004a5560, '
        'WriteBits 004a5600, WriteCompressed 004a5790 ...) and the inline template Read<bool> 004a5050. Library: '
        'never counted; WriteBits / ReadBits / Write0 / Write1 are proven exact here as library evidence.'),
    'g3d-inline 004a5940, 004a59e0, 004a6100': (
        'G3D inline bodies emitted in this unit: isFinite(double), Vector3::isFinite, Vector3::clamp (callers in '
        'other units too). Library; exact here as support bodies.'),
    'streaming 004a5a30..004a7fff': (
        'Network/Streaming.cpp (strings "BitStream >> int failed", "BitStream string write: String too long", '
        '"readBrickVector x failed", "BitStream >> CoordinateFrame orientId failed", "BitStream >> BrickColor '
        'failed"): serializeEnum / deserializeEnum, the operator<< / operator>> family, brickEq, the static '
        'isBrickLocation, write/readBrickVector, rationalize, CoordinateFrame streaming, serialize / deserialize '
        '<std::string> and <BrickColor>, ConstProperty::getValue / Property::setValue<BrickColor>; the RakNet '
        'header templates WriteNormQuat<float> 004a5dd0 / ReadNormQuat<float> 004a5f20; StringReceiver::receive '
        '004a6e20 / 004a6f70, operator>>(Guid::Data) 004a70b0, deserializeString 004a7150, StringSender::trySend '
        '004a7ba0 / send 004a7e20 (members not declared by Network/IdSerializer.h); the STL instances on '
        'IdSerializer::WaitItem, map<Guid::Data, vector<WaitItem> > and map<std::string, unsigned char>. Built here.'),
}

NOT_EXACT = [
    {'address': 'operator>>(BitStream&, CoordinateFrame&) 004a6b80', 'reason': 'Bytes exact (recorded in '
     'uncounted_exact_rows), but not counted: its call target ReadNormQuat<float> 004a5f20 is a RakNet BitStream.h '
     'template body of a later RakNet than the raknet30 header (raknet30 builds 461/466 B: the original multiplies by '
     '1/65535 and branches per sign), so that target is bound by the call site only.'},
    {'address': 'serialize<BrickColor> 004a7570', 'reason': '50/56 B: the original copies the getValue result into a '
     'second local before getClosestPaletteIndex; the variants tried are in rejected.'},
    {'address': 'StringReceiver::receive 004a6e20 / 004a6f70, StringSender::trySend 004a7ba0 / send 004a7e20, '
     'deserializeString 004a7150, operator>>(Guid::Data) 004a70b0, IdSerializer members', 'reason': 'Need member '
     'declarations Network/IdSerializer.h does not have (read-only here; proposal filed). Not attempted.'},
    {'address': 'for_each<vector<WaitItem>::iterator, bind(setRefValue)> 004a7920', 'reason': 'needs the '
     'IdSerializer::setRefValue declaration (proposal); not attempted.'},
    {'address': 'map<std::string, unsigned char>::_Buynode 004a71e0 and its catch block 004a7267', 'reason': 'exact '
     'split at the original extent (support row of _Insert 004a7720), not counted: the row extent excludes the catch '
     'funclet the compiler emits inside the function.'},
    {'address': 'ICF-shared generic bodies', 'reason': '5-byte / 9-byte / 6-byte bodies this build also emits '
     '(fill / ~map / assign 004a7d00 and the identical rows 0049e580.., 0049ed30, 0049f610) are not attributable to '
     'this unit and are not counted.'},
]

REJECTED = {
    'isBrickLocation with external linkage': '272/267 B: the original passes v in esi (static function convention).',
    'rationalize with value.translation.clamp(low, high)': '174/176 B: the original calls G3D::clamp(Vector3(-1e6), '
                                                            'translation, Vector3(1e6)), i.e. clamps the temporary.',
    'serialize<BrickColor> with a named copy (BrickColor value = getValue)': '50/56 B (copy elided)',
    'serialize<BrickColor> with unsigned index': '50/56 B',
    'serialize<BrickColor> with BrickColor(value).getClosestPaletteIndex()': '58/56 B',
    'serialize<BrickColor> with default-constructed value then assignment': '64/56 B',
    'ReadNormQuat<float> from raknet30 BitStream.h, with or without /fp:fast': '430/466 and 461/466 B',
}

PROPOSALS = [
    'native-headers/Network/IdSerializer.h (Replicator family owner): declare the 2008 streaming members built in the '
    'Streaming.cpp unit: StringReceiver::receive(RakNet::BitStream&, std::string&) (004a6e20; reads the unsigned char '
    'id with operator>> 004a6380, a 0x80 id is followed by operator>>(std::string&) 004a6610 and stored in '
    'strings[id & 0x7f], else strings[id] is copied) and receive(RakNet::BitStream&, const Name*&) (004a6f70, '
    'Name::declare 00553f90); StringSender::trySend(RakNet::BitStream&, const std::string&) (004a7ba0, dictionary '
    'find 00696f30, WriteBits 8) and send (004a7e20); IdSerializer::setRefValue(WaitItem&, Instance*) (for_each '
    '004a7920). With them those rows can be built in native-classes/AppUnit49C_2008Streaming.cpp.',
]

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
counted_set = set(exact_rows)
receipt = {
    'class': 'RBX::Network streaming rows (Network/Streaming.cpp) of the application range 0049c000..004a8000 '
             '(2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'library_sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in LIBRARY_SOURCES.values()},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'range_rows': len(RANGE_ROWS),
    'unit_map': UNIT_MAP,
    'unit_map_checks': MAP_CHECKS,
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any quoted bare address in another receipt as counted there.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_counted': ' '.join(a for a in RANGE_ROWS if a not in range_counted and a not in counted_set),
    'rows': counted,
    'uncounted_exact_rows': ['%s %s: %d/%d B, bytes exact %s; not counted (see not_exact)' % (
        r['address'], r['symbol'][:80], r['size'], r['target_size'], r['bytes_exact']) for r in uncounted_rows],
    'support_rows': support_out,
    'library_evidence': lib_out,
    'pending_rows': [],
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit49c-2008: %d counted exact rows (%s); 0 pending-build-only, %d range rows, %d counted elsewhere, '
      '%d support rows, %d library bodies, %d uncounted exact' % (
          len(exact_rows), ' '.join(exact_rows), len(RANGE_ROWS), len(range_counted), len(support_out), len(lib_out),
          len(uncounted_rows)))
