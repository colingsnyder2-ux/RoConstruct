"""Run one deterministic native-convert plan batch; promotion is opt-in and leased."""
import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def header_vendor_include_dirs(header):
    """Existing, unique direct vendor header roots only; never choose basename ties."""
    from native_donor_convert import header_vendor_include_dirs as locate
    return locate(header)


def first_compile_error(folder):
    for log in folder.rglob('compile.log'):
        for line in log.read_text(errors='replace').splitlines():
            if ' error C' in line or 'fatal error C' in line:
                return line.strip()
    return ''


def compile_failed(manifest):
    return any('compiler failed' in blocker.lower()
               for family in manifest.get('families', [])
               for blocker in family.get('blockers', []))


def attempt_key(plan, row, probe_profile):
    source = Path(plan['source']).resolve()
    header = ROOT / plan['headers'][0]
    payload = {'source': str(source),
               'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
               'header': plan['headers'][0],
               'header_sha256': hashlib.sha256(header.read_bytes()).hexdigest(),
               'roc_flags': plan.get('roc_flags', ''), 'probe_profile': probe_profile,
               'symbol': row['symbol'], 'marker': row['marker']}
    return hashlib.sha256(json.dumps(payload, sort_keys=True).encode()).hexdigest()


def run(args):
    subprocess.run([sys.executable, *map(str, args)], cwd=ROOT, check=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--plan', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--batch', type=int, default=0)
    ap.add_argument('--row', type=int, action='append',
                    help='run selected zero-based rows only; isolates one bad body')
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--promote', action='store_true')
    ap.add_argument('--source-preamble', action='store_true')
    ap.add_argument('--source-includes', action='store_true')
    ap.add_argument('--add-flags', default='', help='extra proven compiler-profile flags; no source mutation')
    ap.add_argument('--fields', type=Path,
                    default=ROOT / 'work/native-client/claude-field-evidence.json',
                    help='binary field evidence required by the promotion layout gate')
    args = ap.parse_args()
    plan = json.loads(args.plan.read_text())['plans'][args.batch]
    if args.row:
        chosen = sorted(set(args.row))
        if any(index < 0 or index >= len(plan['rows']) for index in chosen):
            raise ValueError('--row outside plan batch')
        plan = dict(plan)
        plan['rows'] = [plan['rows'][index] for index in chosen]
        plan['probe_records'] = [row['addr'] + '=' + row['marker'] for row in plan['rows']]
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    probe, evidence, config = out / 'probe.cpp', out / 'identity.json', out / 'bulk.json'
    include = Path(plan['headers'][0]).as_posix().replace('rebuild/2008-06/native-headers/', '')
    # A vendor directory may also contain `RakPeer.h`/`Kernel.h`.  The probe
    # must include its selected native declaration, never whichever same-name
    # donor header appears first in the compile profile.
    probe_include = (ROOT / plan['headers'][0]).resolve().as_posix()
    probe_command = [ROOT / 'work/native-client/native_transplant_probe.py', '--packet', plan['source'],
                     '--namespace=' + plan.get('namespace', ''), '--include', probe_include, '--output', probe]
    # A recovered body is finally re-proved in its destination TU.  Preserve
    # only explicitly declared support includes from that TU for the isolated
    # probe; this supplies complete types without importing donor declarations.
    for support in plan.get('support_includes', []):
        probe_command += ['--include', support]
    probe_command += ['--include-dir', str(Path(plan['source']).parent)]
    for include_dir in header_vendor_include_dirs(Path(plan['headers'][0])):
        probe_command += ['--include-dir', str(include_dir)]
    profile_parts = [plan.get('roc_flags', ''), args.add_flags, '/I' + str(Path(plan['source']).parent)]
    # VS2008 MFC headers reject /MD unless their shared-DLL ABI switch is present.
    # This is a compile-profile fact from the real header, never a source rewrite.
    header_text = ''.join(Path(header).read_text(errors='ignore') for header in plan['headers'])
    if 'afxwin.h' in header_text:
        # MFC's shared-DLL headers explicitly require both switches.  This is
        # a compile-provider fact; the downstream exact gate rejects a wrong
        # profile without changing a native source.
        if '/MD' not in ' '.join(profile_parts):
            profile_parts.append('/MD')
        if '/D_AFXDLL' not in ' '.join(profile_parts):
            profile_parts.append('/D_AFXDLL')
    profile = ' '.join(value for value in profile_parts if value)
    probe_command += ['--flags=' + profile]
    probe_command += ['--support-globals']
    if args.source_preamble:
        probe_command += ['--source-preamble']
    if args.source_includes:
        probe_command += ['--source-includes']
    for record in plan['probe_records']:
        probe_command += ['--record', record]
    run(probe_command)
    bulk = out.parent / (out.name + '-bulk-' + hashlib.sha256(probe.read_bytes()).hexdigest()[:16])
    addresses = [row['addr'] for row in plan['rows']]
    identity_command = [ROOT / 'work/native-client/native_identity_evidence.py', '--closure', args.closure, '--output', evidence]
    for address in addresses:
        identity_command += ['--addr', address]
    run(identity_command)
    config.write_text(json.dumps({'client': '2008-06', 'roc_cl': plan.get('roc_cl', 21022), 'targets': addresses,
                                  'families': [{'name': 'native-convert-%03d' % args.batch,
                                                'sources': [str(probe.relative_to(ROOT)).replace('\\', '/')],
                                                'evidence': [str(evidence.relative_to(ROOT)).replace('\\', '/')]}]}, indent=1))
    subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(config), '--out', str(bulk)], cwd=ROOT, check=True)
    manifest = bulk / 'manifest.json'
    checked = json.loads(manifest.read_text())
    expected = {row['symbol']: row['addr'] for row in plan['rows']}
    observed = {row['symbol']: row for family in checked['families'] for row in family['symbols']}
    provider_retry = None
    if compile_failed(checked):
        logs = list(bulk.rglob('compile.log'))
        if logs:
            hints = out / 'provider-hints.json'
            run([ROOT / 'work/native-client/native_provider_hints.py', '--log', logs[0], '--output', hints])
            hint_rows = json.loads(hints.read_text())['rows']
            # A finite, evidence-only retry: every missing type must have one
            # existing 2008 declaration provider.  Ambiguous/missing names are
            # left blocked; no include ordering or layout is guessed.
            if hint_rows and all(row['status'] == 'unique' for row in hint_rows):
                providers = [ROOT / row['providers'][0] for row in hint_rows]
                retry_command = probe_command + sum((['--include', path] for path in providers), [])
                run(retry_command)
                retry_bulk = out.parent / (out.name + '-provider-' + hashlib.sha256(probe.read_bytes()).hexdigest()[:16])
                subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(config), '--out', str(retry_bulk)],
                               cwd=ROOT, check=True)
                bulk, manifest = retry_bulk, retry_bulk / 'manifest.json'
                checked = json.loads(manifest.read_text())
                observed = {row['symbol']: row for family in checked['families'] for row in family['symbols']}
                provider_retry = {'hints': str(hints.relative_to(ROOT)).replace('\\', '/'),
                                  'providers': [str(path.relative_to(ROOT)).replace('\\', '/') for path in providers],
                                  'compile_failed_after': compile_failed(checked)}
    has_compile_failure = compile_failed(checked)
    compile_blockers = sorted({blocker for family in checked.get('families', [])
                               for blocker in family.get('blockers', [])})
    compiled = any(family.get('state') == 'compiled' for family in checked.get('families', []))
    absent_status = 'compile_failed' if has_compile_failure else ('symbol_not_emitted' if compiled else 'missing')
    probe_profile = {'source_preamble': args.source_preamble,
                     'source_includes': args.source_includes,
                     'add_flags': args.add_flags}
    requested = [{'addr': row['addr'], 'symbol': row['symbol'],
                  'status': observed.get(row['symbol'], {}).get('status', absent_status),
                  'attempt_key': attempt_key(plan, row, probe_profile)}
                 for row in sorted(plan['rows'], key=lambda row: row['symbol'])]
    result = {'batch': args.batch, 'owner': plan['owner'], 'manifest': str(manifest),
              'requested': requested,
              'requested_exact': sum(row['status'] == 'inactive_exact' for row in requested),
              'requested_blocked': sum(row['status'] != 'inactive_exact' for row in requested),
              'compile_blockers': compile_blockers,
              'promote': args.promote}
    if provider_retry:
        result['provider_retry'] = provider_retry
    if has_compile_failure:
        result['first_compile_error'] = first_compile_error(bulk)
        result['compile_logs'] = [str(path.relative_to(ROOT)).replace('\\', '/')
                                  for path in bulk.rglob('compile.log')]
    if args.promote:
        exact = sorted({row['addr'] for family in checked['families'] for row in family['symbols']
                        if row.get('status') == 'inactive_exact' and row.get('addr') in addresses})
        if not exact:
            result['promotion_blocked'] = 'no isolated exact source bodies'
            (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
            print(json.dumps(result))
            return
        # Header/source provider selection is unsafe when its emitted virtual
        # order disagrees with a named target table.  Keep this check in the
        # automatic path; no source mutation happens on a differ.
        vtable = out / 'vftable.json'
        run([ROOT / 'work/native-client/native_vftable_check.py', probe,
             '--closure', args.closure, '--output', vtable])
        differs = json.loads(vtable.read_text())['summary'].get('differ', 0)
        result['vftable_gate'] = {'path': str(vtable), 'differ': differs,
                                  'passed': differs == 0}
        if differs:
            result['promotion_blocked'] = 'header virtual order differs from target'
            (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
            print(json.dumps(result))
            return
        # The virtual table check covers slot order only.  Require the compiler
        # view of the selected owner layout to have no contradiction with the
        # independently mined field/vfptr evidence before source promotion.
        layout = out / 'layout.json'
        layout_gate = out / 'layout-gate.json'
        owner = plan['owner'].rsplit('::', 1)[-1]
        run([ROOT / 'work/native-client/native_class_layout.py', probe,
             '--match', owner, '--output', layout])
        layout_result = json.loads(layout.read_text())
        if layout_result.get('compiler_exit'):
            result['layout_gate'] = {'path': str(layout), 'passed': False,
                                     'reason': 'layout compiler failed'}
            result['promotion_blocked'] = 'header layout compiler failed'
            (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
            print(json.dumps(result))
            return
        run([ROOT / 'work/native-client/native_layout_gate.py', layout,
             '--fields', args.fields, '--output', layout_gate])
        layout_summary = json.loads(layout_gate.read_text()).get('summary', {})
        layout_differs = layout_summary.get('differ', 0)
        result['layout_gate'] = {'path': str(layout_gate), 'differ': layout_differs,
                                 'classes': layout_summary.get('classes', 0),
                                 'passed': layout_differs == 0}
        if layout_differs:
            result['promotion_blocked'] = 'header layout differs from target field evidence'
            (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
            print(json.dumps(result))
            return
        # Isolated probe exactness is insufficient: the destination TU can have
        # different flags or resolve same-name headers differently. Render an
        # untracked candidate first, then prove that full TU before any lease or
        # native-source write.
        candidate = out / 'destination-candidate.cpp'
        render = [ROOT / 'work/native-client/native_transplant_promote.py', '--source', probe,
                  '--manifest', manifest, '--destination', ROOT / plan['destination'], '--include', include,
                  '--namespace', plan.get('namespace', ''), '--flags', profile,
                  '--output', out / 'destination-render.json', '--render', candidate]
        if args.source_includes:
            render += ['--source-includes', '--source-root', Path(plan['source']).parent]
        for address in exact:
            render += ['--addr', address]
        run(render)
        destination_evidence = out / 'destination-identity.json'
        run([ROOT / 'work/native-client/native_identity_evidence.py', '--closure', args.closure,
             '--output', destination_evidence,
             *sum((['--addr', address] for address in exact), [])])
        destination_config = out / 'destination-bulk.json'
        destination_config.write_text(json.dumps({
            'client': '2008-06', 'roc_cl': plan.get('roc_cl', 21022), 'targets': exact,
            'families': [{'name': 'native-convert-destination-%03d' % args.batch,
                          'sources': [str(candidate.relative_to(ROOT)).replace('\\\\', '/')],
                          'evidence': [str(destination_evidence.relative_to(ROOT)).replace('\\\\', '/')]}]
        }, indent=1))
        destination_bulk = out.parent / (out.name + '-destination-' + hashlib.sha256(candidate.read_bytes()).hexdigest()[:16])
        subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(destination_config), '--out', str(destination_bulk)],
                       cwd=ROOT, check=True)
        destination_manifest = json.loads((destination_bulk / 'manifest.json').read_text())
        destination_rows = {row['addr']: row for family in destination_manifest['families']
                            for row in family['symbols'] if row.get('addr')}
        destination_status = {address: destination_rows.get(address, {}).get('status', 'symbol_not_emitted')
                              for address in exact}
        result['destination_reproof'] = {'manifest': str(destination_bulk / 'manifest.json'),
                                         'status': destination_status,
                                         'passed': all(value == 'inactive_exact' for value in destination_status.values())}
        if not result['destination_reproof']['passed']:
            result['promotion_blocked'] = 'destination translation unit not exact'
            (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
            print(json.dumps(result))
            return
        command = [ROOT / 'work/native-client/native_transplant_promote.py', '--source', probe,
                   '--manifest', manifest, '--destination', ROOT / plan['destination'], '--include', include,
                   '--namespace', plan.get('namespace', ''), '--flags', profile,
                   '--output', out / 'promotion.json', '--apply']
        if args.source_includes:
            command += ['--source-includes', '--source-root', Path(plan['source']).parent]
        for address in exact:
            command += ['--addr', address]
        run(command)
    (out / 'result.json').write_text(json.dumps(result, indent=1) + '\n')
    print(json.dumps(result))


if __name__ == '__main__':
    main()
