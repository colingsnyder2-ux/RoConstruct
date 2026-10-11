"""Daily leaderboard webhook; credentials live outside the repository."""
import json
import urllib.error
import urllib.request
from datetime import datetime, timedelta, timezone
from pathlib import Path
from zoneinfo import ZoneInfo

from roc import providers
from roc.daily_stats import TIMEZONE
from roc.discord import code_block

KEY = "ROCONSTRUCT_LEADERBOARD_WEBHOOK"


def payload(report, demo=False):
    people = []
    for rank, row in enumerate(report["people"][:10], 1):
        models = ["%s %s" % (m["name"].split(":", 1)[-1], format(m["exacts"], ",")) for m in row["models"] if not m["name"].startswith("roc ")]
        mined = sum(m["exacts"] for m in row["models"] if m["name"].startswith("roc "))
        if mined:
            models.append("Server Mining %s" % format(mined, ","))
        medal = ("🥇", "🥈", "🥉")[rank - 1] if rank <= 3 else "%d." % rank
        entry = "%s **%s — %s**\n%s" % (medal, row["name"], format(row["exacts"], ","), code_block(" · ".join(models)))
        if len("\n".join(people + [entry])) > 1024:
            break
        people.append(entry)
    lines = lambda rows: "\n".join("%s — %s" % (r["name"][4:] if r["name"].startswith("roc ") else r["name"], format(r["exacts"], ",")) for r in rows[:12]) or "—"
    fields = [{"name": "👥 Top people · models used", "value": "\n".join(people) or "No verified gains."},
              {"name": "⛏️ Server Mining", "value": code_block(lines(report["server_mining"]))}]
    return {"allowed_mentions": {"parse": []}, "embeds": [{
        "title": "🏆 " + ("DEMO · " if demo else "") + "RoConstruct Daily Leaderboard",
        "description": "📅 %s · **%s new exact functions**" % (report["date"], format(report["exacts"], ",")) +
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
