"""Daily leaderboard webhook; credentials live outside the repository."""
import json
import urllib.error
import urllib.request
from datetime import datetime, timedelta, timezone
from pathlib import Path
from zoneinfo import ZoneInfo

from roc import providers
from roc.daily_stats import TIMEZONE

KEY = "ROCONSTRUCT_LEADERBOARD_WEBHOOK"


def payload(report, demo=False):
    people = []
    for rank, row in enumerate(report["people"][:10], 1):
        medal = ("🥇", "🥈", "🥉")[rank - 1] if rank <= 3 else "**#%d**" % rank
        models = " · ".join("`%s` **%s**" % (m["name"], format(m["exacts"], ",")) for m in row["models"])
        people.append("%s **%s** — 🟢 **%s** exacts\n%s" % (medal, row["name"], format(row["exacts"], ","), models))
    lines = lambda rows: "\n".join("`%s` → **%s**" % (r["name"], format(r["exacts"], ",")) for r in rows[:12]) or "—"
    fields = [{"name": "🟢 Fully Matched", "value": "**%s** functions" % format(report["exacts"], ","), "inline": True},
              {"name": "🏆 Contributors", "value": "**%d** people" % len(report["people"]), "inline": True},
              {"name": "🗂️ Clients", "value": "**%d** builds" % len(report["clients"]), "inline": True},
              {"name": "🏅 Top Contributors · Models Used", "value": ("\n\n".join(people) or "No verified gains.")[:1024]},
              {"name": "⛏️ Server Mining", "value": lines(report["server_mining"])[:1024], "inline": True},
              {"name": "🤖 Worker Models", "value": lines([r for r in report["models"] if not r["name"].startswith("roc ")])[:1024], "inline": True},
              {"name": "📦 Client Gains", "value": lines(report["clients"])[:1024]}]
    return {"allowed_mentions": {"parse": []}, "embeds": [{
        "title": "🏆 " + ("DEMO · " if demo else "") + "RoConstruct Daily Leaderboard",
        "description": "📅 **%s** · Eastern Time\n✅ Server-verified daily gains" % report["date"] +
                       ("\n*Demo — sample data only.*" if demo else ""),
        "color": 0x58A6FF, "fields": fields,
        "footer": {"text": "RoConstruct Server Mining"},
        "timestamp": datetime.now(timezone.utc).isoformat()}]}


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
