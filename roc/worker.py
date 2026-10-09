"""Worker: lease a function from the server, draft C++ with AI, compile, diff,
retry with feedback, submit the best result under your username."""
import http.client
import contextlib
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


def family_from_example(spec):
    """Resolve CLIENT:ADDRESS to strict opcode fingerprint."""
    from roc import families
    try:
        client, addr = spec.split(":", 1)
        if not re.fullmatch(r"[0-9a-fA-F]{8}", addr):
            return None
        row = match._functions(client).get(addr.lower()) or match._functions(client).get(addr.upper())
        if not row:
            return None
        code, _, _ = match.target(client, addr.lower())
        return families.fingerprint(row, match.disasm(code, int(addr, 16)))
    except (ValueError, OSError, KeyError):
        return None


def register_family_targets(server, token, client, family_id):
    """Publish local family index so a family lease can find its siblings."""
    path = ROOT / "work" / client / ("family-index-%s.jsonl" % client)
    if not path.exists():
        path = ROOT / "work" / ("family-index-%s.jsonl" % client)
    if not path.exists():
        return 0
    rows = []
    for line in path.read_text(errors="replace").splitlines():
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        if row.get("family") == family_id:
            rows.append(row)
    api = Api(server, token)
    total = 0
    for i in range(0, len(rows), 5000):
        total += api.call("/v1/families", {"rows": rows[i:i + 5000]}).get("registered", 0)
    return total
SETTINGS = ROOT / "roconstruct-settings.json"
MAX_WORKERS = 256
USER_RE = re.compile(r"^[A-Za-z0-9_.-]{2,32}$")
SITE = "https://colingsnyder2-ux.github.io/RoConstruct/"
# Tried in order when a cloud worker did not pick a model: cheap first, then the
# stronger coder models. Every entry needs only its provider's API key.
CLOUD_DEFAULTS = ("deepseek:deepseek-flash", "nvidia:qwen/qwen2.5-coder-32b-instruct",
                  "openai:gpt-5-mini", "gemini:gemini-2.5-flash")


def cloud_default():
    """The cheapest cloud model whose key is already set, or None."""
    from roc import providers
    for model in CLOUD_DEFAULTS:
        if providers.is_cloud(model) and providers.available(model):
            return model
    for name, config in sorted(providers.providers().items()):
        remote = (config.get("defaults") or [None])[0]
        if remote and providers.key_available(config["key_env"]):
            return "%s:%s" % (name, remote)
    return None


def pretty_log(message):
    text = str(message)
    def emit(value):
        try:
            print(value)
        except UnicodeEncodeError:
            encoding = getattr(sys.stdout, "encoding", None) or "utf-8"
            print(value.encode(encoding, "replace").decode(encoding, "replace"))
    if not sys.stdout.isatty() or os.environ.get("NO_COLOR"):
        emit(text)
        return
    low = text.lower()
    if text.startswith("✓ "):
        emit("\x1b[92m" + text + "\x1b[0m")
    elif text.startswith("↑ "):
        emit("\x1b[93m" + text + "\x1b[0m")
    elif text.startswith("· "):
        emit("\x1b[90m" + text + "\x1b[0m")
    elif text.startswith("⛏ "):
        emit("\x1b[96m" + text + "\x1b[0m")
    elif "generated source" in low:
        header, _, source = text.partition("\n")
        emit("\x1b[36m" + header + "\x1b[0m")
        if source:
            emit("\x1b[96m" + source + "\x1b[0m")
    elif "submitted" in low or "score updated" in low:
        emit("\x1b[32m" + text + "\x1b[0m")
    elif "error" in low or "offline" in low or "timeout" in low:
        emit("\x1b[31m" + text + "\x1b[0m")
    else:
        emit(text)


class CompactLog:
    """Keep high-parallel cloud workers readable without hiding outcomes."""
    def __init__(self, workers, output=pretty_log):
        self.workers = workers
        self.output = output
        self.lock = threading.Lock()
        self.jobs = self.improved = self.matched = self.failures = 0
        self.current = {}
        self.next_report = max(10, workers)

    def __call__(self, message):
        text = str(message)
        thread = threading.get_ident()
        job = re.match(r"\[([^ ]+) ([^\]]+)\]\s+(\d+)\s*(?:bytes|B),\s*(.*?), best so far (\d+)%", text)
        with self.lock:
            if job:
                self.current[thread] = (job.group(1), job.group(2), int(job.group(3)),
                                        job.group(4), int(job.group(5)))
                return
            if text.startswith("  2016 source candidate") and "using as LLM base" not in text:
                score = re.search(r"(\d+)%", text)
                self._finish(int(score.group(1)) if score else 0)
                return
            if (text.startswith("Worker ") or text.startswith("  auto-think:") or
                    text.startswith("  round ") or text.startswith("  generated source") or
                    text.startswith("  no improvement") or text.startswith("  retained") or
                    text.startswith("  2016 source") or text.startswith("Session:") or
                    text.startswith("== ") or text.startswith("Worker finished") or
                    text.startswith("Cloud model:") or text.startswith("Privacy:") or
                    text.startswith("  tokens used:") or
                    text.startswith("  thinking disabled")):
                if text.startswith("  no improvement") or text.startswith("  retained"):
                    score = re.search(r"(\d+)%", text)
                    self._finish(int(score.group(1)) if text.startswith("  retained") and score else None)
                return
            if "submitted " in text or "candidate submitted" in text:
                score = re.search(r"(\d+)%", text)
                score = int(score.group(1)) if score else 0
                self._finish(score)
                return
            if text.lstrip().startswith("error:") or text.startswith("server_fail:"):
                self.failures += 1
                if self.failures == 1:
                    self.output("! worker error; retrying. Further errors summarized.")
                return
            self.output(text)

    def _finish(self, score=None):
        self.jobs += 1
        self.improved += score is not None and score > 0
        self.matched += score == 100
        client, addr, size, unit, best = self.current.pop(threading.get_ident(), ("?", "?", None, "?", 0))
        size_text = "%d B " % size if size is not None else ""
        if score is None:
            self.output("· %s %s %sno gain (best %d%%) %s" % (client, addr, size_text, best, unit))
        else:
            self.output("%s %s %s %s%d%% %s" % ("✓" if score == 100 else "↑",
                        client, addr, size_text, score, unit))
        if self.jobs >= self.next_report:
            self.output("⛏ %dw | %d done | %d matched | %d improved | %d errors" %
                        (self.workers, self.jobs, self.matched, self.improved, self.failures))
            self.next_report += max(10, self.workers)

    def finish(self):
        self.output("⛏ %dw finished | %d done | %d matched | %d improved | %d errors" %
                    (self.workers, self.jobs, self.matched, self.improved, self.failures))


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


# Conservative ceilings for a worker someone started from a link: bounded prompts,
# bounded spend, and a cost cap when the provider has known pricing.
HANDOFF_CLOUD_REQUESTS = 1000
HANDOFF_CLOUD_TOKENS = 2000000
HANDOFF_CLOUD_COST_USD = 1.0


def keep_awake():
    """Stop Windows sleeping while the worker runs (screen may still turn off)."""
    if os.name == "nt":
        import ctypes
        ctypes.windll.kernel32.SetThreadExecutionState(0x80000000 | 0x00000001)


def resolve_model(payload):
    """Model for a signed handoff: cloud by default, local only when asked for.

    Returns (model, cloud_allowed). Raises SystemExit with a repair hint when the
    config asks for something this machine cannot do, so `roc doctor` and the
    worker agree on why.
    """
    from roc import providers
    mode = payload.get("mode") or "cloud"
    model = payload.get("model") or None
    cloud_allowed = bool(payload.get("cloud"))
    if providers.is_cloud(model or "") and not cloud_allowed:
        raise SystemExit("This setup chose a cloud model but cloud consent was not given. Run: roc setup")
    if mode == "cloud" and not cloud_allowed:
        # Never quietly load a multi-gigabyte local model instead: local is opt-in.
        raise SystemExit("A cloud worker needs cloud consent. Run: roc setup, or pick 'Use local model'.")
    if model and providers.is_cloud(model):
        if not providers.available(model):
            _provider, _remote, config = providers.parse_model(model)
            raise SystemExit("Cloud key missing: set %s (roc provider setup)" % config["key_env"])
        return model, cloud_allowed
    if mode == "local":
        local = draft.pick_model(model)
        if not local:
            raise SystemExit("Local mode needs an installed model. Run: roc local-ai")
        return local, cloud_allowed
    # Cloud-first: an installed local model is ignored unless the link named it.
    model = cloud_default()
    if model:
        return model, cloud_allowed
    local = draft.pick_model(model)
    if local:
        return local, cloud_allowed
    raise SystemExit("No cloud model key is set, and no local model is installed.\n"
                     "  Save a cloud key:      roc provider setup\n"
                     "  Or use a local model:  roc local-ai")


def main_args(payload, argv=()):
    """Run a worker described by a signed handoff config (see roc.handoff).

    Cloud is the default: no Ollama, no Docker, no GPU. Local mode is only used
    when the config asked for it explicitly.
    """
    import argparse
    from roc import providers
    ap = argparse.ArgumentParser(prog="roc launch", description="Run the worker from the signed setup config.")
    ap.add_argument("--client", help="override the client from the config")
    ap.add_argument("--model", help="override the model from the config")
    ap.add_argument("--workers", help="bounded concurrent lease loops (1-256 or auto)")
    ap.add_argument("--rounds", type=int, help="AI tries per function")
    ap.add_argument("--max-size", type=int, help="skip functions bigger than this")
    ap.add_argument("--jobs", type=int, help="stop after this many functions")
    ap.add_argument("--order", choices=["auto", "best", "matched", "unmatched", "easiest", "random"],
                    help="which functions to lease first")
    ap.add_argument("--verbosity", choices=["auto", "verbose", "compact"],
                    help="console detail; auto is verbose below 3 workers")
    ap.add_argument("--no-revng", action="store_true", help="never use Rev.ng hints")
    ap.add_argument("--family-exemplars", action="store_true", default=True,
                    help="use verified same-shape sources as compact family exemplars (default)")
    ap.add_argument("--lease-mode", choices=["function", "family"], default="function",
                    help="lease one function, or stay on one strict family")
    ap.add_argument("--family-id", help="strict 24-hex family fingerprint")
    ap.add_argument("--family-example", help="seed family from CLIENT:ADDRESS")
    ap.add_argument("--dry-run", action="store_true", help="print the plan without leasing a job")
    given = ap.parse_args(list(argv))

    user = payload.get("user") or ""
    server = (payload.get("server") or "").rstrip("/")
    if not USER_RE.match(user):
        raise SystemExit("Saved username is missing or invalid. Run: roc setup")
    if not server:
        raise SystemExit("No server address saved. Run: roc setup")
    token = payload.get("token") or None
    client = given.client or payload.get("client")
    model, cloud_allowed = resolve_model(payload)
    is_cloud = providers.is_cloud(model)
    rounds = given.rounds if given.rounds else 4
    max_size = given.max_size if given.max_size else 256
    workers = given.workers or ("auto" if is_cloud else 1)
    order = given.order or load_settings().get("worker_order", "auto")
    verbosity = given.verbosity or load_settings().get("worker_verbosity", "auto")
    family_id = given.family_id or (family_from_example(given.family_example) if given.family_example else None)
    if given.family_example and not family_id:
        raise SystemExit("Unknown family example; use CLIENT:ADDRESS")
    if family_id and not re.fullmatch(r"[0-9a-f]{24}", family_id):
        raise SystemExit("Family id must be 24 lowercase hex characters")
    if family_id and client:
        registered = register_family_targets(server, token, client, family_id)
        if registered:
            print("Family %s ready: %d sibling targets" % (family_id, registered))
    save_settings(user=user, server=server, token=token, cloud_allowed=cloud_allowed or None, model=model,
                  worker_order=order, worker_verbosity=verbosity)
    budget = providers.CloudBudget(HANDOFF_CLOUD_REQUESTS, HANDOFF_CLOUD_TOKENS,
                                   HANDOFF_CLOUD_COST_USD if providers.has_pricing(model) else None)
    print("Signed setup: user=%s client=%s server=%s model=%s (%s) workers=%s" %
          (user, client or "any", server, model, "cloud" if is_cloud else "local", workers))
    if is_cloud:
        print("Cloud model: prompts are bounded and leave this PC. Only accepted source is uploaded.")
    else:
        print("Local model: this PC does the work (heavy GPU and CPU load).")
    print("Leave this window open as long as you want to help. Close it to stop at any time.\n")
    if given.dry_run:
        return None
    keep_awake()
    return run_concurrent(server, user, token, model, rounds, max_size, not given.no_revng,
                          given.jobs, workers=workers, only=[client] if client else None,
                          cloud_allowed=cloud_allowed, cloud_budget=budget,
                          max_tokens=2048, thinking="auto", order=order,
                          verbosity=verbosity,
                          family_exemplars=given.family_exemplars,
                          lease_mode="family" if family_id else given.lease_mode,
                          family_id=family_id)


_ANNOUNCE_LOCK = threading.Lock()
_ANNOUNCED = set()


def announce_once(key, log, message):
    """Log a shared startup notice only once per process.

    Parallel worker loops would otherwise print the same privacy/idle
    notice once each. The first loop to arrive prints; the rest skip.
    """
    with _ANNOUNCE_LOCK:
        if key in _ANNOUNCED:
            return
        _ANNOUNCED.add(key)
    log(message)


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
        max_jobs=None, log=pretty_log, forever=False, only=None, source_only=False, targets=None,
        strategy="direct", cloud_allowed=False, cloud_budget=None, cloud_gate=None,
        diverse_candidates=1, cloud_min_size=0, cloud_fallback=None, seed=None,
        cloud_escalate=None, cloud_escalate_after=2, thinking=None, reasoning_effort=None,
        max_tokens=2048, examples_cache=None, source_cache=None, guided_mutations=False,
        order="auto", family_exemplars=True, lease_mode="function", family_state=None,
        family_lock=None, family_id=None):
    """forever: survive server/network outages (retry every minute) for overnight runs.
    only: restrict to these clients (one-click links).
    examples_cache/source_cache: shared across parallel loops so N workers do
    one /v1/examples fetch and one prompt-hint build per unit instead of N."""
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
    from roc import providers
    auto_model = model is None and not source_only
    # Link UI already verified an explicit choice. Do not turn a brief
    # /api/tags outage between setup and this point into a false no-model exit.
    model = (draft.pick_model(model) or model) if not source_only else "none"
    if not model and not source_only:
        raise SystemExit("AI workers need Ollama with a code model:  ollama pull qwen2.5-coder:7b\n"
                         "No GPU? You can still help by hand: roc claim / roc check / roc submit.")
    if not source_only and providers.is_cloud(model):
        if not cloud_allowed:
            raise SystemExit("Cloud model sends prompts outside this PC. Re-run with --allow-cloud.")
        if not providers.available(model):
            _provider, _remote, config = providers.parse_model(model)
            raise SystemExit("Cloud key is missing: set %s." % config["key_env"])
        announce_once(("privacy-cloud", providers.parse_model(model)[0]), log,
                        "Privacy: cloud worker sends bounded assembly, symbols, prompts, and source hints to %s. "
                        "No executable, key, or server lease leaves this PC." % providers.parse_model(model)[0])
    if cloud_escalate:
        if not providers.is_cloud(cloud_escalate):
            raise SystemExit("cloud_escalate must be a cloud model")
        if not cloud_allowed:
            raise SystemExit("Cloud escalation needs --allow-cloud")
        if not providers.available(cloud_escalate):
            _provider, _remote, config = providers.parse_model(cloud_escalate)
            raise SystemExit("Cloud key is missing: set %s" % config["key_env"])
        if not providers.is_cloud(model):
            announce_once(("privacy-escalate", providers.parse_model(cloud_escalate)[0]), log,
                          "Privacy: escalation may send bounded prompts to %s after repeated local stalls."
                          % providers.parse_model(cloud_escalate)[0])
    revng = not source_only and use_revng and draft.revng_available()
    worker = uuid.uuid4().hex[:12]
    session = uuid.uuid4().hex[:12]
    log("Worker %s as '%s' on %s | model %s | Rev.ng %s" % (worker, user, ", ".join(have), model,
                                                         "on" if revng else "off"))
    if providers.is_cloud(model):
        announce_once(("startup-note", "cloud"), log,
                      "Cloud model: work runs remotely; this PC stays idle. Ctrl+C or close the window to stop.")
    else:
        announce_once(("startup-note", "local"), log,
                      "Note: workers keep the GPU and CPU busy (fans, heat, power). Ctrl+C or close the window to stop.")
    done = matched = 0
    failures = 0
    family_state = family_state if family_state is not None else {"id": None}
    family_lock = family_lock or threading.Lock()
    if examples_cache is None:
        examples_cache = {}
    if source_cache is None:
        source_cache = {}
    while max_jobs is None or done < max_jobs:
        try:
            lease_order = "random" if lease_mode == "family" else order
            with family_lock if lease_mode == "family" else contextlib.nullcontext():
                family_hint = family_state["id"] if lease_mode == "family" else None
                job = api.call("/v1/lease", {"user": user, "worker": worker, "clients": have,
                                             "mode": "ai", "model": model, "max_size": max_size,
                                             "targets": targets, "order": lease_order,
                                             "family": family_hint})["job"]
                if lease_mode == "family" and job and job.get("family"):
                    family_state["id"] = job["family"]
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
            if lease_mode == "family" and family_state["id"]:
                with family_lock:
                    family_state["id"] = None
                continue
            if max_jobs is not None:
                break
            log("No open functions right now; checking again in 60 s.")
            time.sleep(60)
            continue
        done += 1
        job_model = draft.route_model(model, job) if auto_model else model
        if (cloud_escalate and job.get("size", 0) >= cloud_min_size and
                int((job.get("attempts_by_model") or {}).get(model, 0)) >= cloud_escalate_after):
            job_model = cloud_escalate
            log("  escalate: %s stalled on %d-byte job -> %s" % (model, job.get("size", 0), job_model))
        if providers.is_cloud(job_model) and job.get("size", 0) < cloud_min_size:
            fallback = cloud_fallback
            if not fallback:
                fallback = next((name for name in draft.ollama_models()
                                 if name == "qwen2.5-coder:7b" or name.startswith("qwen2.5-coder:7b")), None)
            if fallback:
                job_model = fallback
                log("  route: %d-byte job -> local fallback %s" % (job.get("size", 0), job_model))
        think, effort = auto_reasoning(job, thinking, reasoning_effort, job_model)
        if thinking == "auto" and think == "disabled":
            log("  auto-think: thinking disabled")
        provider_options = {"allow_cloud": cloud_allowed, "budget": cloud_budget,
                            "gate": cloud_gate, "diverse_candidates": diverse_candidates,
                            "seed": seed, "max_tokens": max_tokens,
                            "guided_mutations": guided_mutations,
                            "family_exemplars": family_exemplars}
        if providers.is_cloud(job_model):
            provider_options["retry_forever"] = True
            provider_options["on_retry"] = lambda error, retries, delay: log(
                "  cloud retry %d (%s); waiting %ds." % (retries, error, delay))
        if rounds == "auto" and (job_model or "").startswith("deepseek:"):
            provider_options["source_hint_max_size"] = 128
        if think is not None:
            provider_options["thinking"] = think
        if effort is not None:
            provider_options["reasoning_effort"] = effort
        score = work_one(api, user, job, info, job_model, rounds, revng, log, examples_cache, source_cache,
                         session, source_only, strategy, provider_options)
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
                   source_only=False, targets=None, only=None, strategy="direct", cloud_allowed=False,
                   cloud_budget=None, cloud_gate=None, diverse_candidates=1,
                   cloud_min_size=0, cloud_fallback=None, seed=None,
                   cloud_escalate=None, cloud_escalate_after=2, thinking=None, reasoning_effort=None,
                   max_tokens=2048, guided_mutations=False, order="auto", verbosity="auto",
                   family_exemplars=True, lease_mode="function", family_id=None):
    """Run a bounded number of independent lease loops.

    Server leases make workers safe to run in parallel. Cloud loops are
    I/O-bound (remote inference), so the cap is generous; local GPU loops
    should stay low so laptop users do not oversubscribe.
    """
    if str(workers).lower() == "auto":
        # Conservative: small models can overlap; large models stay serial.
        workers = 2 if "7b" in str(model).lower() else 1
    workers = max(1, min(int(workers or 1), MAX_WORKERS))
    if cloud_gate is None:
        from roc import providers
        cloud_gate = providers.CloudGate(workers)
    shared_examples, shared_sources = {}, {}
    family_state, family_lock = {"id": family_id}, threading.Lock()
    if workers == 1:
        worker_log = CompactLog(1, log) if verbosity == "compact" else log
        result = run(server, user, token, model, rounds, max_size, use_revng,
                     max_jobs, worker_log, forever=True, only=only, source_only=source_only, targets=targets,
                     strategy=strategy, cloud_allowed=cloud_allowed, cloud_budget=cloud_budget, cloud_gate=cloud_gate,
                     diverse_candidates=diverse_candidates, cloud_min_size=cloud_min_size,
                     cloud_fallback=cloud_fallback, seed=seed, cloud_escalate=cloud_escalate,
                     cloud_escalate_after=cloud_escalate_after, thinking=thinking,
                     reasoning_effort=reasoning_effort, max_tokens=max_tokens,
                     guided_mutations=guided_mutations, order=order,
                     family_exemplars=family_exemplars,
                     lease_mode=lease_mode,
                     family_state=family_state, family_lock=family_lock,
                     family_id=family_id,
                     examples_cache=shared_examples, source_cache=shared_sources)
        if verbosity == "compact":
            worker_log.finish()
        return result
    if max_jobs is None:
        quotas = [None] * workers
    else:
        base, extra = divmod(max(0, int(max_jobs)), workers)
        quotas = [base + (i < extra) for i in range(workers)]
    errors = []
    worker_log = CompactLog(workers, log) if verbosity == "compact" or (verbosity == "auto" and workers >= 3) else log
    if not source_only:
        setup.compilers()
    from roc import refsource
    if refsource.TREE.is_dir():
        refsource.build_index(log=log)

    def worker_loop(index):
        try:
            run(server, user, token, model, rounds, max_size, use_revng,
                quotas[index], worker_log, forever=True, only=only, source_only=source_only, targets=targets,
                strategy=strategy, cloud_allowed=cloud_allowed, cloud_budget=cloud_budget, cloud_gate=cloud_gate,
                diverse_candidates=diverse_candidates, cloud_min_size=cloud_min_size,
                cloud_fallback=cloud_fallback, seed=seed, cloud_escalate=cloud_escalate,
                cloud_escalate_after=cloud_escalate_after, thinking=thinking,
                reasoning_effort=reasoning_effort, max_tokens=max_tokens,
                guided_mutations=guided_mutations, order=order,
                family_exemplars=family_exemplars,
                lease_mode=lease_mode,
                family_state=family_state, family_lock=family_lock,
                family_id=family_id,
                examples_cache=shared_examples, source_cache=shared_sources)
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
    if workers > 3:
        worker_log.finish()


def work_one(api, user, job, info, model, rounds, revng, log, examples_cache=None,
             source_cache=None, session=None, source_only=False, strategy="direct", provider_options=None):
    from roc import providers
    compact_log = isinstance(log, CompactLog)
    output = log
    progress = {"stage": "starting", "at": time.monotonic(), "began": time.monotonic()}
    stalled = threading.Event()

    def stage(name):
        progress["stage"] = name
        progress["at"] = time.monotonic()
        progress["began"] = progress["at"]

    def job_log(message):
        progress["at"] = time.monotonic()
        output(message)

    log = job_log
    family_exemplars = bool((provider_options or {}).get("family_exemplars"))
    client, addr = job["client"], job["addr"]
    flags = info["clients"][client].get("flags")
    log("[%s %s] %d B, %s, best so far %d%%" % (client, addr, job["size"], job["unit"], job["score"]))
    stop = threading.Event()
    started = time.monotonic()
    result, improved, failure = 0, False, None
    family_propagated = False
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
        if stalled.is_set():
            raise TimeoutError("job stalled; restarting worker")
        if time.monotonic() >= deadline:
            raise TimeoutError("job exceeded 600-second worker limit")

    def watchdog():
        while not stop.wait(30):
            quiet = int(time.monotonic() - progress["at"])
            if quiet >= 30:
                output("  still working (%ds): %s." % (quiet, progress["stage"]))
                progress["at"] = time.monotonic()
            if time.monotonic() - progress["began"] >= 300:
                stalled.set()
                output("  stuck 5m in %s; restarting job after current call." % progress["stage"])
                return

    threading.Thread(target=beat, daemon=True).start()
    threading.Thread(target=watchdog, daemon=True).start()
    try:
        stage("reading target")
        code, relocs, _ = match.target(client, addr)
        asm = match.disasm(code, int(addr, 16))
        facts = draft.facts_from_asm(asm)
        facts.update(draft.target_data_facts(client, code, relocs))
        row = match._functions(client)[addr]
        family_id = None
        if family_exemplars:
            from roc import families
            family_id = families.fingerprint(row, asm)
            try:
                api.call("/v1/family", {"client": client, "addr": addr, "family": family_id})
            except RuntimeError:
                # Older servers lack fingerprint registration; shape mode below
                # remains compatible until server restart/update.
                family_id = None
        facts.update({k: row[k] for k in ("call_targets", "callers", "external_calls", "imports", "strings", "data_refs",
                                           "global_reads", "global_writes",
                                           "virtual_slots", "stack_args", "this_reads", "this_writes",
                                           "calling_convention", "branches", "constants", "siblings") if row.get(k)})
        from roc import auto
        stage("checking deterministic candidates")
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
        stage("checking 2016 source candidates")
        source_candidate = refsource.compile_candidates(client, addr, job["unit"], flags, limit=2, log=log)
        ensure_lease()
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
        example_key = (job["unit"], job.get("shape"), family_id)
        if example_key not in examples_cache[client]:
            quarantined = metrics.quarantined_keys()
            if family_exemplars and not family_id:
                examples_cache[client][example_key] = []
            else:
                strict = "&strict=1" if family_exemplars else ""
                family_query = "&family=%s" % quote(family_id) if family_id else ""
                path = "/v1/examples?client=%s&unit=%s&shape=%s&n=%d%s%s" % (
                    quote(client), quote(job["unit"]), quote(job.get("shape") or ""),
                    1 if family_exemplars else 2, strict, family_query)
                stage("loading verified examples")
                examples_cache[client][example_key] = [e["source"] for e in api.call(path)
                                                       if (client, e.get("addr")) not in quarantined]
        examples = examples_cache[client][example_key]
        if family_exemplars and examples and family_id:
            from roc import auto as _auto
            propagated = _auto.family_propagate(asm, examples[0])
            if propagated:
                stage("testing family source")
                try:
                    propagated_score, _, _, _ = match.check_text(client, addr, propagated, flags)
                except match.CompileError:
                    propagated_score = 0
                if propagated_score > job["score"]:
                    r = api.call("/v1/submit", {"lease": job["lease"], "user": user,
                                                "worker": job.get("worker"), "model": job.get("model"),
                                                "client": client, "addr": addr,
                                                "score": propagated_score, "source": propagated})
                    log("  family propagation submitted %d%%" % r["stored"])
                    family_propagated = True
                    result, improved = r["stored"], True
                    return r["stored"]
        source_key = (client, job["unit"], tuple(facts.get("strings", ())),
                      tuple(refsource._target_terms(facts)), int(facts.get("calls", 0) or 0),
                      int(facts.get("branch_count", 0) or 0))
        if source_key not in source_cache:
            source_cache[source_key] = refsource.prompt_hints(job["unit"], target_facts=facts, client=client)
        source_hints = source_cache[source_key]
        # Tiny leaf functions are cheaper to solve from direct asm/source facts;
        # reserve Rev.ng CPU time for larger or structurally uncertain targets.
        run_revng = revng and (job.get("size", 0) > 48 or job.get("calls", 0) or
                               not job.get("source_confidence", 0))
        revng_started = time.monotonic()
        stage("running Rev.ng" if run_revng else "preparing model prompt")
        hint = draft.revng_c(code, int(addr, 16)) if run_revng else None
        phase_seconds["revng"] = round(time.monotonic() - revng_started, 3)
        llm_started = time.monotonic()
        llm_start = (job["source"], job["score"])
        if source_candidate and source_candidate[0] > job["score"]:
            llm_start = (source_candidate[1], source_candidate[0])
        job_rounds = resolve_rounds(job, rounds, model)
        stage("waiting for cloud model" if providers.is_cloud(model) else "waiting for local model")
        score, src = draft.llm_rounds(client, addr, model, draft.model_rounds(model, job_rounds), hint, llm_start,
                                      log, flags, examples, source_hints, facts, round_stats, strategy=strategy,
                                      provider_options=provider_options)
        ensure_lease()
        phase_seconds["llm"] = round(time.monotonic() - llm_started, 3)
        if src and score > job["score"]:
            r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "worker": job.get("worker"),
                                        "model": job.get("model"), "client": client, "addr": addr,
                                        "score": score, "source": src})
            log("  submitted %d%% (%s)" % (r["stored"], "verified by server" if r["verified"] else "not re-checked"))
            if not compact_log:
                log(_usage_line(session, round_stats))
            result, improved = r["stored"], True
            return r["stored"]
        failure_reason = "bad_reply" if not src else "no_gain"
        if source_candidate and source_candidate[0] > job["score"]:
            candidate_score, candidate_source, candidate_path = source_candidate
            r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "worker": job.get("worker"),
                                        "model": job.get("model"), "client": client, "addr": addr,
                                        "score": candidate_score, "source": candidate_source})
            log("  retained partial 2016 source candidate %d%% (%s)" % (r["stored"], candidate_path))
            if not compact_log:
                log(_usage_line(session, round_stats))
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
        elif getattr(error, "category", ""):
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
            generated = [r for r in round_stats if isinstance(r.get("round"), int)]
            provider_row = next((r for r in reversed(generated) if r.get("provider")), {})
            metrics.record(session, event="job", client=client, addr=addr, unit=job["unit"], model=model,
                           strategy=strategy,
                           size=job.get("size", 0), base_score=job.get("score", 0), score=result,
                           score_gain=max(result - job.get("score", 0), 0), improved=improved,
                           source_hints=len(source_hints) if 'source_hints' in locals() else 0,
                           family_id=family_id if 'family_id' in locals() else None,
                           family_exemplar=bool(('examples' in locals()) and examples and family_id),
                           family_propagated=family_propagated,
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
                           provider=provider_row.get("provider", "local"),
                           provider_model=provider_row.get("provider_model", model),
                           provider_endpoint_kind=providers.parse_model(model)[2].get("kind", "ollama"),
                           compiler_flags=flags, seed=(provider_options or {}).get("seed"),
                           input_tokens=sum(r.get("input_tokens", 0) for r in generated),
                           output_tokens=sum(r.get("output_tokens", 0) for r in generated),
                           cached_tokens=sum(r.get("cached_tokens", 0) for r in generated),
                           generation_seconds=round(sum(r.get("generation_seconds", 0) for r in generated), 3),
                           estimated_cost=metrics.known_generation_cost(generated),
                           failure_reason=failure_reason,
                           failure=failure)


def resolve_rounds(job, rounds, model=None):
    if rounds != "auto":
        return rounds
    return 2 if job.get("size", 0) <= 48 or (model or "").startswith("deepseek:") else 4


def auto_reasoning(job, thinking=None, reasoning_effort=None, model=None):
    """Resolve auto reasoning; explicit values pass through untouched.

    Tiny getters/setters truncate when reasoning eats the output budget,
    so auto disables thinking (and drops effort to low) for them. Anything
    else keeps the provider default, except DeepSeek: source-hidden trials
    repeatedly exhausted its reasoning budget without returning source.
    """
    tiny = not (job.get("size", 999999) > 64 or job.get("calls", 0))
    if thinking == "auto":
        thinking = "disabled" if tiny or (model or "").startswith("deepseek:") else None
    if reasoning_effort == "auto":
        reasoning_effort = "low" if tiny else None
    return thinking, reasoning_effort


def _usage_line(session, round_stats):
    """Per-job tokens plus running session total (including this job)."""
    generated = [r for r in round_stats if isinstance(r.get("round"), int)]
    job_in = sum(r.get("input_tokens", 0) or 0 for r in generated)
    job_out = sum(r.get("output_tokens", 0) or 0 for r in generated)
    if not session:
        return "  tokens used: %d (in:%d out:%d)" % (job_in + job_out, job_in, job_out)
    prior = metrics.session_totals(session)
    total_in, total_out = prior["input_tokens"] + job_in, prior["output_tokens"] + job_out
    return ("  tokens used: %d (in:%d out:%d), total usage: %d (in:%d out:%d)" %
            (job_in + job_out, job_in, job_out, total_in + total_out, total_in, total_out))


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
