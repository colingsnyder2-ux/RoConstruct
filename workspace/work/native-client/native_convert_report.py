"""Aggregate deterministic native recovery evidence without claiming integration."""
import argparse
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def load(path):
    return json.loads(path.read_text()) if path.is_file() else {}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--gate', type=Path, required=True)
    ap.add_argument('--sweep', type=Path, required=True)
    ap.add_argument('--donor', type=Path,
                    help='optional donor-name candidate queue; reported separately from native evidence')
    ap.add_argument('--native-bulk', action='append', type=Path, default=[],
                    help='additional native-bulk manifests containing real native source proofs')
    ap.add_argument('--link-probe', type=Path,
                    help='optional honest linkprobe JSON; records unresolved count only')
    ap.add_argument('--link-providers', type=Path,
                    help='optional provider discovery receipt; reported as blocked evidence')
    ap.add_argument('--profile-sweep', type=Path,
                    help='optional compiler-profile sweep directory')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    generated, proved, profile_proved = {}, {}, {}
    attempts, compile_blockers = {}, Counter()
    # Promotion receipts live beside isolated probes too.  Discover every
    # task-local receipt so a real native body is counted without a manual
    # report edit or a directory-specific convention.
    for promotion in ROOT.glob('work/native-client/**/promotion.json'):
        row = load(promotion)
        if row.get('applied'):
            for address in row.get('requested', []):
                generated[address] = row['destination']
    manifests = list(ROOT.glob('work/native-client/native-convert-smoke/**/manifest.json'))
    # Full native-bulk sweeps are the authoritative existing-provider baseline.
    # Do not undercount them merely because they were not conversion probes.
    manifests += list(ROOT.glob('work/native-client/identity-bulk/**/manifest.json'))
    manifests += args.native_bulk
    manifests = list(dict.fromkeys(manifests))
    for manifest in manifests:
        row = load(manifest)
        for family in row.get('families', []):
            native_source = any('rebuild\\2008-06\\native-classes\\' in key.lower()
                                for key in family.get('inputs', {}))
            if native_source:
                for symbol in family.get('symbols', []):
                    if symbol.get('status') == 'inactive_exact' and symbol.get('addr'):
                        proved[symbol['addr']] = symbol['symbol']
    # Keep newest probe outcome per address.  These are conversion diagnostics,
    # separate from native-source proof and never integration claims.
    result_paths = ROOT.glob('work/native-client/**/result.json')
    for result_path in sorted(result_paths, key=lambda path: path.stat().st_mtime):
        result = load(result_path)
        compile_blockers.update(result.get('compile_blockers', []))
        batches = [(result.get('owner'), result.get('requested', []))]
        batches += [(batch.get('owner'), batch.get('requested', []))
                    for batch in result.get('results', [])]
        for owner, rows in batches:
            for row in rows:
                attempts[row['addr']] = {'status': row.get('status', 'missing'),
                                         'symbol': row.get('symbol'),
                                         'owner': owner,
                                         'result': str(result_path.relative_to(ROOT)).replace('\\', '/')}
                if owner == 'existing-native-profile' and row.get('status') == 'inactive_exact':
                    profile_proved[row['addr']] = row.get('symbol')
    gate = load(args.gate)
    sweep = load(args.sweep)
    closure = load(args.closure).get('summary', {})
    donor = load(args.donor) if args.donor else {}
    donor_rows = donor.get('rows', donor.get('functions', []))
    link_probe = load(args.link_probe) if args.link_probe else {}
    link_history = load(ROOT / 'work/native-client/link/batch-history.json')
    link_providers = load(args.link_providers) if args.link_providers else {}
    provider_selected = link_providers.get('selected', [])
    provider_blocked = link_providers.get('blocked', [])
    provider_blocked_sources = sorted({name for row in provider_blocked for name in row.get('providers', [])})
    profile_rows = []
    if args.profile_sweep and args.profile_sweep.is_dir():
        for receipt in sorted(args.profile_sweep.glob('*/profile.json')):
            row = load(receipt)
            gains = [{'profile': name, 'addresses': data.get('gained_addresses', []),
                      'symbols': data.get('gained_symbols', [])}
                     for name, data in row.get('profiles', {}).items() if data.get('gained_addresses')]
            if gains:
                profile_rows.append({'source': row.get('source'), 'verdict': row.get('verdict'),
                                     'best': row.get('best'), 'profiles': gains})
    report = {
        'scope': 'local native-source recovery evidence only; no client selection, link, or runtime claim',
        'generated': {'distinct_addresses': len(generated), 'providers': generated},
        'byte_proved': {
            'distinct_addresses': len(set(proved) | set(profile_proved)),
            'native_source_distinct_addresses': len(proved),
            'isolated_existing_source_profile_distinct_addresses': len(profile_proved),
            'symbols': dict(proved, **profile_proved),
        },
        'blocked': {
            'gate_rows': sum(row.get('status', '').startswith('blocked-') for row in gate.get('rows', [])),
            'sweep_requested': sweep.get('requested_blocked', 0),
            'sweep_rows': sweep.get('rows', []),
            'attempted': {
                'distinct_addresses': len(attempts),
                'by_status': {status: sum(row['status'] == status for row in attempts.values())
                              for status in sorted({row['status'] for row in attempts.values()})},
                'rows': attempts,
            },
            'compile_blockers': dict(sorted(compile_blockers.items())),
        },
        'linked': {'measured': bool(args.link_probe),
                   'selected_providers': link_probe.get('selected_providers') if args.link_probe else None,
                   'client_link': link_probe.get('client_link') if args.link_probe else None,
                   'unresolved_symbols': len(link_probe.get('unresolved', [])) if args.link_probe else None,
                   'duplicate_symbols': len(link_probe.get('duplicates', [])) if args.link_probe else None,
                   'provider_candidates_compiled': len(link_providers['compiled_sources']) if 'compiled_sources' in link_providers else None,
                   'provider_symbols_found': len(link_providers['resolved']) if 'resolved' in link_providers else sum(len(row.get('symbols', [])) for row in provider_selected),
                   'provider_compile_failures': len(link_providers['compile_failures']) if 'compile_failures' in link_providers else None,
                   'provider_nonproviders': len(link_providers['compiled_nonproviders']) if 'compiled_nonproviders' in link_providers else None,
                   'provider_blocked_sources': len(link_providers.get('blocked_sources', {})) if 'blocked_sources' in link_providers else len(provider_blocked_sources),
                   'provider_blocked_rows': len(provider_blocked) if args.link_providers else None,
                   'batches': link_history.get('batches', [])},
        'runtime_gated': {'measured': False, 'real_ogre_frame': None},
        'profile_sweep': {'receipts': len(list(args.profile_sweep.glob('*/profile.json'))) if args.profile_sweep else 0,
                          'supersets': [row for row in profile_rows if row['verdict'] == 'superset'],
                          'splits': [row for row in profile_rows if row['verdict'] == 'split'],
                          'note': 'missing symbols means an older receipt needs a deterministic re-sweep before any split'},
        'donor_candidates': {
            'rows': len(donor_rows),
            'by_status': donor.get('summary', {}),
            'compile_candidates': sum(row.get('verdict') == 'new' and row.get('shared_unique_strings', 0) >= 2
                                      for row in donor_rows),
            'scope': donor.get('scope', ''),
        },
        'identity': closure,
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=1) + '\n')
    print(json.dumps({key: report[key] for key in ('generated', 'byte_proved', 'linked', 'runtime_gated')}))


if __name__ == '__main__':
    main()
