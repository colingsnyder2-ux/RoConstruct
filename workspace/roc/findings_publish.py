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


def prepare_native(root, log=print, db=None):
    """Refresh native ledgers/package for the server's existing hourly publisher."""
    root = Path(root)
    if not (root / 'rebuild/2008-06').is_dir():
        return None
    if db is None:
        path = root / 'work/server.db'
        if not path.is_file():
            return None
        with tempfile.TemporaryDirectory(prefix='findings-native-db-', dir=root / 'work') as folder:
            live = sqlite3.connect(path.as_uri() + '?mode=ro', uri=True)
            snapshot = sqlite3.connect(Path(folder) / 'snapshot.db')
            try:
                live.backup(snapshot, pages=1024)
                return prepare_native(root, log, snapshot)
            finally:
                snapshot.close()
                live.close()
    inventory = export_native(root, db)
    from roc import rebuild_package
    package = rebuild_package.export(root, root / 'local/findings/2008-06')
    log('Packaged %d files; %d large files stored in lossless chunks; %d active artifacts pending.' %
        (len(package['files']), len(package['large_files']), len(package['pending_build_files'])))
    return inventory


def export_native(root, db):
    destination = root / "local/findings/2008-06/verification"
    destination.mkdir(parents=True, exist_ok=True)
    files = {}
    accepted = [{"job": job, "patches": json.loads(patches), "timestamp": ts}
                for job, patches, ts in db.execute("SELECT job,patches,ts FROM integration_accepted ORDER BY ts,job")]
    initial = db.execute("SELECT value FROM integration_config WHERE key='initial_patches'").fetchone()
    jobs = []
    for row in db.execute("SELECT id,user,unit,model,state,phase,created,updated,patches,receipt FROM integration_jobs ORDER BY created,id"):
        job = dict(zip(("id", "user", "unit", "model", "state", "phase", "created", "updated", "patches", "receipt"), row))
        job["patches"] = json.loads(job["patches"])
        receipt = json.loads(job["receipt"] or "{}")
        job["receipt"] = {key: receipt[key] for key in (
            "accepted", "gains", "losses", "new_distinct", "owned_before", "owned_after",
            "distinct_before", "distinct_after", "baseline_revision", "submitted_revision",
            "rebased", "input_hash", "overlay_hash", "credits") if key in receipt}
        jobs.append(job)
    scores = [dict(zip(("client", "stored_sources", "exact_sources"), row)) for row in db.execute(
        "SELECT client,COUNT(*),SUM(score=100) FROM funcs WHERE client LIKE '2008%' AND source IS NOT NULL GROUP BY client")]
    credits = [dict(zip(("client", "addr", "user", "model", "job"), row)) for row in db.execute(
        "SELECT client,addr,user,model,job FROM integration_credit WHERE client LIKE '2008%' ORDER BY client,addr")]
    outputs = {"accepted-integrations.json": {"initial_patches": json.loads(initial[0]) if initial else {}, "accepted": accepted},
               "integration-jobs.json": jobs, "native-credit.json": credits,
               "inventory.json": {"clients": scores, "accepted_jobs": len(accepted), "native_credits": len(credits), "sha256": files}}
    for name, value in outputs.items():
        (destination / name).write_text(json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    native = root / 'work/integration/progress-native.json'
    if native.exists():
        (destination / 'native-functions.json').write_text(native.read_text(encoding='utf-8'), encoding='utf-8')
    return outputs["inventory.json"]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, required=True)
    parser.add_argument("--downloads-only", action="store_true", help="publish the Worker bundle without a database export")
    parser.add_argument("--package-only", action="store_true", help="publish the prepared native package without a database export")
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
    if args.package_only:
        from roc.findings_transport import publish_package
        from roc.rebuild_package import export
        package = export(root, root / 'local/findings/2008-06')
        print('Packaged %d files.' % len(package['files']), flush=True)
        publish_package(root, shutil.which('git'))
        return
    if args.downloads_only:
        from roc.findings_transport import publish_downloads
        # This small update uses its own Git index and a normal fast-forward push.
        # A concurrent findings update is rejected safely instead of being overwritten.
        publish_downloads(root, shutil.which('git'))
        return
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
                inventory = prepare_native(root, log, snapshot)
            finally:
                store.db = live
                snapshot.close()
        print(json.dumps(inventory["clients"]), flush=True)
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
