# Native integration contributors

Worker v8 includes provider routing and OpenCode task-delivery fixes, plus the published original-binary ABI manifest. After source/toolchain
setup, `roc rebuild 2008-06 prepare` validates ABI data, generates missing RTTI,
checks every declared compiler profile, and builds missing dependency libraries with
their ordinary recipes before a native baseline starts. A partial `rebuild install`
no longer treats the presence of rbxgs-app.json as proof that ABI evidence is installed.
VS2005 dependency builds remain separate from the pinned VS2008 native verifier.

This is separate from source mining. A mined 100% snippet becomes readable code
in the coherent rbxgs rebuild; an independent server build must reproduce its
bytes before credit is awarded. Original miners keep their mining points.

## First setup on another PC

Use an updated RoConstruct checkout/worker package with `roc integrate --help`.
Install the historical compiler and obtain your own permitted rbxgs source tree
under `tools/rbxgs/Client`. Vendor trees stay local; packets never replace that
installation. The authoritative build server also needs the 2008-06 client,
manifests, source trees and working rebuild dependencies.
The existing `roc lib-fetch rbxgs` command fetches the configured source recipe
when its source bundle is available to your installation.

Configure your contributor name and the existing group server with `roc config`.
Native integration is public: no invitation, native token or owner approval required.
Claims, queue ownership and independent server verification still apply.

Native verification compiles and runs submitted C++. Operate the verifier under
a dedicated build account/VM for contributors you do not already trust. Private
build directories isolate artifacts; they are not an operating-system sandbox.

Whole-file rebuilds reuse objects only when source/header contents, compiler
binaries, flags, defines and include search paths still match. Include-directory
inventories detect newly shadowing headers; touching unchanged files keeps cache
hits. Object hashes detect replaced artifacts. Cache records sit beside objects
as `.compile.json`; old timestamp-only outputs rebuild once to seed them.

## Parallel AI integrator

The dashboard's Workers drawer offers **Worker** (mining) and **Integrator**
(native rebuild integration). Both use the same provider selector, worker count,
thinking settings, budgets and session controls. The former Agent startup mode
is no longer offered; old session history and the advanced `roc agent` command
remain readable/usable.

```text
roc integrator --model codex:gpt-6.1-sol --workers 16 --compile-workers 4 --batch-files 80 --allow-cloud
roc integrator --model claude:sonnet --workers 8 --allow-cloud
roc integrator --model opencode:PROVIDER/MODEL --workers 16 --allow-cloud
roc integrator --model opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b#none --workers 4 --compile-workers 2 --allow-cloud
roc worker --model codex:gpt-6.1-sol --workers 16 --cloud-concurrency 16 --allow-cloud
```

Signed-in Codex, Claude Code and OpenCode CLIs work alongside existing cloud API,
custom endpoint and local Ollama providers. CLI model availability and allowances
depend on the signed-in account. Select an explicit model for reproducible model
attribution. `codex:default` and `claude:default` use the CLI's configured default;
their label does not establish the underlying model version. CLI responses use
the same anchored edits and local compilation loop as API responses. Codex runs
in a temporary read-only workspace; Claude's text-provider invocation has tools
disabled. CLI subscription usage has no reliable ROC USD estimate; dollar caps
are rejected. Request/token caps still apply at the shared provider boundary.

NVIDIA API models keep their full namespace: `nvidia:nvidia/nemotron-3-ultra-550b-a55b`
(the bare `nvidia/nemotron-3-ultra-550b-a55b` also works). OpenCode adds its provider
prefix: `opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b#none`. OpenCode credentials
stay in OpenCode; direct NVIDIA needs `NVIDIA_API_KEY`. Nemotron Ultra accepts
`none`, `medium`, or `high` reasoning; direct API disabled thinking maps to `none`.

HTTP 401/403 require fixing credentials/access; environment keys override saved ROC
keys. HTTP 402 requires provider balance. HTTP 404 requires the correct model ID and
endpoint. These stop the run and skip queued native files rather than opening a
retry circuit. Only transient network/rate/server failures count toward the circuit.
OpenCode gets native SEARCH/REPLACE blocks inside a code fence. CLI tasks use an
explicit attachment instead of stdin-only delivery. A failed HTTP generation never
silently starts a second CLI generation.

Each integration session snapshots runtime/rebuild files into
`local/integrators/<id>`. Writable overlays, generator changes, claims and outputs
stay there. Installed tools, binaries and mined source inputs are shared with
the contributor installation. This works from a downloaded source ZIP without
Git. Server workspaces remain protected. The native module currently supports
2008-06; mining workers retain all-client support.

Worker count controls parallel **AI file jobs**, up to 256. `--compile-workers`
separately bounds memory-heavy compiler processes. `--batch-files` controls how
many files share one authoritative rebuild. Method-only context is the default;
`--context file` supplies full files when broader context is needed. Completed
file jobs are recorded immediately instead of waiting behind the slowest earlier
request. Pause/stop takes effect before the next file or AI round; already-sent
requests and submitted verification batches finish normally.

These changes target prompt size, compiler memory pressure, queue head-of-line
blocking and repeated server rebuild cost. More AI workers cannot bypass provider
rate limits, missing ABI evidence, ambiguous ownership or serial authoritative
verification. Local preflight gains remain proposals until server acceptance.
No measured end-to-end speedup is claimed without a live accepted batch.

CLI behavior follows the official [Codex non-interactive documentation](https://developers.openai.com/codex/noninteractive)
and [Claude Code CLI reference](https://code.claude.com/docs/en/cli-reference).

## Manual claim flow

```text
roc integrate --count 4
```

This syncs accepted declarative overlays, atomically claims up to four classes,
and writes `work/integration-client/claims/<id>/packet.json`, `PROMPT.md`, and
`notes.md`. Another PC cannot take an active claim. Claims last two hours and
survive server restarts. `roc integrate renew --all` extends active claims;
`roc integrate release --claim ID` releases abandoned work.

Read the packets, then edit real C++ through
`rebuild/2008-06/patches/make_rbxgs_client.py`. Do not edit vendor trees or copy
snippet padding structs/offset views. Cite target addresses in your evidence.
Keep one contributor checkout per concurrently edited batch.

Submit one class:

```text
roc integrate submit --claim ID --model human --evidence-file PATH/notes.md
```

Submit a batch of claims from the same baseline with one rebuild:

```text
roc integrate submit --all --model ACTUAL_MODEL --evidence-file batch-notes.md
roc integrate watch --id JOB_ID
roc integrate sync
```

Use `--wait` on submit to watch immediately. Submission returns a queued job
quickly; the HTTP server does not hold the connection through compilation.
Batch notes must cite evidence for every claimed class. Use the actual AI model
name, or `human`. Repeating the same upload returns the same job.
If verification rejects a candidate, your claims remain available for correction
for another two hours. Edit the generator/evidence and submit again; changed
source becomes a new job, while network replays remain idempotent.

## Thousands of targets in one batch

```text
roc integrate next --targets 2000
roc integrate submit --batch work/integration-client/batches/BATCH_ID.json --model ACTUAL_MODEL --evidence-file batch-notes.md --wait
```

`next` prints the actual saved batch path. It reserves whole classes from one
baseline until it reaches the requested target count, or exhausts eligible work.
The reported count is actual availability; a request for 2,000 is not a claim
that 2,000 matches exist. `--count` instead selects up to 1,024 classes.
Batch JSON selects exactly those claims, avoiding unrelated local packets.
Use `renew --batch FILE` or `release --batch FILE` for one bulk lease request.

Large claim replies share each baseline once on the wire; local packets retain
their full evidence. One submission accepts up to 1,024 source paths, 4,096 edits
per path, 24 MiB of overlays and 2 MiB of evidence, within a 32 MiB authenticated
native HTTP request. Ordinary mining uploads keep their 1 MiB limit. Update both
client and server, then restart the server to load these limits.

Claims reserve work; they do not generate source corrections. Implement and
preflight real methods before submitting. All classes share one independent
linked rebuild and the same runtime, ABI, body-preservation and distinct gates.
These limits increase batch capacity without awarding credit before verification.

## Automatic finding and application

```text
roc research run native-auto-pilot-2008 --jobs 4
roc research run native-auto-fixes-2008 --jobs 4
```

These named grid recipes run the native finder, bypassing ordinary snippet mining.
It compiles real TUs against the accepted overlay, tests method assertion omissions
and the observed x87 profile, then scans instruction bytes **and referenced data**.
Diagnostic changes are minimized to newly exact, unambiguous out-of-line methods.
The final minimized TU is compiled again; losing an existing locally reproduced
owned body rejects that proposal. It claims only successful candidates, applies
declarative generator edits, and queues one independently verified native batch.
The finder respects the running server's class limit, including older 16-class servers.

Evidence and progress live under `work/research/RECIPE/`: `trials.json`,
`final-checks.json`, `proposals.json`, source/object hashes, compiler artifacts,
`batch-notes.txt`, `batch.json` and `summary.json`. The summary's job ID is queued,
not accepted credit; use `roc integrate watch --id ID` and sync after acceptance.
The pilot selects a few real source files; the full recipe scans the App TUs.

Recipes use the checkout's installed native manifests, target executable and
analysis. `ROC_NATIVE_EVIDENCE_ROOT` may point at a local read-only manifest/report
checkout; compilation and generator edits still stay in the working checkout.
Use `native_sweep.apply=false` for proposals only, or `submit=false` to stage and
review proven changes before submission. Staged claims remain leased for review.
Ambiguous overloads, templates, conditional method bodies and layout/signature
recovery defer to manual work. This automates specific proven fix families; it
does not invent fields, offsets, source bodies or claim unverified credit.

## Retry and acceptance

Use `--retry` to rerun an unchanged rejected batch after a verifier/environment
problem has been fixed. Claim operations are explicit:

```text
roc integrate release --claim ID
roc integrate park --claim ID --reason "blocker + addresses"
roc integrate unpark --claim ID
roc integrate unpark --all
```

Release frees work immediately; it does not park. `release --reason` is rejected
with guidance. Park holds a blocker for two hours. Unpark clears your owned park
and frees that class immediately; another contributor's claim cannot be unparked. `unpark
--unit RBX::Class` selects owned parks for that inventory unit, including claims
created on another PC. Status includes park IDs and owners.

Discovery routes claims by the server's address-to-unit inventory rather than
assuming a native method's class is its scheduling label. For example, an
ICharacterSubject method cataloged under RBX::Humanoid claims Humanoid. Parked
classes are skipped; absent units are never requested. Catalog-less proposals
retain the existing carrier-claim fallback and every linked/runtime gate.

Gateway errors do not require rediscovery or a new batch:

```text
roc integrate resume
```

Before POST, the client commits a hash-checked request journal under
`work/integration-client/requests/`: exact payload, generator/base snapshots,
applied files and the linked-proof artifact location. Resume first queries server
state by the same request digest. It recovers already queued/completed jobs or
replays the identical idempotent payload with still-valid claims. It never invents
new claim IDs or retries a rejected job automatically. Both native-try submission
and integrator startup recover unresolved intents before starting new work.
Expired/parked/mismatched claims and incomplete/modified journals retain their
artifacts and require explicit repair. Valid owned leases are reused and renewed
before linked preflight. Protocol version 3 supplies claim inventory, explicit
park/unpark and digest lookup; deploy the updated server before using new endpoints.

Use eight AI workers and four compiler slots initially. Observed 2026-10-28 logs
had a 400.8-second median file run, versus 43.7-second baseline and 40-second trial
compiles; more AI workers can increase compiler waiting. New logs separate compile,
queue and comparison time. Method prompts now carry three targets and request
small unique anchors. Identical candidate source reuses a dependency-checked
compile path; identical objects reuse code/data comparisons. Minimization reuses
an already verified final object. Independent linked verification is unchanged.
The signed launcher and direct worker CLI now pass job limits and worker counts
by name, fixing the duplicate `use_remill` error and accidental positional binding
of worker counts to lift controls. Worker v7 / matching workflow v2 includes these fixes.

`status` shows jobs and the separate native-credit leaderboard. The server checks
the linked rebuild, M2/M4a/M5, size/base regressions, owned addresses and global
distinct coverage. A failed candidate never changes accepted overlays or awards
credit. Stale anchors fail before compiling. Nonconflicting queued work can
rebase against the latest accepted overlay and is fully reverified.

One new distinct client/address earns one native credit, once, regardless of
retries or overlapping submissions. Already-mined 100% functions earn no new
raw mining score gain. Each native credit adds one total leaderboard point and one
Native integrated count. Address-ambiguous bodies do not receive distinct credit.

Accepted data is durable in the server DB and materialized as
`patches/native-promotions.json`; the trusted generator consumes it. `sync`
downloads accepted overlays. It restores a locally edited generator only when
its bytes exactly match your accepted submission and a preserved baseline;
other unsent edits are never overwritten.

## Existing mass matching

Ordinary matching remains available independently:

```text
roc worker --workers 4 --jobs 100
```

The existing worker uses configured model/client/provider settings. Integration
batching does not change its leases, matching scores, points or webhook routing.

## Server operation and progress

The normal `roc server`/`roc host` service starts a serialized native verifier.
It keeps claims, queued work, accepted recipes and credits in `work/server.db`.
Native contribution endpoints are public, even when ordinary mining has a server
password configured. Restart the existing service after installing this feature;
do not start another listener on port 8765.

Each verification uses private writable build outputs. Uploaded bundles contain
validated declarative edits; the HTTP server never executes uploaded Python.
Only the server-owned verifier can finish jobs or issue credit. Baseline receipts
are cached by content hashes of rebuild code, source/toolchain inputs, target
metadata and linked input artifacts, not the age of a report. Candidate work
reuses proven outputs with remapped private include dependencies.
The native verifier pins its historical compiler/SDK for its process lifetime;
restart it after changing the configured toolchain. SDK/compiler discovery is
not repeated for every ABI probe. Accepted candidates become the next cached
baseline, including failed-candidate retries against an unchanged baseline.

To move your queued batch to the front of the waiting queue:

```text
roc integrate force-queue --id JOB_ID
```

The latest force-queue request is selected first after active verification finishes.
Priority survives server restarts, keeps submission timestamps, and preserves normal
batch merging and all verification gates. Only the batch owner may prioritize it;
verifying and completed jobs cannot be force-queued. The server must load the updated
queue handler before using this command; restart it when no verification is active.

Cold verification can take many minutes. Batch several coherent fixes to amortize
it. Current phases are snapshot, baseline build/checks, preflight, building,
checking and complete; no fabricated compiler percentage is shown.

Use `roc integrate fingerprint` for a read-only fingerprint timing check. Initial
full/live fingerprints share one input walk and one content-read pass; later live
checks still detect source/toolchain changes during verification, including edits
that preserve file size and timestamps. Output/cache trees are pruned before descent.
The native cache key covers compiler/matcher/gate modules and build inputs, excluding
unrelated CLI, UI, reporting and webhook modules. The shared integration module is
included because it merges source overlays, even though it also contains queue logic.
Milestones execute the build module directly.

Compiler/SDK path discovery is persisted in `work/integration/toolchain.json`, checked
against resolver code, installation state, configuration and existing paths. Compiler,
SDK and source bytes are still content-hashed. New baseline snapshots checkpoint their
prepared input identity before compiling; after interruption, matching snapshots reuse
their private content-checked objects and rerun every gate. Unprepared snapshots are
retained for diagnostics. Completed baseline receipts remain required for acceptance.

Server Mining receives a fresh digest for accepted native gains: purple integrated native bodies,
blue exact mined sources awaiting integration, white remaining targets.
The 23-cell bar measures code bytes, excluding compiler stubs; category counts and
remaining functions are shown separately. Combined points include one point per
distinct native integration; native counts remain visible. ETA is a rough recent-rate estimate. Notifications
cannot make a valid rebuild fail.

Native contributor submissions now run the independent linked build locally before staging.
`roc native-try preflight` checks all saved proposals without claiming/submitting. The same
M2/M4a/M5, size/base, linked ownership and global coverage gates remain mandatory on the server.
Private baseline caches live in `work/native-linked-preflight/`; candidate receipts and logs
are under `work/native-try/linked-preflight-*` (automatic submissions use `work/native-try/submit/`).
Cold baseline builds can take minutes. A baseline advance requires fresh revalidation;
failed proofs retain saved proposals. Successful replacement checks archive their prior file.

Native source paths use case-insensitive identity, preserving the accepted registry spelling.
`App/gui/Gui.cpp` must extend accepted `App/gui/GUI.cpp`, not overwrite its floating-point pragma
through a second registry key. Ambiguous duplicate keys fail before overlay writes. Guarded
recipe replacement still requires the exact previous recipe. Verifier input hashes include
the shared merge implementation. Objects carry `.command.json` provenance alongside their
content-checked `.compile.json` and resolved `.deps`; legacy objects without provenance rebuild.
Rejections record gained/lost/uncovered addresses, baseline revision and diagnostic folders
when a completed candidate comparison exists; early build failures retain available artifact paths.
