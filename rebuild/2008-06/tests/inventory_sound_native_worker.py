"""Inventory isolated sound COFF symbols; classifications are heuristic, not ABI proof."""
import hashlib
import json
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import rebuild

folder = root / 'rebuild/2008-06/out/native-layouts/sound-header-worker'
names = ('PlayerNativeSound', 'PlayerNativeSoundService', 'PlayerNativeSoundGC',
         'PlayerNativeSoundChannel', 'PlayerNativeSoundReflection',
         'PlayerNativeReverb', 'PlayerNativeSoundStats')
objects = {}
providers = {}
references = {}
for name in names:
    path = folder / (name + '.obj')
    data = path.read_bytes()
    symbols = rebuild.coff_externals(data)
    definitions = sorted(s for s, defined in symbols.items() if defined)
    undefined = sorted(s for s, defined in symbols.items() if not defined)
    objects[name] = {'path': str(path.relative_to(root)), 'sha256': hashlib.sha256(data).hexdigest(),
                     'definitions': definitions, 'undefined': undefined}
    for s in definitions:
        providers.setdefault(s, []).append(name)
    for s in undefined:
        references.setdefault(s, []).append(name)

def category(symbol):
    if 'FMOD' in symbol:
        return 'external_fmod'
    if any(x in symbol for x in ('@RBX@@', '@RBX@', '@G3D@@', '@RakNet@@')):
        return 'likely_engine_or_library'
    return 'external_or_unknown'

unresolved = {s: {'referenced_by': refs, 'category': category(s)}
              for s, refs in sorted(references.items()) if s not in providers}
receipt = {'scope': 'Static COFF name inventory only; no link, runtime, ABI or complete transitive closure proof. Categories are heuristic.',
           'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
           'objects': objects, 'providers': providers, 'unresolved': unresolved}
target = root / 'work/2008-06/shared-layouts/sound-coff-inventory-worker.json'
target.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
print(f'{len(objects)} objects, {len(providers)} unique definitions, {len(unresolved)} external names: {target}')
