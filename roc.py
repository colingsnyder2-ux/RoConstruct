"""RoConstruct: group matching-decompilation of old Roblox clients.

Run with no arguments (or double-click roc.cmd) for a menu.
"""
import argparse
import json
import os
import subprocess
import sys
from pathlib import Path

if sys.version_info < (3, 8):
    sys.exit("RoConstruct needs Python 3.8 or newer. Run install.cmd.")
try:
    from roc import clients
except ImportError as error:
    sys.exit("Missing Python package (%s). Run install.cmd first." % error.name)

ROOT = Path(__file__).resolve().parent


def settings():
    from roc.worker import load_settings
    return load_settings()


def need(value, what, hint):
    if not value:
        sys.exit("No %s set. %s" % (what, hint))
    return value


def need_module(name, what):
    """Import a module that only ships in one package, with a clear reason.

    The three packages share the roc/ package, but the server-only modules are
    left out of the Worker and Local AI zips. Saying so is better than a
    traceback when someone types a maintainer command.
    """
    import importlib
    try:
        return importlib.import_module("roc." + name)
    except ImportError:
        sys.exit("%s ships in RoConstruct Server (maintainer-only). "
                 "Ask a maintainer if you need it." % what)


# ---------- commands ----------

def ask_setup_question(question):
    """A prompt that survives a piped/scheduled run: an empty answer means no."""
    try:
        return input(question)
    except EOFError:
        return "n"


def cmd_install(a):
    """Cloud-first bootstrap: packages, exact compiler bundles, link, website."""
    from roc import setup

    def ask(question):
        try:
            return input(question)
        except EOFError:  # no console (piped / scheduled): take the default
            return ""
    if os.name == "nt":
        from roc import link
        link.install()
    ok = setup.install(ask=(lambda q: "y") if a.yes else ask, assume_yes=a.yes, client=a.client)
    if a.open_site and os.name == "nt":
        import webbrowser
        from roc import worker
        webbrowser.open(worker.SITE + "index.html")
    if not ok:
        raise SystemExit(1)


def cmd_local_ai(a):
    """Opt-in extras: Ollama now, Docker / Rev.ng only if asked."""
    from roc import setup

    if not setup.local_ai(ask=ask_setup_question, docker=a.docker, model=a.model or None):
        raise SystemExit(1)


def cmd_setup(a, run=None):
    """Ask the setup questions here in the terminal and save a signed worker config.

    run=None keeps whatever --launch / --no-launch said; run=True always starts the
    worker in this terminal when the answers are in.
    """
    from roc import handoff, worker
    url = getattr(a, "url", None)
    if url:
        payload = handoff.from_url(url)
        print("Accepted a website link: user=%s client=%s server=%s mode=%s cloud=%s" %
              (payload["user"], payload["client"], payload["server"], payload["mode"],
               "yes" if payload["cloud"] else "no"))
        handoff.apply(url)
        return finish_setup(handoff, a, run=run)
    s = worker.load_settings()
    default_user = s.get("user") or ""
    default_client = getattr(a, "client", None) or s.get("handoff_client") or ""
    user = getattr(a, "user", None) or default_user
    if not user:
        while True:
            user = input("Username for the leaderboard (letters/digits/._-, 2-32): ").strip()
            if worker.USER_RE.match(user):
                break
            print("  Use 2-32 letters, digits, dot, underscore or dash.")
    client = default_client or ask_client()
    if not client:
        raise SystemExit("Choose a client first: roc client list")
    cloud = getattr(a, "cloud", None)
    if cloud is None:
        answer = input("Use a cloud model? (no Ollama, no GPU needed) [y/N] ").strip().lower()
        cloud = answer.startswith("y")
    mode = "cloud" if cloud else "local"
    if not cloud:
        from roc import setup as setup_module
        print("\nLocal mode. Nothing is installed for it yet, so Ollama is offered now -")
        print("you can also skip it and just do the mining by hand (roc claim / roc check / roc submit).")
        setup_module.local_ai(ask=ask_setup_question, docker=bool(getattr(a, "docker", False)),
                              model=getattr(a, "model", None) or "qwen2.5-coder:7b")
    server = getattr(a, "server", None) or s.get("server") or worker.site_server()
    if not server:
        raise SystemExit("No server address known. Pass --server HOST:PORT (the site lists the current one).")
    payload = handoff.save(user=user, client=client, server=server,
                           token=(getattr(a, "token", None) or s.get("token")),
                           mode=mode, cloud=cloud, model=getattr(a, "model", None))
    print("Saved a signed setup: %s" % handoff.config_path())
    return finish_setup(handoff, a, run=run)


def ask_client():
    from roc import clients
    registry = sorted(clients.load())
    if not registry:
        return None
    print("\nWhich client do you want to help with?")
    for index, name in enumerate(registry, 1):
        entry = clients.load()[name]
        print("  %d) %s  (%s, compiler %s)" % (index, name, entry.get("compiler"), entry.get("compiler_build")))
    picked = input("Client [1]: ").strip() or "1"
    if picked.isdigit() and 1 <= int(picked) <= len(registry):
        return registry[int(picked) - 1]
    if picked in clients.load():
        return picked
    raise SystemExit("Unknown client: %s" % picked)


def finish_setup(handoff, a, run=None):
    from roc import doctor
    payload = handoff.load()
    if not payload:
        raise SystemExit("The setup could not be saved (signature check failed). Run: roc setup")
    print()
    doctor_report(doctor.all_checks(network=not getattr(a, "no_check", False)))
    if run is None:
        run = bool(getattr(a, "launch", False))
    if run:
        # run in this terminal: the knobs stay visible and closeable here
        return handoff.run_now(_forwarded(a))
    print("Start the worker with: roc launch")


def doctor_report(checks):
    from roc import doctor
    print(doctor.format_report(checks))
    return doctor.failed(checks)


def cmd_launch(a):
    """Configure and run the worker in this terminal.

    No saved setup, or you want to change something? It just asks here: username,
    client, cloud consent, then the knobs (model, workers, rounds, size). Nothing
    is installed that you did not ask for, and nothing starts until you answer.
    """
def _forwarded(a):
    """Flags on `a` that the worker entry point understands, as a CLI list."""
    forwarded = []
    for name in ("client", "model", "workers", "rounds", "max_size", "jobs", "lease_mode",
                 "family_id", "family_example"):
        value = getattr(a, name, None)
        if value is not None:
            forwarded += ["--%s" % name.replace("_", "-"), str(value)]
    for flag, name in (("no-revng", "no_revng"), ("dry-run", "dry_run")):
        if getattr(a, name, False):
            forwarded.append("--%s" % flag)
    return forwarded


def cmd_launch(a):
    """Configure and run the worker in this terminal.

    With a saved setup it runs straight away and the flags on this command
    override it. Without one - or with --setup - the questions are asked right
    here: username, client, cloud model, then the worker knobs. Nothing is
    installed that you did not ask for, and nothing starts until you answer.
    """
    from roc import handoff
    if not handoff.load():
        print("No saved setup yet. Answering here - nothing installs until you pick a model.\n")
    if getattr(a, "setup", False) or not handoff.load():
        return cmd_setup(a, run=True)
    return handoff.run_now(_forwarded(a))


def cmd_doctor(a):
    from roc import doctor
    checks = doctor.all_checks(network=not a.no_check)
    if a.json:
        print(json.dumps(checks, indent=1))
    else:
        print(doctor.format_report(checks))
    if doctor.failed(checks):
        raise SystemExit(1)


def cmd_link(a):
    if a.target not in ("install", "remove"):
        from roc import selfupdate
        print("Checking for updates: %s" % selfupdate.try_update())
    from roc import link
    if a.target == "install":
        return link.install()
    if a.target == "remove":
        return link.remove()
    try:
        link.run(a.target)
    except (SystemExit, Exception) as error:  # link windows close on exit: keep the message visible
        code = getattr(error, "code", error)
        if code not in (None, 0):
            print()
            print(code)
            input("Press Enter to close.")


def cmd_client_add(a):
    e = clients.add(a.name, a.exe, a.allow_modified, getattr(a, "donor", False))
    print("%s registered%s: compiler %s" % (a.name, " (donor)" if e.get("donor") else "", e["compiler"]))
    cmd_analyze(a)
    print("Commit clients/clients.json so others can join this client.")


def cmd_client_list(a):
    reg = clients.load()
    if not reg:
        print("No clients registered. Add one:  roc client add <name> <path to RobloxApp.exe>")
    for name, e in sorted(reg.items()):
        print("%-6s %-14s %s" % (name, clients.status(name, e), e["compiler"]))


def cmd_client_fetch(a):
    """Download a client's files from Drive into clients/<name>/ and verify them."""
    from roc import sources
    reg = clients.load()
    names = sorted(reg) if a.name == "all" else [a.name]
    bad = 0
    for name in names:
        if name not in reg:
            sys.exit("%s is not registered. See:  roc client list" % name)
        try:
            sources.fetch(name)
        except sources.FetchError as error:
            print("%-8s %s" % (name, error))
            bad += 1
    if bad:
        sys.exit("%d client(s) could not be fetched." % bad)


def cmd_client_sources(a):
    """Point clients/sources.json at a bundle zip, or re-index a public Drive folder."""
    from roc import sources
    if a.bundle:
        sources.set_bundle(a.bundle)
        return
    folder = a.folder.split("/folders/")[-1].split("?")[0].strip("/")
    extra = [s.strip() for s in (a.also or "").split(",") if s.strip()]
    if extra:
        print("also indexing: %s (not in clients.json yet)" % ", ".join(extra))
    sources.index_drive(folder, dry_run=a.dry_run, extra_slots=extra)


def cmd_client_remove(a):
    """Unregister a client. --purge deletes the local copies too, which makes the
    next command that needs it download it again."""
    gone = clients.remove(a.name, a.purge)
    if not gone and a.purge:
        sys.exit(1)  # remove() already explained which folder is locked
    print("%s removed from clients/clients.json" % a.name)
    for folder in gone:
        print("deleted %s" % folder)
    if a.purge:
        print("It will be fetched again on demand:  roc client-fetch %s" % a.name)
    else:
        print("Local files kept in clients/%s/. Commit clients/clients.json." % a.name)


def cmd_client_verify(a):
    """Hash + PE checksum: same build as the group, and not modified."""
    bad = 0
    for name, e in sorted(clients.load().items()):
        st = clients.status(name, e)
        if st != "ok":
            print("%-8s %s" % (name, st))
            bad += st == "hash mismatch"
            continue
        ok = clients.checksum_ok(clients.exe_path(name, e))
        print("%-8s ok, hash matches registry, %s" % (name, {True: "unmodified (PE checksum valid)",
              False: "MODIFIED (PE checksum mismatch)", None: "no PE checksum to check"}[ok]))
        bad += ok is False
    if bad:
        sys.exit("%d client(s) differ from the registered builds." % bad)


def ready(name):
    """Make sure the client is on disk before working on it: fetch it if we can."""
    from roc import sources
    entry = clients.load().get(name)
    if not entry or clients.status(name, entry) == "ok":
        return True
    if sources.ensure(name):
        return True
    print("%s: exe %s (fetch it with: roc client-fetch %s)" % (name, clients.status(name, entry), name))
    return False


def cmd_analyze(a):
    from roc import analyze
    names = sorted(clients.load()) if a.name == "all" else [a.name]
    for name in names:
        entry = clients.load().get(name)
        if not entry:
            sys.exit("%s is not registered. See:  roc client list" % name)
        if not ready(name) or clients.status(name, entry) != "ok":
            print("%s: skipped, exe %s" % (name, clients.status(name, entry)))
            continue
        out, funcs = analyze.analyze(name, clients.exe_path(name, entry))
        real = sum(1 for f in funcs if f["kind"] == "code")
        print("%s: %d functions (%d real code, %d skipped: compiler stubs or bad splits)" % (name, len(funcs), real, len(funcs) - real))


def cmd_next(a):
    import json
    from roc import match
    if not ready(a.name):
        sys.exit("%s: no verified exe, cannot list functions." % a.name)
    scores_file = ROOT / "work" / a.name / "scores.json"
    scores = json.loads(scores_file.read_text()) if scores_file.exists() else {}
    rows = [r for r in match._functions(a.name).values() if r["kind"] == "code" and scores.get(r["addr"], 0) < 100]
    rows.sort(key=lambda r: (r["calls"], r["size"]))
    print("Easiest open functions in %s (claim one with: roc claim %s <addr>):" % (a.name, a.name))
    for r in rows[:a.n]:
        print("  %s  %4d bytes  %-3s  %s" % (r["addr"], r["size"], "%d%%" % scores.get(r["addr"], 0), r["unit"]))


def cmd_claim(a):
    from roc import match
    if not ready(a.name):
        sys.exit("%s: no verified exe, nothing to claim." % a.name)
    path = match.claim(a.name, a.addr)
    print("Edit this file:", path)
    print("Then run:       roc check %s %s" % (a.name, path.stem))
    if a.open and os.name == "nt":
        subprocess.Popen(["notepad.exe", str(path)])


def cmd_check(a):
    from roc import match
    folder = ROOT / "src" / a.name
    if a.addr:
        srcs = [folder / ("%s.cpp" % a.addr.lower().replace("0x", "").zfill(8))]
        if not srcs[0].exists():
            sys.exit("No file %s. Start with:  roc claim %s %s" % (srcs[0], a.name, a.addr))
    else:
        srcs = sorted(folder.glob("*.cpp"))
        if not srcs:
            sys.exit("No files in %s yet. Start with:  roc next %s" % (folder, a.name))
    matched = 0
    for src in srcs:
        try:
            value, name, asm_diff, spans = match.check(a.name, src.stem, src)
        except match.CompileError as error:
            print("%s  does not compile:\n%s" % (src.stem, error))
            continue
        best = match.save_score(a.name, src.stem, value)
        match.save_data(a.name, src.stem, spans)
        match.save_data(a.name, src.stem, spans)
        matched += value == 100
        print("%s  %3d%%  %s%s" % (src.stem, value, name or "-", "  MATCH" if value == 100 else "  (best %d%%)" % best))
        if value < 100 and len(srcs) == 1:
            print("Assembly diff ('-' = target, '+' = yours):")
            print(asm_diff)
    if len(srcs) > 1:
        print("%d / %d match." % (matched, len(srcs)))


def cmd_auto(a):
    from roc import auto, setup
    names = sorted(clients.load()) if a.name == "all" else [a.name]
    have = setup.compilers()
    for name in names:
        entry = clients.load()[name]
        if entry.get("compiler_build") not in have or clients.status(name, entry) != "ok":
            print("%s: skipped (needs the exe and its compiler)" % name)
            continue
        found = auto.solve(name, a.max_size)
        print("%s: %d new files in src/%s/" % (name, auto.save(name, found), name))


def cmd_xcopy(a):
    """Copy every stored match to the other clients that contain the same function.

    Cheap and worth re-running often: each new match is a candidate for every other
    client, so this multiplies whatever else is finding."""
    from roc import xcopy
    names = None if a.name == "all" else [n.strip() for n in a.name.split(",") if n.strip()]
    reg = clients.load()
    for name in names or []:
        if name not in reg:
            sys.exit("%s is not registered. See:  roc client list" % name)
    result = xcopy.run(targets=names, limit=a.limit, dry_run=a.dry_run)
    print("\nClient       new files   newly matched")
    files = scored = 0
    for name in sorted(result):
        new_files, new_matches = result[name]
        print("  %-8s %8d %14d" % (name, new_files, new_matches))
        files += new_files
        scored += new_matches
    print("  %-8s %8d %14d" % ("total", files, scored))


def cmd_ref(a):
    """Resolve a client function to the 2016 Roblox source that probably produced it."""
    from roc import refsource
    if a.summarise:
        refsource.summarise(a.client)
        return
    if not a.unit:
        sys.exit("Give a unit name, or use --summarise. See:  roc ref --help")
    refsource.report(a.unit, a.limit)


def cmd_libs(a):
    """Match open-source library code (zlib, libjpeg, libpng, Lua, G3D, boost, templates)."""
    from roc import libs
    names = list(libs.RECIPES) if a.names == ["all"] else a.names
    unknown = [n for n in names if n not in libs.RECIPES]
    if unknown:
        sys.exit("Unknown library: %s. Known: %s" % (", ".join(unknown), ", ".join(libs.RECIPES)))
    targets = libs.default_targets() if a.client == "all" else [a.client]
    print(libs.run([n for n in names if libs.RECIPES[n].get("files")], targets))


def cmd_mass(a):
    """Everything automatic: compiler runtime tagging, STL, all libraries, then auto shapes."""
    from roc import libs, mass
    targets = libs.default_targets() if a.client == "all" else [a.client]
    mass.staticlibs(targets)
    mass.stl(targets)
    libs.run([n for n, r in libs.RECIPES.items() if r.get("files")], targets)
    for name in targets:
        main(["analyze", name])  # picks up the runtime tags
        main(["auto", name])


def cmd_flags(a):
    from roc import flags
    if a.sweep:
        flags.sweep(a.name, limit=a.limit)
    else:
        flags.tune(a.name)


def cmd_config(a):
    from roc import draft, providers
    from roc.worker import clear_setting, save_settings, USER_RE
    if a.user and not USER_RE.match(a.user):
        sys.exit("Username must be 2-32 letters, digits, _ . -")
    if a.model and a.model != "default" and not draft.pick_model(a.model):
        if providers.is_cloud(a.model):
            _provider, _remote, config = providers.parse_model(a.model)
            sys.exit("Cloud key is missing: set %s" % config["key_env"])
        choices = draft.ollama_models()
        sys.exit("Model '%s' is not installed. Installed: %s" %
                 (a.model, ", ".join(choices) or "none (run: ollama pull <model>)"))
    if a.model == "default":
        clear_setting("model")
        a.model = None
    s = save_settings(user=a.user, server=a.server, token=a.token, model=a.model,
                      public_server=a.public_server, cloud_allowed=a.allow_cloud)
    print("Saved: " + ", ".join("%s=%s" % (k, "***" if k == "token" else v) for k, v in s.items()))


def cmd_submit(a):
    from roc import worker
    s = settings()
    worker.submit_files(need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL"),
                        need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME"),
                        a.name, a.addr or None, a.token or s.get("token"))


def cmd_pull(a):
    from roc import worker
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    names = sorted(clients.load()) if a.name == "all" else [a.name]
    for name in names:
        worker.pull_files(srv, name, a.token or s.get("token"), a.force)


def cmd_server(a):
    server = need_module("server", "The group server")
    if a.startup:
        startup = Path(os.environ["APPDATA"]) / r"Microsoft\Windows\Start Menu\Programs\Startup" / "RoConstruct server.cmd"
        startup.write_text('@start "RoConstruct server" /min "%s"' % (ROOT / "host.cmd"))
        return print("The server will start when you log in: %s" % startup)
    httpd = server.serve(a.host, a.port, token=a.token, lease_seconds=a.lease,
                         discord_webhook=a.discord_webhook or settings().get("discord_webhook"))
    public = a.public_server or settings().get("public_server")
    if a.tunnel and not public:  # a saved fixed address (e.g. Tailscale Funnel) wins over a quick tunnel
        public, _ = server.start_tunnel(a.port)
    if a.publish:
        if not public:
            sys.exit("--publish needs a public address: use --tunnel or --public-server HOST:PORT")
        import threading
        threading.Thread(target=server.publish_loop, args=(httpd.store, public, a.publish_every), daemon=True).start()
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("Server stopped.")


def cmd_worker(a):
    from roc import selfupdate
    if not a.no_update:
        print("Checking for updates: %s" % selfupdate.try_update())
    from roc import draft, providers, worker
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server URL or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user NAME or: roc config --user NAME")
    if a.model and a.model != "default" and not draft.pick_model(a.model):
        if providers.is_cloud(a.model):
            _provider, _remote, config = providers.parse_model(a.model)
            sys.exit("Cloud key is missing: set %s" % config["key_env"])
        sys.exit("Model '%s' is not installed. See: roc model" % a.model)
    if a.model == "default":
        worker.clear_setting("model")
        a.model = None
        s.pop("model", None)
    if a.preset == "fast":
        a.rounds, a.max_size, a.no_revng = min(a.rounds, 2), min(a.max_size, 96), True
    elif a.preset == "deep":
        a.rounds, a.max_size = max(a.rounds, 6), max(a.max_size, 512)
    chosen = a.model or s.get("model")
    cloud_allowed = bool(a.allow_cloud or s.get("cloud_allowed"))
    if chosen and providers.is_cloud(chosen) and not cloud_allowed:
        sys.exit("Cloud models send prompts outside this PC. Pass --allow-cloud to continue.")
    if a.cloud_escalate:
        if not providers.is_cloud(a.cloud_escalate):
            raise SystemExit("--cloud-escalate needs a cloud model")
        if not cloud_allowed:
            raise SystemExit("Cloud escalation needs --allow-cloud")
        if not providers.available(a.cloud_escalate):
            _provider, _remote, config = providers.parse_model(a.cloud_escalate)
            raise SystemExit("Cloud key is missing: set %s" % config["key_env"])
    budget = providers.CloudBudget(a.max_cloud_requests, a.max_cloud_tokens, a.max_cloud_cost)
    gate = providers.CloudGate(a.cloud_concurrency) if a.cloud_concurrency is not None else None
    if a.output_budget is None:
        a.output_budget = 2048
    if not 128 <= a.output_budget <= 8192:
        raise SystemExit("--output-budget must be 128-8192")
    if a.cloud_fallback:
        if providers.is_cloud(a.cloud_fallback):
            if not cloud_allowed:
                raise SystemExit("Cloud fallback needs --allow-cloud")
            if not providers.available(a.cloud_fallback):
                _provider, _remote, config = providers.parse_model(a.cloud_fallback)
                raise SystemExit("Cloud key is missing: set %s" % config["key_env"])
        elif not draft.pick_model(a.cloud_fallback):
            raise SystemExit("Cloud fallback model is not installed: %s" % a.cloud_fallback)
    order = a.order or "auto"
    if order not in ("auto", "best", "matched", "unmatched", "easiest", "random"):
        sys.exit("--order must be one of: auto, best, matched, unmatched, easiest, random")
    family_id = a.family_id or (worker.family_from_example(a.family_example)
                                if a.family_example else None)
    if a.family_example and not family_id:
        raise SystemExit("Unknown family example; use CLIENT:ADDRESS")
    if family_id and a.client:
        ready = worker.register_family_targets(srv, a.token or s.get("token"), a.client, family_id)
        if ready:
            print("Family %s ready: %d sibling targets" % (family_id, ready))
    if a.dry_run:
        info = worker.Api(srv, a.token or s.get("token")).call("/v1/info")
        have = worker.usable_clients(info)
        print("Worker preview: user=%s model=%s clients=%s rounds=%d max-size=%d Rev.ng=%s workers=%s output-budget=%d order=%s" %
              (user, draft.pick_model(chosen) or "none", ", ".join(have) or "none",
               a.rounds, a.max_size, "off" if a.no_revng else "auto", a.workers, a.output_budget, order))
        return
    worker.save_settings(user=user, server=srv, model=a.model, order=order)
    worker.run_concurrent(srv, user, a.token or s.get("token"), chosen, a.rounds, a.max_size,
                          not a.no_revng, a.jobs, a.workers, source_only=a.source_only,
                          only=[a.client] if a.client else None, strategy=a.strategy,
                          cloud_allowed=cloud_allowed, cloud_budget=budget, cloud_gate=gate,
                          diverse_candidates=a.diverse_candidates, cloud_min_size=a.cloud_min_size,
                          cloud_fallback=a.cloud_fallback, seed=a.seed,
                          cloud_escalate=a.cloud_escalate, cloud_escalate_after=a.cloud_escalate_after,
                          thinking=a.thinking, reasoning_effort=a.reasoning_effort,
                          max_tokens=a.output_budget, guided_mutations=a.guided_mutations,
                          order=order, family_exemplars=a.family_exemplars,
                          lease_mode=a.lease_mode,
                          family_id=family_id)


def cmd_provider(a):
    from roc import providers
    if a.sub == "list":
        for name, config in sorted(providers.providers().items()):
            print("%-12s %-18s %s (%s=%s)" % (name, config["kind"], config["base_url"],
                                                config["key_env"], "set" if providers.key_available(config["key_env"]) else "missing"))
        return
    if a.sub == "secrets":
        path = providers.secrets_path()
        if getattr(a, "open", False):
            path.parent.mkdir(parents=True, exist_ok=True)
            if not path.exists():
                path.write_text("{}\n", encoding="utf-8")
            if os.name == "nt":
                os.startfile(path)
        print("Local secret file: %s" % path)
        print('Format: {"DEEPSEEK_API_KEY":"paste-key"}')
        return
    if a.sub == "setup":
        import getpass
        configs = providers.providers()
        names = sorted(configs)
        print("Cloud providers:")
        for index, name in enumerate(names, 1):
            config = configs[name]
            state = "set" if providers.key_available(config["key_env"]) else "missing"
            print("  %d) %s (%s: %s)" % (index, name, config["key_env"], state))
        choice = input("Choose provider name or number: ").strip().lower()
        if choice.isdigit() and 1 <= int(choice) <= len(names):
            choice = names[int(choice) - 1]
        if choice not in configs:
            raise SystemExit("Unknown provider: %s" % choice)
        key_env = configs[choice]["key_env"]
        key = getpass.getpass("Paste %s (hidden): " % key_env).strip()
        providers.save_secret(key_env, key)
        print("Saved %s in %s" % (key_env, providers.secrets_path()))
        return
    if a.sub == "add":
        providers.save_provider(a.name, a.kind, a.base_url, a.key_env)
        print("Saved provider %s. Key stays in %s." % (a.name, a.key_env))
        return
    if a.sub == "remove":
        print("Removed provider override %s." % a.name if providers.remove_provider(a.name) else "No saved provider override: %s" % a.name)
        return
    if a.sub == "test":
        print("Privacy: provider test sends only a fixed two-word prompt; no source or executable.")
        out = providers.test_provider(a.name, a.model)
        print("%s:%s %.2fs in=%d out=%d finish=%s reply=%r" %
              (out.provider, out.model, out.latency_s, out.input_tokens, out.output_tokens,
              out.finish_reason or "unknown", out.text[:80]))
        return
    if a.sub == "pricing":
        providers.save_pricing(a.name, a.model, a.input_per_million, a.output_per_million)
        print("Saved stated USD/million-token rates for %s:%s." % (a.name, a.model))


def cmd_dataset(a):
    dataset = need_module("dataset", "Dataset manifests")
    if a.sub == "init":
        path = Path(a.path)
        if path.exists():
            raise SystemExit("manifest exists: %s" % path)
        path.write_text(json.dumps(dataset.template(), indent=2) + "\n", encoding="utf-8")
        print("Wrote legal-source manifest template: %s" % path)
        return
    report = dataset.audit(a.path, strict=not a.allow_partial)
    print("Dataset audit: %s | entries=%d projects=%d splits=%s" %
          ("PASS" if report["ok"] else "FAIL", report["entries"], report.get("projects", 0), report.get("splits", {})))
    for error in report["errors"]:
        print("  " + error)
    if not report["ok"]:
        raise SystemExit(1)


def cmd_model_stats(a):
    from roc import metrics
    rows = metrics.model_stats()
    if not rows:
        print("No worker telemetry yet: run a worker first.")
        return
    print("Model                                  jobs matched improved rate gain avg-sec gpu-min/match")
    for row in rows:
        print("%-38s %4d %7d %8d %4.1f%% %4d %7.1f %14.1f" %
              (row["model"], row["jobs"], row["matched"], row["improved"], row["match_rate"],
               row["score_gain"], row["avg_seconds"], row["gpu_minutes_per_match"]))


def cmd_family_stats(a):
    from roc import metrics
    row = metrics.family_stats()
    if not row["jobs"]:
        print("No family telemetry yet.")
        return
    print("Family jobs=%d exact=%d rate=%.2f%% clients=%d families=%d exemplars=%d propagated=%d tokens=%d cost=$%.6f exact/$=%s exact/100k=%s" %
          (row["jobs"], row["matched"], row["match_rate"], row["clients"], row["families"],
           row["exemplar_jobs"], row["propagated"], row["tokens"], row["cost"],
           "unknown" if row["exact_per_dollar"] is None else row["exact_per_dollar"],
           "unknown" if row["exact_per_100k_tokens"] is None else row["exact_per_100k_tokens"]))


def cmd_failures(a):
    from roc import metrics
    if a.promote:
        rules = metrics.promote_failures()
        print("Promoted %d recurring failure rule suggestion(s) to %s" % (len(rules), metrics.RULES))
        return
    rows = metrics.failure_clusters()
    if not rows:
        print("No worker failures recorded.")
        return
    print("Failure cluster                                      count")
    for row in rows:
        print("%-52s %5d" % (row["reason"], row["count"]))


def cmd_benchmark_models(a):
    from roc import benchmark, metrics, draft, providers, worker
    if a.progress:
        rows = metrics.corpus_stats(benchmark.build_hidden(a.limit))
        total = sum(r["jobs"] for r in rows)
        print("Benchmark records: %d (resume with --local-run --full --resume)" % total)
        for row in rows:
            print("  %s %-6s source=%s jobs=%d matches=%d gain=%d" %
                  (row["model"], row["bucket"], row["source_present"], row["jobs"],
                   row["matched"], row["score_gain"]))
        return
    if a.hidden:
        hidden = benchmark.build_hidden(a.limit)
        print("Hidden benchmark corpus: %d targets (%s)" % (len(hidden), benchmark.HIDDEN))
        return
    if a.local_run or a.model:
        hidden = benchmark.build_hidden(a.limit)
        models = a.model or [m for m in draft.ollama_models() if "qwen2.5-coder" in m]
        if not models:
            raise SystemExit("no qwen2.5-coder model installed")
        for model in models:
            if providers.is_cloud(model):
                if not a.allow_cloud:
                    raise SystemExit("Cloud benchmark sends prompts outside this PC. Pass --allow-cloud.")
                if not providers.available(model):
                    _provider, _remote, config = providers.parse_model(model)
                    raise SystemExit("Cloud key is missing: set %s" % config["key_env"])
            elif not draft.pick_model(model):
                raise SystemExit("Model is not installed: %s" % model)
        if any(providers.is_cloud(model) for model in models):
            print("Privacy: cloud benchmark sends bounded assembly, symbols, prompts, and source hints. "
                  "No executable or provider key leaves this PC.")
        corpus = hidden if a.full else hidden[:a.limit]
        print("Running benchmark: %d targets, %d models%s" %
              (len(corpus), len(models), " (resumable)" if a.resume else ""))
        strategies = tuple(a.strategies.split(","))
        bad = set(strategies).difference({"auto", "direct", "structured", "reference"})
        if bad:
            raise SystemExit("unknown strategy: %s" % ", ".join(sorted(bad)))
        budget = providers.CloudBudget(a.max_cloud_requests, a.max_cloud_tokens, a.max_cloud_cost)
        gate = providers.CloudGate(a.cloud_concurrency)
        for repeat in range(max(1, a.repeats)):
            session = a.session if a.repeats == 1 else "%s-r%d" % (a.session, repeat + 1)
            benchmark.run_local(corpus, models, rounds=a.rounds, resume=a.resume, session=session,
                                strategies=strategies, provider_options={"allow_cloud": a.allow_cloud,
                                "budget": budget, "gate": gate, "seed": a.seed,
                                "diverse_candidates": a.diverse_candidates,
                                "thinking": a.thinking, "reasoning_effort": a.reasoning_effort})
        return
    if a.baseline:
        hidden = benchmark.build_hidden(a.limit)
        current = metrics.corpus_stats(hidden)
        path = ROOT / "work" / "benchmark-baseline.json"
        if path.exists():
            print("Previous baseline:", path.read_text())
            print("Current:", current)
        path.write_text(json.dumps(current, indent=1))
        print("Saved benchmark baseline: %s" % path)
        return
    rows = benchmark.build(a.limit) if a.generate or not benchmark.CORPUS.exists() else benchmark.load()
    print("Benchmark corpus: %d fixed targets (%s)" % (len(rows), benchmark.CORPUS))
    for bucket in ("tiny", "medium", "large"):
        print("  %-6s %d" % (bucket, sum(r["bucket"] == bucket for r in rows)))
    stats = metrics.model_stats()
    if stats:
        print("Model telemetry (run workers on this corpus to compare):")
        for row in stats:
            print("  %-36s jobs=%d 100%%=%d improved=%d avg=%.1fs" %
                  (row["model"], row["jobs"], row["matched"], row["improved"], row["avg_seconds"]))
    if a.run:
        settings = worker.load_settings()
        server = a.server or settings.get("server")
        user = a.user or settings.get("user")
        if not server or not user:
            raise SystemExit("benchmark run needs --server/--user or saved worker config")
        targets = [{"client": row["client"], "addr": row["addr"]} for row in rows]
        models = [m for m in draft.ollama_models() if "embed" not in m.lower()]
        if not models:
            raise SystemExit("no Ollama models installed")
        for model in models:
            print("Running fixed corpus with %s" % model)
            worker.run(server, user, model=model, max_jobs=len(targets), max_size=256,
                       use_revng=False, rounds=2, targets=targets)


def cmd_source_status(a):
    import json
    from roc import refsource
    classes, funcs = refsource.build_index()
    if a.build_meta:
        print("2016 source metadata: %d files" % refsource.build_meta())
    print("2016 source index: %d classes/namespaces, %d functions" % (len(classes), len(funcs)))
    for name, entry in sorted(clients.load().items()):
        rows = match_rows = 0
        explained = set()
        path = ROOT / "work" / name / "functions.jsonl"
        if not path.exists():
            continue
        for line in path.read_text(errors="replace").splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row.get("kind", "code") != "code":
                continue
            rows += 1
            ids = refsource.identifiers(row.get("unit", ""))
            if any(i and i[0].isupper() and (i in classes or i in funcs) for i in ids):
                explained.add(row.get("unit"))
        match_rows = len(explained)
        print("  %-10s %6d code funcs, %6d source-mapped units" % (name, rows, match_rows))


def cmd_status(a):
    from roc.worker import Api
    s = settings()
    api = Api(need(a.server or s.get("server"), "server", "Use --server URL"), a.token or s.get("token"))
    st = api.call("/v1/status")
    for c in st["clients"]:
        print("%-6s %6d / %-6d matched, %d partial" % (c["client"], c["matched"], c["functions"], c["partial"]))
    print("Workers active (last 15 min): %d" % len(st["workers"]))
    for w in st["workers"]:
        print("  %-20s %-4s seen %ds ago" % (w["user"], w["mode"], w["seen_ago"]))
    print("Open leases: %d" % len(st["leases"]))
    print("Top contributors:")
    for i, row in enumerate(api.call("/v1/leaderboard")[:10], 1):
        print("  %2d. %-20s %5d matched  %6d points" % (i, row["user"], row["matched"], row["points"]))


def cmd_model(a):
    from roc import draft, providers
    from roc.worker import clear_setting, save_settings
    models = draft.ollama_models()
    if a.name:
        if a.name == "default":
            clear_setting("model")
            print("Model: default (%s)" % (draft.pick_model() or "none installed"))
            return
        if providers.is_cloud(a.name):
            if not providers.available(a.name):
                _provider, _remote, config = providers.parse_model(a.name)
                sys.exit("Cloud key is missing: set %s" % config["key_env"])
            save_settings(model=a.name)
            print("Model: %s (cloud)" % a.name)
            return
        local_name = a.name[6:] if a.name.startswith("local:") else a.name
        if local_name not in models:
            sys.exit("Model '%s' is not installed. Installed: %s" %
                     (a.name, ", ".join(models) or "none (run: ollama pull <model>)"))
        save_settings(model=a.name)
        print("Model: %s" % a.name)
        return
    selected = settings().get("model")
    default = draft.pick_model()
    print("Worker model: %s%s" % (selected or default or "none installed",
                                   " (default)" if not selected else ""))
    if models:
        print("Installed: " + ", ".join(models))
        print("Change: roc model <name>   Reset: roc model default")
    else:
        print("Install one: ollama pull qwen2.5-coder:7b")


def cmd_optimize(a):
    from roc import optimizer
    model = a.model or settings().get("model")
    if not model:
        from roc import draft
        model = draft.pick_model()
    if not model:
        raise SystemExit("Choose a model first: roc model")
    if a.clear:
        print("Cleared optimizer profile for %s." % model if optimizer.clear_profile(model)
              else "No optimizer profile saved for %s." % model)
        return
    optimizer.run(model, allow_cloud=a.allow_cloud, max_cloud_requests=a.max_cloud_requests,
                  max_cloud_tokens=a.max_cloud_tokens, max_cloud_cost=a.max_cloud_cost,
                  force=a.force, target_count=a.targets)


def cmd_progress(a):
    progress = need_module("progress", "Publishing the website")
    s = settings()
    srv = a.server or s.get("server")
    p = progress.build(srv, a.token or s.get("token"), s.get("public_server"))
    for c in p["clients"]:
        if c["started"]:
            print("%-6s %d/%d matched, %.2f%% of code" % (
                c["name"], c["matched"], c["functions"], 100 * c["matched_bytes"] / max(c["bytes"], 1)))
        else:
            print("%-6s not started" % c["name"])
    print("Wrote docs/ (%s). Commit + push docs/ to update the website." % ("scores from " + srv if srv else "local scores"))


# ---------- menu ----------

def ask(prompt, default=None):
    value = input("%s%s: " % (prompt, " [%s]" % default if default else "")).strip()
    return value or default


def menu():
    items = [
        ("First-time setup (packages, compilers, links - no Ollama/Docker)", lambda: main(["install"])),
        ("Set up my worker (username, client, cloud)", lambda: main(["setup"])),
        ("Help automatically with AI (start a worker)", menu_worker),
        ("Check what needs fixing", lambda: main(["doctor"])),
        ("Install local AI instead (optional: Ollama, then Docker)", lambda: main(["local-ai"])),
        ("Work on a function by hand", menu_hand),
        ("Check my hand-written functions", lambda: main(["check", ask("Client", "2008-06")])),
        ("Send my hand-written functions to the server", lambda: main(["submit", ask("Client", "2008-06")])),
        ("Host the group server", lambda: main(["server"])),
        ("Server status and leaderboard", lambda: main(["status"])),
        ("Update the progress website files", lambda: main(["progress"])),
        ("Add a new Roblox client", lambda: main(["client", "add", ask("Short name (e.g. 2013-01)"),
                                                  ask("Path to RobloxApp.exe or Roblox.exe")])),
        ("Auto-match easy functions", lambda: main(["auto", "all"])),
    ]
    while True:
        s = settings()
        print()
        print("RoConstruct %s" % ("- you are %s" % s["user"] if s.get("user") else ""))
        for i, (label, _) in enumerate(items, 1):
            print("  %d. %s" % (i, label))
        print("  0. Exit")
        pick = input("> ").strip()
        if pick in ("", "0", "q", "exit"):
            return
        if not (pick.isdigit() and 1 <= int(pick) <= len(items)):
            print("Type a number from the list.")
            continue
        try:
            items[int(pick) - 1][1]()
        except SystemExit as error:
            if error.code not in (None, 0):
                print(error.code)
        except KeyboardInterrupt:
            print(" Stopped.")
        except Exception as error:
            print("Something went wrong: %s" % error)


def menu_worker():
    """Cloud by default; a local model is one answer away, never assumed."""
    from roc import draft, handoff, worker
    s = settings()
    if handoff.load():
        print("Saved setup: %s (%s)" % (handoff.status()["detail"],
                                        ", ".join("%s=%s" % (k, handoff.load()[k])
                                                  for k in ("user", "client", "server", "mode")
                                                  if handoff.load().get(k))))
        if ask("Run it? [Y/n] ", "y").lower().startswith("n"):
            return main(["setup"])
        return main(["launch"])
    cloud = worker.cloud_default()
    local = draft.pick_model()
    print("Cloud model: %s (no GPU needed)" % (cloud or "none set - run: roc provider setup"))
    print("Local model: %s" % (local or "not installed (optional: roc local-ai)"))
    if not cloud:
        return main(["setup"])
    return main(["setup", "--launch"])


def menu_hand():
    client = ask("Client", "2008-06")
    main(["next", client])
    addr = ask("Address to claim (copy one from the list)")
    if addr:
        main(["claim", client, addr, "--open"])


def main(argv=None):
    ap = argparse.ArgumentParser(prog="roc", description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", metavar="command")

    def cmd(name, fn, help, *args):
        p = sub.add_parser(name, help=help)
        for flags, kw in args:
            p.add_argument(*flags, **kw)
        p.set_defaults(fn=fn)
        return p

    cmd("install", cmd_install, "cloud-first bootstrap: packages, exact compilers, link, website",
        (["--yes", "-y"], {"action": "store_true", "help": "accept every download without asking"}),
        (["--client"], {"help": "client you plan to work on, so the size estimate can include its exe"}),
        (["--open-site", "--open"], {"action": "store_true", "dest": "open_site",
                                     "help": "open the website when the install finishes"}))
    cmd("local-ai", cmd_local_ai, "opt-in extras: install Ollama (--docker also adds Docker/Rev.ng)",
        (["--docker"], {"action": "store_true", "help": "also offer Docker Desktop + Rev.ng hints"}),
        (["--model"], {"help": "model tag to pull once Ollama is installed"}))
    cmd("setup", cmd_setup, "ask username / client / cloud, save a signed config, start the worker",
        (["url"], {"nargs": "?", "help": "a roconstruct:// link from the website"}),
        (["--user"], {}), (["--client"], {}), (["--server"], {}), (["--token"], {}),
        (["--model"], {}),
        (["--cloud"], {"action": "store_true", "default": None, "dest": "cloud",
                       "help": "cloud model (opt-in, no GPU)"}),
        (["--local"], {"action": "store_false", "dest": "cloud",
                       "help": "use a local model instead (asks before installing Ollama)"}),
        (["--launch", "-l"], {"action": "store_true", "help": "start the worker immediately"}),
        (["--docker"], {"action": "store_true",
                        "help": "local mode: also offer Docker Desktop + Rev.ng hints"}),
        (["--no-check"], {"action": "store_true", "help": "skip the doctor checks before launching"}))
    p = cmd("launch", cmd_launch, "configure the worker in this terminal and run it")
    p.add_argument("--client", help="override the client from the config")
    p.add_argument("--model", help="override the model from the config")
    p.add_argument("--workers", help="bounded concurrent lease loops (1-256 or auto)")
    p.add_argument("--rounds", type=int, help="AI tries per function")
    p.add_argument("--max-size", dest="max_size", type=int, help="skip functions bigger than this")
    p.add_argument("--jobs", type=int, help="stop after this many functions")
    p.add_argument("--lease-mode", choices=["function", "family"], default=None,
                   help="lease one function, or stay on one strict family")
    p.add_argument("--family-id", help="strict 24-hex family fingerprint")
    p.add_argument("--family-example", help="seed family from CLIENT:ADDRESS")
    p.add_argument("--no-revng", dest="no_revng", action="store_true", help="never use Rev.ng hints")
    p.add_argument("--dry-run", dest="dry_run", action="store_true",
                   help="print the plan without leasing a job")
    p.add_argument("--setup", dest="setup", action="store_true",
                   help="ignore the saved config and answer the setup questions again")
    cmd("doctor", cmd_doctor, "diagnose this install and print repair steps",
        (["--json"], {"action": "store_true", "help": "machine-readable output"}),
        (["--no-check", "--no-network"], {"action": "store_true", "dest": "no_check",
                                           "help": "skip the network checks"}))
    c = sub.add_parser("client", help="add or list Roblox clients").add_subparsers(dest="sub", required=True)
    p = c.add_parser("add", help="register a client exe and analyze it")
    p.add_argument("name")
    p.add_argument("exe")
    p.add_argument("--allow-modified", action="store_true", help="accept an exe whose PE checksum is wrong")
    p.add_argument("--donor", action="store_true", help="reference binary for matching/testing only, not shown on the site")
    p.set_defaults(fn=cmd_client_add)
    c.add_parser("verify", help="check your exes: same build as registered, not modified").set_defaults(fn=cmd_client_verify)
    cmd("client-fetch", cmd_client_fetch, "download a client from Drive and verify it ('all' for every client)",
        (["name"], {}))
    p = cmd("client-sources", cmd_client_sources, "set the clients.zip bundle, or index a Drive folder",
            (["folder"], {"nargs": "?"}), (["--bundle"], {"help": "local clients.zip to hash and record"}),
            (["--also"], {"help": "comma-separated months to index even though they are not "
                                   "registered yet, e.g. 2016-06"}),
            (["--dry-run", "-n"], {"action": "store_true"}))
    p.set_defaults(folder=None)
    c.add_parser("list", help="registered clients and whether you have them").set_defaults(fn=cmd_client_list)
    p = c.add_parser("remove", help="unregister a client (--purge deletes its local copies)")
    p.add_argument("name")
    p.add_argument("--purge", action="store_true",
                   help="also delete clients/<name>/ and work/<name>/ (it re-downloads on demand)")
    p.set_defaults(fn=cmd_client_remove)
    cmd("analyze", cmd_analyze, "split a client exe into functions ('all' for every client)", (["name"], {}))
    cmd("next", cmd_next, "list the easiest open functions", (["name"], {}), (["-n"], {"type": int, "default": 20}))
    cmd("claim", cmd_claim, "start a function: writes src/<client>/<addr>.cpp",
        (["name"], {}), (["addr"], {}), (["--open"], {"action": "store_true", "help": "open in Notepad"}))
    cmd("check", cmd_check, "compile src/<client>/*.cpp and score against the exe",
        (["name"], {}), (["addr"], {"nargs": "?"}))
    cmd("auto", cmd_auto, "auto-match trivial functions (getters, setters, empty...) ('all' for every client)",
        (["name"], {}), (["--max-size"], {"type": int, "default": 48}))
    cmd("xcopy", cmd_xcopy, "copy stored matches to the other clients that share the function",
        (["name"], {}), (["--limit"], {"type": int, "default": None,
                                       "help": "try only the first N candidate sources (testing)"}),
        (["--dry-run", "-n"], {"action": "store_true", "help": "report what would match, write nothing"}))
    cmd("ref", cmd_ref, "find the 2016 Roblox source behind a client function",
        (["unit"], {"nargs": "?"}), (["--summarise"], {"action": "store_true",
                                                       "help": "how much of each client the 2016 tree explains"}),
        (["--client"], {"help": "restrict --summarise to one client"}),
        (["--limit"], {"type": int, "default": 5}))
    cmd("libs", cmd_libs, "match open-source library code from its real source ('all' or recipe names)",
        (["names"], {"nargs": "+"}), (["--client"], {"default": "all"}))
    cmd("mass", cmd_mass, "run every automatic matcher (runtime, STL, libraries, shapes); takes a while",
        (["--client"], {"default": "all"}))
    cmd("flags", cmd_flags, "find the client's compiler flags from matched sources",
        (["name"], {}), (["--sweep"], {"action": "store_true",
        "help": "try interacting flag combinations; stop on exact corpus"}),
        (["--limit"], {"type": int, "help": "sweep only smallest N sources"}))
    cmd("config", cmd_config, "save username / server / password / model",
        (["--user"], {}), (["--server"], {}), (["--token"], {}), (["--model"], {}),
        (["--public-server"], {"help": "address shown in website join links (host:port)"}),
        (["--allow-cloud"], {"action": "store_true", "default": None,
                              "help": "save approval to send worker prompts to cloud models"}))
    cmd("model", cmd_model, "show or choose worker model (default = automatic choice)",
        (["name"], {"nargs": "?"}))
    cmd("optimize", cmd_optimize, "calibrate and save one model's worker profile",
        (["--model"], {}), (["--allow-cloud"], {"action": "store_true"}),
        (["--max-cloud-requests"], {"type": int, "default": 300}),
        (["--max-cloud-tokens"], {"type": int, "default": 500000}),
        (["--targets"], {"type": int, "default": 12, "help": "fresh local targets (6-24; default 12)"}),
        (["--max-cloud-cost"], {"type": float}),
        (["--clear"], {"action": "store_true", "help": "remove saved profile without benchmarking"}),
        (["--force"], {"action": "store_true", "help": "replace existing profile"}))
    p = sub.add_parser("provider", help="configure or test non-secret cloud model providers")
    ps = p.add_subparsers(dest="sub", required=True)
    ps.add_parser("list", help="show providers and whether their key environment variable is set").set_defaults(fn=cmd_provider)
    psecret = ps.add_parser("secrets", help="show safe user-local API-key file path")
    psecret.add_argument("--open", action="store_true", help="create and open the file in Notepad")
    psecret.set_defaults(fn=cmd_provider)
    ppricing = ps.add_parser("pricing", help="set user-supplied model token prices for spend caps")
    ppricing.add_argument("name")
    ppricing.add_argument("--model", required=True, help="exact provider model name")
    ppricing.add_argument("--input-per-million", type=float, required=True, help="USD per million input tokens")
    ppricing.add_argument("--output-per-million", type=float, required=True, help="USD per million output tokens")
    ppricing.set_defaults(fn=cmd_provider)
    ps.add_parser("setup", help="choose a provider and save its key interactively").set_defaults(fn=cmd_provider)
    pa = ps.add_parser("add", help="add an OpenAI-compatible or native cloud endpoint (no key saved)")
    pa.add_argument("name")
    pa.add_argument("--kind", required=True, choices=["openai-chat", "openai-responses", "anthropic-messages", "gemini"])
    pa.add_argument("--base-url", required=True)
    pa.add_argument("--key-env", required=True)
    pa.set_defaults(fn=cmd_provider)
    pr = ps.add_parser("remove", help="remove a custom provider override")
    pr.add_argument("name")
    pr.set_defaults(fn=cmd_provider)
    pt = ps.add_parser("test", help="send a tiny opt-in provider probe")
    pt.add_argument("name")
    pt.add_argument("--model", required=True)
    pt.set_defaults(fn=cmd_provider)
    p = sub.add_parser("dataset", help="create or audit legal MSVC training-pilot manifests")
    ds = p.add_subparsers(dest="sub", required=True)
    di = ds.add_parser("init", help="write a legal-source-only manifest template")
    di.add_argument("path")
    di.set_defaults(fn=cmd_dataset)
    da = ds.add_parser("audit", help="validate compiler data and project-held-out splits")
    da.add_argument("path")
    da.add_argument("--allow-partial", action="store_true", help="check structure before 100-300 pair pilot is complete")
    da.set_defaults(fn=cmd_dataset)
    cmd("link", cmd_link, "one-click links: 'install', 'remove', or a roconstruct:// URL", (["target"], {}))
    cmd("submit", cmd_submit, "send hand-written sources to the server",
        (["name"], {}), (["addr"], {"nargs": "*"}), (["--server"], {}), (["--user"], {}), (["--token"], {}))
    cmd("pull", cmd_pull, "download everyone's sources from the server into src/ ('all' for every client)",
        (["name"], {}), (["--force"], {"action": "store_true", "help": "replace your local files"}),
        (["--server"], {}), (["--token"], {}))
    cmd("server", cmd_server, "host the group server",
        (["--port"], {"type": int, "default": 8765}), (["--host"], {"default": "0.0.0.0"}),
        (["--token"], {"help": "password workers must send"}),
        (["--discord-webhook"], {"help": "Discord mine-log webhook URL (or ROCONSTRUCT_DISCORD_WEBHOOK)"}),
        (["--lease"], {"type": int, "default": 900, "help": "seconds before an abandoned job frees up"}),
        (["--tunnel"], {"action": "store_true", "help": "public HTTPS address via Cloudflare (no router setup)"}),
        (["--publish"], {"action": "store_true", "help": "update + push the website regularly"}),
        (["--publish-every"], {"type": int, "default": 3600, "help": "seconds between site updates"}),
        (["--public-server"], {"help": "address shown on the site (if not using --tunnel)"}),
        (["--startup"], {"action": "store_true", "help": "start host.cmd automatically when you log in"}))
    cmd("worker", cmd_worker, "help automatically: AI drafts, compile, submit",
            (["--order"], {"choices": ["auto", "best", "matched", "unmatched", "easiest", "random"], "default": "auto",
                           "help": "which functions first: most-matched (score high to low), random, unmatched (0%% first), easiest, best evidence, or auto"}),
        (["--server"], {}), (["--user"], {}), (["--token"], {}), (["--model"], {}),
        (["--client"], {"help": "restrict work to one registered client (for example 2008-06)"}),
        (["--rounds"], {"type": int, "default": 4, "help": "AI tries per function"}),
        (["--strategy"], {"choices": ["direct", "structured", "reference"], "default": "direct",
                            "help": "candidate-generation prompt strategy"}),
        (["--max-size"], {"type": int, "default": 256, "help": "skip functions bigger than this (bytes)"}),
        (["--output-budget"], {"type": int, "default": 2048,
                               "help": "max tokens per LLM reply (128-8192)"}),
        (["--jobs"], {"type": int, "help": "stop after this many functions"}),
        (["--workers"], {"default": "1",
                          "help": "bounded concurrent lease loops (1-256 or auto)"}),
        (["--lease-mode"], {"choices": ["function", "family"], "default": "function",
                              "help": "lease one function, or stay on one strict family until exhausted"}),
        (["--family-id"], {"help": "strict 24-hex family fingerprint"}),
        (["--family-example"], {"help": "seed family from CLIENT:ADDRESS"}),
        (["--allow-cloud"], {"action": "store_true", "help": "allow prompt data to leave this PC"}),
        (["--max-cloud-requests"], {"type": int, "help": "cloud request budget for this worker"}),
        (["--max-cloud-tokens"], {"type": int, "help": "cloud token budget for this worker"}),
        (["--max-cloud-cost"], {"type": float, "help": "cloud cost budget when provider pricing is configured"}),
        (["--cloud-concurrency"], {"type": int,
                                     "help": "maximum cloud requests; defaults to worker count"}),
        (["--diverse-candidates"], {"type": int, "default": 1,
                                      "help": "independent samples for hard functions; default 1"}),
        (["--cloud-min-size"], {"type": int, "default": 97,
                                  "help": "use local 7B fallback below this byte size; 0 disables routing"}),
        (["--cloud-fallback"], {"help": "installed local model for --cloud-min-size jobs"}),
        (["--cloud-escalate"], {"help": "cloud model for medium/large jobs stalled by primary model"}),
        (["--cloud-escalate-after"], {"type": int, "default": 2,
                                        "help": "primary attempts before cloud escalation"}),
        (["--seed"], {"type": int, "help": "generation seed where provider supports it"}),
        (["--thinking"], {"choices": ["auto", "enabled", "disabled"], "default": "auto",
                            "help": "provider reasoning mode; auto disables it for tiny jobs"}),
        (["--family-exemplars"], {"action": "store_true", "default": True,
                                    "help": "use verified same-shape sources as compact family exemplars (default)"}),
        (["--reasoning-effort"], {"choices": ["auto", "low", "medium", "high", "max"],
                                    "help": "provider reasoning effort; auto uses low for tiny jobs"}),
        (["--no-revng"], {"action": "store_true"}),
        (["--preset"], {"choices": ["fast", "balanced", "deep"], "default": "balanced"}),
        (["--dry-run"], {"action": "store_true", "help": "show worker setup without leasing a job"}),
        (["--source-only"], {"action": "store_true", "help": "run deterministic candidates; never call Ollama"}),
        (["--guided-mutations"], {"action": "store_true", "help": "enable evidence-guided source mutations after compilation"}),
        (["--no-update"], {"action": "store_true", "help": "skip the pre-run source update check"}))
    cmd("model-stats", cmd_model_stats, "compare models using worker telemetry")
    cmd("family-stats", cmd_family_stats, "show family coverage, propagation, cost, and exact rate")
    cmd("failures", cmd_failures, "show recurring worker compile/API failures",
        (["--promote"], {"action": "store_true", "help": "save repeated failure rule suggestions"}))
    cmd("benchmark-models", cmd_benchmark_models, "create fixed targets and compare model telemetry",
        (["--generate"], {"action": "store_true"}),
        (["--hidden"], {"action": "store_true", "help": "build source/score-hidden solved targets"}),
        (["--local-run"], {"action": "store_true", "help": "run two installed coder models locally without submit"}),
        (["--model"], {"action": "append", "help": "model arm; repeat for local/cloud models"}),
        (["--session"], {"default": "benchmark", "help": "telemetry session id; use one per benchmark arm"}),
        (["--repeats"], {"type": int, "default": 1, "help": "independent benchmark repeats"}),
        (["--rounds"], {"type": int, "default": 1, "help": "generation rounds per target"}),
        (["--diverse-candidates"], {"type": int, "default": 1,
                                      "help": "independent candidates for hard-target benchmark arms"}),
        (["--seed"], {"type": int, "help": "generation seed where provider supports it"}),
        (["--thinking"], {"choices": ["enabled", "disabled"],
                            "help": "explicit provider reasoning mode for measured arms"}),
        (["--reasoning-effort"], {"choices": ["low", "medium", "high", "max"],
                                    "help": "explicit provider reasoning effort for measured arms"}),
        (["--allow-cloud"], {"action": "store_true", "help": "allow cloud benchmark prompt sending"}),
        (["--max-cloud-requests"], {"type": int}),
        (["--max-cloud-tokens"], {"type": int}),
        (["--max-cloud-cost"], {"type": float}),
        (["--cloud-concurrency"], {"type": int, "default": 1}),
        (["--full"], {"action": "store_true", "help": "use the complete fixed/hidden corpus (can take hours)"}),
        (["--resume"], {"action": "store_true", "help": "skip local benchmark targets already recorded"}),
        (["--strategies"], {"default": "direct,structured,reference",
                              "help": "comma-separated: direct,structured,reference"}),
        (["--progress"], {"action": "store_true", "help": "show resumable benchmark records without running models"}),
        (["--baseline"], {"action": "store_true", "help": "save/compare hidden-corpus regression baseline"}),
        (["--run"], {"action": "store_true", "help": "run installed models on the fixed targets"}),
        (["--limit"], {"type": int, "default": 8}),
        (["--server"], {}), (["--user"], {}))
    cmd("source-status", cmd_source_status, "show 2016 source-name coverage",
        (["--build-meta"], {"action": "store_true", "help": "build persisted token/declaration metadata"}))
    cmd("status", cmd_status, "server progress, workers, leaderboard", (["--server"], {}), (["--token"], {}))
    cmd("progress", cmd_progress, "write docs/ data for the website", (["--server"], {}), (["--token"], {}))
    a, unknown = ap.parse_known_args(argv)
    if unknown:
        ap.error("unrecognized arguments: %s" % " ".join(unknown))
    if not a.cmd:
        return menu()
    a.fn(a)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nStopped.")
    except RuntimeError as error:  # server/network problems: message, not a traceback
        sys.exit("Error: %s" % error)
