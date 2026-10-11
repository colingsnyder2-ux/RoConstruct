"""Credential-free CPU views and local config controls for dashboard/terminal."""
import hashlib
import json
import time
from pathlib import Path

from roc import task_files, worker

ROOT = Path(__file__).resolve().parent.parent


def configs():
    paths = set((ROOT / "work").glob("**/node.json"))
    paths.update((ROOT / "work").glob("**/*cpu*.json"))
    found = {}
    for path in sorted(paths):
        if any(part.startswith(("cluster-test-", "cluster-solo-test-")) for part in path.parts):
            continue
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
            if "servers" in data and ("admin_token" in data or "cpu_enabled" in data):
                key = hashlib.sha256(str(path.resolve()).encode()).hexdigest()[:16]
                found[key] = (path, data)
        except (ValueError, OSError):
            continue
    return found


def snapshot(cluster_id=None):
    found = configs()
    nodes, local = [], []
    for key, (path, data) in found.items():
        label = str(path.relative_to(ROOT))
        if "admin_token" in data:
            nodes.append({"id": key, "label": label})
        else:
            try:
                state = json.loads(path.with_suffix(".status.json").read_text())
            except (ValueError, OSError):
                state = {}
            local.append({"id": key, "label": label, "worker": data.get("worker"),
                          "enabled": data.get("cpu_enabled") is True, "paused": bool(data.get("cpu_paused")),
                          "running": state.get("stage") != "stopped" and time.time() - state.get("seen", 0) < 65,
                          "status": state})
    from roc import command_watch
    result = {"clusters": nodes, "local": local, "remote": None, "selected": cluster_id,
              "tasks": command_watch.tasks()}
    if not nodes:
        nodes.extend({"id": n["id"], "label": n["label"]} for n in local)
    if not nodes:
        return result
    nodes.sort(key=lambda n: found[n["id"]][0].stat().st_mtime, reverse=True)
    selected = cluster_id or nodes[0]["id"]
    if selected not in found:
        raise ValueError("Choose a configured coordinator")
    result["selected"] = selected
    config = found[selected][1]
    result["local"] = [n for n in local if set(found[n["id"]][1]["servers"]) == set(config["servers"])]
    api = worker.Api(",".join(config["servers"]), config.get("admin_token") or config["worker_token"])
    try:
        result["remote"] = api.call("/v2/cpu/dashboard", timeout=2)
    except RuntimeError as error:
        result["error"] = str(error)
    finally:
        api.close()
    return result


def control(data):
    key, action = data.get("config"), data.get("action")
    if action not in ("pause", "resume", "off", "on"):
        raise ValueError("Use pause, resume, off or on")
    found = configs()
    if key not in found:
        raise ValueError("Unknown CPU config")
    path, config = found[key]
    if "admin_token" in config:
        api = worker.Api(",".join(config["servers"]), config["admin_token"])
        try:
            endpoint = "/v2/cpu/job-control" if data.get("job") else "/v2/cpu/control"
            return api.call(endpoint, {"action": action, "id": data.get("job"), "worker": data.get("worker")})
        finally:
            api.close()
    if action in ("pause", "resume"):
        config["cpu_paused"] = action == "pause"
    else:
        config.update(cpu_enabled=action == "on", cpu_paused=False)
    task_files.write_text(path, json.dumps(config, indent=2))
    return {"ok": True, "finish_current": True}


def print_status(report):
    print("CPU mining · coordinator %s · %s voter(s)" % (report["node"], report["replicas"]))
    for node in report["nodes"]:
        meta = node["metadata"]
        state = "off" if not node["enabled"] else "paused" if node["paused"] else "enabled"
        print("%s · %s · %s · owner %s · %s" % (node["id"], meta.get("pc", "unknown PC"), state,
              meta.get("owner", "unknown"), meta.get("stage", "idle")))
    for job in report["jobs"]:
        print("%s · %s · %s · owner %s · PC worker %s · %s/%s verified · +%s exact / +%s partial" % (
            job["id"][:12], job["command"], job["state"], job["owner"], job["worker"] or "unassigned",
            job["completed"], job["total"], job["exact_gains"], job["partial_gains"]))
        print("  %s · %s · %s · %s" % (job["client"], ", ".join(job["addrs"]), job["compiler"], job["flags"]))
