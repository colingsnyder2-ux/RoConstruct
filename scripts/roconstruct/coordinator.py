#!/usr/bin/env python3
"""Small, dependency-free coordinator for distributed RoConstruct workers."""
import argparse
import hashlib
import json
import os
import sqlite3
import threading
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import urlparse


SCHEMA = """
CREATE TABLE IF NOT EXISTS jobs(
 id TEXT PRIMARY KEY, binary_hash TEXT NOT NULL, program TEXT NOT NULL,
 address TEXT NOT NULL, state TEXT NOT NULL DEFAULT 'queued', worker TEXT,
 lease_until REAL, attempts INTEGER NOT NULL DEFAULT 0,
 result TEXT, created REAL NOT NULL, updated REAL NOT NULL
);
CREATE TABLE IF NOT EXISTS attempts(
 id INTEGER PRIMARY KEY AUTOINCREMENT, job_id TEXT NOT NULL, worker TEXT NOT NULL,
 started REAL NOT NULL, finished REAL, ok INTEGER, error TEXT, result TEXT
);
CREATE TABLE IF NOT EXISTS evidence(
 id INTEGER PRIMARY KEY AUTOINCREMENT, job_id TEXT NOT NULL, worker TEXT NOT NULL,
 kind TEXT NOT NULL, value TEXT NOT NULL, score REAL NOT NULL DEFAULT 0,
 created REAL NOT NULL
);
CREATE TABLE IF NOT EXISTS workers(
 id TEXT PRIMARY KEY, last_seen REAL NOT NULL, meta TEXT NOT NULL
);
"""


def job_id(binary_hash, program, address):
    raw = "%s:%s:%s" % (binary_hash.lower(), program, address.lower())
    return hashlib.sha256(raw.encode()).hexdigest()[:32]


class Store:
    def __init__(self, path):
        self.db = sqlite3.connect(path, check_same_thread=False)
        self.db.executescript(SCHEMA)
        self.lock = threading.RLock()

    def seed(self, jobs):
        now = time.time()
        added = 0
        with self.lock:
            for item in jobs:
                jid = job_id(item["binary_hash"], item["program"], item["address"])
                cur = self.db.execute(
                    "INSERT OR IGNORE INTO jobs(id,binary_hash,program,address,created,updated) VALUES(?,?,?,?,?,?)",
                    (jid, item["binary_hash"], item["program"], item["address"], now, now))
                added += cur.rowcount
            self.db.commit()
        return added

    def claim(self, worker, lease):
        now = time.time()
        with self.lock:
            row = self.db.execute(
                "SELECT id,binary_hash,program,address,attempts FROM jobs "
                "WHERE state='queued' OR (state='leased' AND lease_until<?) "
                "ORDER BY attempts,created LIMIT 1", (now,)).fetchone()
            if not row:
                return None
            jid, binary_hash, program, address, attempts = row
            self.db.execute("UPDATE jobs SET state='leased',worker=?,lease_until=?,attempts=attempts+1,updated=? WHERE id=?",
                            (worker, now + lease, now, jid))
            self.db.execute("INSERT INTO attempts(job_id,worker,started) VALUES(?,?,?)", (jid, worker, now))
            self.db.execute("INSERT OR REPLACE INTO workers(id,last_seen,meta) VALUES(?,?,?)",
                            (worker, now, "{}"))
            self.db.commit()
            return {"id": jid, "binary_hash": binary_hash, "program": program,
                    "address": address, "attempts": attempts + 1}

    def result(self, jid, worker, payload):
        now = time.time()
        ok = bool(payload.get("ok"))
        encoded = json.dumps(payload, separators=(",", ":"))
        with self.lock:
            row = self.db.execute("SELECT worker,state FROM jobs WHERE id=?", (jid,)).fetchone()
            if not row or row[0] != worker or row[1] != "leased":
                return False
            self.db.execute("UPDATE jobs SET state=?,result=?,lease_until=NULL,updated=? WHERE id=?",
                            ("done" if ok else "failed", encoded, now, jid))
            self.db.execute("UPDATE attempts SET finished=?,ok=?,error=?,result=? "
                            "WHERE job_id=? AND worker=? AND finished IS NULL",
                            (now, 1 if ok else 0, payload.get("error"), encoded, jid, worker))
            for item in payload.get("evidence", []):
                self.db.execute("INSERT INTO evidence(job_id,worker,kind,value,score,created) VALUES(?,?,?,?,?,?)",
                                (jid, worker, item.get("kind", "unknown"), item.get("value", ""),
                                 float(item.get("score", 0)), now))
            self.db.commit()
        return True

    def status(self):
        with self.lock:
            counts = dict(self.db.execute("SELECT state,COUNT(*) FROM jobs GROUP BY state").fetchall())
            workers = self.db.execute("SELECT COUNT(*) FROM workers WHERE last_seen>?", (time.time() - 60,)).fetchone()[0]
            evidence = self.db.execute("SELECT COUNT(*) FROM evidence").fetchone()[0]
        return {"jobs": counts, "workers_online": workers, "evidence": evidence}


class Handler(BaseHTTPRequestHandler):
    store = None
    token = ""

    def log_message(self, fmt, *args):
        return

    def auth(self):
        return not self.token or self.headers.get("X-Worker-Token") == self.token

    def send_json(self, code, value):
        data = json.dumps(value).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def body(self):
        length = int(self.headers.get("Content-Length", 0))
        return json.loads(self.rfile.read(length) or b"{}")

    def do_GET(self):
        if urlparse(self.path).path == "/v1/status":
            return self.send_json(200, self.store.status())
        self.send_json(404, {"error": "not found"})

    def do_POST(self):
        if not self.auth():
            return self.send_json(401, {"error": "worker token required"})
        path = urlparse(self.path).path
        if path == "/v1/jobs/seed":
            return self.send_json(200, {"added": self.store.seed(self.body().get("jobs", []))})
        if path == "/v1/lease":
            body = self.body()
            job = self.store.claim(body.get("worker", "unknown"), int(body.get("lease", 900)))
            return self.send_json(200, {"job": job})
        if path.startswith("/v1/jobs/") and path.endswith("/result"):
            jid = path.split("/")[3]
            body = self.body()
            ok = self.store.result(jid, body.get("worker", ""), body)
            return self.send_json(200 if ok else 409, {"accepted": ok})
        self.send_json(404, {"error": "not found"})


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--port", type=int, default=8765)
    ap.add_argument("--db", default="coordinator.db")
    ap.add_argument("--token", default=os.environ.get("ROCONSTRUCT_TOKEN", ""))
    a = ap.parse_args()
    Handler.store = Store(a.db)
    Handler.token = a.token
    server = ThreadingHTTPServer((a.host, a.port), Handler)
    print("RoConstruct coordinator: http://%s:%d" % (a.host, a.port), flush=True)
    server.serve_forever()


if __name__ == "__main__":
    main()
