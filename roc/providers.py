"""Provider-neutral text generation for local and cloud worker models.

Keys are read from environment variables first, or a user-local secrets file
outside the repository. This module owns provider HTTP details so matching,
MSVC compilation, and server leases stay local and provider-agnostic.
"""
import json
import math
import os
import re
import threading
import time
import urllib.error
import urllib.request
from urllib.parse import urlparse
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CONFIG = ROOT / "roconstruct-providers.json"
OLLAMA = "http://127.0.0.1:11434"

BUILTINS = {
    "nvidia": {"kind": "openai-chat", "base_url": "https://integrate.api.nvidia.com/v1",
               "key_env": "NVIDIA_API_KEY"},
    "deepseek": {"kind": "openai-chat", "base_url": "https://api.deepseek.com",
                 "key_env": "DEEPSEEK_API_KEY"},
    "openai": {"kind": "openai-responses", "base_url": "https://api.openai.com/v1",
               "key_env": "OPENAI_API_KEY"},
    "anthropic": {"kind": "anthropic-messages", "base_url": "https://api.anthropic.com/v1",
                  "key_env": "ANTHROPIC_API_KEY", "api_version": "2023-06-01"},
    "gemini": {"kind": "gemini", "base_url": "https://generativelanguage.googleapis.com/v1beta",
                "key_env": "GEMINI_API_KEY"},
}
KINDS = {"openai-chat", "openai-responses", "anthropic-messages", "gemini"}
SYSTEM = "Reconstruct compact valid C++ only. Never emit inline assembly. Follow the user task exactly."
USER_AGENT = "RoConstruct/1.0"
# Providers that rejected the thinking field once; the process skips it after that.
NO_THINKING = set()


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
        self._lock = threading.Lock()

    def reserve(self, estimate_tokens=0, estimate_cost=0.0):
        with self._lock:
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

    def enter(self, provider):
        with self._lock:
            if self._failed.get(provider, 0) >= self.failures:
                raise ProviderError("provider_circuit", "%s circuit is open" % provider)
            lock = self._locks.setdefault(provider, threading.BoundedSemaphore(self.concurrency))
        lock.acquire()
        return lock

    def done(self, provider, ok):
        with self._lock:
            self._failed[provider] = 0 if ok else self._failed.get(provider, 0) + 1

    def reset(self, provider):
        with self._lock:
            self._failed.pop(provider, None)


def _read_config():
    try:
        loaded = json.loads(CONFIG.read_text(encoding="utf-8"))
        configured = loaded.get("providers", {})
    except (OSError, ValueError, TypeError):
        configured = {}
    out = {name: dict(value) for name, value in BUILTINS.items()}
    for name, value in configured.items():
        if (isinstance(value, dict) and value.get("kind") in KINDS and _safe_base_url(value.get("base_url"))
                and value.get("key_env")):
            out[name] = dict(value)
    return out


def providers():
    """Public non-secret provider registry."""
    return _read_config()


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
        return value
    try:
        data = json.loads(secrets_path().read_text(encoding="utf-8"))
    except (OSError, ValueError, TypeError):
        return ""
    value = data.get(key_env) if isinstance(data, dict) else ""
    return value if isinstance(value, str) else ""


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
    return "local", model, {"kind": "ollama", "base_url": OLLAMA}


def is_cloud(model):
    return parse_model(model)[0] != "local"


def available(model):
    provider, _remote, config = parse_model(model)
    if provider == "local":
        return True
    return key_available(config["key_env"])


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


def _post(url, body, headers, timeout):
    headers = dict(headers)
    # Some OpenAI-compatible gateways sit behind a WAF that rejects the default
    # Python-urllib User-Agent (Cloudflare "error code: 1010"). Send our own.
    headers.setdefault("User-Agent", USER_AGENT)
    req = urllib.request.Request(url, data=json.dumps(body).encode("utf-8"), headers=headers, method="POST")
    try:
        with urllib.request.urlopen(req, timeout=timeout) as response:
            return json.loads(response.read()), dict(response.headers)
    except urllib.error.HTTPError as error:
        detail = error.read().decode("utf-8", "replace").lower()
        retry = (error.code in (408, 429) or error.code >= 500 or
                 any(text in detail for text in ("insufficient_quota", "usage limit", "rate limit",
                                                  "quota exceeded", "current quota", "insufficient balance")))
        raise ProviderError("provider_retry" if retry else "provider_auth" if error.code in (401, 403) else "provider_error",
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
    if think is not None and str(think).lower() != "auto":
        disabled = ((isinstance(think, dict) and think.get("type") == "disabled")
                    or str(think).lower() == "disabled")
        if provider in NO_THINKING:
            # This gateway already rejected the thinking field once; skip the
            # guaranteed 400 and use the knob it does support.
            body.setdefault("reasoning_effort", "low" if disabled else "high")
        else:
            body["thinking"] = think if isinstance(think, dict) else {"type": str(think)}
    if options.get("reasoning_effort") is not None:
        body["reasoning_effort"] = str(options["reasoning_effort"])
    data, headers = _post(_url(config, "/chat/completions"), body,
                          {"Content-Type": "application/json", "Authorization": "Bearer " + key}, options["timeout"])
    choice = (data.get("choices") or [{}])[0]
    text = strip_reasoning((choice.get("message") or {}).get("content") or "")
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
    try:
        attempt = 0
        dropped_knobs = False
        while True:
            ticket = None
            try:
                if budget:
                    ticket = budget.reserve(estimate_tokens,
                                            _cost(config, estimate_input, int(options["max_tokens"]), remote) or 0.0)
                fn = {"openai-chat": _openai_chat, "openai-responses": _openai_responses,
                      "anthropic-messages": _anthropic, "gemini": _gemini}[config["kind"]]
                out = fn(provider, remote, config, prompt, state, options)
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
                        (not options.get("retry_forever") and attempt >= int(options.get("retries", 2)))):
                    if gate and error.category != "cloud_budget":
                        gate.done(provider, False)
                    raise
                retries += 1
                delay = min(60, 0.5 * (2 ** min(attempt, 7)))
                if options.get("on_retry"):
                    options["on_retry"](error, retries, delay)
                time.sleep(delay)
                attempt += 1
    finally:
        if lock:
            lock.release()


def test_provider(name, model):
    """Small opt-in probe; no model source, assembly, or key is displayed."""
    return generate("%s:%s" % (name, model), "Reply with exactly: ok", options={"allow_cloud": True, "max_tokens": 8})
