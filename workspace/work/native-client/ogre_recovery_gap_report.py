"""Classify every source-backed Ogre address without conflating source and objects.

Input facts only: name registry, existing conversion queue, template byte gates,
and native-LLM attempts.  This report selects next automatic lanes; it never
writes native classes or headers.
"""
import collections
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
REGISTRY = ROOT / 'work/native-client/ogre-names-registry.json'
QUEUE = ROOT / 'work/native-client/ogre-conversion-queue-v10.json'
TEMPLATES = ROOT / 'work/native-client/viewnew-template-existing.json'
ATTEMPTS = ROOT / 'work/native-client/native-llm/attempts.jsonl'
OUT = ROOT / 'work/native-client/ogre-recovery-gap-report.json'
CENSUS = ROOT / 'work/native-client/ogre-native-full-census-20261110/manifest.json'


def native_exact_addresses(registry):
    """Current full-TU exact set, not historic source inventory or converter objects."""
    if not CENSUS.is_file():
        return None
    from roc import match
    manifest = json.loads(CENSUS.read_text())
    return {address for family in manifest.get('families', []) for symbol in family.get('symbols', [])
            if symbol.get('status') == 'inactive_exact' for address in symbol.get('candidates', [])
            if isinstance(address, str) and address in registry}


def native_census(registry, exact=None):
    """Serializable full-TU proof metrics."""
    exact = native_exact_addresses(registry) if exact is None else exact
    if exact is None:
        return {'addresses': None, 'bytes': None, 'proved_name_addresses': None,
                'proved_name_bytes': None, 'placeholder_addresses': None, 'placeholder_bytes': None}
    from roc import match
    proved = {address for address in exact if not registry[address].get('placeholder')}
    placeholders = exact - proved
    size = lambda addresses: sum(len(match.target('2008-06', address)[0]) for address in addresses)
    return {'addresses': len(exact), 'bytes': size(exact), 'proved_name_addresses': len(proved),
            'proved_name_bytes': size(proved), 'placeholder_addresses': len(placeholders),
            'placeholder_bytes': size(placeholders)}


def main():
    registry = json.loads(REGISTRY.read_text())
    queue = json.loads(QUEUE.read_text())['classes']
    by_pair = {(m['addr'], m['symbol']): (cl, m) for cl in queue for m in cl['methods']}
    exact_templates = {row['addr'] for row in json.loads(TEMPLATES.read_text()).get('rows', [])
                       if row.get('status') == 'inactive_exact'}
    native_exact = native_exact_addresses(registry)
    attempted = {json.loads(line)['addr'] for line in ATTEMPTS.read_text().splitlines()} if ATTEMPTS.is_file() else set()
    rows = []
    for address, fact in sorted(registry.items()):
        if native_exact and address in native_exact:
            rows.append({'addr': address, 'name': fact['name'], 'lane': 'native-byte-proved'})
            continue
        if fact.get('placeholder'):
            rows.append({'addr': address, 'lane': 'blocked-name-or-signature-proof'})
            continue
        pair = by_pair.get((address, fact['name']))
        if not pair:
            rows.append({'addr': address, 'lane': 'unmapped-to-conversion-queue', 'name': fact['name']})
            continue
        cls, method = pair
        row = {'addr': address, 'name': fact['name'], 'owner': cls['owner'], 'state': method['state'],
               'headers': method['headers'], 'native_providers': method['native_providers']}
        if address in exact_templates:
            row['lane'] = 'existing-native-template-byte-proved'
        elif method['state'] in ('existing-native', 'existing-emitted-exact', 'existing-emitted-address-exact'):
            row['lane'] = 'existing-native-needs-current-byte-audit'
        elif method['state'] != 'convert':
            row['lane'] = 'queue-state-' + method['state']
        elif len(method['headers']) != 1:
            row['lane'] = 'blocked-header-provider-count-%d' % len(method['headers'])
        elif len(method['native_providers']) != 1:
            row['lane'] = 'new-native-source-needed' if not method['native_providers'] else 'blocked-native-provider-count-%d' % len(method['native_providers'])
        elif address in attempted:
            row['lane'] = 'parked-after-llm-gate'
        else:
            row['lane'] = 'existing-destination-body-trial'
        rows.append(row)
    counts = collections.Counter(row['lane'] for row in rows)
    census = native_census(registry, native_exact)
    report = {'scope': 'source-backed requested Ogre prefixes', 'counts': dict(sorted(counts.items())), 'rows': rows,
              'separate_counts': {'proved_names': sum(not r.get('placeholder') for r in registry.values()),
                                  'placeholder_names': sum(r.get('placeholder') for r in registry.values()),
                                  'native_byte_proved': census,
                                  'converter_only_linkable_bytes': None,
                                  'runtime_gated': None}}
    OUT.write_text(json.dumps(report, indent=1) + '\n')
    print(json.dumps(report['counts'], sort_keys=True))


if __name__ == '__main__':
    main()
