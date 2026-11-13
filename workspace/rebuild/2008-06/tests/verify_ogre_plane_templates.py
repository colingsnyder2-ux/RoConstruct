"""Check full plane-template bodies, their catches, and smoke-selected references."""
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, native_bulk  # noqa: E402


def main():
    receipt = 'work/native-client/ogre-plane-template-references.json'
    evidence = json.loads((ROOT / receipt).read_text())
    functions = evidence['functions']
    assert {row['address'] for row in functions} == {'0067c890', '0067c9a0'}
    _, bindings, blockers, _ = native_bulk.seed_evidence(ROOT, [receipt])
    assert not blockers, blockers
    addresses = [a for row in functions for a in (row['address'], row['handler']['address'])]
    original = native_bulk.Targets('2008-06', selected=addresses)
    out = ROOT / 'rebuild/2008-06/out'
    raw = (out / 'Ogre/linked/OgreRbxSceneManager.obj').read_bytes()
    emitted = {name: (body, relocs) for name, body, relocs in match.coff_functions(raw)}
    _, _, definitions, _ = match._coff_data_index(raw)
    lines = (out / 'tests/ogre_link/ogre_link.map').read_text(errors='replace').splitlines()
    image_base, image = match._image('2008-06')
    image_relocs = match._base_relocs('2008-06')
    for row in functions:
        name, addr, size = row['symbol'], int(row['address'], 16), row['size']
        catch = row['catch']
        assert definitions[catch['symbol']][1] == definitions[name][1]
        assert definitions[catch['symbol']][0] - definitions[name][0] == int(catch['address'], 16) - addr
        for symbol in (name, catch['symbol'], row['handler']['symbol']):
            assert any(symbol in line and 'OgreRbxSceneManager.obj' in line for line in lines), symbol
        for symbol, va, length in ((name, addr, size),
                                   (row['handler']['symbol'], int(row['handler']['address'], 16), 10)):
            body, relocs = emitted[symbol]
            target = bytes(image[va - image_base:va - image_base + length])
            original_relocs = [r - va for r in image_relocs if va <= r and r + 4 <= va + length]
            assert set(original_relocs) <= set(relocs) and match.exact_match(target, original_relocs, body, relocs), symbol
            _, errors = native_bulk.audit_references(raw, symbol, body, target, original_relocs, va, original, bindings)
            assert not errors, (symbol, errors)
    print('PASS full Ogre plane templates and original references')


if __name__ == '__main__':
    main()
