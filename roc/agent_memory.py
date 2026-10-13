"""Share bounded experiment reports through the existing group server."""
import hashlib
import json
from pathlib import Path

from roc import clients, providers, worker

ROOT = Path(__file__).resolve().parent.parent
CONTEXT_FILES = ("CLAUDE.md", "docs/AGENT_GUIDE.md", "research/recipes.json", "research/reports.json", "research/log.jsonl")


def context():
    return {name: (ROOT / name).read_text(encoding="utf-8") for name in CONTEXT_FILES if (ROOT / name).is_file()}


def records():
    from roc import research
    path = ROOT / "work" / "agent-memory" / "attempts.jsonl"
    return [row for row in research.journal_records(path) if row.get("client", "2008-06") in clients.load()]



def portable(row):
    allowed = {"kind", "date", "client", "addresses", "library", "area", "profile", "phase",
        "group", "group_cohort", "cohort", "hypothesis", "change", "source_hash", "before_hash",
        "after_hash", "compiler", "flags", "before", "after", "candidate", "outcome", "gains",
        "exacts_gained", "elapsed_seconds", "next", "cli", "server_stored", "receipt", "error", "diff", "symbol",
        "recipe", "tried", "local_exact", "exhausted", "object_hash", "target_hash",
        "campaign_id", "baseline_hash", "target_revision", "tested_hypotheses",
        "observed_server_gains", "attribution", "validation_failed", "evidence_hash",
        "repair_attempted", "skip_reason", "stop_reason", "agent_exit_code", "agent_error",
        "trials_recorded", "agent_output_tail", "time_budget_seconds", "budget_elapsed"}
    result = {k: v for k, v in row.items() if k in allowed}
    for key, value in result.items():
        if isinstance(value, str):
            result[key] = value[:2000]
    if isinstance(result.get("receipt"), dict):
        result["receipt"] = {k: v for k, v in result["receipt"].items()
                            if k in ("verified", "improved", "score", "stored", "reason")}
    return json.loads(providers.sanitize_prompt(json.dumps(result)))


def _rejected(error):
    """The server refused this content (not: offline, or a server without the endpoint)."""
    return getattr(error, "category", "") == "bad_request" and "unknown endpoint" not in str(error)


def append_record(row):
    from roc import research
    path = ROOT / "work" / "agent-memory" / "attempts.jsonl"
    research.append(path, row)
    return row


def shared(server=None, token=None, user=None, upload=False):
    settings = worker.load_settings()
    server = server or settings.get("server")
    user = user or settings.get("user")
    if not server:
        return {"records": [], "available": False, "error": "Configure a group server to share memory"}
    path = ROOT / "work" / "agent-memory" / ("shared-" + hashlib.sha256(server.encode()).hexdigest()[:12] + ".json")
    try:
        cached = json.loads(path.read_text(encoding="utf-8")) if path.exists() else {"cursor": 0, "records": []}
    except ValueError:
        cached = {"cursor": 0, "records": []}
    api = worker.Api(server, token or settings.get("token"))
    try:
        if upload and user:
            rows = records()
            for start in range(cached.get("uploaded", 0), len(rows), 100):
                batch = [portable(row) for row in rows[start:start + 100]]
                try:
                    api.call("/v1/agent-memory", {"user": user, "records": batch}, timeout=10)
                except worker.ApiFailure as error:
                    if not _rejected(error):
                        raise  # offline or older server: keep everything queued
                    # One malformed record must not block every later upload: send singly, skip rejects.
                    for row in batch:
                        try:
                            api.call("/v1/agent-memory", {"user": user, "records": [row]}, timeout=10)
                        except worker.ApiFailure as single:
                            if not _rejected(single):
                                raise
                            cached["rejected"] = cached.get("rejected", 0) + 1
                cached["uploaded"] = start + len(batch)
        while True:
            result = api.call("/v1/agent-memory?after=%s" % cached["cursor"], timeout=5)
            cached.update(cursor=result["cursor"], lessons=result["lessons"], context=result.get("context", {}))
            cached["records"] = (cached["records"] + result["records"])[-10000:]
            if not result.get("more"):
                break
        path.parent.mkdir(parents=True, exist_ok=True)
        from roc import tasks
        tasks.write_text(path, json.dumps(cached))
        paths = []
        for name, content in cached.get("context", {}).items():
            if name not in CONTEXT_FILES or not isinstance(content, str):
                continue
            target = ROOT / name
            if not target.is_file():
                target = path.parent / "context" / name
                target.parent.mkdir(parents=True, exist_ok=True)
                tasks.write_text(target, content)
            paths.append(str(target))
        cached["context_paths"] = paths
        return dict(cached, available=True)
    except (RuntimeError, OSError, ValueError) as error:
        return dict(cached, available=False, error="Memory sync unavailable: " + str(error))
    finally:
        api.close()
