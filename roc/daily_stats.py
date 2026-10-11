"""Auditable daily server gains, grouped in Eastern time."""
import csv
import json
from collections import Counter, defaultdict
from datetime import datetime, timedelta
from pathlib import Path
from zoneinfo import ZoneInfo

TIMEZONE = "America/New_York"


def day_bounds(day=None, timezone=TIMEZONE):
    zone = ZoneInfo(timezone)
    start = datetime.strptime(day, "%Y-%m-%d").replace(tzinfo=zone) if day else datetime.now(zone).replace(hour=0, minute=0, second=0, microsecond=0)
    return start.date().isoformat(), start.timestamp(), (start + timedelta(days=1)).timestamp()


def summarize(rows, day=None, timezone=TIMEZONE, legacy_exact=0):
    day, start, end = day_bounds(day, timezone)
    gains, seen = [], set()
    for row in sorted(rows, key=lambda r: (r["ts"], r["id"])):
        key = row["client"], row["addr"]
        if (row["client"] == "2009-12" or not start <= row["ts"] < end
                or not row["verified"] or row["new"] != 100 or row["old"] >= 100 or key in seen):
            continue
        seen.add(key)
        gains.append(row)
    people, models, mining, clients = defaultdict(Counter), Counter(), Counter(), Counter()
    for row in gains:
        model = row["model"] or "Unknown"
        people[row["user"]][model] += 1
        models[model] += 1
        if model.startswith("roc "):
            mining[model] += 1
        clients[row["client"]] += 1
    ranking = lambda counts: [{"name": name, "exacts": count} for name, count in sorted(counts.items(), key=lambda item: (-item[1], item[0]))]
    return {"date": day, "timezone": timezone, "exacts": len(gains),
            "people": [{"name": name, "exacts": sum(counts.values()), "models": ranking(counts)}
                       for name, counts in sorted(people.items(), key=lambda item: (-sum(item[1].values()), item[0]))],
            "models": ranking(models), "server_mining": ranking(mining), "clients": ranking(clients),
            "legacy_unattributed_exacts": legacy_exact, "gains": gains}


def save(report, directory):
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    path = directory / (report["date"] + ".json")
    temp = path.with_suffix(".tmp")
    temp.write_text(json.dumps(report, indent=2), encoding="utf-8")
    temp.replace(path)
    with path.with_suffix(".csv").open("w", encoding="utf-8", newline="") as out:
        writer = csv.DictWriter(out, fieldnames=["id", "ts", "client", "addr", "user", "model", "old", "new", "verified"])
        writer.writeheader()
        writer.writerows(report["gains"])
    return path


def archive_days(store, directory):
    """Backfill missed days on startup; finalize yesterday even after downtime."""
    zone = ZoneInfo(TIMEZONE)
    today = datetime.now(zone).date()
    with store.lock:
        stamps = store.db.execute("SELECT DISTINCT ts FROM mining_events").fetchall()
    days = {datetime.fromtimestamp(row[0], zone).date() for row in stamps}
    days.add(today - timedelta(days=1))
    for day in sorted(days):
        save(store.daily_stats(day.isoformat()), directory)
