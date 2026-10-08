"""Small local worker telemetry store.

Append-only JSON keeps diagnostics useful after an overnight run without adding
another service or database dependency.
"""
import json
import re
import threading
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PATH = ROOT / "work" / "worker-metrics.jsonl"
RULES = ROOT / "work" / "worker-rules.json"
TEMPLATES = ROOT / "work" / "worker-templates.json"
QUARANTINE = ROOT / "work" / "worker-quarantine.json"
PROMOTED = ROOT / "work" / "worker-promoted.json"
_LOCK = threading.Lock()


def record(session, **data):
    row = {"ts": time.time(), "session": session, **data}
    try:
        PATH.parent.mkdir(parents=True, exist_ok=True)
        with _LOCK, PATH.open("a", encoding="utf-8") as out:
            out.write(json.dumps(row, separators=(",", ":")) + "\n")
    except OSError:
        pass
    return row


def summary(session):
    rows = []
    try:
        for line in PATH.read_text(encoding="utf-8").splitlines()[-5000:]:
            row = json.loads(line)
            if row.get("session") == session:
                rows.append(row)
    except (OSError, ValueError):
        return ""
    if not rows:
        return ""
    done = [r for r in rows if r.get("event") == "job"]
    matched = sum(r.get("score", 0) == 100 for r in done)
    improved = sum(r.get("improved") for r in done)
    source = sum(r.get("source_hints") for r in done)
    source_candidates = sum(bool(r.get("source_candidate")) for r in done)
    source_hits = sum(bool(r.get("source_candidate_hit")) for r in done)
    ai_hits = sum(bool(r.get("improved")) and not bool(r.get("source_candidate_hit")) for r in done)
    failures = {}
    for row in done:
        if row.get("failure"):
            key = row["failure"].split(":", 1)[0][:60]
            failures[key] = failures.get(key, 0) + 1
    tail = "" if not failures else ", failures=" + ";".join("%s:%d" % item for item in failures.items())
    llm = sum(r.get("phase_seconds", {}).get("llm", 0) for r in done)
    compile_time = sum(r.get("compile_seconds", 0) for r in done)
    tokens = sum(a.get("output_tokens", 0) for r in done for a in r.get("rounds", []))
    return (("Session: %d jobs, %d matched, %d improved, source hits %d, AI hits %d, %d source-guided, %.1fs avg (LLM %.1fs, compile %.1fs)"
             % (len(done), matched, improved, source_hits, ai_hits, source_candidates,
                sum(r.get("seconds", 0) for r in done) / max(len(done), 1), llm, compile_time)) +
            " tokens=%d" % tokens + tail)


def _coded_rounds(rounds):
    """Code-bearing attempt rounds, excluding telemetry metas (topk/mutate/early-stop)."""
    out = []
    for a in rounds or []:
        if not isinstance(a, dict) or not isinstance(a.get("round"), int):
            continue
        if a.get("code"):
            out.append(a)
    return out


def known_generation_cost(rounds):
    """Return cost only when every cloud generation reported real pricing."""
    generated = [row for row in rounds or [] if isinstance(row, dict) and isinstance(row.get("round"), int)]
    cloud = [row for row in generated if row.get("provider") and row.get("provider") != "local"]
    if any(row.get("estimated_cost") is None for row in cloud):
        return None
    return round(sum(row.get("estimated_cost", 0) or 0 for row in generated), 8) if generated else None


def compile_success(rounds):
    """Fraction of code-bearing rounds that compiled (no compile_error)."""
    coded = _coded_rounds(rounds)
    if not coded:
        return 0.0
    return round(sum(not a.get("compile_error") for a in coded) / len(coded), 4)


def error_code_counts(rounds):
    """MSVC error-code histogram over failed rounds: {'2039': n}."""
    from roc.repair import parse_error_codes
    out = {}
    for a in _coded_rounds(rounds):
        if a.get("compile_error"):
            for code in parse_error_codes(a["compile_error"])[:1]:
                out[code] = out.get(code, 0) + 1
    return out


def summarize_runs(jobs):
    """Per-change benchmark summary: exact matches, time/match, compile rate.

    jobs: worker-metrics job rows for one fixed target set. No estimates,
    only measured counts over the given rows.
    """
    jobs = list(jobs)
    matched = sum(r.get("score", 0) == 100 for r in jobs)
    seconds = sum(r.get("seconds", 0) for r in jobs)
    rates = [compile_success(r.get("rounds", [])) for r in jobs]
    with_compile = sum(compile_success(r.get("rounds", [])) > 0 for r in jobs)
    tokens = [sum(a.get("output_tokens", 0) for a in _coded_rounds(r.get("rounds", []))) for r in jobs]
    attempts = [len(_coded_rounds(r.get("rounds", []))) for r in jobs]
    rejected_asm = sum(a.get("rejected_asm", False) for r in jobs for a in _coded_rounds(r.get("rounds", [])))
    rejected_qualified = sum(a.get("rejected_qualified_type", False) for r in jobs for a in _coded_rounds(r.get("rounds", [])))
    rejected_contract = sum(a.get("rejected_contract", False) for r in jobs for a in _coded_rounds(r.get("rounds", [])))
    cost_known = [r.get("estimated_cost") for r in jobs if r.get("estimated_cost") is not None]
    total_cost = round(sum(cost_known), 8) if cost_known else None
    scores = sorted(r.get("score", 0) for r in jobs)
    median = scores[len(scores) // 2] if scores else 0
    codes = {}
    for r in jobs:
        for code, n in error_code_counts(r.get("rounds", [])).items():
            codes[code] = codes.get(code, 0) + n
    return {"jobs": len(jobs), "matched": matched,
            "match_rate": round(100.0 * matched / max(len(jobs), 1), 2),
            "seconds_per_job": round(seconds / max(len(jobs), 1), 2),
            "seconds_per_match": round(seconds / matched, 2) if matched else None,
            "compile_success_rate": round(sum(rates) / max(len(rates), 1), 4),
            "jobs_with_compile": with_compile,
            "compile_job_rate": round(100.0 * with_compile / max(len(jobs), 1), 2),
            "avg_score": round(sum(r.get("score", 0) for r in jobs) / max(len(jobs), 1), 2),
            "median_score": median,
            "tokens_per_job": round(sum(tokens) / max(len(tokens), 1), 1),
            "compile_attempts": sum(attempts),
            "rejected_inline_asm": rejected_asm,
            "rejected_qualified_type": rejected_qualified,
            "rejected_contract": rejected_contract,
            "generation_seconds": round(sum(r.get("generation_seconds", 0) for r in jobs), 3),
            "estimated_cost": total_cost,
            "exact_matches_per_dollar": round(matched / total_cost, 4) if total_cost else None,
            "exact_matches_per_wall_hour": round(matched / (seconds / 3600), 4) if seconds else None,
            "errors_by_code": dict(sorted(codes.items(), key=lambda i: -i[1]))}


def model_stats():
    rows = []
    try:
        for line in PATH.read_text(encoding="utf-8").splitlines():
            row = json.loads(line)
            if row.get("event") == "job":
                rows.append(row)
    except (OSError, ValueError):
        return []
    out = {}
    for row in rows:
        model = row.get("model", "unknown")
        stat = out.setdefault(model, [0, 0, 0, 0.0, 0])
        stat[0] += 1
        stat[1] += row.get("score", 0) == 100
        stat[2] += row.get("improved", False)
        stat[3] += row.get("seconds", 0)
        stat[4] += row.get("score_gain", max(row.get("score", 0) - row.get("base_score", 0), 0))
    return [{"model": m, "jobs": v[0], "matched": v[1], "improved": v[2],
             "avg_seconds": round(v[3] / max(v[0], 1), 2), "score_gain": v[4],
             "match_rate": round(100.0 * v[1] / max(v[0], 1), 2),
             "gpu_minutes_per_match": round(v[3] / 60.0 / max(v[1], 1), 2)}
            for m, v in sorted(out.items())]


def failure_clusters(limit=20):
    """Recurring compile/API failure prefixes for deterministic rule work."""
    out = {}
    try:
        lines = PATH.read_text(encoding="utf-8").splitlines()
    except OSError:
        return []
    for line in lines:
        try:
            row = json.loads(line)
        except ValueError:
            continue
        for attempt in row.get("rounds", []):
            error = attempt.get("compile_error")
            if error:
                compact = " ".join(error.split())
                if re.search(r"C2440|C2664|cannot convert|type", compact, re.I):
                    key = "wrong_type_or_return"
                elif re.search(r"ret|stack|calling", compact, re.I):
                    key = "calling_convention_or_stack"
                elif re.search(r"C2146|C2065|C2653|C2039|undeclared|syntax|not a class", compact, re.I):
                    key = "syntax_or_missing_declaration"
                elif re.search(r"no functions compiled|inline", compact, re.I):
                    key = "no_emitted_symbol"
                else:
                    key = compact[:120]
                out[key] = out.get(key, 0) + 1
        if row.get("failure_reason"):
            key = row["failure_reason"]
            out[key] = out.get(key, 0) + 1
    return [{"reason": reason, "count": count} for reason, count in
            sorted(out.items(), key=lambda item: (-item[1], item[0]))[:limit]]


def corpus_stats(corpus):
    targets = {(r.get("client"), r.get("addr")): (r.get("bucket", "unknown"),
                                                    bool(r.get("source_present"))) for r in corpus}
    out = {}
    try:
        lines = PATH.read_text(encoding="utf-8").splitlines()
    except OSError:
        return []
    for line in lines:
        try:
            row = json.loads(line)
        except ValueError:
            continue
        target = targets.get((row.get("client"), row.get("addr")))
        if row.get("event") != "job" or target is None:
            continue
        bucket, source_present = target
        key = (row.get("model", "unknown"), bucket, source_present)
        stat = out.setdefault(key, [0, 0, 0])
        stat[0] += 1
        stat[1] += row.get("score", 0) == 100
        stat[2] += row.get("score_gain", 0)
    return [{"model": model, "bucket": bucket, "source_present": source_present,
             "jobs": v[0], "matched": v[1], "score_gain": v[2]}
            for (model, bucket, source_present), v in sorted(out.items())]


def promote_failures(min_count=3):
    """Persist conservative rules, templates, and noisy-example quarantine hints."""
    clusters = failure_clusters()
    rules = {row["reason"]: {"count": row["count"], "action": "review-template"}
             for row in clusters if row["count"] >= min_count}
    RULES.parent.mkdir(parents=True, exist_ok=True)
    RULES.write_text(json.dumps(rules, indent=1))
    templates = {
        "wrong_type_or_return": {"prompt": "preserve return width; repair only declared type",
                                  "source_pattern": "TYPE NAME(PARAMS) { return EXPR; }"},
        "calling_convention_or_stack": {"prompt": "match ret immediate and caller cleanup before changing body",
                                        "source_pattern": "TYPE __CONV NAME(PARAMS) { BODY }"},
        "syntax_or_missing_declaration": {"prompt": "emit one out-of-line function and minimal declarations",
                                           "source_pattern": "DECLARATIONS\\nTYPE NAME(PARAMS) { BODY }"},
        "no_emitted_symbol": {"prompt": "reject inline/extra helpers; keep exactly one target symbol",
                               "source_pattern": "TYPE NAME(PARAMS) { BODY }"},
    }
    TEMPLATES.write_text(json.dumps({k: {"count": v["count"], **templates.get(k, {
        "prompt": "minimal source only", "source_pattern": "TYPE NAME(PARAMS) { BODY }"})}
                                     for k, v in rules.items()}, indent=1))
    bad = {}
    try:
        for line in PATH.read_text(encoding="utf-8").splitlines():
            row = json.loads(line)
            if row.get("event") == "job" and row.get("score", 0) == 0 and row.get("failure_reason"):
                key = "%s:%s" % (row.get("client", ""), row.get("addr", ""))
                bad[key] = {"client": row.get("client"), "addr": row.get("addr"),
                            "reason": row.get("failure_reason"), "model": row.get("model")}
    except (OSError, ValueError):
        pass
    QUARANTINE.write_text(json.dumps(list(bad.values())[-500:], indent=1))
    promote_sources()
    return rules


def promote_sources(limit=500):
    """Promote byte-perfect local attempts into a compact retrieval corpus."""
    promoted = {}
    try:
        lines = PATH.read_text(encoding="utf-8").splitlines()
        for line in lines:
            row = json.loads(line)
            if row.get("event") != "job":
                continue
            for attempt in row.get("rounds", []):
                source = attempt.get("source")
                if attempt.get("score") == 100 and source:
                    key = "%s:%s" % (row.get("client", ""), row.get("addr", ""))
                    promoted[key] = {"client": row.get("client"), "addr": row.get("addr"),
                                     "model": row.get("model"), "source": source}
    except (OSError, ValueError):
        pass
    PROMOTED.parent.mkdir(parents=True, exist_ok=True)
    PROMOTED.write_text(json.dumps(list(promoted.values())[-limit:], indent=1))
    return len(promoted)


def quarantined_keys():
    """Return noisy target keys excluded from few-shot retrieval."""
    try:
        return {(str(row.get("client")), str(row.get("addr")))
                for row in json.loads(QUARANTINE.read_text())}
    except (OSError, ValueError, TypeError):
        return set()
