import subprocess
import tempfile
import threading
import unittest
from pathlib import Path
from unittest.mock import patch
from roc import telemetry


class ActivityTests(unittest.TestCase):
    def test_source_commands_and_thread_isolation(self):
        with tempfile.TemporaryDirectory() as tmp, patch.object(telemetry, "PATH", Path(tmp)/"history.sqlite"):
            telemetry.begin(dict(client="test", addr="00401000", unit="Example", source="before", score=30), "local", "session")
            identifier = telemetry.local.row["id"]
            thread = threading.Thread(target=lambda: telemetry.event("other thread"))
            thread.start()
            thread.join()
            telemetry.event("compile")
            telemetry.command(["cl", "f.cpp"], "temporary", subprocess.CompletedProcess([], 0, "compiled", ""))
            telemetry.candidate("better", 80)
            telemetry.candidate("worse", 50)
            telemetry.finish(30, "submit failed", [])
            row = telemetry.read(identifier)
            self.assertEqual(row["before"], "before")
            self.assertEqual(row["after"], "better")
            self.assertEqual(row["best_score"], 80)
            self.assertEqual(row["score"], 30)
            self.assertEqual(row["status"], "failed")
            self.assertEqual(len(row["timeline"]), 1)
            self.assertEqual(row["commands"][0]["argv"], ["cl", "f.cpp"])
            self.assertNotIn("after", telemetry.read()[0])
            self.assertIsNone(telemetry.local.row)
