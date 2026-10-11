"""Lease overload must fail quickly instead of piling up behind the DB lock."""
import threading
import unittest
from concurrent.futures import ThreadPoolExecutor
from http.server import ThreadingHTTPServer

from roc.server import make_handler
from roc.worker import Api, ApiFailure


class LeaseQueueTests(unittest.TestCase):
    def test_overload_is_bounded_and_status_remains_available(self):
        ready, release = threading.Event(), threading.Event()

        class Store:
            count = 0
            lock = threading.Lock()

            def lease(self, *args, **kwargs):
                with self.lock:
                    self.count += 1
                    if self.count == 8:
                        ready.set()
                release.wait(5)
                return None

            def status(self):
                return {"ok": True}

        server = ThreadingHTTPServer(("127.0.0.1", 0), make_handler(Store(), None, set()))
        thread = threading.Thread(target=server.serve_forever, daemon=True)
        thread.start()
        address = "http://127.0.0.1:%d" % server.server_port

        def lease():
            api = Api(address)
            try:
                return api.call("/v1/lease", {"user": "colin", "clients": ["C"]})
            finally:
                if api._conn:
                    api._conn.close()

        try:
            with ThreadPoolExecutor(max_workers=8) as pool:
                futures = [pool.submit(lease) for _ in range(8)]
                try:
                    self.assertTrue(ready.wait(3))
                    with self.assertRaisesRegex(ApiFailure, "lease queue busy"):
                        lease()
                    api = Api(address)
                    try:
                        self.assertEqual(api.call("/v1/status"), {"ok": True})
                    finally:
                        api._conn.close()
                finally:
                    release.set()
                self.assertTrue(all(f.result() == {"job": None} for f in futures))
        finally:
            server.shutdown()
            server.server_close()
            thread.join()


if __name__ == "__main__":
    unittest.main()
