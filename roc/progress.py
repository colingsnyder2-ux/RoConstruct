"""Build the GitHub Pages data: docs/progress.json, docs/history.json,
docs/data/<client>.json.

Scores come from work/<client>/scores.json ({addr: 0-100}); 100 = byte match.
"""
import json
import re
import subprocess
import time
from pathlib import Path

from roc import clients

ROOT = Path(__file__).resolve().parent.parent
DOCS = ROOT / "docs"
STATS = ("functions", "matched", "partial", "bytes", "matched_bytes", "source_bytes", "mined_bytes", "partial_bytes")


def summarize(funcs):
    """funcs: [[addr, size, score, ...], ...]"""
    total = sum(f[1] for f in funcs)
    return {
        "functions": len(funcs),
        "matched": sum(1 for f in funcs if f[2] == 100),
        "partial": sum(1 for f in funcs if 0 < f[2] < 100),
        "bytes": total,
        "matched_bytes": sum(f[1] for f in funcs if f[2] == 100),
        "source_bytes": sum(f[1] for f in funcs if f[2] == 100 and len(f) > 5 and f[5]),
        "mined_bytes": sum(f[1] for f in funcs if f[2] == 100 and not (len(f) > 5 and f[5])),
        "partial_bytes": sum(f[1] for f in funcs if 0 < f[2] < 100),
    }


def head_commit():
    try:
        out = subprocess.run(["git", "log", "-1", "--format=%h%x00%s"], cwd=ROOT,
                             capture_output=True, text=True, check=True).stdout.strip()
        return out.split("\0", 1) if out else (None, None)
    except (OSError, subprocess.CalledProcessError):
        return None, None


def add_history(stats, updated):
    """One snapshot per run; a run that changes nothing replaces the last one."""
    path = DOCS / "history.json"
    hist = json.loads(path.read_text()) if path.exists() else []
    commit, subject = head_commit()
    snap = {"date": updated, "commit": commit, "subject": subject, "clients": stats}
    if hist and hist[-1]["clients"] == stats:
        hist[-1] = snap
    else:
        hist.append(snap)
    path.write_text(json.dumps(hist, separators=(",", ":")) + "\n")


def union_bytes(span_lists):
    """Total bytes covered by [va, len] spans; overlaps (shared strings) count once."""
    spans = sorted((va, va + n) for lst in span_lists for va, n in lst)
    total, end = 0, 0
    for a, b in spans:
        if b > end:
            total += b - max(a, end)
            end = b
    return total


def library_meta():
    """{(client, address): [library version, source file]} for matched library code."""
    try:
        output = subprocess.run(["rg", "--json", "^// roc-lib: ", "src"], cwd=ROOT,
                                capture_output=True, text=True, check=True).stdout
    except (OSError, subprocess.CalledProcessError):
        return {}
    out = {}
    for line in output.splitlines():
        row = json.loads(line)
        if row["type"] != "match":
            continue
        path = Path(row["data"]["path"]["text"])
        match = re.match(r"// roc-lib: (\S+) (\S+)", row["data"]["lines"]["text"])
        if match:
            out[(path.parent.name, path.stem)] = list(match.groups())
    return out


def fetch_server(server, token=None):
    from roc.worker import Api
    return Api(server, token).call("/v1/export")


def build(server=None, token=None, public_server=None, remote=None):
    """server: pull scores + leaderboard from the group server (else local scores only).
    remote: the same export passed in directly (the server publishing itself)."""
    (DOCS / "data").mkdir(parents=True, exist_ok=True)
    if remote is None:
        remote = fetch_server(server, token) if server else {"scores": {}, "leaderboard": []}
    library = library_meta()
    out, stats = [], {}
    for name, entry in sorted(clients.load().items()):
        if entry.get("donor"):  # donor binaries are matching/test fixtures, not shown on the site
            continue
        work = ROOT / "work" / name
        row = {"name": name, "compiler": entry["compiler"], "built": entry.get("built"), "started": False}
        if (work / "functions.jsonl").exists():
            scores_file = work / "scores.json"
            scores = json.loads(scores_file.read_text()) if scores_file.exists() else {}
            for addr, value in remote["scores"].get(name, {}).items():
                scores[addr] = max(value, scores.get(addr, 0))
            data_file = work / "data.json"
            spans = json.loads(data_file.read_text()) if data_file.exists() else {}
            spans.update(remote.get("data", {}).get(name, {}))
            meta_file = work / "meta.json"
            meta = json.loads(meta_file.read_text()) if meta_file.exists() else {}
            units, unit_ids, funcs, generated = [], {}, [], 0
            sources = {p.stem: p for p in (ROOT / "src" / name).glob("*.cpp")}
            families = remote.get("families", {}).get(name, {})
            for line in (work / "functions.jsonl").open():
                f = json.loads(line)
                if f.get("kind", "code") != "code":  # compiler/linker stubs don't count
                    generated += 1
                    continue
                unit = f.get("unit", "")
                if unit not in unit_ids:
                    unit_ids[unit] = len(units)
                    units.append(unit)
                addr = f["addr"]
                source = sources.get(addr)
                funcs.append([int(addr, 16), f["size"], scores.get(addr, 0), unit_ids[unit],
                              bool(source), library.get((name, addr)), families.get(addr)])
            (DOCS / "data" / ("%s.json" % name)).write_text(json.dumps(
                {"name": name, "compiler": entry["compiler"], "units": units, "funcs": funcs},
                separators=(",", ":")))
            row.update(summarize(funcs), started=True, data_bytes=meta.get("data_bytes", 0),
                       leaderboard=remote.get("leaderboards", {}).get(name, []),
                       data_matched_bytes=union_bytes(v for a, v in spans.items() if scores.get(a) == 100),
                       classes=meta.get("classes", 0), generated=generated)
            stats[name] = {k: row[k] for k in STATS}
        out.append(row)
    updated = time.strftime("%Y-%m-%d %H:%M UTC", time.gmtime())
    progress = {"updated": updated, "clients": out, "leaderboard": remote["leaderboard"][:50],
                "server": public_server}
    (DOCS / "progress.json").write_text(json.dumps(progress, indent=1) + "\n")
    add_history(stats, updated)
    return progress
