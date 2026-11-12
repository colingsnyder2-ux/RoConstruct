"""Batch-index and check Mew's native fork without overwriting the workspace.

Fork receipts are untrusted leads. Matching is not integration approval: ABI,
provider ownership and runtime gates remain separate.
"""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import re
import subprocess
import sys

SOURCE_ROOT = Path(__file__).resolve().parents[1]
_repo = subprocess.run(['git', '-C', str(SOURCE_ROOT), 'rev-parse', '--show-toplevel'],
                       capture_output=True, text=True)
ROOT = Path(_repo.stdout.strip()) if _repo.returncode == 0 else SOURCE_ROOT
DONOR = 'refs/remotes/mew-review/selected'
DEFAULT_BRANCH = 'claude/optimistic-shannon-0xccuy'
WORK = 'refs/remotes/findings/work'
NATIVE = ('rebuild/2008-06/native-classes/', 'rebuild/2008-06/native-headers/',
          'rebuild/2008-06/native-world/')


def git(root, *args, data=None):
    return subprocess.check_output(['git', *args], cwd=root, input=data)


def fetch_donor(root, branch=DEFAULT_BRANCH):
    valid = subprocess.run(['git', 'check-ref-format', '--branch', branch], cwd=root,
                           capture_output=True)
    if valid.returncode:
        raise ValueError('Invalid Mew branch: ' + branch)
    git(root, 'fetch', 'https://github.com/mewpokemons/RoConstruct.git',
        '+refs/heads/' + branch + ':' + DONOR)


def tree(root, ref, prefix):
    rows = git(root, 'ls-tree', '-r', '-z', ref, '--', prefix).split(b'\0')
    result = {}
    for row in rows:
        if not row:
            continue
        metadata, path = row.split(b'\t', 1)
        mode, kind, sha = metadata.split()
        if mode not in (b'100644', b'100755') or kind != b'blob':
            raise ValueError('non-regular Git entry: ' + path.decode(errors='replace'))
        result[path.decode('utf-8')] = sha.decode('ascii')
    return result


def blobs(root, identities):
    identities = list(dict.fromkeys(identities))
    raw = git(root, 'cat-file', '--batch', data=''.join(x + '\n' for x in identities).encode())
    result, pos = {}, 0
    for expected in identities:
        end = raw.index(b'\n', pos)
        sha, kind, size = raw[pos:end].split()
        if sha.decode() != expected or kind != b'blob':
            raise ValueError('Git blob identity mismatch')
        size = int(size)
        pos = end + 1
        result[expected] = raw[pos:pos + size]
        pos += size + 1
    return result


def receipt_profiles(receipt):
    flags = receipt.get('flags')
    if isinstance(flags, dict):
        return flags
    if not isinstance(flags, list):
        return {}
    argument_names = {str(value).replace('\\', '/') for value in flags
                      if str(value).lower().endswith('.cpp')}
    if len(argument_names) == 1:
        return {'unit': flags}
    sources = receipt.get('sources', {})
    names = [str(path).replace('\\', '/') for path in sources
             if '/native-classes/AppUnit' in str(path).replace('\\', '/')
             and str(path).lower().endswith('.cpp')]
    if len(names) != 1:
        return {}
    return {'unit': flags + [names[0]]}


def receipt_groups(receipt):
    """Find original-address leads and the source each receipt group compiled."""
    rows, flags = receipt.get('rows'), receipt_profiles(receipt)
    if isinstance(rows, list):
        grouped = {}
        for row in rows:
            if not isinstance(row, dict):
                continue
            group = row.get('build') if row.get('build') in flags else row.get('unit')
            if group in flags:
                grouped.setdefault(group, []).append(row)
        if not grouped and len(flags) == 1:
            grouped[next(iter(flags))] = rows
        if not grouped:
            app_groups = [group for group, arguments in flags.items()
                          if sum(str(value).replace('\\', '/').split('/')[-1].lower().startswith('appunit')
                                 and str(value).lower().endswith('.cpp') for value in arguments) == 1]
            if len(app_groups) == 1:
                grouped[app_groups[0]] = rows
        rows = grouped
    if not isinstance(rows, dict) or not isinstance(flags, dict):
        return []
    result = []
    for group, entries in rows.items():
        arguments = flags.get(group, [])
        if not isinstance(arguments, list) or not isinstance(entries, list):
            continue
        names = list(dict.fromkeys(str(x).replace('\\', '/').split('/')[-1] for x in arguments
                                   if str(x).lower().endswith('.cpp')))
        if len(names) != 1:
            continue
        checks = []
        for row in entries:
            if not isinstance(row, dict) or row.get('exact') is not True:
                continue
            address, symbol = str(row.get('address', '')).lower().removeprefix('0x'), row.get('symbol')
            if (re.fullmatch(r'[0-9a-f]{8}', address) and isinstance(symbol, str) and symbol
                    and not symbol.startswith(('__catch$', '__ehhandler$', '__unwindfunclet$'))
                    and not re.search(r' \[0x[0-9a-f]+:0x[0-9a-f]+\]$', symbol, re.I)):
                checks.append({'addr': address, 'symbol': symbol})
        if checks:
            ogre = any(str(value).replace('\\', '/').lower().endswith(
                '/tools/libs/ogre-1.4.5/ogrenew/ogremain/include') for value in arguments)
            native_includes = []
            for value in arguments:
                normalized = str(value).replace('\\', '/')
                marker = '/rebuild/2008-06/native-headers/'
                if normalized.startswith('/I') and marker in normalized:
                    native_includes.append(normalized.split(marker, 1)[1])
            result.append((names[0].lower(), group, checks, '/fp:fast' in arguments,
                           '/U_RELEASEASSERT' in arguments, ogre, native_includes))
    return result


def prepare(root, output, donor=DONOR, work=WORK, batch_size=40):
    root, output = Path(root).resolve(), Path(output).resolve()
    if not 1 <= batch_size <= 50:
        raise ValueError('batch size must be 1..50')
    output.mkdir(parents=True, exist_ok=False)
    donor_sha = git(root, 'rev-parse', donor).decode().strip()
    work_sha = git(root, 'rev-parse', work).decode().strip()
    donor_tree = tree(root, donor_sha, 'rebuild/2008-06')
    donor_files = {p: h for p, h in donor_tree.items() if p.startswith(NATIVE)}
    canonical = tree(root, work_sha, 'workspace/rebuild/2008-06')
    by_blob = {}
    by_name = {}
    for path, sha in canonical.items():
        by_blob.setdefault(sha, []).append(path)
        by_name.setdefault(PurePosixPath(path).name.casefold(), []).append(path)
    receipts = tree(root, donor_sha, 'work/2008-06/shared-layouts')
    receipts = {p: h for p, h in receipts.items() if p.endswith('working.json')}
    data = blobs(root, list(donor_files.values()) + list(receipts.values()))
    leads, errors = {}, []
    for path, sha in receipts.items():
        try:
            receipt = json.loads(data[sha])
            for name, group, checks, fast, undef, ogre, native_includes in receipt_groups(receipt):
                source_hashes = receipt.get('sources', {})
                if not isinstance(source_hashes, dict):
                    source_hashes = {}
                hashes = {str(value).lower() for key, value in source_hashes.items()
                          if key == group or str(key).replace('\\', '/').split('/')[-1].lower() == name}
                leads.setdefault(name, []).append(
                    (path, group, checks, fast, undef, ogre, native_includes, hashes))
        except (ValueError, TypeError, UnicodeError) as error:
            errors.append({'receipt': path, 'error': str(error)})
    inventory, jobs = [], []
    for path, sha in sorted(donor_files.items()):
        name = PurePosixPath(path).name.casefold()
        state = 'identical_blob' if sha in by_blob else 'same_name_differs' if name in by_name else 'no_matching_name'
        item = {'path': path, 'blob': sha, 'state': state,
                'matching_workspace_paths': by_blob.get(sha, []) or by_name.get(name, [])}
        inventory.append(item)
        if state != 'no_matching_name' or not path.lower().endswith('.cpp'):
            continue
        candidates = leads.get(name, [])
        if len(candidates) != 1:
            item['blocker'] = 'no unique receipt/profile' if not candidates else 'multiple receipt profiles require review'
            continue
        receipt, group, checks, fast, undef, ogre, native_includes, source_hashes = candidates[0]
        source = data[sha]
        source_sha = hashlib.sha256(source).hexdigest()
        if source_sha not in source_hashes:
            item['blocker'] = 'receipt does not bind the exact fork source bytes'
            continue
        # A fork comment cannot supply compiler flags. Keep untrusted source bytes intact
        # in the archive and use a controlled private copy for compilation.
        try:
            text = source.decode('utf-8-sig')
        except UnicodeDecodeError:
            item['blocker'] = 'source is not UTF-8; review encoding'
            continue
        text = re.sub(r'^// native-flags:.*\r?\n', '', text, flags=re.M)
        profile = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS'
        if fast:
            profile += ' /fp:fast'
        for relative in native_includes:
            include = (root / 'rebuild/2008-06/native-headers' / relative).resolve()
            header_root = (root / 'rebuild/2008-06/native-headers').resolve()
            if include == header_root or header_root not in include.parents or not include.is_dir():
                item['blocker'] = 'receipt native-header profile is unavailable'
                break
            if ' ' in str(include):
                item['blocker'] = 'native-header profile path contains spaces'
                break
            profile += ' /I' + include.as_posix()
        if 'blocker' in item:
            continue
        if ogre:
            include = root / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include'
            if not (include / 'OgreTexture.h').is_file():
                item['blocker'] = 'pinned Ogre 1.4.5 headers are missing'
                continue
            if ' ' in str(include):
                item['blocker'] = 'Ogre include path contains spaces unsupported by the existing runner'
                continue
            profile += ' /I' + include.as_posix()
        candidate = output / 'sources' / PurePosixPath(path)
        candidate.parent.mkdir(parents=True, exist_ok=True)
        candidate.write_text('// native-flags: ' + profile + '\n' +
                             ('#undef _RELEASEASSERT\n' if undef else '') + text, encoding='utf-8')
        item.update(receipt=receipt, receipt_group=group, original_sha256=source_sha,
                    candidate=str(candidate), state='candidate_unreviewed')
        jobs.append({'source': str(candidate), 'checks': checks})
    manifests = []
    for i in range(0, len(jobs), batch_size):
        path = output / ('batch-%03d.json' % (i // batch_size + 1))
        path.write_text(json.dumps({'jobs': jobs[i:i + batch_size]}, indent=2) + '\n', encoding='utf-8')
        manifests.append(str(path))
    report = {'donor': donor_sha, 'work': work_sha, 'files': inventory,
              'receipt_errors': errors, 'manifests': manifests,
              'scope': 'Inventory and untrusted check leads only; no merge or runtime approval.'}
    (output / 'inventory.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    return report


def check_batches(root, output, manifests, workers):
    """Continue independent batches after failures and retain every log."""
    checker = root / 'workspace/rebuild/2008-06/tests/native_check_runner.py'
    if not checker.is_file():
        checker = root / 'rebuild/2008-06/tests/native_check_runner.py'
    outcomes = []
    for number, manifest in enumerate(manifests, 1):
        result = subprocess.run([sys.executable, str(checker), 'run', manifest, '--workers', str(workers)],
                                cwd=root, text=True, capture_output=True, encoding='utf-8', errors='replace')
        log = output / ('check-%03d.log' % number)
        log.write_text(result.stdout + result.stderr, encoding='utf-8')
        summary = None
        for line in reversed(result.stdout.splitlines()):
            try:
                value = json.loads(line)
                if isinstance(value, dict) and 'run' in value:
                    summary = value
                    break
            except ValueError:
                continue
        outcomes.append({'manifest': manifest, 'exit_code': result.returncode,
                         'log': str(log), 'summary': summary})
        print('Checked batch %d/%d: %s' %
              (number, len(manifests), 'finished; inspect results' if result.returncode == 0 else 'failures; see log'), flush=True)
    (output / 'checks.json').write_text(json.dumps(outcomes, indent=2) + '\n', encoding='utf-8')
    return outcomes


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=['run'])
    parser.add_argument('--all', action='store_true', required=True)
    parser.add_argument('--output', type=Path, required=True, help='new scratch directory')
    parser.add_argument('--workers', type=int, choices=range(1, 9), default=3)
    parser.add_argument('--batch-size', type=int, default=40)
    parser.add_argument('--branch', default=DEFAULT_BRANCH, help='Mew branch to pin')
    parser.add_argument('--offline', action='store_true', help='use already fetched refs')
    parser.add_argument('--check', action='store_true', help='compile proposed candidates in isolated objects')
    args = parser.parse_args(argv)
    if not args.offline:
        git(ROOT, 'fetch', 'findings', 'work')
        fetch_donor(ROOT, args.branch)
    report = prepare(ROOT, args.output, batch_size=args.batch_size)
    print('Indexed %d fork files; prepared %d batches. No files merged.' %
          (len(report['files']), len(report['manifests'])), flush=True)
    if args.check:
        outcomes = check_batches(ROOT, Path(args.output).resolve(), report['manifests'], args.workers)
        if any(item['exit_code'] != 0 for item in outcomes):
            raise SystemExit('Some batches failed; see checks.json and the retained logs.')
    return report


if __name__ == '__main__':
    main()
