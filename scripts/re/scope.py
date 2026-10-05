"""Scope the reconstruction to the code we ACTUALLY must rebuild.

The client is mostly third-party (Ogre 1.2 "Dagon", MFC, ATL, G3D -- see
findings.md §4 BREAKTHROUGH). Only the RBX:: namespace is Roblox-specific,
so rebuilding all 53,002 functions is wasted effort.

Builds the RBX work queue:
  - functions whose decompile or signature mentions RBX:: or an RBX type
  - de-duplicated against the Ogre/MFC/ATL/G3D surface
  - ranked by centrality (in-degree from edges) so the core lands first

Run: python scripts/re/scope.py queue
     python scripts/re/scope.py stats
"""
import collections
import os
import re
import sqlite3
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from summarize import DEFAULT_DB  # noqa: E402
from typelib import connect as typeconnect  # noqa: E402

SCOPE_SCHEMA = """
CREATE TABLE IF NOT EXISTS scope(
    program   TEXT NOT NULL,
    addr      TEXT NOT NULL,
    owner     TEXT,        -- Ogre | MFC | ATL | G3D | RBX | client
    indeg     INTEGER DEFAULT 0,
    in_scope  INTEGER DEFAULT 0,
    tier      TEXT,
    done      INTEGER DEFAULT 0,
    updated_at TEXT,
    PRIMARY KEY(program, addr)
);
CREATE INDEX IF NOT EXISTS idx_scope_owner ON scope(owner, done);
CREATE INDEX IF NOT EXISTS idx_scope_inscope ON scope(in_scope, indeg);
"""

# Type-name families mapped to who owns them
OWNERS = (
    ("RBX", re.compile(r"^RBX::")),
    ("RbxSceneManager", re.compile(r"^Rbx")),
    ("Ogre", re.compile(r"^Ogre::")),
    ("MFC", re.compile(r"^(CWnd|CDC|CFrameWnd|CDialog|CView|CDocument|"
                       r"CWinApp|CCmdTarget|CObject|CFile|CArchive|CRect|"
                       r"CMDIFrameWnd|CMDIClient|CMDIChildWnd|CMenu|"
                       r"CToolBar|CStatusBar|CWnd|CPaintDC|CClientDC|"
                       r"CRuntimeClass|CException|CImageList|CListCtrl|"
                       r"CTreeCtrl|CEdit|CButton|CCtrl|CWinApp|"
                       r"CDocManager|CFrame|CView|CDocTemplate|"
                       r"CMultiDocTemplate|CCommandLineInfo|CGdiObject|"
                       r"CDocTemplate|CFileDialog|CFindReplaceDialog|"
                       r"CPageSetupDialog|CCommDlgWrapper|CPrintDlg|"
                       r"COleException|COleDateTime|CPropertySheet|"
                       r"CPropertyPage|CWndLayout|CDockBar|CControlBar)$")),
    ("ATL", re.compile(r"^ATL::")),
    ("G3D", re.compile(r"^G3D")),
)


def owner_of(name):
    if not name:
        return None
    for owner, pat in OWNERS:
        if pat.match(name):
            return owner
    return None


def queue(conn):
    """Tag every function with its owning library; mark RBX as in-scope."""
    # indegree from the call graph: who calls this function
    indeg = collections.Counter()
    for prog, dst in conn.execute("SELECT program, dst FROM edges"):
        indeg[(prog, dst)] += 1

    rows = conn.execute(
        "SELECT program, addr, name, sig, decompiled FROM functions"
    ).fetchall()

    stats = collections.Counter()
    for prog, addr, name, sig, dec in rows:
        text = (name or "") + " " + (sig or "") + " " + (dec or "")[:6000]
        # which library's types appear in this function?
        owners = set()
        for m in re.finditer(r"\b([A-Z][A-Za-z0-9_]*(?:::[A-Za-z_][A-Za-z0-9_]*)*)",
                             text):
            o = owner_of(m.group(1))
            if o:
                owners.add(o)
        # explicit RBX class names not in the types table yet
        if re.search(r"\bRBX::", text) or re.search(r"\bRbx[A-Z]", text):
            owners.add("RBX")
        owner = "RBX" if "RBX" in owners else (
            sorted(owners)[0] if owners else "client")
        stats[owner] += 1
        ins = 1 if owner == "RBX" else 0
        conn.execute(
            "INSERT OR REPLACE INTO scope"
            "(program, addr, owner, indeg, in_scope, tier, done, updated_at)"
            " VALUES(?,?,?,?,?,?,COALESCE((SELECT done FROM scope "
            "        WHERE program=? AND addr=?),0),?)",
            (prog, addr, owner, indeg[(prog, addr)], ins,
             conn.execute("SELECT tier FROM functions WHERE program=? AND addr=?",
                          (prog, addr)).fetchone()[0] if True else None,
             prog, addr, __import__("time").strftime("%Y-%m-%d %H:%M:%S")))
    conn.commit()
    print("=== functions by owning library")
    for o, n in stats.most_common():
        print("  %-14s %6d" % (o, n))
    tot = sum(stats.values())
    print("  %-14s %6d" % ("TOTAL", tot))
    print()
    inscope = conn.execute(
        "SELECT COUNT(*) FROM scope WHERE in_scope=1").fetchone()[0]
    print("IN SCOPE (RBX only): %d functions = %.1f%% of client"
          % (inscope, 100.0 * inscope / tot))


def stats(conn):
    print("=== in-scope (RBX) by program")
    for r in conn.execute(
            "SELECT program, COUNT(*), SUM(done) FROM scope WHERE in_scope=1 "
            "GROUP BY program"):
        print("  %-24s %5d functions, %d done" % (r[0], r[1], r[2] or 0))
    print()
    print("=== most-central in-scope functions (rebuild these first)")
    for r in conn.execute(
            "SELECT program, addr, indeg, tier FROM scope WHERE in_scope=1 "
            "ORDER BY indeg DESC LIMIT 25"):
        print("  %-24s %-10s indeg=%-4d tier=%s" % r)
    print()
    print("=== in-scope not yet summarised")
    for r in conn.execute(
            "SELECT COUNT(*), SUM(CASE WHEN done=1 THEN 1 ELSE 0 END) "
            "FROM scope WHERE in_scope=1"):
        print("  %d total, %d summarised" % (r[0], r[1] or 0))


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "queue"
    c = typeconnect()          # opens DEFAULT_DB, creates types tables
    c.executescript(SCOPE_SCHEMA)
    if cmd == "queue":
        queue(c)
    elif cmd == "stats":
        stats(c)
    else:
        print("cmd: queue | stats")
    c.close()


if __name__ == "__main__":
    main()