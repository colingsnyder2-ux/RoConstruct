"""Optional Discord notifications for mining events."""
import json
import os
import threading
import urllib.error
import urllib.request


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
