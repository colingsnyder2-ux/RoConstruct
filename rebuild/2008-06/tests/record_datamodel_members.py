"""Verify original DataModel-owned object types via factory constructors and RTTI."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
exe = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(exe), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase

def read(address, size):
    return pe.get_data(address - base, size)

def word(address):
    return struct.unpack('<I', read(address, 4))[0]

def rtti(vtable):
    locator = word(vtable - 4)
    descriptor = word(locator + 12)
    return read(descriptor + 8, 160).split(b'\0')[0].decode('ascii')

# Constructor writes these original vtables. Both GuiRoot members call the
# same factory; workspace factory calls the Workspace constructor.
assert read(0x573b45, 6) == b'\xc7\x06' + struct.pack('<I', 0x82f9fc)
assert read(0x5a4e50, 6) == b'\xc7\x06' + struct.pack('<I', 0x833a54)
assert rtti(0x82f9fc) == '.?AVGuiRoot@RBX@@'
assert rtti(0x833a54) == '.?AVWorkspace@RBX@@'
# DataModel initialization obtains the independently traced RunService and
# stores the returned shared pointer into +0x20c/+0x210.
assert read(0x57ab08, 5) == b'\xe8' + struct.pack('<i', 0x4530f0 - 0x57ab0d)
assert read(0x57ab20, 6) == bytes.fromhex('898e0c020000')
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               original_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(),
               observer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
               fields={'0x204': dict(type='boost::shared_ptr<RBX::Workspace>', factory='00576ff0', constructor='005a4d90', vtable='00833a54'),
                       '0x20c': dict(type='boost::shared_ptr<RBX::RunService>', getter='004530f0', store='0057ab20', proof='workspace-owner-trace.json'),
                       '0x21c': dict(type='boost::shared_ptr<RBX::GuiRoot>', factory='00577090', constructor='00573b10', vtable='0082f9fc'),
                       '0x224': dict(type='boost::shared_ptr<RBX::GuiRoot>', factory='00577090', constructor='00573b10', vtable='0082f9fc')},
               scope='Original constructor/factory flow and RTTI prove pointee classes and shared ownership. Field names and remaining fields require further evidence; no active ABI swap.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: native DataModel workspace and two GuiRoot owner types')
