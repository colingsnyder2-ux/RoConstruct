"""Signed worker handoff: website answers -> local config -> worker run.

The website can only produce a plain roconstruct:// link (it is a static page and
holds no secret). Everything the link claims is therefore re-validated here and
then written to a *signed* local config with a per-machine secret, so the worker
that starts later runs exactly the setup the helper agreed to and nothing that was
edited on disk afterwards.
"""
import hashlib
import hmac
import json
import os
import secrets
import subprocess
import sys
import time
from pathlib import Path
from urllib.parse import urlencode

ROOT = Path(__file__).resolve().parent.parent
CONFIG = ROOT / "roconstruct-worker.json"
MODES = ("cloud", "local")

# What the website is allowed to put in a link. Anything else is ignored, so a
# crafted link cannot smuggle in flags, extra hosts or a token of its choosing.
LINK_FIELDS = ("user", "client", "server", "token", "mode", "model", "cloud")


def secret():
    """Per-machine signing key, created once and kept in settings."""
    from roc import worker
    saved = worker.load_settings().get("handoff_secret")
    if saved and len(saved) >= 32:
        return saved.encode()
    made = secrets.token_hex(32)
    worker.save_settings(handoff_secret=made)
    return made.encode()


def canonical(payload):
    """Stable bytes for one payload, so a signature does not depend on key order."""
    trimmed = {k: payload[k] for k in sorted(payload) if payload[k] is not None}
    return json.dumps(trimmed, sort_keys=True, separators=(",", ":")).encode()


def sign(payload):
    return hmac.new(secret(), canonical(payload), hashlib.sha256).hexdigest()


def verify(data):
    """True only when `data` is a config this machine signed and nobody edited."""
    if not isinstance(data, dict):
        return False
    payload, signature = data.get("payload"), data.get("signature")
    if not isinstance(payload, dict) or not isinstance(signature, str):
        return False
    return hmac.compare_digest(sign(payload), signature)


def config_path():
    return CONFIG


def save(**fields):
    """Write a signed worker config. Only known fields are stored."""
    from roc import worker
    clean = {}
    for key in LINK_FIELDS:
        value = fields.get(key)
        if value is None or value == "":
            continue
        clean[key] = value
    clean["created"] = int(time.time())
    data = {"payload": clean, "signature": sign(clean), "version": 1}
    CONFIG.write_text(json.dumps(data, indent=1), encoding="utf-8")
    worker.save_settings(user=clean.get("user"), server=clean.get("server"),
                         token=clean.get("token"), cloud_allowed=clean.get("cloud"),
                         handoff_client=clean.get("client"))
    return clean


def load(verify_signature=True):
    """The signed config, or {} when it is missing, unreadable or tampered with."""
    try:
        data = json.loads(CONFIG.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}
    if verify_signature and not verify(data):
        return {}
    payload = data.get("payload")
    return payload if isinstance(payload, dict) else {}


def clear():
    for path in (CONFIG,):
        path.unlink(missing_ok=True)


def status():
    """What `roc doctor` prints about the handoff: signed, stale, or missing."""
    if not CONFIG.exists():
        return {"state": "missing", "detail": "no worker config yet (run: roc setup)"}
    try:
        data = json.loads(CONFIG.read_text(encoding="utf-8"))
    except (OSError, ValueError) as content_error:
        return {"state": "broken", "detail": "unreadable: %s" % content_error}
    if not verify(data):
        return {"state": "tampered",
                "detail": "signature does not match; treat it as unsafe and run: roc setup"}
    payload = data["payload"]
    age_hours = max(0.0, (time.time() - float(payload.get("created", 0))) / 3600)
    return {"state": "signed", "payload": payload,
            "detail": "signed %s ago by this PC" % _ago(age_hours)}


def _ago(hours):
    if hours < 1:
        return "%d min" % max(1, int(hours * 60))
    if hours < 48:
        return "%d h" % int(hours)
    return "%d days" % int(hours / 24)


# ---------- link <-> config ----------

def link(user, client, server, cloud=True, mode="cloud", model=None, token=None):
    """The roconstruct:// URL the website hands to the protocol handler."""
    from roc import link as link_module
    query = {"user": user, "client": client, "server": server,
             "mode": mode if mode in MODES else "cloud",
             "cloud": "1" if cloud else "0"}
    if model:
        query["model"] = model
    if token:
        query["token"] = token
    if not link_module.CLIENT_RE.match(client) or not link_module.SERVER_RE.match(server):
        raise SystemExit("Refusing to build a link for client %r / server %r." % (client, server))
    return "%s://work?%s" % (link_module.SCHEME, urlencode(query))


def from_url(url):
    """Validate a website link and return its payload. Nothing is written yet."""
    from roc import link as link_module, worker
    parts = link_module.parse_full(url)
    payload = {key: parts.get(key) or None for key in LINK_FIELDS}
    payload["cloud"] = parts.get("cloud") == "1"
    mode = payload.get("mode")
    payload["mode"] = mode if mode in MODES else "cloud"
    payload["client"] = payload.get("client")
    payload["server"] = (payload.get("server") or "").rstrip("/")
    if not worker.USER_RE.match(payload.get("user") or ""):
        raise SystemExit("That link has no usable username (2-32 letters, digits, . _ -).")
    if not link_module.CLIENT_RE.match(payload.get("client") or ""):
        raise SystemExit("That link has no usable client name.")
    if not link_module.SERVER_RE.match(payload.get("server") or ""):
        raise SystemExit("That link has no usable server address.")
    return payload


def apply(url=None, **answers):
    """Fold a validated link (or interactive answers) into a signed config."""
    payload = from_url(url) if url else {}
    payload.update({k: v for k, v in answers.items() if v is not None})
    if payload.get("mode") == "local" and not payload.get("model"):
        payload.pop("model", None)
    return save(**payload)


# ---------- launching ----------

def launch_command():
    """How a background worker starts: the Windows launcher, or this Python."""
    if os.name == "nt":
        return [str(ROOT / "roc.cmd"), "launch"]
    return [sys.executable, str(ROOT / "roc.py"), "launch"]


def start(detached=True, log=print):
    """Start the worker in its own console window so this one can be closed."""
    if not load():
        raise SystemExit("No signed worker config yet. Run: roc setup")
    flags = getattr(subprocess, "CREATE_NO_WINDOW", 0) if os.name == "nt" else 0
    if detached and os.name == "nt":
        line = 'cmd /c start "RoConstruct worker" "%s" launch' % (ROOT / "roc.cmd")
        subprocess.Popen(line, shell=True, creationflags=flags)
    else:
        # Linux has no `start`; a new session keeps the worker alive after the shell exits.
        subprocess.Popen(launch_command(), creationflags=flags,
                         start_new_session=os.name != "nt")
    log("Worker starting in a new window. Close that window to stop it.")
    return True


def run_now(args=()):
    """Run the worker in this console using the signed config."""
    from roc import worker
    payload = load()
    if not payload:
        raise SystemExit("No signed worker config yet. Run: roc setup")
    known = list(args) or ["--client", payload["client"]]
    return worker.main_args(payload, known)