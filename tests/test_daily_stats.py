"""Daily credit is server verified, atomic, deduplicated, and DST aware."""
import tempfile
import json
import threading
import unittest
from http.server import ThreadingHTTPServer
from pathlib import Path
from unittest.mock import patch

from roc.daily_stats import archive_days, day_bounds, save
from roc.server import Store, make_handler
from roc.worker import Api
from roc.leaderboard import payload, publish_yesterday
from roc.discord import inline_code


class DailyStatsTests(unittest.TestCase):
    def test_verified_gains_and_attribution(self):
        with tempfile.TemporaryDirectory() as directory:
            store = Store(str(Path(directory) / "server.db"), 600)
            _, start, end = day_bounds("2026-10-11")
            try:
                for i, client in enumerate(("2008-06", "2008-06", "2008-06", "2009-12")):
                    store.db.execute("INSERT INTO funcs(client,addr,score) VALUES(?,?,0)", (client, str(i)))
                store.db.commit()
                with patch("roc.server.time.time", return_value=start + 10):
                    store.submit("2008-06", "0", "colin", 80, "partial", model="deepseek:flash", verified=True)
                    store.submit("2008-06", "0", "colin", 100, "exact", model="deepseek:flash", verified=True)
                    store.submit("2008-06", "0", "other", 100, "retry", model="roc propagation", verified=True)
                    store.submit("2008-06", "1", "other", 100, "exact", model="roc propagation", verified=True)
                    store.submit("2008-06", "2", "other", 100, "unverified", model="roc auto")
                    store.submit("2009-12", "3", "other", 100, "banned", model="roc auto", verified=True)
                report = store.daily_stats("2026-10-11")
                self.assertEqual(report["exacts"], 2)
                self.assertEqual(report["server_mining"], [{"name": "roc propagation", "exacts": 1}])
                self.assertEqual(report["people"][0]["models"][0]["name"], "deepseek:flash")
                self.assertEqual(len(report["gains"]), 2)
                self.assertEqual(store.db.execute("SELECT COUNT(*) FROM mining_events").fetchone()[0], 5)
                path = save(report, Path(directory) / "reports")
                self.assertTrue(path.with_suffix(".csv").exists())
                self.assertEqual(store.daily_stats("2026-10-12")["exacts"], 0)
            finally:
                store.db.close()

    def test_dst_day_lengths(self):
        _, start, end = day_bounds("2026-03-08")
        self.assertEqual(end - start, 23 * 3600)
        _, start, end = day_bounds("2026-11-01")
        self.assertEqual(end - start, 25 * 3600)

    def test_legacy_is_not_invented_credit(self):
        store = Store(":memory:", 600)
        try:
            _, start, _ = day_bounds("2026-10-11")
            store.db.execute("INSERT INTO events VALUES(?,?,?,?,?,?)", (start + 1, "2008-06", "0", "colin", 0, 100))
            report = store.daily_stats("2026-10-11")
            self.assertEqual(report["exacts"], 0)
            self.assertEqual(report["legacy_unattributed_exacts"], 1)
        finally:
            store.db.close()

    def test_http_single_and_batch_credit(self):
        store = Store(":memory:", 600)
        for addr in ("00000000", "00000001"):
            store.db.execute("INSERT INTO funcs(client,addr,score) VALUES('2008-06',?,0)", (addr,))
        store.db.commit()
        server = ThreadingHTTPServer(("127.0.0.1", 0), make_handler(store, None, {"2008-06"}))
        thread = threading.Thread(target=server.serve_forever, daemon=True)
        thread.start()
        api = Api("http://127.0.0.1:%d" % server.server_port)
        try:
            with patch("roc.server.match.check_text", return_value=(100, None, None, None)), patch("roc.server.check_many_text", return_value=[("00000001", 100, None)]):
                api.call("/v1/submit", {"client": "2008-06", "addr": "00000000", "user": "colin", "source": "void f(){}", "score": 100, "model": "deepseek:flash"})
                api.call("/v1/submit-batch", {"client": "2008-06", "addrs": ["00000001"], "user": "colin", "source": "void f(){}", "model": "roc propagation"})
            report = api.call("/v1/daily-stats")
            self.assertEqual(report["exacts"], 2)
            self.assertEqual(report["server_mining"][0]["name"], "roc propagation")
        finally:
            api._conn.close()
            server.shutdown()
            server.server_close()
            thread.join()
            store.db.close()

    def test_archive_rebuilds_stale_report_after_downtime(self):
        with tempfile.TemporaryDirectory() as directory:
            store = Store(":memory:", 600)
            day, start, _ = day_bounds("2026-10-01")
            try:
                save(store.daily_stats(day), directory)
                store.db.execute("INSERT INTO mining_events(ts,client,addr,user,model,old,new,verified) VALUES(?,?,?,?,?,?,?,?)",
                                 (start + 1, "2008-06", "0", "colin", "roc propagation", 0, 100, 1))
                archive_days(store, directory)
                report = json.loads((Path(directory) / (day + ".json")).read_text())
                self.assertEqual(report["exacts"], 1)
            finally:
                store.db.close()

    def test_webhook_demo_and_sent_marker(self):
        report = {"date": "2026-10-11", "timezone": "America/New_York", "exacts": 0,
                  "people": [], "models": [], "server_mining": [], "clients": [], "legacy_unattributed_exacts": 0}
        message = payload(report, demo=True)
        self.assertIn("DEMO", message["embeds"][0]["title"])
        self.assertEqual(message["allowed_mentions"]["parse"], [])
        self.assertEqual(message["embeds"][0]["footer"]["text"], "RoConstruct Server Mining")
        self.assertIn("timestamp", message["embeds"][0])
        report["server_mining"] = [{"name": "roc propagation", "exacts": 32}]
        report["people"] = [{"name": "colin", "exacts": 32, "models": [{"name": "roc propagation", "exacts": 32}]}]
        fields = payload(report)["embeds"][0]["fields"]
        self.assertEqual(fields[1]["value"], "`roc propagation` - 32")
        self.assertNotIn("`", fields[0]["value"])
        self.assertEqual(inline_code("roc repair"), "`roc repair`")
        store = Store(":memory:", 600)
        try:
            with tempfile.TemporaryDirectory() as directory, patch("roc.leaderboard.providers.secret", return_value="configured"), patch("roc.leaderboard.send", return_value=True) as send:
                publish_yesterday(store, directory)
                publish_yesterday(store, directory)
                send.assert_called_once()
        finally:
            store.db.close()


if __name__ == "__main__":
    unittest.main()
