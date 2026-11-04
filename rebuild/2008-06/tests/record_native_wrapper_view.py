"""Check inactive CWrapperView source/object evidence; no provider selection or runtime gate.

Uses the registered, hash-pinned client, RTM 21022, document-swap flags remapped to
this checkout, and XTP headers. Reuses CSelectionTreeCtrl lifecycle rows only when
their recorded source/header hashes are current. Their transitive gaps stay open.
"""
import json
import re
import struct
import sys
from pathlib import Path

import pefile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
import native_bind
from native_bind import XTP_FLAGS, plain, rebuild, sha
from roc import match

SOURCE = ROOT / 'rebuild/2008-06/native-classes/CWrapperView.cpp'
HEADER = ROOT / 'rebuild/2008-06/native-headers/CWrapperView.h'
LAYOUT = HERE / 'NativeWrapperViewLayout.cpp'
CLIENT = ROOT / 'clients/2008-06/Roblox.exe'
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/wrapper-view'
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/wrapper-view-working.json'
CRT, VTABLE = 0x8107e0, 0x810a9c
CRT_SYM = '?classCWrapperView@CWrapperView@@2UCRuntimeClass@@B'
VT_SYM = '??_7CWrapperView@@6B@'
owner = 'C:' + chr(92) + 'Users' + chr(92) + 'colin' + chr(92) + 'RoConstruct'
FLAGS = [x.replace(owner, str(ROOT)) for x in json.loads(
    (ROOT / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())['flags']
    if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
FLAGS += XTP_FLAGS
tool = rebuild.toolchain(21022)


class Client(native_bind.Original):
    def __init__(self):
        self.path = CLIENT
        assert sha(CLIENT) == json.loads((ROOT / 'clients/clients.json').read_text())['2008-06']['sha256']
        self.pe = pefile.PE(str(CLIENT))
        self.image = self.pe.OPTIONAL_HEADER.ImageBase
        self.imports = {x.address: (d.dll.decode().lower(), x.ordinal, x.name.decode() if x.name else None)
                        for d in self.pe.DIRECTORY_ENTRY_IMPORT for x in d.imports}
        self.mfc = {}
        for line in (ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='ignore').splitlines():
            m = re.match(r'\s*(\S+)\s+@\s*(\d+)', line)
            if m:
                self.mfc[int(m.group(2))] = m.group(1)


original = Client()


def compile_one(source):
    obj = OUT / (source.stem + '.obj')
    code, log = rebuild.run(tool, 'cl', FLAGS + ['/Fo' + str(obj), str(source)], OUT)
    (OUT / (source.stem + '.log')).write_text(log)
    assert code == 0, log[-3000:]
    return obj


layout_obj = compile_one(LAYOUT)
obj = compile_one(SOURCE)
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
compiler_ids = [v for n, v, _s, _k in symbols.values() if n == '@comp.id']
assert len(compiler_ids) == 1 and compiler_ids[0] & 0xffff == 21022

# Current dependency bodies are reused, not credited again. The dependency's
# broader call-site-only bindings are not upgraded by this receipt.
TREE_PROOF = ROOT / 'work/2008-06/shared-layouts/selection-tree-ctrl-working.json'
tree_proof = json.loads(TREE_PROOF.read_text())
assert all(sha(ROOT / p) == h for p, h in tree_proof['sources'].items()), 'stale tree proof inputs'
external = {}
for symbol, address in [('??0CSelectionTreeCtrl@@QAE@XZ', 0x425c90),
                        ('??1CSelectionTreeCtrl@@UAE@XZ', 0x4270c0),
                        ('?OnCmdMsg@CSelectionTreeCtrl@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z', 0x422960)]:
    row = next(r for r in tree_proof['methods'] if r['symbol'] == symbol)
    assert row['exact'] and int(row['address'], 16) == address
    external[symbol] = address

METHODS = [
    ('?_GetBaseClass@CWrapperView@@KGPAUCRuntimeClass@@XZ', 0x6c4cb0),
    ('?GetThisClass@CWrapperView@@SGPAUCRuntimeClass@@XZ', 0x42ece0),
    ('?GetRuntimeClass@CWrapperView@@UBEPAUCRuntimeClass@@XZ', 0x42ece0),
    ('??0CWrapperView@@IAE@XZ', 0x42eb40),
    ('?OnDraw@CWrapperView@@MAEXPAVCDC@@@Z', 0x70bdf0),
    ('?PreCreateWindow@CWrapperView@@UAEHAAUtagCREATESTRUCTA@@@Z', 0x42eb90),
    ('?OnCmdMsg@CWrapperView@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z', 0x42ebc0),
    ('?OnWndMsg@CWrapperView@@MAEHIIJPAJ@Z', 0x42ec10),
    ('?CreateObject@CWrapperView@@SGPAVCObject@@XZ', 0x430010),
    ('??_GCWrapperView@@UAEPAXI@Z', 0x430070)]
OWN = dict(METHODS)
INTERNAL = dict(external, **{CRT_SYM: CRT, VT_SYM: VTABLE})
rows = native_bind.verify(original, obj, METHODS, INTERNAL)


def relocs(section):
    table = sections[section]
    return [struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7])]


def word(address):
    return struct.unpack('<I', original.data(address, 4))[0]


assert word(0x80fed4 + 5 * 4) == external['?OnCmdMsg@CSelectionTreeCtrl@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z']


def prove_eh(function, handler):
    """Check the complete one-state EH graph, including the shared cleanup body."""
    hname, fname = '__ehhandler$' + function, '__ehfuncinfo$' + function
    hpos, hsec = definitions[hname]
    hs = sections[hsec]
    emitted_stub = raw[hs[4] + hpos:hs[4] + hpos + 10]
    hr = [(o - hpos, i, k) for o, i, k in relocs(hsec) if hpos <= o < hpos + 10]
    assert hpos + 10 == hs[3] and emitted_stub == b'\xb8\0\0\0\0\xe9\0\0\0\0'
    assert [(o, symbols[i][0], k) for o, i, k in hr] == [(1, fname, 6), (6, '___CxxFrameHandler3', 20)]
    stub = original.data(handler, 10)
    assert stub[0] == 0xb8 and stub[5] == 0xe9
    funcinfo = struct.unpack_from('<I', stub, 1)[0]
    thunk = handler + 10 + struct.unpack_from('<i', stub, 6)[0]
    assert original.imported(thunk) == ('msvcr90.dll', '__CxxFrameHandler3')

    xpos, xsec = definitions[fname]
    xs = sections[xsec]
    xdata = raw[xs[4]:xs[4] + xs[3]]
    xr = relocs(xsec)
    assert xpos == 8 and len(xdata) == 44
    xbase = funcinfo - xpos
    original_x = original.data(xbase, len(xdata))
    mask = {j for off, _i, _k in xr for j in range(off, off + 4)}
    assert all(xdata[i] == original_x[i] for i in range(len(xdata)) if i not in mask)
    cleanup_name = '__unwindfunclet$' + function + '$0'
    assert [(o, symbols[i][0], k) for o, i, k in xr] == [(4, cleanup_name, 6), (16, '__unwindtable$' + function, 6)]
    assert word(xbase + 16) == xbase and definitions['__unwindtable$' + function] == (0, xsec)
    cleanup = word(xbase + 4)
    body, refs = bodies[cleanup_name]
    assert cleanup + len(body) == handler, 'cleanup span must end at handler'
    target = original.data(cleanup, len(body))
    mask = {j for off in refs for j in range(off, off + 4)}
    assert all(body[i] == target[i] for i in range(len(body)) if i not in mask)
    cpos, csec = definitions[cleanup_name]
    cr = [(o, i, k) for o, i, k in relocs(csec) if cpos <= o < cpos + len(body)]
    assert len(cr) == 1 and cr[0][2] == 20
    off, index, _kind = cr[0]
    off -= cpos
    callee = cleanup + off + 4 + struct.unpack_from('<i', target, off)[0]
    hit = original.imported(callee)
    cleanup_target = symbols[index][0]
    if hit is not None:
        assert hit == ('mfc90.dll', plain(cleanup_target)), (function, hit)
        cleanup_evidence = '%s!%s' % hit
    else:
        assert cleanup_target == '??3CObject@@SGXPAX@Z' and callee == 0x401110
        cleanup_evidence = native_bind.verify(original, obj, [(cleanup_target, callee)], INTERNAL, OWN)
    return {'function': function, 'handler': '%08x' % handler,
            'funcinfo': '%08x' % funcinfo, 'unwind_table': '%08x' % xbase,
            'metadata_and_both_relocation_targets_checked': True,
            'cleanup': {'address': '%08x' % cleanup, 'size': len(body),
                        'masked_span_match': True, 'callee_evidence': cleanup_evidence},
            'runtime': 'msvcr90.dll!__CxxFrameHandler3 import identity; no runtime implementation claim',
            'counted_as_native_methods': False}


eh = []
for row in rows:
    for symbol in row['local_eh']:
        if symbol.startswith('__ehhandler$'):
            start, sec = definitions[row['symbol']]
            handler_ref = next(o - start for o, i, _k in relocs(sec) if symbols[i][0] == symbol)
            eh.append(prove_eh(row['symbol'], word(int(row['address'], 16) + handler_ref)))

# CRuntimeClass bytes and all three pointers agree with the emitted record.
runtime_words = struct.unpack('<7I', original.data(CRT, 28))
assert original.string(runtime_words[0]) == 'CWrapperView'
assert runtime_words[1:] == (0x188, 0xffff, 0x430010, 0x6c4cb0, 0, 0)
rpos, rsec = definitions[CRT_SYM]
rs = sections[rsec]
record = raw[rs[4] + rpos:rs[4] + rpos + 28]
runtime_pointers = {}
for off, index, kind in relocs(rsec):
    off -= rpos
    if not 0 <= off < 28:
        continue
    assert kind == 6 and off in (0, 12, 16)
    symbol = symbols[index][0]
    value = runtime_words[off // 4] - struct.unpack_from('<I', record, off)[0]
    if off == 0:
        p, sec = definitions[symbol]
        s = sections[sec]
        literal = raw[s[4] + p:s[4] + s[3]].split(b'\0')[0] + b'\0'
        assert original.data(value, len(literal)) == literal == b'CWrapperView\0'
    else:
        assert OWN[symbol] == value
    runtime_pointers[off] = symbol
assert set(runtime_pointers) == {0, 12, 16}
assert all(record[i] == original.data(CRT, 28)[i] for i in range(28) if i // 4 not in (0, 3, 4))

# All 101 slots: own bodies, same-name MFC imports, or exact inherited inline bodies.
vpos, vsec = definitions[VT_SYM]
assert sections[vsec][3] - vpos == 101 * 4
slots = {((o - vpos) // 4): symbols[i][0] for o, i, k in relocs(vsec) if vpos <= o < vpos + 404}
assert set(slots) == set(range(101))
vtable, inherited = [], []
for slot, symbol in sorted(slots.items()):
    address = word(VTABLE + slot * 4)
    if symbol == '??_ECWrapperView@@UAEPAXI@Z':
        assert OWN['??_GCWrapperView@@UAEPAXI@Z'] == address
        proof = 'weak vector-deleting alias of exact scalar deleting destructor'
    elif symbol in OWN:
        assert OWN[symbol] == address
        proof = 'own exact row'
    elif original.imported(address):
        hit = original.imported(address)
        assert hit == ('mfc90.dll', plain(symbol)), (slot, symbol, hit)
        proof = '%s!%s' % hit
    else:
        checked = native_bind.verify(original, obj, [(symbol, address)], INTERNAL, OWN)
        inherited += checked
        proof = 'exact inherited inline body with targets checked'
    vtable.append({'slot': slot, 'symbol': symbol, 'address': '%08x' % address, 'proof': proof})
assert original.vtable_class(VTABLE) == ('.?AVCWrapperView@@', 0)
locator = word(VTABLE - 4)
sig, offset, cd, td, chd = struct.unpack('<5I', original.data(locator, 20))
assert (sig, offset, cd) == (0, 0, 0)
_signature, _attributes, count, array = struct.unpack('<4I', original.data(chd, 16))
chain = []
for i in range(count):
    tdesc, _num, mdisp, pdisp, vdisp = struct.unpack('<IIiii', original.data(word(array + i * 4), 20))
    chain.append([original.string(tdesc + 8), mdisp, pdisp, vdisp])
assert [x[0] for x in chain] == ['.?AV%s@@' % c for c in ('CWrapperView', 'CView', 'CWnd', 'CCmdTarget', 'CObject')]
assert all(x[1:] == [0, -1, 0] for x in chain)

sources = {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p)
           for p in (Path(__file__), SOURCE, HEADER, LAYOUT, HERE / 'native_bind.py')}
receipt = {
    'class': 'CWrapperView', 'status': 'PASS', 'scope': 'inactive source/object proof only',
    'compiler': 'MSVC 15.00.21022', 'coff_compiler_id': hex(compiler_ids[0]), 'flags': FLAGS,
    'original': 'clients/2008-06/Roblox.exe', 'original_sha256': sha(CLIENT),
    'sources': sources, 'object_sha256': sha(obj), 'layout_object_sha256': sha(layout_obj),
    'methods': rows, 'inherited_inline_rows': inherited, 'eh_owner_graphs': eh,
    'new_native_addresses': ['0042eb40', '0042eb90', '0042ebc0', '0042ec10', '0042ece0', '00430010', '00430070'],
    'reused_addresses': {'006c4cb0': 'folded CView base-class getter', '0070bdf0': 'shared empty ret4 (OnDraw)'},
    'layout': {'size': '0x188', 'base': 'CView 0x58', 'tree_offset': '0x58', 'tree_size': '0x130',
               'evidence': 'CRuntimeClass size, CreateObject new(0x188), CView/tree ctor sequence, deleting destructor tree+0x58/CView teardown, RTTI and compile assertions'},
    'runtime_class': {'address': '%08x' % CRT, 'size': 28, 'all_bytes_and_relocation_targets_checked': True},
    'rtti': {'locator': '%08x' % locator, 'chain': chain}, 'vtable': vtable,
    'message_map': 'inherits CView::GetMessageMap (slot12); no own message map declared or emitted',
    'member_dependency': {'receipt': str(TREE_PROOF.relative_to(ROOT)).replace('\\', '/'),
                          'receipt_sha256': sha(TREE_PROOF), 'input_hashes_current': True,
                          'lifecycle_and_dispatch_targets': {k: '%08x' % v for k, v in external.items()},
                          'virtual_dispatch': 'member table0080fed4 slot5 -> CSelectionTreeCtrl::OnCmdMsg00422960; its activeRobloxDoc binding is transitive evidence only',
                          'limit': 'reuses exact lifecycle/dispatch bodies; dependency transitive call-site bindings/header-pending methods are not upgraded'},
    'open': ['CSelectionTreeCtrl transitive proof and provider/link acceptance remain separate',
             'no standalone destructor-address claim; its teardown is inlined into the deleting destructor',
             'names and source shape are codegen analogs, not original declaration proof',
             'no selection, P5/P6, runtime or server credit'],
    'failures': []}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS inactive CWrapperView: %d rows / %d distinct addresses; 7 new native addresses; 101 vtable slots' %
      (len(rows), len({r['address'] for r in rows})))
