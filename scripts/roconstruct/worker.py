#!/usr/bin/env python3
"""Worker client: lease one local DB function, reconstruct, report result."""
import argparse
import hashlib
import json
import os
import socket
import platform
import sqlite3
import threading
import time
import urllib.request
from pathlib import Path


def call(url, payload, token, project):
    req = urllib.request.Request(url, json.dumps(payload).encode(),
                                 {"Content-Type": "application/json", "X-Worker-Token": token,
                                  "X-RoConstruct-Project": project})
    with urllib.request.urlopen(req, timeout=30) as response:
        return json.loads(response.read())


def status(url, token, project):
    request = urllib.request.Request(url, headers={"X-Worker-Token": token,
                                                    "X-RoConstruct-Project": project})
    with urllib.request.urlopen(request, timeout=10) as response:
        return json.loads(response.read())


def work(root, job, model):
    import sys
    sys.path.insert(0, str(root / "scripts" / "re"))
    import rebuild as R
    db = Path(os.environ.get("ROCONSTRUCT_DATA_ROOT", str(root / "work" / "re"))) / "rbx2008m.db"
    conn = sqlite3.connect(db)
    fn = conn.execute("SELECT program,addr,name,decompiled FROM functions WHERE program=? AND addr=?",
                      (job["program"], job["address"])).fetchone()
    if not fn or not fn[3]:
        return {"ok": False, "error": "matching local decompile missing"}
    try:
        code = R.extract_code(R.generate(conn, fn, model))
        if not code:
            return {"ok": False, "error": "model returned no code"}
        good, error = R.compile_c(code, "worker_%s" % job["id"])
        summary = conn.execute("SELECT summary FROM functions WHERE program=? AND addr=?",
                               (job["program"], job["address"])).fetchone()[0]
        return {"ok": good, "error": None if good else error[-4000:],
                "pseudocode": fn[3], "summary": summary or "",
                "source": code if good else "",
                "evidence": [{"kind": "compiler", "value": "clean" if good else error[-1000:],
                              "score": 1 if good else 0}]}
    except Exception as error:
        return {"ok": False, "error": str(error)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--server", default="http://127.0.0.1:8765")
    ap.add_argument("--worker-id", default=socket.gethostname())
    ap.add_argument("--token", default=os.environ.get("ROCONSTRUCT_TOKEN", ""))
    ap.add_argument("--project", default=os.environ.get("ROCONSTRUCT_PROJECT", "default"))
    ap.add_argument("--model", default="qwen2.5-coder:7b-instruct")
    ap.add_argument("--poll", type=int, default=5)
    ap.add_argument("--once", action="store_true")
    ap.add_argument("--root", default=str(Path(__file__).resolve().parents[2]))
    a = ap.parse_args()
    root = Path(a.root).resolve()
    completed = failed = 0
    print("RoConstruct worker // %s // CPU %s // GPU %s" %
          (a.worker_id, os.cpu_count(), os.environ.get("ROCONSTRUCT_GPU", "unknown")), flush=True)
    while True:
        lease = call(a.server.rstrip("/") + "/v1/lease", {
            "worker": a.worker_id,
            "meta": {"hostname": socket.gethostname(), "model": a.model,
                     "cpu_count": os.cpu_count(), "gpu": os.environ.get("ROCONSTRUCT_GPU", "unknown"),
                     "platform": platform.platform()}
        }, a.token, a.project)
        job = lease.get("job")
        if not job:
            if a.once:
                return
            try:
                counts = status(a.server.rstrip("/") + "/v1/status", a.token, a.project).get("jobs", {})
                print("IDLE // queue=%s done=%s failed=%s" %
                      (counts.get("queued", 0), counts.get("done", 0), counts.get("failed", 0)), flush=True)
            except Exception:
                print("IDLE // no queued jobs", flush=True)
            time.sleep(a.poll)
            continue
        print("CLAIM // %s:%s // attempt %s" % (job["program"], job["address"], job["attempts"]), flush=True)
        payload = {"worker": a.worker_id, "lease_id": job.get("lease_id", ""), "ok": False}
        done = threading.Event()
        started = time.time()
        meta = {"hostname": socket.gethostname(), "model": a.model,
                "cpu_count": os.cpu_count(), "gpu": os.environ.get("ROCONSTRUCT_GPU", "unknown"),
                "platform": platform.platform(), "current_job": job["id"], "state": "working",
                "completed": completed, "failed": failed}
        def heartbeat():
            while not done.wait(15):
                try:
                    call(a.server.rstrip("/") + "/v1/heartbeat", {
                        "job": job["id"], "lease_id": job.get("lease_id", ""), "worker": a.worker_id,
                        "lease": 900, "meta": meta}, a.token, a.project)
                except Exception:
                    pass
        thread = threading.Thread(target=heartbeat, daemon=True)
        thread.start()
        try:
            payload.update(work(root, job, a.model))
        finally:
            done.set()
        payload["elapsed"] = round(time.time() - started, 2)
        payload["worker"] = a.worker_id
        payload["lease_id"] = job.get("lease_id", "")
        completed += int(bool(payload.get("ok")))
        failed += int(not payload.get("ok"))
        meta.update({"current_job": None, "state": "idle", "last_elapsed": payload["elapsed"],
                     "completed": completed, "failed": failed,
                     "speed_per_min": round(completed / max((time.time() - started) / 60, 1 / 60), 2)})
        try:
            call(a.server.rstrip("/") + "/v1/heartbeat", {"job": job["id"], "lease_id": job.get("lease_id", ""),
                "worker": a.worker_id, "lease": 900, "meta": meta}, a.token, a.project)
        except Exception:
            pass
        call(a.server.rstrip("/") + "/v1/jobs/%s/result" % job["id"], payload, a.token, a.project)
        print("DONE // %s:%s // %s // %.2fs // completed=%s failed=%s" %
              (job["program"], job["address"], "OK" if payload.get("ok") else "ERROR",
               payload["elapsed"], completed, failed), flush=True)
        if a.once:
            return


if __name__ == "__main__":
    main()
