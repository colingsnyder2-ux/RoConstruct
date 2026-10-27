# Native integration contributors

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
The build-server owner runs `roc integrate invite` and privately gives trusted
helpers the invitation token. Pass it as `--token INVITE` to integration commands,
or set `ROC_NATIVE_TOKEN` in your own environment. Public mining needs no new
password. Do not post invitation tokens, executables or vendor trees.

Native verification compiles and runs submitted C++. Operate the verifier under
a dedicated build account/VM for contributors you do not already trust. Private
build directories isolate artifacts; they are not an operating-system sandbox.

## Quick flow

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
Use `--retry` to rerun an unchanged rejected batch after a verifier/environment
problem has been fixed. Use `release --claim ID --reason "blocker + addresses"`
to park blocked work for two hours instead of immediately assigning it again.

`status` shows jobs and the separate native-credit leaderboard. The server checks
the linked rebuild, M2/M4a/M5, size/base regressions, owned addresses and global
distinct coverage. A failed candidate never changes accepted overlays or awards
credit. Stale anchors fail before compiling. Nonconflicting queued work can
rebase against the latest accepted overlay and is fully reverified.

One new distinct client/address earns one native credit, once, regardless of
retries or overlapping submissions. Already-mined 100% functions earn no new
raw mining points. Address-ambiguous bodies do not receive distinct credit.

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
An invitation is generated privately on first startup when no server/native
token is configured. Restart the existing service after installing this feature;
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

Cold verification can take many minutes. Batch several coherent fixes to amortize
it. Current phases are snapshot, baseline build/checks, preflight, building,
checking and complete; no fabricated compiler percentage is shown.

Server Mining receives one editable digest: purple integrated native bodies,
blue exact mined sources awaiting integration, yellow partial mined sources,
white unmined targets. The 23-cell bar measures target bytes; category counts and
remaining functions are shown separately. User points are real, native credit
is separate, and ETA is labeled as a rough recent-rate estimate. Notifications
cannot make a valid rebuild fail.

## Rebuild input location

Native sources and required build inputs live in RoConstruct-findings/2008-06. Run `roc rebuild 2008-06 install` before native integration on a fresh checkout. Existing local build paths remain supported; accepted overlays, leases and server receipts keep their existing meaning.
