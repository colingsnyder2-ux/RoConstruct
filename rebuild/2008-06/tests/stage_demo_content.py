"""Copy an owned period Content tree's required demo assets beside the player."""
import hashlib
import json
from pathlib import Path
import shutil
import sys

root = Path(__file__).resolve().parents[3]
source = Path(sys.argv[1]).resolve()
target = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/Content'
files = ['textures/SurfacesStrip.png', 'textures/Surfaces.png'] + ['sky/null_plainsky512_' + face + '.jpg' for face in ('bk', 'ft', 'lf', 'rt', 'up', 'dn')]
hashes = {}
for name in files:
    data = (source / name).read_bytes()
    destination = target / name
    destination.parent.mkdir(parents=True, exist_ok=True)
    if destination.exists():
        assert destination.read_bytes() == data, f'Preserve different existing asset: {destination}'
    else:
        shutil.copyfile(source / name, destination)
    hashes[name] = hashlib.sha256(data).hexdigest()
(target / 'demo-assets.json').write_text(json.dumps({'source': str(source), 'sha256': hashes}, indent=2) + '\n')
print('Staged original demo assets:', target)
