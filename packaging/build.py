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
import shutil
import subprocess
import sys
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DIST = ROOT / "dist"

# Every module a working cloud worker needs (transitive closure of worker, link,
# handoff, doctor, setup, analyze, draft, optimizer and the matchers).
WORKER_MODULES = [
    "analyze", "auto", "benchmark", "clients", "doctor", "draft", "fingerprint",
    "flags", "handoff", "libs", "link", "mass", "match", "metrics", "mutate",
    "optimizer", "providers", "refsource", "repair", "selfupdate", "setup",
    "shapes", "sources", "uninstall", "worker", "xcopy",
]
# Only the maintainer's server needs these, so they stay out of the helper zips.
SERVER_MODULES = ["dataset", "discord", "progress", "server"]

COMMON_FILES = ["roc.py", "roc.cmd", "roc.sh", "install.cmd", "install.sh",
                "uninstall.cmd", "README.md",
                "clients/clients.json", "clients/sources.json", "clients/README.md"]

PACKAGES = {
    "worker": {
        "name": "RoConstruct Worker",
        "tagline": "Small cloud worker. No GPU, no Ollama, no Docker.",
        "files": COMMON_FILES + ["start.cmd", "update.cmd", ".gitignore"],
        "modules": WORKER_MODULES,
        "docs": {
            "README-FIRST.txt": """RoConstruct Worker
====================

This is the whole helper install. It is deliberately small:

  1. Run install.cmd (Windows) or install.sh (Linux). It checks Python,
     installs two pip packages (pefile, capstone), downloads the exact MSVC
     compiler bundles, registers the roconstruct:// link on Windows, and
     opens the website.
  2. Click "Start helping" on the website (or run start.cmd; on Linux run
     ./roc.sh launch). It asks your username, which client, and whether
     prompts may go to a cloud model.
  3. The worker runs. Cloud models mean your PC stays idle. Only source that
     compiled and matched is uploaded.

Linux needs Wine (it runs the old cl.exe) plus cabextract or 7z; install.sh
checks for both before downloading anything. roconstruct:// links and the
winget-based Ollama install are Windows-only; on Linux use ./roc.sh.

Not installed, on purpose: Ollama, Docker, Rev.ng, any local model.
Want a local model later? Run local-ai.cmd from RoConstruct Local AI, or:

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
        "files": COMMON_FILES + ["start.cmd", "local-ai.cmd", "update.cmd", ".gitignore"],
        "modules": WORKER_MODULES,
        "docs": {
            "README-FIRST.txt": """RoConstruct Local AI
=====================

Unzip this over your RoConstruct Worker install.

Cloud workers (the default) need none of this. Install it only if you want a
local model to run on your own GPU:

    local-ai.cmd              install Ollama, then a model
    local-ai.cmd --docker     also offer Docker Desktop for Rev.ng hints

Rev.ng is a separate, later step because it costs about 5 GB and needs a restart.
Local models use your GPU and CPU heavily: fans, heat and power draw.
""",
        },
    },
    "server": {
        "name": "RoConstruct Server",
        "tagline": "Maintainer-only: the group server and website publishing.",
        "files": COMMON_FILES + ["host.cmd", "start.cmd", "update.cmd", ".gitignore",
                                 "docs/progress.json", "docs/history.json"],
        "modules": WORKER_MODULES + SERVER_MODULES,
        "docs": {
            "README-FIRST.txt": """RoConstruct Server (MAINTAINER-ONLY)
==================================

This package is for whoever runs the group server. Helpers do not need it: the
worker packages deliberately leave these modules out, and typing a server
command from a Worker install says so instead of crashing.

    host.cmd                 start the server (token, tunnel, publishing)
    py -3.12 roc.py server --help
    py -3.12 roc.py progress          write docs/ for the website
    py -3.12 roc.py server --startup  start host.cmd at logon

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
    if out.exists():
        shutil.rmtree(out)
    (out / "roc").mkdir(parents=True)
    for relative in spec["files"]:
        source = ROOT / relative
        if not source.is_file():
            raise SystemExit("missing file for %s: %s" % (slug, relative))
        target = out / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, target)  # keeps the mode, so install.sh/roc.sh stay executable
        if target.suffix == ".sh":
            target.chmod(0o755)  # a Windows checkout may have lost the bit
    for module in spec["modules"]:
        source = ROOT / "roc" / ("%s.py" % module)
        if not source.is_file():
            raise SystemExit("missing module for %s: roc/%s.py" % (slug, module))
        shutil.copyfile(source, out / "roc" / source.name)
    (out / "roc" / "__init__.py").write_text("", encoding="utf-8")
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
        build(slug)
    print("\nWrote %s" % DIST)
    print("A helper only needs RoConstruct Worker. Local AI and Server are opt-in.")


if __name__ == "__main__":
    main(sys.argv[1:])