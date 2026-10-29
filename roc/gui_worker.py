"""Controlled worker process. JSON commands on stdin; JSON events on stdout."""
import json
import os
import re
import sys
import threading
import time
from types import SimpleNamespace

from roc import clients, providers, worker, setup

DEFAULTS = dict(client="", server="", user="", model="", workers=1, rounds=4,
                max_size=256, max_tokens=2048, strategy="direct", order="random",
                thinking="auto", reasoning_effort=None, use_revng=False,
                use_remill=True,
                min_score=None, max_score=None, diverse_candidates=1,
                guided_mutations=False, near_repair=False, source_only=False,
                cloud_allowed=False, cloud_concurrency="auto", max_cloud_requests=None,
                max_cloud_tokens=None, max_cloud_cost=None, lease_mode="function",
                unit_name=None, family_id=None, targets=None, library="",
                native_batch_files=40, native_compile_workers="auto", native_context="methods", native_generation="auto", native_compile_batch=4)
LIVE = {"workers", "model", "rounds", "max_size", "max_tokens", "strategy", "order",
        "thinking", "reasoning_effort", "use_revng", "use_remill", "min_score", "max_score",
        "diverse_candidates", "guided_mutations", "near_repair", "max_cloud_requests",
        "max_cloud_tokens", "max_cloud_cost", "native_batch_files", "native_compile_workers", "native_context", "native_generation", "native_compile_batch"}


def prepare_clients(config, log):
    """Fetch and analyze the selected Match client before worker loops start."""
    from roc import analyze
    registered = clients.load()
    names = sorted(registered) if not config["client"] else [config["client"]]
    for name in names:
        entry = registered[name]
        if clients.status(name, entry) != "ok":
            log("Match setup: fetching %s client binary." % name)
            if not clients.ensure(name):
                raise SystemExit("Match setup needs %s. Run: roc client-fetch %s" % (name, name))
        build = entry.get("compiler_build")
        if build and build not in setup.compilers():
            log("Match setup: installing %s." % setup.NAMES.get(build, "required compiler"))
            setup.install_compilers(only=[build], assume_yes=True)
            if build not in setup.compilers():
                raise SystemExit("Match setup needs %s. Run: install.cmd" % setup.NAMES.get(build, "the required compiler"))
        functions = clients.ROOT / "work" / name / "functions.jsonl"
        if not functions.exists():
            log("Match setup: analyzing %s." % name)
            analyze.analyze(name, clients.exe_path(name, entry))


def validate(values, base=None, check_model=True):
    if not isinstance(values, dict) or set(values) - set(DEFAULTS):
        raise ValueError("Unknown worker settings")
    config = {**DEFAULTS, **(base or {}), **values}
    for key, low, high in (("workers", 1, 256), ("rounds", 1, 100), ("max_size", 0, 1000000),
                           ("native_batch_files", 1, 1024), ("native_compile_workers", 1, 64),
                           ("native_compile_batch", 1, 32),
                           ("max_tokens", 128, 32768), ("diverse_candidates", 1, 16),
                           ("cloud_concurrency", 1, 256)):
        if key in ("workers", "rounds", "max_tokens", "cloud_concurrency", "native_compile_workers") and config[key] == "auto":
            continue
        if type(config[key]) is not int or not low <= config[key] <= high:
            raise ValueError("%s must be %d-%d" % (key, low, high))
    for key in ("min_score", "max_score"):
        if config[key] is not None and (type(config[key]) is not int or not 0 <= config[key] <= 100):
            raise ValueError("%s must be 0-100" % key)
    if config["min_score"] is not None and config["max_score"] is not None and config["min_score"] > config["max_score"]:
        raise ValueError("Minimum score exceeds maximum score")
    for key in ("max_cloud_requests", "max_cloud_tokens", "max_cloud_cost"):
        value = config[key]
        if value is not None and (type(value) not in (int, float) or not 0 < value < float("inf")):
            raise ValueError("%s must be positive" % key)
        if key != "max_cloud_cost" and value is not None and type(value) is not int:
            raise ValueError("%s must be an integer" % key)
    for key, choices in (("strategy", ("auto", "direct", "structured", "reference")),
                          ("order", ("auto", "best", "matched", "unmatched", "easiest", "random")),
                          ("thinking", ("auto", "enabled", "disabled")),
                          ("reasoning_effort", (None, "auto", "low", "medium", "high", "max")),
                          ("lease_mode", ("function", "family", "unit", "native"))):
        if config[key] not in choices:
            raise ValueError("Invalid %s" % key)
    if config["native_context"] not in ("methods", "file"):
        raise ValueError("Invalid native context")
    if config["native_generation"] not in ("auto", "edits", "method"):
        raise ValueError("Invalid native generation mode")
    if config["lease_mode"] == "native":
        if config["client"] not in ("", "2008-06"):
            raise ValueError("Integrator currently supports 2008-06")
        if config["source_only"]:
            raise ValueError("Integrator requires a model")
        config["client"] = "2008-06"
    for key in ("use_revng", "use_remill", "guided_mutations", "near_repair", "source_only", "cloud_allowed"):
        if type(config[key]) is not bool:
            raise ValueError("Invalid %s" % key)
    if not worker.USER_RE.fullmatch(config["user"]):
        raise ValueError("Username needs 2-32 letters, digits, . _ -")
    from roc.link import SERVER_RE
    if not SERVER_RE.fullmatch(config["server"]):
        raise ValueError("Enter server host:port or http(s) URL")
    if config["client"] and config["client"] not in clients.load():
        raise ValueError("Unknown client")
    from roc.libs import NAMES
    if config["library"] and config["library"] not in NAMES:
        raise ValueError("Unknown library")
    if config["lease_mode"] == "unit" and not config["unit_name"]:
        raise ValueError("Unit lease requires a unit name")
    if config["family_id"] and not re.fullmatch(r"[0-9a-f]{24}", config["family_id"]):
        raise ValueError("Family fingerprint needs 24 lowercase hex digits")
    if config["targets"] is not None:
        if not config["client"] or not isinstance(config["targets"], list) or any(
                not isinstance(row, dict) or row.get("client") != config["client"] or
                not re.fullmatch(r"[0-9a-f]{8}", row.get("addr", "")) for row in config["targets"]):
            raise ValueError("Targets need selected client and eight-digit hex addresses")
    model = config["model"]
    if not isinstance(model, str):
        raise ValueError("Invalid model")
    if not config["source_only"]:
        if not model:
            raise ValueError("Select a model or enable source-only")
        if providers.is_cloud(model):
            if not config["cloud_allowed"]:
                raise ValueError("Cloud consent required")
            if check_model and not providers.available(model):
                raise ValueError(providers.credential_hint(model))
        elif check_model and not worker.draft.pick_model(model):
            raise ValueError("Local model unavailable; run roc model")
    return config


class Control:
    def __init__(self, config, emit):
        self.config = config
        self.emit = emit
        self.condition = threading.Condition()
        self.paused = self.stopping = False
        self.revision = 1
        self.budget = providers.CloudBudget(config["max_cloud_requests"], config["max_cloud_tokens"], config["max_cloud_cost"])
        self.cost_known = config["source_only"] or not providers.is_cloud(config["model"]) or providers.has_pricing(config["model"])
        self.applied = {}
        self.started_at = self.last_report = time.monotonic()
        self.completed = self.matched = self.improved = self.errors = 0
        self.started_jobs = {}

    @property
    def workers(self):
        return worker.resolve_workers(self.config["workers"], self.config["model"], self.config["source_only"])

    def command(self, command):
        with self.condition:
            action = command["action"]
            if action == "update":
                if set(command["config"]) - LIVE:
                    raise ValueError("These settings need a new session")
                self.config = validate(command["config"], self.config)
                if not self.config["source_only"] and providers.is_cloud(self.config["model"]) and not providers.has_pricing(self.config["model"]):
                    self.cost_known = False
                with self.budget._lock:
                    self.budget.max_requests = self.config["max_cloud_requests"]
                    self.budget.max_tokens = self.config["max_cloud_tokens"]
                    self.budget.max_cost = self.config["max_cloud_cost"]
                self.revision += 1
            elif action == "pause":
                self.paused = True
            elif action == "resume":
                self.paused = False
            elif action == "stop":
                self.stopping = True
            else:
                raise ValueError("Unknown control action")
            self.condition.notify_all()
            self.emit("control", config=self.config, revision=self.revision,
                      paused=self.paused, stopping=self.stopping, request=command.get("request"))

    def before_lease(self, slot):
        with self.condition:
            while self.paused and not self.stopping and slot < self.workers:
                self.condition.wait()
            if self.stopping or slot >= self.workers:
                return None
            if self.applied.get(slot) != self.revision:
                self.applied[slot] = self.revision
                self.emit("applied", slot=slot, revision=self.revision)
            return dict(self.config)

    def wait(self, seconds):
        with self.condition:
            if not self.stopping:
                self.condition.wait(seconds)

    def started(self, slot, job):
        with self.condition:
            self.started_jobs[slot] = time.monotonic()
        self.emit("job_started", slot=slot, client=job["client"], addr=job["addr"],
                  unit=job.get("unit"), size=job.get("size"), previous=job.get("score", 0))

    def finished(self, slot, job, score):
        with self.condition:
            now = time.monotonic()
            self.completed += 1
            receipt = job.get("receipt") or {}
            gain = bool(receipt.get("verified") and receipt.get("improved")) if "receipt" in job else score > job.get("score", 0)
            self.matched += gain and score == 100
            self.improved += gain and score != 100
            self.emit("job_finished", slot=slot, client=job["client"], addr=job["addr"], score=score,
                      unit=job.get("unit"), size=job.get("size"), previous=job.get("score", 0),
                      new_exact=gain and score == 100, improved=gain,
                      seconds=round(now - self.started_jobs.pop(slot, now), 1))
            if now - self.last_report >= 30:
                self.emit("benchmark", workers=self.workers, completed=self.completed,
                          matched=self.matched, improved=self.improved, errors=self.errors,
                          per_minute=round(self.completed * 60 / max(now - self.started_at, 1), 1))
                self.last_report = now
        with self.budget._lock:
            self.emit("usage", requests=self.budget.requests, tokens=self.budget.tokens,
                      cost=self.budget.cost if self.cost_known else None)
            exhausted = any(limit is not None and used >= limit for used, limit in (
                (self.budget.requests, self.budget.max_requests),
                (self.budget.tokens, self.budget.max_tokens), (self.budget.cost, self.budget.max_cost)))
        if exhausted:
            self.emit("log", slot=slot, message="Cloud budget cap reached; finishing session.")
            self.command({"action": "stop"})


def native_loop(config, control, emit):
    """Native integration: each pass lets the model edit native files that define waiting exact targets, submits
    locally proven edits as one verified batch; discovery continues while the server verifies."""
    from roc import integration, native_sweep, research
    outage_started = None
    def server_wait(error):
        nonlocal outage_started
        if error.category == 'auth_fail':
            emit('error', slot=0, message='Server authentication failed; saved proofs retained: ' + str(error))
            control.command({'action': 'stop'})
            return False
        if error.category in ('offline', 'server_fail'):
            if outage_started is None:
                outage_started = time.monotonic()
            if time.monotonic() - outage_started >= 7200:
                emit('error', slot=0, message='Server unreachable for two hours; saved proofs retained. Session stopped.')
                control.command({'action': 'stop'})
                return False
        emit('log', slot=0, message='Server request failed; saved proofs retained. Retry in 30s: ' + str(error))
        emit('stage', message='Waiting for server; retrying in 30s', task_status='running')
        control.wait(30)
        return not control.stopping
    if not providers.available(config["model"]):
        raise providers.ProviderError("provider_key", providers.credential_hint(config["model"]))
    spec = json.loads(json.dumps(research.recipes()["native-model-2008"]))
    emit('log', slot=0, message='Startup: validating ABI, RTTI and dependency compiler profiles')
    from roc.rebuild_install import prepare
    prepare(log=lambda message: emit('log', slot=0, message=message))
    worker.save_settings(user=config["user"], server=config["server"])
    emit("log", slot=0, message="Startup: syncing accepted native baseline (unchanged overlays are reused)")
    while not control.stopping:
        try:
            integration.command(SimpleNamespace(action="sync", server=config["server"], user=config["user"], token=None))
            outage_started = None
            break
        except worker.ApiFailure as error:
            if not server_wait(error):
                return
    emit("log", slot=0, message="Startup complete: selecting exact mined targets for parallel integration")
    def native_event(kind, **fields):
        emit(kind, **fields)
        if fields.get("error_category") in providers.FATAL_ERRORS or fields.get("error_category") == "cloud_budget":
            emit("error", slot=fields["slot"], message="Provider unavailable; session stopped. " + fields.get("error", ""))
            control.command({"action": "stop"})

    tried = set()
    file_offsets, retry_targets = {}, {}
    tried_revision = None
    target_offset = 0
    def remember(summary, step):
        nonlocal tried_revision
        revision = summary.get('base_revision')
        if revision is not None and revision != tried_revision:
            tried.clear()
            file_offsets.clear()
            retry_targets.clear()
            tried_revision = revision
        tried.update(summary.get('files_tried', []))
        retry_targets.update(summary.get('pending_files', {}))
        for rel in summary.get('files_tried', []):
            file_offsets[rel] = file_offsets.get(rel, target_offset) + step
    def report(message):
        emit('stage', message=str(message), task_status='running')
    def recover_pass(error):
        # A rejected candidate must not kill discovery or regenerate the same
        # files immediately. Native run archived their source and local proofs.
        path = native_sweep.ROOT / 'work/research/native-model-2008/summary.json'
        if path.exists():
            remember(json.loads(path.read_text()), current['native_compile_batch'])
        if isinstance(error, native_sweep.BaselineAdvanced):
            emit('stage', message='Accepted baseline advanced; rechecking saved proofs without AI', task_status='running')
            control.wait(1)
            return
        control.errors += 1
        emit('error', slot=0, message='Native pass failed; proofs retained. Continuing in 30s: ' + str(error))
        emit('stage', message='Recovering native pass; retrying in 30s', task_status='running')
        control.wait(30)
    pending = set()
    def refresh_pending():
        if not pending:
            return False
        api = worker.Api(config["server"], worker.load_settings().get("token"))
        advanced = False
        try:
            for identifier in list(pending):
                for job in api.call("/v1/integration?id=" + identifier)["jobs"]:
                    if job["state"] not in ("accepted", "rejected", "failed"):
                        continue
                    pending.remove(identifier)
                    credits = (job.get("receipt") or {}).get("credits", 0) if job["state"] == "accepted" else 0
                    control.matched += credits
                    advanced |= job["state"] == "accepted"
                    emit("native_accepted" if credits else "log", credits=credits,
                         message="Native batch %s: %s · %d new server verified" % (identifier[:8], job["state"], credits))
            emit("benchmark", workers=control.workers, completed=control.completed,
                 matched=control.matched, improved=0, errors=control.errors)
        except worker.ApiFailure:
            pass
        finally:
            api.close()
        return advanced
    while not control.stopping:
        current = control.before_lease(0)
        if current is None:
            break
        if refresh_pending():
            tried.clear()
            file_offsets.clear()
        for slot in range(control.workers):
            emit("applied", slot=slot, revision=control.revision)
        inflight = providers.cloud_slots(current["model"],control.workers,current["cloud_concurrency"])
        emit("stage", message="Integrator: %d file workers · %d AI requests · %d compilers · up to %d files per batch" % (
            control.workers, inflight, native_sweep.resolve_compile_workers(current["native_compile_workers"], control.workers), current["native_batch_files"]))
        spec["native_sweep"].update(llm=current["model"], model=current["model"],
            rounds=3 if current["rounds"] == "auto" else current["rounds"], wait=False, exclude_files=sorted(tried),
            max_files=current["native_batch_files"], context=current["native_context"],
            generation=current["native_generation"],
            compile_batch=current["native_compile_batch"],
            target_offset=target_offset, resume_saved=True, rolling_workers=True,
            file_offsets=dict(file_offsets), retry_targets=dict(retry_targets), tried_revision=tried_revision,
            compile_workers=current["native_compile_workers"],
            provider_options={"allow_cloud": current["cloud_allowed"], "budget": control.budget,
                "gate": providers.CloudGate(inflight),
                "max_tokens": 3072 if current["max_tokens"] == "auto" else current["max_tokens"],
                "thinking": current["thinking"], "reasoning_effort": current["reasoning_effort"] if current["reasoning_effort"] not in (None, "auto") else
                    ("low" if current["model"].startswith(("codex:", "claude:")) else None),
                "event": native_event,
                "before_request": lambda: control.before_lease(0) is not None})
        try:
            summary = native_sweep.run(spec, "native-model-2008", server=config["server"] or None, jobs=control.workers,
                                       log=report)
            outage_started = None
        except worker.ApiFailure as error:
            if error.category == 'bad_request':
                outage_started = None
                recover_pass(error)
            elif not server_wait(error):
                break
            continue
        except (Exception, SystemExit) as error:  # noqa: BLE001 - failed native passes preserve proofs and retry
            if getattr(error, 'category', '') in providers.FATAL_ERRORS or getattr(error, 'category', '') == 'cloud_budget':
                emit('error', slot=0, message=str(error))
                control.command({'action': 'stop'})
                break
            outage_started = None
            recover_pass(error)
            continue
        emit("log", slot=0, message="native pass: %s, %s local exact, %s verified" % (
            summary.get("state"), summary.get("local_exact", 0), summary.get("new_verified", 0)))
        remember(summary, current['native_compile_batch'])
        if summary.get("job"):
            pending.add(summary["job"])
        control.completed += len(summary.get("files_tried", []))
        control.matched += summary.get("new_verified", 0)
        emit("benchmark", workers=control.workers, completed=control.completed,
             matched=control.matched, improved=0, errors=control.errors)
        with control.budget._lock:
            emit("usage", requests=control.budget.requests, tokens=control.budget.tokens,
                 cost=control.budget.cost if control.cost_known else None)
            exhausted = any(limit is not None and used >= limit for used, limit in (
                (control.budget.requests, control.budget.max_requests),
                (control.budget.tokens, control.budget.max_tokens), (control.budget.cost, control.budget.max_cost)))
        if exhausted:
            emit("log", slot=0, message="Cloud budget cap reached; finishing session.")
            control.command({"action": "stop"})
        if not summary.get("files_tried") and not summary.get("job"):
            emit("stage", message="Discovery cycle complete; checking updates and rotating targets within 60s", task_status='running')
            signature = None
            restart_at = time.monotonic() + 60
            while not control.stopping:
                if refresh_pending():
                    tried.clear()
                    file_offsets.clear()
                    break
                api = worker.Api(current["server"], worker.load_settings().get("token"))
                try:
                    status = next((row for row in api.call("/v1/status")["clients"] if row["client"] == "2008-06"), {})
                    changed = (status.get("matched"), status.get("integrated"), status.get("functions"), control.revision)
                    if signature is not None and changed != signature:
                        tried.clear()
                        file_offsets.clear()
                        break
                    signature = changed
                except worker.ApiFailure:
                    pass  # Keep local proofs while the shared service recovers.
                finally:
                    api.close()
                if time.monotonic() >= restart_at:
                    tried.clear()
                    file_offsets.clear()
                    target_offset += current['native_compile_batch']
                    report('Starting next discovery cycle with rotated pending targets')
                    break
                control.wait(30)
    for slot in range(control.workers):
        emit("slot_stopped", slot=slot)


def command_lines(stream):
    """Read controller JSON without holding stdin's buffered lock at shutdown."""
    pending = b''
    while True:
        chunk = os.read(stream.fileno(), 65536)
        if not chunk:
            if pending:
                yield pending.decode('utf-8')
            return
        pending += chunk
        while b'\n' in pending:
            line, pending = pending.split(b'\n', 1)
            yield line.decode('utf-8')


def main(initial=None, receive_commands=True):
    commands = command_lines(sys.stdin)
    initial = initial or json.loads(next(commands))
    if not receive_commands:
        initial["terminal"] = True
    initial["config"] = validate(initial["config"])
    if initial["config"].get("lease_mode") == "native" and not os.environ.get("ROC_INTEGRATOR_PRIVATE"):
        from roc import integrator
        return integrator.run_private(initial, receive_commands, commands)
    output_lock = threading.Lock()

    def emit(event, **fields):
        with output_lock:
            if initial.get("terminal"):
                slot = "w%d" % (fields["slot"] + 1) if "slot" in fields else "roc"
                if event == "native_result":
                    print("[%s] %s +%d local exact (awaiting verification) | %.1fs%s" % (
                        slot, fields["file"], fields["local_exact"], fields["seconds"],
                        " | " + fields["error"] if fields.get("error") else ""), flush=True)
                elif event == "native_started":
                    print("[%s] %s | baseline" % (slot, fields["file"]), flush=True)
                elif event == 'native_partial':
                    print('[%s] %s %s | partial %.3f%% -> %.3f%% | local search, no exact credit' % (
                        slot, fields['file'], fields['addr'], fields['previous'], fields['score']), flush=True)
                elif event == "native_progress":
                    if "Requesting" in fields["message"] or "new exact" in fields["message"]:
                        print("[%s] %s | %s" % (slot, fields["file"], fields["message"]), flush=True)
                elif event in ("log", "error", "stage", "native_accepted"):
                    print("[%s] %s" % (slot, fields.get("message", "")), flush=True)
            else:
                print("ROC_EVENT " + json.dumps(dict(event=event, **fields)), flush=True)

    config = validate(initial["config"])
    control = Control(config, emit)
    emit("control", config=config, revision=1, paused=False, stopping=False)
    emit("log", slot=0, message="Startup: checking installed client binary, historical compiler and analysis")
    prepare_clients(config, lambda message: emit("log", slot=0, message=message))
    emit("log", slot=0, message="Startup: client dependencies ready")

    def receive():
        for line in commands:
            try:
                control.command(json.loads(line))
            except (ValueError, KeyError, TypeError) as error:
                emit("rejected", message=str(error))
        control.command({"action": "stop"})

    if receive_commands:
        threading.Thread(target=receive, daemon=True).start()
    shared_examples, shared_sources = {}, {}
    family_state, family_lock = {"id": config["family_id"]}, threading.Lock()
    gate = providers.CloudGate(providers.cloud_slots(config["model"],control.workers,config["cloud_concurrency"]))
    threads, failures = {}, []

    def run_slot(slot):
        with control.condition:
            current = dict(control.config)
        options = {key: value for key, value in current.items() if key not in
                   ("workers", "client", "max_cloud_requests", "max_cloud_tokens", "max_cloud_cost", "cloud_concurrency",
                    "native_batch_files", "native_compile_workers", "native_context", "native_generation", "native_compile_batch")}
        options.update(token=initial.get("token"), only=[current["client"]] if current["client"] else None,
                       model=current["model"] or None, forever=True, cloud_budget=control.budget, cloud_gate=gate,
                       examples_cache=shared_examples, source_cache=shared_sources,
                       family_state=family_state, family_lock=family_lock, control=control, slot=slot,
                       log=lambda message: emit("log", slot=slot, message=str(message)))
        try:
            from roc import telemetry
            telemetry.local.emit = lambda event, **fields: emit(event, slot=slot, **fields)
            worker.run(**options)
        except (Exception, SystemExit) as error:
            failures.append(error)
            with control.condition:
                control.errors += 1
            emit("error", slot=slot, message=str(error))
            control.command({"action": "stop"})
        finally:
            emit("slot_stopped", slot=slot)

    worker.keep_awake()
    if config["lease_mode"] == "native":
        native_loop(config, control, emit)
        return
    while True:
        with control.condition:
            if not control.stopping:
                for slot in range(control.workers):
                    if slot not in threads or not threads[slot].is_alive():
                        threads[slot] = threading.Thread(target=run_slot, args=(slot,), daemon=True)
                        threads[slot].start()
            if control.stopping and not any(thread.is_alive() for thread in threads.values()):
                break
            control.condition.wait(0.3)
    if failures:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
