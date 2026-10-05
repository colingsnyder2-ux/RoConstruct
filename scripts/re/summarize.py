#!/usr/bin/env python3
"""Ingest Ghidra JSONL export -> SQLite, route functions to model tiers, summarize via Ollama.

Pipeline:
  1. python summarize.py ingest          # JSONL -> rbx2008m.db (idempotent, keeps summaries)
  2. python summarize.py run             # route + summarize with local models (idempotent)
  3. python summarize.py run --limit 50  # bounded batch
  4. python summarize.py stats

Tiers:
  skip    -- thunks, library-shaped, tiny/trivial decompile -> no LLM
  fast    -- small/clear functions          -> qwen2.5-coder:7b-instruct
  main    -- big/complex/net-relevant       -> qwen2.5-coder:14b
  pending -- 14b produced nothing twice      -> escalation queue (cloud, opt-in via --cloud)

Everything local by default; $0 API spend.
"""

import argparse
import glob
import json
import os
import re
import sqlite3
import sys
import time
import urllib.request

RE_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))), "work", "re")
DEFAULT_DB = os.path.join(RE_DIR, "rbx2008m.db")
DEFAULT_EXPORT = os.path.join(RE_DIR, "export")
OLLAMA = os.environ.get("OLLAMA_URL", "http://127.0.0.1:11434")

MODEL_FAST = os.environ.get("RE_MODEL_FAST", "qwen2.5-coder:7b-instruct")
MODEL_MAIN = os.environ.get("RE_MODEL_MAIN", "qwen2.5-coder:14b")

# Names that are almost certainly library/runtime -- never worth an LLM call.
LIB_NAME = re.compile(
    r"^(memcpy|memmove|memset|memcmp|strlen|strcmp|strncmp|strcpy|strncpy|strcat|"
    r"_?memcpy|_?memset|_?strlen|_?strcmp|_?strcpy|"
    r"operator.*|std::.*|__.*|_Cxx.*|___.*|"
    r"j_[A-Za-z_]+|\?\?_R.*|\?\?_C.*)$"
)

NET_HINT = re.compile(
    r"\b(socket|recv|send|connect|bind|listen|accept|gethostby|inet_|htons|ntohs|"
    r"WSA|RakNet|Packet|http|TCP|UDP|ssl|select\s*\()",
    re.I,
)

PROMPT = """You are reverse-engineering a 2008 Roblox Windows client (Win32, MSVC, pre-C++11).
Below is decompiled C for function {name} at {addr} in {program}.

```c
{code}
```

Answer with exactly these lines:
PURPOSE: <1-2 sentences, what the function does>
PARAMS: <meaning of arguments if evident, else unknown>
RETURNS: <return meaning, else unknown>
SIDE_EFFECTS: <globals/heap/files/sockets/threads it touches, else none>
TAGS: <lowercase comma tags chosen from: net, thread, render, physics, lua, io, str, math, crypto, ui, audio, refcount, class, thunk, unknown>
CONFIDENCE: <high|medium|low>"""

SCHEMA = """
CREATE TABLE IF NOT EXISTS functions(
    program TEXT NOT NULL,
    addr TEXT NOT NULL,
    name TEXT,
    size INTEGER,
    sig TEXT,
    is_thunk INTEGER,
    decompiled TEXT,
    n_xrefs_in INTEGER,
    tier TEXT NOT NULL DEFAULT 'unrated',
    summary TEXT,
    model TEXT,
    done INTEGER NOT NULL DEFAULT 0,
    updated_at TEXT,
    PRIMARY KEY(program, addr)
);
CREATE TABLE IF NOT EXISTS edges(
    program TEXT NOT NULL,
    src TEXT NOT NULL,
    dst TEXT NOT NULL,
    UNIQUE(program, src, dst)
);
CREATE TABLE IF NOT EXISTS meta(k TEXT PRIMARY KEY, v TEXT);
CREATE INDEX IF NOT EXISTS idx_fn_tier ON functions(tier, done);
"""


def connect(db_path):
    conn = sqlite3.connect(db_path)
    conn.executescript(SCHEMA)
    return conn


# ---------------------------------------------------------------- ingest

def ingest(conn, export_dir):
    n_fn = n_new = n_edge = 0
    for path in sorted(glob.glob(os.path.join(export_dir, "functions_*.jsonl"))):
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            for line in fh:
                line = line.strip()
                if not line:
                    continue
                try:
                    r = json.loads(line)
                except ValueError:
                    continue
                n_fn += 1
                cur = conn.execute(
                    """INSERT INTO functions(program, addr, name, size, sig, is_thunk, decompiled, n_xrefs_in)
                       VALUES(?,?,?,?,?,?,?,?)
                       ON CONFLICT(program, addr) DO UPDATE SET
                         name=excluded.name, size=excluded.size, sig=excluded.sig,
                         is_thunk=excluded.is_thunk, decompiled=excluded.decompiled,
                         n_xrefs_in=excluded.n_xrefs_in""",
                    (r.get("program"), r.get("addr"), r.get("name"), r.get("size"),
                     r.get("sig"), r.get("is_thunk"), r.get("decompiled"), r.get("n_xrefs_in")),
                )
                n_new += cur.rowcount if cur.rowcount and cur.rowcount > 0 else 0
    for path in sorted(glob.glob(os.path.join(export_dir, "edges_*.jsonl"))):
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            for line in fh:
                line = line.strip()
                if not line:
                    continue
                try:
                    r = json.loads(line)
                except ValueError:
                    continue
                cur = conn.execute(
                    "INSERT OR IGNORE INTO edges(program, src, dst) VALUES(?,?,?)",
                    (r.get("program"), r.get("src"), r.get("dst")),
                )
                if cur.rowcount and cur.rowcount > 0:
                    n_edge += 1
    conn.execute("INSERT OR REPLACE INTO meta(k, v) VALUES('last_ingest', ?)",
                 (time.strftime("%Y-%m-%d %H:%M:%S"),))
    conn.commit()
    print("ingest: %d function rows read, %d new/updated, %d new edges" % (n_fn, n_new, n_edge))


# ---------------------------------------------------------------- routing

def route_one(row):
    """-> tier string for a functions row."""
    _program, _addr, name, size, _sig, is_thunk, decompiled, _x = row[:8]
    if is_thunk:
        return "skip"
    if not decompiled or len(decompiled) < 400:
        return "skip"
    if name and LIB_NAME.match(name):
        return "skip"
    lines = decompiled.count("\n")
    if NET_HINT.search(decompiled) or (name and NET_HINT.search(name)):
        return "main"
    if lines <= 45 and "switch (" not in decompiled:
        return "fast"
    return "main"


def route(conn, limit=None):
    sql = "SELECT program, addr, name, size, sig, is_thunk, decompiled, n_xrefs_in FROM functions WHERE tier = 'unrated'"
    rows = conn.execute(sql).fetchall()
    if limit:
        rows = rows[:limit]
    counts = {}
    for r in rows:
        t = route_one(r)
        counts[t] = counts.get(t, 0) + 1
        conn.execute("UPDATE functions SET tier=? WHERE program=? AND addr=?", (t, r[0], r[1]))
    conn.commit()
    print("route: %s" % (counts or "nothing unrated"))


# ---------------------------------------------------------------- llm

def ollama_chat(model, prompt, num_ctx=8192, num_predict=400, timeout=300):
    payload = json.dumps({
        "model": model,
        "messages": [{"role": "user", "content": prompt}],
        "stream": False,
        "options": {"temperature": 0.1, "num_ctx": num_ctx, "num_predict": num_predict},
    }).encode("utf-8")
    req = urllib.request.Request(OLLAMA + "/api/chat", data=payload,
                                 headers={"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        data = json.loads(resp.read().decode("utf-8"))
    return data.get("message", {}).get("content", "") or ""


def truncate(code, head=5200, tail=1200):
    if len(code) <= head + tail:
        return code
    return code[:head] + "\n/* ... truncated ... */\n" + code[-tail:]


def build_prompt(r, model):
    program, addr, name, _size, sig, _t, decompiled, _x = r[:8]
    return PROMPT.format(name=name or "?", addr=addr, program=program,
                         code=truncate(decompiled or ""))


def run(conn, limit=None, only_tier=None, cloud=False):
    q = ("SELECT program, addr, name, size, sig, is_thunk, decompiled, n_xrefs_in, tier "
         "FROM functions WHERE done = 0 AND tier IN ('fast', 'main')")
    if only_tier:
        q += " AND tier = '%s'" % only_tier
    q += " ORDER BY CASE tier WHEN 'main' THEN 0 ELSE 1 END, size DESC"
    rows = conn.execute(q).fetchall()
    if limit:
        rows = rows[:limit]
    if not rows:
        print("run: queue empty")
        return
    print("run: %d queued (fast=%s main=%s)" % (
        len(rows), MODEL_FAST, MODEL_MAIN))
    ok = fail = 0
    t0 = time.time()
    for i, r in enumerate(rows, 1):
        tier = r[8]
        model = MODEL_FAST if tier == "fast" else MODEL_MAIN
        prompt = build_prompt(r, model)
        try:
            out = ollama_chat(model, prompt)
        except Exception as e:
            fail += 1
            print("  FAIL %s %s: %s" % (r[1], r[2], e))
            continue
        if not out.strip():
            fail += 1
            new_tier = "pending" if tier == "main" else "unrated"
            conn.execute(
                "UPDATE functions SET tier=?, updated_at=? WHERE program=? AND addr=?",
                (new_tier, time.strftime("%H:%M:%S"), r[0], r[1]))
            conn.commit()
            continue
        ok += 1
        conn.execute(
            "UPDATE functions SET summary=?, model=?, done=1, updated_at=? WHERE program=? AND addr=?",
            (out.strip(), model, time.strftime("%H:%M:%S"), r[0], r[1]))
        conn.commit()  # per-row: long open write txn blocks other writers (rebuild.py)
        if i % 25 == 0:
            print("  %d/%d ok=%d fail=%d %.0fs" % (i, len(rows), ok, fail, time.time() - t0))
    conn.commit()
    print("run: done ok=%d fail=%d %.0fs" % (ok, fail, time.time() - t0))


def cloud_run(conn, limit=None):
    """Escalation tier: routes 'pending' rows to a cloud endpoint if configured.
    RE_CLOUD_URL (OpenAI-compatible /v1/chat/completions) + RE_CLOUD_KEY + RE_CLOUD_MODEL."""
    url = os.environ.get("RE_CLOUD_URL")
    key = os.environ.get("RE_CLOUD_KEY")
    model = os.environ.get("RE_CLOUD_MODEL", "gpt-5.6-luna")
    if not url or not key:
        print("cloud: set RE_CLOUD_URL + RE_CLOUD_KEY (+ RE_CLOUD_MODEL) to enable; nothing sent")
        return
    rows = conn.execute(
        "SELECT program, addr, name, size, sig, is_thunk, decompiled, n_xrefs_in, tier "
        "FROM functions WHERE tier = 'pending' LIMIT ?", (limit or 50,)).fetchall()
    print("cloud: %d pending -> %s" % (len(rows), model))
    for r in rows:
        body = json.dumps({
            "model": model,
            "messages": [{"role": "user", "content": build_prompt(r, model)}],
            "max_tokens": 400,
        }).encode("utf-8")
        req = urllib.request.Request(url, data=body, headers={
            "Content-Type": "application/json", "Authorization": "Bearer " + key})
        try:
            with urllib.request.urlopen(req, timeout=180) as resp:
                data = json.loads(resp.read().decode("utf-8"))
            out = data["choices"][0]["message"]["content"]
        except Exception as e:
            print("  FAIL %s: %s" % (r[1], e))
            continue
        conn.execute(
            "UPDATE functions SET summary=?, model=?, tier='cloud', done=1, updated_at=? "
            "WHERE program=? AND addr=?",
            (out.strip(), model, time.strftime("%H:%M:%S"), r[0], r[1]))
        conn.commit()


def stats(conn):
    print("--- tiers")
    for row in conn.execute("SELECT tier, done, COUNT(*), SUM(LENGTH(COALESCE(decompiled,''))) FROM functions GROUP BY tier, done ORDER BY tier"):
        print("  %-9s done=%d n=%d decomp_bytes=%s" % row)
    print("--- totals")
    for row in conn.execute("SELECT COUNT(*), SUM(done) FROM functions"):
        print("  functions=%s summarized=%s" % row)
    for row in conn.execute("SELECT COUNT(*) FROM edges"):
        print("  edges=%s" % row[0])
    print("--- programs")
    for row in conn.execute("SELECT program, COUNT(*) FROM functions GROUP BY program"):
        print("  %s: %d" % row)
    print("--- top tagged NET")
    for row in conn.execute(
        "SELECT name, addr, substr(summary,1,120) FROM functions "
        "WHERE summary LIKE '%net%' AND done=1 LIMIT 10"):
        print("  %s @ %s: %s" % row)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("cmd", choices=["ingest", "route", "run", "stats", "cloud"])
    ap.add_argument("--db", default=DEFAULT_DB)
    ap.add_argument("--export-dir", default=DEFAULT_EXPORT)
    ap.add_argument("--limit", type=int, default=None)
    ap.add_argument("--only-tier", choices=["fast", "main"], default=None)
    ap.add_argument("--cloud", action="store_true", help="with run: also send pending to cloud")
    a = ap.parse_args()

    conn = connect(a.db)
    if a.cmd == "ingest":
        ingest(conn, a.export_dir)
    elif a.cmd == "route":
        route(conn, a.limit)
    elif a.cmd == "run":
        route(conn)
        run(conn, a.limit, a.only_tier)
        if a.cloud:
            cloud_run(conn, a.limit)
    elif a.cmd == "cloud":
        cloud_run(conn, a.limit)
    elif a.cmd == "stats":
        stats(conn)
    conn.close()


if __name__ == "__main__":
    main()
