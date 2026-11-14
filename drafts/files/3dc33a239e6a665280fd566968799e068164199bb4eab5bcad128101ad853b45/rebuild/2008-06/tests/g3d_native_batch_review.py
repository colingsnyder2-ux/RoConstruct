"""Check G3D native sources, and queue uncertain matches for review.

Run without arguments for G3D. For libpng discovery use --discover-only
--c-recipe libpng-1.2.5 --prefix Png5. Discovered identities remain review-only.
The native runner checks source freshness, bytes, data, direct bindings and
imports before indexing. Compiler variants are diagnostic, not proofs.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
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
                                   'metrics': row.get('metrics'),
                                   'contiguous_catch_comparison': row.get('contiguous_catch_comparison')})
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
    parser.add_argument('--no-variants', action='store_true', help='skip three bounded compiler-profile trials')
    parser.add_argument('--no-discovery', action='store_true', help='only run the explicitly listed plan')
    parser.add_argument('--discover-only', action='store_true', help='only run discovered review-only targets')
    parser.add_argument('--namespace', default='G3D')
    parser.add_argument('--prefix', default='G3D')
    parser.add_argument('--c-recipe', help='discover a C library recipe, e.g. libpng-1.2.5')
    parser.add_argument('--c-symbol-prefix', default='_png_')
    args = parser.parse_args()
    execute = args.run or (args.analysis == base / 'g3d_native_batch_plan.json' and not args.prepare_only)
    check_runner = Path(__file__).with_name('native_check_runner.py')

    def invoke(*arguments, env=None):
        done = subprocess.run([sys.executable, str(check_runner), *map(str, arguments)],
                              capture_output=True, text=True, env=env)
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

    manual = set()
    if execute:
        plan = json.loads(args.analysis.read_text(encoding='utf-8-sig'))
        if not args.no_discovery and (args.discover_only or args.analysis == base / 'g3d_native_batch_plan.json'):
            import native_target_discovery as discovery
            from roc.integration_site import inactive_code
            data = json.loads((runner.ROOT / 'docs/data/2008-06.json').read_text(encoding='utf-8'))
            inactive = inactive_code(runner.ROOT)
            found = (discovery.discover_c(data, args.c_recipe, args.c_symbol_prefix, args.prefix, inactive)
                     if args.c_recipe else discovery.discover(data, args.namespace, args.prefix, inactive, True))
            jobs = {} if args.discover_only else {
                str((runner.BASE / j['source']).resolve() if not Path(j['source']).is_absolute() else Path(j['source']).resolve()).casefold(): j
                for j in plan['jobs']}
            for job in found['jobs']:
                key = str(Path(job['source']).resolve()).casefold()
                if key not in jobs:
                    jobs[key] = job
                else:
                    present = {c['addr'].lower().removeprefix('0x').zfill(8) for c in jobs[key]['checks']}
                    jobs[key]['checks'].extend(c for c in job['checks'] if c['addr'] not in present)
            plan = {'jobs': list(jobs.values())}
            args.analysis = args.manifest.with_name(args.manifest.stem + '-expanded-plan.json')
            args.analysis.write_text(json.dumps(plan, indent=2) + '\n')
            print('Discovered', sum(len(j['checks']) for j in found['jobs']), 'review-only candidates', flush=True)
        manual = {(c['addr'].lower().removeprefix('0x').zfill(8), c['symbol'])
                  for job in plan['jobs'] for c in job.get('checks', []) if c.get('review_only')}
    analysis = invoke('run', args.analysis, '--workers', '3') if execute else args.analysis
    manifest, missing = prepare(json.loads(analysis.read_text()), json.loads(args.identities.read_text()))
    args.manifest.write_text(json.dumps(manifest, indent=2) + '\n')
    indexed, variants = [], []
    if execute:
        checked = invoke('analyze', analysis.parent, '--manifest', args.manifest)
        passing = json.loads(checked.read_text())
        builds = {row['source']: row for row in json.loads(analysis.read_text())}
        if not args.no_variants:
            for build in builds.values():
                failures = [row for row in build.get('checks', []) if row.get('status') == 'different'
                            and (row['addr'], row['requested_symbol']) not in manual
                            and not row.get('contiguous_catch_comparison', {}).get('relocation_normalized_match')]
                if not failures:
                    continue
                source = Path(build['source'])
                found = re.search(r'^// native-flags: (.*)$', source.read_text(encoding='utf-8-sig'), re.M)
                if not found:
                    continue
                trial_plan = args.manifest.with_name(args.manifest.stem + '-variants.json')
                trial_plan.write_text(json.dumps({'jobs': [{'source': str(source), 'checks': [
                    {'addr': row['addr'], 'symbol': row['requested_symbol']} for row in failures]}]}, indent=2) + '\n')
                for switch in ('/Ob0', '/Ob1', '/fp:precise'):
                    env = dict(os.environ, NATIVE_FLAGS=found.group(1) + ' ' + switch)
                    trial = invoke('run', trial_plan, '--workers', '1', env=env)
                    for job in json.loads(trial.read_text()):
                        for row in job.get('checks', []):
                            variants.append({'address': row['addr'], 'switch': switch, 'status': row['status'],
                                             'metrics': row.get('metrics'), 'run': str(trial)})
        for job, result in zip(manifest['jobs'], passing):
            if job['source'] != result['source']:
                raise RuntimeError('source order changed during review')
            passed = {row['addr'] for row in result['checks']
                      if row.get('status') == 'exact' and not row.get('data_errors')
                      and row.get('call_identity', {}).get('passed')}
            for row in result['checks']:
                if row['addr'] not in passed and row['addr'] not in {x.get('address') for x in missing}:
                    missing.append({'address': row['addr'], 'reason': 'data, call, or byte verification failed'})
            checks = [row for row in job['checks'] if row['addr'] in passed
                      and (row['addr'], row['symbol']) not in manual]
            for row in job['checks']:
                if (row['addr'], row['symbol']) in manual:
                    missing.append({'address': row['addr'], 'reason': 'discovered identity needs review'})
            if not checks:
                continue
            source_sha = runner.sha(Path(result['source']))
            build = builds[result['source']]
            key = hashlib.sha256(json.dumps({'source': result['source'], 'source_sha256': source_sha,
                'dependencies': build['dependencies'], 'flags': build['flags'],
                'compiler': build['build_inputs']['compiler'], 'checks': checks,
                'runner': runner.sha(check_runner), 'original': runner.sha(runner.ROOT / 'clients/2008-06/Roblox.exe')},
                sort_keys=True).encode()).hexdigest()[:24]
            isolated = args.manifest.with_name(args.manifest.stem + '-' + key + '.json')
            isolated.write_text(json.dumps({'jobs': [{'source': job['source'], 'checks': checks}]}, indent=2) + '\n')
            receipt = runner.ROOT / 'work/2008-06/shared-layouts' / ('g3d-batch-' + key + '.json')
            if receipt.exists():
                previous = json.loads(receipt.read_text())
                if (previous.get('source_sha256') != source_sha or
                    {row['address'] for row in previous.get('checks', []) if row.get('exact')} != {row['addr'] for row in checks}):
                    raise RuntimeError('existing receipt does not match this batch: ' + str(receipt))
            else:
                invoke('analyze', analysis.parent, '--manifest', isolated, '--require-proof', '--index-output', receipt)
            indexed.extend(row['addr'] for row in checks)
    report = {'manifest': str(args.manifest), 'indexed': indexed, 'unresolved': missing,
              'variants': variants, 'variant_scope': 'diagnostic only; verify source, calls and chosen build flags before indexing'}
    report_path = args.manifest.with_name(args.manifest.stem + '-report.json')
    report_path.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({'indexed': indexed, 'review_functions': sorted({x.get('address', x.get('source')) for x in missing}),
                      'report': str(report_path)}, indent=2))


if __name__ == '__main__':
    main()
