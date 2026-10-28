"""docs/integration.json: native integration progress for the website (2008-06 rbxgs rebuild).
Same four groups as the Discord digest: integrated (linked rebuild reproduces it), exact waiting (mined 100%,
not yet integrated), partial, unmined. Per-function data is published on gh-pages only (see server.publish_pages)."""
import json
import re
import sqlite3
from datetime import datetime, timezone
from zoneinfo import ZoneInfo

from roc.integration import CLIENT, ROOT, atomic_json

def readable(symbol):
    """MSVC decorated name -> Namespace::Class::method (enough for labels; full name stays in 'symbol')."""
    m = re.match(r"\?\?([01])([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)*)@", symbol)
    if m:
        scope = [m[2]] + [p for p in m[3].split("@") if p]
        cls = "::".join(reversed(scope))
        return "%s::%s%s" % (cls, "~" if m[1] == "1" else "", m[2])
    m = re.match(r"\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)+)@", symbol)
    if m:
        return "::".join(list(reversed([p for p in m[2].split("@") if p])) + [m[1]])
    return symbol


def build(root=ROOT, log=print):
    out = root / "rebuild" / CLIENT / "out"
    native_path = root / "work/integration/progress-native.json"
    native = set(json.loads(native_path.read_text())["addresses"]) if native_path.exists() else set()
    names_path = out / "native-names.json"
    names = json.loads(names_path.read_text()) if names_path.exists() else {}
    db = sqlite3.connect("file:%s?mode=ro" % (root / "work/server.db").as_posix(), uri=True, timeout=30)
    try:
        scores = dict(db.execute("SELECT addr,score FROM funcs WHERE client=?", (CLIENT,)).fetchall())
        jobs = db.execute("SELECT id,user,model,unit,receipt,updated FROM integration_jobs WHERE state='accepted' "
                          "ORDER BY updated DESC").fetchall()
        leaders = db.execute("SELECT user,model,COUNT(*) FROM integration_credit WHERE client=? GROUP BY user,model "
                             "ORDER BY COUNT(*) DESC", (CLIENT,)).fetchall()
    finally:
        db.close()
    groups = {k: [0, 0] for k in ("integrated", "exact_waiting", "partial", "unmined")}
    for line in (root / "work" / CLIENT / "functions.jsonl").read_text().splitlines():
        if not line.strip():
            continue
        f = json.loads(line)
        if f.get("kind", "code") != "code":
            continue
        score = scores.get(f["addr"], 0)
        key = "integrated" if f["addr"] in native else "exact_waiting" if score == 100 else "partial" if score else "unmined"
        groups[key][0] += 1
        groups[key][1] += f["size"]
    units = {job: unit for job, _, _, unit, _, _ in jobs}
    receipts = []
    daily = {}
    seen = set()
    for job, user, model, unit, receipt, updated in jobs:
        r = json.loads(receipt or "{}")
        key = r.get("job", job)
        if key in seen:
            continue
        seen.add(key)
        day = datetime.fromtimestamp(updated, ZoneInfo("America/New_York")).strftime("%Y-%m-%d")
        row = daily.setdefault(day, {"day": day, "gains": 0, "jobs": 0, "models": {}})
        gains = len(r.get("new_distinct", r.get("gains", [])))
        row["gains"] += gains
        row["jobs"] += 1
        series = row["models"].setdefault(model or "Unknown", {"gains": 0, "jobs": 0})
        series["gains"] += gains
        series["jobs"] += 1
        unit = ", ".join(dict.fromkeys(units.get(j, "") for j in r.get("merged_jobs", [job])))
        receipts.append({"job": key[:8], "user": user, "model": model, "units": unit[:120],
                         "gains": len(r.get("gains", [])), "distinct_gains": len(r.get("new_distinct", r.get("gains", []))), "owned_after": r.get("owned_after"),
                         "when": datetime.fromtimestamp(updated, timezone.utc).strftime("%Y-%m-%d %H:%M UTC")})
    shown = {a: names[a] for a in names if a in native or (names[a].get("score") or 0) >= 50}
    links_path = root / 'local/findings/2008-06/verification/native-source-links.json'
    sources = json.loads(links_path.read_text(encoding='utf-8')) if links_path.exists() else {}
    data = {"client": CLIENT, "updated": datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M UTC"),
            "groups": {k: {"functions": n, "bytes": b} for k, (n, b) in groups.items()},
            "native": sorted(native),
            "sources": {a: value for a, value in sources.items() if a in native},
            # addr -> [readable name, decorated symbol, rebuilt score (100 = integrated)]
            "names": {a: [readable(v["symbol"]), v["symbol"], 100 if a in native else v.get("score")] for a, v in sorted(shown.items())},
            "daily": [daily[day] for day in sorted(daily)],
            "jobs": receipts[:100],
            "leaderboard": [{"user": u, "model": m, "native_credits": n} for u, m, n in leaders]}
    path = root / "docs/integration.json"
    previous = json.loads(path.read_text(encoding="utf-8")) if path.exists() else {}
    history = {row["day"]: row for row in previous.get("history", [])} if previous.get("client") == CLIENT else {}
    day = datetime.now(ZoneInfo("America/New_York")).strftime("%Y-%m-%d")
    history[day] = {"day": day, "groups": data["groups"]}
    data["history"] = [history[day] for day in sorted(history)]
    atomic_json(root / "docs/integration.json", data)
    log("Integration site data: %d integrated, %d named" % (len(native), len(data["names"])))
    return data


if __name__ == "__main__":
    build()
