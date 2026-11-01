"""Server-free 2008-06 native integration for forks.

Set ROC_INTEGRATION_OFFLINE=1 and the integration endpoints that native-try needs are answered from
files in this checkout instead of the group server:

  /v1/integration/base      built from rebuild/2008-06/patches (generator, rbxgs-client.json,
                            native-promotions.json): the accepted baseline is whatever is committed.
  /v1/integration/evidence  rebuild/2008-06/offline/evidence.json (snapshot of the server's mined
                            exact targets, linked addresses and native names).
  /v1/integration           rebuild/2008-06/offline/ledger.json (accepted jobs and their gains).

Claims, submissions and credit do not exist offline. `roc native-try accept` runs the same local
linked preflight the server runs (full build/link, no lost bodies, reference and runtime gates)
and, only when it passes, appends the proven edits to native-promotions.json and the gains to the
ledger. A maintainer re-verifies on the server before anything earns credit.

  roc native-try snapshot   refresh evidence.json/ledger.json from the configured server (online)
"""
import hashlib
import json
import os
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PATCHES = ROOT / "rebuild/2008-06/patches"
OFFLINE = ROOT / "rebuild/2008-06/offline"
EVIDENCE = OFFLINE / "evidence.json"
LEDGER = OFFLINE / "ledger.json"
FEATURES = {"context": 1, "metrics": 1, "native_reference_gate": 1, "exact_unit_batches": True,
            "selection_modes": ["easy", "balanced", "large"]}
LIMITS = {"claims": 1024, "targets": 100000, "overlay_paths": 1024, "edits_per_path": 4096,
          "overlay_bytes": 25165824, "evidence_bytes": 2097152, "request_bytes": 33554432}


def enabled():
    return os.environ.get("ROC_INTEGRATION_OFFLINE", "").strip().lower() not in ("", "0", "false", "no")


def _read(path, default):
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except FileNotFoundError:
        return default


def base():
    generator = PATCHES / "make_rbxgs_client.py"
    overlay = _read(PATCHES / "rbxgs-client.json", {})
    accepted = _read(PATCHES / "native-promotions.json", [])
    digest = hashlib.sha256(generator.read_bytes()).hexdigest()
    revision = hashlib.sha256(json.dumps([digest, overlay, accepted], sort_keys=True).encode()).hexdigest()
    return {"revision": revision, "overlay": overlay, "generator": digest, "accepted": accepted,
            "features": dict(FEATURES), "limits": dict(LIMITS), "offline": True}


def ledger():
    return _read(LEDGER, {"jobs": []})


def call(path, payload=None):
    """Answer the read-only integration endpoints; refuse anything that would claim or submit."""
    from roc.worker import ApiFailure
    route, _, query = path.partition("?")
    if payload is None and route == "/v1/integration/base":
        return base()
    if payload is None and route == "/v1/integration/evidence":
        if not EVIDENCE.exists():
            raise ApiFailure("offline", "no %s; run roc native-try snapshot while the server is up" % EVIDENCE.relative_to(ROOT))
        return _read(EVIDENCE, {})
    if payload is None and route == "/v1/integration":
        jobs = ledger()["jobs"]
        if query.startswith("id="):
            jobs = [j for j in jobs if j["id"] == query[3:]]
        result = {"jobs": jobs, "verifier_error": None, "parked": 0, "leaderboard": []}
        if "claims=1" in query:
            result.update(claims=[], inventory={})
        return result
    raise ApiFailure("offline", "%s needs the group server; offline integration uses roc native-try accept" % route)


def snapshot(api):
    """Save the server's evidence and accepted job gains so a fork can work without it."""
    OFFLINE.mkdir(parents=True, exist_ok=True)
    evidence = api.call("/v1/integration/evidence", timeout=300)
    jobs = api.call("/v1/integration")["jobs"]
    accepted = [{"id": j["id"], "state": "accepted", "unit": j.get("unit"), "source": "server",
                 "receipt": {"gains": sorted(j.get("receipt", {}).get("gains", []))}}
                for j in jobs if j.get("state") == "accepted"]
    local = [j for j in ledger()["jobs"] if j.get("source") == "offline"]
    known = {j["id"] for j in accepted}
    _write(EVIDENCE, evidence)
    _write(LEDGER, {"jobs": accepted + [j for j in local if j["id"] not in known]})
    return {"targets": len(evidence.get("targets", {})), "linked": len(evidence.get("linked", [])),
            "server_jobs": len(accepted), "offline_jobs": len(local)}


def accept(additions, receipt, model=None, files=()):
    """Record a locally preflight-accepted overlay delta as the next native promotion."""
    from roc import integration
    if receipt.get("accepted") is not True:
        raise ValueError("preflight did not accept: %s" % receipt.get("reason", "unknown"))
    current = base()
    promotions = list(current["accepted"])
    entry = integration.validate_patches(integration.canonical_patches(additions, current["overlay"]))
    promotions.append(entry)
    job = hashlib.sha256(json.dumps([current["revision"], entry], sort_keys=True).encode()).hexdigest()[:16]
    _write(PATCHES / "native-promotions.json", promotions)
    book = ledger()
    book["jobs"].append({"id": "offline-" + job, "state": "accepted", "source": "offline", "files": sorted(files),
                         "model": model, "ts": int(time.time()),
                         "receipt": {"gains": sorted(receipt.get("gains", [])), "losses": receipt.get("losses", [])}})
    _write(LEDGER, book)
    return "offline-" + job


def _write(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(path.suffix + ".tmp")
    temporary.write_text(json.dumps(data, indent=1) + "\n", encoding="utf-8")
    os.replace(temporary, path)
