#!/usr/bin/env python3
"""Promote coordinator-approved results into a Git branch.

Only successful jobs with a compiler-clean result are promoted. Runtime and
cross-function evidence can raise the score before promotion.
"""
import argparse
import json
import re
import sqlite3
import subprocess
import time
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--db", default="coordinator.db")
    ap.add_argument("--repo", default=".")
    ap.add_argument("--branch", default=None)
    ap.add_argument("--min-score", type=float, default=1.0,
                    help="minimum best evidence score; compiler-clean is 1")
    ap.add_argument("--require-runtime", action="store_true")
    a = ap.parse_args()
    repo = Path(a.repo).resolve()
    branch = a.branch or "roconstruct/batch-%s" % time.strftime("%Y%m%d-%H%M%S")
    if not re.match(r"^[A-Za-z0-9._/-]+$", branch):
        raise SystemExit("invalid branch name")
    db = sqlite3.connect(a.db)
    rows = db.execute("SELECT id,program,address,result FROM jobs WHERE state='done' AND result IS NOT NULL").fetchall()
    eligible = []
    for row in rows:
        result = json.loads(row[3])
        evidence = db.execute("SELECT kind,MAX(score) FROM evidence WHERE job_id=? GROUP BY kind", (row[0],)).fetchall()
        score = max((item[1] for item in evidence), default=0)
        kinds = {item[0] for item in evidence}
        if result.get("ok") and result.get("source") and score >= a.min_score and (not a.require_runtime or "runtime" in kinds):
            eligible.append(row)
    if not eligible:
        raise SystemExit("no successful jobs meet promotion evidence threshold")
    subprocess.run(["git", "-C", str(repo), "switch", "-c", branch], check=True)
    written = 0
    for jid, program, address, encoded in eligible:
        result = json.loads(encoded)
        source = result.get("source", "")
        safe_program = re.sub(r"[^A-Za-z0-9_.-]", "_", program)
        path = repo / "reconstructed" / safe_program / (address + ".cpp")
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("// job %s\n%s\n" % (jid, source), encoding="utf-8")
        written += 1
    subprocess.run(["git", "-C", str(repo), "add", "reconstructed"], check=True)
    subprocess.run(["git", "-C", str(repo), "commit", "-m", "Promote reconstruction batch"], check=True)
    print("promoted %d/%d functions on branch %s" % (written, len(eligible), branch))
    print("push branch, then open GitHub PR for review")


if __name__ == "__main__":
    main()
