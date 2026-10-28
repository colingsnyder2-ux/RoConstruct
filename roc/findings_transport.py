"""Findings Git transport shared by server and independent hourly publisher."""
import hashlib
import json
import os
import re
from pathlib import Path
import subprocess
import tempfile
import uuid


def publish_downloads(root, git_exe, log=print):
    """Publish only reviewed native Worker assets, preserving the remote findings tree."""
    root = Path(root)
    folder = root / 'local/findings/data'
    files = ['native-worker.zip', 'native-worker.json', 'NATIVE_AGENT.md']
    manifest = json.loads((folder / 'native-worker.json').read_text(encoding='utf-8'))
    if hashlib.sha256((folder / 'native-worker.zip').read_bytes()).hexdigest() != manifest['sha256']:
        raise ValueError('Worker download hash mismatch; rebuild the download bundle')
    index = root / 'work' / ('downloads-index-' + uuid.uuid4().hex)
    index.parent.mkdir(exist_ok=True)
    env = dict(os.environ, GIT_INDEX_FILE=str(index))
    def git(*args):
        result = subprocess.run([git_exe, *args], cwd=root, env=env, capture_output=True, text=True, timeout=120)
        if result.returncode:
            raise RuntimeError('Download publication failed: ' + result.stderr.strip()[-300:])
        return result.stdout.strip()
    try:
        git('fetch', 'findings', 'refs/heads/main:refs/remotes/findings/main')
        parent = git('rev-parse', 'refs/remotes/findings/main')
        git('read-tree', parent)
        for name in files:
            blob = git('hash-object', '-w', '--', str(folder / name))
            git('update-index', '--add', '--cacheinfo', '100644', blob, 'data/' + name)
        tree = git('write-tree')
        if tree == git('rev-parse', parent + '^{tree}'):
            return log('Native Worker download already current.')
        commit = git('commit-tree', tree, '-p', parent, '-m', 'Publish native Worker download')
        git('push', 'findings', commit + ':refs/heads/main')
        log('Native Worker download published: ' + commit)
    finally:
        index.unlink(missing_ok=True)


def publish_package(root, git_exe, log=print):
    """Update the native package using existing blobs for unchanged or renamed files."""
    root = Path(root)
    folder = root / 'local/findings/2008-06'
    manifest = json.loads((folder / 'package.json').read_text(encoding='utf-8'))
    index = root / 'work' / ('package-index-' + uuid.uuid4().hex)
    index.parent.mkdir(exist_ok=True)
    env = dict(os.environ, GIT_INDEX_FILE=str(index))
    def git(*args, **kwargs):
        result = subprocess.run([git_exe, *args], cwd=root, env=env, capture_output=True,
                                text=True, encoding='utf-8', errors='replace', timeout=120, **kwargs)
        if result.returncode:
            raise RuntimeError('Package publication failed: ' + result.stderr.strip()[-300:])
        return result.stdout.strip()
    try:
        git('fetch', 'findings', 'refs/heads/main:refs/remotes/findings/main')
        parent = git('rev-parse', 'refs/remotes/findings/main')
        previous = json.loads(git('show', parent + ':2008-06/package.json'))
        git('read-tree', parent)
        blobs = {}
        for row in git('ls-tree', '-r', '-z', parent, '--', '2008-06').split('\0'):
            if row:
                meta, path = row.split('\t', 1)
                blobs[path] = meta.split()[2]
        rows = ['0 ' + '0' * 40 + '\t2008-06/' + path + '\0'
                for path in previous['files'].keys() - manifest['files'].keys()]
        for relative in [*manifest['files'], 'package.json']:
            old = relative
            if old not in previous['files'] and relative.startswith('src/Client/'):
                old = relative.replace('src/Client/', 'src/rbxgs/Client/', 1)
            same = relative != 'package.json' and manifest['files'][relative] == previous['files'].get(old)
            blob = blobs.get('2008-06/' + old) if same else None
            if not blob:
                blob = git('hash-object', '-w', '--', str(folder / relative))
            rows.append('100644 ' + blob + '\t2008-06/' + relative + '\0')
        git('update-index', '-z', '--index-info', input=''.join(rows))
        tree = git('write-tree')
        if tree == git('rev-parse', parent + '^{tree}'):
            return log('Native package already current.')
        commit = git('commit-tree', tree, '-p', parent, '-m', 'Flatten native Client source path')
        git('push', 'findings', commit + ':refs/heads/main')
        log('Native package published: ' + commit)
    finally:
        index.unlink(missing_ok=True)


def publish(root, git_exe, log=print):
    """Copy local recovered sources into the separate findings repository."""
    from roc.server import findings_source
    source = root / "src"
    if not source.exists():
        return
    index = root / "work" / ("findings-index-" + uuid.uuid4().hex)
    index.parent.mkdir(exist_ok=True)
    env = os.environ.copy()
    env["GIT_INDEX_FILE"] = str(index)
    git = lambda *a: subprocess.run([git_exe, *a], cwd=root, env=env, capture_output=True, text=True)
    try:
        fetched = git("fetch", "findings", "main")
        if fetched.returncode:
            return log("Findings fetch failed: %s" % fetched.stderr.strip()[-300:])
        parent = git("rev-parse", "FETCH_HEAD")
        if parent.returncode:
            return log("Findings revision unavailable: %s" % parent.stderr.strip()[-300:])
        parent = parent.stdout.strip()
        # The findings tree is rebuilt from an allowlist (sources + portable evidence), so files
        # that do not belong there never persist. sync_findings has already exported every
        # stored source into src/.
        if git("read-tree", "--empty").returncode or git("add", "-f", "src").returncode:
            return log("Findings source staging failed.")
        from roc import libs
        units = libs.generated_units()
        # Stream blobs into one Git pack; avoid a temporary file/process per function.
        with tempfile.TemporaryDirectory(prefix="findings-sources-", dir=root / "work") as temporary:
            names, seen = [], {}
            marks = Path(temporary) / "marks"
            listed = git("ls-files", "--stage", "-z", "--", "src")
            if listed.returncode:
                return log("Findings source listing failed.")
            rows = [row.split("\t", 1) for row in listed.stdout.split("\0") if row]
            with tempfile.TemporaryFile(dir=temporary) as originals, tempfile.TemporaryFile(dir=temporary) as stream:
                # Reading staged blobs in bulk avoids reopening 170k files on Windows.
                read = subprocess.run([git_exe, "cat-file", "--batch"], cwd=root, env=env,
                    input=("\n".join(meta.split()[1] for meta, _ in rows) + "\n").encode(),
                    stdout=originals, stderr=subprocess.PIPE)
                if read.returncode:
                    return log("Findings source reading failed: " + read.stderr.decode(errors="replace")[-300:])
                originals.seek(0)
                for _, relative in rows:
                    size = int(originals.readline().split()[-1])
                    text = originals.read(size).decode("utf-8", errors="replace").replace("\r\n", "\n")
                    originals.read(1)  # batch record separator
                    expanded = findings_source(text, units)
                    if expanded == text:
                        continue
                    body = expanded.encode("utf-8")
                    digest = hashlib.sha256(body).digest()
                    if digest not in seen:
                        seen[digest] = len(seen) + 1
                        stream.write(("blob\nmark :%d\ndata %d\n" % (seen[digest], len(body))).encode("ascii"))
                        stream.write(body)
                        stream.write(b"\n")
                    names.append((relative, seen[digest]))
                stream.write(b"done\n")
                stream.seek(0)
                if names:
                    blobs = subprocess.run([git_exe, "fast-import", "--quiet", "--done", "--export-marks=" + str(marks)],
                                           cwd=root, env=env, stdin=stream, capture_output=True, text=True)
                    if blobs.returncode:
                        return log("Findings source hashing failed: " + blobs.stderr.strip()[-300:])
            if names:
                hashes = dict(line.split() for line in marks.read_text().splitlines())
                staged = subprocess.run([git_exe, "update-index", "-z", "--index-info"], cwd=root, env=env,
                                        input="".join("100644 %s\t%s\0" % (hashes[":" + str(mark)], name)
                                                      for name, mark in names),
                                        capture_output=True, text=True)
                if staged.returncode:
                    return log("Findings source staging failed: " + staged.stderr.strip()[-300:])
                log("Prepared %d readable library sources." % len(names))
        findings = root / 'local/findings'
        portable = [findings / 'README.md', findings / '.gitignore',
                    findings / 'agent-memory/lessons.json',
                    *[path for folder in ('.github', 'units', 'data')
                      for path in sorted((findings / folder).rglob('*'))]]
        package = findings / '2008-06'
        package_index = package / 'package.json'
        if package_index.is_file():
            portable.append(package_index)
            for relative in json.loads(package_index.read_text(encoding='utf-8'))['files']:
                path = (package / relative).resolve()
                if not path.is_relative_to(package.resolve()) or not path.is_file():
                    return log('Findings package file unavailable: ' + relative)
                portable.append(path)
        # One pack/index update instead of two Git processes per source/artifact.
        with tempfile.TemporaryDirectory(prefix="findings-portable-", dir=root / "work") as temporary:
            marks, staged = Path(temporary) / 'marks', []
            with tempfile.TemporaryFile(dir=temporary) as stream:
                for path in portable:
                    if not path.is_file():
                        continue
                    data = path.read_bytes()
                    mark = len(staged) + 1
                    relative = path.relative_to(findings).as_posix()
                    if relative == 'agent-memory/lessons.json':
                        relative = 'data/lessons.json'
                    staged.append((relative, mark))
                    stream.write(('blob\nmark :%d\ndata %d\n' % (mark, len(data))).encode('ascii'))
                    stream.write(data)
                    stream.write(b'\n')
                stream.write(b'done\n')
                stream.seek(0)
                packed = subprocess.run([git_exe, 'fast-import', '--quiet', '--done', '--export-marks=' + str(marks)],
                                        cwd=root, env=env, stdin=stream, capture_output=True, text=True)
            if packed.returncode:
                return log('Findings evidence packing failed: ' + packed.stderr.strip()[-300:])
            hashes = dict(line.split() for line in marks.read_text().splitlines())
            updated = subprocess.run([git_exe, 'update-index', '-z', '--index-info'], cwd=root, env=env,
                input=''.join('100644 %s\t%s\0' % (hashes[':' + str(mark)], name) for name, mark in staged),
                capture_output=True, text=True)
            if updated.returncode:
                return log('Findings evidence staging failed: ' + updated.stderr.strip()[-300:])
        tree = git("write-tree")
        if tree.returncode:
            return log("Findings tree creation failed: %s" % tree.stderr.strip()[-300:])
        tree = tree.stdout.strip()
        old_tree = git("rev-parse", parent + "^{tree}")
        if tree == old_tree.stdout.strip():
            return
        commit = git("commit-tree", tree, "-p", parent, "-m", "Publish recovered findings")
        if commit.returncode:
            return log("Findings commit failed: %s" % commit.stderr.strip()[-300:])
        pushed = git("push", "findings", commit.stdout.strip() + ":refs/heads/main")
        log("Findings published." if not pushed.returncode else "Findings push failed: %s" % pushed.stderr.strip()[-300:])
    finally:
        if index.exists():
            index.unlink()

