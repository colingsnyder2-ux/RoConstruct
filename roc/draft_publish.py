"""Publish only proof-bound inactive source actions using an isolated Git index."""
import argparse
from contextlib import closing, ExitStack
from concurrent.futures import ThreadPoolExecutor
import importlib.util
import json
import os
from pathlib import Path
import sqlite3
import subprocess
import time
import uuid

from roc import native_drafts
from roc.draft_merger import content_hash, proof_key
from roc.draft_proof import validate_adapter
from roc.draft_files import exclusive_existing

BRANCH = 'codex/native-partial-search-20261029'
ALIASES = '''CREATE TABLE IF NOT EXISTS source_aliases(path TEXT,before_sha256 TEXT,
 after_sha256 TEXT,normalized_sha256 TEXT,receipt TEXT,PRIMARY KEY(path,after_sha256));'''


def git(root, *args, data=None, env=None):
    return subprocess.run(['git', '-C', str(root), *args], input=data, capture_output=True,
                          check=True, env=env).stdout


def render_status(root, path, raw):
    spec = importlib.util.spec_from_file_location('_draft_publish_status', root / 'scripts/native_status.py')
    status = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(status)
    bom = b'\xef\xbb\xbf' if raw.startswith(b'\xef\xbb\xbf') else b''
    text = raw[len(bom):].replace(b'\r\n', b'\n').decode()
    entries = status.build_index([path])
    entry = entries.get(path) or entries.get(path.replace('/', '\\'))
    if entry is None:
        raise ValueError('Native status generator did not index selected source: ' + path)
    rendered = status.apply_banner(text, path, entry)
    if status.strip_existing_banner(text)[0] != status.strip_existing_banner(rendered)[0]:
        raise ValueError('Generated metadata changed source body')
    return bom + rendered.encode()


def native_input_snapshot(root):
    from roc.integration_verify import digest_paths, file_hash, input_paths
    paths = sorted((path for path in input_paths(root)[0] if not (
        path.parent == root / 'rebuild/2008-06/Source/App'
        and path.name.startswith('roc_claude_') and path.suffix == '.cpp')), key=str)
    with ThreadPoolExecutor(max_workers=8) as pool:
        hashes = dict(zip(paths, pool.map(file_hash, paths)))
    return digest_paths(root, paths, hashes), {str(path): value.hex() for path, value in hashes.items()}


def verify_sources(root, sources, receipts, output):
    from roc import rebuild
    from roc.draft_native import closed_function_targets, flags, numeric_literal_targets, original_view, reviewed_call_targets, ReviewedOriginal
    original, binder = original_view(root)
    before, before_files = native_input_snapshot(root)
    verifier_paths = [root / 'roc' / (name + '.py') for name in ('draft_publish', 'draft_native', 'draft_proof')]
    closure_path = root / 'work/native-client/claude-identity-closure.json'
    if closure_path.is_file():
        verifier_paths.append(closure_path)
    verifier_hashes = {str(path): content_hash(path.read_bytes()) for path in verifier_paths}
    native_drafts.atomic(output / 'inputs-before.json', before_files)
    from roc.input_reuse import ensure_link
    mirror = output / 'exact-tree'
    mirror.mkdir(parents=True)
    entries = []
    for record in git(root, 'ls-tree', '-rz', '-r', 'HEAD', '--',
                      'rebuild/2008-06/native-classes', 'rebuild/2008-06/native-headers',
                      'rebuild/2008-06/native-world').split(b'\0'):
        if not record:
            continue
        meta, name = record.split(b'\t', 1)
        mode, kind, blob = meta.split()
        if mode not in (b'100644', b'100755') or kind != b'blob':
            raise ValueError('Exact-tree compiler input is not a regular blob')
        label = name.decode()
        if not (mirror / label).resolve().is_relative_to(mirror.resolve()):
            raise ValueError('Exact-tree input escaped private output')
        entries.append((label, blob.decode()))
    data = git(root, 'cat-file', '--batch', data=''.join(blob + '\n' for _, blob in entries).encode())
    cursor = 0
    for name, blob in entries:
        end = data.index(b'\n', cursor)
        header = data[cursor:end].split()
        if header[0].decode() != blob or header[1] != b'blob':
            raise ValueError('Exact-tree blob identity mismatch')
        size = int(header[2])
        destination = mirror / name
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(data[end + 1:end + 1 + size])
        cursor = end + 2 + size
    ensure_link(root / 'tools', mirror / 'tools')
    evidence = {}
    for name, raw in sources.items():
        directory = output / proof_key(name)[:16]
        directory.mkdir(parents=True)
        source, obj = mirror / name, directory / 'unit.obj'
        source.parent.mkdir(parents=True, exist_ok=True)
        source.write_bytes(raw)
        configuration = flags(mirror)
        profiles = {receipt.get('compiler_profile', 'default') for receipt in receipts[name]}
        if not profiles <= {'default', 'fast-fp'} or len(profiles) != 1:
            raise ValueError('Publication needs one supported verified compiler profile')
        if profiles == {'fast-fp'}:
            configuration += ['/fp:fast']
        code, log = rebuild.run(rebuild.toolchain(21022), 'cl', configuration + ['/Fo' + str(obj), str(source)], directory, timeout=120)
        (directory / 'compiler.log').write_text(log)
        if code:
            raise ValueError('Exact Git source blob compile failed: ' + name + ': ' + log[-1200:])
        methods = sorted({(record['symbol'], int(record['address'], 16))
                          for receipt in receipts[name] for record in receipt['reference_evidence']})
        if not methods:
            raise ValueError('Published source needs independent original method witnesses')
        closure = root / 'work/native-client/claude-identity-closure.json'
        bindings = json.loads(closure.read_text())['bindings'] if closure.is_file() else []
        external = closed_function_targets(bindings)
        numeric = numeric_literal_targets(original, obj, methods)
        reviewed_source = all(row.get('kind') == 'reviewed-source-improvement' for row in receipts[name])
        calls = reviewed_call_targets(
            original, binder, obj, methods, bindings, allow_exact_inferred=True
        ) if reviewed_source else dict(targets={}, notes=[], import_aliases=set())
        view = ReviewedOriginal(original, calls['import_aliases']) if reviewed_source else original
        checked = binder.verify(view, obj, methods, dict(calls['targets'], **external, **numeric['targets']), dict(methods))
        if any(row['local_eh'] for row in checked) and not reviewed_source:
            raise ValueError('Published method has unproved exception metadata')
        evidence[name] = dict(source_sha256=content_hash(raw), object_sha256=content_hash(obj.read_bytes()),
                              methods=checked, inferred_calls=calls['notes'], compiler=21022, flags=configuration)
    after, after_files = native_input_snapshot(root)
    if after != before:
        changed = sorted(name for name in before_files.keys() | after_files.keys()
                         if before_files.get(name) != after_files.get(name))
        native_drafts.atomic(output / 'changed-inputs.json', dict(paths=changed))
        raise ValueError('Native inputs changed during exact-tree verification: ' + str(changed[:20]))
    if any(content_hash(Path(name).read_bytes()) != sha for name, sha in verifier_hashes.items()):
        raise ValueError('Publication verifier or external identities changed during proof')
    return dict(native_input_key=before, verifier_hashes=verifier_hashes, sources=evidence)


def publish(root, push=False):
    root = Path(root).resolve()
    token = native_drafts.integration_lock(root, 'start')['token']
    output = root / 'work/draft-merger/publications' / uuid.uuid4().hex
    output.mkdir(parents=True)
    result = dict(state='preparing', pushed=False)
    leases = []
    index_lock = None
    owns_index_lock = False
    try:
        branch = git(root, 'branch', '--show-current').decode().strip()
        if branch != BRANCH:
            raise ValueError('Publication requires existing authorized branch: ' + BRANCH)
        head = git(root, 'rev-parse', 'HEAD').decode().strip()
        remote = git(root, 'ls-remote', 'origin', 'refs/heads/' + branch).decode().split()
        if not remote or remote[0] != head:
            raise ValueError('Origin and local HEAD differ; reconcile existing commits before publishing this batch')
        sources, receipts, originals, actions, new_sources = {}, {}, {}, [], set()
        with closing(sqlite3.connect(root / 'work/draft-merger/state.sqlite3')) as db:
            for action, path, before_sha, after_sha, detail in db.execute("SELECT id,path,before_sha256,after_sha256,detail FROM actions WHERE state='applied-inactive'"):
                metadata = json.loads(detail)
                proof = db.execute('SELECT adapter,receipt FROM proofs WHERE id=?', (metadata['proof'],)).fetchone()
                if not proof:
                    raise ValueError('Source action has no coordinator proof')
                receipt = json.loads(proof[1])
                expected = {key: receipt[key] for key in ('candidate_sha256', 'input_key', 'client', 'verifier_sha256')}
                blockers = validate_adapter(proof[0], receipt, expected)
                if blockers:
                    raise ValueError('; '.join(blockers))
                native_drafts.safe_path(path)
                raw = (root / path).read_bytes()
                if content_hash(raw) != after_sha:
                    continue  # A changed source needs fresh proof; never restore it.
                selected_index = git(root, 'ls-files', '--stage', '--', path).decode().split()
                base = subprocess.run(['git', 'cat-file', '-e', head + ':' + path], cwd=root,
                                      capture_output=True).returncode == 0
                if before_sha is None:
                    if base or selected_index:
                        raise ValueError('Proven new source now exists in base/index: ' + path)
                    new_sources.add(path)
                else:
                    base_blob = git(root, 'rev-parse', head + ':' + path).decode().strip()
                    if not selected_index or selected_index[1] != base_blob:
                        raise ValueError('Selected source has unrelated staged changes: ' + path)
                if path not in sources:
                    name = 'draft-publish-' + str(len(leases)) + '-' + output.name[:8]
                    subprocess.run([str(root / 'roc.cmd'), 'lease', 'take', name, path, '--hours', '2'],
                                   cwd=root, check=True, capture_output=True)
                    leases.append(name)
                    sources[path] = render_status(root, path, raw)
                    originals[path] = raw
                    receipts[path] = []
                receipts[path].append(receipt)
                actions.append(action)
        if not sources:
            result.update(state='nothing-current-to-publish')
            return result
        dirty = git(root, 'diff', '--name-only', head, '--', 'rebuild/2008-06').decode().splitlines()
        if set(dirty) - sources.keys():
            raise ValueError('Other native source/header edits are outside the exact publication tree: ' + str(sorted(set(dirty) - sources.keys())))
        env = dict(os.environ, GIT_INDEX_FILE=str(output / 'index'))
        git(root, 'read-tree', head, env=env)
        for path, raw in sources.items():
            blob = git(root, 'hash-object', '-w', '--stdin', data=raw).decode().strip()
            git(root, 'update-index', '--add', '--cacheinfo', '100644,' + blob + ',' + path, env=env)
        verification = verify_sources(root, sources, receipts, output / 'verification')
        receipt_path = 'work/2008-06/shared-layouts/draft-publication-' + output.name + '.json'
        public_receipt = dict(scope='Inactive source publication; no runtime selection or server credit',
                              base=head, verification=verification, acceptance_receipts=receipts)
        receipt_raw = (json.dumps(public_receipt, indent=2) + '\n').encode()
        blob = git(root, 'hash-object', '-w', '--stdin', data=receipt_raw).decode().strip()
        git(root, 'update-index', '--add', '--cacheinfo', '100644,' + blob + ',' + receipt_path, env=env)
        tree = git(root, 'write-tree', env=env).decode().strip()
        check = subprocess.run([os.sys.executable, str(root / 'rebuild/2008-06/tests/verify_fork_preservation.py'),
                                head, tree, '--output', str(output / 'preservation.json')], cwd=root,
                               check=True, capture_output=True)
        preserved = json.loads((output / 'preservation.json').read_text())
        if preserved.get('passed') is not True or preserved.get('losses') != []:
            raise ValueError('Exact-tree preservation receipt did not prove zero losses')
        subprocess.run([str(root / 'roc.cmd'), 'lease', 'check', *sources], cwd=root, check=True, capture_output=True)
        subprocess.run([os.sys.executable, str(root / 'scripts/native_status.py'), '--check', '--staged'],
                       cwd=root, env=env, check=True, capture_output=True)
        if verification.get('native_input_key'):
            if native_input_snapshot(root)[0] != verification['native_input_key']:
                raise ValueError('Native dependencies changed after exact-tree proof')
        if any(content_hash(Path(name).read_bytes()) != sha for name, sha in verification.get('verifier_hashes', {}).items()):
            raise ValueError('Publication verifier or external identities changed after proof')
        # Git's real-index lock excludes conventional staging/checkouts while a
        # copied real index is updated. It is distinct from our candidate index.
        index_path = Path(git(root, 'rev-parse', '--git-path', 'index').decode().strip())
        if not index_path.is_absolute():
            index_path = root / index_path
        index_lock = index_path.with_name(index_path.name + '.lock')
        lock_stream = index_lock.open('xb')
        owns_index_lock = True
        try:
            real_copy = output / 'real-index'
            real_copy.write_bytes(index_path.read_bytes())
            real_env = dict(os.environ, GIT_INDEX_FILE=str(real_copy))
            for path in sources:
                staged = git(root, 'ls-files', '--stage', '--', path, env=real_env).decode().split()
                if path in new_sources:
                    if staged:
                        raise ValueError('Proven new source became staged before guarded commit: ' + path)
                else:
                    old_blob = git(root, 'rev-parse', head + ':' + path).decode().strip()
                    if not staged or staged[1] != old_blob:
                        raise ValueError('Selected index changed before guarded commit: ' + path)
            for path in [*sources, receipt_path]:
                blob = git(root, 'rev-parse', tree + ':' + path).decode().strip()
                git(root, 'update-index', '--add', '--cacheinfo', '100644,' + blob + ',' + path, env=real_env)
            lock_stream.write(real_copy.read_bytes())
            lock_stream.flush()
            os.fsync(lock_stream.fileno())
        finally:
            lock_stream.close()
        with ExitStack() as stack:
            handles = {path: stack.enter_context(exclusive_existing(root / path)) for path in sources}
            for path, stream in handles.items():
                if stream.read() != originals[path]:
                    raise ValueError('Selected source changed before exclusive commit: ' + path)
                backup = output / 'originals' / path
                backup.parent.mkdir(parents=True, exist_ok=True)
                backup.write_bytes(originals[path])
            if (git(root, 'rev-parse', 'HEAD').decode().strip() != head or
                    git(root, 'branch', '--show-current').decode().strip() != branch):
                raise ValueError('HEAD/branch advanced; rebase and reverify publication')
            commit = git(root, 'commit-tree', tree, '-p', head, data=b'Integrate independently proved inactive native methods\n').decode().strip()
            result.update(state='verified-commit-created', commit=commit, tree=tree, base=head,
                          paths=sorted(sources), publication_receipt=receipt_path)
            native_drafts.atomic(output / 'result.json', result)
            git(root, 'update-ref', 'refs/heads/' + branch, commit, head)
            result['state'] = 'committed-local'
            for path, stream in handles.items():
                stream.seek(0)
                stream.write(sources[path])
                stream.truncate()
                stream.flush()
                os.fsync(stream.fileno())
            destination = root / receipt_path
            destination.parent.mkdir(parents=True, exist_ok=True)
            with destination.open('xb') as stream:
                stream.write(receipt_raw)
                stream.flush()
                os.fsync(stream.fileno())
            os.replace(index_lock, index_path)
            owns_index_lock = False
        with closing(sqlite3.connect(root / 'work/draft-merger/state.sqlite3')) as db, db:
            db.executescript(ALIASES)
            for path, raw in sources.items():
                db.execute('INSERT OR REPLACE INTO source_aliases VALUES(?,?,?,?,?)',
                    (path, None if path in new_sources else content_hash(originals[path]), content_hash(raw), content_hash(raw.replace(b'\r\n', b'\n')),
                     json.dumps(dict(commit=commit, verification=verification['sources'][path]))))
        if push:
            git(root, 'push', 'origin', commit + ':refs/heads/' + branch)
            result.update(state='pushed', pushed=True)
        return result
    except Exception as error:
        result.update(state='blocked' if 'commit' not in result else 'publication-needs-reconciliation', error=str(error))
        return result
    finally:
        try:
            native_drafts.atomic(output / 'result.json', result)
        finally:
            try:
                if owns_index_lock:
                    index_lock.unlink(missing_ok=True)
                for lease in leases:
                    subprocess.run([str(root / 'roc.cmd'), 'lease', 'release', lease], cwd=root, capture_output=True)
            finally:
                native_drafts.integration_lock(root, 'release', token=token)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--push', action='store_true')
    args = parser.parse_args()
    print(json.dumps(publish(args.root, args.push), indent=2))
