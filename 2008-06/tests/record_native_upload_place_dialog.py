"""Verify the inactive native CUploadPlaceDialog constructor and deleting destructor with their targets.

The target imports CSimpleStringT::operator PCXSTR, so the unit is compiled through the same
noinline profile as record_native_save_dialog.py. Writes shared-layouts/upload-place-dialog-working.json.
"""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild  # noqa: E402

out = root / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
source = root / 'rebuild/2008-06/native-classes/CUploadPlaceDialog.cpp'
fixture = root / 'rebuild/2008-06/tests/NativeUploadPlaceDialogLayout.cpp'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(out / 'NativeUploadPlaceDialogLayout.obj'), str(fixture)], out)
assert code == 0, log
pre = out / 'upload-place-dialog-pre'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', [x for x in flags if x != '/c'] + ['/P', str(source)], pre)
assert code == 0, log
body = (pre / 'CUploadPlaceDialog.i').read_text(errors='replace')
needle = 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert body.count(needle) == 1
unit = out / 'NativeUploadPlaceDialogProfile.cpp'
unit.write_text(body.replace(needle, '__declspec(noinline) ' + needle))
obj = out / 'NativeUploadPlaceDialogProfile.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                                                       '/Fo' + str(obj), str(unit)], out)
assert code == 0, log

pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image = pe.OPTIONAL_HEADER.ImageBase
data = lambda address, size: pe.get_data(address - image, size)
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

INTERNAL = {
    '?applicationBaseUrl@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ': 0x4060d0,
    '??0CSaveToRobloxDialog@@QAE@PAUIDispatch@@PBDPAVCWnd@@@Z': 0x45fe80,
    '??1CSaveToRobloxDialog@@UAE@XZ': 0x45fe20,
    '??HATL@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@0@ABV10@PBD@Z': 0x40e160,
    '??_7CUploadPlaceDialog@@6BCDialog@@@': 0x81757c,
    '??_7CUploadPlaceDialog@@6BCDHtmlEventSink@@@': 0x817550,
}
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
rows = []
for name, address in [('??0CUploadPlaceDialog@@QAE@PAUIDispatch@@PAVCWnd@@@Z', 0x44f5c0), ('??_GCUploadPlaceDialog@@UAEPAXI@Z', 0x44f5a0)]:
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
        if symbol.startswith('__ehhandler$'):
            local.append(symbol)
            continue
        hit = imported(value)
        if hit is not None:
            plain = symbol[6:] if symbol.startswith('__imp_') else symbol
            assert hit[1] == plain, (name, symbol, hit)
            verified[symbol] = '%s!%s' % hit
        elif symbol.startswith('??_C@'):
            assert data(value, 18) == b'/Game/Upload.aspx\0', (symbol, hex(value))
            verified[symbol] = hex(value)
        else:
            assert INTERNAL.get(symbol) == value, (name, symbol, hex(value))
            verified[symbol] = hex(value)
    rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(b), 'exact': True,
                 'verified_targets': verified, 'local_eh': local})
assert '0x45fe80' in rows[0]['verified_targets'].values() and '0x45fe20' in rows[1]['verified_targets'].values()
# Original vtables equal CPublishAsPlaceDialog's word for word (shared COMDAT bodies), 111 and 10 slots.
assert data(0x81757c, 111 * 4) == data(0x81737c, 111 * 4) and data(0x817550, 40) == data(0x817350, 40)

paths = [Path(__file__), source, fixture, root / 'rebuild/2008-06/native-headers/CUploadPlaceDialog.h',
         root / 'rebuild/2008-06/native-headers/CSaveToRobloxDialog.h']
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
(root / 'work/2008-06/shared-layouts/upload-place-dialog-working.json').write_text(json.dumps({
    'class': 'CUploadPlaceDialog', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags,
    'profile': 'CString operator PCXSTR noinline (target imports it)',
    'sources': {str(p.relative_to(root)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'layout': {'size': '0x130 (no own members)', 'evidence': 'constructor 0044f5c0 stores only vtables 0081757c/00817550; deleting destructor 0044f5a0 forwards to ~CSaveToRobloxDialog; RTTI base chain; stack-only construction at 004553b2, so the size rests on the CSaveToRobloxDialog layout'},
    'methods': rows, 'open': [],
    'scope': 'Inactive. Both own bodies exact with verified targets; inherits everything else. No active build, swap or credit.'}, indent=2) + '\n')
print('PASS native CUploadPlaceDialog: constructor and deleting destructor, targets verified')
