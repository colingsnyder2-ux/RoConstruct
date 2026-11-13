"""Check the linked Ogre subentity bounds method and its original references."""
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, native_bulk  # noqa: E402


def main():
    receipt = 'work/native-client/ogre-subentity-bounds-references.json'
    rows = json.loads((ROOT / receipt).read_text())['rows']
    targets = {'00685490', '007dde4e', '00801580'}
    assert {row['address'] for row in rows} == targets
    _, bindings, blockers, _ = native_bulk.seed_evidence(ROOT, [receipt])
    assert not blockers, blockers
    original = native_bulk.Targets('2008-06', selected=list(targets))
    out = ROOT / 'rebuild/2008-06/out'
    obj = out / 'Ogre/linked/AppUnit67C_2008SubEntity.obj'
    raw = obj.read_bytes()
    functions = {name: (body, relocs) for name, body, relocs in match.coff_functions(raw)}
    lines = (out / 'tests/ogre_link/ogre_link.map').read_text(errors='replace').splitlines()
    for row in rows:
        name, addr = row['symbol'], row['address']
        assert any(name in line and 'AppUnit67C_2008SubEntity.obj' in line for line in lines), addr
        body, relocs = functions[name]
        target, original_relocs, _ = match.target('2008-06', addr)
        assert set(original_relocs) <= set(relocs) and match.exact_match(target, original_relocs, body, relocs), addr
        _, errors = native_bulk.audit_references(raw, name, body, target, original_relocs,
                                                 int(addr, 16), original, bindings)
        assert not errors, (addr, errors)
    print('PASS linked Ogre subentity bounds and original references')


if __name__ == '__main__':
    main()
