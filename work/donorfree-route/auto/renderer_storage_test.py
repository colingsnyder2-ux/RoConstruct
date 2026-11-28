"""Check that converted renderer globals use their own initialized native storage."""
from pathlib import Path
import pefile
import re
import struct
import sys
root = Path(__file__).resolve().parents[1]
exe = Path(sys.argv[1] if len(sys.argv) > 1 else root / 'run/RobloxQT.exe')
rows = {}
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    fields = line.split()
    if len(fields) >= 4 and re.fullmatch(r'[0-9a-f]{8}', fields[2], re.I):
        rows[fields[1]] = int(fields[2], 16)
pe = pefile.PE(str(exe), fast_load=True)
checks = [
    ('?cylinderAlongX@AdornRbxGfx@RBX@@UAEXMMABVColor4@G3D@@0@Z', 0xb8, '?rocAdornCylinderMesh@@3VMeshPtr@Ogre@@A', 4),
    ('?explosion@AdornRbxGfx@RBX@@UAEXABVSphere@G3D@@ABVColor4@4@1@Z', 0xaaa, '?rocExplosionMaterial@@3VMaterialPtr@Ogre@@A', 0),
]
failed = False
for fn, offset, target, addend in checks:
    value = struct.unpack('<I', pe.get_data(rows[fn] + offset - pe.OPTIONAL_HEADER.ImageBase, 4))[0]
    expected = rows[target] + addend
    ok = value == expected
    print('PASS' if ok else 'FAIL', fn.split('@')[0], hex(value), 'expected', hex(expected))
    failed |= not ok
sys.exit(1 if failed else 0)
