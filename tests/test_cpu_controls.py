"""CPU controls, telemetry and provisional-score isolation; no paid calls."""
import hashlib
import json
import tempfile
import threading
import unittest
import urllib.error
import urllib.request
from http.server import ThreadingHTTPServer
from pathlib import Path
from unittest.mock import patch

from roc import cluster, command_watch, cpu_status, cpu_worker, match, task_files
from test_cluster import MemoryJournal


class CpuControls(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.replica = cluster.Replica({"db": str(Path(self.tmp.name) / "pilot.db")}, MemoryJournal())
        self.config = {"worker_token": "worker" * 8, "admin_token": "admin" * 8,
                       "node": "unit", "servers": [], "cluster_id": "unit", "replicas": 1}
        self.token = "cpu" * 16
        self.replica.run(lambda: self.replica.db.execute("INSERT INTO cluster_contributors VALUES('cpu-1',?,1)",
                        (hashlib.sha256(self.token.encode()).hexdigest(),)))
        self.replica.run(lambda: self.replica.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('2008-06','00401000',10,'Pilot')"))
        self.http = ThreadingHTTPServer(("127.0.0.1", 0), cluster.handler(self.replica, self.config, {"2008-06"}))
        threading.Thread(target=self.http.serve_forever, daemon=True).start()

    def tearDown(self):
        self.http.shutdown()
        self.http.server_close()
        self.replica.close()
        self.tmp.cleanup()

    def request(self, path, data=None, token=None):
        request = urllib.request.Request("http://127.0.0.1:%s%s" % (self.http.server_port, path),
                  None if data is None else json.dumps(data).encode(),
                  {"X-Roc-Token": token or self.config["admin_token"]})
        try:
            response = urllib.request.urlopen(request, timeout=3)
        except urllib.error.HTTPError as error:
            response = error
        with response:
            return response.code, json.loads(response.read())

    def test_pause_off_resume_and_only_verified_gains(self):
        job = self.request("/v2/cpu/enqueue", {"client": "2008-06", "source": "int f(){return 0;}",
                           "addrs": ["00401000"], "user": "pilot", "model": "roc propagation"})[1]["id"]
        lease = {"enabled": True, "worker": "cpu-1", "clients": ["2008-06"],
                 "metadata": {"pc": "pilot-pc", "owner": "pilot"}}
        self.assertEqual(self.request("/v2/cpu/dashboard", token=self.token)[1]["jobs"], [])
        self.assertFalse(self.request("/v2/cpu/dashboard", token=self.token)[1]["can_control"])
        self.assertEqual(self.request("/v2/cpu/control", {"worker": "cpu-1", "action": "off"}, self.token)[0], 403)
        self.assertEqual(self.request("/v2/cpu/job-control", {"id": job, "action": "pause"})[0], 200)
        self.assertIsNone(self.request("/v2/cpu/lease", lease, self.token)[1]["job"])
        self.request("/v2/cpu/job-control", {"id": job, "action": "resume"})
        self.request("/v2/cpu/control", {"worker": "cpu-1", "action": "pause"})
        self.assertTrue(self.request("/v2/cpu/lease", lease, self.token)[1]["paused"])
        self.request("/v2/cpu/control", {"worker": "cpu-1", "action": "off"})
        self.assertTrue(self.request("/v2/cpu/lease", lease, self.token)[1]["disabled"])
        self.request("/v2/cpu/control", {"worker": "cpu-1", "action": "on"})
        claimed = self.request("/v2/cpu/lease", lease, self.token)[1]["job"]
        receipt = {"id": job, "worker": "cpu-1", "nonce": claimed["nonce"]}
        self.request("/v2/cpu/control", {"worker": "cpu-1", "action": "off"})
        self.assertEqual(self.request("/v2/cpu/heartbeat", receipt, self.token)[0], 200)
        self.assertEqual(self.request("/v2/cpu/job-control", {"id": job, "action": "pause"})[0], 409)
        self.request("/v2/cpu/result", {**receipt, "result": {"scores": [{"addr": "00401000", "score": 100}]}}, self.token)
        view = self.request("/v2/cpu/dashboard")[1]
        self.assertEqual(view["nodes"][0]["metadata"]["pc"], "pilot-pc")
        self.assertEqual(view["jobs"][0]["exact_gains"], 0)
        self.assertEqual(view["jobs"][0]["completed"], 0)
        self.assertNotIn("source", view["jobs"][0])
        self.assertNotIn(self.token, json.dumps(view))
        with patch("roc.cluster.server.check_many_text", return_value=[("00401000", 100, [])]):
            self.assertTrue(self.request("/v2/cpu/validate", {"id": job})[1]["verified"])
        self.assertEqual(self.request("/v2/cpu/dashboard")[1]["jobs"][0]["exact_gains"], 1)
        self.assertTrue(self.request("/v2/cpu/validate", {"id": job})[1]["duplicate"])
        self.assertEqual(self.replica.db.execute("SELECT COUNT(*) FROM mining_events WHERE new=100").fetchone()[0], 1)


class LocalControls(unittest.TestCase):
    def test_windows_reader_lock_retries_atomic_write(self):
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / "status.json"
            path.write_text("old")
            original = Path.replace
            calls = []
            def replace(temporary, target):
                calls.append(temporary)
                if len(calls) == 1:
                    raise PermissionError("reader holds Windows file")
                return original(temporary, target)
            with patch.object(Path, "replace", replace), patch.object(task_files.time, "sleep"):
                task_files.write_text(path, "new")
            self.assertEqual(path.read_text(), "new")
            self.assertEqual(len(calls), 2)
            self.assertEqual(list(Path(folder).glob("*.tmp")), [])

    def test_config_controls_hide_credentials(self):
        with tempfile.TemporaryDirectory() as folder, patch.object(cpu_status, "ROOT", Path(folder)):
            path = Path(folder) / "work" / "helper-cpu.json"
            path.parent.mkdir()
            config = {"servers": ["localhost:1"], "worker_token": "private-token", "cpu_enabled": False, "worker": "helper"}
            path.write_text(json.dumps(config))
            key = next(iter(cpu_status.configs()))
            cpu_status.control({"config": key, "action": "on"})
            cpu_status.control({"config": key, "action": "pause"})
            self.assertTrue(json.loads(path.read_text())["cpu_paused"])
            cpu_status.control({"config": key, "action": "off"})
            self.assertFalse(json.loads(path.read_text())["cpu_enabled"])
            self.assertEqual(json.loads(path.read_text())["worker_token"], "private-token")
            with patch.object(cpu_status.worker.Api, "call", return_value={"nodes": [], "jobs": []}):
                self.assertNotIn("private-token", json.dumps(cpu_status.snapshot()))

    def test_command_pause_resume_stop_and_restore(self):
        with tempfile.TemporaryDirectory() as folder, patch.object(command_watch, "ROOT", Path(folder)):
            watch = command_watch.Watch("check")
            watch.install()
            try:
                watch.control_path.write_text("pause")
                with patch.object(command_watch.time, "sleep", side_effect=lambda _: watch.control_path.write_text("resume")):
                    watch.checkpoint()
                self.assertEqual(watch.state["status"], "running")
                watch.control_path.write_text("stop")
                watch.last_control = 0
                with self.assertRaises(KeyboardInterrupt):
                    watch.checkpoint()
            finally:
                original = watch.originals["target"]
                watch.finish("cancelled")
            self.assertIs(match.target, original)
            self.assertEqual(command_watch.tasks()[0]["status"], "cancelled")

    def test_progress_observer_preserves_comparator(self):
        payload = {"client": "2008-06", "addrs": ["00401000", "00402000"], "source": "source"}
        progress = []
        def compare(*_):
            for addr in payload["addrs"]:
                match.target(payload["client"], addr)
            return [(addr, 99, []) for addr in payload["addrs"]]
        with patch.object(match, "target", return_value=(b"", [], {"unit": "Pilot"})) as original, \
             patch.object(cpu_worker.cpu_jobs, "check_many_text", side_effect=compare):
            result = cpu_worker.compare(payload, lambda **state: progress.append(state))
            self.assertIs(match.target, original)
        self.assertEqual([p["checked"] for p in progress], [0, 1])
        self.assertEqual(result, [(addr, 99, []) for addr in payload["addrs"]])


if __name__ == "__main__":
    unittest.main()
