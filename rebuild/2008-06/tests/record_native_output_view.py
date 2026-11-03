"""Verify the inactive native COutputView / CStandardOutputView unit against its targets.

Repo-style record (draft kept beside its sources). The target imports
std::string::c_str, so the unit is compiled through the noinline profile for
'const _Elem * c_str() const' (CString operator PCXSTR stays inline: appendMessage
reads the buffer directly). Checks: layout fixture, 31 bodies relocation-normalized
exact, every call/data target of those bodies, and the three vtables slot by slot.
"""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import pefile

here = Path(__file__).resolve().parent
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild  # noqa: E402

out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = []
for x in base['flags']:
    if x.startswith('/Fo') or x.endswith('NativeDocumentLayout.cpp'):
        continue
    flags.append(x)
source = root / 'rebuild/2008-06/native-classes/COutputView.cpp'
fixture = here / 'NativeOutputViewLayout.cpp'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(out / 'NativeOutputViewLayout.obj'), str(fixture)], out)
assert code == 0, log
pre = out / 'output-view-pre'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', [x for x in flags if x != '/c'] + ['/P', str(source)], pre)
assert code == 0, log
body = (pre / 'COutputView.i').read_text(errors='replace')
needle = 'const _Elem * c_str() const'
assert body.count(needle) == 1
unit = out / 'NativeOutputViewProfile.cpp'
unit.write_text(body.replace(needle, '__declspec(noinline) ' + needle))
obj = out / 'NativeOutputViewProfile.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                                                       '/Fo' + str(obj), str(unit)], out)
assert code == 0, log

pe = pefile.PE(str(root / 'clients/2008-06/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
data = lambda address, size: pe.get_data(address - image, size)
word = lambda address: struct.unpack('<I', data(address, 4))[0]
imports = {x.address: (d.dll.decode().lower(), x.ordinal, x.name.decode() if x.name else None)
           for d in pe.DIRECTORY_ENTRY_IMPORT for x in d.imports}
mfc = {}
for line in (root / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='ignore').splitlines():
    m = re.match(r'\s*(\S+)\s+@\s*(\d+)', line)
    if m:
        mfc[int(m.group(2))] = m.group(1)


def imported(value):
    slot = value
    if slot not in imports:
        head = data(value, 6)
        if head[:2] != b'\xff\x25':
            return None
        slot = struct.unpack_from('<I', head, 2)[0]
    dll, ordinal, name = imports[slot]
    return dll, (mfc.get(ordinal) if dll == 'mfc90.dll' else name)


def plain(symbol):
    name = symbol[6:] if symbol.startswith('__imp_') else symbol
    if not name.startswith('?'):  # C / stdcall import: _name or _name@N
        name = re.sub(r'@\d+$', '', name[1:])
    return name


# Bodies of this unit (prefix -> original address).
OWN = [
    ('?_GetBaseClass@COutputView@@', 0x436060), ('?GetRuntimeClass@COutputView@@', 0x436070),
    ('?GetRuntimeClass@CStandardOutputView@@', 0x436080), ('?OnInitialUpdate@COutputView@@', 0x436090),
    ('?_AtlCopyNCR@ATL@@', 0x4360b0), ('?_AtlCopyNCRPair@ATL@@', 0x436100), ('?EscapeXML@ATL@@', 0x436150),
    ('??D?$_Deque_const_iterator@V?$CComPtr@UIHTMLDOMNode@@', 0x436420),
    ('?OnDocumentComplete@COutputView@@', 0x4364b0),
    ('?pop_front@?$deque@V?$CComPtr@UIHTMLDOMNode@@', 0x436670),
    ('?_Tidy@?$deque@UStandardOutMessage@RBX@@', 0x4366d0),
    ('?_Tidy@?$deque@V?$CComPtr@UIHTMLDOMNode@@', 0x436760),
    ('?_Growmap@?$deque@V?$CComPtr@UIHTMLDOMNode@@', 0x436800),
    ('??1?$deque@UStandardOutMessage@RBX@@', 0x436960),
    ('?push_back@?$deque@V?$CComPtr@UIHTMLDOMNode@@', 0x4369b0),
    ('??0COutputView@@', 0x436a30), ('??1COutputView@@', 0x436ab0), ('??_GCOutputView@@', 0x436b40),
    ('?appendElement@COutputView@@', 0x436b60), ('??1CStandardOutputView@@', 0x436ce0),
    ('??_ECStandardOutputView@@W', 0x436e30), ('??$_Construct@UStandardOutMessage@RBX@@', 0x436e40),
    ('?_Growmap@?$deque@UStandardOutMessage@RBX@@', 0x436eb0),
    ('?push_back@?$deque@UStandardOutMessage@RBX@@', 0x437010),
    ('?onEvent@CStandardOutputView@@', 0x437070), ('?appendMessage@CStandardOutputView@@', 0x437150),
    ('??0CStandardOutputView@@', 0x4373a0), ('??_GCStandardOutputView@@', 0x437500),
    ('?OnStandardOutMessage@CStandardOutputView@@', 0x437520),
    ('?CreateObject@CStandardOutputView@@', 0x437740), ('?GetMessageMap@CStandardOutputView@@', 0x4377a0),
]
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
funcs = match.coff_functions(raw)
bodies = {n: (b, r) for n, b, r in funcs}
resolved = {}
for prefix, address in OWN:
    name = next(n for n, b, r in funcs if n.startswith(prefix))
    resolved[name] = address
# Identical-COMDAT folds and other units' bodies reached from these (address proven by the target bytes
# and, for folds, by name-independent equal code in the original image).
EXTERNAL = {
    '??0CSecureHtmlView@@QAE@XZ': 0x465a60, '??1CSecureHtmlView@@UAE@XZ': 0x465a80,
    '?GetThisClass@CSecureHtmlView@@SGPAUCRuntimeClass@@XZ': 0x465a50,
    '?PreCreateWindow@CSecureHtmlView@@UAEHAAUtagCREATESTRUCTA@@@Z': 0x465ae0,
    '?OnAmbientProperty@CSecureHtmlView@@UAEHPAVCOleControlSite@@JPAUtagVARIANT@@@Z': 0x465a90,
    '?OnBeforeNavigate2@CSecureHtmlView@@UAEXPBDK0AAVCByteArray@@0PAH@Z': 0x465d70,
    '?singleton@StandardOut@RBX@@SA?AV?$shared_ptr@VStandardOut@RBX@@@boost@@XZ': 0x569620,
    '??0mutex@boost@@QAE@XZ': 0x594c90, '??1mutex@boost@@QAE@XZ': 0x594cb0,
    '?do_lock@mutex@boost@@AAEXXZ': 0x594ce0, '?do_unlock@mutex@boost@@AAEXXZ': 0x594d00,
    '??4CComVariant@ATL@@QAEAAV01@PBD@Z': 0x415d70, '??0CComBSTR@ATL@@QAE@PBD@Z': 0x401180,
    # Vector deleting destructors resolve to the scalar deleting bodies (no arrays of views are built).
    '??_ECOutputView@@UAEPAXI@Z': 0x436b40, '??_ECStandardOutputView@@UAEPAXI@Z': 0x437500,
    '?AtlThrowImpl@ATL@@YGXJ@Z': 0x401000, '?AfxCrtErrorCheck@@YAHH@Z': 0x401680,
}
FOLDED_PREFIX = {  # COMDATs whose original copy is shared with another instantiation (same code).
    '?addListener@?$Notifier@VStandardOut@RBX@@': 0x4218a0, '?removeListener@?$Notifier@VStandardOut@RBX@@': 0x5e5a80,
    '??$_Allocate@PAUStandardOutMessage@RBX@@': 0x420b50, '??$_Allocate@PAV?$CComPtr@UIHTMLDOMNode@@': 0x420b50,
    '?_Xlen@?$deque@UStandardOutMessage@RBX@@': 0x516a10, '?_Xlen@?$deque@V?$CComPtr@UIHTMLDOMNode@@': 0x516a10,
    '??D?$_Deque_const_iterator@UStandardOutMessage@RBX@@': 0x496020,
}


def expected(symbol):
    if symbol in resolved:
        return resolved[symbol]
    if symbol in EXTERNAL:
        return EXTERNAL[symbol]
    for prefix, address in FOLDED_PREFIX.items():
        if symbol.startswith(prefix):
            if symbol in bodies:  # our own copy must equal the shared original body
                t, tr, _ = match.target('2008-06', '%08x' % address)
                assert match.exact_match(t, tr, *bodies[symbol]), (symbol, hex(address))
            return address
    return None


rows = []
for name, address in sorted(resolved.items(), key=lambda kv: kv[1]):
    b, refs = bodies[name]
    target, target_refs, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, target_refs, b, refs), (name, len(b), len(target))
    start, section = definitions[name]
    table = sections[section]
    code_bytes = raw[table[4] + start:]
    verified, local = {}, []
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < len(b):
            continue
        symbol = symbols[index][0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code_bytes, offset)[0]) & 0xffffffff
        if symbol.startswith('__ehhandler$') or symbol.startswith('$LN'):
            local.append(symbol)
            continue
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(symbol), (name, symbol, hit)
            verified[symbol] = '%s!%s' % hit
            continue
        if symbol.startswith('??_C@') or symbol.startswith('__GUID_'):
            dstart, dsec = definitions[symbol]
            dt = sections[dsec]
            blob = raw[dt[4] + dstart: dt[4] + dt[3]]  # literal / GUID COMDAT section contents
            blob = blob[:16] if symbol.startswith('__GUID_') else blob
            assert data(value, len(blob)) == blob, (name, symbol, hex(value))
            verified[symbol] = hex(value)
            continue
        if symbol.startswith('??_7') or symbol.startswith('?class') or symbol.startswith('?messageMap@'):
            fixed = {'??_7COutputView@@6B@': 0x81300c, '??_7CStandardOutputView@@6BCOutputView@@@': 0x81324c,
                     '?classCOutputView@COutputView@@2UCRuntimeClass@@B': 0x812f60,
                     '?classCStandardOutputView@CStandardOutputView@@2UCRuntimeClass@@B': 0x812f7c}
            want = fixed.get(symbol, 0x813240 if symbol.startswith('??_7CStandardOutputView@@6B?$Listener') else
                             0x8134dc if symbol.startswith('?messageMap@?1??GetThisMessageMap@CStandardOutputView') else None)
            assert want == value, (name, symbol, hex(value))
            verified[symbol] = hex(value)
            continue
        want = expected(symbol)
        assert want == value, (name, symbol, hex(value), want)
        verified[symbol] = hex(value)
    rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(b), 'exact': True,
                 'verified_targets': verified, 'local': sorted(set(local))})

# Vtables slot by slot.
vtables = {v['vtable']: [int(a, 16) for a, c in v['slots']] for v in json.loads((root / 'work/2008-06/vtables.json').read_text())}
vrows = {}
for symbol, address in [('??_7COutputView@@6B@', 0x81300c), ('??_7CStandardOutputView@@6BCOutputView@@@', 0x81324c),
                        ('??_7CStandardOutputView@@6B?$Listener@VStandardOut@RBX@@UStandardOutMessage@2@@RBX@@@', 0x813240)]:
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    count = max(slots) + 1
    assert vtables['%08x' % address] == [word(address + 4 * k) for k in range(count)], symbol
    folded = 0
    for k in range(count):
        s, value = slots[k], word(address + 4 * k)
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(s), (symbol, k, s, hit)
            continue
        want = expected(s)
        if want is None and s in bodies:  # header-inline COMDAT folded with another unit's identical copy
            t, tr, _ = match.target('2008-06', '%08x' % value)
            assert match.exact_match(t, tr, *bodies[s]), (symbol, k, s, hex(value))
            folded += 1
            continue
        assert want == value, (symbol, k, s, hex(value), want)
    vrows['%08x' % address] = {'symbol': symbol, 'slots': count, 'inline_folds_verified_by_body': folded}

paths = [Path(__file__), source, fixture, root / 'rebuild/2008-06/native-headers/COutputView.h',
         root / 'rebuild/2008-06/native-headers/CSecureHtmlView.h', root / 'tools/rbxgs/Client/App/include/util/standardout.h',
         root / 'rebuild/2008-06/native-headers/util/Events.h']
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
(root / 'work/2008-06/shared-layouts/output-view-working.json').write_text(json.dumps({
    'class': 'COutputView + CStandardOutputView', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags,
    'profile': "std::string c_str noinline (target imports it)",
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'layout': {'COutputView': '0x120: CSecureHtmlView 0xf8, deque<CComPtr<IHTMLDOMNode>> +0xf8, CComQIPtr<IHTMLDocument2> +0x118, CComQIPtr<IHTMLDOMNode> +0x11c',
               'CStandardOutputView': '0x14c: COutputView, Listener<StandardOut,StandardOutMessage> +0x120, deque<StandardOutMessage> +0x124, boost::mutex +0x144'},
    'methods': rows, 'vtables': vrows, 'open': ['00437810 (jmp 006fa3e0, not part of this unit)'],
    'scope': 'Inactive. All bodies exact with verified targets. No active build, swap or credit.'}, indent=2) + '\n')
print('PASS native COutputView/CStandardOutputView: %d bodies exact, targets and %d vtables verified' % (len(rows), len(vrows)))
