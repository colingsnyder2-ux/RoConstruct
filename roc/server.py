"""Group server: hands out functions, keeps the best source per function,
credits whoever improved it.

Workers lease one function at a time; a lease expires if its worker stops
heartbeating, so crashed workers never leave a function stuck. Submissions
are re-scored here when this machine has the client's compiler.
"""
import json
import re
import sqlite3
import subprocess
import threading
import time
import uuid
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlparse

from roc import clients, match, setup

ROOT = Path(__file__).resolve().parent.parent
USER_RE = re.compile(r"^[A-Za-z0-9_.-]{2,32}$")
SCHEMA = """
CREATE TABLE IF NOT EXISTS funcs(client TEXT, addr TEXT, size INT, unit TEXT,
  score INT DEFAULT 0, source TEXT, user TEXT, attempts INT DEFAULT 0, updated REAL,
  PRIMARY KEY(client, addr));
CREATE TABLE IF NOT EXISTS leases(id TEXT PRIMARY KEY, client TEXT, addr TEXT,
  user TEXT, worker TEXT, expires REAL);
CREATE TABLE IF NOT EXISTS events(ts REAL, client TEXT, addr TEXT, user TEXT, old INT, new INT);
CREATE TABLE IF NOT EXISTS workers(id TEXT PRIMARY KEY, user TEXT, mode TEXT, last_seen REAL);
CREATE INDEX IF NOT EXISTS funcs_open ON funcs(client, score, attempts, size);
"""


class Store:
    def __init__(self, path, lease_seconds):
        self.db = sqlite3.connect(path, check_same_thread=False)
        self.db.executescript(SCHEMA)
        if "data" not in {r[1] for r in self.db.execute("PRAGMA table_info(funcs)")}:
            self.db.execute("ALTER TABLE funcs ADD COLUMN data TEXT")  # verified data spans, JSON
        self.lock = threading.Lock()
        self.lease_seconds = lease_seconds

    def seed(self, client):
        """Load analyzed functions (real code only) for one client."""
        path = ROOT / "work" / client / "functions.jsonl"
        if not path.exists():
            return 0
        rows = []
        for line in path.open():
            f = json.loads(line)
            if f.get("kind", "code") == "code":
                rows.append((client, f["addr"], f["size"], f["unit"]))
        keep = {r[1] for r in rows}
        with self.lock:
            before = self.db.total_changes
            self.db.executemany("INSERT OR IGNORE INTO funcs(client,addr,size,unit) VALUES(?,?,?,?)", rows)
            added = self.db.total_changes - before
            # Re-analysis may drop junk "functions"; forget them unless someone worked on them.
            stale = [(client, a) for (a,) in self.db.execute(
                "SELECT addr FROM funcs WHERE client = ? AND source IS NULL", (client,)) if a not in keep]
            self.db.executemany("DELETE FROM funcs WHERE client = ? AND addr = ?", stale)
            self.db.commit()
            return added

    def lease(self, user, worker, have, mode, max_size):
        now = time.time()
        with self.lock:
            self.db.execute("DELETE FROM leases WHERE expires < ?", (now,))
            self.db.execute("INSERT OR REPLACE INTO workers VALUES(?,?,?,?)", (worker, user, mode, now))
            # One live lease per worker: a restarted worker gets a fresh job, old one frees up.
            self.db.execute("DELETE FROM leases WHERE worker = ?", (worker,))
            marks = ",".join("?" * len(have))
            row = self.db.execute(
                "SELECT client, addr, size, unit, score, source FROM funcs f "
                "WHERE client IN (%s) AND score < 100 AND size <= ? AND NOT EXISTS "
                "(SELECT 1 FROM leases l WHERE l.client = f.client AND l.addr = f.addr) "
                "ORDER BY attempts, size LIMIT 1" % marks, (*have, max_size)).fetchone()
            if not row:
                self.db.commit()
                return None
            lease = uuid.uuid4().hex
            self.db.execute("INSERT INTO leases VALUES(?,?,?,?,?,?)",
                            (lease, row[0], row[1], user, worker, now + self.lease_seconds))
            self.db.execute("UPDATE funcs SET attempts = attempts + 1 WHERE client = ? AND addr = ?", row[:2])
            self.db.commit()
        return {"lease": lease, "client": row[0], "addr": row[1], "size": row[2], "unit": row[3],
                "score": row[4], "source": row[5], "heartbeat": max(5, self.lease_seconds // 3)}

    def heartbeat(self, lease):
        with self.lock:
            cur = self.db.execute("UPDATE leases SET expires = ? WHERE id = ?", (time.time() + self.lease_seconds, lease))
            self.db.commit()
            return cur.rowcount == 1

    def release(self, lease):
        with self.lock:
            self.db.execute("DELETE FROM leases WHERE id = ?", (lease,))
            self.db.commit()

    def submit(self, client, addr, user, score, source, data=None):
        """Keep the source if it beats the stored score. Returns (stored score, improved)."""
        now = time.time()
        with self.lock:
            row = self.db.execute("SELECT score FROM funcs WHERE client = ? AND addr = ?", (client, addr)).fetchone()
            if not row:
                raise ValueError("unknown function %s %s" % (client, addr))
            if score <= row[0]:
                return row[0], False
            self.db.execute("UPDATE funcs SET score=?, source=?, user=?, updated=?, data=? WHERE client=? AND addr=?",
                            (score, source, user, now, json.dumps(data) if data else None, client, addr))
            self.db.execute("INSERT INTO events VALUES(?,?,?,?,?,?)", (now, client, addr, user, row[0], score))
            self.db.commit()
            return score, True

    def leaderboard(self, client=None):
        """Overall ranking, or one client's when client is given."""
        where, args = ("WHERE client = ?", (client,)) if client else ("", ())
        with self.lock:
            rows = self.db.execute(
                "SELECT user, SUM(new = 100 AND old < 100), SUM(new - old), COUNT(*), MAX(ts) "
                "FROM events %s GROUP BY user ORDER BY 2 DESC, 3 DESC" % where, args).fetchall()
        return [{"user": u, "matched": m or 0, "points": p or 0, "submissions": n, "last": t}
                for u, m, p, n, t in rows]

    def scores(self):
        with self.lock:
            rows = self.db.execute("SELECT client, addr, score FROM funcs WHERE score > 0").fetchall()
        out = {}
        for c, a, s in rows:
            out.setdefault(c, {})[a] = s
        return out

    def data(self):
        with self.lock:
            rows = self.db.execute("SELECT client, addr, data FROM funcs WHERE data IS NOT NULL").fetchall()
        out = {}
        for c, a, d in rows:
            out.setdefault(c, {})[a] = json.loads(d)
        return out

    def status(self):
        now = time.time()
        with self.lock:
            per = self.db.execute("SELECT client, COUNT(*), SUM(score = 100), SUM(score > 0 AND score < 100) "
                                  "FROM funcs GROUP BY client").fetchall()
            leases = self.db.execute("SELECT client, addr, user, expires FROM leases WHERE expires >= ?", (now,)).fetchall()
            workers = self.db.execute("SELECT user, mode, last_seen FROM workers WHERE last_seen > ?", (now - 900,)).fetchall()
        return {"clients": [{"client": c, "functions": n, "matched": m or 0, "partial": p or 0} for c, n, m, p in per],
                "leases": [{"client": c, "addr": a, "user": u, "expires_in": int(e - now)} for c, a, u, e in leases],
                "workers": [{"user": u, "mode": m, "seen_ago": int(now - t)} for u, m, t in workers]}

    def best(self, client, addr):
        with self.lock:
            row = self.db.execute("SELECT score, source, user FROM funcs WHERE client = ? AND addr = ?",
                                  (client, addr)).fetchone()
        return {"score": row[0], "source": row[1], "user": row[2]} if row else None

    def examples(self, client, n=3):
        """Small matched sources, used as few-shot examples for AI workers."""
        with self.lock:
            rows = self.db.execute("SELECT addr, source FROM funcs WHERE client = ? AND score = 100 "
                                   "AND source IS NOT NULL ORDER BY RANDOM() LIMIT ?", (client, n)).fetchall()
        return [{"addr": a, "source": s} for a, s in rows]

    def sources(self, client, min_score=1):
        """Every stored source for a client (for `roc pull`)."""
        with self.lock:
            rows = self.db.execute("SELECT addr, score, user, source FROM funcs WHERE client = ? AND score >= ? "
                                   "AND source IS NOT NULL ORDER BY addr", (client, min_score)).fetchall()
        return [{"addr": a, "score": s, "user": u, "source": src} for a, s, u, src in rows]


def export(store):
    """Everything the website needs from the database."""
    scores = store.scores()
    return {"scores": scores, "data": store.data(), "leaderboard": store.leaderboard(),
            "leaderboards": {c: store.leaderboard(c)[:20] for c in scores}}


def make_handler(store, token, can_verify):
    class Handler(BaseHTTPRequestHandler):
        def log_message(self, fmt, *args):
            pass

        def send(self, code, obj):
            """Write a response. A worker that gave up and closed the socket (timeout,
            restart, laptop sleep) is normal, not an error: the request was handled and
            there is simply nobody left to tell. Failing here raised
            ConnectionAbortedError out of the handler thread and printed a traceback for
            every abandoned request."""
            body = json.dumps(obj).encode()
            try:
                self.send_response(code)
                self.send_header("Content-Type", "application/json")
                self.send_header("Content-Length", str(len(body)))
                self.send_header("Access-Control-Allow-Origin", "*")
                self.end_headers()
                self.wfile.write(body)
            except (ConnectionAbortedError, ConnectionResetError, BrokenPipeError):
                self.close_connection = True

        def do_GET(self):
            url = urlparse(self.path)
            q = {k: v[0] for k, v in parse_qs(url.query).items()}
            if url.path == "/v1/info":
                reg = clients.load()
                return self.send(200, {"clients": {n: {k: e.get(k) for k in ("sha256", "compiler", "compiler_build", "flags")}
                                                   for n, e in reg.items()}, "verify": sorted(can_verify)})
            if url.path == "/v1/status":
                return self.send(200, store.status())
            if url.path == "/v1/leaderboard":
                return self.send(200, store.leaderboard())
            if url.path == "/v1/export":
                return self.send(200, export(store))
            if url.path == "/v1/source":
                best = store.best(q.get("client", ""), q.get("addr", ""))
                return self.send(200 if best else 404, best or {"error": "unknown function"})
            if url.path == "/v1/sources":
                return self.send(200, store.sources(q.get("client", ""), int(q.get("min_score", 1))))
            if url.path == "/v1/examples":
                return self.send(200, store.examples(q.get("client", ""), min(int(q.get("n", 3)), 10)))
            self.send(404, {"error": "unknown endpoint"})

        def do_POST(self):
            if token and self.headers.get("X-Roc-Token") != token:
                return self.send(403, {"error": "wrong or missing server password (token)"})
            try:
                length = int(self.headers.get("Content-Length") or 0)
                if length > 1 << 20:
                    return self.send(413, {"error": "too large"})
                body = json.loads(self.rfile.read(length) or b"{}")
            except (ValueError, json.JSONDecodeError):
                return self.send(400, {"error": "bad json"})
            path = urlparse(self.path).path
            user = str(body.get("user", ""))
            if path in ("/v1/lease", "/v1/submit") and not USER_RE.match(user):
                return self.send(400, {"error": "username must be 2-32 letters, digits, _ . -"})
            if path == "/v1/lease":
                have = [c for c in body.get("clients", []) if isinstance(c, str)]
                if not have:
                    return self.send(400, {"error": "no clients"})
                job = store.lease(user, str(body.get("worker", ""))[:64], have,
                                  str(body.get("mode", ""))[:16], int(body.get("max_size", 256)))
                return self.send(200, {"job": job})
            if path == "/v1/heartbeat":
                return self.send(200, {"ok": store.heartbeat(str(body.get("lease", "")))})
            if path == "/v1/release":
                store.release(str(body.get("lease", "")))
                return self.send(200, {"ok": True})
            if path == "/v1/submit":
                client, addr = str(body.get("client", "")), str(body.get("addr", ""))
                source, claimed = str(body.get("source", "")), int(body.get("score", 0))
                if not source.strip() or len(source) > 200_000:
                    return self.send(400, {"error": "empty or huge source"})
                score, verified, spans = claimed, False, None
                if client in can_verify:
                    try:
                        score, _, _, spans = match.check_text(client, addr, source)
                        verified = True
                    except match.CompileError as error:
                        return self.send(400, {"error": "does not compile here: %s" % str(error)[:500]})
                    except SystemExit as error:
                        return self.send(400, {"error": str(error)})
                else:
                    try:
                        match.reject_asm(source)
                    except match.CompileError as error:
                        return self.send(400, {"error": str(error)})
                try:
                    stored, improved = store.submit(client, addr, user, max(0, min(100, score)), source, spans)
                except ValueError as error:
                    return self.send(400, {"error": str(error)})
                if body.get("lease"):
                    store.release(str(body["lease"]))
                return self.send(200, {"score": score, "stored": stored, "improved": improved, "verified": verified})
            self.send(404, {"error": "unknown endpoint"})

    return Handler


def serve(host="0.0.0.0", port=8765, db=None, token=None, lease_seconds=900, log=print):
    db = db or str(ROOT / "work" / "server.db")
    Path(db).parent.mkdir(parents=True, exist_ok=True)
    store = Store(db, lease_seconds)
    for name in clients.load():
        added = store.seed(name)
        if added:
            log("Loaded %d functions for %s" % (added, name))
    have = setup.compilers()
    can_verify = {n for n, e in clients.load().items()
                  if e.get("compiler_build") in have and clients.status(n, e) == "ok"}
    log("Re-checking submissions for: %s" % (", ".join(sorted(can_verify)) or "none (trusting workers)"))
    from roc import auto
    for name in sorted(can_verify):
        done = {a for a, s in store.scores().get(name, {}).items() if s == 100}
        found = auto.solve(name, skip=done, log=lambda *a: None)
        for addr, src in found.items():
            store.submit(name, addr, "auto", 100, src)
        if found:
            log("Auto-matched %d trivial functions for %s (credited to 'auto')" % (len(found), name))
    httpd = ThreadingHTTPServer((host, port), make_handler(store, token, can_verify))
    httpd.store = store
    log("RoConstruct server running on port %d. Workers connect with:  roc worker --server http://<this-pc>:%d"
        % (port, port))
    return httpd


def start_tunnel(port, log=print):
    """Cloudflare quick tunnel: public HTTPS URL, no account, no router setup.
    ponytail: the URL changes on every restart; workers re-read it from the site.
    A named tunnel (cloudflared login) gives a fixed address if that hurts."""
    exe = setup.get_cloudflared()
    # A tunnel left over from a closed server window answers "Bad Gateway": remove it.
    setup.powershell("Get-CimInstance Win32_Process -Filter \"Name='cloudflared.exe'\" | Where-Object "
                     "{ $_.CommandLine -match '127.0.0.1:%d' } | ForEach-Object { Stop-Process -Id $_.ProcessId -Force }"
                     % port)
    proc = subprocess.Popen([exe, "tunnel", "--no-autoupdate", "--url", "http://127.0.0.1:%d" % port],
                            stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, text=True,
                            creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
    url = None
    for line in proc.stderr:
        m = re.search(r"https://[a-z0-9-]+\.trycloudflare\.com", line)
        if m:
            url = m.group(0)
            break
    if not url:
        raise SystemExit("cloudflared exited without a tunnel URL")
    threading.Thread(target=lambda: [None for _ in proc.stderr], daemon=True).start()  # keep pipe drained
    log("Public HTTPS address: %s" % url)
    return url, proc


def publish_once(store, public_url, log=print):
    """Rebuild docs/ from the live database and push it, if anything changed."""
    from roc import progress, setup
    progress.build(public_server=public_url, remote=export(store))
    setup.refresh_path()
    git_exe = setup.find_exe("git")
    if not git_exe:
        return log("git not found, so the site was not published. docs/ is updated locally.")
    git = lambda *a: subprocess.run([git_exe, *a], cwd=ROOT, capture_output=True, text=True)
    git("add", "docs")
    if git("diff", "--cached", "--quiet").returncode == 0:
        return log("Site unchanged.")
    git("commit", "-m", "Update progress")
    push = git("push", "origin", "HEAD")
    log("Site published." if push.returncode == 0 else "Site push failed: %s" % push.stderr.strip()[-300:])


def publish_loop(store, public_url, every, log=print):
    while True:
        try:
            publish_once(store, public_url, log)
        except Exception as error:  # keep serving even if a publish fails
            log("Publish failed: %s" % error)
        time.sleep(every)
