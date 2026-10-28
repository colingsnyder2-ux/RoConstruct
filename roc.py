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


def _addr(text):
    value = text.strip().lower()
    value = value[2:] if value.startswith("0x") else value
    return value.zfill(8) if value and len(value) <= 8 and all(c in "0123456789abcdef" for c in value) else text


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
    from roc import link, worker
    url = getattr(a, "url", None)
    if url:
        payload = link.from_url(url)
        print("Accepted a website link: user=%s client=%s server=%s mode=%s cloud=%s" %
              (payload["user"], payload["client"], payload["server"], payload["mode"],
               "yes" if payload["cloud"] else "no"))
        link.apply(url)
        return finish_setup(link, a, run=run)
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
    if client == "all":
        print("\nAll clients: the worker takes jobs from every client that is ready and")
        print("fetches each missing exe itself. Analyze them once so none are skipped:")
        print("  roc client-fetch all && roc analyze all")
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
    payload = link.save(user=user, client=client, server=server,
                           token=(getattr(a, "token", None) or s.get("token")),
                           mode=mode, cloud=cloud, model=getattr(a, "model", None))
    print("Saved a signed setup: %s" % link.config_path())
    return finish_setup(link, a, run=run)


def ask_client():
    from roc import clients
    registry = sorted(clients.load())
    if not registry:
        return None
    print("\nWhich client do you want to help with?")
    for index, name in enumerate(registry, 1):
        entry = clients.load()[name]
        print("  %d) %s  (%s, compiler %s)" % (index, name, entry.get("compiler"), entry.get("compiler_build")))
    print("  a) all of them  (every client with its exe, compiler and analysis ready)")
    picked = input("Client [1]: ").strip() or "1"
    if picked.lower() in ("a", "all"):
        return "all"
    if picked.isdigit() and 1 <= int(picked) <= len(registry):
        return registry[int(picked) - 1]
    if picked in clients.load():
        return picked
    raise SystemExit("Unknown client: %s" % picked)


def finish_setup(link, a, run=None):
    from roc import doctor
    payload = link.load()
    if not payload:
        raise SystemExit("The setup could not be saved (signature check failed). Run: roc setup")
    print()
    doctor_report(doctor.all_checks(network=not getattr(a, "no_check", False)))
    if run is None:
        run = bool(getattr(a, "launch", False))
    if run:
        # run in this terminal: the knobs stay visible and closeable here
        return link.run_now(_forwarded(a))
    print("Start the worker with: roc launch")


def doctor_report(checks):
    from roc import doctor
    print(doctor.format_report(checks))
    return doctor.failed(checks)


def _forwarded(a):
    """Flags on `a` that the worker entry point understands, as a CLI list."""
    forwarded = []
    for name in ("client", "model", "workers", "rounds", "max_size", "jobs", "lease_mode",
                 "family_id", "family_example", "unit", "cloud_escalate", "cloud_escalate_after",
                 "thinking", "reasoning_effort", "output_budget", "cloud_concurrency", "strategy",
                 "order", "verbosity", "max_cloud_requests", "max_cloud_tokens", "max_cloud_cost"):
        value = getattr(a, name, None)
        if value is not None:
            forwarded += ["--%s" % name.replace("_", "-"), str(value)]
    for flag, name in (("no-revng", "no_revng"), ("no-remill", "no_remill"),
                       ("force-lift", "force_lift"), ("dry-run", "dry_run"),
                       ("allow-cloud", "allow_cloud"), ("source-only", "source_only")):
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
    from roc import link
    if not link.load():
        print("No saved setup yet. Answering here - nothing installs until you pick a model.\n")
    if getattr(a, "setup", False) or not link.load():
        return cmd_setup(a, run=True)
    return link.run_now(_forwarded(a))


def cmd_doctor(a):
    from roc import doctor
    checks = doctor.all_checks(network=not a.no_check)
    if a.json:
        print(json.dumps(checks, indent=1))
    else:
        print(doctor.format_report(checks))
    if doctor.failed(checks):
        raise SystemExit(1)


def cmd_gui(a):
    from roc import gui
    gui.serve(port=a.port, open_browser=not a.no_browser)


def cmd_link(a):
    from roc import link
    if a.target == "install":
        return link.install()
    if a.target == "remove":
        return link.remove()
    try:
        link.launch(a.target)
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
    from roc import clients
    reg = clients.load()
    names = sorted(reg) if a.name == "all" else [a.name]
    bad = 0
    for name in names:
        if name not in reg:
            sys.exit("%s is not registered. See:  roc client list" % name)
        try:
            clients.fetch(name)
        except clients.FetchError as error:
            print("%-8s %s" % (name, error))
            bad += 1
    if bad:
        sys.exit("%d client(s) could not be fetched." % bad)


def cmd_client_sources(a):
    """Point clients/clients.json at a bundle zip, or re-index a public Drive folder."""
    from roc import clients
    if a.bundle:
        clients.set_bundle(a.bundle)
        return
    folder = a.folder.split("/folders/")[-1].split("?")[0].strip("/")
    extra = [s.strip() for s in (a.also or "").split(",") if s.strip()]
    if extra:
        print("also indexing: %s (not in clients.json yet)" % ", ".join(extra))
    clients.index_drive(folder, dry_run=a.dry_run, extra_slots=extra)


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
    from roc import clients
    entry = clients.load().get(name)
    if not entry or clients.status(name, entry) == "ok":
        return True
    if clients.ensure(name):
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
    s = settings()
    if s.get("server"):  # local scores.json alone lists functions others already matched on the server
        from roc import worker
        try:
            for row in worker.Api(s["server"], s.get("token")).call("/v1/sources?scores=1&client=" + a.name, timeout=120):
                match.save_score(a.name, row["addr"], row["score"])
        except Exception as error:
            print("Server scores unavailable (%s); listing local scores only." % error)
    scores_file = ROOT / "work" / a.name / "scores.json"
    scores = json.loads(scores_file.read_text()) if scores_file.exists() else {}
    rows = [r for r in match._functions(a.name).values() if r["kind"] == "code" and scores.get(r["addr"], 0) < 100]
    rows.sort(key=lambda r: (r["calls"], r["size"]))
    print("Easiest open functions in %s (claim one with: roc claim %s <addr>):" % (a.name, a.name))
    for r in rows[:a.n]:
        print("  %s  %4d bytes  %-3s  %s" % (r["addr"], r["size"], "%d%%" % scores.get(r["addr"], 0), r["unit"]))


def cmd_claim(a):
    from roc import match, worker
    if not ready(a.name):
        sys.exit("%s: no verified exe, nothing to claim." % a.name)
    path = match.claim(a.name, a.addr)
    s = settings()
    if s.get("server") and s.get("user"):
        try:
            worker.Api(s["server"], s.get("token")).call(
                "/v1/claim", {"user": s["user"], "worker": s["user"],
                              "client": a.name, "addr": a.addr}, timeout=15)
            print("Claimed on the server (other agents skip it for ~2h).")
        except worker.ApiFailure as error:
            if "another worker" in str(error):
                print("Note: %s is already claimed by another worker." % a.addr)
    print("Edit this file:", path)
    print("Then run:       roc check %s %s" % (a.name, path.stem))
    if a.open and os.name == "nt":
        subprocess.Popen(["notepad.exe", str(path)])


def _score_band(score):
    """Coarser the band, the more work a function needs. Manual matching drains the
    near-done bands first (see the manual matching loop in docs/AGENT_GUIDE.md)."""
    if score >= 95:
        return 0
    if score >= 90:
        return 1
    if score >= 70:
        return 2
    return 3


BLOCK_SECONDS = 365 * 86400


def _work_cooldown_seconds(a):
    """A --block park outlives any session; a changed source still reopens it (see cmd_work)."""
    if getattr(a, "block", False):
        return BLOCK_SECONDS
    try:
        return max(0, int(getattr(a, "cooldown", 900) or 0))
    except (TypeError, ValueError):
        return 900


def _work_reason(a, default):
    reason = getattr(a, "reason", "") or default
    return "blocked: " + reason if getattr(a, "block", False) else reason


def _local_evidence(client, addr):
    """Evidence key for local cooldowns: source hash when present, else row facts."""
    from roc import claims as claim_state, match, research
    path = ROOT / "src" / client / (addr + ".cpp")
    if path.exists():
        return research.digest(path.read_text(encoding="utf-8", errors="replace"))
    try:
        row = match._functions(client).get(addr) or {}
    except (OSError, SystemExit):
        row = {}
    return claim_state.evidence_key(row)


def _release_target(api, user, client, addr, reason="", cooldown=900, keep_token_on_failure=True):
    """Release the token this checkout persisted, never somebody else's."""
    from roc import claims as claim_state
    addr = str(addr).lower().replace("0x", "").zfill(8)
    claim = claim_state.load_claim(client, addr, include_expired=True)
    released, note = False, ""
    if not claim:
        print("%s %s: no locally stored lease token; nothing to release." % (client, addr))
    elif claim.get("worker") and user and claim["worker"] != user:
        print("%s %s: local token belongs to %s, not %s; refusing to release another agent's claim."
              % (client, addr, claim["worker"], user))
        return False
    else:
        try:
            result = api.call("/v1/release", {"lease": claim["lease"], "worker": claim.get("worker") or user,
                                              "client": client, "addr": addr,
                                              "cooldown": cooldown}, timeout=20) or {}
        except RuntimeError as error:
            note = "server unreachable (%s); token kept for retry" % str(error)[:120]
            print("%s %s: %s" % (client, addr, note))
            if not keep_token_on_failure:
                claim_state.clear_claim(client, addr, claim["lease"])
            released = False
        else:
            if result.get("released"):
                released = True
                claim_state.clear_claim(client, addr, claim["lease"])
                print("%s %s: released the stored claim." % (client, addr))
            elif result.get("reason") in ("unknown or expired lease",):
                claim_state.clear_claim(client, addr, claim["lease"])
                note = "lease had already expired or was replaced"
                print("%s %s: %s; cleared the stale local token." % (client, addr, note))
            else:
                note = result.get("reason") or "server rejected release"
                print("%s %s: release refused (%s); token kept." % (client, addr, note))
    evidence = _local_evidence(client, addr)
    claim_state.add_cooldown(client, addr, evidence, cooldown, reason=reason or "skipped")
    print("%s %s: parked for %ds%s." % (client, addr, int(cooldown),
                                         (" (%s)" % reason) if reason else ""))
    return released


def cmd_release(a):
    """Release one stored claim and cooldown the target for future selections."""
    from roc import claims as claim_state, worker
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
    api = worker.Api(srv, a.token or s.get("token"))
    claim_state.purge_expired()
    _release_target(api, user, a.name, a.addr, reason=_work_reason(a, "manual skip"),
                    cooldown=_work_cooldown_seconds(a))
    return 0


def cmd_scout(a):
    """Read-only ranked opportunities: never claims or reserves a target."""
    from roc import scout, worker
    s = settings()
    srv = a.server or s.get("server")
    api = worker.Api(srv, a.token or s.get("token")) if srv else None
    try:
        if api is not None:
            rows, live, note = scout.candidates(
                api, a.name, limit=a.limit, profile=a.profile, max_size=a.max_size,
                min_score=a.min_score, max_score=a.max_score, include_claimed=a.include_claimed)
        else:
            rows = scout.from_local(a.name, limit=a.limit, profile=a.profile, max_size=a.max_size,
                                    min_score=a.min_score, max_score=a.max_score,
                                    include_claimed=a.include_claimed)
            live, note = False, "no server configured"
    except (ValueError, RuntimeError) as error:
        sys.exit(str(error))
    if a.json:
        print(json.dumps({"client": a.name, "live": live, "note": note, "candidates": rows}, indent=1))
        return
    print(scout.format_table(rows, live=live, note=note))


def cmd_packet(a):
    """Compact token-bounded evidence packet for one shortlisted target."""
    from roc import packet, worker
    s = settings()
    srv = a.server or s.get("server")
    api = worker.Api(srv, a.token or s.get("token")) if srv else None
    flags = (clients.load().get(a.name) or {}).get("flags")
    try:
        built = packet.build(a.name, a.addr, api=api, max_tokens=a.max_tokens,
                             include_diff=not a.no_diff, similar_limit=a.similar,
                             check=not a.no_diff, flags=flags)
    except (ValueError, RuntimeError, SystemExit) as error:
        sys.exit(str(error))
    if a.json:
        print(json.dumps(built, indent=1))
    else:
        print(packet.render(built))


def cmd_rebuild(a):
    from roc import rebuild
    from roc.rebuild_install import install
    if a.action == "install":
        install(ROOT, a.name, a.target)
        return
    if a.action == 'prepare':
        from roc.rebuild_install import prepare
        prepare(a.name)
        return
    if not (ROOT / "rebuild" / a.name / "modules").exists():
        install(ROOT, a.name)
    if a.action == "doctor":
        sys.exit(0 if rebuild.doctor(a.name) else 1)
    if a.action == "audit":
        rebuild.audit(a.name)
        return
    if a.action == "status":
        rebuild.status(a.name)
        return
    if a.action == "closure":
        rebuild.closure(a.name, a.target)
        return
    if a.action == "placed":
        rebuild.placed(a.name)
        return
    if a.action == "milestones":
        rebuild.milestones(a.name)
        return
    if a.action == "progress":
        rebuild.progress(a.name, notify=not getattr(a, "no_notify", False))
        return
    if not a.target:
        raise SystemExit("roc rebuild %s module NAME   (modules: %s)" % (a.name, ", ".join(
            sorted(p.stem for p in (ROOT / "rebuild" / a.name / "modules").glob("*.json")))))
    report = rebuild.build_module(a.name, a.target)
    sys.exit(0 if report["linked"] and report["test_exit"] == 0 else 1)



def cmd_integrate(a):
    from roc import integration
    integration.command(a)


def cmd_integrator(a):
    from roc import gui_worker, worker
    saved = worker.load_settings()
    config = {**gui_worker.DEFAULTS, "lease_mode": "native", "client": "2008-06",
              "user": a.user or saved.get("user", ""), "server": a.server or saved.get("server", ""),
              "model": a.model or saved.get("model", ""), "workers": "auto" if a.workers == "auto" else int(a.workers),
              "rounds": a.rounds, "max_tokens": a.output_budget, "thinking": a.thinking,
              "reasoning_effort": a.reasoning_effort, "cloud_allowed": a.allow_cloud or saved.get("cloud_allowed", False),
              "cloud_concurrency": "auto" if a.cloud_concurrency == "auto" else int(a.cloud_concurrency), "native_batch_files": a.batch_files,
              "native_compile_workers": a.compile_workers, "native_context": a.context,
              "max_cloud_requests": a.max_cloud_requests, "max_cloud_tokens": a.max_cloud_tokens,
              "max_cloud_cost": a.max_cloud_cost}
    config = gui_worker.validate(config)
    gui_worker.main({"config": config, "token": saved.get("token")}, receive_commands=False)


def cmd_work(a):
    """Manual-matching admin: list clients, scout, or select+claim the next function.

    Selection, ranking and claiming come from the server, never from possibly-stale
    local scores.json.  The lease token is persisted under work/state/ so
    ``--skip``/``roc release`` can return it even after a restart."""
    from roc import claims as claim_state, scout, worker, match
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
    api = worker.Api(srv, a.token or s.get("token"))

    if not a.name:
        st = api.call("/v1/status", timeout=30)
        print("Which client do you want me to work on?\n")
        for i, c in enumerate(sorted(st["clients"], key=lambda r: r["client"]), 1):
            total = c["functions"] or 1
            print("  %d. %-8s %6d / %-6d matched  (%5.1f%%)" %
                  (i, c["client"], c["matched"], c["functions"], 100.0 * c["matched"] / total))
        print("\nSelect a client, then run: roc work CLIENT")
        return

    claim_state.purge_expired()
    if getattr(a, "skip", None):
        addr = a.skip
        if addr == "last":
            latest = claim_state.latest_claim(a.name, include_expired=True)
            if not latest:
                sys.exit("No stored claim to skip for %s; give an address." % a.name)
            addr = latest["addr"]
        _release_target(api, user, a.name, addr, reason=_work_reason(a, "skipped"),
                        cooldown=_work_cooldown_seconds(a))
        return

    st = api.call("/v1/status", timeout=30)
    info = next((c for c in st["clients"] if c["client"] == a.name), None)
    if info is None:
        sys.exit("Unknown client %s. Registered: %s" %
                 (a.name, ", ".join(c["client"] for c in st["clients"])))

    try:
        rows, live, note = scout.candidates(
            api, a.name, limit=max(a.limit, 20), profile=a.profile, max_size=a.max_size,
            min_score=a.min_score, max_score=a.max_score, include_claimed=True,
            skip_cooling=not getattr(a, "include_cooling", False))
    except (ValueError, RuntimeError) as error:
        sys.exit("Could not load candidates: %s" % error)
    include_claimed = bool(getattr(a, "include_claimed", False))
    include_cooling = bool(getattr(a, "include_cooling", False))

    if not rows:
        print("No unmatched functions left for %s on the server." % a.name)
        print("This is NOT proof the client is exhausted: parked/cooling or claimed targets may remain.")
        print("Try:  roc work %s --include-cooling" % a.name)
        print("      roc work %s --min-score 0" % a.name)
        print("      roc scout %s --include-claimed" % a.name)
        return
    candidates = []
    for row in rows:
        if row.get("claimed") and not include_claimed:
            continue
        if (not include_cooling) and claim_state.cooling(a.name, row["addr"]):
            continue
        candidates.append(row)

    # If nothing is open, try revisiting parked targets whose evidence has changed
    # (e.g. the source was edited since parking) before declaring exhaustion.
    revisited = False
    if not candidates and not include_cooling:
        for row in rows:
            if row.get("claimed") and not include_claimed:
                continue
            if claim_state.cooling(a.name, row["addr"]):
                ev = _local_evidence(a.name, row["addr"])
                if not claim_state.cooling(a.name, row["addr"], evidence=ev):
                    candidates.append(row)
                    revisited = True
    if revisited:
        print("No open targets; revisiting parked target(s) with changed evidence.")
    if a.dry_run:
        print(scout.format_table(candidates[:a.limit], live=live, note=note))
        print("\nDry run: nothing claimed.")
        return
    if not candidates:
        cooling = claim_state.cooldowns(a.name)
        claimed_n = sum(1 for r in rows if r.get("claimed"))
        print("No claimable candidate right now: %d cooling/parked, %d claimed by other workers."
              % (len(cooling), claimed_n))
        print("This is NOT proof the client is exhausted. Parked targets can be revisited.")
        if cooling:
            print("Cooling targets (remaining seconds):")
            for cd in cooling[:10]:
                print("  %s  %ds  %s" % (cd["addr"], cd["remaining"], (cd.get("reason") or "")[:60]))
        print("Try:  roc work %s --include-cooling   (revisit parked targets)" % a.name)
        print("      roc work %s --include-cooling --include-claimed" % a.name)
        print("      roc work %s --min-score 0" % a.name)
        return

    chosen, claim = None, None
    for row in candidates[:max(1, a.limit)]:
        try:
            claim = api.call("/v1/claim", {"user": user, "worker": user,
                                           "client": a.name, "addr": row["addr"]}, timeout=20)
            chosen = row
            break
        except worker.ApiFailure as error:
            if error.category == "bad_request" and "another worker" in str(error):
                continue
            if "another worker" in str(error) or "already claimed" in str(error):
                continue
            print("Could not claim %s: %s" % (row["addr"], error))
            return
    if not chosen or not claim or not claim.get("lease"):
        print("Every candidate is claimed by another worker right now. Try again shortly.")
        return

    addr = chosen["addr"]
    claim_state.save_claim(a.name, addr, claim["lease"], worker=user,
                           expires=claim.get("expires"),
                           score=chosen.get("score"),
                           source_hash=_local_evidence(a.name, addr))
    path = ROOT / "src" / a.name / (addr + ".cpp")
    if not path.exists():
        try:
            best = api.call("/v1/source?client=%s&addr=%s" % (a.name, addr), timeout=20) or {}
        except worker.ApiFailure:
            best = {}
        if best.get("source"):
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(best["source"], encoding="utf-8")
        else:
            path = match.claim(a.name, addr)

    total = info["functions"] or 1
    print("Client:   %s  (%d / %d matched, %.2f%%)" %
          (a.name, info["matched"], info["functions"], 100.0 * info["matched"] / total))
    print("Function: %s" % addr)
    print("Evidence: %d%% score, %d B, %d attempt(s), source confidence %d%%" %
          (chosen.get("score", 0), chosen.get("size", 0), chosen.get("attempts", 0),
           chosen.get("source_confidence", 0)))
    if chosen.get("twin"):
        print("Twin:     %s (already matched) - try copying its source first" % chosen["twin"])
    print("Why:      %s -> %s" % (chosen.get("difficulty_reason", "unknown"),
                                  chosen.get("recommendation", "research")))
    if not live:
        print("Note:     local fallback (%s); percentage is not confirmed server progress." % note)
    print("Size:     %d bytes   Unit: %s   Attempts: %d" %
          (chosen.get("size", 0), chosen.get("unit") or "-", chosen.get("attempts", 0)))
    print("Claimed for %s (token stored in work/state). Edit: %s" % (user, path))
    print("Skip:     roc work %s --skip %s --reason TEXT   (or: roc release %s %s)" %
          (a.name, addr, a.name, addr))
    print("Next:     roc check %s %s   ->   roc submit %s %s" % (a.name, addr, a.name, addr))
    if getattr(a, "packet_tokens", 0) > 0:
        _write_work_packet(a.name, addr, chosen, a.packet_tokens, api)


def _write_work_packet(client, addr, chosen, tokens, api):
    """Hand the claimer its evidence at once: real residue hunks, failed ideas, siblings, and the
    two cheap traps (local source worse than the server's best; extent cut before its own code)."""
    import re
    from roc import match, packet as packet_mod
    try:
        built = packet_mod.build(client, addr, api=api, max_tokens=tokens)
    except (match.CompileError, SystemExit, OSError) as error:
        return print("Packet:   unavailable (%s)" % str(error)[:120])
    notes = []
    measured = (built.get("diff") or {}).get("score")
    if measured is not None and measured < (chosen.get("score") or 0):
        notes.append("WARNING: local source scores %d%% but the server best is %d%%: your src file is stale; "
                     "start from the server source (roc pull %s --force if you have no unsubmitted work)."
                     % (measured, chosen.get("score"), client))
    if re.search(r"^-j\w+ sym$", (built.get("diff") or {}).get("first_hunk") or "", re.M):
        notes.append("WARNING: the target jumps out of its own extent: likely a bounds problem, not source. "
                     "Log a BOUNDS LEAD with proof instead of editing C++.")
    text = "\n".join(notes + [packet_mod.render(built)])
    path = ROOT / "work" / client / "packets" / (addr + ".txt")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text + "\n", encoding="utf-8")
    for note in notes:
        print(note)
    print("Packet:   %s (~%d tokens): read it before editing" % (path, built.get("estimated_tokens", 0)))


def _journal_check(client, addr, path, score):
    """Agent scratch checks go to shared memory, so later sessions see functions tried without gain."""
    if not os.environ.get("ROC_AGENT"):
        return
    from datetime import datetime, timezone
    from roc import research
    research.append(ROOT / "work" / "agent-memory" / "attempts.jsonl",
                    dict(kind="agent_check", date=datetime.now(timezone.utc).isoformat(), client=client,
                         addresses=[addr], after=score, source_hash=research.digest(path.read_text(errors="replace"))))


def cmd_check(a):
    from roc import match
    match.DIFF_CONTEXT = getattr(a, "context", 99)
    folder = ROOT / "src" / a.name
    if a.file:  # scratch trial: score any file against one function, save nothing
        if not a.addr:
            sys.exit("--file needs an address")
        addr = a.addr.lower().replace("0x", "").zfill(8)
        if os.environ.get("ROC_AGENT"):
            _refuse_matched(a.name, addr)
        path = Path(a.file)
        if (path.parent / "task.json").exists():
            from roc import research
            row = research.trial(ROOT, a.name, addr, path, "assigned scratch check (automatic journal)")
            print("%s  %3d%%  %s  (assigned trial recorded; best candidate preserved)" %
                  (addr, row["after"], row.get("symbol") or "-"))
            print(row.get("diff") or row.get("error") or "Exact code/data match")
            return
        try:
            value, name, asm_diff, _ = match.check(a.name, addr, Path(a.file))
        except match.CompileError as error:
            _journal_check(a.name, addr, path, 0)
            sys.exit("%s  does not compile:\n%s" % (a.file, error))
        _journal_check(a.name, addr, path, value)
        print("%s  %3d%%  %s  (scratch, nothing saved)" % (addr, value, name or "-"))
        if value < 100:
            print("Assembly diff ('-' = target, '+' = yours):")
            print(asm_diff)
        return
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
        matched += value == 100
        print("%s  %3d%%  %s%s" % (src.stem, value, name or "-", "  MATCH" if value == 100 else "  (best %d%%)" % best))
        if value < 100 and len(srcs) == 1:
            print("Assembly diff ('-' = target, '+' = yours):")
            print(asm_diff)
    if len(srcs) > 1:
        print("%d / %d match." % (matched, len(srcs)))


def cmd_mutsearch(a):
    """Beam-search meaning-preserving rewrites (operand order, grouping, locals, float gates)
    against the target; a roc-lib stub mutates its unit. Writes an improved winner, never submits."""
    from roc import match, mutsearch
    addr = a.addr.lower().replace("0x", "").zfill(8)
    path = Path(a.file) if a.file else ROOT / "src" / a.name / (addr + ".cpp")
    if not path.exists():
        sys.exit("No file %s" % path)
    source = path.read_text(encoding="utf-8", errors="replace")
    try:
        best = mutsearch.search(a.name, addr, source, budget=a.budget, beam=a.beam, depth=a.depth,
                                jobs=a.jobs, log=print)
    except match.CompileError as error:
        sys.exit(str(error))
    print("%s %s: %d%% (%.3f) -> %d%% (%.3f, residue %d) in %d compiles%s" % (
        a.name, addr, best["start"], best["start_precise"], best["score"], best["precise"],
        best["residue"], best["compiles"],
        ("; " + " > ".join(best["path"])) if best["path"] else "; no improvement"))
    out = mutsearch.save(a.name, addr, source, best)
    if out:
        print("Wrote %s\nNext: roc submit %s %s --file %s" % (out, a.name, addr, out))
    elif best["exhausted"] and a.block_if_exhausted and best["compiles"] < 10:
        print("%s %s: only %d rewrites apply; too few to call it a blocker" % (a.name, addr, best["compiles"]))
    elif best["exhausted"] and a.block_if_exhausted:
        from roc import claims as claim_state
        reason = "blocked: mutsearch exhausted %d rewrites at depth %d, max %.3f" % (
            best["compiles"], a.depth, best["precise"])
        claim_state.add_cooldown(a.name, addr, _local_evidence(a.name, addr), BLOCK_SECONDS, reason=reason)
        print("%s %s: %s" % (a.name, addr, reason))


def cmd_twinpatch(a):
    """Copy an exact same-shape twin's source with the constants the two targets disagree on.
    Writes an improvement over the local score, never submits."""
    from roc import match, mutsearch, twinpatch
    addr = a.addr.lower().replace("0x", "").zfill(8)
    current = json.loads((ROOT / "work" / a.name / "scores.json").read_text()).get(addr, 0)
    chosen = [a.twin] if a.twin else twinpatch.twins(a.name, addr, limit=a.limit)
    if not chosen:
        sys.exit("%s %s: no exact same-size twin with shape >= 0.95" % (a.name, addr))
    best, original = None, None
    for twin in chosen:
        try:
            result, stub = twinpatch.patch(a.name, addr, twin, log=print)
        except (OSError, match.CompileError) as error:
            print("%s %s twin %s: %s" % (a.name, addr, twin, error))
            continue
        if result and (best is None or (result["score"], result["precise"]) > (best["score"], best["precise"])):
            best, original = result, stub
        if best and best["score"] == 100:
            break
    if not best:
        sys.exit("%s %s: no twin compiled" % (a.name, addr))
    print("%s %s: local %d%% -> %d%% (%.3f) via %s; constant pairs %s" % (
        a.name, addr, current, best["score"], best["precise"], " > ".join(best["path"]), best["pairs"] or "none"))
    if best["score"] > current:
        out = mutsearch.save(a.name, addr, original, best)
        print("Wrote %s\nNext: roc submit %s %s --file %s" % (out, a.name, addr, out))


def _precise_or(value, client, addr, text):
    """Untruncated score for ranking; the integer score when the target cannot be read."""
    from roc import match
    try:
        return round(match.precise_score(client, addr, text), 3)
    except (OSError, SystemExit, match.CompileError):
        return float(value or 0)


def cmd_check_batch(a):
    """Compile several candidate variants of one function in parallel and rank them.

    The agent loop is serial (edit -> check -> read diff -> edit), costing 3-8s per
    hypothesis. This command lets an agent generate 3-5 variants up front and test
    them all at once: the object cache deduplicates identical sources, and each
    compile runs concurrently (match.check_text already shares per-object locks).
    One file is one hypothesis. Identical source hashes compile once; compile
    failures are reported, never dropped. Use --json/--summary for machine use.
    """
    import hashlib
    import time
    from concurrent.futures import ThreadPoolExecutor, as_completed
    from roc import match, research
    match.DIFF_CONTEXT = getattr(a, "context", 99)
    if not a.files or not a.addr:
        sys.exit("usage: roc check-batch CLIENT ADDR FILE [FILE ...]")
    addr = a.addr.lower().replace("0x", "").zfill(8)
    if os.environ.get("ROC_AGENT"):
        _refuse_matched(a.name, addr)

    pairs, seen, duplicates = [], {}, []
    for label in a.files:
        path = Path(label)
        if not path.exists():
            sys.exit("No file %s" % label)
        text = path.read_text(encoding="utf-8", errors="replace")
        digest = hashlib.sha256(text.encode("utf-8", "replace")).hexdigest()
        if digest in seen:
            duplicates.append({"label": label, "duplicate_of": seen[digest], "source_hash": digest})
            continue
        seen[digest] = label
        pairs.append((label, text, digest))

    def score_one(item):
        label, text, digest = item
        started = time.monotonic()
        try:
            value, symbol, asm_diff, _ = match.check_text(a.name, addr, text)
            return {"label": label, "score": value, "symbol": symbol, "diff": asm_diff,
                    "precise": _precise_or(value, a.name, addr, text),
                    "error": None, "source_hash": digest,
                    "elapsed_seconds": round(time.monotonic() - started, 3),
                    "hypothesis": getattr(a, "hypothesis", None) or Path(label).stem}
        except match.CompileError as error:
            return {"label": label, "score": 0, "symbol": None, "diff": "",
                    "error": str(error), "source_hash": digest,
                    "elapsed_seconds": round(time.monotonic() - started, 3),
                    "hypothesis": getattr(a, "hypothesis", None) or Path(label).stem}
        except Exception as error:  # never hide an engine failure as a 0% candidate
            return {"label": label, "score": 0, "symbol": None, "diff": "",
                    "error": "%s: %s" % (type(error).__name__, error), "source_hash": digest,
                    "elapsed_seconds": round(time.monotonic() - started, 3),
                    "hypothesis": getattr(a, "hypothesis", None) or Path(label).stem}

    jobs = int(os.environ.get("ROC_JOBS") or 0) or min(8, os.cpu_count() or 4)
    results = []
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = [pool.submit(score_one, pair) for pair in pairs]
        for future in as_completed(futures):
            results.append(future.result())
    results.sort(key=lambda row: (-row["score"], -row.get("precise", 0)))
    best = results[0] if results else {"label": None, "score": 0, "diff": "", "error": None}

    journal = getattr(a, "journal", True) and os.environ.get("ROC_CHECK_BATCH_JOURNAL", "1") != "0"
    if journal and results:
        tokens = getattr(a, "tokens", None)
        for row in results:
            try:
                research.append(ROOT / "work" / "agent-memory" / "attempts.jsonl", {
                    "kind": "agent_check", "client": a.name, "addresses": [addr],
                    "model": getattr(a, "model", None) or os.environ.get("ROC_MODEL"),
                    "hypothesis": row["hypothesis"], "source_hash": row["source_hash"],
                    "after": row["score"],
                    "diff_class": ("compile_failure" if row["error"] else
                                   (row["symbol"] or "byte_diff")),
                    "result": ("compile_failed" if row["error"] else
                               "exact" if row["score"] == 100 else "no_gain"),
                    "tokens": tokens, "elapsed_seconds": row["elapsed_seconds"],
                    "receipt": None,
                })
            except (OSError, ValueError):
                pass

    if a.json:
        print(json.dumps({"client": a.name, "addr": addr, "results": results,
                          "duplicates": duplicates,
                          "winner": best["label"] if best.get("label") else None,
                          "best_score": best.get("score", 0),
                          "authoritative": False}, indent=1))
        return best.get("score", 0)
    if getattr(a, "summary", False):
        print("Batch %s %s · %d unique, %d duplicate(s):" % (a.name, addr, len(results), len(duplicates)))
        for row in results:
            print("  %3d%% %7.3f  %-28s %s" % (row["score"], row.get("precise", 0), Path(row["label"]).name,
                                         "COMPILE FAILED" if row["error"] else
                                         ("MATCH" if row["score"] == 100 else row["symbol"] or "-")))
        if duplicates:
            print("  duplicates: " + ", ".join("%s=%s" % (d["label"], d["duplicate_of"]) for d in duplicates))
        print("Note: local scores are candidates only; roc submit --file still server-verifies the winner.")
        return best.get("score", 0)

    print("Batch check %s %s · %d candidate(s), best first:" % (a.name, addr, len(results)))
    for row in results:
        note = "COMPILE FAILED: %s" % row["error"].splitlines()[0][:80] if row["error"] else \
               ("MATCH" if row["score"] == 100 else row["symbol"] or "-")
        print("  %3d%% %7.3f  %-8s  %s" % (row["score"], row.get("precise", 0), Path(row["label"]).name, note))
    if duplicates:
        print("Duplicate source hashes compiled once: %s" %
              ", ".join("%s=%s" % (d["label"], d["duplicate_of"]) for d in duplicates))
    if best.get("label") and best.get("score") == 100:
        print("Winner: %s is an exact match; submit it with:" % best["label"])
        print('  roc submit %s %s --file "%s"' % (a.name, addr, best["label"]))
    elif best.get("label") and best.get("score", 0) > 0:
        print("\nWinner %s residue ('-' = target, '+' = yours):" % best["label"])
        print(best.get("diff") or "Exact code/data match")
    return best.get("score", 0)


def cmd_classify(a):
    """Compile one source and emit conservative mismatch evidence as JSON."""
    from roc import match
    source = Path(a.source).read_text(errors="replace")
    score, symbol, diff, spans, diagnosis = match.check_text(
        a.client, a.addr, source, include_diagnosis=True)
    print(json.dumps({"client": a.client, "addr": a.addr, "score": score,
                      "symbol": symbol, "diagnosis": diagnosis}, sort_keys=True))


def cmd_auto(a):
    from roc import matchers, setup
    names = sorted(clients.load()) if a.name == "all" else [a.name]
    have = setup.compilers()
    for name in names:
        entry = clients.load()[name]
        if entry.get("compiler_build") not in have or clients.status(name, entry) != "ok":
            print("%s: skipped (needs the exe and its compiler)" % name)
            continue
        found = matchers.solve(name, a.max_size)
        print("%s: %d new files in src/%s/" % (name, matchers.save(name, found), name))


def cmd_xcopy(a):
    """Copy every stored match to the other clients that contain the same function.

    Cheap and worth re-running often: each new match is a candidate for every other
    client, so this multiplies whatever else is finding."""
    from roc import matchers
    names = None if a.name == "all" else [n.strip() for n in a.name.split(",") if n.strip()]
    reg = clients.load()
    for name in names or []:
        if name not in reg:
            sys.exit("%s is not registered. See:  roc client list" % name)
    result = matchers.run(targets=names, limit=a.limit, dry_run=a.dry_run,
                          cross_only=a.cross_only, min_size=a.min_size,
                          max_score=a.max_score)
    print("\nClient       new files   newly matched")
    files = scored = 0
    for name in sorted(result):
        new_files, new_matches = result[name]
        print("  %-8s %8d %14d" % (name, new_files, new_matches))
        files += new_files
        scored += new_matches
    print("  %-8s %8d %14d" % ("total", files, scored))
    if scored and not a.dry_run:
        from roc.reports import tool_digest
        tool_digest("xcopy", "**%d verified cross-client matches**" % scored,
                    [{"name": "New source files", "value": str(files), "inline": True},
                     {"name": "Clients", "value": ", ".join(sorted(result)), "inline": True}])


def cmd_shapes(a):
    from roc import fingerprint
    fingerprint.report([a.name], max_size=a.size, show=a.show, top=a.top)


def cmd_ref(a):
    """Resolve a client function to the 2016 Roblox source that probably produced it."""
    from roc import refsource
    if a.summarise:
        refsource.summarise(a.client)
        return
    if a.warm_large:
        print("cached %d target string(s)" % refsource.warm_large(a.client or "2008-06"))
        return
    if a.warm_lineage:
        print("cached lineage for %d target(s)" % refsource.warm_lineage(a.client or "2008-06"))
        return
    if a.addr:
        client = a.client or "2008-06"
        row = refsource.function_facts(client, a.addr)
        if not row:
            sys.exit("Unknown %s function %s" % (client, a.addr))
        for source in refsource.cross_client_sources(client, a.addr, limit=a.limit):
            print("exact-binary %s:%s %s" %
                  (source["client"], source["addr"], source.get("unit", "")))
        for source in refsource.shape_client_sources(client, a.addr, limit=a.limit):
            print("exact-shape %s:%s %s (%s%%)" %
                  (source["client"], source["addr"], source.get("unit", ""), source.get("score", 0)))
        for source in refsource.literal_sources(row.get("strings", []), limit=a.limit, log=print):
            print("%d %s %s" % (len(source["matches"]), source["path"], repr(source["matches"])))
        return
    if not a.unit:
        sys.exit("Give a unit name, --addr, or --summarise. See:  roc ref --help")
    refsource.report(a.unit, a.limit)


def cmd_libs(a):
    """Match open-source library code (zlib, libjpeg, libpng, Lua, G3D, boost, templates)."""
    from roc import libs
    names = list(libs.RECIPES) if a.names == ["all"] else a.names
    unknown = [n for n in names if n not in libs.RECIPES]
    if unknown:
        sys.exit("Unknown library: %s. Known: %s" % (", ".join(unknown), ", ".join(libs.RECIPES)))
    if a.no_fetch:
        local = [n for n in names if libs._case_path(libs.LIBS / libs.RECIPES[n]["src"]).exists()
                 or libs.bundle_has(libs.RECIPES[n]["src"]) or libs.RECIPES[n].get("generate")]
        missing = [n for n in names if n not in local]
        if missing:
            print("Skipped (vendor tree not local, --no-fetch): %s" % ", ".join(missing))
        names = local
        if not names:
            print("No recipe has its vendor tree locally; run without --no-fetch to download.")
            return
    targets = libs.default_targets() if a.client == "all" else [a.client]
    print(libs.run([n for n in names if libs.RECIPES[n].get("files")], targets))


def cmd_lib_fetch(a):
    """Download and unpack library sources (checked SHA-256) without compiling anything."""
    from roc import libs
    names = list(libs.RECIPES) if a.names == ["all"] else a.names
    unknown = [n for n in names if n not in libs.RECIPES]
    if unknown:
        sys.exit("Unknown library: %s. Known: %s" % (", ".join(unknown), ", ".join(libs.RECIPES)))
    for name in names:
        print("%s -> %s" % (name, libs.fetch(name)))


def cmd_similar(a):
    """Rank exact-matched functions whose instruction shape resembles an open one."""
    import difflib
    rows = {r["addr"]: r for r in map(json.loads, (ROOT / "work" / a.name / "functions.jsonl").read_text().splitlines() if (ROOT / "work" / a.name / "functions.jsonl").exists() else [])}
    addr = a.addr.lower().replace("0x", "").zfill(8)
    if addr not in rows:
        sys.exit("%s is not in work/%s/functions.jsonl (run: roc analyze %s)" % (addr, a.name, a.name))
    scores = json.loads((ROOT / "work" / a.name / "scores.json").read_text())
    want = rows[addr]
    shape = want.get("shape", "").split(" ; ")
    ranked = []
    for other, row in rows.items():
        if other == addr or scores.get(other) != 100 or abs(row["size"] - want["size"]) > want["size"] * a.band:
            continue
        ratio = difflib.SequenceMatcher(None, shape, row.get("shape", "").split(" ; "), autojunk=False).ratio()
        ranked.append((ratio, other, row["size"]))
    print("%s: %d bytes, shape: %s" % (addr, want["size"], want.get("shape", "")))
    for ratio, other, size in sorted(ranked, reverse=True)[:a.limit]:
        src = ROOT / "src" / a.name / (other + ".cpp")
        print("%s  %4d bytes  shape %.2f  %s" % (other, size, ratio, src.relative_to(ROOT).as_posix() if src.exists() else "(no local source: roc pull)"))


def cmd_lib_info(a):
    """Recipe version, source, flags and every recorded lesson/experiment that names it."""
    from roc import libs
    if a.name not in libs.RECIPES:
        sys.exit("Unknown library: %s. Known: %s" % (a.name, ", ".join(libs.RECIPES)))
    recipe = {k: v for k, v in libs.RECIPES[a.name].items() if k not in ("generate", "write", "sha256")}
    print(json.dumps(recipe, indent=2, default=str))
    needle = a.name.lower()
    for fname, key in (("lessons.json", None), ("recipes.json", "recipes")):
        data = json.loads((ROOT / "research" / fname).read_text())
        items = data.items() if isinstance(data, dict) else enumerate(data)
        for ident, item in items:
            if needle in json.dumps(item).lower():
                print("%s %s: %s" % (fname, item.get("id", ident) if isinstance(item, dict) else ident,
                                     (item.get("hypothesis") or item.get("change") or "")[:160]))


def cmd_libs_bundle(a):
    """One zip per library tree that cannot be downloaded (XTP, MFC, Scintilla, ...), shared via Drive."""
    from roc import libs
    if a.action == "pack":
        print("Packed into %s: %s" % (libs.BUNDLE_DIR, ", ".join(libs.bundle_pack())))
        print("Next: upload that folder to Drive (anyone with the link), then: roc libs-bundle index FOLDER_LINK")
    elif a.action == "index":
        if not a.value:
            sys.exit("Give the Drive folder link: roc libs-bundle index LINK")
        print("Recorded in research/libs-bundle.json (commit it): %s" % ", ".join(libs.bundle_index(a.value)))
    else:
        print("Unpacked into tools/libs: %s" % (", ".join(libs.bundle_fetch(a.value and a.value.split(","))) or "nothing new"))


def cmd_brute(a):
    """Portable, resumable compiler and authentic-template sweep."""
    a.action = "status" if a.status else "plan" if a.plan else "run"
    a.name, a.more = "portable-bruteforce-deep" if a.deep else "portable-bruteforce", []
    a.force, a.job_state = False, None
    cmd_research(a)
    if a.status:
        for client in sorted(clients.load()) if a.client == "all" else [a.client]:
            for stage in ("bruteforce-compiler-gates", "bruteforce-source-portfolios-deep" if a.deep else "bruteforce-source-portfolios"):
                folder = ROOT / "work" / "research" / stage
                path = (folder if client == "2008-06" else folder / client) / "progress.json"
                if path.exists():
                    print(path.read_text())


def cmd_research(a):
    """Named compiler-only research recipes (research/recipes.json)."""
    from roc import libs, research
    recipes = research.recipes()
    if a.action == "note":  # roc research note TITLE TEXT...
        print(json.dumps(research.note(a.name, " ".join(a.more)), ensure_ascii=False))
        return
    if a.action == "log":
        for row in research.log_entries(int(a.name or 10)):
            print("%s  %s" % (row["date"], row["title"]))
            print("    " + row["text"][:300].replace(chr(10), " "))
        return
    if a.action == "audit":
        for folder in [a.name] + (a.more or []):
            result = research.audit(folder)
            print(json.dumps({folder: {k: result[k] for k in ("unique_verified_exacts", "by_journal", "error_rows")}}, indent=2))
        return
    if a.action == "capture-units":
        added = libs.capture_units(a.name or "2008-06")
        print("Stored %d generated units in %s" % (sum(map(len, added.values())), libs.UNITS_FILE.relative_to(ROOT).as_posix()))
        return
    if a.action == "list" or not a.name:
        for name, spec in recipes.items():
            result = spec.get("result", {})
            print("%-28s %-6s %-9s %s" % (name, spec["op"], result.get("status") or
                  ("+%s new" % result["new_verified"] if "new_verified" in result else "untried"), spec.get("hypothesis", "")))
        return
    if a.name not in recipes:
        sys.exit("Unknown recipe %s. Run: roc research list" % a.name)
    selected = getattr(a, "client", None) or recipes[a.name].get("client", "2008-06")
    if selected != "all" and selected not in clients.load():
        sys.exit("Unknown selected research client: " + selected)
    folder = ROOT / "work" / "research-jobs" / a.name
    if selected != "2008-06":
        folder /= selected
    if a.action == "status":
        states = sorted(folder.glob("*.json"), key=lambda path: path.stat().st_mtime)
        print(json.dumps(research.job_status(states[-1])) if states else json.dumps({"state": "not_started"}))
        return
    print(json.dumps(research.plan(a.name), indent=2))
    if a.action == "plan":
        return
    if recipes[a.name].get("result", {}).get("status") == "rejected" and not a.force:
        sys.exit("Recipe %s is recorded as rejected: %s Use --force with new evidence." %
                 (a.name, recipes[a.name].get("next", "")))
    if a.background:
        import uuid
        try:
            with research.job_lock(folder / ".launch.lock"):
                existing = research.active_job(folder)
                if existing:
                    print(json.dumps({"already_running": True, **existing}))
                    return
                state = folder / (uuid.uuid4().hex + ".json")
                state.parent.mkdir(parents=True, exist_ok=True)
                log_path = state.with_suffix(".log")
                command = [sys.executable, "-u", str(ROOT / "roc.py"), "research", "run", a.name,
                           "--jobs", str(a.jobs), "--job-state", str(state), "--client", selected]
                if a.server:
                    command += ["--server", a.server]
                if a.limit:
                    command += ["--limit", str(a.limit)]
                if a.force:
                    command += ["--force"]
                if getattr(a, "campaign_id", None):
                    command += ["--campaign-id", a.campaign_id]
                state.write_text(json.dumps({"state": "starting", "launcher_pid": os.getpid(), "log": str(log_path)}))
                try:
                    with log_path.open("w", encoding="utf-8") as stream:
                        process = subprocess.Popen(command, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT,
                                                   stdin=subprocess.DEVNULL,
                                                   env={**os.environ, "PYTHONIOENCODING": "utf-8"},
                                                   creationflags=subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0)
                except OSError as error:
                    state.write_text(json.dumps({"state": "failed", "error": str(error)}))
                    raise
                state.with_suffix(".pid").write_text(str(process.pid))
                print(json.dumps({"pid": process.pid, "state_file": str(state), "log": str(log_path),
                                  "status": "roc research status " + a.name + " --client " + selected,
                                  "resume": "roc research run " + a.name + " --background --client " + selected}))
        except research.ResearchJobBusy as error:
            print(json.dumps({"already_running": True, "detail": str(error),
                              "status": "roc research status " + a.name}))
        return
    if a.job_state:
        state = Path(a.job_state)
        state.write_text(json.dumps({"state": "running", "pid": os.getpid(), "log": str(state.with_suffix(".log"))}))
    try:
        result = research.run(a.name, a.server, a.jobs, a.limit,
                              campaign_id=getattr(a, "campaign_id", None), client=selected)
    except BaseException as error:
        if a.job_state:
            state.write_text(json.dumps({"state": "failed", "error": str(error), "log": str(state.with_suffix(".log"))}))
        raise
    if a.job_state:
        state.write_text(json.dumps({"state": "done", "result": result, "log": str(state.with_suffix(".log"))}))


def cmd_donor(a):
    from roc import matchers
    matchers.build(matchers.default_targets() if a.client == "all" else [a.client])


def cmd_lint(a):
    from roc import analyze
    if any(k.startswith("error") for k in analyze.lint(a.client, show=a.show)):
        sys.exit(1)


def cmd_vtables(a):
    from roc import analyze
    analyze.vtable_report(a.client, top=a.top)


def cmd_ghidra(a):
    from roc import analyze
    path, count = analyze.ghidra(a.client)
    print("Wrote %s (%d functions). In Ghidra: Script Manager, add this folder, run it." % (path, count))


def cmd_lift(a):
    from roc import remill
    tools = remill.resolve_tools()
    if not tools["available"]:
        print(remill.not_available_message(tools))
        raise SystemExit(2)
    print("lifter: %s   verifier: %s" % (tools["exe_name"], tools["opt_name"]))
    print()
    summary, compact, paths = remill.lift_function(a.name, a.addr, getattr(a, "out", None), timeout=a.timeout)
    print(compact)
    print()
    print("client: %s  size: %d  function: %s" % (summary["client"], summary["size"], summary.get("function")))
    print("IR: %s" % paths["ll"])
    print("bitcode: %s" % paths["bc"])
    print("summary: %s" % paths["summary"])
    print("verified with LLVM 17 opt: %s" % ("yes" if summary["verified"] else "no"))
    if not summary["verified"]:
        print(summary.get("verify_error", "")[:500])
    if summary["returncode"]:
        print("remill return code: %d" % summary["returncode"])
        print((summary.get("stderr_tail") or "")[:800])


def cmd_rtti(a):
    """RTTI reverse-index: binary-proven template types (read the descriptor, never guess)."""
    from roc import rtti
    if a.addr:
        refs = rtti.function_refs(a.name, a.addr)
        if not refs:
            print("%s %s: no RTTI descriptor references." % (a.name, a.addr))
            return
        print("%s %s references %d RTTI type descriptor(s):" % (a.name, a.addr, len(refs)))
        for ref in refs:
            print("  offset %3d  %08x  %s" % (ref["offset"], ref["address"], ref["type"]))
            print("           pretty: %s" % rtti.pretty(ref["type"]))
        print("\nThese are the binary-proven type parameters. A `push <descriptor>` before")
        print("__RTDynamicCast states the exact template type the original source used.")
        return
    if a.open:
        rows = rtti.open_function_refs(a.name, limit=a.limit)
        rows.sort(key=lambda r: (-r["score"], -r["size"]))
        print("Open functions with RTTI descriptor refs: %d" % len(rows))
        for r in rows:
            types = "; ".join(rtti.pretty(x["type"])[:48] for x in r["refs"][:3])
            print("  %s %3d%% %4d bytes  %s" % (r["addr"], r["score"], r["size"], types))
        return
    index = rtti.descriptors(a.name)
    print("%d RTTI type descriptors in %s." % (len(index), a.name))
    for address in sorted(index)[:a.limit] if a.limit else sorted(index):
        print("  %08x  %s" % (address, index[address]))


def cmd_extents(a):
    """Near-misses whose recorded extent ends in padding: honest bounds candidates."""
    from roc import extents
    rows = extents.scan(a.name, a.min_score)
    if not rows:
        print("No padded-extent functions in the %d%%+ open band of %s." % (a.min_score, a.name))
        return
    print("Padded extents in %s (%d functions): real code ends before the padding." % (a.name, len(rows)))
    print("addr      score  size  pad  suggested  pattern")
    for r in rows:
        print("%s  %3d%%  %4d  %3d  %9d  %s  %s" % (r["addr"], r["score"], r["size"],
              r["padding"], r["suggested_size"], r["pattern"], r["unit"][:30]))
    print("\nCorrect sizes through work/%s/bounds.json (evidence-backed only); re-check after." % a.name)


def cmd_bruteforce(a):
    """Post-draft brute force: full compiler grid (incl /fp:fast) + family fanout."""
    from roc import bruteforce
    if a.addr or a.file:
        grand = bruteforce.run(a.name, addr=a.addr, file=a.file, full=not a.fast,
                               family=not a.no_family)
    elif a.near is not None:
        grand = bruteforce.run(a.name, near=a.near, full=not a.fast, family=not a.no_family)
    else:
        raise SystemExit("give ADDR, --file, or --near")
    print("Brute force done: %d grid wins, %d family hits." %
          (grand["grid_wins"], len(grand["family_wins"])))


def cmd_immediates(a):
    """Near-misses whose only residue is ONE wrong constant: the fix list."""
    from roc import repair_scan
    s = settings()
    rows = repair_scan.scan(a.name, a.min_score, a.max_score, server=s.get("server"), token=s.get("token"))
    if not rows:
        print("No single-immediate near-misses in the %d-%d%% band of %s." %
              (a.min_score, a.max_score, a.name))
        return
    print("Single-immediate residues in %s (%d functions):" % (a.name, len(rows)))
    print("Trace operand meaning before editing; stack/EH values need lifetime/ABI evidence, not padding.")
    for r in rows:
        f = r["fix"]
        print("  %s %3d%%  %s" % (r["addr"], r["score"], r["unit"][:40] if isinstance(r["unit"], str) else ""))
        print("       target: %-42s ours: %s" % (f["target"], f["ours"]))
        print("       observed target value: %s; verify a source-level correction with check-batch." % f["target_value"])


def cmd_versions(a):
    import re
    """Compile one function's source under every installed vendor-version recipe.

    Big library functions attributed to the wrong vendor version plateau at
    20-90% forever; the bytes of the right version are the evidence. This probe
    rewrites the `// roc-lib:` recipe across every installed version whose tree
    contains the same file and scores them all in parallel.
    """
    from concurrent.futures import ThreadPoolExecutor, as_completed
    from roc import libs, match
    src_path = ROOT / "src" / a.name / ("%s.cpp" % a.addr.lower().replace("0x", "").zfill(8))
    if not src_path.exists():
        sys.exit("No local source for %s. roc pull %s first." % (a.addr, a.name))
    text = src_path.read_text(encoding="utf-8", errors="replace")
    d = match.directives(text)
    if "lib" not in d:
        sys.exit("%s has no // roc-lib: recipe to probe." % a.addr)
    recipe, _, rel = d["lib"].partition(" ")
    if recipe not in libs.RECIPES:
        sys.exit("Unknown recipe %s." % recipe)
    # Every same-vendor recipe whose tree contains the same relative file:
    # version numbers in recipe names (ogre-1.4.5 vs ogre-1.4.9) have distinct
    # src roots, so match by name prefix and verify the file exists there.
    prefix = re.match(r"(.*?)-?\d[\d.]*(-dll)?$", recipe)
    vendor = prefix.group(1) if prefix else recipe
    candidates = []
    for name, r in libs.RECIPES.items():
        if name == recipe or not name.startswith(vendor):
            continue
        try:
            path = libs.LIBS / r.get("src", "") / rel
            if r.get("src") and (path.exists() or libs._case_path(path).exists()):
                candidates.append(name)
        except (OSError, ValueError):
            continue
    if not candidates:
        print("No other installed version of %s contains %s." % (recipe, rel))
        return

    def score_with(name):
        variant = re.sub(r"(?m)^//\s*roc-lib:.*$", "// roc-lib: %s %s" % (name, rel), text)
        try:
            value, symbol, _, _ = match.check_text(a.name, a.addr, variant)
            return name, value, symbol, None
        except match.CompileError as error:
            return name, 0, None, str(error).splitlines()[0][:80]

    print("Probing %s %s under %d vendor version(s)..." % (a.addr, recipe, len(candidates)))
    results = []
    with ThreadPoolExecutor(max_workers=min(8, len(candidates) or 1)) as pool:
        futures = [pool.submit(score_with, name) for name in candidates]
        for future in as_completed(futures):
            results.append(future.result())
    results.sort(key=lambda row: -row[1])
    for name, value, symbol, error in results:
        note = "COMPILE FAILED: %s" % error if error else symbol or "-"
        print("  %3d%%  %-16s  %s" % (value, name, note[:80]))


def cmd_mass(a):
    """Everything automatic: compiler runtime tagging, STL, all libraries, then auto shapes."""
    from roc import libs, matchers
    choice = getattr(a, "client_name", None) or a.client or "all"
    targets = libs.default_targets() if choice == "all" else [choice]
    def stage(message):
        if os.environ.get("ROC_GUI_EVENTS"):
            print("ROC_EVENT " + json.dumps({"event": "stage", "message": message}), flush=True)
    stage("Static libraries")
    matchers.staticlibs(targets)
    stage("STL")
    matchers.stl(targets)
    stage("Library recipes")
    libs.run([n for n, r in libs.RECIPES.items() if r.get("files")], targets)
    for name in targets:
        stage("Analyze " + name)
        main(["analyze", name])  # picks up the runtime tags
        stage("Auto-match " + name)
        main(["auto", name])


def cmd_flags(a):
    from roc import flags
    if a.sweep:
        flags.sweep(a.name, limit=a.limit)
    else:
        flags.tune(a.name)


def cmd_repair(a):
    """Run bounded compiler-backed source mutations over partial matches."""
    from datetime import date
    import json
    from roc import match, mutate
    root = Path(__file__).resolve().parent
    paths = sorted((root / "src" / a.name).glob("*.cpp"))
    if a.addresses:
        wanted = {x.lower().replace("0x", "").zfill(8) for x in a.addresses}
        paths = [p for p in paths if p.stem.lower() in wanted]
    if a.offset:
        paths = paths[a.offset:]
    if a.limit:
        paths = paths[:a.limit]
    from roc import research
    scores_path = root / "work" / a.name / "scores.json"
    saved_scores = json.loads(scores_path.read_text()) if scores_path.exists() else {}
    scores_changed = False
    report = []
    for path in paths:
        addr = path.stem
        source = path.read_text(errors="replace")
        try:
            before = saved_scores.get(addr)
            if before is None or a.refresh_all:
                before = match.check_text(a.name, addr, source)[0]
                if saved_scores.get(addr) != before:
                    saved_scores[addr] = before
                    scores_changed = True
            if before >= 100 or before < a.min_score:
                continue
            # Refresh score only for saved partials; avoids recompiling exact corpus.
            before = match.check_text(a.name, addr, source)[0]
            if saved_scores.get(addr) != before:
                saved_scores[addr] = before
                scores_changed = True
            if before < a.min_score:
                continue
            result = mutate.improve(a.name, addr, source, guided=True,
                                    guided_categories=a.categories,
                                    guided_fallback=not bool(a.categories),
                                    permute=a.permute)
        except (match.CompileError, SystemExit, KeyError):
            continue
        after, updated, tried = result
        mutations = list(result.mutations)
        if getattr(a, "chain", False) and after > before and after < 100:
            # One extra evidence refresh lets a safe two-step ABI repair chain
            # (e.g. convention then return propagation) finish without an
            # unbounded mutation loop.
            chained = mutate.improve(a.name, addr, updated, guided=True,
                                     guided_categories=a.categories,
                                     guided_fallback=not bool(a.categories),
                                     permute=False)
            tried += chained[2]
            mutations.extend(chained.mutations)
            if chained[0] > after:
                after, updated = chained[0], chained[1]
        report.append({"addr": addr, "before": before, "after": after,
                       "tried": tried,
                       "mutations": [{"category": m.get("category"),
                                      "score": m.get("score"),
                                      "compile_error": m.get("compile_error", False)}
                                     for m in mutations]})
        print("%-8s %d -> %d tried=%d" % (addr, before, after, tried), flush=True)
        trials = ", ".join("%s=%s" % (m.get("category"), m.get("score"))
                            for m in mutations)
        research.note("roc repair %s %s" % (a.name, addr), "%d -> %d, tried %d variants [%s]%s." %
                      (before, after, tried, trials, "; applied" if after > before and not a.dry_run else ""))
        if after > before and not a.dry_run:
            path.write_text(updated)
            match.save_score(a.name, addr, after)
            saved_scores[addr] = after
            scores_changed = True
    if scores_changed and not a.dry_run:
        scores_path.write_text(json.dumps(saved_scores, indent=0, sort_keys=True))
    improved = [row for row in report if row["after"] > row["before"]]
    if improved and not a.dry_run:
        from roc.reports import tool_digest
        lines = "\n".join("`%s` %d%% → **%d%%**" % (row["addr"], row["before"], row["after"])
                          for row in improved[:10])
        tool_digest("repair", "**%s**: %d source repair gain(s)\n%s" % (a.name, len(improved), lines),
                    [{"name": "Best score", "value": "%d%%" % max(row["after"] for row in improved),
                      "inline": True}])
    if a.json:
        print(json.dumps(report, sort_keys=True))
    if a.json_out:
        report_path = root / a.json_out
        report_path.parent.mkdir(parents=True, exist_ok=True)
        report_path.write_text(json.dumps(report, indent=2, sort_keys=True),
                               encoding="utf-8")


def cmd_config(a):
    from roc import draft, providers
    from roc.worker import clear_setting, save_settings, USER_RE
    if a.user and not USER_RE.match(a.user):
        sys.exit("Username must be 2-32 letters, digits, _ . -")
    if a.model and a.model != "default" and not draft.pick_model(a.model):
        if providers.is_cloud(a.model):
            _provider, _remote, config = providers.parse_model(a.model)
            sys.exit(providers.credential_hint(a.model))
        choices = draft.ollama_models()
        sys.exit("Model '%s' is not installed. Installed: %s" %
                 (a.model, ", ".join(choices) or "none (run: ollama pull <model>)"))
    if a.model == "default":
        clear_setting("model")
        a.model = None
    s = save_settings(user=a.user, server=a.server, token=a.token, model=a.model,
                      public_server=a.public_server, cloud_allowed=a.allow_cloud)
    import re
    secret = re.compile(r"token|secret|webhook|password|key", re.I)  # never echo credentials into agent transcripts
    print("Saved: " + ", ".join("%s=%s" % (k, "***" if secret.search(k) else v) for k, v in s.items()))


def cmd_agent(a):
    from roc import agent
    if a.automatic or a.plan:
        from roc import agent_auto
        if a.goal or a.interactive:
            sys.exit("Automatic mode uses ranked client batches; omit --goal/--interactive")
        selected_client = a.client or "2008-06"
        if a.plan:
            names = [selected_client] if selected_client != "all" else [name for name in clients.load()
                if (ROOT / "work" / name / "functions.jsonl").exists()]
            print(json.dumps(agent_auto.public_plan(agent_auto.portfolio(names, a.max_size if a.max_size is not None else 512,
                a.cli + ":" + (a.model or "default") + (":individual" if a.individual else ""), random_targets=True)), indent=2))
            return
        s = settings()
        srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
        user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
        return agent_auto.run(srv, user, a.token or os.environ.get("ROC_AGENT_SERVER_TOKEN") or s.get("token"), a.cli, a.model, a.workers,
            a.jobs or 24, a.max_size if a.max_size is not None else 512, a.minutes or 120, a.batch_size, a.batch_minutes, a.individual, client=selected_client,
            continuous=a.continuous)
    if a.interactive:
        return agent.interactive(a.cli, a.goal or "match open 2008-06 functions", a.model)
    if a.goal:
        goal = a.goal
        goal += ("\\nRemill evidence is available: run `roc lift CLIENT ADDR` and read "
                 "work/CLIENT/lifted/ADDR/ADDR.summary.txt` for a compact LLVM semantic packet. "
                 "Keep original MSVC compilation and `roc check` as the final truth.")
        if a.client:
            goal += "\nClient scope: %s." % a.client
        if a.server:
            goal += "\nUse server %s for project commands." % a.server
        if a.user:
            goal += "\nUse contributor username %s." % a.user
        s = settings()
        code = agent.run_goal(a.cli, goal, a.model, a.minutes or 120, continuous=a.continuous,
                              server=a.server or s.get("server"), token=a.token or os.environ.get("ROC_AGENT_SERVER_TOKEN") or s.get("token"),
                              user=a.user or s.get("user"), client=a.client or "2008-06")
        if code:
            raise SystemExit(code)
        return code
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
    agent.run(srv, user, a.token or s.get("token"), a.cli, a.model, a.client, a.jobs or 1, a.max_size if a.max_size is not None else 256, a.minutes or 120)


def _refuse_matched(client, addr):
    """Exit 3 when the server already has this function at 100%: another worker may have matched it."""
    from roc import worker
    s = settings()
    if not s.get("server") or not addr:
        return
    try:
        best = worker.Api(s["server"], s.get("token")).call(
            "/v1/source?client=%s&addr=%s" % (client, addr), timeout=10) or {}
    except (worker.ApiFailure, OSError, ValueError):
        return
    if best.get("score") == 100:
        print("%s is already matched (100%% on the server). Stop working on it; pick an unmatched target." % addr)
        sys.exit(3)


def cmd_agent_check(a):
    from roc import agent_auto
    _refuse_matched(a.name, a.addr)
    row = agent_auto.trial(a.name, a.addr, a.path, a.hypothesis)
    print("%s %d%% %s" % (a.addr, row["after"], row["outcome"]))
    print(row.get("diff") or row.get("error") or "Exact code/data match")


def cmd_agent_check_batch(a):
    """Check independent assigned targets in one process, keeping trial journals."""
    import re
    from concurrent.futures import ThreadPoolExecutor
    from roc import agent_auto
    paths = [Path(path) for path in a.paths]
    addresses = [path.stem for path in paths]
    if any(not re.fullmatch(r"[0-9a-f]{8}", addr) for addr in addresses):
        sys.exit("Each source must be named with its eight-digit lowercase target address")
    if len(set(addresses)) != len(addresses):
        sys.exit("Batch requires distinct targets; same-target variants use check-batch")
    with ThreadPoolExecutor(max_workers=min(8, len(paths))) as pool:
        # Finish server checks before changing any journals or best sources.
        list(pool.map(lambda addr: _refuse_matched(a.name, addr), addresses))
        rows = list(pool.map(lambda path: agent_auto.trial(
            a.name, path.stem, path, a.hypothesis), paths))
    if a.json:
        print(json.dumps(rows))
        return
    for addr, row in zip(addresses, rows):
        print("%s %d%% %s" % (addr, row["after"], row["outcome"]))
        if not a.summary:
            print(row.get("diff") or row.get("error") or "Exact code/data match")


def cmd_agent_context(a):
    """Read source, target instructions and recent rejected trials in one tool trip."""
    from roc import match, research
    rows = []
    for name in a.paths:
        path = Path(name).resolve()
        addr = _addr(path.stem)
        code, relocs, target = match.target(a.name, addr)
        source = path.read_text(encoding="utf-8")
        task_path = path.parent / "task.json"
        task = json.loads(task_path.read_text(encoding="utf-8")) if task_path.exists() else {}
        if task and (task["client"] != a.name or task["addr"] != addr):
            sys.exit("Source does not belong to this assigned target")
        journal = path.parent if task else ROOT / "work" / "agent-checks" / a.name / addr
        trials = research.journal_records(journal / "trials.jsonl")[-5:]
        best_path = journal / "best.cpp"
        best_source = best_path.read_text(encoding="utf-8") if best_path.exists() else source
        rows.append(dict(client=a.name, addr=addr, file=str(path), source=source,
            source_hash=research.digest(source), task=task, best_source=best_source if best_source != source else None,
            target={key: target[key] for key in ("unit", "size", "kind", "strings", "imports", "callers", "callees") if key in target},
            target_asm=match.disasm(code, int(addr, 16)),
            recent_trials=[{key: trial[key] for key in ("source_hash", "hypothesis", "before", "after", "outcome", "error") if key in trial}
                           for trial in trials]))
    print(json.dumps(rows))


def cmd_agent_block(a):
    from roc import agent_recovery
    path = Path(a.path).resolve()
    task = json.loads((path.parent / "task.json").read_text(encoding="utf-8"))
    if task["client"] != a.name or task["addr"] != _addr(a.addr):
        sys.exit("Source does not belong to this assigned target")
    row = agent_recovery.block(ROOT, path, a.reason)
    print("%s blocked: %s" % (task["addr"], row["missing_evidence"]))


def cmd_agent_metrics(a):
    from roc import agent_recovery
    if not 1 <= a.limit <= 1000:
        sys.exit("--limit must be between 1 and 1000")
    print(json.dumps(agent_recovery.report(ROOT, a.limit), indent=2))


def cmd_submit(a):
    from roc import worker
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
    names = sorted(clients.load()) if a.name == "all" else [a.name]
    if getattr(a, "file", None) and (a.name == "all" or len(a.addr) != 1):
        sys.exit("--file requires one client and one address")
    for name in names:
        if not getattr(a, "file", None) and not (ROOT / "src" / name).is_dir():
            continue
        try:
            worker.submit_files(srv, user, name, a.addr or None, a.token or s.get("token"),
                                file=getattr(a, "file", None), model=getattr(a, "model", None))
        except worker.ApiFailure as error:
            print("%s: submit failed: %s" % (name, error))


def cmd_pull(a):
    from roc import worker
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    names = sorted(clients.load()) if a.name == "all" else [a.name]
    for name in names:
        worker.pull_files(srv, name, a.token or s.get("token"), a.force)
    from roc import libs
    libs.fetch_units()  # agent-written library units that pulled sources point at


def cmd_cluster(a):
    module = need_module("cluster", "The trusted cluster")
    if a.action == "setup":
        if not a.nodes:
            raise RuntimeError("Use --nodes 127.0.0.1 for one PC, or three private host addresses")
        path = module.generate(a.directory, a.nodes.split(","), a.db, a.broker, a.local_pilot)
        print("Cluster setup: %s\nRun node-N/start.cmd, or: roc cluster start --config %s/node-1/node.json" % (path, path))
    elif a.action == "start":
        if not a.config:
            raise RuntimeError("Use --config work/cluster/node-1/node.json")
        module.start(a.config)
    else:
        from roc.worker import Api
        config = need_module("cluster", "The trusted cluster").load_config(a.config)
        api = Api(",".join(config["servers"]), config["admin_token"])
        if a.action == "invite":
            if not a.name or not a.output:
                raise RuntimeError("Use --name PERSON --output work/PERSON-cpu.json")
            output = Path(a.output)
            if output.exists():
                raise RuntimeError("Output already exists; choose a new private config file")
            import hashlib, secrets
            token = secrets.token_hex(24)
            api.call("/v2/cpu/contributor", {"id": a.name, "token_hash": hashlib.sha256(token.encode()).hexdigest()})
            output.parent.mkdir(parents=True, exist_ok=True)
            output.write_text(json.dumps({"servers": config["servers"], "worker_token": token,
                                         "worker": a.name, "cpu_enabled": False, "cpu_slots": 1}, indent=2))
            if os.name != "nt":
                output.chmod(0o600)
            print("CPU contributor config: %s" % output.resolve())
        elif a.action == "revoke":
            if not a.name:
                raise RuntimeError("Use --name PERSON")
            print(json.dumps(api.call("/v2/cpu/revoke", {"id": a.name})))
        elif a.action == "enqueue":
            if not a.job:
                raise RuntimeError("Use --job JSON containing client, source, addrs, user and model")
            print(json.dumps(api.call("/v2/cpu/enqueue", json.loads(Path(a.job).read_text()))))
        elif a.action == "validate":
            if not a.id:
                raise RuntimeError("Use --id JOB_ID")
            print(json.dumps(api.call("/v2/cpu/validate", {"id": a.id})))
        elif a.action in ("cpu-pause", "cpu-resume", "cpu-off", "cpu-on"):
            if not a.name:
                raise RuntimeError("Use --name CONTRIBUTOR")
            print(json.dumps(api.call("/v2/cpu/control", {"worker": a.name, "action": a.action[4:]})))
        elif a.action in ("job-pause", "job-resume"):
            if not a.id:
                raise RuntimeError("Use --id JOB_ID")
            print(json.dumps(api.call("/v2/cpu/job-control", {"id": a.id, "action": a.action[4:]})))
        else:
            from roc.tasks import print_status
            try:
                while True:
                    print_status(api.call("/v2/cpu/dashboard"))
                    if not a.watch:
                        break
                    import time
                    time.sleep(5)
            except KeyboardInterrupt:
                pass
        api.close()


def cmd_cpu_worker(a):
    from roc import tasks
    if a.disable:
        from roc import tasks
        config = json.loads(Path(a.config).read_text())
        config["cpu_enabled"] = False
        tasks.write_text(a.config, json.dumps(config, indent=2))
        return print("CPU contribution disabled; running process finishes current job, then pauses.")
    tasks.run(a.config, a.enable, a.jobs)


def cmd_tasks(a):
    from roc import tasks
    if a.action != "status":
        tasks.control(a.id or "", a.action)
        return print("Control saved; applies between targets / compiler calls.")
    for row in tasks.tasks():
        print("%s · %s · %s · owner %s · %s/PID %s · %s targets inspected" % (
            row["id"], row["command"], row["status"], row["owner"], row["pc"], row["pid"], row["inspected"]))
        print("  %s · %s" % (row["stage"], row["flags"]))


def cmd_host(a):
    """The canonical group-server host: server with tunnel and publishing, restarted 30 s
    after any exit. Restart = stop the child python process; this loop starts it again."""
    import time
    while True:
        code = subprocess.call([sys.executable, str(ROOT / "roc.py"), "server", "--tunnel", "--publish"], cwd=ROOT)
        print("Server stopped (exit %s). Restarting in 30 seconds (Ctrl+C to quit)..." % code, flush=True)
        time.sleep(30)


def cmd_update(a):
    from roc import setup
    print(setup.update())


def cmd_uninstall(a):
    from roc import setup
    sys.exit(setup.run_uninstall(assume_yes=a.yes))


def cmd_server(a):
    server = need_module("server", "The group server")
    if getattr(a, "publisher_only", False):
        server.run_publisher(a.publish_every, getattr(a, "publisher_parent", None))
        return
    if a.startup:
        if os.name != "nt":
            sys.exit("--startup is Windows-only. On Linux, run the server from a systemd user "
                     "unit or cron instead, for example:\n"
                     "  ExecStart=%s %s server --port %d" % (sys.executable, ROOT / "roc.py", a.port))
        startup = Path(os.environ["APPDATA"]) / r"Microsoft\Windows\Start Menu\Programs\Startup" / "RoConstruct server.cmd"
        startup.write_text('@start "RoConstruct server" /min "%s" host' % (ROOT / "roc.cmd"))
        return print("The server will start when you log in: %s" % startup)
    httpd = server.serve(a.host, a.port, token=a.token, lease_seconds=a.lease,
                         discord_webhook=a.discord_webhook or settings().get("discord_webhook"))
    public = a.public_server or settings().get("public_server")
    primary = public
    tunnel = None
    if a.tunnel:  # Keep Cloudflare available behind an optional fixed primary address.
        try:
            public, tunnel = server.start_tunnel(a.port)
        except SystemExit as error:  # e.g. Cloudflare 429: keep serving locally, publish_loop retries with backoff
            print("Tunnel unavailable at start: %s" % error)
            tunnel = type("DeadTunnel", (), {"poll": lambda self: 1})()
            public = public or "pending"
    if a.publish:
        import threading
        threading.Thread(target=server.publish_loop, args=(httpd.store, public, a.publish_every),
                         kwargs={"tunnel": tunnel, "port": a.port, "primary": primary}, daemon=True).start()
    elif tunnel is not None:
        import threading
        threading.Thread(target=server.publish_loop, args=(httpd.store, None, a.publish_every),
                         kwargs={"tunnel": tunnel, "port": a.port, "publish": False}, daemon=True).start()
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("Server stopped.")


def cmd_worker(a):
    from roc import setup
    if not a.no_update:
        print("Checking for updates: %s" % setup.try_update())
    from roc import draft, providers, worker
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server URL or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user NAME or: roc config --user NAME")
    if a.client and a.client.lower() == "all":
        a.client = None
    if a.model and a.model != "default" and not draft.pick_model(a.model):
        if providers.is_cloud(a.model):
            _provider, _remote, config = providers.parse_model(a.model)
            sys.exit(providers.credential_hint(a.model))
        sys.exit("Model '%s' is not installed. See: roc model" % a.model)
    if a.model == "default":
        worker.clear_setting("model")
        a.model = None
        s.pop("model", None)
    explicit_rounds = a.rounds is not None
    a.rounds = a.rounds if explicit_rounds else 4
    if a.rounds != "auto" and not 1 <= a.rounds <= 100:
        raise SystemExit("--rounds must be auto or 1-100")
    a.max_size = a.max_size if a.max_size is not None else (512 if a.preset in ("auto", "automatic") else 256)
    if a.preset in ("auto", "automatic"):
        if not explicit_rounds:
            a.rounds = "auto"
        a.no_revng = True
        a.workers = a.workers or "auto"
        a.order = a.order or "random"
    elif a.preset == "fast":
        a.rounds, a.max_size, a.no_revng = min(4 if a.rounds == "auto" else a.rounds, 2), min(a.max_size, 96), True
    elif a.preset == "deep":
        a.rounds, a.max_size = max(4 if a.rounds == "auto" else a.rounds, 6), 0
    if a.min_score is not None and not 0 <= a.min_score <= 100:
        raise SystemExit("--min-score must be 0-100")
    if a.max_score is not None and not 0 <= a.max_score <= 100:
        raise SystemExit("--max-score must be 0-100")
    if a.min_score is not None and a.max_score is not None and a.min_score > a.max_score:
        raise SystemExit("--min-score cannot exceed --max-score")
    # Deterministic repair must never inherit a saved cloud model.
    chosen = None if a.source_only else (a.model or s.get("model"))
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
            raise SystemExit(providers.credential_hint(a.cloud_escalate))
    budget = providers.CloudBudget(a.max_cloud_requests, a.max_cloud_tokens, a.max_cloud_cost)
    gate = providers.CloudGate(a.cloud_concurrency) if a.cloud_concurrency is not None else None
    if a.output_budget is None:
        a.output_budget = "auto" if a.preset in ("auto", "automatic") else 2048
    if a.output_budget != "auto" and not 128 <= a.output_budget <= 32768:
        raise SystemExit("--output-budget must be auto or 128-32768")
    if a.cloud_min_size is None:
        a.cloud_min_size = 0 if a.preset in ("auto", "automatic") else 97
    if a.cloud_fallback:
        if providers.is_cloud(a.cloud_fallback):
            if not cloud_allowed:
                raise SystemExit("Cloud fallback needs --allow-cloud")
            if not providers.available(a.cloud_fallback):
                _provider, _remote, config = providers.parse_model(a.cloud_fallback)
                raise SystemExit(providers.credential_hint(a.cloud_fallback))
        elif not draft.pick_model(a.cloud_fallback):
            raise SystemExit("Cloud fallback model is not installed: %s" % a.cloud_fallback)
    if getattr(a, "prompt_style", None) is None:
        a.prompt_style = "lean"
    order = a.order or "random"
    if order not in ("auto", "best", "matched", "unmatched", "easiest", "random"):
        sys.exit("--order must be one of: auto, best, matched, unmatched, easiest, random")
    family_id = a.family_id or (worker.family_from_example(a.family_example)
                                if a.family_example else None)
    if a.family_example and not family_id:
        raise SystemExit("Unknown family example; use CLIENT:ADDRESS")
    targets = None
    if a.addr:
        if not a.client:
            raise SystemExit("--addr needs --client CLIENT")
        targets = [{"client": a.client, "addr": addr.lower().removeprefix("0x")} for addr in a.addr]
        if any(len(row["addr"]) != 8 or any(c not in "0123456789abcdef" for c in row["addr"]) for row in targets):
            raise SystemExit("--addr must be an 8-digit hex address")
    if family_id and a.client:
        ready = worker.register_family_targets(srv, a.token or s.get("token"), a.client, family_id)
        if ready:
            print("Family %s ready: %d sibling targets" % (family_id, ready))
    if a.dry_run:
        info = worker.Api(srv, a.token or s.get("token")).call("/v1/info")
        if a.client:
            info["clients"] = {k: v for k, v in info["clients"].items() if k == a.client}
        have = worker.usable_clients(info)
        print("Worker preview: user=%s model=%s clients=%s rounds=%s max-size=%d Rev.ng=%s workers=%s output-budget=%s order=%s" %
              (user, draft.pick_model(chosen) or "none", ", ".join(have) or "none",
               a.rounds, a.max_size, "off" if a.no_revng else "auto", a.workers, a.output_budget, order))
        return
    if a.lease_mode == "unit" and not a.unit:
        raise SystemExit("Unit lease needs --unit NAME")
    worker.save_settings(user=user, server=srv, model=a.model, order=order)
    worker.run_concurrent(srv, user, a.token or s.get("token"), chosen, a.rounds, a.max_size,
                          not a.no_revng, max_jobs=a.jobs, workers=a.workers or "1", source_only=a.source_only,
                          only=[a.client] if a.client else None, strategy=a.strategy,
                          cloud_allowed=cloud_allowed, cloud_budget=budget, cloud_gate=gate,
                          diverse_candidates=a.diverse_candidates, cloud_min_size=a.cloud_min_size,
                          cloud_fallback=a.cloud_fallback, seed=a.seed,
                          cloud_escalate=a.cloud_escalate, cloud_escalate_after=a.cloud_escalate_after,
                          thinking=a.thinking, reasoning_effort=a.reasoning_effort,
                          max_tokens=a.output_budget, guided_mutations=a.guided_mutations,
                          order=order, family_exemplars=a.family_exemplars,
                          lease_mode=a.lease_mode,
                          family_id=family_id, unit_name=a.unit, targets=targets,
                          near_repair=a.near_repair, min_score=a.min_score, max_score=a.max_score,
                          abi_only=a.abi_only)


def cmd_provider(a):
    from roc import providers
    if a.sub == "list":
        for name, config in sorted(providers.providers().items()):
            if name == "chatgpt":
                print("chatgpt      ChatGPT plan       %s (%s)" % (config["base_url"],
                      "signed in" if providers.provider_ready(name) else "run roc chatgpt login"))
                continue
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
            if name == "chatgpt":
                print("  %d) ChatGPT plan (Continue with ChatGPT; no API key)" % index)
                continue
            state = "set" if providers.key_available(config["key_env"]) else "missing"
            print("  %d) %s (%s: %s)" % (index, name, config["key_env"], state))
        choice = input("Choose provider name or number: ").strip().lower()
        if choice.isdigit() and 1 <= int(choice) <= len(names):
            choice = names[int(choice) - 1]
        if choice not in configs:
            raise SystemExit("Unknown provider: %s" % choice)
        if choice == "chatgpt":
            return cmd_chatgpt(argparse.Namespace(sub="login", account=None, new=False, model=None))
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


def cmd_chatgpt(a):
    from roc import chatgpt, worker
    if a.sub == "login":
        try:
            chatgpt._dependencies()
        except chatgpt.ProviderError:  # first use: install the optional sign-in packages
            print("Installing ChatGPT sign-in support...")
            subprocess.check_call([sys.executable, "-m", "pip", "install", "--user", "-q", "--disable-pip-version-check",
                                   "-r", str(ROOT / "packaging" / "requirements-chatgpt.txt")])
        account = chatgpt.login(client_id=a.account, new=a.new)
        print("Signed in: %s [%s]" % (account["label"], account["client_id"]))
        choices = chatgpt.models()
        for index, row in enumerate(choices, 1):
            print("  %d) %s (%s)" % (index, row["display_name"], row["slug"]))
        picked = a.model or input("ChatGPT model [1]: ").strip() or "1"
        if picked.isdigit() and 1 <= int(picked) <= len(choices):
            picked = choices[int(picked) - 1]["slug"]
        if picked not in [row["slug"] for row in choices]:
            raise SystemExit("Choose a model from the signed-in account's catalog.")
        worker.save_settings(model="chatgpt:" + picked, cloud_allowed=True,
                             worker_workers=1, worker_workers_model="chatgpt:" + picked)
        print("Using ChatGPT plan: %s. Start with roc launch or the website's Help out link." % picked)
        print("Shared plan limits apply. Manage limits and credit permission: " + chatgpt.USAGE_URL)
    elif a.sub in ("status", "accounts"):
        data = chatgpt.status()
        for client_id, account in data["accounts"].items():
            print("%s %s [%s]" % ("*" if data.get("active") == client_id else " ", account["label"], client_id))
        print("ChatGPT plan: %s" % ("ready" if chatgpt.ready() else "sign in with roc chatgpt login"))
        print("Manage usage: " + chatgpt.USAGE_URL)
    elif a.sub == "models":
        for row in chatgpt.models():
            print("chatgpt:%s  %s" % (row["slug"], row["display_name"]))
    elif a.sub == "use":
        chatgpt.use(a.account)
        choices = chatgpt.models()
        worker.save_settings(model="chatgpt:" + choices[0]["slug"], cloud_allowed=True)
        print("Active ChatGPT registration: " + a.account)
    elif a.sub == "logout":
        chatgpt.logout(a.account)
        print("ChatGPT signed out. Saved registration is retained for your next sign-in.")


def cmd_model_stats(a):
    from roc import telemetry
    rows = telemetry.model_stats()
    if not rows:
        print("No worker telemetry yet: run a worker first.")
        return
    print("Model                                  jobs matched improved rate gain avg-sec gpu-min/match")
    for row in rows:
        print("%-38s %4d %7d %8d %4.1f%% %4d %7.1f %14.1f" %
              (row["model"], row["jobs"], row["matched"], row["improved"], row["match_rate"],
               row["score_gain"], row["avg_seconds"], row["gpu_minutes_per_match"]))


def cmd_family_stats(a):
    from roc import telemetry
    row = telemetry.family_stats()
    if not row["jobs"]:
        print("No family telemetry yet.")
        return
    print("Family jobs=%d exact=%d rate=%.2f%% clients=%d families=%d exemplars=%d propagated=%d tokens=%d cost=$%.6f exact/$=%s exact/100k=%s" %
          (row["jobs"], row["matched"], row["match_rate"], row["clients"], row["families"],
           row["exemplar_jobs"], row["propagated"], row["tokens"], row["cost"],
           "unknown" if row["exact_per_dollar"] is None else row["exact_per_dollar"],
           "unknown" if row["exact_per_100k_tokens"] is None else row["exact_per_100k_tokens"]))


def cmd_failures(a):
    from roc import telemetry
    if a.promote:
        rules = telemetry.promote_failures()
        print("Promoted %d recurring failure rule suggestion(s) to %s" % (len(rules), telemetry.RULES))
        return
    if a.addr:
        _show_rejected_variants(a.addr, a.client)
        return
    rows = telemetry.failure_clusters()
    if not rows:
        print("No worker failures recorded.")
        return
    print("Failure cluster                                      count")
    for row in rows:
        print("%-52s %5d" % (row["reason"], row["count"]))


def _show_rejected_variants(addr, client):
    """Per-address rejected-variant lookup so agents skip recorded rejections."""
    from roc import research
    path = ROOT / "work" / "agent-memory" / "attempts.jsonl"
    if not path.exists():
        print("No attempts recorded yet.")
        return
    addr = addr.lower().replace("0x", "").zfill(8)
    seen_hashes = {}
    rejected = []
    for row in research.journal_records(path):  # handles concatenated objects
        if not isinstance(row, dict) or row.get("client") != client:
            continue
        if addr not in (row.get("addresses") or []):
            continue
        outcome = row.get("outcome") or ""
        source_hash = row.get("source_hash") or row.get("after_hash") or ""
        if outcome in ("no_gain", "compile_failed", "rejected", "rolled_back"):
            key = (source_hash, row.get("change") or row.get("hypothesis") or "")
            if key in seen_hashes:
                continue
            seen_hashes[key] = True
            rejected.append(row)
    if not rejected:
        print("No rejected variants recorded for %s %s." % (client, addr))
        return
    print("Rejected variants for %s %s (%d):" % (client, addr, len(rejected)))
    for row in rejected:
        change = (row.get("change") or row.get("hypothesis") or "?")[:80]
        score = " -> %s" % row["after"] if row.get("after") is not None else ""
        print("  [%s]%s %s" % (row.get("outcome", "?"), score, change))


def cmd_benchmark_models(a):
    from roc import telemetry, draft, providers, worker
    if a.progress:
        rows = telemetry.corpus_stats(telemetry.build_hidden(a.limit))
        total = sum(r["jobs"] for r in rows)
        print("Benchmark records: %d (resume with --local-run --full --resume)" % total)
        for row in rows:
            print("  %s %-6s source=%s jobs=%d matches=%d gain=%d" %
                  (row["model"], row["bucket"], row["source_present"], row["jobs"],
                   row["matched"], row["score_gain"]))
        return
    if a.ab_compare:
        print(telemetry.format_compare(telemetry.compare_sessions(*a.ab_compare)))
        return
    if a.ab:
        hidden = telemetry.build_hidden(a.limit)
        groups = telemetry.ab_split(hidden)
        for arm in ("A", "B"):
            print("Arm %s: %d fixed targets" % (arm, len(groups[arm])))
            for row in groups[arm]:
                print("  %-8s %s %s %-6s %s" % (row["client"], row["addr"], row["target_hash"],
                                                 row["bucket"], row.get("unit") or ""))
        print("Nothing was run. Give each arm its own --session, then report with: "
              "roc benchmark-models --ab-compare SESSION_A SESSION_B")
        return
    if a.hidden:
        hidden = telemetry.build_hidden(a.limit)
        print("Hidden benchmark corpus: %d targets (%s)" % (len(hidden), telemetry.HIDDEN))
        return
    if a.local_run or a.model:
        hidden = telemetry.build_hidden(a.limit)
        models = a.model or [m for m in draft.ollama_models() if "qwen2.5-coder" in m]
        if not models:
            raise SystemExit("no qwen2.5-coder model installed")
        for model in models:
            if providers.is_cloud(model):
                if not a.allow_cloud:
                    raise SystemExit("Cloud benchmark sends prompts outside this PC. Pass --allow-cloud.")
                if not providers.available(model):
                    _provider, _remote, config = providers.parse_model(model)
                    raise SystemExit(providers.credential_hint(model))
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
            telemetry.run_local(corpus, models, rounds=a.rounds, resume=a.resume, session=session,
                                strategies=strategies, provider_options={"allow_cloud": a.allow_cloud,
                                "budget": budget, "gate": gate, "seed": a.seed,
                                "diverse_candidates": a.diverse_candidates,
                                "thinking": a.thinking, "reasoning_effort": a.reasoning_effort})
        return
    if a.baseline:
        hidden = telemetry.build_hidden(a.limit)
        current = telemetry.corpus_stats(hidden)
        path = ROOT / "work" / "benchmark-baseline.json"
        if path.exists():
            print("Previous baseline:", path.read_text())
            print("Current:", current)
        path.write_text(json.dumps(current, indent=1))
        print("Saved benchmark baseline: %s" % path)
        return
    rows = telemetry.build(a.limit) if a.generate or not telemetry.CORPUS.exists() else telemetry.load()
    print("Benchmark corpus: %d fixed targets (%s)" % (len(rows), telemetry.CORPUS))
    for bucket in ("tiny", "medium", "large"):
        print("  %-6s %d" % (bucket, sum(r["bucket"] == bucket for r in rows)))
    stats = telemetry.model_stats()
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


def cmd_daily_stats(a):
    from roc.reports import save
    from roc.worker import Api
    s = settings()
    if a.db:
        store = need_module("server", "Local daily reports").Store(a.db, 600)
        try:
            report = store.daily_stats(a.date)
        finally:
            store.db.close()
    else:
        api = Api(need(a.server or s.get("server"), "server", "Use --server URL"), a.token or s.get("token"))
        report = api.call("/v1/daily-stats" + ("?date=" + a.date if a.date else ""))
    path = save(report, a.output)
    print("%s (%s): %d verified exact gains" % (report["date"], report["timezone"], report["exacts"]))
    print("People:")
    for row in report["people"]:
        print("  %s: %d | %s" % (row["name"], row["exacts"], ", ".join("%s %d" % (m["name"], m["exacts"]) for m in row["models"])))
    for title, key in (("Models", "models"), ("Server Mining", "server_mining"), ("Clients", "clients")):
        print(title + ":")
        for row in report[key]:
            print("  %s: %d" % (row["name"], row["exacts"]))
    print("Older exact events without attribution/verification: %d" % report["legacy_unattributed_exacts"])
    print("Saved: %s" % path)


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
                sys.exit(providers.credential_hint(a.name))
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
    from roc import telemetry
    model = a.model or settings().get("model")
    if not model:
        from roc import draft
        model = draft.pick_model()
    if not model:
        raise SystemExit("Choose a model first: roc model")
    if a.clear:
        print("Cleared optimizer profile for %s." % model if telemetry.clear_profile(model)
              else "No optimizer profile saved for %s." % model)
        return
    telemetry.run(model, allow_cloud=a.allow_cloud, max_cloud_requests=a.max_cloud_requests,
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
        ("First-time setup (packages, exact compilers, links)", lambda: main(["install"])),
        ("Open the dashboard (Workers, integrators, history)", lambda: main(["gui"])),
        ("Start my AI worker (cloud model)", menu_worker),
        ("Start an AI integrator (CLI, cloud API or local model)",
         lambda: main(["integrator", "--model", ask("Model (codex:default, claude:sonnet, opencode:provider/model, API or local)", "codex:default"),
                       "--workers", ask("Concurrent AI workers", "4"), "--allow-cloud"])),
        ("Check what needs fixing", lambda: main(["doctor"])),
        ("Work on a function by hand", menu_hand),
        ("Send my hand-written functions to the server", lambda: main(["submit", ask("Client", "2008-06")])),
        ("Host the group server", lambda: main(["host"])),
        ("Add or change cloud API keys", lambda: main(["provider", "secrets", "--open"])),
        ("Update RoConstruct", lambda: main(["update"])),
        ("All commands", lambda: main(["--help"])),
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
    from roc import draft, link, worker
    s = settings()
    if link.load():
        print("Saved setup: %s (%s)" % (link.status()["detail"],
                                        ", ".join("%s=%s" % (k, link.load()[k])
                                                  for k in ("user", "client", "server", "mode")
                                                  if link.load().get(k))))
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


# `roc --help` shows common workflows first; every other command still works and is
# listed by name under Advanced (`roc <command> --help` for its options).
COMMAND_GROUPS = [
    ("Start here", ["install", "doctor", "config", "setup", "gui", "client-fetch", "analyze", "pull"]),
    ("Match and submit", ["integrate", "research", "mass", "auto", "xcopy", "libs", "lib-fetch", "lib-info", "libs-bundle", "similar", "donor",
                          "check", "check-batch", "classify", "next", "work", "scout", "packet", "release",
                          "claim", "submit", "agent-context", "agent-block", "agent-metrics"]),
    ("Workers and server", ["worker", "integrator", "status", "host", "server", "link", "tasks", "cpu-worker", "cluster"]),
    ("This copy", ["update", "provider", "chatgpt", "local-ai", "uninstall"]),
]


def command_groups(sub):
    helps = {action.dest: action.help for action in sub._choices_actions}
    sub.help = argparse.SUPPRESS  # the grouped epilog replaces argparse's flat list
    shown = [name for _, names in COMMAND_GROUPS for name in names]
    lines = []
    for title, names in COMMAND_GROUPS:
        lines.append(title + ":")
        lines += ["  %-13s %s" % (name, helps.get(name, "")) for name in names if name in helps]
        lines.append("")
    advanced = sorted(name for name in helps if name not in shown)
    lines.append("Advanced (roc <command> --help):")
    row = "  "
    for name in advanced:
        if len(row) + len(name) > 78:
            lines.append(row.rstrip())
            row = "  "
        row += name + "  "
    lines.append(row.rstrip())
    lines.append("\nNew here: roc install, then roc gui -> Workers. Agents: docs/AGENT_GUIDE.md")
    return "\n".join(lines)


def main(argv=None):
    ap = argparse.ArgumentParser(prog="roc", description=__doc__, usage="roc <command> [options]",
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", metavar="command")

    def cmd(name, fn, help, *args):
        p = sub.add_parser(name, help=help)
        for flags, kw in args:
            p.add_argument(*flags, **kw)
        p.set_defaults(fn=fn)
        return p

    cmd("gui", cmd_gui, "open the local worker and command dashboard",
        (["--port"], {"type": int, "default": 0, "help": "local port (default: choose a free port)"}),
        (["--no-browser"], {"action": "store_true", "help": "print session link without opening browser"}))
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
    p.add_argument("--rounds", type=lambda v: v if v == "auto" else int(v), help="AI tries per function (or auto)")
    p.add_argument("--max-size", dest="max_size", type=int, help="skip functions bigger than this")
    p.add_argument("--jobs", type=int, help="stop after this many functions")
    p.add_argument("--lease-mode", choices=["function", "family", "unit"], default=None,
                   help="lease one function, strict family, or whole unit")
    p.add_argument("--unit", help="unit/class name for unit lease mode")
    p.add_argument("--family-id", help="strict 24-hex family fingerprint")
    p.add_argument("--family-example", help="seed family from CLIENT:ADDRESS")
    p.add_argument("--no-revng", dest="no_revng", action="store_true", help="never use Rev.ng hints")
    p.add_argument("--no-remill", dest="no_remill", action="store_true", help="never use Remill LLVM semantic hints")
    p.add_argument("--force-lift", dest="force_lift", action="store_true",
                   help="lift structural near-misses even when cheap evidence is thin")
    p.add_argument("--dry-run", dest="dry_run", action="store_true",
                   help="print the plan without leasing a job")
    p.add_argument("--setup", dest="setup", action="store_true",
                   help="ignore the saved config and answer the setup questions again")
    p.add_argument("--cloud-escalate", dest="cloud_escalate",
                   help="cloud model for hard jobs stalled by the primary model")
    p.add_argument("--cloud-escalate-after", dest="cloud_escalate_after", type=int,
                   help="primary attempts before cloud escalation")
    p.add_argument("--thinking", choices=["auto", "enabled", "disabled"], help="provider reasoning mode")
    p.add_argument("--reasoning-effort", dest="reasoning_effort",
                   choices=["auto", "low", "medium", "high", "max"], help="provider reasoning effort")
    p.add_argument("--output-budget", dest="output_budget", type=lambda v: v if v == "auto" else int(v), help="max tokens per reply (128-32768 or auto)")
    p.add_argument("--allow-cloud", dest="allow_cloud", action="store_true", help="allow prompts to leave this PC")
    p.add_argument("--cloud-concurrency", dest="cloud_concurrency", type=int,
                   help="max concurrent cloud requests")
    p.add_argument("--max-cloud-requests", dest="max_cloud_requests", type=int,
                   help="cloud request budget for this worker")
    p.add_argument("--max-cloud-tokens", dest="max_cloud_tokens", type=int,
                   help="cloud token budget for this worker")
    p.add_argument("--max-cloud-cost", dest="max_cloud_cost", type=float,
                   help="cloud cost budget when provider pricing is set")
    p.add_argument("--source-only", dest="source_only", action="store_true",
                   help="deterministic candidates only; never call the model")
    p.add_argument("--strategy", choices=["direct", "structured", "reference"],
                   help="candidate-generation prompt strategy")
    p.add_argument("--prompt-style", choices=["legacy", "lean"], default="lean",
                   help="prompt evidence mode: legacy control or simplified lean prompt")
    p.add_argument("--order", choices=["auto", "best", "matched", "unmatched", "easiest", "random"],
                   help="which functions to lease first")
    p.add_argument("--verbosity", choices=["auto", "verbose", "compact"],
                   help="console detail; verbose shows each generated source")
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
    cmd("rebuild", cmd_rebuild, "2008 client rebuild: doctor | audit | module NAME (see rebuild/<client>/POLICY.md)",
        (["name"], {"help": "client, e.g. 2008-06"}),
        (["action"], {"choices": ["install", "prepare", "doctor", "audit", "module", "status", "closure", "milestones", "progress", "placed"]}),
        (["target"], {"nargs": "?", "help": "module name for `module` (rebuild/<client>/modules/NAME.json)"}),
        (["--no-notify"], {"action": "store_true", "help": "do not send the Discord webhook"}))
    cmd("integrate", cmd_integrate, "claim native integration work, bulk submit, track verified credit",
        (["action"], {"nargs": "?", "default": "next", "choices": ["next", "submit", "resume", "force-queue", "fingerprint", "status", "watch", "renew", "release", "park", "unpark", "sync", "invite"]}),
        (["--count"], {"type": int, "default": 1, "help": "claim 1-1024 classes; --all submits them as one verified batch"}),
        (["--targets"], {"type": int, "help": "claim enough classes for this many targets (up to 100000), one baseline"}),
        (["--batch"], {"help": "saved batch JSON from next; select its claims for submit/renew/release"}),
        (["--unit"], {}), (["--claim"], {}), (["--all"], {"action": "store_true"}),
        (["--reason"], {"help": "blocker for explicit park (two hours); release frees immediately; unpark frees your owned parked claims"}),
        (["--id"], {}), (["--model"], {}), (["--evidence-file"], {}),
        (["--retry"], {"action": "store_true", "help": "retry a rejected batch after a verifier/environment failure"}),
        (["--wait"], {"action": "store_true"}), (["--server"], {}), (["--user"], {}), (["--token"], {}))
    cmd("analyze", cmd_analyze, "split a client exe into functions ('all' for every client)", (["name"], {}))
    cmd("next", cmd_next, "list the easiest open functions", (["name"], {}), (["-n"], {"type": int, "default": 20}))
    cmd("work", cmd_work, "list clients or select+claim the next unmatched function for manual matching",
        (["name"], {"nargs": "?", "help": "client to work on (omit to list clients and server progress)"}),
        (["--server"], {}), (["--user"], {}), (["--token"], {}),
        (["--profile"], {"choices": ["quick", "balanced", "deep"], "default": "quick",
                         "help": "candidate evidence profile (default: quick)"}),
        (["--max-size"], {"dest": "max_size", "type": int, "help": "skip functions larger than this"}),
        (["--min-score"], {"dest": "min_score", "type": int, "default": 0}),
        (["--max-score"], {"dest": "max_score", "type": int, "default": 99}),
        (["--limit"], {"type": int, "default": 20, "help": "compact candidate batch (1-200)"}),
        (["--skip"], {"nargs": "?", "const": "last", "metavar": "ADDR|last",
                      "help": "release the stored claim and park it (default: most recent claim)"}),
        (["--reason"], {"default": "", "help": "reason recorded with a skip/park"}),
        (["--cooldown"], {"type": int, "default": 900, "help": "seconds to keep a skipped target parked (default 15 min)"}),
        (["--block"], {"action": "store_true",
                       "help": "park a known blocker for a year; it reopens only when its source changes "
                               "and the queue is empty, or with --include-cooling"}),
        (["--dry-run"], {"action": "store_true", "help": "show ranked candidates without claiming"}),
        (["--include-cooling", "--include-parked", "--revisit", "--revisit-parked", "--force"],
         {"dest": "include_cooling", "action": "store_true",
          "help": "include cooling/parked targets so they can be revisited (use after evidence changes)"}),
        (["--include-claimed"], {"dest": "include_claimed", "action": "store_true",
                                "help": "include targets claimed by other workers (read-only unless you own the claim)"}),
        (["--packet-tokens"], {"dest": "packet_tokens", "type": int, "default": 4000,
                               "help": "evidence packet written on claim (work/CLIENT/packets/ADDR.txt); 0 skips it"}))
    cmd("scout", cmd_scout, "read-only ranked candidates; never claims or reserves a target",
        (["name"], {"help": "client to scout"}),
        (["--server"], {}), (["--token"], {}),
        (["--profile"], {"choices": ["quick", "balanced", "deep"], "default": "quick"}),
        (["--limit"], {"type": int, "default": 20}),
        (["--max-size"], {"dest": "max_size", "type": int}),
        (["--min-score"], {"dest": "min_score", "type": int, "default": 0}),
        (["--max-score"], {"dest": "max_score", "type": int, "default": 99}),
        (["--include-claimed"], {"dest": "include_claimed", "action": "store_true",
                                 "help": "show claimed targets too (read-only)"}),
        (["--json"], {"action": "store_true"}))
    cmd("release", cmd_release, "release a stored claim (never another agent's) and park the target",
        (["name"], {}), (["addr"], {}),
        (["--server"], {}), (["--user"], {}), (["--token"], {}),
        (["--reason"], {"default": "manual skip"}),
        (["--cooldown"], {"type": int, "default": 3600, "help": "seconds to keep it parked"}),
        (["--block"], {"action": "store_true", "help": "park a known blocker for a year (see roc work --block)"}))
    cmd("packet", cmd_packet, "compact token-bounded evidence packet for a shortlisted target",
        (["name"], {}), (["addr"], {}),
        (["--server"], {}), (["--token"], {}),
        (["--json"], {"action": "store_true"}),
        (["--max-tokens"], {"dest": "max_tokens", "type": int, "default": 2000}),
        (["--similar"], {"type": int, "default": 5}),
        (["--no-diff"], {"dest": "no_diff", "action": "store_true",
                         "help": "skip the optional compile/diff step"}))
    cmd("claim", cmd_claim, "start a function: writes src/<client>/<addr>.cpp",
        (["name"], {}), (["addr"], {}), (["--open"], {"action": "store_true", "help": "open in Notepad"}))
    cmd("check", cmd_check, "compile src/<client>/*.cpp and score against the exe",
        (["name"], {}), (["addr"], {"nargs": "?"}),
        (["--file"], {"help": "scratch source to score against ADDR; saves nothing"}),
        (["--context"], {"type": int, "default": 99, "help": "unchanged lines around each diff hunk (3 = residue only)"}))
    cmd("mutsearch", cmd_mutsearch, "beam-search meaning-preserving rewrites (x87 operand order, grouping, float gates) for one function",
        (["name"], {}), (["addr"], {}),
        (["--file"], {"help": "source to start from (default src/CLIENT/ADDR.cpp)"}),
        (["--budget"], {"type": int, "default": 120, "help": "maximum compiles"}),
        (["--beam"], {"type": int, "default": 3}),
        (["--depth"], {"type": int, "default": 3, "help": "edits stacked on the start source"}),
        (["--jobs"], {"type": int, "default": 6}),
        (["--block-if-exhausted"], {"dest": "block_if_exhausted", "action": "store_true",
                                    "help": "park the target as a blocker (roc work --block) when every rewrite failed"}))
    cmd("twinpatch", cmd_twinpatch, "reuse an exact same-shape twin, substituting the constants the targets differ in",
        (["name"], {}), (["addr"], {}),
        (["--twin"], {"help": "exact twin address (default: best same-shape matches within 4 bytes)"}),
        (["--limit"], {"type": int, "default": 3, "help": "twins to try"}))
    cmd("check-batch", cmd_check_batch,"score several candidate variants of one function in parallel (agents: test multiple hypotheses at once)",
        (["name"], {}), (["addr"], {}), (["files"], {"nargs": "+"}),
        (["--context"], {"type": int, "default": 99, "help": "unchanged lines around each diff hunk"}),
        (["--json"], {"action": "store_true", "help": "machine-readable results, including compile failures"}),
        (["--summary"], {"action": "store_true", "help": "compact one-line-per-candidate output"}),
        (["--model"], {"help": "model name recorded in attempt memory"}),
        (["--hypothesis"], {"help": "one hypothesis label shared by these candidates"}),
        (["--tokens"], {"type": int, "help": "known token usage to record in attempt memory"}),
        (["--no-journal"], {"dest": "journal", "action": "store_false",
                            "help": "do not append to work/agent-memory/attempts.jsonl"}))
    cmd("classify", cmd_classify, "compile a source and classify target/candidate mismatch",
        (["client"], {}), (["addr"], {}), (["source"], {}))
    cmd("auto", cmd_auto, "auto-match trivial functions (getters, setters, empty...) ('all' for every client)",
        (["name"], {}), (["--max-size"], {"type": int, "default": 48}))
    cmd("xcopy", cmd_xcopy, "copy stored matches to the other clients that share the function",
        (["name"], {}), (["--limit"], {"type": int, "default": None,
                                       "help": "try only the first N candidate sources (testing)"}),
        (["--cross-only"], {"action": "store_true",
                             "help": "skip target's own sources; probe cross-client exact reuse only"}),
        (["--min-size"], {"type": int, "default": 0,
                           "help": "restrict target functions by byte size"}),
        (["--max-score"], {"type": int, "default": 99,
                            "help": "restrict target functions by current score"}),
        (["--dry-run", "-n"], {"action": "store_true", "help": "report what would match, write nothing"}))
    cmd("shapes", cmd_shapes, "count unmatched assembly shapes (picks the next templates)",
        (["name"], {}), (["--size"], {"type": int, "default": 128, "help": "bounded bytes to lift"}),
        (["--show"], {"type": int, "default": 20}), (["--top"], {"type": int, "default": 5}))
    cmd("ref", cmd_ref, "find the 2016 Roblox source behind a client function",
        (["unit"], {"nargs": "?"}), (["--summarise"], {"action": "store_true",
                                                       "help": "how much of each client the 2016 tree explains"}),
        (["--addr"], {"help": "rank authentic source files by exact function strings"}),
        (["--warm-large"], {"action": "store_true", "help": "cache source ranking for large low-score functions"}),
        (["--warm-lineage"], {"action": "store_true", "help": "cache exact cross-client lineage for large low-score functions"}),
        (["--client"], {"help": "restrict --summarise to one client"}),
        (["--limit"], {"type": int, "default": 5}))
    cmd("libs", cmd_libs, "match open-source library code from its real source ('all' or recipe names)",
        (["names"], {"nargs": "+"}), (["--client"], {"default": "all"}),
        (["--no-fetch"], {"action": "store_true", "help": "skip recipes whose vendor tree is not present locally"}))
    cmd("lib-fetch", cmd_lib_fetch, "download library sources for recipes, e.g. boost-1.35.0 ('all' for every recipe)",
        (["names"], {"nargs": "+"}))
    cmd("similar", cmd_similar, "list exact-matched functions with a similar instruction shape to ADDR",
        (["name"], {}), (["addr"], {}), (["--limit"], {"type": int, "default": 10}),
        (["--band"], {"type": float, "default": 0.25, "help": "max size difference as a fraction"}))
    __import__("roc.native_try").native_try.register(cmd)
    cmd("standins", lambda a: __import__("roc.standins").standins.main([a.name, a.addr]),
        "map an exact mined source's placeholder externs to the real symbols the exe relocates",
        (["name"], {}), (["addr"], {}))
    cmd("lib-info", cmd_lib_info, "show a library recipe's version, source, flags and recorded findings",
        (["name"], {}))
    cmd("libs-bundle", cmd_libs_bundle, "pack/index/fetch the private library trees, one zip each (XTP, MFC, Scintilla)",
        (["action"], {"choices": ["pack", "index", "fetch"]}),
        (["value"], {"nargs": "?", "help": "index: Drive folder link; fetch: comma-separated trees (default all)"}))
    cmd("brute", cmd_brute, "resume authentic families, source portfolios and compiler contexts over unresolved functions",
        (["client"], {"nargs": "?", "default": "2008-06"}),
        (["--jobs"], {"type": int, "default": 4, "choices": range(1, 9), "help": "parallel targets; gates stay sequential per target"}),
        (["--limit"], {"type": int, "help": "pilot limit per stage"}),
        (["--server"], {"help": "group server (default saved setting)"}),
        (["--deep"], {"action": "store_true", "help": "try all indexed candidates and donors, without the default eight-source cap"}),
        (["--plan"], {"action": "store_true"}),
        (["--status"], {"action": "store_true"}),
        (["--background"], {"action": "store_true"}),
        (["--campaign-id"], {"help": "agent campaign receipt attribution"}))
    cmd("research", cmd_research, "run named compiler-only research recipes (research/recipes.json)",
        (["action"], {"choices": ["list", "plan", "run", "status", "audit", "note", "log", "capture-units"]}),
        (["name"], {"nargs": "?", "help": "recipe name (audit: folder; note: title; log: entry count; capture-units: client)"}),
        (["more"], {"nargs": "*", "help": "audit: more folders; note: the text"}),
        (["--server"], {"help": "group server (default: saved setting)"}),
        (["--jobs"], {"type": int, "default": 1, "choices": range(1, 9), "help": "parallel targets (grid) or compile prefetch (fanout)"}),
        (["--limit"], {"type": int, "help": "first N targets/sources only (pilot)"}),
        (["--force"], {"action": "store_true", "help": "rerun a recipe recorded as rejected"}),
        (["--background"], {"action": "store_true", "help": "start resumable run and return immediately"}),
        (["--client"], {"help": "research only this client, or all registered clients (default: recipe client)"}),
        (["--campaign-id"], {"help": "attribute verified receipts to this agent campaign"}),
        (["--job-state"], {"help": argparse.SUPPRESS}))
    cmd("donor", cmd_donor, "name client functions byte-identical to RBXGS WebService.dll (OpenRBX PDB names)",
        (["client"], {"nargs": "?", "default": "all"}))
    cmd("lint", cmd_lint, "check src/<client> files, function boundaries and verified-data coverage",
        (["client"], {}), (["--show"], {"type": int, "default": 5, "help": "examples per problem"}))
    cmd("vtables", cmd_vtables, "list RTTI vtables with matched-slot coverage (writes work/<client>/vtables.json)",
        (["client"], {}), (["--top"], {"type": int, "default": 20}))
    cmd("ghidra", cmd_ghidra, "write a Ghidra script that applies recovered names and match status",
        (["client"], {}))
    cmd("lift", cmd_lift, "lift one function with the configured Remill + LLVM opt (writes inspectable IR)",
        (["name"], {}),
        (["addr"], {}),
        (["--out"], {"help": "output directory (default: work/<client>/lifted/<addr>)"}),
        (["--timeout"], {"type": int, "default": 180, "help": "Remill timeout seconds"}),
        (["--prompt-style"], {"choices": ["legacy", "lean"], "default": "lean", "help": "prompt evidence mode: legacy control or simplified lean prompt"}))
    cmd("rtti", cmd_rtti, "RTTI reverse-index: binary-proven template types (never guess a type parameter)",
        (["name"], {}), (["addr"], {"nargs": "?"}),
        (["--open"], {"action": "store_true", "help": "annotate every open function's RTTI type refs"}),
        (["--limit"], {"type": int, "default": 0, "help": "cap rows (0 = all)"}))
    cmd("extents", cmd_extents, "find near-misses whose recorded size includes padding (bounds.json candidates)",
        (["name"], {}), (["--min-score"], {"type": int, "default": 90, "help": "scan band floor"}))
    cmd("immediates", cmd_immediates, "list near-misses whose only residue is ONE wrong constant, with the target value",
        (["name"], {}), (["--min-score"], {"type": int, "default": 95}),
        (["--max-score"], {"type": int, "default": 99}))
    cmd("versions", cmd_versions, "compile one function's source under every installed vendor-version recipe (wrong version = permanent ceiling)",
        (["name"], {}), (["addr"], {}))
    cmd("bruteforce", cmd_bruteforce, "post-draft sweep: full compiler grid (incl /fp:fast) + same-shape family fanout",
        (["name"], {}), (["addr"], {"nargs": "?"}), (["--file"], {}),
        (["--near"], {"type": int, "help": "brute-force every stored source at >= N%"}),
        (["--fast"], {"action": "store_true", "help": "only the 3 quick gates, not the full grid"}),
        (["--no-family"], {"action": "store_true", "help": "skip the sibling fanout"}))
    cmd("mass", cmd_mass, "run every automatic matcher (runtime, STL, libraries, shapes); takes a while",
        (["client_name"], {"nargs": "?"}), (["--client"], {"default": "all"}))
    cmd("flags", cmd_flags, "find the client's compiler flags from matched sources",
        (["name"], {}), (["--sweep"], {"action": "store_true",
        "help": "try interacting flag combinations; stop on exact corpus"}),
        (["--limit"], {"type": int, "help": "sweep only smallest N sources"}))
    cmd("repair", cmd_repair, "run bounded compiler-backed mutations over partial sources",
        (["name"], {}), (["--addr"], {"dest": "addresses", "action": "append"}),
        (["--limit"], {"type": int}),
        (["--offset"], {"type": int, "default": 0,
                        "help": "skip this many sorted sources before --limit"}),
        (["--min-score"], {"type": int, "default": 80}),
        (["--permute"], {"action": "store_true",
                          "help": "also try semantics-preserving source permutations"}),
        (["--category"], {"dest": "categories", "action": "append",
                           "help": "restrict guided repair to this mutation category"}),
        (["--refresh-all"], {"action": "store_true",
                              "help": "refresh every score before filtering"}),
        (["--json"], {"action": "store_true",
                       "help": "print machine-readable result report"}),
        (["--json-out"], {"help": "save machine-readable report under repository root"}),
        (["--chain"], {"action": "store_true",
                        "help": "run one refreshed guided repair after an improvement"}),
        (["--dry-run", "-n"], {"action": "store_true"}))
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
    p = sub.add_parser("chatgpt", help="use your ChatGPT plan through official browser sign-in")
    cs = p.add_subparsers(dest="sub", required=True)
    login = cs.add_parser("login", help="Continue with ChatGPT and select an available plan model")
    login_choice = login.add_mutually_exclusive_group()
    login_choice.add_argument("--account", help="reauthorize a saved issued client ID")
    login_choice.add_argument("--new", action="store_true", help="add another ChatGPT account or workspace")
    login.add_argument("--model", help="model slug from your account's catalog; otherwise ask")
    login.set_defaults(fn=cmd_chatgpt)
    for command in ("status", "accounts", "models"):
        cs.add_parser(command).set_defaults(fn=cmd_chatgpt)
    use = cs.add_parser("use", help="switch to a saved account registration")
    use.add_argument("account")
    use.set_defaults(fn=cmd_chatgpt)
    logout = cs.add_parser("logout", help="revoke and clear credentials for one account")
    logout.add_argument("--account")
    logout.set_defaults(fn=cmd_chatgpt)
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
    cmd("link", cmd_link, "one-click links: 'install', 'remove', or a roconstruct:// URL", (["target"], {}))
    cmd("agent", cmd_agent, "match shared functions with your own Claude Code or Codex CLI",
        (["cli"], {"choices": ["claude", "codex", "opencode"]}),
        (["--goal"], {"help": 'free-form task, e.g. "match as many 2008-06 RakNet functions as you can"'}),
        (["--interactive"], {"action": "store_true",
                              "help": "open a normal session you can watch and steer (asks before risky commands)"}),
        (["--automatic"], {"action": "store_true", "help": "rank areas, reuse sources first, then parallel batch repair"}),
        (["--continuous"], {"action": "store_true", "help": "repeat agent cycles until stopped; switch strategies after no gains"}),
        (["--plan"], {"action": "store_true", "help": "preview local automatic ranking without starting agents"}),
        (["--workers"], {"type": int, "default": 2, "help": "automatic batch workers (1-8)"}),
        (["--batch-size"], {"type": int, "default": 4, "help": "functions per automatic batch (1-12)"}),
        (["--batch-minutes"], {"type": int, "default": 30, "help": "time cap per agent batch (1-120)"}),
        (["--individual"], {"action": "store_true", "help": "allow individual repair after shared hypotheses fail"}),
        (["--client"], {"help": "client name or all (automatic default: 2008-06; all requires explicit selection)"}),
        (["--jobs"], {"type": int, "help": "target cap (automatic: 24; leased mode: 1)"}),
        (["--model"], {"help": "passed to the CLI's --model"}),
        (["--max-size"], {"type": int, "help": "function byte ceiling (0 = unlimited; automatic: 512; leased: 256)"}),
        (["--minutes"], {"type": int, "help": "time limit per function or per --goal session (120)"}),
        (["--server"], {}), (["--user"], {}), (["--token"], {}))
    cmd("agent-check", cmd_agent_check, "check an agent source and journal the trial",
        (["name"], {}), (["addr"], {}), (["path"], {}),
        (["--hypothesis"], {"required": True, "help": "specific source/config change being tested"}))
    cmd("agent-check-batch", cmd_agent_check_batch, "check independent assigned targets concurrently and journal every trial",
        (["name"], {}), (["paths"], {"nargs": "+"}),
        (["--summary"], {"action": "store_true", "help": "print scores only; omit assembly diffs"}),
        (["--json"], {"action": "store_true", "help": "emit trial results as JSON"}),
        (["--hypothesis"], {"required": True, "help": "shared source/config change being tested"}))
    cmd("agent-context", cmd_agent_context, "read assigned sources, target assembly and recent trials together without compiling",
        (["name"], {}), (["paths"], {"nargs": "+"}))
    cmd("agent-block", cmd_agent_block, "record missing evidence for an assigned recovery target and stop",
        (["name"], {}), (["addr"], {}), (["path"], {}),
        (["--reason"], {"required": True, "help": "missing fact/declaration and next concrete evidence needed"}))
    cmd("agent-metrics", cmd_agent_metrics, "compare verified gains/hour and first-check latency for completed recovery runs",
        (["--limit"], {"type": int, "default": 20, "help": "number of completed recovery runs (20)"}))
    cmd("submit", cmd_submit, "send hand-written sources to the server ('all' for every client)",
        (["name"], {}), (["addr"], {"nargs": "*"}), (["--server"], {}), (["--user"], {}), (["--token"], {}),
        (["--model"], {"help": "LLM that mined these functions, e.g. gpt-6.1-sol (Player Mining credit)"}),
        (["--file"], {"help": "submit an isolated ADDR.cpp candidate without editing src/"}))
    cmd("pull", cmd_pull, "download everyone's sources from the server into src/ ('all' for every client)",
        (["name"], {}), (["--force"], {"action": "store_true", "help": "replace your local files"}),
        (["--server"], {}), (["--token"], {}))
    cmd("cluster", cmd_cluster, "trusted private server, CPU queue and optional failover",
        (["action"], {"choices": ["setup", "start", "enqueue", "validate", "status", "invite", "revoke",
                                  "cpu-pause", "cpu-resume", "cpu-off", "cpu-on", "job-pause", "job-resume"]}),
        (["--nodes"], {"help": "one or three private host addresses, comma separated"}),
        (["--directory"], {"default": str(ROOT / "work" / "cluster")}),
        (["--db"], {"help": "offline SQLite backup to import once"}), (["--broker"], {}),
        (["--local-pilot"], {"action": "store_true"}), (["--config"], {}), (["--job"], {}), (["--id"], {}),
        (["--name"], {}), (["--output"], {}), (["--watch"], {"action": "store_true"}))
    cmd("cpu-worker", cmd_cpu_worker, "opt-in one-slot CPU mining contributor",
        (["--config"], {"required": True}), (["--enable"], {"action": "store_true"}),
        (["--disable"], {"action": "store_true"}),
        (["--jobs"], {"type": int}))
    cmd("tasks", cmd_tasks, "local ROC tasks, progress and cooperative CPU controls",
        (["action"], {"nargs": "?", "default": "status", "choices": ["status", "pause", "resume", "stop"]}),
        (["--id"], {}))
    cmd("server", cmd_server, "host the group server",
        (["--publisher-only"], {"action": "store_true", "help": "run the server-owned hourly publisher without another API host"}),
        (["--publisher-parent"], {"type": int, "help": "exit the publisher when this API host exits"}),
        (["--port"], {"type": int, "default": 8765}), (["--host"], {"default": "0.0.0.0"}),
        (["--token"], {"help": "password workers must send"}),
        (["--discord-webhook"], {"help": "Discord mine-log webhook URL (or ROCONSTRUCT_DISCORD_WEBHOOK)"}),
        (["--lease"], {"type": int, "default": 900, "help": "seconds before an abandoned job frees up"}),
        (["--tunnel"], {"action": "store_true", "help": "public HTTPS address via Cloudflare (no router setup)"}),
        (["--publish"], {"action": "store_true", "help": "publish new sources, partials, mined findings and website changes"}),
        (["--publish-every"], {"type": int, "default": 3600, "help": "seconds between findings/site checks; unchanged output makes no commit"}),
        (["--public-server"], {"help": "address shown on the site (if not using --tunnel)"}),
        (["--startup"], {"action": "store_true", "help": "start `roc host` automatically when you log in"}))
    cmd("host", cmd_host, "run the group server with tunnel + publishing, restarting it if it stops")
    cmd("update", cmd_update, "update this copy from GitHub (a ZIP download becomes a git checkout)")
    cmd("uninstall", cmd_uninstall, "remove what install put on this PC; asks before every step",
        (["--yes"], {"action": "store_true"}))
    cmd("integrator", cmd_integrator, "parallel AI native integration with independent server verification",
        (["--model"], {"help": "codex:default, claude:sonnet, opencode:provider/model, API or local model"}),
        (["--workers"], {"default": "4", "help": "parallel AI jobs (1-256 or auto)"}),
        (["--compile-workers"], {"type": int, "default": 4, "help": "concurrent local compilers (1-64)"}),
        (["--batch-files"], {"type": int, "default": 40, "help": "files per verified batch (1-1024)"}),
        (["--rounds"], {"type": int, "default": 3}),
        (["--output-budget"], {"type": int, "default": 3072}),
        (["--context"], {"choices": ["methods", "file"], "default": "methods"}),
        (["--thinking"], {"choices": ["auto", "enabled", "disabled"], "default": "disabled"}),
        (["--reasoning-effort"], {"choices": ["auto", "low", "medium", "high", "max"], "default": "auto"}),
        (["--cloud-concurrency"], {"default": "auto"}),
        (["--max-cloud-requests"], {"type": int}), (["--max-cloud-tokens"], {"type": int}),
        (["--max-cloud-cost"], {"type": float}), (["--allow-cloud"], {"action": "store_true"}),
        (["--user"], {}), (["--server"], {}))
    cmd("worker", cmd_worker, "help automatically: AI drafts, compile, submit",
            (["--order"], {"choices": ["auto", "best", "matched", "unmatched", "easiest", "random"], "help": "which functions first: random named units (default), most-matched, unmatched, easiest, best evidence, or auto"}),
        (["--server"], {}), (["--user"], {}), (["--token"], {}), (["--model"], {}),
(["--client"], {"help": "restrict work to one registered client, or 'all' for every ready one"}),
        (["--addr"], {"action": "append", "help": "pin AI work to one or more client function addresses"}),
        (["--rounds"], {"type": lambda v: v if v == "auto" else int(v), "help": "AI tries per function (or auto)"}),
        (["--strategy"], {"choices": ["direct", "structured", "reference"], "default": "direct",
                            "help": "candidate-generation prompt strategy"}),
        (["--max-size"], {"type": int, "help": "skip functions bigger than this (bytes; 0 = unlimited)"}),
        (["--min-score"], {"type": int, "help": "lease only functions at or above this score"}),
        (["--max-score"], {"type": int, "help": "lease only functions at or below this score"}),
        (["--output-budget"], {"type": lambda v: v if v == "auto" else int(v), "help": "max tokens per reply (128-32768 or auto)"}),
        (["--jobs"], {"type": int, "help": "stop after this many functions"}),
        (["--workers"], {"help": "bounded concurrent lease loops (1-256 or auto)"}),
        (["--lease-mode"], {"choices": ["function", "family", "unit"], "default": "function",
                              "help": "lease one function, strict family, or whole unit"}),
        (["--unit"], {"help": "unit/class name for unit lease mode"}),
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
        (["--cloud-min-size"], {"type": int, "help": "use local 7B fallback below this byte size; 0 disables routing"}),
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
        (["--preset"], {"choices": ["automatic", "auto", "fast", "balanced", "deep"], "default": "balanced"}),
        (["--dry-run"], {"action": "store_true", "help": "show worker setup without leasing a job"}),
        (["--source-only"], {"action": "store_true", "help": "run deterministic candidates; never call Ollama"}),
        (["--guided-mutations"], {"action": "store_true", "help": "enable evidence-guided source mutations after compilation"}),
        (["--abi-only"], {"action": "store_true", "help": "limit compiler mutations to ABI/return/type families"}),
        (["--near-repair"], {"action": "store_true", "help": "preserve 90%+ source; ask for one minimal evidence-backed change"}),
        (["--no-update"], {"action": "store_true", "help": "skip the pre-run source update check"}))
    cmd("model-stats", cmd_model_stats, "compare models using worker telemetry")
    cmd("family-stats", cmd_family_stats, "show family coverage, propagation, cost, and exact rate")
    cmd("failures", cmd_failures, "show recurring worker compile/API failures",
        (["--promote"], {"action": "store_true", "help": "save repeated failure rule suggestions"}),
        (["--addr"], {"help": "show rejected variants recorded for one function address"}),
        (["--client"], {"default": "2008-06", "help": "client for --addr lookup"}))
    cmd("benchmark-models", cmd_benchmark_models, "create fixed targets and compare model telemetry",
        (["--generate"], {"action": "store_true"}),
        (["--hidden"], {"action": "store_true", "help": "build source/score-hidden solved targets"}),
        (["--ab"], {"action": "store_true",
                    "help": "print the fixed hash A/B split of the hidden corpus; runs nothing"}),
        (["--ab-compare"], {"dest": "ab_compare", "nargs": 2, "metavar": ("SESSION_A", "SESSION_B"),
                            "help": "compare recorded telemetry for a baseline arm and a variant arm"}),
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
    cmd("daily-stats", cmd_daily_stats, "daily verified gains by people, models, and Server Mining",
        (["--date"], {}), (["--server"], {}), (["--token"], {}), (["--db"], {}),
        (["--output"], {"default": str(ROOT / "work" / "reports" / "daily")}))
    cmd("progress", cmd_progress, "write docs/ data for the website", (["--server"], {}), (["--token"], {}))
    ap.epilog = command_groups(sub)
    a, unknown = ap.parse_known_args(argv)
    if unknown:
        ap.error("unrecognized arguments: %s" % " ".join(unknown))
    if not a.cmd:
        return menu()
    if getattr(a, "addr", None):  # agents often type 0x00542A50; stored names are 00542a50
        a.addr = ([_addr(x) for x in a.addr] if isinstance(a.addr, list) else _addr(a.addr))
    from roc import tasks
    if a.cmd in tasks.COMMANDS:
        watch = tasks.Watch(a.cmd)
        watch.install()
        try:
            a.fn(a)
        except BaseException:
            watch.finish("cancelled" if watch.control_path.exists() and watch.control_path.read_text() == "stop" else "failed")
            raise
        else:
            watch.finish("completed")
    else:
        a.fn(a)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nStopped.")
    except RuntimeError as error:  # server/network problems: message, not a traceback
        sys.exit("Error: %s" % error)
