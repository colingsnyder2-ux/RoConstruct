"""Local ROC dashboard; stdlib HTTP, managed subprocesses, no web dependencies."""
import collections
import json
import mimetypes
import os
import secrets
import socket
import subprocess
import sys
import threading
import time
import uuid
import webbrowser
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlparse

from roc import chatgpt, clients, libraries, providers, worker
from roc.gui_worker import DEFAULTS, LIVE, validate

ROOT = Path(__file__).resolve().parent.parent
ASSETS = ROOT / "roc" / "web"
COMMANDS = {
    "mass": ("Mass match", "Runtime, STL, libraries, analysis and automatic matching", "all"),
    "libs": ("Library match", "Compile registered source recipes and match fingerprints", "all"),
    "analyze": ("Analyze", "Split a client binary into functions", "all"),
    "auto": ("Auto match", "Match deterministic function shapes", "all"),
    "xcopy": ("Cross-copy", "Reuse verified matches across compatible clients", "all"),
    "shapes": ("Shapes", "Inspect the most common unmatched assembly shapes", "all"),
    "repair": ("Repair", "Bounded compiler-backed mutations for partial matches", "one"),
    "check": ("Check source", "Compile sources and compare bytes", "one"),
    "pull": ("Pull sources", "Download shared sources; preserve existing files", "all"),
    "client-fetch": ("Fetch client", "Download binaries and verify registered hashes", "all"),
    "flags": ("Compiler flags", "Find compiler flags from known matches", "one"),
    "doctor": ("Doctor", "Check installation and explain repairs", "none"),
    "model-stats": ("Model stats", "Compare recorded worker performance", "none"),
    "family-stats": ("Family stats", "Inspect family coverage and exact rate", "none"),
    "failures": ("Failures", "Inspect recurring compile and provider failures", "none"),
    "status": ("Server status", "Read server progress and worker leaderboard", "none"),
    "install": ("Install tools", "Download exact compilers; no Ollama or Docker", "optional"),
    "agent": ("Agent", "Claude Code or Codex works a goal on your own plan", "none"),
}


def command_args(data):
    name, client = data.get("command"), data.get("client", "")
    if client == "2009-12":
        raise ValueError("Client excluded from mining")
    if name not in COMMANDS:
        raise ValueError("Unknown command")
    mode = COMMANDS[name][2]
    if mode in ("one", "all") and client not in clients.load() and not (mode == "all" and client == "all"):
        raise ValueError("Choose a registered client")
    args = [name] + ([client] if mode in ("one", "all") else [])
    if name == "mass":
        args = [name, "--client", client]
    if name == "libs":
        from roc import libs
        recipes = str(data.get("recipes", "all")).replace(",", " ").split()
        if not recipes or recipes != ["all"] and any(recipe not in libs.RECIPES for recipe in recipes):
            raise ValueError("Unknown library recipe; use all or registered recipe names")
        args = [name, *recipes, "--client", client]
    if name == "install":
        if data.get("accept_downloads") is not True:
            raise ValueError("Accept compiler downloads before running install")
        args += ["--yes"]
        if client and client != "all":
            if client not in clients.load():
                raise ValueError("Unknown client")
            args += ["--client", client]
    if name in ("check", "repair") and data.get("addr"):
        import re
        addr = data["addr"].lower().removeprefix("0x")
        if not re.fullmatch(r"[0-9a-f]{8}", addr):
            raise ValueError("Address needs eight hex digits")
        args += ([addr] if name == "check" else ["--addr", addr])
    if name == "repair":
        for key, low, high in (("limit", 1, 100000), ("min_score", 0, 100)):
            value = data.get(key, 20 if key == "limit" else 80)
            if type(value) is not int or not low <= value <= high:
                raise ValueError("Invalid %s" % key)
            args += ["--" + key.replace("_", "-"), str(value)]
        if data.get("permute"):
            args += ["--permute"]
    if name == "agent":
        goal, minutes = str(data.get("goal", "")).strip(), data.get("minutes", 120)
        if data.get("cli") not in ("claude", "codex"):
            raise ValueError("Choose claude or codex")
        if not goal or len(goal) > 2000:
            raise ValueError("Describe the goal (up to 2000 characters)")
        if type(minutes) is not int or not 1 <= minutes <= 600:
            raise ValueError("Minutes must be 1-600")
        args += [data["cli"], "--goal", goal, "--minutes", str(minutes)]
    return args


class Dashboard:
    def __init__(self, initial=None, directory=None):
        self.directory = directory or ROOT / "work" / "gui"
        self.directory.mkdir(parents=True, exist_ok=True)
        self.lock = threading.RLock()
        self.changed = threading.Condition(self.lock)
        self.jobs = {}
        self.processes = {}
        self.events = collections.deque(maxlen=3000)
        self.sequence = 0
        self.last_save = 0
        self.closed = False
        self.token = secrets.token_urlsafe(32)
        self.settings = worker.load_settings()
        self.initial = {**DEFAULTS, "user": self.settings.get("user", ""),
                        "server": self.settings.get("server", ""),
                        "client": self.settings.get("handoff_client", ""),
                        "model": self.settings.get("model", "") or "",
                        "cloud_allowed": bool(self.settings.get("cloud_allowed"))}
        self.worker_token = self.settings.get("token")
        if initial:
            self.initial.update({key: value for key, value in initial.items() if key in DEFAULTS})
            self.worker_token = initial.get("token", self.worker_token)
        self.secret_values = [self.worker_token] if self.worker_token else []
        self.secret_values += [providers.secret(config["key_env"]) for config in providers.providers().values()
                               if providers.key_available(config["key_env"])]
        self.preferences = self.read_json("preferences.json", {"presets": {}, "theme": "dark"})
        for job in self.read_json("history.json", []):
            if job["status"] in ("running", "queued", "paused", "stopping"):
                job["status"] = "interrupted"
                job["ended"] = time.time()
            self.jobs[job["id"]] = job

    def read_json(self, name, default):
        try:
            return json.loads((self.directory / name).read_text(encoding="utf-8"))
        except (OSError, ValueError):
            return default

    def write_json(self, name, data):
        path = self.directory / name
        temp = path.with_suffix(".tmp")
        temp.write_text(json.dumps(data, indent=1), encoding="utf-8")
        temp.replace(path)

    def redact(self, message):
        message = str(message)
        for secret in self.secret_values:
            if secret:
                message = message.replace(secret, "<redacted>")
        return providers.sanitize_prompt(message)

    def save(self):
        # Keep every active job plus the 100 most recent completed runs.
        active = [job for job in self.jobs.values() if job["status"] in ("queued", "running", "paused", "stopping")]
        old = [job for job in self.jobs.values() if job not in active][-100:]
        self.jobs = {job["id"]: job for job in old + active}
        self.write_json("history.json", list(self.jobs.values()))
        self.last_save = time.monotonic()

    def event(self, job_id, kind="log", **fields):
        with self.lock:
            self.sequence += 1
            if "message" in fields:
                fields["message"] = self.redact(fields["message"])
            row = dict(seq=self.sequence, time=time.time(), job=job_id, event=kind, **fields)
            self.events.append(row)
            self.changed.notify_all()
            if job_id:
                path = self.directory / (job_id + ".jsonl")
                if path.exists() and path.stat().st_size > 4 * 1024 * 1024:
                    path.replace(path.with_suffix(".previous.jsonl"))
                with path.open("a", encoding="utf-8") as out:
                    out.write(json.dumps(row) + "\n")
            return row

    def metadata(self):
        registry = clients.load()
        return {"initial": self.initial, "preferences": self.preferences,
                "uri_mode": self.settings.get("uri_interface", "ask"),
                "clients": [{"name": name, "compiler": row.get("compiler", ""),
                             "downloaded": clients.exe_path(name, row).exists(),
                             "analyzed": (ROOT / "work" / name / "functions.jsonl").exists()}
                            for name, row in sorted(registry.items())],
                "providers": [{"name": name, "ready": providers.provider_ready(name),
                               "auth": "chatgpt" if name == "chatgpt" else "api-key",
                               "models": ([model["slug"] for model in chatgpt.models(refresh=False)]
                                          if name == "chatgpt" else row.get("defaults", []))}
                              for name, row in providers.providers().items()],
                "libraries": libraries.NAMES,
                "commands": [{"name": name, "title": row[0], "description": row[1], "target": row[2]}
                             for name, row in COMMANDS.items()]}

    def snapshot(self, after=0, wait=0):
        with self.changed:
            if wait:
                self.changed.wait_for(lambda: self.sequence > after or self.closed, timeout=wait)
            pending = [row for row in self.events if row["seq"] > after]
            rows = pending[:500]
            return {"jobs": list(self.jobs.values()), "events": rows,
                    "sequence": rows[-1]["seq"] if rows else self.sequence, "more": len(pending) > 500}

    def start(self, data):
        with self.lock:
            if self.closed:
                raise ValueError("Dashboard is shutting down")
            if sum(job["status"] == "queued" for job in self.jobs.values()) >= 20:
                raise ValueError("Queue is full")
            kind = data.get("kind", "command")
            if kind == "worker":
                config = validate(data.get("config", {}))
                args = None
                title = "Worker · " + (config["client"] or "all clients")
            elif kind == "command":
                args, config = command_args(data), None
                title = COMMANDS[args[0]][0] + (" · " + data["client"] if data.get("client") else "")
            elif kind == "cpu":
                from roc import cpu_status
                found = cpu_status.configs()
                if data.get("config") not in found or "cpu_enabled" not in found[data["config"]][1]:
                    raise ValueError("Choose a local contributor config")
                path, saved = found[data["config"]]
                state_path = path.with_suffix(".status.json")
                state = json.loads(state_path.read_text()) if state_path.exists() else {}
                if state.get("stage") != "stopped" and time.time() - state.get("seen", 0) < 65:
                    raise ValueError("This CPU contributor already runs")
                cpu_status.control({"config": data["config"], "action": "on"})
                args, config = ["cpu-worker", "--config", str(path)], {"cpu_config": data["config"]}
                title = "CPU mining · " + saved.get("worker", path.stem)
            else:
                raise ValueError("Unknown job kind")
            job_id = uuid.uuid4().hex[:12]
            job = dict(id=job_id, title=title, kind=kind, args=args, config=config,
                       status="queued", created=time.time(), started=None, ended=None,
                       attempted=0, matched=0, improved=0, failed=0, slots={}, usage={}, revision=0)
            job.update(owner=(config or {}).get("user", self.initial.get("user") or os.environ.get("USERNAME", "local")),
                       pc=socket.gethostname())
            self.jobs[job_id] = job
            self.event(job_id, "state", message="Queued; jobs run serially to protect client files")
            self.save()
            self.schedule()
            return job_id

    def schedule(self):
        if self.closed or self.processes:
            return
        job = next((row for row in self.jobs.values() if row["status"] == "queued"), None)
        if job is None:
            return
        job_id = job["id"]
        argv = [sys.executable, "-u"] + (["-m", "roc.gui_worker"] if job["kind"] == "worker"
                                         else [str(ROOT / "roc.py"), *job["args"]])
        env = dict(os.environ, PYTHONIOENCODING="utf-8", PYTHONUNBUFFERED="1", ROC_GUI_EVENTS="1")
        env.update(ROC_TASK_ID=job_id, ROC_TASK_OWNER=job["owner"])
        try:
            process = subprocess.Popen(argv, cwd=ROOT, env=env, stdin=subprocess.PIPE,
                                       stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                                       encoding="utf-8", errors="replace", bufsize=1,
                                       creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
            self.processes[job_id] = process
            job.update(status="running", started=time.time(), pid=process.pid)
            if job["kind"] == "worker":
                process.stdin.write(json.dumps({"config": job["config"], "token": self.worker_token}) + "\n")
                process.stdin.flush()
            else:
                process.stdin.close()
        except OSError as error:
            job.update(status="failed", ended=time.time())
            self.event(job_id, "error", message=str(error))
            self.save()
            self.schedule()
            return
        self.event(job_id, "state", message="Started")
        self.save()
        threading.Thread(target=self.consume, args=(job_id, process), daemon=True).start()

    def consume(self, job_id, process):
        started_slots = set()
        for line in process.stdout:
            text = line.rstrip()
            if text.startswith("ROC_EVENT "):
                try:
                    fields = json.loads(text[10:])
                    kind = fields.pop("event")
                except (ValueError, KeyError):
                    kind, fields = "log", {"message": text}
            else:
                kind, fields = "log", {"message": text}
            with self.lock:
                job = self.jobs[job_id]
                if kind == "job_started":
                    started_slots.add(fields.get("slot"))
                elif kind == "log" and job["kind"] == "worker":
                    fields["startup"] = fields.get("slot") not in started_slots
                if kind == "control":
                    job.update(config=fields["config"], revision=fields["revision"],
                               status="stopping" if fields["stopping"] else "paused" if fields["paused"] else "running")
                    job.pop("pending", None)
                elif kind == "rejected":
                    job.pop("pending", None)
                elif kind == "applied":
                    job["slots"].setdefault(str(fields["slot"]), {}).update(revision=fields["revision"])
                elif kind == "job_started":
                    job["slots"].setdefault(str(fields["slot"]), {}).update(addr=fields["addr"], client=fields["client"], busy=True)
                elif kind == "job_finished":
                    job["attempted"] += 1
                    job["matched"] += fields["score"] == 100
                    job["improved"] += fields["score"] > fields["previous"] and fields["score"] != 100
                    job["failed"] += fields["score"] == 0
                    job["slots"].setdefault(str(fields["slot"]), {}).update(busy=False, score=fields["score"])
                elif kind == "slot_stopped":
                    job["slots"].pop(str(fields["slot"]), None)
                elif kind == "usage":
                    job["usage"] = fields
                elif kind == "stage":
                    job["stage"] = fields["message"]
                    if fields.get("task_status") in ("running", "paused") and job["status"] != "stopping":
                        job["status"] = fields["task_status"]
                self.event(job_id, kind, **fields)
                if kind != "log" and (kind in ("control", "rejected") or time.monotonic() - self.last_save >= 1):
                    self.save()
        code = process.wait()
        process.stdout.close()
        if process.stdin and not process.stdin.closed:
            process.stdin.close()
        with self.lock:
            job = self.jobs[job_id]
            job.update(status="cancelled" if job.get("cancelled") else "completed" if code == 0 else "failed",
                       ended=time.time(), exit_code=code, slots={})
            self.processes.pop(job_id, None)
            self.event(job_id, "state", message="%s (exit %s)" % (job["status"].capitalize(), code))
            self.save()
            self.schedule()

    def control(self, data):
        with self.lock:
            job = self.jobs.get(data.get("id"))
            if not job:
                raise ValueError("Unknown job")
            action = data.get("action")
            if action == "remove":
                if job["status"] in ("queued", "running", "paused", "stopping") or job["id"] in self.processes:
                    raise ValueError("Only finished runs can be removed")
                del self.jobs[job["id"]]
                self.save()
                self.event(None, "state", message="Run removed from history")
                return
            if action == "cancel" and job["status"] == "queued":
                job.update(status="cancelled", ended=time.time())
                self.save()
                return
            process = self.processes.get(job["id"])
            if not process or process.poll() is not None:
                raise ValueError("Job is not running")
            if action == "kill":
                job["cancelled"] = True
                job["status"] = "stopping"
                if os.name == "nt":
                    subprocess.run(["taskkill", "/PID", str(process.pid), "/T", "/F"],
                                   capture_output=True, creationflags=subprocess.CREATE_NO_WINDOW)
                else:
                    process.terminate()
                self.event(job["id"], "state", message="Immediate stop; cloud requests may still bill. Leases expire if not released.")
                return
            if job["kind"] == "cpu" and action in ("pause", "resume", "stop"):
                from roc import cpu_status
                cpu_status.control({"config": job["config"]["cpu_config"],
                                    "action": "off" if action == "stop" else action})
                job["status"] = {"pause": "paused", "resume": "running", "stop": "stopping"}[action]
                self.event(job["id"], "state", message="%s requested; active job finishes" % action.capitalize())
                self.save()
                return
            if job["kind"] == "command" and action in ("pause", "resume", "stop"):
                from roc import command_watch
                if job["args"][0] not in command_watch.COMMANDS:
                    raise ValueError("This command has no cooperative CPU checkpoints")
                command_watch.control(job["id"], action)
                job.update(status={"pause": "paused", "resume": "running", "stop": "stopping"}[action])
                if action == "stop":
                    job["cancelled"] = True
                self.event(job["id"], "state", message=action + " requested; applies at next target/compiler boundary")
                self.save()
                return
            if job["kind"] != "worker" or action not in ("pause", "resume", "stop", "update"):
                raise ValueError("Control is supported only for workers")
            if job["status"] == "stopping":
                raise ValueError("Worker is already stopping")
            command = {"action": action, "request": uuid.uuid4().hex[:8]}
            if action == "update":
                changes = data.get("config", {})
                if not isinstance(changes, dict) or set(changes) - LIVE:
                    raise ValueError("Only live settings can change during a session")
                validate(changes, job["config"])
                command["config"] = changes
                job["pending"] = changes
            process.stdin.write(json.dumps(command) + "\n")
            process.stdin.flush()

    def preferences_update(self, data):
        with self.lock:
            if data.get("uri_mode") in ("ask", "terminal", "web"):
                self.settings = worker.save_settings(uri_interface=data["uri_mode"])
            if data.get("theme") in ("light", "dark"):
                self.preferences["theme"] = data["theme"]
            if "preset" in data:
                name = str(data["preset"]).strip()[:60]
                if not name:
                    raise ValueError("Preset name required")
                config = validate(data.get("config", {}), check_model=False)
                self.preferences["presets"][name] = config
            self.write_json("preferences.json", self.preferences)

    def shutdown(self):
        with self.lock:
            self.closed = True
            self.changed.notify_all()
            for job in self.jobs.values():
                if job["status"] == "queued":
                    job.update(status="cancelled", ended=time.time())
            for job_id in list(self.processes):
                self.control({"id": job_id, "action": "kill"})
            self.save()


class Handler(BaseHTTPRequestHandler):
    def log_message(self, *args):
        pass

    def send(self, code, content, content_type="application/json"):
        if content_type == "application/json":
            content = json.dumps(content).encode()
        try:
            self.send_response(code)
            self.send_header("Content-Type", content_type)
            self.send_header("Content-Length", str(len(content)))
            self.send_header("Cache-Control", "no-store")
            self.send_header("X-Content-Type-Options", "nosniff")
            self.send_header("Content-Security-Policy", "default-src 'self'; script-src 'self'; style-src 'self'; connect-src 'self'; img-src 'self' data:; frame-ancestors 'none'")
            self.end_headers()
            self.wfile.write(content)
        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError):
            # Browser refresh/close can abort a long-poll response. The job
            # remains owned by the dashboard; there is nothing to report.
            return

    def authorized(self):
        host = "127.0.0.1:%d" % self.server.server_port
        if self.headers.get("Host") != host:
            return False
        origin = self.headers.get("Origin")
        if origin and origin != "http://" + host:
            return False
        return secrets.compare_digest(self.headers.get("X-ROC-Token", ""), self.server.dashboard.token)

    def do_GET(self):
        parsed = urlparse(self.path)
        if parsed.path.startswith("/api/"):
            if not self.authorized():
                return self.send(403, {"error": "Dashboard session required"})
            try:
                app = self.server.dashboard
                if parsed.path == "/api/meta":
                    return self.send(200, app.metadata())
                if parsed.path == "/api/state":
                    after = int(parse_qs(parsed.query).get("after", [0])[0])
                    wait = min(1, max(0, float(parse_qs(parsed.query).get("wait", [0])[0])))
                    return self.send(200, app.snapshot(after, wait))
                if parsed.path == "/api/functions":
                    from roc import activity
                    identifier = parse_qs(parsed.query).get("id", [None])[0]
                    return self.send(200, json.loads(app.redact(json.dumps(activity.read(identifier)))))
                if parsed.path == "/api/cpu":
                    from roc import cpu_status
                    selected = parse_qs(parsed.query).get("cluster", [None])[0]
                    return self.send(200, cpu_status.snapshot(selected))
                if parsed.path == "/api/models":
                    return self.send(200, {"models": worker.draft.ollama_models()})
                if parsed.path == "/api/daily-stats":
                    day = parse_qs(parsed.query).get("date", [""])[0]
                    from roc.daily_stats import day_bounds
                    day, _, _ = day_bounds(day or None)
                    address = app.initial.get("server") or app.settings.get("server")
                    if not address:
                        raise ValueError("Configure a group server first")
                    try:
                        report = worker.Api(address, app.worker_token).call("/v1/daily-stats?date=" + day, timeout=10)
                    except worker.ApiFailure as error:
                        return self.send(502, {"error": str(error)})
                    return self.send(200, report)
                if parsed.path == "/api/log":
                    job_id = parse_qs(parsed.query).get("id", [""])[0]
                    if job_id not in app.jobs:
                        raise ValueError("Unknown job")
                    path = app.directory / (job_id + ".jsonl")
                    previous = path.with_suffix(".previous.jsonl")
                    with app.lock:
                        content = (previous.read_bytes() if previous.exists() else b"") + (path.read_bytes() if path.exists() else b"")
                    return self.send(200, content, "text/plain; charset=utf-8")
            except (ValueError, OSError, RuntimeError) as error:
                return self.send(400, {"error": str(error)})
            return self.send(404, {"error": "Unknown endpoint"})
        files = {"/": "index.html", "/app.js": "app.js", "/style.css": "style.css",
                 "/fonts.css": "fonts.css", "/logo.png": "logo.png", "/favicon.png": "favicon.png"}
        files.update({"/fonts/" + path.name: "fonts/" + path.name for path in (ASSETS / "fonts").iterdir()
                      if path.suffix in (".woff2", ".ttf")})
        if parsed.path not in files:
            return self.send(404, {"error": "Not found"})
        file = ASSETS / files[parsed.path]
        content_type = mimetypes.guess_type(file.name)[0] or "application/octet-stream"
        self.send(200, file.read_bytes(), content_type + ("; charset=utf-8" if content_type.startswith("text/") else ""))

    def do_POST(self):
        if not self.authorized():
            return self.send(403, {"error": "Dashboard session required"})
        try:
            size = int(self.headers.get("Content-Length", "0"))
            if not 0 < size <= 65536:
                raise ValueError("Invalid request size")
            data = json.loads(self.rfile.read(size))
            if not isinstance(data, dict):
                raise ValueError("JSON object required")
            app = self.server.dashboard
            if self.path == "/api/start":
                return self.send(200, {"id": app.start(data)})
            if self.path == "/api/control":
                app.control(data)
            elif self.path == "/api/cpu-control":
                from roc import cpu_status
                return self.send(200, cpu_status.control(data))
            elif self.path == "/api/roc-control":
                from roc import command_watch
                command_watch.control(data.get("id", ""), data.get("action"))
            elif self.path == "/api/preferences":
                app.preferences_update(data)
            elif self.path == "/api/provider":
                config = providers.providers().get(data.get("provider"))
                if not config or not config.get("key_env") or not isinstance(data.get("key"), str) or not data["key"].strip():
                    raise ValueError("Provider and key required")
                providers.save_secret(config["key_env"], data["key"].strip())
                app.secret_values.append(data["key"].strip())
            elif self.path == "/api/preview":
                return self.send(200, {"args": command_args(data)})
            elif self.path == "/api/shutdown":
                app.shutdown()
                threading.Thread(target=self.server.shutdown, daemon=True).start()
            else:
                return self.send(404, {"error": "Unknown endpoint"})
            self.send(200, {"ok": True})
        except (ValueError, TypeError, KeyError, OSError, BrokenPipeError, RuntimeError) as error:
            self.send(400, {"error": str(error)})


def serve(port=0, open_browser=True, initial=None, page="overview"):
    app = Dashboard(initial)
    server = ThreadingHTTPServer(("127.0.0.1", port), Handler)
    server.dashboard = app
    url = "http://127.0.0.1:%d/" % server.server_port
    if page == "cpu":
        url += "?page=cpu"
    print("ROC dashboard: " + url, flush=True)
    print("Browser refresh/close keeps jobs running. Ctrl+C stops dashboard and jobs.", flush=True)
    if open_browser:
        webbrowser.open(url + "#" + app.token)
    else:
        # Only explicitly requested headless launches print the session link.
        print("Session link: " + url + "#" + app.token, flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        app.shutdown()
        server.server_close()


if __name__ == "__main__":
    serve()
