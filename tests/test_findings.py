"""Source publication includes unfinished server submissions."""
import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import Mock, patch

from roc import server


class FindingsTests(unittest.TestCase):
    def test_sync_includes_zero_and_partial_preserves_better_local(self):
        store = Mock()
        store.scores.return_value = {"client": {}}
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
