"""Check generated diagnostic headers against current native inputs without writes."""
import hashlib
from pathlib import Path

root = Path(__file__).resolve().parents[3]
native = root / 'rebuild/2008-06/native-headers/v8datamodel'
generated = root / 'rebuild/2008-06/out/native-layouts/workspace-model-vector-include/v8datamodel'
sha = lambda b: hashlib.sha256(b).hexdigest()
good = True
for name in ('ModelInstance.h', 'Workspace.h'):
    source = (native / name).read_text()
    if name == 'Workspace.h':
        marker = 'RBXASSERT(currentCommand.get());'
        assert source.count(marker) == 1
        source = source.replace(marker, '', 1)
    expected = source.encode()
    path = generated / name
    actual = path.read_text().encode() if path.exists() else b''
    same = expected == actual
    good &= same
    print(f'{name}: {"OK" if same else "STALE"} expected={sha(expected)} actual={sha(actual)}')
raise SystemExit(0 if good else 1)
