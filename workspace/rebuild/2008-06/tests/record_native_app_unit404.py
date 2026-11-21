"""Verify the inactive 2008-06 native rows of the application range 00404000..00408000 and record its unit map.

Unit map (boundary evidence in the receipt's `unit_map` and `unit_map_checks`; rows counted by other receipts in
`range_rows_counted_by_other_receipts`, written as 'ADDR counted by RECEIPT' text, never as quoted bare addresses):
  * 00401910..00405a9f (starts below this range): the ATL COM unit of CWorkspace. Here: the ATL registrar
    (CRegParser 004043f0 "Delete" / "ForceRemove" / "NoRemove"), CComTypeInfoHolder::GetTI 00404a80,
    IObjectSafetyRobloxImpl<CWorkspace> Get/SetInterfaceSafetyOptions 00404d20 / 00404db0 (slots 3/4 of vtable
    0081c80c; workspace-safety receipt of the CWorkspace owner), CComObject / CComClassFactory thunks to 00405a80.
  * 00405aa0..00405d9f: the active-document unit (setActiveDocument 00405aa0 and its helpers 00405ce0 / 00405d50 /
    00405d80; ActiveDocView owner, dispatches into CRobloxDoc).
  * 00405da0..0040995f (continues past this range): the ATL COM unit of CApp (vtables 0080b50c..0080b58c RTTI
    CComObject<CApp>, 0080b40c IObjectSafetyRobloxImpl<CApp>), with the Creatable / Name / GlobalSettingsItem template
    instances it emits, the ATL CUrl / CSimpleStringT inline COMDATs and boost / STL instances.

Build (document-swap flags, VS2008 RTM 21022): native-classes/AppUnit404Templates.cpp, explicit instantiations over the
read-only committed native headers (util/Object.h, v8tree/Instance.h, v8datamodel/GlobalSettings.h / DebugSettings.h):
  * AbstractFactoryProduct<Instance>::getCreators 00405da0 (util/Object.h inline body);
  * Creatable<Instance>::operator delete 00405e20 (util/Object.h inline body; emitted out of line because the unwind
    funclets of the create<T> instances call it, as the original funclets 007c8bcc / 007d82f4 ... do);
  * GlobalSettingsItem<DebugSettings>::singleton 00407be0 (same template body as GameSettings.cpp 0044bee0).
No new header (nothing shadowed), no pending build, no class with a vtable defined here (no vtable slot check).

Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, bodies this build also emits by exactness at the
bound address (support rows outside the range, or rows counted by another receipt's exact_function_rows), and the
remaining externals / statics by the EXTERNAL / DATA maps below, cross-checked against the same symbols in other
recorders' maps. A symbol binds to one address. A row is counted only when no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit404-working.json.
Set NATIVE_APP_UNIT404_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
import record_native_settings_items_maps as settings_maps  # noqa: E402  (read-only cross-check)

R = ROOT / 'rebuild/2008-06'
OUT = R / 'out/app-unit404'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {'templates': R / 'native-classes/AppUnit404Templates.cpp'}
HEADERS = [R / 'native-headers/util/Object.h', R / 'native-headers/v8tree/Instance.h',
           R / 'native-headers/v8datamodel/GlobalSettings.h', R / 'native-headers/v8datamodel/DebugSettings.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT404_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit404-working.json'
LO, HI = 0x404000, 0x408000


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('NativeAppUnit404_' + _k, _src)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

MAP = 'V?$map@PBVName@RBX@@PBVICreator@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@PBVICreator@2@@std@@@5@@std@@'
GSD = '?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDebugSettings@2@3QBDB@RBX@@'
TREE = '?$_Tree@V?$_Tmap_traits@PBVName@RBX@@PBVICreator@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@PBVICreator@2@@std@@@5@$0A@@std@@@std@@'
# (address, exact symbol)
ROWS_SPEC = [
    (0x405da0, '?getCreators@?$AbstractFactoryProduct@VInstance@RBX@@@RBX@@KAAA' + MAP + 'XZ'),
    (0x405e20, '??3?$Creatable@VInstance@RBX@@@RBX@@CAXPAX@Z'),
    (0x407be0, '?singleton@' + GSD + 'SAAAVDebugSettings@2@XZ'),
]
# Bodies this build also emits that a counted row calls, exact at the bound address; outside the range and counted by
# no receipt: support evidence, never counted here.
SUPPORT_SPEC = [
    (0x446110, '??0' + TREE + 'QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@PBVICreator@2@@std@@@1@@Z'),
    (0x7fa0a0, '??__Fcreators@?1??getCreators@?$AbstractFactoryProduct@VInstance@RBX@@@RBX@@KAAA' + MAP + 'XZ@YAXXZ'),
]
# Bodies this build emits that another receipt counts (bound by the call site; that receipt must count the address and
# this build's body must be exact there).
COUNTED_ELSEWHERE_SPEC = [
    (0x407820, '??$create@VDebugSettings@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VDebugSettings@RBX@@@boost@@XZ',
     'settings-items-working.json'),
]
# Externals: the address the original call / push uses (call sites read in the target disassembly).
EXTERNAL = {
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x563090,        # 00407c06 call
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,      # 00407cd3 call
    '?singleton@GlobalSettings@RBX@@SA?AV?$shared_ptr@VGlobalSettings@RBX@@@boost@@XZ': 0x5690f0,   # 00407c39 call
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,           # 00407c4d call
    '_atexit': 0x6a17af,                                        # 00405dea call (??__Fcreators pushed at 00405de5)
}
DATA = {
    '?mutex@GlobalSettings@RBX@@2Vrecursive_mutex@boost@@A': 0x974aa0,          # 00407bf9 / 00407cc6 mov ecx, imm
    '?sing@' + GSD + '0PAV12@A': 0x96c318,                                         # 00407c10 / 00407cc0
    '?creators@?1??getCreators@?$AbstractFactoryProduct@VInstance@RBX@@@RBX@@KAAA' + MAP + 'XZ@4V45@A': 0x96c2b4,  # 00405dd3
    '??_B?1??getCreators@?$AbstractFactoryProduct@VInstance@RBX@@@RBX@@KAAA' + MAP + 'XZ@51': 0x96c2d4,           # 00405dbb
}
# Cross-check: the same symbols bound by the settings-items recorder must name the same addresses.
for _sym, _addr in list(EXTERNAL.items()) + list(DATA.items()):
    for _table in (settings_maps.EXTERNAL, settings_maps.DATA):
        if _sym in _table:
            assert _table[_sym] == _addr, (_sym, hex(_table[_sym]), hex(_addr))

UNBOUND = []
binding = {}
support_out = {}
elsewhere_out = {}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


raw = Path(OBJ['templates']).read_bytes()
FUNCS = match.coff_functions(raw)
BODIES = {n: (b, r) for n, b, r in FUNCS}
for _a, _s in ROWS_SPEC + SUPPORT_SPEC + [(a, s) for a, s, _ in COUNTED_ELSEWHERE_SPEC]:
    assert _s in BODIES, ('symbol not emitted', '%08x' % _a, _s)
ROWS = list(ROWS_SPEC)
SUPPORT = {s: a for a, s in SUPPORT_SPEC}
COUNTED_ELSEWHERE = {s: (a, rc) for a, s, rc in COUNTED_ELSEWHERE_SPEC}


def bind_value(sections, symbols, definitions, name, body, target, address, own):
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
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in SUPPORT:
            assert SUPPORT[symbol] == value, (name, symbol, hex(value), hex(SUPPORT[symbol]))
            sbody, srefs = BODIES[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('support body not exact', symbol, hex(value))
            support_out.setdefault(symbol, {'address': hex(value), 'reached_from': name,
                                            'note': 'body this build emits, exact at the bound address (outside this '
                                                    'range, counted by no receipt); support evidence, not counted'})
            how = 'support body exact at the bound address'
        elif symbol in COUNTED_ELSEWHERE:
            at, receipt = COUNTED_ELSEWHERE[symbol]
            assert at == value, (name, symbol, hex(value), hex(at))
            data = json.loads((ROOT / 'work/2008-06/shared-layouts' / receipt).read_text())
            assert '%08x' % value in data['exact_function_rows'], (symbol, receipt)
            sbody, srefs = BODIES[symbol]
            starget, strefs = target_of(value)
            assert match.exact_match(starget, strefs, sbody, srefs), ('counted-elsewhere body not exact', symbol)
            elsewhere_out[symbol] = '%s counted by %s (this build exact there)' % (hex(value), receipt)
            how = 'row counted by %s (this build exact there)' % receipt
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external (call site in the original)'
        elif symbol in DATA:
            assert DATA[symbol] == value, (name, symbol, hex(value), hex(DATA[symbol]))
            how = 'data (address the original uses)'
        else:
            UNBOUND.append('    %r: %#x,   # %s in %s' % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        prev = binding.setdefault(symbol, (value, name))
        assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(rows, own):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    result = []
    for address, name in rows:
        body, refs = BODIES[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact, 'unit': 'templates'}
        if not exact:
            assert DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(sections, symbols, definitions, name, body, target, address, own)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


counted = verify(ROWS, {name: address for address, name in ROWS})
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for r in counted:
        if not r['exact']:
            print('NOT EXACT', r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND
assert all(r['exact'] for r in counted)
assert set(SUPPORT) <= set(binding), sorted(set(SUPPORT) - set(binding))
assert set(COUNTED_ELSEWHERE) <= set(binding), sorted(set(COUNTED_ELSEWHERE) - set(binding))
# 00405e20 is operator delete (free), not the operator new twin (malloc) of the same 6-byte shape
_free = [v for k, v in counted[1]['verified_targets'].items()]
assert len(_free) == 1 and _free[0].endswith('!free)'), _free


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
for _sym, _addr in SUPPORT.items():
    assert '%08x' % _addr not in elsewhere, ('support row is counted elsewhere', hex(_addr), elsewhere['%08x' % _addr])
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '%08x' % LO <= a < '%08x' % HI}
FUNCTIONS = [json.loads(x) for x in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()]
RANGE_ROWS = sorted(x['addr'] for x in FUNCTIONS if LO <= int(x['addr'], 16) < HI)
assert set(exact_rows) <= set(RANGE_ROWS), sorted(set(exact_rows) - set(RANGE_ROWS))


# ---- unit-map evidence checks (strings, RTTI, evidence names) ------------------------------------------------------
def cstr(a, n=96):
    return original.data(a, n).split(b'\0')[0].decode('latin-1')


MAP_CHECKS = []
for row in FUNCTIONS:
    if row['addr'] in ('004043f0', '00407500', '004078a0'):
        MAP_CHECKS.append('strings referenced by row %s: %s' % (row['addr'], ' / '.join(row.get('strings') or [])))
_strs = {x['addr']: x.get('strings') or [] for x in FUNCTIONS if x['addr'] in ('004043f0', '00407500', '004078a0')}
assert {'Delete', 'ForceRemove', 'NoRemove'} <= set(_strs['004043f0']), _strs['004043f0']
assert {'Failed to get SiteUrl', 'Untrusted Site: %s'} <= set(_strs['00407500']), _strs['00407500']
assert 'requested WindowType is invalid' in _strs['004078a0'], _strs['004078a0']
for vt, want in ((0x81c80c, '.?AV?$IObjectSafetyRobloxImpl@VCWorkspace@@$00@@'),
                 (0x80b40c, '.?AV?$IObjectSafetyRobloxImpl@VCApp@@$00@@'),
                 (0x80b58c, '.?AV?$CComObject@VCApp@@@ATL@@'), (0x80b50c, '.?AV?$CComObject@VCApp@@@ATL@@'),
                 (0x80b2f0, '.?AVsp_counted_base@detail@boost@@'),
                 (0x80b3f8, '.?AV?$sp_counted_impl_pd@PAVDebugSettings@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@2@@detail@boost@@')):
    rtti = original.vtable_class(vt)
    assert rtti and rtti[0] == want, (hex(vt), rtti)
    MAP_CHECKS.append('vtable %s RTTI %s' % (hex(vt), want))
# CComObject<CApp> ctor-side vtable stores (00407cf0) and the IObjectSafetyRobloxImpl<CWorkspace> slots 3/4
for vt, slot, want in ((0x81c80c, 3, 0x404d20), (0x81c80c, 4, 0x404db0), (0x80b2f0, 2, 0x405e10)):
    got = struct.unpack('<I', original.data(vt + 4 * slot, 4))[0]
    assert got == want, (hex(vt), slot, hex(got))
    MAP_CHECKS.append('vtable %s slot %d = %s' % (hex(vt), slot, hex(want)))
for at, want in ((0x405e10, '?destroy@sp_counted_base@detail@boost@@UAEXXZ'),
                 (0x4062a0, '?AtlGetDefaultUrlPort@ATL@@YAGW4ATL_URL_SCHEME@1@@Z'), (0x407380, '??0CUrl@ATL@@QAE@XZ'),
                 (0x4066c0, '??_H@YGXPAXIHP6EPAX0@Z@Z'), (0x406b80, '??0thread_exception@boost@@QAE@ABV01@@Z')):
    assert names.get(at) == want, (hex(at), names.get(at))
    MAP_CHECKS.append('evidence name %s %s' % (hex(at), want[:70]))
for at, call in ((0x7c8bcc, 0x405e20), (0x7d82f4, 0x405e20)):
    b = original.data(at, 5)
    assert b[0] == 0xe8 and (at + 5 + struct.unpack('<i', b[1:])[0]) & 0xffffffff == call, (hex(at), b.hex())
    MAP_CHECKS.append('unwind funclet call %s -> %s (Creatable<Instance>::operator delete)' % (hex(at), hex(call)))

UNIT_MAP = {
    'atl com unit of CWorkspace ..00405a9f': (
        'Starts at 00401910 (app-unit400-2008 map). In this range: the ATL registrar CRegParser body 00404040 / '
        '004043f0 ("Delete" / "ForceRemove" / "NoRemove") with its EH funclets, CComTypeInfoHolder::GetTI 00404a80 '
        '(app-unit414 binds it under that name), IObjectSafetyRobloxImpl<CWorkspace>::GetInterfaceSafetyOptions / '
        'SetInterfaceSafetyOptions 00404d20 / 00404db0 (slots 3/4 of vtable 0081c80c; listed by the CWorkspace owner '
        'workspace-safety receipt), and the CComObject / CComAggObject / CComClassFactory QueryInterface / Release / '
        'CreateInstance thunks 00404e30..00405a80 (workspace-factory-vtables trial). Not recovered here: CWorkspace is '
        'another owner (CWorkspace.h, CWorkspace*.cpp / Workspace*.cpp); the ATL rows are library header code.'),
    'active-document unit 00405aa0..00405d9f': (
        'setActiveDocument 00405aa0 and its helpers 00405ce0 / 00405d50 / 00405d80 (callers in the doc / view '
        'units). Not recovered here: ActiveDocView owner, and the body dispatches into CRobloxDoc (maintainer '
        'exclusion).'),
    'atl com unit of CApp 00405da0..': (
        'Continues to 0040995f. AbstractFactoryProduct<Instance>::getCreators 00405da0 (built and counted here), '
        'boost::detail::sp_counted_base::destroy 00405e10 (boost header, ICF-shared by every sp_counted_impl vtable; '
        'library), Creatable<Instance>::operator delete 00405e20 (built and counted here), '
        'Creatable<Instance>::Deleter::operator() 00405e30 (needs Instance::predelete, see not_exact), the Creatable '
        'block of RunService 00405e60..0040602f and DebugSettings 00406ed0 / 00407450 / 00407820 (counted elsewhere), '
        'the CApp COM methods 004060d0..00406260 / 004069d0..00406be0 / 00406da0..00407180 / 004078a0 (AFX_MANAGE_STATE '
        'bodies; "requested WindowType is invalid"), the ATL CUrl / AtlUnescapeUrl / CSimpleStringT / CComBSTR inline '
        'COMDATs 004062a0..00406650, 00406930, 00406c00..00406d60, 00407380..00407400, the CRT vector iterator '
        '004066c0, the Name::doDeclare / callDoDeclare instances 00406700..004068c0 / 00406e80..00406ec0, '
        'IObjectSafetyRobloxImpl<CApp> 00407500 / 00407690 / 00407720 ("Untrusted Site: %s"), the std::vector<string> '
        '_Destroy / _Tidy instances 004077a0 / 004077d0 (STL), the boost recursive_mutex scoped_lock ctor / dtor '
        '00407130 / 00407160 (boost), GlobalSettingsItem<DebugSettings>::singleton 00407be0 (built and counted here), '
        'and the CComObject<CApp> constructor 00407cf0 / IsEqualGUID 00407d40 / Release 00407d90 with the adjustor '
        'thunks 00407dc0..00407ff0 (vtables 0080b50c..0080b58c). CApp has no native header or donor source: not '
        'recovered.'),
}
LIBRARY = ('ATL (atlbase.h registrar / class factory / CComObject / CComBSTR, atlutil.h CUrl, atlsimpstr.h '
           'CSimpleStringT), boost (sp_counted_base::destroy 00405e10, thread_exception 00406b80, recursive_mutex '
           'scoped_lock 00407130 / 00407160), STL (vector<string> 004077a0 / 004077d0) and the CRT 004066c0 are header '
           'instances inside the units above. No separately compiled library unit starts in this range. Never '
           'recovered here.')
EXCLUDED = ('No CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView member lies in the range. setActiveDocument 00405aa0 '
            'dispatches into CRobloxDoc (left to its owner); the CApp methods 00406110 / 00406180 / 004061e0 call '
            'members of the running CRobloxApp / log manager and are not recovered (no CApp header).')

NOT_EXACT = [
    {'address': 'Creatable<Instance>::Deleter::operator() 00405e30',
     'reason': 'Blocked, not attempted: the body is Instance::predelete(p) (0055b770, cdecl static) followed by the '
               'virtual delete through the Creatable base at +0x10; v8tree/Instance.h does not declare predelete and '
               'util/Object.h only declares operator(). Existing proposal (TANDEM 2026-11-04/06, util/Object.h owner): '
               'define it inline; it also needs `static void predelete(Instance*);` in Instance.h (core, owner only).'},
    {'address': 'CApp COM rows (004060d0..004078a0, 00407cf0..00407ff0)',
     'reason': 'Not attempted: CApp has no native header and no donor source; its layout and interface set (IApp '
               'dispinterface, IObjectSafetyRobloxImpl<CApp>, CComObject<CApp> at +0/+4/+0xc/+0x14) would have to be '
               'derived first. Several bodies also call CRobloxApp members (maintainer exclusion).'},
    {'address': 'CWorkspace COM unit rows 00404040..00405a80',
     'reason': 'Other owner (CWorkspace family, workspace-* receipts and trials); ATL library header code otherwise.'},
    {'address': 'setActiveDocument 00405aa0 and helpers 00405ce0 / 00405d50 / 00405d80',
     'reason': 'ActiveDocView owner (native-classes/ActiveDocument.cpp); dispatches into CRobloxDoc.'},
]

REJECTED = {}

PROPOSALS = [
    'util/Object.h (core owner) + v8tree/Instance.h (core owner), re-confirming the 2026-11-04 proposal: define '
    'Creatable<T>::Deleter::operator()(T* obj) { T::predelete(obj); delete obj; } inline and declare '
    '`static void predelete(Instance*);` (0055b770) accessible to it. Evidence: 00405e30 = push p; call 0055b770; '
    'add esp,4; then delete through [p+0x10] slot 0 with 1; the dispose body 0048ee50 inlines the same sequence.',
]

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
counted_set = set(exact_rows)
receipt = {
    'class': 'RBX template instances of the ATL COM unit of CApp in the application range 00404000..00408000 '
             '(2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'range_rows': len(RANGE_ROWS),
    'unit_blocks': ['0x404000..0x405aa0 ATL COM unit of CWorkspace (from 0x401910)',
                    '0x405aa0..0x405da0 active-document unit',
                    '0x405da0..0x408000 ATL COM unit of CApp (continues to 0x409960)'],
    'unit_map': UNIT_MAP,
    'library': LIBRARY,
    'excluded': EXCLUDED,
    'unit_map_checks': MAP_CHECKS,
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any quoted bare address in another receipt as counted there.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_counted': ' '.join(a for a in RANGE_ROWS if a not in range_counted and a not in counted_set),
    'rows': counted,
    'support_rows': support_out,
    'targets_counted_elsewhere': elsewhere_out,
    'pending_rows': [],
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit404: %d counted exact rows (%s); 0 pending-build-only, %d range rows, %d counted elsewhere, '
      '%d support rows' % (len(exact_rows), ' '.join(exact_rows), len(RANGE_ROWS), len(range_counted), len(support_out)))
