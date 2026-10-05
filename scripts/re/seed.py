"""Seed the rebuild queue with the RBX core, highest-centrality first.

Now that scope.py proved only RBX:: is ours to rebuild (2,678 of 53,002),
the per-function codegen loop should spend its whole budget on those instead
of the 36,953 unattributed / Ogre / MFC functions.

Run: python scripts/re/rebuild.py seed-rbx [n]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import rebuild as R  # noqa: E402


def seed_rbx(conn, n=200):
    """Insert the n most-central RBX functions into `rebuild`, if absent."""
    rows = conn.execute(
        "SELECT program, addr FROM scope WHERE in_scope=1 AND done=0 "
        "ORDER BY indeg DESC LIMIT ?", (n,)).fetchall()
    added = 0
    for prog, addr in rows:
        # skip thunks and trivial stubs: they are the compiler's problem, not
        # the decompiler's, and they waste the budget
        f = conn.execute(
            "SELECT is_thunk, length(coalesce(decompiled,'')), sig "
            "FROM functions WHERE program=? AND addr=?", (prog, addr)).fetchone()
        if not f or f[0] or not f[1] or f[1] < 300:
            continue
        cur = conn.execute(
            "INSERT OR IGNORE INTO rebuild(program, addr, name) VALUES(?,?,?)",
            (prog, addr, conn.execute(
                "SELECT name FROM functions WHERE program=? AND addr=?",
                (prog, addr)).fetchone()[0]))
        added += cur.rowcount if cur.rowcount and cur.rowcount > 0 else 0
    conn.commit()
    total = conn.execute("SELECT COUNT(*) FROM rebuild").fetchone()[0]
    print("seed-rbx: +%d new (queue now %d total)" % (added, total))
    print()
    print("next 20 by centrality:")
    for r in conn.execute(
            "SELECT r.program, r.addr, s.indeg FROM rebuild r "
            "JOIN scope s ON s.program=r.program AND s.addr=r.addr "
            "WHERE r.compiles=0 ORDER BY s.indeg DESC LIMIT 20"):
        print("  %-24s %-10s indeg=%d" % r)