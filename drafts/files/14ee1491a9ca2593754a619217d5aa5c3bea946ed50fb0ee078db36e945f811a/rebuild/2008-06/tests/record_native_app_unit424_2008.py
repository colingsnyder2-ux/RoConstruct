"""Verify the inactive 2008-06 native rows of the application range 00424000..00430000 and record its unit map.

Unit map (boundary evidence checked below and written to the receipt's `unit_map`; rows counted by other receipts are
listed as 'ADDR counted by RECEIPT' text, never as quoted bare addresses):
  * 00424030..0042730f  CSelectionTreeCtrl unit (SelectionTreeCtrl.cpp with the CRobloxTreeCtrl / CRobloxTreeCtrlNode /
    RootNode header code and its std::set / vector instances); selection-tree-ctrl / roblox-tree-ctrl count most of it.
  * 00427310..0042788f  LoginRenewer unit (the KeepAlivePinger URL, renewLogin, the LoginRenewer worker_thread
    constructor 004277d0 of native-classes/LoginRenewer.cpp, whose probe receipt counts no row).
  * 00427890..0042a62f  LogManager unit (LogManager / ThreadLogManager / MainLogManager / RobloxCrashReporter).
    Blocked: native-headers/CRobloxApp.h declares ThreadLogManager / MainLogManager with bases that contradict the RTTI
    (see `proposals`); not recovered here.
  * 0042a630..0042cecf  CLuaHtmlView unit (EventHandler, CLuaHtmlView::Binder; luahtml-binder2008 / app-leaves2008).
  * 0042ced0..0042e45f  CLuaFunction unit (CComObject<CLuaFunction>, LuaArgs::push): this recorder builds its RBX
    ScriptContext template COMDATs (native-classes/AppUnit424_2008ScriptContextTemplates.cpp).
  * 0042e460..0042ffff  CMainFrame unit (MainFrm.cpp with MyXTPCommandBars, CPatchedControlComboBox, CWrapperView and
    the XTP control overrides): maintainer exclusion (CMainFrame / CWrapperView), mapped only.

Build: VS2008 RTM 21022, document-swap flags, /fp:fast, current native headers only (read-only); no new header, so no
recorder is shadowed. Every counted row is relocation-masked exact against the original and every REL32/DIR32 target
is bound to the address the original instruction uses and verified, one address per symbol over all rows: imports by
DLL export name, class-name arrays by bytes, own rows by their row address, local statics / guards by consistency (in
the original's data sections), rows counted by other receipts by that receipt, find<ScriptContext>() const by
identity (open row) and the remaining externals by the explicit EXTERNAL map. A row is counted only when no other
receipt counts it. Writes work/2008-06/shared-layouts/app-unit424-2008-working.json.
NATIVE_APP_UNIT424_DISCOVER=1 lists unbound targets.
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
NH = R / 'native-headers'
OUT = R / 'out/app-unit424-2008'
OUT.mkdir(parents=True, exist_ok=True)
SOURCES = {'templates': R / 'native-classes/AppUnit424_2008ScriptContextTemplates.cpp'}
HEADERS = [NH / h for h in ('script/ScriptContext.h', 'v8tree/Service.h', 'v8tree/Instance.h', 'util/Object.h',
                            'util/Name.h')]
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit424-2008-working.json'
LO, HI = 0x424000, 0x430000
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT424_DISCOVER'))


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/fp:fast', '/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['templates'], FLAGS['templates'] = build('AppUnit424_2008ScriptContextTemplates', SOURCES['templates'])

original = nb.Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {}
for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines():
    if line.strip():
        x = json.loads(line)
        FUNCTIONS[int(x['addr'], 16)] = x

# ---- rows --------------------------------------------------------------------------------------------------------
SC = 'VScriptContext@RBX@@'
SP = '@ServiceProvider@RBX@@'
FP = '?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@3PADA@RBX@@'
CR = '?$Creatable@VInstance@RBX@@@RBX@@'
ROWS = {'templates': [
    (0x42ced0, '??$doDeclare@$1?sScriptContext@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x42d090, '??$callDoDeclare@$1?sScriptContext@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x42d030, '??$doGetClassIndex@' + SC + '@ServiceProvider@RBX@@SAIXZ'),
    (0x42d180, '??$callDoGetClassIndex@' + SC + '@ServiceProvider@RBX@@SAXXZ'),
    (0x42dfd0, '??$create@' + SC + '@ServiceProvider@RBX@@QBEPAVScriptContext@1@XZ'),
    (0x42d3f0, '??$create@' + SC + '@' + CR + 'SA?AV?$shared_ptr@VScriptContext@RBX@@@boost@@XZ'),
    (0x42d2c0, '??$?0VScriptContext@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@?$shared_ptr@VScriptContext@RBX@@@'
               'boost@@QAE@PAVScriptContext@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z'),
    (0x42dde0, '?create@Creator@' + FP + 'UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ'),
]}
CLASS_NAMES = {'?sScriptContext@RBX@@3PADA': 'ScriptContext'}

# find<ScriptContext>() const: compiled here through create, not exact (open row; see NOT_EXACT). Bound by identity:
# the original create row calls 0042de90, and the 0042de90 bytes push this unit's callDoGetClassIndex / callDoDeclare
# rows for call_once.
FIND = '??$find@' + SC + '@ServiceProvider@RBX@@QBEPAVScriptContext@1@XZ'
IDENTITY = {FIND: 0x42de90}

# Externals: call targets read in the original disassembly (callers named in comments).
EXTERNAL = {
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,                 # doDeclare 0042cf07
    '?newIndex@ServiceProvider@RBX@@SAIXZ': 0x572690,              # doGetClassIndex 0042d060
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,             # create 0042e061
    '??0ScriptContext@RBX@@QAE@XZ': 0x5ae490,                      # create<ScriptContext> 0042d434 (vtable 008347fc)
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,                  # create 0042e01a
}
# Targets counted (with this symbol) by another receipt.
COUNTED_TARGETS = {
    '??$?0PAVScriptContext@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVScriptContext@'
    'RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': (0x42d0f0, 'creatable-shared-count-working.json'),
}

DATA_SECTIONS = [(original.image + s.VirtualAddress, original.image + s.VirtualAddress + s.Misc_VirtualSize)
                 for s in original.pe.sections if s.Name.rstrip(b'\0') in (b'.data', b'.rdata')]
own = {s: a for rows in ROWS.values() for a, s in rows}
BINDING = {}
UNBOUND = []
HELPERS = {}


def bind(symbol, value, where):
    prev = BINDING.setdefault(symbol, (value, where))
    assert prev[0] == value, ('one address per symbol', symbol, hex(prev[0]), prev[1], hex(value), where)


def receipt_counts(name, address, symbol):
    data = json.loads((ROOT / 'work/2008-06/shared-layouts' / name).read_text())
    rows = data.get('exact_function_rows', data.get('exact_distinct_addresses', []))
    assert '%08x' % address in [str(r) for r in rows], (name, hex(address))
    found = []

    def walk(o):
        if isinstance(o, dict):
            if o.get('address') == '%08x' % address and o.get('symbol'):
                found.append(o['symbol'])
            for v in o.values():
                walk(v)
        elif isinstance(o, list):
            for v in o:
                walk(v)
    walk(data)
    assert symbol in found, (name, hex(address), symbol, found)


def verify(build_name, obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    out = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        exact = match.exact_match(target, target_refs, body, refs)
        row = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
               'exact': bool(exact), 'build': build_name, 'verified_targets': {}, 'local_eh': []}
        out.append(row)
        if not exact:
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
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
            elif symbol in CLASS_NAMES:
                lit = CLASS_NAMES[symbol].encode() + b'\0'
                assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
                how = 'class name %r' % CLASS_NAMES[symbol]
            elif symbol in IDENTITY:
                assert IDENTITY[symbol] == value, (where, symbol, hex(value))
                how = 'identity (open row, see not_exact)'
            elif symbol in COUNTED_TARGETS:
                assert COUNTED_TARGETS[symbol][0] == value, (where, symbol, hex(value))
                receipt_counts(COUNTED_TARGETS[symbol][1], value, symbol)
                how = 'counted by %s' % COUNTED_TARGETS[symbol][1]
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (where, symbol, hex(value))
                how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else '')
            elif symbol in bodies:
                hb, hr = bodies[symbol]
                ht, htr, _ = match.target('2008-06', '%08x' % value)
                assert match.exact_match(ht, htr, hb, hr), (where, symbol, hex(value))
                HELPERS.setdefault(symbol, '%#x' % value)
                how = 'helper body exact at the bound address (not counted)'
            elif symbol in definitions and symbol not in bodies:
                assert any(lo <= value < hi for lo, hi in DATA_SECTIONS), (where, symbol, hex(value))
                how = 'own static (bound by consistency)'
            if how is None:
                UNBOUND.append((where, symbol, hex(value)))
                continue
            bind(symbol, value, where)
            row['verified_targets'][symbol] = '%#x (%s)' % (value, how)
    return out, bodies


groups, BODIES = {}, {}
for k in ROWS:
    groups[k], BODIES[k] = verify(k, OBJ[k], ROWS[k])
assert not UNBOUND or DISCOVER, UNBOUND
not_exact = [r for rows in groups.values() for r in rows if not r['exact']]
assert not not_exact or DISCOVER, [(r['address'], r['symbol'][:80]) for r in not_exact]

# find<ScriptContext>() const: the compiled body is present and not exact (open), and the original row is the
# ServiceProvider lookup of this unit: it pushes callDoGetClassIndex / callDoDeclare <ScriptContext> for call_once.
fb, fr = BODIES['templates'][FIND]
ft, ftr, _ = match.target('2008-06', '%08x' % IDENTITY[FIND])
assert not match.exact_match(ft, ftr, fb, fr) and len(ft) == 320 and len(fb) == 404, (len(ft), len(fb))
assert struct.pack('<BI', 0x68, 0x42d180) in ft and struct.pack('<BI', 0x68, 0x42d090) in ft
assert struct.pack('<BI', 0x68, 0x96d130) in ft and struct.pack('<BI', 0x68, 0x96d12c) in ft
_rel = lambda body, at, base: (base + at + 5 + struct.unpack_from('<i', body, at + 1)[0]) & 0xffffffff
_calls = [_rel(ft, i, 0x42de90) for i in range(len(ft) - 4) if ft[i] == 0xe8]
assert 0x600660 in _calls and 0x557330 in _calls, [hex(c) for c in _calls]

# Creator vtable: 00810710 (RTTI Creator<FactoryProduct<ScriptContext, Instance, sScriptContext>>) slot 0 = 0042dde0;
# it is referenced only by the creator static's initializer 007fa90x.
CREATOR_VT = 0x810710
rtti, at = original.vtable_class(CREATOR_VT)
assert rtti == '.?AVCreator@' + FP and at == 0, (rtti, at)
assert d(CREATOR_VT) == 0x42dde0
SLOTS = {'0x810710 slot 0': '0x42dde0 (%s offset %#x)' % (rtti, at)}

# Layout: ScriptContext is 0x1f8 bytes (the exact create<ScriptContext> 0042d3f0 pushes 0x1f8 to malloc before the
# constructor 005ae490 stores the ScriptContext vtables 008347fc / 008347f0 / 008347e8 / 008347e0 / 008347d0).
create_body = original.data(0x42d3f0, 120)
assert struct.pack('<BI', 0x68, 0x1f8) in create_body
assert original.vtable_class(0x8347fc) == ('.?AVScriptContext@RBX@@', 0)
LAYOUT = {'ScriptContext': 'sizeof 0x1f8 (malloc 0x1f8 in the exact create<ScriptContext> 0x42d3f0)',
          'ServiceProvider': 'serviceArray (v8tree/Service.h) begin / end read at this+0x19c / this+0x1a0 in the exact '
                             'create<ScriptContext>() const 0x42dfd0'}


# ---- unit map evidence -------------------------------------------------------------------------------------------
def holds_string(address, text):
    """The row's bytes hold a DIR32 pointer to that exact NUL-terminated string."""
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


BLOCKS = [   # (name, start, end, kind, string evidence, vtable evidence {vtable: (RTTI, {slot: row})})
    ('CSelectionTreeCtrl unit', LO, 0x427310, 'rbx-mfc', [(0x426ef0, 'Drop')], {
        0x80fed4: ('.?AVCSelectionTreeCtrl@@', {84: 0x426bd0, 85: 0x425da0, 86: 0x424600, 89: 0x426680}),
        0x80fcd4: ('.?AVCRobloxTreeCtrl@@', {1: 0x425c70, 12: 0x4272f0}),
        0x80fc28: ('.?AVCRobloxTreeCtrlNode@@', {0: 0x424dd0, 6: 0x424c00}),
        0x810060: ('.?AVRootNode@@', {6: 0x426640})}),
    ('LoginRenewer unit', 0x427310, 0x427890, 'rbx', [
        (0x427310, '/Game/KeepAlivePinger.ashx'), (0x427480, 'renewLogin %s failed: %s'),
        (0x4277d0, 'LoginRenewer')], {}),
    ('LogManager unit', 0x427890, 0x42a630, 'rbx-blocked', [
        (0x427b00, 'ROBLOX Crash'), (0x427f30, 'log_'), (0x4282a0, 'Pure Call Error'), (0x428790, 'G3D Error: %s\n%s(%d)')],
     {0x8104b4: ('.?AVThreadLogManager@@', {0: 0x429300, 1: 0x427890}),
      0x8104c0: ('.?AVMainLogManager@@', {1: 0x427f30}),
      0x8104cc: ('.?AVMainLogManager@@', {0: 0x42a5c0}),
      0x81030c: ('.?AVLogManager@@', {0: 0x428cf0}),
      0x810320: ('.?AVRobloxCrashReporter@@', {0: 0x427b00})}),
    ('CLuaHtmlView unit', 0x42a630, 0x42ced0, 'rbx', [
        (0x42ae50, 'The HtmlDocument is not loaded'), (0x42c0d0, 'attachEvent failed'), (0x42c8c0, '%s not found')], {
        0x810598: ('.?AVEventHandler@@', {0: 0x42adb0, 6: 0x42b130}),
        0x810654: ('.?AVBinder@CLuaHtmlView@@', {0: 0x42c4e0}),
        0x810524: ('.?AV?$sp_counted_impl_p@VPropBinding@Binder@CLuaHtmlView@@@detail@boost@@', {1: 0x42b310})}),
    ('CLuaFunction unit', 0x42ced0, 0x42e460, 'rbx', [
        (0x42ced0, 'ScriptContext'), (0x42db20, 'Invalid argument %d VT_TYPE=%d'),
        (0x42e350, 'CLuaFunction::Call failed, %s')], {
        0x80ebd8: ('.?AV?$CComObject@VCLuaFunction@@@ATL@@', {7: 0x42e0c0, 8: 0x42da40}),
        CREATOR_VT: ('.?AVCreator@' + FP, {0: 0x42dde0})}),
    ('CMainFrame unit', 0x42e460, HI, 'excluded', [
        (0x42e4c0, 'CMainFrameV2'), (0x42f9d0, 'CommandBars'), (0x42fcf0, 'Camera Positioning')], {
        0x811a1c: ('.?AVCMainFrame@@', {0: 0x42e460, 27: 0x42e500, 87: 0x42eee0}),
        0x810804: ('.?AVMyXTPCommandBars@@', {0: 0x42e4b0, 33: 0x42e470}),
        0x810914: ('.?AVCPatchedControlComboBox@@', {0: 0x42eb30, 34: 0x42eac0}),
        0x810a9c: ('.?AVCWrapperView@@', {0: 0x42ece0, 71: 0x42ec10})}),
]
EVIDENCE = []
for name, lo, hi, kind, strings, vts in BLOCKS:
    for a, text in strings:
        assert lo <= a < hi and holds_string(a, text), (name, hex(a), text)
        EVIDENCE.append('%s: %#x holds string %r' % (name, a, text))
    for vt, (want, slots) in vts.items():
        got = original.vtable_class(vt)
        assert got[0] == want, (name, hex(vt), got)
        for slot, row in slots.items():
            assert d(vt + 4 * slot) == row and lo <= row < hi, (name, hex(vt), slot, hex(d(vt + 4 * slot)))
            EVIDENCE.append('%s: vtable %#x (%s) slot %d = %#x' % (name, vt, want, slot, row))
range_rows = sorted(a for a in FUNCTIONS if LO <= a < HI)
for a in range_rows:
    assert sum(lo <= a < hi for _, lo, hi, _, _, _ in BLOCKS) == 1, hex(a)
for a, _ in ROWS['templates']:
    assert 0x42ced0 <= a < 0x42e460, hex(a)
# the LogManager blocker: native CRobloxApp.h declares ThreadLogManager without a LogManager base and MainLogManager
# with LogManagerSink + ThreadLogManager bases; the RTTI has ThreadLogManager : LogManager and MainLogManager :
# ILogProvider (+0), LogManager (+4).
app_h = (NH / 'CRobloxApp.h').read_text()
assert 'class ThreadLogManager {' in app_h and 'class MainLogManager : public LogManagerSink, public ThreadLogManager' in app_h


# ---- counting rules ------------------------------------------------------------------------------------------------
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
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}

UNIT_MAP = {}
for name, lo, hi, kind, _, _ in BLOCKS:
    rows = [a for a in range_rows if lo <= a < hi]
    UNIT_MAP['%s %#x..%#x' % (name, lo, hi - 1)] = {
        'kind': kind, 'rows': len(rows), 'bytes': sum(FUNCTIONS[a]['size'] for a in rows),
        'counted_here': len([a for a in rows if '%08x' % a in exact_rows]),
        'counted_elsewhere': len([a for a in rows if '%08x' % a in range_counted]),
        'open': ['%#x' % a for a in rows if '%08x' % a not in exact_rows and '%08x' % a not in range_counted],
    }
UNIT_NOTES = {
    'CSelectionTreeCtrl unit': (
        'SelectionTreeCtrl.cpp with the CRobloxTreeCtrl / CRobloxTreeCtrlNode / RootNode header code (vtables '
        '0x80fed4 / 0x80fcd4 / 0x80fc28 / 0x810060, the XTP CXTTreeCtrl overrides 0x425bc0..0x425c60) and its std::set '
        '/ vector / map instances (std::set<WeakReferenceCountedPointer<Render::Chunk>> insert 0x424030 is an ICF body '
        'per its evidence name). selection-tree-ctrl-working.json and roblox-tree-ctrl-working.json count most rows; '
        'the open rows are std::_Tree / vector instances and CSelectionTreeCtrl handlers those recorders leave open.'),
    'LoginRenewer unit': (
        'loginRenewalUrl 0x427310 ("/Game/KeepAlivePinger.ashx" appended to the base URL), the boost::bind storage / '
        'list1<value<std::string>> instances 0x4273b0 / 0x427410 (evidence names), renewLogin 0x427480 (atoi of the '
        'reply, clamped 1..30 minutes, boost::thread::sleep), the boost::function manager / invoker instances '
        '0x427620..0x427720 and LoginRenewer() 0x4277d0 (native-classes/LoginRenewer.cpp; its login-renewer probe '
        'receipt has no exact row list, so nothing here is counted). Not recovered in this pass: renewLogin needs the '
        'Http / StandardOut / Time declarations of other owners.'),
    'LogManager unit': (
        'LogManager (vtable 0x81030c, dtor 0x428cf0), ThreadLogManager (0x8104b4: slots 0x429300 / 0x427890), '
        'MainLogManager (0x8104cc / 0x8104c0, ctor 0x42a1c0), RobloxCrashReporter (0x810320, ProcessException '
        '0x427b00 counted by app-leaves2008), the crash / assert / G3D-error hooks 0x4282a0..0x428790, the log-file '
        'archive helpers 0x4284e0..0x428d10 / 0x429bc0..0x42a3d0 and their std::vector<std::string> / list '
        'instances. Blocked: see proposals (CRobloxApp.h log-manager declarations contradict the RTTI). Rows '
        '0x42a5f0 (getRootAncestor ICF body) and 0x42a610 (jmp operator delete) are ICF-shared.'),
    'CLuaHtmlView unit': (
        'starts with shared_count<CLuaHtmlView::Binder*> 0x42a630 (stores sp_counted_impl_p<Binder> 0x810538); '
        'EventHandler (0x810598) and CLuaHtmlView::Binder (0x810654) are counted by app-leaves2008 / '
        'luahtml-binder2008. The open rows are the boost::function managers / invokers of the Binder bind_t functors '
        '(type_info 0x92e6b0 / 0x92e7a0 / 0x92e9b8), the Security::Context thread_specific_ptr / tss_adapter '
        'instances, std::list<shared_ptr<PropBinding>> helpers and CLuaHtmlView 0x42c8c0 (luahtml-binder2008 '
        '`left`).'),
    'CLuaFunction unit': (
        'starts with Name::doDeclare<sScriptContext> 0x42ced0 (no caller before 0x42ced0 references the ScriptContext '
        'templates); boost::any holder<float> / holder<int> type / clone 0x42cf40..0x42cf90 (boost templates of '
        'built-in types, referenced from many units: library, not recovered), the std::vector<Reflection::Value> '
        'instances 0x42cfc0..0x42d980 (open), the Value(float / bool / int) constructors and LuaArgs::push / '
        'vector<Value>::push_back (lua-args-trial), CComObject<CLuaFunction> (0x80ebd8: slot 7 0x42e0c0 Invoke, '
        'slot 8 0x42da40) and the ScriptContext service templates counted here.'),
    'CMainFrame unit': (
        'MainFrm.cpp: CMainFrame (0x811a1c), MyXTPCommandBars (0x810804; its probe receipt counts no row), '
        'CPatchedControlComboBox (0x810914), CWrapperView (0x810a9c) and the XTP CXTPControl overrides 0x42e770..'
        '0x42ea90. Maintainer exclusion (CMainFrame / CWrapperView): mapped only, never recovered here.'),
}
for key in list(UNIT_MAP):
    UNIT_MAP[key]['unit'] = UNIT_NOTES[key.rsplit(' ', 1)[0]]

NOT_EXACT = {
    '0x42de90 ServiceProvider::find<ScriptContext>() const (320 B)': (
        'compiled here through create<ScriptContext>() const: 404 B, because the native boost shared_ptr<Instance> '
        'destructor is inlined where the original calls it out of line (0x600660); the same open shape as find<C>() '
        'const 0x490af0.. in app-unit48c-2008 (a generated noinline-destructor profile is not used). Open; bound by '
        'identity where the counted create row calls it.'),
}
REJECTED = {}
PROPOSALS = {
    'native-headers/CRobloxApp.h (owner; maintainer exclusion: proposal only)': (
        'the log-manager classes: RTTI of vtable 0x81030c is LogManager (no bases; slot 0 dtor 0x428cf0), of '
        '0x8104b4 ThreadLogManager : LogManager (slots 0x429300 / 0x427890), of 0x8104cc / 0x8104c0 MainLogManager : '
        'RBX::ILogProvider (+0, leaves2008/Log2008.h), LogManager (+4) (attr 1, nbases 3). CRobloxApp.h declares '
        'ThreadLogManager without a base and MainLogManager : LogManagerSink, ThreadLogManager, which gives other '
        'RTTI and vtables. Proposal: declare LogManager / ThreadLogManager : LogManager / MainLogManager : '
        'RBX::ILogProvider, LogManager in a separate native header (e.g. LogManager.h) that CRobloxApp.h includes; '
        'it unlocks the LogManager unit 0x427890..0x42a62f (constructors 0x42a1c0 / 0x42a4f0, vtables above).'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'unit map and RBX ScriptContext template rows of the application range 00424000..00430000 (2008-06), '
             'inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'layout': LAYOUT,
    'unit_map': UNIT_MAP,
    'unit_evidence': EVIDENCE,
    'range_functions': len(range_rows),
    'range_bytes': sum(FUNCTIONS[a]['size'] for a in range_rows),
    # 'ADDR counted by RECEIPT' text, never a quoted bare address (local_backpack / viewnew_brick_build /
    # viewnew_part_mesh treat any quoted bare address in another receipt as counted there).
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'rows': groups,
    'vtable_slots': SLOTS,
    'helper_bodies_not_counted': HELPERS,
    'not_exact': NOT_EXACT,
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'shadowing': 'none (no new native header)',
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
text = json.dumps(receipt, indent=2) + '\n'
bare = set(re.findall(r'"([0-9a-f]{8})"', text))
assert bare <= set(exact_rows), sorted(bare - set(exact_rows))
RECEIPT.write_text(text)
if UNBOUND:
    print('UNBOUND', UNBOUND)
print('PASS app-unit424-2008: %d counted exact rows (%s); %d range rows, %d counted elsewhere, %d blocks'
      % (len(exact_rows), ' '.join(exact_rows), len(range_rows), len(range_counted), len(BLOCKS)))
