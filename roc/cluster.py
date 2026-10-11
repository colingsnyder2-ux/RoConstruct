"""Private, quorum-backed group server. JetStream is the durable transaction log.

Only approved coordinators receive NATS credentials. Public workers use HTTP;
they cannot write SQL or vote on matches. SQLite files are disposable projections.
"""
import asyncio
import concurrent.futures
import hashlib
import io
import json
import secrets
import sqlite3
import threading
import time
import uuid
import zlib
from http.server import ThreadingHTTPServer
from pathlib import Path

from roc import clients, match, server, setup
from roc.cpu_jobs import identity, cpu_manifest

STREAM = "ROC_LEDGER"
SUBJECT = "roc.ledger"
SCHEMA = """
CREATE TABLE IF NOT EXISTS cluster_applied(id INTEGER PRIMARY KEY CHECK(id=1), seq INTEGER);
INSERT OR IGNORE INTO cluster_applied VALUES(1,0);
CREATE TABLE IF NOT EXISTS cluster_requests(id TEXT PRIMARY KEY, digest TEXT, response TEXT);
CREATE TABLE IF NOT EXISTS cluster_contributors(id TEXT PRIMARY KEY, token_hash TEXT UNIQUE, active INTEGER);
CREATE TABLE IF NOT EXISTS cpu_nodes(id TEXT PRIMARY KEY, enabled INTEGER DEFAULT 1,
 paused INTEGER DEFAULT 0, seen REAL DEFAULT 0, metadata TEXT DEFAULT '{}');
CREATE TABLE IF NOT EXISTS cpu_jobs(id TEXT PRIMARY KEY, payload TEXT, state TEXT,
 worker TEXT, nonce TEXT, expires REAL DEFAULT 0, attempts INTEGER DEFAULT 0,
 result TEXT, verification TEXT, created REAL);
"""


class Journal:
    def __init__(self, config):
        self.loop = asyncio.new_event_loop()
        self.thread = threading.Thread(target=self.loop.run_forever, daemon=True)
        self.thread.start()
        self.config = config
        try:
            self.wait(self.connect())
        except BaseException:
            self.loop.call_soon_threadsafe(self.loop.stop)
            self.thread.join(3)
            raise

    def wait(self, coroutine):
        future = asyncio.run_coroutine_threadsafe(coroutine, self.loop)
        try:
            return future.result(20)
        except concurrent.futures.TimeoutError:
            future.cancel()
            raise RuntimeError("Broker request timed out") from None

    async def connect(self):
        try:
            import nats
        except ImportError:
            raise RuntimeError("Install cluster dependency: python -m pip install nats-py==2.16.0") from None
        async def error_cb(error):
            self.last_error = str(error)
        self.nc = await nats.connect(self.config["nats"], token=self.config["nats_token"], error_cb=error_cb,
                                     connect_timeout=2, max_reconnect_attempts=-1,
                                     reconnect_time_wait=0.25, allow_reconnect=True)
        self.js = self.nc.jetstream(timeout=5)

    async def create(self):
        from nats.js.api import StreamConfig
        try:
            info = await self.js.stream_info(STREAM)
            if info.config.num_replicas != self.config.get("replicas", 1) or info.config.subjects != [SUBJECT]:
                raise RuntimeError("Existing ledger configuration differs; refusing to change it")
        except Exception as error:
            if getattr(error, "err_code", None) != 10059:
                raise
            await self.js.add_stream(config=StreamConfig(name=STREAM, subjects=[SUBJECT],
                                     num_replicas=self.config.get("replicas", 1), storage="file", max_msg_size=950000,
                                     deny_delete=True, deny_purge=True))

    async def head(self):
        return (await self.js.stream_info(STREAM)).state.last_seq

    async def get(self, seq):
        msg = await self.js.get_msg(STREAM, seq=seq)
        return json.loads(zlib.decompress(msg.data))

    async def append(self, record, expected):
        data = zlib.compress(json.dumps(record, separators=(",", ":")).encode())
        if len(data) > 900000:
            raise RuntimeError("Transaction exceeds ledger limit; split this batch")
        ack = await self.js.publish(SUBJECT, data, headers={
            "Nats-Expected-Last-Sequence": str(expected), "Nats-Msg-Id": record["id"]})
        return ack.seq

    def close(self):
        self.wait(self.nc.close())
        self.loop.call_soon_threadsafe(self.loop.stop)
        self.thread.join(3)


class TransactionConnection:
    """Store commits become one quorum-acknowledged HTTP transaction."""
    def __init__(self, db):
        self.raw = db
        self.active = False

    def __getattr__(self, name):
        return getattr(self.raw, name)

    def commit(self):
        if not self.active:
            self.raw.commit()


class Replica:
    def __init__(self, config, journal=None):
        self.journal = journal or Journal(config)
        self.store = server.Store(config["db"], config.get("lease_seconds", 120))
        self.store.lock = threading.RLock()
        self.store.db.executescript(SCHEMA)
        self.store.db.commit()
        self.db = self.store.db
        self.store.db = TransactionConnection(self.db)
        self.lock = threading.RLock()
        self.fingerprint = identity()

    def sync(self):
        seq = self.db.execute("SELECT seq FROM cluster_applied WHERE id=1").fetchone()[0]
        head = self.journal.wait(self.journal.head())
        while seq < head:
            record = self.journal.wait(self.journal.get(seq + 1))
            if record["identity"] != self.fingerprint:
                raise RuntimeError("Cluster registry/matcher differs from this checkout")
            try:
                self.db.execute("BEGIN")
                for sql in record["sql"]:
                    self.db.execute(sql)
                seq += 1
                self.db.execute("UPDATE cluster_applied SET seq=? WHERE id=1", (seq,))
                self.db.commit()
            except BaseException:
                self.db.rollback()
                raise
        return seq

    def run(self, operation):
        """CAS publishes serialize concurrent nodes; conflicts re-run from new state.

        Uncertain publish acknowledgements are resolved by replay, never by accepting
        a speculative local commit. Request IDs make an HTTP retry return its receipt.
        """
        with self.lock, self.store.lock:
            for _ in range(12):
                seq = self.sync()
                sql = []
                self.db.execute("BEGIN")
                self.store.db.active = True
                self.db.set_trace_callback(lambda statement: sql.append(statement)
                    if statement.lstrip().split(None, 1)[0].upper() in ("INSERT", "UPDATE", "DELETE", "REPLACE") else None)
                try:
                    result = operation()
                    self.db.set_trace_callback(None)
                    if not sql:
                        self.db.rollback()
                        return result
                    record = {"id": uuid.uuid4().hex, "identity": self.fingerprint, "sql": sql}
                    try:
                        committed = self.journal.wait(self.journal.append(record, seq))
                    except Exception as error:
                        self.db.rollback()
                        if getattr(error, "err_code", None) == 10071:
                            continue
                        raise RuntimeError("Cluster quorum unavailable; retry with same request ID") from error
                    self.db.execute("UPDATE cluster_applied SET seq=? WHERE id=1", (committed,))
                    self.db.commit()
                    return result
                except BaseException:
                    self.db.rollback()
                    raise
                finally:
                    self.db.set_trace_callback(None)
                    self.store.db.active = False
            raise RuntimeError("Cluster busy; retry with same request ID")

    def close(self):
        self.db.close()
        self.journal.close()


def handler(replica, config, verifiable):
    base = server.make_handler(replica.store, config["worker_token"], verifiable)
    compile_slots = threading.BoundedSemaphore(1)

    class Handler(base):
        def principal(self):
            credential = self.headers.get("X-Roc-Token", "")
            if credential == config["admin_token"]:
                return "admin", None
            if credential == config["worker_token"]:
                return "worker", None
            row = replica.db.execute("SELECT id FROM cluster_contributors WHERE token_hash=? AND active=1",
                                     (hashlib.sha256(credential.encode()).hexdigest(),)).fetchone()
            return ("cpu", row[0]) if row else (None, None)

        def send(self, code, obj):
            if getattr(self, "buffering", False):
                self.response = [code, obj]
            else:
                super().send(code, obj)

        def do_GET(self):
            if "2009-12" in self.path:
                return self.send(400, {"error": "client excluded"})
            try:
                self.buffering = True
                def read():
                    role, contributor = self.principal()
                    if not role or (role == "cpu" and self.path not in ("/v2/cluster", "/v2/cpu/status", "/v2/cpu/dashboard")):
                        return self.send(403, {"error": "cluster authentication required"})
                    if self.path == "/v2/cluster":
                        return self.send(200, {"node": config["node"], "replicas": config.get("replicas", 1), "protocol": 1,
                                "cluster_id": config["cluster_id"], "servers": config["servers"], "cpu_default": False})
                    if self.path == "/v2/cpu/status":
                        rows = replica.db.execute("SELECT state,COUNT(*) FROM cpu_jobs GROUP BY state").fetchall()
                        return self.send(200, {"jobs": dict(rows)})
                    if self.path == "/v2/cpu/dashboard":
                        nodes = [dict(zip(("id", "enabled", "paused", "seen", "metadata"), r))
                                 for r in replica.db.execute("SELECT id,enabled,paused,seen,metadata FROM cpu_nodes WHERE ? OR id=?", (role != "cpu", contributor))]
                        for node in nodes:
                            node["metadata"] = json.loads(node["metadata"])
                        jobs = []
                        for r in replica.db.execute("SELECT id,payload,state,worker,attempts,verification,created,result FROM cpu_jobs WHERE ? OR worker=? ORDER BY created DESC LIMIT 300", (role != "cpu", contributor)):
                            payload, verification = json.loads(r[1]), json.loads(r[5] or "null")
                            scores = verification if isinstance(verification, list) else []
                            reported = json.loads(r[7] or "null")
                            compared = len({s.get("addr") for s in reported.get("scores", [])
                                            if isinstance(s, dict) and s.get("addr") in payload["addrs"]}) if isinstance(reported, dict) and isinstance(reported.get("scores"), list) else None
                            jobs.append(dict(id=r[0], client=payload["client"], addrs=payload["addrs"],
                                owner=payload["user"], command=payload["model"],
                                flags=match.directives(payload["source"]).get("flags") or payload["registry"].get("flags") or match.DEFAULT_FLAGS,
                                compiler=match.directives(payload["source"]).get("cl") or payload["registry"].get("compiler_build"),
                                targets=[dict(addr=a, unit=(replica.db.execute("SELECT unit FROM funcs WHERE client=? AND addr=?",
                                         (payload["client"], a)).fetchone() or [""])[0]) for a in payload["addrs"]],
                                state=r[2], worker=r[3], attempts=r[4], created=r[6], total=len(payload["addrs"]),
                                completed=len(scores), scores=scores,
                                compared=compared,
                                exact_gains=sum(s["improved"] and s["score"] == 100 for s in scores),
                                partial_gains=sum(s["improved"] and s["score"] < 100 for s in scores)))
                        return self.send(200, {"nodes": nodes, "jobs": jobs, "node": config["node"],
                                              "replicas": config.get("replicas", 1), "can_control": role == "admin"})
                    if self.path == "/v2/cpu/pending":
                        if role != "admin":
                            return self.send(403, {"error": "admin credential required"})
                        rows = replica.db.execute("SELECT id,payload FROM cpu_jobs WHERE state='reported' ORDER BY created LIMIT 20").fetchall()
                        return self.send(200, {"jobs": [r[0] for r in rows if json.loads(r[1])["client"] in verifiable]})
                    super(Handler, self).do_GET()
                    if self.path == "/v1/info" and self.response[0] == 200:
                        self.response[1]["clients"].pop("2009-12", None)
                replica.run(read)
            except Exception as error:
                self.response = [503, {"error": str(error)}]
            finally:
                self.buffering = False
            self.send(*self.response)

        def do_POST(self):
            credential = self.headers.get("X-Roc-Token", "")
            try:
                size = int(self.headers.get("Content-Length", "0"))
                if not 0 <= size <= 1 << 20:
                    return self.send(413, {"error": "too large"})
                raw = self.rfile.read(size)
                body = json.loads(raw or b"{}")
                if not isinstance(body, dict):
                    raise ValueError("JSON object required")
                values = [body]
                while values:
                    value = values.pop()
                    if isinstance(value, str) and "\0" in value:
                        raise ValueError("NUL characters prohibited")
                    if isinstance(value, dict):
                        values.extend(value.keys())
                        values.extend(value.values())
                    elif isinstance(value, list):
                        values.extend(value)
                if body.get("client") == "2009-12" or "2009-12" in body.get("clients", []):
                    raise ValueError("Client excluded")
                reqid = self.headers.get("X-Roc-Request") or uuid.uuid4().hex
                if len(reqid) > 128:
                    raise ValueError("Request ID too long")
            except (ValueError, TypeError) as error:
                return self.send(400, {"error": str(error)})
            digest = hashlib.sha256(self.path.encode() + raw + hashlib.sha256(credential.encode()).digest()).hexdigest()
            self.buffering = True
            checked = {}
            try:
                def prepare():
                    role, _ = self.principal()
                    cached = replica.db.execute("SELECT 1 FROM cluster_requests WHERE id=?", (reqid,)).fetchone()
                    if cached:
                        return None
                    if role == "worker" and self.path in ("/v1/submit", "/v1/submit-batch") and body.get("client") in verifiable:
                        source = body.get("source", "")
                        import re
                        addrs = body.get("addrs") if self.path.endswith("submit-batch") else [body.get("addr")]
                        if (not isinstance(source, str) or not source.strip() or len(source) > 200000 or
                                not isinstance(addrs, list) or not 1 <= len(addrs) <= 1000 or
                                not all(isinstance(a, str) and re.fullmatch(r"[0-9a-fA-F]{8}", a) for a in addrs)):
                            raise ValueError("Need bounded source and 1-1000 target addresses")
                        return {"client": body["client"], "source": source, "addrs": addrs}
                    if role == "admin" and self.path == "/v2/cpu/validate":
                        row = replica.db.execute("SELECT payload,state FROM cpu_jobs WHERE id=?", (body.get("id"),)).fetchone()
                        if row and row[1] == "reported":
                            payload = json.loads(row[0])
                            return payload if payload["client"] in verifiable else None
                payload = replica.run(prepare)
                if payload:
                    if not compile_slots.acquire(blocking=False):
                        raise RuntimeError("Validator busy; retry with same request ID")
                    try:
                        # Compile outside projection/transaction locks. Status and
                        # heartbeats remain available during a slow 120s compile.
                        if self.path == "/v1/submit":
                            score, _, _, spans = match.check_text(payload["client"], payload["addrs"][0], payload["source"])
                            checked["results"] = [(payload["addrs"][0], score, spans)]
                        else:
                            checked["results"] = server.check_many_text(payload["client"], payload["addrs"], payload["source"])
                    except (match.CompileError, SystemExit) as error:
                        checked["error"] = str(error)[:500]
                        checked["results"] = []
                    finally:
                        compile_slots.release()
                def write():
                    role, contributor = self.principal()
                    if not role or (role == "cpu" and self.path not in ("/v2/cpu/lease", "/v2/cpu/heartbeat", "/v2/cpu/result")):
                        return self.send(403, {"error": "cluster authentication required"})
                    admin = role == "admin"
                    if role == "cpu" and body.get("worker") != contributor:
                        return self.send(403, {"error": "worker identity differs from credential"})
                    if role == "worker" and self.path in ("/v2/cpu/lease", "/v2/cpu/heartbeat", "/v2/cpu/result"):
                        return self.send(403, {"error": "CPU contributor credential required"})
                    cached = replica.db.execute("SELECT digest,response FROM cluster_requests WHERE id=?", (reqid,)).fetchone()
                    if cached:
                        self.response = json.loads(cached[1]) if cached[0] == digest else [409, {"error": "request ID reused with different body"}]
                        return
                    if self.path.startswith("/v2/cpu/"):
                        self.cpu(body, admin, verifiable, checked)
                    elif self.path in ("/v1/submit", "/v1/submit-batch"):
                        if role != "worker":
                            self.send(403, {"error": "mining worker credential required"})
                        elif body.get("client") not in verifiable:
                            self.send(503, {"error": "this node cannot verify client; use compatible backup node"})
                        else:
                            self.submit_checked(body, checked)
                    else:
                        if admin:
                            # Legacy handler expects worker token. Admin uses only v2 endpoints.
                            self.send(403, {"error": "use worker credential for mining API"})
                        else:
                            original = self.rfile
                            self.rfile = io.BytesIO(raw)
                            try:
                                super(Handler, self).do_POST()
                            finally:
                                self.rfile = original
                    if self.response[0] < 500:
                        replica.db.execute("INSERT INTO cluster_requests VALUES(?,?,?)", (reqid, digest, json.dumps(self.response)))
                replica.run(write)
            except (ValueError, match.CompileError) as error:
                self.response = [400, {"error": str(error)[:500]}]
            except Exception as error:
                self.response = [503, {"error": str(error)}]
            finally:
                self.buffering = False
            self.send(*self.response)

        def submit_checked(self, body, checked):
            user = str(body.get("user", ""))
            if not server.USER_RE.fullmatch(user):
                return self.send(400, {"error": "invalid username"})
            if "error" in checked:
                return self.send(400, {"error": checked["error"]})
            results = []
            for addr, score, spans in checked["results"]:
                stored, improved = replica.store.submit(body["client"], addr, user, score, body["source"], spans,
                    body.get("lease") if self.path == "/v1/submit" else None, model=body.get("model", ""), verified=True)
                results.append({"addr": addr, "score": score, "stored": stored, "improved": improved})
            if body.get("lease") and self.path == "/v1/submit":
                replica.store.release(body["lease"])
            if self.path == "/v1/submit":
                return self.send(200, {k: v for k, v in results[0].items() if k != "addr"} | {"verified": True})
            return self.send(200, {"verified": True, "results": results})

        def cpu(self, body, admin, verifiable, checked):
            db = replica.db
            now = time.time()
            if self.path == "/v2/cpu/control":
                if not admin:
                    return self.send(403, {"error": "admin credential required"})
                action = body.get("action")
                if action not in ("pause", "resume", "off", "on"):
                    raise ValueError("Use pause, resume, off or on")
                node = body.get("worker")
                if not db.execute("SELECT 1 FROM cluster_contributors WHERE id=? AND active=1", (node,)).fetchone():
                    raise ValueError("Unknown active contributor")
                db.execute("INSERT OR IGNORE INTO cpu_nodes(id) VALUES(?)", (node,))
                if action in ("pause", "resume"):
                    db.execute("UPDATE cpu_nodes SET paused=? WHERE id=?", (action == "pause", node))
                else:
                    db.execute("UPDATE cpu_nodes SET enabled=?,paused=0 WHERE id=?", (action == "on", node))
                return self.send(200, {"ok": True, "finish_current": True})
            if self.path == "/v2/cpu/job-control":
                if not admin:
                    return self.send(403, {"error": "admin credential required"})
                previous, following = {"pause": ("queued", "paused"), "resume": ("paused", "queued")}.get(body.get("action"), (None, None))
                if not previous:
                    raise ValueError("Use pause or resume")
                changed = db.execute("UPDATE cpu_jobs SET state=? WHERE id=? AND state=?", (following, body.get("id"), previous)).rowcount
                return self.send(200 if changed else 409, {"ok": bool(changed), "state": following if changed else "unchanged"})
            if self.path in ("/v2/cpu/contributor", "/v2/cpu/revoke"):
                if not admin:
                    return self.send(403, {"error": "admin credential required"})
                contributor = str(body.get("id", ""))
                if not server.USER_RE.fullmatch(contributor):
                    raise ValueError("Contributor name must be 2-32 letters/digits/_/./-")
                if self.path.endswith("revoke"):
                    db.execute("UPDATE cluster_contributors SET active=0 WHERE id=?", (contributor,))
                    db.execute("UPDATE cpu_jobs SET state='queued',worker=NULL,nonce=NULL WHERE worker=? AND state='leased'", (contributor,))
                else:
                    token_hash = body.get("token_hash", "")
                    import re
                    if not re.fullmatch(r"[0-9a-f]{64}", token_hash):
                        raise ValueError("Need SHA-256 credential hash")
                    if db.execute("SELECT 1 FROM cluster_contributors WHERE id=?", (contributor,)).fetchone():
                        return self.send(409, {"error": "Contributor already exists; choose another name"})
                    db.execute("INSERT INTO cluster_contributors VALUES(?,?,1)", (contributor, token_hash))
                return self.send(200, {"ok": True, "id": contributor})
            if self.path == "/v2/cpu/enqueue":
                if not admin:
                    return self.send(403, {"error": "admin credential required"})
                payload = cpu_manifest(body["client"], body["source"], body["addrs"], body.get("user", "auto"), body.get("model", "roc propagation"))
                if not server.USER_RE.fullmatch(payload["user"]):
                    raise ValueError("Invalid username")
                jobid = hashlib.sha256(json.dumps(payload, sort_keys=True).encode()).hexdigest()
                db.execute("INSERT OR IGNORE INTO cpu_jobs(id,payload,state,created) VALUES(?,?,'queued',?)", (jobid, json.dumps(payload), now))
                return self.send(200, {"id": jobid})
            if self.path == "/v2/cpu/lease":
                worker = str(body.get("worker", ""))
                if not 1 <= len(worker) <= 64:
                    raise ValueError("Worker identity required")
                metadata = body.get("metadata", {})
                if not isinstance(metadata, dict) or len(json.dumps(metadata)) > 4096:
                    raise ValueError("Bounded worker metadata required")
                db.execute("INSERT OR IGNORE INTO cpu_nodes(id) VALUES(?)", (worker,))
                db.execute("UPDATE cpu_nodes SET seen=?,metadata=? WHERE id=?", (now, json.dumps(metadata), worker))
                if body.get("enabled") is not True:
                    return self.send(200, {"job": None, "disabled": True})
                enabled, paused = db.execute("SELECT enabled,paused FROM cpu_nodes WHERE id=?", (worker,)).fetchone()
                if not enabled or paused:
                    return self.send(200, {"job": None, "disabled": not enabled, "paused": bool(paused)})
                db.execute("UPDATE cpu_jobs SET state=CASE WHEN attempts>=3 THEN 'quarantined' ELSE 'queued' END, worker=NULL,nonce=NULL WHERE state='leased' AND expires<?", (now,))
                if db.execute("SELECT 1 FROM cpu_jobs WHERE state='leased' AND worker=?", (worker,)).fetchone():
                    return self.send(200, {"job": None})
                have = [c for c in body.get("clients", []) if c != "2009-12"]
                rows = db.execute("SELECT id,payload FROM cpu_jobs WHERE state='queued' ORDER BY created").fetchall()
                row = next((r for r in rows if json.loads(r[1])["client"] in have), None)
                if not row:
                    return self.send(200, {"job": None})
                nonce = secrets.token_hex(24)
                db.execute("UPDATE cpu_jobs SET state='leased',worker=?,nonce=?,expires=?,attempts=attempts+1 WHERE id=?", (worker, nonce, now + 180, row[0]))
                return self.send(200, {"job": {"id": row[0], "nonce": nonce, "payload": json.loads(row[1]), "heartbeat": 30}})
            row = db.execute("SELECT payload,state,worker,nonce,expires FROM cpu_jobs WHERE id=?", (body.get("id"),)).fetchone()
            if not row:
                return self.send(404, {"error": "unknown job"})
            if self.path in ("/v2/cpu/heartbeat", "/v2/cpu/result"):
                if row[1] != "leased" or row[2] != body.get("worker") or row[3] != body.get("nonce") or row[4] < now:
                    return self.send(409, {"error": "stale or foreign lease"})
                if self.path.endswith("heartbeat"):
                    db.execute("UPDATE cpu_jobs SET expires=? WHERE id=?", (now + 180, body["id"]))
                    db.execute("UPDATE cpu_nodes SET seen=? WHERE id=?", (now, body["worker"]))
                    progress = body.get("progress")
                    if isinstance(progress, dict) and len(json.dumps(progress)) <= 4096:
                        db.execute("UPDATE cpu_nodes SET metadata=? WHERE id=?", (json.dumps(progress), body["worker"]))
                    return self.send(200, {"ok": True})
                db.execute("UPDATE cpu_jobs SET state='reported',result=? WHERE id=?", (json.dumps(body.get("result")), body["id"]))
                progress = body.get("progress")
                if isinstance(progress, dict) and len(json.dumps(progress)) <= 4096:
                    progress["stage"] = "awaiting trusted verification"
                    db.execute("UPDATE cpu_nodes SET seen=?,metadata=? WHERE id=?", (now, json.dumps(progress), body["worker"]))
                # Provisional scores never enter funcs or gain counters.
                return self.send(200, {"verified": False, "state": "reported"})
            if self.path == "/v2/cpu/validate":
                if not admin:
                    return self.send(403, {"error": "admin credential required"})
                if row[1] not in ("reported", "accepted", "rejected"):
                    return self.send(409, {"error": "result not reported"})
                if row[1] != "reported":
                    return self.send(200, {"state": row[1], "duplicate": True})
                payload = json.loads(row[0])
                if payload["client"] not in verifiable:
                    return self.send(503, {"error": "compatible validator unavailable on this node"})
                if "results" not in checked:
                    return self.send(503, {"error": "Job changed during validation; retry"})
                if "error" in checked:
                    db.execute("UPDATE cpu_jobs SET state='rejected',verification=? WHERE id=?", (json.dumps({"error": checked["error"]}), body["id"]))
                    return self.send(200, {"state": "rejected", "verified": False, "error": checked["error"]})
                results = []
                for addr, score, spans in checked["results"]:
                    stored, improved = replica.store.submit(payload["client"], addr, payload["user"], score, payload["source"], spans, model=payload["model"], verified=True)
                    results.append({"addr": addr, "score": score, "stored": stored, "improved": improved, "verified": True})
                state = "accepted" if any(r["improved"] for r in results) else "rejected"
                db.execute("UPDATE cpu_jobs SET state=?,verification=? WHERE id=?", (state, json.dumps(results), body["id"]))
                return self.send(200, {"state": state, "results": results, "verified": True})
            return self.send(404, {"error": "unknown endpoint"})

    return Handler


def serve(config):
    replica = Replica(config)
    with replica.lock:
        replica.sync()
        if not replica.db.execute("SELECT 1 FROM cluster_requests WHERE id='bootstrap-complete'").fetchone():
            replica.close()
            raise RuntimeError("Bootstrap incomplete; initialize a fresh ledger before serving")
    available = setup.compilers()
    verifiable = {name for name, e in clients.load().items() if name != "2009-12" and not e.get("donor")
                  and e.get("compiler_build") in available and clients.status(name, e) == "ok"}
    httpd = ThreadingHTTPServer((config.get("host", "127.0.0.1"), config["port"]), handler(replica, config, verifiable))
    httpd.daemon_threads = True
    httpd.replica = replica
    return httpd


def initialize(config, source_db=None):
    """Import an offline SQLite backup once; never modify the live server DB."""
    journal = Journal(config)
    try:
        journal.wait(journal.create())
        source_hash = hashlib.sha256()
        if source_db:
            with open(source_db, "rb") as backup:
                for chunk in iter(lambda: backup.read(1 << 20), b""):
                    source_hash.update(chunk)
        source_hash = source_hash.hexdigest()
        seq = journal.wait(journal.head())
        resume = -1
        if seq:
            first = journal.wait(journal.get(1))
            last = journal.wait(journal.get(seq))
            if first.get("bootstrap_source") != source_hash:
                raise RuntimeError("Bootstrap backup differs; refusing to mix datasets")
            if last.get("bootstrap_complete"):
                return
            resume = last.get("bootstrap_step", -1)
        step = -1
        def append(sql, complete=False):
            nonlocal step, seq
            step += 1
            if step <= resume:
                return
            record = {"id": hashlib.sha256((source_hash + ":" + str(step)).encode()).hexdigest(),
                      "identity": identity(), "sql": sql, "bootstrap_step": step,
                      "bootstrap_source": source_hash, "bootstrap_complete": complete}
            seq = journal.wait(journal.append(record, seq))
        initial = config.get("initial_contributor")
        append(["INSERT INTO cluster_contributors VALUES(%s,%s,1)" % (
                "'" + initial["id"].replace("'", "''") + "'", "'" + initial["token_hash"] + "'")] if initial else [])
        if source_db:
            src = sqlite3.connect(Path(source_db).resolve().as_uri() + "?mode=ro", uri=True)
            try:
                # Data only; Store creates the schema. Keep old unverified events honest.
                tables = {r[0] for r in src.execute("SELECT name FROM sqlite_master WHERE type='table'")}
                for table in ("funcs", "leases", "events", "mining_events", "workers"):
                    if table not in tables or table in ("leases", "workers"):
                        continue
                    columns = [r[1] for r in src.execute('PRAGMA table_info("%s")' % table)]
                    batch, size = [], 0
                    for row in src.execute('SELECT * FROM "%s" WHERE client != ?' % table, ("2009-12",)):
                        if any(isinstance(v, str) and "\0" in v for v in row):
                            raise RuntimeError("Backup contains NUL text; repair before importing")
                        literals = [src.execute("SELECT quote(?)", (v,)).fetchone()[0] for v in row]
                        sql = 'INSERT INTO "%s" (%s) VALUES(%s)' % (table, ",".join('"%s"' % c for c in columns), ",".join(literals))
                        batch.append(sql)
                        size += len(sql.encode())
                        if size >= 500000:
                            append(batch)
                            batch, size = [], 0
                    if batch:
                        append(batch)
            finally:
                src.close()
        append(["INSERT INTO cluster_requests VALUES('bootstrap-complete','bootstrap','[]')"], complete=True)
    finally:
        journal.close()


def load_config(path):
    path = Path(path).resolve()
    config = json.loads(path.read_text())
    for key in ("worker_token", "admin_token", "nats_token"):
        if len(config.get(key, "")) < 24:
            raise ValueError("Cluster credentials must have at least 24 characters")
    if config["worker_token"] == config["admin_token"]:
        raise ValueError("Separate admin and worker credentials required")
    config.setdefault("cluster_id", hashlib.sha256(config["nats_token"].encode()).hexdigest()[:32])
    for key in ("db", "broker_config"):
        if key in config:
            config[key] = str((path.parent / config[key]).resolve())
    Path(config["db"]).parent.mkdir(parents=True, exist_ok=True)
    return config
