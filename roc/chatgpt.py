"""Official ChatGPT plan authorization and Responses inference.

OAuth credentials are encrypted locally with a key held by the OS keyring.
Account labels, client IDs, model choices, and the stable host ID are public metadata.
Authlib handles OAuth/PKCE, PyJWT validates identity, and OpenAI handles SSE.
"""
import functools
import hashlib
import json
import os
import secrets
import threading
import time
import uuid
import webbrowser
from contextlib import contextmanager
from http.server import BaseHTTPRequestHandler, HTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlsplit

from roc.providers import ProviderError

ISSUER = "https://auth.openai.com"
RESOURCE = "https://api.openai.com/v1"
SCOPES = "openid profile email offline_access resource.invoke chatgpt.tokens.use.direct"
SERVICE = "RoConstruct ChatGPT plan"
USAGE_URL = "https://chatgpt.com/settings/usage"
_mutex = threading.RLock()


def _dependencies():
    try:
        import keyring
        import jwt
        import openai
        import requests
        from authlib.integrations.requests_client import OAuth2Session
        from filelock import FileLock
    except ImportError:
        raise ProviderError("provider_auth", "Install ChatGPT support: python -m pip install -r packaging/requirements-chatgpt.txt") from None
    return keyring, jwt, openai, requests, OAuth2Session, FileLock


def directory():
    override = os.environ.get("ROCONSTRUCT_CHATGPT_DIR")
    if override:
        return Path(override).expanduser()
    root = Path(os.environ.get("APPDATA") or Path.home() / ".config")
    return root / "roconstruct-chatgpt"


@contextmanager
def _locked():
    *_, FileLock = _dependencies()
    directory().mkdir(parents=True, exist_ok=True)
    with _mutex, FileLock(str(directory() / "accounts.lock"), timeout=600):
        yield


def _read():
    path = directory() / "accounts.json"
    if not path.exists():
        return {"host_id": "urn:uuid:" + str(uuid.uuid4()), "active": None, "accounts": {}}
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
        if not isinstance(data.get("accounts"), dict) or not data.get("host_id"):
            raise ValueError()
        return data
    except (OSError, ValueError, AttributeError):
        raise ProviderError("provider_auth", "ChatGPT account registry could not be read.") from None


def _write(data):
    path = directory() / "accounts.json"
    temp = path.with_suffix(".tmp")
    temp.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    if os.name != "nt":
        temp.chmod(0o600)
    temp.replace(path)


def _keyring():
    keyring, *_ = _dependencies()
    backend = keyring.get_keyring()
    # Never accept a plaintext alternative or a failed keyring backend.
    secure = ("keyring.backends.Windows", "keyring.backends.macOS",
              "keyring.backends.OS_X", "keyring.backends.SecretService",
              "keyring.backends.libsecret", "keyring.backends.kwallet")
    if backend.priority <= 0 or not type(backend).__module__.startswith(secure):
        raise ProviderError("provider_auth", "A native secure OS keyring is required for ChatGPT sign-in.")
    return keyring


def _credentials(client_id):
    try:
        from cryptography.fernet import Fernet
        path = directory() / (hashlib.sha256(client_id.encode()).hexdigest() + ".enc")
        if not path.exists():
            return {}
        key = _keyring().get_password(SERVICE, client_id)
        if not key:
            raise ProviderError("provider_auth", "ChatGPT credential encryption key is missing; sign in again.")
        return json.loads(Fernet(key.encode()).decrypt(path.read_bytes()))
    except ProviderError:
        raise
    except Exception:
        raise ProviderError("provider_auth", "ChatGPT credentials could not be read from the OS keyring.") from None


def _save_credentials(client_id, tokens):
    try:
        from cryptography.fernet import Fernet
        keyring = _keyring()
        key = keyring.get_password(SERVICE, client_id)
        if not key:
            key = Fernet.generate_key().decode()
            keyring.set_password(SERVICE, client_id, key)
        # Windows credential entries have a small size limit. Keep only the
        # encryption key there and atomically store arbitrarily sized tokens.
        path = directory() / (hashlib.sha256(client_id.encode()).hexdigest() + ".enc")
        temp = path.with_suffix(".tmp")
        temp.write_bytes(Fernet(key.encode()).encrypt(json.dumps(tokens).encode()))
        if os.name != "nt":
            temp.chmod(0o600)
        temp.replace(path)
    except ProviderError:
        raise
    except Exception:
        raise ProviderError("provider_auth", "ChatGPT credentials could not be saved in the OS keyring.") from None


def _clear_credentials(client_id):
    _save_credentials(client_id, {})


@functools.lru_cache(maxsize=1)
def _discovery():
    _, _, _, requests, *_ = _dependencies()
    try:
        response = requests.get(ISSUER + "/.well-known/openid-configuration", timeout=30)
        response.raise_for_status()
        data = response.json()
        if data.get("issuer") != ISSUER:
            raise ValueError()
        for name in ("authorization_endpoint", "token_endpoint", "jwks_uri", "revocation_endpoint"):
            parsed = urlsplit(data[name])
            if parsed.scheme != "https" or parsed.netloc != "auth.openai.com":
                raise ValueError()
        return data
    except Exception:
        raise ProviderError("provider_retry", "OpenAI sign-in discovery failed.") from None


@functools.lru_cache(maxsize=1)
def _jwks():
    _, jwt, *_ = _dependencies()
    return jwt.PyJWKClient(_discovery()["jwks_uri"], lifespan=300, timeout=30)


def _identity(id_token, client_id, nonce=None, account=None):
    _, jwt, *_ = _dependencies()
    try:
        key = _jwks().get_signing_key_from_jwt(id_token).key
        identity = jwt.decode(id_token, key, algorithms=["RS256"], audience=client_id,
                              issuer=ISSUER, leeway=5,
                              options={"require": ["iss", "aud", "sub", "exp", "iat"]})
        if not isinstance(identity["sub"], str) or not identity["sub"]:
            raise ValueError()
        if nonce is not None and not secrets.compare_digest(str(identity.get("nonce", "")), nonce):
            raise ValueError()
        if account and (identity["sub"] != account["subject"] or identity["iss"] != account["issuer"]):
            raise ValueError()
        return identity
    except Exception:
        raise ProviderError("provider_auth", "OpenAI identity validation failed; account was not changed.") from None


def _normalize_tokens(tokens, previous=None):
    previous = previous or {}
    if (not isinstance(tokens.get("access_token"), str) or not tokens["access_token"]
            or str(tokens.get("token_type", "")).lower() != "bearer"):
        raise ProviderError("provider_auth", "OpenAI did not return a bearer access token.")
    try:
        expires_at = float(tokens.get("expires_at") or (time.time() + float(tokens["expires_in"])))
        if expires_at <= time.time():
            raise ValueError()
    except (KeyError, ValueError, TypeError):
        raise ProviderError("provider_auth", "OpenAI returned an invalid token expiry.") from None
    scope = tokens.get("scope", previous.get("scope", ""))
    if not isinstance(scope, str):
        raise ProviderError("provider_auth", "OpenAI returned invalid granted scopes.")
    return {"access_token": tokens["access_token"], "refresh_token": tokens.get("refresh_token", ""),
            "id_token": tokens.get("id_token", previous.get("id_token", "")), "scope": scope,
            "token_type": "Bearer", "expires_at": expires_at,
            "earliest_refresh_at": tokens.get("earliest_refresh_at", 0)}


def _callback(query, state, client_id):
    values = parse_qs(query, keep_blank_values=True)
    if any(len(value) != 1 for value in values.values()):
        raise ProviderError("provider_auth", "OpenAI callback contains duplicate parameters.")
    values = {key: value[0] for key, value in values.items()}
    if not secrets.compare_digest(values.get("state", ""), state):
        raise ProviderError("provider_auth", "OpenAI callback state did not match.")
    if values.get("error"):
        raise ProviderError("provider_auth", "ChatGPT sign-in was declined or could not be completed.")
    issued = values.get("client_id") or client_id
    if not values.get("code") or not issued or issued == "dynamic_agent_client":
        raise ProviderError("provider_auth", "OpenAI registration did not return a code and issued client ID.")
    if client_id and issued != client_id:
        raise ProviderError("provider_auth", "OpenAI callback changed the selected registration.")
    return values["code"], issued


def _oauth(client_id, **kwargs):
    *_, OAuth2Session, _ = _dependencies()
    return OAuth2Session(client_id, token_endpoint_auth_method="none", **kwargs)


def login(client_id=None, new=False, timeout=300):
    """Authorize in the user's browser; activate only after signature validation."""
    with _locked():
        _keyring()  # Check secure storage before requesting credentials.
        data = _read()
        _write(data)  # Persist host ID even if the attempt is cancelled.
        selected = None if new else client_id or data.get("active") or data.get("pending")
        account = data["accounts"].get(selected)
        if selected and not account and selected != data.get("pending"):
            raise ProviderError("provider_auth", "Unknown ChatGPT account registration.")
        previous = _credentials(selected) if selected else {}
        state, nonce, verifier = (secrets.token_urlsafe(48) for _ in range(3))
        result = {}

        class Callback(BaseHTTPRequestHandler):
            def log_message(self, *_args):
                pass  # A callback URL contains the authorization code.

            def do_GET(self):
                parsed = urlsplit(self.path)
                if parsed.path != "/auth/callback":
                    self.send_error(404)
                    return
                try:
                    result["code"], result["client_id"] = _callback(parsed.query, state, selected)
                    message = b"Return to RoConstruct to finish ChatGPT sign-in."
                    status = 200
                except ProviderError as error:
                    result["error"] = error
                    message, status = b"Sign-in could not be verified. Return to RoConstruct.", 400
                self.send_response(status)
                self.send_header("Content-Type", "text/plain; charset=utf-8")
                self.send_header("Cache-Control", "no-store")
                self.send_header("Referrer-Policy", "no-referrer")
                self.send_header("Content-Length", str(len(message)))
                self.end_headers()
                self.wfile.write(message)

        with HTTPServer(("127.0.0.1", 0), Callback) as server:
            server.timeout = 1
            redirect = "http://127.0.0.1:%d/auth/callback" % server.server_port
            extras = {"nonce": nonce, "resource": RESOURCE, "ext_agent_host_id": data["host_id"]}
            if selected:
                if previous.get("id_token"):
                    extras["id_token_hint"] = previous["id_token"]
                if account and account.get("email"):
                    extras["login_hint"] = account["email"]
                if "chatgpt.tokens.use.direct" not in previous.get("scope", "").split():
                    extras["prompt"] = "consent"
            else:
                extras["agent_name_hint"] = SERVICE
            with _oauth(selected or "dynamic_agent_client", redirect_uri=redirect, scope=SCOPES,
                        code_challenge_method="S256") as oauth:
                url, _ = oauth.create_authorization_url(_discovery()["authorization_endpoint"],
                                                        state=state, code_verifier=verifier, **extras)
            print("Continue with ChatGPT in your browser. Existing plan limits apply.", flush=True)
            print("Manage this app's usage and credits: " + USAGE_URL, flush=True)
            if not webbrowser.open(url):
                raise ProviderError("provider_auth", "Could not open the sign-in browser; set your default browser and retry.")
            deadline = time.monotonic() + timeout
            while not result and time.monotonic() < deadline:
                server.handle_request()
            if not result:
                raise ProviderError("provider_auth", "ChatGPT sign-in timed out; run roc chatgpt login again.")
            if "error" in result:
                raise result["error"]

        issued = result["client_id"]
        if not account:
            data["pending"] = issued
            _write(data)  # Reuse this registration if the code exchange expires.
        try:
            with _oauth(issued, redirect_uri=redirect) as oauth:
                tokens = oauth.fetch_token(_discovery()["token_endpoint"], code=result["code"],
                                           code_verifier=verifier, resource=RESOURCE, timeout=30)
        except Exception:
            raise ProviderError("provider_auth", "OpenAI token exchange failed; start a fresh sign-in.") from None
        identity = _identity(tokens.get("id_token", ""), issued, nonce, account)
        tokens = _normalize_tokens(tokens)
        _save_credentials(issued, tokens)
        data["accounts"][issued] = {"client_id": issued, "email": identity.get("email", ""),
                                    "subject": identity["sub"], "issuer": identity["iss"],
                                    "models": [], "label": identity.get("email") or issued}
        data["active"] = issued
        data.pop("pending", None)
        _write(data)
        if "chatgpt.tokens.use.direct" not in tokens["scope"].split():
            raise ProviderError("provider_auth", "Signed in, but ChatGPT plan usage was not authorized. Run roc chatgpt login to enable it.")
        return data["accounts"][issued]


def ready():
    if not (directory() / "accounts.json").exists():
        return False
    try:
        with _locked():
            data = _read()
            tokens = _credentials(data["active"]) if data.get("active") else {}
            return ("chatgpt.tokens.use.direct" in tokens.get("scope", "").split()
                    and bool(tokens.get("refresh_token") or tokens.get("access_token")))
    except ProviderError:
        return False


def access_token(client_id=None):
    # The file lock serializes rotating refresh tokens across threads/processes.
    with _locked():
        data = _read()
        client_id = client_id or data.get("active")
        account = data["accounts"].get(client_id)
        tokens = _credentials(client_id) if account else {}
        if "chatgpt.tokens.use.direct" not in tokens.get("scope", "").split():
            raise ProviderError("provider_auth", "ChatGPT plan sign-in required: roc chatgpt login")
        if tokens.get("access_token") and tokens.get("expires_at", 0) > time.time() + 60:
            return tokens["access_token"]
        if not tokens.get("refresh_token"):
            raise ProviderError("provider_auth", "ChatGPT session expired: roc chatgpt login")
        earliest = float(tokens.get("earliest_refresh_at") or 0)
        if time.time() < earliest:
            if tokens.get("expires_at", 0) > time.time():
                return tokens["access_token"]
            raise ProviderError("provider_retry", "ChatGPT token cannot be refreshed yet; retry later.")
        try:
            with _oauth(client_id) as oauth:
                replacement = oauth.refresh_token(_discovery()["token_endpoint"],
                                                   refresh_token=tokens["refresh_token"],
                                                   resource=RESOURCE, timeout=30)
        except Exception as error:
            code = getattr(error, "error", "")
            if code in ("invalid_grant", "invalid_refresh_token", "token_expired", "refresh_token_expired",
                        "refresh_token_invalidated", "refresh_token_reused"):
                _clear_credentials(client_id)
                raise ProviderError("provider_auth", "ChatGPT sign-in expired or was disconnected: roc chatgpt login") from None
            if code == "invalid_client":
                raise ProviderError("provider_auth", "ChatGPT client registration was refused; check the saved registration.") from None
            raise ProviderError("provider_retry", "ChatGPT token refresh failed temporarily; retry later.") from None
        if replacement.get("id_token"):
            _identity(replacement["id_token"], client_id, account=account)
        refreshed = _normalize_tokens(replacement, tokens)
        if not refreshed.get("refresh_token"):
            raise ProviderError("provider_auth", "OpenAI refresh did not return its replacement refresh token.")
        _save_credentials(client_id, refreshed)
        if "chatgpt.tokens.use.direct" not in refreshed["scope"].split():
            raise ProviderError("provider_auth", "ChatGPT plan usage permission was removed: roc chatgpt login")
        return refreshed["access_token"]


def status():
    if not (directory() / "accounts.json").exists():
        return {"active": None, "accounts": {}}
    with _locked():
        return _read()


def use(client_id):
    with _locked():
        data = _read()
        if client_id not in data["accounts"]:
            raise ProviderError("provider_auth", "Unknown ChatGPT registration; run roc chatgpt accounts.")
        tokens = _credentials(client_id)
        if not tokens.get("access_token") or "chatgpt.tokens.use.direct" not in tokens.get("scope", "").split():
            raise ProviderError("provider_auth", "This account needs sign-in: roc chatgpt login --account " + client_id)
        data["active"] = client_id
        _write(data)


def logout(client_id=None):
    with _locked():
        data = _read()
        client_id = client_id or data.get("active")
        if client_id not in data["accounts"]:
            return
        tokens = _credentials(client_id)
        remote_ok = not tokens.get("refresh_token")
        if not remote_ok:
            _, _, _, requests, *_ = _dependencies()
            for attempt in range(3):
                try:
                    response = requests.post(_discovery()["revocation_endpoint"],
                                             data={"token": tokens["refresh_token"], "token_type_hint": "refresh_token",
                                                   "client_id": client_id}, timeout=30)
                    remote_ok = response.status_code == 200
                    if remote_ok or response.status_code < 500:
                        break
                except Exception:
                    pass
                if attempt < 2:
                    time.sleep(2 ** attempt)
        _clear_credentials(client_id)
        if data.get("active") == client_id:
            data["active"] = None
        _write(data)
        if not remote_ok:
            print("Signed out locally. Remote revocation was not confirmed; disconnect the app in ChatGPT Settings.")


def _client(timeout=180, client_id=None):
    _, _, openai, *_ = _dependencies()
    return openai.OpenAI(api_key=access_token(client_id), base_url=RESOURCE, max_retries=0,
                         timeout=timeout, organization="", project="")


def _failure(error, status=None, request_id=""):
    code = getattr(error, "code", None) if not isinstance(error, dict) else error.get("code")
    code = code if isinstance(code, str) and code.replace("_", "").isalnum() else "request_failed"
    request_id = request_id if request_id.replace("-", "").replace("_", "").isalnum() else ""
    suffix = " (request %s)" % request_id if request_id else ""
    if code == "subscription_sharing_usage_limit_exceeded":
        return ProviderError("cloud_budget", "ChatGPT app/plan limit reached. Review " + USAGE_URL + suffix, status)
    if status in (401, 403) or code in ("subscription_sharing_user_not_eligible", "subscription_sharing_invalid_user"):
        return ProviderError("provider_auth", "ChatGPT plan request refused: %s. Check account permission or sign in again.%s" % (code, suffix), status)
    category = "provider_retry" if status in (408, 429) or (status and status >= 500) or code in (
        "subscription_sharing_usage_unavailable", "subscription_sharing_user_unavailable") else "provider_error"
    return ProviderError(category, "ChatGPT request failed: %s%s%s" %
                         (code, " (HTTP %s)" % status if status else "", suffix), status)


def models(refresh=True):
    if not refresh:
        data = status()
        return data["accounts"].get(data.get("active"), {}).get("models", [])
    _, _, openai, *_ = _dependencies()
    selected = status().get("active")
    if not selected:
        raise ProviderError("provider_auth", "ChatGPT plan sign-in required: roc chatgpt login")
    try:
        with _client(30, selected) as client:
            catalog = client.get("/models", cast_to=dict[str, object])
        rows = [{"slug": row["slug"], "display_name": row.get("display_name", row["slug"])}
                for row in catalog.get("models", []) if row.get("visibility") == "list" and row.get("slug")]
    except openai.APIStatusError as error:
        raise _failure(error, error.status_code, error.request_id or "") from None
    except openai.APIConnectionError:
        raise ProviderError("provider_retry", "ChatGPT model discovery could not reach OpenAI.") from None
    if not rows:
        raise ProviderError("provider_auth", "OpenAI returned no available ChatGPT plan models.")
    with _locked():
        data = _read()
        data["accounts"][selected]["models"] = rows
        _write(data)
    return rows


def default_model():
    rows = models(refresh=False)
    return "chatgpt:" + rows[0]["slug"] if rows and ready() else None


def generate(remote, messages, options):
    from roc.providers import Generation, strip_reasoning
    _, _, openai, *_ = _dependencies()
    # This route rejects system messages, sampling knobs, and max_output_tokens.
    instructions = "\n".join(message["content"] for message in messages if message["role"] == "system")
    inputs = [message for message in messages if message["role"] != "system"]
    body = {"model": remote, "instructions": instructions, "input": inputs, "store": False, "stream": True}
    if options.get("reasoning_effort") not in (None, "auto"):
        body["reasoning"] = {"effort": options["reasoning_effort"]}
    completed, pieces = None, []
    text_size = 0
    request_id = ""
    try:
        with _client(options["timeout"]) as client:
            with client.responses.create(**body) as stream:
                request_id = stream.response.headers.get("x-request-id", "")
                for event in stream:
                    if event.type == "response.output_text.delta":
                        text_size += len(event.delta)
                        # A local memory guard, not a server token/billing cap.
                        if text_size > int(options["max_tokens"]) * 8:
                            raise ProviderError("provider_error", "ChatGPT reply exceeded the local text limit; raise the output budget.")
                        pieces.append(event.delta)
                    elif event.type == "response.completed":
                        completed = event.response
                    elif event.type == "response.failed":
                        raise _failure(event.response.error, request_id=request_id)
                    elif event.type == "response.incomplete":
                        raise ProviderError("provider_error", "ChatGPT response was incomplete; no candidate was accepted.")
                    elif event.type == "error":
                        raise _failure(event, request_id=request_id)
    except openai.APIStatusError as error:
        raise _failure(error, error.status_code, error.request_id or "") from None
    except openai.APIConnectionError:
        raise ProviderError("provider_retry", "ChatGPT stream was interrupted; no candidate was accepted.") from None
    if completed is None:
        raise ProviderError("provider_retry", "ChatGPT stream ended without response.completed.")
    text = strip_reasoning("".join(pieces))
    usage = completed.usage
    return Generation(text, {"messages": messages + [{"role": "assistant", "content": text}]},
                      input_tokens=usage.input_tokens if usage else 0,
                      output_tokens=usage.output_tokens if usage else 0,
                      cached_tokens=getattr(usage.input_tokens_details, "cached_tokens", 0) if usage else 0,
                      reasoning_tokens=getattr(usage.output_tokens_details, "reasoning_tokens", None) if usage else None,
                      provider="chatgpt", model=remote, request_id=request_id,
                      finish_reason="completed")
