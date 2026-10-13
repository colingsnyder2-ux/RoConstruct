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
                 "family_id", "family_example", "unit", "cloud_escalate", "cloud_escalate_after",
                 "thinking", "reasoning_effort", "output_budget", "cloud_concurrency", "strategy",
                 "order", "verbosity", "max_cloud_requests", "max_cloud_tokens", "max_cloud_cost"):
        value = getattr(a, name, None)
        if value is not None:
            forwarded += ["--%s" % name.replace("_", "-"), str(value)]
    for flag, name in (("no-revng", "no_revng"), ("dry-run", "dry_run"),
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
    if a.file:  # scratch trial: score any file against one function, save nothing
        if not a.addr:
            sys.exit("--file needs an address")
        addr = a.addr.lower().replace("0x", "").zfill(8)
        try:
            value, name, asm_diff, _ = match.check(a.name, addr, Path(a.file))
        except match.CompileError as error:
            sys.exit("%s  does not compile:\n%s" % (a.file, error))
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
        match.save_data(a.name, src.stem, spans)
        matched += value == 100
        print("%s  %3d%%  %s%s" % (src.stem, value, name or "-", "  MATCH" if value == 100 else "  (best %d%%)" % best))
        if value < 100 and len(srcs) == 1:
            print("Assembly diff ('-' = target, '+' = yours):")
            print(asm_diff)
    if len(srcs) > 1:
        print("%d / %d match." % (matched, len(srcs)))


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
    result = matchers.run(targets=names, limit=a.limit, dry_run=a.dry_run)
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
    print(json.dumps(research.plan(a.name), indent=2))
    if a.action == "plan":
        return
    if recipes[a.name].get("result", {}).get("status") == "rejected" and not a.force:
        sys.exit("Recipe %s is recorded as rejected: %s Use --force with new evidence." %
                 (a.name, recipes[a.name].get("next", "")))
    research.run(a.name, a.server, a.jobs, a.limit)


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
    print("Saved: " + ", ".join("%s=%s" % (k, "***" if k == "token" else v) for k, v in s.items()))


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
                a.cli + ":" + (a.model or "default") + (":individual" if a.individual else ""))), indent=2))
            return
        s = settings()
        srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
        user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
        return agent_auto.run(srv, user, a.token or os.environ.get("ROC_AGENT_SERVER_TOKEN") or s.get("token"), a.cli, a.model, a.workers,
            a.jobs or 24, a.max_size if a.max_size is not None else 512, a.minutes or 120, a.batch_size, a.batch_minutes, a.individual, client=selected_client,
            continuous=a.continuous, experimental=a.experimental,
            experimental_percent=max(0, min(100, a.experimental_percent)))
    if a.interactive:
        return agent.interactive(a.cli, a.goal or "match open 2008-06 functions", a.model)
    if a.goal:
        goal = a.goal
        if a.client:
            goal += "\nClient scope: %s." % a.client
        if a.server:
            goal += "\nUse server %s for project commands." % a.server
        if a.user:
            goal += "\nUse contributor username %s." % a.user
        code = agent.run_goal(a.cli, goal, a.model, a.minutes or 120, continuous=a.continuous)
        if code:
            raise SystemExit(code)
        return code
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
    agent.run(srv, user, a.token or s.get("token"), a.cli, a.model, a.client, a.jobs or 1, a.max_size if a.max_size is not None else 256, a.minutes or 20)


def cmd_agent_check(a):
    from roc import agent_auto
    row = agent_auto.trial(a.name, a.addr, a.path, a.hypothesis)
    print("%s %d%% %s" % (a.addr, row["after"], row["outcome"]))
    print(row.get("diff") or row.get("error") or "Exact code/data match")


def cmd_submit(a):
    from roc import worker
    s = settings()
    srv = need(a.server or s.get("server"), "server", "Use --server or: roc config --server URL")
    user = need(a.user or s.get("user"), "username", "Use --user or: roc config --user NAME")
    names = sorted(clients.load()) if a.name == "all" else [a.name]
    for name in names:
        if not (ROOT / "src" / name).is_dir():
            continue
        try:
            worker.submit_files(srv, user, name, a.addr or None, a.token or s.get("token"))
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
        if not public:
            sys.exit("--publish needs a public address: use --tunnel or --public-server HOST:PORT")
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
                          not a.no_revng, a.jobs, a.workers or "1", source_only=a.source_only,
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
    rows = telemetry.failure_clusters()
    if not rows:
        print("No worker failures recorded.")
        return
    print("Failure cluster                                      count")
    for row in rows:
        print("%-52s %5d" % (row["reason"], row["count"]))


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
        ("Open the dashboard (Workers, agents, history)", lambda: main(["gui"])),
        ("Start my AI worker (cloud model)", menu_worker),
        ("Start an automatic agent worker (Claude Code / Codex)",
         lambda: main(["agent", ask("CLI (claude/codex)", "claude"), "--automatic"])),
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
    ("Match and submit", ["agent", "research", "mass", "auto", "xcopy", "libs", "lib-fetch", "lib-info", "libs-bundle", "similar", "donor",
                          "check", "classify", "next", "claim", "submit"]),
    ("Workers and server", ["worker", "status", "host", "server", "link", "tasks", "cpu-worker", "cluster"]),
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
    cmd("analyze", cmd_analyze, "split a client exe into functions ('all' for every client)", (["name"], {}))
    cmd("next", cmd_next, "list the easiest open functions", (["name"], {}), (["-n"], {"type": int, "default": 20}))
    cmd("claim", cmd_claim, "start a function: writes src/<client>/<addr>.cpp",
        (["name"], {}), (["addr"], {}), (["--open"], {"action": "store_true", "help": "open in Notepad"}))
    cmd("check", cmd_check, "compile src/<client>/*.cpp and score against the exe",
        (["name"], {}), (["addr"], {"nargs": "?"}),
        (["--file"], {"help": "scratch source to score against ADDR; saves nothing"}))
    cmd("classify", cmd_classify, "compile a source and classify target/candidate mismatch",
        (["client"], {}), (["addr"], {}), (["source"], {}))
    cmd("auto", cmd_auto, "auto-match trivial functions (getters, setters, empty...) ('all' for every client)",
        (["name"], {}), (["--max-size"], {"type": int, "default": 48}))
    cmd("xcopy", cmd_xcopy, "copy stored matches to the other clients that share the function",
        (["name"], {}), (["--limit"], {"type": int, "default": None,
                                       "help": "try only the first N candidate sources (testing)"}),
        (["--dry-run", "-n"], {"action": "store_true", "help": "report what would match, write nothing"}))
    cmd("shapes", cmd_shapes, "count unmatched assembly shapes (picks the next templates)",
        (["name"], {}), (["--size"], {"type": int, "default": 128, "help": "bounded bytes to lift"}),
        (["--show"], {"type": int, "default": 20}), (["--top"], {"type": int, "default": 5}))
    cmd("ref", cmd_ref, "find the 2016 Roblox source behind a client function",
        (["unit"], {"nargs": "?"}), (["--summarise"], {"action": "store_true",
                                                       "help": "how much of each client the 2016 tree explains"}),
        (["--client"], {"help": "restrict --summarise to one client"}),
        (["--limit"], {"type": int, "default": 5}))
    cmd("libs", cmd_libs, "match open-source library code from its real source ('all' or recipe names)",
        (["names"], {"nargs": "+"}), (["--client"], {"default": "all"}))
    cmd("lib-fetch", cmd_lib_fetch, "download library sources for recipes, e.g. boost-1.35.0 ('all' for every recipe)",
        (["names"], {"nargs": "+"}))
    cmd("similar", cmd_similar, "list exact-matched functions with a similar instruction shape to ADDR",
        (["name"], {}), (["addr"], {}), (["--limit"], {"type": int, "default": 10}),
        (["--band"], {"type": float, "default": 0.25, "help": "max size difference as a fraction"}))
    cmd("lib-info", cmd_lib_info, "show a library recipe's version, source, flags and recorded findings",
        (["name"], {}))
    cmd("libs-bundle", cmd_libs_bundle, "pack/index/fetch the private library trees, one zip each (XTP, MFC, Scintilla)",
        (["action"], {"choices": ["pack", "index", "fetch"]}),
        (["value"], {"nargs": "?", "help": "index: Drive folder link; fetch: comma-separated trees (default all)"}))
    cmd("research", cmd_research, "run named compiler-only research recipes (research/recipes.json)",
        (["action"], {"choices": ["list", "plan", "run", "audit", "note", "log", "capture-units"]}),
        (["name"], {"nargs": "?", "help": "recipe name (audit: folder; note: title; log: entry count; capture-units: client)"}),
        (["more"], {"nargs": "*", "help": "audit: more folders; note: the text"}),
        (["--server"], {"help": "group server (default: saved setting)"}),
        (["--jobs"], {"type": int, "default": 1, "choices": range(1, 9), "help": "compile prefetch"}),
        (["--limit"], {"type": int, "help": "first N targets/sources only (pilot)"}),
        (["--force"], {"action": "store_true", "help": "rerun a recipe recorded as rejected"}))
    cmd("donor", cmd_donor, "name client functions byte-identical to RBXGS WebService.dll (OpenRBX PDB names)",
        (["client"], {"nargs": "?", "default": "all"}))
    cmd("lint", cmd_lint, "check src/<client> files, function boundaries and verified-data coverage",
        (["client"], {}), (["--show"], {"type": int, "default": 5, "help": "examples per problem"}))
    cmd("vtables", cmd_vtables, "list RTTI vtables with matched-slot coverage (writes work/<client>/vtables.json)",
        (["client"], {}), (["--top"], {"type": int, "default": 20}))
    cmd("ghidra", cmd_ghidra, "write a Ghidra script that applies recovered names and match status",
        (["client"], {}))
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
        (["--experimental"], {"action": "store_true", "default": True, "help": "choose unfinished vendor libraries and run evidence-backed research campaigns (default)"}),
        (["--experimental-percent"], {"type": int, "default": 70, "help": "chance (0-100) that each cycle is a library campaign; otherwise ranked repair batches"}),
        (["--plan"], {"action": "store_true", "help": "preview local automatic ranking without starting agents"}),
        (["--workers"], {"type": int, "default": 2, "help": "automatic batch workers (1-8)"}),
        (["--batch-size"], {"type": int, "default": 4, "help": "functions per automatic batch (1-12)"}),
        (["--batch-minutes"], {"type": int, "default": 10, "help": "time cap per agent batch (1-60)"}),
        (["--individual"], {"action": "store_true", "help": "allow individual repair after shared hypotheses fail"}),
        (["--client"], {"help": "client name or all (automatic default: 2008-06; all requires explicit selection)"}),
        (["--jobs"], {"type": int, "help": "target cap (automatic: 24; leased mode: 1)"}),
        (["--model"], {"help": "passed to the CLI's --model"}),
        (["--max-size"], {"type": int, "help": "function byte ceiling (0 = unlimited; automatic: 512; leased: 256)"}),
        (["--minutes"], {"type": int, "help": "time limit per function (20) or per --goal session (120)"}),
        (["--server"], {}), (["--user"], {}), (["--token"], {}))
    cmd("agent-check", cmd_agent_check, "check an agent source and journal the trial",
        (["name"], {}), (["addr"], {}), (["path"], {}),
        (["--hypothesis"], {"required": True, "help": "specific source/config change being tested"}))
    cmd("submit", cmd_submit, "send hand-written sources to the server ('all' for every client)",
        (["name"], {}), (["addr"], {"nargs": "*"}), (["--server"], {}), (["--user"], {}), (["--token"], {}))
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
