"""Measure the compile oracle on the seeded RBX queue.

`rebuild.py fixup` only measures the 10-file debug set, which is unrepresentative
(it predates the type universe and was picked for triage convenience). This runs
the real pipeline over the seeded in-scope RBX functions and reports an honest
first-try / repair-loop / final rate, plus which error classes remain.

  phase 1  model  : qwen2.5-coder:7b-instruct writes C++ per function
  phase 2  compile: cl /c /TP with the mechanical repair ladder
  phase 3  retry  : compiler errors fed back to the model, <=N attempts

Run: python scripts/re/bench.py --n 20 --max-attempts 2
"""
import argparse
import collections
import os
import re
import sqlite3
import sys
import time

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, SCRIPT_DIR)
import rebuild as R  # noqa: E402

DB = os.path.join(os.path.dirname(os.path.dirname(SCRIPT_DIR)), "work", "re",
                  "rbx2008m.db")
CODE_RE = re.compile(r"error (C\d+)")


def bench(n=20, max_attempts=2, model="qwen2.5-coder:7b-instruct"):
    c = sqlite3.connect(DB)
    c.executescript(R.REBUILD_SCHEMA)
    rows = c.execute(
        "SELECT r.program, r.addr FROM rebuild r "
        "JOIN scope s ON s.program=r.program AND s.addr=r.addr "
        "WHERE r.compiles=0 AND r.attempts < ? "
        "ORDER BY s.indeg DESC LIMIT ?", (max_attempts, n)).fetchall()
    if not rows:
        print("bench: nothing pending in the RBX queue")
        return

    print("bench: %d functions, model=%s, max_attempts=%d"
          % (len(rows), model, max_attempts))
    ok = first_try = 0
    errs = collections.Counter()
    t0 = time.time()

    for i, (prog, addr) in enumerate(rows, 1):
        fn = c.execute(
            "SELECT program, addr, name, decompiled FROM functions "
            "WHERE program=? AND addr=?", (prog, addr)).fetchone()
        if not fn or not fn[3]:
            continue
        indeg = c.execute(
            "SELECT indeg FROM scope WHERE program=? AND addr=?",
            (prog, addr)).fetchone()[0]
        err = None
        code = ""
        for attempt in range(1, max_attempts + 1):
            try:
                out = R.generate(c, fn, model, err)
            except Exception as e:
                err = "ollama: %s" % e
                continue
            code = R.extract_code(out)
            if not code:
                err = "empty output"
                continue
            good, cerr = R.compile_c(code, "%s_%s" % (prog, addr))
            if good:
                if attempt == 1:
                    first_try += 1
                c.execute(
                    "UPDATE rebuild SET name=?, code=?, compiles=1, attempts=?,"
                    " first_try=?, last_err=NULL, model=?, updated_at=? "
                    "WHERE program=? AND addr=?",
                    (fn[2], code, attempt, 1 if attempt == 1 else 0, model,
                     time.strftime("%Y-%m-%d %H:%M:%S"), prog, addr))
                c.commit()
                ok += 1
                print("  [%2d/%2d] OK   %s %s (indeg=%d, attempt %d)"
                      % (i, len(rows), prog, addr, indeg, attempt))
                break
            err = cerr
            for code_id in set(CODE_RE.findall(cerr)):
                errs[code_id] += 1
        else:
            c.execute(
                "UPDATE rebuild SET name=?, code=?, compiles=0, attempts=?,"
                " first_try=0, last_err=?, model=?, updated_at=? "
                "WHERE program=? AND addr=?",
                (fn[2], code, max_attempts, (err or "")[-4000:], model,
                 time.strftime("%Y-%m-%d %H:%M:%S"), prog, addr))
            c.commit()
            first_line = ""
            for ln in (err or "").splitlines():
                if "error" in ln:
                    first_line = ln.strip()[:100]
                    break
            print("  [%2d/%2d] FAIL %s %s (indeg=%d) | %s"
                  % (i, len(rows), prog, addr, indeg, first_line))

    print()
    print("=" * 62)
    print("compiled      : %d/%d  (%.0f%%)" % (ok, len(rows), 100.0 * ok / len(rows)))
    print("first attempt : %d  (%.0f%%)" % (first_try, 100.0 * first_try / len(rows)))
    print("elapsed       : %.0fs" % (time.time() - t0))
    print()
    print("remaining error classes:")
    for code, n in errs.most_common(15):
        print("  %-8s %d" % (code, n))
    c.close()


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=20)
    ap.add_argument("--max-attempts", type=int, default=2)
    ap.add_argument("--model", default="qwen2.5-coder:7b-instruct")
    a = ap.parse_args()
    bench(a.n, a.max_attempts, a.model)
