"""Preserve the current native demo and its visual evidence without rebuilding it."""
import hashlib
import json
from pathlib import Path
import shutil

ROOT = Path(__file__).resolve().parents[3]
source = ROOT / 'rebuild/2008-06/out/tests/ogre_demo'
target = ROOT / 'work/wasm-castle/native-reference'
if (target / 'manifest.json').exists():
    raise SystemExit('Reference already frozen; refusing to replace it.')
target.mkdir(parents=True, exist_ok=True)
files = [source / name for name in (
    'ogre_demo.exe', 'ogre_demo.exe.manifest', 'rgmain.dll', 'rggl.dll',
    'report.json', 'castle_island.png', 'castle_night.png', 'castle_dawn.png',
    'castle_dusk.png', 'castle_sun.png', 'castle_moon.png')]
files += list((source / 'assets').glob('*'))
files += [ROOT / 'rebuild/2008-06/tests' / name for name in ('ogre_demo.cpp', 'run_ogre_demo.py')]
manifest = {}
for path in files:
    relative = path.relative_to(source) if path.is_relative_to(source) else Path('source') / path.name
    destination = target / relative
    destination.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(path, destination)
    manifest[str(relative)] = hashlib.sha256(destination.read_bytes()).hexdigest()
(target / 'manifest.json').write_text(json.dumps(manifest, indent=2))
print(f'Frozen {len(manifest)} files at {target}')
