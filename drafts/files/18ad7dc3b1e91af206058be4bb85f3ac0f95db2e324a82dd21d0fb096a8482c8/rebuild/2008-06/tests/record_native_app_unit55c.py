"""Verify the inactive 2008-06 native rows of the application range 0055c000..00560000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` / `unit_blocks`, checked below; rows counted by other receipts
are listed as 'ADDR counted by RECEIPT' text, never as a quoted bare address):
  * 0055bae0..00563069  util/ContentProvider.cpp, one translation unit that starts below the range (ContentId isAsset
                        0055bae0, operator< 0055bd50, fromAssets 0055bd80) and ends past it (~ContentProvider 00562e60,
                        the ??_E thunks 00562de0..00562e50 and ??_G 00563050). Inside it, interleaved in COMDAT order:
                        boost.date_time (ptime / gregorian date / int_adapter / second_clock), ATL CString / CPathT /
                        string-resource inlines, std exception COMDATs, boost.iostreams copy_impl, the MD5HasherImpl
                        class (misc-leaves owner) and the ContentProvider bodies (asset-folder statics, FailedUrl,
                        isUrlBad, cache paths, load / get / worker; colin content-* trial receipts).
  The range holds no other unit and no separately compiled library unit; the library rows are header instances.

Build (VS2008 RTM 21022, document-swap flags), current native headers only (read-only, no new header, no shadowing):
  * native-classes/AppUnit55CContentTemplates.cpp: explicit instantiations of the ContentProvider containers
    (map<ContentId, CachedContent> + its _Tree, list<ContentRequest>, list<FailedUrl>, vector<RequestCallback>),
    shared_ptr<const std::string> / sp_counted_impl_p<std::string>, NonFactoryProduct<Instance, sContentProvider>()
    and Name::declare<sContentProvider>(). It includes the content-cache-inline variant of util/NativeContentProvider.h
    (inline ContentId operator<, which the original key comparisons inline).

Every relocation of a counted row is resolved to the address the original instruction uses and verified, one address
per symbol over all rows: imports by DLL export name, type descriptors and vtables by original RTTI, own rows by their
row address, bodies compiled here that are not rows (or rows counted by other receipts) must be exact at the bound
address, externals by evidence name or by the binding other committed receipts use. Vtables emitted here are compared
slot by slot with the original vtable the constructor stores. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit55c-working.json. NATIVE_APP_UNIT55C_DISCOVER=1 lists unbound targets and
non-exact rows instead of asserting.
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
OUT = R / 'out/app-unit55c'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {'content': R / 'native-classes/AppUnit55CContentTemplates.cpp'}
HEADERS = [R / 'native-headers' / h for h in (
    'content-cache-inline/util/NativeContentProvider.h', 'util/NativeContentProvider.h', 'util/Object.h',
    'util/Name.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit55c-working.json'
LO, HI = 0x55c000, 0x560000
UNIT_LO, UNIT_HI = 0x55bae0, 0x563070
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT55C_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('AppUnit55C' + _k, _src)

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    x = json.loads(line)
    FUNCTIONS[int(x['addr'], 16)] = x


def norm(s):
    return s.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


ACCESS = {'A': 'Q', 'I': 'Q', 'Q': 'Q', 'E': 'U', 'M': 'U', 'U': 'U', 'C': 'S', 'K': 'S', 'S': 'S', 'B': 'R',
          'J': 'R', 'R': 'R'}


def same_member(a, b):
    """Equal decorated names up to the member access letter (private / protected / public)."""
    def key(n):
        m = re.match(r'^(\?[^@?][^@]*@(?:[^@]+@)*@)([A-Z])(.*)$', n)
        return (m.group(1), ACCESS.get(m.group(2), m.group(2)), m.group(3)) if m else n
    return a == b or key(a) == key(b)


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

# ---- rows --------------------------------------------------------------------------------------------------------
TREE = '?$_Tree@V?$_Tmap_traits@VContentId@RBX@@UCachedContent@ContentProvider@2@'
MAP = '?$map@VContentId@RBX@@UCachedContent@ContentProvider@2@'
LREQ = '?$list@UContentRequest@RBX@@'
LURL = '?$list@UFailedUrl@ContentProvider@RBX@@'
FN = 'V?$function@$$A6AXW4RequestResult@RBX@@AAV?$basic_istream@DU?$char_traits@D@std@@@std@@@ZV?$allocator@X@4@@boost@@'
VEC = '?$vector@' + FN
PAIR = '?$pair@$$CBVContentId@RBX@@UCachedContent@ContentProvider@2@@std@@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
NFP = '?$NonFactoryProduct@VInstance@RBX@@$1?sContentProvider@2@3PADA@RBX@@'

# (row, [acceptable symbol prefixes], what). Several prefixes: identical COMDATs the linker folded (/OPT:ICF); the
# symbol kept is the one the compiled rows here reference (checked below), and the others are listed in the receipt.
ROW_SPECS = [
    (0x55bd50, ['??MRBX@@YA_NABVContentId@0@0@Z'], 'RBX::operator<(const ContentId&, const ContentId&) (evidence name; '
     'below the range, same unit; one jmp to msvcp90 operator<(const string&, const string&))'),
    (0x55c000, ['??R?$less@VContentId@RBX@@@std@@'], 'std::less<ContentId>::operator()'),
    (0x55c080, ['??0' + NFP], 'NonFactoryProduct<Instance, sContentProvider>::NonFactoryProduct() (stores the ten '
     'NonFactoryProduct vtables 0x82db28..0x82dba4)'),
    (0x55c0e0, ['?_Min@' + TREE], 'map<ContentId, CachedContent> _Tree::_Min'),
    (0x55c170, ['?_Max@' + TREE], '_Tree::_Max'),
    (0x55c330, ['??$_Allocate@' + FN], 'std::_Allocate<function<void(RequestResult, istream&)>>'),
    (0x55ca20, ['?_Inc@const_iterator@' + TREE], '_Tree::const_iterator::_Inc'),
    (0x55ca90, ['?_Lbound@' + TREE], '_Tree::_Lbound (inline ContentId operator<)'),
    (0x55cb20, ['?_Dec@const_iterator@' + TREE], '_Tree::const_iterator::_Dec'),
    (0x55ced0, ['??$_Construct@UFailedUrl@ContentProvider@RBX@@'], 'std::_Construct<FailedUrl>'),
    (0x55d150, ['??1' + PAIR], 'pair<const ContentId, CachedContent>::~pair (caller: map::operator[] 0x560720)'),
    (0x55d1a0, ['?_Buy@' + VEC], 'vector<RequestCallback>::_Buy'),
    (0x55d1f0, ['?_Buynode@' + LREQ], 'list<ContentRequest>::_Buynode()'),
    (0x55d210, ['??0' + PAIR + 'QAE@ABVContentId@RBX@@'], 'pair<const ContentId, CachedContent>(key, value)'),
    (0x55d330, ['?_Incsize@' + LREQ], 'list<ContentRequest>::_Incsize ("list<T> too long")'),
    (0x55d3d0, ['??0?$function@$$A6AXW4RequestResult', '??0?$function2@XW4RequestResult'],
     'boost::function<void(RequestResult, istream&)> copy constructor'),
    (0x55d400, ['??0' + PAIR + 'QAE@ABU01@@Z'], 'pair<const ContentId, CachedContent> copy constructor'),
    (0x55d6b0, ['?dispose@?$sp_counted_impl_p@' + STR], 'sp_counted_impl_p<std::string>::dispose (slot 1 of 0x82dbe8)'),
    (0x55dab0, ['??$?0' + STR + '@?$shared_ptr@$$CBV'], 'shared_ptr<const std::string>(std::string*)'),
    (0x55ddb0, ['??$declare@$1?sContentProvider@RBX@@3PADA@Name@RBX@@'], 'Name::declare<sContentProvider>() (the '
     'linker folded NonFactoryProduct<Instance, sContentProvider>::getClassName() const into it: slot 1 of the '
     'NonFactoryProduct vtable 0x82db98 holds this row)'),
    (0x55e1d0, ['??$reset@' + STR + '@?$shared_ptr@$$CBV'], 'shared_ptr<const std::string>::reset(std::string*)'),
    (0x55e530, ['??0' + LREQ], 'list<ContentRequest>::list() (ContentProvider() 0x562c30 calls it for requestQueue)'),
    (0x55e650, ['?push_front@' + LURL], 'list<FailedUrl>::push_front'),
    (0x55e690, ['?erase@' + LURL], 'list<FailedUrl>::erase(first, last)'),
    (0x55e750, ['?find@' + TREE + '|QAE?AViterator@12@ABVContentId'], '_Tree::find'),
    (0x55e8d0, ['?_Insert@' + TREE], '_Tree::_Insert ("map/set<T> too long")'),
    (0x55ebb0, ['??$_Copy_opt@PA' + FN, '??$unchecked_copy@PA' + FN], 'copy of RequestCallback ranges'),
    (0x55ebf0, ['??$_Fill@PA' + FN, '??$fill@PA' + FN], 'fill of RequestCallback ranges'),
    (0x55ec20, ['?destroy@?$allocator@' + FN], 'allocator<RequestCallback>::destroy'),
    (0x55eed0, ['?insert@' + TREE + '|@std@@QAE?AU?$pair@Viterator@'],
     '_Tree::insert(const value_type&)'),
    (0x55efc0, ['?erase@' + TREE + '|@std@@QAE?AViterator@12@Vconst_iterator@12@@Z'],
     '_Tree::erase(const_iterator) ("invalid map/set<T> iterator")'),
    (0x55f2c0, ['?_Erase@' + TREE], '_Tree::_Erase'),
    (0x55f4b0, ['??$_Copy_backward_opt@PA' + FN, '??$_Move_backward_opt@PA' + FN,
                '??$_Unchecked_move_backward@PA' + FN], 'backward move of RequestCallback ranges'),
    (0x55f5b0, ['??$_Destroy_range@V?$allocator@' + FN], 'std::_Destroy_range<RequestCallback>'),
    (0x55ffc0, ['?insert@' + TREE + '|@std@@QAE?AViterator@12@Vconst_iterator@12@ABU'],
     '_Tree::insert(const_iterator hint, const value_type&)'),
    # the unit continues past the range: its container instances there are counted with it
    (0x560720, ['??A' + MAP], 'map<ContentId, CachedContent>::operator[] (past the range, same unit)'),
    (0x560820, ['?_Destroy@' + VEC], 'vector<RequestCallback>::_Destroy (past the range)'),
    (0x560840, ['?_Tidy@' + VEC], 'vector<RequestCallback>::_Tidy (past the range)'),
    (0x560890, ['?_Ufill@' + VEC], 'vector<RequestCallback>::_Ufill (past the range)'),
    (0x5608d0, ['?erase@' + VEC], 'vector<RequestCallback>::erase(first, last) (past the range)'),
    (0x560960, ['?erase@' + TREE + '|@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z'],
     '_Tree::erase(first, last) (past the range)'),
    (0x560a40, ['??$_Ucopy@PA' + FN, '??$_Umove@PA' + FN], 'vector<RequestCallback>::_Ucopy / _Umove (past the range)'),
    (0x560b60, ['??1' + VEC], 'vector<RequestCallback>::~vector (past the range)'),
    (0x560bd0, ['?clear@' + VEC], 'vector<RequestCallback>::clear (past the range)'),
    (0x560ea0, ['??0ContentRequest@RBX@@QAE@ABU01@@Z'], 'ContentRequest copy constructor (past the range)'),
    (0x561020, ['??1ContentRequest@RBX@@QAE@XZ'], 'ContentRequest::~ContentRequest (past the range; callers: list '
     'erase 0x5617c0, loadContent 0x561980, the worker 0x5620f0)'),
    (0x561070, ['??4' + VEC], 'vector<RequestCallback>::operator= (past the range)'),
    (0x561180, ['??1' + TREE], '_Tree::~_Tree (past the range)'),
    (0x5611f0, ['?insert@' + VEC], 'vector<RequestCallback>::insert(where, value) (past the range)'),
    (0x561330, ['?push_back@' + VEC], 'vector<RequestCallback>::push_back (past the range)'),
    (0x561780, ['?push_back@' + LREQ], 'list<ContentRequest>::push_back (past the range)'),
    (0x5617c0, ['?erase@' + LREQ], 'list<ContentRequest>::erase(where) (past the range)'),
    (0x561850, ['?clear@' + LREQ], 'list<ContentRequest>::clear (past the range)'),
    (0x562bd0, ['??1' + LREQ], 'list<ContentRequest>::~list (past the range; ~ContentProvider 0x562e60 calls it)'),
]
# rows of the unit built here whose address another receipt counts: bound only (their compiled body must be exact)
BOUND_ONLY = [
    (0x55dfd0, ['?clear@' + LURL], 'list<FailedUrl>::clear'),
    (0x55e590, ['??0' + LURL], 'list<FailedUrl>::list() (folded with list<TimerService::Item>::list)'),
    (0x55e5f0, ['??1' + LURL], 'list<FailedUrl>::~list'),
]
# near misses built here, never counted (text addresses only)
NEAR_MISS = [
    (0x55d5e0, '??$?0' + STR + '@shared_count@detail@boost@@', 'shared_count(std::string*): 131 B against 110 B; '
     'the original has no try/catch around new sp_counted_impl_p (the boost 1.34.1 ctor here keeps it)'),
    (0x55e010, '?_Buynode@' + TREE, '_Tree::_Buynode(left, parent, right, value): 147 B against 126 B; the original '
     'calls the pair copy constructor 0x55d400 out of line, here it is inlined'),
    (0x55d8c0, '?_Buynode@' + LURL, 'list<FailedUrl>::_Buynode(next, prev, value): 134 B against 113 B; the original '
     'calls _Construct<FailedUrl> 0x55ced0 out of line, here it is inlined'),
]

RAW = Path(OBJ['content']).read_bytes()
BODIES = {n: (b, r) for n, b, r in match.coff_functions(RAW) if not nb.LOCAL_EH.match(n)}
SECTIONS, SYMBOLS, DEFINITIONS, _ = match._coff_data_index(RAW)


def referenced_here():
    """Symbols that some compiled function's relocations name (REL32 / DIR32)."""
    out = set()
    for name in BODIES:
        start, sec = DEFINITIONS[name]
        table = SECTIONS[sec]
        for i in range(table[7]):
            off, idx, kind = struct.unpack_from('<IIH', RAW, table[5] + 10 * i)
            out.add(SYMBOLS[idx][0])
    return out


REFERENCED = referenced_here()
TARGETS = {}


def target(address):
    if address not in TARGETS:
        TARGETS[address] = match.target('2008-06', '%08x' % address)
    return TARGETS[address]


def exact_at(symbol, address):
    body, refs = BODIES[symbol]
    t, tr, _ = target(address)
    return bool(match.exact_match(t, tr, body, refs))


def resolve(address, prefixes):
    """The symbol compiled here for the row: byte-exact candidates among the prefixes; among folded duplicates, the
    one the compiled rows reference (or the first prefix when nothing references any)."""
    def ok(n, p):
        head, _, part = p.partition('|')
        return n.startswith(head) and part in n
    cands = [n for n in BODIES if any(ok(n, p) for p in prefixes)]
    good = [n for n in cands if exact_at(n, address)]
    if len(good) > 1:
        ref = [n for n in good if n in REFERENCED]
        good = ref if len(ref) == 1 else [n for n in (ref or good) if ok(n, prefixes[0])]
    if len(good) != 1:
        if DISCOVER:
            return None, cands
        raise AssertionError(('row', hex(address), prefixes[0][:60], cands[:6], good))
    return good[0], [n for n in cands if n != good[0] and exact_at(n, address)]


ROWS, FOLDED, BOUND = [], {}, {}
COUNTED_TARGETS = {}
for address, prefixes, what in ROW_SPECS:
    sym, folded = resolve(address, prefixes)
    if sym is None:
        print('UNRESOLVED', hex(address), what, folded[:4])
        continue
    if '%08x' % address in elsewhere:
        COUNTED_TARGETS[sym] = (address, sorted(set(elsewhere['%08x' % address])))
        continue
    ROWS.append((address, sym))
    FOLDED[sym] = folded
for address, prefixes, what in BOUND_ONLY:
    sym, folded = resolve(address, prefixes)
    assert '%08x' % address in elsewhere, (hex(address), 'expected counted elsewhere')
    COUNTED_TARGETS[sym] = (address, sorted(set(elsewhere['%08x' % address])))
    BOUND[sym] = (address, what, sorted(set(elsewhere['%08x' % address])))

EXTERNAL = {
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,   # bound the same way by app-unit40c / 424 / 568 / 658
    '??3@YAXPAX@Z': 0x6a067a,
    '??2@YAPAXI@Z': 0x6a0920,
    # Instance() 0x55b7e0: evidence name ??0Instance@RBX@@IAE@XZ (protected in the original; the native
    # v8tree/Instance.h declares it public, which changes only the access letter of the symbol)
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,
}
assert names.get(0x55b7e0) == '??0Instance@RBX@@IAE@XZ', names.get(0x55b7e0)
DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
TEXT = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
        for s in original.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
BINDING = {}
DROPPED_SYMBOLS = {}
UNBOUND = []
HELPERS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def verify(rows):
    own = {s: a for a, s in rows}
    out = []
    for address, name in rows:
        body, refs = BODIES[name]
        t, tr, _ = target(address)
        exact = match.exact_match(t, tr, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(t),
               'exact': bool(exact), 'verified_targets': {}, 'local_eh': [], 'unverified': []}
        out.append(row)
        if not exact:
            continue
        start, section = DEFINITIONS[name]
        table = SECTIONS[section]
        code = RAW[table[4] + start:]
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', RAW, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = SYMBOLS[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', t, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', t, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            where = '%08x+%#x' % (address, offset)
            if nb.LOCAL_EH.match(symbol):
                row['local_eh'].append(symbol)
                continue
            how = None
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol in own:
                assert own[symbol] == value, (where, symbol, hex(value))
                how = 'own row'
            elif symbol.startswith('??_C@'):
                pos, at = DEFINITIONS[symbol]
                literal = RAW[SECTIONS[at][4] + pos:SECTIONS[at][4] + SECTIONS[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
                how = 'string %r' % literal[:-1].decode('latin-1')
            elif symbol.startswith('__TI') and symbol[4:5].isdigit():
                # ThrowInfo -> CatchableTypeArray (count, first CatchableType) -> TypeDescriptor name
                count = int(symbol[4])
                cta = d(value + 12)
                assert d(cta) == count, (where, symbol, hex(value), d(cta))
                tname = original.string(d(d(cta + 4) + 4) + 8)
                assert tname == '.' + symbol[5:], (where, symbol, hex(value), tname)
                how = 'ThrowInfo of %s (%d catchable types)' % (tname, count)
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in COUNTED_TARGETS:
                other, receipts = COUNTED_TARGETS[symbol]
                assert other == value, (where, symbol, hex(value), hex(other))
                assert exact_at(symbol, value), ('counted-elsewhere body not exact', symbol, hex(value))
                how = 'row counted by %s (compiled body exact at the bound address)' % ', '.join(receipts)
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif names.get(value, '') == symbol:
                how = 'external (evidence name)'
            elif symbol in DROPPED_SYMBOLS:
                row['unverified'].append('%s -> %#x: row not counted (%s)' % (symbol[:90], value,
                                                                              DROPPED_SYMBOLS[symbol]))
                continue
            elif symbol in BODIES:
                # helper / COMDAT body compiled here but not a row: exact at the bound address, never counted
                if not exact_at(symbol, value):
                    row['unverified'].append('%s -> %#x: the body compiled here is not exact there' % (
                        symbol[:90], value))
                    continue
                HELPERS.setdefault(symbol, '%#x' % value)
                how = 'helper body exact at the bound address (not counted)'
            elif symbol in DEFINITIONS and symbol not in BODIES:
                assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
                how = 'own static (bound by consistency)'
            if how is None:
                UNBOUND.append((where, symbol, hex(value), names.get(value, '')[:80]))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out


# Fixed point: a row whose call target cannot be verified (the callee compiled here is not exact at the bound
# address and has no evidence name) is built but not counted, and so is every row that calls such a row.
DROPPED, DROPPED_SYMBOLS = {}, {}
current = list(ROWS)
while True:
    BINDING.clear()
    HELPERS.clear()
    del UNBOUND[:]
    rows_out = verify(current)
    bad = [r for r in rows_out if r['unverified']]
    if not bad:
        break
    for r in bad:
        DROPPED[r['address']] = r
        DROPPED_SYMBOLS[r['symbol']] = 'calls ' + '; '.join(r['unverified'])
    current = [x for x in current if '%08x' % x[0] not in DROPPED]
for r in rows_out:
    del r['unverified']
not_exact = [r for r in rows_out if not r['exact']]
if DISCOVER:
    for u in UNBOUND:
        print('UNBOUND', u)
    for r in not_exact:
        print('NOT EXACT', r['address'], r['size'], r['target_size'], r['symbol'][:100])
assert not UNBOUND or DISCOVER, UNBOUND
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]
for symbol, address in EXTERNAL.items():
    assert address in FUNCTIONS or original.imported(address) is not None, (symbol, hex(address))

near = []
for address, prefix, why in NEAR_MISS:
    hits = [n for n in BODIES if n.startswith(prefix) and not n.endswith('@XZ')]
    assert len(hits) == 1, (hex(address), hits)
    ok = exact_at(hits[0], address)
    assert not ok or DISCOVER, ('near miss became exact', hex(address))
    near.append({'row': '%#x (not counted, exact=false)' % address, 'symbol': hits[0], 'exact': False,
                 'compiled_size': len(BODIES[hits[0]][0]), 'target_size': FUNCTIONS[address]['size'], 'reason': why})


# ---- vtables emitted here against the original vtables the rows store ---------------------------------------------
def vtable_slots(vtable_address):
    out = {}
    for symbol, address in sorted(vtable_address.items()):
        start, sec = DEFINITIONS[symbol]
        table = SECTIONS[sec]
        relocs = sorted((struct.unpack_from('<IIH', RAW, table[5] + 10 * k)) for k in range(table[7]))
        slots = [(off - start, SYMBOLS[idx][0]) for off, idx, kind in relocs if kind == 6 and off >= start]
        slots = [x for x in slots if x[0] < table[3] - start]
        checked, unbound = [], []
        for off, slot_symbol in slots:
            value = d(address + off)
            if slot_symbol in BINDING:
                assert BINDING[slot_symbol][0] == value or DISCOVER, ('vtable slot', symbol, off // 4, slot_symbol,
                                                                      hex(value), hex(BINDING[slot_symbol][0]))
                checked.append('%d %s = %#x (bound by the rows)' % (off // 4, slot_symbol[:90], value))
            elif slot_symbol in BODIES:
                assert exact_at(slot_symbol, value) or DISCOVER, ('vtable slot body', symbol, off // 4, slot_symbol,
                                                                  hex(value))
                bind(slot_symbol, value, '%s slot %d' % (symbol[:40], off // 4))
                checked.append('%d %s = %#x (compiled body exact there)' % (off // 4, slot_symbol[:90], value))
            elif same_member(names.get(value, ''), slot_symbol):
                checked.append('%d %s = %#x (evidence name%s)' % (off // 4, slot_symbol[:90], value, '' if names.get(
                    value) == slot_symbol else ' up to the access letter: ' + names.get(value)[:90]))
            else:
                unbound.append('%d %s = %#x' % (off // 4, slot_symbol[:90], value))
        originals = [d(address + 4 * k) for k in range(len(slots) + 1)]
        in_text = [TEXT[0] <= v < TEXT[1] for v in originals]
        assert (all(in_text[:-1]) and not in_text[-1]) or DISCOVER, (
            'vtable slot count', symbol, hex(address), [hex(v) for v in originals])
        out[symbol] = {'address': '%#x' % address, 'rtti': original.vtable_class(address)[0], 'slots': len(slots),
                       'checked': checked, 'not_bound_here': unbound}
    return out


VTABLE_ADDRESS = {}
for r in rows_out:
    for sym, how in r['verified_targets'].items():
        # slot-by-slot check for the RBX vtables; the std exception vtables (_Xlen / _Xran throws) are library
        # data and are verified by their RTTI in the rows' verified_targets only
        if sym.startswith('??_7') and NFP in sym:
            VTABLE_ADDRESS[sym] = int(how.split()[0], 16)
# sp_counted_impl_p<std::string>: the vtable 0x82dbe8 that shared_count(std::string*) 0x55d5e0 stores
_spc = [s for s in DEFINITIONS if s.startswith('??_7?$sp_counted_impl_p@' + STR)]
assert len(_spc) == 1, _spc
assert original.vtable_class(0x82dbe8)[0] == '.?AV' + _spc[0][4:_spc[0].index('@@6B') + 2], original.vtable_class(0x82dbe8)
_b = original.data(0x55d5e0, FUNCTIONS[0x55d5e0]['size'])
assert struct.pack('<I', 0x82dbe8) in _b, 'shared_count(std::string*) stores 0x82dbe8'
VTABLE_ADDRESS[_spc[0]] = 0x82dbe8
vtables = vtable_slots(VTABLE_ADDRESS)
assert len([s for s in vtables if NFP in s]) == 10, list(vtables)


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


def holds_vtable(address, prefix):
    body = original.data(address, FUNCTIONS[address]['size'])
    for i in range(len(body) - 3):
        v = struct.unpack_from('<I', body, i)[0]
        if 0x7f0000 <= v < 0x880000:
            try:
                c = original.vtable_class(v)
            except Exception:
                continue
            if c and c[0] and c[0][4:].startswith(prefix[4:]):
                return True
    return False


UNIT_EVIDENCE = [
    ('string', 0x55c3e0, 'Roblox\\content\\'), ('string', 0x55c3e0, 'Failed to get asset folder from registry'),
    ('string', 0x55dd60, 'ContentProvider callback exception: %s'), ('string', 0x55d330, 'list<T> too long'),
    ('string', 0x55e8d0, 'map/set<T> too long'), ('string', 0x55efc0, 'invalid map/set<T> iterator'),
    ('vt', 0x55c080, '.?AV?$NonFactoryProduct@VInstance@RBX@@$1?sContentProvider@'),
    ('vt', 0x55c540, '.?AVMD5HasherImpl@RBX@@'),
    ('vt', 0x55c3c0, '.?AVbad_day_of_month@gregorian@boost@@'), ('vt', 0x55cae0, '.?AVbad_year@gregorian@boost@@'),
]
for kind, a, text in UNIT_EVIDENCE:
    assert (holds_string(a, text) if kind == 'string' else holds_vtable(a, text)), (kind, hex(a), text)
# the unit's ends: ContentId::isAsset 0x55bae0 (evidence name, "rbxasset://" prefix test) below the range and
# ~ContentProvider 0x562e60 / ??_G 0x563050 past it; the row before 0x55bae0 is Instance.cpp (app-unit558 map)
assert names.get(0x55bae0, '').startswith('?isAsset@ContentId@RBX@@'), names.get(0x55bae0)
assert names.get(0x55bd50, '') == '??MRBX@@YA_NABVContentId@0@0@Z'

range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
exact_rows = sorted({r['address'] for r in rows_out if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}

LIB_PATTERNS = [
    ('boost.date_time (library, not recovered)', r'date_time@boost|gregorian@boost|posix_time@boost'),
    ('ATL CString / CPathT / string-resource inlines (library, not recovered)', r'@ATL@@'),
    ('boost.iostreams (library, not recovered)', r'iostreams@boost'),
]
UNNAMED_LIBRARY = {
    0x55c390: 'std::logic_error-family ??_G (std exception COMDAT; library)',
    0x55c3c0: 'boost::gregorian::bad_day_of_month copy constructor (vtable RTTI bad_day_of_month; library)',
    0x55cae0: 'boost::gregorian::bad_year copy constructor (vtable RTTI bad_year; library)',
    0x55cb00: 'boost::gregorian::bad_month copy constructor (vtable RTTI bad_month; library)',
    0x55c910: 'auto_ptr / scoped_ptr<std::istream> delete through the virtual base (std library COMDAT, ICF-shared; '
              'caller 0x58f270 in another unit)',
    0x55d6d0: 'std::_Uninit_copy<Reflection::Value> (evidence name; ICF-shared, callers in other units)',
    0x55d71d: 'catch funclet of 0x55d6d0 (rethrow; library)',
    0x55e310: 'boost function_obj_invoker0 (evidence name; folded COMDAT of another unit, luahtml-binder2008 binds it)',
}
MD5 = 'MD5HasherImpl (misc-leaves owner)'


def category(a):
    k = '%08x' % a
    if k in exact_rows:
        return 'counted here'
    if k in range_counted:
        return 'counted by other receipts'
    if a in UNNAMED_LIBRARY:
        return 'library / shared COMDAT'
    n = names.get(a, '')
    if re.match(r'^\?\w+@RBX@@', n):
        return 'ContentProvider bodies and unnamed rows, open'
    for label, pat in LIB_PATTERNS:
        if re.search(pat, n):
            return label
    if 'MD5Hasher' in n:
        return MD5
    return 'ContentProvider bodies and unnamed rows, open'


OPEN = {}
for a in range_rows:
    OPEN.setdefault(category(a), []).append('%#x' % a)

UNIT_MAP = {
    'rbx util/ContentProvider.cpp 0x55bae0..0x56306f (whole range; starts below it and ends past it)': (
        'One translation unit covers every row of 0x55c000..0x55ffff. Boundary evidence (asserted): ContentId isAsset '
        '0x55bae0 / isHttp 0x55bb50 / operator< 0x55bd50 / operator!= 0x55bd60 / fromAssets 0x55bd80 (evidence names) '
        'begin it right after the Instance.cpp rows (app-unit558 map); the asset-folder registry read 0x55c3e0 '
        '("Roblox\\content\\", "Failed to get asset folder from registry") and its call_once getter 0x55c4c0 / path '
        'builder 0x55d0b0; NonFactoryProduct<Instance, sContentProvider>() 0x55c080 (ten vtables 0x82db28..0x82dba4); '
        'readContent 0x55dc80 + catch 0x55dd60 ("ContentProvider callback exception: %s"); the map<ContentId, '
        'CachedContent> / list<ContentRequest> / list<FailedUrl> / vector<RequestCallback> instances ("map/set<T> too '
        'long", "invalid map/set<T> iterator", "list<T> too long"); FailedUrl 0x55f710, getLocalCachePath 0x55f940 '
        '(evidence names), findHashFile 0x55fdc0, the hash-path helpers 0x55fa70 / 0x55fbc0 (MD5Hasher::create '
        'caller); past the range classDescriptor 0x5612b0, DescribedNonCreatable 0x5613f0, loadContent 0x561980, '
        'getContent 0x561f20, the worker 0x5620f0, ContentProvider() 0x562c30, ~ContentProvider 0x562e60, its ??_E '
        'thunks 0x562de0..0x562e50 and ??_G 0x563050. MD5HasherImpl (vtable 0x82dc9c; 0x55c540..0x55c8b0, 0x55e320) '
        'is defined in the same unit (misc-leaves counts it).'),
    'library code inside the unit (not recovered)': (
        'boost.date_time (bad_day_of_month / bad_year / bad_month and their copy constructors 0x55c3c0 / 0x55cae0 / '
        '0x55cb00, on_error 0x55c020..0x55c060, gregorian calendar 0x55c1f0..0x55c2d0, int_adapter 0x55c100..0x55c140 '
        '/ 0x55cc40 / 0x55cdc0, date 0x55d000, counted_time 0x55d270 / 0x55d780, second_clock 0x55e7d0, '
        'to_tick_count 0x55c930), ATL CString / CPathT / string resources (0x55c190, 0x55cbb0, 0x55d760, 0x55d950, '
        '0x55d9f0, 0x55dae0, 0x55dee0, 0x55df40, 0x55e250, 0x55ee20), boost.iostreams copy_impl 0x55ec50 and '
        'list<linked_streambuf*>::back 0x55ddd0, std exception COMDAT 0x55c390 and the ICF-shared COMDATs listed under '
        'library_rows. Header instances; never recovered here.'),
    'excluded': (
        'No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row lies in the range.'),
}
OPEN_REASONS = {
    'asset-folder statics 0x55c3e0 / 0x55c4c0 / 0x55d0b0': (
        'file-static once-initialised std::string (0x9740f0, once flag 0x973fe4) filled by '
        'SHGetFolderPathAndSubDirA(CSIDL_COMMON_APPDATA, "Roblox\\content\\"), its getter (call_once + copy) and the '
        'getter + path builder (9 callers); util/NativeContentProvider.h declares none of them, so their names and '
        'signatures are not derived; not attempted (proposal).'),
    'FailedUrl 0x55f710 / isUrlBad 0x55f7b0 / getLocalCachePath 0x55f940 / findHashFile 0x55fdc0 / readContent '
    '0x55dc80': (
        'bodies already drafted by the ContentProvider owner (native-classes/ContentProviderCacheSupport.cpp, '
        'ContentRead.cpp and the colin content-* trial receipts); not duplicated or counted here.'),
    'worker / request helpers 0x55cf30 / 0x55cfa0 / 0x55d460 / 0x55d530 / 0x55d670 / 0x55db60 / 0x55dbe0 / '
    '0x55de10 / 0x55e0b0 / 0x55e270 / 0x55ead0 / 0x55ed20 / 0x55edd0 / 0x55f350 / 0x55f3b0 / 0x55f4f0 / 0x55f5f0 / '
    '0x55f6a0 / 0x55fa70 / 0x55fbc0 / 0x55fed0 / 0x55cc20 / 0x55d840': (
        'boost bind_t / function managers (0x55d670 manages bind_t<work_result, mf0<.., ContentProvider>, ..>, typeid '
        '0x944328; it needs the newer boost function manager, as ContentProviderWorkerBinding.cpp uses), for_each / '
        'find over the request list, the requestContentString ifstream copy, the hash-file path helpers and shared_ptr '
        'assignments reached only from the worker / loadContent / registerFile bodies. Not attempted this pass: they '
        'come out of those bodies (ContentProvider owner) or need declarations the native header lacks.'),
    'catch funclets 0x55d64e / 0x55d931 / 0x55e08e / 0x55ed8d / 0x55f65d / 0x55ffa9': (
        'EH funclet fragments of the container instances (split rows); BOUNDS evidence only, not counted.'),
}
PROPOSALS = {
    'util/NativeContentProvider.h (ContentProvider owner)': (
        'Make ContentId operator< inline in the main header, as the content-cache-inline variant does: the original '
        'less<ContentId>::operator() 0x55c000, _Tree::_Lbound 0x55ca90, find 0x55e750, insert 0x55eed0 / 0x55ffc0 and '
        'map::operator[] 0x560720 call msvcp90 operator<(const string&, const string&) (import 0x80235c) directly, and '
        'the out-of-line operator< 0x55bd50 is one jmp through that import. AppUnit55CContentTemplates.cpp includes '
        'the variant read-only for this reason. Also declare the asset-folder statics (string 0x9740f0, once flag '
        '0x973fe4, initialiser 0x55c3e0, getter 0x55c4c0, path builder 0x55d0b0) once their names are derived.'),
    'boost shared_count / _Buynode near misses (FYI)': (
        'shared_count(std::string*) 0x55d5e0 is 110 B without the try/catch the boost 1.34.1 header compiles to (131 '
        'B); _Tree::_Buynode 0x55e010 and list<FailedUrl>::_Buynode 0x55d8c0 keep the pair copy / _Construct calls out '
        'of line. No header change proposed without the vendor configuration that explains them.'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX util/ContentProvider.cpp template instances of the application range 0055c000..00560000 (2008-06), '
             'inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'unit_blocks': ['%#x..%#x util/ContentProvider.cpp (range %#x..%#x)' % (UNIT_LO, UNIT_HI, LO, HI)],
    'range_functions': len(range_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_by_category': OPEN,
    'library_rows': {'%#x' % a: v for a, v in UNNAMED_LIBRARY.items()},
    'open_reasons': OPEN_REASONS,
    'row_descriptions': {'%#x' % a: w for a, _, w in ROW_SPECS},
    'rows': rows_out,
    'folded_duplicates': {s: f for s, f in FOLDED.items() if f},
    'bound_only': ['%#x %s: %s (row counted by %s; compiled body exact there)' % (a, s[:80], w, ', '.join(r))
                   for s, (a, w, r) in BOUND.items()],
    'near_misses_not_counted': near,
    'built_byte_exact_not_counted': [{'row': '%#x (not counted, exact=false)' % int(a, 16), 'symbol': r['symbol'],
                                      'exact': False, 'body_exact': r['exact'], 'reason': r['unverified']}
                                     for a, r in sorted(DROPPED.items())],
    'vtables': vtables,
    'helper_bodies_not_counted': HELPERS,
    'rejected': {
        'including util/NativeContentProvider.h (out-of-line donor ContentId operator<) instead of the '
        'content-cache-inline variant': (
            'less<ContentId>::operator() 21 B vs 22 B (0x55c000), _Tree::_Lbound 61 B vs 70 B (0x55ca90), find 126 B '
            'vs 127 B (0x55e750), insert(value) 237 B vs 235 B (0x55eed0), insert(hint, value) 552 B vs 562 B '
            '(0x55ffc0); operator[] 0x560720 also differs. The other container rows are identical either way.'),
    },
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact_rows), sorted(bare - set(exact_rows))
in_range = [a for a in exact_rows if LO <= int(a, 16) < HI]
if DISCOVER:
    print('DISCOVER: receipt not written; %d exact rows (%d in range)' % (len(exact_rows), len(in_range)),
          ' '.join(exact_rows))
    for s, v in vtables.items():
        print('VT', s[:90], v['address'], v['slots'], 'unbound', v['not_bound_here'])
    sys.exit(0)
RECEIPT.write_text(text)
print('PASS app-unit55c: %d counted exact rows (%d in range 0055c000..00560000): %s; %d range rows, %d counted '
      'elsewhere; %d vtables checked' % (len(exact_rows), len(in_range), ' '.join(exact_rows), len(range_rows),
                                         len(range_counted), len(vtables)))
