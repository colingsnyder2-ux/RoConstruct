"""One editable Server Mining digest; native credit never becomes raw mining credit."""
import json
import sqlite3
import time
import urllib.error
import urllib.parse
import urllib.request
from datetime import datetime, timezone

from roc.integration import CLIENT, atomic_json, digest
from roc.reports import fmt_duration, server_mines_webhook


def payload(promotions, job, receipt=None):
    store, root = promotions.store, promotions.root
    with store.lock:
        credits = store.db.execute("SELECT COUNT(*) FROM integration_credit WHERE user=?", (job["user"],)).fetchone()[0]
        recent = store.db.execute("SELECT COUNT(*) FROM integration_credit WHERE ts>?", (time.time() - 7200,)).fetchone()[0]
        pending = store.db.execute("SELECT COUNT(*) FROM integration_jobs WHERE state IN ('queued','verifying')").fetchone()[0]
        state = store.db.execute("SELECT phase FROM integration_jobs WHERE id=?", (job["id"],)).fetchone()[0]
        scores = dict(store.db.execute("SELECT addr,score FROM funcs WHERE client=?", (CLIENT,)).fetchall())
    points = store.user_points(job["user"])
    proof = promotions.directory / "progress-native.json"
    description = "**2008-06 | Mined \u2192 Native**\n\nEstablishing verified native baseline..."
    if proof.exists():
        native = set(json.loads(proof.read_text())["addresses"])
        manifest = {f["addr"]: f for f in json.loads((root / "rebuild/2008-06/manifests/functions.json").read_text())}
        counts, sizes = [0] * 4, [0] * 4
        for line in (root / "work/2008-06/functions.jsonl").read_text().splitlines():
            if not line.strip():
                continue
            f = json.loads(line)
            score = scores.get(f["addr"], manifest.get(f["addr"], {}).get("score", 0))
            group = 0 if f["addr"] in native else 1 if score == 100 else 2 if score else 3
            counts[group] += 1
            sizes[group] += f["size"]
        total = sum(sizes)
        cells = [s * 23 // total if total else 0 for s in sizes]
        for i in sorted(range(4), key=lambda i: sizes[i] * 23 % total if total else 0, reverse=True)[:23 - sum(cells)]:
            cells[i] += 1
        bar = "".join(c * n for c, n in zip(("\U0001f7ea", "\U0001f7e6", "\U0001f7e8", "\u2b1c"), cells))
        description = ("**2008-06 | Mined \u2192 Native**\n\n%s\n**%.2f%% of target bytes integrated**\n\n"
            "\U0001f7ea **%s native** \u00b7 \U0001f7e6 **%s exact waiting**\n"
            "\U0001f7e8 **%s partial mined** \u00b7 \u2b1c **%s unmined**\n**%s remaining to integrate**") % (
                bar, 100 * sizes[0] / total if total else 0, *(format(n, ",") for n in counts), format(sum(counts[1:]), ","))
        remaining = sum(counts[1:])
    else:
        remaining = None
    rate = recent / 2
    eta = "collecting rate" if not rate or remaining is None else "~" + fmt_duration(remaining / (rate / 3600))
    accepted = receipt and receipt.get("accepted")
    rejected = receipt is not None and not accepted
    delta = receipt.get("credits", 0) if accepted else 0
    fields = [
        {"name": "\U0001f7e9 Fully Matched", "value": "**%d native credits**\n**100%%** exact" % credits, "inline": True},
        {"name": "\U0001f7e8 Partially Matched", "value": "**0** partial promotions\n**%d** batches pending" % pending, "inline": True},
        {"name": "\u26a1 Native Rate / ETA", "value": "**%g/hr**\nETA **%s** (last 2h)" % (rate, eta), "inline": True},
        {"name": "\U0001f3c6 User / Score", "value": "**%s**\n**%s pts** (+0 mining)\n**+%d native**" % (job["user"], format(points, ","), delta), "inline": True},
        {"name": "\u274c Batch" if rejected else "\u2705 Batch", "value": "**%d classes**\n%s" % (
            len(job["unit"].split(", ")), "checks passed" if accepted else "rejected" if rejected else state), "inline": True},
        {"name": "\U0001f527 Model", "value": job["model"], "inline": True},
    ]
    if accepted:
        fields.append({"name": "\U0001f7ea Rebuild Ownership", "value": "**%s owned** (+%d) \u00b7 **%s distinct** (+%d)" % (
            format(receipt["owned_after"], ","), receipt["owned_after"] - receipt["owned_before"],
            format(receipt["distinct_after"], ","), receipt["distinct_after"] - receipt["distinct_before"]), "inline": False})
    return {"allowed_mentions": {"parse": []}, "embeds": [{"title": "\u26cf\ufe0f RoConstruct Server Mining Digest",
        "description": description, "color": 0xA855F7, "fields": fields,
        "footer": {"text": "Native integration | Independent server verification | ETA is a rough recent-rate extrapolation"},
        "timestamp": datetime.now(timezone.utc).isoformat()}]}


def notify(promotions, job, receipt=None):
    url = server_mines_webhook()
    if not url:
        return
    try:
        body = payload(promotions, job, receipt)
        state_path = promotions.directory / "discord.json"
        state = json.loads(state_path.read_text()) if state_path.exists() else {}
        content = dict(body["embeds"][0])
        content.pop("timestamp")
        key = digest(content)
        if state.get("digest") == key:
            return
        parts = urllib.parse.urlsplit(url)
        message = state.get("message_id")
        target = urllib.parse.urlunsplit(parts._replace(
            path=parts.path.rstrip("/") + ("/messages/" + message if message else ""), query="" if message else "wait=true"))
        request = urllib.request.Request(target, json.dumps(body).encode(),
            {"Content-Type": "application/json", "User-Agent": "RoConstruct-Native/1.0"}, method="PATCH" if message else "POST")
        with urllib.request.urlopen(request, timeout=15) as response:
            result = json.loads(response.read() or b"{}")
        atomic_json(state_path, {"message_id": message or result["id"], "digest": key})
    except (OSError, ValueError, KeyError, sqlite3.Error, urllib.error.URLError):
        # Optional reporting cannot reject independently verified code.
        return
