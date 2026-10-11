"""Real three-broker/process integration test, opt-in to avoid paid AI/live-server work.

ROC_CLUSTER_LIVE=1 ROC_NATS_SERVER=/path/to/nats-server python -m unittest
discover -s tests -p test_cluster_live.py -v
Requires installed compilers and one existing allowed exact source in work/server.db.
Uses independent temporary databases and ports; never submits to the campaign server.
"""
import json
import os
import sqlite3
import subprocess
import sys
import time
import unittest
import urllib.error
import urllib.request
import uuid
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

from roc import cluster, cluster_setup, cpu_jobs, cpu_worker, worker

ROOT = Path(__file__).resolve().parent.parent


@unittest.skipUnless(os.environ.get("ROC_CLUSTER_LIVE") == "1", "set ROC_CLUSTER_LIVE=1 for real failover test")
class LiveCluster(unittest.TestCase):
    def original(self):
        backups = sorted((ROOT / "work" / "backups").glob("server-before-*.db"))
        path = backups[-1] if backups else ROOT / "work" / "server.db"
        return sqlite3.connect(path.as_uri() + "?mode=ro", uri=True, timeout=30)

    def start_node(self, index):
        path = self.folder / ("node-%d" % (index + 1))
        log = open(path / ("server-%s.log" % time.time_ns()), "wb")
        self.logs.append(log)
        self.processes[index] = subprocess.Popen([sys.executable, "-X", "utf8", str(ROOT / "roc.py"),
                            "cluster", "start", "--config", str(path / "node.json")], cwd=ROOT,
                            stdout=log, stderr=subprocess.STDOUT,
                            creationflags=subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0,
                            start_new_session=os.name != "nt")

    def stop_node(self, index):
        process = self.processes.get(index)
        if not process or process.poll() is not None:
            return
        if os.name == "nt":
            subprocess.run(["taskkill", "/PID", str(process.pid), "/T", "/F"], capture_output=True)
        else:
            import signal
            os.killpg(process.pid, signal.SIGKILL)
        process.wait(10)

    def request(self, index, path, body=None, admin=False, request_id=None):
        data = json.dumps(body).encode() if body is not None else None
        contributor = json.loads((self.folder / "cpu-worker.json").read_text())
        token = self.config["admin_token" if admin else "worker_token"]
        if not admin and path in ("/v2/cpu/lease", "/v2/cpu/result", "/v2/cpu/heartbeat"):
            token = contributor["worker_token"]
            body = {**body, "worker": body.get("worker", contributor["worker"])}
        headers = {"X-Roc-Token": token, "Content-Type": "application/json"}
        if request_id:
            headers["X-Roc-Request"] = request_id
        try:
            response = urllib.request.urlopen(urllib.request.Request(self.config["servers"][index] + path, data, headers), timeout=20)
        except urllib.error.HTTPError as error:
            response = error
        with response:
            return response.status, json.loads(response.read())

    def ready(self, indexes):
        deadline = time.monotonic() + 100
        while time.monotonic() < deadline:
            try:
                if all(self.request(i, "/v2/cluster")[0] == 200 for i in indexes):
                    return
            except OSError:
                pass
            time.sleep(1)
        self.fail("Nodes failed startup; logs retained in %s" % self.folder)

    def test_real_compile_failover_replay_and_quorum(self):
        binary = os.environ.get("ROC_NATS_SERVER")
        if not binary:
            self.skipTest("set ROC_NATS_SERVER to approved NATS executable")
        self.folder = ROOT / "work" / ("cluster-test-" + uuid.uuid4().hex[:8])
        self.logs, self.processes = [], {}
        # Recheck one archived exact as a fixture. This is zero new campaign gains.
        original = self.original()
        rows = original.execute("SELECT client,addr,size,unit,source FROM funcs WHERE client='2008-06' AND score=100 AND size BETWEEN 6 AND 40 AND source NOT LIKE '%roc-lib%' AND source NOT LIKE '%standard library%' LIMIT 12").fetchall()
        original.close()
        fixture = None
        for row in rows:
            try:
                if cpu_jobs.check_many_text(row[0], [row[1]], row[4])[0][1] == 100:
                    fixture = row
                    break
            except BaseException as error:
                print("Fixture rejected:", str(error)[:120])
        if not fixture:
            self.skipTest("No locally verifiable exact fixture")
        client, addr, size, unit, source = fixture
        seed_file = ROOT / "work" / ("cluster-seed-" + uuid.uuid4().hex[:8] + ".db")
        seed = cluster.server.Store(str(seed_file), 120)
        seed.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)", (client, addr, size, unit))
        seed.db.commit()
        seed.db.close()
        cluster_setup.generate(self.folder, ["127.0.0.1"] * 3, str(seed_file), binary, local=True)
        for i in range(3):
            config_path = self.folder / ("node-%d" % (i + 1)) / "node.json"
            conf = json.loads(config_path.read_text())
            conf["validate_queue"] = False  # exercise provisional state before manual validation
            config_path.write_text(json.dumps(conf))
        self.config = cluster.load_config(self.folder / "node-1" / "node.json")
        try:
            for i in range(3):
                self.start_node(i)
            self.ready([0, 1, 2])
            self.assertEqual(cpu_worker.run(self.folder / "cpu-worker.json", jobs=1, log=lambda _: None), 0)
            self.assertEqual(self.request(0, "/v2/cpu/status")[1]["jobs"], {})
            enqueue = {"client": client, "source": source, "addrs": [addr], "user": "pilot", "model": "roc propagation"}
            self.assertEqual(self.request(0, "/v2/cpu/enqueue", enqueue)[0], 403)
            jobid = self.request(0, "/v2/cpu/enqueue", enqueue, admin=True)[1]["id"]
            # Genuine compile-once contribution; every result still provisional.
            self.assertEqual(cpu_worker.run(self.folder / "cpu-worker.json", enable=True, jobs=1, log=print), 1)
            self.assertEqual(self.request(1, "/v1/source?client=%s&addr=%s" % (client, addr))[1]["score"], 0)
            receipt = uuid.uuid4().hex
            code, result = self.request(0, "/v2/cpu/validate", {"id": jobid}, admin=True, request_id=receipt)
            self.assertEqual(code, 200)
            self.assertTrue(result["verified"])
            self.assertEqual(result["results"][0]["score"], 100)
            duplicate = self.request(2, "/v2/cpu/validate", {"id": jobid}, admin=True, request_id=receipt)
            self.assertEqual(duplicate, (code, result))
            self.assertEqual(self.request(0, "/v2/cpu/validate", {"id": "different"}, admin=True, request_id=receipt)[0], 409)
            # Concurrent coordinators must not lose queue jobs or produce duplicate credit.
            def enqueue_more(i):
                return self.request(i % 3, "/v2/cpu/enqueue", {**enqueue, "user": "pilot-%d" % i}, admin=True)
            with ThreadPoolExecutor(max_workers=6) as pool:
                self.assertTrue(all(code == 200 for code, _ in pool.map(enqueue_more, range(12))))
            self.stop_node(0)
            api = worker.Api(",".join(self.config["servers"]), self.config["worker_token"])
            self.assertEqual(api.call("/v1/source?client=%s&addr=%s" % (client, addr))["score"], 100)
            # POST failover also works, not only GETs.
            cpu_config = json.loads((self.folder / "cpu-worker.json").read_text())
            cpu_api = worker.Api(",".join(self.config["servers"]), cpu_config["worker_token"])
            self.assertIsNone(cpu_api.call("/v2/cpu/lease", {"enabled": False, "worker": cpu_config["worker"]})["job"])
            cpu_api.close()
            api.close()
            # Lost projection: restart must reconstruct accepted source and credit.
            db = self.folder / "node-1" / "projection.db"
            db.rename(db.with_suffix(".before-replay.db"))
            self.start_node(0)
            self.ready([0, 1, 2])
            self.assertEqual(self.request(0, "/v1/source?client=%s&addr=%s" % (client, addr))[1]["score"], 100)
            report = self.request(0, "/v1/daily-stats")[1]
            self.assertEqual(report["exacts"], 1)
            # Two dead voting nodes => no speculative local queue writes accepted.
            self.stop_node(0)
            self.stop_node(1)
            uncertain_receipt = uuid.uuid4().hex
            uncertain_job = {**enqueue, "user": "no-quorum"}
            self.assertEqual(self.request(2, "/v2/cpu/enqueue", uncertain_job, admin=True, request_id=uncertain_receipt)[0], 503)
            # A timed-out publish is uncertain, not proof that no record exists.
            # Minority must not project it; after quorum recovers retry the SAME
            # receipt, whether the pending broker entry committed or was discarded.
            probe = sqlite3.connect(self.folder / "node-3" / "projection.db")
            self.assertEqual(probe.execute("SELECT COUNT(*) FROM cpu_jobs WHERE state='queued'").fetchone()[0], 12)
            probe.close()
            self.start_node(0)
            self.start_node(1)
            self.ready([0, 1, 2])
            retry = self.request(2, "/v2/cpu/enqueue", uncertain_job, admin=True, request_id=uncertain_receipt)
            self.assertEqual(retry[0], 200)
            self.assertEqual(self.request(0, "/v2/cpu/enqueue", uncertain_job, admin=True, request_id=uncertain_receipt), retry)
            self.assertEqual(self.request(2, "/v2/cpu/status")[1]["jobs"].get("queued"), 13)
            self.assertEqual(self.request(2, "/v1/daily-stats")[1]["exacts"], 1)
            print("LIVE PASS: compile+trusted exact, CPU opt-out, auth, CAS contention, GET/POST failover, lost DB replay, quorum rejection; fixture %s:%s" % (client, addr))
        finally:
            for i in range(3):
                self.stop_node(i)
            for log in self.logs:
                log.close()

    def test_single_pc_automatic_validator_and_forged_score(self):
        binary = os.environ.get("ROC_NATS_SERVER")
        if not binary:
            self.skipTest("set ROC_NATS_SERVER")
        self.folder = ROOT / "work" / ("cluster-solo-test-" + uuid.uuid4().hex[:8])
        self.logs, self.processes = [], {}
        original = self.original()
        row = original.execute("SELECT client,addr,size,unit,source FROM funcs WHERE client='2008-06' AND addr='00401040'").fetchone()
        original.close()
        if not row or cpu_jobs.check_many_text(row[0], [row[1]], row[4])[0][1] != 100:
            self.skipTest("Missing verified pilot fixture")
        client, addr, size, unit, source = row
        seed_file = ROOT / "work" / ("cluster-solo-seed-" + uuid.uuid4().hex[:8] + ".db")
        seed = cluster.server.Store(str(seed_file), 120)
        seed.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)", (client, addr, size, unit))
        seed.db.commit()
        seed.db.close()
        cluster_setup.generate(self.folder, ["127.0.0.1"], str(seed_file), binary)
        self.config = cluster.load_config(self.folder / "node-1" / "node.json")
        try:
            self.start_node(0)
            self.ready([0])
            self.assertEqual(self.request(0, "/v2/cluster")[1]["replicas"], 1)
            enqueue = {"client": client, "source": source, "addrs": [addr], "user": "solo-pilot", "model": "roc propagation"}
            # A changed immediate can be a masked relocation in this fixture.
            # Change actual opcodes, not only a relocation-covered constant.
            wrong = 'extern "C" int unrelated(volatile int* x) { return *x + 123; }'
            self.assertLess(cpu_jobs.check_many_text(client, [addr], wrong)[0][1], 100)
            jobid = self.request(0, "/v2/cpu/enqueue", {**enqueue, "source": wrong}, admin=True)[1]["id"]
            self.assertEqual(self.request(0, "/v2/cpu/job-control", {"id": jobid, "action": "pause"}, admin=True)[0], 200)
            self.assertIsNone(self.request(0, "/v2/cpu/lease", {"enabled": True, "worker": "cpu-1", "clients": [client]})[1]["job"])
            self.request(0, "/v2/cpu/job-control", {"id": jobid, "action": "resume"}, admin=True)
            self.request(0, "/v2/cpu/control", {"worker": "cpu-1", "action": "off"}, admin=True)
            self.assertTrue(self.request(0, "/v2/cpu/lease", {"enabled": True, "worker": "cpu-1", "clients": [client]})[1]["disabled"])
            self.request(0, "/v2/cpu/control", {"worker": "cpu-1", "action": "on"}, admin=True)
            self.assertEqual(self.request(0, "/v2/cpu/lease", {"enabled": True, "worker": "fake-id", "clients": [client]})[0], 403)
            lease = self.request(0, "/v2/cpu/lease", {"enabled": True, "worker": "cpu-1", "clients": [client]})[1]["job"]
            self.assertIsNone(self.request(0, "/v2/cpu/lease", {"enabled": True, "worker": "cpu-1", "clients": [client]})[1]["job"])
            receipt = {"id": jobid, "worker": "cpu-1", "nonce": lease["nonce"], "result": {"scores": [{"addr": addr, "score": 100}]}}
            self.assertEqual(self.request(0, "/v2/cpu/result", {**receipt, "nonce": "foreign"})[0], 409)
            self.assertFalse(self.request(0, "/v2/cpu/result", receipt)[1]["verified"])
            self.assertEqual(self.request(0, "/v2/cpu/result", receipt)[0], 409)
            deadline = time.monotonic() + 60
            while time.monotonic() < deadline:
                if self.request(0, "/v2/cpu/status")[1]["jobs"].get("reported", 0) == 0:
                    break
                time.sleep(1)
            self.assertLess(self.request(0, "/v1/source?client=%s&addr=%s" % (client, addr))[1]["score"], 100)
            self.assertEqual(self.request(0, "/v1/daily-stats")[1]["exacts"], 0)
            self.request(0, "/v2/cpu/enqueue", enqueue, admin=True)
            self.assertEqual(cpu_worker.run(self.folder / "cpu-worker.json", enable=True, jobs=1, log=print), 1)
            deadline = time.monotonic() + 60
            while time.monotonic() < deadline:
                if self.request(0, "/v1/source?client=%s&addr=%s" % (client, addr))[1]["score"] == 100:
                    break
                time.sleep(1)
            self.assertEqual(self.request(0, "/v1/daily-stats")[1]["exacts"], 1)
            dashboard = self.request(0, "/v2/cpu/dashboard", admin=True)[1]
            self.assertEqual(sum(j["exact_gains"] for j in dashboard["jobs"]), 1)
            self.assertIn("pc", dashboard["nodes"][0]["metadata"])
            self.assertNotIn("source", dashboard["jobs"][0])
            self.assertEqual(self.request(0, "/v2/cpu/revoke", {"id": "cpu-1"}, admin=True)[0], 200)
            self.assertEqual(self.request(0, "/v2/cpu/lease", {"enabled": True, "worker": "cpu-1", "clients": [client]})[0], 403)
            print("SOLO PASS: one trusted PC, automatic validation, forged 100 rejected, foreign/stale nonce rejected")
        finally:
            self.stop_node(0)
            for log in self.logs:
                log.close()


if __name__ == "__main__":
    unittest.main()
