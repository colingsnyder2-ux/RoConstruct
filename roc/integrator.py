"""Private contributor workspaces for controlled, parallel native integration sessions."""
import json
import os
import shutil
import subprocess
import sys
import threading
import uuid
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def link_directory(source, target):
    if os.name == "nt":
        subprocess.run(["cmd", "/c", "mklink", "/J", str(target), str(source)],
                       check=True, capture_output=True)
    else:
        target.symlink_to(source, target_is_directory=True)


def workspace(log=print):
    """Copy runtime and rebuild inputs; source overlays, claims and outputs remain private."""
    folder = ROOT / "local/integrators" / uuid.uuid4().hex
    folder.parent.mkdir(parents=True, exist_ok=True)
    log("Preparing private integrator workspace: " + str(folder))
    folder.mkdir()
    shutil.copytree(ROOT / "roc", folder / "roc", dirs_exist_ok=True,
                    ignore=shutil.ignore_patterns("__pycache__", "web"))
    shutil.copy2(ROOT / "roc.py", folder / "roc.py")
    shutil.copytree(ROOT / "research", folder / "research", ignore=shutil.ignore_patterns("*.jsonl"))
    shutil.copytree(ROOT / "rebuild/2008-06", folder / "rebuild/2008-06",
                    ignore=shutil.ignore_patterns("out", "__pycache__", "*.obj", "*.pdb", "*.exe", "*.dll"))
    (folder / "clients").mkdir()
    for path in (ROOT / "clients").glob("*.json"):
        shutil.copy2(path, folder / "clients" / path.name)
    if (ROOT / "local/config").exists():
        shutil.copytree(ROOT / "local/config", folder / "local/config", dirs_exist_ok=True)
    if (ROOT / "tools").exists():
        link_directory(ROOT / "tools", folder / "tools")
    if (ROOT / "src").exists():
        link_directory(ROOT / "src", folder / "src")
    for path in (ROOT / "clients").iterdir():
        if path.is_dir():
            link_directory(path, folder / "clients" / path.name)
    work = folder / "work/2008-06"
    work.mkdir(parents=True, exist_ok=True)
    for path in (ROOT / "work/2008-06").glob("*.json*"):
        shutil.copy2(path, work / path.name)
    return folder


def run_private(initial, receive_commands=True):
    folder = workspace(lambda message: print("ROC_EVENT " + json.dumps({"event": "log", "slot": 0, "message": message}), flush=True))
    env = dict(os.environ, ROC_NATIVE_EVIDENCE_ROOT=str(ROOT), ROC_INTEGRATOR_PRIVATE="1")
    process = subprocess.Popen([sys.executable, "-u", "-m", "roc.gui_worker"], cwd=folder, env=env,
                               stdin=subprocess.PIPE, text=True, encoding="utf-8",
                               creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
    process.stdin.write(json.dumps(initial) + "\n")
    process.stdin.flush()
    if receive_commands:
        def forward():
            try:
                for line in sys.stdin:
                    process.stdin.write(line)
                    process.stdin.flush()
            except (BrokenPipeError, OSError):
                pass
            finally:
                process.stdin.close()
        threading.Thread(target=forward, daemon=True).start()
    try:
        code = process.wait()
    except KeyboardInterrupt:
        process.stdin.write('{"action":"stop"}\n')
        process.stdin.flush()
        code = process.wait()
    finally:
        if not receive_commands:
            process.stdin.close()
    if code:
        raise SystemExit(code)
