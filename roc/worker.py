"""Worker: lease a function from the server, draft C++ with AI, compile, diff,
retry with feedback, submit the best result under your username."""
import json
import re
import threading
import time
import urllib.error
import urllib.request
import uuid
from pathlib import Path

from roc import clients, draft, match, setup

ROOT = Path(__file__).resolve().parent.parent
SETTINGS = ROOT / "roconstruct-settings.json"
USER_RE = re.compile(r"^[A-Za-z0-9_.-]{2,32}$")


def load_settings():
    try:
        return json.loads(SETTINGS.read_text())
    except (OSError, ValueError):
        return {}


def save_settings(**changes):
    s = load_settings()
    s.update({k: v for k, v in changes.items() if v is not None})
    SETTINGS.write_text(json.dumps(s, indent=1))
    return s


class Api:
    def __init__(self, server, token=None):
        self.server = server.rstrip("/")
        if not self.server.startswith("http"):
            self.server = "http://" + self.server
        self.token = token

    def call(self, path, payload=None, timeout=60):
        data = json.dumps(payload).encode() if payload is not None else None
        req = urllib.request.Request(self.server + path, data=data, headers={"Content-Type": "application/json"})
        if self.token:
            req.add_header("X-Roc-Token", self.token)
        try:
            with urllib.request.urlopen(req, timeout=timeout) as r:
                return json.loads(r.read())
        except urllib.error.HTTPError as error:
            try:
                msg = json.loads(error.read()).get("error")
            except ValueError:
                msg = error.reason
            raise RuntimeError("server said: %s" % msg)
        except urllib.error.URLError as error:
            raise RuntimeError("cannot reach server %s (%s). Is it running? Right address?"
                               % (self.server, error.reason))


def usable_clients(info, log=print):
    """Clients this machine can work on: same exe hash as the server, compiler present."""
    have, compilers = [], setup.compilers()
    local = clients.load()
    for name, remote in sorted(info["clients"].items()):
        entry = local.get(name)
        if not entry or entry.get("sha256") != remote.get("sha256"):
            log("  skip %s: clients.json differs from server (git pull)" % name)
        elif clients.status(name, entry) != "ok":
            log("  skip %s: put your RobloxApp_client.exe in clients/%s/ (status: %s)"
                % (name, name, clients.status(name, entry)))
        elif not (Path(ROOT / "work" / name / "functions.jsonl")).exists():
            log("  skip %s: run  roc analyze %s" % (name, name))
        elif remote.get("compiler_build") not in compilers:
            log("  skip %s: compiler %s missing (roc install)" % (name, remote.get("compiler")))
        else:
            have.append(name)
    return have


def run(server, user, token=None, model=None, rounds=4, max_size=256, use_revng=True,
        max_jobs=None, log=print, forever=False, only=None):
    """forever: survive server/network outages (retry every minute) for overnight runs.
    only: restrict to these clients (one-click links)."""
    if not USER_RE.match(user or ""):
        raise SystemExit("Pick a username: 2-32 letters, digits, _ . -")
    api = Api(server, token)
    while True:
        try:
            info = api.call("/v1/info")
            break
        except RuntimeError as error:
            if not forever:
                raise
            log("%s  Retrying in 60 s." % error)
            time.sleep(60)
    if only:
        info["clients"] = {k: v for k, v in info["clients"].items() if k in only}
    have = usable_clients(info, log)
    if not have:
        raise SystemExit("Nothing to work on from this PC yet (see the skip reasons above).")
    model = draft.pick_model(model)
    if not model:
        raise SystemExit("AI workers need Ollama with a code model:  ollama pull qwen2.5-coder:7b\n"
                         "No GPU? You can still help by hand: roc claim / roc check / roc submit.")
    revng = use_revng and draft.revng_available()
    worker = uuid.uuid4().hex[:12]
    log("Worker %s as '%s' on %s | model %s | Rev.ng %s" % (worker, user, ", ".join(have), model,
                                                         "on" if revng else "off"))
    done = matched = 0
    while max_jobs is None or done < max_jobs:
        try:
            job = api.call("/v1/lease", {"user": user, "worker": worker, "clients": have,
                                         "mode": "ai", "max_size": max_size})["job"]
        except RuntimeError as error:
            if not forever:
                raise
            log("%s  Retrying in 60 s." % error)
            time.sleep(60)
            continue
        if not job:
            if max_jobs is not None:
                break
            log("No open functions right now; checking again in 60 s.")
            time.sleep(60)
            continue
        done += 1
        matched += work_one(api, user, job, info, model, rounds, revng, log) == 100
        if done % 10 == 0:
            log("== %s: %d functions tried, %d matched this session ==" % (time.strftime("%H:%M"), done, matched))
    log("Worker finished %d job(s), %d matched." % (done, matched))


def work_one(api, user, job, info, model, rounds, revng, log):
    client, addr = job["client"], job["addr"]
    flags = info["clients"][client].get("flags")
    log("[%s %s] %d bytes, %s, best so far %d%%" % (client, addr, job["size"], job["unit"], job["score"]))
    stop = threading.Event()

    def beat():
        while not stop.wait(job.get("heartbeat", 60)):
            try:
                api.call("/v1/heartbeat", {"lease": job["lease"]})
            except RuntimeError:
                pass

    threading.Thread(target=beat, daemon=True).start()
    try:
        examples = [e["source"] for e in api.call("/v1/examples?client=%s&n=3" % client)]
        code, _, _ = match.target(client, addr)
        hint = draft.revng_c(code, int(addr, 16)) if revng else None
        score, src = draft.llm_rounds(client, addr, model, rounds, hint, (job["source"], job["score"]),
                                      log, flags, examples)
        if src and score > job["score"]:
            r = api.call("/v1/submit", {"lease": job["lease"], "user": user, "client": client,
                                        "addr": addr, "score": score, "source": src})
            log("  submitted %d%% (%s)" % (r["stored"], "verified by server" if r["verified"] else "not re-checked"))
            return r["stored"]
        api.call("/v1/release", {"lease": job["lease"]})
        log("  no improvement (best %d%%), released" % job["score"])
        return job["score"]
    except (Exception, SystemExit) as error:  # never leave a lease hanging on a crash
        log("  error: %s" % error)
        try:
            api.call("/v1/release", {"lease": job["lease"]})
        except RuntimeError:
            pass
        return 0
    finally:
        stop.set()


def submit_files(server, user, client, addrs=None, token=None, log=print):
    """Upload hand-written src/<client>/*.cpp to the server (checked locally first)."""
    api = Api(server, token)
    paths = sorted((ROOT / "src" / client).glob("*.cpp"))
    if addrs:
        paths = [p for p in paths if p.stem in addrs]
    for p in paths:
        try:
            score, _, _ = match.check(client, p.stem, p)
        except match.CompileError as error:
            log("%s  skipped, does not compile: %s" % (p.stem, str(error).splitlines()[0]))
            continue
        r = api.call("/v1/submit", {"user": user, "client": client, "addr": p.stem,
                                    "score": score, "source": p.read_text()})
        log("%s  %3d%%  %s" % (p.stem, r["stored"], "new best" if r["improved"] else "server already has this or better"))
