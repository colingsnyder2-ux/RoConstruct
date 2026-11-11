"""Emit only source-backed 2008 Ogre-layer name facts from the canonical registry."""
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
SCOPE = ('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew', 'RBX::Render', 'RBX::RenderBase')


def main():
    from roc import match
    from native_conversion_queue import owner as symbol_owner, undecorate
    source = ROOT / 'src/2008-06'
    all_rows = json.loads((ROOT / 'work/2008-06/identity-registry.json').read_text())
    rescues = json.loads((ROOT / 'work/native-client/claude-identity-rescue-bound.json').read_text())
    rescue_names = {}
    for rescue in rescues:
        passing = rescue.get('passing', [])
        if rescue.get('rescued') and len(passing) == 1:
            rescue_names.setdefault(passing[0], set()).add(rescue['symbol'])
    replay_names = {}
    for report in (ROOT / 'work/native-client/ogre/batches').glob('*/link/ogre_convert.json'):
        for address, result in json.loads(report.read_text()).items():
            symbol = result.get('symbol', '')
            if (result.get('status') == 'renamed' and result.get('name_source') == 'lib'
                    and symbol and not symbol.startswith('roc_fn_')):
                replay_names.setdefault(address, set()).add(symbol)
    template_names = {row['addr']: row['symbol'] for row in
                      json.loads((ROOT / 'work/native-client/viewnew-template-existing.json').read_text()).get('rows', [])
                      if row.get('status') == 'inactive_exact'}
    local_rescue = {}
    for row in json.loads((ROOT / 'work/native-client/ogre-viewnew-rescue.json').read_text()):
        passing = row.get('passing', [])
        if row.get('rescued') and len(passing) == 1:
            local_rescue.setdefault(passing[0], set()).add(row['symbol'])
    methods = {}
    for cls in json.loads((ROOT / 'work/native-client/ogre-conversion-queue-v10.json').read_text()).get('classes', []):
        if cls.get('owner', '').startswith(SCOPE):
            methods.update({method['addr']: cls['owner'] for method in cls.get('methods', [])})
    rows = {}
    for address, fact in match._functions('2008-06').items():
        if fact.get('kind') != 'code' or not (source / (address + '.cpp')).is_file():
            continue
        owner = methods.get(address)
        if not owner and not fact.get('unit', '').startswith(SCOPE):
            continue
        row = all_rows.get(address)
        if not row:
            continue
        rows[address] = {key: row.get(key) for key in
                         ('name', 'owner_class', 'signature', 'name_source', 'evidence', 'placeholder')}
        rescued = rescue_names.get(address, set())
        if rows[address]['placeholder'] and len(rescued) == 1:
            rows[address].update(name=next(iter(rescued)), name_source='identity-rescue', placeholder=False,
                                 evidence=[{'kind': 'unique-body-rescue'}])
        replay = replay_names.get(address, set())
        if rows[address]['placeholder'] and len(replay) == 1:
            rows[address].update(name=next(iter(replay)), name_source='upstream-replay', placeholder=False,
                                 evidence=[{'kind': 'byte-proved-vendor-replay'}])
        if rows[address]['placeholder'] and address in template_names:
            rows[address].update(name=template_names[address], name_source='native-template-exact', placeholder=False,
                                 evidence=[{'kind': 'existing-native-template-exact'}])
        rescued_local = local_rescue.get(address, set())
        if rows[address]['placeholder'] and len(rescued_local) == 1:
            rows[address].update(name=next(iter(rescued_local)), name_source='native-reference-rescue', placeholder=False,
                                 evidence=[{'kind': 'native-reference-rescue'}])
        # Folded addresses can have many symbols/owners.  The selected symbol
        # alone determines its declaration; never borrow an address peer's ABI.
        if not rows[address]['placeholder']:
            symbol = rows[address]['name']
            rows[address]['owner_class'] = symbol_owner(symbol) or None
            signature = undecorate(symbol)
            rows[address]['signature'] = signature if signature != symbol else None
        elif owner:
            rows[address]['owner_candidate'] = owner
    output = ROOT / 'work/native-client/ogre-names-registry.json'
    output.write_text(json.dumps(dict(sorted(rows.items())), indent=1, sort_keys=True) + '\n')
    print(json.dumps({'total': len(rows), 'proved': sum(not row['placeholder'] for row in rows.values()),
                      'placeholder': sum(row['placeholder'] for row in rows.values()),
                      'with_owner': sum(bool(row['owner_class']) for row in rows.values())}, sort_keys=True))


if __name__ == '__main__':
    main()
