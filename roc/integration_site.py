"""docs/integration.json: native integration progress for the website (2008-06 rbxgs rebuild).
Same four groups as the Discord digest: integrated (linked rebuild reproduces it), exact waiting (mined 100%,
not yet integrated), partial, unmined. Per-function data is published on gh-pages only (see server.publish_pages)."""
import hashlib
import json
import posixpath
from pathlib import Path
import re
import sqlite3
import subprocess
from datetime import datetime, timezone
from zoneinfo import ZoneInfo

from roc.integration import CLIENT, ROOT, atomic_json

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


def linked_native_inventory(root):
    addresses = set()
    for path in sorted((root / 'rebuild' / CLIENT / 'out').glob('*/report.json')):
        report = json.loads(path.read_text(encoding='utf-8'))
        if report.get('linked') is not True or report.get('test_exit') != 0:
            continue
        addresses.update(address.lower() for address in report.get('owned_addrs', ())
                         if re.fullmatch('[0-9a-fA-F]{8}', address))
    return addresses


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
            if isinstance(addr, str) and isinstance(symbol, str) and isinstance(exact, bool):
                addr = addr.lower().removeprefix("0x").zfill(8)
                old = found.get(addr)
                # exact beats not-exact; otherwise the newest receipt wins
                if not old or (exact, stamp) > (old[1], old[3]):
                    found[addr] = [symbol, exact, name, stamp, receipt_source]
            for value in node.values():
                walk(value, name, stamp)
        elif isinstance(node, list):
            for value in node:
                walk(value, name, stamp)
    # native source of a trial receipt: the repo file whose hash it records, else the first existing .cpp it names
    by_hash = {}
    for item in (sorted((root / "rebuild" / CLIENT / "native-classes").rglob("*.cpp")) +
                 sorted((root / "rebuild" / CLIENT / "native-world").rglob("*.cpp")) +
                 sorted((root / "rebuild" / CLIENT / "native-headers").rglob("*.h"))):
        by_hash.setdefault(hashlib.sha256(item.read_bytes()).hexdigest(), str(item))
    def source_in(text, data):
        digest = data.get("source_sha256") if isinstance(data, dict) else None
        named = data.get("source_path") if isinstance(data, dict) else None
        if isinstance(named, str) and isinstance(digest, str):
            item = (root / named).resolve()
            if item.is_relative_to(root.resolve()) and item.is_file() and hashlib.sha256(item.read_bytes()).hexdigest() == digest:
                return str(item)
        if isinstance(digest, str) and digest in by_hash:
            return by_hash[digest]
        for named in re.findall(r'"([^"\n]*?\.cpp)"', text):
            item = Path(named.replace("\\\\", "/"))
            item = item if item.is_absolute() else root / item
            if item.is_file():
                return str(item)
        return None
    receipt_source = None
    for path in (root / "work" / CLIENT / "shared-layouts").glob("*.json"):
        try:
            text = path.read_text(encoding="utf-8")
            data = json.loads(text)
            receipt_source = source_in(text, data)
            walk(data, path.name, path.stat().st_mtime)
            # single-function trial receipt with no exact verdict: native code exists, unproven
            if isinstance(data, dict) and isinstance(data.get("address"), str) and (
                    "inputs" in data or "source_sha256" in data):
                found.setdefault(data["address"].lower().removeprefix("0x").zfill(8),
                                 [path.stem, False, path.name, 0, receipt_source])
        except (ValueError, OSError):
            continue
    # native_bulk proofs (work/native-client/prove.py: full census + per-file runs). Byte-exact rows are inactive
    # (exact); a byte-matched body at one candidate still waiting for identity/reference proof is draft.
    manifests = sorted((root / "work/native-client/prove-out").glob("*/manifest.json"), key=lambda p: p.stat().st_mtime)
    # symbol -> source from single-source (per-file) proofs: names the file for census rows outside any job's checks
    single = {}
    for path in manifests:
        try:
            for family in json.loads(path.read_text(encoding="utf-8")).get("families", []):
                if len(family.get("jobs", [])) == 1:
                    for row in family.get("symbols", []):
                        single[row["symbol"]] = family["jobs"][0]["source"]
        except (ValueError, OSError, KeyError):
            continue
    for path in manifests:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (ValueError, OSError):
            continue
        stamp = path.stat().st_mtime
        for family in data.get("families", []):
            source_of = {(c["addr"], c["symbol"]): job["source"] for job in family.get("jobs", []) for c in job.get("checks", [])}
            for row in family.get("symbols", []):
                exact = row.get("status") == "inactive_exact"
                candidates = row.get("candidates") or []
                if not candidates or row["symbol"].startswith(("__", "$")) or (not exact and len(candidates) != 1):
                    continue
                for addr in candidates:
                    old = found.get(addr)
                    if not old or (exact, stamp) > (old[1], old[3]):
                        found[addr] = [row["symbol"], exact, "native-bulk:" + path.parent.name, stamp,
                                       source_of.get((addr, row["symbol"])) or single.get(row["symbol"])]
    # native source with an address-named method but no receipt yet (e.g. CRobloxDoc::handle_453c30)
    for path in sorted((root / "rebuild" / CLIENT).glob("*/*.cpp")):
        text = path.read_text(encoding="utf-8", errors="replace")
        for cls, addr in re.findall(r"\b(\w+)::handle_([0-9a-f]{6,8})\b", text):
            found.setdefault(addr.zfill(8), ["%s::handle_%s" % (cls, addr), False, path.relative_to(root).as_posix(), 0, str(path)])
    texts = {}

    def located(symbol, source):
        """[repo-relative path, line of the definition (1 if not found)] of the native source, or None."""
        if not source:
            return None
        path = Path(source)
        try:
            rel = path.resolve().relative_to(root.resolve()).as_posix()
        except ValueError:
            return None
        if path not in texts:
            texts[path] = path.read_text(encoding="utf-8", errors="replace").splitlines() if path.is_file() else []
        parts = readable(symbol).split("(")[0].split("::")
        needle = "::".join(parts[-2:]) + "("
        line = next((i + 1 for i, text in enumerate(texts[path]) if needle in text.replace(" (", "(")), 1)
        if line == 1 and path.suffix == ".h":
            line = next((i + 1 for i, text in enumerate(texts[path])
                         if re.search(r"\b" + re.escape(parts[-1]) + r"\s*\(", text)), 1)
        return [rel, line]
    # addr -> [readable symbol, exact, receipt, [native source path, line] or None]
    return {a: [readable(v[0]) if v[0].startswith("?") else v[0]] + v[1:3] + [located(v[0], v[4] if len(v) > 4 else None)]
            for a, v in sorted(found.items())}


WORK = "refs/remotes/origin/work"
WRAPPER = re.compile(r'^\s*(?://[^\n]*\n\s*)*#include "([^"]+\.(?:cpp|c))"\s*$')


def work_blobs(root, paths):
    """{path: text} for workspace paths on the published work branch (one git cat-file call)."""
    paths = sorted(set(paths))
    if not paths:
        return {}
    run = subprocess.run(["git", "cat-file", "--batch"], cwd=root, capture_output=True,
                         input="".join("%s:%s\n" % (WORK, p) for p in paths).encode())
    out, data, at = {}, run.stdout, 0
    for path in paths:
        end = data.index(b"\n", at)
        header = data[at:end].split()
        at = end + 1
        if len(header) == 3 and header[1] == b"blob":
            size = int(header[2])
            out[path] = data[at:at + size].decode("utf-8", errors="replace")
            at += size + 1
    return out


def function_line(text, name):
    parts = name.split("(")[0].split("::")
    needle = "::".join(parts[-2:]) + "("
    return next((i + 1 for i, line in enumerate(text.splitlines()) if needle in line.replace(" (", "(")), 1)


def follow_wrappers(root, links, names):
    """Compatibility units on the work branch (`#include "../WindowsClient/src/X.cpp"`) link their real file."""
    for _ in range(3):  # wrappers of wrappers
        texts = work_blobs(root, [l["path"] for l in links.values()])
        targets = {}
        for path, text in texts.items():
            hit = WRAPPER.match(text) if len(text) < 2000 else None
            if hit:
                targets[path] = posixpath.normpath(posixpath.join(posixpath.dirname(path), hit.group(1)))
        if not targets:
            break
        real = work_blobs(root, targets.values())
        for addr, link in links.items():
            target = targets.get(link["path"])
            if target in real:
                link["path"], link["line"] = target, function_line(real[target], names.get(addr, ""))


def integrated_sources(root, missing, published):
    """{addr: link} for integrated functions: owning object in a linked module -> the source that built it.
    Roblox/OpenRBX trees link to their public repositories at the pinned revision; native layers and repo sources
    link to the work branch. Upstream library trees and mined swaps (already linked) are skipped."""
    from roc import libs, rebuild
    lock = json.loads((root / "research/native-source-lock.json").read_text())
    repos = {"tools/rbxgs/": "https://github.com/RBLXDecomp/RBXGSdecomp/blob/%s/" % lock.get("https://github.com/RBLXDecomp/RBXGSdecomp.git", "master"),
             "tools/openrbx/": "https://github.com/Asphaltian/OpenRBX/blob/%s/" % lock.get("https://github.com/Asphaltian/OpenRBX.git", "main"),
             "work/upstream/OpenRBX/": "https://github.com/Asphaltian/OpenRBX/blob/%s/" % lock.get("https://github.com/Asphaltian/OpenRBX.git", "main")}
    out, texts = {}, {}
    for _, spec in rebuild.live_module_specs(CLIENT):
        folder = root / "rebuild" / CLIENT / "out" / spec["name"]
        owners = folder / "owned-symbols.json"
        report = folder / "report.json"
        if not owners.exists() or not report.exists():
            continue
        choices = json.loads(report.read_text()).get("choices") or {}
        sources = {}
        for layer in spec["layers"]:
            try:
                if layer["mode"] == "recipe":
                    src = libs._case_path(libs.LIBS / libs.RECIPES[layer["recipe"]]["src"])
                    listed = libs.RECIPES[layer["recipe"]].get("files")
                    globs = [] if layer["files"] == "recipe" and isinstance(listed, list) else \
                        (listed if layer["files"] == "recipe" else layer["files"]).split()
                    paths = [src / f for f in listed] if not globs else [p for g in globs for p in src.glob(g)]
                else:
                    paths = [p for g in layer["files"].split() for p in (root / layer["dir"]).glob(g)]
            except (KeyError, OSError):
                continue
            sources["layer-" + layer["name"]] = {p.stem.lower(): p for p in paths}
        for addr, rows in json.loads(owners.read_text()).items():
            if addr not in missing or addr in out:
                continue
            for row in rows:
                obj = row["object"]
                path = sources.get(choices.get(obj) or "", {}).get(Path(obj).stem.lower())
                if path is None:
                    continue
                try:
                    rel = path.resolve().relative_to(root.resolve()).as_posix()
                except ValueError:
                    continue
                name = readable(row["symbol"]) if row["symbol"].startswith("?") else row["symbol"]
                prefix = next((p for p in repos if rel.startswith(p)), None)
                if prefix:
                    if path not in texts:
                        texts[path] = path.read_text(encoding="utf-8", errors="replace")
                    out[addr] = {"url": repos[prefix] + rel[len(prefix):], "line": function_line(texts[path], name)}
                elif rel in published:
                    if path not in texts:
                        texts[path] = path.read_text(encoding="utf-8", errors="replace")
                    out[addr] = {"path": "workspace/" + rel, "line": function_line(texts[path], name)}
                if addr in out:
                    break
    return out


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
    server_native = set(json.loads(native_path.read_text())["addresses"]) if native_path.exists() else set()
    # Isolated linked module reports do not prove selection in the client.
    native = server_native
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
    inactive = inactive_code(root)
    owned = set(inactive)
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
            "server_native": sorted(server_native),
            "owned": sorted(set(owned) & functions.keys()),
            "owned_waiting": sorted((set(owned) & functions.keys()) - native),
            "ownership_note": "Inactive / draft: native code exists (receipt-exact or draft) but is not integrated; link, runtime and server acceptance still pending.",
            # inactive native code: addr -> [decorated symbol, receipt-proven exact, receipt file]
            "inactive": {a: v for a, v in inactive.items() if a not in native},
            "sources": {a: value for a, value in sources.items() if a in native},
            # addr -> [readable name, decorated symbol, rebuilt score (100 = integrated)]
            "names": {a: [readable(v["symbol"]), v["symbol"], 100 if a in native else v.get("score")] for a, v in sorted(shown.items())},
            "daily": [daily[day] for day in sorted(daily)],
            "jobs": receipts[:100],
            "leaderboard": [{"user": u, "model": m, "native_credits": n} for u, m, n in leaders]}
    # addr -> {path, line} on the published work branch (site links these beside the mined source)
    listed = subprocess.run(["git", "ls-tree", "-r", "--name-only", "refs/remotes/origin/work", "--", "workspace/"],
                            cwd=root, capture_output=True, text=True).stdout.splitlines()
    published = {path.removeprefix("workspace/") for path in listed if path}
    data["inactive_sources"] = {a: {"path": "workspace/" + v[3][0], "line": v[3][1]}
                                for a, v in data["inactive"].items() if len(v) > 3 and v[3] and v[3][0] in published}
    follow_wrappers(root, data["inactive_sources"], {a: v[0] for a, v in data["inactive"].items()})
    # integrated functions without an indexed source: the object that owns them in the linked rebuild -> its source
    for addr, link in integrated_sources(root, native - set(data["sources"]), published).items():
        data["sources"][addr] = link
    follow_wrappers(root, {a: s for a, s in data["sources"].items() if "url" not in s},
                    {a: v[0] for a, v in data["names"].items()})
    for key, exact in (("native_inactive", True), ("native_draft", False)):
        hits = [functions[a] for a, v in data["inactive"].items() if v[1] == exact and a in functions]
        # separate from "groups": groups partition the code and are summed by the site
        data.setdefault("native_code", {})[key[7:]] = {"functions": len(hits), "bytes": sum(f["size"] for f in hits)}
    path = output or root / "docs/integration.json"
    previous_path = path if path.exists() else root / "docs/integration.json"
    previous = json.loads(previous_path.read_text(encoding="utf-8")) if previous_path.exists() else {}
    history = {row["day"]: row for row in previous.get("history", [])} if previous.get("client") == CLIENT else {}
    published_path = root / "docs/integration.json"
    if published_path != previous_path and published_path.exists():
        published = json.loads(published_path.read_text(encoding="utf-8"))
        if published.get("client") == CLIENT:
            history.update({row["day"]: row for row in published.get("history", [])})
    day = datetime.now(ZoneInfo("America/New_York")).strftime("%Y-%m-%d")
    history[day] = {"day": day, "groups": data["groups"], "native_code": data.get("native_code", {})}
    data["history"] = [history[day] for day in sorted(history)]
    atomic_json(path, data)
    if output is None and "inactive" in previous:  # first build has no baseline: don't announce everything
        announce_inactive(previous["inactive"], data["inactive"], log)
    log("Integration site data: %d integrated, %d named" % (len(native), len(data["names"])))
    return data


if __name__ == "__main__":
    build()
