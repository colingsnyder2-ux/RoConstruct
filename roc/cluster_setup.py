"""Generate a one-node private server or a three-node failover cluster."""
import hashlib
import json
import os
import platform
import secrets
import subprocess
import sys
import time
import urllib.request
import zipfile
import tarfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
VERSION = "2.15.1"


def install_broker(directory):
    machine = "arm64" if platform.machine().lower() in ("arm64", "aarch64") else "amd64"
    system = {"Windows": "windows", "Linux": "linux", "Darwin": "darwin"}.get(platform.system())
    if not system:
        raise RuntimeError("Unsupported platform for bundled NATS")
    suffix = "zip" if system == "windows" else "tar.gz"
    name = "nats-server-v%s-%s-%s.%s" % (VERSION, system, machine, suffix)
    base = "https://github.com/nats-io/nats-server/releases/download/v%s/" % VERSION
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    archive = directory / name
    with urllib.request.urlopen(base + "SHA256SUMS", timeout=30) as response:
        checksums = response.read().decode()
    expected = next((line.split()[0] for line in checksums.splitlines() if line.split()[-1].lstrip("*") == name), None)
    if not expected:
        raise RuntimeError("Release checksum missing")
    if not archive.exists() or hashlib.sha256(archive.read_bytes()).hexdigest() != expected:
        urllib.request.urlretrieve(base + name, archive)
    if hashlib.sha256(archive.read_bytes()).hexdigest() != expected:
        raise RuntimeError("NATS download checksum mismatch")
    if suffix == "zip":
        with zipfile.ZipFile(archive) as zipped:
            zipped.extractall(directory)
    else:
        with tarfile.open(archive) as packed:
            packed.extractall(directory, filter="data")
    binary = next(directory.rglob("nats-server.exe" if system == "windows" else "nats-server"))
    if system != "windows":
        binary.chmod(0o700)
    return str(binary.resolve())


def generate(directory, nodes, source_db=None, binary=None, local=False):
    if len(nodes) not in (1, 3):
        raise ValueError("Use one trusted server, or three trusted coordinator nodes. Extra CPU PCs do not need voting nodes.")
    if len(set(nodes)) != len(nodes) and not local:
        raise ValueError("Use distinct private host addresses; --local-pilot permits localhost repeats")
    directory = Path(directory).resolve()
    if directory.exists() and any(directory.iterdir()):
        raise ValueError("Choose an empty directory; existing cluster secrets/state are never overwritten")
    directory.mkdir(parents=True, exist_ok=True)
    if os.name != "nt":
        directory.chmod(0o700)
    if source_db is None:
        if (ROOT / "work" / "server.db").exists():
            raise RuntimeError("Existing server.db found. Preserve scores with --db <offline-backup.db>; do not snapshot a busy live database during setup.")
        source_db = directory / "bootstrap.db"
        from roc import clients, server
        seed = server.Store(str(source_db), 120)
        try:
            for name, entry in clients.load().items():
                if name != "2009-12" and not entry.get("donor"):
                    seed.seed(name)
        finally:
            seed.db.close()
    # Dependencies are installed only for this explicit cluster setup.
    subprocess.run([sys.executable, "-m", "pip", "install", "nats-py==2.16.0"], check=True)
    binary = str(Path(binary).resolve()) if binary else install_broker(ROOT / "tools" / "cluster")
    secret = {k: secrets.token_hex(24) for k in ("worker_token", "admin_token", "nats_token", "route_token")}
    cluster_id = secrets.token_hex(16)
    cpu_token = secrets.token_hex(24)
    http_ports = [18765 + i if local else 8766 for i in range(len(nodes))]
    nats_ports = [14222 + i if local else 4222 for i in range(len(nodes))]
    route_ports = [16222 + i if local else 6222 for i in range(len(nodes))]
    servers = ["http://%s:%d" % (host, port) for host, port in zip(nodes, http_ports)]
    urls = ["nats://%s:%d" % (host, port) for host, port in zip(nodes, nats_ports)]
    for i, host in enumerate(nodes):
        path = directory / ("node-%d" % (i + 1))
        path.mkdir()
        routes = ["nats://route:%s@%s:%d" % (secret["route_token"], h, p)
                  for j, (h, p) in enumerate(zip(nodes, route_ports)) if j != i]
        broker = {"server_name": "roc-%d" % (i + 1), "listen": "%s:%d" % (host, nats_ports[i]),
                  "authorization": {"token": secret["nats_token"]},
                  "jetstream": {"store_dir": "jetstream", "max_file_store": 20 * 1024**3}}
        if len(nodes) == 3:
            broker["cluster"] = {"name": "ROC", "listen": "%s:%d" % (host, route_ports[i]),
                                  "authorization": {"user": "route", "password": secret["route_token"]}, "routes": routes}
        (path / "nats.conf").write_text(json.dumps(broker, indent=2))
        config = {**{k: v for k, v in secret.items() if k != "route_token"}, "node": "roc-%d" % (i + 1),
                  "nats": urls, "replicas": len(nodes), "servers": servers,
                  "cluster_id": cluster_id,
                  "initial_contributor": {"id": "cpu-1", "token_hash": hashlib.sha256(cpu_token.encode()).hexdigest()},
                  "db": "projection.db", "host": host, "port": http_ports[i],
                  "broker": binary, "broker_config": "nats.conf",
                  "validate_queue": True,
                  "bootstrap": i == 0, "bootstrap_db": str(Path(source_db).resolve()) if source_db and i == 0 else None}
        (path / "node.json").write_text(json.dumps(config, indent=2))
        (path / "start.cmd").write_text('@echo off\npy -3.12 "%~dp0..\\..\\..\\roc.py" cluster start --config "%~dp0node.json"\npause\n')
        launcher = path / "start.sh"
        launcher.write_text('#!/bin/sh\nnode_dir="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)"\n'
                            'exec python3 "$node_dir/../../../roc.py" cluster start --config "$node_dir/node.json"\n')
        if os.name != "nt":
            launcher.chmod(0o700)
    contributor = {"servers": servers, "worker_token": cpu_token, "worker": "cpu-1", "cpu_enabled": False, "cpu_slots": 1}
    (directory / "cpu-worker.json").write_text(json.dumps(contributor, indent=2))
    (directory / "ai-worker.json").write_text(json.dumps({"servers": servers, "worker_token": secret["worker_token"]}, indent=2))
    (directory / "SETUP.txt").write_text(
        "PRIVATE CLUSTER: use private LAN/VPN addresses; do not expose broker or HTTP publicly.\n"
        "Run node-N/start.cmd on Windows, or start.sh on Linux. Start every node.\n"
        "First node imports bootstrap_db once, others replay automatically.\n"
        "One node works alone. Three voting nodes need two online. CPU contributors do not vote.\n"
        "Contributor gets ONLY cpu-worker.json. Keep node.json/nats.conf private.\n"
        "CPU: python roc.py cpu-worker --config cpu-worker.json --enable\n"
        "AI: python roc.py worker --server " + ",".join(servers) + " --token <worker_token from ai-worker.json> --user NAME\n"
        "On another PC copy only its node-N directory into that repo's work/cluster directory.\n"
        "From that repo run: python roc.py cluster start --config work/cluster/node-N/node.json\n"
        "Local broker binary is downloaded/checked automatically if the original path is unavailable.\n"
        "Never launch two copies of one node; each node needs its own disk state.\n")
    return directory


def start(config_path):
    from roc import cluster
    config = cluster.load_config(config_path)
    if not Path(config["broker"]).exists():
        config["broker"] = install_broker(ROOT / "tools" / "cluster")
    try:
        import nats
    except ImportError:
        subprocess.run([sys.executable, "-m", "pip", "install", "nats-py==2.16.0"], check=True)
    out = open(Path(config["db"]).parent / "broker.log", "ab")
    process = subprocess.Popen([config["broker"], "-c", config["broker_config"]], stdout=out, stderr=out,
                               cwd=Path(config["db"]).parent,
                               creationflags=subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0)
    httpd = None
    try:
        print("Broker started. Waiting for trusted cluster/bootstrap...", flush=True)
        deadline = time.monotonic() + 300
        while time.monotonic() < deadline:
            if process.poll() is not None:
                raise RuntimeError("Broker stopped; inspect broker.log")
            probe = None
            try:
                probe = cluster.Replica(config)
                probe.journal.wait(probe.journal.create())
                with probe.lock:
                    probe.sync()
                head = probe.journal.wait(probe.journal.head())
                complete = probe.db.execute("SELECT 1 FROM cluster_requests WHERE id='bootstrap-complete'").fetchone()
                probe.close()
                probe = None
                if not complete and config.get("bootstrap"):
                    cluster.initialize(config, config.get("bootstrap_db"))
                    complete = True
                if complete:
                    httpd = cluster.serve(config)
                    break
            except Exception as error:
                if probe:
                    probe.close()
                print("Waiting: %s" % str(error)[:160], flush=True)
            time.sleep(3)
        if httpd is None:
            raise RuntimeError("Cluster not ready after 5 minutes. Start remaining voting nodes; check broker.log.")
        print("Trusted server ready: http://%s:%s; CPU contribution off by default" % (config["host"], config["port"]), flush=True)
        if config.get("validate_queue", True):
            import threading
            from roc.worker import Api
            def validate_pending():
                api = Api("http://%s:%s" % (config["host"], config["port"]), config["admin_token"])
                while True:
                    try:
                        for jobid in api.call("/v2/cpu/pending")["jobs"]:
                            api.call("/v2/cpu/validate", {"id": jobid}, timeout=180)
                    except RuntimeError as error:
                        print("Validator waiting: %s" % str(error)[:160], flush=True)
                    time.sleep(3)
            threading.Thread(target=validate_pending, daemon=True).start()
        httpd.serve_forever()
    finally:
        if httpd:
            httpd.server_close()
            httpd.replica.close()
        process.terminate()
        process.wait(10)
        out.close()
