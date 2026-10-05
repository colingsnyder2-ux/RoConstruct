#!/usr/bin/env python3
"""First-run dependency check and Windows installer for RoConstruct."""
import argparse
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MODEL = "qwen2.5-coder:7b-instruct"


def vcvars():
    paths = [
        Path(__import__("os").environ.get("ROCONSTRUCT_VCVARS", "")),
        Path(r"C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars32.bat"),
        Path(r"C:\Program Files\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars32.bat"),
        Path(r"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"),
    ]
    return next((path for path in paths if str(path) != "." and path.exists()), None)


def has_model():
    if not shutil.which("ollama"):
        return False
    try:
        return MODEL in subprocess.run(["ollama", "list"], capture_output=True, text=True,
                                       timeout=10).stdout
    except (OSError, subprocess.SubprocessError):
        return False


def present():
    return {
        "Python": bool(shutil.which("py") or shutil.which("python")),
        "Ollama": bool(shutil.which("ollama")),
        "Ollama code model": has_model(),
        "Visual Studio x86 tools": bool(vcvars()),
        "Ghidra project": (ROOT / "work" / "re" / "projects" / "Rbx2008M.rep").exists(),
        "Client samples": any((ROOT / "clients").glob("*/RobloxApp_*.exe")),
    }


def install():
    if not shutil.which("winget"):
        raise RuntimeError("winget missing. Install App Installer, retry.")
    for label, package, found in (
        ("Python", "Python.Python.3.12", bool(shutil.which("py") or shutil.which("python"))),
        ("Ollama", "Ollama.Ollama", bool(shutil.which("ollama"))),
        ("Visual Studio Build Tools", "Microsoft.VisualStudio.2022.BuildTools", bool(vcvars())),
    ):
        if found:
            continue
        print("Installing %s..." % label)
        command = ["winget", "install", "--id", package, "-e",
                   "--accept-package-agreements", "--accept-source-agreements"]
        if package == "Microsoft.VisualStudio.2022.BuildTools":
            command += ["--override", "--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"]
        result = subprocess.run(command)
        if result.returncode:
            raise RuntimeError("%s install failed (%d)" % (label, result.returncode))
    if not has_model() and shutil.which("ollama"):
        print("Downloading local code model (about 4.4 GB)...")
        subprocess.run(["ollama", "pull", MODEL], check=True)
    print("Restart app after install if Python or Visual Studio was added.")
    print("Ghidra: extract official release to work\\re\\ghidra.")


if __name__ == "__main__":
    try:
        args = argparse.ArgumentParser()
        args.add_argument("--install", action="store_true")
        args = args.parse_args()
        if args.install:
            install()
        else:
            for name, ok in present().items():
                print("%-26s %s" % (name, "ready" if ok else "missing"))
    except Exception as error:
        print("setup failed: %s" % error, file=sys.stderr)
        sys.exit(1)
