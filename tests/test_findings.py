"""Source publication includes unfinished server submissions."""
import json
import os
import tempfile
import unittest
from pathlib import Path
from unittest.mock import Mock, patch

from roc import libs, server


def test_findings_source_expands_recipe_only_wrappers(tmp_path):
    wrapper = "// from server: 41% by colin\n// roc-lib: ogre unit.cpp\n"
    (tmp_path / "ogre").mkdir()
    (tmp_path / "ogre/unit.cpp").write_text("int candidate() { return 42; }\n")
    with patch.object(libs, "LIBS", tmp_path), patch.object(libs, "RECIPES", {"ogre": {"src": "ogre"}}):
        expanded = server.findings_source(wrapper, {})
        assert expanded.startswith(wrapper)
        assert "int candidate() { return 42; }" in expanded
        assert server.findings_source(expanded, {}) == expanded
        assert server.findings_source("// target 007ab0a0\n" + wrapper, {}) == expanded
        assert "cached candidate" in server.findings_source(wrapper, {"ogre": {"unit.cpp": "cached candidate"}})
        assert server.findings_source(wrapper.replace("unit.cpp", "missing.cpp"), {}) == wrapper.replace("unit.cpp", "missing.cpp")
        assert server.findings_source(wrapper.replace("unit.cpp", "../../outside.cpp"), {}) == wrapper.replace("unit.cpp", "../../outside.cpp")
        handwritten = wrapper + "int hand_written() { return 7; }\n"
        assert server.findings_source(handwritten, {}) == handwritten


def test_progress_build_reads_local_sources_without_shadowing_clients(tmp_path, monkeypatch):
    from roc import progress
    monkeypatch.setattr(progress, "ROOT", tmp_path)
    monkeypatch.setattr(progress, "DOCS", tmp_path / "docs")
    monkeypatch.setattr(progress.clients, "load", lambda: {"test": {"compiler": "test compiler"}})
    monkeypatch.setattr(progress, "library_meta", lambda: {})
    monkeypatch.setattr(progress, "landmarks", lambda *a: [])
    monkeypatch.setattr(progress, "source_links", lambda: {})
    monkeypatch.setattr(progress, "add_history", lambda *a: None)
    work = tmp_path / "work/test"
    work.mkdir(parents=True)
    (work / "functions.jsonl").write_text(json.dumps(dict(addr="00401000", size=8, unit="G3D")) + "\n")
    (work / "scores.json").write_text(json.dumps({"00401000": 99}))
    sources = tmp_path / "src/test"
    sources.mkdir(parents=True)
    (sources / "00401000.cpp").write_text("int f() { return 1; }")
    result = progress.build(remote={"scores": {}, "leaderboard": []})
    assert result["clients"][0]["partial"] == 1
    data = json.loads((tmp_path / "docs/data/test.json").read_text())
    assert data["funcs"][0][4] is True


class FindingsTests(unittest.TestCase):
    def test_hourly_publish_syncs_sources_even_when_site_unchanged(self):
        from roc import progress, setup
        with tempfile.TemporaryDirectory() as folder, patch.object(server, "ROOT", Path(folder)), \
             patch.object(server, "sync_findings") as sync, \
             patch.object(server, "publish_findings") as publish, \
             patch.object(server, "publish_pages") as pages, \
             patch.object(server, "export", return_value={}), \
             patch.object(progress, "build"), patch.object(setup, "refresh_path"), \
             patch.object(setup, "find_exe", return_value="git"), \
             patch.object(server.subprocess, "run", return_value=Mock(returncode=0)) as git:
            store = Mock()
            server._publish_once(store, "https://example.com", log=Mock())
            sync.assert_called_once_with(store)
            publish.assert_called_once()
            pages.assert_called_once()
            commands = [call.args[0][1] for call in git.call_args_list]
            self.assertEqual(commands, ["push", "add", "diff"])

    def test_address_pushed_before_slow_source_sync(self):
        from roc import progress, setup
        with tempfile.TemporaryDirectory() as folder, patch.object(server, "ROOT", Path(folder)), \
             patch.object(server, "sync_findings") as sync, \
             patch.object(server, "publish_findings"), patch.object(server, "export", return_value={}), \
             patch.object(progress, "build"), patch.object(setup, "refresh_path"), \
             patch.object(setup, "find_exe", return_value="git"), \
             patch.object(server.subprocess, "run", return_value=Mock(returncode=0)) as git:
            path = Path(folder) / "docs/progress.json"
            path.parent.mkdir()
            path.write_text('{"server":"https://old.example","clients":[]}')
            sync.side_effect = lambda _: self.assertEqual(
                [call.args[0][1] for call in git.call_args_list], ["add", "commit", "push"])
            server._publish_once(Mock(), "https://new.example", log=Mock())
            self.assertEqual(json.loads(path.read_text())["server"], "https://new.example")

    def test_sync_includes_zero_and_partial_preserves_better_local(self):
        store = Mock()
        store.scores.return_value = {"client": {}}
        store.agent_memory.return_value = {"lessons": [], "records": [], "cursor": 0, "more": False}
        store.sources.return_value = [
            {"addr": "00000001", "score": 0, "user": "worker", "source": "draft"},
            {"addr": "00000002", "score": 65, "user": "worker", "source": "partial"},
            {"addr": "00000003", "score": 80, "user": "worker", "source": "older"},
        ]
        with tempfile.TemporaryDirectory() as folder, patch.object(server, "ROOT", Path(folder)):
            root = Path(folder)
            (root / "src/client").mkdir(parents=True)
            (root / "src/client/00000003.cpp").write_text("exact")
            (root / "work/client").mkdir(parents=True)
            (root / "work/client/scores.json").write_text('{"00000003":100}')
            server.sync_findings(store)
            self.assertIn("draft", (root / "src/client/00000001.cpp").read_text())
            self.assertIn("65%", (root / "src/client/00000002.cpp").read_text())
            self.assertEqual((root / "src/client/00000003.cpp").read_text(), "exact")
            self.assertEqual(json.loads((root / "work/client/scores.json").read_text()),
                             {"00000001": 0, "00000002": 65, "00000003": 100})
            server.sync_findings(store)
            self.assertEqual((root / "src/client/00000003.cpp").read_text(), "exact")
        store.sources.assert_called_with("client", min_score=0)


def test_publisher_stages_sources_and_portable_findings_files(tmp_path):
    import shutil
    import subprocess
    git = shutil.which("git")
    if not git:
        import pytest
        pytest.skip("git not installed")
    run = lambda cwd, *a: subprocess.run([git, *a], cwd=cwd, check=True, capture_output=True, text=True).stdout
    remote = tmp_path / "remote.git"
    run(tmp_path, "init", "-q", "--bare", "-b", "main", str(remote))
    seed = tmp_path / "seed"
    run(tmp_path, "init", "-q", "-b", "main", str(seed))
    (seed / "README.md").write_text("old")
    (seed / "roc.py").write_text("stale app copy")  # must not survive a publish
    run(seed, "add", ".")
    run(seed, "-c", "user.name=t", "-c", "user.email=t@t", "commit", "-qm", "seed")
    run(seed, "push", "-q", str(remote), "main")
    root = tmp_path / "root"
    run(tmp_path, "init", "-q", str(root))
    run(root, "remote", "add", "findings", str(remote))
    (root / "src" / "2008-06").mkdir(parents=True)
    (root / "src" / "2008-06" / "00401000.cpp").write_text("int f() { return 1; }\n")
    wrapper = "// from server: 41% by colin\n// roc-lib: test roc_unit_test.cpp\n"
    candidate = root / "src/2008-06/007ab0a0.cpp"
    candidate.write_text(wrapper)
    findings = root / "local" / "findings"
    (findings / ".github" / "workflows").mkdir(parents=True)
    (findings / "README.md").write_text("# RoConstruct findings\n")
    (findings / ".github" / "workflows" / "package.yml").write_text("name: x\n")
    (findings / "agent-memory").mkdir()
    (findings / "agent-memory" / "lessons.json").write_text("[]")
    (findings / "reports").mkdir()
    (findings / "reports" / "old.md").write_text("# old report")
    (findings / ".gitignore").write_text("*.log\n")
    (root / "work").mkdir()
    logs = []
    with patch.object(server, "ROOT", root), \
            patch.object(libs, "RECIPES", {"test": {"src": "test"}}), \
            patch.object(libs, "generated_units", return_value={"test": {"roc_unit_test.cpp": "int candidate() { return 2; }\n"}}), \
            patch.dict(os.environ, {"GIT_AUTHOR_NAME": "t", "GIT_AUTHOR_EMAIL": "t@t",
                                    "GIT_COMMITTER_NAME": "t", "GIT_COMMITTER_EMAIL": "t@t"}):
        server.publish_findings(git, logs.append)
    assert logs == ["Prepared 1 readable library sources.", "Findings published."]
    files = set(run(tmp_path, "--git-dir", str(remote), "ls-tree", "-r", "--name-only", "main").split())
    assert files == {"README.md", ".gitignore", ".github/workflows/package.yml", "agent-memory/lessons.json",
                     "reports/old.md", "src/2008-06/00401000.cpp", "src/2008-06/007ab0a0.cpp"}
    published = run(tmp_path, "--git-dir", str(remote), "show", "main:src/2008-06/007ab0a0.cpp")
    assert "41% by colin" in published
    assert "int candidate() { return 2; }" in published
    assert candidate.read_text() == wrapper
    assert run(tmp_path, "--git-dir", str(remote), "show", "main:README.md") == "# RoConstruct findings\n"
    assert not list((root / "work").glob("findings-index-*"))


def test_site_publish_commits_only_site_files(tmp_path):
    import shutil
    import subprocess
    git = shutil.which("git")
    if not git:
        import pytest
        pytest.skip("git not installed")
    run = lambda *a: subprocess.run([git, *a], cwd=tmp_path, check=True, capture_output=True, text=True).stdout
    run("init", "-q", "-b", "main")
    (tmp_path / "docs" / "data").mkdir(parents=True)
    (tmp_path / "docs" / "progress.json").write_text("{}")
    for name in ("data/2008-06.json", "source-links.json"):
        (tmp_path / "docs" / name).write_text("{}")
    (tmp_path / "other.py").write_text("x = 1\n")
    run("add", ".")
    run("-c", "user.name=t", "-c", "user.email=t@t", "commit", "-qm", "seed")
    (tmp_path / "docs" / "history.json").write_text("[]")
    (tmp_path / "other.py").write_text("x = 2\n")
    run("add", "other.py")  # a maintainer's staged work-in-progress
    calls = []
    real = subprocess.run

    def fake(argv, **kw):
        calls.append(argv)
        if "push" in argv or "fetch" in argv:
            return subprocess.CompletedProcess(argv, 0, "", "")
        return real(argv, **kw)
    with patch.object(server, "ROOT", tmp_path), patch.object(server, "publish_findings"), \
            patch.object(server, "sync_findings"), patch.object(server.subprocess, "run", side_effect=fake), \
            patch("roc.progress.build"), patch.object(server, "export", return_value={}), \
            patch("roc.setup.find_exe", return_value=git), patch("roc.setup.refresh_path"), \
            patch.dict(os.environ, {"GIT_AUTHOR_NAME": "t", "GIT_AUTHOR_EMAIL": "t@t",
                                    "GIT_COMMITTER_NAME": "t", "GIT_COMMITTER_EMAIL": "t@t"}):
        server._publish_once(Mock(), None, lambda *a: None)
    committed = run("show", "--name-only", "--format=", "HEAD").split()
    assert committed == ["docs/history.json"]
    assert run("diff", "--cached", "--name-only").split() == ["other.py"]  # still staged, not pushed


def test_pages_publish_is_one_parentless_commit_and_skips_guides(tmp_path):
    import shutil
    import subprocess
    git = shutil.which("git")
    if not git:
        import pytest
        pytest.skip("git not installed")
    run = lambda cwd, *a: subprocess.run([git, *a], cwd=cwd, check=True, capture_output=True, text=True).stdout
    remote = tmp_path / "remote.git"
    run(tmp_path, "init", "-q", "--bare", "-b", "main", str(remote))
    root = tmp_path / "root"
    run(tmp_path, "init", "-q", str(root))
    run(root, "remote", "add", "origin", str(remote))
    (root / "docs" / "data").mkdir(parents=True)
    (root / "docs" / "index.html").write_text("<html>")
    (root / "docs" / "data" / "2008-06.json").write_text("{}")
    (root / "docs" / "SETUP.md").write_text("guide")
    (root / "work").mkdir()
    logs = []
    env = {"GIT_AUTHOR_NAME": "t", "GIT_AUTHOR_EMAIL": "t@t", "GIT_COMMITTER_NAME": "t", "GIT_COMMITTER_EMAIL": "t@t"}
    with patch.object(server, "ROOT", root), patch.dict(os.environ, env):
        server.publish_pages(git, logs.append)
        (root / "docs" / "data" / "2008-06.json").write_text('{"changed": 1}')
        server.publish_pages(git, logs.append)
        server.publish_pages(git, logs.append)  # unchanged: no new commit
    assert logs == ["Website published.", "Website published.", "Website unchanged."]
    files = set(run(tmp_path, "--git-dir", str(remote), "ls-tree", "-r", "--name-only", "gh-pages").split())
    assert files == {"index.html", "data/2008-06.json", ".nojekyll"}  # guides stay on main
    assert run(tmp_path, "--git-dir", str(remote), "rev-list", "--count", "gh-pages").strip() == "1"
    assert not list((root / "work").glob("pages-index-*"))
