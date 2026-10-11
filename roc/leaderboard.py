"""Daily leaderboard webhook; credentials live outside the repository."""
import json
import urllib.error
import urllib.request
from datetime import datetime, timedelta
from pathlib import Path
from zoneinfo import ZoneInfo

from roc import providers
from roc.daily_stats import TIMEZONE

KEY = "ROCONSTRUCT_LEADERBOARD_WEBHOOK"


def payload(report, demo=False):
    people = []
    for rank, row in enumerate(report["people"][:10], 1):
        models = ", ".join("%s: %d" % (m["name"], m["exacts"]) for m in row["models"])
        people.append("%d. **%s** — %d exacts\n%s" % (rank, row["name"], row["exacts"], models))
    lines = lambda rows: "\n".join("%s — **%d**" % (r["name"], r["exacts"]) for r in rows[:12]) or "No verified gains."
    fields = [{"name": "Top people · models used", "value": ("\n".join(people) or "No verified gains.")[:1024]},
              {"name": "Server Mining", "value": lines(report["server_mining"])[:1024]},
              {"name": "Models / commands", "value": lines(report["models"])[:1024]},
              {"name": "Clients", "value": lines(report["clients"])[:1024]}]
    return {"allowed_mentions": {"parse": []}, "embeds": [{
        "title": ("DEMO · " if demo else "") + "RoConstruct Daily Leaderboard",
        "description": ("Sample data only; no actual credit.\n" if demo else "") +
                       "%s · %s\n**%d new verified exact functions**" % (report["date"], report["timezone"], report["exacts"]),
        "color": 0x3FB950, "fields": fields,
        "footer": {"text": "Client/address counted once · 2009-12 excluded · historical unattributed events: %d" % report["legacy_unattributed_exacts"]}}]}


def send(report, demo=False):
    url = providers.secret(KEY)
    if not url:
        return False
    request = urllib.request.Request(url, data=json.dumps(payload(report, demo)).encode(),
                                     headers={"Content-Type": "application/json", "User-Agent": "RoConstruct/1.0"})
    try:
        with urllib.request.urlopen(request, timeout=15) as response:
            return 200 <= response.status < 300
    except urllib.error.HTTPError as error:
        raise RuntimeError("Leaderboard webhook HTTP %d" % error.code) from None
    except OSError:
        raise RuntimeError("Leaderboard webhook connection failed") from None


def publish_yesterday(store, directory):
    if not providers.secret(KEY):
        return
    day = (datetime.now(ZoneInfo(TIMEZONE)).date() - timedelta(days=1)).isoformat()
    marker = Path(directory) / (day + ".discord-sent")
    if not marker.exists() and send(store.daily_stats(day)):
        marker.write_text(day, encoding="utf-8")
