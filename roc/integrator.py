"""Private contributor workspaces for controlled, parallel native integration sessions."""
import json
from contextlib import contextmanager
import os
import re
import shutil
import subprocess
import sys
import threading
import time
import uuid
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def link_directory(source, target):
    if os.name == "nt":
        subprocess.run(["cmd", "/d", "/c", "mklink", "/J", str(target), str(source)],
                       check=True, capture_output=True, stdin=subprocess.DEVNULL, timeout=30)
    else:
        target.symlink_to(source, target_is_directory=True)


def workspace(log=print):
    """Copy runtime and rebuild inputs; source overlays, claims and outputs remain private."""
    started = time.monotonic()
    folder = ROOT / "local/integrators" / uuid.uuid4().hex
    folder.parent.mkdir(parents=True, exist_ok=True)
    log("Preparing private integrator workspace: " + str(folder))
    folder.mkdir()
    log("Startup 1/6: copying Python runtime")
    shutil.copytree(ROOT / "roc", folder / "roc", dirs_exist_ok=True,
                    ignore=shutil.ignore_patterns("__pycache__", "web"))
    shutil.copy2(ROOT / "roc.py", folder / "roc.py")
    log("Startup 2/6: copying recipe metadata")
    shutil.copytree(ROOT / "research", folder / "research", ignore=shutil.ignore_patterns("*.jsonl"))
    log("Startup 3/6: snapshotting private rebuild inputs")
    shutil.copytree(ROOT / "rebuild/2008-06", folder / "rebuild/2008-06",
                    ignore=shutil.ignore_patterns("out", "__pycache__", "*.obj", "*.pdb", "*.exe", "*.dll"))
    log("Startup 4/6: loading contributor configuration")
    (folder / "clients").mkdir()
    for path in (ROOT / "clients").glob("*.json"):
        shutil.copy2(path, folder / "clients" / path.name)
    if (ROOT / "local/config").exists():
        shutil.copytree(ROOT / "local/config", folder / "local/config", dirs_exist_ok=True)
    log("Startup 5/6: linking installed tools and source inputs")
    if (ROOT / "tools").exists():
        link_directory(ROOT / "tools", folder / "tools")
    if (ROOT / "src").exists():
        link_directory(ROOT / "src", folder / "src")
    for path in (ROOT / "clients").iterdir():
        if path.is_dir():
            link_directory(path, folder / "clients" / path.name)
    work = folder / "work/2008-06"
    log("Startup 6/6: loading client analysis")
    work.mkdir(parents=True, exist_ok=True)
    for path in (ROOT / "work/2008-06").glob("*.json*"):
        shutil.copy2(path, work / path.name)
    log("Private workspace ready (%.1fs)" % (time.monotonic() - started))
    return folder


@contextmanager
def session_workspace(log=print):
    """A dashboard restart keeps its private sources/proofs, never another run's."""
    identifier = os.environ.get('ROC_TASK_ID', '')
    if not re.fullmatch(r'[0-9a-f]{12,32}', identifier):
        yield workspace(log)
        return
    directory = ROOT/'work/integrator-sessions'
    directory.mkdir(parents=True, exist_ok=True)
    with (directory/(identifier+'.lock')).open('a+b') as handle:
        if handle.tell() == 0:
            handle.write(b'\0');handle.flush()
        handle.seek(0)
        try:
            if os.name == 'nt':
                import msvcrt
                msvcrt.locking(handle.fileno(), msvcrt.LK_NBLCK, 1)
            else:
                import fcntl
                fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError:
            raise RuntimeError('This integrator session is already active') from None
        try:
            marker = directory/(identifier+'.json')
            if marker.exists():
                folder = Path(json.loads(marker.read_text())['workspace']).resolve()
                managed = (ROOT/'local/integrators').resolve()
                if folder == managed or not folder.is_relative_to(managed) or not (folder/'roc.py').is_file():
                    raise ValueError('Session workspace is outside the managed integrator folders or missing')
                owner = folder/'integrator-session.json'
                if not owner.exists() or json.loads(owner.read_text()).get('session') != identifier:
                    raise ValueError('Private workspace belongs to a different integrator session')
                log('Reusing private integrator workspace; sources, proofs and build cache retained: '+str(folder))
                shutil.copytree(ROOT/'roc', folder/'roc', dirs_exist_ok=True,
                                ignore=shutil.ignore_patterns('__pycache__', 'web'))
                shutil.copy2(ROOT/'roc.py', folder/'roc.py')
                if (ROOT/'local/config').exists():
                    shutil.copytree(ROOT/'local/config', folder/'local/config', dirs_exist_ok=True)
            else:
                folder = workspace(log)
                from roc.integration import atomic_json
                atomic_json(folder/'integrator-session.json', {'session':identifier})
                atomic_json(marker, {'workspace':str(folder)})
            yield folder
        finally:
            handle.seek(0)
            if os.name == 'nt':
                msvcrt.locking(handle.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(handle, fcntl.LOCK_UN)


def run_private(initial, receive_commands=True, commands=None):
    def log(message):
        print("ROC_EVENT " + json.dumps({"event": "log", "slot": 0, "message": message}), flush=True)
    with session_workspace(log) as folder:
        _run_private(folder, initial, receive_commands, log, commands)


def _run_private(folder, initial, receive_commands, log, commands=None):
    log("Starting private integrator process")
    env = dict(os.environ, ROC_NATIVE_EVIDENCE_ROOT=str(ROOT), ROC_INTEGRATOR_PRIVATE="1")
    process = subprocess.Popen([sys.executable, "-u", "-m", "roc.gui_worker"], cwd=folder, env=env,
                               stdin=subprocess.PIPE, text=True, encoding="utf-8",
                               creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
    process.stdin.write(json.dumps(initial) + "\n")
    process.stdin.flush()
    log("Private integrator started; checking installed client and accepted baseline")
    if receive_commands:
        if commands is None:
            from roc.gui_worker import command_lines
            commands = command_lines(sys.stdin)
        def forward():
            try:
                for line in commands:
                    process.stdin.write(line.rstrip('\r\n')+'\n')
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
