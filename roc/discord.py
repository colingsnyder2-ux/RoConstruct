"""Optional Discord notifications for mining events."""
import json
import os
import threading
import urllib.request


def mined(webhook, job, user, worker, model):
    url = webhook or os.environ.get("ROCONSTRUCT_DISCORD_WEBHOOK")
    if not url or not job:
        return
    content = ("⛏️ **Function mined** | `%s %s` | `%s` | user `%s` | worker `%s` | model `%s` | %d bytes" %
               (job.get("client", "?"), job.get("addr", "?"), job.get("unit", "?"),
                user, worker, model or "auto", int(job.get("size", 0))))

    def send():
        try:
            body = json.dumps({"content": content[:1900]}).encode()
            req = urllib.request.Request(url, data=body,
                                         headers={"Content-Type": "application/json"})
            with urllib.request.urlopen(req, timeout=5):
                pass
        except (OSError, ValueError):
            pass

    threading.Thread(target=send, daemon=True).start()
