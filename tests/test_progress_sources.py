"""Original source links preserve recipe versions and upstream revisions."""
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from roc import libs, progress


class SourceLinksTests(unittest.TestCase):
    def test_unchanged_build_preserves_progress_and_history(self):
        with tempfile.TemporaryDirectory() as folder, \
             patch.object(progress, "DOCS", Path(folder)), \
             patch.object(progress.clients, "load", return_value={}), \
             patch.object(progress, "library_meta", return_value={}), \
             patch.object(progress, "source_links", return_value={}), \
             patch.object(progress, "head_commit", return_value=("abc", "test")), \
             patch.object(progress.time, "strftime", side_effect=["first", "second", "third"]):
            remote = {"scores": {}, "leaderboard": []}
            progress.build(remote=remote)
            before = {p.name: p.read_bytes() for p in Path(folder).glob("*.json")}
            progress.build(remote=remote)
            self.assertEqual(before, {p.name: p.read_bytes() for p in Path(folder).glob("*.json")})
            changed = progress.build(remote=remote, public_server="https://new.example.com")
            self.assertEqual(changed["updated"], "third")

    def test_archive_and_commit_pinned_file(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "upstream/Source Files").mkdir(parents=True)
            recipes = {"archive": {"url": "https://example.com/v1.tar.gz"},
                       "clone": {"src": "upstream/Source Files"}, "generated": {}}
            replies = [str(root / "upstream"), "git@github.com:owner/repo.git", "abc123", ""]
            with patch.object(libs, "RECIPES", recipes), patch.object(libs, "LIBS", root), \
                 patch.object(progress.shutil, "which", return_value="git"), \
                 patch.object(progress.subprocess, "run", side_effect=[
                     SimpleNamespace(stdout=value) for value in replies]):
                links = progress.source_links()
            self.assertEqual(links["archive"]["kind"], "archive")
            self.assertEqual(links["clone"], {
                "kind": "file", "url": "https://github.com/owner/repo/blob/abc123/Source%20Files/", "files": []})
            self.assertNotIn("generated", links)

    def test_without_git_still_links_release_archives(self):
        with patch.object(libs, "RECIPES", {"lib": {"url": "https://example.com/v1.zip"}}), \
             patch.object(progress.shutil, "which", return_value=None):
            self.assertEqual(progress.source_links()["lib"]["url"], "https://example.com/v1.zip")

    def test_only_exact_tracked_source_paths_are_linked(self):
        import json
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "upstream/Source").mkdir(parents=True)
            (root / "data").mkdir()
            (root / "data/client.json").write_text(json.dumps({"funcs": [
                [1, 1, 100, 0, True, ["clone", "good.cpp"]],
                [2, 1, 100, 0, True, ["clone", "missing.cpp"]],
                [3, 1, 14, 0, True, ["clone", "partial.cpp"]]]}))
            replies = [str(root / "upstream"), "https://github.com/owner/repo.git",
                       "abc123", "Source/good.cpp\nSource/partial.cpp"]
            with patch.object(libs, "RECIPES", {"clone": {"src": "upstream/Source"}}), \
                 patch.object(libs, "LIBS", root), patch.object(progress, "DOCS", root), \
                 patch.object(progress.shutil, "which", return_value="git"), \
                 patch.object(progress.subprocess, "run", side_effect=[
                     SimpleNamespace(stdout=value) for value in replies]):
                self.assertEqual(progress.source_links()["clone"]["files"], ["good.cpp"])

    def test_template_methods_link_to_distinct_header_definitions(self):
        import json
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "upstream/Source").mkdir(parents=True)
            (root / "data").mkdir()
            symbols = ["?First@?$Tree@I@@", "?Second@?$Tree@I@@"]
            (root / "data/client.json").write_text(json.dumps({"funcs": [
                [i, 1, 100, 0, True, ["clone", "unit.cpp", symbol]] for i, symbol in enumerate(symbols)]}))
            replies = [str(root / "upstream"), "https://github.com/owner/repo.git", "abc123",
                       "Source/unit.cpp\nSource/DS_Tree.h",
                       "void Tree<T>::First() { return; }\nvoid Tree<T>::Second() { return; }"]
            with patch.object(libs, "RECIPES", {"clone": {"src": "upstream/Source"}}), \
                 patch.object(libs, "LIBS", root), patch.object(progress, "DOCS", root), \
                 patch.object(progress.shutil, "which", return_value="git"), \
                 patch.object(progress.subprocess, "run", side_effect=[
                     SimpleNamespace(stdout=value) for value in replies]):
                functions = progress.source_links()["clone"]["functions"]
                self.assertTrue(functions[symbols[0]].endswith("DS_Tree.h#L1"))
                self.assertTrue(functions[symbols[1]].endswith("DS_Tree.h#L2"))
