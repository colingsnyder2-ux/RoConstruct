"""Best-effort self-update before a worker run: fast-forward the checkout.

Mirrors update.cmd's safety rules: never touch local tracked edits, never
fail the worker (offline PCs must still mine). Returns a short status line;
raises nothing.
"""
import shutil
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def _run(*args, timeout):
    return subprocess.run(["git", *args], capture_output=True, text=True,
                          cwd=ROOT, timeout=timeout)


def try_update(log=print, timeout=60):
    """Fetch origin/main and fast-forward if clean and behind. Returns status."""
    if not shutil.which("git"):
        return "update skipped: git not installed"
    if not (ROOT / ".git" / "HEAD").exists():
        return "update skipped: not a git checkout (run update.cmd once)"
    try:
        if _run("diff", "--quiet", "HEAD", timeout=timeout).returncode != 0:
            return "update skipped: local source edits present (commit them first)"
        if _run("fetch", "--quiet", "origin", "main", timeout=timeout).returncode != 0:
            return "update skipped: could not reach repository (working offline)"
        behind = _run("rev-list", "--count", "HEAD..origin/main",
                      timeout=timeout)
        if behind.returncode != 0 or not behind.stdout.strip().isdigit():
            return "update skipped: could not compare versions (working as-is)"
        if int(behind.stdout.strip()) == 0:
            return "already current"
        if _run("pull", "--ff-only", "--quiet", "origin", "main",
               timeout=timeout).returncode != 0:
            return "update skipped: fast-forward failed (working as-is)"
    except (OSError, subprocess.TimeoutExpired):
        return "update skipped: timed out (working as-is)"
    log("Updated to the latest RoConstruct source.")
    return "updated"
