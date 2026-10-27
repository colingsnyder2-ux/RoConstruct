"""Findings Git transport shared by server and independent hourly publisher."""
import hashlib
import json
import os
import re
from pathlib import Path
import subprocess
import tempfile
import uuid


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
