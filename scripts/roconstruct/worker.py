#!/usr/bin/env python3
"""Worker client: lease one local DB function, reconstruct, report result."""
import argparse
import hashlib
import json
import os
import socket
import sqlite3
import time
import urllib.request
from pathlib import Path


def call(url, payload, token):
    req = urllib.request.Request(url, json.dumps(payload).encode(),
                                 {"Content-Type": "application/json", "X-Worker-Token": token})
    with urllib.request.urlopen(req, timeout=30) as response:
        return json.loads(response.read())


def work(root, job, model):
    import sys
    sys.path.insert(0, str(root / "scripts" / "re"))
    import rebuild as R
    db = root / "work" / "re" / "rbx2008m.db"
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
        return {"ok": good, "error": None if good else error[-4000:],
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
    ap.add_argument("--model", default="qwen2.5-coder:7b-instruct")
    ap.add_argument("--poll", type=int, default=5)
    ap.add_argument("--once", action="store_true")
    ap.add_argument("--root", default=str(Path(__file__).resolve().parents[2]))
    a = ap.parse_args()
    root = Path(a.root).resolve()
    while True:
        lease = call(a.server.rstrip("/") + "/v1/lease", {
            "worker": a.worker_id,
            "meta": {"hostname": socket.gethostname(), "model": a.model}
        }, a.token)
        job = lease.get("job")
        if not job:
            if a.once:
                return
            time.sleep(a.poll)
            continue
        payload = work(root, job, a.model)
        payload["worker"] = a.worker_id
        call(a.server.rstrip("/") + "/v1/jobs/%s/result" % job["id"], payload, a.token)
        if a.once:
            return


if __name__ == "__main__":
    main()
