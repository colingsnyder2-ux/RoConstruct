"""One-click links: roconstruct://work?client=2008-06&server=host:8765

`roc link install` registers the roconstruct:// scheme for the current
Windows user (HKCU, no admin). Clicking a link opens a console that sets up
whatever is missing, asks for a username once, and runs a worker until closed.
"""
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
# The whole vocabulary of a work link. A link may carry nothing else.
HANDOFF_FIELDS = ("user", "client", "server", "token", "mode", "model", "cloud")


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


def parse_full(url):
    """Validate a link and return every query value it carried.

    Only the fields in HANDOFF_FIELDS are returned; a crafted link cannot smuggle
    in flags or extra hosts, and nothing is written or launched here.
    """
    u = urlparse(url)
    if u.scheme != SCHEME or (u.netloc or u.path.strip("/")) != "work":
        raise SystemExit("Not a RoConstruct work link: %s" % url)
    q = {k: v[0] for k, v in parse_qs(u.query).items()}
    client, server = q.get("client", ""), q.get("server", "")
    if not CLIENT_RE.match(client) or not SERVER_RE.match(server):
        raise SystemExit("Link has a bad client or server value.")
    return {key: q.get(key) for key in HANDOFF_FIELDS if key in q}


def parse(url):
    """Client, server and token from a work link."""
    q = parse_full(url)
    return q.get("client", ""), q.get("server", ""), q.get("token")


def keep_awake():
    """Stop Windows sleeping while the worker runs (screen may still turn off)."""
    from roc import worker
    return worker.keep_awake()


def run(url):
    """Everything a link click does, in order.

    The website sends a username, client, server and cloud consent. Those are
    validated here and written to a signed local config (roc.handoff), so the
    worker that starts runs exactly what was agreed. Cloud is the default path:
    no Ollama, no Docker, no GPU.
    """
    from roc import analyze, clients, handoff, providers, setup, worker
    parts = parse_full(url)
    client, server, token = parts["client"], parts["server"].rstrip("/"), parts.get("token")
    mode = parts.get("mode") if parts.get("mode") in handoff.MODES else "cloud"
    cloud_allowed = parts.get("cloud") == "1"
    s = worker.load_settings()
    known = s.get("known_servers", [])
    user = parts.get("user") or s.get("user")
    print("RoConstruct: help decompile Roblox %s" % client)
    if server not in known:
        print("First time you're joining %s. Only continue if you trust this link." % server)
    while not worker.USER_RE.match(user or ""):
        user = input("Pick a username for the leaderboard (letters/digits, 2-32): ").strip()
    worker.save_settings(known_servers=known + [server] if server not in known else known)

    if client not in clients.load():
        raise SystemExit("This copy of RoConstruct doesn't know %s. Download the latest version." % client)
    build = clients.load()[client]["compiler_build"]
    if build not in setup.compilers():
        print("Downloading the compiler for %s (one time, this is the only big download)..." % client)
        setup.FETCHERS[build]()
        setup.compilers.cache_clear()
    wait_for_exe(client)
    if not (ROOT / "work" / client / "functions.jsonl").exists():
        print("Analyzing %s (one time, about 10 seconds)..." % client)
        analyze.analyze(client, clients.exe_path(client, clients.load()[client]))

    model, rounds, max_size, use_revng, workers, budget, thinking = choose_worker(s, mode)
    lease_mode = worker.load_settings().get("worker_lease_mode", "function")
    family_id = worker.load_settings().get("worker_family_id")
    family_example = worker.load_settings().get("worker_family_example")
    cloud = providers.is_cloud(model)
    payload = handoff.save(user=user, client=client, server=server, token=token,
                           mode="cloud" if cloud else "local", cloud=cloud, model=model)
    print("Saved a signed setup: %s" % handoff.config_path())
    worker.keep_awake()
    return worker.main_args(payload, knobs(rounds, max_size, use_revng, workers,
                                           worker.load_settings().get("worker_order", "auto"),
                                           worker.load_settings().get("worker_verbosity", "auto"), lease_mode,
                                           family_id, family_example))


def choose_worker(settings, mode):
    """The model path, then the worker knobs - what a link click asks in the console.

    One question picks cloud or local. Then choose_options asks the model, the
    worker mode, how many workers to run, and whether to open the advanced
    options. Enter at each step keeps the last answer. Ollama is only ever
    offered on the local branch, and Docker/Rev.ng not at all from here.
    """
    from roc import providers, worker as worker_module
    if mode == "local":
        return choose_local(settings, settings.get("model"))
    # Cloud-first, but the helper still gets to say no: a silent default was the
    # thing nobody asked for, so ask - and remember the answer.
    cloud_allowed = bool(settings.get("cloud_allowed"))
    if not cloud_allowed:
        print("\nCloud models send bounded assembly and source clues off this PC.")
        print("Your PC stays idle: no GPU, no Ollama, no Docker.")
        if input("Use a cloud model? [y/N] ").strip().lower() not in ("y", "yes"):
            print("Using a local model instead.")
            return choose_local(settings, settings.get("model"))
        cloud_allowed = True
        worker_module.save_settings(cloud_allowed=True)
    default_cloud = worker_module.cloud_default() or settings.get("model")
    # force the questions every click: model, worker mode, worker count, advanced
    fresh = dict(settings, model=default_cloud, worker_launcher_configured=False,
                 cloud_allowed=cloud_allowed)
    return choose_options(fresh)


def knobs(rounds, max_size, use_revng, workers, order="auto", verbosity="auto", lease_mode="function",
          family_id=None, family_example=None):
    """The chosen options as CLI flags for worker.main_args."""
    argv = ["--workers", str(workers), "--order", order, "--verbosity", verbosity,
            "--lease-mode", lease_mode]
    if isinstance(rounds, int):
        argv += ["--rounds", str(rounds)]
    if isinstance(max_size, int):
        argv += ["--max-size", str(max_size)]
    if not use_revng:
        argv.append("--no-revng")
    if family_id:
        argv += ["--family-id", family_id]
    if family_example:
        argv += ["--family-example", family_example]
    return argv


def choose_local(settings, wanted):
    """Local mode: only reached when the helper explicitly asked for a local model."""
    from roc import draft
    if not draft.pick_model(wanted):
        ensure_model()
    return choose_options(dict(settings, model=wanted, worker_launcher_configured=False))


def cloud_model(settings, cloud_allowed):
    """Cloud-first model choice: no Ollama prompt unless the helper opted out."""
    from roc import draft, providers, worker
    saved = settings.get("model")
    if saved and providers.is_cloud(saved) and providers.available(saved):
        if not cloud_allowed:
            raise SystemExit("Saved model %s is a cloud model. Run: roc setup" % saved)
        return saved
    if worker.cloud_default():
        if not cloud_allowed:
            raise SystemExit("This worker uses cloud models by default. Run: roc setup to agree, "
                             "or choose 'Use local model'.")
        return worker.cloud_default()
    if draft.pick_model(saved):
        return draft.pick_model(saved)
    if input("No cloud model key is set. Save one now? [Y/n] ").strip().lower().startswith("n"):
        raise SystemExit("No model available. Save a cloud key (roc provider setup) or run: roc local-ai")
    raise SystemExit("Save your cloud key, then click the link again:\n"
                     "  roc provider setup")


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


def _saved_worker_options(settings, installed):
    from roc import draft, optimizer, providers, worker
    model = settings.get("model")
    if model and providers.is_cloud(model):
        if not providers.available(model):
            return None
    else:
        model = draft.pick_model(model)
        if not model:
            return None
    if not providers.is_cloud(model) and model not in installed:
        return None
    profile = optimizer.profile(model, settings) or {}
    manual_preset = settings.get("worker_preset_model") == model
    preset = (settings.get("worker_preset") if manual_preset else
              profile.get("name", settings.get("worker_preset", "balanced")))
    preset = preset if preset in ("fast", "balanced", "deep", "auto") else "balanced"
    rounds, max_size, use_revng = 4, 256, True
    if preset == "fast":
        rounds, max_size, use_revng = 2, 96, False
    elif preset == "deep":
        rounds, max_size = 6, 512
    elif preset == "auto":
        rounds, max_size, use_revng = "auto", 512, False
    rounds = (settings.get("worker_rounds") if settings.get("worker_rounds_model") == model else
              profile.get("rounds", settings.get("worker_rounds", rounds)))
    output_budget = (settings.get("worker_output_budget") if settings.get("worker_output_budget_model") == model else
                     profile.get("max_tokens", settings.get("worker_output_budget", 2048)))
    if not isinstance(output_budget, int):
        output_budget = 2048
    workers = (settings.get("worker_workers") if settings.get("worker_workers_model") == model else
               profile.get("workers", settings.get("worker_workers", "1")))
    if workers != "auto":
        try:
            workers = max(1, min(int(workers), worker.MAX_WORKERS))
        except (TypeError, ValueError):
            return None
    use_revng = settings.get("worker_revng", use_revng)
    thinking = settings.get("worker_thinking", "auto")
    strategy = (settings.get("worker_strategy") if settings.get("worker_strategy_model") == model else
                profile.get("strategy", settings.get("worker_strategy", "direct")))
    worker.save_settings(worker_strategy=strategy)
    return model, rounds, max_size, use_revng, workers, output_budget, thinking


def choose_options(settings):
    """Let each link launch choose runtime options while keeping safe defaults.

    Defaults come from the last run (saved in settings), so Enter repeats
    the previous launch; any prompt still accepts a new value.
    """
    from roc import draft, providers, worker
    installed = draft.ollama_models()
    from roc import optimizer
    saved = _saved_worker_options(settings, installed) if settings.get("worker_launcher_configured") else None
    if saved:
        model = saved[0]
        profile = optimizer.profile(model, settings)
        mode = "optimized %s" % profile["name"] if profile else settings.get("worker_preset", "balanced")
        print("Saved setup: %s | %s. Enter=start, 2=setup, 3=workers, 4=optimize." %
              (model, mode))
        action = input("[1]: ").strip().lower()
        if action in ("", "1"):
            return saved
        if action == "3":
            picked_workers = input("Workers [%s] (1-%d or auto): " %
                                   (saved[4], worker.MAX_WORKERS)).strip() or saved[4]
            if picked_workers != "auto":
                try:
                    picked_workers = max(1, min(int(picked_workers), worker.MAX_WORKERS))
                except ValueError:
                    raise SystemExit("Workers must be 1-%d or auto" % worker.MAX_WORKERS)
            worker.save_settings(worker_workers=picked_workers, worker_workers_model=model)
            return saved[:4] + (picked_workers,) + saved[5:]
        if action == "4":
            cost_cap = None
            if providers.is_cloud(model):
                raw_cap = input("Optimizer cloud spend cap in USD [0.25]: ").strip() or "0.25"
                try:
                    cost_cap = float(raw_cap)
                except ValueError:
                    raise SystemExit("Spend cap must be a positive dollar amount")
                if cost_cap <= 0:
                    raise SystemExit("Spend cap must be a positive dollar amount")
            profile = optimizer.run(model, allow_cloud=bool(settings.get("cloud_allowed")),
                                    max_cloud_cost=cost_cap, force=bool(optimizer.profile(model, settings)))
            settings = dict(settings)
            settings.setdefault("optimizer_profiles", {})[model] = profile
            for key in ("worker_preset_model", "worker_rounds_model", "worker_workers_model",
                        "worker_output_budget_model", "worker_strategy_model"):
                settings[key] = ""
            return _saved_worker_options(settings, installed)
        if action not in ("2", "options", "change"):
            raise SystemExit("Choose 1 to start, 2 to change setup, 3 to change workers, or 4 to optimize.")
    cloud = ["deepseek:deepseek-flash", "nvidia:qwen/qwen2.5-coder-32b-instruct", "openai:gpt-5"]
    previous = [name for name in settings.get("worker_model_choices", []) if isinstance(name, str)]
    choices = list(dict.fromkeys(installed + cloud + previous +
                                 ([settings["model"]] if settings.get("model") and settings["model"] not in installed + cloud else [])))
    default_model = draft.pick_model(settings.get("model")) or settings.get("model") or "none"
    print("\nChoose model (number or model name; Enter keeps saved choice):")
    for index, name in enumerate(choices, 1):
        print("  %d) %s%s" % (index, name, " [optimizer profile]" if optimizer.profile(name, settings) else ""))
    print("  %d) Add / configure cloud model" % (len(choices) + 1))
    print("  %d) Install another local model" % (len(choices) + 2))
    picked = input("Model [%s]: " % default_model).strip()
    if picked.isdigit() and int(picked) == len(choices) + 1:
        model = input("Cloud model (provider:MODEL): ").strip()
    elif picked.isdigit() and int(picked) == len(choices) + 2:
        name = input("Ollama model tag to install: ").strip()
        if not name:
            raise SystemExit("Model tag required")
        from roc import setup
        import subprocess
        exe = setup.find_exe("ollama")
        if not exe:
            raise SystemExit("Install Ollama first, then run: ollama pull %s" % name)
        subprocess.run([exe, "pull", name], check=True)
        installed = draft.ollama_models()
        model = next((tag for tag in installed if tag == name), None)
        if not model:
            raise SystemExit("Model pull finished, but Ollama did not list %s." % name)
    else:
        model = choices[int(picked) - 1] if picked.isdigit() and 1 <= int(picked) <= len(choices) else (picked or default_model)
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
    profile = optimizer.profile(model, settings) or {}
    last_preset = settings.get("worker_preset", "balanced")
    recommended = (last_preset if settings.get("worker_preset_model") == model else
                   profile.get("name", last_preset))
    if recommended not in ("fast", "balanced", "deep"):
        recommended = "balanced"
    print("Worker mode: 1) Recommended  2) Fast  3) Deep  4) Advanced  5) Optimize model")
    picked_mode = input("Mode [%s]: " % ("1" if profile else last_preset)).strip().lower()
    if picked_mode == "5":
        cost_cap = None
        if providers.is_cloud(model):
            raw_cap = input("Optimizer cloud spend cap in USD [0.25]: ").strip() or "0.25"
            try:
                cost_cap = float(raw_cap)
            except ValueError:
                raise SystemExit("Spend cap must be a positive dollar amount")
            if cost_cap <= 0:
                raise SystemExit("Spend cap must be a positive dollar amount")
        print("Calibrating %s before worker starts; no mining jobs will be submitted." % model)
        profile = optimizer.run(model, allow_cloud=bool(settings.get("cloud_allowed")),
                                max_cloud_cost=cost_cap, force=bool(profile))
        picked_mode = "1"
    preset = ({"1": recommended, "2": "fast", "3": "deep", "4": "balanced"}.get(
        picked_mode, picked_mode or recommended))
    show_advanced = picked_mode == "4"
    if preset not in ("auto", "fast", "balanced", "deep"):
        raise SystemExit("Preset must be auto, fast, balanced, or deep")
    rounds, max_size, use_revng = 4, 256, True
    if preset == "fast":
        rounds, max_size, use_revng = 2, 96, False
    elif preset == "deep":
        rounds, max_size = 6, 512
    elif preset == "auto":
        rounds, max_size, use_revng = "auto", 512, False
    if profile and picked_mode in ("", "1", "4"):
        rounds = profile.get("rounds", rounds)
        output_budget = profile.get("max_tokens", settings.get("worker_output_budget", 2048))
    strategy = (settings.get("worker_strategy") if settings.get("worker_strategy_model") == model else
                profile.get("strategy", settings.get("worker_strategy", "direct")))
    order = settings.get("worker_order", "auto")
    lease_mode = settings.get("worker_lease_mode", "function")
    family_id = settings.get("worker_family_id")
    family_example = settings.get("worker_family_example")
    last_workers = (profile.get("workers", settings.get("worker_workers", "1"))
                    if profile and settings.get("worker_workers_model") != model
                    else settings.get("worker_workers", "1"))
    workers = input("Workers [%s] (1-%d or auto): " % (last_workers, worker.MAX_WORKERS)).strip() or last_workers
    if workers != "auto":
        try:
            workers = max(1, min(int(workers), worker.MAX_WORKERS))
        except ValueError:
            raise SystemExit("Workers must be 1-%d or auto" % worker.MAX_WORKERS)
    if (show_advanced or input("Advanced options? [Enter=skip, y=show]: ").strip().lower()
            in ("y", "yes", "advanced")):
        default_rounds = (settings.get("worker_rounds") if settings.get("worker_rounds_model") == model
                          else rounds)
        picked = input("Rounds [%s]: " % default_rounds).strip().lower() or str(default_rounds)
        if picked != "auto":
            try:
                rounds = max(1, min(int(picked), 12))
            except ValueError:
                raise SystemExit("Rounds must be auto or 1-12")
        default_max_size = settings.get("worker_max_size", 96)
        picked = input("Max function size [%s bytes]: " % default_max_size).strip() or str(default_max_size)
        try:
            max_size = int(picked)
        except ValueError:
            raise SystemExit("Max function size must be a positive byte count")
        if max_size < 6:
            raise SystemExit("Max function size must be at least 6 bytes")
        last_budget = (settings.get("worker_output_budget") if settings.get("worker_output_budget_model") == model
                       else profile.get("max_tokens", settings.get("worker_output_budget", 2048)))
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
        strategy = input("Generation strategy [%s] (auto/direct/structured/reference): " % strategy).strip().lower() or strategy
        if strategy not in ("auto", "direct", "structured", "reference"):
            raise SystemExit("Strategy must be auto, direct, structured, or reference")
        work_order = input("Work order [%s] (auto/best/matched/unmatched/easiest/random/family): " %
                           ("family" if lease_mode == "family" else order)).strip().lower()
        work_order = work_order or ("family" if lease_mode == "family" else order)
        if work_order == "family":
            lease_mode, order = "family", "auto"
            target = input("Family target [random] (random, fingerprint, or CLIENT:ADDRESS): ").strip()
            family_id = None
            family_example = None
            if target and ":" in target:
                family_example = target
            elif target and target.lower() != "random":
                family_id = target.lower()
        else:
            lease_mode, order = "function", work_order
        if order not in ("auto", "best", "matched", "unmatched", "easiest", "random"):
            raise SystemExit("Work order must be auto, best, matched, unmatched, easiest, random, or family")
        verbosity = input("Console verbosity [auto] (auto/verbose/compact): ").strip().lower() or "auto"
        if verbosity not in ("auto", "verbose", "compact"):
            raise SystemExit("Console verbosity must be auto, verbose, or compact")
    else:
        last_budget = (settings.get("worker_output_budget") if settings.get("worker_output_budget_model") == model
                       else profile.get("max_tokens", settings.get("worker_output_budget", 2048)))
        output_budget = (profile.get("max_tokens", last_budget) if profile and picked_mode in ("", "1")
                         else last_budget)
        output_budget = output_budget if isinstance(output_budget, int) else 2048
        thinking = settings.get("worker_thinking", "auto")
        if thinking not in ("auto", "enabled", "disabled"):
            thinking = "auto"
        verbosity = settings.get("worker_verbosity", "auto")
    from roc import worker
    if model is None:
        worker.clear_setting("model")
    else:
        worker.save_settings(model=model)
    worker.save_settings(worker_preset=preset, worker_workers=workers,
                         worker_revng=use_revng, worker_output_budget=output_budget,
                         worker_thinking=thinking, worker_strategy=strategy,
                         worker_order=order, worker_verbosity=verbosity, worker_max_size=max_size,
                         worker_lease_mode=lease_mode,
                         worker_family_id=family_id, worker_family_example=family_example,
                         worker_rounds=rounds, worker_launcher_configured=True,
                         worker_preset_model=model, worker_rounds_model=model,
                         worker_workers_model=model, worker_output_budget_model=model,
                         worker_strategy_model=model,
                         worker_model_choices=list(dict.fromkeys(previous + ([model] if model else []))))
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
