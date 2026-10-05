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
    a = ap.parse_args()
    repo = Path(a.repo).resolve()
    branch = a.branch or "roconstruct/batch-%s" % time.strftime("%Y%m%d-%H%M%S")
    if not re.match(r"^[A-Za-z0-9._/-]+$", branch):
        raise SystemExit("invalid branch name")
    rows = sqlite3.connect(a.db).execute(
        "SELECT id,program,address,result FROM jobs WHERE state='done' AND result IS NOT NULL"
    ).fetchall()
    if not rows:
        raise SystemExit("no successful jobs to promote")
    subprocess.run(["git", "-C", str(repo), "switch", "-c", branch], check=True)
    written = 0
    for jid, program, address, encoded in rows:
        result = json.loads(encoded)
        source = result.get("source", "")
        if not result.get("ok") or not source:
            continue
        safe_program = re.sub(r"[^A-Za-z0-9_.-]", "_", program)
        path = repo / "reconstructed" / safe_program / (address + ".cpp")
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("// job %s\n%s\n" % (jid, source), encoding="utf-8")
        written += 1
    subprocess.run(["git", "-C", str(repo), "add", "reconstructed"], check=True)
    subprocess.run(["git", "-C", str(repo), "commit", "-m", "Promote reconstruction batch"], check=True)
    print("promoted %d functions on branch %s" % (written, branch))
    print("push branch, then open GitHub PR for review")


if __name__ == "__main__":
    main()
