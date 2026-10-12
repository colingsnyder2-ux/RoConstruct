"""Offline protocol tests: real JWT signatures, OAuth forms, and SDK streams."""
import base64
import hashlib
import json
import threading
import time
from types import SimpleNamespace
from urllib.parse import parse_qs, urlencode, urlsplit

import httpx
import jwt
import openai
import pytest
from cryptography.hazmat.primitives.asymmetric import rsa
from unittest.mock import patch

from roc import chatgpt, providers, worker


@pytest.fixture
def storage(tmp_path, monkeypatch):
    monkeypatch.setenv("ROCONSTRUCT_CHATGPT_DIR", str(tmp_path))
    vault = {}
    monkeypatch.setattr(chatgpt, "_keyring", lambda: SimpleNamespace(
        get_password=lambda service, account: vault.get(account),
        set_password=lambda service, account, value: vault.__setitem__(account, value)))
    monkeypatch.setattr(chatgpt, "_discovery", lambda: {
        "issuer": chatgpt.ISSUER,
        "authorization_endpoint": chatgpt.ISSUER + "/api/accounts/authorize",
        "token_endpoint": chatgpt.ISSUER + "/api/accounts/oauth/token",
        "revocation_endpoint": chatgpt.ISSUER + "/api/accounts/oauth/revoke"})
    return vault


def connected(storage, expires=None, client_id="oaiapp_test", subject="user"):
    with chatgpt._locked():
        data = chatgpt._read()
        data["accounts"][client_id] = {"client_id": client_id, "subject": subject,
                                      "issuer": chatgpt.ISSUER, "label": "user@example.com",
                                      "email": "user@example.com", "models": []}
        data["active"] = client_id
        chatgpt._write(data)
        chatgpt._save_credentials(client_id, {"access_token": "private-access", "refresh_token": "private-refresh",
                                "id_token": "private-id", "token_type": "Bearer", "scope": chatgpt.SCOPES,
                                "expires_at": expires or time.time() + 3600})


@pytest.fixture
def signing_key(monkeypatch):
    key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    monkeypatch.setattr(chatgpt, "_jwks", lambda: SimpleNamespace(
        get_signing_key_from_jwt=lambda token: SimpleNamespace(key=key.public_key())))
    return key


def identity_token(key, nonce="nonce", **overrides):
    claims = {"iss": chatgpt.ISSUER, "aud": "oaiapp_test", "sub": "user",
              "iat": int(time.time()), "exp": int(time.time()) + 3600, "nonce": nonce,
              "email": "user@example.com"}
    claims.update(overrides)
    return jwt.encode(claims, key, algorithm="RS256")


@pytest.mark.parametrize("overrides", [{"iss": "https://wrong.example"}, {"aud": "other_client"},
                                     {"exp": int(time.time()) - 100}, {"nonce": "wrong"}, {"sub": ""}])
def test_identity_rejects_invalid_claims(signing_key, overrides):
    with pytest.raises(providers.ProviderError, match="identity validation"):
        chatgpt._identity(identity_token(signing_key, **overrides), "oaiapp_test", "nonce")


def test_identity_rejects_bad_signature_and_account_swap(signing_key):
    bad_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    with pytest.raises(providers.ProviderError):
        chatgpt._identity(identity_token(bad_key), "oaiapp_test", "nonce")
    with pytest.raises(providers.ProviderError):
        chatgpt._identity(identity_token(signing_key), "oaiapp_test", "nonce",
                         {"issuer": chatgpt.ISSUER, "subject": "other_user"})
    assert chatgpt._identity(identity_token(signing_key), "oaiapp_test", "nonce")["sub"] == "user"


@pytest.mark.parametrize("query", ["code=c&state=wrong&client_id=oaiapp_test", "code=c&state=s",
                                   "code=c&state=s&client_id=dynamic_agent_client", "error=access_denied&state=s",
                                   "code=c&code=d&state=s&client_id=oaiapp_test"])
def test_callback_rejects_bad_or_declined_registration(query):
    with pytest.raises(providers.ProviderError):
        chatgpt._callback(query, "s", None)


def test_callback_preserves_returning_client():
    assert chatgpt._callback("code=c&state=s", "s", "oaiapp_test") == ("c", "oaiapp_test")
    with pytest.raises(providers.ProviderError):
        chatgpt._callback("code=c&state=s&client_id=other", "s", "oaiapp_test")


def test_browser_login_uses_pkce_and_issued_client(storage, signing_key, monkeypatch):
    captured = {}
    callback_thread = []
    def browser(url):
        query = parse_qs(urlsplit(url).query)
        captured.update(query)
        callback = query["redirect_uri"][0] + "?" + urlencode({
            "code": "private-code", "state": query["state"][0], "client_id": "oaiapp_test"})
        import requests
        thread = threading.Thread(target=lambda: requests.get(callback, timeout=10))
        thread.start()
        callback_thread.append(thread)
        return True
    def exchange(session, url, **kwargs):
        assert session.client_id == "oaiapp_test"
        assert session.redirect_uri == captured["redirect_uri"][0]
        assert kwargs["resource"] == chatgpt.RESOURCE
        digest = hashlib.sha256(kwargs["code_verifier"].encode()).digest()
        assert captured["code_challenge"][0] == base64.urlsafe_b64encode(digest).rstrip(b"=").decode()
        return {"access_token": "private-access", "refresh_token": "private-refresh", "token_type": "Bearer",
                "expires_in": 3600, "scope": chatgpt.SCOPES,
                "id_token": identity_token(signing_key, nonce=captured["nonce"][0])}
    monkeypatch.setattr(chatgpt.webbrowser, "open", browser)
    from authlib.integrations.requests_client import OAuth2Session
    monkeypatch.setattr(OAuth2Session, "fetch_token", exchange)
    account = chatgpt.login(timeout=5)
    callback_thread[0].join()
    assert captured["client_id"] == ["dynamic_agent_client"]
    assert captured["code_challenge_method"] == ["S256"]
    assert captured["agent_name_hint"] == [chatgpt.SERVICE]
    assert captured["ext_agent_host_id"][0].startswith("urn:uuid:")
    assert account["client_id"] == "oaiapp_test" and chatgpt.ready()
    text = (chatgpt.directory() / "accounts.json").read_text()
    assert "private-access" not in text and "private-refresh" not in text and "private-code" not in text
    host = chatgpt.status()["host_id"]
    # A returning account uses the issued client and validates the fresh identity.
    chatgpt.login(timeout=5)
    callback_thread[-1].join()
    assert captured["client_id"] == ["oaiapp_test"]
    assert chatgpt.status()["host_id"] == host


def test_missing_plan_scope_retains_identity_but_disables_inference(storage, signing_key, monkeypatch):
    connected(storage)
    tokens = chatgpt._credentials("oaiapp_test")
    tokens["scope"] = "openid profile email"
    chatgpt._save_credentials("oaiapp_test", tokens)
    assert not chatgpt.ready()
    with pytest.raises(providers.ProviderError, match="sign-in required"):
        chatgpt.access_token()
    assert chatgpt.status()["accounts"]["oaiapp_test"]["subject"] == "user"


def test_rotating_refresh_is_serialized_and_saved(storage, monkeypatch):
    connected(storage, expires=time.time() - 100)
    calls = []
    from authlib.integrations.requests_client import OAuth2Session
    def refresh(session, url, **kwargs):
        calls.append(kwargs)
        time.sleep(0.02)
        return {"access_token": "new-access", "refresh_token": "new-refresh", "token_type": "Bearer",
                "scope": chatgpt.SCOPES, "expires_in": 3600}
    monkeypatch.setattr(OAuth2Session, "refresh_token", refresh)
    from concurrent.futures import ThreadPoolExecutor
    with ThreadPoolExecutor(max_workers=4) as executor:
        tokens = list(executor.map(lambda _: chatgpt.access_token(), range(4)))
    assert tokens == ["new-access"] * 4 and len(calls) == 1
    assert "scope" not in calls[0] and calls[0]["refresh_token"] == "private-refresh"
    assert chatgpt._credentials("oaiapp_test")["refresh_token"] == "new-refresh"


def test_terminal_refresh_error_clears_tokens_only(storage, monkeypatch):
    connected(storage, expires=time.time() - 100)
    from authlib.integrations.requests_client import OAuth2Session
    from authlib.oauth2.rfc6749.errors import InvalidGrantError
    def reject(*args, **kwargs):
        raise InvalidGrantError(description="sensitive diagnostic")
    monkeypatch.setattr(OAuth2Session, "refresh_token", reject)
    with pytest.raises(providers.ProviderError, match="disconnected") as error:
        chatgpt.access_token()
    assert "sensitive" not in str(error.value)
    assert chatgpt._credentials("oaiapp_test") == {}
    assert "oaiapp_test" in chatgpt.status()["accounts"]


def test_transient_refresh_keeps_credentials(storage, monkeypatch):
    connected(storage, expires=time.time() - 100)
    from authlib.integrations.requests_client import OAuth2Session
    monkeypatch.setattr(OAuth2Session, "refresh_token", lambda *a, **kw: (_ for _ in ()).throw(OSError("secret")))
    with pytest.raises(providers.ProviderError, match="temporarily"):
        chatgpt.access_token()
    assert chatgpt._credentials("oaiapp_test")["refresh_token"] == "private-refresh"


def sdk_client(monkeypatch, handler):
    def factory(timeout=180, client_id=None):
        return openai.OpenAI(api_key="oauth-test", base_url=chatgpt.RESOURCE, max_retries=0,
                             http_client=httpx.Client(transport=httpx.MockTransport(handler)))
    monkeypatch.setattr(chatgpt, "_client", factory)


def sse(events):
    return "".join("event: %s\ndata: %s\n\n" % (event["type"], json.dumps(event)) for event in events)


def complete(text="int f() { return 1; }"):
    return {"type": "response.completed", "response": {"id": "resp_test", "object": "response",
             "created_at": 0, "model": "model-test", "status": "completed", "output": [],
             "parallel_tool_calls": False, "tool_choice": "auto", "tools": [],
             "usage": {"input_tokens": 10, "output_tokens": 12, "total_tokens": 22,
                       "input_tokens_details": {"cached_tokens": 2},
                       "output_tokens_details": {"reasoning_tokens": 3}}}}


def test_sdk_stream_requires_completion_and_uses_plan_contract(monkeypatch):
    sent = []
    def handler(request):
        sent.append(json.loads(request.content))
        assert request.headers["authorization"] == "Bearer oauth-test"
        assert str(request.url) == chatgpt.RESOURCE + "/responses"
        return httpx.Response(200, headers={"content-type": "text/event-stream", "x-request-id": "req_123"},
               text=sse([{"type": "response.output_text.delta", "delta": "int f() { return 1; }"}, complete()]))
    sdk_client(monkeypatch, handler)
    result = providers.generate("chatgpt:model-test", "write cpp", options={"allow_cloud": True, "max_tokens": 128,
                                "temperature": 0.2, "seed": 1, "reasoning_effort": "high"})
    assert result.text == "int f() { return 1; }" and result.finish_reason == "completed"
    assert result.input_tokens == 10 and result.reasoning_tokens == 3 and result.cached_tokens == 2
    assert result.request_id == "req_123" and result.cost is None
    body = sent[0]
    assert body["store"] is False and body["stream"] is True and body["reasoning"] == {"effort": "high"}
    assert body["instructions"] == providers.SYSTEM
    assert all(message["role"] != "system" for message in body["input"])
    assert not {"max_output_tokens", "temperature", "seed", "previous_response_id"}.intersection(body)


@pytest.mark.parametrize("terminal", [None, {"type": "response.incomplete", "response": complete()["response"]}])
def test_incomplete_stream_never_accepts_partial_cpp(monkeypatch, terminal):
    events = [{"type": "response.output_text.delta", "delta": "int unfinished()"}]
    if terminal:
        events.append(terminal)
    sdk_client(monkeypatch, lambda request: httpx.Response(200, headers={"content-type": "text/event-stream"}, text=sse(events)))
    with pytest.raises(providers.ProviderError):
        providers.generate("chatgpt:model-test", "p", options={"allow_cloud": True, "retries": 0})


@pytest.mark.parametrize("streamed", [False, True])
def test_usage_limit_stops_shared_budget_without_retry_or_api_fallback(monkeypatch, streamed):
    calls = []
    def handler(request):
        calls.append(request)
        error = {"code": "subscription_sharing_usage_limit_exceeded", "message": "sensitive-text"}
        if streamed:
            response = complete()["response"]
            response.update(status="failed", error=error)
            return httpx.Response(200, headers={"content-type": "text/event-stream"},
                                  text=sse([{"type": "response.failed", "response": response}]))
        return httpx.Response(429, json={"error": error})
    sdk_client(monkeypatch, handler)
    budget = providers.CloudBudget(requests=10)
    with pytest.raises(providers.ProviderError, match="limit reached") as error:
        providers.generate("chatgpt:model-test", "p", options={"allow_cloud": True, "budget": budget, "retry_forever": True})
    assert error.value.category == "cloud_budget" and len(calls) == 1 and budget.stopped
    assert "sensitive-text" not in str(error.value)
    with pytest.raises(providers.ProviderError, match="stopped"):
        budget.reserve()


def test_model_catalog_keeps_visibility_and_order(storage, monkeypatch):
    connected(storage)
    sdk_client(monkeypatch, lambda req: httpx.Response(200, json={"models": [
        {"slug": "second", "display_name": "Second", "visibility": "list"},
        {"slug": "hidden", "visibility": "hide"}, {"slug": "first", "visibility": "list"}]}))
    assert [row["slug"] for row in chatgpt.models()] == ["second", "first"]
    assert chatgpt.default_model() == "chatgpt:second"


def test_plan_cannot_be_overridden_with_paid_provider(tmp_path, monkeypatch):
    path = tmp_path / "providers.json"
    path.write_text(json.dumps({"providers": {"chatgpt": {"kind": "openai-responses",
                                      "base_url": "https://api.openai.com/v1", "key_env": "OPENAI_API_KEY"}}}))
    monkeypatch.setattr(providers, "CONFIG", path)
    assert providers.parse_model("chatgpt:model-test")[2]["kind"] == "chatgpt-plan"
    with pytest.raises(ValueError, match="reserved"):
        providers.save_provider("chatgpt", "openai-chat", "https://example.com", "API_KEY")


def test_saved_plan_never_defaults_to_paid_cloud(monkeypatch):
    monkeypatch.setattr(worker, "load_settings", lambda: {"model": "chatgpt:selected"})
    monkeypatch.setattr(chatgpt, "ready", lambda: False)
    monkeypatch.setattr(providers, "key_available", lambda key: True)
    assert worker.cloud_default() == "chatgpt:selected"


def test_consent_and_usd_cap_fail_before_network(monkeypatch):
    monkeypatch.setattr(chatgpt, "_client", lambda *args: pytest.fail("network must not start"))
    with pytest.raises(providers.ProviderError, match="allow-cloud"):
        providers.generate("chatgpt:model-test", "p")
    with pytest.raises(providers.ProviderError, match="USD"):
        providers.generate("chatgpt:model-test", "p", options={"allow_cloud": True, "budget": providers.CloudBudget(cost=1)})


def test_logout_revoke_failure_clears_only_selected_account(storage, monkeypatch, capsys):
    connected(storage, client_id="oaiapp_other")
    connected(storage)
    _, _, _, requests, *_ = chatgpt._dependencies()
    calls = []
    def post(url, **kwargs):
        calls.append(kwargs["data"])
        return SimpleNamespace(status_code=503)
    monkeypatch.setattr(requests, "post", post)
    monkeypatch.setattr(chatgpt.time, "sleep", lambda seconds: None)
    chatgpt.logout()
    assert len(calls) == 3 and calls[0]["token_type_hint"] == "refresh_token"
    assert chatgpt._credentials("oaiapp_test") == {}
    assert chatgpt._credentials("oaiapp_other")["access_token"] == "private-access"
    assert "revocation was not confirmed" in capsys.readouterr().out


def test_oauth_library_sends_public_client_and_original_redirect(monkeypatch):
    import requests
    requests_sent = []
    def send(adapter, request, **kwargs):
        requests_sent.append(request)
        response = requests.Response()
        response.status_code = 200
        response._content = json.dumps({"access_token": "test", "token_type": "Bearer",
                                       "refresh_token": "new", "expires_in": 3600}).encode()
        response.headers["content-type"] = "application/json"
        response.request = request
        return response
    monkeypatch.setattr(requests.adapters.HTTPAdapter, "send", send)
    redirect = "http://127.0.0.1:1234/auth/callback"
    with chatgpt._oauth("oaiapp_issued", redirect_uri=redirect) as oauth:
        oauth.fetch_token(chatgpt.ISSUER + "/api/accounts/oauth/token", code="code", code_verifier="v" * 64,
                          resource=chatgpt.RESOURCE, timeout=30)
    body = parse_qs(requests_sent[0].body)
    assert body["client_id"] == ["oaiapp_issued"] and body["redirect_uri"] == [redirect]
    assert body["resource"] == [chatgpt.RESOURCE] and body["code_verifier"] == ["v" * 64]
    assert "client_secret" not in body and "authorization" not in requests_sent[0].headers


def test_large_credentials_are_encrypted_not_stored_in_keyring_blob(storage):
    connected(storage)
    large = {"access_token": "private-access-" + "x" * 10000, "refresh_token": "private-refresh"}
    with chatgpt._locked():
        chatgpt._save_credentials("oaiapp_test", large)
        assert chatgpt._credentials("oaiapp_test") == large
    assert len(storage["oaiapp_test"]) == 44
    assert all(b"private-access" not in path.read_bytes() for path in chatgpt.directory().glob("*.enc"))


def test_plan_temporary_retries_are_bounded_even_for_unattended_worker(monkeypatch):
    calls = []
    def handler(request):
        calls.append(request)
        return httpx.Response(503, json={"error": {"code": "subscription_sharing_usage_unavailable", "message": "hidden"}})
    sdk_client(monkeypatch, handler)
    monkeypatch.setattr(providers.time, "sleep", lambda *_: None)
    with pytest.raises(providers.ProviderError):
        providers.generate("chatgpt:model-test", "p", options={"allow_cloud": True, "retry_forever": True, "retries": 2})
    assert len(calls) == 3


def test_plan_auto_concurrency_conserves_shared_allowance():
    assert worker.resolve_workers("auto", "chatgpt:model-test") == 1
