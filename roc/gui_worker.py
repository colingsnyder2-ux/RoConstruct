"""Controlled worker process. JSON commands on stdin; JSON events on stdout."""
import json
import re
import sys
import threading
import time

from roc import clients, providers, worker

DEFAULTS = dict(client="", server="", user="", model="", workers=1, rounds=4,
                max_size=256, max_tokens=2048, strategy="direct", order="random",
                thinking="auto", reasoning_effort=None, use_revng=False,
                min_score=None, max_score=None, diverse_candidates=1,
                guided_mutations=False, near_repair=False, source_only=False,
                cloud_allowed=False, cloud_concurrency=1, max_cloud_requests=None,
                max_cloud_tokens=None, max_cloud_cost=None, lease_mode="function",
                unit_name=None, family_id=None, targets=None)
LIVE = {"workers", "model", "rounds", "max_size", "max_tokens", "strategy", "order",
        "thinking", "reasoning_effort", "use_revng", "min_score", "max_score",
        "diverse_candidates", "guided_mutations", "near_repair", "max_cloud_requests",
        "max_cloud_tokens", "max_cloud_cost"}


def validate(values, base=None, check_model=True):
    if not isinstance(values, dict) or set(values) - set(DEFAULTS):
        raise ValueError("Unknown worker settings")
    config = {**DEFAULTS, **(base or {}), **values}
    for key, low, high in (("workers", 1, 256), ("rounds", 1, 100), ("max_size", 1, 1000000),
                           ("max_tokens", 128, 8192), ("diverse_candidates", 1, 16),
                           ("cloud_concurrency", 1, 256)):
        if key in ("workers", "rounds", "max_tokens", "cloud_concurrency") and config[key] == "auto":
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
                          ("lease_mode", ("function", "family", "unit"))):
        if config[key] not in choices:
            raise ValueError("Invalid %s" % key)
    for key in ("use_revng", "guided_mutations", "near_repair", "source_only", "cloud_allowed"):
        if type(config[key]) is not bool:
            raise ValueError("Invalid %s" % key)
    if not worker.USER_RE.fullmatch(config["user"]):
        raise ValueError("Username needs 2-32 letters, digits, . _ -")
    from roc.link import SERVER_RE
    if not SERVER_RE.fullmatch(config["server"]):
        raise ValueError("Enter server host:port or http(s) URL")
    if config["client"] and config["client"] not in clients.load():
        raise ValueError("Unknown client")
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
                raise ValueError("Provider key missing; run roc provider setup")
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
            self.matched += score == 100
            self.improved += score > job.get("score", 0) and score != 100
            self.emit("job_finished", slot=slot, client=job["client"], addr=job["addr"], score=score,
                      unit=job.get("unit"), size=job.get("size"), previous=job.get("score", 0),
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


def main():
    initial = json.loads(sys.stdin.readline())
    output_lock = threading.Lock()

    def emit(event, **fields):
        with output_lock:
            print("ROC_EVENT " + json.dumps(dict(event=event, **fields)), flush=True)

    config = validate(initial["config"])
    control = Control(config, emit)
    emit("control", config=config, revision=1, paused=False, stopping=False)

    def receive():
        for line in sys.stdin:
            try:
                control.command(json.loads(line))
            except (ValueError, KeyError, TypeError) as error:
                emit("rejected", message=str(error))
        control.command({"action": "stop"})

    threading.Thread(target=receive, daemon=True).start()
    shared_examples, shared_sources = {}, {}
    family_state, family_lock = {"id": config["family_id"]}, threading.Lock()
    gate = providers.CloudGate(control.workers if config["cloud_concurrency"] == "auto" else config["cloud_concurrency"])
    threads, failures = {}, []

    def run_slot(slot):
        with control.condition:
            current = dict(control.config)
        options = {key: value for key, value in current.items() if key not in
                   ("workers", "client", "max_cloud_requests", "max_cloud_tokens", "max_cloud_cost", "cloud_concurrency")}
        options.update(token=initial.get("token"), only=[current["client"]] if current["client"] else None,
                       model=current["model"] or None, forever=True, cloud_budget=control.budget, cloud_gate=gate,
                       examples_cache=shared_examples, source_cache=shared_sources,
                       family_state=family_state, family_lock=family_lock, control=control, slot=slot,
                       log=lambda message: emit("log", slot=slot, message=str(message)))
        try:
            from roc import activity
            activity.local.emit = lambda event, **fields: emit(event, slot=slot, **fields)
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
