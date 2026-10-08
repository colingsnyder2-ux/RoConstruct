"""Worker: lease a function from the server, draft C++ with AI, compile, diff,
retry with feedback, submit the best result under your username."""
import http.client
import json
import os
import re
import ssl
import sys
import threading
import time
import traceback
import urllib.error
import urllib.request
from urllib.parse import quote, urlparse
import uuid
from pathlib import Path

from roc import clients, draft, match, metrics, setup

ROOT = Path(__file__).resolve().parent.parent
SETTINGS = ROOT / "roconstruct-settings.json"
USER_RE = re.compile(r"^[A-Za-z0-9_.-]{2,32}$")
SITE = "https://colingsnyder2-ux.github.io/RoConstruct/"


def pretty_log(message):
    text = str(message)
    if not sys.stdout.isatty() or os.environ.get("NO_COLOR"):
        print(text)
        return
    low = text.lower()
    if "generated source" in low:
        header, _, source = text.partition("\n")
        print("\x1b[36m" + header + "\x1b[0m")
        if source:
            print("\x1b[96m" + source + "\x1b[0m")
    elif "submitted" in low or "score updated" in low:
        print("\x1b[32m" + text + "\x1b[0m")
    elif "error" in low or "offline" in low or "timeout" in low:
        print("\x1b[31m" + text + "\x1b[0m")
    else:
        print(text)


class ApiFailure(RuntimeError):
    """Short, machine-readable server/network failure for telemetry and UI."""
    def __init__(self, category, message):
        self.category = category
        super().__init__("%s: %s" % (category, message))


def site_server():
    """Current public server address as published on the progress site (tunnel URLs change)."""
    try:
        with urllib.request.urlopen(SITE + "progress.json", timeout=20) as r:
            return json.loads(r.read()).get("server")
    except (OSError, ValueError):
        return None


def reconnect(api, log):
    """Server unreachable: switch to the address the site lists now, if it moved."""
    new = site_server()
    if new and Api(new).server != api.server:
        log("Server moved to %s, switching." % new)
        api.__init__(new, api.token)
        save_settings(server=new)
        return True
    return False


def load_settings():
    try:
        return json.loads(SETTINGS.read_text())
    except (OSError, ValueError):
        return {}


def save_settings(**changes):
    s = load_settings()
    s.update({k: v for k, v in changes.items() if v is not None})
    SETTINGS.write_text(json.dumps(s, indent=1))
    return s


def clear_setting(name):
    s = load_settings()
    s.pop(name, None)
    SETTINGS.write_text(json.dumps(s, indent=1))
    return s


def save_session_state(worker, user, model, done, matched, failures=0):
    path = ROOT / "work" / "worker-sessions" / (worker + ".json")
    try:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps({"worker": worker, "user": user, "model": model,
                                    "completed": done, "matched": matched, "failures": failures,
                                    "updated": time.time()}, indent=1))
    except OSError:
        pass


class Api:
    def __init__(self, server, token=None):
        self.server = server.rstrip("/")
        if not self.server.startswith("http"):
            self.server = "http://" + self.server
        self.token = token
        parsed = urlparse(self.server)
        self._host = parsed.hostname
        self._port = parsed.port or (443 if parsed.scheme == "https" else 80)
        self._https = parsed.scheme == "https"
        self._prefix = parsed.path.rstrip("/")
        self._conn = None

    def _get_conn(self, timeout=60):
        if self._conn is None:
            if self._https:
                self._conn = http.client.HTTPSConnection(self._host, self._port, timeout=timeout,
                                                         context=ssl.create_default_context())
            else:
                self._conn = http.client.HTTPConnection(self._host, self._port, timeout=timeout)
        return self._conn

    def call(self, path, payload=None, timeout=60):
        data = json.dumps(payload).encode() if payload is not None else None
        headers = {"Content-Type": "application/json"}
        if self.token:
            headers["X-Roc-Token"] = self.token
        method = "POST" if data is not None else "GET"
        tries = 3 if payload is None else 1  # safe retries only for idempotent GETs
        for attempt in range(tries):
            try:
                conn = self._get_conn(timeout)
                conn.request(method, self._prefix + path, body=data, headers=headers)
                resp = conn.getresponse()
                body = resp.read()
                if resp.status >= 400:
                    try:
                        msg = json.loads(body).get("error")
                    except (ValueError, AttributeError):
                        msg = resp.reason
                    category = "auth_fail" if resp.status in (401, 403) else \
                               "bad_request" if 400 <= resp.status < 500 else "server_fail"
                    if resp.status >= 500 and attempt + 1 < tries:
                        self._conn = None
                        time.sleep(0.5 * (attempt + 1))
                        continue
                    raise ApiFailure(category, msg)
                return json.loads(body)
            except ApiFailure:
                raise
            except (http.client.HTTPException, OSError, ValueError) as error:
                self._conn = None  # force reconnect on next attempt
                if attempt + 1 == tries:
                    raise ApiFailure("offline", "cannot reach server %s (%s). Is it running? Right address?"
                                     % (self.server, error))
                time.sleep(0.5 * (attempt + 1))


def usable_clients(info, log=print):
    """Clients this machine can work on: same exe hash as the server, compiler present.

    A client that is registered but not on disk yet is fetched once, rather than
    silently dropped, so starting a worker is enough to get set up.
    """
    have, compilers = [], setup.compilers()
    local = clients.load()
    from roc import sources
    manifest = sources.load_sources()
    for name, remote in sorted(info["clients"].items()):
        entry = local.get(name)
        if not entry or entry.get("sha256") != remote.get("sha256"):
            log("  skip %s: clients.json differs from server (git pull)" % name)
            continue
        if clients.status(name, entry) != "ok":
            if name in manifest.get("drive", {}) or manifest.get("bundle"):
                log("  fetching %s (%s)..." % (name, clients.status(name, entry)))
                try:
                    sources.fetch(name)
                except sources.FetchError as error:
                    log("  skip %s: %s" % (name, error))
                    continue
            if clients.status(name, entry) != "ok":
                log("  skip %s: put the exe listed in clients.json into clients/%s/ (status: %s)"
                    % (name, name, clients.status(name, entry)))
                continue
        if not (Path(ROOT / "work" / name / "functions.jsonl")).exists():
            log("  skip %s: run  roc analyze %s" % (name, name))
            continue
        if remote.get("compiler_build") not in compilers:
            log("  skip %s: compiler %s missing (roc install)" % (name, remote.get("compiler")))
            continue
        have.append(name)
    return have


def run(server, user, token=None, model=None, rounds=4, max_size=256, use_revng=True,
        max_jobs=None, log=pretty_log, forever=False, only=None, source_only=False, targets=None):
    """forever: survive server/network outages (retry every minute) for overnight runs.
    only: restrict to these clients (one-click links)."""
    if not USER_RE.match(user or ""):
        raise SystemExit("Pick a username: 2-32 letters, digits, _ . -")
    api = Api(server, token)
    while True:
        try:
            info = api.call("/v1/info")
            break
        except RuntimeError as error:
            if not forever:
                raise
            if not reconnect(api, log):
                log("%s  Retrying in 60 s." % error)
                time.sleep(60)
    if only:
        info["clients"] = {k: v for k, v in info["clients"].items() if k in only}
    have = usable_clients(info, log)
    if not have:
        raise SystemExit("Nothing to work on from this PC yet (see the skip reasons above).")
    auto_model = model is None and not source_only
    model = draft.pick_model(model) if not source_only else "none"
    if not model and not source_only:
        raise SystemExit("AI workers need Ollama with a code model:  ollama pull qwen2.5-coder:7b\n"
                         "No GPU? You can still help by hand: roc claim / roc check / roc submit.")
    revng = not source_only and use_revng and draft.revng_available()
    worker = uuid.uuid4().hex[:12]
    session = uuid.uuid4().hex[:12]
    log("Worker %s as '%s' on %s | model %s | Rev.ng %s" % (worker, user, ", ".join(have), model,
                                                         "on" if revng else "off"))
    log("Note: workers keep the GPU and CPU busy (fans, heat, power). Ctrl+C or close the window to stop.")
    done = matched = 0
    failures = 0
    examples_cache = {}
    source_cache = {}
    while max_jobs is None or done < max_jobs:
        try:
            job = api.call("/v1/lease", {"user": user, "worker": worker, "clients": have,
                                         "mode": "ai", "model": model, "max_size": max_size,
                                         "targets": targets})["job"]
        except (Exception, SystemExit) as error:  # overnight: nothing short of Ctrl+C stops the loop
            if not forever:
                raise
            if not reconnect(api, log):
                log("%s  Retrying in 60 s." % error)
                time.sleep(60)
            else:
                info = api.call("/v1/info")
                have = usable_clients(info, log)
            continue
        if not job:
            if max_jobs is not None:
                break
            log("No open functions right now; checking again in 60 s.")
            time.sleep(60)
            continue
        done += 1
        job_model = draft.route_model(model, job) if auto_model else model
        score = work_one(api, user, job, info, job_model, rounds, revng, log, examples_cache, source_cache,
                         session, source_only)
        matched += score == 100
        failures += score == 0
        save_session_state(worker, user, model, done, matched, failures)
        if done % 10 == 0:
            log("== %s: %d functions tried, %d matched this session ==" % (time.strftime("%H:%M"), done, matched))
            report = metrics.summary(session)
            if report:
                log(report)
    log("Worker finished %d job(s), %d matched." % (done, matched))
    report = metrics.summary(session)
    if report:
        log(report)


def run_concurrent(server, user, token=None, model=None, rounds=4, max_size=256,
                   use_revng=True, max_jobs=None, workers=1, log=pretty_log,
                   source_only=False, targets=None, only=None):
    """Run a bounded number of independent lease loops.

    Server leases make workers safe to run in parallel.  Keep the default at one
    process/thread so laptop users do not accidentally oversubscribe GPU/CPU.
    """
    if str(workers).lower() == "auto":
        # Conservative: small models can overlap; large models stay serial.
        workers = 2 if "7b" in str(model).lower() else 1
    workers = max(1, min(int(workers or 1), 8))
    if workers == 1:
        return run(server, user, token, model, rounds, max_size, use_revng,
                   max_jobs, log, forever=True, only=only, source_only=source_only, targets=targets)
    if max_jobs is None:
        quotas = [None] * workers
    else:
        base, extra = divmod(max(0, int(max_jobs)), workers)
        quotas = [base + (i < extra) for i in range(workers)]
    errors = []

    def worker_loop(index):
        try:
            run(server, user, token, model, rounds, max_size, use_revng,
                quotas[index], log, forever=True, only=only, source_only=source_only, targets=targets)
        except BaseException as error:
            errors.append(error)

    threads = [threading.Thread(target=worker_loop, args=(i,),
                                name="roc-worker-%d" % (i + 1), daemon=True)
               for i in range(workers)]
    log("Starting %d bounded worker loops (server leases prevent duplicates)." % workers)
    for thread in threads:
        thread.start()
    try:
        for thread in threads:
            thread.join()
    except KeyboardInterrupt:
        log("Stopping worker loops; active leases will release on heartbeat expiry.")
        raise
    if errors:
        raise errors[0]


def work_one(api, user, job, info, model, rounds, revng, log, examples_cache=None,
             source_cache=None, session=None, source_only=False):
    client, addr = job["client"], job["addr"]
    flags = info["clients"][client].get("flags")
    log("[%s %s] %d bytes, %s, best so far %d%%" % (client, addr, job["size"], job["unit"], job["score"]))
    stop = threading.Event()
    started = time.monotonic()
    result, improved, failure = 0, False, None
    source_candidate = None
    phase_seconds = {}
    failure_reason = None
    round_stats = []
    lease_lost = threading.Event()
    deadline = started + 600

    def beat():
        # Its own connection: http.client is not thread-safe, so sharing the main
        # thread's api here raced self._conn, forcing a new socket per call and
        # exhausting ephemeral ports (WinError 10048).
        hb = Api(api.server, api.token)
        while not stop.wait(job.get("heartbeat", 60)):
            try:
                if not hb.call("/v1/heartbeat", {"lease": job["lease"]}).get("ok"):
                    lease_lost.set()
                    return
            except RuntimeError:
                lease_lost.set()
                return

    def ensure_lease():
        if lease_lost.is_set():
            raise RuntimeError("lease lost; abandoning job")
        if time.monotonic() >= deadline:
            raise TimeoutError("job exceeded 600-second worker limit")

    threading.Thread(target=beat, daemon=True).start()
    try:
        code, relocs, _ = match.target(client, addr)
        asm = match.disasm(code, int(addr, 16))
        facts = draft.facts_from_asm(asm)
        facts.update(draft.target_data_facts(client, code, relocs))
        row = match._functions(client)[addr]
        facts.update({k: row[k] for k in ("call_targets", "callers", "external_calls", "imports", "strings", "data_refs",
                                           "global_reads", "global_writes",
                                           "virtual_slots", "stack_args", "this_reads", "this_writes",
                                           "calling_convention", "branches", "constants", "siblings") if row.get(k)})
        from roc import auto
        phase_started = time.monotonic()
        for candidate in auto.candidates(asm):
            ensure_lease()
            try:
                candidate_score, _, _, _ = match.check_text(client, addr, candidate, flags)
            except match.CompileError:
                continue
            if candidate_score > job["score"]:
                r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "worker": job.get("worker"),
                                            "model": job.get("model"), "client": client, "addr": addr,
                                            "score": candidate_score, "source": candidate})
                log("  deterministic candidate submitted %d%%" % r["stored"])
                result, improved = r["stored"], True
                return r["stored"]
        from roc import refsource
        ensure_lease()
        source_candidate = refsource.compile_candidates(client, addr, job["unit"], flags, limit=2, log=log)
        phase_seconds["source_compile"] = round(time.monotonic() - phase_started, 3)
        if source_candidate and source_candidate[0] == 100:
            candidate_score, candidate_source, candidate_path = source_candidate
            r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "worker": job.get("worker"),
                                        "model": job.get("model"), "client": client, "addr": addr,
                                        "score": candidate_score, "source": candidate_source})
            log("  2016 source candidate %d%% (%s)" % (r["stored"], candidate_path))
            result, improved = r["stored"], True
            return r["stored"]
        if source_candidate:
            log("  2016 source candidate scored %d%%; using as LLM base" % source_candidate[0])
        if source_only:
            api.call("/v1/release", {"lease": job["lease"], "cooldown": 30})
            result = job["score"]
            failure_reason = "no_gain"
            log("  no deterministic improvement (best %d%%), released" % job["score"])
            return result
        if examples_cache is None:
            examples_cache = {}
        if source_cache is None:
            source_cache = {}
        if client not in examples_cache:
            examples_cache[client] = {}
        example_key = (job["unit"], job.get("shape"))
        if example_key not in examples_cache[client]:
            path = "/v1/examples?client=%s&unit=%s&shape=%s&n=2" % (
                quote(client), quote(job["unit"]), quote(job.get("shape") or ""))
            quarantined = metrics.quarantined_keys()
            examples_cache[client][example_key] = [e["source"] for e in api.call(path)
                                                   if (client, e.get("addr")) not in quarantined]
        examples = examples_cache[client][example_key]
        source_key = (client, job["unit"], tuple(facts.get("strings", ())))
        if source_key not in source_cache:
            source_cache[source_key] = refsource.prompt_hints(job["unit"], target_facts=facts)
        source_hints = source_cache[source_key]
        # Tiny leaf functions are cheaper to solve from direct asm/source facts;
        # reserve Rev.ng CPU time for larger or structurally uncertain targets.
        run_revng = revng and (job.get("size", 0) > 48 or job.get("calls", 0) or
                               not job.get("source_confidence", 0))
        revng_started = time.monotonic()
        hint = draft.revng_c(code, int(addr, 16)) if run_revng else None
        phase_seconds["revng"] = round(time.monotonic() - revng_started, 3)
        llm_started = time.monotonic()
        llm_start = (job["source"], job["score"])
        if source_candidate and source_candidate[0] > job["score"]:
            llm_start = (source_candidate[1], source_candidate[0])
        score, src = draft.llm_rounds(client, addr, model, draft.model_rounds(model, rounds), hint, llm_start,
                                      log, flags, examples, source_hints, facts, round_stats)
        ensure_lease()
        phase_seconds["llm"] = round(time.monotonic() - llm_started, 3)
        if src and score > job["score"]:
            r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "worker": job.get("worker"),
                                        "model": job.get("model"), "client": client, "addr": addr,
                                        "score": score, "source": src})
            log("  submitted %d%% (%s)" % (r["stored"], "verified by server" if r["verified"] else "not re-checked"))
            result, improved = r["stored"], True
            return r["stored"]
        failure_reason = "bad_reply" if not src else "no_gain"
        if source_candidate and source_candidate[0] > job["score"]:
            candidate_score, candidate_source, candidate_path = source_candidate
            r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "worker": job.get("worker"),
                                        "model": job.get("model"), "client": client, "addr": addr,
                                        "score": candidate_score, "source": candidate_source})
            log("  retained partial 2016 source candidate %d%% (%s)" % (r["stored"], candidate_path))
            result, improved = r["stored"], r["stored"] > job["score"]
            return r["stored"]
        api.call("/v1/release", {"lease": job["lease"], "cooldown": 60})
        log("  no improvement (best %d%%), released" % job["score"])
        result = job["score"]
        return result
    except (Exception, SystemExit) as error:  # never leave a lease hanging on a crash
        failure = str(error)[:300]
        if isinstance(error, match.CompileError):
            failure_reason = "compile_fail"
        elif isinstance(error, TimeoutError) or "timed out" in failure.lower() or "timeout" in failure.lower():
            failure_reason = "timeout"
        elif isinstance(error, ApiFailure):
            failure_reason = error.category
        elif isinstance(error, RuntimeError):
            failure_reason = "api"
        else:
            failure_reason = "worker_error"
        if session:
            metrics.record(session, event="error", client=client, addr=addr,
                           reason=failure_reason, detail=traceback.format_exc())
        log("  error: %s" % error)
        try:
            api.call("/v1/release", {"lease": job["lease"], "cooldown": 120})
        except RuntimeError:
            pass
        return 0
    except KeyboardInterrupt:
        try:
            api.call("/v1/release", {"lease": job["lease"], "cooldown": 120})
        finally:
            raise
    finally:
        stop.set()
        if session:
            coded = [r for r in round_stats if isinstance(r.get("round"), int) and r.get("code")]
            metrics.record(session, event="job", client=client, addr=addr, unit=job["unit"], model=model,
                           size=job.get("size", 0), base_score=job.get("score", 0), score=result,
                           score_gain=max(result - job.get("score", 0), 0), improved=improved,
                           source_hints=len(source_hints) if 'source_hints' in locals() else 0,
                           source_candidate=bool(source_candidate),
                           source_candidate_score=source_candidate[0] if source_candidate else 0,
                           source_candidate_hit=bool(source_candidate and source_candidate[0] == 100),
                           revng=bool(run_revng if 'run_revng' in locals() else revng),
                           prompt_profile=draft.model_profile(model), rounds=round_stats,
                           seconds=round(time.monotonic() - started, 2),
                           phase_seconds=phase_seconds,
                           compile_seconds=round(sum(r.get("compile_seconds", 0) for r in round_stats) +
                                                 phase_seconds.get("source_compile", 0), 3),
                           compile_attempts=sum(1 for r in coded),
                           compile_ok=sum(1 for r in coded if not r.get("compile_error")),
                           failure_reason=failure_reason,
                           failure=failure)


def pull_files(server, client, token=None, force=False, log=print):
    """Download every stored source for a client into src/<client>/.
    Local files are kept unless force; scores.json is updated either way."""
    api = Api(server, token)
    rows = api.call("/v1/sources?client=%s" % client, timeout=300)
    folder = ROOT / "src" / client
    folder.mkdir(parents=True, exist_ok=True)
    written = kept = 0
    for r in rows:
        if not re.match(r"^[0-9a-f]{8}$", r["addr"]):
            continue
        path = folder / ("%s.cpp" % r["addr"])
        match.save_score(client, r["addr"], r["score"])
        if path.exists() and not force:
            kept += 1
            continue
        src = r["source"]
        if not src.lstrip().startswith("// roc"):
            try:
                src = match.template(client, r["addr"]).split("\n\n")[0] + "\n\n" + src
            except SystemExit:
                pass  # no local exe/analysis: write the source without the asm header
        path.write_text("// from server: %d%% by %s\n%s" % (r["score"], r["user"], src))
        written += 1
    log("%s: %d sources from the server, %d written to %s, %d local files kept%s"
        % (client, len(rows), written, folder, kept, " (use --force to replace them)" if kept else ""))


def submit_files(server, user, client, addrs=None, token=None, log=print):
    """Upload hand-written src/<client>/*.cpp to the server (checked locally first)."""
    api = Api(server, token)
    paths = sorted((ROOT / "src" / client).glob("*.cpp"))
    if addrs:
        paths = [p for p in paths if p.stem in addrs]
    for p in paths:
        try:
            score, _, _, _ = match.check(client, p.stem, p)
        except match.CompileError as error:
            log("%s  skipped, does not compile: %s" % (p.stem, str(error).splitlines()[0]))
            continue
        r = api.call("/v1/submit", {"user": user, "client": client, "addr": p.stem,
                                    "score": score, "source": p.read_text()})
        log("%s  %3d%%  %s" % (p.stem, r["stored"], "new best" if r["improved"] else "server already has this or better"))
