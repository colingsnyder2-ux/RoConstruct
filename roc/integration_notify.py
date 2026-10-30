"""Send native integration digests to Server Mining, using the shared mining layout."""
import json
import math
import re
import sqlite3
import time
import urllib.error
import urllib.parse
import urllib.request
from datetime import datetime, timezone
from pathlib import PurePosixPath

from roc.integration import CLIENT, atomic_json, digest
from roc.reports import RATE_WINDOW, fmt_duration, inline_code, mining_embed, server_mines_webhook


def progress_text(groups):
    """Disjoint stages; amber candidates never increase accepted coverage."""
    keys = ('integrated', 'owned_waiting', 'exact_waiting')
    sizes = [groups.get(key, {}).get('bytes', 0) for key in keys]
    sizes.append(sum(groups[key]['bytes'] for key in ('partial', 'unmined')))
    total = sum(sizes)
    cells = [n * 23 // total if total else 0 for n in sizes]
    for index in sorted(range(4), key=lambda i: sizes[i] * 23 % total if total else 0, reverse=True)[:23-sum(cells)]:
        cells[index] += 1
    bar = ''.join(color * n for color, n in zip(('🟪', '🟨', '🟦', '⬜'), cells))
    integrated = groups['integrated']['functions']
    nearly = groups.get('owned_waiting', {}).get('functions', 0)
    functions = sum(row['functions'] for row in groups.values())
    nearly_line = ('%s nearly integrated\n' % format(nearly, ',')) if 'owned_waiting' in groups else ''
    return ('**2008-06 Client**\n%s / %s integrated · %s remaining\n%s\n'
            '%s **%.2f%%** of target bytes integrated\n'
            '🟪 integrated · 🟨 nearly integrated · 🟦 exact waiting · ⬜ not exact\n'
            'Nearly integrated = owned byte-exact; checks/acceptance pending.') % (
        format(integrated, ','), format(functions, ','), format(functions-integrated, ','), nearly_line,
        bar, 100 * sizes[0] / total if total else 0)


def owned_payload(user, model, rows, groups=None):
    lines = ['`%s` %s · %s' % (row['addr'], inline_code(row['name'][:96]), inline_code(row['module'])) for row in rows]
    fields = [
        {'name': '🟣 Nearly Integrated', 'value': '\n'.join(lines)[:1024] or 'None', 'inline': False},
        {'name': '⚡ Mining Rate', 'value': 'collecting native integration rate', 'inline': True},
        {'name': '🏆 Workers', 'value': '**%s**' % user, 'inline': True},
        {'name': '✅ Batch', 'value': '%d owned exacts · 0 accepted integration credits · acceptance pending' % len(rows), 'inline': True},
        {'name': '🔧 Models', 'value': inline_code(model), 'inline': True},
    ]
    description = progress_text(groups) if groups else '**2008-06 Client**\nOwned byte-exact discoveries · acceptance pending'
    return {'allowed_mentions': {'parse': []}, 'embeds': [mining_embed(description, fields, color=0xA855F7)]}


def record_partials(promotions, user, body):
    """Bounded contributor observations. Separate telemetry table; no scoring/credit writes."""
    revision, model, rows = body.get('base_revision'), body.get('model'), body.get('partials')
    if not isinstance(model, str) or not 1 <= len(model.strip()) <= 120:
        raise ValueError('Partial reports need actual model identity')
    if not isinstance(rows, list) or not 1 <= len(rows) <= 64:
        raise ValueError('Need 1-64 partial observations')
    manifest = promotions.root / 'rebuild/2008-06/manifests/functions.json'
    targets = {r['addr'] for r in json.loads(manifest.read_text()) if r.get('score') == 100 and r.get('unit', '').startswith('RBX::')}
    clean = []
    for row in rows:
        if not isinstance(row, dict):
            raise ValueError('Invalid partial observation')
        path = PurePosixPath(row.get('file', ''))
        if (len(str(path)) > 260 or '\\' in str(path) or ':' in str(path)
                or path.is_absolute() or '..' in path.parts or len(path.parts) < 2 or path.as_posix() != row.get('file')
                or path.parts[0] not in ('App', 'Network', 'RbxView', 'RbxGraphics', 'Rendering') or path.suffix != '.cpp'):
            raise ValueError('Invalid partial source path')
        if row.get('addr') not in targets or row.get('base_revision') != revision:
            raise ValueError('Unknown partial target or baseline')
        for key in ('previous', 'score'):
            if type(row.get(key)) not in (int, float) or not math.isfinite(row[key]) or not 0 <= row[key] <= 100:
                raise ValueError('Invalid partial score')
        for key in ('frame_before', 'frame_ok', 'calls_before', 'calls_ok'):
            if type(row.get(key)) is not bool:
                raise ValueError('Invalid partial structural metric')
        for key in ('source_sha256', 'object_sha256'):
            if not isinstance(row.get(key), str) or not re.fullmatch('[0-9a-f]{64}', row[key]):
                raise ValueError('Partial source/object hashes required')
        if not (row['score'] > row['previous'] or row['frame_ok'] and not row['frame_before'] or row['calls_ok'] and not row['calls_before']):
            raise ValueError('Partial report contains no improvement')
        clean.append({k: row[k] for k in ('file', 'addr', 'previous', 'score', 'frame_before', 'frame_ok',
                      'calls_before', 'calls_ok', 'source_sha256', 'object_sha256')})
    fresh = []
    with promotions.store.lock, promotions.store.db as db:
        if not isinstance(revision, str) or not db.execute('SELECT 1 FROM integration_bases WHERE revision=?', (revision,)).fetchone():
            raise ValueError('Unknown partial baseline revision')
        db.execute('CREATE TABLE IF NOT EXISTS integration_partial_observations('
                   'revision TEXT,file TEXT,addr TEXT,score REAL,frame_ok INTEGER,calls_ok INTEGER,'
                   'user TEXT,model TEXT,observation TEXT,updated REAL,PRIMARY KEY(revision,file,addr))')
        for row in clean:
            key = revision, row['file'], row['addr']
            previous = db.execute('SELECT score,frame_ok,calls_ok FROM integration_partial_observations WHERE revision=? AND file=? AND addr=?', key).fetchone()
            if previous and row['score'] <= previous[0] and row['frame_ok'] <= previous[1] and row['calls_ok'] <= previous[2]:
                continue
            db.execute('INSERT OR REPLACE INTO integration_partial_observations VALUES(?,?,?,?,?,?,?,?,?,?)',
                (*key, max(row['score'], previous[0]) if previous else row['score'],
                 row['frame_ok'] or bool(previous and previous[1]), row['calls_ok'] or bool(previous and previous[2]),
                 user, model, json.dumps(row), time.time()))
            fresh.append(row)
    return dict(recorded=len(fresh), local_only=True, exact_credits=0)


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
        from roc.integration_site import coverage
        groups, functions = coverage(root, scores, native)
        description = progress_text(groups)
        remaining = sum(row['bytes'] for key, row in groups.items() if key != 'integrated')
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
        {"name": "\u26a1 Mining Rate", "value": "**%g functions/hr** \u00b7 **%s B/hr** *(last 6h)* \u00b7 byte ETA %s" % (round(rate, 1), format(round(byte_rate * 3600), ","), eta), "inline": True},
        {"name": "\U0001f3c6 Workers", "value": "**%s** \u00b7 %s pts \u00b7 %s native integrated *(+%d)*" % (
            job["user"], format(store.user_points(job["user"]), ","), format(credits, ","), delta), "inline": True},
        {"name": "\u2705 Batch", "value": "server-verified \u00b7 %d integrated" % len(gains) if accepted else "rejected \u00b7 no native credit" if rejected else state, "inline": True},
        {"name": "\U0001f527 Models", "value": inline_code(job["model"]), "inline": True},
    ]
    return {"allowed_mentions": {"parse": []}, "embeds": [mining_embed(description, fields, color=0xA855F7)]}



def notify(promotions, job, receipt=None):
    url = server_mines_webhook()
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
