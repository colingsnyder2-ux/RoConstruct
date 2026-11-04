# NVIDIA and DeepSeek provider routing investigation

2026-10-28. Source-only fixes; no server database edits or submissions.

## Findings

- Bare `nvidia/nemotron-3-ultra-550b-a55b` lost the `nvidia/` API model namespace.
  Explicit `nvidia:nvidia/nemotron-3-ultra-550b-a55b` already retained it. Both now
  send the complete model ID. OpenCode uses the separate provider prefix:
  `opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b`.
- Non-transient failures incremented the cloud circuit. Auth-disabled gates then
  reported only a generic open circuit to waiting workers. Gates now retain the
  original safe failure. Only exhausted transient failures count toward a circuit.
  Auth/key/config/model failures stop workers and queued native discovery.
- Installed OpenCode 2.0.16 accepted a positional task, but the old stdin-only CLI
  invocation hung. Native CLI tasks now use a temporary UTF-8 attachment plus an
  explicit instruction, avoiding command-line length limits for large files.
- OpenCode's API generation utility returned empty text for unfenced edit output.
  Native prompts consistently request SEARCH/REPLACE blocks inside a code fence,
  rather than complete C++ files. Unknown HTTP results no longer silently trigger
  a duplicate CLI generation.
- Nemotron Ultra supports `none`, `medium`, `high`, not `low`. Disabled thinking
  now maps to `none` for NVIDIA HTTP and `#none` for OpenCode. Low effort maps to
  medium. Explicit OpenCode variants remain authoritative.

## Validation

- NVIDIA through the contributor's existing OpenCode sign-in: tiny generation
  succeeded in 2.88 seconds. No credential was copied into ROC.
- Real native edit-loop fixture through NVIDIA Nemotron Ultra: 3.7 seconds AI,
  correct anchored edit on its first round. Genuine VS2008 RTM build 21022 COFF
  comparison reproduced one synthetic target and preserved the existing exact
  function. Fixture addresses are synthetic, never client credits. Nothing submitted.
- The contributor's DeepSeek key fetched the model catalog successfully, but
  generation returned HTTP 402 (insufficient balance). The friend's HTTP 401
  cannot be reproduced without that friend's configuration; 401 means credentials
  or access, rather than the balance failure observed here.
- Regression tests cover full IDs, 401/403/404 failure retention without sleeps,
  waiting gate consumers, supported reasoning flags, explicit CLI attachments,
  no duplicate HTTP-to-CLI fallback, and skipping queued files after fatal errors.

The native fixture does not establish gains on the historical client or replace
independent linked ownership/runtime/ABI checks. Remote model latency remains
variable; increasing concurrent requests cannot repair auth, billing or model IDs.
