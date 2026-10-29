"""Build the three RoConstruct packages.

    py -3.12 packaging/build.py            # build all three
    py -3.12 packaging/build.py worker     # just one

RoConstruct ships as three zips that share the roc/ package but not the extras:

  RoConstruct Worker   small cloud worker: bootstrap, compilers, worker, no GPU
  RoConstruct Local AI opt-in Ollama/Docker extras, installed over the Worker
  RoConstruct Server   maintainer-only: the group server and website publishing

Each zip is staged, then imported for real before it is packed: a package that
cannot import its own modules is a build failure, not a download problem later.
"""
import ast
import hashlib
import json
import shutil
import subprocess
import sys
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
DIST = ROOT / "local" / "packages"

# Every module a working cloud worker needs (transitive closure of worker, link,
# handoff, doctor, setup, analyze, draft, optimizer and the matchers).
WORKER_MODULES = [
    "telemetry", "agent", "agent_auto", "analyze", "matchers", "chatgpt", "clients", "doctor", "matchers",
    "draft", "fingerprint",
    "tasks", "flags", "gui", "gui_worker", "link", "libs", "match", "mutate",
    "repair", "providers", "refsource", "setup", "setup",
    "worker", "matchers",
]
# Only the maintainer's server needs these, so they stay out of the helper zips.
SERVER_MODULES = ["cluster", "progress", "reports", "server"]
WORKER_MODULES += ["bounds_proof", "agent_memory", "research", "agent_recovery", "bruteforce", "extents", "remill", "repair_scan", "rtti", "boundaries",
                   "claims", "packet", "scout", "ranking", "routing"]
WORKER_MODULES += ["integration", "integrator", "rebuild", "rebuild_install", "mutsearch", "twinpatch", "native_try", "native_sweep", "native_batch", "standins"]
WORKER_MODULES += ["integration_verify", "native_search"]  # contributor linked preflight shares authoritative build/gates
SERVER_MODULES += ["integration_notify", "integration_site"]

COMMON_FILES = ["roc.py", "roc.cmd", "roc.sh", "install.cmd", "install.sh",
                "packaging/organize-local.ps1", "research/repair-patterns.json", "docs/SETUP.md", "docs/SERVER.md",
                "research/log.jsonl",
                "CLAUDE.md", "AGENTS.md", "docs/AGENT_GUIDE.md", "research/lessons.json", "research/reports.json",
                "research/recipes.json", "research/template-units.json", "research/function-data.json",
                "README.md", "packaging/requirements-chatgpt.txt", "docs/providers.example.json",
                "roc/web/index.html", "roc/web/style.css", "roc/web/app.js", "roc/web/fonts.css",
                *sorted(p.relative_to(ROOT).as_posix() for p in (ROOT / "roc" / "web" / "fonts").iterdir()),
                "docs/logo.png", "docs/favicon.png",
                "clients/clients.json", "clients/sources.json", "clients/donor.json"]
# Native contributors need trusted recipes/generator, never private vendor trees.
COMMON_FILES += ["docs/INTEGRATION.md", "docs/INTEGRATOR_PERFORMANCE.md", "benchmarks/native_compile_batches.py", "benchmarks/native_matcher.py", "docs/NATIVE_AGENT.md", "docs/MATCHING_AGENT.md", "research/libs-bundle.json", "research/native-units.json", "research/native-source-lock.json"]
COMMON_FILES += ["benchmarks/native_search.py"]
COMMON_FILES += subprocess.check_output(["git", "ls-files", "rebuild/2008-06"],
                                        cwd=ROOT, text=True).splitlines()

PACKAGES = {
    "worker": {
        "name": "RoConstruct Worker",
        "tagline": "Small cloud worker. No GPU, no Ollama, no Docker.",
        "files": COMMON_FILES + [".gitignore"],
        "modules": WORKER_MODULES,
        "docs": {
            "README-FIRST.txt": """RoConstruct Worker
====================

This is the whole helper install. It is deliberately small:

Everything starts from roc.cmd (Linux: ./roc.sh). No arguments opens a menu;
the first run installs what is missing. Models and ChatGPT plan: docs/SETUP.md.

  1. Run install.cmd (Windows) or install.sh (Linux). It checks Python, installs required pip packages
     (pefile, capstone, tzdata), downloads the exact MSVC compiler bundles, registers
     the roconstruct:// link, and opens the website.
  2. Click "Start helping" on the website (or run: roc.cmd launch; Linux: ./roc.sh launch). It asks your
     username, which client, and whether prompts may go to a cloud model.
  3. The worker runs. Cloud models mean your PC stays idle. Only source that
     compiled and matched is uploaded.

Linux needs Wine plus cabextract or 7z. Use ./roc.sh instead of Windows URI links.

Not installed, on purpose: Ollama, Docker, Rev.ng, any local model.
Want a local model later? Install RoConstruct Local AI, or:

    py -3.12 roc.py local-ai

Something wrong? Run:

    py -3.12 roc.py doctor

It prints what is broken and the exact command that fixes it.
""",
        },
    },
    "local-ai": {
        "name": "RoConstruct Local AI",
        "tagline": "Opt-in extras: Ollama for local models, Docker/Rev.ng hints.",
        "files": COMMON_FILES + [".gitignore"],
        "modules": WORKER_MODULES,
        "docs": {
            "README-FIRST.txt": """RoConstruct Local AI
=====================

Unzip this over your RoConstruct Worker install.

Cloud workers (the default) need none of this. Install it only if you want a
local model to run on your own GPU:

    roc.cmd local-ai              install Ollama, then a model
    roc.cmd local-ai --docker     also offer Docker Desktop for Rev.ng hints

Rev.ng is a separate, later step because it costs about 5 GB and needs a restart.
Local models use your GPU and CPU heavily: fans, heat and power draw.
""",
        },
    },
    "server": {
        "name": "RoConstruct Server",
        "tagline": "Maintainer-only: the group server and website publishing.",
        "files": COMMON_FILES + [".gitignore",
                                 "docs/progress.json", "docs/history.json",
                                 ],
        "modules": WORKER_MODULES + SERVER_MODULES,
        "docs": {
            "README-FIRST.txt": """RoConstruct Server (MAINTAINER-ONLY)
==================================

This package is for whoever runs the group server. Helpers do not need it: the
worker packages deliberately leave these modules out, and typing a server
command from a Worker install says so instead of crashing.

    roc.cmd host             start the server (tunnel, publishing, auto-restart)
    py -3.12 roc.py server --help
    py -3.12 roc.py progress          write docs/ for the website
    py -3.12 roc.py server --startup  start `roc host` at logon

Hosting, publishing, private CPU sharing and failover: docs/SERVER.md
    py -3.12 roc.py cluster --help

Do not hand this zip to ordinary helpers.
""",
        },
    },
}


def version():
    try:
        out = subprocess.run(["git", "rev-parse", "--short", "HEAD"], cwd=ROOT,
                             capture_output=True, text=True, timeout=20)
        return out.stdout.strip() or "dev"
    except (OSError, subprocess.TimeoutExpired):
        return "dev"


def stage(slug, spec, out):
    """Copy one package into out/ so it can be imported and zipped."""
    from roc.rebuild_install import ensure_abi
    abi = ensure_abi(ROOT)
    if out.exists():
        shutil.rmtree(out)
    (out / "roc").mkdir(parents=True)
    for relative in spec["files"]:
        source = ROOT / relative
        if not source.is_file():
            raise SystemExit("missing file for %s: %s" % (slug, relative))
        target = out / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
    target = out / 'rebuild/2008-06/manifests/abi-evidence.json'
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(abi, target)
    # Adopted headers are compiler inputs even if no ordinary mined snippet named them.
    overlay = ROOT / 'rebuild/2008-06/patches/rbxgs-client.json'
    native = json.loads((ROOT / 'research/native-units.json').read_text(encoding='utf-8'))
    adopted = {}
    for edits in json.loads(overlay.read_text(encoding='utf-8')).values():
        for old, ref in edits:
            if old != '@replace':
                continue
            relative = Path(ref)
            if relative.parts[0] != 'App' or '..' in relative.parts or not relative.name.startswith('roc_'):
                raise SystemExit('Unsupported native dependency: ' + ref)
            name = Path(*relative.parts[1:]).as_posix()
            path = ROOT / 'tools/rbxgs/Client' / relative
            text = path.read_text(errors='replace') if path.exists() else native.get('../rbxgs/Client/App', {}).get(name)
            if text is None:
                raise SystemExit('Missing native dependency: ' + ref)
            adopted[name] = text
    (out / 'research/native-units.json').write_text(json.dumps(
        {'../rbxgs/Client/App': adopted}, indent=1, sort_keys=True) + '\n', encoding='utf-8')
    for module in spec["modules"]:
        source = ROOT / "roc" / ("%s.py" % module)
        if not source.is_file():
            raise SystemExit("missing module for %s: roc/%s.py" % (slug, module))
        shutil.copyfile(source, out / "roc" / source.name)
    shutil.copytree(ROOT / "roc" / "web", out / "roc" / "web", dirs_exist_ok=True)
    (out / "roc" / "__init__.py").write_text("", encoding="utf-8")
    (out / "roconstruct-package.json").write_text(json.dumps(
        {"package": slug, "revision": version(), "native_workflow": True, "native_workflow_version": 12,
         "matching_workflow_version": 4}, indent=2) + "\n", encoding="utf-8")
    for name, text in spec["docs"].items():
        (out / name).write_text(text, encoding="utf-8")
    return out


def referenced_modules(staged):
    """Every roc.* module roc.py mentions, at any depth."""
    tree = ast.parse((staged / "roc.py").read_text(encoding="utf-8"))
    names = set()
    for node in ast.walk(tree):
        if isinstance(node, ast.ImportFrom) and node.module and node.module.startswith("roc."):
            names.add(node.module.split(".", 1)[1])
        elif isinstance(node, ast.ImportFrom) and node.module == "roc":
            # from roc import draft, worker
            names.update(alias.name for alias in node.names if alias.name != "worker")
        elif isinstance(node, ast.Import):
            for alias in node.names:
                if alias.name.startswith("roc."):
                    names.add(alias.name.split(".", 1)[1])
        elif isinstance(node, ast.Call) and getattr(node.func, "id", "") == "need_module":
            # need_module("server", ...) is how a package leaves a module out on purpose.
            if node.args and isinstance(node.args[0], ast.Constant) and isinstance(node.args[0].value, str):
                names.add(node.args[0].value)
        elif isinstance(node, ast.Call) and getattr(node.func, "id", "") == "__import__":
            if node.args and isinstance(node.args[0], ast.Constant) and isinstance(node.args[0].value, str):
                module = node.args[0].value
                if module.startswith("roc."):
                    names.add(module.split(".", 1)[1])
    return names


def audit(staged, spec):
    """Fail the build when roc.py needs a module this package leaves out.

    Every roc import in roc.py sits inside a command, so a left-out module only
    breaks that one command. It is allowed for exactly the maintainer modules,
    which roc.py reaches through need_module() and reports as such.
    """
    left_out = sorted(name for name in referenced_modules(staged)
                      if name not in spec["modules"] and name != "worker")
    unexpected = [name for name in left_out if name not in SERVER_MODULES]
    if unexpected:
        raise SystemExit("these modules are referenced by roc.py but missing from the %s package: %s"
                         % (spec["name"], ", ".join(unexpected)))
    return left_out


def verify(staged):
    """Import every module in the staged tree, from that tree, with the repo off the path."""
    modules = sorted(p.stem for p in (staged / "roc").glob("*.py") if p.stem != "__init__")
    code = "import importlib,sys\n" \
           "for name in %r:\n    importlib.import_module('roc.' + name)\n" \
           "import ast\n" \
           "ast.parse(open('roc.py', encoding='utf-8').read())\n" \
           "print('imported', len(%r), 'modules')\n" % (modules, modules)
    run = subprocess.run([sys.executable, "-c", code], cwd=staged, capture_output=True, text=True)
    if run.returncode:
        raise SystemExit("package does not import:\n%s" % (run.stderr.strip() or run.stdout.strip()))
    return run.stdout.strip()


def pack(staged, target):
    with zipfile.ZipFile(target, "w", zipfile.ZIP_DEFLATED) as zf:
        for path in sorted(staged.rglob("*")):
            if path.is_file():
                zf.write(path, path.relative_to(staged).as_posix())
    return target


def build(slug):
    spec = PACKAGES[slug]
    staged = DIST / ("stage-" + slug)
    stage(slug, spec, staged)
    leaks = audit(staged, spec)
    print("  modules: %d" % len(spec["modules"]))
    print("  maintainer modules left out: %s" % (", ".join(leaks) or "none"))
    print("  check: %s" % verify(staged))
    target = pack(staged, DIST / ("%s-%s.zip" % (slug, version())))
    print("  %s (%.1f KB)" % (target.name, target.stat().st_size / 1024))
    return target


def main(argv):
    wanted = argv or list(PACKAGES)
    unknown = [slug for slug in wanted if slug not in PACKAGES]
    if unknown:
        raise SystemExit("unknown package(s): %s. Choose from: %s" % (", ".join(unknown), ", ".join(PACKAGES)))
    DIST.mkdir(exist_ok=True)
    print("RoConstruct packages (version %s)" % version())
    for slug in wanted:
        print("\n%s" % PACKAGES[slug]["name"])
        print("  %s" % PACKAGES[slug]["tagline"])
        target = build(slug)
        if slug == "worker":
            prepare_downloads(target)
    print("\nWrote %s" % DIST)
    print("A helper only needs RoConstruct Worker. Local AI and Server are opt-in.")


def prepare_downloads(package):
    """Refresh the shared bootstrap ZIP/manifest and both standalone agent guides."""
    with zipfile.ZipFile(package) as zipped:
        marker = json.loads(zipped.read("roconstruct-package.json"))
        if marker.get("matching_workflow_version", 0) < 4 or not {
                "docs/MATCHING_AGENT.md", "docs/NATIVE_AGENT.md",
                "rebuild/2008-06/manifests/abi-evidence.json"} <= set(zipped.namelist()):
            raise ValueError("Worker ZIP lacks the matching/native workflows; rebuild it")
        abi = zipped.read('rebuild/2008-06/manifests/abi-evidence.json')
    folder = ROOT / "local/findings/data"
    folder.mkdir(parents=True, exist_ok=True)
    manifest = folder / "native-worker.json"
    data = json.loads(manifest.read_text(encoding="utf-8")) if manifest.exists() else {}
    base = "https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/"
    archive = folder / "native-worker.zip"
    shutil.copy2(package, archive)
    for name in ("NATIVE_AGENT.md", "MATCHING_AGENT.md"):
        shutil.copy2(ROOT / "docs" / name, folder / name)
    data.update(schema=1, workflow_version=12, matching_workflow_version=4,
                abi_manifest_sha256=hashlib.sha256(abi).hexdigest(), abi_manifest_classes=len(json.loads(abi)),
                url=base + archive.name, sha256=hashlib.sha256(archive.read_bytes()).hexdigest(),
                size=archive.stat().st_size, guide=base + "NATIVE_AGENT.md", matching_guide=base + "MATCHING_AGENT.md",
                native_clients=["2008-06"], invitation_required=False)
    data.setdefault("server", "https://colinpc.tail2879d0.ts.net")
    data.setdefault("status_url", data["server"].rstrip("/") + "/v1/status")
    manifest.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    print("  Bootstrap ZIP + matching/native guides refreshed: %s" % folder)


if __name__ == "__main__":
    main(sys.argv[1:])
