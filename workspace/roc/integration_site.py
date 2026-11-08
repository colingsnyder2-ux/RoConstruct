"""site/integration.json: native integration progress for the website (2008-06 rbxgs rebuild).
Same four groups as the Discord digest: integrated (linked rebuild reproduces it), exact waiting (mined 100%,
not yet integrated), partial, unmined. Per-function data is published on gh-pages only (see server.publish_pages)."""
import json
import re
import sqlite3
import hashlib
import io
import subprocess
from datetime import datetime, timezone
from zoneinfo import ZoneInfo

from roc.integration import CLIENT, ROOT, atomic_json

def progress_description(data):
    """Shared byte coverage; exact inactive work never grants runtime credit."""
    groups = data['groups']
    native = data.get('native_code', {})
    integrated = groups['integrated']
    inactive = native.get('inactive', {'functions': 0, 'bytes': 0})
    draft = native.get('draft', {'functions': 0, 'bytes': 0})
    total = sum(g['bytes'] for g in groups.values())
    covered = integrated['bytes'] + inactive['bytes']
    sizes = [integrated['bytes'], inactive['bytes'], draft['bytes'], total - covered - draft['bytes']]
    cells = [value * 23 // total if total else 0 for value in sizes]
    if total:
        order = sorted(range(4), key=lambda i: sizes[i] * 23 % total, reverse=True)
        for i in order[:23 - sum(cells)]:
            cells[i] += 1
    if not total:
        cells[-1] = 23
    bar = ''.join(color * n for color, n in zip(('🟪', '🟧', '🩷', '⬜'), cells))
    functions = sum(g['functions'] for g in groups.values())
    return ('**2008-06 Client**\n%s / %s integrated · %s remaining\n'
            '%s inactive exact · %s draft functions · %s exact waiting\n\n'
            '%s **%.2f%% native code**\n\n'
            '🟪 integrated · 🟧 inactive exact · 🩷 draft · ⬜ remaining') % (
                format(integrated['functions'], ','), format(functions, ','),
                format(functions - integrated['functions'], ','), format(inactive['functions'], ','),
                format(draft['functions'], ','), format(groups.get('exact_waiting', {}).get('functions', 0), ','),
                bar, 100 * covered / total if total else 0)


def live_progress(root=ROOT):
    """Read current proof, receipts and scores; never reuse the hourly site snapshot."""
    native = set(json.loads((root / 'work/integration/progress-native.json').read_text())['addresses'])
    db = sqlite3.connect((root / 'work/server.db').as_uri() + '?mode=ro', uri=True, timeout=30)
    try:
        scores = dict(db.execute('SELECT addr,score FROM funcs WHERE client=?', (CLIENT,)))
    finally:
        db.close()
    inactive = inactive_code(root)
    groups, functions = coverage(root, scores, native, set(inactive))
    stats = {key: {'functions': 0, 'bytes': 0} for key in ('inactive', 'draft')}
    for addr, row in inactive.items():
        if addr not in native and addr in functions:
            bucket = stats['inactive' if row[1] else 'draft']
            bucket['functions'] += 1
            bucket['bytes'] += functions[addr]['size']
    return dict(groups=groups, native_code=stats,
                updated=datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M UTC'))


def integration_rate(data, root=ROOT, now=None):
    """Integration-only deltas from distinct timestamped progress observations."""
    from roc.reports import fmt_duration
    now = datetime.now(timezone.utc).timestamp() if now is None else now
    try:
        stamp = datetime.strptime(data['updated'], '%Y-%m-%d %H:%M UTC').replace(tzinfo=timezone.utc).timestamp()
    except (KeyError, ValueError):
        return 'Building rate · waiting for timestamped progress'
    if now - stamp > 6 * 3600 or stamp > now:
        return 'Building rate · waiting for fresh progress'
    path = root / 'work/native-integration-rate.json'
    try:
        samples = json.loads(path.read_text(encoding='utf-8'))['samples']
    except (OSError, ValueError, KeyError):
        samples = []
    group = data['groups']['integrated']
    total = sum(g['bytes'] for g in data['groups'].values())
    current = dict(time=stamp, functions=group['functions'], bytes=group['bytes'], total=total)
    if samples and stamp < samples[-1]['time']:
        return 'Building rate · waiting for current progress'
    if samples and (current['functions'] < samples[-1]['functions'] or
                    current['bytes'] < samples[-1]['bytes'] or total != samples[-1]['total']):
        samples = []  # A corrected baseline is not a negative integration gain.
    samples = [s for s in samples if now - 6 * 3600 <= s['time'] < stamp]
    samples.append(current)
    atomic_json(path, dict(schema=1, samples=samples))
    elapsed = stamp - samples[0]['time']
    if not elapsed:
        return 'Building rate · waiting for a second progress sample'
    functions = (current['functions'] - samples[0]['functions']) * 3600 / elapsed
    byte_rate = (current['bytes'] - samples[0]['bytes']) * 3600 / elapsed
    remaining = max(0, total - current['bytes'])
    eta = fmt_duration(remaining * 3600 / byte_rate) if byte_rate > 0 else 'building rate'
    if not remaining:
        eta = '0s'
    return '**%g functions/hr** · **%s B/hr** *(observed %d min; 6h window)* · byte ETA %s' % (
        round(functions, 1), format(round(byte_rate), ','), elapsed // 60, eta)


def readable(symbol):
    """MSVC decorated name -> Namespace::Class::method (enough for labels; full name stays in 'symbol')."""
    m = re.match(r"\?\?([01])([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)*)@", symbol)
    if m:
        scope = [m[2]] + [p for p in m[3].split("@") if p]
        cls = "::".join(reversed(scope))
        return "%s::%s%s" % (cls, "~" if m[1] == "1" else "", m[2])
    m = re.match(r"\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)+)@", symbol)
    if m:
        return "::".join(list(reversed([p for p in m[2].split("@") if p])) + [m[1]])
    return symbol


def owned_inventory(root, extra_reports=()):
    """Unique compiled owners, including explicitly published unaccepted candidates."""
    rows = {}
    paths = sorted((root / 'rebuild' / CLIENT / 'out').glob('*/report.json'))
    paths += [root / 'work/integration/owned-candidates.json',
              root / 'local/findings/2008-06/verification/owned-candidates.json']
    paths += list(extra_reports)
    for path in paths:
        if not path.exists():
            continue
        data = json.loads(path.read_text(encoding='utf-8'))
        for report in data.get('reports', [data]):
            module = report.get('module', path.parent.name)
            if module.casefold() == 'codegenanalogs':
                continue
            for address in report.get('owned_addrs', []):
                if re.fullmatch('[0-9a-f]{8}', address):
                    rows.setdefault(address, {'module': module})
    return rows


def coverage(root, scores, native, owned=None):
    """Website and webhook share the same code-only function/byte denominator."""
    owned = owned_inventory(root) if owned is None else owned
    groups = {key: {"functions": 0, "bytes": 0} for key in ("integrated", "owned_waiting", "exact_waiting", "partial", "unmined")}
    functions = {}
    for line in (root / "work" / CLIENT / "functions.jsonl").read_text().splitlines():
        if not line.strip():
            continue
        f = json.loads(line)
        if f.get("kind", "code") != "code":
            continue
        functions[f["addr"]] = f
        score = scores.get(f["addr"], 0)
        key = "integrated" if f["addr"] in native else "owned_waiting" if f["addr"] in owned else "exact_waiting" if score == 100 else "partial" if score else "unmined"
        groups[key]["functions"] += 1
        groups[key]["bytes"] += f["size"]
    return groups, functions


def inactive_code(root):
    """addr -> [symbol, exact, receipt] from inactive native trial receipts (code exists, not integrated)."""
    found = {}
    def walk(node, name, stamp):
        if isinstance(node, dict):
            addr = node.get("address") or node.get("original_address")
            symbol = node.get("symbol") or node.get("source_symbol")
            exact = node.get("relocation_normalized_exact", node.get("exact"))
            # Native runner checks use addr/status, not address/exact. Byte-only
            # equality is insufficient when the same check reports data errors.
            if 'addr' in node and 'status' in node and 'target_size' in node:
                addr = node['addr']
                exact = (node['status'] == 'exact' and node.get('score') == 100
                         and 'data_errors' in node and not node['data_errors']
                         and node.get('object_size') == node['target_size'])
            if isinstance(addr, str) and isinstance(symbol, str) and isinstance(exact, bool):
                addr = addr.lower().removeprefix("0x").zfill(8)
                old = found.get(addr)
                # exact beats not-exact; otherwise the newest receipt wins
                if not old or (exact, stamp) > (old[1], old[3]):
                    found[addr] = [symbol, exact, name, stamp]
            for value in node.values():
                walk(value, name, stamp)
        elif isinstance(node, list):
            for value in node:
                walk(value, name, stamp)
    for path in (root / "work" / CLIENT / "shared-layouts").glob("*.json"):
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
            walk(data, path.name, path.stat().st_mtime)
            # single-function trial receipt with no exact verdict: native code exists, unproven
            if isinstance(data, dict) and isinstance(data.get("address"), str) and (
                    "inputs" in data or "source_sha256" in data):
                found.setdefault(data["address"].lower().removeprefix("0x").zfill(8),
                                 [path.stem, False, path.name, 0])
        except (ValueError, OSError):
            continue
    # Owner integrations land in work/workspace without touching this checkout.
    # Read immutable committed receipts too; never extract over workers' files.
    ref = None
    for candidate in ('refs/remotes/findings/work', 'refs/forks/origin/work'):
        result = subprocess.run(['git', 'rev-parse', '--verify', candidate + '^{commit}'],
                                cwd=root, capture_output=True)
        if result.returncode == 0:
            tip = result.stdout.decode().strip()
            if ref is None or subprocess.run(['git', 'merge-base', '--is-ancestor', ref, tip],
                                            cwd=root, capture_output=True).returncode == 0:
                ref = tip
    if ref:
        prefix = 'workspace/work/' + CLIENT + '/shared-layouts/'
        rows = subprocess.check_output(['git', 'ls-tree', '-r', '-z', ref, '--', prefix], cwd=root).split(b'\0')
        entries = []
        for row in rows:
            if row:
                meta, path = row.split(b'\t')
                mode, kind, blob = meta.split()
                if mode in (b'100644', b'100755') and kind == b'blob' and path.endswith(b'.json'):
                    entries.append((path.decode()[len(prefix):], blob))
        result = subprocess.run(['git', 'cat-file', '--batch'], cwd=root,
                                input=b'\n'.join(blob for _, blob in entries) + b'\n',
                                capture_output=True, check=True)
        stream = io.BytesIO(result.stdout)
        stamp = int(subprocess.check_output(['git', 'show', '-s', '--format=%ct', ref], cwd=root))
        for name, blob in entries:
            header = stream.readline().split()
            if len(header) != 3 or header[0] != blob or header[1] != b'blob':
                raise ValueError('Committed native receipt identity mismatch')
            content = stream.read(int(header[2])); stream.read(1)
            try:
                walk(json.loads(content), name, stamp)
            except (ValueError, UnicodeError):
                continue
    # native source with an address-named method but no receipt yet (e.g. CRobloxDoc::handle_453c30)
    for path in sorted((root / "rebuild" / CLIENT).glob("*/*.cpp")):
        text = path.read_text(encoding="utf-8", errors="replace")
        for cls, addr in re.findall(r"\b(\w+)::handle_([0-9a-f]{6,8})\b", text):
            found.setdefault(addr.zfill(8), ["%s::handle_%s" % (cls, addr), False, path.relative_to(root).as_posix(), 0])
    return {a: [readable(v[0]) if v[0].startswith("?") else v[0]] + v[1:3] for a, v in sorted(found.items())}


def inactive_sources(root, inactive, published=None):
    """Link only source files whose bytes are present in the maintained work tree."""
    if published is None:
        result = subprocess.run(['git', 'ls-tree', '-r', '-z', 'refs/remotes/findings/work',
                                 '--', 'workspace/rebuild/2008-06'], cwd=root, capture_output=True)
        published = {}
        if result.returncode == 0:
            for row in result.stdout.split(b'\0'):
                if row:
                    meta, path = row.split(b'\t', 1)
                    published[path.decode().removeprefix('workspace/')] = meta.split()[2].decode()
    links, receipts, texts = {}, {}, {}
    for addr, row in inactive.items():
        receipt = row[2]
        if receipt not in receipts:
            path = root / 'work' / CLIENT / 'shared-layouts' / receipt
            try:
                receipts[receipt] = path.read_text(encoding='utf-8')
            except OSError:
                receipts[receipt] = ''
        candidates = set()
        # Receipt JSON uses both Windows and POSIX paths. Never invent a URL from a basename.
        for value in re.findall(r'"([^"\n]*\.cpp)"', receipts[receipt]) + [receipt]:
            path = value.replace('\\\\', '/').replace('\\', '/')
            prefix = root.as_posix().rstrip('/') + '/'
            if path.casefold().startswith(prefix.casefold()):
                path = path[len(prefix):]
            if path in published:
                candidates.add(path)
        usable = []
        method = '::'.join(row[0].split('::')[-2:])
        for path in sorted(candidates):
            if path not in texts:
                try:
                    body = (root / path).read_bytes()
                    blob = hashlib.sha1(b'blob ' + str(len(body)).encode() + b'\0' + body).hexdigest()
                    normalized = body.replace(b'\r\n', b'\n')
                    normalized_blob = hashlib.sha1(b'blob ' + str(len(normalized)).encode() + b'\0' + normalized).hexdigest()
                    texts[path] = body.decode('utf-8', errors='replace') if published[path] in (blob, normalized_blob) else ''
                except OSError:
                    texts[path] = ''
            text = texts[path]
            if not text:
                continue
            lines = [n for n, line in enumerate(text.splitlines(), 1)
                     if method + '(' in line or method + ' (' in line or 'handle_' + addr.lstrip('0') in line]
            if lines or len(candidates) == 1:
                usable.append({'path': 'workspace/' + path, 'line': lines[0] if lines else 1})
        if len(usable) == 1:
            links[addr] = usable[0]
    return links


def link_errors(root):
    """Unresolved-symbol families from linked trial receipts (*blocker-ranking.json): family -> errors."""
    out = {"trials": [], "families": {}}
    for path in sorted((root / "work" / CLIENT / "shared-layouts").glob("*blocker-ranking*.json")):
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (ValueError, OSError):
            continue
        out["trials"].append({"receipt": path.name, "link_exit": data.get("link_exit"),
                              "error_lines": data.get("error_lines"), "revision": str(data.get("receipt_revision", ""))[:10]})
        for row in data.get("ranked", []):
            entry = out["families"].setdefault(row["family"], {"symbols": [], "objects": [], "receipts": []})
            entry["symbols"] = sorted(set(entry["symbols"]) | {s["name"] for s in row.get("symbols", [])})
            entry["objects"] = sorted(set(entry["objects"]) | set(row.get("objects", [])))
            entry["receipts"].append(path.name)
    return out


def commit(root):
    head = root / ".git" / "HEAD"
    try:
        ref = head.read_text().strip()
        return (root / ".git" / ref[5:]).read_text().strip()[:10] if ref.startswith("ref: ") else ref[:10]
    except OSError:
        return ""


def announce_inactive(before, after, log=print):
    """Integration Digest (report only) for addresses that newly became inactive (exact) or draft native code."""
    rows = [(a, v) for a, v in after.items() if a not in before or (v[1] and not before[a][1])]
    if not rows:
        return
    from roc.integration_notify import post_section
    from roc.reports import inline_code
    rows.sort(key=lambda r: (not r[1][1], r[0]))
    lines = ["%s `%s` %s" % ("🟣 inactive" if v[1] else "🩷 draft", a, inline_code(v[0])) for a, v in rows[:12]]
    if len(rows) > 12:
        lines.append("+%d more" % (len(rows) - 12))
    section = {"name": "🟪 New Native Code · inactive (exact) / draft, not integrated",
               "value": "\n".join(lines)[:1024], "inline": False}
    post_section(None, "site", "rebuild", section, background=False)
    log("Integration digest: %d newly inactive/draft" % len(rows))


def build(root=ROOT, log=print, output=None, extra_reports=()):
    out = root / "rebuild" / CLIENT / "out"
    native_path = root / "work/integration/progress-native.json"
    native = set(json.loads(native_path.read_text())["addresses"]) if native_path.exists() else set()
    names_path = out / "native-names.json"
    names = json.loads(names_path.read_text()) if names_path.exists() else {}
    db = sqlite3.connect("file:%s?mode=ro" % (root / "work/server.db").as_posix(), uri=True, timeout=30)
    try:
        scores = dict(db.execute("SELECT addr,score FROM funcs WHERE client=?", (CLIENT,)).fetchall())
        jobs = db.execute("SELECT id,user,model,unit,receipt,updated FROM integration_jobs WHERE state='accepted' "
                          "ORDER BY updated DESC").fetchall()
        leaders = db.execute("SELECT user,model,COUNT(*) FROM integration_credit WHERE client=? GROUP BY user,model "
                             "ORDER BY COUNT(*) DESC", (CLIENT,)).fetchall()
        # agent (Codex/Claude/...) claims: latest per unit; unexpired ones are live work
        now = datetime.now(timezone.utc).timestamp()
        activity, working = {}, {}
        for unit, user, worker, expires, state, addresses in db.execute(
                "SELECT unit,user,worker,expires,state,addresses FROM integration_claims WHERE client=? ORDER BY rowid",
                (CLIENT,)):
            live = expires > now and state == "claimed"
            activity[unit] = ["working" if live else state, user, worker]
            if live:
                for addr in json.loads(addresses or "[]"):
                    working[str(addr).lower().removeprefix("0x").zfill(8)] = [user, worker, unit]
    finally:
        db.close()
    # site's middle bucket: inactive (receipt-exact) or draft native code, not yet integrated
    owned = set(inactive_code(root))
    groups, functions = coverage(root, scores, native, owned)
    units = {job: unit for job, _, _, unit, _, _ in jobs}
    receipts = []
    daily = {}
    seen = set()
    for job, user, model, unit, receipt, updated in jobs:
        r = json.loads(receipt or "{}")
        key = r.get("job", job)
        if key in seen:
            continue
        seen.add(key)
        day = datetime.fromtimestamp(updated, ZoneInfo("America/New_York")).strftime("%Y-%m-%d")
        row = daily.setdefault(day, {"day": day, "gains": 0, "jobs": 0, "models": {}})
        gains = len(r.get("new_distinct", r.get("gains", [])))
        row["gains"] += gains
        row["jobs"] += 1
        series = row["models"].setdefault(model or "Unknown", {"gains": 0, "jobs": 0})
        series["gains"] += gains
        series["jobs"] += 1
        unit = ", ".join(dict.fromkeys(units.get(j, "") for j in r.get("merged_jobs", [job])))
        receipts.append({"job": key[:8], "user": user, "model": model, "units": unit[:120],
                         "gains": len(r.get("gains", [])), "distinct_gains": len(r.get("new_distinct", r.get("gains", []))), "owned_after": r.get("owned_after"),
                         "when": datetime.fromtimestamp(updated, timezone.utc).strftime("%Y-%m-%d %H:%M UTC")})
    shown = {a: names[a] for a in names if a in native or (names[a].get("score") or 0) >= 50}
    links_path = root / 'local/findings/2008-06/verification/native-source-links.json'
    sources = json.loads(links_path.read_text(encoding='utf-8')) if links_path.exists() else {}
    data = {"client": CLIENT, "updated": datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M UTC"),
            "groups": groups,
            "commit": commit(root),
            "link_errors": link_errors(root),
            # unit -> [latest claim state ("working", "released", "parked: reason", ...), user, worker]
            "activity": activity,
            # addr -> [user, worker, unit] for unexpired agent claims
            "working": working,
            "native": sorted(native),
            "owned": sorted(set(owned) & functions.keys()),
            "owned_waiting": sorted((set(owned) & functions.keys()) - native),
            "ownership_note": "Inactive / draft: native code exists (receipt-exact or draft) but is not integrated; link, runtime and server acceptance still pending.",
            # inactive native code: addr -> [decorated symbol, receipt-proven exact, receipt file]
            "inactive": {a: v for a, v in inactive_code(root).items() if a not in native},
            "sources": {a: value for a, value in sources.items() if a in native},
            # addr -> [readable name, decorated symbol, rebuilt score (100 = integrated)]
            "names": {a: [readable(v["symbol"]), v["symbol"], 100 if a in native else v.get("score")] for a, v in sorted(shown.items())},
            "daily": [daily[day] for day in sorted(daily)],
            "jobs": receipts[:100],
            "leaderboard": [{"user": u, "model": m, "native_credits": n} for u, m, n in leaders]}
    data['inactive_sources'] = inactive_sources(root, data['inactive'])
    for key, exact in (("native_inactive", True), ("native_draft", False)):
        hits = [functions[a] for a, v in data["inactive"].items() if v[1] == exact and a in functions]
        # separate from "groups": groups partition the code and are summed by the site
        data.setdefault("native_code", {})[key[7:]] = {"functions": len(hits), "bytes": sum(f["size"] for f in hits)}
    path = output or root / "site/integration.json"
    previous_path = path
    if output is None and not path.exists() and (root / "docs/integration.json").exists():
        previous_path = root / "docs/integration.json"
    previous = json.loads(previous_path.read_text(encoding="utf-8")) if previous_path.exists() else {}
    history = {row["day"]: row for row in previous.get("history", [])} if previous.get("client") == CLIENT else {}
    day = datetime.now(ZoneInfo("America/New_York")).strftime("%Y-%m-%d")
    history[day] = {"day": day, "groups": data["groups"], "native_code": data.get("native_code", {})}
    data["history"] = [history[day] for day in sorted(history)]
    atomic_json(path, data)
    if output is None:
        atomic_json(root / "site/native-source-links.json", {"client": CLIENT, "sources": data["inactive_sources"]})
    if output is None and "inactive" in previous:  # first build has no baseline: don't announce everything
        announce_inactive(previous["inactive"], data["inactive"], log)
    log("Integration site data: %d integrated, %d named" % (len(native), len(data["names"])))
    return data


if __name__ == "__main__":
    build()
