"""roc doctor: one command that says what is wrong and exactly how to fix it.

Every check returns the same shape so the output is machine-readable and the exit
code means "something needs repair":

    {"name": ..., "state": "ok" | "warn" | "fail", "detail": ..., "fix": [...]}
"""
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FAIL = "fail"
WARN = "warn"
OK = "ok"


def check(name, state, detail, fix=()):
    return {"name": name, "state": state, "detail": detail, "fix": list(fix)}


def python_check():
    """Version, the two required pip packages, and (Windows) msilib for unpacking compilers."""
    from roc import setup
    version = ".".join(str(part) for part in sys.version_info[:3])
    missing = setup.missing_packages()
    state, detail, fix = OK, "Python %s" % version, []
    if setup.WINDOWS:
        # msilib is how install.cmd unpacks the compiler MSIs, and Python 3.13
        # dropped it. Linux unpacks with msitools/Wine instead, so it is fine there.
        if sys.version_info[:2] != (3, 12):
            detail += " (expected 3.12)"
            fix.append("Python 3.13 dropped msilib, which unpacks the compilers. "
                       "Re-run install.cmd to get 3.12.")
            state = FAIL
        if not setup.has_module("msilib"):
            state = FAIL
            detail += ", msilib unavailable"
            if not any("3.12" in step for step in fix):
                fix.append("Use Python 3.12 (install.cmd does this for you).")
    if missing:
        state = FAIL
        detail += ", missing packages: %s" % ", ".join(missing)
        fix.append('%s -m pip install --user %s' % (sys.executable, " ".join(missing)))
    if state == OK:
        detail += ", pefile and capstone installed"
    return check("python", state, detail, fix)


def compilers_check():
    """Every compiler build the registered clients need."""
    from roc import clients, setup
    if not setup.compiler_ready():
        return check("compilers", FAIL, "Wine is missing, so the old cl.exe cannot run",
                     ["Arch: sudo pacman -S wine",
                      "Debian/Ubuntu: sudo apt install wine wine32",
                      "Then run: roc doctor"])
    have = setup.compilers()
    registry = clients.load()
    missing = sorted({e.get("compiler_build") for e in registry.values()} - set(have) - {None})
    present = sorted(have)
    if not registry:
        return check("compilers", WARN, "no clients registered yet", [])
    if not missing:
        return check("compilers", OK, "all %d build(s) ready: %s" % (len(present), present))
    names = [setup.NAMES.get(b, str(b)) for b in missing]
    total = sum(setup.BUNDLES[b][0] for b in missing if b in setup.BUNDLES)
    return check("compilers", FAIL,
                 "missing %s (%d MB to download)" % (", ".join(names), total),
                 ["Run: roc install (Windows: install.cmd)",
                  "It resumes an interrupted download and never reinstalls a compiler you already have."])


def clients_check():
    """Client exes on disk versus the registry, including the analysis step."""
    from roc import clients
    rows = []
    for name, entry in sorted(clients.load().items()):
        status = clients.status(name, entry)
        analyzed = (ROOT / "work" / name / "functions.jsonl").exists()
        rows.append((name, status, analyzed))
    if not rows:
        return check("clients", WARN, "no clients registered", [])
    ready = [name for name, status, _ in rows if status == "ok"]
    mismatched = [name for name, status, _ in rows if status == "hash mismatch"]
    absent = [name for name, status, _ in rows if status != "ok" and status != "hash mismatch"]
    unanalyzed = [name for name, _, analyzed in rows if not analyzed]
    state = OK if len(ready) == len(rows) else WARN
    detail = "%d/%d client(s) verified (%s)" % (len(ready), len(rows), ", ".join(ready) or "none")
    fix = []
    if mismatched:
        fix.append("Hash mismatch (different build): delete clients/%s/ and run: roc client-fetch %s"
                   % (mismatched[0], mismatched[0]))
    if absent:
        fix.append("Missing exe: the worker downloads it on start, or run: roc client-fetch %s" % absent[0])
    if unanalyzed:
        fix.append("Not analyzed yet: run: roc analyze %s" % unanalyzed[0])
    return check("clients", state, detail, fix)


def identity_check():
    """Saved username, server and the signed handoff config."""
    from roc import handoff, worker
    settings = worker.load_settings()
    state = OK
    detail, fix = [], []
    user, server = settings.get("user"), settings.get("server")
    if not user:
        state = FAIL
        fix.append("No username saved. Run: roc setup")
    if not server:
        state = FAIL
        fix.append("No server saved. Run: roc setup")
    if user and server:
        detail.append("user=%s server=%s" % (user, server))
    handoff_state = handoff.status()
    detail.append("worker config: %s" % handoff_state["detail"])
    if handoff_state["state"] == "missing":
        if state != FAIL:
            state = WARN
        fix.append("No signed worker config. Run: roc setup (or click Start helping on the site)")
    elif handoff_state["state"] in ("tampered", "broken"):
        state = FAIL
        fix.append("Worker config was edited or is unreadable. Delete roconstruct-worker.json and run: roc setup")
    return check("identity", state, ", ".join(detail), fix)


def cloud_check(network=True):
    """Cloud readiness: a provider key, and the server actually answering."""
    from roc import providers, worker
    state, detail, fix = OK, [], []
    available = [name for name, config in sorted(providers.providers().items())
                 if providers.key_available(config["key_env"])]
    model = worker.cloud_default()
    if not model:
        # A custom OpenAI-compatible provider has no built-in default, so fall
        # back to the model the user actually saved.
        saved = worker.load_settings().get("model")
        if saved and providers.is_cloud(saved) and providers.available(saved):
            model = saved
    if model:
        detail.append("cloud model %s ready" % model)
    elif available:
        detail.append("provider keys set for %s (no default model matches)" % ", ".join(available))
        fix.append("Pick a model with: roc model")
    else:
        state = FAIL
        detail.append("no cloud provider key saved")
        fix.append("Save a cloud key: roc provider setup")
    if network:
        state2, detail2, fix2 = server_check()
        state = FAIL if "fail" in (state, state2) else state
        detail.append(detail2)
        fix.extend(fix2)
    return check("cloud", state, ", ".join(detail), fix)


def server_check():
    """Can this PC reach the group server, and does it answer /v1/info?"""
    from roc import worker
    saved = worker.load_settings().get("server")
    target = saved or worker.site_server()
    if not target:
        return WARN, "no server address known (run: roc setup)", ["Run: roc setup to save the server"]
    from roc import worker as worker_module
    api = worker_module.Api(target, worker_module.load_settings().get("token"))
    try:
        info = api.call("/v1/info", timeout=20)
    except Exception as error:  # ApiFailure and network errors both mean "cannot work"
        return FAIL, "cannot reach %s (%s)" % (target, error), \
               ["Check your internet connection",
                "The address may have moved: run: roc setup, or check the website for the current server"]
    clients_online = len(info.get("clients", {}))
    return OK, "%s answered (%d client(s) published)" % (target, clients_online), []


def link_check():
    """Is roconstruct:// registered so the website can start the worker?"""
    from roc import link, setup
    if os.name != "nt":
        return check("links", WARN, "roconstruct:// links are Windows-only", [])
    if link.installed():
        return check("links", OK, "roconstruct:// registered")
    return check("links", FAIL, "roconstruct:// not registered",
                 ["Register it: roc link install", "Or simply run install.cmd again"])


def local_check():
    """Optional local AI. Never a failure: cloud is the default."""
    from roc import draft, setup
    model = draft.pick_model()
    if model:
        return check("local-ai", OK, "Ollama ready, %s" % model)
    if setup.find_exe("ollama"):
        if not setup.wait_for_http(setup.OLLAMA_API, timeout=4, interval=1):
            return check("local-ai", WARN, "Ollama installed but not running", ["Run: ollama serve"])
        return check("local-ai", WARN, "Ollama running with no model",
                     ["Run: ollama pull qwen2.5-coder:7b", "Or keep using cloud models (the default)"])
    return check("local-ai", OK, "not installed (cloud models are the default; no GPU needed)")


def extras_check():
    """Docker / Rev.ng: optional extras, reported so nobody wonders."""
    from roc import draft
    if draft.revng_available():
        return check("extras", OK, "Rev.ng hints ready (Docker + image installed)")
    from roc import setup
    if setup.find_exe("docker"):
        return check("extras", WARN, "Docker installed but the Rev.ng image is missing",
                     ["Run: docker pull revng/revng"])
    return check("extras", OK, "Docker/Rev.ng not installed (optional: roc local-ai --docker)")


def all_checks(network=True):
    return [python_check(), compilers_check(), clients_check(), identity_check(),
            cloud_check(network), link_check(), local_check(), extras_check()]


def failed(checks):
    return [row for row in checks if row["state"] == FAIL]


def format_report(checks):
    mark = {OK: "ok", WARN: "warn", FAIL: "FAIL"}
    lines = ["RoConstruct doctor", ""]
    for row in checks:
        lines.append("  [%-4s] %-11s %s" % (mark[row["state"]], row["name"], row["detail"]))
        for step in row["fix"]:
            lines.append("            fix: %s" % step)
    problems = failed(checks)
    warnings = [row for row in checks if row["state"] == WARN]
    lines.append("")
    if problems:
        lines.append("%d problem(s): %s" % (len(problems), ", ".join(row["name"] for row in problems)))
        lines.append("Run the fix lines above, then: roc doctor")
    else:
        lines.append("Everything needed to run the worker is in place. Start one with: roc launch")
    # which model a launch would actually use, so the consent story is visible here too
    try:
        from roc import handoff, providers, worker as worker_module
        payload = handoff.load() or {}
        model = worker_module.resolve_model(payload)[0] if payload else None
        if model:
            lines.append("A launch would use: %s (%s)" % (
                model, "cloud: bounded prompts leave this PC" if providers.is_cloud(model)
                else "local: this PC does the work"))
    except SystemExit:
        pass  # no signed config yet, or the model needs a key: the launch will say so
    if warnings:
        lines.append("%d note(s): %s" % (len(warnings), ", ".join(row["name"] for row in warnings)))
    return "\n".join(lines)