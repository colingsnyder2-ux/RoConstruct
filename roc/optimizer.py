"""Small, bounded, per-model worker configuration calibration."""
import hashlib
import json
import platform
import uuid
from concurrent.futures import ThreadPoolExecutor
from functools import lru_cache
import time


CONFIGS = (
    {"name": "fast", "rounds": 2, "max_tokens": 1024, "strategy": "direct"},
    {"name": "balanced", "rounds": 4, "max_tokens": 2048, "strategy": "direct"},
    {"name": "structured", "rounds": 4, "max_tokens": 2048, "strategy": "structured"},
)


def profile(model, settings=None):
    from roc import worker
    settings = settings if settings is not None else worker.load_settings()
    saved = (settings.get("optimizer_profiles") or {}).get(model)
    return saved if saved and saved.get("fingerprint") == fingerprint(model) else None


def clear_profile(model):
    from roc import worker
    settings = worker.load_settings()
    profiles = dict(settings.get("optimizer_profiles") or {})
    removed = profiles.pop(model, None) is not None
    if removed:
        worker.save_settings(optimizer_profiles=profiles)
    return removed


@lru_cache(maxsize=32)
def fingerprint(model):
    from roc import clients, draft, providers
    if providers.is_cloud(model):
        _name, remote, config = providers.parse_model(model)
        version = {"provider_model": remote, "endpoint": config["base_url"]}
    else:
        version = {"provider_model": model, "digest": "unknown"}
        try:
            tags = draft._get("/api/tags", timeout=5).get("models", [])
            name = model[6:] if model.startswith("local:") else model
            tagged = next((row for row in tags if row.get("name", row.get("model")) == name), {})
            version["digest"] = tagged.get("digest", "unknown")
        except (OSError, ValueError, KeyError):
            pass
    compilers = {name: (entry.get("compiler_build"), entry.get("flags"))
                 for name, entry in sorted(clients.load().items())}
    material = {"model": version, "compilers": compilers,
                "machine": [platform.system(), platform.machine(), platform.processor()]}
    return hashlib.sha256(json.dumps(material, sort_keys=True).encode()).hexdigest()


def split_targets(targets):
    """Stable disjoint calibration/validation split, shuffled by target identity."""
    ordered = sorted(targets, key=lambda row: hashlib.sha256(
        (row["client"] + row["addr"]).encode()).hexdigest())
    cut = max(1, len(ordered) * 2 // 3)
    if len(ordered) > 1:
        cut = min(cut, len(ordered) - 1)
    return ordered[:cut], ordered[cut:]


def _fresh_targets(targets, model, limit=12):
    from roc import metrics
    seen = set()
    try:
        for line in metrics.PATH.read_text(encoding="utf-8").splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row.get("event") == "job":
                if row.get("model") == model:
                    seen.add((row.get("client"), row.get("addr")))
    except OSError:
        pass
    fresh = [row for row in targets if (row.get("client"), row.get("addr")) not in seen]
    return sorted(fresh, key=lambda row: hashlib.sha256(
        (row["client"] + row["addr"]).encode()).hexdigest())[:limit]


def _local_targets(targets):
    from roc import clients, setup
    registry, compilers = clients.load(), set(setup.compilers())
    usable = {}
    for row in targets:
        name = row.get("client")
        if name not in usable:
            entry = registry.get(name)
            usable[name] = bool(entry and entry.get("compiler_build") in compilers and
                                clients.status(name, entry) == "ok")
    return [row for row in targets if usable.get(row.get("client"))]


def _session_rows(session):
    from roc import metrics
    rows = []
    try:
        for line in metrics.PATH.read_text(encoding="utf-8").splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row.get("session") == session and row.get("event") == "job":
                rows.append(row)
    except OSError:
        pass
    return rows


def _rank(rows):
    from roc.metrics import _coded_rounds, compile_success
    matches = sum(row.get("score") == 100 for row in rows)
    compiling = sum(compile_success(row.get("rounds")) > 0 for row in rows)
    coded = [attempt for row in rows for attempt in _coded_rounds(row.get("rounds"))]
    compile_rate = sum(not attempt.get("compile_error") for attempt in coded) / max(len(coded), 1)
    seconds = sum(row.get("seconds", 0) for row in rows)
    tokens = sum(row.get("input_tokens", 0) + row.get("output_tokens", 0) for row in rows)
    costs = [row.get("estimated_cost") for row in rows]
    cost = sum(costs) if costs and all(value is not None for value in costs) else None
    cost_unit = (cost / matches if matches else cost / max(len(rows), 1)) if cost is not None else None
    return matches, compile_rate, compiling, -(cost_unit or 0), -seconds, -tokens


def _summary(rows):
    from roc.metrics import _coded_rounds
    matches, compile_rate, compiling, _cost_rank, _time_rank, _token_rank = _rank(rows)
    costs = [row.get("estimated_cost") for row in rows]
    cost = round(sum(costs), 8) if costs and all(value is not None for value in costs) else None
    seconds = round(sum(row.get("seconds", 0) for row in rows), 2)
    tokens = sum(row.get("input_tokens", 0) + row.get("output_tokens", 0) for row in rows)
    attempts = [attempt for row in rows for attempt in _coded_rounds(row.get("rounds"))]
    return {"jobs": len(rows), "exact_matches": matches, "compilable_jobs": compiling,
            "compile_rate": round(100 * compile_rate, 2), "compile_attempts": len(attempts),
            "seconds": seconds, "tokens": tokens, "estimated_cost": cost,
            "failures": sum(bool(row.get("failure")) for row in rows),
            "cost_per_job": round(cost / len(rows), 8) if cost is not None and rows else None,
            "cost_per_exact": round(cost / matches, 8) if cost is not None and matches else None}


def _require_complete(rows, expected, name):
    if len(rows) != expected or any(row.get("failure") for row in rows):
        raise SystemExit("Optimizer %s run incomplete (%d/%d jobs); no profile saved." %
                         (name, len(rows), expected))


def _log_result(log, name, rows):
    result = _summary(rows)
    cost = ("$%.6f/exact" % result["cost_per_exact"] if result["cost_per_exact"] is not None else
            "$%.6f/job" % result["cost_per_job"] if result["cost_per_job"] is not None else "cost unknown")
    log("%s: exact %d/%d | compile %.1f%% (%d jobs) | %s | %ds | %d tokens" %
        (name, result["exact_matches"], result["jobs"], result["compile_rate"],
         result["compilable_jobs"], cost,
         result["seconds"], result["tokens"]))


def _concurrency(model, allow_cloud, budget, log):
    from roc import providers
    results = []
    try:
        providers.generate(model, "Reply briefly. Fixed optimizer warm-up probe.", options={
            "allow_cloud": allow_cloud, "max_tokens": 8, "thinking": "disabled",
            "budget": budget, "gate": providers.CloudGate(1)})
    except Exception:
        pass
    for workers in (1, 4, 8):
        gate = providers.CloudGate(workers)
        started = time.monotonic()

        def probe(_index):
            try:
                reply = providers.generate(model, "Reply exactly OK. This is a fixed throughput probe.", options={
                    "allow_cloud": allow_cloud, "max_tokens": 8, "thinking": "disabled",
                    "budget": budget, "gate": gate})
                return bool(reply.text.strip())
            except Exception:
                return False

        replies = []
        for _repeat in range(2):
            with ThreadPoolExecutor(max_workers=workers) as pool:
                replies.extend(pool.map(probe, range(3)))
        row = {"workers": workers, "valid": sum(replies), "requests": len(replies), "repeats": 2,
               "seconds": round(time.monotonic() - started, 2)}
        results.append(row)
        log("Concurrency probe: %dw %d/6 replies in %.2fs." %
            (workers, row["valid"], row["seconds"]))
    best = max(results, key=lambda row: (row["valid"] == row["requests"], row["valid"],
                                         -row["seconds"], -row["workers"]))
    return best["workers"], results


def run(model, allow_cloud=False, max_cloud_requests=300, max_cloud_tokens=500000,
        max_cloud_cost=None, force=False, target_count=12, log=print):
    from roc import benchmark, draft, providers, worker
    settings = worker.load_settings()
    if profile(model, settings) and not force:
        raise SystemExit("Optimizer profile exists for %s; pass --force to recalibrate." % model)
    if providers.is_cloud(model):
        if not allow_cloud:
            raise SystemExit("Cloud optimization sends benchmark prompts off this PC; pass --allow-cloud.")
        if not providers.available(model):
            _provider, _remote, config = providers.parse_model(model)
            raise SystemExit("Cloud key is missing: set %s." % config["key_env"])
        if max_cloud_cost is None or max_cloud_cost <= 0:
            raise SystemExit("Cloud optimization requires positive --max-cloud-cost.")
        if not providers.has_pricing(model):
            raise SystemExit("Provider has no model pricing; configure it with `roc provider pricing` first.")
        log("Cloud optimization: request cap %d, token cap %d, cost cap $%.2f." %
            (max_cloud_requests, max_cloud_tokens, max_cloud_cost))
    elif not draft.pick_model(model):
        raise SystemExit("Model is not installed: %s" % model)
    if not 6 <= target_count <= 24:
        raise SystemExit("Optimizer target count must be 6-24.")
    targets = _fresh_targets(_local_targets(benchmark.build_hidden(100000, persist=False)), model, target_count)
    if len(targets) < 2:
        raise SystemExit("Need at least two locally available, verified matched targets never used with this model.")
    calibration, validation = split_targets(targets)
    estimated_requests = len(calibration) * sum(row["rounds"] for row in CONFIGS) + \
                         len(validation) * 8 + 19
    if providers.is_cloud(model) and max_cloud_requests < estimated_requests:
        raise SystemExit("Optimizer needs up to %d requests for a fair run; raise --max-cloud-requests." %
                         estimated_requests)
    budget = providers.CloudBudget(max_cloud_requests, max_cloud_tokens, max_cloud_cost)
    gate = providers.CloudGate(1)
    best_workers, concurrency_results = _concurrency(model, allow_cloud, budget, log)
    if not any(row["valid"] for row in concurrency_results):
        raise SystemExit("Optimizer model probe failed; no profile saved.")
    arms = []
    for config in CONFIGS:
        session = "opt-%s-%s" % (uuid.uuid4().hex[:8], config["name"])
        log("Testing %s: %d rounds, %d tokens, %s on %d calibration targets." %
            (config["name"], config["rounds"], config["max_tokens"], config["strategy"], len(calibration)))
        benchmark.run_local(calibration, [model], rounds=config["rounds"], session=session,
                            strategies=(config["strategy"],), provider_options={
                                "allow_cloud": allow_cloud, "max_tokens": config["max_tokens"],
                                "budget": budget, "gate": gate})
        rows = _session_rows(session)
        _require_complete(rows, len(calibration), config["name"])
        _log_result(log, config["name"], rows)
        arms.append((_rank(rows), config, rows))
    _score, winner, _rows = max(arms, key=lambda arm: arm[0])
    # Validate selected config against current balanced default on held-out targets.
    validation_rows = []
    validation_summary = []
    if validation:
        control = next(row for row in CONFIGS if row["name"] == "balanced")
        candidates = (winner,) if winner == control else (winner, control)
        for config in candidates:
            session = "opt-%s-v-%s" % (uuid.uuid4().hex[:8], config["name"])
            benchmark.run_local(validation, [model], rounds=config["rounds"], session=session,
                                strategies=(config["strategy"],), provider_options={
                                    "allow_cloud": allow_cloud, "max_tokens": config["max_tokens"],
                                    "budget": budget, "gate": gate})
            measured = _session_rows(session)
            _require_complete(measured, len(validation), config["name"] + " validation")
            _log_result(log, config["name"] + " validation", measured)
            validation_rows.append((config, measured))
            validation_summary.append({"name": config["name"], **_summary(measured)})
        chosen_rows = next(rows for config, rows in validation_rows if config == winner)
        control_rows = next((rows for config, rows in validation_rows if config["name"] == "balanced"),
                            chosen_rows)
        if _rank(control_rows) > _rank(chosen_rows):
            winner = control
    profiles = dict(settings.get("optimizer_profiles") or {})
    profiles[model] = {**winner, "workers": best_workers, "fingerprint": fingerprint(model),
                       "sample_count": len(targets), "calibration_count": len(calibration),
                       "validation_count": len(validation), "validated": bool(validation),
                       "calibration_targets": [row["client"] + ":" + row["addr"] for row in calibration],
                       "validation_targets": [row["client"] + ":" + row["addr"] for row in validation],
                       "calibration_results": [{"name": config["name"], **_summary(rows)}
                                               for _ranked, config, rows in arms],
                       "validation_results": validation_summary,
                       "concurrency_results": concurrency_results,
                       "result": "best observed; not guaranteed optimal"}
    worker.save_settings(optimizer_profiles=profiles, worker_preset_model="", worker_rounds_model="",
                         worker_workers_model="", worker_output_budget_model="", worker_strategy_model="")
    log("Saved best-observed profile for %s: %s, %d rounds, %d tokens, %s." %
        (model, winner["name"], winner["rounds"], winner["max_tokens"], winner["strategy"]))
    return profiles[model]
