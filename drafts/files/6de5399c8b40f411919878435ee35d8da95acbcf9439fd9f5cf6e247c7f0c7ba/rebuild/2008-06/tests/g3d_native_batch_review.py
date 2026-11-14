"""Prepare native call checks from explicitly reviewed target identities.

Output is a review manifest, not proof. The native runner still checks source
freshness, bytes, data, direct bindings and imports before indexing.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL
from capstone.x86 import X86_OP_IMM, X86_OP_MEM
import native_check_runner as runner


def prepare(analysis, identities):
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    imports = runner.import_evidence()[0]
    jobs, unresolved = [], []
    for result in analysis:
        if result.get('status') != 'complete':
            unresolved.append({'source': result.get('source'), 'reason': result.get('error', 'compile failed')})
            continue
        raw = Path(result['object']).read_bytes()
        sections, symbols, definitions, _ = runner.match._coff_data_index(raw)
        checks = []
        for row in result['checks']:
            if row.get('status') != 'exact':
                unresolved.append({'address': row['addr'], 'reason': row.get('status', 'missing'),
                                   'metrics': row.get('metrics')})
                continue
            address = int(row['addr'], 16)
            target, _, _ = runner.match.target('2008-06', row['addr'])
            start, section = definitions[row['symbol']]
            table = sections[section]
            refs = {}
            for i in range(table[7]):
                offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
                refs[offset - start] = (symbols[index][0], kind)
            calls = []
            for ins in decoder.disasm(target, address):
                if not ins.group(CS_GRP_CALL):
                    continue
                off = ins.address - address
                operand = ins.operands[0]
                ref = refs.get(off + 1)
                item = None
                if operand.type == X86_OP_IMM and ref and ref[1] == 20:
                    dest = f'{operand.imm & 0xffffffff:08x}'
                    if dest in identities.get(ref[0], []):
                        item = {'offset': off, 'target': dest, 'symbol': ref[0], 'kind': 'direct'}
                elif operand.type == X86_OP_MEM and not operand.mem.base and not operand.mem.index:
                    dest = operand.mem.disp & 0xffffffff
                    ref = refs.get(off + 2)
                    if ref and ref[1] == 6 and dest in imports:
                        item = {'offset': off, 'target': f'{dest:08x}', 'symbol': ref[0],
                                'kind': 'import', 'import': imports[dest]}
                if item:
                    calls.append(item)
                else:
                    unresolved.append({'address': row['addr'], 'offset': off,
                                       'instruction': ins.mnemonic + ' ' + ins.op_str,
                                       'candidate': ref[0] if ref else None})
            checks.append({'addr': row['addr'], 'symbol': row['symbol'], 'calls': calls})
        jobs.append({'source': result['source'], 'checks': checks})
    return {'jobs': jobs}, unresolved


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    base = Path(__file__).resolve().parent
    parser.add_argument('analysis', type=Path, nargs='?', default=base / 'g3d_native_batch_plan.json')
    parser.add_argument('identities', type=Path, nargs='?', default=base / 'g3d_native_batch_identities.json',
                        help='reviewed symbol -> list of original addresses')
    parser.add_argument('manifest', type=Path, nargs='?', default=runner.ROOT / 'work/2008-06/shared-layouts/g3d-batch-review.json')
    parser.add_argument('--run', action='store_true', help='compile input manifest, verify and index passing checks')
    parser.add_argument('--prepare-only', action='store_true', help='read prior analysis and write review manifest only')
    args = parser.parse_args()
    execute = args.run or (args.analysis == base / 'g3d_native_batch_plan.json' and not args.prepare_only)
    check_runner = Path(__file__).with_name('native_check_runner.py')

    def invoke(*arguments):
        done = subprocess.run([sys.executable, str(check_runner), *map(str, arguments)],
                              capture_output=True, text=True)
        print(done.stdout, end='')
        if done.returncode:
            raise RuntimeError(done.stderr or 'native checker failed')
        for line in reversed(done.stdout.splitlines()):
            try:
                value = json.loads(line)
            except ValueError:
                continue
            if isinstance(value, dict) and value.get('results'):
                return Path(value['results'])
        raise RuntimeError('native checker did not report results')

    analysis = invoke('run', args.analysis, '--workers', '3') if execute else args.analysis
    manifest, missing = prepare(json.loads(analysis.read_text()), json.loads(args.identities.read_text()))
    args.manifest.write_text(json.dumps(manifest, indent=2) + '\n')
    indexed = []
    if execute:
        checked = invoke('analyze', analysis.parent, '--manifest', args.manifest)
        passing = json.loads(checked.read_text())
        for job, result in zip(manifest['jobs'], passing):
            if job['source'] != result['source']:
                raise RuntimeError('source order changed during review')
            passed = {row['addr'] for row in result['checks']
                      if row.get('status') == 'exact' and not row.get('data_errors')
                      and row.get('call_identity', {}).get('passed')}
            for row in result['checks']:
                if row['addr'] not in passed and row['addr'] not in {x.get('address') for x in missing}:
                    missing.append({'address': row['addr'], 'reason': 'data, call, or byte verification failed'})
            checks = [row for row in job['checks'] if row['addr'] in passed]
            if not checks:
                continue
            source_sha = runner.sha(Path(result['source']))
            object_sha = runner.sha(Path(result['object']))
            key = hashlib.sha256(json.dumps({'source': result['source'], 'source_sha256': source_sha,
                'object_sha256': object_sha, 'checks': checks,
                'runner': runner.sha(check_runner), 'original': runner.sha(runner.ROOT / 'clients/2008-06/Roblox.exe')},
                sort_keys=True).encode()).hexdigest()[:24]
            isolated = args.manifest.with_name(args.manifest.stem + '-' + key + '.json')
            isolated.write_text(json.dumps({'jobs': [{'source': job['source'], 'checks': checks}]}, indent=2) + '\n')
            receipt = runner.ROOT / 'work/2008-06/shared-layouts' / ('g3d-batch-' + key + '.json')
            if receipt.exists():
                previous = json.loads(receipt.read_text())
                if (previous.get('source_sha256') != source_sha or
                    previous.get('object_sha256') != object_sha or
                    {row['address'] for row in previous.get('checks', []) if row.get('exact')} != passed):
                    raise RuntimeError('existing receipt does not match this batch: ' + str(receipt))
            else:
                invoke('analyze', analysis.parent, '--manifest', isolated, '--require-proof', '--index-output', receipt)
            indexed.extend(row['addr'] for row in checks)
    report = {'manifest': str(args.manifest), 'indexed': indexed, 'unresolved': missing}
    report_path = args.manifest.with_name(args.manifest.stem + '-report.json')
    report_path.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({'indexed': indexed, 'review_functions': sorted({x.get('address', x.get('source')) for x in missing}),
                      'report': str(report_path)}, indent=2))


if __name__ == '__main__':
    main()
