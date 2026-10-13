"""Dashboard/control regression tests. No provider calls, binaries or compilers."""
import json
import io
import queue
import sys
import tempfile
import threading
import time
import unittest
import urllib.error
import urllib.request
from pathlib import Path
from unittest.mock import Mock, patch

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from roc import gui, gui_worker, link, setup, worker


def config(**changes):
    return {**gui_worker.DEFAULTS, "user": "tester", "server": "localhost:8765", "source_only": True, **changes}


class ControlTests(unittest.TestCase):
    def test_already_exact_receipt_does_not_count_as_new_win(self):
        events = []
        control = gui_worker.Control(config(), lambda event, **fields: events.append((event, fields)))
        job = {"client": "C", "addr": "00401000", "score": 99,
               "receipt": {"verified": True, "improved": False, "stored": 100}}
        control.finished(0, job, 100)
        result = next(fields for event, fields in events if event == "job_finished")
        self.assertFalse(result["new_exact"])
        self.assertEqual(control.matched, 0)

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
        for changes in ({"workers": 0}, {"max_tokens": 40000}, {"server": "other:8765"},
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
             patch.object(worker, "save_session_state"), patch.object(worker.telemetry, "summary", return_value=""):
            worker.run("localhost:8765", "tester", source_only=True, max_jobs=1, control=control, log=lambda msg: None)
        self.assertEqual(calls[1][1]["max_size"], 888)
        self.assertEqual(work.call_args.args[5], 7)
        self.assertEqual(work.call_args.args[-1]["max_tokens"], 1024)


class DashboardTests(unittest.TestCase):
    def test_agent_worker_optional_goal(self):
        for goal in ("", "   ", "Match Ogre"):
            with patch.object(self.app, "schedule"):
                identifier = self.app.start({"kind": "agent_worker", "cli": "codex", "goal": goal})
            job = self.app.jobs[identifier]
            self.assertEqual(job["config"]["goal"], goal)
            self.assertIn("--continuous", job["args"])
            self.assertEqual("--automatic" in job["args"], not bool(goal.strip()))
            if goal.strip():
                self.assertEqual(job["args"][job["args"].index("--goal") + 1], goal)

    def test_automatic_mode_selects_library_campaigns(self):
        for mode in ("automatic", "fast", "balanced", "deep"):
            with patch.object(self.app, "schedule"):
                identifier = self.app.start({"kind": "agent_worker", "cli": "codex", "mode": mode})
            self.assertIn("--experimental", self.app.jobs[identifier]["args"])

    def test_agent_worker_joins_managed_worker_history(self):
        with patch.object(self.app, "schedule"):
            identifier = self.app.start({"kind": "agent_worker", "cli": "codex", "client": "2008-06", "workers": 3, "model": "chosen-model"})
        job = self.app.jobs[identifier]
        self.assertEqual(job["kind"], "agent_worker")
        self.assertEqual(job["config"]["workers"], 3)
        self.assertEqual(job["config"]["client"], "2008-06")
        self.assertIn("--automatic", job["args"])
        self.assertIn("chosen-model", job["args"])
        self.assertNotIn(self.app.worker_token or "NOT_A_TOKEN", job["args"])

    def test_agent_connection_fields_reach_cli_and_history(self):
        with patch.object(self.app, "schedule"):
            identifier = self.app.start({"kind": "agent_worker", "cli": "codex",
                "client": "2008-06", "user": "other-user", "server": "other-host:8765", "mode": "deep"})
        job = self.app.jobs[identifier]
        self.assertEqual(job["title"], "Agent · codex · 2008-06")
        self.assertEqual(job["config"]["user"], "other-user")
        self.assertEqual(job["config"]["server"], "other-host:8765")
        self.assertEqual(job["config"]["mode"], "deep")
        for key, value in (("--user", "other-user"), ("--server", "other-host:8765")):
            self.assertEqual(job["args"][job["args"].index(key) + 1], value)
        for overrides in ({"client": "unknown-client"}, {"user": "bad user"}, {"server": "bad host"}):
            with self.assertRaises(ValueError), patch.object(self.app, "schedule"):
                self.app.start({"kind": "agent_worker", "cli": "codex", **overrides})

    def test_unlimited_byte_limit_reaches_both_workers(self):
        self.assertEqual(gui_worker.validate(config(max_size=0), check_model=False)["max_size"], 0)
        with patch.object(self.app, "schedule"):
            identifier = self.app.start({"kind": "agent_worker", "cli": "claude", "client": "2008-06", "max_size": 0})
        args = self.app.jobs[identifier]["args"]
        self.assertEqual(args[args.index("--max-size") + 1], "0")

    def test_agent_selected_and_all_clients_reach_cli(self):
        for client in ("2008-06", "2009-12", ""):
            with patch.object(self.app, "schedule"):
                identifier = self.app.start({"kind": "agent_worker", "cli": "codex", "client": client})
            job = self.app.jobs[identifier]
            self.assertEqual(job["config"]["client"], client)
            self.assertEqual(job["args"][job["args"].index("--client") + 1], client or "all")

    def test_function_history_includes_shared_source_without_local_activity(self):
        row = dict(id="server:2009-12:00401000", client="2009-12", addr="00401000",
                   unit="Mined getter", score=100, base_score=None, started=10, model="alice", status="matched")
        self.app.initial["server"] = "localhost:8765"
        from roc import telemetry
        api = Mock()
        api.call.return_value = [row]
        with patch.object(worker, "Api", return_value=api), patch.object(telemetry, "read", return_value=[]):
            self.assertEqual(self.app.function_history(query="alice"), [row])
        self.assertIn("query=alice", api.call.call_args.args[0])
        api.close.assert_called_once()

    def test_research_command_uses_registered_recipe(self):
        from roc import research
        recipe = next(iter(json.loads(research.RECIPES_FILE.read_text(encoding="utf-8"))))
        self.assertEqual(gui.command_args(dict(command="research", research_action="plan", recipe=recipe)),
                         ["research", "plan", recipe])
        with self.assertRaises(ValueError):
            gui.command_args(dict(command="research", research_action="run", recipe="missing"))

    def test_every_dashboard_command_parses_in_real_cli(self):
        import importlib.util
        spec = importlib.util.spec_from_file_location("roc_gui_cli_test", gui.ROOT / "roc.py")
        cli = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cli)
        for name in gui.COMMANDS:
            data = dict(command=name, client="2008-06", accept_downloads=True, cli="claude", goal="match zlib")
            args = gui.command_args(data)
            with patch.object(cli, "cmd_" + name.replace("-", "_")) as command:
                cli.main(args)
                command.assert_called_once()
                if name in ("mass", "libs"):
                    self.assertEqual(command.call_args.args[0].client, "2008-06")

    def test_legacy_automatic_cli_defaults_to_2008(self):
        import importlib.util
        from roc import agent_auto
        spec = importlib.util.spec_from_file_location("roc_agent_scope_test", gui.ROOT / "roc.py")
        cli = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cli)
        for selected in (None, "2008-06", "2009-12", "all"):
            args = ["agent", "claude", "--automatic", "--server", "localhost:8765", "--user", "tester"]
            if selected:
                args += ["--client", selected]
            with patch.object(agent_auto, "run") as run:
                cli.main(args)
            self.assertEqual(run.call_args.kwargs["client"], selected or "2008-06")
            self.assertTrue(run.call_args.kwargs["experimental"])

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
        # Wait for the complete locked transition, including its atomic save.
        with self.app.lock:
            saved = json.loads((self.app.directory / "history.json").read_text())
        self.assertEqual(saved[-1]["exit_code"], 0)

    def test_queue_waits_and_cancel_does_not_start(self):
        with patch.object(self.app, "schedule"):
            job_id = self.app.start({"command": "doctor"})
            self.app.control({"id": job_id, "action": "cancel"})
        self.assertEqual(self.app.jobs[job_id]["status"], "cancelled")

    def test_agent_tabs_start_while_another_worker_is_running(self):
        first = Mock(pid=1001, stdin=io.StringIO())
        second = Mock(pid=1002, stdin=io.StringIO())
        with patch.object(gui.subprocess, "Popen", side_effect=[first, second]), \
             patch.object(gui.threading, "Thread"):
            one = self.app.start({"kind": "agent_worker", "cli": "codex", "client": "2008-06"})
            two = self.app.start({"kind": "agent_worker", "cli": "claude", "client": "2008-06"})
            self.assertEqual(self.app.jobs[one]["status"], "running")
            self.assertEqual(self.app.jobs[two]["status"], "running")
            self.assertEqual(len(self.app.processes), 2)
        self.app.processes.clear()
        for job in self.app.jobs.values():
            job["status"] = "completed"

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

    def test_live_snapshot_wakes_on_new_event(self):
        result = []
        thread = threading.Thread(target=lambda: result.append(self.app.snapshot(0, wait=1)))
        thread.start()
        self.app.event(None, message="Live output")
        thread.join(0.5)
        self.assertFalse(thread.is_alive())
        self.assertEqual(result[0]["events"][0]["message"], "Live output")

    def test_startup_logs_end_when_each_slot_leases_first_function(self):
        with patch.object(self.app, "schedule"):
            job_id = self.app.start({"kind": "worker", "config": config()})
            rows = [dict(event="log", slot=0, message="Worker ready"),
                    dict(event="job_started", slot=0, client="C", addr="00401000"),
                    dict(event="log", slot=0, message="compile chatter"),
                    dict(event="log", slot=1, message="Worker ready")]
            process = Mock(stdout=io.StringIO("".join("ROC_EVENT " + json.dumps(row) + "\n" for row in rows)), stdin=None)
            process.wait.return_value = 0
            self.app.consume(job_id, process)
        logs = [row for row in self.app.events if row["event"] == "log"]
        self.assertEqual([row["startup"] for row in logs], [True, False, True])

    def test_remove_finished_run_persists_and_rejects_active(self):
        with patch.object(self.app, "schedule"):
            job_id = self.app.start({"command": "doctor"})
        with self.assertRaises(ValueError):
            self.app.control({"id": job_id, "action": "remove"})
        self.app.jobs[job_id]["status"] = "completed"
        self.app.control({"id": job_id, "action": "remove"})
        self.assertNotIn(job_id, self.app.jobs)
        other = gui.Dashboard(directory=self.app.directory)
        self.assertNotIn(job_id, other.jobs)

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
            for asset in ("/fonts.css", "/logo.png", "/favicon.png", "/fonts/chakra-petch-700.woff2"):
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
    def test_server_uri_opens_setup_without_starting_worker(self):
        with patch.object(setup, "update", return_value="already current"), \
             patch.object(gui, "serve") as serve, patch.object(link, "run") as terminal:
            link.launch("roconstruct://server", ask=lambda _: self.fail("Should not ask"))
        serve.assert_called_once_with(page="cpu")
        terminal.assert_not_called()

    def test_server_uri_refuses_commands_and_credentials(self):
        for url in ("roconstruct://server?token=secret", "roconstruct://server?command=start", "roconstruct://server#secret"):
            with self.subTest(url=url), patch.object(setup, "update", return_value="already current"), \
                 patch.object(gui, "serve") as serve:
                with self.assertRaises(SystemExit):
                    link.launch(url)
                serve.assert_not_called()

    def test_web_uri_preserves_context_without_launching_worker(self):
        url = "roconstruct://work?client=2008-06&server=localhost:8765&user=tester&cloud=1"
        with patch.object(setup, "update", return_value="already current"), \
             patch.object(worker, "load_settings", return_value={}), patch.object(gui, "serve") as serve, \
             patch.object(link, "run") as terminal:
            link.launch(url, ask=lambda _: "2")
        self.assertEqual(serve.call_args.kwargs["initial"]["client"], "2008-06")
        self.assertTrue(serve.call_args.kwargs["initial"]["cloud_allowed"])
        terminal.assert_not_called()

    def test_saved_terminal_choice(self):
        url = "roconstruct://work?client=2008-06&server=localhost:8765"
        from roc import setup
        with patch.object(worker, "load_settings", return_value={"uri_interface": "terminal"}), \
             patch.object(setup, "update", return_value="unchanged"), patch.object(link, "run") as terminal:
            link.launch(url, ask=lambda _: self.fail("Should not ask"))
        terminal.assert_called_once_with(url)


if __name__ == "__main__":
    unittest.main()
