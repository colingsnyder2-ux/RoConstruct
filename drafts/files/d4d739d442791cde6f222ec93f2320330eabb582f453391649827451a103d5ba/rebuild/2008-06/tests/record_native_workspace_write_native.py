"""Partial inactive native proof of CWorkspace::Write/WriteSelection.

Exact bodies and known imports/literals/data are checked. Address-only callee
bindings and local EH metadata stay explicit gaps; no selection or runtime gate.
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
from native_bind import rebuild, sha
from roc import match

SOURCE = ROOT / 'rebuild/2008-06/native-classes/CWorkspaceWrite.cpp'
CLOSE = ROOT / 'rebuild/2008-06/native-classes/CWorkspaceClose.cpp'
LAYOUT = HERE / 'NativeWorkspaceWriteLayout.cpp'
HEADER = ROOT / 'rebuild/2008-06/native-headers/CWorkspace.h'
CONTENT = ROOT / 'rebuild/2008-06/native-headers/CContent.h'
HELPER = ROOT / 'rebuild/2008-06/native-classes/WorkspaceSiteError.cpp'
CLIENT = ROOT / 'clients/2008-06/Roblox.exe'
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/workspace-write-native'
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/workspace-write-native-working.json'
owner = 'C:' + chr(92) + 'Users' + chr(92) + 'colin' + chr(92) + 'RoConstruct'
FLAGS = [x.replace(owner, str(ROOT)) for x in json.loads(
    (ROOT / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())['flags']
    if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]


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
tool = rebuild.toolchain(21022)


def compile_one(source):
    obj = OUT / (source.stem + '.obj')
    code, log = rebuild.run(tool, 'cl', FLAGS + ['/Fo' + str(obj), str(source)], OUT)
    (OUT / (source.stem + '.log')).write_text(log)
    assert code == 0, log[-3000:]
    return obj


layout_obj = compile_one(LAYOUT)
obj = compile_one(SOURCE)
helper_obj = compile_one(HELPER)
close_pre = OUT / 'close-pre'
close_pre.mkdir(exist_ok=True)
code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + ['/P', str(CLOSE)], close_pre)
assert code == 0, log[-3000:]
close_profile = OUT / 'CWorkspaceCloseProfile.cpp'
close_profile.write_text((close_pre / 'CWorkspaceClose.i').read_text(errors='replace'))
close_obj = OUT / 'CWorkspaceClose.obj'
CLOSE_FLAGS = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHs-c-', '/MD']
code, log = rebuild.run(tool, 'cl', CLOSE_FLAGS + ['/Fo' + str(close_obj), str(close_profile)], OUT)
assert code == 0, log[-3000:]
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
comp_ids = [v for n, v, _s, _k in symbols.values() if n == '@comp.id']
assert len(comp_ids) == 1 and comp_ids[0] & 0xffff == 21022

FACTORY = '?CreateInstance@?$CComObject@VCContent@@@ATL@@SGJPAPAV12@@Z'
STATE_DTOR = '??1AFX_MAINTAIN_STATE2@@QAE@XZ'
SITE = '?reportWorkspaceSiteError@@YAJABU_GUID@@PBDJ@Z'
CONTEXT = '?workspaceSiteErrorContext@@3U_GUID@@B'
EXPECTED = {
    FACTORY: 0x46ac90,
    '?reportWorkspaceHResult@@YAXHJPBDH@Z': 0x427d80,
    '?raiseWorkspaceError@@YAXJABU_GUID@@@Z': 0x46ad70,
    '?writeXmlModel@CWorkspace@@QAE?AV?$auto_ptr@VXmlElement@@@std@@XZ': 0x46ab90,
    '?writeXmlSelection@CWorkspace@@QAE?AV?$auto_ptr@VXmlElement@@@std@@XZ': 0x46b750,
    '?write@CWorkspace@@QAEJPAVXmlElement@@AAV?$basic_ostream@DU?$char_traits@D@std@@@std@@@Z': 0x46b860,
    '??1XmlElement@@QAE@XZ': 0x413a70,
    SITE: 0x429330, CONTEXT: 0x8164f8, STATE_DTOR: 0x4060f0}
METHODS = [('?Write@CWorkspace@@UAGJPAPAUIContent@@@Z', 0x46bd70),
           ('?WriteSelection@CWorkspace@@UAGJPAPAUIContent@@@Z', 0x46bfd0)]
rows = native_bind.verify(original, obj, METHODS, EXPECTED)
support = native_bind.verify(original, obj, [(STATE_DTOR, 0x4060f0)], {})

# The neutral context GUID has a real native definition, checked as COFF bytes.
hs, hy, hd, _ = match._coff_data_index(helper_obj.read_bytes())
p, n = hd[CONTEXT]
guid = helper_obj.read_bytes()[hs[n][4] + p:hs[n][4] + p + 16]
assert len(guid) == 16 and guid == original.data(0x8164f8, 16)

# Fresh helper body, retaining its further function dependencies as gaps.
helper_expected = {'?reportWorkspaceStatus@@YAXGPBD@Z': 0x427c20,
                   '?AtlReportError@ATL@@YGJABU_GUID@@PBDK10J@Z': 0x4290b0,
                   '_GUID_NULL': 0x8501ec}
helper_rows = native_bind.verify(original, helper_obj, [(SITE, 0x429330)], helper_expected)
for row in helper_rows:
    row['unproven_targets'] = {k: row['verified_targets'].pop(k) for k in helper_expected if k in row['verified_targets']}

for row in rows:
    row['unproven_targets'] = {k: row['verified_targets'].pop(k) for k in EXPECTED
                               if k not in (STATE_DTOR, CONTEXT, SITE) and k in row['verified_targets']}
    row['target_evidence'] = {STATE_DTOR: 'fresh exact support row from this object',
                              CONTEXT: 'native WorkspaceSiteError.cpp definition: emitted 16 GUID bytes equal original',
                              SITE: 'fresh exact helper body; its further dependencies remain open'}
    # native_bind explicitly leaves local EH symbols unverified. Resolve code
    # continuation labels by COFF position; retain EH-owner metadata as pending.
    start, sec = definitions[row['symbol']]
    table = sections[sec]
    target = original.data(int(row['address'], 16), row['size'])
    local_continuations = []
    pending_eh = []
    for j in range(table[7]):
        off, index, kind = struct.unpack_from('<IIH', raw, table[5] + j * 10)
        off -= start
        if not 0 <= off < len(target):
            continue
        name = symbols[index][0]
        if name.startswith('$LN'):
            value = struct.unpack_from('<I', target, off)[0]
            addend = struct.unpack_from('<i', raw, table[4] + start + off)[0]
            # Local $LN labels can repeat across functions; the relocation's
            # symbol-table index identifies the correct section and position.
            _name, pos, sn, _type = symbols[index]
            assert kind == 6 and sn - 1 == sec and value == int(row['address'], 16) + pos - start + addend
            local_continuations.append({'symbol': name, 'offset': off, 'address': '%08x' % value})
        elif name.startswith('__ehhandler$'):
            pending_eh.append({'symbol': name, 'address': '%08x' % struct.unpack_from('<I', target, off)[0],
                               'status': 'operand only; full funcinfo/catch/unwind graph not verified here'})
    row['local_continuations'] = local_continuations
    row['pending_eh_metadata'] = pending_eh

close_rows = native_bind.verify(original, close_obj, [('?Close@CWorkspace@@UAGJXZ', 0x46b500)],
                                {'?cleanup@CWorkspace@@QAEXXZ': 0x46b0e0})
for row in close_rows:
    name = '?cleanup@CWorkspace@@QAEXXZ'
    row['unproven_targets'] = {name: row['verified_targets'].pop(name)}
    row['target_evidence'] = {'profile': 'document-swap preprocessing with /EHsc, then /EHs-c- compilation; compatible profile, original flag spelling unproven'}
rows += close_rows

# Factory contract evidence supports the explicit non-null optimization hint.
# A matching body with unresolved module/static operands is not full acceptance.
fb, fr = bodies[FACTORY]
ft, ftr, _ = match.target('2008-06', '0046ac90')
assert len(fb) == len(ft) == 209 and match.exact_match(ft, ftr, fb, fr)
assert b'\x68\x94\0\0\0' in ft, 'original factory allocation is not 0x94'
for vtable, offset in [(0x80eabc, 0), (0x80ea98, 4)]:
    assert original.vtable_class(vtable) == ('.?AV?$CComObject@VCContent@@@ATL@@', offset)
workspace_table = 0x80ae6c
for slot, (_symbol, address) in zip((10, 11), METHODS):
    assert struct.unpack('<I', original.data(workspace_table + slot * 4, 4))[0] == address
assert struct.unpack('<I', original.data(workspace_table + 14 * 4, 4))[0] == 0x46b500
assert original.vtable_class(workspace_table) == ('.?AV?$CComObject@VCWorkspace@@@ATL@@', 0)

sources = {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in
           (Path(__file__), SOURCE, CLOSE, HEADER, CONTENT, LAYOUT, HELPER, HERE / 'native_bind.py',
            ROOT / 'rebuild/2008-06/native-headers/RobloxLib.h')}
receipt = {
    'class': 'CWorkspace', 'status': 'PARTIAL', 'scope': 'inactive native source/object evidence only',
    'compiler': 'MSVC 15.00.21022', 'coff_compiler_id': hex(comp_ids[0]), 'flags': FLAGS,
    'original': 'clients/2008-06/Roblox.exe', 'original_sha256': sha(CLIENT), 'sources': sources,
    'object_sha256': sha(obj), 'layout_object_sha256': sha(layout_obj), 'helper_object_sha256': sha(helper_obj),
    'close_object_sha256': sha(close_obj), 'close_profile_sha256': sha(close_profile), 'close_compile_flags': CLOSE_FLAGS,
    'methods': rows, 'support_rows_reused': support, 'helper_rows_reused': helper_rows,
    'layout': {'workspace_size': '0x34', 'dataModel': '0x24', 'runService': '0x2c',
               'content_allocation_size': '0x94', 'content_stream': '0xc',
               'proof': 'compile assertions; existing constructor/destructor/RTTI evidence, not a new complete-class claim'},
    'com_slots': {'table': '0080ae6c', 'Write': 10, 'WriteSelection': 11, 'Close': 14,
                  'evidence': 'original CComObject<CWorkspace> RTTI and interface slot words'},
    'factory_contract_evidence': {'symbol': FACTORY, 'address': '0046ac90', 'size': len(fb),
                                  'masked_exact_body': True, 'allocation': '0x94',
                                  'implementation': 'genuine ATL9 CComObject::CreateInstance; S_OK implies a constructed non-null object',
                                  'type_rtti_offsets': {'ISupportErrorInfo': 0, 'IContent': 4},
                                  'acceptance': 'partial: factory call/data operands are not upgraded by this body check'},
    'native_source_promotions': ['0046bd70', '0046bfd0', '0046b500'], 'server_credit': 0,
    'failures': [],
    'open': ['XML writer0046b860 remains a known mismatch requiring its native header owner',
             'unproven_targets are relocation operands only, including factory/module/static and XML helpers',
             'local EH owner metadata retained in pending_eh_metadata; continuations checked separately',
             'workspace reporter further callees and GUID_NULL not upgraded by this observer',
             'shared LIBID linkage, selected providers, full-class closure and runtime gates remain open',
             'Close cleanup0046b0e0 remains unproven; exception-disabled compile profile is confined to Close',
             'source uses existing native headers; no test header dependency or shared header edits',
             'source promotion is not accepted-tree mapping, server credit or runtime verification']}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PARTIAL inactive CWorkspace: Write/WriteSelection/Close masked-exact; explicit callee/EH gaps retained')
