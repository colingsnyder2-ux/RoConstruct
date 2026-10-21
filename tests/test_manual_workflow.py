"""Manual-matching helpers: server function ranking/claiming for the agent loop.

`roc work CLIENT` selects and claims the next unmatched function from the server, so
these tests exercise the read-only /v1/functions ranking (twin detection, claimed
flags) and the soft /v1/claim endpoint without needing a client exe or compiler.
"""
import os
import tempfile
import threading
import unittest
from http.server import ThreadingHTTPServer

from roc.server import Store, make_handler
from roc.worker import Api, ApiFailure


def _seed(store):
    rows = [
        ("test", "004abc00", 40, "UnitA", 100, "void a(){}", "shapeX", "famA", 1, 3, 1, 0.5),
        ("test", "004abc10", 40, "UnitA", 98, "void b(){}", "shapeX", "famA", 2, 3, 1, 0.5),
        ("test", "004abc20", 40, "UnitA", 96, "void c(){}", "shapeY", "famA", 0, 3, 1, 0.5),
        ("test", "004abc30", 40, "UnitA", 93, "void d(){}", "shapeZ", "famB", 1, 3, 1, 0.5),
        ("test", "004abc40", 40, "UnitA", 50, "void e(){}", "shapeW", "famC", 5, 3, 1, 0.5),
        ("test", "004abc50", 40, "UnitA", 100, "void f(){}", "shapeY", "famD", 0, 3, 1, 0.5),
    ]
    with store.lock:
        store.db.executemany(
            "INSERT INTO funcs(client,addr,size,unit,score,source,shape,family,attempts,calls,source_confidence,difficulty) "
            "VALUES(?,?,?,?,?,?,?,?,?,?,?,?)", rows)
        store.db.commit()


class ManualWorkflowTests(unittest.TestCase):
    def setUp(self):
        self._tmp = tempfile.NamedTemporaryFile(suffix=".db", delete=False)
        self._tmp.close()
        self.path = self._tmp.name
        self.store = Store(self.path, 7200)
        _seed(self.store)

    def tearDown(self):
        self.store.db.close()
        os.remove(self.path)

    def test_functions_ranking_with_twins_and_claimed(self):
        rows = self.store.functions("test", max_score=99)
        by_addr = {r["addr"]: r for r in rows}
        # 100% functions are excluded
        self.assertNotIn("004abc00", by_addr)
        self.assertNotIn("004abc50", by_addr)
        # same-shape twin, then same-family twin, then none
        self.assertEqual(by_addr["004abc10"]["twin"], "004abc00")
        self.assertEqual(by_addr["004abc20"]["twin"], "004abc50")
        self.assertIsNone(by_addr["004abc30"]["twin"])
        self.assertIsNone(by_addr["004abc40"]["twin"])
        self.assertFalse(any(r["claimed"] for r in rows))
        # ranking order follows score DESC
        scores = [r["score"] for r in rows]
        self.assertEqual(scores, sorted(scores, reverse=True))

    def test_claim_is_soft_and_respects_other_workers(self):
        lease = self.store.claim("test", "004abc10", "alice")
        self.assertIn("lease", lease)
        # another worker cannot steal it
        self.assertIsNone(self.store.claim("test", "004abc10", "bob"))
        # same worker re-claims fine
        lease = self.store.claim("test", "004abc10", "alice")
        self.assertTrue(self.store.functions("test", max_score=99)[0]["claimed"]
                        or any(r["addr"] == "004abc10" and r["claimed"]
                               for r in self.store.functions("test", max_score=99)))
        self.store.release(lease["lease"])
        claimed = {r["addr"]: r["claimed"] for r in self.store.functions("test", max_score=99)}
        self.assertFalse(claimed["004abc10"])


class ManualWorkflowEndpointTests(unittest.TestCase):
    def setUp(self):
        self._tmp = tempfile.NamedTemporaryFile(suffix=".db", delete=False)
        self._tmp.close()
        self.store = Store(self._tmp.name, 7200)
        _seed(self.store)
        self.server = ThreadingHTTPServer(("127.0.0.1", 0), make_handler(self.store, None, set()))
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.thread.start()
        self.api = Api("http://127.0.0.1:%d" % self.server.server_port)

    def tearDown(self):
        self.api.close()
        self.server.shutdown()
        self.server.server_close()
        self.thread.join()
        self.store.db.close()
        os.remove(self._tmp.name)

    def test_functions_endpoint(self):
        rows = self.api.call("/v1/functions?client=test&max_score=99")
        self.assertEqual({r["addr"] for r in rows}, {"004abc10", "004abc20", "004abc30", "004abc40"})

    def test_claim_endpoint(self):
        result = self.api.call("/v1/claim", {"user": "alice", "worker": "alice",
                                             "client": "test", "addr": "004abc10"})
        self.assertIn("lease", result)
        with self.assertRaisesRegex(ApiFailure, "another worker"):
            self.api.call("/v1/claim", {"user": "bob", "worker": "bob",
                                        "client": "test", "addr": "004abc10"})
        with self.assertRaisesRegex(ApiFailure, "8 hex digits"):
            self.api.call("/v1/claim", {"user": "alice", "client": "test", "addr": "zzz"})


if __name__ == "__main__":
    unittest.main()
