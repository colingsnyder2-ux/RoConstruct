"""tasks"""
import hashlib
import json
import os
import re
import socket
import threading
import time
import uuid
from pathlib import Path
from urllib.parse import urlparse

from roc import clients, match, setup, worker


# --- command watch ---
# Local ROC task visibility; cooperative controls between compiler/target calls.

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
                write_text(self.path, json.dumps(self.state))
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
    write_text(path, action)


# --- task files ---
# Atomic local task files; Windows readers briefly block replacement.

def write_text(path, text):
    path = Path(path)
    temporary = path.with_name(path.name + "." + uuid.uuid4().hex + ".tmp")
    temporary.write_text(text, encoding="utf-8")
    try:
        for attempt in range(6):
            try:
                temporary.replace(path)
                return
            except PermissionError:
                if attempt == 5:
                    raise
                time.sleep(0.02)
    finally:
        temporary.unlink(missing_ok=True)


# --- cpu jobs ---
# Immutable CPU job inputs and the shared compile-once comparator.

def identity():
    registry = {k: v for k, v in clients.load().items() if k != "2009-12" and not v.get("donor")}
    return hashlib.sha256(b"roc-cluster-v1" + json.dumps(registry, sort_keys=True).encode() +
                          Path(match.__file__).read_bytes() + Path(__file__).read_bytes()).hexdigest()


def cpu_manifest(client, source, addrs, user, model):
    entry = clients.load().get(client)
    if client == "2009-12" or not entry or entry.get("donor"):
        raise ValueError("Client excluded or unknown")
    if not isinstance(source, str) or not source.strip() or len(source) > 200000:
        raise ValueError("Need bounded source")
    if not isinstance(addrs, list) or not 1 <= len(addrs) <= 1000 or not all(
            isinstance(a, str) and re.fullmatch(r"[0-9a-f]{8}", a) for a in addrs):
        raise ValueError("Need 1-1000 lowercase addresses")
    match.reject_asm(source)
    return {"client": client, "source": source, "addrs": sorted(set(addrs)),
            "user": user, "model": model, "registry": entry, "identity": identity(),
            "source_hash": hashlib.sha256(source.encode()).hexdigest()}


def _source_class_token(source):
    path = source.rsplit(": ", 1)[-1].split(" ", 1)[-1]
    token = re.sub(r"[^a-z0-9]", "", Path(path).stem.lower())
    recipe = source.rsplit(": ", 1)[-1].split(" ", 1)[0].lower()
    for prefix in (("ogre",) if recipe.startswith("ogre-") else ("cxtp", "xtp", "rbx", "c")):
        if token.startswith(prefix) and len(token) > len(prefix) + 3:
            token = token[len(prefix):]
            break
    return token if len(token) >= 5 else None


def check_many_text(client, addrs, source):
    obj = match.compile_text(client, source)
    funcs = match.coff_functions(obj)
    token = _source_class_token(source)
    class_funcs = [r for r in funcs if token and token in re.sub(r"[^a-z0-9]", "", r[0].lower())]
    if class_funcs:
        funcs = class_funcs
    by_size = {}
    for row in funcs:
        by_size.setdefault(len(row[1]), []).append(row)
    results = []
    for addr in addrs:
        code, relocs, _ = match.target(client, addr)
        wiggle = max(8, len(code) // 4)
        candidates = [r for size in range(max(1, len(code) - wiggle), len(code) + wiggle + 1)
                      for r in by_size.get(size, ())]
        if not candidates:
            results.append((addr, 0, []))
            continue
        exacts = [r for r in candidates if match.exact_match(code, relocs, r[1], r[2])]
        best = exacts[0] if exacts else max(candidates, key=lambda r: match.score(code, relocs, r[1], r[2]))
        score, spans = match.score(code, relocs, best[1], best[2]), []
        if score == 100:
            best, spans, bad = match.select_exact_data(client, addr, code, obj, exacts or [best])
            if bad:
                score, spans = 99, []
        results.append((addr, score, spans))
    return results


# --- cpu status ---
# Credential-free CPU views and local config controls for dashboard/terminal.

def configs():
    paths = set((ROOT / "work").glob("**/node.json"))
    paths.update((ROOT / "work").glob("**/*cpu*.json"))
    found = {}
    for path in sorted(paths):
        if any(part.startswith(("cluster-test-", "cluster-solo-test-")) for part in path.parts):
            continue
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
            if "servers" in data and ("admin_token" in data or "cpu_enabled" in data):
                key = hashlib.sha256(str(path.resolve()).encode()).hexdigest()[:16]
                found[key] = (path, data)
        except (ValueError, OSError):
            continue
    return found


def snapshot(cluster_id=None):
    found = configs()
    nodes, local = [], []
    for key, (path, data) in found.items():
        label = str(path.relative_to(ROOT))
        if "admin_token" in data:
            nodes.append({"id": key, "label": "%s · %s" % (data.get("node", "Server"), ", ".join(urlparse(s).netloc or s for s in data["servers"])), "path": label})
        else:
            try:
                state = json.loads(path.with_suffix(".status.json").read_text())
            except (ValueError, OSError):
                state = {}
            local.append({"id": key, "label": data.get("worker") or "CPU helper", "path": label, "servers": data["servers"], "worker": data.get("worker"),
                          "enabled": data.get("cpu_enabled") is True, "paused": bool(data.get("cpu_paused")),
                          "running": state.get("stage") != "stopped" and time.time() - state.get("seen", 0) < 65,
                          "status": state})
    
    result = {"clusters": nodes, "local": local, "remote": None, "selected": cluster_id,
              "tasks": tasks()}
    if not nodes:
        nodes.extend({"id": n["id"], "label": "%s · %s" % (n["label"], ", ".join(urlparse(s).netloc or s for s in n["servers"])), "path": n["path"]} for n in local)
    if not nodes:
        return result
    nodes.sort(key=lambda n: found[n["id"]][0].stat().st_mtime, reverse=True)
    selected = cluster_id or nodes[0]["id"]
    if selected not in found:
        raise ValueError("Choose a configured coordinator")
    result["selected"] = selected
    config = found[selected][1]
    result["servers"] = config["servers"]
    result["local"] = [n for n in local if set(found[n["id"]][1]["servers"]) == set(config["servers"])]
    api = worker.Api(",".join(config["servers"]), config.get("admin_token") or config["worker_token"])
    try:
        result["remote"] = api.call("/v2/cpu/dashboard", timeout=2)
    except RuntimeError as error:
        result["error"] = str(error)
    finally:
        api.close()
    return result


def cpu_control(data):
    key, action = data.get("config"), data.get("action")
    if action not in ("pause", "resume", "off", "on"):
        raise ValueError("Use pause, resume, off or on")
    found = configs()
    if key not in found:
        raise ValueError("Unknown CPU config")
    path, config = found[key]
    if "admin_token" in config:
        api = worker.Api(",".join(config["servers"]), config["admin_token"])
        try:
            endpoint = "/v2/cpu/job-cpu_control" if data.get("job") else "/v2/cpu/cpu_control"
            return api.call(endpoint, {"action": action, "id": data.get("job"), "worker": data.get("worker")})
        finally:
            api.close()
    if action in ("pause", "resume"):
        config["cpu_paused"] = action == "pause"
    else:
        config.update(cpu_enabled=action == "on", cpu_paused=False)
    write_text(path, json.dumps(config, indent=2))
    return {"ok": True, "finish_current": True}


def print_status(report):
    print("CPU mining · coordinator %s · %s voter(s)" % (report["node"], report["replicas"]))
    for node in report["nodes"]:
        meta = node["metadata"]
        state = "off" if not node["enabled"] else "paused" if node["paused"] else "enabled"
        print("%s · %s · %s · owner %s · %s" % (node["id"], meta.get("pc", "unknown PC"), state,
              meta.get("owner", "unknown"), meta.get("stage", "idle")))
    for job in report["jobs"]:
        print("%s · %s · %s · owner %s · PC worker %s · %s/%s verified · +%s exact / +%s partial" % (
            job["id"][:12], job["command"], job["state"], job["owner"], job["worker"] or "unassigned",
            job["completed"], job["total"], job["exact_gains"], job["partial_gains"]))
        print("  %s · %s · %s · %s" % (job["client"], ", ".join(job["addrs"]), job["compiler"], job["flags"]))


# --- cpu worker ---
# Explicit CPU contribution. No provider keys or coordinator credentials needed.

def compare(payload, progress):
    """Observe the unchanged comparator in this single-job contributor process."""
    original = match.target
    positions = {addr: index for index, addr in enumerate(payload["addrs"])}
    def target(client, addr):
        result = original(client, addr)
        if client == payload["client"] and addr in positions:
            # Entering target N means the previous N targets finished comparing.
            progress(stage="comparing", checked=positions[addr], current_addr=addr,
                     unit=result[2].get("unit", ""))
        return result
    match.target = target
    try:
        return check_many_text(payload["client"], payload["addrs"], payload["source"])
    finally:
        match.target = original


def run(config_path, enable=False, jobs=None, log=print):
    config = json.loads(Path(config_path).read_text())
    if enable:
        config["cpu_enabled"] = True
        write_text(config_path, json.dumps(config, indent=2))
    if config.get("cpu_enabled") is not True:
        log("CPU mining disabled. Start with --enable; AI workers remain independent.")
        return 0
    if config.get("cpu_slots", 1) != 1:
        raise ValueError("Pilot supports one CPU slot per process")
    api = worker.Api(",".join(config["servers"]), config["worker_token"])
    worker_id = config.get("worker") or uuid.uuid4().hex
    compilers = setup.compilers()
    have = [n for n, e in clients.load().items() if n != "2009-12" and not e.get("donor")
            and e.get("compiler_build") in compilers and clients.status(n, e) == "ok"]
    if not have:
        raise RuntimeError("No allowed clients/compilers installed; run roc install and analyze first")
    completed = 0
    state = {"worker": worker_id, "pc": socket.gethostname(), "pid": os.getpid(),
             "owner": config.get("user", worker_id), "stage": "idle", "completed": 0, "job": None}
    state_lock = threading.Lock()
    def status(**changes):
        with state_lock:
            state.update(changes, seen=time.time())
            path = Path(config_path).with_suffix(".status.json")
            try:
                write_text(path, json.dumps(state))
            except PermissionError:
                pass  # Telemetry failure must not discard a matching job.
    def progress():
        with state_lock:
            return {k: v for k, v in state.items() if k != "addrs"}
    try:
        while jobs is None or completed < jobs:
            # Editing cpu_enabled=false pauses a saved enabled worker after current job.
            current = json.loads(Path(config_path).read_text())
            if current.get("cpu_enabled") is not True:
                break
            status(stage="paused" if current.get("cpu_paused") else "idle", job=None)
            if current.get("cpu_paused"):
                api.call("/v2/cpu/lease", {"enabled": False, "worker": worker_id, "metadata": progress()})
                time.sleep(3)
                continue
            response = api.call("/v2/cpu/lease", {"enabled": True, "worker": worker_id, "clients": have,
                               "metadata": {k: state[k] for k in ("pc", "pid", "owner")}})
            if response.get("disabled"):
                log("CPU disabled by coordinator; finish current job, then exit.")
                break
            job = response.get("job")
            if not job:
                status(stage="paused" if response.get("paused") else "idle")
                if jobs is not None:
                    break
                time.sleep(3)
                continue
            payload = job["payload"]
            status(stage="compile / compare", job=job["id"], client=payload["client"], addrs=payload["addrs"],
                   total=len(payload["addrs"]), checked=None, flags=match.directives(payload["source"]).get("flags") or
                   payload["registry"].get("flags") or match.DEFAULT_FLAGS)
            log("%s · %s · %s · %s targets · %s" % (worker_id, state["pc"], payload["model"], len(payload["addrs"]), state["flags"]))
            stop = threading.Event()
            lost = threading.Event()
            receipt = {"id": job["id"], "nonce": job["nonce"], "worker": worker_id}
            def beat():
                heartbeat = worker.Api(",".join(config["servers"]), config["worker_token"])
                while not stop.wait(job["heartbeat"]):
                    try:
                        heartbeat.call("/v2/cpu/heartbeat", {**receipt, "progress": progress()})
                        status()
                    except RuntimeError:
                        lost.set()
                        heartbeat.close()
                        return
                heartbeat.close()
            thread = threading.Thread(target=beat, daemon=True)
            thread.start()
            try:
                if (payload["client"] not in have or payload["identity"] != identity() or
                        payload["registry"] != clients.load()[payload["client"]] or
                        payload["source_hash"] != hashlib.sha256(payload["source"].encode()).hexdigest()):
                    raise ValueError("Pinned job inputs differ from local checkout")
                results = compare(payload, status)
                result = {"scores": [{"addr": a, "score": s} for a, s, _ in results]}
                status(stage="reporting", checked=len(results))
            except (ValueError, match.CompileError, SystemExit) as error:
                result = {"error": str(error)[:500]}
            finally:
                stop.set()
                thread.join(10)
            # Preserve score/error and complete candidate inputs even when delivery or
            # the lease fails. Provider/coordinator credentials never enter this log.
            with Path(config_path).with_suffix(".attempts.jsonl").open("a", encoding="utf-8") as archive:
                archive.write(json.dumps({"id": job["id"], "payload": payload, "result": result,
                                          "lease_lost": lost.is_set(), "ts": time.time()}) + "\n")
                archive.flush()
                os.fsync(archive.fileno())
            if not lost.is_set():
                api.call("/v2/cpu/result", {**receipt, "result": result, "progress": progress()},
                         request_id="cpu-result:%s:%s" % (job["id"], job["nonce"]))
                completed += 1
                status(stage="awaiting trusted verification", completed=completed)
                log("CPU job %s reported; awaiting trusted recompilation" % job["id"][:12])
    finally:
        api.close()
        status(stage="stopped", job=None)
    return completed
