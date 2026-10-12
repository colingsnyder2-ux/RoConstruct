# Help using your ChatGPT subscription

This fork adds **Continue with ChatGPT** to RoConstruct. Eligible ChatGPT Plus
and Pro accounts can run cloud workers using their existing plan limits.
RoConstruct still compiles and checks each reconstruction on your computer.

## Set up on Windows

1. Download this fork and extract it to a folder you will keep.
2. Double-click `setup-chatgpt.cmd`.
3. In the browser, sign in to your ChatGPT account and authorize this app to use
   your plan. Choose your workspace if asked.
4. Return to the console and choose a model from your account's catalog.
5. Let the compiler installation finish. Visit the
   [RoConstruct website](https://colingsnyder2-ux.github.io/RoConstruct/), click
   **Help out**, and choose **Terminal** or **Webpage**.
6. Keep the saved `chatgpt:MODEL` selection. Start with **Recommended** mode and
   **1 worker**.

Your subscription limits are shared with other apps and Codex. Set this app's
limit and its permission to use extra credits in
[ChatGPT Settings → Usage](https://chatgpt.com/settings/usage). Connecting this
fork does not create another usage allowance. RoConstruct does not switch to
an API key when subscription access fails or reaches a limit.

## Connect an existing installation

From this fork's folder, run:

```powershell
py -3.12 -m pip install --user -r requirements-chatgpt.txt
.\roc.cmd chatgpt login
.\roc.cmd launch
```

On Linux, install the optional requirements into `tools/venv` after the normal
`install.sh` setup. A supported secure OS keyring (Secret Service or KWallet)
must be available. Run `./roc.sh chatgpt login` and `./roc.sh launch`.

## Accounts and checks

```powershell
.\roc.cmd chatgpt status
.\roc.cmd chatgpt models
.\roc.cmd chatgpt login --new
.\roc.cmd chatgpt use ISSUED_CLIENT_ID
.\roc.cmd chatgpt login --account ISSUED_CLIENT_ID
.\roc.cmd chatgpt logout
.\roc.cmd doctor
```

`accounts` lists saved registrations and marks the active one. Stop workers
before switching accounts. Registrations remain separate even if they have the
same email address. Sign-out revokes the renewable session and clears local
tokens while retaining the account mapping for later sign-in.

To check inference before starting a worker, take a model slug from
`chatgpt models` and run:

```powershell
.\roc.cmd provider test chatgpt --model MODEL_SLUG
```

This sends a fixed two-word reply request and consumes a small amount of plan
usage. Model discovery and a successful sign-in alone do not confirm that an
inference request will be admitted for your account.

## Storage and limits

Tokens are encrypted outside the repository; the encryption key is held by the
native OS keyring. On Windows,
the non-secret account registry is in `%APPDATA%\roconstruct-chatgpt`.
Sign-in validates PKCE, state, nonce, issuer, audience, expiry, and signature.
Refreshes are serialized across processes to protect rotating refresh tokens.

The provider uses the public Responses API with `store: false` and
`stream: true`. A candidate is accepted only after `response.completed`.
Subscription, permission, and sign-in errors stop new requests in that worker
session. Temporary failures receive bounded retries.

This subscription route does not accept a server-side output-token cap.
RoConstruct's output budget is a local text-size guard. Its request-count cap
still applies, but a token reservation cannot guarantee actual plan usage.
Use ChatGPT's app limit to control subscription usage. A USD cost cap is
rejected for this provider; API pricing does not describe subscription usage.

If sign-in or inference is refused, read the reported error and check your plan,
workspace permissions, and app usage limit. Run `chatgpt login` again after a
confirmed expired or disconnected session. If remote revocation cannot be
confirmed, disconnect the app in ChatGPT Settings.

## Official integration references

- [Registration and sign-in](https://developers.openai.com/siwc/token-sharing-open-source/sign-in)
- [Accounts and token refresh](https://developers.openai.com/siwc/token-sharing-open-source/profiles-and-sessions)
- [Models and inference](https://developers.openai.com/siwc/token-sharing-open-source/models-and-inference)
- [Preview limitations](https://developers.openai.com/siwc/token-sharing-open-source/preview-limitations)
