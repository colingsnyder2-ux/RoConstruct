"""Group server: suggests shared functions, keeps the best source per function,
and credits whoever improved it. Submissions are re-scored here when this
machine has the client's compiler.
"""
import gzip
import json
import hashlib
import os
import re
import shutil
import sqlite3
import subprocess
import tempfile
import threading
import time
import uuid
from collections import deque
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlparse

from roc import clients, match, setup, integration as integration_protocol

ROOT = Path(__file__).resolve().parent.parent
USER_RE = re.compile(r"^[A-Za-z0-9_.-]{2,32}$")
CLAIM_SECONDS = 2 * 3600  # one agent batch (max 120 min); released early when the batch ends


from roc.tasks import _source_class_token, check_many_text

# Which function a worker gets next. Random is default so parallel workers spread
# across real named units instead of draining one ranked segment at a time.
ORDER_SQL = {
    # most confident evidence first, near-complete next, then cheap
    "best": "source_confidence DESC, (score >= 90) DESC, (unit NOT LIKE 'seg_%') DESC, "
            "difficulty, attempts, size",
    # highest score first: finish the almost-done functions
    "matched": "score DESC, source_confidence DESC, difficulty, size",
    # untouched first: functions still sitting at 0%, fewest tries first
    "unmatched": "(score = 0) DESC, attempts, difficulty, size",
    # cheapest first, ignoring how confident the evidence is
    "easiest": "difficulty, size, source_confidence DESC",
    # spread named functions first; anonymous/blank segments are fallback only
    "random": "CASE WHEN unit IS NULL OR unit = '' OR unit LIKE 'seg_%' THEN 1 ELSE 0 END, RANDOM()",
}
ORDERS = tuple(sorted(ORDER_SQL)) + ("auto",)


def resolve_order(order, db):
    """Turn auto into spread sampling; ranked orders stay explicit."""
    if order != "auto":
        return order if order in ORDER_SQL else "random"
    # Avoid score bias: auto must sample all score bands, including hard/untested.
    return "random"
SCHEMA = """
CREATE TABLE IF NOT EXISTS funcs(client TEXT, addr TEXT, size INT, unit TEXT,
  score INT DEFAULT 0, source TEXT, user TEXT, attempts INT DEFAULT 0, updated REAL, shape TEXT, family TEXT,
  cooldown REAL DEFAULT 0, calls INT DEFAULT 0, source_confidence INT DEFAULT 0,
  difficulty REAL DEFAULT 0, attempts_by_model TEXT DEFAULT '{}',
  PRIMARY KEY(client, addr));
CREATE TABLE IF NOT EXISTS events(ts REAL, client TEXT, addr TEXT, user TEXT, old INT, new INT);
CREATE TABLE IF NOT EXISTS mining_events(id INTEGER PRIMARY KEY, ts REAL, client TEXT, addr TEXT,
  user TEXT, model TEXT, old INT, new INT, verified INT);
CREATE INDEX IF NOT EXISTS mining_events_day ON mining_events(ts);
CREATE INDEX IF NOT EXISTS events_day ON events(ts);
CREATE TABLE IF NOT EXISTS workers(id TEXT PRIMARY KEY, user TEXT, mode TEXT, last_seen REAL);
CREATE INDEX IF NOT EXISTS funcs_open ON funcs(client, score, attempts, size);
CREATE TABLE IF NOT EXISTS agent_attempts(id INTEGER PRIMARY KEY, hash TEXT UNIQUE,
  user TEXT, ts REAL, payload TEXT);
"""


class Store:
    def __init__(self, path, lease_seconds):
        self.db = sqlite3.connect(path, check_same_thread=False)
        from roc.libs import library_of
        self.db.create_function("roc_library", 1, library_of, deterministic=True)
        self.db.executescript(SCHEMA)
        columns = {r[1] for r in self.db.execute("PRAGMA table_info(funcs)")}
        if "data" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN data TEXT")  # verified data spans, JSON
        if "shape" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN shape TEXT")
        if "family" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN family TEXT")
        if "cooldown" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN cooldown REAL DEFAULT 0")
        if "calls" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN calls INT DEFAULT 0")
        if "source_confidence" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN source_confidence INT DEFAULT 0")
        if "difficulty" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN difficulty REAL DEFAULT 0")
        if "attempts_by_model" not in columns:
            self.db.execute("ALTER TABLE funcs ADD COLUMN attempts_by_model TEXT DEFAULT '{}'")
        self.db.execute("CREATE INDEX IF NOT EXISTS funcs_lease_pool ON funcs "
                        "(client,score,size,cooldown,unit,attempts,source_confidence,difficulty,addr)")
        self.db.execute("CREATE INDEX IF NOT EXISTS funcs_work_pool ON funcs "
                        "(client,score,size,attempts,source_confidence,family,shape)")
        self.db.commit()
        self.lock = threading.Lock()
        self.lease_seconds = lease_seconds  # Legacy server option; assignments do not expire.
        # Soft, in-memory claims: parallel agents skip a function another worker is on while
        # other targets remain. Lost on restart, which only makes work shared again.
        self.claims = {}  # (client, addr) -> (lease, worker, expiry)

    def agent_memory(self, after=0, limit=500):
        from roc import agent_memory
        with self.lock:
            rows = self.db.execute("SELECT id,user,payload FROM agent_attempts WHERE id>? ORDER BY id LIMIT ?",
                                   (after, limit)).fetchall()
        path = ROOT / "research" / "lessons.json"
        return {"lessons": json.loads(path.read_text(encoding="utf-8")) if path.exists() else [],
                "context": agent_memory.context(),
                "records": [dict(json.loads(payload), shared_id=identifier, reported_by=user)
                            for identifier, user, payload in rows],
                "cursor": rows[-1][0] if rows else after, "more": len(rows) == limit}

    def remember(self, user, rows):
        if not isinstance(rows, list) or not 1 <= len(rows) <= 100:
            raise ValueError("Need 1-100 attempt records")
        payloads = []
        for row in rows:
            if not isinstance(row, dict) or row.get("client", "2008-06") not in clients.load():
                raise ValueError("Attempt records must describe a registered client")
            row = {k: v for k, v in row.items() if k not in ("shared_id", "reported_by", "server_confirmed")}
            addresses = row.get("addresses", [])
            if not isinstance(addresses, list) or len(addresses) > 200 or not all(
                    isinstance(addr, str) and re.fullmatch(r"[0-9a-f]{8}", addr) for addr in addresses):
                raise ValueError("Need at most 200 eight-digit addresses")
            payload = json.dumps(row, sort_keys=True, ensure_ascii=True)
            if len(payload) > 16000:
                raise ValueError("Attempt record exceeds 16000 characters")
            payloads.append((hashlib.sha256((user + payload).encode()).hexdigest(), row))
        added = 0
        with self.lock:
            for key, row in payloads:
                addresses = row.get("addresses", [])
                confirmed = False
                if row.get("kind") == "auto_target" and row.get("outcome") == "server_verified" and len(addresses) == 1:
                    best = self.db.execute("SELECT source,score FROM funcs WHERE client=? AND addr=?",
                                           (row.get("client", "2008-06"), addresses[0])).fetchone()
                    confirmed = bool(best and best[1] == row.get("after") and
                        hashlib.sha256((best[0] or "").encode()).hexdigest() == row.get("source_hash") and
                        self.db.execute("SELECT 1 FROM mining_events WHERE client=? "
                        "AND addr=? AND user=? AND new=? AND verified=1 LIMIT 1",
                        (row.get("client", "2008-06"), addresses[0], user, row.get("after"))).fetchone())
                row["server_confirmed"] = confirmed
                added += self.db.execute("INSERT OR IGNORE INTO agent_attempts(hash,user,ts,payload) VALUES(?,?,?,?)",
                    (key, user, time.time(), json.dumps(row))).rowcount
            self.db.commit()
        return {"added": added}

    def tools(self):
        from roc import agent_memory
        return [row for row in self.agent_memory()["records"] if agent_memory.is_tool_record(row)]

    def tool_records(self):
        return self.tools()

    def suggested_tools(self):
        return self.tools()

    def suggest_tool(self, user, record):
        rows = record if isinstance(record, list) else [record]
        return self.remember(user, rows)

    def save_tool(self, user, record):
        return self.suggest_tool(user, record)

    def auto_improve_workflow(self, server=None, user=None):
        return {"tools": self.tools(), "improved": True}

    def seed(self, client):
        """Load analyzed functions (real code only) for one client."""
        path = ROOT / "work" / client / "functions.jsonl"
        if not path.exists():
            return 0
        rows = []
        for line in path.read_text().splitlines():
            f = json.loads(line)
            if f.get("kind", "code") == "code":
                calls = int(f.get("calls", 0) or 0)
                unit = f["unit"]
                rows.append((client, f["addr"], f["size"], unit, f.get("shape"), calls,
                             0 if unit.startswith("seg_") else 1, f["size"] + calls * 4))
        keep = {r[1] for r in rows}
        with self.lock:
            before = self.db.total_changes
            self.db.executemany("INSERT OR IGNORE INTO funcs(client,addr,size,unit,shape,calls,source_confidence,difficulty) VALUES(?,?,?,?,?,?,?,?)", rows)
            added = self.db.total_changes - before
            # A changed extent invalidates the old score (it measured other bytes); the source stays as a reference.
            self.db.executemany("UPDATE funcs SET score=CASE WHEN size=? THEN score ELSE 0 END, size=?, unit=?, shape=?, "
                                "calls=?, source_confidence=?, difficulty=? WHERE client=? AND addr=?",
                                [(size, size, unit, shape, calls, confidence, difficulty, client, addr)
                                 for client, addr, size, unit, shape, calls, confidence, difficulty in rows])
            # Re-analysis may drop junk "functions"; never count them in progress again.
            stale = [(client, a) for (a,) in self.db.execute(
                "SELECT addr FROM funcs WHERE client = ?", (client,)) if a not in keep]
            self.db.executemany("DELETE FROM funcs WHERE client = ? AND addr = ?", stale)
            self.db.commit()
            return added

    def lease(self, user, worker, have, mode, max_size, model=None, targets=None, order="random", family=None, unit=None,
              min_score=None, max_score=None, library=None):
        """Pick work cooperatively.

        This endpoint used to create an exclusive, expiring lease.  Matching is
        now deliberately shared: several people or agents may investigate the
        same function and the normal best-score write in ``submit`` resolves the
        race.  Keep the endpoint/name for older workers, but return an assignment
        token only as harmless request correlation.
        """
        now = time.time()
        with self.lock:
            self.db.execute("INSERT OR REPLACE INTO workers VALUES(?,?,?,?)", (worker, user, mode, now))
            marks = ",".join("?" * len(have))
            size_sql, size_args = (" AND size <= ?", [max_size]) if max_size else ("", [])
            target_sql, target_args = "", []
            family_sql, family_args = (" AND f.family = ?", [family]) if family else ("", [])
            unit_sql, unit_args = (" AND f.unit = ?", [unit]) if unit else ("", [])
            if library:
                unit_sql += " AND roc_library(f.unit) = ?"
                unit_args.append(library)
            score_sql, score_args = (" AND f.score >= ?", [min_score]) if min_score is not None else ("", [])
            if max_score is not None:
                score_sql += " AND f.score <= ?"
                score_args.append(max_score)
            if targets:
                pairs = [(str(t.get("client", "")), str(t.get("addr", "")))
                         for t in targets if isinstance(t, dict)]
                pairs = [(c, a) for c, a in pairs if c in have and re.match(r"^[0-9a-f]{8}$", a)]
                if pairs:
                    target_sql = " AND (" + " OR ".join("(f.client = ? AND f.addr = ?)" for _ in pairs) + ")"
                    target_args = [v for pair in pairs for v in pair]
                else:
                    self.db.commit()
                    return None
            keys = self.db.execute(
                "SELECT client, addr FROM funcs f "
                "WHERE client IN (%s) AND score < 100 AND size >= 6 %s %s%s%s%s "
                "ORDER BY %s LIMIT 64" % (marks, size_sql, target_sql, family_sql, unit_sql, score_sql,
                                          ORDER_SQL[resolve_order(order, self.db)]),
                (*have, *size_args, *target_args, *family_args, *unit_args, *score_args)).fetchall()
            # Fetch source/metadata only for the sampled functions; avoid sorting
            # every eligible function's large source text while holding the lock.
            candidates = [self.db.execute(
                "SELECT client,addr,size,unit,score,source,shape,calls,source_confidence,difficulty,attempts_by_model,family "
                "FROM funcs WHERE client=? AND addr=?", key).fetchone() for key in keys]
            self.claims = {key: claim for key, claim in self.claims.items() if claim[2] > now}
            free = [c for c in candidates if self.claims.get((c[0], c[1]), (None, worker))[1] == worker]
            if candidates and not free and targets:
                self.db.commit()
                return None  # every requested target is being worked on by another worker
            candidates = free or candidates
            row = None
            if candidates:
                # Do not burn the same model repeatedly on a stubborn target when
                # another eligible target exists.  Two attempts is enough to force
                # a different profile/model while still allowing recovery later.
                for candidate in candidates:
                    tried = json.loads(candidate[10] or "{}")
                    if not model or int(tried.get(model, 0)) < 2:
                        row = candidate
                        break
                row = row or candidates[0]
            if not row:
                self.db.commit()
                return None
            lease = uuid.uuid4().hex
            self.claims[(row[0], row[1])] = (lease, worker, now + CLAIM_SECONDS)
            current = self.db.execute("SELECT attempts_by_model FROM funcs WHERE client = ? AND addr = ?", row[:2]).fetchone()[0]
            by_model = json.loads(current or "{}")
            if model:
                by_model[model] = int(by_model.get(model, 0)) + 1
            self.db.execute("UPDATE funcs SET attempts = attempts + 1, attempts_by_model = ? WHERE client = ? AND addr = ?",
                            (json.dumps(by_model, separators=(",", ":")), row[0], row[1]))
            self.db.commit()
        return {"lease": lease, "client": row[0], "addr": row[1], "size": row[2], "unit": row[3],
                "worker": worker, "model": model or "auto",
                "score": row[4], "source": row[5], "shape": row[6], "calls": row[7],
                "source_confidence": row[8], "difficulty": row[9], "attempts_by_model": json.loads(row[10] or "{}"),
                "family": row[11],
                "heartbeat": 3600}

    def heartbeat(self, lease):
        # Legacy clients still ping this endpoint. Assignments never expire.
        return True

    def release(self, lease, cooldown=0, worker=None, client=None, addr=None):
        """Free a soft claim, but only the one this token names.

        The token is the credential: a caller that guesses an address cannot
        release another worker's claim, and a stale token never frees a newer
        claim for the same function."""
        lease = str(lease or "")
        if not lease:
            return {"ok": False, "released": False, "reason": "missing lease token"}
        with self.lock:
            for key, claim in list(self.claims.items()):
                if claim[0] != lease:
                    continue
                if worker and claim[1] != worker:
                    return {"ok": False, "released": False, "reason": "lease belongs to another worker"}
                if (client and key[0] != client) or (addr and key[1] != addr):
                    return {"ok": False, "released": False, "reason": "lease does not match that function"}
                del self.claims[key]
                return {"ok": True, "released": True, "client": key[0], "addr": key[1],
                        "worker": claim[1]}
        return {"ok": True, "released": False, "reason": "unknown or expired lease"}

    def claim(self, client, addr, worker):
        """Register a soft claim so other agents skip this function while it is being
        worked on. Returns a lease token, or None when another worker already holds it."""
        now = time.time()
        lease = uuid.uuid4().hex
        with self.lock:
            self.claims = {key: claim for key, claim in self.claims.items() if claim[2] > now}
            current = self.claims.get((client, addr))
            if current and current[1] != worker:
                return None
            self.claims[(client, addr)] = (lease, worker, now + CLAIM_SECONDS)
        return {"lease": lease, "expires_in": CLAIM_SECONDS, "expires": now + CLAIM_SECONDS,
                "client": client, "addr": addr, "worker": worker}

    def functions(self, client, min_score=0, max_score=99, limit=500, order="score"):
        """Read-only ranking of one client's functions for manual matching: score, size,
        unit, shape/family (for twin detection), attempts, and whether another worker
        currently claims it. ``twin`` names a 100%-matched function with the same shape
        (or, failing that, family), which is usually the cheapest copy-and-adjust fix.

        ``order="work"`` applies :mod:`roc.ranking` before the limit, so a low-scored
        but easy twin outside the old top-500 score slice is still discoverable.
        The default ``score`` order keeps older clients byte-compatible.
        """
        if order == "work":
            rows = self.work_candidates(client, limit=limit, min_score=min_score,
                                        max_score=max_score, profile="balanced")
            return [{key: row[key] for key in
                     ("addr", "size", "unit", "score", "shape", "family", "attempts",
                      "source_confidence", "twin", "claimed")} for row in rows]
        now = time.time()
        with self.lock:
            self.claims = {key: claim for key, claim in self.claims.items() if claim[2] > now}
            matched = self.db.execute(
                "SELECT addr, shape, family FROM funcs WHERE client = ? AND score = 100 "
                "AND (shape IS NOT NULL OR family IS NOT NULL)", (client,)).fetchall()
            shape_twin, family_twin = {}, {}
            for addr, shape, family in matched:
                if shape and shape not in shape_twin:
                    shape_twin[shape] = addr
                if family and family not in family_twin:
                    family_twin[family] = addr
            rows = self.db.execute(
                "SELECT addr, size, unit, score, shape, family, attempts, source_confidence "
                "FROM funcs WHERE client = ? AND score >= ? AND score <= ? "
                "ORDER BY score DESC, attempts, size LIMIT ?",
                (client, min_score, max_score, max(1, min(limit, 2000)))).fetchall()
        out = []
        for addr, size, unit, score, shape, family, attempts, confidence in rows:
            twin = None
            if shape and shape in shape_twin:
                twin = shape_twin[shape]
            elif family and family in family_twin:
                twin = family_twin[family]
            claim = self.claims.get((client, addr))
            out.append({"addr": addr, "size": size, "unit": unit, "score": score,
                        "shape": shape, "family": family, "attempts": attempts,
                        "source_confidence": confidence, "twin": twin,
                        "claimed": bool(claim and claim[2] > now)})
        return out

    def work_candidates(self, client, limit=20, min_score=0, max_score=99, profile="quick",
                        max_size=None, include_claimed=True):
        """Server-side ranked open targets over the full eligible pool.

        Read-only: no claim is created and no target is reserved.  Ranking happens
        before ``LIMIT``; the SQL only bounds columns and row count, so a cheap
        low-score twin is not hidden by a score-first slice.  ``mismatch_category``
        is ``None`` because the schema has no measured residue column; callers must
        compute a cheap local category after shortlisting.
        """
        from roc import ranking
        now = time.time()
        with self.lock:
            self.claims = {key: claim for key, claim in self.claims.items() if claim[2] > now}
            matched_rows = self.db.execute(
                "SELECT addr, shape, family FROM funcs WHERE client = ? AND score = 100 "
                "AND (shape IS NOT NULL OR family IS NOT NULL)", (client,)).fetchall()
            shape_twin, family_twin = {}, {}
            for addr, shape, family in matched_rows:
                if shape and shape not in shape_twin:
                    shape_twin[shape] = addr
                if family and family not in family_twin:
                    family_twin[family] = addr
            # Bounded but complete enough for one client: reads no source text and
            # ranks in Python with the same helper the CLI uses offline.
            rows = self.db.execute(
                "SELECT addr,size,unit,score,shape,family,attempts,source_confidence,difficulty,"
                "calls,cooldown,attempts_by_model,"
                "CASE WHEN source IS NOT NULL AND length(source)>0 THEN 1 ELSE 0 END "
                "FROM funcs WHERE client=? AND score>=? AND score<=? AND size>=6 "
                "ORDER BY score DESC, attempts, size LIMIT 200000",
                (client, int(min_score), int(max_score))).fetchall()
        pool = []
        for (addr, size, unit, score, shape, family, attempts, confidence, difficulty,
             calls, cooldown, by_model, has_source) in rows:
            claim = self.claims.get((client, addr))
            stuck = 0
            try:
                stuck = sum(1 for count in json.loads(by_model or "{}").values() if int(count) >= 2)
            except (ValueError, TypeError):
                pass
            pool.append({
                "addr": addr, "size": size, "unit": unit, "score": score,
                "shape": shape, "family": family, "attempts": attempts,
                "source_confidence": confidence, "difficulty": difficulty,
                "calls": calls, "has_source": bool(has_source), "stuck_models": stuck,
                "claimed": bool(claim and claim[2] > now),
                "owner": claim[1] if claim else None,
                "claim_expires": claim[2] if claim else None,
                "cooldown_until": cooldown if cooldown and cooldown > now else None,
                "mismatch_category": None,
            })
        ranked = ranking.rank_candidates(pool, {"shape": shape_twin, "family": family_twin},
                                         profile_name=profile, max_size=max_size,
                                         limit=max(1, min(int(limit), 200)),
                                         exclude_claimed=not include_claimed)
        return ranked

    def submit(self, client, addr, user, score, source, data=None, lease=None, model="", verified=False):
        """Keep the source if it beats the stored score. Returns (stored score, improved)."""
        with self.lock:
            row = self.db.execute("SELECT score FROM funcs WHERE client = ? AND addr = ?", (client, addr)).fetchone()
            if not row:
                raise ValueError("unknown function %s %s" % (client, addr))
            if score <= row[0]:
                return row[0], False
            self.db.execute("UPDATE funcs SET score=?, source=?, user=?, updated=?, data=? WHERE client=? AND addr=?",
                            (score, source, user, time.time(), json.dumps(data) if data else None, client, addr))
            self.db.execute("INSERT INTO events VALUES(?,?,?,?,?,?)", (time.time(), client, addr, user, row[0], score))
            self.db.execute("INSERT INTO mining_events(ts,client,addr,user,model,old,new,verified) VALUES(?,?,?,?,?,?,?,?)",
                            (time.time(), client, addr, user, str(model)[:120], row[0], score, int(verified)))
            self.db.commit()
            return score, True

    def daily_stats(self, day=None, timezone="America/New_York"):
        from roc.reports import day_bounds, summarize
        day, start, end = day_bounds(day, timezone)
        with self.lock:
            rows = self.db.execute("SELECT id,ts,client,addr,user,model,old,new,verified FROM mining_events "
                                   "WHERE ts >= ? AND ts < ?", (start, end)).fetchall()
            legacy = self.db.execute("SELECT COUNT(DISTINCT client || ':' || addr) FROM events e "
                                     "WHERE ts >= ? AND ts < ? AND new = 100 AND old < 100 AND client != '2009-12' "
                                     "AND NOT EXISTS (SELECT 1 FROM mining_events m WHERE m.ts=e.ts AND m.client=e.client AND m.addr=e.addr)",
                                     (start, end)).fetchone()[0]
        fields = ("id", "ts", "client", "addr", "user", "model", "old", "new", "verified")
        return summarize([dict(zip(fields, row)) for row in rows], day, timezone, legacy)

    def leaderboard(self, client=None):
        """Overall ranking, or one client's when client is given."""
        where, args = ("WHERE client = ?", (client,)) if client else ("", ())
        with self.lock:
            rows = self.db.execute(
                "SELECT user, SUM(new = 100 AND old < 100), SUM(new - old), COUNT(*), MAX(ts) "
                "FROM events %s GROUP BY user ORDER BY 2 DESC, 3 DESC" % where, args).fetchall()
        from roc.reports import server_users
        hidden = server_users()
        ranking = {u: {"user": u, "matched": m or 0, "mining_points": p or 0, "points": p or 0,
                       "native_integrated": 0, "submissions": n, "last": t} for u, m, p, n, t in rows}
        for user, count, stamp in self.native_totals(client):
            row = ranking.setdefault(user, {"user": user, "matched": 0, "mining_points": 0,
                                           "points": 0, "native_integrated": 0, "submissions": 0, "last": stamp})
            row["native_integrated"] = count
            row["points"] += count
            row["last"] = max(row["last"] or 0, stamp or 0)
        return sorted((row for user, row in ranking.items() if user not in hidden),
                      key=lambda row: (-row["points"], -row["matched"], row["user"]))

    def native_totals(self, client=None, user=None):
        """One point per distinct accepted native address; mining-only stores have no native table."""
        with self.lock:
            if not self.db.execute("SELECT 1 FROM sqlite_master WHERE name='integration_credit'").fetchone():
                return []
            conditions, args = [], []
            for key, value in (("client", client), ("user", user)):
                if value is not None:
                    conditions.append(key + "=?")
                    args.append(value)
            where = " WHERE " + " AND ".join(conditions) if conditions else ""
            return self.db.execute("SELECT user,COUNT(*),MAX(ts) FROM integration_credit" + where + " GROUP BY user", args).fetchall()

    def user_points(self, user):
        """Total leaderboard points for one user (0 when unknown)."""
        with self.lock:
            row = self.db.execute("SELECT SUM(new - old) FROM events WHERE user = ?", (user,)).fetchone()
        return int(row[0] or 0) + sum(count for _, count, _ in self.native_totals(user=user))

    def client_progress(self, client):
        """(matched, total) functions for one client."""
        with self.lock:
            row = self.db.execute("SELECT SUM(score = 100), COUNT(*) FROM funcs WHERE client = ?",
                                  (client,)).fetchone()
        return (int(row[0] or 0), int(row[1] or 0))

    def client_bytes(self, client):
        """(matched, total) code bytes for accurate percentage progress."""
        with self.lock:
            row = self.db.execute("SELECT SUM(CASE WHEN score = 100 THEN size ELSE 0 END), SUM(size) "
                                  "FROM funcs WHERE client = ?", (client,)).fetchone()
        return (int(row[0] or 0), int(row[1] or 0))

    def display_progress(self, client):
        """Function and byte totals from the authoritative server score table."""
        with self.lock:
            row = self.db.execute(
                "SELECT SUM(score = 100), COUNT(*), "
                "SUM(CASE WHEN score = 100 THEN size ELSE 0 END), SUM(size) "
                "FROM funcs WHERE client = ?", (client,)).fetchone()
        return tuple(int(value or 0) for value in row)

    def digest_progress(self, client):
        """Exact source, mined, retry, and total bytes for a digest bar."""
        with self.lock:
            row = self.db.execute(
                "SELECT SUM(CASE WHEN score = 100 AND source LIKE '%roc-lib:%' THEN size ELSE 0 END), "
                "SUM(CASE WHEN score = 100 AND (source IS NULL OR source NOT LIKE '%roc-lib:%') THEN size ELSE 0 END), "
                "SUM(CASE WHEN (score > 0 AND score < 100) OR (score = 0 AND attempts > 0) THEN size ELSE 0 END), SUM(size) "
                "FROM funcs WHERE client = ?", (client,)).fetchone()
        return tuple(int(value or 0) for value in row)

    def progress_snapshot(self, client=None):
        """Public live website totals, from the same rows used by mining digests."""
        fields = ("name", "functions", "matched", "partial", "bytes", "matched_bytes", "partial_bytes")
        with self.lock:
            rows = self.db.execute(
                "SELECT client, COUNT(*), SUM(score=100), SUM(score>0 AND score<100), SUM(size), "
                "SUM(CASE WHEN score=100 THEN size ELSE 0 END), "
                "SUM(CASE WHEN score>0 AND score<100 THEN size ELSE 0 END) "
                "FROM funcs GROUP BY client").fetchall()
            functions = self.db.execute("SELECT addr,size,score,unit,source IS NOT NULL FROM funcs WHERE client=? ORDER BY addr",
                                        (client,)).fetchall() if client else None
        return {"updated": time.strftime("%Y-%m-%d %H:%M:%S UTC", time.gmtime()),
                "clients": [dict(zip(fields, [row[0], *(int(v or 0) for v in row[1:])])) for row in rows],
                "scores": {row[0]: row[2] for row in functions} if functions is not None else None,
                "functions": functions}

    def match_rate(self, client, window=86400):
        """Matches per second over the recent window (0 when idle)."""
        now = time.time()
        with self.lock:
            count = self.db.execute("SELECT COUNT(*) FROM events WHERE client = ? AND ts >= ? "
                                    "AND new = 100 AND old < 100", (client, now - window)).fetchone()[0]
        return (count or 0) / window

    def match_byte_rate(self, client, window=86400):
        """Target bytes newly matched per second over the recent window."""
        now = time.time()
        with self.lock:
            size = self.db.execute(
                "SELECT SUM(f.size) FROM funcs f JOIN "
                "(SELECT DISTINCT addr FROM events WHERE client=? AND ts>=? "
                "AND new=100 AND old<100) e ON e.addr=f.addr WHERE f.client=?",
                (client, now - window, client)).fetchone()[0]
        return (size or 0) / window

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

    def families(self):
        with self.lock:
            rows = self.db.execute("SELECT client, addr, family FROM funcs WHERE family IS NOT NULL AND family != ''").fetchall()
        out = {}
        for c, a, f in rows:
            out.setdefault(c, {})[a] = f
        return out

    def status(self):
        now = time.time()
        with self.lock:
            per = self.db.execute("SELECT client, COUNT(*), SUM(score = 100), SUM(score > 0 AND score < 100) "
                                  "FROM funcs GROUP BY client").fetchall()
            workers = self.db.execute("SELECT user, mode, last_seen FROM workers WHERE last_seen > ?", (now - 900,)).fetchall()
        return {"clients": [{"client": c, "functions": n, "matched": m or 0, "partial": p or 0} for c, n, m, p in per],
                "workers": [{"user": u, "mode": m, "seen_ago": int(now - t)} for u, m, t in workers]}

    def best(self, client, addr):
        with self.lock:
            row = self.db.execute("SELECT score, source, user FROM funcs WHERE client = ? AND addr = ?",
                                  (client, addr)).fetchone()
        return {"score": row[0], "source": row[1], "user": row[2]} if row else None

    def function_info(self, client, addr):
        with self.lock:
            row = self.db.execute("SELECT size, unit, family FROM funcs WHERE client = ? AND addr = ?", (client, addr)).fetchone()
        return {"client": client, "addr": addr, "size": row[0], "unit": row[1], "family": row[2]} if row else None

    def register_family(self, client, addr, family):
        with self.lock:
            self.db.execute("UPDATE funcs SET family = ? WHERE client = ? AND addr = ?",
                            (family, client, addr))
            self.db.commit()
        return True

    def register_families(self, rows):
        with self.lock:
            self.db.executemany("UPDATE funcs SET family = ? WHERE client = ? AND addr = ?",
                                [(str(r.get("family", "")), str(r.get("client", "")),
                                  str(r.get("addr", ""))) for r in rows if r.get("family")])
            self.db.commit()
        return len(rows)

    def examples(self, client, n=3, unit=None, shape=None, strict=False, family=None):
        """Small matched sources, used as few-shot examples for AI workers."""
        with self.lock:
            unit_sql = " AND unit = ?" if unit else ""
            shape_sql = " AND shape = ?" if shape else ""
            family_sql = " AND family = ?" if family else ""
            args = ((client, unit, shape, family, n) if unit and shape and family else
                    (client, unit, family, n) if unit and family else
                    (client, shape, family, n) if shape and family else
                    (client, family, n) if family else
                    (client, unit, shape, n) if unit and shape else
                    (client, unit, n) if unit else
                    (client, shape, n) if shape else (client, n))
            rows = self.db.execute("SELECT addr, source FROM funcs WHERE client = ? AND score = 100 "
                                   "AND source IS NOT NULL AND LENGTH(source) <= 6000 "
                                   + unit_sql + shape_sql + family_sql + " ORDER BY RANDOM() LIMIT ?", args).fetchall()
            if (unit or shape or family) and not rows and not strict:
                rows = self.db.execute("SELECT addr, source FROM funcs WHERE client = ? AND score = 100 "
                                       "AND source IS NOT NULL AND LENGTH(source) <= 6000 "
                                       " ORDER BY RANDOM() LIMIT ?",
                                       (client, n)).fetchall()
        return [{"addr": a, "source": s} for a, s in rows]

    def function_history(self, identifier=None, query="", status="", sort="recent", limit=300):
        """Stored sources include manual, library, CLI and agent gains, even without local activity."""
        where, args = "source IS NOT NULL", []
        if identifier:
            prefix, client, addr = identifier.split(":", 2)
            if prefix != "server":
                return None
            where += " AND client=? AND addr=?"
            args += [client, addr]
        else:
            where += " AND lower(coalesce(unit,'') || ' ' || client || ' ' || addr || ' ' || coalesce(user,'')) LIKE ?"
            args += ['%' + query.lower() + '%']
            if status:
                where += " AND (CASE WHEN score=100 THEN 'matched' WHEN score>0 THEN 'improved' ELSE 'failed' END)=?"
                args += [status]
        order = {"score": "score DESC", "gain": "updated DESC", "unit": "unit", "addr": "addr"}.get(sort, "updated DESC")
        with self.lock:
            rows = self.db.execute("SELECT client,addr,unit,score,user,updated" + (",source" if identifier else "") +
                " FROM funcs WHERE " + where + " ORDER BY " + order + " LIMIT ?", (*args, limit)).fetchall()
        results = [dict(id="server:" + row[0] + ":" + row[1], client=row[0], addr=row[1], unit=row[2],
            score=row[3], best_score=row[3], base_score=None, model=row[4] or "", origin="server",
            started=row[5] or 0, ended=row[5] or 0,
            status="matched" if row[3] == 100 else "improved" if row[3] > 0 else "failed") for row in rows]
        if identifier:
            if not results:
                return None
            return dict(results[0], before="", after=rows[0][6], timeline=[], commands=[], rounds=[])
        return results

    def source_page(self, client, after="", limit=1000):
        """Bound source transfers so concurrent agents do not decompress the entire corpus."""
        with self.lock:
            rows = self.db.execute("SELECT addr, score, user, source FROM funcs WHERE client = ? "
                                   "AND addr > ? AND score >= 1 AND source IS NOT NULL ORDER BY addr LIMIT ?",
                                   (client, after, max(1, min(limit, 1000)))).fetchall()
        return [{"addr": a, "score": score, "user": user, "source": source} for a, score, user, source in rows]

    def sources(self, client, min_score=1, scores_only=False):
        """Every stored source for a client (for `roc pull`); scores_only leaves out the source text."""
        if scores_only:
            with self.lock:
                rows = self.db.execute("SELECT addr, score FROM funcs WHERE client = ? AND score >= ? "
                                       "AND source IS NOT NULL ORDER BY addr", (client, min_score)).fetchall()
            return [{"addr": a, "score": s} for a, s in rows]
        with self.lock:
            rows = self.db.execute("SELECT addr, score, user, source FROM funcs WHERE client = ? AND score >= ? "
                                   "AND source IS NOT NULL ORDER BY addr", (client, min_score)).fetchall()
        return [{"addr": a, "score": s, "user": u, "source": src} for a, s, u, src in rows]


def export(store):
    """Everything the website needs from the database."""
    scores = store.scores()
    return {"scores": scores, "data": store.data(), "families": store.families(), "leaderboard": store.leaderboard(),
            "leaderboards": {c: store.leaderboard(c)[:20] for c in scores}}


def make_handler(store, token, can_verify, mine_log=None, server_mine_log=None, integration=None):
    if integration is None and getattr(store, "db", None) is not None:
        from roc.integration import Promotions
        integration = Promotions(store)
    from roc import libs
    recipe_versions = libs.recipe_versions()
    lease_slots = threading.BoundedSemaphore(8)
    verification_slots = threading.BoundedSemaphore(3)
    class Handler(BaseHTTPRequestHandler):
        recipes = recipe_versions
        # Api keeps one HTTP connection per worker. HTTP/1.0 closes it after
        # every response, rapidly exhausting Windows ephemeral ports locally.
        protocol_version = "HTTP/1.1"

        def log_message(self, fmt, *args):
            pass

        def send(self, code, obj):
            """Write a response. A worker that gave up and closed the socket (timeout,
            restart, laptop sleep) is normal, not an error: the request was handled and
            there is simply nobody left to tell. Failing here raised
            ConnectionAbortedError out of the handler thread and printed a traceback for
            every abandoned request."""
            body = json.dumps(obj).encode()
            gzipped = len(body) > 4096 and "gzip" in self.headers.get("Accept-Encoding", "")
            if gzipped:
                body = gzip.compress(body, 5)  # source listings are ~8x smaller; the link is the slow part
            try:
                self.send_response(code)
                self.send_header("Content-Type", "application/json")
                if gzipped:
                    self.send_header("Content-Encoding", "gzip")
                self.send_header("Content-Length", str(len(body)))
                self.send_header("Access-Control-Allow-Origin", "*")
                self.end_headers()
                self.wfile.write(body)
            except (ConnectionAbortedError, ConnectionResetError, BrokenPipeError):
                self.close_connection = True

        def do_GET(self):
            url = urlparse(self.path)
            q = {k: v[0] for k, v in parse_qs(url.query).items()}
            if url.path in ("/v1/integration", "/v1/integration/base", "/v1/integration/evidence"):
                if integration is None:
                    return self.send(503, {"error": "Native integration unavailable"})
                try:
                    if url.path.endswith("/evidence"):
                        return self.send(200, integration.evidence())
                    return self.send(200, integration.baseline() if url.path.endswith("/base")
                                     else integration.status(q.get("id"), q.get("request"), q.get("user"), q.get("claims") == "1"))
                except (ValueError, OSError) as error:
                    return self.send(503, {"error": str(error)})
            if url.path == "/v1/info":
                reg = clients.load()
                return self.send(200, {"clients": {n: {k: e.get(k) for k in ("sha256", "compiler", "compiler_build", "flags")}
                                                   for n, e in reg.items()}, "verify": sorted(can_verify),
                                       "recipe_versions": recipe_versions,
                                       "native_integration": {"version": 3, "enabled": integration is not None, "invitation_required": False,
                                                              "claim_inventory": True, "explicit_park": True, "submission_recovery": True,
                                                              "max_batch": 16}})
            if url.path == "/v1/status":
                status = store.status()
                progress = integration.root / "work/integration/progress-native.json" if integration else None
                linked = set(json.loads(progress.read_text())["addresses"]) if progress and progress.exists() else None
                for client in status["clients"]:
                    supported = integration is not None and client["client"] == integration_protocol.CLIENT
                    count = len(linked) if supported and linked is not None else None
                    client.update(native_supported=supported, integrated=count,
                                  integration_percent=100 * count / client["functions"]
                                  if count is not None and client["functions"] else None)
                return self.send(200, status)
            if url.path == "/v1/progress":
                return self.send(200, store.progress_snapshot(q.get("client")))
            if url.path == "/v1/function-history":
                try:
                    return self.send(200, store.function_history(q.get("id"), q.get("query", ""), q.get("status", ""),
                        q.get("sort", "recent"), min(10000, max(1, int(q.get("limit", 300))))))
                except (ValueError, TypeError) as error:
                    return self.send(400, {"error": str(error)})
            if url.path == "/v1/agent-memory":
                try:
                    return self.send(200, store.agent_memory(max(0, int(q.get("after", 0))),
                                                            min(500, max(1, int(q.get("limit", 500))))))
                except ValueError as error:
                    return self.send(400, {"error": str(error)})
            if url.path == "/v1/leaderboard":
                return self.send(200, store.leaderboard())
            if url.path == "/v1/daily-stats":
                try:
                    return self.send(200, store.daily_stats(q.get("date")))
                except ValueError as error:
                    return self.send(400, {"error": str(error)})
            if url.path == "/v1/export":
                return self.send(200, export(store))
            if url.path == "/v1/source":
                best = store.best(q.get("client", ""), q.get("addr", ""))
                return self.send(200 if best else 404, best or {"error": "unknown function"})
            if url.path == "/v1/source-page":
                return self.send(200, store.source_page(q.get("client", ""), q.get("after", ""),
                                                       int(q.get("limit", 1000))))
            if url.path == "/v1/sources":
                return self.send(200, store.sources(q.get("client", ""), int(q.get("min_score", 1)),
                                                    q.get("scores") == "1"))
            if url.path == "/v1/functions":
                try:
                    return self.send(200, store.functions(
                        q.get("client", ""),
                        int(q.get("min_score", 0)),
                        int(q.get("max_score", 99)),
                        int(q.get("limit", 500)),
                        order=q.get("order", "score")))
                except (ValueError, TypeError) as error:
                    return self.send(400, {"error": str(error)})
            if url.path == "/v1/work-candidates":
                try:
                    return self.send(200, store.work_candidates(
                        q.get("client", ""),
                        limit=int(q.get("limit", 20)),
                        min_score=int(q.get("min_score", 0)),
                        max_score=int(q.get("max_score", 99)),
                        profile=q.get("profile", "quick"),
                        max_size=(int(q["max_size"]) if q.get("max_size") else None),
                        include_claimed=q.get("include_claimed", "1") == "1"))
                except (ValueError, TypeError) as error:
                    return self.send(400, {"error": str(error)})
            if url.path == "/v1/examples":
                return self.send(200, store.examples(q.get("client", ""), min(int(q.get("n", 3)), 10),
                                                     q.get("unit"), q.get("shape"),
                                                     q.get("strict") == "1", q.get("family")))
            if url.path == "/v1/family":
                return self.send(200, store.register_family(q.get("client", ""), q.get("addr", ""),
                                                             q.get("family", "")))
            self.send(404, {"error": "unknown endpoint"})

        def do_POST(self):
            path = urlparse(self.path).path
            native = path.startswith("/v1/integration/")
            if (not native
                    and token and self.headers.get("X-Roc-Token") != token):
                return self.send(403, {"error": "wrong or missing server password (token)"})
            try:
                length = int(self.headers.get("Content-Length") or 0)
                if not 0 <= length <= (integration_protocol.MAX_REQUEST_BYTES if native else 1 << 20):
                    self.close_connection = True
                    return self.send(413, {"error": "too large"})
                body = json.loads(self.rfile.read(length) or b"{}")
            except (ValueError, json.JSONDecodeError):
                return self.send(400, {"error": "bad json"})
            user = str(body.get("user", ""))
            if path.startswith("/v1/integration/"):
                if integration is None:
                    return self.send(503, {"error": "Native integration unavailable"})
                if not USER_RE.fullmatch(user):
                    return self.send(400, {"error": "Need a valid contributor username"})
                try:
                    if path.endswith("/claim"):
                        if integration.worker_error:
                            return self.send(503, {"error": "Native verifier unavailable: " + integration.worker_error})
                        result = integration.claim(user, str(body.get("worker", "")),
                                                   body.get("count", 1), body.get("unit"),
                                                   body.get("targets"), body.get("compact", False))
                    elif path.endswith("/submit"):
                        result = integration.submit(user, body)
                    elif path.endswith("/force-queue"):
                        result = integration.force_queue(user, body.get("id"))
                    elif path.rsplit("/", 1)[-1] in ("renew", "release", "park", "unpark"):
                        identifiers = body.get("claims", [str(body.get("claim", ""))])
                        result = integration.renew_many(user, identifiers, reason=body.get("reason"), action=path.rsplit("/", 1)[-1])
                    else:
                        return self.send(404, {"error": "Unknown integration action"})
                    return self.send(200, result)
                except (ValueError, TypeError, OSError) as error:
                    return self.send(400, {"error": str(error)})
            if path == "/v1/family":
                return self.send(200, store.register_family(str(body.get("client", "")),
                                                             str(body.get("addr", "")),
                                                             str(body.get("family", ""))))
            if path == "/v1/claim":
                if not USER_RE.match(user):
                    return self.send(400, {"error": "username must be 2-32 letters, digits, _ . -"})
                client, addr = str(body.get("client", "")), str(body.get("addr", "")).lower()
                if not re.fullmatch(r"[0-9a-f]{8}", addr):
                    return self.send(400, {"error": "address must be 8 hex digits"})
                worker = str(body.get("worker", "")).strip()[:64] or user
                result = store.claim(client, addr, worker)
                if not result:
                    return self.send(409, {"error": "already claimed by another worker"})
                return self.send(200, result)
            if path == "/v1/families":
                rows = body.get("rows", [])
                if not isinstance(rows, list) or len(rows) > 5000:
                    return self.send(400, {"error": "rows must be list <= 5000"})
                return self.send(200, {"registered": store.register_families(rows)})
            if path in ("/v1/lease", "/v1/submit", "/v1/submit-batch", "/v1/agent-memory", "/v1/units") and not USER_RE.match(user):
                return self.send(400, {"error": "username must be 2-32 letters, digits, _ . -"})
            if path in ("/v1/submit", "/v1/submit-batch") and str(body.get("model", "")).strip().lower() in ("function", "family", "unit", "native"):
                return self.send(400, {"error": "model must identify the actual AI model or human, not a lease mode"})
            if path in ("/v1/submit", "/v1/submit-batch") and any(
                    recipe_versions.get(name) != version for name, version in body.get("recipe_versions", {}).items()):
                return self.send(409, {"error": "Verifier recipe mismatch; update/restart verifier"})
            if path == "/v1/units":
                from roc import libs
                try:
                    return self.send(200, {"added": libs.accept_units(body.get("units"))})
                except (ValueError, TypeError) as error:
                    return self.send(400, {"error": str(error)})
            if path == "/v1/agent-memory":
                try:
                    return self.send(200, store.remember(user, body.get("records")))
                except (ValueError, TypeError) as error:
                    return self.send(400, {"error": str(error)})
            if path == "/v1/lease":
                have = [c for c in body.get("clients", []) if isinstance(c, str)]
                if not have:
                    return self.send(400, {"error": "no clients"})
                if not lease_slots.acquire(blocking=False):
                    return self.send(503, {"error": "lease queue busy; retry shortly"})
                try:
                    job = store.lease(user, str(body.get("worker", ""))[:64], have,
                                  str(body.get("mode", ""))[:16], int(body.get("max_size", 256)),
                                  str(body.get("model", ""))[:120] or None,
                                  body.get("targets"),
                                  order=str(body.get("order", "random"))[:16],
                                  family=(str(body["family"])[:64] if body.get("family") else None),
                                  unit=(str(body["unit"])[:160] if body.get("unit") else None),
                                  min_score=(int(body["min_score"]) if body.get("min_score") is not None else None),
                                  max_score=(int(body["max_score"]) if body.get("max_score") is not None else None),
                                  library=(str(body["library"])[:64] if body.get("library") else None))
                finally:
                    lease_slots.release()
                return self.send(200, {"job": job})
            if path == "/v1/heartbeat":
                return self.send(200, {"ok": store.heartbeat(str(body.get("lease", "")))})
            if path == "/v1/release":
                return self.send(200, store.release(str(body.get("lease", "")), body.get("cooldown", 0),
                                                    worker=str(body.get("worker", "")) or None,
                                                    client=str(body.get("client", "")) or None,
                                                    addr=(str(body.get("addr", "")).lower() or None)))
            if path == "/v1/submit":
                client, addr = str(body.get("client", "")), str(body.get("addr", ""))
                source, claimed = str(body.get("source", "")), int(body.get("score", 0))
                if not source.strip() or len(source) > 200_000:
                    return self.send(400, {"error": "empty or huge source"})
                score, verified, spans = claimed, False, None
                previous = (store.best(client, addr) or {}).get("score", 0)
                if client in can_verify:
                    if not verification_slots.acquire(blocking=False):
                        return self.send(503, {"error": "verification queue busy; retry shortly"})
                    try:
                        try:
                            score, _, _, spans = match.check_text(client, addr, source)
                            verified = True
                        except match.CompileError as error:
                            return self.send(400, {"error": "does not compile here: %s" % str(error)[:500]})
                        except SystemExit as error:
                            return self.send(400, {"error": str(error)})
                    finally:
                        verification_slots.release()
                else:
                    try:
                        match.reject_asm(source)
                    except match.CompileError as error:
                        return self.send(400, {"error": str(error)})
                try:
                    stored, improved = store.submit(client, addr, user, max(0, min(100, score)), source, spans,
                                                    str(body.get("lease", "")) or None,
                                                    model=body.get("model", ""), verified=verified)
                except ValueError as error:
                    return self.send(400, {"error": str(error)})
                if body.get("lease"):
                    store.release(str(body["lease"]))
                if improved:
                    feed = mine_log
                    if feed is not None:
                        feed.submit(store.function_info(client, addr), user,
                                        str(body.get("worker", ""))[:64],
                                        str(body.get("model", ""))[:120] or "Unknown model",
                                        stored, stored - previous)
                return self.send(200, {"score": score, "stored": stored, "improved": improved, "verified": verified})
            if path == "/v1/submit-batch":
                client, source = str(body.get("client", "")), str(body.get("source", ""))
                addrs = body.get("addrs", [])
                if (client not in can_verify or not source.strip() or len(source) > 200_000 or
                        not isinstance(addrs, list) or not 1 <= len(addrs) <= 1000 or
                        not all(isinstance(addr, str) and re.fullmatch(r"[0-9a-fA-F]{8}", addr) for addr in addrs)):
                    return self.send(400, {"error": "need verifiable client, source, and 1-1000 addresses"})
                if not verification_slots.acquire(blocking=False):
                    return self.send(503, {"error": "verification queue busy; retry shortly"})
                try:
                    try:
                        checked = check_many_text(client, addrs, source)
                    except match.CompileError as error:
                        return self.send(400, {"error": "does not compile here: %s" % str(error)[:500]})
                    except SystemExit as error:
                        return self.send(400, {"error": str(error)})
                finally:
                    verification_slots.release()
                results = []
                for addr, score, spans in checked:
                    previous = (store.best(client, addr) or {}).get("score", 0)
                    try:
                        stored, improved = store.submit(client, addr, user, score, source, spans,
                                                        model=body.get("model", ""), verified=True)
                    except ValueError as error:
                        return self.send(400, {"error": str(error)})
                    feed = mine_log
                    if improved and feed is not None:
                        feed.submit(store.function_info(client, addr), user,
                                        str(body.get("worker", ""))[:64],
                                        str(body.get("model", ""))[:120] or "Unknown model", stored, stored - previous)
                    results.append({"addr": addr, "score": score, "stored": stored, "improved": improved})
                return self.send(200, {"verified": True, "results": results})
            self.send(404, {"error": "unknown endpoint"})

    return Handler


def import_auto_matches(store, name, found, log=print):
    """Re-verify sources before crediting automatic or cached local matches.

    A single stale addr must never stop the server (startup crash loop).
    Returns (imported, skipped).
    """
    imported = skipped = 0
    for addr, src in found.items():
        current = store.best(name, addr)
        if not current:
            skipped += 1
            continue
        if current["score"] == 100:
            continue
        try:
            score, _, _, spans = match.check_text(name, addr, src)
            if score != 100:
                skipped += 1
                log("Skipped stale auto-match %s %s: reverified %d%%" % (name, addr, score))
                continue
            _, improved = store.submit(name, addr, "auto", 100, src, spans, verified=True)
            imported += int(improved)
        except (ValueError, match.CompileError) as error:
            skipped += 1
            log("Skipped unverified auto-match %s %s: %s" % (name, addr, str(error)[-300:]))
    if found:
        log("Imported %d verified functions for %s (credited to 'auto'%s)" % (
            imported, name,
            "; skipped %d dropped or unverified" % skipped if skipped else ""))
    return imported, skipped


def import_startup_matches(store, can_verify, log=print):
    """Import local automatic/library matches without delaying server startup."""
    from roc import matchers
    for name in sorted(can_verify):
        if clients.load().get(name, {}).get("donor"):
            continue
        done = {a for a, s in store.scores().get(name, {}).items() if s == 100}
        found = matchers.solve(name, skip=done, log=lambda *a: None)
        import_auto_matches(store, name, found, log)
        scores_file = ROOT / "work" / name / "scores.json"
        local = json.loads(scores_file.read_text()) if scores_file.exists() else {}
        done = {a for a, s in store.scores().get(name, {}).items() if s == 100}
        imported = 0
        for addr, score in local.items():
            path = ROOT / "src" / name / ("%s.cpp" % addr)
            if score == 100 and addr not in done and path.exists():
                text = path.read_text(errors="replace")
                if "// roc-lib:" in text or "// standard library" in text:
                    count, _ = import_auto_matches(store, name, {addr: text}, log)
                    imported += count
        if imported:
            log("Imported %d library matches for %s (credited to 'auto')" % (imported, name))


def serve(host="0.0.0.0", port=8765, db=None, token=None, lease_seconds=900,
          discord_webhook=None, log=print):
    from roc.reports import MineLog, player_mines_webhook
    discord_webhook = discord_webhook or player_mines_webhook()
    db = db or str(ROOT / "work" / "server.db")
    Path(db).parent.mkdir(parents=True, exist_ok=True)
    store = Store(db, lease_seconds)
    for name, entry in clients.load().items():
        if entry.get("donor"):  # donor binaries feed matching/spread only, never a progress target
            continue
        added = store.seed(name)
        if added:
            log("Loaded %d functions for %s" % (added, name))
    have = setup.compilers()
    can_verify = {n for n, e in clients.load().items()
                  if e.get("compiler_build") in have and clients.status(n, e) == "ok"}
    log("Re-checking submissions for: %s" % (", ".join(sorted(can_verify)) or "none (trusting workers)"))
    if discord_webhook:
        log("Discord worker mine logs: enabled (batched digests)")
    mine_log = MineLog(discord_webhook, store) if discord_webhook else None
    server_mine_log = None
    from roc.integration import Promotions
    from roc.integration_verify import loop as integration_loop
    integration = Promotions(store)
    httpd = ThreadingHTTPServer((host, port), make_handler(store, token, can_verify,
                                                       mine_log=mine_log, server_mine_log=server_mine_log,
                                                       integration=integration))
    httpd.store = store
    threading.Thread(target=integration_loop, args=(integration, log), daemon=True).start()
    def daily_reports():
        from roc.reports import archive_days, save
        archived = False
        previous_day = None
        while True:
            try:
                if not archived:
                    archive_days(store, Path(db).parent / "reports" / "daily")
                    archived = True
                report = store.daily_stats()
                directory = Path(db).parent / "reports" / "daily"
                if previous_day and previous_day != report["date"]:
                    save(store.daily_stats(previous_day), directory)
                save(report, directory)
                previous_day = report["date"]
            except (OSError, sqlite3.Error, ValueError, RuntimeError) as error:
                log("Daily report failed: %s" % error)
            time.sleep(60)
    threading.Thread(target=daily_reports, daemon=True).start()
    log("RoConstruct server running on port %d. Workers connect with:  roc worker --server http://<this-pc>:%d"
        % (port, port))
    threading.Thread(target=import_startup_matches, args=(store, can_verify, log), daemon=True).start()
    return httpd


def start_tunnel(port, log=print):
    """Cloudflare quick tunnel: public HTTPS URL, no account, no router setup.
    ponytail: the URL changes on every restart; workers re-read it from the site.
    A named tunnel (cloudflared login) gives a fixed address if that hurts."""
    exe = setup.get_cloudflared()
    # A tunnel left over from a closed server window answers "Bad Gateway": remove it.
    if setup.WINDOWS:
        setup.powershell("Get-CimInstance Win32_Process -Filter \"Name='cloudflared.exe'\" | Where-Object "
                         "{ $_.CommandLine -match '127.0.0.1:%d' } | ForEach-Object { Stop-Process -Id $_.ProcessId -Force }"
                         % port)
    else:
        subprocess.run(["pkill", "-f", "cloudflared.*127.0.0.1:%d" % port], capture_output=True)
    proc = subprocess.Popen([exe, "tunnel", "--no-autoupdate", "--url", "http://127.0.0.1:%d" % port],
                            stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, text=True,
                            creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
    url, tail = None, deque(maxlen=6)
    for line in proc.stderr:
        tail.append(line.strip())
        m = re.search(r"https://[a-z0-9-]+\.trycloudflare\.com", line)
        if m:
            url = m.group(0)
            break
    if not url:
        output = "\n  ".join(line for line in tail if line) or "(none)"
        raise SystemExit("cloudflared exited without a tunnel URL (exit %s). Its last output:\n  %s"
                         % (proc.wait(), output))
    threading.Thread(target=lambda: deque(proc.stderr, maxlen=0), daemon=True).start()  # keep pipe drained
    log("Public HTTPS address: %s" % url)
    return url, proc


def publish_once(store, public_url, log=print, findings_only=False):
    """Rebuild docs/ from the live database and push it, if anything changed."""
    lock = ROOT / "work" / "publish.lock"
    lock.parent.mkdir(parents=True, exist_ok=True)
    handle = lock.open("a+b")
    if handle.tell() == 0:
        handle.write(b"\0")
        handle.flush()
    handle.seek(0)
    try:
        if os.name == "nt":
            import msvcrt
            msvcrt.locking(handle.fileno(), msvcrt.LK_NBLCK, 1)
        else:
            import fcntl
            fcntl.flock(handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
    except OSError:
        handle.close()
        log("Publish already running.")
        return False
    try:
        if findings_only:
            _publish_findings_only(store, log)
        else:
            _publish_once(store, public_url, log)
        return True
    finally:
        handle.close()  # OS releases the lock even when the hosting process crashes.



def _publish_once(store, public_url, log=print):
    """Publish implementation, protected by publish_once's cross-process lock."""
    from roc import progress, setup
    setup.refresh_path()
    git_exe = setup.find_exe("git")
    if not git_exe:
        sync_findings(store)
        progress.build(public_server=public_url, remote=export(store))
        return log("git not found, so site and findings were not published. docs/ is updated locally.")
    git = lambda *a: subprocess.run([git_exe, *a], cwd=ROOT, capture_output=True, text=True)
    # Workers need the new address before the potentially slow findings export.
    address_file = ROOT / "docs" / "progress.json"
    if address_file.exists():
        snapshot = json.loads(address_file.read_text())
        if snapshot.get("server") != public_url:
            snapshot["server"] = public_url
            address_file.write_text(json.dumps(snapshot, indent=1) + "\n")
            # Pathspec commits: never sweep a maintainer's other staged changes into a push.
            for args in (("add", "docs/progress.json"),
                         ("commit", "-m", "Update server address", "--", "docs/progress.json")):
                result = git(*args)
                if result.returncode:
                    raise RuntimeError("Address publish failed: " + result.stderr.strip()[-300:])
    pushed = git("push", "origin", "HEAD")
    if pushed.returncode:
        raise RuntimeError("Address push failed: " + pushed.stderr.strip()[-300:])
    sync_findings(store)
    publish_findings(git_exe, log)
    progress.build(public_server=public_url, remote=export(store))
    try:
        from roc import rebuild
        for client_dir in sorted((ROOT / "rebuild").glob("*/modules")):
            rebuild.progress(client_dir.parent.name, notify=True, log=log)
    except Exception as error:  # reporting only; never fail a publish
        log("Rebuild progress update failed: %s" % error)
    try:
        from roc import integration_site
        integration_site.build(log=log)  # docs/integration.json: gh-pages only, like per-function data
    except Exception as error:  # reporting only; never fail a publish
        log("Integration site update failed: %s" % error)
    publish_pages(git_exe, log)
    # main keeps only the small progress files, so its history still shows progress over
    # time; per-function data lives only in the history-free gh-pages commit.
    site = ("docs/progress.json", "docs/history.json", "docs/source-links.json",
            "docs/rebuild-progress.json")
    site = tuple(path for path in site if (ROOT / path).exists())
    if not site:
        return log("No progress files to publish.")
    git("add", *site)
    if git("diff", "--cached", "--quiet", "--", *site).returncode == 0:
        return log("Progress unchanged.")
    git("commit", "-m", "Update progress", "--", *site)
    push = git("push", "origin", "HEAD")
    log("Progress published." if push.returncode == 0 else "Progress push failed: %s" % push.stderr.strip()[-300:])



def publish_pages(git_exe, log=print):
    """Overwrite the gh-pages branch with the whole website (docs/ minus guides) as one
    parentless commit: the hourly 20+ MB of function data never accumulates in any history."""
    index = ROOT / "work" / ("pages-index-" + uuid.uuid4().hex)
    env = dict(os.environ, GIT_INDEX_FILE=str(index))
    git = lambda *a, **kw: subprocess.run([git_exe, *a], cwd=ROOT, env=env, capture_output=True, text=True, **kw)
    docs = ROOT / "docs"
    try:
        if git("read-tree", "--empty").returncode:
            return log("Pages staging failed.")
        for path in sorted(docs.rglob("*")):
            if not path.is_file() or path.suffix == ".md" or path.name == "providers.example.json":
                continue
            relative = path.relative_to(docs).as_posix()
            blob = git("hash-object", "-w", str(path))
            if blob.returncode or git("update-index", "--add", "--cacheinfo", "100644", blob.stdout.strip(),
                                     relative).returncode:
                return log("Pages staging failed: " + relative)
        empty = git("hash-object", "-w", "--stdin", input="")  # .nojekyll: serve files as-is
        git("update-index", "--add", "--cacheinfo", "100644", empty.stdout.strip(), ".nojekyll")
        tree = git("write-tree")
        if tree.returncode:
            return log("Pages tree failed: %s" % tree.stderr.strip()[-300:])
        known = git("rev-parse", "--verify", "-q", "refs/remotes/origin/gh-pages^{tree}")
        if known.returncode == 0 and known.stdout.strip() == tree.stdout.strip():
            return log("Website unchanged.")
        commit = git("commit-tree", tree.stdout.strip(), "-m", "Website")
        if commit.returncode:
            return log("Pages commit failed: %s" % commit.stderr.strip()[-300:])
        pushed = git("push", "-f", "origin", commit.stdout.strip() + ":refs/heads/gh-pages")
        if pushed.returncode == 0:
            git("update-ref", "refs/remotes/origin/gh-pages", commit.stdout.strip())
        log("Website published." if pushed.returncode == 0 else "Website push failed: %s" % pushed.stderr.strip()[-300:])
    finally:
        index.unlink(missing_ok=True)


def sync_findings(store):
    """Save every stored source, including partials, before building the site."""
    from roc import libs
    for name in store.scores():
        # Units this server compiled from its own vendor trees must ship with the findings.
        libs.capture_source_units(row["source"] or "" for row in store.sources(name, min_score=0))
        scores_file = ROOT / "work" / name / "scores.json"
        scores = json.loads(scores_file.read_text()) if scores_file.exists() else {}
        starts = match.function_starts(name)
        for row in store.sources(name, min_score=0):
            if starts is not None and row["addr"] not in starts:
                continue  # address retired by a boundary fix
            path = ROOT / "src" / name / (row["addr"] + ".cpp")
            if path.exists() and scores.get(row["addr"], 0) > row["score"]:
                continue
            text = "// from server: %d%% by %s\n%s" % (row["score"], row["user"], row["source"])
            if path.exists() and (scores.get(row["addr"]) == row["score"] or
                                  path.read_text(errors="replace") == text):
                continue
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text)
            scores[row["addr"]] = row["score"]
        scores_file.parent.mkdir(parents=True, exist_ok=True)
        scores_file.write_text(json.dumps(scores, indent=0, sort_keys=True))
    export_agent_findings(store)
    units = ROOT / "local" / "units" / "generated-units.json"
    if units.is_file():  # shared through the findings repo; `roc pull` downloads it
        target = ROOT / "local" / "findings" / "units" / "generated-units.json"
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(units, target)


def export_agent_findings(store):
    """Only reviewed lessons are needed by findings consumers; attempts remain in the server DB/API."""
    from roc import tasks
    folder = ROOT / 'local/findings/data'
    folder.mkdir(parents=True, exist_ok=True)
    result = store.agent_memory(0)
    tasks.write_text(folder / 'lessons.json', json.dumps(result['lessons'], indent=2))



def findings_source(text, units):
    """Expand recipe-only wrappers for readers; retain directives for reproducibility."""
    from roc import libs
    directive = match.directives(text).get("lib", "")
    if not directive or re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S).strip():
        return text
    recipe, _, relative = directive.partition(" ")
    entry = libs.RECIPES.get(recipe, {})
    if not entry.get("src"):
        return text
    relative = relative.strip().replace("\\", "/")
    body = units.get(entry["src"], {}).get(relative)
    if body is None:
        folder = (libs.LIBS / entry["src"]).resolve()
        path = (folder / relative).resolve()
        if not path.is_relative_to(folder) or not path.is_file():
            return text
        body = path.read_text(errors="replace")
        units.setdefault(entry["src"], {})[relative] = body
    # Address-specific assembly comments duplicate the same unit thousands of times.
    # The filename identifies the target; keep its score and reproducible build settings.
    header = "\n".join(line for line in text.splitlines()
                       if line.startswith(("// from server:", "// roc-")))
    return header + "\n\n// Candidate translation unit (score above; library headers required).\n" + body


def publish_findings(git_exe, log=print):
    from roc.findings_publish import prepare_native
    prepare_native(ROOT, log)
    from roc.findings_transport import publish
    messages = []
    def report(message):
        messages.append(message)
        log(message)
    publish(ROOT, git_exe, report)
    failures = [message for message in messages if 'failed' in message.lower() or 'unavailable' in message.lower()]
    if failures:
        raise RuntimeError(failures[-1])



def publish_loop(store, public_url, every, log=print, tunnel=None, port=None, publish=True, primary=None):
    next_publish = 0
    next_probe = 0
    active_url = public_url
    failures = 0
    while True:
        if tunnel is not None and tunnel.poll() is not None:
            if not failures:
                log("Tunnel stopped; restarting public connection.")
            try:
                public_url, tunnel = start_tunnel(port, log)
                failures = 0
                next_publish = 0
                next_probe = 0
            except (OSError, SystemExit) as error:
                failures += 1
                wait = min(5 * 2 ** (failures - 1), 300)
                if "429" in str(error):
                    wait = 900  # Cloudflare rate-limited quick tunnels: asking more often only extends the ban  # back off 5 s .. 5 min, log first failure then every 10th
                if failures == 1 or failures % 10 == 0:
                    log("Tunnel restart failed (%d so far): %s. Retrying every %d s." % (failures, error, wait))
                time.sleep(wait)
                continue
        if primary and time.monotonic() >= next_probe:
            from roc.worker import Api, ApiFailure
            probe = Api(primary)
            try:
                probe.call("/v1/info", timeout=5)
                selected = primary
            except ApiFailure:
                selected = public_url
            finally:
                probe.close()
            if selected != active_url:
                log("Public connection switched to %s" % selected)
                active_url = selected
                next_publish = 0
            next_probe = time.monotonic() + 30
        elif not primary:
            active_url = public_url
        try:
            if time.monotonic() >= next_publish:
                published = publish_once(store, active_url, log, findings_only=not active_url) if publish else True
                next_publish = time.monotonic() + (30 if published is False else every)
        except Exception as error:  # keep serving even if a publish fails
            log("Publish failed: %s" % error)
            next_publish = time.monotonic() + min(60, every)
        time.sleep(5 if tunnel is not None or primary else min(30, every))



def _publish_findings_only(store, log=print):
    """Findings publication does not require a public worker URL or an origin push."""
    git_exe = setup.find_exe('git')
    if not git_exe:
        raise RuntimeError('git not found; findings were not published')
    sync_findings(store)
    publish_findings(git_exe, log)



def run_publisher(every=3600, parent_pid=None, log=print):
    """Server-owned publisher process. Its lease keeps older API hosts from publishing stale layouts."""
    from roc import libs, progress, integration_site
    from roc.integration import atomic_json
    store = Store.__new__(Store)
    store.lock = threading.Lock()
    store.db = sqlite3.connect((ROOT / 'work/server.db').as_uri() + '?mode=ro', uri=True)
    store.db.create_function('roc_library', 1, libs.library_of, deterministic=True)
    path = ROOT / 'work/publish.lock'
    handle = path.open('a+b')
    if handle.tell() == 0:
        handle.write(b'\0')
        handle.flush()
    handle.seek(0)
    state_path = ROOT / 'work/server-publisher.json'
    state = {'pid': os.getpid(), 'parent_pid': parent_pid, 'interval_seconds': every, 'state': 'starting'}
    next_publish = 0
    locked = False
    try:
        while parent_pid is None or _publisher_parent_running(parent_pid):
            if not locked:
                try:
                    if os.name == 'nt':
                        import msvcrt
                        msvcrt.locking(handle.fileno(), msvcrt.LK_NBLCK, 1)
                    else:
                        import fcntl
                        fcntl.flock(handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
                    locked = True
                except OSError:
                    time.sleep(5)
                    continue
            if time.monotonic() >= next_publish:
                state.update(state='publishing', error=None)
                atomic_json(state_path, state)
                try:
                    _publish_findings_only(store, log)
                    existing = ROOT / 'docs/progress.json'
                    public = json.loads(existing.read_text()).get('server') if existing.exists() else None
                    progress.build(public_server=public, remote=export(store))
                    integration_site.build(root=ROOT, log=log)
                    messages = []
                    publish_pages(setup.find_exe('git'), messages.append)
                    for message in messages:
                        log(message)
                        if 'failed' in message.lower():
                            raise RuntimeError(message)
                    revision = subprocess.run(['git', 'ls-remote', 'findings', 'refs/heads/main'],
                        cwd=ROOT, capture_output=True, text=True, timeout=60, check=True).stdout.split()[0]
                    state.update(state='idle', last_published=time.time(), findings_revision=revision)
                    next_publish = time.monotonic() + every
                    log('Server publisher complete; next run in %d seconds.' % every)
                except Exception as error:
                    state.update(state='retrying', error=str(error)[:500])
                    next_publish = time.monotonic() + min(60, every)
                    log('Server publisher will retry: ' + str(error)[:500])
                atomic_json(state_path, state)
            time.sleep(5)
    finally:
        handle.close()
        store.db.close()
        state['state'] = 'stopped'
        atomic_json(state_path, state)



def _publisher_parent_running(pid):
    if os.name != 'nt':
        try:
            os.kill(pid, 0)
            return True
        except ProcessLookupError:
            return False
    import ctypes
    from ctypes import wintypes
    api = ctypes.WinDLL('kernel32', use_last_error=True)
    api.OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
    api.OpenProcess.restype = wintypes.HANDLE
    api.GetExitCodeProcess.argtypes = [wintypes.HANDLE, ctypes.POINTER(wintypes.DWORD)]
    api.CloseHandle.argtypes = [wintypes.HANDLE]
    handle = api.OpenProcess(0x1000, False, pid)
    if not handle:
        return False
    try:
        code = wintypes.DWORD()
        return bool(api.GetExitCodeProcess(handle, ctypes.byref(code))) and code.value == 259
    finally:
        api.CloseHandle(handle)

