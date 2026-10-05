#!/usr/bin/env python3
"""RoConstruct colored terminal console."""
import shutil
import sqlite3
import subprocess
import sys
from pathlib import Path


class Color:
    CYAN = "\033[96m"
    GREEN = "\033[92m"
    YELLOW = "\033[93m"
    RED = "\033[91m"
    BOLD = "\033[1m"
    RESET = "\033[0m"


def find_root():
    start = Path(sys.executable).resolve().parent if getattr(sys, "frozen", False) else Path(__file__).resolve()
    for parent in (start, *start.parents):
        if (parent / "scripts" / "re" / "rebuild.py").exists():
            return parent
    return Path(__file__).resolve().parents[2]


ROOT = find_root()
RE_DIR = ROOT / "scripts" / "re"
DB = ROOT / "work" / "re" / "rbx2008m.db"


def say(color, text):
    print(color + text + Color.RESET)


def runtime():
    if not getattr(sys, "frozen", False):
        return [sys.executable]
    for name in ("py", "python"):
        if shutil.which(name):
            return [name]
    return []


def status():
    if not DB.exists():
        say(Color.RED, "Database missing. Run export + ingest first.")
        return
    try:
        with sqlite3.connect(DB) as conn:
            total, done = conn.execute("SELECT COUNT(*), SUM(done) FROM functions").fetchone()
            rbx = conn.execute("SELECT COUNT(*) FROM scope WHERE in_scope=1").fetchone()[0]
            queued, compiled = conn.execute("SELECT COUNT(*), SUM(compiles) FROM rebuild").fetchone()
        say(Color.CYAN, "\nSTATUS")
        print("  Functions:       %s" % f"{total:,}")
        print("  Explained:       %s" % f"{done or 0:,}")
        print("  RBX rebuild set: %s" % f"{rbx:,}")
        print("  Compile clean:   %s / %s" % (compiled or 0, queued or 0))
    except sqlite3.Error as error:
        say(Color.RED, "Database not ready: %s" % error)


def run(label, args):
    launcher = runtime()
    if not launcher:
        say(Color.RED, "Python missing. Choose setup first.")
        return
    command = [*launcher, str(RE_DIR / args[0]), *args[1:]]
    say(Color.YELLOW, "\n== %s ==" % label)
    say(Color.CYAN, subprocess.list2cmdline(command))
    result = subprocess.run(command, cwd=ROOT)
    say(Color.GREEN if result.returncode == 0 else Color.RED,
        "== exit %d ==" % result.returncode)


def setup():
    say(Color.YELLOW, "Will use winget: Python, Ollama, Visual Studio Build Tools.")
    if input("Install missing tools? [y/N] ").strip().lower() == "y":
        sys.path.insert(0, str(RE_DIR))
        import bootstrap
        bootstrap.install()


def first_run():
    sys.path.insert(0, str(RE_DIR))
    import bootstrap
    missing = [name for name, ready in bootstrap.present().items()
               if not ready and name not in ("Ghidra project", "Client samples")]
    if not missing:
        return
    say(Color.YELLOW, "First launch missing: " + ", ".join(missing))
    if input("Install needed public tools now? [Y/n] ").strip().lower() not in ("n", "no"):
        bootstrap.install()


def main():
    first_run()
    while True:
        print("\n" + Color.BOLD + Color.CYAN + "RoConstruct" + Color.RESET)
        print("1 status       2 setup tools       3 type universe")
        print("4 refresh RBX  5 seed core         6 compile repair")
        print("7 benchmark 20 8 explain workflow  q quit")
        choice = input("> ").strip().lower()
        if choice == "1":
            status()
        elif choice == "2":
            setup()
        elif choice == "3":
            run("Type universe", ["opaque.py", "build"])
        elif choice == "4":
            run("Scope queue", ["scope.py", "queue"])
        elif choice == "5":
            run("Seed RBX core", ["seed.py"])
        elif choice == "6":
            run("Compile repair", ["rebuild.py", "fixup"])
        elif choice == "7":
            if input("GPU-heavy benchmark. Continue? [y/N] ").strip().lower() == "y":
                run("Benchmark", ["bench.py", "--n", "20", "--max-attempts", "2"])
        elif choice == "8":
            say(Color.CYAN, "Types -> RBX-only queue -> local model C++ -> MSVC repair loop.")
            print("No client file or decompile output uploads. See scripts\\re\\README.md.")
        elif choice in ("q", "quit", "exit"):
            return


if __name__ == "__main__":
    main()
