"""Dashboard/control regression tests. No provider calls, binaries or compilers."""
import json
import queue
import sys
import tempfile
import threading
import time
import unittest
import urllib.error
import urllib.request
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from roc import gui, gui_worker, link, worker


def config(**changes):
    return {**gui_worker.DEFAULTS, "user": "tester", "server": "localhost:8765", "source_only": True, **changes}


class ControlTests(unittest.TestCase):
    def test_function_timing_and_periodic_benchmark(self):
        events = []
        with patch.object(gui_worker.time, "monotonic", side_effect=[0, 1, 31, 32, 33]):
            control = gui_worker.Control(config(workers=4), lambda event, **fields: events.append((event, fields)))
            job = {"client":"2007-08", "addr":"00401000", "score":50, "unit":"Unit", "size":24}
            control.started(0, job)
            control.finished(0, job, 60)
            control.started(0, job)
            control.finished(0, job, 100)
        result = next(fields for event, fields in events if event == "job_finished")
        self.assertEqual(result["seconds"], 30)
        self.assertEqual(result["unit"], "Unit")
        reports = [fields for event, fields in events if event == "benchmark"]
        self.assertEqual(len(reports), 1)
        self.assertEqual(reports[0]["improved"], 1)
        self.assertEqual(reports[0]["workers"], 4)
        self.assertEqual(reports[0]["per_minute"], 1.9)

    def test_request_cap_finishes_session(self):
        events=[]
        control=gui_worker.Control(config(max_cloud_requests=2), lambda event, **fields: events.append(event))
        control.budget.requests=2
        control.finished(0, {"client":"2007-08","addr":"00401000","score":50}, 60)
        self.assertTrue(control.stopping)
        self.assertIn("job_finished", events)

    def test_process_controller_resizes_and_drains(self):
        class Input:
            def __init__(self):
                self.lines = queue.Queue()

            def readline(self):
                return self.lines.get()

            def __iter__(self):
                return self

            def __next__(self):
                return self.lines.get()

        stream = Input()
        stream.lines.put(json.dumps({"config": config()}) + "\n")
        started, stopped, errors = [], [], []

        def run(**options):
            slot, control = options["slot"], options["control"]
            started.append((slot, options["rounds"]))
            while control.before_lease(slot) is not None:
                control.wait(0.01)
            stopped.append(slot)

        def main():
            try:
                gui_worker.main()
            except BaseException as error:
                errors.append(error)

        def wait_for(predicate):
            deadline = time.time() + 3
            while not predicate() and time.time() < deadline:
                time.sleep(0.01)
            self.assertTrue(predicate())

        with patch.object(sys, "stdin", stream), patch.object(worker, "run", side_effect=run), \
             patch.object(worker, "keep_awake"), patch("builtins.print"):
            thread = threading.Thread(target=main, daemon=True)
            thread.start()
            try:
                wait_for(lambda: (0, 4) in started)
                stream.lines.put(json.dumps({"action": "update", "config": {"workers": 2, "rounds": 7}}))
                wait_for(lambda: (1, 7) in started)
                stream.lines.put(json.dumps({"action": "update", "config": {"workers": 1}}))
                wait_for(lambda: 1 in stopped)
            finally:
                stream.lines.put(json.dumps({"action": "stop"}))
                thread.join(3)
            self.assertFalse(thread.is_alive())
            self.assertEqual(errors, [])
            self.assertIn(0, stopped)

    def test_hundred_workers_resize_pause_and_stop(self):
        class Input:
            def __init__(self): self.lines=queue.Queue()
            def readline(self): return self.lines.get()
            def __iter__(self): return self
            def __next__(self): return self.lines.get()
        stream=Input();stream.lines.put(json.dumps({"config":config(workers=10)}))
        running=set();lock=threading.Lock();errors=[]
        def run(**options):
            slot,control=options["slot"],options["control"]
            with lock:running.add(slot)
            try:
                while control.before_lease(slot) is not None:control.wait(.01)
            finally:
                with lock:running.discard(slot)
        def main():
            try:gui_worker.main()
            except BaseException as error:errors.append(error)
        def wait_for(count):
            deadline=time.time()+10
            while len(running)!=count and time.time()<deadline:time.sleep(.01)
            self.assertEqual(len(running),count)
        with patch.object(sys,"stdin",stream),patch.object(worker,"run",side_effect=run),patch.object(worker,"keep_awake"),patch("builtins.print"):
            thread=threading.Thread(target=main,daemon=True);thread.start()
            try:
                wait_for(10)
                stream.lines.put(json.dumps({"action":"update","config":{"workers":100}}));wait_for(100)
                stream.lines.put(json.dumps({"action":"pause"}))
                stream.lines.put(json.dumps({"action":"update","config":{"workers":10}}));wait_for(10)
                stream.lines.put(json.dumps({"action":"resume"}))
            finally:
                stream.lines.put(json.dumps({"action":"stop"}));thread.join(10)
            self.assertFalse(thread.is_alive());self.assertEqual(errors,[]);self.assertEqual(running,set())

    def test_pause_resume_stop_and_retirement(self):
        events = []
        control = gui_worker.Control(config(workers=2), lambda kind, **fields: events.append((kind, fields)))
        control.command({"action": "pause"})
        result = []
        thread = threading.Thread(target=lambda: result.append(control.before_lease(0)))
        thread.start()
        self.assertTrue(thread.is_alive())
        control.command({"action": "resume"})
        thread.join(1)
        self.assertEqual(result[0]["workers"], 2)
        control.command({"action": "update", "config": {"workers": 1, "rounds": 7}})
        self.assertIsNone(control.before_lease(1))
        self.assertEqual(control.before_lease(0)["rounds"], 7)
        control.command({"action": "stop"})
        self.assertIsNone(control.before_lease(0))

    def test_budget_update_keeps_usage(self):
        control = gui_worker.Control(config(), lambda *args, **kw: None)
        control.budget.reserve(100, 0.01)
        control.command({"action": "update", "config": {"max_cloud_requests": 1}})
        self.assertEqual(control.budget.requests, 1)
        with self.assertRaises(gui_worker.providers.ProviderError):
            control.budget.reserve()

    def test_invalid_config_rejected_without_change(self):
        control = gui_worker.Control(config(), lambda *args, **kw: None)
        for changes in ({"workers": 0}, {"max_tokens": 9000}, {"server": "other:8765"},
                        {"max_cloud_cost": float("nan")}, {"min_score": 90, "max_score": 10}):
            with self.assertRaises(ValueError):
                control.command({"action": "update", "config": changes})
        self.assertEqual(control.revision, 1)

    def test_live_snapshot_reaches_lease_and_generation(self):
        control = gui_worker.Control(config(max_size=888, rounds=7, max_tokens=1024), lambda *args, **kw: None)
        calls = []
        job = dict(client="C", addr="00401000", size=4, score=0)

        class Api:
            def __init__(self, *args):
                pass

            def call(self, path, data=None):
                calls.append((path, data))
                return {"clients": {"C": {}}} if path == "/v1/info" else {"job": job}

        with patch.object(worker, "Api", Api), patch.object(worker, "usable_clients", return_value=["C"]), \
             patch.object(worker, "work_one", return_value=100) as work, \
             patch.object(worker, "save_session_state"), patch.object(worker.metrics, "summary", return_value=""):
            worker.run("localhost:8765", "tester", source_only=True, max_jobs=1, control=control, log=lambda msg: None)
        self.assertEqual(calls[1][1]["max_size"], 888)
        self.assertEqual(work.call_args.args[5], 7)
        self.assertEqual(work.call_args.args[-1]["max_tokens"], 1024)


class DashboardTests(unittest.TestCase):
    def test_every_dashboard_command_parses_in_real_cli(self):
        import importlib.util
        spec = importlib.util.spec_from_file_location("roc_gui_cli_test", gui.ROOT / "roc.py")
        cli = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cli)
        for name in gui.COMMANDS:
            data = dict(command=name, client="2008-06", accept_downloads=True)
            args = gui.command_args(data)
            with patch.object(cli, "cmd_" + name.replace("-", "_")) as command:
                cli.main(args)
                command.assert_called_once()
                if name in ("mass", "libs"):
                    self.assertEqual(command.call_args.args[0].client, "2008-06")

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.app = gui.Dashboard(directory=Path(self.temp.name))

    def tearDown(self):
        self.app.shutdown()
        deadline = time.time() + 3
        while self.app.processes and time.time() < deadline:
            time.sleep(0.02)
        self.temp.cleanup()

    def test_real_command_logs_and_persists(self):
        job_id = self.app.start({"kind": "command", "command": "model-stats"})
        deadline = time.time() + 10
        while self.app.jobs[job_id]["status"] in ("running", "queued") and time.time() < deadline:
            time.sleep(0.03)
        self.assertEqual(self.app.jobs[job_id]["status"], "completed")
        self.assertTrue((self.app.directory / (job_id + ".jsonl")).exists())
        saved = json.loads((self.app.directory / "history.json").read_text())
        self.assertEqual(saved[-1]["exit_code"], 0)

    def test_queue_waits_and_cancel_does_not_start(self):
        with patch.object(self.app, "schedule"):
            job_id = self.app.start({"command": "doctor"})
            self.app.control({"id": job_id, "action": "cancel"})
        self.assertEqual(self.app.jobs[job_id]["status"], "cancelled")

    def test_redaction_and_bounded_events(self):
        self.app.secret_values.append("example-secret-value")
        row = self.app.event(None, message="token example-secret-value")
        self.assertNotIn("example-secret-value", row["message"])
        for i in range(3100):
            self.app.event(None, message=str(i))
        self.assertEqual(len(self.app.events), 3000)
        self.assertEqual(len(self.app.snapshot()["events"]), 500)

    def test_event_burst_pages_without_skipping(self):
        for i in range(2000):self.app.event(None,message=str(i))
        seen=[];cursor=0
        while True:
            state=self.app.snapshot(cursor);seen.extend(r["seq"] for r in state["events"]);cursor=state["sequence"]
            if not state["more"]:break
        self.assertEqual(seen,list(range(1,2001)))

    def test_restart_marks_active_interrupted(self):
        with patch.object(self.app, "schedule"):
            job_id = self.app.start({"command": "doctor"})
        other = gui.Dashboard(directory=self.app.directory)
        self.assertEqual(other.jobs[job_id]["status"], "interrupted")

    def test_command_validation(self):
        for data in ({"command": "server"}, {"command": "analyze", "client": "../escape"},
                     {"command": "install"}, {"command": "repair", "client": "all"}):
            with self.assertRaises(ValueError):
                gui.command_args(data)

    def test_http_auth_origin_and_assets(self):
        server = gui.ThreadingHTTPServer(("127.0.0.1", 0), gui.Handler)
        server.dashboard = self.app
        thread = threading.Thread(target=server.serve_forever, daemon=True)
        thread.start()
        url = "http://127.0.0.1:%s" % server.server_port
        try:
            self.assertEqual(urllib.request.urlopen(url).status, 200)
            for asset in ("/fonts.css", "/logo.png", "/favicon.png", "/fonts/chakra-petch-700.ttf"):
                self.assertEqual(urllib.request.urlopen(url + asset).status, 200)
            with self.assertRaises(urllib.error.HTTPError) as error:
                urllib.request.urlopen(url + "/api/meta")
            self.assertEqual(error.exception.code, 403)
            req = urllib.request.Request(url + "/api/meta", headers={"X-ROC-Token": self.app.token})
            body = json.loads(urllib.request.urlopen(req).read())
            self.assertNotIn("token", body["initial"])
            req.add_header("Origin", "https://untrusted.example")
            with self.assertRaises(urllib.error.HTTPError) as error:
                urllib.request.urlopen(req)
            self.assertEqual(error.exception.code, 403)
            req = urllib.request.Request(url + "/api/state", headers={"X-ROC-Token": self.app.token, "Host": "evil.example"})
            with self.assertRaises(urllib.error.HTTPError):
                urllib.request.urlopen(req)
        finally:
            server.shutdown()
            server.server_close()


class LinkTests(unittest.TestCase):
    def test_web_uri_preserves_context_without_launching_worker(self):
        url = "roconstruct://work?client=2008-06&server=localhost:8765&user=tester&cloud=1"
        with patch.object(worker, "load_settings", return_value={}), patch.object(gui, "serve") as serve, \
             patch.object(link, "run") as terminal:
            link.launch(url, ask=lambda _: "2")
        self.assertEqual(serve.call_args.kwargs["initial"]["client"], "2008-06")
        self.assertTrue(serve.call_args.kwargs["initial"]["cloud_allowed"])
        terminal.assert_not_called()

    def test_saved_terminal_choice(self):
        url = "roconstruct://work?client=2008-06&server=localhost:8765"
        from roc import selfupdate
        with patch.object(worker, "load_settings", return_value={"uri_interface": "terminal"}), \
             patch.object(selfupdate, "try_update", return_value="unchanged"), patch.object(link, "run") as terminal:
            link.launch(url, ask=lambda _: self.fail("Should not ask"))
        terminal.assert_called_once_with(url)


if __name__ == "__main__":
    unittest.main()
