# Native source recovery with automatic draft sharing

Default assignment: recover new native classes, implemented methods and authentic
associated headers across the client. Spend most effort on these source batches.
A class does not need to unblock the current runnable swap to be a valid target.
Reuse existing files, preserve recovered bodies, and choose unleased classes with
strong original evidence. Extend partial classes when that adds real methods.

Blocker repair is secondary: attempt a small evidence-backed fix when it directly
prevents the current class/header batch from compiling or being checked, within
the existing function budget. Save harder dependency/EH/selection/runtime issues
for owner integration, then continue another class. Do not turn source recovery
into a prolonged Workspace writer, linker or audit campaign. An explicit owner
integration assignment may prioritize those blockers separately.

Current workflow: 53. Use `docs/NATIVE_WORKER_HISTORY.md` only as history.
Native authority: **RoConstruct, branch `work`, subtree `workspace/`**. Local paths
below that subtree retain their normal repository-relative names.

## Concurrent agents and verification

Before choosing files, run `roc.cmd lease ls` and inspect all overlapping leases,
including your own username. The server treats one username as one owner: it
cannot distinguish two chats or stop them replacing or releasing each other's
leases. Choose a distinct unleased family and unique lease name; renew or release
only your own lease. Keep scratch sources, manifests, objects and draft sessions
separate. Never edit another agent's files or shared headers.

Equal byte size is only a lead; establish original address and symbol identity
before matching a body. Report matching pre-existing code as verified existing
work, not a newly recovered method. Byte/data matches do not establish call
bindings, ABI, linked selection or runtime. Do not repeatedly compile unrelated
existing files just to find equal sizes.

In Windows PowerShell, use `Select-Object -First N` instead of Unix `head`.
Use `@'` / `'@` here-strings piped to `python -`, not `python - <<'PY'`.
Use the configured native runner and toolchain instead of guessing compiler paths.
Put temporary scripts and output in a unique task scratch folder.

## Task and priorities

Default to new native class/header recovery across the client. Recover
real native C++ under `rebuild/2008-06/native-classes`, `native-headers` and
`native-world`. Mining requires a separate explicit assignment: do not run
`roc auto`, `roc xcopy`, `roc immediates`, `roc similar` or `roc submit` in this loop.
Mined source is untrusted reference material, not layout or integration authority.

Open each source batch with:

**class/family -> missing source/header -> next implementation -> next check**

For secondary blocker fixes or explicit owner integration work, use:
**swap target -> current concrete blocker -> required source/provider -> next proof**

Read current `AGENTS.md`, `CLAUDE.md` and `docs/NATIVE_SWAP_BATCH.md`. Use:

- Owner checkout queue: `work/native-draft-integration-state.json`, especially
  `next_runnable_target` and `last_owner_engineering_pass`. This is owner-local
  state and is **not currently shipped in the Worker**; there is no contributor
  queue endpoint. If absent, use the owner's assignment and relevant published
  receipts under `work/2008-06/shared-layouts/`; report missing priorities rather
  than inventing a queue. A general class/header assignment can continue with an
  unleased missing/partial class supported by original source/assembly evidence;
  it need not wait for an owner swap target.
- Dependency graph: local `work/2008-06/graph.json`, or the packaged snapshot under
  `site/graph-data/2008-06/`. After missing-input setup, inspect focused evidence
  with `roc graph 2008-06 --focus ADDRESS --depth 1 --json`; refresh only when
  needed with `roc graph build 2008-06`. Graph hints are not ABI/layout proof.
- Research: `research/log.jsonl`, `research/lessons.json` and existing trials in
  `work/2008-06/shared-layouts/`. `roc research note TITLE TEXT` records a dated
  finding. Keep task-owned campaign/receipts in the existing shared-layouts
  directory; do not upload another worker's edits to a shared log as your own.

Record the package marker's `revision` and `workspace-manifest.json`'s
`source_revision` in the task receipt. These identify packaged source content,
not a Git commit or proof of current queue freshness. Compare relevant paths,
receipt hashes and owner priorities before porting newer work. Use a verified
Git SHA for `baseline_commit` only when known; otherwise record unknown. Report
inactive candidates, selected matches, gated swaps, draft receipts and independent
server credit separately. Unknown proof/progress stays unknown.

## Reuse a compatible workspace

Use the current authorized workspace and nearby package markers. Preserve every
edit, installed input, session and outbox. Never reset, stash, force-update,
create a worktree automatically, or extract over existing work. Default client:
2008-06; another requested client must be supported by the actual package.

Compatibility uses `roconstruct-package.json` authority
`RoConstruct/work/workspace`, native workflow version at least 52, the required
files below, and real CLI capabilities. After Python dependencies are available,
check `python -m roc.native_drafts --help` for init/start/checkpoint/flush/status/stop,
`python -m roc.native_drafts stop --help` for `--wait`, and
`python rebuild/2008-06/tests/native_check_runner.py --help` for `--require-proof`.
Exact documentation headings are diagnostics only: renaming a heading does not
require another download. An import error means inspect missing runtime inputs;
do not repeatedly download the same package to fix a missing Python dependency.

A newer source revision is not automatically an incompatible workflow. Keep
valid evidence and installed inputs; update source when relevant queue/dependency
changes require it. An ordinary origin checkout is not the native authority.
Never fetch a retired feature branch as a native baseline.

## Verified fresh Worker bootstrap

Do not ask the user to find a ZIP. Use these actual published resources:

- Manifest: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/native-worker.json
- Package: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/native-worker.zip
- Guide: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/NATIVE_AGENT.md

For an update, checkpoint/flush the old session first as described below. This
Windows bootstrap reuses a verified cache or downloads once, checks SHA-256 and
extracts into a fresh folder in the current authorized workspace:

```powershell
$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'
$nativeManifest = Invoke-RestMethod ('https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/native-worker.json?t=' + [guid]::NewGuid().ToString('N'))
if ($nativeManifest.authority -ne 'RoConstruct/work/workspace' -or
    $nativeManifest.workflow_version -lt 53 -or
    $nativeManifest.draft_workflow_version -lt 1 -or
    $nativeManifest.native_clients -notcontains '2008-06' -or
    $nativeManifest.url -ne 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/native-worker.zip' -or
    $nativeManifest.sha256 -notmatch '^[0-9a-fA-F]{64}$') { throw 'Invalid Worker manifest' }
$nativeWorkspace = (Get-Location).Path
$nativeSearch = @($nativeWorkspace, (Split-Path -Parent $nativeWorkspace), (Join-Path $env:USERPROFILE 'Downloads'))
$nativeSearch += @(Get-ChildItem -LiteralPath $nativeWorkspace -Directory -Filter 'RoConstruct*' | Select-Object -ExpandProperty FullName)
$nativeSearch += @(Get-ChildItem -LiteralPath (Split-Path -Parent $nativeWorkspace) -Directory -Filter 'RoConstruct*' | Select-Object -ExpandProperty FullName)
$nativeCached = $null
foreach ($nativeBase in ($nativeSearch | Select-Object -Unique)) {
    foreach ($nativeCache in @($nativeBase, (Join-Path $nativeBase 'local/packages'), (Join-Path $nativeBase 'local/findings/data'))) {
        if (-not (Test-Path -LiteralPath $nativeCache -PathType Container)) { continue }
        foreach ($nativeZip in (Get-ChildItem -LiteralPath $nativeCache -File -Filter '*.zip')) {
            if ((Get-FileHash -LiteralPath $nativeZip.FullName -Algorithm SHA256).Hash -eq $nativeManifest.sha256) {
                $nativeCached = $nativeZip.FullName
                break
            }
        }
        if ($nativeCached) { break }
    }
    if ($nativeCached) { break }
}
$nativeFolder = Join-Path $nativeWorkspace ('RoConstruct-Native-' + [guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $nativeFolder -ErrorAction Stop | Out-Null
$nativeArchive = Join-Path $nativeFolder 'worker.zip'
if ($nativeCached) {
    Copy-Item -LiteralPath $nativeCached -Destination $nativeArchive
    Write-Output ('Reusing verified Worker ZIP: ' + $nativeCached)
} else {
    Invoke-WebRequest -UseBasicParsing -Uri ($nativeManifest.url + '?sha256=' + $nativeManifest.sha256) -OutFile $nativeArchive
}
if ((Get-FileHash -LiteralPath $nativeArchive -Algorithm SHA256).Hash -ne $nativeManifest.sha256) {
    throw 'Worker ZIP hash mismatch'
}
Expand-Archive -LiteralPath $nativeArchive -DestinationPath $nativeFolder
Set-Location -LiteralPath $nativeFolder
$env:ROC_NONINTERACTIVE = '1'
Write-Output ('Native checkout: ' + $nativeFolder)
$nativeMarker = Get-Content -LiteralPath 'roconstruct-package.json' -Raw | ConvertFrom-Json
$nativeInventory = Get-Content -LiteralPath 'workspace-manifest.json' -Raw | ConvertFrom-Json
if ($nativeMarker.authority -ne 'RoConstruct/work/workspace' -or
    $nativeMarker.native_workflow_version -lt 53 -or
    $nativeMarker.draft_workflow_version -lt 1 -or
    $nativeInventory.authority -ne $nativeMarker.authority -or
    $nativeMarker.revision -ne $nativeManifest.source_revision -or
    $nativeInventory.source_revision -ne $nativeMarker.revision) { throw 'Extracted Worker metadata mismatch' }
foreach ($nativeRequired in @('roc/native_drafts.py', 'research/native-units.json', 'research/native-source-lock.json', 'rebuild/2008-06/tests/native_check_runner.py', 'work/native-client/prove.py', 'work/native-client/bootstrap_tools.py', 'work/native-client/data/identity-registry.json.gz', 'work/native-client/audit_digest.py')) {
    if (-not (Test-Path -LiteralPath $nativeRequired -PathType Leaf)) { throw ('Missing Worker capability file: ' + $nativeRequired) }
}
Write-Output ('Package/source revision: ' + $nativeMarker.revision)

```

Capture the printed absolute checkout path and pass it as the working directory
for every later call. `Set-Location` and environment variables do not persist
across separate tool calls. On Linux use the same metadata/cache/hash checks and
fresh-folder extraction. Read the extracted `AGENTS.md` and `CLAUDE.md`; verify the
CLI capabilities above after resolving missing Python dependencies, before editing.
On failure retain both workspaces/outboxes and report the exact URL, revision and
error; do not repeat an identical failed download indefinitely.

## Install only missing inputs

Reuse verified Python 3.12, historical MSVC/SDK, original clients and vendor caches.
Use `.\roc.cmd` on Windows, `./roc.sh` on Linux; `install.cmd` selects Python if
missing. Keep `ROC_NONINTERACTIVE=1` in each setup call. Do not run `roc update`
on a packaged workspace. Native routing overrides mining-only setup/priorities;
shared preservation and verification rules still apply.

Only when needed, run these existing prerequisites sequentially, stopping on an
actual failure; these are not commands to repeat per function:

```text
roc doctor
roc install --yes --client 2008-06
roc client-fetch 2008-06
roc analyze 2008-06
roc vtables 2008-06
roc rebuild 2008-06 install
roc pull 2008-06
roc lib-fetch rbxgs rbxgs-net rbxgs-appdraw rbxgs-render rbxgs-view openrbx-client
roc libs-bundle fetch mfc-9.0-rtm
```

Use `client-fetch --from VERIFIED_EXISTING_EXE` when available. Skip analysis if
current indexes already cover the verified original. Load persisted input-reuse
environment before later compiler calls. `roc pull` supplies mined references,
not a native source update. Do not run full linked builds or P5/P6 merely to save
a draft, or reinstall everything because an optional probe is missing.

## Scope and initialize before editing

Use actual contributor/model identity; ask only for missing identity. Take real
file leases (`roc lease ls/take/renew/release`); shared headers have one owner.
A new lease does not establish authorship of pre-existing changes. Inspect dirty
files and their provenance first. For mixed ownership, preserve the original and
prepare a task-owned proposal under existing `work/native-candidates/` paths.
Never watch the whole checkout or capture unrelated dirty edits.

Name explicit task-owned source/header/probe/receipt files or directories;
directory scopes include future files. Initialize against untouched packaged
files **before** editing or porting changes. New packaged sessions reject watched
files already differing from their package inventory rather than absorbing edits.
Existing Git edits retain the implementation's HEAD-based provenance, but that
does not make all those edits yours. Keep the original when ownership is mixed.

Use the manifest's `draft_server` (normally the URL below), never another user's
credentials. Initialization is local; the watcher obtains upload-only credentials.
No fork, branch, Git commit, PR, passing compile, live lease or integration approval
is required to upload incomplete/broken native drafts. Private configs and compiled
binaries are excluded; deletions remain review proposals only.

```text
python -m roc.native_drafts init --user YOUR_NAME --model YOUR_ACTUAL_MODEL --server https://colinpc.tail2879d0.ts.net/native-drafts --paths rebuild/2008-06/native-classes/YOUR_CLASS.cpp rebuild/2008-06/tests/YOUR_PROBE.py work/2008-06/shared-layouts/YOUR_RECEIPT.json
python -m roc.native_drafts start SESSION
python -m roc.native_drafts status SESSION
```

Retain the returned SESSION. The baseline is immutable. Restoring a previously
checkpointed file to baseline is also a saved change: its packet references the
previous candidate as the per-path base, with the parent retaining provenance.

## Updating an existing Worker without losing drafts

1. In the old folder, checkpoint, flush and check status. Verify a durable receipt
   for the latest saved snapshot when transport is available. Retain the folder,
   immutable checkpoints and outbox, including anything unsent; report failures.
2. Verify/extract the new package into a fresh folder as above; retain installed
   inputs. Do not overwrite or reset the old workspace.
3. In the new folder, initialize and start a new scoped draft session against the
   **untouched** packaged files. Expand scopes through another fresh session before
   editing newly included files, after checkpointing/flushing the prior session.
4. Port only task-owned changes using old base / current packaged source / candidate
   comparison. Porting is editing; never initialize after it and absorb the work.
   Preserve better implementations and use inactive proposals for mixed ownership.
5. Checkpoint/flush the new session and verify its latest durable receipt covers
   the ported snapshot. End the old watcher cooperatively once its work is safe;
   keep its folder/outbox for any remaining retries.

## Milestones and final shutdown

The watcher checkpoints roughly every five minutes. Use the same session and
retained outbox for retries. An upload receipt proves durable storage only.

Ordinary milestone: save files, then run:

```text
python -m roc.native_drafts checkpoint SESSION
python -m roc.native_drafts flush SESSION
python -m roc.native_drafts status SESSION
```

Keep the watcher running. Inspect health/error/heartbeat, `pending`,
`snapshot_current`, `latest_packet` and `latest_receipt`. `queued` counts retained
outbox packets, including acknowledged ones. Delivery requires `snapshot_current`
true and a matching `latest_receipt.id` / `latest_packet` with `durable: true`.
A later edit invalidates that content-coverage claim until checkpointed again.

Session end: save the last edit, then run:

```text
python -m roc.native_drafts stop SESSION --wait --timeout 60
python -m roc.native_drafts flush SESSION
python -m roc.native_drafts status SESSION
```

`--wait` cooperatively requests stop, waits for the watch lock and completes the
final checkpoint/flush, including recovery when the watcher is dead. Verify the
latest packet's receipt **after** final cleanup, not a pre-stop receipt. Timeout
or transport failure is a blocker: retain the same session/outbox, retry stop/flush
and check status; do not kill the watcher or claim delivery. If the session never
had changes, no draft receipt is expected. Split tasks over the 16 MiB bundle limit
without discarding originals. No new edits in an ended session until resumed.

## Fast native tools (workflow 53)

After the Worker is extracted and the prerequisites above are installed, run once and fix every `MISS` line:

```text
python work/native-client/bootstrap_tools.py --smoke
```

It unpacks the identity registry, builds `registry-identities.json`, checks the original client and MSVC 2008, and proves
one small class end to end. Do not start recovery until it prints `READY`.

Use these instead of compiling by hand (each prints `--help`; run from the checkout root; no `roc submit`):

- `python work/native-client/prove.py FILE.cpp --rounds 3 --infer-names --quiet` compiles a native class with the flags in
  its first-line `// native-flags:` comment and reports byte-exact functions. `--why FILTER` lists the non-exact symbols and
  why; `--diff ADDR` prints the assembly diff. Do not edit shared inventory sources or headers while someone runs `--all`.
- `python work/native-client/scope.py rbxapp --queue 15` is the contributor work queue: unfinished Roblox classes ranked
  (extend partial native files first, then small classes; leased and huge classes last or skipped). Without `--queue` it
  lists every class with its exact/total count. Results are cached; `--refresh` rebuilds them.
- `python work/native-client/upstream_lane.py --root TREE --prefix P --all-in DIR` copies verbatim upstream library
  source and keeps only files with an exact function (G3D, XTP, libpng, libjpeg, zlib, Lua, MFC).
- `python work/native-client/fingerprint.py` and `analog_to_native.py` turn matched mined analogs into native classes;
  `beautify.py` renames their placeholders. `fix_loop.py` applies the deterministic include/friend/extern fixes.
- `python work/native-client/native_commit.py --path GLOB ...` takes the lease, writes the status banners and commits.
  Commit one finished family, or at most hourly; never per function. The tool refuses within 45 minutes of the last
  commit (`--force` overrides) and while a `prove.py --all` census runs (edits would void the census).
- Inferred fields, layouts and inline asm are allowed when the original source plausibly had them. Mark each
  `// INFERRED: <evidence>`; the proof reports inferred names separately from proven ones.

## Hourly self-audit

Set this up once per session, before recovery work. Use your own agent's scheduler on its own login; no CLI, API key or
other provider is needed:

- Claude Code: `/loop 60m Run work/native-client/AUDIT_PROMPT.md` (or the schedule tool with an hourly task).
- Codex: create a recurring automation/task that runs every 60 minutes with the same prompt.
- No scheduler available: at the start of each work step, run it if the newest file in `work/native-client/audit/` is
  older than 60 minutes.

Each run does `python work/native-client/audit_digest.py --write`, reads the digest (bytes/hour, time per tool, repeated
command shapes, waste, tool health) and follows `work/native-client/AUDIT_PROMPT.md`: report the bytes/hour gain, turn
repeated manual steps into one `.py` tool, speed up the slowest step, and try evidence-backed inferences
(`// INFERRED: <evidence>`). It must not skip leases, commit cadence, or the no-`__emit`/no-byte-blob rules.

## Scope: RbxApp only

When the assignment says "RbxApp only" (or `scope=rbxapp`), work only on Roblox's own code: the MFC/COM app classes
(`CRobloxView`, `CMainFrame`, `CBrowserView`, ...) and the `RBX::` engine classes. Skip every library: G3D, Ogre, XTP, ATL,
stock MFC classes (`CWnd`, `CView`, ...), boost, std, Lua, libpng/libjpeg/zlib and RakNet. Run
`python work/native-client/scope.py rbxapp --todo`, pick an unleased class from that list, and ignore library classes even
when a failing build points at them. A Roblox class that needs a library header may include it; do not recover the library
function. Report RbxApp counts separately.

## Recovery and contributor handoff

Follow `docs/NATIVE_SWAP_BATCH.md`. Read original assembly with `roc native-asm`
and focused evidence with `roc source 2008-06 ADDRESS --json`. Keep genuine native
classes/lifetimes; no invented fields, padding, raw-offset views, stubs, assembly
patches or weakened checks. Prioritize class implementations/headers; keep hard swap blockers for the owner.

Compile once per distinct candidate and build configuration. Reuse that exact
object for applicable byte, data and call-binding checks. Recompile whenever
source, included headers, compiler, flags or other relevant build inputs change.
`native_check_runner.py run BATCH.json` isolates outputs;
`analyze RUN --manifest CHECKS.json --require-proof` reuses objects and checks
freshness without compiling. Recorded flag overrides survive shell exit; an
explicit new override selects a different configuration. Preserve historical
receipts lacking build fingerprints, but do not call them fresh proofs.

Byte equality, referenced data, direct calls, indirect-call proofs, ABI/layout,
linked selection and runtime gates are separate obligations. Retain a verified
body while its inputs/evidence remain valid; advance its next obligation and
revisit only when relevant evidence invalidates the result.

After three substantive hypotheses fail to reduce a blocker using the same
evidence, park it and continue an independent authorized blocker. Syntax
corrections and multiple checks of one object are not separate hypotheses.
Revisit parked work when relevant evidence or inputs change.

When available source/dependency/ABI proofs are complete, checkpoint/upload the
candidate and list owner-only selection/runtime gates explicitly. That completes
the contributor handoff, not an integrated swap. Continue another authorized
unleased blocker while owner gates await review. Draft upload never waits for
successful compilation or approval.

Repeat the authorized loop persistently: read current state/leases → choose a
missing/partial class family → test evidence-backed hypotheses → save proofs and drafts →
upload the class batch and choose the next family → repeat. A parked blocker, match, upload or handoff
does not stop all useful work. Do not poll/spin or recompile unchanged candidates.
Near a platform/context limit, save the queue, next action, hashes and evidence,
then flush drafts **before** the limit prevents cleanup. For a global block, end
cooperatively, retain resumable state/outbox, release leases and report the cause.

The owner reviews untrusted packets/code before execution and integrates reviewed
paths into `work/workspace`; executable selection and integration promotion stay
with the owner. Original-MSVC, dependency, ABI, no-loss and relevant P5/P6/runtime
gates still apply. Only independent server verification grants server credit.
Optional `python -m roc.native_drafts notes` / `note SESSION --scope CLASS --text TEXT`
is sparse advisory handoff context; never per function/minute and never ownership.
Clear notes with `--clear` when done. Prefer leases and silence.
