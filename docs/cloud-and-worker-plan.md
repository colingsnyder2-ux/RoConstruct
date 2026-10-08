# Cloud models and worker improvement plan

## Status

Implemented: provider registry, local/Ollama adapter, generic OpenAI-compatible adapter (including NVIDIA NIM and DeepSeek), native OpenAI/Anthropic/Gemini adapters, environment-only key handling, cloud consent gate, request/token/cost budgets, provider concurrency/circuit breaker, redacted telemetry, size-based output caps, provider CLI, hard-target diverse sampling, local-to-cloud stall escalation, call/shape/age-aware reference ranking, strict legal MSVC dataset audit, and fake-provider regression tests.

Still external: a live cloud smoke and benchmark require the owner's provider key and explicit cost authority. No key is present in this checkout. Training pilot needs user-supplied legally usable source/binary pairs; `roc dataset init` and `roc dataset audit` enforce format and project-held-out splits.

## Goal

Let each worker use local Ollama, NVIDIA NIM, OpenAI, Anthropic, Gemini, or a user's OpenAI-compatible endpoint without changing matching, compilation, scoring, leases, or source ownership. Cloud improves candidate quality only if fixed-corpus exact/compile results repay latency and cost.

## Architecture

Keep compilation and scoring local. A worker sends only its prompt to a provider and receives text. The group server never receives provider keys and never calls a provider.

```
lease -> local analysis -> prompt -> provider adapter -> candidate
      -> local MSVC -> local byte matcher -> server submit
```

Add `roc/providers.py` with one stable interface:

```
generate(model, messages, options) -> Generation
Generation(text, state, input_tokens, output_tokens, latency_s,
           provider, model, request_id, finish_reason)
```

Provider adapters:

1. `ollama` — existing local behavior, preserved.
2. `openai-chat` — OpenAI-compatible Chat Completions. This covers NVIDIA NIM and compatible hosted/self-hosted gateways.
3. `openai-responses` — direct OpenAI Responses API.
4. `anthropic-messages` — direct Messages API.
5. `gemini` — direct API.

NVIDIA should be the first pilot because NIM exposes `POST https://integrate.api.nvidia.com/v1/chat/completions`, supports streaming, and documents OpenAI compatibility. It exposes code models including Qwen coder variants and larger reasoning/coding models. Do not hard-code NVIDIA's catalog: model availability changes. [NVIDIA NIM API](https://docs.api.nvidia.com/nim/reference/llm-apis) [NVIDIA model catalog](https://build.nvidia.com/models)

## Model identity and configuration

Use unambiguous names:

```
local:qwen2.5-coder:7b-instruct
nvidia:qwen/qwen2.5-coder-32b-instruct
openai:gpt-5
anthropic:MODEL_ID
gemini:MODEL_ID
hosted:my-provider/MODEL_ID
```

Add a non-secret `roconstruct-providers.json` file:

```json
{
  "providers": {
    "nvidia": {
      "kind": "openai-chat",
      "base_url": "https://integrate.api.nvidia.com/v1",
      "key_env": "NVIDIA_API_KEY"
    },
    "my-provider": {
      "kind": "openai-chat",
      "base_url": "https://example.com/v1",
      "key_env": "MY_PROVIDER_API_KEY"
    }
  }
}
```

Never store a key in this file, `roconstruct-settings.json`, a server lease, candidate source, telemetry, command history, or logs. Keys live only in environment variables or the user's OS secret store. Add `.example` and git-ignore the real file.

CLI:

```
roc provider add nvidia --kind openai-chat --base-url https://integrate.api.nvidia.com/v1 --key-env NVIDIA_API_KEY
roc provider test nvidia
roc model nvidia:qwen/qwen2.5-coder-32b-instruct
roc worker --model nvidia:qwen/qwen2.5-coder-32b-instruct --client 2008-06 --jobs 1
```

`provider test` sends a tiny fixed prompt, reports model, latency, response format, and usage, never prints a key.

## Draft-loop changes

Refactor `draft._ask_context()` into `providers.generate()`. Keep `llm_rounds()` unchanged above that boundary.

- Ollama retains its local context path.
- Cloud providers use explicit `system`, `user`, and `assistant` message lists; never rely on provider-specific opaque state.
- First implementation uses non-streaming cloud requests for reliable usage and finish reasons. Add SSE streaming later behind the same interface.
- Require one C++ fenced block; keep current asm and invalid-qualified-definition rejection.
- Set `max_tokens` from function size. Start with 256 tiny, 512 medium, 1024 large; measure before changing.
- Default cloud reasoning/thinking off for generation. Enable a reasoning profile only in a separately measured hard-function bucket.

## Security and privacy gates

Before first cloud request, print a one-time warning that assembly, symbols, prompts, and later-source snippets leave the machine. Require `--allow-cloud` or saved `cloud_allowed=true`.

- Strip local paths, account names, tokens, and unrelated source from prompts.
- Do not attach executable files; send only the bounded disassembly/facts already used locally.
- Set provider data controls where supported. For example, OpenAI's Responses API has state retention behavior that must be understood before sending proprietary material. [OpenAI data controls](https://platform.openai.com/docs/models/default-usage-policies-by-endpoint)
- Redact authorization headers, URLs with query secrets, and provider error bodies from telemetry.
- Cloud failure returns a normal `provider_error`; no silent fallback to another billable provider.

## Limits and accounting

Each cloud worker must have:

- `--max-cloud-requests`, `--max-cloud-tokens`, and `--max-cloud-cost`.
- Per-provider concurrency and exponential retry only for transient 408/429/5xx failures.
- A circuit breaker after repeated provider failures.
- Telemetry: provider, model, request ID, input/output tokens, cached tokens, latency, retries, finish reason, and estimated cost.
- Optional user-supplied pricing table. If price is unknown, report cost as `unknown`, never invent it.

Cloud concurrency is independent from compiler concurrency. Limit API calls by provider; keep each local MSVC compile isolated. NVIDIA documents OpenAI-compatible streaming responses and standard `max_tokens`; preserve those values in telemetry. [NVIDIA NIM endpoint](https://docs.api.nvidia.com/nim/reference/openai-gpt-oss-120b-infer)

## Worker quality plan

### Phase 0 — measurement first

Record prompt tokens, cached input tokens, output tokens, generation latency, compile latency, stop reason, provider, model, and cost. Freeze a 21-target corpus with tiny/medium/large buckets.

Success: reproducible runs, no secret leakage, complete per-round telemetry.

### Phase 1 — cheap candidate-quality gates

Keep deterministic rejection for inline asm and invalid qualified definitions. Add only observed high-frequency structural rejects: malformed fences, missing target definition, invalid receiver/object usage, and undeclared base/member initializer. Feed one compact error class into the next generation.

Success: lower `bad_reply`/compile-error rate without extra model calls.

### Phase 2 — structure-first generation

Replace free-text CFG hints with a small deterministic IR: entry, blocks, successors, loop back-edges, branches/signedness, calls, stack slots, ECX/`this` evidence, returns, constants, and trusted type evidence. Keep pseudocode, binary facts, and speculative source hints labelled separately.

Success: higher compile-job rate on medium/large bucket; no fuzzy-score-only acceptance.

### Phase 3 — retrieval discipline

Rank known source by class/method tokens, strings, calls, normalized instruction shape, and client age. Send one compact verified method window plus metadata. Never dump a later-version class.

Success: reference arm beats direct arm on the same repeated targets.

### Phase 4 — diverse search

For hard functions only, sample three structurally different candidates, compile all, then rank by exactness, compilation, branch/call agreement, and byte score. Preserve all sources. Stop after a budgeted no-gain streak.

Success: exact matches per dollar/hour exceed single-candidate baseline. Decaf supports sample-and-rerank as a direction, but its model/data differ from historical MSVC; treat it as a hypothesis. [Decaf](https://arxiv.org/abs/2605.11501)

### Phase 5 — model routing

Route trivial functions to deterministic templates/local 7B. Use cloud coding models only for medium/large or repeatedly stalled functions. Use a larger/reasoning model only after a small cloud model compiles but stalls structurally. Never choose by fuzzy average alone.

Success: improved exact or compile conversions at fixed overall budget.

### Phase 6 — MSVC training pilot

Build 100–300 legal MSVC 2005/2008 source-to-binary pairs split by project. Validate compiler flags, function boundaries, relocations, and held-out scoring before any fine-tuning.

Success: dataset audit passes; an existing model baseline establishes a real gap. No model training before this gate.

## Benchmark matrix

1. Local 7B direct/structured/reference, 3 repeats.
2. Local 14B on the hard bucket.
3. NVIDIA one coding model, direct then structured, same targets/rounds.
4. One frontier cloud model only if NVIDIA result justifies cost.
5. Three-candidate search only on the hard bucket.

Track exact matches, jobs compiling, attempts, error codes, rejected asm, rejected malformed output, structure mismatch, median/mean fuzzy score, prompt/output tokens, latency, compiler time, dollars, and exact matches per wall-hour and per dollar.

Do not accept a change from one lucky run. Preserve session IDs, model revision, provider endpoint class, target list, compiler flags, and random seed where supported.

## Implementation order

1. Provider registry + OpenAI-compatible/NVIDIA adapter + fake-HTTP tests.
2. Environment-key validation, `provider test`, cloud opt-in, redaction, and budgets.
3. Telemetry schema and local regression tests.
4. One-job NVIDIA smoke test using a non-secret key supplied by the user.
5. Fixed-corpus benchmark before adding more providers.
6. Native OpenAI/Anthropic/Gemini adapters only after the generic adapter is stable.
