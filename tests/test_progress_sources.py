"""Original source links preserve recipe versions and upstream revisions."""
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from roc import libs, progress


class SourceLinksTests(unittest.TestCase):
    def test_archive_and_commit_pinned_file(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "upstream/Source Files").mkdir(parents=True)
            recipes = {"archive": {"url": "https://example.com/v1.tar.gz"},
                       "clone": {"src": "upstream/Source Files"}, "generated": {}}
            replies = [str(root / "upstream"), "git@github.com:owner/repo.git", "abc123"]
            with patch.object(libs, "RECIPES", recipes), patch.object(libs, "LIBS", root), \
                 patch.object(progress.shutil, "which", return_value="git"), \
                 patch.object(progress.subprocess, "run", side_effect=[
                     SimpleNamespace(stdout=value) for value in replies]):
                links = progress.source_links()
            self.assertEqual(links["archive"]["kind"], "archive")
            self.assertEqual(links["clone"], {
                "kind": "file", "url": "https://github.com/owner/repo/blob/abc123/Source%20Files/"})
            self.assertNotIn("generated", links)

    def test_without_git_still_links_release_archives(self):
        with patch.object(libs, "RECIPES", {"lib": {"url": "https://example.com/v1.zip"}}), \
             patch.object(progress.shutil, "which", return_value=None):
            self.assertEqual(progress.source_links()["lib"]["url"], "https://example.com/v1.zip")
