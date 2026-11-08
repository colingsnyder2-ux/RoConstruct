"""Lease overload must fail quickly instead of piling up behind the DB lock."""
import threading
import unittest
import sqlite3
import tempfile
import json
from urllib.error import HTTPError
from urllib.request import Request, urlopen
from concurrent.futures import ThreadPoolExecutor
from http.server import ThreadingHTTPServer

from roc.leases import Leases
from roc.server import make_handler
from roc.worker import Api, ApiFailure


class LeaseQueueTests(unittest.TestCase):
    def test_commit_failure_rolls_back_file_lease(self):
        db = sqlite3.connect(':memory:')
        class FailingCommit:
            fail = False
            def __getattr__(self, name):
                return getattr(db, name)
            def commit(self):
                if self.fail:
                    raise sqlite3.OperationalError('commit failed')
                db.commit()
        proxy = FailingCommit()
        leases = Leases(proxy)
        proxy.fail = True
        try:
            with self.assertRaises(sqlite3.OperationalError):
                leases.take('Alice', 'lease-test', ['rebuild/foo.cpp'])
            self.assertFalse(db.in_transaction)
            self.assertEqual(leases.active(), [])
        finally:
            db.close()

    def test_file_lease_database_failure_returns_retryable_error(self):
        class BrokenLeases:
            def active(self):
                raise sqlite3.OperationalError('database is locked')
            def take(self, *args):
                raise sqlite3.OperationalError('database is locked')
        class Store:
            lock = threading.Lock()
            file_leases = BrokenLeases()
        server = ThreadingHTTPServer(('127.0.0.1', 0), make_handler(Store(), None, set(), integration=object()))
        thread = threading.Thread(target=server.serve_forever, daemon=True)
        thread.start()
        url = 'http://127.0.0.1:%d/v1/leases' % server.server_port
        requests = [Request(url), Request(url + '/take', data=json.dumps({'user': 'Alice', 'name': 'foo',
                    'patterns': ['rebuild/foo.cpp']}).encode(), headers={'Content-Type': 'application/json'})]
        try:
            for request in requests:
                with self.assertRaises(HTTPError) as caught:
                    urlopen(request, timeout=3)
                self.assertEqual(caught.exception.code, 503)
                self.assertIn('retry', caught.exception.read().decode().lower())
        finally:
            server.shutdown()
            server.server_close()
            thread.join()

    def test_conflicting_leases_are_atomic_across_connections(self):
        with tempfile.TemporaryDirectory() as folder:
            path = folder + '/leases.db'
            first_db = sqlite3.connect(path, check_same_thread=False, timeout=3)
            second_db = sqlite3.connect(path, check_same_thread=False, timeout=3)
            first, second = Leases(first_db), Leases(second_db)
            read_done, release, started = threading.Event(), threading.Event(), threading.Event()
            method_name = '_active' if hasattr(first, '_active') else 'active'
            original = getattr(first, method_name)
            def paused(now=None):
                rows = original(now)
                read_done.set()
                if not release.wait(3):
                    raise RuntimeError('test timed out waiting to release first lease')
                return rows
            setattr(first, method_name, paused)
            def take(store, user):
                if user == 'Bob':
                    started.set()
                try:
                    store.take(user, 'race-' + user, ['rebuild/shared.cpp'])
                    return 'granted'
                except PermissionError:
                    return 'conflict'
            try:
                with ThreadPoolExecutor(max_workers=2) as pool:
                    one = pool.submit(take, first, 'Alice')
                    self.assertTrue(read_done.wait(3))
                    two = pool.submit(take, second, 'Bob')
                    self.assertTrue(started.wait(3))
                    try:
                        two.result(timeout=0.2)
                    except TimeoutError:
                        pass
                    finally:
                        release.set()
                    self.assertEqual(sorted([one.result(), two.result()]), ['conflict', 'granted'])
            finally:
                release.set()
                first_db.close()
                second_db.close()

    def test_file_lease_endpoint_uses_store_lock(self):
        class TrackingLock:
            def __init__(self):
                self.lock = threading.Lock()
                self.entries = 0
            def __enter__(self):
                self.lock.acquire()
                self.entries += 1
            def __exit__(self, *args):
                self.lock.release()
        class Store:
            def __init__(self):
                self.db = sqlite3.connect(':memory:', check_same_thread=False)
                self.lock = TrackingLock()
        store = Store()
        server = ThreadingHTTPServer(('127.0.0.1', 0), make_handler(store, None, set(), integration=object()))
        thread = threading.Thread(target=server.serve_forever, daemon=True)
        thread.start()
        api = Api('http://127.0.0.1:%d' % server.server_port)
        try:
            self.assertEqual(api.call('/v1/leases'), {'leases': []})
            self.assertGreaterEqual(store.lock.entries, 2)
        finally:
            if api._conn:
                api._conn.close()
            server.shutdown()
            server.server_close()
            thread.join()
            store.db.close()

    def test_conflicting_file_leases_are_atomic(self):
        db = sqlite3.connect(':memory:', check_same_thread=False)
        leases = Leases(db)
        method_name = '_active' if hasattr(leases, '_active') else 'active'
        original = getattr(leases, method_name)
        first_ident = []
        read_done, release, second_started = threading.Event(), threading.Event(), threading.Event()

        def paused(now=None):
            rows = original(now)
            if first_ident and threading.get_ident() == first_ident[0]:
                read_done.set()
                if not release.wait(3):
                    raise RuntimeError('test timed out waiting to release first lease')
            return rows

        setattr(leases, method_name, paused)
        def take(user):
            if user == 'Alice':
                first_ident.append(threading.get_ident())
            else:
                second_started.set()
            try:
                leases.take(user, 'race-' + user, ['rebuild/2008-06/native-classes/Foo.cpp'])
                return 'granted'
            except PermissionError:
                return 'conflict'

        try:
            with ThreadPoolExecutor(max_workers=2) as pool:
                first = pool.submit(take, 'Alice')
                self.assertTrue(read_done.wait(3))
                second = pool.submit(take, 'Bob')
                self.assertTrue(second_started.wait(3))
                try:
                    second.result(timeout=0.2)
                except TimeoutError:
                    pass
                finally:
                    release.set()
                self.assertEqual(sorted([first.result(), second.result()]), ['conflict', 'granted'])
                self.assertEqual(len(leases.active()), 1)
        finally:
            release.set()
            db.close()

    def test_file_leases_share_database_lock_and_release_concurrently(self):
        db = sqlite3.connect(':memory:', check_same_thread=False)
        lock = threading.Lock()
        leases = Leases(db, lock)
        try:
            for i in range(12):
                leases.take('Alice', 'lease-%02d' % i, ['rebuild/file-%02d.cpp' % i])
            started, finished = threading.Event(), threading.Event()
            def read():
                started.set()
                leases.active()
                finished.set()
            with ThreadPoolExecutor(max_workers=12) as pool:
                with lock:
                    reader = pool.submit(read)
                    self.assertTrue(started.wait(2))
                    self.assertFalse(finished.wait(0.1))
                reader.result()
                results = list(pool.map(lambda i: leases.renew('Alice', 'lease-%02d' % i, release=True), range(12)))
            self.assertTrue(all(result['released'] for result in results))
            self.assertEqual(leases.active(), [])
        finally:
            db.close()

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
                return {"ok": True, "clients": []}

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
                        self.assertEqual(api.call("/v1/status"), {"ok": True, "clients": []})
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
