"""Verify the inactive native 2008-06 app leaves, third pass: DHTMLWindowService (+ the Marshaller registry of its
unit) and CIDEDocManager. The first two passes stay in tests/record_native_app_leaves2008.py (unchanged).

Builds (document-swap flags, VS2008 RTM 21022, native headers first):
  * tests/NativeAppLeaves2008Layout3.cpp            sizeof probes and offsetof asserts;
  * native-classes/AppLeaves2008DHTMLWindowService.cpp  DHTMLWindowService (ctor, deleting destructor and its
                                                    adjustor thunks, the DescribedCreatable / FactoryProduct
                                                    template members of its unit, classDescriptor, getClassName)
                                                    and the Marshaller registry (acquireMarshaller 0041b6f0,
                                                    initializeHtmlMarshaller 0041bc40, map / recursive_mutex
                                                    initializers and atexit functions);
  * native-classes/AppLeaves2008IDEDocManager.cpp      CIDEDocManager::DoPromptFileName / OnFileNew;
  * native-classes/AppLeaves2008IDEDocManagerCtor.cpp  the constructor (and the ??_G its vtable brings), with the
                                                    XTP 11.2.2 and Scintilla MFC 1.20 include paths for the
                                                    CIDEBrowserView / CScriptEditor runtime-class getters.
Every row must be relocation-masked exact, and every REL32/DIR32 target is bound to the address the original
instruction uses and verified: imports by mfc90 ordinal / DLL export name, literals by bytes, type descriptors and
vtables by original RTTI names, runtime-class getters by their `mov eax, CRuntimeClass; ret` and the class name
string, own symbols by the rows proven here, inline / library instances by bytes at the called address with their
own targets verified recursively (listed under 'instances', not counted), the rest by the EXTERNAL / DATA maps
(one address per symbol; evidence in the comments). Each vtable of the main builds is compared slot by slot with
the original vtable it binds to. No pending build: nothing here needs a missing declaration.
Writes work/2008-06/shared-layouts/app-leaves2008-services-working.json.
"""
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_bind as nb  # noqa: E402
from native_bind import ROOT, OUT, LOCAL_EH, Original, flags, match, rebuild, sha  # noqa: E402

R = ROOT / 'rebuild/2008-06'
HDR = R / 'native-headers'
SRC = R / 'native-classes'
LAYOUT = R / 'tests/NativeAppLeaves2008Layout3.cpp'
DHTML_H = HDR / 'AppLeaves2008/DHTMLWindowService2008.h'
IDE_H = HDR / 'AppLeaves2008/IDEDocManager2008.h'
DHTML_CPP = SRC / 'AppLeaves2008DHTMLWindowService.cpp'
IDE_CPP = SRC / 'AppLeaves2008IDEDocManager.cpp'
IDE_CTOR_CPP = SRC / 'AppLeaves2008IDEDocManagerCtor.cpp'
VIEWS = ['/UNOMINMAX', '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source'), '/D_XTP_STATICLINK',
         '/I' + str(ROOT / 'tools/libs/scintilla-mfc-1.20')]
original = Original()
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]


def build(source, name, extra=()):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    base = flags()
    i = next(k for k, x in enumerate(base) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    pre = [x for x in extra if x.startswith('/I')]
    post = [x for x in extra if not x.startswith('/I')]
    args = base[:i] + pre + base[i:] + post + ['/Fo' + str(obj), str(source)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', args, OUT)
    assert code == 0, log[-4000:]
    return obj, args


layout_obj, layout_flags = build(LAYOUT, 'NativeAppLeaves2008Layout3')
dhtml_obj, dhtml_flags = build(DHTML_CPP, 'NativeAppLeaves2008DHTMLWindowService')
ide_obj, ide_flags = build(IDE_CPP, 'NativeAppLeaves2008IDEDocManager')
ctor_obj, ctor_flags = build(IDE_CTOR_CPP, 'NativeAppLeaves2008IDEDocManagerCtor', VIEWS)
OBJ = {'dhtml': dhtml_obj, 'ide': ide_obj, 'ide_ctor': ctor_obj}

# ---- layout ---------------------------------------------------------------------------------------------------
raw = layout_obj.read_bytes()
for prefix, value in (('?nativeDHTMLWindowServiceSize@@', 0x130), ('?nativeDHTMLWindowServiceInstanceSize@@', 0x130),
                      ('?nativeIDEDocManagerSize@@', 0x30)):
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())


def pushes_then_calls(caller, size, callee):
    """The original `push size; call operator new` ... `call callee` sequence inside caller."""
    body, _, _ = match.target('2008-06', '%08x' % caller)
    at = body.index(b'\x6a' + bytes([size]) if size < 0x80 else b'\x68' + struct.pack('<I', size))
    call = body.index(b'\xe8', at + 2)
    while (caller + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)


pushes_then_calls(0x41cda0, 0x130, 0x41c9c0)   # Creatable<Instance>::create<DHTMLWindowService> (malloc import)
body = original.data(0x44dc03, 0x20)            # CRobloxApp::InitInstance: new(0x30) ... call 00449910
assert body[:2] == b'\x6a\x30' and (0x44dc1e + 5 + struct.unpack_from('<i', original.data(0x44dc1f, 4))[0]) == 0x449910
assert original.data(0x44dd5a, 2) == b'\x6a\x30' and \
    (0x44dd75 + 5 + struct.unpack_from('<i', original.data(0x44dd76, 4))[0]) == 0x449910
pushes_then_calls(0x41b6f0, 0x54, 0x41b310)     # acquireMarshaller: new(0x54) Marshaller(threadId)


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


DS_NAME = '$1?sDHTMLWindowService@@3PADA'
svc = bases(0x80efd4)
assert len(svc) == 22 and svc['.?AVService@RBX@@'] == 0x130, svc
assert svc['.?AV?$DescribedCreatable@VDHTMLWindowService@@VInstance@RBX@@%s@RBX@@' % DS_NAME] == 0
assert original.vtable_class(0x81685c) == ('.?AVCIDEDocManager@@', 0)
assert list(bases(0x81685c)) == ['.?AVCIDEDocManager@@', '.?AVCDocManager@@', '.?AVCObject@@']
assert original.string(0x92c1f8) == 'HtmlService' and original.string(0x80f014) == 'WindowService'

# ---- rows ---------------------------------------------------------------------------------------------------
SVC = 'DHTMLWindowService@@'
FP = '?$FactoryProduct@VDHTMLWindowService@@VInstance@RBX@@%s@RBX@@' % DS_NAME
DC = '?$DescribedCreatable@VDHTMLWindowService@@VInstance@RBX@@%s@RBX@@' % DS_NAME
DS = '?$Described@VDHTMLWindowService@@%sV%s@Reflection@RBX@@' % (DS_NAME, FP)
ON_FILE_NEW = '?OnFileNew@CIDEDocManager@@UAEXXZ'
ROWS = {
    'dhtml': [
        (0x0041c9c0, '??0DHTMLWindowService@@QAE@XZ'),
        (0x0041caa0, '??_GDHTMLWindowService@@UAEPAXI@Z'),
        (0x0041ca80, '??_EDHTMLWindowService@@WIE@AEPAXI@Z'),
        (0x0041ca90, '??_EDHTMLWindowService@@WBA@AEPAXI@Z'),
        (0x0041b9d0, '??_EDHTMLWindowService@@WEE@AEPAXI@Z'),
        (0x0041b9e0, '??_EDHTMLWindowService@@WGE@AEPAXI@Z'),
        (0x0041b9f0, '??_EDHTMLWindowService@@WBE@AEPAXI@Z'),
        (0x0041bcf0, '??_EDHTMLWindowService@@WKE@AEPAXI@Z'),
        (0x0041bd00, '??_EDHTMLWindowService@@WME@AEPAXI@Z'),
        (0x0041bd10, '??_EDHTMLWindowService@@WCE@AEPAXI@Z'),
        (0x0041bc50, '??0' + DC + 'IAE@XZ'),
        (0x0041b970, '??0' + FP + 'IAE@XZ'),
        (0x0041b910, '??1' + FP + 'MAE@XZ'),
        # ~DescribedCreatable: the constructor's unwind funclet 007be1e3 jumps here (jmp ~FactoryProduct).
        (0x0041ba90, '??1' + DC + 'UAE@XZ'),
        (0x0041bb70, '?classDescriptor@' + DS + 'SAAAVClassDescriptor@23@XZ'),
        (0x0041bb50, '?getClassName@' + FP + 'UBEABVName@2@XZ'),
        (0x007fa630, '??__Ffoo@?1??classDescriptor@' + DS + 'SAAAVClassDescriptor@23@XZ@YAXXZ'),
        (0x0041b6f0, '?acquireMarshaller@@YAPAVMarshaller@@XZ'),
        (0x0041bc40, '?initializeHtmlMarshaller@@YAXXZ'),
        (0x007eef40, '??__Emarshallers@@YAXXZ'),
        (0x007eef70, '??__EmarshallersLock@@YAXXZ'),
        (0x007fa640, '??__Fmarshallers@@YAXXZ'),
        (0x007fa610, '??__FmarshallersLock@@YAXXZ'),
    ],
    'ide': [
        (0x00449ae0, '?DoPromptFileName@CIDEDocManager@@UAEHAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@IKHPAVCDocTemplate@@@Z'),
        # OnFileNew: the function list splits the body at 0044ac2f (after the call in the try block) and at the
        # catch funclet 0044ac40; each piece is compared with its own listed extent.
        ((0x0044abd0, 0, 95), ON_FILE_NEW), ((0x0044ac2f, 95, 112), ON_FILE_NEW), ((0x0044ac40, 112, 161), ON_FILE_NEW),
    ],
    'ide_ctor': [
        (0x00449910, '??0CIDEDocManager@@QAE@_N@Z'),
        (0x0044a150, '??_GCIDEDocManager@@UAEPAXI@Z'),
    ],
}
SPLIT_EXTRA = {'0044ac2f', '0044ac40'}   # pieces of OnFileNew: the function is counted once (0044abd0)

# Explicit bindings: the address the original instruction uses; evidence in the comment.
EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # FactoryProduct() 0041b970 (record_native_click_detector.py)
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                       # ~FactoryProduct 0041b910 tail jump (same)
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,              # Name::doDeclare (record_native_click_detector.py)
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,               # getClassName 0041bb50
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,   # classDescriptor 0041bb70
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,      # atexit 007fa630 (evidence name)
    # Described<Instance>::classDescriptor: evidence name with the 3PBDB spelling; the 2008 class name is a const
    # char array (3QBDB), the binding the other RBX recorders use.
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,
    '_atexit': 0x6a17af,
    '??2@YAPAXI@Z': 0x6a0920,
    # boost 1.34.1 recursive_mutex (record_native_reflection_sync.py & co. bind the same four addresses).
    '??0recursive_mutex@boost@@QAE@XZ': 0x563070,
    '??1recursive_mutex@boost@@QAE@XZ': 0x594cb0,
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x563090,
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,
    # Marshaller(DWORD) 0041b310: an exact row of tests/record_native_app_leaves2008.py.
    '??0Marshaller@@QAE@K@Z': 0x41b310,
    # throwPendingPlayError 0044ab30: an exact row of tests/record_native_app_leaves2008.py.
    '?throwPendingPlayError@@YAXXZ': 0x44ab30,
    # reportDocumentException 00428850 (native-classes/DocumentException.cpp, record_native_document_exception.py).
    '?reportDocumentException@@YAXABVexception@std@@@Z': 0x428850,
}
DATA = {
    '?sDHTMLWindowService@@3PADA': 0x92c1f8,     # "HtmlService" (checked above)
    '?htmlMarshaller@@3PAVMarshaller@@A': 0x96cc4c,  # stored by 0041bc40, read by 0041b2b0 / 0041b660 / 0042c54e
    '?marshallers@@3V?$map@KPAVMarshaller@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAVMarshaller@@@std@@@3@@std@@A': 0x96cec4,
    '_marshallers': 0x96cec4,                    # internal-linkage spelling of the same static
    '?marshallersLock@@3Vrecursive_mutex@boost@@A': 0x96cee4,
    '_marshallersLock': 0x96cee4,
    # pendingPlayError (tests/record_native_app_leaves2008.py: atexit 007fadf0 deletes [0096dcf4]).
    '?pendingPlayError@@3V?$scoped_ptr@Vexception@std@@@boost@@A': 0x96dcf4,
}
LOCAL_STATIC_PREFIXES = ('??_B?1??', '?foo@?1??classDescriptor@', '?$S1@?1??classDescriptor@', '?n@?1???$doDeclare@',
                         '?$S1@?1???$doDeclare@', '?flag@?1???$declare@', '?flag@', '?root@')
GUARDS = {}   # local static symbol -> address (one address per symbol, recorded in the receipt)


def first(address):
    return address[0] if isinstance(address, tuple) else address


own = {}
for v in ROWS.values():
    for addr, sym in v:
        own.setdefault(sym, first(addr))
binding = {}
INSTANCES = {}
CURRENT = []
BODIES = {}


def bodies_of(obj):
    if obj not in BODIES:
        BODIES[obj] = {n: (b, r) for n, b, r in match.coff_functions(Path(obj).read_bytes())}
    return BODIES[obj]


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


def runtime_class(symbol, value):
    """?GetThisClass@X@@SGPAUCRuntimeClass@@XZ defined in the exe: `mov eax, rc; ret` with rc->m_lpszClassName X."""
    if not symbol.startswith('?GetThisClass@') or not symbol.endswith('@@SGPAUCRuntimeClass@@XZ'):
        return None
    cls = symbol[len('?GetThisClass@'):-len('@@SGPAUCRuntimeClass@@XZ')]
    code = original.data(value, 6)
    assert code[0] == 0xb8 and code[5] == 0xc3, (symbol, hex(value), code.hex())
    rc = struct.unpack_from('<I', code, 1)[0]
    assert original.string(d(rc)) == cls, (symbol, hex(value), original.string(d(rc)))
    return 'runtime class %s (CRuntimeClass %#x)' % (cls, rc)


def classify(symbol, value, raw, sections, definitions, where):
    hit = original.imported(value)
    if hit is not None:
        assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
        return '%s!%s' % hit
    if symbol.startswith('??_C@'):
        pos, at = definitions[symbol]
        literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal, (where, symbol, hex(value))
        return 'literal %r' % literal[:-1].decode()
    if symbol.startswith('??_R0') and symbol.endswith('@8'):
        rtti = original.string(value + 8)
        assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
        return 'RTTI %s' % rtti
    if symbol.startswith('__TI') and '?AV' in symbol:
        # _ThrowInfo: pCatchableTypeArray +12 -> first CatchableType -> TypeDescriptor name
        cta = d(value + 12)
        assert d(cta) == int(symbol[4]), (where, symbol, hex(value))
        name = original.string(d(d(cta + 4) + 4) + 8)
        assert name == '.' + symbol[5:], (where, symbol, hex(value), name)
        return 'throw info %s (%d catchable types)' % (name, d(cta))
    if symbol.startswith('??_7'):
        rtti, at = original.vtable_class(value)
        assert norm(rtti) == norm('.?AV' + symbol[4:symbol.index('@@6B') + 2]), (where, symbol, hex(value), rtti)
        return 'vtable RTTI %s offset %#x' % (rtti, at)
    if symbol in own:
        assert own[symbol] == value, (where, symbol, hex(value), hex(own[symbol]))
        return 'own row'
    if symbol.startswith('??_E') and ('??_G' + symbol[4:]) in own:
        assert own['??_G' + symbol[4:]] == value, (where, symbol, hex(value))
        return 'own row (??_G)'
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
        return 'external'
    if symbol in DATA:
        assert DATA[symbol] == value, (where, symbol, hex(value), hex(DATA[symbol]))
        return 'data'
    how = runtime_class(symbol, value)
    if how:
        return how
    if symbol.startswith(LOCAL_STATIC_PREFIXES) or symbol.startswith('?$S'):
        assert GUARDS.setdefault(symbol, value) == value, (where, symbol, hex(value))
        return 'local static of %s' % where[:60]
    if symbol.startswith('??_E') and symbol.endswith(('UAEPAXI@Z', 'MAEPAXI@Z')) and CURRENT and \
            ('??_G' + symbol[4:]) in bodies_of(CURRENT[-1]):
        # ??_E is the weak alias of ??_G (no array delete): the ??_G body must equal the code at the address
        # (an identical-COMDAT fold when another class's ??_G sits there).
        how = instance('??_G' + symbol[4:], value, where)
        return how and how + ' via ??_G'
    if EVIDENCE.get('%08x' % value, {}).get('symbol') == symbol:
        return 'evidence name'
    return instance(symbol, value, where)


EVIDENCE = json.loads((R / 'offline/evidence.json').read_text())['names']


def instance(symbol, value, where):
    """An inline / template body this build emits, proven by bytes at the address the original uses."""
    if symbol in INSTANCES:
        assert INSTANCES[symbol]['address'] == '%08x' % value, (where, symbol, hex(value))
        return 'instance (bytes equal, targets verified)'
    obj = CURRENT[-1]
    if symbol not in bodies_of(obj):
        return None
    INSTANCES[symbol] = {'address': '%08x' % value}
    body = bodies_of(obj)[symbol][0]
    try:
        listed = len(match.target('2008-06', '%08x' % value)[0])
    except SystemExit:   # not a listed function start
        listed = None
    # The function list cuts some bodies at catch funclets or runs them into a neighbour: then the whole emitted
    # body is compared with the image bytes at the address (relocated fields masked, every one bound below).
    spec = value if listed == len(body) else (value, 0, len(body), 'raw')
    row = verify(obj, [(spec, symbol)])[0]
    if spec != value:
        row['listed_extent'] = listed
    row['exact'] = False
    row['status'] = 'instance emitted by this unit (STL / boost / RBX template), bytes equal, every target verified, not counted'
    INSTANCES[symbol] = row
    return 'instance (bytes equal, targets verified)'


def verify(obj, rows):
    CURRENT.append(obj)
    try:
        return verify_rows(obj, rows)
    finally:
        CURRENT.pop()


def verify_rows(obj, rows):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = bodies_of(obj)
    out = []
    for spec, name in rows:
        body, refs = bodies[name]
        address, lo, hi = spec[:3] if isinstance(spec, tuple) else (spec, 0, len(body))
        body, refs = body[lo:hi], [r - lo for r in refs if lo <= r < hi]
        if isinstance(spec, tuple) and spec[3:] == ('raw',):
            target, target_refs = original.data(address, len(body)), []
        else:
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
        start, section = definitions[name]
        start += lo
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
            if LOCAL_EH.match(symbol) or symbol.startswith('__sehtable$'):
                local.add(symbol)
                continue
            how = classify(symbol, value, raw, sections, definitions, name)
            assert how is not None, ('unbound relocation', name, symbol, hex(value))
            prev = binding.setdefault(symbol, value)
            assert prev == value, ('inconsistent binding', symbol, hex(prev), hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), how)
        row = {'address': '%08x' % address, 'symbol': name + ('' if (lo, hi) == (0, len(bodies[name][0])) else ' [%#x:%#x]' % (lo, hi)),
               'size': len(body), 'exact': True, 'verified_targets': verified, 'local_eh': sorted(local)}
        out.append(row)
    return out


results = {k: verify(OBJ[k], v) for k, v in ROWS.items()}

# ---- vtables of the current-header objects ------------------------------------------------------------------
INSTANCE_VTABLES = {0x0: 0x82d884, 0x10: 0x82d878, 0x14: 0x82d870, 0x20: 0x82d868, 0x24: 0x82d858, 0x44: 0x82d848,
                    0x64: 0x82d838, 0x84: 0x82d828, 0xa4: 0x82d818, 0xc4: 0x82d808}
for at, vt in INSTANCE_VTABLES.items():
    assert original.vtable_class(vt) == ('.?AVInstance@RBX@@', at), (hex(vt), original.vtable_class(vt))
# askAddChild of DHTMLWindowService is defined in the DHTMLWindow unit (not compiled here): bound by the vtable
# slot only, after its body is checked to be `dynamic_cast<const DHTMLWindow*>(instance) != 0` (TD 0092c210).
UNCOMPILED = {'?askAddChild@DHTMLWindowService@@MBE_NPBVInstance@RBX@@@Z': 0x416e60}
ask = original.data(0x416e60, 0x24)
assert ask[:4] == b'\x8b\x44\x24\x04' and struct.unpack_from('<I', ask, 7)[0] == 0x92c210 and \
    original.string(0x92c210 + 8) == '.?AVDHTMLWindow@@'


def vtable_slots(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    value, sec = definitions[symbol]
    table = sections[sec]
    end = min([x for x in starts[sec + 1] if x > value] + [table[3]])
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if value <= offset < end:
            slots[(offset - value) // 4] = symbols[index][0]
    return raw, sections, definitions, slots


def local_body(raw, symbol, value):
    """An inline MFC body (CObject::Serialize & co.) emitted here: proven by bytes against the slot target."""
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    if symbol not in bodies:
        return None
    target, target_refs, _ = match.target('2008-06', '%08x' % value)
    body, refs = bodies[symbol]
    if not refs and len(body) == len(target) and match.exact_match(target, target_refs, body, refs):
        return 'inline body, bytes equal (ICF-shared copy)'
    return None


vtables = {}
for key in ('dhtml', 'ide_ctor'):
    obj = OBJ[key]
    raw = obj.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    for symbol in sorted(s for s in definitions if s.startswith('??_7') and s in binding
                         and ('DHTMLWindowService' in s or 'CIDEDocManager' in s)):
        vt = binding[symbol]
        rtti, at = original.vtable_class(vt)
        raw, sections, definitions, slots = vtable_slots(obj, symbol)
        assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
        checked = {}
        CURRENT.append(obj)
        for slot, sym in sorted(slots.items()):
            value = d(vt + 4 * slot)
            how = None
            if sym in UNCOMPILED:
                assert UNCOMPILED[sym] == value, (symbol, slot, sym, hex(value))
                how = 'defined in the DHTMLWindow unit (not compiled here; body shape checked above)'
            if how is None:
                how = classify(sym, value, raw, sections, definitions, symbol) or local_body(raw, sym, value)
            if how is None and at in INSTANCE_VTABLES and d(INSTANCE_VTABLES[at] + 4 * slot) == value \
                    and 'DHTMLWindowService' not in sym:
                how = 'inherited (Instance vtable %#x slot %d)' % (INSTANCE_VTABLES[at], slot)
            assert how is not None, ('unbound vtable slot', symbol, slot, sym, hex(value))
            prev = binding.setdefault(sym, value)
            assert prev == value, ('inconsistent', sym, hex(prev), hex(value))
            checked[slot] = '%s = %s (%s)' % (sym, hex(value), how)
        CURRENT.pop()
        vtables[symbol] = {'address': hex(vt), 'rtti': rtti, 'offset': hex(at), 'slots': checked}
for vt in (0x80efd4, 0x81685c):
    assert any(v['address'] == hex(vt) for v in vtables.values()), (hex(vt), 'vtable not checked')
assert d(0x81685c + 4 * 13) == 0x449ae0 and d(0x81685c + 4 * 15) == 0x44abd0 and d(0x81685c + 4) == 0x44a150

exact = sorted({r['address'] for k in ROWS for r in results[k]} - SPLIT_EXTRA)
paths = [Path(__file__).resolve(), R / 'tests/native_bind.py', LAYOUT, DHTML_H, IDE_H, DHTML_CPP, IDE_CPP, IDE_CTOR_CPP,
         HDR / 'AppLeaves2008/Marshaller2008.h', HDR / 'AppLeaves2008/RbxDocTemplates2008.h']
receipt = {
    'family': 'AppLeaves2008 pass 3 (DHTMLWindowService + Marshaller registry, CIDEDocManager)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': {'layout': layout_flags, 'dhtml': dhtml_flags, 'ide': ide_flags, 'ide_ctor': ctor_flags},
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {k: sha(v) for k, v in OBJ.items()},
    'layout': {
        'DHTMLWindowService': '0x130 == sizeof(Instance) (0041cda0 mallocs 0x130); empty Service base at mdisp 0x130; '
                              'class name "HtmlService" (char[] 0092c1f8), instance name "WindowService"',
        'CIDEDocManager': '0x30 (InitInstance news 0x30 at 0044dc03 / 0044dd5a): CDocManager (0x20), then the '
                          'templates browser +0x20, play +0x24, script +0x28, object browser +0x2c',
        'Marshaller registry': 'std::map<DWORD, Marshaller*> 0096cec4, boost::recursive_mutex 0096cee4, '
                               'htmlMarshaller 0096cc4c (defined with the DHTMLWindow statics)',
    },
    'methods': results, 'instances': INSTANCES, 'local_statics': {k: hex(v) for k, v in sorted(GUARDS.items())},
    'exact': exact, 'exact_count': len(exact), 'pending_build_only': [],
    'not_counted': {'0044ac2f / 0044ac40': 'pieces of OnFileNew 0044abd0 (listed separately by the function list)',
                    'instances': 'STL / boost / RBX template bodies proven by bytes and targets (see instances)'},
    'left': {
        'DHTMLWindow (descriptors and methods of the same unit)': 'Navigate 0041cc00, SetBody 0041ccd0, '
            'SetCallback 0041cb30, Resize 0041cac0, Show 0041b2b0, Unbind 0041b660, Bind 0041d0a0, the BoundFuncDesc / '
            'SignalDesc initializers 007eed70..007eef20: they belong to class DHTMLWindow (FuncDesc<DHTMLWindow>, '
            'recursive_mutex +0x130, CLuaHtmlView* +0x13c), which has no vtable in this binary and whose own unit '
            '(00416e60.., 00417a10..) is not recovered',
        'Creatable<Instance>::create<DHTMLWindowService> 0041cda0 / Creator 0041ceb0 / creator initializer 007eef90':
            'FactoryProduct::Creator has no native definition yet (util/Object.h declares it only)',
        'CRobloxApp 0044bbf0': 'tail jump m_pDocManager->playTemplate->getPlayDocument(): a CRobloxApp member, not '
                               'recovered here (CRobloxApp files are not edited)',
        'CRobloxWnd::RenderStatsItem (vtable 0081a32c, ctor 0045f340, update 0045f570)': 'its constructor argument '
            '(stored at +0x170) is an object whose type is not derived (fields +0x58 .. +0x234 bound as child items, '
            '+0x210..+0x21c read by update); createBoundChildItem helpers 0045f120 / 0045f230 and the memory counters '
            '0096ef44 / 0096efd0 / 00476470 belong to other units. Layout: Stats::Item (0x158), child Item* at '
            '+0x158..+0x16c, source pointer +0x170 (size 0x174 not yet read from its factory).',
        'CLuaHtmlView::Binder (vtable 00810654)': 'COM element binder (EventHandler +0x2c, IHTMLElement* +0x30, '
            'property-binding container +0xc, enable_shared_from_this +4); constructor 0042c0d0 needs the CLuaHtmlView '
            'unit and PropertyDescriptor bindings: not attempted in this pass',
    },
    'vtables': vtables,
    'proposals': [],
    'scope': 'Inactive. Exact rows with verified targets; no pending rows. No active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/app-leaves2008-services-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native app leaves2008 services: %d exact (%s), %d vtables checked, %d instances' % (
    len(exact), ' '.join(exact), len(vtables), len(INSTANCES)))
