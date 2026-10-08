"""Optional Discord notifications for mining events.

Submits are batched into digests: a burst of worker jobs produces one message
per batch (up to 10 events or 90 seconds) instead of one message per submit.
Each digest carries per-user point totals, functions remaining per client,
and a finish ETA at the recent match rate.
"""
import json
import os
import threading
import time
import urllib.error
import urllib.request

BATCH_EVENTS = 10
BATCH_SECONDS = 90
RATE_WINDOW = 24 * 3600


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
        """One embed for a batch: per-event lines plus totals/remaining/ETA."""
        users = sorted({e["user"] for e in events})
        clients = sorted({e["job"].get("client", "?") for e in events})
        points = {u: self.store.user_points(u) for u in users}
        lines = ["`%s` %s %d%% (+%d) by `%s`" % (e["job"].get("addr", "?"),
                 e["job"].get("unit", "?"), e["score"], e["points"], e["user"])
                 for e in events[:25]]
        if len(events) > 25:
            lines.append("…and %d more" % (len(events) - 25))
        footer = []
        for client in clients:
            matched, total = self.store.client_progress(client)
            left = max(0, total - matched)
            rate = self.store.match_rate(client, RATE_WINDOW)
            eta = "ETA %s at %d/hr" % (fmt_duration(left / rate * 3600), round(rate * 3600)) if rate > 0 else "ETA unknown"
            footer.append("%s: %d/%d matched, %d left (%s)" % (client, matched, total, left, eta))
        footer.append(" | ".join("`%s`: %d pts" % (u, points[u]) for u in users))
        all100 = all(e["score"] == 100 for e in events)
        return {"title": "✅ %d function%s matched" % (len(events), "" if len(events) == 1 else "s")
                        if all100 else "⛏️ Mining digest (%d updates)" % len(events),
                "color": 0x3FB950 if all100 else 0xF2C14E,
                "fields": [{"name": "Updates", "value": "\n".join(lines), "inline": False}],
                "footer": {"text": " — ".join(footer)[:2048]}}

    def _send(self, events):
        try:
            payload = {"embeds": [self.digest(events)]}
        except (OSError, ValueError, KeyError) as error:
            print("Discord digest skipped: %s" % error)
            return
        threading.Thread(target=_post, args=(self.webhook, payload), daemon=True).start()


def mined(webhook, job, user, worker, model, score, points, title="⛏️ Function mined"):
    url = webhook or os.environ.get("ROCONSTRUCT_DISCORD_WEBHOOK")
    if not url or not job or int(score) <= 0:
        return
    color = 0x3FB950 if int(score) == 100 else 0xF2C14E
    embed = {"title": title, "color": color,
             "fields": [
                 {"name": "Function", "value": "`%s`" % job.get("unit", "?"), "inline": False},
                 {"name": "Client", "value": "`%s`" % job.get("client", "?"), "inline": True},
                 {"name": "Address", "value": "`%s`" % job.get("addr", "?"), "inline": True},
                 {"name": "Score", "value": "%d%%" % int(score), "inline": True},
                 {"name": "Points earned", "value": "+%d" % int(points), "inline": True},
                 {"name": "User", "value": "`%s`" % user, "inline": True},
                 {"name": "Model", "value": "`%s`" % (model or "auto"), "inline": True},
             ], "footer": {"text": "%d bytes | worker %s" % (int(job.get("size", 0)), worker)}}

    def send():
        try:
            body = json.dumps({"embeds": [embed]}).encode()
            req = urllib.request.Request(url, data=body,
                                         headers={"Content-Type": "application/json",
                                                  "User-Agent": "RoConstruct/1.0"})
            with urllib.request.urlopen(req, timeout=5):
                print("Discord mine log sent")
        except urllib.error.HTTPError as error:
            detail = error.read().decode("utf-8", "replace")[:300]
            print("Discord mine log failed: HTTP %d: %s" % (error.code, detail))
        except (OSError, ValueError) as error:
            print("Discord mine log failed: %s" % error)

    threading.Thread(target=send, daemon=True).start()
