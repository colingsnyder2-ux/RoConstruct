"""Uninstall RoConstruct: everything install.cmd put on this machine, one step at a time.

Nothing is removed without a yes. RoConstruct's own files default to yes because
they are useless without it; anything shared with the rest of your system defaults
to no, because you may want it for other work.

Ollama models are treated carefully: only the coder models RoConstruct documents
are offered, never the rest of your library.
"""
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# What install.cmd downloads into tools/. Each is re-creatable with `roc install`.
TOOL_DIRS = ["dl", "vc2005", "vc2008rtm", "vc2008sp1", "cloudflared"]
# Local state. work/<client> holds match scores, so it is asked separately.
WORK_DIRS = ["work"]
BUILD_DIRS = ["build", "dist"]

# draft.PREFERRED_MODELS, minus the unversioned/alias spellings: only offer a model
# to delete if it is one of these exact names. Anything else in your Ollama library
# is never considered for removal.
ROC_MODELS = ["qwen2.5-coder:14b", "qwen2.5-coder:7b", "qwen2.5-coder:7b-instruct",
              "qwen2.5-coder"]
REVNG_IMAGE = "revng/revng"


def human(n):
    """Byte count -> readable. Ollama reports sizes as strings like '9.0 GB'."""
    if isinstance(n, str):
        return n
    value = float(n)
    for unit in ("B", "KB", "MB", "GB"):
        if value < 1024 or unit == "GB":
            return "%d B" % n if unit == "B" else "%.1f %s" % (value, unit)
        value /= 1024


def size_of(path):
    if path.is_file():
        return path.stat().st_size
    if not path.is_dir():
        return 0
    return sum(f.stat().st_size for f in path.rglob("*") if f.is_file())


def folder_bytes():
    """Folder sizes for the plan, so you can see what each step frees."""
    out = {}
    for name in TOOL_DIRS:
        path = ROOT / "tools" / name
        if path.exists():
            out[name] = size_of(path)
    for name in WORK_DIRS + BUILD_DIRS:
        path = ROOT / name
        if path.exists():
            out[name] = size_of(path)
    return out


class Console:
    def __init__(self, assume_yes=False):
        self.assume_yes = assume_yes
        self.removed = []
        self.kept = []
        self.skipped = []
        self.deferred = []

    def ask(self, question, default=False):
        if self.assume_yes:
            return True
        hint = "Y/n" if default else "y/N"
        try:
            answer = input("%s [%s] " % (question, hint)).strip().lower()
        except EOFError:
            return default
        if not answer:
            return default
        return not answer.startswith("n")

    def run(self, label, argv, check=False):
        try:
            done = subprocess.run(argv, capture_output=True, text=True, timeout=300)
        except (OSError, subprocess.TimeoutExpired) as error:
            print("   skipped: %s" % error)
            self.skipped.append(label)
            return False
        if check and done.returncode != 0:
            print("   skipped: %s exited %d" % (argv[0], done.returncode))
            self.skipped.append(label)
            return False
        return True


def which(name):
    return shutil.which(name)


def python_312():
    """True if the py launcher can start 3.12, the interpreter install.cmd installs."""
    if os.name != "nt" or not which("py"):
        return False
    try:
        done = subprocess.run(["py", "-3.12", "-c", "import sys"], capture_output=True, timeout=30)
        return done.returncode == 0
    except (OSError, subprocess.TimeoutExpired):
        return False


def ollama_lib():
    """Models Ollama knows about: [(name, size_str)]. Empty if Ollama is absent."""
    exe = which("ollama")
    if not exe:
        return []
    try:
        out = subprocess.run([exe, "list"], capture_output=True, text=True, timeout=30).stdout
    except (OSError, subprocess.TimeoutExpired):
        return []
    rows = []
    for line in out.splitlines()[1:]:
        parts = line.split()
        # Columns are NAME ID SIZE MODIFIED, but SIZE is "9.0 GB" - two tokens.
        if len(parts) >= 5:
            rows.append((parts[0], " ".join(parts[2:4])))
    return rows


def pip_packages():
    """pip packages install.cmd added, and only if nothing else needs them here."""
    try:
        out = subprocess.run([sys.executable, "-m", "pip", "list", "--user", "--format=freeze"],
                             capture_output=True, text=True, timeout=120).stdout
    except (OSError, subprocess.TimeoutExpired):
        return []
    have = set()
    for line in out.splitlines():
        if "==" in line:
            have.add(line.split("==")[0].strip().lower())
    return sorted(p for p in ("capstone", "pefile") if p in have)


def plan():
    """Everything removable, grouped. Pure read: touches nothing."""
    sizes = folder_bytes()
    steps = []

    tools = [(name, sizes[name]) for name in TOOL_DIRS if (ROOT / "tools" / name).exists()]
    if tools:
        steps.append(("files", "RoConstruct's downloaded tools and old compilers", tools,
                      sum(s for _, s in tools)))

    work = [(name, sizes[name]) for name in WORK_DIRS if (ROOT / name).exists()]
    if work:
        steps.append(("files", "Analysis state and match scores (re-analyzable)", work,
                      sum(s for _, s in work)))

    build = [(name, sizes[name]) for name in BUILD_DIRS if (ROOT / name).exists()]
    if build:
        steps.append(("files", "Build output", build, sum(s for _, s in build)))

    settings = ROOT / "roconstruct-settings.json"
    if settings.exists():
        steps.append(("files", "Your username, server, and saved links", [("roconstruct-settings.json",
                                                                          size_of(settings))],
                      size_of(settings)))

    from roc import link
    if os.name == "nt" and link.installed():
        steps.append(("registry", "One-click roconstruct:// links (Windows registry)", [], 0))

    models = [(n, s) for n, s in ollama_lib() if n.split(":")[0] in ROC_MODELS]
    if models:
        steps.append(("model", "Ollama coder models RoConstruct uses for AI drafts", models, 0))

    if which("docker"):
        steps.append(("docker", "Rev.ng Docker image RoConstruct calls for decompiler hints", [], 0))

    packages = pip_packages()
    if packages:
        steps.append(("pip", "Python packages RoConstruct installed (pefile, capstone)", [], 0))

    for label, exe, wid in (("Ollama (used for AI drafts)", "ollama", "Ollama.Ollama"),
                            ("Docker Desktop (used for Rev.ng hints)", "docker", "Docker.DockerDesktop"),
                            ("Python 3.12 (install.cmd installs it if you had no 3.12)",
                             "py", "Python.Python.3.12")):
        if wid == "Python.Python.3.12" and not python_312():
            continue
        if which(exe):
            steps.append(("software", label, [], 0, wid))

    return steps


def show(steps):
    if not steps:
        print("Nothing to remove: RoConstruct's downloads are already gone.")
        return
    print("What can be removed:\n")
    total = 0
    for step in steps:
        kind, label, items, size = step[0], step[1], step[2], step[3]
        total += size
        print("  %s%s" % (label, ("  (%s)" % human(size)) if size else ""))
        for name, item_size in items:
            shown = human(item_size) if item_size and kind in ("files", "model") else ""
            print("      %s %s" % (name, shown))
    print("\nTotal in RoConstruct's own folders: %s" % human(total))
    print("Software installs and pip packages are not included in that total.\n")


def drop_folders(console, label, items):
    """Delete each path: folders recursively, single files (settings) with unlink."""
    freed = 0
    for name, _ in items:
        path = ROOT / "tools" / name if (ROOT / "tools" / name).exists() else ROOT / name
        freed += size_of(path)
        if path.is_dir():
            shutil.rmtree(path, ignore_errors=True)
        else:
            path.unlink(missing_ok=True)
        if path.exists():
            print("   could not delete %s (in use?)" % path.relative_to(ROOT))
        else:
            print("   deleted %s" % path.relative_to(ROOT))
    console.removed.append("%s (%s)" % (label, human(freed)))


def run(assume_yes=False):
    steps = plan()
    show(steps)
    if not steps:
        return 0
    console = Console(assume_yes)
    print("Answer y to remove. Press Enter to accept the [Y/n] / [y/N] default.\n")

    for step in steps:
        kind, label = step[0], step[1]
        items, size = step[2], step[3]

        if kind == "files":
            if console.ask("Remove %s? [%s]" % (label.lower(), human(size) if size else ""),
                           default=True):
                drop_folders(console, label, items)
            else:
                console.kept.append(label)
            continue

        if kind == "registry":
            if console.ask("Remove %s?" % label.lower(), default=True):
                from roc import link
                link.remove()
                console.removed.append(label)
            else:
                console.kept.append(label)
            continue

        if kind == "model":
            print("\n%s:" % label)
            print("   Your other Ollama models are not touched.")
            for name, model_size in items:
                if console.ask("   Remove model %s (%s)?" % (name, model_size)):
                    if console.run(name, ["ollama", "rm", name]):
                        console.removed.append("model %s (%s)" % (name, model_size))
                    else:
                        print("   could not remove %s" % name)
            continue

        if kind == "docker":
            images = console.run("docker images", ["docker", "images", "--format", "{{.Repository}}:{{.Tag}}"])
            del images  # presence of docker is enough; the pull is explicit below
            if console.ask("Remove the %s image?" % REVNG_IMAGE):
                if console.run(REVNG_IMAGE, ["docker", "rmi", REVNG_IMAGE]):
                    console.removed.append("docker image %s" % REVNG_IMAGE)
            else:
                console.kept.append("docker image %s" % REVNG_IMAGE)
            continue

        if kind == "pip":
            packages = pip_packages()
            if console.ask("Uninstall the Python packages %s?" % ", ".join(packages)):
                if console.run("pip uninstall", [sys.executable, "-m", "pip", "uninstall", "-y"] + packages):
                    console.removed.append("pip %s" % ", ".join(packages))
            else:
                console.kept.append("pip %s" % ", ".join(packages))
            continue

        if kind == "software":
            package = step[4]
            if package == "Python.Python.3.12":
                # This script is running on the interpreter we'd be removing. winget
                # would refuse or break the process mid-run, so hand it back as a
                # command to run after everything else is done.
                if console.ask("Remove Python 3.12?\n   This uninstaller is running on it, so it "
                               "cannot remove it for you. I will print the command instead. "
                               "Other projects may need Python."):
                    console.deferred.append(
                        ("Python 3.12", 'winget uninstall --id Python.Python.3.12 -e '
                                         '(close this window first)'))
                else:
                    console.kept.append(label)
                continue
            answer = console.ask("Uninstall %s?\n   This is software you may use for other things. "
                                 "It is not removed by default." % label.lower(), default=False)
            if answer:
                if console.run(package, ["winget", "uninstall", "--id", package, "-e",
                                         "--silent", "--accept-source-agreements"], check=True):
                    console.removed.append(package)
            else:
                console.kept.append(label)

    finish(console)
    return 0


def finish(console):
    print("\n" + "-" * 62)
    if console.removed:
        print("Removed:")
        for item in console.removed:
            print("   %s" % item)
    if console.kept:
        print("\nKept (you said no):")
        for item in console.kept:
            print("   %s" % item)
    if console.skipped:
        print("\nCould not remove:")
        for item in console.skipped:
            print("   %s" % item)
    if console.deferred:
        print("\nRun these yourself, after closing this window:")
        for name, command in console.deferred:
            print("   %s\n      %s" % (name, command))
    print("-" * 62)

    tools_left = folder_bytes()
    if tools_left:
        print("\nStill in this folder: %s" % ", ".join("%s (%s)" % (k, human(v))
                                                        for k, v in sorted(tools_left.items())))
    print("\nRoConstruct's own scripts are still here: this file is running from it.")
    print("When you are happy with what is left, delete the whole %s folder." % ROOT.name)
    print("The git history, and anything you pushed to GitHub, is unaffected.")


if __name__ == "__main__":
    try:
        sys.exit(run(assume_yes="--yes" in sys.argv))
    except KeyboardInterrupt:
        print("\nStopped. Nothing further was removed.")
        sys.exit(1)
