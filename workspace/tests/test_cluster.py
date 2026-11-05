"""Cluster state-machine tests; live broker/failover pilot lives in test_cluster_live.py."""
import json
import tempfile
import threading
import urllib.request
import unittest
import uuid
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
from http.server import ThreadingHTTPServer
from unittest.mock import patch

from roc import cluster


class Conflict(Exception):
    err_code = 10071


class MemoryJournal:
    def __init__(self):
        self.records = []
        self.fail = False

    def wait(self, value):
        return value

    def head(self):
        return len(self.records)

    def get(self, seq):
        return self.records[seq - 1]

    def append(self, record, expected):
        if self.fail:
            raise TimeoutError("no quorum")
        if expected != len(self.records):
            raise Conflict()
        self.records.append(record)
        return len(self.records)

    def close(self):
        pass


class ClusterTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.journal = MemoryJournal()
        self.a = cluster.Replica({"db": str(Path(self.tmp.name) / "a.db")}, self.journal)
        self.b = cluster.Replica({"db": str(Path(self.tmp.name) / "b.db")}, self.journal)

    def tearDown(self):
        self.a.close()
        self.b.close()
        self.tmp.cleanup()

    def seed(self):
        self.a.run(lambda: self.a.db.execute("INSERT INTO funcs(client,addr,size,unit) VALUES('2008-06','00401000',10,'Pilot')"))

    def test_agent_memory_replicates_without_duplicate_reports(self):
        report = {"kind": "trial", "client": "2008-06", "addresses": ["00401000"], "outcome": "no_gain"}
        self.a.run(lambda: self.a.store.remember("alice", [report]))
        rows = self.b.run(lambda: self.b.store.agent_memory())["records"]
        self.assertEqual(rows[0]["reported_by"], "alice")
        self.assertEqual(self.b.run(lambda: self.b.store.remember("alice", [report]))["added"], 0)

    def test_replay_after_publish_before_local_commit(self):
        self.seed()
        record = {"id": uuid.uuid4().hex, "identity": cluster.identity(),
                  "sql": ["UPDATE funcs SET score=88 WHERE addr='00401000'"]}
        self.journal.append(record, 1)  # publish succeeded, original coordinator died
        self.b.run(lambda: None)
        self.assertEqual(self.b.store.best("2008-06", "00401000")["score"], 88)
        self.a.run(lambda: None)
        self.assertEqual(self.a.store.best("2008-06", "00401000")["score"], 88)

    def test_no_quorum_rolls_back_score_and_credit(self):
        self.seed()
        self.journal.fail = True
        with self.assertRaises(RuntimeError):
            self.a.run(lambda: self.a.store.submit("2008-06", "00401000", "pilot", 100, "candidate", verified=True))
        self.assertEqual(self.a.store.best("2008-06", "00401000")["score"], 0)
        self.assertEqual(self.a.store.leaderboard(), [])

    def test_stale_node_retries_conflict_without_double_credit(self):
        self.seed()
        original = self.journal.append
        raced = [False]
        def race(record, expected):
            if not raced[0]:
                raced[0] = True
                # Another node committed between our read and CAS publication.
                self.b.run(lambda: self.b.store.submit("2008-06", "00401000", "other", 90, "partial", verified=True))
            return original(record, expected)
        with patch.object(self.journal, "append", race):
            self.a.run(lambda: self.a.store.submit("2008-06", "00401000", "pilot", 100, "exact", verified=True))
        self.b.run(lambda: None)
        self.assertEqual(self.b.store.best("2008-06", "00401000")["score"], 100)
        self.assertEqual(self.b.db.execute("SELECT COUNT(*) FROM mining_events WHERE new=100").fetchone()[0], 1)

    def test_mismatched_policy_refuses_replay(self):
        self.journal.records.append({"identity": "different-policy", "sql": []})
        with self.assertRaisesRegex(RuntimeError, "differs"):
            self.a.run(lambda: None)

    def test_slow_compile_does_not_block_status(self):
        self.seed()
        config = {"worker_token": "worker" * 8, "admin_token": "admin" * 8,
                  "node": "unit", "servers": [], "cluster_id": "unit", "replicas": 1}
        httpd = ThreadingHTTPServer(("127.0.0.1", 0), cluster.handler(self.a, config, {"2008-06"}))
        httpd.daemon_threads = True
        threading.Thread(target=httpd.serve_forever, daemon=True).start()
        started, finish = threading.Event(), threading.Event()
        def compile_slow(*_):
            started.set()
            finish.wait(5)
            return 100, None, None, []
        url = "http://127.0.0.1:%d" % httpd.server_port
        headers = {"X-Roc-Token": config["worker_token"]}
        def submit():
            body = json.dumps({"client": "2008-06", "addr": "00401000", "source": "int f(){return 0;}", "user": "pilot"}).encode()
            with urllib.request.urlopen(urllib.request.Request(url + "/v1/submit", body, headers), timeout=8) as response:
                return json.loads(response.read())
        try:
            with patch("roc.cluster.match.check_text", side_effect=compile_slow), ThreadPoolExecutor(max_workers=1) as pool:
                future = pool.submit(submit)
                self.assertTrue(started.wait(3))
                with urllib.request.urlopen(urllib.request.Request(url + "/v1/status", headers=headers), timeout=1) as response:
                    self.assertEqual(response.status, 200)
                finish.set()
                self.assertTrue(future.result()["verified"])
        finally:
            finish.set()
            httpd.shutdown()
            httpd.server_close()


if __name__ == "__main__":
    unittest.main()
