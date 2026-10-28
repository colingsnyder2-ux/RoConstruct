"""Provider-neutral text generation for local and cloud worker models.

Keys are read from environment variables first, or a user-local secrets file
outside the repository. This module owns provider HTTP details so matching,
MSVC compilation, and server leases stay local and provider-agnostic.
"""
import base64
import json
import math
import os
import re
import shutil
import socket
import subprocess
import threading
import time
import tempfile
import urllib.error
import urllib.request
from urllib.parse import urlparse
from dataclasses import dataclass
from pathlib import Path
from roc import setup

ROOT = Path(__file__).resolve().parent.parent
CONFIG = setup.config("roconstruct-providers.json")
OLLAMA = "http://127.0.0.1:11434"

BUILTINS = {
    "codex": {"kind": "codex-cli", "base_url": "", "key_env": "", "defaults": ["default"]},
    "claude": {"kind": "claude-cli", "base_url": "", "key_env": "", "defaults": ["default", "sonnet", "opus"]},
    "chatgpt": {"kind": "chatgpt-plan", "base_url": "https://api.openai.com/v1", "key_env": ""},
    # `defaults` are the suggested remote models shown in the dashboard.
    # Runs through the signed-in OpenCode CLI (`opencode run`): OpenCode Console
    # and Go subscription allowances apply, and no API key is stored here.
    "opencode": {"kind": "opencode-cli", "base_url": "", "key_env": ""},
    "nvidia": {"kind": "openai-chat", "base_url": "https://integrate.api.nvidia.com/v1",
               "key_env": "NVIDIA_API_KEY", "defaults": ["nvidia/nemotron-3-ultra-550b-a55b"]},
    "deepseek": {"kind": "openai-chat", "base_url": "https://api.deepseek.com",
                 "key_env": "DEEPSEEK_API_KEY", "defaults": ["deepseek-flash"]},
    "openrouter": {"kind": "openai-chat", "base_url": "https://openrouter.ai/api/v1",
                   "key_env": "OPENROUTER_API_KEY", "defaults": ["google/gemini-2.5-flash"]},
    "openai": {"kind": "openai-responses", "base_url": "https://api.openai.com/v1",
               "key_env": "OPENAI_API_KEY", "defaults": ["gpt-5-mini"]},
    "anthropic": {"kind": "anthropic-messages", "base_url": "https://api.anthropic.com/v1",
                  "key_env": "ANTHROPIC_API_KEY", "api_version": "2023-06-01",
                  "defaults": ["claude-sonnet-4-6"]},
    "gemini": {"kind": "gemini", "base_url": "https://generativelanguage.googleapis.com/v1beta",
                "key_env": "GEMINI_API_KEY", "defaults": ["gemini-2.5-flash"]},
}
KINDS = {"openai-chat", "openai-responses", "anthropic-messages", "gemini"}
SYSTEM = "Reconstruct compact valid C++ only. Never emit inline assembly. Follow the user task exactly."
USER_AGENT = "RoConstruct/1.0"
# Providers that rejected the thinking field once; the process skips it after that.
NO_THINKING = set()
FATAL_ERRORS = frozenset(("provider_auth", "provider_key", "provider_config", "provider_model"))
MODEL_CATALOG = {}
MODEL_CATALOG_LOCK = threading.Lock()


class ProviderError(RuntimeError):
    """Safe error: never carries an Authorization header or provider body."""
    def __init__(self, category, message, status=None):
        self.category, self.status = category, status
        super().__init__("%s: %s" % (category, message))


@dataclass
class Generation:
    text: str
    state: object
    input_tokens: int = 0
    output_tokens: int = 0
    cached_tokens: int = 0
    latency_s: float = 0.0
    provider: str = "local"
    model: str = ""
    request_id: str = ""
    finish_reason: str = ""
    retries: int = 0
    cost: object = None
    reasoning_tokens: object = None

    def telemetry(self):
        return {"provider": self.provider, "provider_model": self.model,
                "request_id": self.request_id, "input_tokens": self.input_tokens,
                "output_tokens": self.output_tokens, "cached_tokens": self.cached_tokens,
                "generation_seconds": round(self.latency_s, 3), "finish_reason": self.finish_reason,
                "provider_retries": self.retries, "estimated_cost": self.cost,
                "reasoning_tokens": self.reasoning_tokens}


class CloudBudget:
    """Thread-safe, conservative request/token/cost guard shared by worker loops."""
    def __init__(self, requests=None, tokens=None, cost=None):
        self.max_requests = requests
        self.max_tokens = tokens
        self.max_cost = cost
        self.requests = self.tokens = 0
        self.cost = 0.0
        self.stopped = False
        self._lock = threading.Lock()

    def reserve(self, estimate_tokens=0, estimate_cost=0.0):
        with self._lock:
            if self.stopped:
                raise ProviderError("cloud_budget", "cloud requests stopped for this session")
            if self.max_requests is not None and self.requests >= self.max_requests:
                raise ProviderError("cloud_budget", "cloud request limit reached")
            if self.max_tokens is not None and self.tokens + estimate_tokens > self.max_tokens:
                raise ProviderError("cloud_budget", "cloud token limit reached")
            if self.max_cost is not None and self.cost + estimate_cost > self.max_cost:
                raise ProviderError("cloud_budget", "cloud cost limit reached")
            self.requests += 1
            self.tokens += estimate_tokens
            self.cost += estimate_cost
            return estimate_tokens, estimate_cost

    def stop(self):
        with self._lock:
            self.stopped = True

    def settle(self, ticket, tokens=0, cost=None):
        """Replace the reservation with measured usage; refunds over-estimates.

        reserve() books estimate_input+max_tokens up front, so a large output
        budget would otherwise permanently shrink the shared cap even when the
        reply used far fewer tokens.
        """
        with self._lock:
            old_tokens, old_cost = ticket
            self.tokens = max(0, self.tokens + int(tokens) - old_tokens)
            if cost is not None:
                self.cost = max(0.0, self.cost + float(cost) - old_cost)


class CloudGate:
    """Shared provider limiter and short circuit breaker for concurrent workers."""
    def __init__(self, concurrency=1, failures=3):
        self.concurrency = max(1, int(concurrency or 1))
        self.failures = max(1, int(failures or 3))
        self._locks, self._failed, self._lock = {}, {}, threading.Lock()
        self._disabled = {}

    def enter(self, provider):
        with self._lock:
            if provider in self._disabled:
                raise ProviderError(*self._disabled[provider])
            if self._failed.get(provider, 0) >= self.failures:
                raise ProviderError("provider_circuit", "%s circuit is open" % provider)
            lock = self._locks.setdefault(provider, threading.BoundedSemaphore(self.concurrency))
        lock.acquire()
        with self._lock:
            if provider in self._disabled:
                lock.release()
                raise ProviderError(*self._disabled[provider])
            if self._failed.get(provider, 0) >= self.failures:
                lock.release()
                raise ProviderError("provider_circuit", "%s circuit is open" % provider)
        return lock

    def disable(self, provider, error=None):
        with self._lock:
            error = error or ProviderError("provider_config", "%s disabled; fix configuration and restart" % provider)
            self._disabled[provider] = (error.category, str(error).partition(": ")[2], error.status)
            self._failed[provider] = self.failures

    def done(self, provider, ok):
        with self._lock:
            if provider in self._disabled:
                return
            self._failed[provider] = 0 if ok else self._failed.get(provider, 0) + 1

    def reset(self, provider):
        with self._lock:
            if provider not in self._disabled:
                self._failed.pop(provider, None)


def _read_config():
    try:
        loaded = json.loads(CONFIG.read_text(encoding="utf-8"))
        configured = loaded.get("providers", {})
    except (OSError, ValueError, TypeError):
        configured = {}
    out = {name: dict(value) for name, value in BUILTINS.items()}
    for name, value in configured.items():
        if name in ("chatgpt", "opencode", "codex", "claude"):
            continue  # Reserved for CLI sign-in providers; never user-overridden.
        if (isinstance(value, dict) and value.get("kind") in KINDS and _safe_base_url(value.get("base_url"))
                and value.get("key_env")):
            out[name] = dict(value)
    return out


def providers():
    """Public non-secret provider registry."""
    registry = _read_config()
    registry["codex"]["defaults"] = codex_models()
    return registry


def codex_models():
    """Use the installed CLI's public catalog, without reading account credentials."""
    home = Path(os.environ.get("CODEX_HOME", Path.home() / ".codex")).expanduser()
    try:
        rows = json.loads((home / "models_cache.json").read_text(encoding="utf-8")).get("models") or []
    except (OSError, ValueError, AttributeError):
        return ["default"]
    return list(dict.fromkeys(["default", *(row["slug"] for row in rows
        if isinstance(row, dict) and isinstance(row.get("slug"), str) and row["slug"]
        and row.get("visibility", "list") == "list")]))


def provider_models(name, config):
    """Public model discovery only; never sends prompts or credentials."""
    if name != 'openrouter':
        return config.get('defaults', [])
    url = _url(config, '/models')
    with MODEL_CATALOG_LOCK:
        expires, models = MODEL_CATALOG.get(url, (0, config.get('defaults', [])))
        if time.monotonic() < expires:
            return list(models)
        try:
            request = urllib.request.Request(url, headers={'User-Agent': USER_AGENT})
            with urllib.request.urlopen(request, timeout=5) as response:
                rows = json.load(response)['data']
            found = sorted({row['id'] for row in rows if isinstance(row, dict)
                and isinstance(row.get('id'), str) and row['id']
                and 'text' in ((row.get('architecture') or {}).get('output_modalities') or ['text'])})
            if not found:
                raise ValueError('Empty model catalog')
            models = found
            expires = time.monotonic() + 300
        except (OSError, ValueError, KeyError, TypeError):
            expires = time.monotonic() + 30  # retain last catalog through an outage
        MODEL_CATALOG[url] = expires, models
        return list(models)


def secrets_path():
    """User-local key file; never the repository settings/config file."""
    override = os.environ.get("ROCONSTRUCT_SECRETS_FILE")
    if override:
        return Path(override).expanduser()
    root = Path(os.environ.get("APPDATA", Path.home() / ".roconstruct"))
    return root / "roconstruct-secrets.json"


def secret(key_env):
    """Return an environment key, then a local JSON secret, without logging it."""
    value = os.environ.get(key_env)
    if value:
        return value.strip()
    try:
        data = json.loads(secrets_path().read_text(encoding="utf-8"))
    except (OSError, ValueError, TypeError):
        return ""
    value = data.get(key_env) if isinstance(data, dict) else ""
    return value.strip() if isinstance(value, str) else ""

def key_available(key_env):
    return bool(secret(key_env))


def save_secret(key_env, value):
    """Save one key in the user-local file, atomically; never print the value."""
    if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", key_env or "") or not str(value or "").strip():
        raise ValueError("invalid secret")
    path = secrets_path()
    try:
        data = json.loads(path.read_text(encoding="utf-8")) if path.exists() else {}
    except (OSError, ValueError, TypeError):
        data = {}
    if not isinstance(data, dict):
        data = {}
    data[key_env] = str(value).strip()
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + ".tmp")
    temporary.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    temporary.replace(path)
    if os.name != "nt":
        try:
            path.chmod(0o600)
        except OSError:
            pass


def _safe_base_url(value):
    """Provider config must never persist userinfo or query-string secrets."""
    parsed = urlparse(str(value or ""))
    return (parsed.scheme == "https" and bool(parsed.netloc) and not parsed.username and
            not parsed.password and not parsed.query and not parsed.fragment)


def save_provider(name, kind, base_url, key_env, **extra):
    if name in ("codex", "claude"):
        raise ValueError(name + " is reserved for the signed-in CLI")
    if name == "chatgpt":
        raise ValueError("chatgpt is reserved for official ChatGPT plan sign-in")
    if name == "opencode":
        raise ValueError("opencode is reserved for the signed-in OpenCode CLI; no key needed")
    if not re.match(r"^[A-Za-z][A-Za-z0-9_-]{0,63}$", name or ""):
        raise ValueError("provider name must be letters, digits, _ or -")
    if kind not in KINDS:
        raise ValueError("unknown provider kind")
    if not _safe_base_url(base_url):
        raise ValueError("provider URL must be https without credentials, query, or fragment")
    if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", key_env or ""):
        raise ValueError("key environment variable is invalid")
    try:
        data = json.loads(CONFIG.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        data = {}
    data.setdefault("providers", {})[name] = {"kind": kind, "base_url": base_url.rstrip("/"),
                                                  "key_env": key_env, **extra}
    CONFIG.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def save_pricing(name, model, input_per_million, output_per_million):
    """Save user-supplied USD rates for one exact remote model name."""
    if name == "chatgpt":
        raise ValueError("ChatGPT plan usage has no API USD pricing; manage app limits in ChatGPT Settings > Usage")
    config = _read_config().get(name)
    if not config or not str(model or "").strip():
        raise ValueError("unknown provider")
    rates = (float(input_per_million), float(output_per_million))
    if any(not math.isfinite(rate) or rate < 0 for rate in rates):
        raise ValueError("token rates must be finite, non-negative USD amounts")
    try:
        data = json.loads(CONFIG.read_text(encoding="utf-8")) if CONFIG.exists() else {}
    except (OSError, ValueError):
        data = {}
    providers_data = data.setdefault("providers", {})
    entry = dict(providers_data.get(name) or config)
    pricing = dict(entry.get("pricing") or {})
    models = dict(pricing.get("models") or {})
    models[model] = {"input_per_million": rates[0], "output_per_million": rates[1]}
    entry["pricing"] = {"default": pricing.get("default"), "models": models}
    if entry["pricing"]["default"] is None:
        entry["pricing"].pop("default")
    providers_data[name] = entry
    CONFIG.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def remove_provider(name):
    """Remove a user override; built-in names fall back to their safe defaults."""
    try:
        data = json.loads(CONFIG.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return False
    removed = bool(data.get("providers", {}).pop(name, None))
    CONFIG.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return removed


def parse_model(model):
    """Return (provider, remote-model, config); bare names retain Ollama compatibility."""
    model = model or ""
    if model.startswith("local:"):
        return "local", model[6:], {"kind": "ollama", "base_url": OLLAMA}
    head, sep, tail = model.partition(":")
    registry = _read_config()
    if head == "hosted" and sep:
        provider, slash, remote = tail.partition("/")
        if provider in registry and slash and remote:
            return provider, remote, registry[provider]
        raise ProviderError("provider_config", "hosted model must be hosted:provider/MODEL")
    if sep and head in registry:
        if not tail:
            raise ProviderError("provider_config", "cloud model name is missing")
        return head, tail, registry[head]
    # Bare provider/model IDs (e.g. nvidia/nemotron-...) are treated as cloud
    # when the leading segment names a configured provider.
    if not sep and "/" in model:
        head, slash, tail = model.partition("/")
        if head in registry and tail:
            # NVIDIA's own models include the vendor namespace in the API ID.
            return head, model if head == "nvidia" and "/" not in tail else tail, registry[head]
    return "local", model, {"kind": "ollama", "base_url": OLLAMA}


def is_cloud(model):
    return parse_model(model)[0] != "local"


def cloud_slots(model, workers, value="auto"):
    """Keep extra file workers useful without flooding the shared NVIDIA OpenCode transport."""
    if value != "auto":
        return int(value)
    provider, remote, _ = parse_model(model)
    return min(workers, 8) if provider == "opencode" and remote.startswith("nvidia/") else workers


def available(model):
    provider, _remote, config = parse_model(model)
    if provider == "local":
        return True
    return provider_ready(provider)


def provider_ready(name):
    if name in ("codex", "claude"):
        return bool(shutil.which(name))
    if name == "chatgpt":
        from roc import chatgpt
        return chatgpt.ready()
    if name == "opencode":
        return bool(shutil.which("opencode"))
    config = _read_config().get(name)
    return bool(config and key_available(config.get("key_env", "")))


def credential_hint(model):
    provider, _remote, config = parse_model(model)
    if provider in ("codex", "claude"):
        return "%s CLI required; install and sign in with %s" % (provider, provider)
    if provider == "chatgpt":
        return "ChatGPT plan sign-in required: roc chatgpt login"
    if provider == "opencode":
        return "OpenCode CLI missing or not signed in: npm i -g opencode-ai, then opencode auth login"
    hint = "Cloud key missing: set %s (roc provider setup)" % config.get("key_env", "")
    if provider == "nvidia":
        hint += "; OpenCode sign-in uses opencode:nvidia/" + _remote
    return hint


def _chatgpt_plan(provider, remote, config, prompt, state, options):
    from roc import chatgpt
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    try:
        return chatgpt.generate(remote, messages, options)
    except ProviderError as error:
        if error.category in ("cloud_budget", "provider_auth") and options.get("budget"):
            options["budget"].stop()
        raise


_REASONING_BLOCK = re.compile(r"<think(?:ing)?>.*?</think(?:ing)?>", re.S | re.I)


def strip_reasoning(text):
    """Drop inline reasoning some models leak into content (e.g. MiniMax  thinking...)."""
    return _REASONING_BLOCK.sub("", str(text or "")).strip()


def sanitize_prompt(text):
    """Remove accidental local-user paths and likely secret values, not source facts."""
    text = str(text or "")
    text = re.sub(r"(?i)\b[A-Z]:\\Users\\[^\s\r\n]+", r"C:\\Users\\<redacted>", text)
    text = re.sub(r"(?i)\b[A-Z]:\\(?:[^\\/:*?\"<>|\r\n]+[\\/])+[^\s\r\n]*", r"<local-path>", text)
    text = re.sub(r"(?i)/Users/[^/\s]+", "/Users/<redacted>", text)
    text = re.sub(r"(?i)(?:sk|nvapi|AIza)[-_A-Za-z0-9]{16,}", "<redacted-key>", text)
    text = re.sub(r"(?i)\b(api[_-]?key|authorization|token|password|secret)\s*[:=]\s*['\"]?[^\s'\"]{12,}",
                  r"\1=<redacted>", text)
    return text


def _url(config, suffix):
    return config["base_url"].rstrip("/") + suffix


def _post(url, body, headers, timeout, allow_empty=False):
    headers = dict(headers)
    # Some OpenAI-compatible gateways sit behind a WAF that rejects the default
    # Python-urllib User-Agent (Cloudflare "error code: 1010"). Send our own.
    headers.setdefault("User-Agent", USER_AGENT)
    req = urllib.request.Request(url, data=json.dumps(body).encode("utf-8"), headers=headers, method="POST")
    try:
        with urllib.request.urlopen(req, timeout=timeout) as response:
            raw = response.read()
            if not raw and allow_empty:
                return {}, dict(response.headers)
            return json.loads(raw), dict(response.headers)
    except urllib.error.HTTPError as error:
        detail = error.read().decode("utf-8", "replace").lower()
        if error.code == 402:
            raise ProviderError("provider_auth", "HTTP 402: insufficient provider balance; check API billing", 402) from None
        if error.code in (401, 403):
            raise ProviderError("provider_auth", "HTTP %d: check API key and model access" % error.code, error.code) from None
        if error.code == 404:
            raise ProviderError("provider_model", "HTTP 404: model or endpoint not found; check full model ID and base URL", 404) from None
        retry = (error.code in (408, 429) or error.code >= 500 or
                 any(text in detail for text in ("insufficient_quota", "usage limit", "rate limit",
                                                  "quota exceeded", "current quota", "insufficient balance")))
        raise ProviderError("provider_retry" if retry else "provider_error",
                            "HTTP %d" % error.code, error.code)
    except (urllib.error.URLError, OSError, ValueError) as error:
        raise ProviderError("provider_retry", type(error).__name__)


def _usage(data, *names):
    usage = data.get("usage") or data.get("usageMetadata") or {}
    for name in names:
        if name in usage and isinstance(usage[name], (int, float)):
            return int(usage[name])
    return 0


def _cached_tokens(data):
    usage = data.get("usage") or data.get("usageMetadata") or {}
    for name in ("cached_tokens", "prompt_cache_hit_tokens", "cachedContentTokenCount",
                 "cache_read_input_tokens"):
        if isinstance(usage.get(name), (int, float)):
            return int(usage[name])
    for name in ("prompt_tokens_details", "input_tokens_details"):
        details = usage.get(name) or {}
        if isinstance(details.get("cached_tokens"), (int, float)):
            return int(details["cached_tokens"])
    return 0


def _pricing(config, model):
    prices = config.get("pricing") or {}
    if "models" in prices:
        prices = prices["models"].get(model) or prices.get("default")
    if not isinstance(prices, dict):
        return None
    try:
        values = [float(prices[name]) for name in ("input_per_million", "output_per_million")]
    except (KeyError, TypeError, ValueError):
        return None
    return prices if all(math.isfinite(value) and value >= 0 for value in values) else None


def has_pricing(model):
    provider, remote, config = parse_model(model)
    return provider != "local" and bool(_pricing(config, remote))


def _cost(config, inp, out, model=None):
    prices = _pricing(config, model)
    if not prices:
        return None
    return round((inp * float(prices.get("input_per_million", 0)) +
                  out * float(prices.get("output_per_million", 0))) / 1000000, 8)


def _cloud_messages(prompt, state, keep_last=2):
    """Bounded history: system + first user (target facts) + tail exchanges.

    Repair rounds otherwise resend every prior full prompt, so input tokens
    grow linearly per round (~3.6k/round observed). The new prompt already
    carries the latest attempt and feedback inline, so older exchanges add
    cost without evidence. keep_last counts tail messages (one exchange = 2).
    """
    history = []
    for message in (state or {}).get("messages", ()):
        if not isinstance(message, dict) or not message.get("content"):
            continue
        history.append({"role": str(message.get("role", "user")),
                        "content": sanitize_prompt(message.get("content", ""))})
    system = next((m for m in history if m["role"] == "system"), None)
    others = [m for m in history if m["role"] != "system"]
    if len(others) > 1 + max(0, keep_last):
        others = [others[0]] + others[-keep_last:] if keep_last > 0 else [others[0]]
    messages = ([system] if system else [{"role": "system", "content": SYSTEM}]) + others
    messages.append({"role": "user", "content": sanitize_prompt(prompt)})
    return messages


def _nemotron_effort(options):
    think, effort = options.get("thinking"), options.get("reasoning_effort")
    if think is not None and str(think).lower() != "auto":
        disabled = str(think).lower() == "disabled" or isinstance(think, dict) and think.get("type") == "disabled"
        effort = "none" if disabled else effort or "high"
    return "medium" if effort in ("minimal", "low") else effort


def _openai_chat(provider, remote, config, prompt, state, options):
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    key = secret(config["key_env"])
    if not key:
        raise ProviderError("provider_key", "%s is not set" % config["key_env"])
    body = {"model": remote, "messages": messages, "temperature": options.get("temperature", 0.2),
            "max_tokens": options.get("max_tokens", 1024), "stream": False}
    if options.get("seed") is not None:
        body["seed"] = int(options["seed"])
    think = options.get("thinking")
    nemotron_ultra = provider == "nvidia" and remote == "nvidia/nemotron-3-ultra-550b-a55b"
    if provider == 'openrouter':
        effort = options.get('reasoning_effort')
        if think is not None and str(think).lower() != 'auto':
            disabled = str(think).lower() == 'disabled' or isinstance(think, dict) and think.get('type') == 'disabled'
            body['reasoning'] = {'enabled': not disabled}
            if not disabled and effort not in (None, 'auto'):
                body['reasoning']['effort'] = str(effort)
        elif effort not in (None, 'auto'):
            body['reasoning'] = {'effort': str(effort)}
    elif nemotron_ultra:
        effort = _nemotron_effort(options)
        if effort is not None:
            body["reasoning_effort"] = str(effort)
    elif think is not None and str(think).lower() != "auto":
        disabled = ((isinstance(think, dict) and think.get("type") == "disabled")
                    or str(think).lower() == "disabled")
        if provider in NO_THINKING:
            # This gateway already rejected the thinking field once; skip the
            # guaranteed 400 and use the knob it does support.
            body.setdefault("reasoning_effort", "low" if disabled else "high")
        else:
            body["thinking"] = think if isinstance(think, dict) else {"type": str(think)}
    if provider != 'openrouter' and not nemotron_ultra and options.get("reasoning_effort") is not None:
        body["reasoning_effort"] = str(options["reasoning_effort"])
    data, headers = _post(_url(config, "/chat/completions"), body,
                          {"Content-Type": "application/json", "Authorization": "Bearer " + key}, options["timeout"])
    choice = (data.get("choices") or [{}])[0]
    if provider == 'openrouter' and (data.get('error') or choice.get('error')):
        error = data.get('error') or choice['error']
        status = error.get('code') if isinstance(error, dict) else None
        category = ('provider_auth' if status in (401, 402, 403) else 'provider_model' if status == 404
                    else 'provider_retry' if status in (408, 429) or isinstance(status, int) and status >= 500 else 'provider_error')
        raise ProviderError(category, 'OpenRouter generation failed (code %s)' % status, status)
    message = choice.get("message") or {}
    content = message.get("content")
    if not content and provider != 'openrouter':
        content = message.get("reasoning_content") or message.get("reasoning") or ""
    text = strip_reasoning(content or "")
    return Generation(text, {"messages": messages + [{"role": "assistant", "content": text}]},
                      input_tokens=_usage(data, "prompt_tokens", "input_tokens"),
                      output_tokens=_usage(data, "completion_tokens", "output_tokens"),
                      cached_tokens=_cached_tokens(data), provider=provider, model=remote,
                      request_id=headers.get("x-request-id", data.get("id", "")),
                      finish_reason=choice.get("finish_reason", ""),
                      reasoning_tokens=((data.get("usage") or {}).get("completion_tokens_details") or {}).get("reasoning_tokens"))


def _openai_responses(provider, remote, config, prompt, state, options):
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    key = secret(config["key_env"])
    if not key:
        raise ProviderError("provider_key", "%s is not set" % config["key_env"])
    body = {"model": remote, "input": messages, "max_output_tokens": options.get("max_tokens", 1024),
            "temperature": options.get("temperature", 0.2), "store": False}
    data, headers = _post(_url(config, "/responses"), body,
                          {"Content-Type": "application/json", "Authorization": "Bearer " + key}, options["timeout"])
    text = data.get("output_text", "")
    if not text:
        text = "".join(part.get("text", "") for item in data.get("output", [])
                       for part in item.get("content", []) if part.get("type") in ("output_text", "text"))
    text = strip_reasoning(text)
    return Generation(text, {"messages": messages + [{"role": "assistant", "content": text}]},
                      input_tokens=_usage(data, "input_tokens"), output_tokens=_usage(data, "output_tokens"),
                      cached_tokens=_cached_tokens(data), provider=provider, model=remote,
                      request_id=headers.get("x-request-id", data.get("id", "")), finish_reason=data.get("status", ""))


def _anthropic(provider, remote, config, prompt, state, options):
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    key = secret(config["key_env"])
    if not key:
        raise ProviderError("provider_key", "%s is not set" % config["key_env"])
    system = "\n".join(message["content"] for message in messages if message["role"] == "system")
    body = {"model": remote, "messages": [message for message in messages if message["role"] != "system"],
            "system": system, "max_tokens": options.get("max_tokens", 1024),
            "temperature": options.get("temperature", 0.2)}
    data, headers = _post(_url(config, "/messages"), body, {"Content-Type": "application/json",
                          "x-api-key": key, "anthropic-version": config.get("api_version", "2023-06-01")}, options["timeout"])
    text = "".join(part.get("text", "") for part in data.get("content", []) if part.get("type") == "text")
    return Generation(text, {"messages": messages + [{"role": "assistant", "content": text}]},
                      input_tokens=_usage(data, "input_tokens"), output_tokens=_usage(data, "output_tokens"),
                      cached_tokens=_cached_tokens(data), provider=provider, model=remote,
                      request_id=headers.get("request-id", data.get("id", "")),
                      finish_reason=data.get("stop_reason", ""))


def _gemini(provider, remote, config, prompt, state, options):
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    key = secret(config["key_env"])
    if not key:
        raise ProviderError("provider_key", "%s is not set" % config["key_env"])
    contents = [{"role": "model" if m["role"] == "assistant" else "user", "parts": [{"text": m["content"]}]}
                for m in messages if m["role"] != "system"]
    body = {"contents": contents, "systemInstruction": {"parts": [{"text": "\n".join(
            m["content"] for m in messages if m["role"] == "system")}]},
            "generationConfig": {"temperature": options.get("temperature", 0.2),
            "maxOutputTokens": options.get("max_tokens", 1024)}}
    data, headers = _post(_url(config, "/models/%s:generateContent" % remote), body,
                          {"Content-Type": "application/json", "x-goog-api-key": key}, options["timeout"])
    candidate = (data.get("candidates") or [{}])[0]
    text = "".join(part.get("text", "") for part in (candidate.get("content") or {}).get("parts", []))
    return Generation(text, {"messages": messages + [{"role": "assistant", "content": text}]},
                      input_tokens=_usage(data, "promptTokenCount"), output_tokens=_usage(data, "candidatesTokenCount"),
                      cached_tokens=_cached_tokens(data), provider=provider, model=remote,
                      request_id=headers.get("x-request-id", ""), finish_reason=candidate.get("finishReason", ""))


def _opencode_failure(error):
    """Map one `opencode run` error event to a safe ProviderError."""
    status = error.get("status") if isinstance(error.get("status"), int) else None
    message = str(error.get("message") or error.get("type") or "OpenCode request failed")
    transient = any(term in message.lower() for term in ("socket connection was closed", "econnreset", "econnrefused", "etimedout", "fetch failed"))
    if status in (408, 429) or (status or 0) >= 500 or status is None and transient:
        category = "provider_retry"
    elif status in (401, 402, 403):
        category = "provider_auth"  # quota/refusal: waiting will not clear it
    else:
        category = "provider_error"  # e.g. "Variant unavailable for provider/model: x"
    return ProviderError(category, message, status)


_OPENCODE_STANDALONE = []


def _opencode_run_flags():
    """`--standalone` only exists in newer OpenCode builds; probe once like the agent path."""
    if not _OPENCODE_STANDALONE:
        exe = shutil.which("opencode")
        try:
            text = subprocess.run([exe, "run", "--help"], capture_output=True, text=True,
                                  timeout=30).stdout if exe else ""
        except (OSError, subprocess.SubprocessError):
            text = ""
        _OPENCODE_STANDALONE.append(["--standalone"] if "--standalone" in text else [])
    return _OPENCODE_STANDALONE[0]


def _opencode_run(argv, prompt, timeout):
    """One non-interactive `opencode run`; the whole process tree dies on timeout."""
    task = Path(argv[argv.index("--file") + 1]) if "--file" in argv else None
    workspace = Path(tempfile.gettempdir()) / "roconstruct-model-workspace" if task else None
    if workspace:
        workspace.mkdir(exist_ok=True)
    service = _opencode_service() if "--server" in argv else None
    env = dict(os.environ, OPENCODE_SERVER_PASSWORD=service[1]) if service else None
    process = subprocess.Popen(argv, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                               stderr=subprocess.STDOUT, text=True,
                               encoding="utf-8", errors="replace", cwd=workspace, env=env,
                               creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
    to = int(timeout or 0)
    try:
        output, _unused = process.communicate(prompt, timeout=(None if to <= 0 else max(5, to)))
    except subprocess.TimeoutExpired:
        if os.name == "nt":
            # npm shims are .cmd files: kill the whole tree, not just cmd.exe.
            subprocess.run(["taskkill", "/T", "/F", "/PID", str(process.pid)], capture_output=True)
        else:
            process.kill()
        try:
            process.communicate(timeout=10)
        except subprocess.TimeoutExpired:
            pass
        raise ProviderError("provider_retry", "OpenCode run timed out")
    finally:
        if process.stdout:
            process.stdout.close()
    return process.returncode, output or ""


def _opencode_service():
    """(url, password) for the running OpenCode server, or None when absent.

    OpenCode writes its background service address and password here, so RoConstruct
    can call the same signed-in API the CLI uses without storing credentials.
    """
    override = os.environ.get("OPENCODE_SERVER_URL")
    if override:
        return override.rstrip("/"), os.environ.get("OPENCODE_SERVER_PASSWORD", "")
    home = Path.home()
    candidates = [home / ".local" / "state" / "opencode" / "service.json",
                  home / ".local" / "share" / "opencode" / "service.json"]
    local = os.environ.get("LOCALAPPDATA") or os.environ.get("XDG_STATE_HOME")
    if local:
        candidates.append(Path(local) / "opencode" / "service.json")
    for path in candidates:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, ValueError, TypeError):
            continue
        url = data.get("url") if isinstance(data, dict) else None
        password = data.get("password", "") if isinstance(data, dict) else ""
        if isinstance(url, str) and url.startswith(("http://", "https://")):
            parsed = urlparse(url)
            try:
                with socket.create_connection((parsed.hostname, parsed.port or (443 if parsed.scheme == "https" else 80)), timeout=1):
                    pass
            except (OSError, ValueError):
                continue  # Stale metadata must not pin every worker to a dead service.
            return url.rstrip("/"), str(password or "")
    return None


def _opencode_api(remote, messages, prompt, options):
    """One OpenCode HTTP call through the running signed-in server.

    Unlike `opencode run`, this keeps a real HTTP session with the model and
    returns the text in one response, so an unresponsive CLI no longer wedges a
    worker. The model string is provider/model with an optional #variant.
    """
    service = _opencode_service()
    if not service:
        raise ProviderError("provider_config", "OpenCode server not running")
    base, password = service
    model = str(remote).partition("#")[0]
    provider_id, slash, model_id = model.partition("/")
    if not slash or not provider_id or not model_id:
        raise ProviderError("provider_config", "OpenCode API model must be provider/model")
    headers = {"Content-Type": "application/json", "User-Agent": USER_AGENT}
    if password:
        token = base64.b64encode(("opencode:" + password).encode("utf-8")).decode("ascii")
        headers["Authorization"] = "Basic " + token
    timeout = int(options.get("timeout") or 180)
    session, _ = _post(base + "/api/session", {"title": "RoConstruct"}, headers, min(timeout, 30))
    session_id = ((session or {}).get("data") or {}).get("id")
    if not session_id:
        raise ProviderError("provider_error", "OpenCode API returned no session")
    ref = {"providerID": provider_id, "id": model_id}
    variant = str(remote).partition("#")[2]
    if variant:
        ref["variant"] = variant
    _post(base + "/api/session/%s/model" % session_id, {"model": ref}, headers, min(timeout, 30),
          allow_empty=True)
    reply, _ = _post(base + "/api/session/%s/generate" % session_id, {"prompt": prompt}, headers, timeout)
    text = str(((reply or {}).get("data") or {}).get("text") or "")
    if not text.strip():
        raise ProviderError("provider_error", "OpenCode API produced no text")
    text = strip_reasoning(text)
    return Generation(text, {"messages": messages + [{"role": "assistant", "content": text}]},
                      provider="opencode", model=remote, finish_reason="completed")


def _opencode_cli(provider, remote, config, prompt, state, options):
    """Generate through the signed-in OpenCode CLI: plan allowances, no API key.

    The CLI keeps its own sign-in (OpenCode Console; the Go subscription's
    monthly allowances, e.g. $80/mo DeepSeek V4.1 Flash, apply automatically),
    so RoConstruct never stores or handles its credentials.
    """
    exe = shutil.which("opencode")
    if not exe:
        raise ProviderError("provider_auth",
                            "OpenCode CLI not found: npm i -g opencode-ai, then opencode auth login")
    if remote == "nvidia/nvidia/nemotron-3-ultra-550b-a55b":
        effort = _nemotron_effort(options)
        if effort not in (None, "auto"):
            remote += "#" + str(effort)
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    system = "\n\n".join(message["content"] for message in messages if message["role"] == "system")
    others = [message for message in messages if message["role"] != "system"]
    transcript = "".join("%s:\n%s\n\n" % ("Previous assistant reply" if message["role"] == "assistant"
                                          else "Previous context", message["content"])
                         for message in others[:-1])
    body = (system + "\n\n" if system else "") + transcript + others[-1]["content"]
    discipline = ("RESPOND WITH ONLY THE REQUESTED SEARCH/REPLACE BLOCKS IN ONE ```cpp CODE FENCE.\n"
                  "The fence must contain edit blocks, not a complete replacement source file.\n"
                  "Do NOT use tools. Do NOT read files. Do NOT explore the repository.\n\n") if options.get("edit_blocks") else (
                  "RESPOND WITH EXACTLY ONE ```cpp CODE BLOCK AND NOTHING ELSE.\n"
                  "Do NOT use tools. Do NOT read files. Do NOT explore the repository.\n"
                  "Do NOT add prose outside the code block. Your entire reply must be one "
                  "fenced code block of C++ source.\n\n")
    if options.get("opencode_api") and _opencode_service():
        # Once submitted, a timeout may still leave generation running remotely.
        # Do not start a duplicate CLI generation after an uncertain HTTP result.
        return _opencode_api(remote, messages, discipline + body, options)
    # -m takes provider/model#variant; no --auto: a draft needs text, not tools.
    # Current OpenCode builds do not consume a stdin-only task. A task attachment
    # also avoids Windows command-line limits for whole native translation units.
    with tempfile.TemporaryDirectory(prefix="roc-opencode-task-") as folder:
        task = Path(folder) / "task.txt"
        task.write_text(discipline + body, encoding="utf-8")
        # Explicit attachment avoids a timed-out CLI owning/killing a new shared service.
        service = _opencode_service()
        server = ["--server", service[0]] if service else _opencode_run_flags()
        code, output = _opencode_run([exe, "run", "-m", remote, "--format", "json", *server, "--file", str(task),
                                      "Follow the attached task exactly. Return only its requested output. Do not use tools."],
                                     "", options["timeout"])
    text, failure = "", None
    for line in output.splitlines():
        try:
            event = json.loads(line)
        except ValueError:
            continue
        if not isinstance(event, dict):
            continue
        if event.get("type") == "error" and isinstance(event.get("error"), dict):
            failure = event["error"]
        elif event.get("type") == "text" and isinstance(event.get("part"), dict):
            text += str(event["part"].get("text") or "")
    if not text.strip():
        if failure:
            raise _opencode_failure(failure)
        raise ProviderError("provider_error", "OpenCode run produced no text (exit %s)" % code)
    text = strip_reasoning(text)
    return Generation(text, {"messages": messages + [{"role": "assistant", "content": text}]},
                      provider="opencode", model=remote, finish_reason="completed")


def _ollama(remote, prompt, state, options):
    request = {"model": remote, "prompt": prompt, "stream": True, "keep_alive": "10m",
               "options": {"temperature": options.get("temperature", 0.2), **options.get("profile", {})}}
    if options.get("seed") is not None:
        request["options"]["seed"] = int(options["seed"])
    if state:
        request["context"] = state
    req = urllib.request.Request(OLLAMA + "/api/generate", data=json.dumps(request).encode(),
                                 headers={"Content-Type": "application/json"})
    pieces, fences, returned, final = [], 0, None, {}
    started = time.monotonic()
    try:
        with urllib.request.urlopen(req, timeout=options["timeout"]) as response:
            for raw in response:
                try:
                    item = json.loads(raw)
                except ValueError:
                    continue
                piece = item.get("response", "")
                pieces.append(piece)
                fences += piece.count("```")
                if item.get("context"):
                    returned = item["context"]
                final = item
                if fences >= 2:
                    break
    except urllib.error.HTTPError as error:
        raise ProviderError("provider_error", "Ollama HTTP %d" % error.code, error.code)
    return Generation("".join(pieces), returned, int(final.get("prompt_eval_count", 0) or 0),
                      int(final.get("eval_count", 0) or 0), int(final.get("prompt_eval_cached_count", 0) or 0),
                      time.monotonic() - started, "local", remote, "", final.get("done_reason", ""))


def _coding_cli(provider, remote, config, prompt, state, options):
    """Use the contributor's signed-in CLI as a text provider; edits stay in ROC's compiler loop."""
    exe = shutil.which(provider)
    if not exe:
        raise ProviderError("provider_config", credential_hint(provider + ":" + remote))
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    text = "\n\n".join(message["role"].upper() + ":\n" + message["content"] for message in messages)
    if provider == "claude":
        argv = [exe, "-p", "--output-format", "json", "--tools", "", "--strict-mcp-config",
                "--mcp-config", '{"mcpServers":{}}', "--no-session-persistence"]
    else:
        argv = [exe, "exec", "--json", "--sandbox", "read-only", "--skip-git-repo-check", "--ephemeral"]
    if remote != "default":
        argv += ["--model", remote]
    effort = options.get("reasoning_effort")
    if effort and effort != "auto":
        argv += (["--effort", effort] if provider == "claude" else ["-c", 'model_reasoning_effort="%s"' % effort])
    if provider == "codex":
        argv += ["-"]
    with tempfile.TemporaryDirectory(prefix="roc-generation-") as folder:
        try:
            process = subprocess.Popen(argv, cwd=folder, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE, text=True, encoding="utf-8", errors="replace",
                                       creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
            started = time.monotonic()
            pending_input = text
            while True:
                try:
                    output, _ = process.communicate(pending_input, timeout=min(15, options.get("timeout", 180)))
                    break
                except subprocess.TimeoutExpired:
                    pending_input = None
                    elapsed = time.monotonic() - started
                    if options.get("log"):
                        options["log"]("%s CLI request running (%ds)" % (provider, elapsed))
                    if elapsed >= options.get("timeout", 180):
                        if os.name == "nt":
                            subprocess.run(["taskkill", "/T", "/F", "/PID", str(process.pid)], capture_output=True)
                        else:
                            process.kill()
                        process.communicate()
                        raise ProviderError("provider_retry", provider + " CLI timed out")
        except OSError:
            raise ProviderError("provider_config", provider + " CLI could not start") from None
    if process.returncode:
        raise ProviderError("provider_error", provider + " CLI failed; check CLI sign-in and model access")
    if provider == "claude":
        try:
            result = json.loads(output)
        except ValueError:
            raise ProviderError("provider_error", "Claude CLI returned invalid JSON") from None
        if result.get("is_error"):
            raise ProviderError("provider_error", "Claude CLI rejected generation; check sign-in and plan limits")
        answer, usage = result.get("result", ""), result.get("usage", {})
    else:
        answer, usage = "", {}
        for line in output.splitlines():
            try:
                event = json.loads(line)
            except ValueError:
                continue
            if event.get("type") in ("turn.failed", "error"):
                raise ProviderError("provider_error", "Codex CLI rejected generation; check sign-in and model access")
            if event.get("type") == "item.completed" and event.get("item", {}).get("type") == "agent_message":
                answer = event["item"].get("text", "")
            if event.get("type") == "turn.completed":
                usage = event.get("usage", {})
    if not answer.strip():
        raise ProviderError("provider_error", provider + " CLI returned no text")
    return Generation(answer, {"messages": messages + [{"role": "assistant", "content": answer}]},
                      input_tokens=usage.get("input_tokens", 0), output_tokens=usage.get("output_tokens", 0),
                      cached_tokens=usage.get("cached_input_tokens", usage.get("cache_read_input_tokens", 0)),
                      provider=provider, model=remote)


def generate(model, messages, options=None, state=None):
    """Generate once from a prompt or explicit message list. Cloud requires consent."""
    if isinstance(messages, (list, tuple)):
        history = [dict(item) for item in messages if isinstance(item, dict) and item.get("content")]
        last = next((item for item in reversed(history) if item.get("role") == "user"), None)
        if not last:
            raise ProviderError("provider_input", "message list needs a user message")
        prompt = str(last["content"])
        state = {"messages": history[:history.index(last)]} if state is None else state
    else:
        prompt = str(messages or "")
    options = dict(options or {})
    options.setdefault("timeout", 180)
    options.setdefault("max_tokens", 1024)
    options.setdefault("temperature", 0.2)
    provider, remote, config = parse_model(model)
    if provider == "local":
        return _ollama(remote, prompt, state, options)
    if not options.get("allow_cloud"):
        raise ProviderError("cloud_disabled", "pass --allow-cloud before sending prompts to cloud providers")
    if config["kind"] == "chatgpt-plan":
        options["retry_forever"] = False
        if options.get("budget") and options["budget"].max_cost is not None:
            raise ProviderError("cloud_budget", "ChatGPT uses plan limits, not USD pricing. Remove the USD cap; manage app limits in ChatGPT Settings > Usage.")
    elif config["kind"] in ("opencode-cli", "codex-cli", "claude-cli"):
        options["retry_forever"] = False
        if not options.get("timeout"):
            options["timeout"] = 180  # Avoid an unresponsive model wedging worker forever.
        if options.get("budget") and options["budget"].max_cost is not None:
            raise ProviderError("cloud_budget", "CLI models use their signed-in account's limits. Remove the USD cap; check usage in the provider console.")
    gate, lock = options.get("gate"), None
    budget = options.get("budget")
    messages = _cloud_messages(prompt, state, options.get("history_keep_last", 2))
    # Reserve for the whole transmitted conversation, including role framing.
    estimate_input = sum(len(message["content"].encode("utf-8")) + 16 for message in messages)
    estimate_tokens = estimate_input + int(options["max_tokens"])
    if budget and budget.max_cost is not None and not _pricing(config, remote):
        raise ProviderError("cloud_budget", "--max-cloud-cost needs provider pricing; cost is unknown")
    if gate:
        lock = gate.enter(provider)
    started, retries = time.monotonic(), 0
    deadline = None if options.get("retry_forever") else started + max(1, float(options.get("timeout") or 180))
    try:
        attempt = 0
        dropped_knobs = False
        while True:
            ticket = None
            try:
                if deadline is not None and time.monotonic() >= deadline:
                    raise ProviderError("provider_retry", "Generation deadline exceeded")
                if budget:
                    ticket = budget.reserve(estimate_tokens,
                                            _cost(config, estimate_input, int(options["max_tokens"]), remote) or 0.0)
                fn = {"chatgpt-plan": _chatgpt_plan, "opencode-cli": _opencode_cli,
                      "codex-cli": _coding_cli, "claude-cli": _coding_cli,
                      "openai-chat": _openai_chat, "openai-responses": _openai_responses,
                      "anthropic-messages": _anthropic, "gemini": _gemini}[config["kind"]]
                request_options = dict(options, timeout=min(options["timeout"], max(1, math.ceil(deadline-time.monotonic())))) if deadline else options
                out = fn(provider, remote, config, prompt, state, request_options)
                out.latency_s = time.monotonic() - started
                out.retries = retries
                out.cost = _cost(config, out.input_tokens, out.output_tokens, remote)
                if budget:
                    budget.settle(ticket, out.input_tokens + out.output_tokens, out.cost)
                if dropped_knobs:
                    # Only a successful retry proves the knobs caused the 400;
                    # remember it so later requests skip the round trip.
                    NO_THINKING.add(provider)
                if gate:
                    gate.done(provider, True)
                return out
            except ProviderError as error:
                if (error.status == 400 and not dropped_knobs
                        and config.get("kind") == "openai-chat"
                        and ("thinking" in options or "reasoning_effort" in options)):
                    # Some OpenAI-compatible gateways reject the thinking/reasoning
                    # knobs on /chat/completions with a 400 ("thinking is not
                    # supported ... use reasoning_effort"). Retry once without
                    # them, translating a disabled request to reasoning_effort low.
                    think = options.pop("thinking", None)
                    options.pop("reasoning_effort", None)
                    if think is not None:
                        disabled = ((isinstance(think, dict) and think.get("type") == "disabled")
                                    or str(think).lower() == "disabled")
                        options["reasoning_effort"] = "low" if disabled else "high"
                    dropped_knobs = True
                    retries += 1
                    if budget and ticket:
                        budget.settle(ticket, 0, 0.0)  # the provider did not bill this
                    continue
                if (error.category != "provider_retry" or
                        deadline is not None and time.monotonic() >= deadline or
                        (not options.get("retry_forever") and attempt >= int(options.get("retries", 2)))):
                    if error.status in (401, 403):
                        error = ProviderError(error.category, "%s HTTP %d: check %s and model access; environment overrides saved key" %
                                              (provider, error.status, config.get("key_env", "provider sign-in")), error.status)
                    elif error.status == 404:
                        error = ProviderError(error.category, "%s model %s: HTTP 404; check full model ID and base URL" %
                                              (provider, sanitize_prompt(remote)[:160]), error.status)
                    if gate:
                        if error.category in FATAL_ERRORS:
                            gate.disable(provider, error)
                        elif error.category == "provider_retry":
                            gate.done(provider, False)
                    raise error
                retries += 1
                # Free-tier OpenCode models rate-limit hard (429); the 0.5s
                # steps are too fast and the worker just loops "waiting for cloud
                # model" until exhausted. Give 429s a 60s floor and cap retries.
                _retry_delay = min(180, 0.5 * (2 ** min(attempt, 7)))
                if getattr(error, "status", None) == 429:
                    _retry_delay = max(60, _retry_delay)
                if deadline:
                    _retry_delay = min(_retry_delay, max(0, deadline - time.monotonic()))
                if options.get("on_retry"):
                    options["on_retry"](error, retries, _retry_delay)
                time.sleep(_retry_delay)
                attempt += 1
    finally:
        if lock:
            lock.release()


def test_provider(name, model):
    """Small opt-in probe; no model source, assembly, or key is displayed."""
    return generate("%s:%s" % (name, model), "Reply with exactly: ok", options={"allow_cloud": True, "max_tokens": 8})
