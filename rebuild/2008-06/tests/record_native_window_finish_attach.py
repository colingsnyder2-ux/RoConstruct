"""Record inactive window attach draft and prove its provider/global identities."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match

base = root / 'rebuild/2008-06'
out = base / 'out/native-window-finish-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/CRobloxWndFinishAttach.cpp', '0045ead0=?finishAttach@CRobloxWnd@@'],
                     cwd=root, env=env, capture_output=True, text=True, check=True)
assert 'differs' in run.stdout, run.stdout
obj = out / 'CheckCRobloxWndFinishAttach.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?finishAttach@CRobloxWnd@@'))
offset, index = definitions[name]
table = sections[index]
bound = {symbols[symbol][0] for position, symbol, kind in
         (struct.unpack_from('<IIH', raw, table[5] + 10 * i) for i in range(table[7]))
         if offset <= position < offset + 87}
assert any(n.startswith('??$create@VContentProvider@RBX@@') for n in bound)
assert any(n.startswith('?buildGui@DataModel@RBX@@') for n in bound)
assert any(n.startswith('?guiContentProvider@RBX@@') for n in bound)
assert any(n.startswith('?m_current@GWindow@G3D@@') for n in bound)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'), fast_load=True)
image = pe.get_memory_mapped_image()
base_address = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack_from('<I', image, address - base_address)[0]
locator = read32(0x82df6c - 4)
descriptor = read32(locator + 12)
assert pe.get_string_at_rva(descriptor - base_address + 8) == b'.?AVContentProvider@RBX@@'
assert read32(0x974d74) == 0
original, _, _ = match.target('2008-06', '0045ead0')
assert struct.pack('<I', 0x974d74) in original and struct.pack('<I', 0x96eff4) in original
paths = [base / 'native-classes/CRobloxWndFinishAttach.cpp', base / 'native-classes/GuiContentProviderState.cpp',
         base / 'native-headers/CRobloxView.h', base / 'native-headers/v8datamodel/DataModel.h',
         base / 'native-headers/util/NativeContentProvider.h', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'check': run.stdout,
           'original': {'address': '0045ead0', 'content_provider_global': '00974d74',
                        'window_current_global': '0096eff4', 'provider_rtti': '.?AVContentProvider@RBX@@'},
           'scope': 'Inactive semantic draft, not byte exact. Global ownership, full call bindings, vtable and runtime unverified.'}
path = root / 'work/2008-06/native-window-finish-attach.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
print(path)
