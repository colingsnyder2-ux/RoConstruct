"""Import a pinned Git fork delta as inert, provenance-rich draft bundles."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

from roc import native_drafts


def git(root, *args, text=False, check=True):
    result = subprocess.run(['git', *args], cwd=root, capture_output=True, text=text, check=False)
    if check and result.returncode:
        message = result.stderr.strip() if text else result.stderr.decode('utf-8', 'replace').strip()
        raise ValueError(message or 'Git command failed')
    return result


def revision(root, value):
    result = git(root, 'rev-parse', '--verify', value + '^{commit}', text=True)
    return result.stdout.strip()


def blob(root, commit, path):
    result = git(root, 'cat-file', 'blob', commit + ':' + path, check=False)
    return result.stdout if result.returncode == 0 else None


def mode(root, commit, path):
    result = git(root, 'ls-tree', commit, '--', path, text=True)
    return result.stdout.split(None, 1)[0] if result.stdout else None


def decode(value, path):
    if value is None:
        return None
    if b'\0' in value:
        raise ValueError('Binary content unsupported')
    try:
        return value.decode('utf-8')
    except UnicodeDecodeError as error:
        raise ValueError('Non-UTF-8 content unsupported') from error


def import_commit(root, repository, target, base=None, user=None, paths=(), new_only=False):
    root = Path(root).resolve()
    target = revision(root, target)
    base = revision(root, base) if base else git(root, 'merge-base', 'HEAD', target, text=True).stdout.strip()
    if git(root, 'merge-base', '--is-ancestor', base, target, check=False).returncode:
        raise ValueError('Fork baseline is not an ancestor of target')
    user = user or repository.split('/')[0].lower()[:27] + '-fork'
    native_drafts.validate(dict(schema=1, user=user, model='git-fork:x', session='0' * 32,
                                baseline=base, files={'docs/checkpoint.txt': {'base': None, 'text': 'x'}}))
    names = git(root, 'diff', '--name-only', '-z', '--no-renames', base, target).stdout.split(b'\0')
    selected = {native_drafts.safe_path(path) for path in paths}
    found = set()
    changes, blockers = {}, []
    for raw_name in names:
        if not raw_name:
            continue
        try:
            name = raw_name.decode('utf-8')
            if selected and name not in selected:
                continue
            native_drafts.safe_path(name)
            found.add(name)
            old_mode, new_mode = mode(root, base, name), mode(root, target, name)
            if old_mode not in (None, '100644', '100755') or new_mode not in (None, '100644', '100755'):
                raise ValueError('Symlink, gitlink, or special file unsupported')
            old, new = decode(blob(root, base, name), name), decode(blob(root, target, name), name)
            if new_only and (old is not None or new is None or (root / name).exists()):
                continue
            if old == new:
                continue
            changes[name] = dict(base=old, text=new)
        except (ValueError, UnicodeError) as error:
            blockers.append(dict(path=raw_name.decode('utf-8', 'replace'), blocker=str(error)))
    blockers.extend(dict(path=name, blocker='Requested path is unchanged or absent from fork delta')
                    for name in sorted(selected - found))
    created = int(git(root, 'show', '-s', '--format=%ct', target, text=True).stdout.strip())
    model = 'git-fork:' + repository + '@' + target
    session = hashlib.sha256((repository + '\0' + target).encode()).hexdigest()[:32]
    chunks, current = [], {}
    for name, change in sorted(changes.items()):
        trial = {**current, name: change}
        packet = dict(schema=1, user=user, model=model, session=session, baseline=base, parent=None,
                      status='draft', exact_credits=0, created=created, files=trial)
        try:
            native_drafts.validate(packet)
            current = trial
        except ValueError as error:
            if not current:
                blockers.append(dict(path=name, blocker=str(error)))
                continue
            chunks.append(current)
            single = dict(schema=1, user=user, model=model, session=session, baseline=base, parent=None,
                          status='draft', exact_credits=0, created=created, files={name: change})
            try:
                native_drafts.validate(single)
                current = {name: change}
            except ValueError as single_error:
                blockers.append(dict(path=name, blocker=str(single_error)))
                current = {}
    if current:
        chunks.append(current)
    inbox = native_drafts.Inbox(root)
    credential = inbox.register(user) if chunks else None
    bundles, inserted, parent = [], 0, None
    for files in chunks:
        packet = dict(schema=1, user=user, model=model, session=session, baseline=base, parent=parent,
                      status='draft', exact_credits=0, created=created, files=files)
        identifier = native_drafts.digest(packet)
        with inbox.connect() as db:
            existed = db.execute('SELECT 1 FROM bundles WHERE id=?', (identifier,)).fetchone() is not None
        receipt = inbox.receive(packet, credential['token'])
        bundles.append(receipt['id'])
        inserted += not existed
        parent = receipt['id']
    result = dict(repository=repository, target=target, baseline=base, user=user, bundles=bundles,
                  inserted=int(inserted), paths=len(changes), new_only=new_only, blockers=blockers)
    native_drafts.atomic(root / 'work/draft-merger/fork-imports' /
                         (hashlib.sha256((repository + '\0' + target + '\0' + base + '\0' + str(new_only) + '\0' + '\0'.join(sorted(selected))).encode()).hexdigest() + '.json'), result)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('target')
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--repository', required=True)
    parser.add_argument('--base')
    parser.add_argument('--user')
    parser.add_argument('--path', action='append', default=[])
    parser.add_argument('--new-only', action='store_true')
    args = parser.parse_args()
    print(json.dumps(import_commit(args.root, args.repository, args.target, args.base, args.user, args.path, args.new_only), indent=2))


if __name__ == '__main__':
    main()
