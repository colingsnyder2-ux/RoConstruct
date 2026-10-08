"""Optional Discord mining digests."""
import json
import os
import threading
import time
import urllib.error
import urllib.request

BATCH_EVENTS = 10
BATCH_SECONDS = 90
RATE_WINDOW = 24 * 3600
ETA_MIN_RATE = 1.0 / 3600


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
        left = max(0, total - matched)
        percent = 100.0 * matched / total if total else 0
        filled = min(20, round(percent / 5))
        bar = "█" * filled + "░" * (20 - filled)
        full = [e for e in events if e["score"] == 100]
        partial = [e for e in events if e["score"] < 100]

        def lines(rows):
            out = ["%s **%d%%** `%s` %s" % ("🟢" if e["score"] == 100 else "🟡",
                   e["score"], e["job"].get("addr", "?"), e["job"].get("unit", "?"))
                   for e in rows[:10]]
            if len(rows) > 10:
                out.append("…and %d more" % (len(rows) - 10))
            return "\n".join(out) or "None"

        rate = self.store.match_rate(client, RATE_WINDOW)
        rate_hr = rate * 3600
        eta = fmt_duration(left / rate) if rate >= ETA_MIN_RATE else "building rate"
        leaders = self.store.leaderboard(client)
        leader = leaders[0] if leaders else {"user": "none", "points": 0}
        return {"title": "⛏️ RoConstruct Mining Digest",
                "description": "**%s Client**\n\n`%s` **%.2f%%**\n%s / %s matched · %s remaining" % (
                    client, bar, percent, format(matched, ","), format(total, ","), format(left, ",")),
                "color": 0x57F287,
                "fields": [
                    {"name": "🟢 Fully Matched", "value": lines(full), "inline": False},
                    {"name": "🟡 Partially Matched", "value": lines(partial), "inline": False},
                    {"name": "⚡ Mining Rate", "value": "%d functions/hr" % round(rate_hr), "inline": True},
                    {"name": "🏆 Contributor", "value": "%s · %s pts" % (
                        leader["user"], format(leader["points"], ",")), "inline": True}],
                "footer": {"text": "ETA: %s • %d example updates" % (eta, len(events))}}

    def _send(self, events):
        try:
            payload = {"embeds": [self.digest(events)]}
        except (OSError, ValueError, KeyError) as error:
            print("Discord digest skipped: %s" % error)
            return
        threading.Thread(target=_post, args=(self.webhook, payload), daemon=True).start()
