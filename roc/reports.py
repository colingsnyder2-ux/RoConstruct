"""reports"""
import csv
import json
import os
import threading
import time
import urllib.error
import urllib.request
from collections import Counter, defaultdict
from datetime import datetime, timedelta, timezone
from pathlib import Path
from zoneinfo import ZoneInfo

from roc import setup


# --- daily stats ---
# Auditable daily server gains, grouped in Eastern time.

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


# --- discord ---
# Optional Discord mining digests.

ROOT = Path(__file__).resolve().parent.parent


BATCH_SECONDS = 90


RATE_WINDOW = 2 * 60 * 60


ETA_MIN_RATE = 1.0 / 3600


def emoji_bar(source, mined, retry, total):
    """Twenty-three cells: blue source, green mined, yellow partial, white untouched."""
    values = (source, mined, retry)
    cells = [value * 23 // total if total else 0 for value in values]
    spare = 23 - sum(cells)
    order = sorted(range(3), key=lambda i: values[i] * 23 % total if total else 0, reverse=True)
    for i in order[:spare]:
        cells[i] += 1
    return (":blue_square:" * cells[0] + ":green_square:" * cells[1] +
            ":yellow_square:" * cells[2] + ":white_large_square:" * (23 - sum(cells)))


def fmt_duration(seconds):
    """Compact ETA: 45s, 12m, 5h 20m, 3d 4h."""
    seconds = max(0, int(seconds))
    if seconds < 60:
        return "%ds" % seconds
    minutes, seconds = divmod(seconds, 60)
    if minutes < 60:
        return "%dm" % minutes
    hours, minutes = divmod(minutes, 60)
    if hours < 48:
        return "%dh %dm" % (hours, minutes)
    days, hours = divmod(hours, 24)
    return "%dd %dh" % (days, hours)


def inline_code(text):
    return "`%s`" % str(text).replace("`", "'")


def _post(url, payload):
    try:
        body = json.dumps(payload).encode()
        req = urllib.request.Request(url, data=body,
                                     headers={"Content-Type": "application/json",
                                              "User-Agent": "RoConstruct/1.0"})
        with urllib.request.urlopen(req, timeout=10):
            print("Discord mine log sent")
    except urllib.error.HTTPError as error:
        detail = error.read().decode("utf-8", "replace")[:300]
        print("Discord mine log failed: HTTP %d: %s" % (error.code, detail))
    except (OSError, ValueError) as error:
        print("Discord mine log failed: %s" % error)


def server_mines_webhook():
    """Dedicated feed for server-side automatic mining."""
    configured = os.environ.get("ROCONSTRUCT_SERVER_MINES_WEBHOOK")
    if configured:
        return configured
    try:
        return json.loads(setup.config("roconstruct-settings.json").read_text()).get("server_mines_webhook")
    except (OSError, ValueError):
        return None


def server_users():
    """Service usernames hidden from the leaderboard; feed routing uses mining source."""
    try:
        return set(json.loads(setup.config("roconstruct-settings.json").read_text()).get("server_users", []))
    except (OSError, ValueError):
        return set()


def tool_digest(tool, description, fields=()):
    """One asynchronous summary for local mining tools such as xcopy and repair."""
    webhook = server_mines_webhook()
    if not webhook:
        return
    embed = {"title": "⛏️ Server Mine: %s" % tool,
             "description": description,
             "color": 0x245B9E,
             "fields": list(fields),
             "footer": {"text": "RoConstruct Server Mines"},
             "timestamp": datetime.now(timezone.utc).isoformat()}
    threading.Thread(target=_post, args=(webhook, {"embeds": [embed]}), daemon=True).start()


class MineLog:
    """Thread-safe submit batcher. submit() never blocks the request handler."""

    def __init__(self, webhook, store, batch_events=None, batch_seconds=BATCH_SECONDS, server=False):
        self.webhook = webhook
        self.store = store
        self.batch_seconds = batch_seconds
        self.server = server
        self._lock = threading.Lock()
        self._buffer = []
        self._timer = None

    def submit(self, job, user, worker, model, score, points):
        if not self.webhook or not job or int(score) <= 0:
            return
        with self._lock:
            self._buffer.append({"job": dict(job), "user": user, "worker": worker,
                                 "model": model, "score": int(score), "points": int(points)})
            if self._timer is None:
                self._timer = threading.Timer(self.batch_seconds, self._timed_flush)
                self._timer.daemon = True
                self._timer.start()

    def _cancel_timer(self):
        if self._timer is not None:
            self._timer.cancel()
            self._timer = None

    def _timed_flush(self):
        with self._lock:
            events, self._buffer = self._buffer, []
            self._timer = None
        if events:
            self._send(events)

    def flush(self):
        """Send whatever is buffered (tests, shutdown)."""
        with self._lock:
            events, self._buffer = self._buffer, []
            self._cancel_timer()
        if events:
            self._send(events)

    def digest(self, events):
        """One consistent digest shape; never send per-function webhook spam."""
        client = events[0]["job"]["client"]
        if any(e["job"]["client"] != client for e in events):
            raise ValueError("Digest must contain one client")
        matched, total, matched_bytes, total_bytes = self.store.display_progress(client)
        source, mined, retry, _total = self.store.digest_progress(client)
        left = max(0, total - matched)
        percent = 100.0 * matched_bytes / total_bytes if total_bytes else 0
        bar = emoji_bar(source, mined, retry, total_bytes)
        rate = self.store.match_rate(client, RATE_WINDOW)
        rate_hr = rate * 3600
        eta = fmt_duration(left / rate) if rate >= ETA_MIN_RATE else "building rate"
        full = [e for e in events if e["score"] == 100]
        partial = [e for e in events if e["score"] < 100]
        functions = []
        for name in sorted({e["model"] for e in events if e["model"]}) or ["auto" if self.server else "Unknown model"]:
            entry = inline_code(name)
            if len(", ".join(functions + [entry])) > 1024:
                break
            functions.append(entry)

        def lines(rows):
            return "\n".join("%s **%d%%** `%s` %s · %s B" % (
                "🟢" if e["score"] == 100 else "🟨", e["score"], e["job"].get("addr", "?"),
                e["job"].get("unit", "?"), e["job"].get("size", "?")) for e in rows[:10]) or "None"

        if self.server:
            people = {"name": "⚙️ Verification", "value": "server-verified", "inline": True}
        else:
            contributors = sorted({e["user"] for e in events})
            workers = len({e["worker"] for e in events if e["worker"]})
            totals = "\n".join("%s · %s pts (%+d)" % (
                user, format(self.store.user_points(user), ","),
                sum(e["points"] for e in events if e["user"] == user)) for user in contributors)
            people = {"name": "🏆 Workers", "value": ("%d worker%s in batch\n%s" % (workers, "s" if workers != 1 else "", totals))[:1024],
                      "inline": True}
        fields = [{"name": "🟢 Fully Matched", "value": lines(full), "inline": False}]
        fields += [{"name": "🟨 Partially Matched",
                    "value": "x%d partially matched" % len(partial) if len(partial) > 10 else lines(partial),
                    "inline": False},
                   {"name": "⚡ Mining Rate", "value": "%g functions/hr (last 2h) · ETA %s" % (round(rate_hr, 1), eta), "inline": True},
                   people,
                   {"name": "✅ Batch", "value": "%d full · %d improved" % (len(full), len(partial)), "inline": True},
                   {"name": "🔧 Functions" if self.server else "🔧 Models", "value": ", ".join(functions), "inline": True}]
        return {"title": "⛏️ RoConstruct Server Mining Digest" if self.server else "⛏️ RoConstruct Mining Digest",
                "description": "**%s Client**\n%s / %s matched · %s remaining\n\n%s **%.2f%%**\n\n🟦 source · 🟩 mined · 🟨 partial · ⬜ remaining" % (
                    client, format(matched, ","), format(total, ","), format(left, ","), bar, percent),
                "color": 0x58A6FF,
                "fields": fields,
                "footer": {"text": "RoConstruct Server Mines" if self.server else "RoConstruct Mining"},
                "timestamp": datetime.now(timezone.utc).isoformat()}

    def _send(self, events):
        clients = defaultdict(list)
        for event in events:
            clients[event["job"]["client"]].append(event)
        for rows in clients.values():
            try:
                payload = {"allowed_mentions": {"parse": []}, "embeds": [self.digest(rows)]}
            except (OSError, ValueError, KeyError) as error:
                print("Discord digest skipped: %s" % error)
                continue
            threading.Thread(target=_post, args=(self.webhook, payload), daemon=True).start()
