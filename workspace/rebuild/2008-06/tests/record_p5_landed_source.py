"""Pin original Landed/Running identities, timer constants and transition table."""
import hashlib
import json
import pathlib
import struct
import subprocess
import sys

import pefile

root = pathlib.Path(__file__).resolve().parents[3]
original = root / 'work/2008-06/original-p4-reference/Roblox.exe'
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
assert sha(original) == '2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
pe = pefile.PE(str(original))
def data(address, size):
    return pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, size)
def uint(address):
    return struct.unpack('<I', data(address, 4))[0]
def typename(vtable):
    locator = uint(vtable - 4)
    descriptor = uint(locator + 12)
    return data(descriptor + 8, 100).split(b'\0')[0].decode('ascii')
assert typename(0x84ac9c) == '.?AVLanded@HUMAN@RBX@@'
assert typename(0x84cc94) == '.?AVRunning@HUMAN@RBX@@'
timers = [struct.unpack('<f', data(a, 4))[0] for a in (0x84acc0, 0x84cc84)]
assert abs(timers[0] - .45) < 1e-6 and abs(timers[1] - .25) < 1e-6
table = [list(struct.unpack('<18I', data(0x84a92c + state * 72, 72))) for state in (3, 5, 6)]
predicates = list(struct.unpack('<17I', data(0x64476c, 68)))
assert table[0][11] == 5 and predicates[11] == 0x64470f  # floor present
assert table[1][10] == 3 and predicates[10] == 0x64471a  # floor absent
assert table[1][15] == 6 and predicates[15] == 0x64473e  # timer expired
out = root / 'work/2008-06' / sys.argv[1]
out.mkdir(exist_ok=False)
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'original_sha256': sha(original), 'observer_sha256': sha(pathlib.Path(__file__)),
           'landed_rtti': typename(0x84ac9c), 'running_rtti': typename(0x84cc94),
           'landed_seconds': timers[0], 'running_seconds': timers[1],
           'states_3_5_6': table, 'predicate_addresses': [hex(v) for v in predicates],
           'scope': 'Static RTTI, constructors and table; transition order and runtime parity remain open.'}
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('original landed RTTI, timers and transition entries PASS')
