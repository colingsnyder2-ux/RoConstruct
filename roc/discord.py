"""Optional Discord mining digests."""
import json
import os
import threading
import time
import urllib.error
import urllib.request
from datetime import datetime, timezone

BATCH_EVENTS = 10
BATCH_SECONDS = 90
RATE_WINDOW = 15 * 60
ETA_MIN_RATE = 1.0 / 3600


def emoji_bar(source, mined, retry, total):
    """Fifteen cells: blue source, green mined, red retry, white untouched."""
    values = (source, mined, retry)
    cells = [value * 15 // total if total else 0 for value in values]
    spare = 15 - sum(cells)
    order = sorted(range(3), key=lambda i: values[i] * 15 % total if total else 0, reverse=True)
    for i in order[:spare]:
        cells[i] += 1
    return (":blue_square:" * cells[0] + ":green_square:" * cells[1] +
            ":negative_squared_cross_mark:" * cells[2] + ":white_large_square:" * (15 - sum(cells)))


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


class MineLog:
    """Thread-safe submit batcher. submit() never blocks the request handler."""

    def __init__(self, webhook, store, batch_events=BATCH_EVENTS, batch_seconds=BATCH_SECONDS):
        self.webhook = webhook
        self.store = store
        self.batch_events = batch_events
        self.batch_seconds = batch_seconds
        self._lock = threading.Lock()
        self._buffer = []
        self._timer = None

    def submit(self, job, user, worker, model, score, points):
        if not self.webhook or not job or int(score) <= 0:
            return
        with self._lock:
            self._buffer.append({"job": dict(job), "user": user, "worker": worker,
                                 "model": model, "score": int(score), "points": int(points)})
            flush_now = len(self._buffer) >= self.batch_events
            if flush_now:
                events = self._buffer
                self._buffer = []
                self._cancel_timer()
            else:
                events = None
                if self._timer is None:
                    self._timer = threading.Timer(self.batch_seconds, self._timed_flush)
                    self._timer.daemon = True
                    self._timer.start()
        if flush_now:
            self._send(events)

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
        client = events[-1]["job"].get("client", "?")
        matched, total = self.store.client_progress(client)
        matched_bytes, total_bytes = self.store.client_bytes(client)
        source, mined, retry, _total = self.store.digest_progress(client)
        left = max(0, total - matched)
        percent = 100.0 * matched_bytes / total_bytes if total_bytes else 0
        bar = emoji_bar(source, mined, retry, total_bytes)
        rate = self.store.match_rate(client, RATE_WINDOW)
        rate_hr = rate * 3600
        eta = fmt_duration(left / rate) if rate >= ETA_MIN_RATE else "building rate"
        contributor = events[-1]["user"]
        batch_points = sum(e["points"] for e in events if e["user"] == contributor)
        full = [e for e in events if e["score"] == 100]
        partial = [e for e in events if e["score"] < 100]

        def lines(rows):
            return "\n".join("%s **%d%%** `%s` %s · %s B" % (
                "🟢" if e["score"] == 100 else "🟡", e["score"], e["job"].get("addr", "?"),
                e["job"].get("unit", "?"), e["job"].get("size", "?")) for e in rows[:10]) or "None"

        return {"title": "⛏️ RoConstruct Mining Digest",
                "description": "**%s Client**\n\n%s **%.2f%%**\n%s / %s matched · %s remaining" % (
                    client, bar, percent, format(matched, ","), format(total, ","), format(left, ",")),
                "color": 0x58A6FF,
                "fields": [
                    {"name": "🟢 Fully Matched", "value": lines(full), "inline": False},
                    {"name": "🟡 Partially Matched", "value": lines(partial), "inline": False},
                    {"name": "⚡ Mining Rate", "value": "%d functions/hr" % round(rate_hr), "inline": True},
                    {"name": "🏆 Workers", "value": "%s - %s pts (%+d)" % (
                        contributor, format(self.store.user_points(contributor), ","), batch_points), "inline": True},
                    {"name": "✅ Batch", "value": "%d matched · %d improved" % (len(full), len(partial)), "inline": True},
                    {"name": "⏱ ETA", "value": eta, "inline": True},
                    ],
                "footer": {"text": "RoConstruct Mining"},
                "timestamp": datetime.now(timezone.utc).isoformat()}

    def _send(self, events):
        try:
            payload = {"embeds": [self.digest(events)]}
        except (OSError, ValueError, KeyError) as error:
            print("Discord digest skipped: %s" % error)
            return
        threading.Thread(target=_post, args=(self.webhook, payload), daemon=True).start()
