"""Analog objects compiled from raw rbxgs (2007) headers carry their own vtable/RTTI COMDATs with the 2007 slot order; the linker may
keep those instead of the engine's (2008-patched) copies.  Drop every ??_7 / ??_R definition an engine object also defines.
python strip_analog_vtables.py [folder]"""
import sys
from pathlib import Path
sys.path.insert(0, '.')
from roc import rebuild
from roc.rebuild import coff_externals
folder = Path(sys.argv[1] if len(sys.argv) > 1 else 'work/native-client/shortcut/closure/renamed')
engine = set()
for o in list(Path('rebuild/2008-06/out/RbxgsApp/linked').glob('*.obj')) + list(Path('work/native-client/obj-engine-abi').glob('*.obj')):
    engine |= {s for s, d in coff_externals(o.read_bytes()).items() if d and s.startswith(('??_7', '??_R'))}
n = 0
for o in sorted(folder.glob('*.obj')):
    raw = o.read_bytes()
    drop = {s for s, d in coff_externals(raw).items() if d and s in engine}
    if drop:
        o.write_bytes(rebuild.strip_symbols(raw, drop=drop)); n += 1
print('objects stripped', n, 'engine vtable/RTTI symbols', len(engine))
