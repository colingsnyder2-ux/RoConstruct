"""Verify the inactive 2008-06 native rows of the application range 0046c000..00474000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, checked below; rows counted by other receipts
are written as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * 0046c230..0046cabf: the tail of Workspace.cpp, the ATL COM CWorkspace scripting object (execScript / execUrl /
    the site-trust check; workspace-*-trial receipts, CWorkspace.h owner): mapped, not rebuilt here.
  * 0046cac0..0046fc0f: RBX::LDraw2Lua (LDraw -> Lua converter: color / part map loaded from
    fonts\\LDraw2RobloxMap.xml, LDraw part commands, the Lua writer, the parser and stringCompareNoCase). The
    committed native sources native-classes/LDraw*.cpp with the native util/LDrawMapRoot.h / LDrawEntities.h /
    LDrawParser.h (another owner: compiled read-only, unchanged, each with the include directories of its own
    `native-flags` line on top of the document-swap flags) are exact for almost every row of the unit.
  * 0046fc10..00473fff: G3D 6.09 GLG3Dcpp GLCaps.cpp and Texture.cpp (library; not recovered).

No new header is created (nothing is shadowed). The LDraw rows come from the committed LDraw sources compiled
unchanged; the one new source, native-classes/AppUnit46CStringIterators.cpp, explicitly instantiates the
std::string const_iterator operator* kept at 0046f940 (/O1 and the opt-in std-noinline-string-iterators xstring,
pinned in its native-flags line). The RTTI of the vtables 0081ca00 / 0081ca0c / 0081cbd4 names the classes
LuaObjectWriter / LDrawCommand(: LuaObjectWriter) / LuaWriter, which util/LDrawEntities.h declares as LDrawItem /
LDrawPart / LDrawModel. Rows whose relocations name those vtables are therefore not counted from the current
header (exact=false, rtti-name-mismatch); they are built a second time from generated pending copies of that
header and of LDrawEntityLifetime.cpp under out/app-unit46c/pending/ with the RTTI names, and recorded
exact=false (pending-build-only) when exact there (proposal for the header owner). Members of those classes that do
not reference a vtable (writeShape .. writeLua, LuaWriter::writeLua / add / ??_G, vector<LDrawItem*>::at) are
counted: their bytes and every call / data target verify.

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, string literals and constants by bytes, vtables by original
RTTI (and their slots against the current-header objects), own rows by row address, the tag_* Name references by
their static initializers (string + global write), and the remaining helpers by a compiled body exact at the bound
address (never counted). Rows split by the analysis at a catch funclet (or merged with the next function) are
recorded as bounds evidence only. Writes work/2008-06/shared-layouts/app-unit46c-working.json.
NATIVE_APP_UNIT46C_DISCOVER=1 lists unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit46c'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT46C_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit46c-working.json'
LO, HI = 0x46c000, 0x474000
NC = R / 'native-classes'
# committed LDraw sources of another owner, compiled read-only and unchanged
SOURCES = {k: NC / ('LDraw%s.cpp' % k) for k in (
    'MapOperations', 'MapRootConstructor', 'MapRootLifetime', 'EntityLifetime', 'ModelWrite', 'Parser',
    'ParserParse', 'PartColor', 'PartParent', 'PartShape', 'PartTransform', 'PartWrite', 'StringCompare')}
HEADERS = [R / 'native-headers/util' / h for h in ('LDrawMapRoot.h', 'LDrawEntities.h', 'LDrawParser.h')]
HEADER_DIR = R / 'native-headers'


def pinned_profile(src, allowed_extra=()):
    """The source's own `native-flags` line: its /I directories go first; every other flag must already be in the
    document-swap base flags (checked) or be one of allowed_extra (appended)."""
    m = re.search(r'^// native-flags: (.*)$', src.read_text(), re.M)
    assert m, src
    base = set(nb.flags())
    first, extra = [], []
    for f in m.group(1).split():
        if f.startswith('/I'):
            first.append(Path(f[2:].replace('{headers}', str(HEADER_DIR))))
        elif f not in base:
            assert f in allowed_extra, (src.name, f)
            extra.append(f)
    EXTRA[src] = extra
    return first


EXTRA = {}


def build(name, src, first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + ['/I' + str(p) for p in first] + flags[i:] + EXTRA.get(src, []) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS, FIRST = {}, {}, {}
for _k, _src in SOURCES.items():
    FIRST[_k] = pinned_profile(_src)
    OBJ[_k], FLAGS[_k] = build('AppUnit46C_' + _k, _src, FIRST[_k])
# new source of this lease: the std::string const_iterator operator* instance 0046f940 (/O1 pinned, see the source)
OWN_SOURCES = {'StringIterators': NC / 'AppUnit46CStringIterators.cpp'}
for _k, _src in OWN_SOURCES.items():
    FIRST[_k] = pinned_profile(_src, ('/O1',))
    OBJ[_k], FLAGS[_k] = build('AppUnit46C_' + _k, _src, FIRST[_k])

# evidence builds (not counted): the committed LDrawAssetState.cpp (currentMap and its atexit destructor) and
# LDrawPath.cpp (resolveMapPath), compiled read-only to bind the parser's data / call targets
EVIDENCE_SOURCES = {k: NC / ('LDraw%s.cpp' % k) for k in ('AssetState', 'Path')}
for _k, _src in EVIDENCE_SOURCES.items():
    FIRST[_k] = pinned_profile(_src)
    OBJ[_k], FLAGS[_k] = build('AppUnit46C_' + _k, _src, FIRST[_k])

# ---- pending build: a generated copy of util/LDrawEntities.h with the RTTI class names -----------------------------
PENDING = OUT / 'pending'
(PENDING / 'util').mkdir(parents=True, exist_ok=True)
_ent = (HEADER_DIR / 'util/LDrawEntities.h').read_text()
RENAMES = [('LDrawItem', 'LuaObjectWriter'), ('LDrawPart', 'LDrawCommand'), ('LDrawModel', 'LuaWriter')]
assert _ent.count('#include "LDrawMapRoot.h"') == 1
_pend = _ent.replace('#include "LDrawMapRoot.h"', '#include "util/LDrawMapRoot.h"')
for old, new in RENAMES:
    _pend = re.sub(r'\b%s\b' % old, new, _pend)
(PENDING / 'util/LDrawEntities.h').write_text(
    '// generated by tests/record_native_app_unit46c.py (pending build only; proposal for util/LDrawEntities.h:\n'
    '// the RTTI of vtables 0081ca00 / 0081ca0c / 0081cbd4 names LuaObjectWriter / LDrawCommand / LuaWriter)\n'
    + _pend)
_src = SOURCES['EntityLifetime'].read_text()
for old, new in RENAMES:
    _src = re.sub(r'\b%s\b' % old, new, _src)
PENDING_SRC = PENDING / 'LDrawEntityLifetime.cpp'
PENDING_SRC.write_text('// generated by tests/record_native_app_unit46c.py: native-classes/LDrawEntityLifetime.cpp with '
                       'the RTTI class names (pending build only)\n' + _src)
OBJ['EntityLifetime_pending'], FLAGS['EntityLifetime_pending'] = build(
    'AppUnit46C_EntityLifetime_pending', PENDING_SRC, [PENDING] + FIRST['EntityLifetime'])

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)


def norm(s):
    return s.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- counting rules ----------------------------------------------------------------------------------------------
def counted_elsewhere():
    """Rows other receipts count: their top-level exact_function_rows (or an equivalent key); for receipts without
    one, every row object marked exact anywhere in the receipt (a conservative reading of their counted lists)."""
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
        for key in ('exact_function_rows', 'exact_addresses', 'exact_unique_addresses', 'exact_distinct_addresses'):
            if isinstance(data.get(key), (list, dict)):
                rows = list(data[key])
                break
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    for v in o.values():
                        walk(v)
            walk(data)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()

# ---- rows: (address, build, symbol prefix) -------------------------------------------------------------------------
NS = '@LDraw2Lua@RBX@@'
NRP = 'UNativeRobloxPart' + NS
VNRP = '?$vector@' + NRP + 'V?$allocator@' + NRP + '@std@@@std@@'
CMAP = '?$_Tmap_traits@HPAVLDraw2RobloxColorMap' + NS
ROWS = [
    # LDraw2RobloxColorMap / LDraw2RobloxPartMap / NativeRobloxPart / LDraw2RobloxMapRoot members
    (0x46cac0, 'MapOperations', '??0LDraw2RobloxColorMap' + NS + 'QAE@HH@Z'),
    (0x46cae0, 'MapOperations', '??_GLDraw2RobloxColorMap' + NS + 'UAEPAXI@Z'),
    (0x46cb00, 'MapOperations', '?getFilename@LDraw2RobloxPartMap' + NS),
    (0x46cb30, 'MapOperations', '??1NativeRobloxPart' + NS + 'QAE@XZ'),
    (0x46cb80, 'MapOperations', '?readFidelity@LDraw2RobloxMapRoot' + NS),
    (0x46cc80, 'MapOperations', '?readShape@LDraw2RobloxMapRoot' + NS),
    (0x46cde0, 'MapOperations', '?readFormFactor@LDraw2RobloxMapRoot' + NS),
    (0x46cee0, 'MapRootConstructor', '?_Min@?$_Tree@V' + CMAP),
    (0x46cf00, 'MapOperations', '??$_Transform@PADPADP6AHH@Z'),
    (0x46cfa0, 'MapOperations', '??$_Transform@PADV?$_String_iterator@'),
    (0x46d010, 'MapOperations', '?findColor@LDraw2RobloxMapRoot' + NS),
    (0x46d080, 'MapOperations', '?mapColor@LDraw2RobloxMapRoot' + NS),
    (0x46d0a0, 'MapOperations', '?findPart@LDraw2RobloxMapRoot' + NS),
    (0x46d110, 'MapOperations', '?findPartCaseInsensitive@LDraw2RobloxMapRoot' + NS),
    (0x46d1f0, 'MapRootConstructor', '?insert@?$_Tree@V' + CMAP),
    (0x46d3d0, 'MapRootConstructor', '??A?$map@HPAVLDraw2RobloxColorMap' + NS),
    (0x46d480, 'MapOperations', '?addPartMap@LDraw2RobloxMapRoot' + NS),
    (0x46d580, 'MapRootLifetime', '??1?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVLDraw2RobloxPartMap' + NS),
    (0x46d590, 'MapRootLifetime', '??1LDraw2RobloxMapRoot' + NS + 'UAE@XZ'),
    (0x46d6f0, 'MapRootLifetime', '??_GLDraw2RobloxMapRoot' + NS + 'UAEPAXI@Z'),
    (0x46d710, 'MapRootConstructor', '??0LDraw2RobloxMapRoot' + NS),
    (0x46deb0, 'MapOperations', '??0NativeRobloxPart' + NS + 'QAE@ABU012@@Z'),
    (0x46df20, 'MapOperations', '??$_Fill@PAUNativeRobloxPart' + NS),
    (0x46df70, 'MapOperations', '??$_Copy_backward_opt@PAUNativeRobloxPart' + NS + 'PAU123@Uforward_iterator_tag'),
    (0x46dfc0, 'MapOperations', '?_Xran@' + VNRP),
    (0x46e040, 'MapOperations', '??$_Allocate@UNativeRobloxPart' + NS),
    (0x46e0a0, 'MapOperations', '??$_Uninit_copy@PAUNativeRobloxPart' + NS),
    (0x46e180, 'MapOperations', '??$_Uninit_fill_n@PAUNativeRobloxPart' + NS),
    (0x46e210, 'MapOperations', '??$_Destroy_range@V?$allocator@UNativeRobloxPart' + NS),
    (0x46e280, 'MapOperations', '?at@' + VNRP),
    (0x46e310, 'MapOperations', '?_Ufill@' + VNRP),
    (0x46e350, 'MapOperations', '?_Destroy@' + VNRP),
    (0x46e370, 'MapOperations', '?getPart@LDraw2RobloxPartMap' + NS),
    (0x46e390, 'MapOperations', '??$_Umove@PAUNativeRobloxPart' + NS),
    (0x46e3c0, 'MapOperations', '??1' + VNRP),
    (0x46e430, 'MapOperations', '?_Insert_n@' + VNRP),
    (0x46e6b0, 'MapOperations', '??0LDraw2RobloxPartMap' + NS),
    (0x46e790, 'MapOperations', '??1LDraw2RobloxPartMap' + NS + 'UAE@XZ'),
    (0x46e800, 'MapOperations', '?insert@' + VNRP),
    (0x46e8c0, 'MapOperations', '??_GLDraw2RobloxPartMap' + NS + 'UAEPAXI@Z'),
    (0x46e8e0, 'MapOperations', '?push_back@' + VNRP),
    (0x46e960, 'MapOperations', '?addPart@LDraw2RobloxPartMap' + NS),
    (0x46e970, 'MapOperations', '??0NativeRobloxPart' + NS + 'QAE@HHV'),
    # LuaObjectWriter / LDrawCommand (header: LDrawItem / LDrawPart)
    (0x46ea00, 'EntityLifetime', '??1LDrawItem' + NS + 'UAE@XZ'),
    (0x46ea10, 'EntityLifetime', '??_GLDrawItem' + NS + 'UAEPAXI@Z'),
    (0x46ea30, 'EntityLifetime', '??0LDrawPart' + NS),
    (0x46eae0, 'EntityLifetime', '??_GLDrawPart' + NS + 'UAEPAXI@Z'),
    (0x46eb40, 'PartShape', '?writeShape@LDrawPart' + NS),
    (0x46ecf0, 'PartColor', '?writeColor@LDrawPart' + NS),
    (0x46ed40, 'PartTransform', '?writeTransform@LDrawPart' + NS),
    (0x46ef70, 'PartParent', '?writeParent@LDrawPart' + NS),
    (0x46f000, 'PartWrite', '?writeLua@LDrawPart' + NS),
    # LDrawParser
    (0x46f100, 'Parser', '??1LDrawParser' + NS + 'UAE@XZ'),
    (0x46f110, 'Parser', '??0LDrawParser' + NS),
    (0x46f1d0, 'Parser', '??_GLDrawParser' + NS + 'UAEPAXI@Z'),
    (0x46f200, 'ParserParse', '?parse@LDrawParser' + NS),
    # LuaWriter (header: LDrawModel)
    (0x46f5a0, 'EntityLifetime', '?at@?$vector@PAVLDrawItem' + NS),
    (0x46f630, 'EntityLifetime', '??0LDrawModel' + NS),
    (0x46f6b0, 'ModelWrite', '?writeLua@LDrawModel' + NS),
    (0x46f820, 'EntityLifetime', '??1LDrawModel' + NS + 'UAE@XZ'),
    (0x46f900, 'EntityLifetime', '??_GLDrawModel' + NS + 'UAEPAXI@Z'),
    (0x46f920, 'EntityLifetime', '?add@LDrawModel' + NS),
    # stringCompareNoCase and its std::string const_iterator instances
    (0x46f940, 'StringIterators', '??D?$_String_const_iterator@'),
    (0x46f980, 'StringCompare', '??E?$_String_const_iterator@'),
    (0x46f9c0, 'StringCompare', '??8?$_String_const_iterator@'),
    (0x46f9f0, 'StringCompare', '?stringCompareNoCase@@'),
]
# Rows whose vtable relocations name a class by a header name the RTTI contradicts: rebuilt in the pending build.
PENDING_ROWS = {0x46ea00: '??1LuaObjectWriter' + NS + 'UAE@XZ', 0x46ea10: '??_GLuaObjectWriter' + NS + 'UAEPAXI@Z',
                0x46ea30: '??0LDrawCommand' + NS, 0x46eae0: '??_GLDrawCommand' + NS + 'UAEPAXI@Z',
                0x46f630: '??0LuaWriter' + NS, 0x46f820: '??1LuaWriter' + NS + 'UAE@XZ'}
# rows split at a catch funclet (or merged with the next function) by the analysis: bounds evidence only
SPANS = []
MERGED = []
# tag_* Name references (LDrawMapTags.cpp): initializer row -> tag text
TAG_INIT = {'tag_schema_version': 0x7efb60, 'tag_color_map': 0x7efb80, 'tag_color': 0x7efba0,
            'tag_ldraw_code': 0x7efbc0, 'tag_roblox_code': 0x7efbe0, 'tag_part_map': 0x7efc00, 'tag_part': 0x7efc20,
            'tag_name': 0x7efc40, 'tag_description': 0x7efc60, 'tag_ldraw_filename': 0x7efc80,
            'tag_mapping_fidelity': 0x7efca0, 'tag_roblox_part': 0x7efcc0, 'tag_shape': 0x7efce0,
            'tag_form_factor': 0x7efd00, 'tag_size_vect3': 0x7efd20, 'tag_y_offset': 0x7efd40}
EXTERNAL = {}
USED_EXTERNAL = set()

BODIES = {}     # build -> {symbol: (body, refs)}
INDEX = {}
RAW = {}
for k, obj in OBJ.items():
    RAW[k] = Path(obj).read_bytes()
    INDEX[k] = match._coff_data_index(RAW[k])
    BODIES[k] = {n: (b, r) for n, b, r in match.coff_functions(RAW[k]) if not nb.LOCAL_EH.match(n)}


def find(build, prefix, address=None):
    """The one compiled symbol with that prefix; several instances sharing a prefix (overloads) are told apart by
    the row's bytes (relocation-masked, same size)."""
    hits = [n for n in BODIES[build] if n.startswith(prefix)]
    if len(hits) > 1 and address is not None:
        t, tr, _ = match.target('2008-06', '%08x' % address)
        hits = [n for n in hits if len(BODIES[build][n][0]) == len(t)
                and match.exact_match(t, tr, BODIES[build][n][0], BODIES[build][n][1])]
    assert len(hits) == 1, (build, prefix, hits)
    return hits[0]


SYM = {a: (b, find(b, p, a)) for a, b, p in ROWS}
OWN = {}
for a, (b, s) in SYM.items():
    assert OWN.setdefault(s, a) == a, (s, hex(a))
BINDING = {}
UNBOUND = []
HELPERS = {}
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def any_body(symbol):
    for k in BODIES:
        if symbol in BODIES[k]:
            return BODIES[k][symbol]
    return None


def resolve(build, name, address, target):
    """Yield (offset, symbol, original value) for each relocation of the compiled body against the original."""
    raw = RAW[build]
    sections, symbols, definitions, _ = INDEX[build]
    start, section = definitions[name]
    table = sections[section]
    code = raw[table[4] + start:]
    body = BODIES[build][name][0]
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
        yield offset, symbol, value


def classify(build, symbol, value, where, own, rtti_names=True):
    raw = RAW[build]
    sections, symbols, definitions, _ = INDEX[build]
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('__real@'):
        assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (where, symbol)
        return 'constant %s' % symbol[7:]
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'string %r' % literal[:-1].decode('latin-1')
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        if value in PENDING_ROWS:
            return 'row of this range, byte-exact here (not counted: rtti-name-mismatch)'
        return 'own row'
    if symbol in SPLIT:
        assert SPLIT[symbol][0] == value, (where, symbol, hex(value))
        return SPLIT[symbol][1]
    if symbol in DATA_EVIDENCE:
        assert DATA_EVIDENCE[symbol][0] == value, (where, symbol, hex(value))
        return DATA_EVIDENCE[symbol][1]
    if symbol.startswith('__TI') and symbol[4:5].isdigit():
        # ThrowInfo -> CatchableTypeArray (count, first CatchableType) -> TypeDescriptor name
        count = int(symbol[4])
        cta = d(value + 12)
        assert d(cta) == count, (where, symbol, hex(value), d(cta))
        name = original.string(d(d(cta + 4) + 4) + 8)
        assert name == '.' + symbol[5:], (where, symbol, hex(value), name)
        return 'ThrowInfo of %s (%d catchable types)' % (name, count)
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        cls = symbol[4:symbol.index('@@6B') + 2]
        if norm(rtti) != norm('.?AV' + cls):
            assert not rtti_names, (where, symbol, hex(value), rtti)
            return None
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol.startswith('?tag_') and symbol.endswith('@@3ABVName@RBX@@B'):
        tag = symbol[1:symbol.index('@@')]
        init = FUNCTIONS[TAG_INIT[tag]]
        assert init['strings'] == [tag[4:]] and init['global_writes'] == ['%#x' % value], (where, symbol, init)
        return 'Name reference written by its static initializer %#x (Name::declare(%r))' % (TAG_INIT[tag], tag[4:])
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        USED_EXTERNAL.add(symbol)
        return 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
    body = any_body(symbol)
    if body is not None and TEXT[0] <= value < TEXT[1] and value in FUNCTIONS:
        ht, htr, _ = match.target('2008-06', '%08x' % value)
        if len(ht) == len(body[0]) and match.exact_match(ht, htr, body[0], body[1]):
            HELPERS.setdefault(symbol, '%#x' % value)
            return 'helper body exact at the bound address (not counted here)'
    if names.get(value, '') == symbol:
        return 'external (evidence name)'
    return None


def verify(rows, record=True, rtti_names=True, own=None):
    own = OWN if own is None else own
    out = []
    for address, build, name in rows:
        body, refs = BODIES[build][name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = len(target) == len(body) and match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'build': build, 'size': len(body),
               'target_size': len(target), 'exact': bool(exact), 'verified_targets': {}}
        out.append(row)
        if not exact:
            continue
        for offset, symbol, value in resolve(build, name, address, target):
            if nb.LOCAL_EH.match(symbol):
                continue
            where = '%08x+%#x' % (address, offset)
            how = classify(build, symbol, value, where, own, rtti_names)
            if how is None:
                if rtti_names or not symbol.startswith('??_7'):
                    UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                row['exact'] = False
                row.setdefault('rtti_name_mismatch', []).append('%s -> %#x (RTTI %s)' % (
                    symbol, value, original.vtable_class(value)[0]) if symbol.startswith('??_7') else symbol)
                continue
            if record:
                bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


# ---- split / merged rows: bounds evidence (computed first: their callers bind them) -------------------------------
BOUNDS = []
SPLIT = {}
for parts, build, prefix in SPANS:
    name = find(build, prefix)
    body, refs = BODIES[build][name]
    data, relocs = b'', []
    for a in parts:
        t, tr, _ = match.target('2008-06', '%08x' % a)
        assert a == parts[0] + len(data), ('rows not contiguous', hex(a))
        relocs += [x + len(data) for x in tr]
        data += t
    ok = len(data) == len(body) and match.exact_match(data, relocs, body, refs)
    assert ok or DISCOVER, ('bounds evidence', hex(parts[0]))
    SPLIT[name] = (parts[0], 'split row: compiled body exact against the joined extent (bounds_evidence, not counted)')
    BOUNDS.append({'rows': ' + '.join('%#x' % a for a in parts), 'symbol': name, 'compiled_size': len(body),
                   'joined_size': len(data), 'exact_when_joined': ok,
                   'reason': 'one function: the try body and its catch(...) funclet (destroy the constructed '
                             'elements and rethrow, __CxxThrowException); the analysis splits it at the funclet. '
                             'Relocation-masked exact against the joined extent. Not counted (extent fix needed; '
                             'bounds.json is not changed here).'})
for a, build, prefix in MERGED:
    name = find(build, prefix)
    body, refs = BODIES[build][name]
    t, tr, _ = match.target('2008-06', '%08x' % a)
    head = [x for x in tr if x < len(body)]
    ok = len(t) > len(body) and match.exact_match(t[:len(body)], head, body, refs)
    pad = t[len(body):]
    k = len(pad) - len(pad.lstrip(b'\xcc'))
    nxt = a + len(body) + k
    assert ok and nxt % 16 == 0 or DISCOVER, hex(a)
    SPLIT[name] = (a, 'merged row: compiled body exact as the row prefix (bounds_evidence, not counted)')
    BOUNDS.append({'rows': '%#x' % a, 'symbol': name, 'compiled_size': len(body), 'row_size': len(t),
                   'exact_prefix': ok,
                   'reason': 'the analysed row is two functions: _Uninit_copy<NativeRobloxPart*> (%d B, exact as the '
                             'row prefix, its catch(...) funclet inside) then int3 padding and a second function at '
                             '%#x (%d B, the copy-backward wrapper that calls 0x46df70). Not counted (extent fix '
                             'needed).' % (len(body), nxt, a + len(t) - nxt)})

# ---- data / helper evidence from the evidence builds -------------------------------------------------------------
DATA_EVIDENCE = {}
EVIDENCE_ROWS = [  # (address, build, symbol prefix, note): exact bodies outside the range (never counted)
    (0x7faff0, 'AssetState', '??__FcurrentMap@LDraw2Lua@RBX@@YAXXZ', 'atexit destructor of currentMap'),
    (0x55d0b0, 'Path', '?resolveMapPath@LDraw2Lua@RBX@@', 'resolveMapPath (caller 0x46f110 among others)'),
]
evidence_checks = []
for a, build, prefix, note in EVIDENCE_ROWS:
    name = find(build, prefix)
    body, refs = BODIES[build][name]
    t, tr, _ = match.target('2008-06', '%08x' % a)
    ok = len(t) == len(body) and match.exact_match(t, tr, body, refs)
    assert ok or DISCOVER, (hex(a), name)
    targets = {}
    for offset, symbol, value in resolve(build, name, a, t):
        if not nb.LOCAL_EH.match(symbol):
            targets[symbol] = value
    if name.startswith('??__FcurrentMap'):
        cm = '?currentMap@LDraw2Lua@RBX@@3V?$auto_ptr@VLDraw2RobloxMapRoot@LDraw2Lua@RBX@@@std@@A'
        assert any(lo <= targets[cm] < hi for lo, hi in DATA_SECTIONS), hex(targets[cm])
        DATA_EVIDENCE[cm] = (targets[cm], 'global read and deleted by its atexit destructor %#x (exact there)' % a)
    else:
        DATA_EVIDENCE[name] = (a, 'helper body exact at the bound address (not counted; %s)' % note)
    evidence_checks.append({'row': '%#x (outside the range, not counted)' % a, 'symbol': name, 'exact': ok,
                            'note': note, 'targets': {k: '%#x' % v for k, v in targets.items()}})

current_rows = [(a, b, s) for a, (b, s) in sorted(SYM.items())]
groups = verify([r for r in current_rows if r[0] not in PENDING_ROWS])
mismatch = verify([r for r in current_rows if r[0] in PENDING_ROWS], record=False, rtti_names=False)
for r in mismatch:
    assert not r['exact'] and r.get('rtti_name_mismatch'), r['address']
    r['note'] = 'rtti-name-mismatch: not counted from the current header'
# pending build: the same EntityLifetime.cpp against the generated header copy with the RTTI names
pend_rows = [(a, 'EntityLifetime_pending', find('EntityLifetime_pending', p, a)) for a, p in sorted(PENDING_ROWS.items())]
pend_own = dict(OWN)
for a, _, s in pend_rows:
    pend_own[s] = a
pending = verify(pend_rows, record=False, own=pend_own)
for r in pending:
    r['pending_build_only'] = True
    r['exact_in_pending_build'] = r['exact']
    r['exact'] = False
not_exact = [r for r in groups if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact + pending:
        print('ROW', r['address'], r['exact'], r.get('exact_in_pending_build'), r['size'], r['target_size'],
              r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
assert all(r['exact_in_pending_build'] for r in pending) or DISCOVER, pending
assert sorted(USED_EXTERNAL) == sorted(EXTERNAL), sorted(set(EXTERNAL) - USED_EXTERNAL)


# ---- vtables: RTTI of the original vtable, slots against the current-header objects ---------------------------------
def compiled_vtable(build, symbol):
    raw = RAW[build]
    sections, symbols, definitions, _ = INDEX[build]
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start and (offset - start) % 4 == 0:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


VTABLES = [  # (original vtable, build, compiled vtable symbol, RTTI the original names)
    (0x81c8b8, 'MapOperations', '??_7LDraw2RobloxColorMap' + NS + '6B@', '.?AVLDraw2RobloxColorMap' + NS),
    (0x81c904, 'MapRootLifetime', '??_7LDraw2RobloxMapRoot' + NS + '6B@', '.?AVLDraw2RobloxMapRoot' + NS),
    (0x81c9f8, 'MapOperations', '??_7LDraw2RobloxPartMap' + NS + '6B@', '.?AVLDraw2RobloxPartMap' + NS),
    (0x81cb74, 'Parser', '??_7LDrawParser' + NS + '6B@', '.?AVLDrawParser' + NS),
    (0x81ca00, 'EntityLifetime', '??_7LDrawItem' + NS + '6B@', '.?AVLuaObjectWriter' + NS),
    (0x81ca0c, 'EntityLifetime', '??_7LDrawPart' + NS + '6B@', '.?AVLDrawCommand' + NS),
    (0x81cbd4, 'EntityLifetime', '??_7LDrawModel' + NS + '6B@', '.?AVLuaWriter' + NS),
]
SLOT_SYMBOLS = dict(OWN)
SLOT_SYMBOLS.update({s: a for a, s in [(0x46ea10, '??_GLDrawItem' + NS + 'UAEPAXI@Z'),
                                       (0x46eae0, '??_GLDrawPart' + NS + 'UAEPAXI@Z')]})
vtable_checks = []
for vt, build, symbol, rtti in VTABLES:
    got = original.vtable_class(vt)
    assert got == (rtti, 0), (hex(vt), got)
    slots = compiled_vtable(build, symbol)
    n = 0
    while TEXT[0] <= d(vt + 4 * n) < TEXT[1]:
        n += 1
    assert n == len(slots), (hex(vt), n, slots)
    detail = []
    for i, s in enumerate(slots):
        value = d(vt + 4 * i)
        if s == '__purecall':
            assert original.imported(value) is not None and original.imported(value)[1] == '_purecall', (hex(vt), i)
            detail.append('slot %d _purecall (import)' % i)
        else:
            if s.startswith('??_E') and any_body(s) is None:
                s = '??_G' + s[4:]      # the scalar ??_E slot resolves to ??_G (no vector delete emitted)
            assert SLOT_SYMBOLS.get(s) == value, (hex(vt), i, s, hex(value))
            detail.append('slot %d %s row' % (i, s[:40]))
    name_ok = norm('.?AV' + symbol[4:symbol.index('@@6B') + 2]) == norm(rtti)
    vtable_checks.append({'vtable': '%#x' % vt, 'rtti': rtti, 'compiled': symbol, 'slots': detail,
                          'header_name_matches_rtti': name_ok})

# ---- unit map evidence -------------------------------------------------------------------------------------------
def holds_string(address, text):
    body = original.data(address, FUNCTIONS[address]['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if any(lo <= v < hi for lo, hi in DATA_SECTIONS):
            try:
                if original.string(v) == text:
                    return True
            except Exception:
                pass
    return False


def refs_vtable(address, vt):
    return struct.pack('<I', vt) in original.data(address, FUNCTIONS[address]['size'])


BLOCKS = [
    ('Workspace.cpp tail: ATL CWorkspace (other owners; continues from 0x46a940)', 0x46c000, 0x46cac0,
     [(0x46c430, 'Failed to get URL, %s'), (0x46c920, 'Untrusted Url: %s')], []),
    ('RBX::LDraw2Lua (rbx; native LDraw*.cpp)', 0x46cac0, 0x46fc10,
     [(0x46cb80, 'exact'), (0x46cc80, 'cylinder'), (0x46cde0, 'symmetric'), (0x46eb40, 'part = Instance.new("Part")'),
      (0x46f110, 'fonts\\LDraw2RobloxMap.xml'), (0x46f200, 'Roblox LDraw2Lua Conversion'),
      (0x46f6b0, 'local w = game:service("Workspace")')],
     [(0x46cac0, 0x81c8b8), (0x46d710, 0x81c904), (0x46e6b0, 0x81c9f8), (0x46ea30, 0x81ca0c), (0x46f110, 0x81cb74),
      (0x46f630, 0x81cbd4)]),
    ('G3D 6.09 GLG3Dcpp/GLCaps.cpp (library)', 0x46fc10, 0x4729d0,
     [(0x46fc50, 'GLCaps has not been initialized.'), (0x4716f0, '.\\glg3dcpp\\GLCaps.cpp')], []),
    ('G3D 6.09 GLG3Dcpp/Texture.cpp (library; continues past 0x474000)', 0x4729d0, HI,
     [(0x473250, '.\\glg3dcpp\\Texture.cpp'), (0x4739f0, '.\\glg3dcpp\\Texture.cpp')], []),
]
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _ in BLOCKS) == 1, hex(a)
for name, lo, hi, strings, vts in BLOCKS:
    for a, text in strings:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
    for a, vt in vts:
        assert lo <= a < hi and refs_vtable(a, vt), (name, hex(a), hex(vt))
# the last Workspace row before LDraw and the first G3D rows (evidence names)
assert names.get(0x46fc30) == '?iMin@G3D@@YAHHH@Z' and names.get(0x46fc40) == '?iMax@G3D@@YAHHH@Z'

# rows another receipt counts (ldraw-parse-trial counts parse 0x46f200): compiled exact here, not counted again
for r in groups:
    if r['address'] in elsewhere:
        r['counted_elsewhere'] = r['exact']
        r['exact'] = False
        r['address'] = '%#x counted by %s' % (int(r['address'], 16), ', '.join(sorted(set(elsewhere[r['address']]))))
exact_rows = sorted(r['address'] for r in groups if r['exact'])
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}
block_rows = {}
for name, lo, hi, _, _ in BLOCKS:
    rows = [a for a in range_rows if lo <= a < hi]
    block_rows[name] = {
        'rows': len(rows), 'bytes': sum(FUNCTIONS[a]['size'] for a in rows),
        'counted_here': sum('%08x' % a in exact_rows for a in rows),
        'counted_elsewhere': ['%#x counted by %s' % (a, ', '.join(range_counted['%08x' % a])) for a in rows
                              if '%08x' % a in range_counted],
        'first': '%#x' % rows[0], 'last': '%#x' % rows[-1]}
ldraw_open = ['%#x' % a for a in range_rows if 0x46cac0 <= a < 0x46fc10 and '%08x' % a not in exact_rows
              and '%08x' % a not in range_counted]
OPEN = {
    '0x46ea00 / 0x46ea10 / 0x46ea30 / 0x46eae0 / 0x46f630 / 0x46f820': (
        'LuaObjectWriter / LDrawCommand / LuaWriter dtor, ??_G, ctors: byte-exact from LDrawEntityLifetime.cpp, but '
        'their vtable relocations name ??_7LDrawItem / LDrawPart / LDrawModel while the RTTI of 0x81ca00 / 0x81ca0c / '
        '0x81cbd4 names LuaObjectWriter / LDrawCommand / LuaWriter: not counted (exact in the pending build).'),
    '0x46cf40 ??Y (operator+=) of std::_String_const_iterator<char>': (
        'std header COMDAT (callers 0x46cfc7 in _Transform 0x46cfa0, 0x48b866, 0x5f5e52, 0x64faf7). Same size (82 B) '
        'but not exact with the std-noinline-string-iterators xstring under /O2 or /O1: the original recomputes '
        '_Ptr + _Off for the second bound check (edx) and schedules push edi after the _invalid_parameter_noinfo '
        'load; the build reuses ecx. Plain xstring and std-noinline-string: 91 B (/O2, /O1, /Os; 21022 and '
        '50727). Open.'),
}
UNIT_MAP = {
    'workspace 0x46c000..0x46cabf': (
        'Workspace.cpp (ATL CComObject<CWorkspace> scripting object; CWorkspace.h / CRobloxDoc.h owners and the '
        'workspace-*-trial receipts): execScript 0x46c230 (workspace-execscript-port-mismatch), execUrl 0x46c430 '
        '("Failed to get URL, %s"; workspace-execurl-trial), 0x46c780 with its funclet row 0x46c8cb, the site-trust '
        'check 0x46c920 ("Untrusted Url: %s"). Other owners\' area: not rebuilt here.'),
    'ldraw 0x46cac0..0x46fc0f': (
        'RBX::LDraw2Lua, one unit in link order: LDraw2RobloxColorMap ctor 0x46cac0 / ??_G 0x46cae0 (vtable 0x81c8b8), '
        'PartMap::getFilename 0x46cb00, ~NativeRobloxPart 0x46cb30, readFidelity / readShape / readFormFactor '
        '0x46cb80 / 0x46cc80 / 0x46cde0 ("exact" / "cylinder" / "symmetric"), the map<int, ColorMap*> and '
        'std::transform instances, findColor / mapColor / findPart / findPartCaseInsensitive / addPartMap, '
        '~LDraw2RobloxMapRoot 0x46d590 / ??_G 0x46d6f0 / ctor 0x46d710 (vtable 0x81c904, TextXmlParser), the '
        'vector<NativeRobloxPart> instances 0x46deb0..0x46e3c0 / 0x46e800 / 0x46e8e0, LDraw2RobloxPartMap ctor / dtor '
        '/ ??_G 0x46e6b0 / 0x46e790 / 0x46e8c0 (vtable 0x81c9f8), LuaObjectWriter 0x46ea00 / 0x46ea10 (vtable '
        '0x81ca00), LDrawCommand 0x46ea30..0x46f000 (vtable 0x81ca0c: ctor, ??_G, writeShape / writeColor / '
        'writeTransform / writeParent / writeLua), LDrawParser 0x46f100..0x46f200 (vtable 0x81cb74, '
        '"fonts\\\\LDraw2RobloxMap.xml", parse), LuaWriter 0x46f5a0..0x46f920 (vtable 0x81cbd4) and '
        'stringCompareNoCase 0x46f9f0 with its std::string const_iterator instances 0x46f940..0x46f9c0. The '
        'tag_* Name references are initialised at 0x7efb60..0x7efd40; initializeAssetFolder is 0x55c3e0 (outside).'),
    'g3d-glcaps 0x46fc10..0x4729cf': (
        'G3D 6.09 GLG3Dcpp/GLCaps.cpp (library): G3D inlines iClamp / iMin / iMax 0x46fc10..0x46fc40, the supports_* '
        'inlines, init / loadExtensions 0x4716f0, Table / Set instances and ReferenceCountedObject (0x4729b0 counted '
        'by user-controller-working.json). Not recovered.'),
    'g3d-texture 0x4729d0..0x473fff': (
        'G3D 6.09 GLG3Dcpp/Texture.cpp (library; continues in app-unit474). Not recovered.'),
}
PROPOSALS = {
    'util/LDrawEntities.h (LDraw owner; not edited)': (
        'Rename LDrawItem -> LuaObjectWriter, LDrawPart -> LDrawCommand, LDrawModel -> LuaWriter (and the '
        'definitions in native-classes/LDrawEntityLifetime.cpp, LDrawModelWrite.cpp, LDrawPart*.cpp, '
        'LDrawParserParse.cpp): the complete-object locators of vtables 0x81ca00 / 0x81ca0c / 0x81cbd4 name '
        '.?AVLuaObjectWriter@LDraw2Lua@RBX@@, .?AVLDrawCommand@LDraw2Lua@RBX@@ (bases LDrawCommand, LuaObjectWriter) '
        'and .?AVLuaWriter@LDraw2Lua@RBX@@. Verified here with generated copies of the header and of '
        'LDrawEntityLifetime.cpp with the RTTI names: 0x46ea00 / 0x46ea10 / 0x46ea30 / 0x46eae0 / 0x46f630 / 0x46f820 are exact with every '
        'target verified (pending-build-only, not counted).'),
    'work/2008-06/bounds.json (server host)': (
        'The current function map now gives 0x46e0a0 (141 B), 0x46e180 (139 B), and 0x46e430 (635 B) their complete '
        'extents, so all three are counted normally.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + list(OWN_SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX::LDraw2Lua rows of the application range 0046c000..00474000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags plus each committed source\'s own native-flags '
                'include directories (no /fp:fast)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'sources_note': 'committed LDraw*.cpp of another owner compiled read-only and unchanged; one new source of this '
                    'lease (AppUnit46CStringIterators.cpp, an explicit member instantiation); no new header',
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'unit_blocks': block_rows,
    'range_functions': len(range_rows),
    'range_bytes': sum(FUNCTIONS[a]['size'] for a in range_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%#x counted by %s' % (int(a, 16), ', '.join(v))
                                             for a, v in range_counted.items()],
    'ldraw_rows_open': ldraw_open,
    'open': OPEN,
    'rows': groups,
    'rtti_name_mismatch_rows': [dict(r, address='%#x (not counted)' % int(r['address'], 16)) for r in mismatch],
    'pending_build_only': [dict(r, address='%#x (pending-build-only, not counted)' % int(r['address'], 16))
                           for r in pending],
    'vtables': vtable_checks,
    'evidence_rows': evidence_checks,
    'bounds_evidence': BOUNDS,
    'helper_bodies_not_counted': HELPERS,
    'proposals': PROPOSALS,
    'library': 'G3D 6.09 GLCaps.cpp / Texture.cpp 0x46fc10..0x474000: library code, not recovered.',
    'excluded': 'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView member lies in the range.',
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact_rows), sorted(bare - set(exact_rows))
if DISCOVER:
    print('DISCOVER: receipt not written; %d exact rows' % len(exact_rows), ' '.join(exact_rows))
    sys.exit(0)
RECEIPT.write_text(text)
print('PASS app-unit46c: %d counted exact rows; %d range rows, %d counted elsewhere, %d LDraw rows open; '
      '%d pending-build-only; %d vtables checked; %d bounds records'
      % (len(exact_rows), len(range_rows), len(range_counted), len(ldraw_open), len(pending), len(vtable_checks),
         len(BOUNDS)))
