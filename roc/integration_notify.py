"""Send changed native integration digests, using the player mining layout."""
import json
import sqlite3
import time
import urllib.error
import urllib.parse
import urllib.request
from datetime import datetime, timezone

from roc.integration import CLIENT, atomic_json, digest
from roc.reports import RATE_WINDOW, fmt_duration, inline_code, player_mines_webhook


def payload(promotions, job, receipt=None):
    store, root = promotions.store, promotions.root
    with store.lock:
        credits = store.db.execute("SELECT COUNT(*) FROM integration_credit WHERE user=?", (job["user"],)).fetchone()[0]
        recent = store.db.execute("SELECT receipt FROM integration_jobs WHERE state='accepted' AND updated>=?",
                                  (time.time() - RATE_WINDOW,)).fetchall()
        state = store.db.execute("SELECT phase FROM integration_jobs WHERE id=?", (job["id"],)).fetchone()[0]
        scores = dict(store.db.execute("SELECT addr,score FROM funcs WHERE client=?", (CLIENT,)).fetchall())
    proof = promotions.directory / "progress-native.json"
    functions = {}
    description = "**2008-06 Client**\n\nEstablishing verified native baseline..."
    if proof.exists():
        native = set(json.loads(proof.read_text())["addresses"])
        manifest = {f["addr"]: f for f in json.loads((root / "rebuild/2008-06/manifests/functions.json").read_text())}
        counts, sizes = [0] * 3, [0] * 3
        for line in (root / "work/2008-06/functions.jsonl").read_text().splitlines():
            if not line.strip():
                continue
            f = json.loads(line)
            if f.get("kind", "code") != "code":
                continue
            functions[f["addr"]] = f
            score = scores.get(f["addr"], manifest.get(f["addr"], {}).get("score", 0))
            group = 0 if f["addr"] in native else 1 if score == 100 else 2
            counts[group] += 1
            sizes[group] += f["size"]
        total = sum(sizes)
        cells = [s * 23 // total if total else 0 for s in sizes]
        for i in sorted(range(3), key=lambda i: sizes[i] * 23 % total if total else 0, reverse=True)[:23 - sum(cells)]:
            cells[i] += 1
        bar = "".join(c * n for c, n in zip(("\U0001f7ea", "\U0001f7e6", "\u2b1c"), cells))
        description = ("**2008-06 Client**\n%s / %s integrated \u00b7 %s remaining\n\n%s **%.2f%%** of target bytes\n\n"
            "\U0001f7ea integrated \u00b7 \U0001f7e6 exact waiting \u00b7 \u2b1c not integrated") % (
                format(counts[0], ","), format(sum(counts), ","), format(sum(counts[1:]), ","),
                bar, 100 * sizes[0] / total if total else 0)
        remaining = sum(sizes[1:])
    else:
        remaining = None
    recent_gains = {addr for row in recent for addr in json.loads(row[0]).get("gains", [])
                    if addr in functions}
    rate = len(recent_gains) * 3600 / RATE_WINDOW
    byte_rate = sum(functions[addr]["size"] for addr in recent_gains) / RATE_WINDOW
    eta = "collecting rate" if not byte_rate or remaining is None else "~" + fmt_duration(remaining / byte_rate)
    if remaining == 0:
        eta = "0s"
    accepted = receipt and receipt.get("accepted")
    rejected = receipt is not None and not accepted
    delta = receipt.get("credits", 0) if accepted else 0
    gains = receipt.get("gains", []) if accepted else []
    matched = "\n".join("\U0001f7e3 **100%%** `%s` %s \u00b7 %s B" % (
        addr, functions.get(addr, {}).get("unit", "?"), functions.get(addr, {}).get("size", "?"))
        for addr in gains[:10]) or "None"
    if len(gains) > 10:
        matched += "\n+%d more integrated" % (len(gains) - 10)
    fields = [
        {"name": "\U0001f7e3 Fully Integrated", "value": matched[:1024], "inline": False},
        {"name": "\u26a1 Integration Rate", "value": "**%g functions/hr** \u00b7 **%s B/hr** *(last 6h)* \u00b7 byte ETA %s" % (round(rate, 1), format(round(byte_rate * 3600), ","), eta), "inline": True},
        {"name": "\U0001f3c6 Workers", "value": "**%s** \u00b7 %s pts \u00b7 %s native integrated *(+%d)*" % (
            job["user"], format(store.user_points(job["user"]), ","), format(credits, ","), delta), "inline": True},
        {"name": "\u2699\ufe0f Verification", "value": "server-verified \u00b7 %d integrated" % len(gains) if accepted else "rejected \u00b7 no native credit" if rejected else state, "inline": True},
        {"name": "\U0001f527 Models", "value": inline_code(job["model"]), "inline": True},
    ]
    if accepted:
        fields.append({"name": "\U0001f7ea Rebuild Ownership", "value": "**%s owned** (+%d) \u00b7 **%s distinct** (+%d)" % (
            format(receipt["owned_after"], ","), receipt["owned_after"] - receipt["owned_before"],
            format(receipt["distinct_after"], ","), receipt["distinct_after"] - receipt["distinct_before"]), "inline": False})
    return {"allowed_mentions": {"parse": []}, "embeds": [{"title": "\u26cf\ufe0f RoConstruct Integration Digest",
        "description": description, "color": 0xA855F7, "fields": fields,
        "footer": {"text": "RoConstruct Integration"},
        "timestamp": datetime.now(timezone.utc).isoformat()}]}


def notify(promotions, job, receipt=None):
    url = player_mines_webhook()
    # Post only real progress: an accepted job that integrated something. Phase changes, retries, merges
    # and rejections changed the digest every time and flooded the channel with zero-gain messages.
    if not url or not (receipt and receipt.get("accepted") and receipt.get("gains")):
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
        target = urllib.parse.urlunsplit(parts._replace(query="wait=true"))
        request = urllib.request.Request(target, json.dumps(body).encode(),
            {"Content-Type": "application/json", "User-Agent": "RoConstruct-Native/1.0"}, method="POST")
        with urllib.request.urlopen(request, timeout=15) as response:
            result = json.loads(response.read() or b"{}")
        atomic_json(state_path, {"message_id": result["id"], "digest": key})
    except (OSError, ValueError, KeyError, sqlite3.Error, urllib.error.URLError):
        # Optional reporting cannot reject independently verified code.
        return
