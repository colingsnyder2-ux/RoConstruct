"""Verify SurfaceType property constructors use the Lua enum singleton."""
from pathlib import Path
import pefile
import re
import struct
import sys
root = Path(__file__).resolve().parents[1]
rows = {}
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    fields = line.split()
    if len(fields) >= 4 and re.fullmatch(r'[0-9a-f]{8}', fields[2], re.I):
        rows[fields[1]] = int(fields[2], 16)
caller = rows['func_005ed6c0'] + 0x30
target = rows['?doSingleton@?$EnumDesc@W4SurfaceType@RBX@@@Reflection@RBX@@CAAAV123@XZ']
pe = pefile.PE(str(root / 'run/RobloxQT.exe'), fast_load=True)
ins = pe.get_data(caller - pe.OPTIONAL_HEADER.ImageBase, 5)
if ins[0] != 0xe8:
    raise ValueError('expected direct call')
actual = caller + 5 + struct.unpack('<i', ins[1:])[0]
print('PASS' if actual == target else 'FAIL', hex(actual), 'expected', hex(target))
sys.exit(actual != target)
