"""telemetry"""
import hashlib
import json
import platform
import re
import sqlite3
import threading
import time
import uuid
from concurrent.futures import ThreadPoolExecutor
from contextlib import closing
from functools import lru_cache
from pathlib import Path

from roc import clients


# --- metrics ---
# Small local worker telemetry store.

ROOT = Path(__file__).resolve().parent.parent


PATH = ROOT / "work" / "worker-jsonl"


RULES = ROOT / "work" / "worker-rules.json"


TEMPLATES = ROOT / "work" / "worker-templates.json"


QUARANTINE = ROOT / "work" / "worker-quarantine.json"


PROMOTED = ROOT / "work" / "worker-promoted.json"


_LOCK = threading.Lock()


_RECENT = {"key": None, "rows": []}


def recent_rows():
    """Read the latest 5,000 records once per file change, without loading history."""
    with _LOCK:
        try:
            stat = PATH.stat()
            key = (PATH, stat.st_ino, stat.st_size, stat.st_mtime_ns)
            if _RECENT["key"] == key:
                return _RECENT["rows"]
            with PATH.open("rb") as stream:
                position, count, blocks = stat.st_size, 0, []
                while position and count <= 5000:
                    size = min(position, 65536)
                    position -= size
                    stream.seek(position)
                    block = stream.read(size)
                    blocks.append(block)
                    count += block.count(b"\n")
            lines = b"".join(reversed(blocks)).splitlines()
            if position:
                lines = lines[1:]
        except OSError:
            return []
        rows = []
        for line in lines[-5000:]:
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if isinstance(row, dict):
                rows.append(row)
        _RECENT.update(key=key, rows=rows)
        return rows


def record(session, **data):
    row = {"ts": time.time(), "session": session, **data}
    try:
        PATH.parent.mkdir(parents=True, exist_ok=True)
        with _LOCK, PATH.open("a", encoding="utf-8") as out:
            out.write(json.dumps(row, separators=(",", ":")) + "\n")
    except OSError:
        pass
    return row


def session_totals(session):
    """Running token/cost totals for one worker session (prior recorded jobs)."""
    totals = {"jobs": 0, "input_tokens": 0, "output_tokens": 0,
              "cached_tokens": 0, "estimated_cost": 0, "cloud_jobs": 0}
    done = [row for row in recent_rows() if row.get("session") == session and row.get("event") == "job"]
    cloud = [r for r in done if r.get("provider") and r.get("provider") != "local"]
    costs = [r.get("estimated_cost") for r in cloud]
    totals.update(jobs=len(done),
                  input_tokens=sum(r.get("input_tokens", 0) or 0 for r in done),
                  output_tokens=sum(r.get("output_tokens", 0) or 0 for r in done),
                  cached_tokens=sum(r.get("cached_tokens", 0) or 0 for r in done),
                  estimated_cost=(None if any(v is None for v in costs) else sum(costs or [0])),
                  cloud_jobs=len(cloud))
    return totals


def inline_asm_prone(client, addr, threshold=2):
    """True when recent attempts repeatedly emitted forbidden inline asm."""
    strikes = 0
    for row in recent_rows():
        if row.get("event") != "job" or row.get("client") != client or row.get("addr") != addr:
            continue
        strikes += sum(bool(round_row.get("rejected_asm"))
                       for round_row in row.get("rounds", [])
                       if isinstance(round_row, dict))
    return strikes >= threshold


def summary(session):
    rows = [row for row in recent_rows() if row.get("session") == session]
    if not rows:
        return ""
    done = [r for r in rows if r.get("event") == "job"]
    matched = sum(r.get("score", 0) == 100 for r in done)
    improved = sum(r.get("improved") for r in done)
    source = sum(r.get("source_hints", 0) or 0 for r in done)
    family_jobs = sum(bool(r.get("family_id")) for r in done)
    family_examples = sum(bool(r.get("family_exemplar")) for r in done)
    family_propagated = sum(bool(r.get("family_propagated")) for r in done)
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
    totals = session_totals(session)
    input_tokens, output_tokens, cached_tokens = (totals["input_tokens"], totals["output_tokens"],
                                                  totals["cached_tokens"])
    cloud, cost = totals["cloud_jobs"], totals["estimated_cost"]
    token_line = " tokens=in:%d out:%d cached:%d" % (input_tokens, output_tokens, cached_tokens)
    cost_line = " cost=unknown" if cloud and cost is None else " cost=$%.6f" % cost
    return (("Session: %d jobs, %d matched, %d improved, family %d/%d, propagated %d, source hits %d, AI hits %d, %d source-guided, %.1fs avg (LLM %.1fs, compile %.1fs)"
             % (len(done), matched, improved, family_examples, family_jobs, family_propagated, source_hits, ai_hits, source_candidates,
                sum(r.get("seconds", 0) for r in done) / max(len(done), 1), llm, compile_time)) +
            token_line + cost_line + tail)


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
    codes, mutation_attempts, mutation_exact = {}, {}, {}
    mutation_conversions = mutation_seconds = 0
    mismatch_classes = {}
    for r in jobs:
        for code, n in error_code_counts(r.get("rounds", [])).items():
            codes[code] = codes.get(code, 0) + n
        for attempt in r.get("rounds", []):
            if isinstance(attempt, dict) and attempt.get("round") == "mutate":
                mutation_conversions += bool(attempt.get("exact_conversion"))
                for item in attempt.get("mutations", []):
                    category = item.get("category", "unknown")
                    mutation_attempts[category] = mutation_attempts.get(category, 0) + 1
                    mutation_seconds += item.get("seconds", 0) or 0
                    if item.get("exact"):
                        mutation_exact[category] = mutation_exact.get(category, 0) + 1
        for attempt in _coded_rounds(r.get("rounds", [])):
            category = attempt.get("mismatch_class")
            if category and category != "exact":
                mismatch_classes[category] = mismatch_classes.get(category, 0) + 1
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
            "errors_by_code": dict(sorted(codes.items(), key=lambda i: -i[1])),
            "mismatch_classes": dict(sorted(mismatch_classes.items(), key=lambda i: -i[1])),
            "mutation_exact_conversions": mutation_conversions,
            "mutation_attempts": sum(mutation_attempts.values()),
            "mutation_attempts_by_category": dict(sorted(mutation_attempts.items(), key=lambda i: -i[1])),
            "mutation_exact_by_category": dict(sorted(mutation_exact.items(), key=lambda i: -i[1])),
            "mutation_seconds": round(mutation_seconds, 3)}


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


def family_stats():
    """Aggregate family-index worker telemetry for cost/exact reporting."""
    rows = []
    try:
        lines = PATH.read_text(encoding="utf-8").splitlines()
    except OSError:
        return {"jobs": 0, "matched": 0, "propagated": 0, "tokens": 0, "cost": 0}
    for line in lines:
        try:
            row = json.loads(line)
        except ValueError:
            continue
        if row.get("event") == "job" and row.get("family_id"):
            rows.append(row)
    cost = sum(r.get("estimated_cost", 0) or 0 for r in rows)
    tokens = sum((r.get("input_tokens", 0) or 0) + (r.get("output_tokens", 0) or 0) for r in rows)
    matched = sum(r.get("score") == 100 for r in rows)
    clients = {r.get("client") for r in rows if r.get("client")}
    families = {r.get("family_id") for r in rows if r.get("family_id")}
    exemplar_jobs = sum(bool(r.get("family_exemplar")) for r in rows)
    return {"jobs": len(rows), "matched": matched,
            "match_rate": round(100 * matched / max(len(rows), 1), 2),
            "propagated": sum(bool(r.get("family_propagated")) for r in rows),
            "exemplar_jobs": exemplar_jobs, "clients": len(clients),
            "families": len(families), "tokens": tokens, "cost": round(cost, 8),
            "exact_per_100k_tokens": round(100000 * matched / tokens, 4) if tokens else None,
            "exact_per_dollar": round(matched / cost, 4) if cost else None}


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
        attempts = row.get("rounds", [])
        if not isinstance(attempts, list):
            attempts = []
        for attempt in attempts:
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


# --- benchmark ---
# Deterministic local benchmark corpus and telemetry report.

CORPUS = ROOT / "work" / "benchmark-corpus.json"


HIDDEN = ROOT / "work" / "benchmark-hidden.json"


def build(limit=8):
    buckets = {}
    for client in sorted(clients.load()):
        path = ROOT / "work" / client / "functions.jsonl"
        if not path.exists():
            continue
        for line in path.read_text(errors="replace").splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row.get("kind", "code") != "code":
                continue
            size = row.get("size", 0)
            bucket = "tiny" if size <= 48 else "medium" if size <= 128 else "large"
            key = (client, bucket)
            buckets.setdefault(key, []).append(row)
    out = []
    for (client, bucket), rows in sorted(buckets.items()):
        rows.sort(key=lambda r: hashlib.sha256((client + r["addr"]).encode()).hexdigest())
        for row in rows[:limit]:
            out.append({"client": client, "addr": row["addr"], "size": row["size"],
                        "unit": row.get("unit"), "bucket": bucket,
                        "source_present": not str(row.get("unit", "")).startswith("seg_")})
    CORPUS.parent.mkdir(parents=True, exist_ok=True)
    CORPUS.write_text(json.dumps(out, indent=1))
    return out


def load():
    try:
        return json.loads(CORPUS.read_text())
    except (OSError, ValueError):
        return []


def build_hidden(limit=8, persist=True):
    """Sample locally solved functions while omitting their source/score metadata."""
    out = []
    for client in sorted(clients.load()):
        scores_path = ROOT / "work" / client / "scores.json"
        funcs_path = ROOT / "work" / client / "functions.jsonl"
        if not scores_path.exists() or not funcs_path.exists():
            continue
        scores = json.loads(scores_path.read_text())
        rows = {"tiny": [], "medium": [], "large": []}
        for line in funcs_path.read_text(errors="replace").splitlines():
            row = json.loads(line)
            if scores.get(row.get("addr")) != 100 or row.get("kind", "code") != "code":
                continue
            size = row.get("size", 0)
            bucket = "tiny" if size <= 48 else "medium" if size <= 128 else "large"
            rows[bucket].append(row)
        for bucket, bucket_rows in rows.items():
            for row in sorted(bucket_rows, key=lambda item: item["addr"])[:limit]:
                out.append({"client": client, "addr": row["addr"], "size": row["size"],
                            "unit": row.get("unit"), "bucket": bucket,
                            "source_present": not str(row.get("unit", "")).startswith("seg_")})
    if persist:
        HIDDEN.parent.mkdir(parents=True, exist_ok=True)
        HIDDEN.write_text(json.dumps(out, indent=1))
    return out


def ab_split(corpus):
    """Deterministic fixed A/B split by client+addr hash.

    The split does not depend on corpus order or on which arm ran first, so two
    benchmark runs can be compared target-for-target.  Every entry carries a
    short ``target_hash`` for the report.
    """
    groups = {"A": [], "B": []}
    for row in corpus:
        digest = hashlib.sha256(("roconstruct-ab:" + row["client"] + ":" + row["addr"]).encode()).hexdigest()
        entry = dict(row)
        entry["target_hash"] = digest[:16]
        groups["A" if int(digest[:8], 16) % 2 == 0 else "B"].append(entry)
    for rows in groups.values():
        rows.sort(key=lambda item: item["target_hash"])
    return groups


def compare_sessions(session_a, session_b):
    """Measured A/B report from recorded worker telemetry.

    A is the baseline arm, B the variant.  Deltas are raw differences on this
    corpus; no significance claim is made when the samples are small.
    """
    a = _summary(_session_rows(session_a))
    b = _summary(_session_rows(session_b))
    return {"A": dict(session=session_a, **a), "B": dict(session=session_b, **b),
            "delta": {"exact_matches": b["exact_matches"] - a["exact_matches"],
                      "compile_rate": round(b["compile_rate"] - a["compile_rate"], 2),
                      "seconds": round(b["seconds"] - a["seconds"], 2),
                      "tokens": b["tokens"] - a["tokens"]},
            "note": "raw difference over each recorded session; not a significance test"}


def format_compare(report):
    lines = ["A/B benchmark report (A = baseline, B = variant)"]
    for arm in ("A", "B"):
        row = report[arm]
        lines.append("  %s %-24s jobs=%d exact=%d compile=%.2f%% time=%.2fs tokens=%d" % (
            arm, row["session"], row["jobs"], row["exact_matches"], row["compile_rate"],
            row["seconds"], row["tokens"]))
    delta = report["delta"]
    lines.append("  B-A exact=%+d compile=%+.2fpp time=%+.2fs tokens=%+d" % (
        delta["exact_matches"], delta["compile_rate"], delta["seconds"], delta["tokens"]))
    lines.append("  " + report["note"])
    return "\n".join(lines)


def run_local(corpus, models, rounds=1, log=print, resume=False, session="benchmark", strategies=("direct",),
              provider_options=None, family_examples=None, candidate_dir=None, initial_sources=None):
    """Benchmark configured models without submitting or changing server state.

    ``family_examples`` optionally maps ``(client, addr)`` to verified source
    exemplars for controlled sibling experiments; normal runs pass none.
    ``initial_sources`` maps targets to freshly verified (source, score) pairs
    for repair experiments; omission keeps the source-hidden baseline.

    session isolates one measured run: pass a unique id per arm (e.g.
    "bench-<date>-<label>") so background worker jobs sharing the metrics
    file can never contaminate the comparison. Filter rows by session.
    """
    import time
    from roc import clients, draft, match, providers, refsource
    done = set()
    if resume:
        try:
            for line in PATH.read_text(encoding="utf-8").splitlines():
                row = json.loads(line)
                if row.get("session") == session and row.get("event") == "job":
                    done.add((row.get("client"), row.get("addr"), row.get("model"), row.get("strategy", "direct")))
        except (OSError, ValueError):
            pass
    for target in corpus:
        client, addr = target["client"], target["addr"]
        code, relocs, row = match.target(client, addr)
        asm = match.disasm(code, int(addr, 16))
        facts = draft.facts_from_asm(asm)
        facts.update(draft.target_data_facts(client, code, relocs))
        facts.update({k: row[k] for k in ("call_targets", "external_calls", "imports", "strings",
                                          "global_reads", "global_writes", "virtual_slots", "stack_args",
                                          "this_reads", "this_writes", "calling_convention", "branches",
                                          "constants") if row.get(k)})
        for model in models:
            for strategy in strategies:
                if (client, addr, model, strategy) in done:
                    log("  skip %s %s (already measured)" % (model, addr))
                    continue
                started = time.monotonic()
                stats = []
                _src = None
                start = (initial_sources or {}).get((client, addr), (None, 0))
                try:
                    examples = (family_examples or {}).get((client, addr), ())
                    score, _src = draft.llm_rounds(client, addr, model, rounds, None, start,
                                                   log, clients.load()[client].get("flags"), examples,
                                                   refsource.prompt_hints(row.get("unit", ""), target_facts=facts, client=client),
                                                   facts, stats, strategy=strategy, provider_options=provider_options)
                    failure = None
                except Exception as error:
                    score, _src, failure = start[1], start[0], str(error)[:300]
                if candidate_dir is not None and _src:
                    output = Path(candidate_dir) / client
                    output.mkdir(parents=True, exist_ok=True)
                    stem = output / (addr + "-" + strategy)
                    stem.with_suffix(".cpp").write_text(_src, encoding="utf-8")
                    stem.with_suffix(".json").write_text(json.dumps({
                        "client": client, "addr": addr, "model": model,
                        "strategy": strategy, "score": score, "session": session,
                        "compiler_flags": clients.load()[client].get("flags"),
                        "source_sha256": hashlib.sha256(_src.encode()).hexdigest(),
                    }, indent=1), encoding="utf-8")
                generated = [item for item in stats if isinstance(item.get("round"), int)]
                coded = [item for item in generated if item.get("code")]
                provider_row = next((item for item in reversed(generated) if item.get("provider")), {})
                _name, _remote, config = providers.parse_model(model)
                record(session, event="job", client=client, addr=addr, unit=row.get("unit"),
                               model=model, strategy=strategy, size=row.get("size", 0), base_score=start[1], score=score,
                               score_gain=score - start[1], improved=score > start[1], rounds=stats,
                               seconds=round(time.monotonic() - started, 2), failure=failure,
                               compiler_flags=clients.load()[client].get("flags"),
                               provider=provider_row.get("provider", _name),
                               provider_model=provider_row.get("provider_model", _remote),
                               provider_endpoint_kind=config.get("kind", "ollama"),
                               seed=(provider_options or {}).get("seed"),
                               input_tokens=sum(item.get("input_tokens", 0) for item in generated),
                               output_tokens=sum(item.get("output_tokens", 0) for item in generated),
                               reasoning_tokens=sum(item.get("reasoning_tokens") or 0 for item in generated),
                               cached_tokens=sum(item.get("cached_tokens", 0) for item in generated),
                               generation_seconds=round(sum(item.get("generation_seconds", 0) for item in generated), 3),
                               compile_seconds=round(sum(item.get("compile_seconds", 0) for item in coded), 3),
                               compile_attempts=len(coded),
                               compile_ok=sum(not item.get("compile_error") for item in coded),
                               estimated_cost=known_generation_cost(generated))
                log("  %s/%s %s %d%% %.1fs" % (model, strategy, addr, score, time.monotonic() - started))


# --- optimizer ---
# Small, bounded, per-model worker configuration calibration.

CONFIGS = (
    {"name": "fast", "rounds": 2, "max_tokens": 1024, "strategy": "direct"},
    {"name": "balanced", "rounds": 4, "max_tokens": 2048, "strategy": "direct"},
    {"name": "structured", "rounds": 4, "max_tokens": 2048, "strategy": "structured"},
    {"name": "auto", "rounds": 4, "max_tokens": 2048, "strategy": "auto"},
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
    
    seen = set()
    try:
        for line in PATH.read_text(encoding="utf-8").splitlines():
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
    
    rows = []
    try:
        for line in PATH.read_text(encoding="utf-8").splitlines():
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
    from roc.telemetry import _coded_rounds, compile_success
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
    from roc.telemetry import _coded_rounds
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
    from roc import draft, providers, worker
    settings = worker.load_settings()
    if profile(model, settings) and not force:
        raise SystemExit("Optimizer profile exists for %s; pass --force to recalibrate." % model)
    if providers.is_cloud(model):
        if not allow_cloud:
            raise SystemExit("Cloud optimization sends benchmark prompts off this PC; pass --allow-cloud.")
        if not providers.available(model):
            _provider, _remote, config = providers.parse_model(model)
            raise SystemExit(providers.credential_hint(model))
        if providers.parse_model(model)[0] == "chatgpt":
            if max_cloud_cost is not None:
                raise SystemExit("ChatGPT optimization uses plan limits; omit --max-cloud-cost.")
            log("ChatGPT optimization: shared plan limits; request cap %d, token reservation cap %d." %
                (max_cloud_requests, max_cloud_tokens))
        else:
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
    targets = _fresh_targets(_local_targets(build_hidden(100000, persist=False)), model, target_count)
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
        run_local(calibration, [model], rounds=config["rounds"], session=session,
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
            run_local(validation, [model], rounds=config["rounds"], session=session,
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


# --- activity ---
# Persistent per-function worker activity, isolated per worker thread.

ACTIVITY_PATH = Path(__file__).resolve().parent.parent / "work" / "function-history.sqlite"


local = threading.local()


def connect():
    ACTIVITY_PATH.parent.mkdir(parents=True, exist_ok=True)
    db = sqlite3.connect(ACTIVITY_PATH, timeout=15)
    db.execute("CREATE TABLE IF NOT EXISTS activity (id TEXT PRIMARY KEY, updated REAL, data TEXT)")
    return db


def save(force=True):
    row = getattr(local, "row", None)
    if row is None:
        return
    if not force and time.monotonic()-getattr(local, "saved_at", 0)<1:
        return
    try:
        with closing(connect()) as db:
            db.execute("INSERT OR REPLACE INTO activity VALUES (?, ?, ?)",
                       (row["id"], time.time(), json.dumps(row)))
            db.commit()
            local.saved_at = time.monotonic()
    except (OSError, sqlite3.Error):
        pass  # History must not interrupt a leased function.


def begin(job, model, session):
    local.row = dict(id=uuid.uuid4().hex, client=job["client"], addr=job["addr"],
                     unit=job.get("unit", ""), model=model, session=session,
                     started=time.time(), status="working", before=job.get("source") or "",
                     after=job.get("source") or "", base_score=job.get("score", 0),
                     score=job.get("score", 0), timeline=[], commands=[], candidates=[])
    save()


def event(message):
    row = getattr(local, "row", None)
    if row is not None:
        row["timeline"].append(dict(seconds=round(time.time()-row["started"], 2), message=str(message)))
        row["timeline"] = row["timeline"][-500:]
        save(force=False)


def command(argv, cwd, result):
    row = getattr(local, "row", None)
    if row is not None:
        row["commands"].append(dict(argv=argv, cwd=cwd, exit_code=result.returncode,
                                    output=(result.stdout + result.stderr)[-12000:]))
        row["commands"] = row["commands"][-200:]
        if getattr(local, "emit", None):
            local.emit("compile", message="Compiler finished", **row["commands"][-1])


def candidate(text, score):
    row = getattr(local, "row", None)
    if row is not None:
        row["candidates"].append(dict(score=score))
        if score > row["score"]:
            row.update(score=score, after=text)
            save()
            if getattr(local, "emit", None):
                local.emit("candidate", client=row["client"], addr=row["addr"], score=score, code=text)


def finish(score, failure, rounds):
    row = getattr(local, "row", None)
    if row is None:
        return
    row.update(ended=time.time(), best_score=row["score"], score=max(score, row["base_score"]), failure=failure,
               status="failed" if failure else "matched" if score == 100 else "improved" if score > row["base_score"] else "unchanged",
               rounds=rounds)
    save()
    local.row = None


def read(identifier=None, query="", status="", sort="recent", limit=300):
    with closing(connect()) as db:
        if identifier:
            value = db.execute("SELECT data FROM activity WHERE id=?", (identifier,)).fetchone()
            return json.loads(value[0]) if value else None
        order = {"score": "json_extract(data,'$.score') DESC", "gain":
                 "(json_extract(data,'$.score') - json_extract(data,'$.base_score')) DESC",
                 "unit": "json_extract(data,'$.unit')", "addr": "json_extract(data,'$.addr')"}.get(sort, "updated DESC")
        rows = [json.loads(value[0]) for value in db.execute(
            "SELECT data FROM activity WHERE (?='' OR lower(coalesce(json_extract(data,'$.unit'),'') || ' ' || "
            "json_extract(data,'$.client') || ' ' || json_extract(data,'$.addr') || ' ' || "
            "coalesce(json_extract(data,'$.model'),'')) LIKE ?) AND (?='' OR json_extract(data,'$.status')=?) "
            "ORDER BY " + order + " LIMIT ?", (query, '%' + query.lower() + '%', status, status, limit))]
    return [{k: v for k, v in row.items() if k not in ("before", "after", "timeline", "commands", "rounds", "candidates")} for row in rows]
