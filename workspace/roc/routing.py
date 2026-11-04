"""Model routing for weak/free models and expensive targets.

Two rules, both measured where possible rather than guessed from a model name:

* weak models get one prompt that asks for 2-4 independent variants, at most two
  targeted follow-ups, and only high-confidence small patch work;
* uncertain multi-block functions with little source evidence are recorded as
  needing research instead of being handed to a free model.  A stronger model is
  used only when the operator configured one explicitly; there is no hidden
  paid fallback.

``roc optimize --model`` stores measured compile/exact rates in the worker
settings; those win over the generic name heuristics.
"""
import fnmatch
import os

WEAK_PATTERNS = ("*free*", "*flash*", "*mini*", "*small*", "*lite*", "*:0.5b*",
                 "*:1.5b*", "*:3b*", "*:7b*")
STRONG_PATTERNS = ("*opus*", "*sonnet*", "*pro*", "*max*", "*large*")

# A weak model only receives work it can finish in a constrained reply.
WEAK_MAX_SIZE = 160
WEAK_MAX_ROUNDS = 3
WEAK_VARIANTS = 3


def _patterns(name):
    raw = os.environ.get(name, "")
    return [item.strip().lower() for item in raw.split(",") if item.strip()]


def _matches(model, patterns):
    low = (model or "").lower()
    return any(fnmatch.fnmatch(low, pattern) for pattern in patterns)


def calibration(model):
    """Measured optimizer profile, or ``{}`` when the model is uncalibrated."""
    try:
        from roc import telemetry
        return telemetry.profile(model) or {}
    except Exception:
        return {}


def _measured(profile):
    results = profile.get("calibration_results") or []
    rows = [row for row in results if isinstance(row, dict)]
    if not rows:
        return None
    attempts = sum(int(row.get("compile_attempts") or 0) for row in rows)
    exact = sum(int(row.get("exact_matches") or 0) for row in rows)
    jobs = sum(int(row.get("jobs") or 0) for row in rows)
    compile_rate = (sum(float(row.get("compile_rate") or 0) * int(row.get("compile_attempts") or 0)
                        for row in rows) / attempts) if attempts else 0.0
    return {"jobs": jobs, "exact": exact, "compile_rate": round(compile_rate, 1)}


def classify(model, profile=None):
    """Return ``(class, evidence)`` where class is weak/strong/unknown."""
    if _matches(model, _patterns("ROC_STRONG_MODELS")):
        return "strong", "ROC_STRONG_MODELS"
    if _matches(model, _patterns("ROC_WEAK_MODELS")):
        return "weak", "ROC_WEAK_MODELS"
    profile = calibration(model) if profile is None else profile
    measured = _measured(profile)
    if measured and measured["jobs"] >= 4:
        if measured["exact"] == 0 and (measured["compile_rate"] < 40 or
                                       int(profile.get("max_tokens") or 0) <= 1024):
            return "weak", "calibration: %d jobs, 0 exacts, %.0f%% compile" % (
                measured["jobs"], measured["compile_rate"])
        if measured["exact"] >= 1 and measured["compile_rate"] >= 40:
            return "strong", "calibration: %d exact(s), %.0f%% compile" % (
                measured["exact"], measured["compile_rate"])
    if _matches(model, WEAK_PATTERNS):
        return "weak", "model name heuristic"
    if _matches(model, STRONG_PATTERNS):
        return "strong", "model name heuristic"
    return "unknown", "no calibration"


def patchable(job):
    """High-confidence, constrained patch work only."""
    size = int(job.get("size") or 0)
    score = int(job.get("score") or 0)
    confidence = int(job.get("source_confidence") or 0)
    source = bool((job.get("source") or "").strip())
    if not source:
        return False
    if size > WEAK_MAX_SIZE:
        return False
    # Either the stored source is close, or the source itself is measured work.
    return score >= 80 or confidence >= 40


def decide(job, model, source_only=False, requested_rounds=None, profile=None):
    """Return routing fields; no side effects and no provider calls.

    ``skip`` jobs are released and recorded, not silently dropped.  An explicit
    operator configuration can disable the routing with ``ROC_WEAK_ROUTING=0``.
    """
    enabled = os.environ.get("ROC_WEAK_ROUTING", "1") not in ("0", "false", "no")
    kind, evidence = classify(model, profile)
    result = {"model_class": kind, "evidence": evidence, "skip": False, "reason": None,
              "rounds": requested_rounds, "variants": 1, "max_size": None,
              "needs_research": False}
    if source_only or not enabled or kind != "weak":
        return result
    if not patchable(job):
        result.update(skip=True, needs_research=True,
                      reason="weak model: %s is %d B with %s source evidence"
                             % (job.get("addr"), int(job.get("size") or 0),
                                "no" if not (job.get("source") or "").strip() else "weak"))
        return result
    rounds = WEAK_MAX_ROUNDS
    if requested_rounds not in (None, "auto"):
        try:
            rounds = min(int(requested_rounds), WEAK_MAX_ROUNDS)
        except (TypeError, ValueError):
            pass
    result.update(rounds=rounds, variants=WEAK_VARIANTS, max_size=WEAK_MAX_SIZE)
    return result


def escalate(job, model, configured=None, after=2):
    """Use a stronger model only when one was explicitly configured."""
    if not configured:
        return None
    attempts = int((job.get("attempts_by_model") or {}).get(model, 0))
    return configured if attempts >= int(after) else None
