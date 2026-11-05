"""Read-only candidate ranking shared by the server and the CLI.

The ordering is deliberately evidence-first, not similarity-first:

1. an exact matched donor with the same shape/family (copy and adjust);
2. a measured residue class (data-only, one constant, import) when the server
   actually has that measurement;
3. an authentic source/template candidate;
4. a small candidate with proven source;
5. everything else, split by structural difficulty.

Similarity score is a weak tie-breaker.  Repeated no-gain attempts, missing
source on an oversized function, unknown ABI/layout evidence and active claims
lower the rank; they never silently mark a target "easy".  Mismatch categories
are only reported when supplied: absent data is ``unknown``, not a guess.
"""
import math

DONOR, RESIDUE, SOURCE, SMALL_SOURCE, STRUCTURAL, RESEARCH = range(6)

PROFILES = {
    "quick": {"max_size": 160, "size_penalty": 0.35, "tier_max": 5},
    "balanced": {"max_size": 512, "size_penalty": 0.15, "tier_max": 5},
    "deep": {"max_size": 4096, "size_penalty": 0.08, "tier_max": 5},
}

RESIDUE_CLASSES = {
    "data": "data-only residue",
    "data mismatch": "data-only residue",
    "one constant": "one-constant residue",
    "one_constant": "one-constant residue",
    "constant": "one-constant residue",
    "import": "import/declaration residue",
    "imports": "import/declaration residue",
    "calling_convention": "ABI/calling-convention residue",
    "direct_member_receiver": "member-receiver residue",
    "return_carrier": "return-carrier residue",
}


def profile(name):
    return PROFILES.get(str(name or "quick").lower(), PROFILES["quick"])


def _int(value, default=0):
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def _residue_kind(mismatch):
    if not mismatch:
        return None
    text = str(mismatch).strip().lower()
    for key, label in RESIDUE_CLASSES.items():
        if key in text:
            return label
    return None


def _source_rank(row):
    """How much real source evidence the row carries."""
    confidence = _int(row.get("source_confidence"))
    score = _int(row.get("score"))
    size = _int(row.get("size"))
    source = bool(row.get("has_source", True))
    if source and (confidence >= 50 or score >= 85):
        return SOURCE, "source-backed near miss"
    if source and confidence > 0 and size <= 160:
        return SMALL_SOURCE, "small candidate with proven source"
    if confidence > 0:
        return SOURCE, "source evidence present"
    return None, ""


def _tier(row, twin, mismatch, profile_name):
    """Return (tier, recommendation, primary reason)."""
    measured = _residue_kind(mismatch)
    score = _int(row.get("score"))
    size = _int(row.get("size"))
    confidence = _int(row.get("source_confidence"))
    attempts = _int(row.get("attempts"))
    if twin:
        return DONOR, "reuse", "exact twin %s already matched (same shape/family)" % twin
    if measured:
        return RESIDUE, "patch", "measured %s" % measured
    source_tier, source_reason = _source_rank(row)
    if source_tier is not None:
        return source_tier, "patch", "%s at %d%%" % (source_reason, score)
    if confidence <= 0 and size > (160 if profile_name == "quick" else 300):
        return STRUCTURAL, "structural", "oversized (%d B) with no source evidence" % size
    if score >= 90:
        return SOURCE, "patch", "high similarity (%d%%) but unknown source provenance" % score
    if score >= 60:
        return STRUCTURAL, "structural", "partial similarity (%d%%); needs structural evidence" % score
    return RESEARCH, "research", "low similarity (%d%%) and no source evidence" % score


def _penalties(row, profile_name, now=None):
    """Return (points to subtract, list of reasons)."""
    conf = profile(profile_name)
    size = _int(row.get("size"))
    score = _int(row.get("score"))
    attempts = _int(row.get("attempts"))
    confidence = _int(row.get("source_confidence"))
    stuck = _int(row.get("stuck_models") or 0)
    penalty, reasons = 0.0, []
    if attempts > 0:
        amount = min(40, attempts * 8)
        penalty += amount
        reasons.append("%d attempt(s) without a stored gain" % attempts)
    if stuck >= 2:
        penalty += 35
        reasons.append("%d model(s) already failed twice" % stuck)
    if confidence <= 0 and score < 70:
        penalty += 18
        reasons.append("ABI/layout unknown")
    if size <= 0:
        penalty += 20
        reasons.append("size unknown")
    elif size > conf["max_size"]:
        excess = size / float(conf["max_size"])
        penalty += min(70, (excess - 1) * 40)
        reasons.append("%d B exceeds the %s profile size" % (size, profile_name))
    if confidence <= 0 and size > 300:
        penalty += 45
        reasons.append("oversized without source")
    if row.get("claimed"):
        penalty += 12
        reasons.append("claimed by %s" % (row.get("owner") or "another worker"))
    return penalty, reasons


def rank_one(row, twin=None, mismatch=None, profile_name="quick"):
    """Rank a single candidate.  Pure function; no I/O."""
    profile_name = str(profile_name or "quick").lower()
    if profile_name not in PROFILES:
        profile_name = "quick"
    tier, recommendation, reason = _tier(row, twin, mismatch, profile_name)
    con = profile(profile_name)
    score = _int(row.get("score"))
    size = max(_int(row.get("size")), 1)
    # Similarity is intentionally a small tie-breaker (max ~15 points).
    rank = 1000.0 - tier * 100.0 + min(15.0, score * 0.15)
    rank -= con["size_penalty"] * math.log2(size)
    penalty, reasons = _penalties(row, profile_name)
    rank -= penalty
    if row.get("cooldown_until") and not now_is_past(row.get("cooldown_until")):
        reasons.append("parked by a local cooldown")
        rank -= 30
    return {
        "addr": row.get("addr"),
        "score": score,
        "size": _int(row.get("size")),
        "unit": row.get("unit"),
        "shape": row.get("shape"),
        "family": row.get("family"),
        "attempts": _int(row.get("attempts")),
        "source_confidence": _int(row.get("source_confidence")),
        "difficulty": row.get("difficulty"),
        "twin": twin,
        "claimed": bool(row.get("claimed")),
        "owner": row.get("owner"),
        "claim_expires": row.get("claim_expires"),
        "mismatch_category": mismatch,
        "tier": tier,
        "recommendation": recommendation,
        "difficulty_reason": reason,
        "penalties": reasons,
        "rank": round(rank, 3),
    }


def now_is_past(value):
    import time
    try:
        return float(value) <= time.time()
    except (TypeError, ValueError):
        return False


def rank_candidates(rows, matched=None, profile_name="quick", max_size=None, limit=20,
                    exclude_claimed=False):
    """Rank a full eligible pool.

    ``matched`` maps shape/family to a matched address.  ``mismatch`` on a row is
    only used when the caller supplies a real measurement."""
    matched = matched or {"shape": {}, "family": {}}
    shape_twin = matched.get("shape", {}) if isinstance(matched, dict) else {}
    family_twin = matched.get("family", {}) if isinstance(matched, dict) else {}
    out = []
    for row in rows:
        if max_size and _int(row.get("size")) > int(max_size):
            continue
        if exclude_claimed and row.get("claimed"):
            continue
        shape = row.get("shape")
        family = row.get("family")
        twin = shape_twin.get(shape) if shape else None
        if not twin and family:
            twin = family_twin.get(family)
        out.append(rank_one(row, twin=twin, mismatch=row.get("mismatch_category"),
                            profile_name=profile_name))
    out.sort(key=lambda row: (-row["rank"], row["attempts"], row["size"], row["addr"] or ""))
    return out[:max(1, int(limit))] if limit else out


def summary(row):
    """One-line human explanation used by ``roc scout``."""
    twin = " twin=%s" % row["twin"] if row.get("twin") else ""
    why = row.get("difficulty_reason") or "unknown"
    if row.get("penalties"):
        why += " (" + "; ".join(row["penalties"][:2]) + ")"
    return "%s %3d%% %4dB %-9s %-10s%s" % (
        row.get("addr"), row.get("score", 0), row.get("size", 0),
        row.get("recommendation", "?"), "%d att" % row.get("attempts", 0), twin) + "  " + why
