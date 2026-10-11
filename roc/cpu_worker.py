"""Explicit CPU contribution. No provider keys or coordinator credentials needed."""
import hashlib
import json
import os
import socket
import threading
import time
import uuid
from pathlib import Path

from roc import clients, cpu_jobs, match, setup, task_files, worker


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
        return cpu_jobs.check_many_text(payload["client"], payload["addrs"], payload["source"])
    finally:
        match.target = original


def run(config_path, enable=False, jobs=None, log=print):
    config = json.loads(Path(config_path).read_text())
    if enable:
        config["cpu_enabled"] = True
        task_files.write_text(config_path, json.dumps(config, indent=2))
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
                task_files.write_text(path, json.dumps(state))
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
                if (payload["client"] not in have or payload["identity"] != cpu_jobs.identity() or
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
