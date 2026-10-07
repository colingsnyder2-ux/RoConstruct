"""One-click links: roconstruct://work?client=2008M&server=host:8765

`roc link install` registers the roconstruct:// scheme for the current
Windows user (HKCU, no admin). Clicking a link opens a console that sets up
whatever is missing, asks for a username once, and runs a worker until closed.
"""
import ctypes
import os
import re
import sys
import time
from pathlib import Path
from urllib.parse import parse_qs, urlparse

ROOT = Path(__file__).resolve().parent.parent
SCHEME = "roconstruct"
CLIENT_RE = re.compile(r"^[A-Za-z0-9_-]{1,32}$")
SERVER_RE = re.compile(r"^(https?://)?[A-Za-z0-9.-]+(:\d{1,5})?/?$")


def install():
    import winreg
    cmd = '"%s" link "%%1"' % (ROOT / "roc.cmd")
    with winreg.CreateKey(winreg.HKEY_CURRENT_USER, r"Software\Classes\%s" % SCHEME) as k:
        winreg.SetValueEx(k, "", 0, winreg.REG_SZ, "URL:RoConstruct")
        winreg.SetValueEx(k, "URL Protocol", 0, winreg.REG_SZ, "")
    with winreg.CreateKey(winreg.HKEY_CURRENT_USER, r"Software\Classes\%s\shell\open\command" % SCHEME) as k:
        winreg.SetValueEx(k, "", 0, winreg.REG_SZ, cmd)
    print("One-click links enabled: %s:// links now open RoConstruct from %s" % (SCHEME, ROOT))


def remove():
    import winreg
    for sub in (r"shell\open\command", r"shell\open", "shell", ""):
        try:
            winreg.DeleteKey(winreg.HKEY_CURRENT_USER, r"Software\Classes\%s%s" % (SCHEME, "\\" + sub if sub else ""))
        except OSError:
            pass
    print("One-click links disabled.")


def installed():
    try:
        import winreg
        with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r"Software\Classes\%s\shell\open\command" % SCHEME) as k:
            return str(ROOT / "roc.cmd") in winreg.QueryValueEx(k, "")[0]
    except OSError:
        return False


def parse(url):
    """Validate a link. Only client, server and token are read; nothing else."""
    u = urlparse(url)
    if u.scheme != SCHEME or (u.netloc or u.path.strip("/")) != "work":
        raise SystemExit("Not a RoConstruct work link: %s" % url)
    q = {k: v[0] for k, v in parse_qs(u.query).items()}
    client, server = q.get("client", ""), q.get("server", "")
    if not CLIENT_RE.match(client) or not SERVER_RE.match(server):
        raise SystemExit("Link has a bad client or server value.")
    return client, server, q.get("token")


def keep_awake():
    """Stop Windows sleeping while the worker runs (screen may still turn off)."""
    if os.name == "nt":
        ctypes.windll.kernel32.SetThreadExecutionState(0x80000000 | 0x00000001)


def wait_for_exe(client, log=print):
    from roc import clients
    entry = clients.load()[client]
    if clients.status(client, entry) == "ok":
        return
    folder = ROOT / "clients" / client
    folder.mkdir(parents=True, exist_ok=True)
    log("Put your copy of %s in this folder:\n  %s\n(it must be the exact %s build). Waiting..."
        % (entry["exe"], folder, client))
    if os.name == "nt":
        os.startfile(folder)
    while clients.status(client, entry) != "ok":
        if clients.status(client, entry) == "hash mismatch":
            log("That file is a different build (hash mismatch). Replace it with the right one.")
            time.sleep(10)
        time.sleep(3)
    log("Found it.")


def run(url):
    """Everything a link click does, in order."""
    from roc import analyze, clients, draft, setup, worker
    client, server, token = parse(url)
    s = worker.load_settings()
    known = s.get("known_servers", [])
    user = s.get("user")
    print("RoConstruct: help decompile Roblox %s" % client)
    print("Server: %s" % server)
    if server not in known or not user:
        if server not in known:
            print("This is the first time you're joining this server. Only continue if you trust the link.")
        while not worker.USER_RE.match(user or ""):
            user = input("Pick a username for the leaderboard (letters/digits, 2-32): ").strip()
        worker.save_settings(known_servers=known + [server] if server not in known else known)
    worker.save_settings(user=user, server=server, token=token)

    if client not in clients.load():
        raise SystemExit("This copy of RoConstruct doesn't know %s. Download the latest version." % client)
    build = clients.load()[client]["compiler_build"]
    if build not in setup.compilers():
        print("Downloading the compiler for %s (one time)..." % client)
        setup.FETCHERS[build]()
        setup.compilers.cache_clear()
    wait_for_exe(client)
    if not (ROOT / "work" / client / "functions.jsonl").exists():
        print("Analyzing %s (one time, about 10 seconds)..." % client)
        analyze.analyze(client, clients.exe_path(client, clients.load()[client]))
    if not draft.pick_model(s.get("model")):
        ensure_model()
    keep_awake()
    print("Working. Leave this window open overnight; close it to stop.\n")
    worker.run(server, user, token, s.get("model"), forever=True, only=[client])


def ensure_model():
    import shutil
    import subprocess
    from roc import draft
    if not shutil.which("ollama"):
        if input("AI workers need Ollama (free). Install it now? [Y/n] ").strip().lower() in ("", "y", "yes"):
            subprocess.run(["winget", "install", "--id", "Ollama.Ollama", "-e",
                            "--accept-package-agreements", "--accept-source-agreements"])
        if not shutil.which("ollama"):
            raise SystemExit("Ollama is installed: close this window and click the link again.")
    if not draft.ollama_models():
        subprocess.Popen(["ollama", "serve"], creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
        time.sleep(3)
    if not draft.pick_model():
        print("Downloading the AI model qwen2.5-coder:7b (about 4.7 GB, one time)...")
        subprocess.run(["ollama", "pull", "qwen2.5-coder:7b"], check=True)
