"""Canonical research operations, driven by named recipes in research/recipes.json.

New experiments add a recipe (data), not a script. Two operations cover the compiler-only
campaigns of 2026-10 (Ogre, Boost, RakNet, XTP/MFC library sweeps):

  grid    re-check stored sources of selected targets under builds x flag profiles
  fanout  compile library files / generated units and match every function in the object
          against all unresolved targets (fingerprint fan-out)

Both are resumable (journal keyed by source hash), never call a model, and submit only
exacts the group server re-verifies. Every run appends attempts to the agent memory.
"""
import hashlib
import json
import re
import threading
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
from itertools import islice
from pathlib import Path
from urllib.parse import quote

from roc import clients, draft, fingerprint, libs, matchers, match, worker

ROOT = Path(__file__).resolve().parent.parent
RECIPES_FILE = ROOT / "research" / "recipes.json"
CLIENT = "2008-06"
# Compiler gates: both 2008 builds x the profiles that won before (CLAUDE.md step 3).
BUILDS = (50727, 21022)
PROFILES = ("/O2 /GS- /EHsc /MD", "/O2 /Ob2 /GS- /EHsc /MD", "/O1 /GS- /EHsc /MD", "/Od /Ob0 /GS /EHsc /MD")
ERRORS = (RuntimeError, ValueError, OSError, SystemExit)


def digest(source):
    return hashlib.sha256(source.encode("utf-8")).hexdigest()


class Campaign:
    """Server-verified submission plus an append-only journal under one output folder."""

    def __init__(self, output, server=None):
        self.root = Path(output)
        self.root.mkdir(parents=True, exist_ok=True)
        settings = worker.load_settings()
        self.api = worker.Api(server or settings["server"], settings.get("token"))
        self.user = settings["user"]
        self.info = self.api.call("/v1/info")
        # 2009-12 is registered for provenance, excluded from all mining.
        self.info["clients"].pop("2009-12", None)
        for client, remote in self.info["clients"].items():
            if clients.load().get(client, {}).get("sha256") != remote["sha256"]:
                raise ValueError("Client registry differs: " + client)

    def record(self, stage, row):
        with (self.root / (stage + ".jsonl")).open("a", encoding="utf-8") as stream:
            stream.write(json.dumps(row) + "\n")

    def previous(self, stage):
        path = self.root / (stage + ".jsonl")
        if not path.exists():
            return []
        rows = []
        for line in path.read_text(encoding="utf-8").splitlines():
            try:
                rows.append(json.loads(line))
            except ValueError:  # a run killed mid-write leaves one torn line
                continue
        return rows

    def current(self, client, addr):
        if client not in self.info["clients"]:
            raise ValueError("Client excluded from experiments: " + client)
        return self.api.call("/v1/source?client=%s&addr=%s" % (quote(client), addr))

    def submit_exact(self, stage, client, addr, source, flags=None):
        if client not in self.info["clients"]:
            raise ValueError("Client excluded from experiments: " + client)
        score, symbol, diff, spans = match.check_text(client, addr, source, flags)
        result = {"client": client, "addr": addr, "score": score,
                  "symbol": symbol, "source_sha256": digest(source)}
        if score != 100:
            result["diff"] = diff[:500]
            return result
        folder = self.root / "candidates" / stage / client
        folder.mkdir(parents=True, exist_ok=True)
        if flags and "flags" not in match.directives(source):
            source = "// roc-flags: %s\n%s" % (flags, source)
        path = folder / (addr + ".cpp")
        path.write_text(source, encoding="utf-8")
        result["candidate_path"] = str(path)
        result["source_sha256"] = digest(source)
        current = self.current(client, addr)
        result["server_before"] = current["score"]
        if current["score"] == 100:
            result["already_exact"] = True
            return result
        if client not in self.info["verify"]:
            result["not_submitted"] = "server cannot verify this client"
            return result
        response = self.api.call("/v1/submit", {
            "user": self.user, "client": client, "addr": addr, "score": 100,
            "source": source, "model": "roc " + stage}, timeout=120)
        result["submission"] = response
        if not response["verified"] or response["score"] != 100:
            raise ValueError("Server failed exact verification: %s %s" % (client, addr))
        return result

    def snapshot(self):
        out = {}
        for client in self.info["clients"]:
            path = self.root / ("sources-" + client + ".json")
            if not path.exists():
                rows = self.api.call("/v1/sources?client=" + client, timeout=120)
                path.write_text(json.dumps(rows), encoding="utf-8")
            out[client] = {r["addr"]: r for r in json.loads(path.read_text(encoding="utf-8"))}
        return out


# ---------- reusable operations ----------

def strip_settings(source):
    return re.sub(r"(?m)^// roc-(cl|flags):[^\n]*\n", "", source)


def variants(source, builds=BUILDS, profiles=PROFILES, append=("",), client=CLIENT):
    """(source, build, flags) for each compiler gate. Profile "keep" reuses the source's flags."""
    body = strip_settings(source)
    kept = match.directives(source).get("flags") or clients.load()[client].get("flags") or match.DEFAULT_FLAGS
    for build in builds:
        for profile in profiles:
            for suffix in append:
                flags = ((kept if profile == "keep" else profile) + suffix).strip()
                yield "// roc-cl: %s\n// roc-flags: %s\n%s" % (build, flags, body), build, flags


def unresolved(client, scores):
    """Fingerprint target holding only code functions that are not exact yet."""
    target = fingerprint.Target(client)
    target.index = defaultdict(list)
    for addr, function in match._functions(client).items():
        if function.get("kind", "code") == "code" and scores.get(addr, 0) < 100:
            target.index[function["size"]].append(addr)
    return target


def select(rows, spec, client=CLIENT):
    """Server source rows narrowed by a recipe's `targets` spec."""
    functions = match._functions(client)
    low, high = spec.get("scores", [90, 99])
    small, large = spec.get("sizes", [0, 1 << 20])
    addresses = set(spec.get("addresses", ()))
    unit = re.compile(spec["unit"]) if spec.get("unit") else None
    lib = re.compile(spec["lib"]) if spec.get("lib") else None
    chosen = []
    for row in rows:
        function = functions.get(row["addr"])
        if not function or not row.get("source") or (addresses and row["addr"] not in addresses):
            continue
        if not low <= row["score"] <= high or not small <= function["size"] <= large:
            continue
        if unit and not unit.search(function.get("unit") or ""):
            continue
        if lib and not lib.search(match.directives(row["source"]).get("lib", "")):
            continue
        chosen.append(dict(row, size=function["size"], unit=function.get("unit")))
    return sorted(chosen, key=lambda r: (-r["score"], r["size"], r["addr"]))[:spec.get("limit", 10 ** 6)]


def grid(campaign, stage, rows, builds=BUILDS, profiles=PROFILES, append=("",), client=CLIENT, log=print):
    """Compiler gates per target; stop a target at its first exact. Returns winners."""
    done = {(r["addr"], r["source_sha256"]) for r in campaign.previous(stage) if r.get("source_sha256")}
    winners = []
    for row in rows:
        for source, build, flags in variants(row["source"], builds, profiles, append):
            key = digest(source)
            if (row["addr"], key) in done:
                continue
            result = dict(addr=row["addr"], source_sha256=key, build=build, flags=flags, before=row["score"])
            try:
                score, symbol, diff, _ = match.check_text(client, row["addr"], source)
                result.update(score=score, symbol=symbol, diff=diff[:2000])
                if score == 100:
                    result["receipt"] = campaign.submit_exact(stage, client, row["addr"], source)
                    winners.append(result)
            except ERRORS as error:
                result["error"] = str(error)[-2000:]
            campaign.record(stage, result)
            log("%s %s %s %s %s" % (stage, row["addr"], build, flags, result.get("score", "error")))
            if result.get("score") == 100:
                break
    return winners


def fanout(campaign, stage, clients, jobs=1, client=CLIENT, log=print):
    """Compile (source, evidence) pairs with bounded prefetch; submit every exact hit."""
    scores = {r["addr"]: r["score"] for r in campaign.api.call("/v1/sources?client=" + client, timeout=300)}
    target = unresolved(client, scores)
    done = {r["key"] for r in campaign.previous(stage) if "error" not in r}
    pending = ((s, e) for s, e in clients if digest(s) not in done)

    def compiled():  # bound object memory; matching and journal writes keep one owner
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            queue = [(item, pool.submit(match.compile_text, client, item[0])) for item in islice(pending, jobs)]
            while queue:
                item, future = queue.pop(0)
                try:
                    obj, error = future.result(), None
                except ERRORS as failure:
                    obj, error = None, failure
                following = next(pending, None)
                if following:
                    queue.append((following, pool.submit(match.compile_text, client, following[0])))
                yield (*item, obj, error)

    winners = []
    for source, evidence, obj, failure in compiled():
        row = {"key": digest(source), "source": source, "evidence": evidence, "winners": []}
        try:
            if failure:
                raise failure
            hits = target.match_obj(obj, source)
            row["local_exact_hits"] = len(hits)
            for addr, (_, symbol, *_) in sorted(hits.items()):
                result = campaign.submit_exact(stage, client, addr, source)
                result["symbol"] = symbol
                row["winners"].append(result)
                winners.append(result)
        except ERRORS as error:
            row["error"] = str(error)[-2000:]
        campaign.record(stage, row)
        log("%s %s local exact %d new %d %s" % (stage, evidence, len(row["winners"]),
            sum(bool(w.get("submission", {}).get("improved")) for w in row["winners"]), row.get("error", "")[-160:]))
    return winners


def recipe_sources(spec):
    """(source, evidence) pairs for a fan-out recipe's `sources` list."""
    for item in spec:
        name = item["recipe"]
        r = libs.RECIPES[name]
        builds = item.get("builds") or r.get("builds") or [21022]
        grid_flags = item.get("flags") or r.get("grid", libs.GRID)
        if "unit" in item:  # agent-written unit kept portable via the findings repo
            files = [libs.add_unit(name, (ROOT / item["unit"]).read_text(encoding="utf-8"),
                                   item.get("prefix", "roc_unit_"))]
        else:
            folder = libs.fetch(name)
            pattern = item.get("files")
            files = libs.files_of(dict(r, files=pattern) if isinstance(pattern, str) else r, folder) \
                if not isinstance(pattern, list) else pattern
            if item.get("match"):
                files = [f for f in files if re.search(item["match"], f.replace("\\", "/"))]
        for file in files:
            for build in builds:
                for flags in grid_flags:
                    for lang in item.get("langs") or r.get("langs", ["cpp"]):
                        yield (libs.source_for(name, file, lang, build, flags),
                               {"recipe": name, "file": file, "build": build, "flags": flags})


# ---------- recipes ----------

def recipes():
    return json.loads(RECIPES_FILE.read_text(encoding="utf-8"))


def plan(name):
    """What a recipe would do, without a server or compiler: counts only."""
    spec = recipes()[name]
    if spec["op"] == "fanout":
        return {"op": "fanout", "sources": sum(1 for _ in recipe_sources(spec["sources"]))}
    gates = len(spec.get("builds", BUILDS)) * len(spec.get("profiles", PROFILES)) * len(spec.get("append", [""]))
    return {"op": "grid", "gates_per_target": gates, "targets": spec.get("targets", {})}


def run(name, server=None, jobs=1, limit=None, log=print):
    """Run one named recipe. Returns a summary; also journaled as agent memory."""
    spec = recipes()[name]
    if spec.get("client", CLIENT) != CLIENT:
        raise ValueError("Research recipes are limited to " + CLIENT)
    campaign = Campaign(spec.get("output") or ROOT / "work" / "research" / name, server)
    try:
        if spec["op"] == "grid":
            rows = select(campaign.api.call("/v1/sources?client=" + CLIENT, timeout=300), spec.get("targets", {}))
            rows = rows[:limit] if limit else rows
            winners = grid(campaign, name, rows, spec.get("builds", BUILDS), spec.get("profiles", PROFILES),
                           spec.get("append", [""]), log=log)
            tried = len(rows)
        elif spec["op"] == "fanout":
            sources = list(islice(recipe_sources(spec["sources"]), limit))
            winners = fanout(campaign, name, clients, jobs, log=log)
            tried = len(clients)
        else:
            raise ValueError("Unknown research op: " + spec["op"])
    finally:
        campaign.api.close()
    new = [w for w in winners if w.get("submission", {}).get("improved") or
           w.get("receipt", {}).get("submission", {}).get("improved")]
    summary = {"recipe": name, "op": spec["op"], "tried": tried, "local_exact": len(winners), "new_verified": len(new)}
    remember(spec, name, summary, new, campaign.root)
    log("TOTAL %s" % json.dumps(summary))
    return summary


def remember(spec, name, summary, new, evidence):
    """One run record plus one verified trial per new exact, in the agent attempt journal."""
    now = datetime.now(timezone.utc).isoformat()
    rows = [dict(kind="research_run", date=now, client=CLIENT, library=spec.get("library"), recipe=name,
                 hypothesis=spec.get("hypothesis"), change=spec.get("change"), addresses=[],
                 outcome="improved" if new else "no_gain", exacts_gained=len(new), evidence=str(evidence),
                 next=spec.get("next"), **{k: summary[k] for k in ("tried", "local_exact")})]
    for win in new:
        result = win.get("receipt", win)
        rows.append(dict(kind="trial", date=now, client=CLIENT, library=spec.get("library"), recipe=name,
                         addresses=[result["addr"]], hypothesis=spec.get("hypothesis"),
                         source_hash=result.get("source_sha256"), after=100, exacts_gained=1,
                         outcome="server_verified", receipt=result.get("submission"), evidence=str(evidence)))
    path = ROOT / "work" / "agent-memory" / "attempts.jsonl"
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as stream:
        stream.writelines(json.dumps(row) + "\n" for row in rows)


def audit(directory, client=CLIENT):
    """Read-only receipt audit of one campaign folder: unique server-verified new exacts.
    Counts only receipts with verified + improved + score 100; journals stay untouched."""
    from collections import Counter
    winners, errors, rows = {}, Counter(), Counter()
    for path in sorted(Path(directory).glob("*.jsonl")):
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            try:
                record = json.loads(line)
            except ValueError:
                continue
            if not isinstance(record, dict):
                continue
            rows[path.name] += 1
            errors[path.name] += bool(record.get("error"))
            candidates = [record, *record.get("winners", [])]
            if isinstance(record.get("receipt"), dict):
                candidates.append(record["receipt"])
            for item in candidates:
                receipt = item.get("submission") or {}
                # Older journals omit client; explicit other clients stay excluded.
                if (item.get("client", client) == client and item.get("addr") and receipt.get("verified")
                        and receipt.get("improved") and receipt.get("score") == 100):
                    winners.setdefault(item["addr"], {"journal": path.name, "before": item.get("server_before"),
                                                     "source_hash": item.get("source_sha256")})
    return {"unique_verified_exacts": len(winners), "by_journal": dict(Counter(w["journal"] for w in winners.values())),
            "journal_rows": dict(rows), "error_rows": dict(errors), "winners": winners}


# ---------- agent operations (reused by the automatic worker and by `roc agent-check`) ----------

WRITE_LOCK = threading.Lock()


def append(path, row):
    path.parent.mkdir(parents=True, exist_ok=True)
    with WRITE_LOCK, path.open("a", encoding="utf-8") as stream:
        stream.write(json.dumps(row, ensure_ascii=True) + "\n")


def trial(root, client, addr, path, hypothesis):
    """The agent's check command: journal every compile and preserve the best source."""
    path = Path(path).resolve()
    task_path = path.parent / "task.json"
    journal = path.parent
    direct_source = False
    if task_path.exists():
        task = json.loads(task_path.read_text())
        if task["client"] != client or task["addr"] != addr or path.name != addr + ".cpp":
            raise ValueError("Source does not belong to this assigned target")
    elif path == (root / "src" / client / (addr + ".cpp")).resolve():
        # Campaign agents edit checked-in working sources directly.  They still
        # get a per-target journal and best-score rollback, without requiring an
        # obsolete exclusive assignment folder.
        task = {"client": client, "addr": addr, "area": "campaign", "profile": "agent-check",
                "best_score": match.save_score(client, addr, 0)}
        journal = root / "work" / "agent-checks" / client / addr
        journal.mkdir(parents=True, exist_ok=True)
        direct_source = True
    else:
        raise ValueError("Agent checks require src/<client>/<addr>.cpp or an automatic task source")
    text = path.read_text(encoding="utf-8")
    row = {"kind": "trial", "date": datetime.now(timezone.utc).isoformat(), "client": client,
           "addresses": [addr], "area": task["area"], "profile": task["profile"],
           "hypothesis": hypothesis, "source_hash": digest(text), "before": task["best_score"],
           "compiler": match.directives(text).get("cl") or match.clients.load()[client]["compiler_build"],
           "flags": match.directives(text).get("flags") or match.clients.load()[client].get("flags") or match.DEFAULT_FLAGS,
           "evidence": str(journal / "trials.jsonl")}
    try:
        score, symbol, diff, _ = match.check_text(client, addr, text)
        row.update(after=score, symbol=symbol, diff=diff, outcome="improved" if score > task["best_score"] else "no_gain")
        if score > task["best_score"]:
            (journal / "best.cpp").write_text(text, encoding="utf-8")
            task["best_score"] = score
            match.save_score(client, addr, score)
            if task_path.exists():
                task_path.write_text(json.dumps(task))
        elif direct_source and (journal / "best.cpp").exists():
            path.write_text((journal / "best.cpp").read_text(encoding="utf-8"), encoding="utf-8")
    except match.CompileError as error:
        row.update(after=0, outcome="compile_failed", error=str(error))
    append(journal / "trials.jsonl", row)
    append(root / "work" / "agent-memory" / "attempts.jsonl", row)
    return row


# Free compiler gates tried on each near-miss before any paid repair (CLAUDE.md step 3).
GATES = ("keep", "/O2 /GS- /EHsc /MD", "/O1 /GS- /EHsc /MD")


def known_failures(records):
    """(addr, source hash) pairs already compiled without gain, on any PC."""
    return {(addr, r["source_hash"]) for r in records if r.get("kind") == "trial" and r.get("source_hash")
            and r.get("outcome") in ("no_gain", "compile_failed") for addr in r.get("addresses") or ()}


def reuse(root, task, portfolio, tried=frozenset()):
    """Donor verification and normal target checks decide; shape alone never accepts."""
    client = task.get("client", CLIENT)
    source_path = Path(task["path"])
    asm = None
    for donor in task["donors"]:
        try:
            if match.check_text(client, donor["addr"], donor["source"])[0] != 100:
                continue
            if asm is None:
                code, _, _ = match.target(client, task["addr"])
                asm = match.disasm(code, int(task["addr"], 16))
            body = matchers.family_propagate(asm, draft.clean_repair_context(donor["source"]))
            if body:
                portfolio.append("".join("// roc-%s: %s\n" % pair for pair in match.directives(donor["source"]).items()) + body)
            portfolio.append(donor["source"])
        except match.CompileError:
            continue
    if task["before"] >= 90:
        portfolio += [source for source, _, _ in variants(task["source"], profiles=GATES, client=client,
            builds=BUILDS if client == CLIENT else (clients.load()[client]["compiler_build"],))]
    seen = {digest(task["source"])}
    for source in portfolio:
        key = digest(source)
        if key in seen or (task["addr"], key) in tried:
            continue
        seen.add(key)
        source_path.write_text(source, encoding="utf-8")
        result = trial(root, client, task["addr"], source_path, "verified donor / existing recipe reuse")
        if result["after"] == 100:
            break
    source_path.write_text((source_path.parent / "best.cpp").read_text(encoding="utf-8"), encoding="utf-8")


LOG = ROOT / "research" / "log.jsonl"


def note(title, text, date=None, path=None):
    """Append one dated campaign entry to the findings log (research/log.jsonl): what was
    tried, exacts gained, rejected variants, next step. One JSON object per line."""
    row = {"date": date or datetime.now(timezone.utc).date().isoformat(), "title": title, "text": text}
    append(path or LOG, row)
    return row


def log_entries(limit=None):
    """Newest-last list of log entries (torn trailing lines are ignored)."""
    path = LOG
    rows = []
    if path.exists():
        for line in path.read_text(encoding="utf-8").splitlines():
            try:
                rows.append(json.loads(line))
            except ValueError:
                continue
    return rows[-limit:] if limit else rows
