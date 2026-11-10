"""Local work/ claim and cooldown state.

The group server owns the actual claim token.  This module only remembers what
this checkout was told, so a crash or restart cannot silently lose a token and
so ``roc work``/``roc release`` can skip a target it just parked.  SQLite keeps
read-modify-write atomic across separate CLI processes.

Nothing here claims work on its own.  Network failures leave the record in place
for a later retry; an expired token is reported, never reused as ownership.
"""
import hashlib
import json
import sqlite3
import time
from pathlib import Path

from roc import match

SCHEMA = """
CREATE TABLE IF NOT EXISTS claims(
  client TEXT NOT NULL, addr TEXT NOT NULL, lease TEXT NOT NULL, worker TEXT,
  expires REAL DEFAULT 0, score INT DEFAULT 0, source_hash TEXT, updated REAL,
  PRIMARY KEY(client, addr));
CREATE TABLE IF NOT EXISTS cooldowns(
  client TEXT NOT NULL, addr TEXT NOT NULL, evidence TEXT NOT NULL, until REAL NOT NULL,
  reason TEXT, updated REAL, PRIMARY KEY(client, addr, evidence));
CREATE INDEX IF NOT EXISTS cooldowns_until ON cooldowns(until);
"""


def state_dir(root=None):
    return Path(root or match.ROOT) / "work" / "state"


def db_path(root=None):
    return state_dir(root) / "workqueue.db"


def _connect(root=None):
    folder = state_dir(root)
    folder.mkdir(parents=True, exist_ok=True)
    db = sqlite3.connect(str(db_path(root)), timeout=15)
    db.executescript(SCHEMA)
    return db


def now():
    return time.time()


def normalized(addr):
    return str(addr or "").lower().replace("0x", "").zfill(8)


def evidence_key(row=None, source=None, **extra):
    """Stable key for "the same failing evidence", not just the same address."""
    if source:
        return hashlib.sha256(source.encode("utf-8", "replace")).hexdigest()[:24]
    payload = {"address": normalized((row or {}).get("addr", "") if row else ""),
               "score": (row or {}).get("score") if row else None,
               "size": (row or {}).get("size") if row else None,
               "attempts": (row or {}).get("attempts") if row else None}
    payload.update(extra)
    return hashlib.sha256(json.dumps(payload, sort_keys=True).encode()).hexdigest()[:24]


def save_claim(client, addr, lease, worker=None, expires=None, score=0, source_hash=None, root=None):
    if not lease:
        raise ValueError("claim needs a lease token")
    addr = normalized(addr)
    expires = float(expires if expires is not None else now() + 2 * 3600)
    with _connect(root) as db:
        db.execute("INSERT OR REPLACE INTO claims"
                   "(client,addr,lease,worker,expires,score,source_hash,updated) VALUES(?,?,?,?,?,?,?,?)",
                   (client, addr, str(lease), worker, expires, int(score or 0), source_hash, now()))
    return {"client": client, "addr": addr, "lease": str(lease), "worker": worker,
            "expires": expires, "score": int(score or 0), "source_hash": source_hash}


def _row(row):
    return {"client": row[0], "addr": row[1], "lease": row[2], "worker": row[3],
            "expires": row[4], "score": row[5], "source_hash": row[6], "updated": row[7],
            "expired": bool(row[4] and row[4] < now())}


def load_claim(client, addr, root=None, include_expired=False):
    addr = normalized(addr)
    with _connect(root) as db:
        row = db.execute("SELECT client,addr,lease,worker,expires,score,source_hash,updated "
                         "FROM claims WHERE client=? AND addr=?", (client, addr)).fetchone()
    if not row:
        return None
    claim = _row(row)
    if claim["expired"] and not include_expired:
        return None
    return claim


def claims(client=None, root=None, include_expired=False):
    with _connect(root) as db:
        if client:
            rows = db.execute("SELECT client,addr,lease,worker,expires,score,source_hash,updated "
                              "FROM claims WHERE client=? ORDER BY updated DESC", (client,)).fetchall()
        else:
            rows = db.execute("SELECT client,addr,lease,worker,expires,score,source_hash,updated "
                              "FROM claims ORDER BY updated DESC").fetchall()
    out = [_row(row) for row in rows]
    return out if include_expired else [row for row in out if not row["expired"]]


def latest_claim(client=None, root=None, include_expired=False):
    rows = claims(client, root, include_expired)
    return rows[0] if rows else None


def clear_claim(client, addr, lease=None, root=None):
    """Remove only the token this checkout owns.  A stale/foreign token never
    deletes a newer claim for the same address."""
    addr = normalized(addr)
    with _connect(root) as db:
        if lease:
            changed = db.execute("DELETE FROM claims WHERE client=? AND addr=? AND lease=?",
                                 (client, addr, str(lease))).rowcount
        else:
            changed = db.execute("DELETE FROM claims WHERE client=? AND addr=?", (client, addr)).rowcount
    return bool(changed)


def add_cooldown(client, addr, evidence, seconds, reason="", root=None):
    addr = normalized(addr)
    until = now() + max(0, int(seconds or 0))
    with _connect(root) as db:
        db.execute("INSERT OR REPLACE INTO cooldowns"
                   "(client,addr,evidence,until,reason,updated) VALUES(?,?,?,?,?,?)",
                   (client, addr, str(evidence), until, str(reason or "")[:240], now()))
    return {"client": client, "addr": addr, "evidence": str(evidence),
            "until": until, "reason": reason}


def cooldown(client, addr, evidence, root=None):
    addr = normalized(addr)
    with _connect(root) as db:
        row = db.execute("SELECT until,reason FROM cooldowns WHERE client=? AND addr=? AND evidence=?",
                         (client, addr, str(evidence))).fetchone()
    if not row or row[0] <= now():
        return None
    return {"until": row[0], "seconds": round(row[0] - now(), 1), "reason": row[1]}


def switch_evidence(client, addr, evidence, root=None):
    """Drop other cooldown keys for this address once its evidence changed.

    A repaired source (different hash) is a new experiment and must not inherit
    the previous failure's cooldown; a different hypothesis under the same stale
    evidence still does."""
    addr = normalized(addr)
    with _connect(root) as db:
        db.execute("DELETE FROM cooldowns WHERE client=? AND addr=? AND evidence<>?",
                   (client, addr, str(evidence)))


def cooling(client, addr, evidence=None, root=None):
    """True when any evidence for this address is still cooling down."""
    addr = normalized(addr)
    with _connect(root) as db:
        if evidence is not None:
            row = db.execute("SELECT 1 FROM cooldowns WHERE client=? AND addr=? AND evidence=? AND until>?",
                             (client, addr, str(evidence), now())).fetchone()
        else:
            row = db.execute("SELECT 1 FROM cooldowns WHERE client=? AND addr=? AND until>?",
                             (client, addr, now())).fetchone()
    return bool(row)


def purge_expired(root=None, cooldown_grace=0):
    with _connect(root) as db:
        claims = db.execute("DELETE FROM claims WHERE expires>0 AND expires<?",
                            (now() - 0,)).rowcount
        cools = db.execute("DELETE FROM cooldowns WHERE until<?",
                           (now() - max(0, int(cooldown_grace)),)).rowcount
    return {"claims": claims, "cooldowns": cools}


def cooldowns(client=None, root=None, include_expired=False):
    """List active (or all) cooldowns, newest first, with remaining seconds."""
    with _connect(root) as db:
        if client:
            if include_expired:
                rows = db.execute(
                    "SELECT client,addr,evidence,until,reason,updated FROM cooldowns "
                    "WHERE client=? ORDER BY updated DESC", (client,)).fetchall()
            else:
                rows = db.execute(
                    "SELECT client,addr,evidence,until,reason,updated FROM cooldowns "
                    "WHERE client=? AND until>? ORDER BY updated DESC",
                    (client, now())).fetchall()
        else:
            if include_expired:
                rows = db.execute(
                    "SELECT client,addr,evidence,until,reason,updated FROM cooldowns "
                    "ORDER BY updated DESC").fetchall()
            else:
                rows = db.execute(
                    "SELECT client,addr,evidence,until,reason,updated FROM cooldowns "
                    "WHERE until>? ORDER BY updated DESC", (now(),)).fetchall()
    out = []
    for row in rows:
        until = float(row[3] or 0)
        out.append({"client": row[0], "addr": row[1], "evidence": row[2],
                    "until": until, "reason": row[4], "updated": row[5],
                    "remaining": max(0, int(until - now()))})
    return out


def snapshot(root=None):
    with _connect(root) as db:
        claims_n = db.execute("SELECT count(*) FROM claims WHERE expires=0 OR expires>=?",
                              (now(),)).fetchone()[0]
        cooldowns_n = db.execute("SELECT count(*) FROM cooldowns WHERE until>=?", (now(),)).fetchone()[0]
    return {"path": str(db_path(root)), "claims": claims_n, "cooldowns": cooldowns_n}
