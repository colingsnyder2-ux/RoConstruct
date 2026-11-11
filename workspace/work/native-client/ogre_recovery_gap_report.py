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
CENSUS = ROOT / 'work/native-client/ogre-native-full-census-current/manifest.json'


def native_emitted_exact_addresses():
    """Every uniquely reference-proved body emitted by Ogre-scope native TUs."""
    if not CENSUS.is_file():
        return None
    manifest = json.loads(CENSUS.read_text())
    # ``candidates`` contains byte-only aliases.  ``addr`` is written only
    # after identity plus every relocation/data reference passes.
    return {symbol['addr'] for family in manifest.get('families', [])
            for symbol in family.get('symbols', [])
            if symbol.get('status') == 'inactive_exact' and isinstance(symbol.get('addr'), str)}


def native_exact_addresses(registry):
    """Subset with an Ogre registry identity, used only for root queue lanes."""
    emitted = native_emitted_exact_addresses()
    return None if emitted is None else emitted & set(registry)


def native_census(registry, exact=None):
    """Serializable full-TU proof metrics."""
    roots = native_exact_addresses(registry) if exact is None else exact
    emitted = native_emitted_exact_addresses()
    if roots is None or emitted is None:
        return {'addresses': None, 'bytes': None, 'proved_name_addresses': None,
                'proved_name_bytes': None, 'placeholder_addresses': None, 'placeholder_bytes': None,
                'emitted_addresses': None, 'emitted_bytes': None, 'unclassified_emitted_addresses': None,
                'unclassified_emitted_bytes': None}
    from roc import match
    proved = {address for address in roots if not registry[address].get('placeholder')}
    placeholders = roots - proved
    unclassified = emitted - roots
    size = lambda addresses: sum(len(match.target('2008-06', address)[0]) for address in addresses)
    return {'addresses': len(roots), 'bytes': size(roots), 'proved_name_addresses': len(proved),
            'proved_name_bytes': size(proved), 'placeholder_addresses': len(placeholders),
            'placeholder_bytes': size(placeholders), 'emitted_addresses': len(emitted),
            'emitted_bytes': size(emitted), 'unclassified_emitted_addresses': len(unclassified),
            'unclassified_emitted_bytes': size(unclassified)}


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
