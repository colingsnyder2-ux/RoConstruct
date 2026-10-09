import subprocess
import tempfile
import threading
import unittest
from pathlib import Path
from unittest.mock import patch
from roc import activity


class ActivityTests(unittest.TestCase):
    def test_source_commands_and_thread_isolation(self):
        with tempfile.TemporaryDirectory() as tmp, patch.object(activity, "PATH", Path(tmp)/"history.sqlite"):
            activity.begin(dict(client="test", addr="00401000", unit="Example", source="before", score=30), "local", "session")
            identifier = activity.local.row["id"]
            thread = threading.Thread(target=lambda: activity.event("other thread"))
            thread.start()
            thread.join()
            activity.event("compile")
            activity.command(["cl", "f.cpp"], "temporary", subprocess.CompletedProcess([], 0, "compiled", ""))
            activity.candidate("better", 80)
            activity.candidate("worse", 50)
            activity.finish(30, "submit failed", [])
            row = activity.read(identifier)
            self.assertEqual(row["before"], "before")
            self.assertEqual(row["after"], "better")
            self.assertEqual(row["best_score"], 80)
            self.assertEqual(row["score"], 30)
            self.assertEqual(row["status"], "failed")
            self.assertEqual(len(row["timeline"]), 1)
            self.assertEqual(row["commands"][0]["argv"], ["cl", "f.cpp"])
            self.assertNotIn("after", activity.read()[0])
            self.assertIsNone(activity.local.row)
