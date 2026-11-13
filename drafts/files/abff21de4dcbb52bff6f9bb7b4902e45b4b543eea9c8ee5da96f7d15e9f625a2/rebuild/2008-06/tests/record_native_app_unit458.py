"""Verify the inactive 2008-06 native rows of the application range 00458000..0045c000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as
'ADDR counted by RECEIPT' text, never as quoted bare addresses).

Unit map summary (details in UNIT_MAP below; the blocks continue the app-unit454-2008 map of 00454000..00460000):
  * 00458000..00458e6f: the tail of the CRobloxReportView unit (CRobloxReportView / CStatsItemRecord members of the
    native CRobloxReportView.h owner, StatsService instances counted by stats-service / app-unit454-2008).
  * 00458e70..0045afcf: the CRobloxView unit (maintainer exclusion; its verbs are other owners' classes) and the G3D
    6.09 header-inline COMDATs emitted there (library).
  * 0045afd0..: the CRobloxWnd unit (CRobloxWnd is declared in the native CRobloxView.h, other owner), continuing past
    the range. Built here: the std::auto_ptr<G3D::RenderDevice> destructor 0045b620, a Roblox-instantiated STL
    template that only this unit references (EH unwind funclets of the CRobloxWnd constructor and destructor).

Build: native-classes/AppUnit458RenderDevicePtr.cpp, document-swap flags, VS2008 RTM 21022 (no extra flags, no new
header, nothing shadowed). Every counted row is relocation-masked exact against the original with the same length,
and every REL32/DIR32 target is bound to the address the original instruction uses and verified: imports by export
name, externals by the explicit EXTERNAL map (call-site identification), one address per symbol. A row is counted only
when no other receipt counts it. Writes work/2008-06/shared-layouts/app-unit458-working.json.
Set NATIVE_APP_UNIT458_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
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
OUT = nb.OUT / 'app-unit458'
OUT.mkdir(parents=True, exist_ok=True)
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT458_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit458-working.json'
LO, HI = 0x458000, 0x45c000
SOURCES = {
    'renderdeviceptr': R / 'native-classes/AppUnit458RenderDevicePtr.cpp',
}


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = {}, {}
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeAppUnit458_' + key, src)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

# ---- externals: address the original instruction uses -------------------------------------------------------------
EXTERNAL = {
    # G3D 6.09 RenderDevice::~RenderDevice (library body in RenderDevice.cpp; app-unit478 maps 0047bec0 to that unit).
    # Call-site identification: 0045b620 calls it with the auto_ptr's pointer in ecx, then operator delete; the body
    # destroys members at +0x89c / +0x880 / +0x120 under an EH frame (checked below).
    '??1RenderDevice@G3D@@QAE@XZ': 0x47bec0,
}
UNBOUND = []
binding = {}

# (address, symbol): one entry per counted address
ROWS = {
    'renderdeviceptr': [
        (0x0045b620, '??1?$auto_ptr@VRenderDevice@G3D@@@std@@QAE@XZ'),
    ],
}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in funcs])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in funcs])
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
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else ' (call-site identification)')
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
        exact = len(body) == len(target) and match.exact_match(target, target_refs, body, refs)
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


# ---- boundary / identity evidence checked against the original bytes ---------------------------------------------
IMAGE = original.pe.get_memory_mapped_image()


def dword(va):
    return struct.unpack_from('<I', IMAGE, va - original.image)[0]


def cstring(va, limit=256):
    raw = IMAGE[va - original.image:va - original.image + limit]
    return raw[:raw.index(b'\0')].decode('latin-1')


def rtti(vtable):
    col = dword(vtable - 4)
    return cstring(dword(col + 12) + 8), dword(col + 4)


def refs_to(value, lo=0x401000, hi=0x9a0000):
    """Addresses whose dword equals value (data references, e.g. unwind maps and vtables)."""
    image = IMAGE
    base = original.image
    pattern = struct.pack('<I', value)
    out, o = [], 0
    while True:
        o = image.find(pattern, o)
        if o < 0:
            return [x for x in out if lo <= x < hi]
        out.append(base + o)
        o += 1


VTABLES = {
    0x818a74: ('.?AVCStatsItemRecord@CRobloxReportView@@', 0x0),     # slot 1 = 00458150 (scalar deleting dtor)
    0x818a5c: ('.?AVCStatsItemRecord@CRobloxReportView@@', 0x54),    # slot 2 = 004581a0 (listener base)
    0x81933c: ('.?AVCRobloxView@@', 0x0),                             # slot 0 = 00458e70 (GetRuntimeClass)
    0x8199f4: ('.?AVCRobloxWnd@@', 0x0),                              # slot 0 = 0045afd0 (GetMessageMap)
    0x8199e8: ('.?AVCRobloxWnd@@', 0x54),                             # IRunView base: slot 1 = 0045ba60
    0x819750: ('.?AVHashable@G3D@@', 0x0),                            # 0045ac70 / 0045ac80
    0x81975c: ('.?AVGImage@G3D@@', 0x0),                              # 0045aca0
    0x819770: ('.?AVTextureArgs@TextureManager@G3D@@', 0x0),          # 0045adc0 / 0045ae10
    0x819840: ('.?AV?$sp_counted_impl_pd@PAVRenderStatsItem@CRobloxWnd@@VDeleter@?$Creatable@VInstance@RBX@@@RBX@@'
               '@detail@boost@@', 0x0),                               # stored by shared_count 0045b700
}
for vt, (want, off) in VTABLES.items():
    assert rtti(vt) == (want, off), (hex(vt), rtti(vt), want, off)
SLOTS = {(0x818a74, 1): 0x458150, (0x818a5c, 2): 0x4581a0, (0x81933c, 0): 0x458e70, (0x8199f4, 0): 0x45afd0,
         (0x8199e8, 1): 0x45ba60}
for (vt, slot), fn in SLOTS.items():
    assert dword(vt + 4 * slot) == fn, (hex(vt), slot, hex(dword(vt + 4 * slot)), hex(fn))
assert original.data(0x45b74a, 6) == bytes.fromhex('c70040988100'), 'shared_count 0045b700 stores the RenderStatsItem vtable'

# 0045b620 is reached only from two EH unwind funclets (tail jumps on this+0xac); their unwind maps belong to the CRobloxWnd constructor 0045c730
# and destructor 0045fbe0 (the handler thunk referencing each FuncInfo is pushed at the function's entry).
FUNCLET_PARENTS = {}
for funclet, call_site in [(0x7c2c9b, 0x7c2ca4), (0x7c3090, 0x7c3099)]:
    # funclet: mov ecx, [ebp-0x10] (this); add ecx, 0xac (the member); jmp 0045b620
    assert original.data(funclet, 9) == bytes.fromhex('8b4df081c1ac000000'), hex(funclet)
    insn = original.data(call_site, 5)
    assert insn[0] == 0xe9 and (call_site + 5 + struct.unpack('<i', insn[1:])[0]) & 0xffffffff == 0x45b620, hex(call_site)
    (entry,) = refs_to(funclet, 0x800000, 0x9a0000)
    start = entry - 4
    while True:  # walk back to the first unwind entry (toState, action)
        state, action = struct.unpack('<iI', original.data(start - 8, 8))
        if -1 <= state < 64 and (action == 0 or 0x7c0000 <= action < 0x7d0000):
            start -= 8
        else:
            break
    (funcinfo_map_ref,) = refs_to(start, 0x800000, 0x9a0000)
    funcinfo = funcinfo_map_ref - 8
    assert dword(funcinfo) == 0x19930522, hex(funcinfo)
    (handler_ref,) = refs_to(funcinfo, 0x7c0000, 0x7d0000)
    (push_site,) = refs_to(handler_ref - 1, 0x401000, 0x6a0000)
    FUNCLET_PARENTS['%x' % funclet] = (start, funcinfo, push_site - 3)
BRANCHES = []
for m in re.finditer(b'[\xe8\xe9]', IMAGE[0x1000:0x3d0000]):
    at = original.image + 0x1000 + m.start()
    if (at + 5 + struct.unpack_from('<i', IMAGE, at + 1 - original.image)[0]) & 0xffffffff == 0x45b620:
        BRANCHES.append(at)
assert BRANCHES == [0x7c2ca4, 0x7c3099], [hex(x) for x in BRANCHES]
assert refs_to(0x45b620) == [], 'no data reference (vtable) to 0045b620'
assert FUNCLET_PARENTS['7c2c9b'][2] == 0x45c730 and FUNCLET_PARENTS['7c3090'][2] == 0x45fbe0, FUNCLET_PARENTS

# 0045bde0 releases the member: cleanup() 0047c3e0, then `if (p) { ~RenderDevice(); delete p; }` before `p = 0`
# (std::auto_ptr::reset(0) order: compare, delete, store; boost::scoped_ptr::reset stores first).
reset = original.data(0x45be08, 0x33)
assert reset[:2] == bytes.fromhex('8b8e') and reset[10:11] == b'\xe8', reset.hex()
assert (0x45be12 + 5 + struct.unpack('<i', original.data(0x45be13, 4))[0]) == 0x47c3e0
assert (0x45be23 + 5 + struct.unpack('<i', original.data(0x45be24, 4))[0]) == 0x47bec0
assert original.data(0x45be31, 10) == bytes.fromhex('c786ac00000000000000'), 'store of 0 after the delete'
# "Shutting down RenderDevice." is pushed by 0047c3e0 (G3D RenderDevice::cleanup)
cleanup = original.data(0x47c3e0, 0x80)
pushes = [struct.unpack('<I', cleanup[i + 1:i + 5])[0] for i in range(len(cleanup) - 5) if cleanup[i] == 0x68]
assert any(0x800000 <= p < 0x900000 and cstring(p, 64).startswith('Shutting down RenderDevice.') for p in pushes), pushes
# ~RenderDevice 0047bec0: EH frame, then member destructors at +0x89c / +0x880 / +0x120
dtor = original.data(0x47bec0, 0x60)
for disp in (b'\x9c\x08\x00\x00', b'\x80\x08\x00\x00', b'\x20\x01\x00\x00'):
    assert disp in dtor, (disp.hex(), dtor.hex())


# ---- rows counted by other receipts ------------------------------------------------------------------------------
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
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if LO <= int(a, 16) < HI}

# ---- unit map ----------------------------------------------------------------------------------------------------
RANGE_ROWS = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()]
RANGE_ROWS = [r for r in RANGE_ROWS if LO <= int(r['addr'], 16) < HI]
UNITS = [
    ('rbx CRobloxReportView unit tail', 0x458000, 0x458e70, False),
    ('rbx CRobloxView unit', 0x458e70, 0x45afd0, False),
    ('rbx CRobloxWnd unit', 0x45afd0, 0x45c000, False),
]
# Open rows: why each one is not built here (text keys, no quoted bare addresses)
OPEN = {
    0x458150: 'CRobloxReportView::CStatsItemRecord scalar deleting destructor (vtable 0x818a74 slot 1; calls the '
              'destructor 0x457ff0); nested class of the native CRobloxReportView.h owner',
    0x4581a0: 'CStatsItemRecord listener override (vtable 0x818a5c, listener base at +0x54, slot 2; calls '
              'shared_dynamic_cast<Stats::Item> 0x456ee0 and new CStatsItemRecord 0x457ca0); CRobloxReportView.h owner',
    0x4582f0: 'CRobloxReportView::onMarshaledEvent(ChildAdded) (declared in CRobloxReportView.h, defined in the '
              'committed CRobloxReportView.cpp; open in roblox-report-view): owner row, not redefined here',
    0x458700: 'CRobloxReportView::setDataModel (declared and defined by the CRobloxReportView owner; not redefined)',
    0x45afd0: 'CRobloxWnd::GetMessageMap (vtable 0x8199f4 slot 0; message map 0x819730); CRobloxView.h owner',
    0x45afe0: 'out-of-line destructor of a file-local scope object that calls G3D::Stopwatch::tock 0x511df0 on a '
              'RenderStats stopwatch (paired with the inlined tick 0x511cf0 in 0x45beb0); only referenced from EH '
              'funclets; no declaration exists (not invented)',
    0x45aff0: 'CRobloxWnd message handler (reads +0xa8, CWnd::Default); CRobloxView.h owner',
    0x45b010: 'CRobloxWnd resize handler (GetClientRect, Ogre::Camera::yaw import); CRobloxView.h owner',
    0x45b0d0: 'CRobloxWnd command poster (PostMessageA WM_COMMAND 0x80f4 to the main window); CRobloxView.h owner',
    0x45b310: 'G3D Vector3::magnitude header-inline copy (library)',
    0x45b330: 'CRobloxWnd::PreCreateWindow (AfxRegisterWndClass, minimum 100x100); CRobloxView.h owner',
    0x45b3a0: 'CRobloxWnd adorn / view creation (new 0x4c ViewNew 0x4d9990, new 0x144 AdornRbxGfx 0x674210); '
              'CRobloxView.h owner',
    0x45b4a0: 'CRobloxWnd::OnWndMsg override; CRobloxView.h owner',
    0x45b5d0: 'CRobloxWnd::OnSetFocus (DxUserInput 0x468050); CRobloxView.h owner',
    0x45b600: 'CRobloxWnd-unit helper releasing an object through its +0x28 base (no declaration in native headers)',
    0x45b700: 'boost shared_count<CRobloxWnd::RenderStatsItem*, Creatable<Instance>::Deleter> (pending-build-only in '
              'render-stats-item2008: needs `class RenderStatsItem;` nested in CRobloxWnd, CRobloxView.h owner)',
    0x45b950: 'G3D Rect2D::xyxy header-inline copy (library)',
    0x45b9d0: 'G3D Rect2D::xywh header-inline copy (library; calls 0x45b950)',
    0x45ba60: 'CRobloxWnd IRunView override (vtable 0x8199e8 = IRunView base at +0x54, slot 1; the native header declares AdjustThrottle(double); '
              'critical section 0x96df6c, double at +0x3c); CRobloxView.h owner',
    0x45ba90: 'CRobloxWnd render-device initialisation ("renderDevice->init failed"); CRobloxView.h owner',
    0x45bc80: 'CRobloxWnd member; CRobloxView.h owner',
    0x45bde0: 'CRobloxWnd render-device teardown (cleanup 0x47c3e0, auto_ptr reset of +0xac); CRobloxView.h owner',
    0x45be60: 'CRobloxWnd renderer teardown by mode (+0x5c == 2); CRobloxView.h owner',
    0x45beb0: 'CRobloxWnd deferred camera/stats update (+0x8a flag, Stopwatch tick/tock); CRobloxView.h owner',
    0x45bf30: 'CRobloxWnd message handler (DxUserInput 0x468050, 0x45beb0, CWnd::Default); CRobloxView.h owner',
    0x45bf60: 'CRobloxWnd message handler (CWnd::Default then 0x45beb0); CRobloxView.h owner',
    0x45bf80: 'CRobloxWnd message handler (0x45beb0 then CWnd::Default); CRobloxView.h owner',
    0x45bf90: 'CRobloxWnd::windowCommand (declared in CRobloxView.h); CRobloxView.h owner',
}
LIBRARY_ROWS = {0x45b310, 0x45b950, 0x45b9d0}
unit_rows = {}
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    unit = [u for u, lo, hi, _ in UNITS if lo <= a < hi][0]
    unit_rows.setdefault(unit, []).append(r)
UNIT_MAP = {
    'rbx CRobloxReportView unit tail ..0x458e6f': (
        'Continues the CRobloxReportView unit of the app-unit454-2008 map (starts 0x455d40). In this range: the '
        'CStatsItemRecord nested class (RTTI .?AVCStatsItemRecord@CRobloxReportView@@, vtable 0x818a74 at offset 0 '
        'and 0x818a5c at +0x54; both asserted) with its scalar deleting destructor 0x458150 and listener override '
        '0x4581a0, onMarshaledEvent(ChildAdded) 0x4582f0, setDataModel 0x458700, the StatsService instances (Hint '
        'constructor, constructor, Creatable create / ServiceProvider create counted by stats-service and '
        'app-unit454-2008) and the CRobloxReportView / sub-view members counted by roblox-report-view and '
        'report-sub-views. All open rows belong to the native CRobloxReportView.h owner (members declared there; '
        'setDataModel and onMarshaledEvent already defined in the committed CRobloxReportView.cpp): not built here.'),
    'rbx CRobloxView unit 0x458e70..0x45afcf': (
        'CRobloxView (RTTI .?AVCRobloxView@@, vtable 0x81933c asserted; GetRuntimeClass 0x458e70 at slot 0) and its '
        'verbs InsertModelFromRobloxVerb / ToggleIDEModeVerb / LockPlayModeVerb / ToggleFullscreenVerb / HelpCommand '
        '(other owners), VerbBinder<CRobloxView, CView>. Maintainer exclusion (CRobloxView): mapped only. The unit '
        'also emits G3D 6.09 header-inline COMDATs (library, not recovered): Vector3 operator- 0x45ac40, '
        'Hashable dtor / ??_G 0x45ac70 / 0x45ac80 (RTTI .?AVHashable@G3D@@ 0x819750), GImage ctor 0x45aca0 '
        '(.?AVGImage@G3D@@ 0x81975c), GWindow::Settings ctor 0x45ace0 / dtor 0x45ad70, GWindow::makeCurrent '
        '0x45ad50, AtomicInt32 decrement 0x45ad80, ReferenceCountedObject_zeroWeakPointers 0x45ad90, '
        'TextureManager::TextureArgs dtor / ??_G 0x45adc0 / 0x45ae10 (.?AVTextureArgs@TextureManager@G3D@@ '
        '0x819770), RenderDevice::setColorWrite-style 0x45ae70 (glColorMask), plus RBX header inlines owned by core '
        'headers (UserInputBase::ctrlKeyDown 0x45aec0, Camera getCameraFocus 0x45aef0 / getCameraCoordinateFrame '
        '0x45af00) and the SHGetSpecialFolderLocation helper 0x45af20 of the excluded unit.'),
    'rbx CRobloxWnd unit 0x45afd0..': (
        'CRobloxWnd (RTTI .?AVCRobloxWnd@@, vtable 0x8199f4 slot 0 = GetMessageMap 0x45afd0, IRunView '
        'sub-vtable 0x8199e8 at +0x54 with slot 1 = 0x45ba60; asserted), declared in the native CRobloxView.h (other owner; CRobloxView is a '
        'maintainer exclusion), continuing past 0x45c000 (app-unit454-2008 map). Members not built here (header '
        'owner): message handlers, PreCreateWindow, OnWndMsg, render-device initialisation / teardown. RenderStatsItem '
        'shared_count 0x45b700 (stores sp_counted_impl_pd vtable 0x819840, asserted) is pending in '
        'render-stats-item2008. Library header copies: G3D Vector3::magnitude 0x45b310, Rect2D::xyxy 0x45b950, '
        'Rect2D::xywh 0x45b9d0. Built here: std::auto_ptr<G3D::RenderDevice>::~auto_ptr 0x45b620 '
        '(native-classes/AppUnit458RenderDevicePtr.cpp, an explicit member instantiation). Evidence asserted: it is reached '
        'only by `this+0xac; jmp` from the unwind funclets 0x7c2c9b / 0x7c3090 whose FuncInfo handlers are installed by the CRobloxWnd '
        'constructor 0x45c730 and destructor 0x45fbe0; 0x45bde0 releases the same CRobloxWnd +0xac member with '
        'cleanup() 0x47c3e0 ("Shutting down RenderDevice.") followed by the auto_ptr::reset(0) order (test, '
        '~RenderDevice 0x47bec0, operator delete, then the store of 0).'),
}
unit_map = []
for u, lo, hi, library in UNITS:
    key = [k for k in UNIT_MAP if k.startswith(u)][0]
    rows = unit_rows.get(u, [])
    unit_map.append({'unit': key, 'rows': len(rows), 'bytes': sum(r['size'] for r in rows),
                     'counted_elsewhere': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()
                                           if lo <= int(a, 16) < hi],
                     'counted_here': len([a for a in exact_rows if lo <= int(a, 16) < hi]),
                     'library': library,
                     'evidence': UNIT_MAP[key]})
assert sum(u['rows'] for u in unit_map) == len(RANGE_ROWS)
code_rows = [r for r in RANGE_ROWS if r.get('kind', 'code') == 'code']
open_rows = []
for r in RANGE_ROWS:
    a = int(r['addr'], 16)
    key = '%08x' % a
    if key in exact_rows or key in range_counted:
        continue
    if 0x458e70 <= a < 0x45afd0:
        why = 'CRobloxView unit (maintainer exclusion or library header inline; see unit_map)'
    else:
        why = OPEN.get(a, 'not attempted')
    open_rows.append('0x%x (%d B): %s%s' % (a, r['size'], 'library: ' if a in LIBRARY_ROWS else '', why))

PROPOSALS = [
    'Owner of native-headers/CRobloxView.h (CRobloxWnd; FYI, no edit): CRobloxWnd +0xac is a '
    'std::auto_ptr<G3D::RenderDevice> (the void* slots_ac_b8[0] today). Evidence: the out-of-line ~auto_ptr 0045b620 '
    '(exact here) is called only from the unwind funclets of the constructor 0045c730 (state for +0xac) and the '
    'destructor 0045fbe0, and 0045bde0 calls cleanup() 0047c3e0 then resets it in auto_ptr::reset(0) order. With the '
    'member typed, the constructor / destructor rows can reach that destructor by name; this receipt keeps counting '
    'the instantiation itself.',
    'Owner of native-headers/CRobloxView.h (repeat of the render-stats-item2008 proposal): declare `class '
    'RenderStatsItem;` inside CRobloxWnd so the pending shared_count 0045b700 / shared_ptr 0045c0f0 / create 0045f730 '
    'rows of render-stats-item2008 can be counted.',
    'Owner of native-headers/CRobloxReportView.h (FYI): open rows of the nested CStatsItemRecord in this range are the '
    'scalar deleting destructor 00458150 (vtable 0x818a74 slot 1, destructor 00457ff0) and the listener override '
    '004581a0 (vtable 0x818a5c = the listener base at +0x54, slot 2).',
    'BOUNDS: none (no extent change proposed).',
]
REJECTED = {
    'boost::scoped_ptr<G3D::RenderDevice> for 0045b620': (
        'not adopted: its destructor compiles to the same bytes, but 0045bde0 deletes before storing 0 (auto_ptr '
        'reset order); scoped_ptr::reset stores before deleting.'),
}
receipt = {
    'scope': ('Inactive 2008-06 native recovery of the application range 00458000..0045c000: unit map of every row '
              'and the CRobloxWnd unit\'s std::auto_ptr<G3D::RenderDevice> destructor. No runtime, link or class-swap '
              'claim.'),
    'exact_function_rows': exact_rows,
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags',
    'flags': {k: [f for f in v if not f.startswith('/Fo')] for k, v in FLAGS.items()},
    'sources': {k: {'path': str(v.relative_to(ROOT)), 'sha256': nb.sha(v)} for k, v in SOURCES.items()},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'rows': groups,
    'unit_blocks': ['0x%x..0x%x %s' % (lo, hi, u) for u, lo, hi, _ in UNITS],
    'unit_map': unit_map,
    'range_rows': len(RANGE_ROWS),
    'range_code_rows': len(code_rows),
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_counted_here': len(exact_rows),
    'range_rows_open': open_rows,
    'vtables_checked_by_rtti': {'0x%x' % k: '%s offset 0x%x' % v for k, v in VTABLES.items()},
    'funclet_parents': {k: 'unwind map 0x%x, FuncInfo 0x%x, function 0x%x' % v for k, v in FUNCLET_PARENTS.items()},
    'rejected': REJECTED,
    'proposals': PROPOSALS,
}
text = json.dumps(receipt, indent=2) + '\n'
for a in {'%08x' % int(r['addr'], 16) for r in RANGE_ROWS} - set(exact_rows):
    assert '"%s"' % a not in text, a
RECEIPT.write_text(text)
print('PASS app-unit458: %d counted rows %s; range %d rows, %d counted elsewhere, %d open' % (
    len(exact_rows), exact_rows, len(RANGE_ROWS), len(range_counted), len(open_rows)))
