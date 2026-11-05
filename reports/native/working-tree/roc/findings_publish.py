"""Publish portable findings without changing or restarting the live server."""
import argparse
import hashlib
import json
import re
from pathlib import Path
import shutil
import sqlite3
import sys
import tempfile
import threading


def portable_text(data):
    data = data.replace(b"\r\n", b"\n")
    return re.sub(rb"https://(?:canary\.|ptb\.)?discord(?:app)?\.com/api/webhooks/[^\s\x22\x27<>]+",
                  b"DISCORD_WEBHOOK_REDACTED", data)


def export_native(root, db):
    destination = root / "local/findings/reports/native"
    destination.mkdir(parents=True, exist_ok=True)
    files = {}
    for client in sorted((root / "rebuild").glob("2008*")):
        for path in sorted(client.rglob("*")):
            relative = path.relative_to(client)
            if not path.is_file() or path.suffix not in {".py", ".json", ".h", ".cpp", ".md"}:
                continue
            if len(relative.parts) > 1 and relative.parts[0] not in {"patches", "modules", "glue", "tests"}:
                continue
            target = destination / "working-tree/rebuild" / client.name / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            # Git publishes these text files with LF endings; hash the same bytes.
            data = portable_text(path.read_bytes())
            target.write_bytes(data)
            files[target.relative_to(destination).as_posix()] = hashlib.sha256(data).hexdigest()
    for name in ("rebuild.py", "integration.py", "integration_verify.py", "native_sweep.py", "findings_publish.py"):
        path = Path(__file__) if name == "findings_publish.py" else root / "roc" / name
        if not path.is_file():
            continue
        target = destination / "working-tree/roc" / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(portable_text(path.read_bytes()))
        files[target.relative_to(destination).as_posix()] = hashlib.sha256(target.read_bytes()).hexdigest()
    accepted = [{"job": job, "patches": json.loads(patches), "timestamp": ts}
                for job, patches, ts in db.execute("SELECT job,patches,ts FROM integration_accepted ORDER BY ts,job")]
    initial = db.execute("SELECT value FROM integration_config WHERE key='initial_patches'").fetchone()
    jobs = []
    for row in db.execute("SELECT id,unit,model,state,phase,created,updated,patches,receipt FROM integration_jobs ORDER BY created,id"):
        job = dict(zip(("id", "unit", "model", "state", "phase", "created", "updated", "patches", "receipt"), row))
        job["patches"] = json.loads(job["patches"])
        receipt = json.loads(job["receipt"] or "{}")
        job["receipt"] = {key: receipt[key] for key in (
            "accepted", "gains", "losses", "new_distinct", "owned_before", "owned_after",
            "distinct_before", "distinct_after", "baseline_revision", "submitted_revision",
            "rebased", "input_hash", "overlay_hash", "credits") if key in receipt}
        jobs.append(job)
    scores = [dict(zip(("client", "stored_sources", "exact_sources"), row)) for row in db.execute(
        "SELECT client,COUNT(*),SUM(score=100) FROM funcs WHERE client LIKE '2008%' AND source IS NOT NULL GROUP BY client")]
    credits = [dict(zip(("client", "addr", "model", "job"), row)) for row in db.execute(
        "SELECT client,addr,model,job FROM integration_credit WHERE client LIKE '2008%' ORDER BY client,addr")]
    outputs = {"accepted-integrations.json": {"initial_patches": json.loads(initial[0]) if initial else {}, "accepted": accepted},
               "integration-jobs.json": jobs, "native-credit.json": credits,
               "inventory.json": {"clients": scores, "accepted_jobs": len(accepted), "native_credits": len(credits), "sha256": files}}
    for name, value in outputs.items():
        (destination / name).write_text(json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    (destination / "README.md").write_text(
        "# 2008 native integration findings\n\n"
        "`accepted-integrations.json` preserves the server's accepted overlay history. "
        "`native-credit.json` records server-awarded native credit.\n\n"
        "`integration-jobs.json` includes pending and rejected proposals; those are not accepted integrations. "
        "`working-tree/` contains reproducible build tooling, specs, glue and overlays as currently on disk; "
        "unsubmitted edits may be present. Acceptance comes only from the server ledger. "
        "`inventory.json` records source counts and file hashes.\n\n"
        "Recovered exact and partial functions live at `/src/<client>/`. "
        "The complete native rebuild is published at `/2008-06/`, including source and build artifacts. "
        "Private configuration and credentials remain excluded.\n", encoding="utf-8")
    return outputs["inventory.json"]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, required=True)
    args = parser.parse_args()
    root = args.root.resolve()
    # Load the live checkout's established publisher, without editing its protected inputs.
    sys.path.insert(0, str(root))
    import roc
    # Review tooling may be newer than a busy host's pinned verifier files.
    helper_path = str(Path(__file__).resolve().parent)
    if helper_path not in roc.__path__:
        roc.__path__.append(helper_path)
    from roc import server, libs
    store = server.Store.__new__(server.Store)
    store.lock = threading.Lock()
    store.db = sqlite3.connect((root / "work/server.db").as_uri() + "?mode=ro", uri=True)
    store.db.create_function("roc_library", 1, libs.library_of, deterministic=True)
    logs = []

    def publish(store, public_url, log):
        print("Exporting stored sources and portable evidence...", flush=True)
        # Export can take minutes. A live read transaction blocks commits in
        # SQLite's DELETE journal mode; back up in short steps and read privately.
        with tempfile.TemporaryDirectory(prefix="findings-db-", dir=root / "work") as folder:
            snapshot = sqlite3.connect(Path(folder) / "snapshot.db")
            live = store.db
            try:
                live.backup(snapshot, pages=1024)
                snapshot.create_function("roc_library", 1, libs.library_of, deterministic=True)
                store.db = snapshot
                server.sync_findings(store)
                inventory = export_native(root, snapshot)
            finally:
                store.db = live
                snapshot.close()
        print(json.dumps(inventory["clients"]), flush=True)
        if (root / 'rebuild/2008-06').is_dir():
            from roc import rebuild_package
            print('Exporting complete 2008-06 rebuild package...', flush=True)
            package = rebuild_package.export(root, root / 'local/findings/2008-06')
            print('Packaged %d files; %d large files stored in lossless chunks.' %
                  (len(package['files']), len(package['large_files'])), flush=True)
            if package['pending_build_files']:
                print('%d build artifacts still being written; recorded as pending in package.json.' %
                      len(package['pending_build_files']), flush=True)
        from roc import findings_transport
        findings_transport.publish(root, shutil.which("git"), log)

    def log(message):
        logs.append(message)
        print(message, flush=True)

    # Reuse the live publisher's cross-process lock; publish to findings only.
    original_publish = server._publish_once
    server._publish_once = publish
    try:
        server.publish_once(store, None, log)
    finally:
        server._publish_once = original_publish
        store.db.close()
    if any("failed" in line.lower() or "unavailable" in line.lower() or "already running" in line.lower() for line in logs):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
