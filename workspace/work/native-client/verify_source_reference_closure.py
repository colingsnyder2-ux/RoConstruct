"""Reuse frozen native objects for bounded identity/reference closure. Never publish."""
import argparse
import json
from pathlib import Path
import subprocess
import sys
import uuid

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import native_bulk as bulk


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('evidence_list', type=Path)
    parser.add_argument('--rounds', type=int, default=6, choices=range(1, 13))
    parser.add_argument('--refresh-run', type=Path,
                        help='reuse fresh runner objects for the same source/profile; retain every proof gate')
    args = parser.parse_args()
    output_dir = args.manifest.parent / ('closure-' + uuid.uuid4().hex[:8])
    output_dir.mkdir()
    print('Output: ' + str(output_dir), flush=True)
    manifest = json.loads(args.manifest.read_text())
    if args.refresh_run:
        results = args.refresh_run / 'results.json'
        fresh = {}
        for job in json.loads(results.read_text()):
            key = (Path(job['source']).resolve(), json.dumps(job.get('native_flags'), sort_keys=True))
            if key in fresh or job.get('status') != 'complete' or job.get('compiler_exit') != 0:
                raise ValueError('Fresh run has duplicate or unsuccessful source/profile: ' + str(key))
            fresh[key] = job
        for family in manifest['families']:
            family['jobs'] = [fresh[(Path(job['source']).resolve(),
                json.dumps(job.get('native_flags'), sort_keys=True))] for job in family['jobs']]
        manifest['refresh_results'] = {'path': str(results.resolve()), 'sha256': bulk.sha(results)}
    evidence = json.loads(args.evidence_list.read_text())
    targets = bulk.Targets('2008-06')
    checked = {}
    for family in manifest['families']:
        for job in family['jobs']:
            checked.update(job.get('dependencies', {}))
            checked[job['object']] = job['object_sha256']
            checked[job['source']] = job['source_sha256']
    stale = [p for p, digest in checked.items() if bulk.sha(p) != digest]
    if stale:
        raise ValueError('Frozen batch inputs changed: ' + ', '.join(stale))
    previous = None
    for turn in range(args.rounds):
        names, bindings, blockers, inputs = bulk.seed_evidence(ROOT, evidence, strict_conflicts=False)
        exact = set()
        for family in manifest['families']:
            family['symbols'] = []
            family['inputs'] = inputs
            for job in family['jobs']:
                family['symbols'].extend(bulk.harvest(Path(job['object']).read_bytes(), targets, names, bindings))
            exact.update(row['addr'] for row in family['symbols'] if row['status'] == 'inactive_exact')
        output = output_dir / ('closure-round-%02d.json' % (turn + 1))
        output.write_text(json.dumps(manifest, indent=1))
        print(json.dumps({'round': turn + 1, 'exact_addresses': len(exact),
                          'evidence_receipts': len(evidence), 'blockers': len(blockers)}), flush=True)
        fingerprint = (exact, bulk.digest(sorted(bindings.items())))
        if fingerprint == previous:
            break
        previous = fingerprint
        receipt = output.with_name(output.stem + '-bindings.json')
        known = output.with_name(output.stem + '-known.json')
        known.write_text(json.dumps({'rows': [{'symbol': name, 'address': address}
            for name, address in bindings.items() if address and not name.startswith('$')]}))
        subprocess.run([sys.executable, str(ROOT / 'work/native-client/batch_reference_bind.py'),
                        str(output), '--out', str(receipt), '--known', str(known),
                        '--jobs', '1'], check=True, cwd=ROOT)
        evidence.append(receipt.resolve().relative_to(ROOT).as_posix())
    (output_dir / 'closure-evidence.json').write_text(json.dumps(evidence, indent=1))
    if any(bulk.sha(p) != digest for p, digest in checked.items()):
        raise ValueError('Frozen inputs changed during closure; results are historical only')


if __name__ == '__main__':
    main()
