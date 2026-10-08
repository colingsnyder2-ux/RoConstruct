"""One-click links: roconstruct://work?client=2008-06&server=host:8765

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
    from roc import clients, sources
    entry = clients.load()[client]
    if clients.status(client, entry) == "ok":
        return
    # A link click means the helper wants this one client: download it from Drive
    # (falling back to clients.zip) before asking them to find it by hand.
    if client in sources.load_sources().get("drive", {}) or sources.load_sources().get("bundle"):
        log("Downloading %s (%s)..." % (client, entry["exe"]))
        try:
            sources.fetch(client, quiet=False)
            return
        except sources.FetchError as error:
            log("Automatic download failed: %s" % error)
            log("Put your own copy in the folder below and RoConstruct will carry on.")
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
    print("Selected client: %s (worker will only mine this client)" % client)
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
    from roc import providers
    if not draft.pick_model(s.get("model")) and not (s.get("model") and providers.is_cloud(s["model"])):
        ensure_model()
    model, rounds, max_size, use_revng, workers, output_budget, thinking = choose_options(s)
    if providers.is_cloud(model) and not s.get("cloud_allowed"):
        raise SystemExit("Cloud model selected. Run: roc config --allow-cloud")
    keep_awake()
    if providers.is_cloud(model):
        print("Cloud model: work runs remotely; this PC stays idle.")
    else:
        print("Working. This uses your GPU and CPU heavily (fans, heat, power draw; laptops: plug in).")
    print("Leave this window open overnight; close it to stop at any time.\n")
    worker.run_concurrent(server, user, token, model, rounds, max_size, use_revng,
                          workers=workers, source_only=False, only=[client],
                          cloud_allowed=bool(s.get("cloud_allowed")),
                          max_tokens=output_budget, thinking=thinking)


def choose_options(settings):
    """Let each link launch choose runtime options while keeping safe defaults.

    Defaults come from the last run (saved in settings), so Enter repeats
    the previous launch; any prompt still accepts a new value.
    """
    from roc import draft, providers, worker
    installed = draft.ollama_models()
    default_model = draft.pick_model(settings.get("model")) or "none"
    print("\nWorker options (Enter keeps the default):")
    print("Installed models: " + ", ".join(installed or ["none"]))
    print("Cloud models: deepseek:deepseek-flash, nvidia:qwen/qwen2.5-coder-32b-instruct, "
          "openai:gpt-5, anthropic:MODEL, gemini:MODEL")
    model = input("Model [%s]: " % default_model).strip() or default_model
    if model == "default":
        model = None
    elif providers.is_cloud(model):
        if not providers.available(model):
            import getpass
            _provider, _remote, config = providers.parse_model(model)
            key = getpass.getpass("Paste %s (hidden): " % config["key_env"]).strip()
            providers.save_secret(config["key_env"], key)
            if not providers.available(model):
                raise SystemExit("Cloud key still missing: %s" % config["key_env"])
        if not settings.get("cloud_allowed"):
            consent = input("Cloud sends bounded assembly/source clues off this PC. Continue? [y/N] ")
            if consent.strip().lower() not in ("y", "yes"):
                raise SystemExit("Cloud use cancelled.")
            settings["cloud_allowed"] = True
            from roc import worker
            worker.save_settings(cloud_allowed=True)
    elif model not in installed:
        raise SystemExit("Model '%s' is not installed. Run: roc model" % model)
    last_preset = settings.get("worker_preset", "balanced")
    preset = (input("Preset [%s] (fast/balanced/deep): " % last_preset).strip().lower() or last_preset)
    if preset not in ("fast", "balanced", "deep"):
        raise SystemExit("Preset must be fast, balanced, or deep")
    rounds, max_size, use_revng = 4, 256, True
    if preset == "fast":
        rounds, max_size, use_revng = 2, 96, False
    elif preset == "deep":
        rounds, max_size = 6, 512
    last_workers = settings.get("worker_workers", "1")
    workers = input("Workers [%s] (1-%d or auto): " % (last_workers, worker.MAX_WORKERS)).strip() or last_workers
    if workers != "auto":
        try:
            workers = max(1, min(int(workers), worker.MAX_WORKERS))
        except ValueError:
            raise SystemExit("Workers must be 1-%d or auto" % worker.MAX_WORKERS)
    if (input("Advanced (rounds, tokens, Rev.ng, thinking)? [Enter=skip, y=show]: ").strip().lower()
            in ("y", "yes", "advanced")):
        picked = input("Rounds [auto=%d]: " % rounds).strip().lower() or "auto"
        if picked != "auto":
            try:
                rounds = max(1, min(int(picked), 12))
            except ValueError:
                raise SystemExit("Rounds must be auto or 1-12")
        last_budget = settings.get("worker_output_budget", 2048)
        picked = input("Output budget [auto=%s tokens]: " % last_budget).strip().lower() or "auto"
        if picked == "auto":
            output_budget = last_budget if isinstance(last_budget, int) else 2048
        else:
            try:
                output_budget = int(picked)
            except ValueError:
                raise SystemExit("Output budget must be auto or 128-8192")
            if not 128 <= output_budget <= 8192:
                raise SystemExit("Output budget must be auto or 128-8192")
        if preset == settings.get("worker_preset") and settings.get("worker_revng") is not None:
            rev_default = "on" if settings.get("worker_revng") else "off"
        else:
            rev_default = "on" if use_revng else "off"
        revng = input("Rev.ng [%s] (y/n): " % rev_default).strip().lower()
        if revng in ("y", "yes"):
            use_revng = True
        elif revng in ("n", "no"):
            use_revng = False
        else:
            use_revng = rev_default == "on"
        last_thinking = settings.get("worker_thinking", "auto")
        thinking = input("Thinking [%s] (auto/enabled/disabled): " % last_thinking).strip().lower() or last_thinking
        if thinking not in ("auto", "enabled", "disabled"):
            raise SystemExit("Thinking must be auto, enabled, or disabled")
    else:
        last_budget = settings.get("worker_output_budget", 2048)
        output_budget = last_budget if isinstance(last_budget, int) else 2048
        thinking = settings.get("worker_thinking", "auto")
        if thinking not in ("auto", "enabled", "disabled"):
            thinking = "auto"
    from roc import worker
    if model is None:
        worker.clear_setting("model")
    else:
        worker.save_settings(model=model)
    worker.save_settings(worker_preset=preset, worker_workers=workers,
                         worker_revng=use_revng, worker_output_budget=output_budget,
                         worker_thinking=thinking)
    return model, rounds, max_size, use_revng, workers, output_budget, thinking


def ensure_model():
    """Ollama plus one model, installed on demand. Called from a link click, where the
    user has just installed software, so PATH can be stale: resolve the exe, not which()."""
    import subprocess
    from roc import draft, setup
    exe = setup.find_exe("ollama")
    if not exe:
        if input("AI workers need Ollama (free). Install it now? [Y/n] ").strip().lower() in ("", "y", "yes"):
            subprocess.run(["winget", "install", "--id", "Ollama.Ollama", "-e", "--silent",
                            "--accept-package-agreements", "--accept-source-agreements"])
        setup.refresh_path()
        exe = setup.find_exe("ollama")
        if not exe:
            raise SystemExit("Ollama was not found. Restart Windows, then click the link again.")
    if not draft.ollama_models():
        print("Starting the Ollama server...")
        subprocess.Popen([exe, "serve"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                         creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
        if not setup.wait_for_http(setup.OLLAMA_API, timeout=90):
            raise SystemExit("Ollama is installed but its server did not start.\n"
                             "Start it from the Start menu, then click the link again.")
    if not draft.pick_model():
        print("Downloading the AI model qwen2.5-coder:7b (about 4.7 GB, one time)...")
        subprocess.run([exe, "pull", "qwen2.5-coder:7b"], check=True)
