"""Local ROC task visibility; cooperative controls between compiler/target calls."""
import json
import os
import socket
import threading
import time
import uuid
from pathlib import Path

from roc import match, task_files

ROOT = Path(__file__).resolve().parent.parent
COMMANDS = {"mass", "libs", "analyze", "auto", "xcopy", "repair", "check", "flags"}


class Watch:
    def __init__(self, command):
        self.directory = ROOT / "work" / "roc-tasks"
        self.directory.mkdir(parents=True, exist_ok=True)
        self.id = os.environ.get("ROC_TASK_ID") or uuid.uuid4().hex[:12]
        self.path = self.directory / (self.id + ".json")
        self.control_path = self.directory / (self.id + ".control")
        self.state = dict(id=self.id, command="roc " + command, owner=os.environ.get("ROC_TASK_OWNER") or
                          os.environ.get("USERNAME") or os.environ.get("USER", "local"),
                          pc=socket.gethostname(), pid=os.getpid(), status="running", started=time.time(),
                          inspected=0, stage="Starting", flags="", addr="", client="", unit="")
        self.last = 0
        self.last_control = 0
        self.action = "resume"
        self.lock = threading.RLock()
        self.originals = {}
        self.seen = set()

    def save(self, force=False):
        with self.lock:
            if not force and time.monotonic() - self.last < 0.5:
                return
            self.last = time.monotonic()
            self.state["updated"] = time.time()
            try:
                task_files.write_text(self.path, json.dumps(self.state))
            except PermissionError:
                pass  # A busy status reader must not stop a mining command.
            if os.environ.get("ROC_GUI_EVENTS"):
                print("ROC_EVENT " + json.dumps({"event": "stage", "message": self.state["stage"],
                                               "task_status": self.state["status"]}), flush=True)

    def checkpoint(self):
        while True:
            with self.lock:
                if self.action != "resume" or time.monotonic() - self.last_control >= 0.2:
                    self.action = self.control_path.read_text().strip() if self.control_path.exists() else "resume"
                    self.last_control = time.monotonic()
                action = self.action
            if action == "stop":
                raise KeyboardInterrupt
            if action != "pause":
                if self.state["status"] == "paused":
                    self.state["status"] = "running"
                    self.save(True)
                return
            self.state["status"] = "paused"
            self.save()
            time.sleep(0.2)

    def install(self):
        self.originals = {name: getattr(match, name) for name in ("target", "compile_text")}
        def target(client, addr):
            self.checkpoint()
            result = self.originals["target"](client, addr)
            with self.lock:
                self.seen.add((client, addr))
                self.state.update(client=client, addr=addr, unit=result[2].get("unit", ""),
                                  inspected=len(self.seen), stage="%s %s %s" % (client, addr, result[2].get("unit", "")))
                self.save()
            return result
        def compile_text(client, source, flags=None, build=None):
            self.checkpoint()
            with self.lock:
                self.state.update(client=client, flags=flags or match.directives(source).get("flags") or
                                  match.clients.load()[client].get("flags") or match.DEFAULT_FLAGS,
                                  stage="Compiling " + client)
                self.save()
            return self.originals["compile_text"](client, source, flags, build)
        match.target, match.compile_text = target, compile_text
        self.save(True)

    def finish(self, status):
        for name, original in self.originals.items():
            setattr(match, name, original)
        self.state.update(status=status, ended=time.time())
        self.save(True)


def tasks():
    result = []
    for path in (ROOT / "work" / "roc-tasks").glob("*.json"):
        try:
            row = json.loads(path.read_text())
            # A compile may run for 120 seconds without a checkpoint.
            if row["status"] in ("running", "paused") and time.time() - row["updated"] > 180:
                row["status"] = "stale"
            result.append(row)
        except (ValueError, OSError, KeyError):
            continue
    return sorted(result, key=lambda r: r["started"], reverse=True)[:100]


def control(identifier, action):
    if action not in ("pause", "resume", "stop") or not any(r["id"] == identifier for r in tasks()):
        raise ValueError("Choose an existing ROC task and pause, resume or stop")
    if not identifier.isalnum():
        raise ValueError("Invalid task ID")
    path = ROOT / "work" / "roc-tasks" / (identifier + ".control")
    task_files.write_text(path, action)
