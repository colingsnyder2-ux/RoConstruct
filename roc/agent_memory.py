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
    return [campaign_context(row) for row in research.journal_records(path)
            if row.get("client", "2008-06") in clients.load()]


# Fields that identify a machine-local experiment report. Reports may describe tool or
# workflow suggestions, and those fields need to cross PCs, so only local/private fields
# are stripped here. Everything else is retained as bounded experiment evidence.
PRIVATE_REPORT_FIELDS = {"shared_id", "reported_by", "server_confirmed", "token",
    "evidence", "local_path", "private_path", "credentials", "password"}


def portable(row):
    result = {k: v for k, v in row.items() if k not in PRIVATE_REPORT_FIELDS}
    for key, value in result.items():
        if isinstance(value, str):
            result[key] = value[:2000]
    if isinstance(result.get("receipt"), dict):
        result["receipt"] = {k: v for k, v in result["receipt"].items()
                            if k in ("verified", "improved", "score", "stored", "reason")}
    return json.loads(providers.sanitize_prompt(json.dumps(result)))

TOOL_RECORD_KINDS = {"tool", "tool_suggestion", "tools", "script", "script_suggestion",
    "command", "command_suggestion", "workflow", "workflow_improvement", "workflow_suggestion"}


def is_tool_record(row):
    if not isinstance(row, dict):
        return False
    kind = str(row.get("kind", "")).strip().lower()
    if kind in TOOL_RECORD_KINDS or kind.replace("-", "_").startswith("tool") or "tool" in kind or kind.startswith("workflow") or kind.startswith("script"):
        return True
    return any(key in row for key in ("script", "script_text", "content", "command", "command_line", "tool_name", "workflow"))


def tool_records(shared=None):
    rows = list(records())
    if isinstance(shared, dict):
        rows += list(shared.get("records", []))
    return [row for row in rows if is_tool_record(row)]


# Compatibility names used by callers and tests.
tools = tool_records
suggested_tools = tool_records
suggest_tool_record = tool_records


def _rejected(error):
    """The server refused this content (not: offline, or a server without the endpoint)."""
    return getattr(error, "category", "") == "bad_request" and "unknown endpoint" not in str(error)


def append_record(row):
    from roc import research
    path = ROOT / "work" / "agent-memory" / "attempts.jsonl"
    row = campaign_context(row)
    if row.get("kind") == "trial" and "T" not in row.get("date", ""):
        row["date"] = _now()
    research.append(path, row)
    return row


def campaign_context(row):
    """Recover task metadata when a manually journaled trial supplies its evidence path."""
    if row.get("kind") != "trial" or row.get("campaign_id") or not row.get("evidence"):
        return row
    evidence = Path(row["evidence"]).resolve()
    if not evidence.is_relative_to((ROOT / "work" / "agent-campaigns").resolve()):
        return row
    for folder in (evidence.parent, *evidence.parents):
        task_path = folder / "task.json"
        if task_path.exists():
            task = json.loads(task_path.read_text(encoding="utf-8"))
            if task["client"] == row.get("client") and task["addr"] in row.get("addresses", []):
                return {**row, **{key: task[key] for key in ("campaign_id", "baseline_hash", "target_revision") if key in task}}
            break
    return row


def _now():
    from datetime import datetime, timezone
    return datetime.now(timezone.utc).isoformat()


def suggest_tool(name=None, title=None, description="", script="", path="", command="", client="2008-06",
                 workflow=None, kind="tool_suggestion", **extra):
    row = {"kind": kind, "date": _now(), "client": client, "name": name or title, "title": title or name,
           "description": description, "script": script, "path": path, "command": command}
    if workflow:
        row["workflow"] = workflow
    row.update({k: v for k, v in extra.items() if v is not None})
    if name is None and title is None:
        row.pop("name", None)
        row.pop("title", None)
    return append_record(row)


# Common aliases, so agents/tests can use either naming convention.
create_tool = suggest_tool
create_tool_suggestion = suggest_tool
record_tool = suggest_tool
tool_suggestion = suggest_tool
suggest_script = suggest_tool
record_script = suggest_tool
record_tool_suggestion = suggest_tool
append_tool = suggest_tool
append_tool_suggestion = suggest_tool
save_tool_suggestion = suggest_tool
create_tool_record = suggest_tool
add_tool = suggest_tool
add_tool_suggestion = suggest_tool
workflow_improvement = lambda **kwargs: suggest_tool(kind="workflow_improvement", **kwargs)

# Generic local-memory helpers for agents and tests that use either name.
append = append_record
remember = lambda rows: len([append_record(row) for row in (rows if isinstance(rows, list) else [rows])])
save = remember


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
