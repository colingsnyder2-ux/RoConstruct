"""Match leased functions with the contributor's own coding-agent CLI.

`roc agent` leases one function at a time from the group server, writes it to
src/<client>/<addr>.cpp (seeded with the server's best source), and hands it to
Claude Code (`claude -p`) or Codex (`codex exec`). The agent edits the file and
re-runs `roc check` itself, so it pays with whatever plan or key that CLI is
signed in with on this PC. Afterwards the file is re-scored here: improvements
are submitted under the lease, regressions are rolled back.
"""
import os
import shutil
import subprocess
import sys
import threading
import uuid
from pathlib import Path

from roc import match, worker

ROOT = Path(__file__).resolve().parent.parent
CLIS = ("claude", "codex")

PROMPT = """You are matching one function of the {client} Roblox client for RoConstruct,
a matching-decompilation project. Goal: C++ that the client's original MSVC
compiles to exactly the target bytes.

File to edit (edit ONLY this file): {path}
Score it after every edit with:   {check}
That prints the score and an assembly diff ('-' = target, '+' = yours).
Current best: {score}%  (unit: {unit}, {size} bytes)

Rules:
- No inline assembly, __emit, or byte arrays standing in for code.
- Keep the first `// roc` header line if there is one.
- Matched files in src/{client}/ show this codebase's style, class layouts and
  calling conventions; docs/AI_WORKER_GUIDE.md has repair advice.
- Stop at 100%, or when several edits in a row bring no gain.
- Leave the best-scoring version in the file when you stop.
"""


GOAL_PROMPT = """You are working on RoConstruct, a matching-decompilation project for old Roblox
clients: write C++ that each client's original MSVC compiles to the exact target
bytes. Read CLAUDE.md and docs/AI_WORKER_GUIDE.md first.

Your goal: {goal}

Run project commands as:  {roc} <command>   (`{roc} --help` lists them all).
Useful: doctor, pull, next, claim, check, classify, libs, ref, lint, submit.
Library code (RakNet, zlib, Ogre, ...) is open source: search the web for the
exact original version's source and port it rather than guessing.

Rules: no inline assembly, __emit or byte blobs; never edit clients/, work/ or
tools/; only add or edit files under src/. Submit each function that improves
with `{roc} submit <client> <addr>` (the server re-verifies). Work through as
much of the goal as you can in about {minutes} minutes, then stop and summarize
what matched, what improved, and what blocked you.
"""


def roc_command():
    return '"%s" roc.py' % Path(sys.executable).as_posix()


def check_command():
    return roc_command() + " check"


def command(cli, model=None, goal=False):
    """argv for one non-interactive agent run; the prompt goes on stdin.

    Goal mode may run any roc.py command and search the web; single-function
    mode may only run `roc.py check`.
    """
    if cli == "claude":
        tools = ("Read,Grep,Glob,Edit,Write,WebSearch,WebFetch,Bash(%s *)" % roc_command() if goal
                 else "Read,Grep,Glob,Edit,Bash(%s *)" % check_command())
        argv = ["claude", "-p", "--permission-mode", "acceptEdits", "--allowedTools", tools]
    elif cli == "codex":
        argv = ["codex", "exec", "--full-auto", "-C", str(ROOT), "-"]
    else:
        raise ValueError("cli must be one of: " + ", ".join(CLIS))
    if model:
        argv[2:2] = ["--model", model]
    return argv


def score(client, addr, path):
    try:
        return match.check(client, addr, path)[0]
    except match.CompileError:
        return 0


def _kill(process):
    # The npm shims are .cmd files on Windows: kill the whole tree, not just cmd.exe.
    if os.name == "nt":
        subprocess.run(["taskkill", "/T", "/F", "/PID", str(process.pid)], capture_output=True)
    else:
        process.kill()


def run_agent(cli, prompt, model=None, minutes=20, log=print, goal=False):
    exe = shutil.which(cli)
    if not exe:
        raise SystemExit("%s CLI not found. Install it and sign in first (see docs/agent-cli.md)." % cli)
    argv = command(cli, model, goal)
    argv[0] = exe
    process = subprocess.Popen(argv, cwd=ROOT, stdin=subprocess.PIPE, text=True, encoding="utf-8")
    process.stdin.write(prompt)
    process.stdin.close()
    try:
        return process.wait(timeout=minutes * 60)
    except subprocess.TimeoutExpired:
        log("  agent hit the %d-minute limit; stopping it." % minutes)
        _kill(process)
        process.wait()
        return None


def work_one(api, user, agent_id, job, cli, model, minutes, log):
    client, addr = job["client"], job["addr"]
    path = ROOT / "src" / client / ("%s.cpp" % addr)
    if not path.exists():
        best = {}
        if job.get("score"):
            try:
                best = api.call("/v1/source?client=%s&addr=%s" % (client, addr)) or {}
            except (worker.ApiFailure, OSError, ValueError):
                pass
        if best.get("source"):
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(best["source"], encoding="utf-8")
        else:
            match.claim(client, addr)
    before_text = path.read_text(encoding="utf-8", errors="replace")
    before = score(client, addr, path)
    log("%s %s  %s  %d bytes  %d%%  -> %s" % (client, addr, job.get("unit", ""), job.get("size", 0), before, path))
    stop = threading.Event()

    def beat():
        hb = worker.Api(",".join(api.servers), api.token)
        while not stop.wait(job.get("heartbeat", 60)):
            try:
                if not hb.call("/v1/heartbeat", {"lease": job["lease"]}).get("ok"):
                    return
            except RuntimeError:
                return

    threading.Thread(target=beat, daemon=True).start()
    try:
        prompt = PROMPT.format(client=client, path=path.relative_to(ROOT).as_posix(), unit=job.get("unit", "?"),
                               check="%s %s %s" % (check_command(), client, addr),
                               score=before, size=job.get("size", 0))
        run_agent(cli, prompt, model, minutes, log)
    finally:
        stop.set()
    after = score(client, addr, path)
    if after < before:
        path.write_text(before_text, encoding="utf-8")
        log("  agent left %d%% < %d%%; restored the previous file." % (after, before))
        after = before
    match.save_score(client, addr, after)
    if after > job.get("score", 0):
        r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "worker": agent_id,
                                    "model": "agent:" + cli, "client": client, "addr": addr,
                                    "score": after, "source": path.read_text(encoding="utf-8", errors="replace")})
        log("  submitted: server stored %s%%" % r.get("stored"))
    else:
        api.call("/v1/release", {"lease": job["lease"], "cooldown": 60})
        log("  no gain over the server's %d%%; released." % job.get("score", 0))
    return after


def run(server, user, token=None, cli="claude", model=None, client=None, jobs=1, max_size=256,
        minutes=20, log=print):
    api = worker.Api(server, token)
    have = worker.usable_clients(api.call("/v1/info"), log)
    if client:
        have = [name for name in have if name == client]
    if not have:
        raise SystemExit("No usable client%s on this PC (run: roc doctor)." % (" " + client if client else ""))
    agent_id = "agent-" + uuid.uuid4().hex[:8]
    matched = 0
    for _ in range(jobs):
        job = api.call("/v1/lease", {"user": user, "worker": agent_id, "clients": have, "mode": "ai",
                                     "model": "agent:" + cli, "max_size": max_size})["job"]
        if not job:
            log("No open functions right now.")
            break
        matched += work_one(api, user, agent_id, job, cli, model, minutes, log) == 100
    log("Agent session: %d matched." % matched)


def run_goal(cli, goal, model=None, minutes=120, log=print):
    """One open-ended session, e.g. "match as many 2008-06 RakNet functions as you can"."""
    log("Agent goal (%s, up to %d min): %s" % (cli, minutes, goal))
    return run_agent(cli, GOAL_PROMPT.format(goal=goal, roc=roc_command(), minutes=minutes),
                     model, minutes, log, goal=True)
