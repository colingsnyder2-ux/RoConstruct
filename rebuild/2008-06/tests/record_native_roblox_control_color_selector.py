"""Verify the inactive native CRobloxControlColorSelector: layout, exact bodies, call/data targets, vtables, CRuntimeClass.

Profiles: plain document-swap flags + XTP headers (/UNOMINMAX /D_XTP_STATICLINK), and the same unit with
std::string::c_str noinline (the original imports c_str from msvcp90 in addColor 0044eb90).
Run with DISCOVER=1 to list every relocation binding instead of asserting the INTERNAL table.
"""
import hashlib, json, os, re, struct, sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[3]
here = Path(__file__).resolve().parent
sys.path.insert(0, str(root))
from roc import match, rebuild  # noqa: E402

DISCOVER = os.environ.get('DISCOVER')
out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
xtp = ['/UNOMINMAX', '/I' + str(root / 'tools/libs/xtp-11.2.2/Source'), '/D_XTP_STATICLINK']
source = root / 'rebuild/2008-06/native-classes/CRobloxControlColorSelector.cpp'
fixture = here / 'NativeRobloxControlColorSelectorLayout.cpp'
header = root / 'rebuild/2008-06/native-headers/CRobloxControlColorSelector.h'
sidecar = here / 'record_native_roblox_control_color_selector.json'
obj = out / 'NativeRobloxControlColorSelector.obj'
for path, target in [(source, obj), (fixture, out / 'NativeRobloxControlColorSelectorLayout.obj')]:
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + xtp + ['/Fo' + str(target), str(path)], out)
    assert code == 0, log
# noinline c_str profile: preprocess, mark the one RTM definition head, compile the preprocessed unit.
NEEDLE = 'const _Elem * c_str() const'
pre = out / 'noinl'; pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', [x for x in flags if x != '/c'] + xtp + ['/P', str(source)], pre)
assert code == 0, log
body = (pre / (source.stem + '.i')).read_text(errors='replace')
assert body.count(NEEDLE) == 1
unit = out / 'NativeRobloxControlColorSelectorNoinline.cpp'
unit.write_text(body.replace(NEEDLE, '__declspec(noinline) ' + NEEDLE))
nobj = out / 'NativeRobloxControlColorSelectorNoinline.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                                                        '/Fo' + str(nobj), str(unit)], out)
assert code == 0, log[-3000:]

pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
def data(address, size):
    return pe.get_data(address - image, size)
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
    if symbol.startswith('__imp_'):
        symbol = symbol[6:]
    if symbol.startswith('?'):
        return symbol
    return re.sub(r'@\d+$', '', symbol[1:] if symbol.startswith('_') else symbol)

V = '?$vector@UCColorInfo@CRobloxControlColorSelector@@V?$allocator@UCColorInfo@CRobloxControlColorSelector@@@std@@@std@@'
CI = 'UCColorInfo@CRobloxControlColorSelector@@'
# Own exact bodies (this probe) by symbol -> original address.
METHODS = [
    ('?GetRuntimeClass@CRobloxControlColorSelector@@UBEPAUCRuntimeClass@@XZ', 0x44ddd0),
    ('?OnSetSelected@CRobloxControlColorSelector@@MAEHH@Z', 0x44dde0),
    ('?GetColor@CRobloxControlColorSelector@@QBEKXZ', 0x44de00),
    ('?SetColor@CRobloxControlColorSelector@@QAEXK@Z', 0x44de10),
    ('??0CColorInfo@CRobloxControlColorSelector@@QAE@ABU01@@Z', 0x44deb0),
    ('??$_Copy_backward_opt@PA%sPAU12@Uforward_iterator_tag@std@@@std@@YAPA%sPAU12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z' % (CI, CI), 0x44dee0),
    ('?GetSize@CRobloxControlColorSelector@@MAE?AVCSize@@PAVCDC@@@Z', 0x44dfa0),
    ('?HitTest@CRobloxControlColorSelector@@ABEHVCPoint@@@Z', 0x44dfc0),
    ('?Draw@CRobloxControlColorSelector@@MAEXPAVCDC@@@Z', 0x44e090),
    ('?OnMouseMove@CRobloxControlColorSelector@@MAEXVCPoint@@@Z', 0x44e2e0),
    ('?OnExecute@CRobloxControlColorSelector@@MAEXXZ', 0x44e310),
    ('?OnClick@CRobloxControlColorSelector@@MAEXHVCPoint@@@Z', 0x44e370),
    ('?OnLButtonUp@CRobloxControlColorSelector@@MAEXVCPoint@@@Z', 0x44e410),
    ('??$_Fill@PA%sU12@@std@@YAXPA%s0ABU12@@Z' % (CI, CI), 0x44e460),
    ('??$_Copy_backward_opt@PA%sPAU12@@std@@YAPA%sPAU12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z' % (CI, CI), 0x44e4a0),
    ('??$_Uninit_copy@PA%sPAU12@V?$allocator@%s@std@@@std@@YAPA%sPAU12@00AAV?$allocator@%s@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z' % (CI, CI, CI, CI), 0x44e500),
    ('??$_Unchecked_move_backward@PA%sPAU12@@stdext@@YAPA%sPAU12@00@Z' % (CI, CI), 0x44e5a0),
    ('__catch$??$_Uninit_fill_n@PA%sIU12@V?$allocator@%s@std@@@std@@YAXPA%sIABU12@AAV?$allocator@%s@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z$0' % (CI, CI, CI, CI), 0x44e638),
    ('?_Ufill@%sIAEPA%sPAU34@IABU34@@Z' % (V, CI), 0x44e670),
    ('?_Destroy@%sIAEXPA%s0@Z' % (V, CI), 0x44e6b0),
    ('?_Tidy@%sIAEXXZ' % V, 0x44e6e0),
    ('??$_Umove@PA%s@%sIAEPA%sPAU23@00@Z' % (CI, V, CI), 0x44e730),
    ('?_Insert_n@%sIAEXV?$_Vector_const_iterator@%sV?$allocator@%s@std@@@2@IAB%s@Z' % (V, CI, CI, CI), 0x44e760),
    ('?insert@%sQAE?AV?$_Vector_iterator@%sV?$allocator@%s@std@@@2@V?$_Vector_const_iterator@%sV?$allocator@%s@std@@@2@AB%s@Z' % (V, CI, CI, CI, CI, CI), 0x44ea20),
    ('?push_back@%sQAEXAB%s@Z' % (V, CI), 0x44eaf0),
    ('??0CRobloxControlColorSelector@@QAE@XZ', 0x44ec60),
    ('??_ECRobloxControlColorSelector@@WCA@AEPAXI@Z', 0x44ed30),
    ('??_GCRobloxControlColorSelector@@UAEPAXI@Z', 0x44edd0),
    ('?CreateObject@CRobloxControlColorSelector@@SGPAVCObject@@XZ', 0x44edf0),
    ('?Clone@CRobloxControlColorSelector@@UAEPAVCXTPControl@@H@Z', 0x44ee50),
    ('?_GetBaseClass@CRobloxControlColorSelector@@KGPAUCRuntimeClass@@XZ', 0x745620),
    ('??__E?colors@CRobloxControlColorSelector@@0%sA@@YAXXZ' % V[1:].replace('?$', 'V?$', 1) if False else None, 0x7ef8c0),
    ('??__E_init_CRobloxControlColorSelector@@YAXXZ', 0x7ef920),
    (None, 0x7faeb0),
    (None, 0x7c15b0),
]
NOINLINE = [('?addColor@CRobloxControlColorSelector@@CAXVBrickColor@RBX@@@Z', 0x44eb90)]
# Header inlines emitted as COMDATs in this unit (MFC/XTP owned; matched and bound, not class methods).
INLINES = [('??0CRect@@QAE@UtagPOINT@@UtagSIZE@@@Z', 0x44df30), ('?PtInRect@CRect@@QBEHUtagPOINT@@@Z', 0x44df60),
           ('?GetEnabled@CXTPControl@@QBEHXZ', 0x44df80)]

raw = obj.read_bytes()
def resolve(funcs, prefix):
    hits = [n for n, b, r in funcs if n.startswith(prefix)]
    assert len(hits) >= 1, prefix
    return hits[0]
funcs = match.coff_functions(raw)
fix = []
for name, address in METHODS:
    if name is None:
        prefix = {0x7ef8c0: '??__E?colors@CRobloxControlColorSelector', 0x7faeb0: '??__F?colors@CRobloxControlColorSelector',
                  0x7c15b0: '__unwindfunclet$??__E?colors@CRobloxControlColorSelector'}[address]
        name = resolve(funcs, prefix)
    fix.append((name, address))
METHODS = fix

# Internal targets bound from original call sites / data references (address -> how proven), see INTERNAL_WHY.
INTERNAL = json.loads(sidecar.read_text())
OWN = {n: a for n, a in METHODS + NOINLINE + INLINES}
LOCAL_EH = re.compile(r'^(__ehhandler\$|__unwindfunclet\$|__catch\$|__tryblocktable\$|__unwindtable\$|__ehfuncinfo\$|\$LN\d|__catchsym\$)')

def vtable_identity(symbol, value):
    cls = symbol[4:symbol.index('@@6B') + 2]
    locator = struct.unpack('<I', data(value - 4, 4))[0]
    descriptor = struct.unpack('<I', data(locator + 12, 4))[0]
    rtti = pe.get_string_at_rva(descriptor + 8 - image).decode()
    assert rtti == '.?AV' + cls, (symbol, hex(value), rtti)
    return '%s (RTTI %s, offset %#x)' % (hex(value), rtti, struct.unpack('<I', data(locator + 4, 4))[0])

discovered = {}
def bind(raw, name, address):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[name]
    body_size = next(len(b) for n, b, _ in match.coff_functions(raw) if n == name)
    target, _, _ = match.target('2008-06', '%08x' % address)
    code = raw[sections[section][4] + start:]
    table = sections[section]
    verified, local = {}, set()
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if not 0 <= offset < body_size:
            continue
        symbol = symbols[index][0]
        if kind == 20:
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        else:
            value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
        if LOCAL_EH.match(symbol):
            local.add(symbol); continue
        hit = imported(value)
        if hit is not None:
            assert hit[1] == plain(symbol), (name, symbol, hex(value), hit)
            verified[symbol] = '%s!%s' % hit
        elif symbol.startswith('??_7') and symbol not in INTERNAL:
            verified[symbol] = vtable_identity(symbol, value)
        elif symbol in OWN:
            assert OWN[symbol] == value, (name, symbol, hex(value))
            verified[symbol] = '%s (exact here)' % hex(value)
        elif DISCOVER:
            discovered.setdefault(symbol, set()).add(hex(value))
        else:
            assert symbol in INTERNAL and int(INTERNAL[symbol][0], 16) == value, (name, symbol, hex(value))
            verified[symbol] = '%s (%s)' % (hex(value), INTERNAL[symbol][1])
    return verified, sorted(local)

rows = []
for objraw, methods, profile in [(raw, METHODS + INLINES, 'XTP headers'), (nobj.read_bytes(), NOINLINE, 'XTP headers + c_str noinline')]:
    bodies = {n: (b, r) for n, b, r in match.coff_functions(objraw)}
    for name, address in methods:
        b, r = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, b, r), (name, hex(address), len(b), len(target))
        verified, local = bind(objraw, name, address)
        rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(b), 'exact': True, 'profile': profile,
                     'inline_owner': (name, address) in INLINES, 'verified_targets': verified, 'local_eh': local})
# _Uninit_fill_n 0044e5d0: the compiled COMDAT holds the 104-byte body plus its catch block (0044e638, row above).
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
fill_n = next(n for n in bodies if n.startswith('??$_Uninit_fill_n@PA' + CI))
b, r = bodies[fill_n]
target, target_refs, _ = match.target('2008-06', '0044e5d0')
assert len(target) == 104 and match.exact_match(target, target_refs, b[:104], [x for x in r if x < 104])
rows.append({'address': '0044e5d0', 'symbol': fill_n, 'size': 104, 'exact': 'prefix (catch funclet split at 0044e638)',
             'profile': 'XTP headers'})
if DISCOVER:
    for k, v in sorted(discovered.items()):
        print(sorted(v), k)
    sys.exit(0)

# Vtables: every slot this object defines binds to the original slot value.
sections, symbols, definitions, _ = match._coff_data_index(raw)
def check_vtable(name, address, count):
    start, section = definitions[name]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if start <= offset < start + count * 4:
            slots[(offset - start) // 4] = symbols[index][0]
    assert len(slots) == count and table[3] - start == count * 4, (name, len(slots), table[3] - start)
    original = struct.unpack('<%dI' % count, data(address, count * 4))
    result, unverified = {}, {}
    for slot, symbol in sorted(slots.items()):
        value = original[slot]
        if symbol in OWN:
            assert OWN[symbol] == value, (slot, symbol, hex(value)); result[slot] = symbol
        elif symbol in INTERNAL and int(INTERNAL[symbol][0], 16) == value:
            result[slot] = symbol
        else:
            hit = imported(value)
            if hit is not None:
                assert hit[1] == plain(symbol); result[slot] = symbol
            else:
                unverified[slot] = (symbol, hex(value))
    return result, unverified
primary, primary_open = check_vtable('??_7CRobloxControlColorSelector@@6BCXTPControl@@@', 0x816e74, 82) \
    if '??_7CRobloxControlColorSelector@@6BCXTPControl@@@' in definitions else (None, None)

# XTP library bodies (recipe xtp-11.2.2-shared-mfc) for inherited slots: compiled in xtpobj/ by xtp_bodies().
XTP_SRC = str(root / 'tools/libs/xtp-11.2.2/Source')  # recipe copy with StdAfx.h (roc install / libs recipe)
(out / 'xtp-color-selector').mkdir(exist_ok=True)
for unit in ('CommandBars/XTPControl.cpp', 'Common/XTPColorManager.cpp'):
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/MD', '/GS', '/EHsc', '/Ob1', '/D_AFXDLL',
                            '/D_XTP_STATICLINK', '/D_DLL', '/I' + XTP_SRC, '/I' + str(root / 'tools/libs/mfc-9.0/atlmfc/include'),
                            '/Fo' + str(out / 'xtp-color-selector' / (Path(unit).stem + '.obj')), XTP_SRC + '/' + unit], out / 'xtp-color-selector')
    assert code == 0, log
xtp_bodies = {}
for o in (out / 'xtp-color-selector').glob('*.obj'):
    if o.name != 'cm_probe.obj':
        xtp_bodies.update({n: (b, r) for n, b, r in match.coff_functions(o.read_bytes())})
own_bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
def slot_proof(symbol, value):
    for where, table in (('xtp-lib', xtp_bodies), ('header COMDAT in this unit', own_bodies)):
        if symbol in table:
            b, r = table[symbol]
            t, tr, _ = match.target('2008-06', '%08x' % value)
            if match.exact_match(t, tr, b, r):
                return where
    return None
BASE_VTABLE = {0x816e74: 0x85181c, 0x816e14: 0x8517bc}  # CXTPControl's own RTTI vtables (same slot counts)
def check_vtable2(name, address, count):
    start, section = definitions[name]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if start <= offset < start + count * 4:
            slots[(offset - start) // 4] = symbols[index][0]
    assert len(slots) == count and table[3] - start == count * 4, (name, len(slots), table[3] - start)
    original = struct.unpack('<%dI' % count, data(address, count * 4))
    proof, unverified = {}, {}
    for slot, symbol in sorted(slots.items()):
        value = original[slot]
        if symbol in OWN:
            assert OWN[symbol] == value, (slot, symbol, hex(value)); proof[slot] = 'own exact'
        elif symbol in INTERNAL and int(INTERNAL[symbol][0], 16) == value:
            proof[slot] = INTERNAL[symbol][1]
        elif imported(value) is not None:
            assert imported(value)[1] == plain(symbol); proof[slot] = 'import'
        else:
            p = slot_proof(symbol, value)
            inherited = struct.unpack('<I', data(BASE_VTABLE[address] + 4 * slot, 4))[0]
            if p: proof[slot] = p
            elif inherited == value and ('@CXTPControl@@' in symbol or '@CXTPAccessible@@' in symbol):
                proof[slot] = 'inherited: equals CXTPControl vtable %08x slot %d' % (BASE_VTABLE[address], slot)
            else: unverified[slot] = (symbol, hex(value))
    return proof, unverified
primary, primary_open = check_vtable2('??_7CRobloxControlColorSelector@@6BCCmdTarget@@@', 0x816e74, 82)
secondary, secondary_open = check_vtable2('??_7CRobloxControlColorSelector@@6BCXTPAccessible@@@', 0x816e14, 23)
print('primary vtable: %d verified, open %s' % (len(primary), primary_open))
print('secondary vtable: %d verified, open %s' % (len(secondary), secondary_open))

# CRuntimeClass 00931c34 (writable, IMPLEMENT_SERIAL): name, size 0x184, schema, CreateObject, base getter, next, init.
runtime = struct.unpack('<IiIIIII', data(0x931c34, 28))
assert data(runtime[0], 28) == b'CRobloxControlColorSelector\0'
assert runtime[1:7] == (0x184, 0x80000020, 0x44edf0, 0x745620, 0, 0x96dd3c), [hex(x) for x in runtime]

sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {
    'class': 'CRobloxControlColorSelector', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags + xtp,
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in [Path(__file__), source, fixture, header, sidecar]},
    'object_sha256': sha(obj), 'noinline_object_sha256': sha(nobj),
    'layout': {'size': '0x184', 'base': 'CXTPControl (0x174, XTP 11.2.2)', 'm_nSelected': '0x174', 'm_nPressed': '0x178',
               'm_bColorPicked': '0x17c (bool)', 'm_clr': '0x180'},
    'methods': rows, 'vtables': {'00816e74': {'verified': len(primary), 'open': primary_open},
                                 '00816e14': {'verified': len(secondary), 'open': secondary_open}},
    'runtime_class': {'address': '00931c34', 'size': '0x184', 'schema': '0x80000020', 'create': '0044edf0',
                      'base_getter': '00745620', 'class_init': '0096dd3c'},
}
(root / 'work/2008-06/shared-layouts/roblox-control-color-selector-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native CRobloxControlColorSelector: %d exact rows' % len(rows))
