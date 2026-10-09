"""Persistent per-function worker activity, isolated per worker thread."""
from contextlib import closing
import json
import sqlite3
import threading
import time
import uuid
from pathlib import Path

PATH = Path(__file__).resolve().parent.parent / "work" / "function-history.sqlite"
local = threading.local()


def connect():
    PATH.parent.mkdir(parents=True, exist_ok=True)
    db = sqlite3.connect(PATH, timeout=15)
    db.execute("CREATE TABLE IF NOT EXISTS activity (id TEXT PRIMARY KEY, updated REAL, data TEXT)")
    return db


def save(force=True):
    row = getattr(local, "row", None)
    if row is None:
        return
    if not force and time.monotonic()-getattr(local, "saved_at", 0)<1:
        return
    try:
        with closing(connect()) as db:
            db.execute("INSERT OR REPLACE INTO activity VALUES (?, ?, ?)",
                       (row["id"], time.time(), json.dumps(row)))
            db.commit()
            local.saved_at = time.monotonic()
    except (OSError, sqlite3.Error):
        pass  # History must not interrupt a leased function.


def begin(job, model, session):
    local.row = dict(id=uuid.uuid4().hex, client=job["client"], addr=job["addr"],
                     unit=job.get("unit", ""), model=model, session=session,
                     started=time.time(), status="working", before=job.get("source") or "",
                     after=job.get("source") or "", base_score=job.get("score", 0),
                     score=job.get("score", 0), timeline=[], commands=[], candidates=[])
    save()


def event(message):
    row = getattr(local, "row", None)
    if row is not None:
        row["timeline"].append(dict(seconds=round(time.time()-row["started"], 2), message=str(message)))
        row["timeline"] = row["timeline"][-500:]
        save(force=False)


def command(argv, cwd, result):
    row = getattr(local, "row", None)
    if row is not None:
        row["commands"].append(dict(argv=argv, cwd=cwd, exit_code=result.returncode,
                                    output=(result.stdout + result.stderr)[-12000:]))
        row["commands"] = row["commands"][-200:]
        if getattr(local, "emit", None):
            local.emit("compile", message="Compiler finished", **row["commands"][-1])


def candidate(text, score):
    row = getattr(local, "row", None)
    if row is not None:
        row["candidates"].append(dict(score=score))
        if score > row["score"]:
            row.update(score=score, after=text)
            save()
            if getattr(local, "emit", None):
                local.emit("candidate", client=row["client"], addr=row["addr"], score=score, code=text)


def finish(score, failure, rounds):
    row = getattr(local, "row", None)
    if row is None:
        return
    row.update(ended=time.time(), best_score=row["score"], score=max(score, row["base_score"]), failure=failure,
               status="failed" if failure else "matched" if score == 100 else "improved" if score > row["base_score"] else "unchanged",
               rounds=rounds)
    save()
    local.row = None


def read(identifier=None):
    with closing(connect()) as db:
        if identifier:
            value = db.execute("SELECT data FROM activity WHERE id=?", (identifier,)).fetchone()
            return json.loads(value[0]) if value else None
        rows = [json.loads(value[0]) for value in db.execute("SELECT data FROM activity ORDER BY updated DESC LIMIT 300")]
    return [{k: v for k, v in row.items() if k not in ("before", "after", "timeline", "commands", "rounds", "candidates")} for row in rows]
