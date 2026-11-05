"""Canonical research operations, driven by named recipes in research/recipes.json.

New experiments add a recipe (data), not a script. Operations cover the compiler-only
campaigns of 2026-10 (Ogre, Boost, RakNet, XTP/MFC library sweeps):

  grid    re-check stored sources of selected targets under builds x flag profiles
  fanout  compile library files / generated units and match every function in the object
          against all unresolved targets (fingerprint fan-out)
  sweep   compose client-scoped recipes, then shared compiler gates

All are resumable (journal keyed by source hash), never call a model, and submit only
exacts the group server re-verifies. Every run appends attempts to the agent memory.
"""
import hashlib
import contextlib
import errno
import json
import os
import re
import threading
import time
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor, wait, FIRST_COMPLETED
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


class ResearchJobBusy(RuntimeError):
    pass


@contextlib.contextmanager
def job_lock(path):
    """Nonblocking process lock; crashes release it automatically."""
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a+b") as stream:
        if os.name == "nt":
            import msvcrt
            stream.seek(0)
            try:
                msvcrt.locking(stream.fileno(), msvcrt.LK_NBLCK, 1)
            except OSError as error:
                if error.errno not in (errno.EACCES, errno.EAGAIN, errno.EDEADLK):
                    raise
                raise ResearchJobBusy("Research job already active: " + str(path.parent)) from error
        else:
            import fcntl
            try:
                fcntl.flock(stream, fcntl.LOCK_EX | fcntl.LOCK_NB)
            except BlockingIOError as error:
                raise ResearchJobBusy("Research job already active: " + str(path.parent)) from error
        try:
            yield
        finally:
            if os.name == "nt":
                stream.seek(0)
                msvcrt.locking(stream.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(stream, fcntl.LOCK_UN)


def active_job(folder):
    for path in sorted(folder.glob("*.json"), key=lambda path: path.stat().st_mtime, reverse=True):
        state = job_status(path)
        if state.get("state") in ("running", "starting"):
            return {**state, "state_file": str(path)}
    return None


def job_status(path):
    state = json.loads(path.read_text())
    pid_path = path.with_suffix(".pid")
    if not state.get("pid") and pid_path.exists():
        state["pid"] = int(pid_path.read_text())
    if not state.get("pid") and state.get("launcher_pid"):
        state["pid"] = state["launcher_pid"]
    if state.get("state") not in ("running", "starting") or not state.get("pid"):
        return state
    pid = state["pid"]
    if os.name == "nt":
        import ctypes
        from ctypes import wintypes
        kernel = ctypes.WinDLL("kernel32", use_last_error=True)
        kernel.OpenProcess.restype = wintypes.HANDLE
        kernel.OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
        kernel.GetExitCodeProcess.argtypes = [wintypes.HANDLE, ctypes.POINTER(wintypes.DWORD)]
        kernel.CloseHandle.argtypes = [wintypes.HANDLE]
        handle = kernel.OpenProcess(0x1000, False, pid)
        if handle:
            code = wintypes.DWORD()
            alive = not kernel.GetExitCodeProcess(handle, ctypes.byref(code)) or code.value == 259
            kernel.CloseHandle(handle)
        else:
            alive = ctypes.get_last_error() == 5  # Access denied does not prove exit.
    else:
        try:
            os.kill(pid, 0)
            alive = True
        except ProcessLookupError:
            alive = False
        except PermissionError:
            alive = True
    return state if alive else {**state, "state": "interrupted", "resume": "rerun the same research command"}


class Campaign:
    """Server-verified submission plus an append-only journal under one output folder."""

    def __init__(self, output, server=None, campaign_id=None, client=None):
        self.campaign_id = campaign_id
        self.root = Path(output)
        self.root.mkdir(parents=True, exist_ok=True)
        settings = worker.load_settings()
        self.api = worker.Api(server or settings["server"], settings.get("token"))
        self.user = settings["user"]
        self.info = self.api.call("/v1/info")
        if client:
            if client not in self.info["clients"]:
                raise ValueError("Client unavailable on server: " + client)
            self.info["clients"] = {client: self.info["clients"][client]}
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

    def submit_exact(self, stage, client, addr, source, flags=None, obj=None):
        if client not in self.info["clients"]:
            raise ValueError("Client excluded from experiments: " + client)
        score, symbol, diff, spans = match.check_text(client, addr, source, flags, obj=obj, minimum=99)
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
        if self.campaign_id:
            append(ROOT / "work" / "agent-memory" / "attempts.jsonl",
                   dict(kind="campaign_submission", date=datetime.now(timezone.utc).isoformat(),
                        client=client, addresses=[addr], campaign_id=self.campaign_id,
                        source_hash=digest(source), after=100, receipt=response))
        return result

    def submit_partial(self, stage, client, addr, source, score, path):
        """Submit only a retained improvement; partial receipts never count as exacts."""
        if client not in self.info["clients"] or not 0 < score < 100:
            raise ValueError("Invalid partial submission")
        current = self.current(client, addr)
        result = dict(client=client, addr=addr, score=score, server_before=current["score"],
                      source_sha256=digest(source), candidate_path=str(path))
        if score <= current["score"] or client not in self.info["verify"]:
            return result
        result["submission"] = self.api.call("/v1/submit", dict(user=self.user, client=client,
            addr=addr, score=score, source=source, model="roc " + stage), timeout=120)
        self.record(stage + "-partials", result)
        if result["submission"].get("verified") and result["submission"].get("improved"):
            append(ROOT / "work/agent-memory/attempts.jsonl", dict(kind="trial",
                date=datetime.now(timezone.utc).isoformat(), client=client, addresses=[addr],
                hypothesis="source portfolio/compiler-context improvement", source_hash=digest(source),
                before=current["score"], after=result["submission"]["score"], exacts_gained=0,
                outcome="server_verified", receipt=result["submission"], evidence=str(path.parent)))
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
        seen = set()
        for profile in profiles:
            bases = fingerprint.flag_variants("// roc-lang: cpp\n// roc-cl: %s\n// roc-flags: %s" % (build, kept)) if profile == "context" else [kept if profile == "keep" else profile]
            for base in bases:
                for suffix in append:
                    flags = " ".join([*base.split(), *(flag for flag in suffix.split() if flag not in base.split())])
                    if flags in seen:
                        continue
                    seen.add(flags)
                    yield "// roc-cl: %s\n// roc-flags: %s\n%s" % (build, flags, body), build, flags


def unresolved(client, scores, targets=None):
    """Fingerprint target holding only code functions that are not exact yet."""
    target = fingerprint.Target(client)
    target.index = defaultdict(list)
    targets = targets or {}
    low, high = targets.get("scores", [0, 99])
    small, large = targets.get("sizes", [0, 1 << 30])
    addresses = set(targets.get("addresses", []))
    unit = re.compile(targets["unit"]) if targets.get("unit") else None
    for addr, function in match._functions(client).items():
        if (function.get("kind", "code") == "code" and low <= scores.get(addr, 0) <= min(high, 99)
                and small <= function["size"] <= large and (not addresses or addr in addresses)
                and (unit is None or unit.search(function.get("unit", "")))):
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
        if (not function or function.get("kind", "code") != "code" or not row.get("source")
                or (addresses and row["addr"] not in addresses)):
            continue
        if not low <= row["score"] <= min(high, 99) or not small <= function["size"] <= large:
            continue
        if unit and not unit.search(function.get("unit") or ""):
            continue
        if lib and not lib.search(match.directives(row["source"]).get("lib", "")):
            continue
        chosen.append(dict(row, size=function["size"], unit=function.get("unit")))
    return sorted(chosen, key=lambda r: (-r["score"], r["size"], r["addr"]))[:spec.get("limit", 10 ** 6)]


def grid_rows(campaign, spec, client, coverage=None, limit=None):
    """Optional client-scoped starter files are trial inputs, never stored sources."""
    rows = campaign.api.call("/v1/sources?client=" + client, timeout=300)
    if coverage is not None:
        sources = {row["addr"]: row for row in rows}
        unresolved_rows = [sources.get(addr, {}) for addr, function in match._functions(client).items()
                           if function.get("kind", "code") == "code" and sources.get(addr, {}).get("score", 0) < 100]
        coverage.update(unresolved_code=len(unresolved_rows),
                        without_source=sum(not row.get("source") for row in unresolved_rows))
    seeds = spec.get("seed_sources", {}).get(client, {})
    if seeds:
        functions = match._functions(client)
        by_addr = {row["addr"]: row for row in rows}
        for addr, candidate in seeds.items():
            function = functions.get(addr)
            if not function or function.get("kind", "code") != "code":
                continue
            current = campaign.current(client, addr)
            if current["score"] == 100:
                continue
            path = (ROOT / candidate).resolve()
            if not path.is_relative_to(ROOT.resolve()) or path.suffix.lower() != ".cpp":
                raise ValueError("Research seed must be a workspace C++ file: " + candidate)
            by_addr[addr] = dict(current, addr=addr, source=path.read_text(encoding="utf-8"))
        rows = list(by_addr.values())
    if spec.get("portfolio"):
        from roc import brute
        rows = brute.portfolios(ROOT, client, rows, match._functions(client), recipes(), {**spec["portfolio"], "target_limit": limit})
        if coverage is not None:
            coverage["portfolio_targets"] = len(rows)
            coverage["source_candidates"] = sum(1 + len(row["candidates"]) for row in rows)
            coverage["candidates_omitted"] = sum(row["candidates_available"] - 1 - len(row["candidates"]) for row in rows)
    return select(rows, spec.get("targets", {}), client=client)


def compiler_evidence(client, row, source, build, flags, units):
    """A gate changes identity when source dependencies, target extent or settings change."""
    directives = match.directives(source)
    if "lib" in directives:
        recipe, _, path = directives["lib"].partition(" ")
        key = (recipe, path.strip(), build)
        if key not in units:
            units[key] = digest(libs.unit(recipe, path.strip(), build))
        body = units[key]
        # Preserve raw additions outside a metadata-only wrapper.
        extra = "\n".join(line for line in source.splitlines() if line.strip() and not line.lstrip().startswith("//"))
        body += digest(extra)
    else:
        body = digest(strip_settings(source))
    code, relocs, _ = match.target(client, row["addr"])
    return digest(json.dumps([client, clients.load()[client]["sha256"], row["addr"],
                             code.hex(), relocs, body, build, flags, directives.get("lang")]))


def grid(campaign, stage, rows, builds=BUILDS, profiles=PROFILES, suffixes=("",), client=CLIENT, log=print,
         keep_partials=False, jobs=1, reuse_history=False, stats=None, improvement_only=False, preserve_inputs=False, submit_partials=False, reuse_objects=False):
    """Parallel targets, sequential gates; serialize verification and journal writes."""
    started = time.monotonic()
    stats = stats if stats is not None else {}
    stats.update(checks=0, skipped=0, errors=0, finished_targets=0, verified_exacts=0, verified_partial_gains=0, object_reuses=0)
    history = campaign.previous(stage)
    done = {(r["addr"], r["source_sha256"]) for r in history if r.get("source_sha256")}
    winners = []
    lock = threading.Lock()
    units = {}
    blocked_native = set()
    trial_path = ROOT / "work" / "agent-memory" / "compiler-trials.jsonl"
    previous_trials = [r for r in journal_records(trial_path)
                       if r.get("client") == client and r.get("terminal") and r.get("evidence_key")] if reuse_history else []
    completed = {r["evidence_key"] for r in previous_trials}
    bounds = {}
    for trial in previous_trials:
        key = trial.get("base_evidence_key", trial["evidence_key"])
        ceiling = trial.get("score") if trial.get("score") is not None else trial.get("score_ceiling")
        if ceiling is not None:
            bounds[key] = min(bounds.get(key, 100), ceiling)

    def progress(state, **fields):
        path = campaign.root / "progress.json"
        temporary = path.with_suffix(".tmp")
        temporary.write_text(json.dumps(dict(client=client, stage=stage, state=state,
                             targets=len(rows), **stats, **fields)))
        try:
            os.replace(temporary, path)
        except PermissionError:
            # Windows readers can briefly deny replacement; the next target refreshes it.
            # Progress is advisory and must not abort verification or trial journals.
            pass

    def target(row):
        best = row["score"]
        objects = {}
        path = None
        if keep_partials:
            path = campaign.root / "candidates" / stage / client / (row["addr"] + ".cpp")
            if path.exists():
                kept_source = path.read_text(encoding="utf-8")
                kept_hash = digest(kept_source)
                matching = [r for r in history if r.get("addr") == row["addr"] and
                            r.get("source_sha256") == kept_hash and r.get("score") is not None]
                if reuse_history:
                    directives = match.directives(kept_source)
                    build = int(directives.get("cl") or clients.load()[client]["compiler_build"])
                    flags = directives.get("flags") or clients.load()[client].get("flags") or match.DEFAULT_FLAGS
                    try:
                        evidence = compiler_evidence(client, row, kept_source, build, flags, units)
                        matching = [r for r in matching if r.get("base_evidence_key", r.get("evidence_key")) == evidence]
                    except ERRORS:
                        matching = []
                best = max([best] + [r["score"] for r in matching])
        candidates = [dict(source=row["source"], origin=row.get("source_origin", "stored")), *row.get("candidates", [])]
        if preserve_inputs:
            with lock:
                folder = campaign.root / "inputs"
                folder.mkdir(exist_ok=True)
                for candidate in candidates:
                    snapshot = folder / (digest(candidate["source"]) + ".cpp")
                    if not snapshot.exists():
                        snapshot.write_text(candidate["source"], encoding="utf-8")
                    candidate["input_path"] = str(snapshot)
        for source, build, flags, origin, input_path in ((*gate, candidate.get("origin", "candidate"), candidate.get("input_path"))
                for candidate in candidates
                for gate in variants(candidate["source"], builds, profiles, suffixes, client=client)):
            key = digest(source)
            if not reuse_history and (row["addr"], key) in done:
                continue
            result = dict(addr=row["addr"], source_sha256=key, build=build, flags=flags, before=row["score"], client=client, origin=origin, input_path=input_path)
            try:
                if reuse_history:
                    result["evidence_key"] = compiler_evidence(client, row, source, build, flags, units)
                    if improvement_only:
                        result["base_evidence_key"] = result["evidence_key"]
                        if bounds.get(result["evidence_key"], 100) <= best:
                            with lock:
                                stats["skipped"] += 1
                            continue
                        result["evidence_key"] = digest(result["evidence_key"] + ":floor:" + str(best))
                    if result["evidence_key"] in completed:
                        with lock:
                            stats["skipped"] += 1
                        continue
                native_key = None
                directives = match.directives(source)
                if reuse_history and "lib" in directives:
                    recipe, _, file = directives["lib"].partition(" ")
                    native_key = (build, units.get((recipe, file.strip(), build)))
                    if native_key in blocked_native:
                        with lock:
                            stats["skipped"] += 1
                        continue
                options = {"minimum": best} if improvement_only else {}
                object_key = None
                if reuse_objects:
                    obj = match.compile_text(client, source)
                    # Standard i386 COFF timestamp is not code, data or relocation evidence.
                    object_key = hashlib.sha256(obj[:4] + obj[8:]).hexdigest()
                    options["obj"] = obj
                if object_key is not None and objects.get(object_key, 100) <= best:
                    score, symbol, diff = None, None, "identical compiled object already bounded"
                    with lock:
                        stats["object_reuses"] += 1
                else:
                    score, symbol, diff, _ = match.check_text(client, row["addr"], source, **options)
                if object_key is not None:
                    objects[object_key] = min(objects.get(object_key, 100), score if score is not None else best)
                result.update(score=score, symbol=symbol, diff=diff[:2000])
                if score is None:
                    result.update(outcome="no_improvement", score_ceiling=best)
                if path is not None and score is not None and best < score < 100:
                    path.parent.mkdir(parents=True, exist_ok=True)
                    path.write_text(source, encoding="utf-8")
                    best = score
                    result["candidate_path"] = str(path)
                if score == 100:
                    with lock:
                        result["receipt"] = campaign.submit_exact(stage, client, row["addr"], source)
                        winners.append(result)
            except ERRORS as error:
                result["error"] = str(error)[-2000:]
                if reuse_history and "C2248" in str(error) and "IRenderable::indexFunc" in str(error):
                    directives = match.directives(source)
                    if "lib" in directives:
                        recipe, _, file = directives["lib"].partition(" ")
                        body = units.get((recipe, file.strip(), build))
                        if body:
                            with lock:
                                blocked_native.add((build, body))
                            result["blocked_reason"] = "known native IRenderable private-access header blocker"
            with lock:
                stats["checks"] += 1
                stats["errors"] += bool(result.get("error"))
                stats["verified_exacts"] += bool(result.get("receipt", {}).get("submission", {}).get("improved"))
                campaign.record(stage, result)
                if reuse_history:
                    receipt = result.get("receipt", {}).get("submission", {})
                    append(ROOT / "work/agent-memory/attempts.jsonl", dict(kind="trial",
                        date=datetime.now(timezone.utc).isoformat(), client=client, addresses=[row["addr"]],
                        profile="compiler-sweep", recipe=stage, hypothesis=origin + ": compiler context",
                        source_hash=key, compiler=build, flags=flags, before=row["score"], after=result.get("score"),
                        score_ceiling=result.get("score_ceiling"), outcome="compile_failed" if result.get("error") else
                        "server_verified" if receipt.get("verified") and receipt.get("improved") else
                        "improved" if result.get("score") is not None and result["score"] > row["score"] else "no_gain",
                        exacts_gained=int(bool(receipt.get("verified") and receipt.get("improved") and receipt.get("score") == 100)),
                        receipt=receipt, evidence=str(campaign.root / (stage + ".jsonl"))))
                if reuse_history and result.get("evidence_key"):
                    receipt = result.get("receipt", {})
                    terminal = result.get("outcome") == "no_improvement" or (result.get("score") is not None and result["score"] < 100) or bool(
                        receipt.get("submission", {}).get("verified") or receipt.get("already_exact"))
                    append(trial_path, {**result, "terminal": terminal, "stage": stage})
                    if terminal:
                        completed.add(result["evidence_key"])
                        ceiling = result.get("score") if result.get("score") is not None else result.get("score_ceiling")
                        if ceiling is not None:
                            base_key = result.get("base_evidence_key", result["evidence_key"])
                            bounds[base_key] = min(bounds.get(base_key, 100), ceiling)
                log("%s %s %s %s %s" % (stage, row["addr"], build, flags, result.get("score", "error")))
            if result.get("score") == 100:
                break
        with lock:
            if submit_partials and path is not None and row["score"] < best < 100:
                try:
                    result = campaign.submit_partial(stage, client, row["addr"], path.read_text(encoding="utf-8"), best, path)
                    receipt = result.get("submission", {})
                    stats["verified_partial_gains"] += bool(receipt.get("verified") and receipt.get("improved"))
                except ERRORS as error:
                    campaign.record(stage + "-partials", dict(addr=row["addr"], error=str(error)[-2000:]))
            stats["finished_targets"] += 1
            if reuse_history:
                progress("running", last_addr=row["addr"], seconds=round(time.monotonic() - started, 3))

    with ThreadPoolExecutor(max_workers=jobs) as pool:
        pending = iter(rows)
        queue = {pool.submit(target, row) for row in islice(pending, jobs)}
        while queue:
            ready, queue = wait(queue, return_when=FIRST_COMPLETED)
            for future in ready:
                future.result()
                row = next(pending, None)
                if row is not None:
                    queue.add(pool.submit(target, row))
    stats["seconds"] = round(time.monotonic() - started, 3)
    if reuse_history:
        progress("done")
    return winners


def fanout(campaign, stage, clients, jobs=1, client=CLIENT, log=print, targets=None, evidence_resume=False):
    """Compile (source, evidence) pairs with bounded prefetch; submit every exact hit."""
    scores = {r["addr"]: r["score"] for r in campaign.api.call("/v1/sources?scores=1&client=" + client, timeout=300)}
    target = unresolved(client, scores, targets) if targets else unresolved(client, scores)
    history = campaign.previous(stage)
    coverage_key = None
    if evidence_resume:
        from roc import clients as client_registry
        coverage_key = digest(json.dumps([2, client, client_registry.load()[client]["sha256"], targets,
            sorted((addr, row["size"], row.get("relocs", [])) for addr, row in match._functions(client).items()
                   if row.get("kind", "code") == "code")]))
    done = {r["key"] for r in history if not evidence_resume and "error" not in r and not r.get("retryable")}
    def pending_sources():
        seen = set(done)
        for source, evidence in clients:
            key = digest(source)
            if key not in seen:
                seen.add(key)
                yield source, evidence
    pending = iter(pending_sources())

    def compiled():  # bound object memory; matching and journal writes keep one owner
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            queue = {pool.submit(match.compile_text, client, item[0]): item for item in islice(pending, jobs)}
            while queue:
                ready, _ = wait(queue, return_when=FIRST_COMPLETED)
                for future in ready:
                    item = queue.pop(future)
                    try:
                        obj, error = future.result(), None
                    except ERRORS as failure:
                        obj, error = None, failure
                    following = next(pending, None)
                    if following:
                        queue[pool.submit(match.compile_text, client, following[0])] = following
                    yield (*item, obj, error)

    winners = []
    seen_objects = {r["object_sha256"] for r in history if evidence_resume and r.get("coverage_key") == coverage_key
                    and r.get("object_sha256") and "error" not in r and not r.get("retryable")}
    for source, evidence, obj, failure in compiled():
        row = {"key": digest(source), "source": source, "evidence": evidence, "winners": [], "coverage_key": coverage_key}
        pending_hits = set()
        try:
            if failure:
                raise failure
            object_key = hashlib.sha256(obj[:4] + obj[8:]).hexdigest()
            row["object_sha256"] = object_key
            row["object_reused"] = object_key in seen_objects
            hits = {} if row["object_reused"] else target.match_obj(obj, source)
            pending_hits.update(hits)
            row["local_exact_hits"] = len(hits)
            for addr, (_, symbol, *_) in sorted(hits.items()):
                result = campaign.submit_exact(stage, client, addr, source, obj=obj)
                result["symbol"] = symbol
                receipt = result.get("submission", {})
                if result.get("already_exact") or (receipt.get("verified") and receipt.get("score") == 100):
                    pending_hits.discard(addr)
                row["winners"].append(result)
                winners.append(result)
                if result.get("submission", {}).get("verified") and result["submission"].get("improved"):
                    campaign.record(stage + "-wins", result)
                    log("%s %s -> 100 - server verified exact" % (client, addr))
        except ERRORS as error:
            row["error"] = str(error)[-2000:]
        # match_obj retires local hits; failed/unavailable verification must remain eligible.
        if pending_hits:
            row["retryable"] = True
            for addr in pending_hits:
                target.index[len(match.target(client, addr)[0])].append(addr)
        elif "error" not in row:
            seen_objects.add(row["object_sha256"])
        campaign.record(stage, row)
        log("%s %s local exact %d new %d %s" % (stage, evidence, len(row["winners"]),
            sum(bool(w.get("submission", {}).get("improved")) for w in row["winners"]), row.get("error", "")[-160:]))
    return winners


def recipe_sources(spec, client=None):
    """(source, evidence) pairs for a fan-out recipe's `sources` list."""
    for item in spec:
        name = item["recipe"]
        r = libs.RECIPES[name]
        builds = item.get("builds") or r.get("builds") or [21022]
        if client and client != CLIENT:
            builds = [clients.load()[client]["compiler_build"]]
        if "unit" in item:  # agent-written unit kept portable via the findings repo
            files = [libs.add_unit(name, (ROOT / item["unit"]).read_text(encoding="utf-8"),
                                   item.get("prefix", "roc_unit_"))]
        else:
            folder = libs.fetch(name)
            pattern = item.get("files")
            if isinstance(pattern, list):
                files = pattern
            elif item.get("generated") and pattern is None:
                files = libs.matching_files(r, folder)
            else:
                files = libs.files_of(dict(r, files=pattern) if isinstance(pattern, str) else r, folder)
            if item.get("match"):
                files = [f for f in files if re.search(item["match"], f.replace("\\", "/"))]
        for file in files:
            grid_flags = item.get("flags") or libs.compile_profiles(client or CLIENT, name, file)
            for build in builds:
                for flags in grid_flags:
                    for lang in item.get("langs") or r.get("langs", ["cpp"]):
                        yield (libs.source_for(name, file, lang, build, flags),
                               {"recipe": name, "file": file, "build": build, "flags": flags, "lang": lang})


# ---------- recipes ----------

def recipes():
    return json.loads(RECIPES_FILE.read_text(encoding="utf-8"))


def plan(name):
    """What a recipe would do, without a server or compiler: counts only."""
    spec = recipes()[name]
    if "native_sweep" in spec:
        return {"op": "native-grid", "files": spec["native_sweep"].get("files", ["App/*/*.cpp"]),
                "apply": bool(spec["native_sweep"].get("apply")), "submit": bool(spec["native_sweep"].get("submit"))}
    if spec["op"] == "sweep":
        return {"op": "sweep", "stages": spec.get("stages", []),
                "stages_by_client": spec.get("stages_by_client", {})}
    if spec["op"] == "fanout":
        return {"op": "fanout", "portfolio": spec["portfolio"]} if spec.get("portfolio") is not None else {"op": "fanout", "sources": sum(1 for _ in recipe_sources(spec["sources"]))}
    if spec["op"] == "mutate":
        return {"op": "mutate", "targets": spec.get("targets", {}), "budget_per_target": spec.get("budget", 120)}
    profiles = spec.get("profiles", PROFILES)
    gates = len(spec.get("builds", BUILDS)) * sum(9 if profile == "context" else 1 for profile in profiles) * len(spec.get("append", [""]))
    return {"op": "grid", "gates_per_candidate_max": gates, "targets": spec.get("targets", {}), "portfolio": spec.get("portfolio")}


def mutate_search(campaign, name, rows, spec, client, jobs, log, stats):
    """Beam-search semantics-preserving rewrites of each stored source (roc/mutsearch.py).
    Wrapper sources naming a generated unit (`// roc-lib:`) are skipped: their code lives in the unit."""
    from roc import mutsearch
    done = {row.get("addr"): row for row in campaign.previous(name)}
    winners, stats["skipped_lib"], stats["improved_local"] = [], 0, 0
    for row in rows:
        addr = row["addr"]
        if "lib" in match.directives(row["source"]):
            stats["skipped_lib"] += 1
            continue
        if done.get(addr, {}).get("source_sha256") == digest(row["source"]):
            continue  # this exact input was already searched
        best = mutsearch.search(client, addr, row["source"], budget=spec.get("budget", 120),
                                beam=spec.get("beam", 3), depth=spec.get("depth", 3), jobs=max(1, jobs), log=log)
        record = dict(addr=addr, before=row["score"], after=best["score"], residue=best["residue"],
                      edits=best["path"], compiles=best["compiles"], source_sha256=digest(row["source"]))
        if best["score"] == 100:
            receipt = campaign.submit_exact(name, client, addr, best["source"])
            record["receipt"] = receipt
            winners.append(receipt)
        elif best["score"] > row["score"]:
            stats["improved_local"] += 1
            path = campaign.root / "candidates" / name / client / (addr + ".cpp")
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(best["source"], encoding="utf-8")
            record["candidate_path"] = str(path)
            if spec.get("submit_partials"):
                record["receipt"] = campaign.submit_partial(name, client, addr, best["source"], best["score"], path)
        campaign.record(name, record)
        log("%s %s %d -> %d (residue %d, %d compiles) %s" % (client, addr, row["score"], best["score"],
                                                          best["residue"], best["compiles"], " > ".join(best["path"])))
    return winners


def run(name, server=None, jobs=1, limit=None, log=print, campaign_id=None, client=None):
    spec = recipes()[name]
    selected = client or spec.get("client", CLIENT)
    names = sorted(clients.load()) if selected == "all" else [selected]
    if any(name not in clients.load() for name in names):
        raise ValueError("Unknown selected research client: " + selected)
    results = {}
    for name_client in names:
        output = Path(spec.get("output") or ROOT / "work" / "research" / name).resolve()
        if name_client != CLIENT:
            output /= name_client
        with job_lock(output / ".research-job.lock"):
            if "native_sweep" in spec:
                if name_client != CLIENT:
                    from roc.native_search import client_profile
                    results[name_client] = client_profile(spec['native_sweep'], name_client, output, jobs, limit, log)
                    continue
                from roc import native_sweep
                results[name_client] = native_sweep.run(dict(spec, client=name_client), name, server, jobs, limit, output, log)
            else:
                results[name_client] = _run(name, server, jobs, limit, log, campaign_id, name_client, output)
    return results[names[0]] if len(names) == 1 else {"clients": results}


def _run(name, server=None, jobs=1, limit=None, log=print, campaign_id=None, client=CLIENT, output=None):
    """Run one named recipe. Returns a summary; also journaled as agent memory."""
    spec = recipes()[name]
    if spec["op"] == "sweep":
        started = time.monotonic()
        stages = spec.get("stages_by_client", {}).get(client, []) + spec.get("stages", [])
        results = []
        for stage in stages:
            if recipes()[stage]["op"] == "sweep":
                raise ValueError("Nested sweeps are not supported: " + stage)
            results.append(run(stage, server, jobs, limit, log, campaign_id, client))
        summary = dict(recipe=name, client=client, op="sweep", stages=results,
                       new_verified=sum(r["new_verified"] for r in results),
                       verified_partial_gains=sum(r.get("verified_partial_gains", 0) for r in results),
                       seconds=round(time.monotonic() - started, 3))
        append((output or ROOT / "work" / "research" / name) / "runs.jsonl", summary)
        log("TOTAL " + json.dumps(summary))
        return summary
    campaign = Campaign(output or ROOT / "work" / "research" / name, server, campaign_id, client)
    stats = {}
    try:
        if spec["op"] == "grid":
            rows = grid_rows(campaign, spec, client, coverage=stats if spec.get("reuse_history") else None, limit=limit)
            stats["eligible_targets"] = len(rows)
            rows = rows[:limit] if limit else rows
            builds = spec.get("builds", BUILDS) if client == CLIENT else [clients.load()[client]["compiler_build"]]
            winners = grid(campaign, name, rows, builds, spec.get("profiles", PROFILES),
                           spec.get("append", [""]), client=client, log=log,
                           keep_partials=spec.get("keep_partials", False), jobs=jobs,
                           reuse_history=spec.get("reuse_history", False), stats=stats,
                           improvement_only=spec.get("improvement_only", False), preserve_inputs=bool(spec.get("portfolio")),
                           submit_partials=spec.get("submit_partials", False), reuse_objects=spec.get("reuse_objects", False))
            tried = len(rows)
        elif spec["op"] == "fanout":
            if spec.get("portfolio") is not None:
                from roc import brute
                rows = grid_rows(campaign, spec, client)
                builds = spec.get("builds", BUILDS) if client == CLIENT else [clients.load()[client]["compiler_build"]]
                inputs = brute.portfolio_sources(rows, client, builds, spec.get("profiles", PROFILES), spec.get("append", [""]))
            else:
                inputs = recipe_sources(spec["sources"], client=client)
            tried = 0
            def counted_sources():
                nonlocal tried
                for item in islice(inputs, limit):
                    tried += 1
                    yield item
            winners = fanout(campaign, name, counted_sources(), jobs, client=client, log=log, targets=spec.get("targets"),
                             evidence_resume=spec.get("evidence_resume", False))
        elif spec["op"] == "mutate":
            rows = grid_rows(campaign, spec, client, limit=limit)
            rows = rows[:limit] if limit else rows
            winners = mutate_search(campaign, name, rows, spec, client, jobs, log, stats)
            tried = len(rows)
        else:
            raise ValueError("Unknown research op: " + spec["op"])
    finally:
        campaign.api.close()
    new = [w for w in winners if w.get("submission", {}).get("improved") or
           w.get("receipt", {}).get("submission", {}).get("improved")]
    summary = {"recipe": name, "client": client, "op": spec["op"], "tried": tried, "local_exact": len(winners), "new_verified": len(new), **stats}
    remember(spec, name, summary, new, campaign.root, campaign_id, client)
    log("TOTAL %s" % json.dumps(summary))
    return summary


def remember(spec, name, summary, new, evidence, campaign_id=None, client=CLIENT):
    """One run record plus one verified trial per new exact, in the agent attempt journal."""
    now = datetime.now(timezone.utc).isoformat()
    rows = [dict(kind="research_run", date=now, client=client, library=spec.get("library"), recipe=name,
                 hypothesis=spec.get("hypothesis"), change=spec.get("change"), addresses=[],
                 outcome="improved" if new else "no_gain", exacts_gained=len(new), evidence=str(evidence),
                 next=spec.get("next"), **{k: summary[k] for k in ("tried", "local_exact")})]
    for win in new:
        result = win.get("receipt", win)
        rows.append(dict(kind="trial", date=now, client=client, library=spec.get("library"), recipe=name,
                         addresses=[result["addr"]], hypothesis=spec.get("hypothesis"),
                         source_hash=result.get("source_sha256"), after=100, exacts_gained=1,
                         outcome="server_verified", receipt=result.get("submission"), evidence=str(evidence)))
    path = ROOT / "work" / "agent-memory" / "attempts.jsonl"
    path.parent.mkdir(parents=True, exist_ok=True)
    for row in rows:
        if campaign_id:
            row["campaign_id"] = campaign_id
        append(path, row)


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
    if not isinstance(row, dict):
        raise ValueError("Journal record must be an object")
    encoded = (json.dumps(row, ensure_ascii=True, allow_nan=False) + "\n").encode("utf-8")
    path.parent.mkdir(parents=True, exist_ok=True)
    with WRITE_LOCK, match._object_lock(path), path.open("a+b") as stream:
        stream.seek(0, 2)
        if stream.tell():
            stream.seek(-1, 2)
            if stream.read(1) != b"\n":
                stream.write(b"\n")
        stream.write(encoded)


def journal_records(path):
    """Read one line at a time; recover concatenated objects from older writers."""
    decoder = json.JSONDecoder()
    rows = []
    if path.exists():
        with path.open(encoding="utf-8-sig") as stream:
            for line in stream:
                remaining = line.strip().lstrip("\ufeff")
                while remaining:
                    try:
                        row, end = decoder.raw_decode(remaining)
                    except ValueError:
                        break
                    if isinstance(row, dict):
                        rows.append(row)
                    remaining = remaining[end:].lstrip()
    return rows


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
    row.update({key: task[key] for key in ("campaign_id", "baseline_hash", "target_revision") if key in task})
    if task.get("model_started_at") is not None:
        row["seconds_to_check"] = max(0, time.time() - task["model_started_at"])
    previous = []
    if (journal / "trials.jsonl").exists():
        for line in (journal / "trials.jsonl").read_text().splitlines():
            try:
                previous.append(json.loads(line))
            except ValueError:
                continue
    try:
        obj = match.compile_text(client, text)
        row["object_hash"] = hashlib.sha256(obj).hexdigest()
        code, relocs, _ = match.target(client, addr)
        row["target_hash"] = hashlib.sha256(code + repr(relocs).encode()).hexdigest()
        duplicate = next((r for r in reversed(previous) if all(r.get(key) == row.get(key)
                         for key in ("source_hash", "compiler", "flags", "object_hash", "target_hash"))), None)
        if duplicate:
            score, symbol, diff = duplicate["after"], duplicate.get("symbol"), duplicate.get("diff", "")
            row["duplicate"] = True
        else:
            score, symbol, diff, _ = match.check_text(client, addr, text, obj=obj)
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
        if '#import, #using, #include "file"' in str(error):
            row["validation_failed"] = True
        if any(all(r.get(key) == row.get(key) for key in ("source_hash", "compiler", "flags", "error"))
               for r in previous):
            row["duplicate"] = True
    if not row.get("duplicate"):
        append(journal / "trials.jsonl", row)
        append(root / "work" / "agent-memory" / "attempts.jsonl", row)
    return row


# Free compiler gates tried on each near-miss before any paid repair (CLAUDE.md step 3).
GATES = ("keep", "/O2 /GS- /EHsc /MD", "/O1 /GS- /EHsc /MD")


def known_failures(records):
    """(addr, source hash) pairs already compiled without gain, on any PC."""
    return {(addr, r["source_hash"]) for r in records if r.get("kind") == "trial" and r.get("source_hash")
            and r.get("outcome") in ("no_gain", "compile_failed") for addr in r.get("addresses") or ()}


def gate_sweeps(records):
    """(addr, source hash) pairs whose compiler-gate sweep already ran, on any PC."""
    return {(addr, r["source_hash"]) for r in records if r.get("kind") == "reuse_gates" and r.get("source_hash")
            for addr in r.get("addresses") or ()}


def reuse(root, task, portfolio, tried=frozenset(), swept=frozenset()):
    """Donor verification and normal target checks decide; shape alone never accepts.

    The compiler-gate sweep runs once per (function, source): later sessions skip it.
    """
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
    source_hash = digest(task["source"])
    if task["before"] >= 90 and (task["addr"], source_hash) not in swept:
        portfolio += [source for source, _, _ in variants(task["source"], profiles=GATES, client=client,
            builds=BUILDS if client == CLIENT else (clients.load()[client]["compiler_build"],))]
        append(root / "work" / "agent-memory" / "attempts.jsonl",
               dict(kind="reuse_gates", date=datetime.now(timezone.utc).isoformat(), client=client,
                    addresses=[task["addr"]], source_hash=source_hash, profiles=list(GATES)))
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
