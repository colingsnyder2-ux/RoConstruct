# Native integration with an agent (Codex, Claude)

## Command compatibility

This guide's manual loop uses `roc native-try targets / evidence / check / submit`.
The GUI's continuous session uses `roc integrator`. Keep these supported paths;
`roc integrate work` and `roc integrate packet` do not exist. Earlier workflow
instructions requiring those actions were incorrect. Their absence in Worker v12
is not a reason to download that same package again or stop native-try work.

Before setup, inspect the installed CLI once:

```text
roc native-try --help
roc integrate --help
```

On Windows use `roc.cmd`; on Linux use `./roc.sh`. For explicit class claims,
use `roc integrate next --count 4`. If the installed CLI lists `context`, retrieve
one claimed target with:

```text
roc integrate context --claim CLAIM_ID --address ADDRESS
```

`context` needs the configured server and a saved local claim containing ADDRESS.
It saves `context/ADDRESS/context.json`, `mined.cpp`, `target.asm` and native source
files beneath `work/integration-client/claims/CLAIM_ID/`. It does not generate
CONTEXT.md or accept `--max-tokens` / `--unit` search hints. Missing `context`
does not block this guide's native-try evidence loop. Use the actual command help
and server capabilities rather than assuming a package version supplies an action.
Compiler smoke success establishes compiler readiness only; report native credit
only after independent server acceptance.

## Match the current GUI Integrator

Choose one execution path for a mutable workspace. For the GUI, run `roc gui`,
open **Workers → + New → Integrator**, select the actual model, contributor and
server, then **Start Integrator**. Native sessions currently use 2008-06 only.
The equivalent continuous CLI uses the same backend:

```text
roc integrator --model YOUR_ACTUAL_MODEL --workers 4 --rounds 3 --output-budget 3072 --batch-files 1 --compile-workers auto --compile-batch 4 --context methods --generation auto --thinking disabled --cloud-concurrency auto --allow-cloud
```

Use remote prompts only within the operator's authorization. The GUI offers
signed-in CLIs, API providers and local models. Selecting a model does not change
the independent acceptance gates. The manual agent path below writes its own
anchored edits through native-try; it follows the same evidence/acceptance goals
but does not automatically acquire the GUI's scheduling or shared compiler jobs.
Do not launch a second editor or continuous session in its mutable staging tree.

| Current GUI control | Behavior to preserve |
| --- | --- |
| Concurrent AI workers / Cloud concurrency | File-job slots and simultaneous provider requests are separate limits. More slots do not bypass rate limits. |
| Parallel local compilers | Independent compiler limit; `auto` caps at 8 slots subject to CPU capacity. |
| Files per integration batch | Set 1 for immediate per-file submission (program default: 40). This does not promise acceptance. |
| Methods per shared compile | Default 4 independent edits per file; split conflicting/failing combinations, recompile retained edits. |
| Source context / AI output | Default `methods` / `auto`: one complete method, then anchored repairs. Manual native-try still consumes SEARCH/REPLACE blocks. |
| Rounds / Output tokens | New native sessions start at 3 / 3072; configured presets or edits can override these values. |
| Request / Token / Estimated spend caps | Session-wide limits. Editing a cap retains usage already spent; unknown pricing is not zero cost. CLI subscription dollar caps are unsupported. |

GUI presets are shared with mining workers. **Balanced** preset does not select
the CLI's native `--mode balanced` ranking policy. The current GUI form does not
expose native selection/escalation/no-improvement controls; use supported CLI
flags when the operator requests those settings.

Keep the agent's progress loop aligned with the GUI:

1. Sync the accepted baseline, inspect saved proposals before generating more
   edits, and work from genuine declarations and target evidence.
2. Test one hypothesis, preserve local gains, isolate failures, and stop spending
   on an unchanged exhausted target. Broaden method context only when needed.
3. Queue each completed passing fix immediately. Record each job ID, keep discovery moving,
   and check pending jobs between batches. Local exact, queued and accepted are
   separate states; only accepted receipts add verified native credits.
4. On baseline advance, reconcile and recheck saved proofs before new generation.
   The automatic backend can recover saved proposals without another AI request;
   the manual path uses native-try revalidation and submit recovery described below.
5. Rotate pending targets after a discovery pass. Revisit exhausted targets only
   when relevant inputs change; respect provider/attempt budgets and stop/pause.

The GUI snapshots mutable runtime/rebuild inputs under `local/integrators/<id>/`.
**Restart offline / failed** reuses that same session's owned workspace, proofs
and compiler cache. **+ New** creates a separate workspace; a new CLI invocation
does not imply recovery of an earlier GUI session. Keep its printed path and job
IDs when diagnosing failures.

Use **Configure → Apply changes** for supported live settings. Pause/stop is
checked before the next file or AI round; already-sent requests and submitted
server batches can finish. Closing the browser tab leaves the dashboard running;
exiting the dashboard stops its process trees. Verify final server job states
when resuming instead of assuming interrupted local monitoring cancelled a batch.

## Missing native types or build units

Do not bypass the invented-type gate or upload `@replace` adoption directives.
For a genuine missing declaration/build unit, create a JSON evidence packet and
run `roc native-promote submit packet.json`. Include client, baseline revision,
actual writer model, exact-mined target witnesses, source/RTTI/ABI evidence,
anchored patches, and declaration header/size records. Direct allocation sizes
must match server binary evidence. Embedded types require exact binary instruction
sites plus a size derivation for owner review. See docs/INTEGRATION.md for schema
and host-only inspect/queue commands. A quarantined packet grants no credits;
only independent compile/link/runtime/ABI/ownership acceptance publishes it.

Other contributors can submit packets from their own PCs; the owner does not
need their local lane-map file. Send the packet ID when escalating. Do not claim
the class is promoted until its server job is accepted.

Paste this file into a Codex or Claude Code session opened in a RoConstruct checkout. It follows the native
conversion workflow used by the automatic Integrator. You write the edits; the tools compile the real
2008-06 file, check exact bytes and referenced data, minimize your edits, and submit verified batches.

## Continuous, terse operation

Continue until the user stops the run or a configured provider/budget limit requires action.
After setup succeeds, do not repeat readiness checks, ask to continue, or end after submitting.
One status line per meaningful change: `FILE: +N local, queued JOB; next FILE`.
Do not narrate every command or foreground-wait on a queued rebuild. Byte/data preflight
and independent server acceptance remain mandatory.

Select once. Reuse client, checkout, installed dependencies and successful setup across
retries/restarts. Repeat setup only for actual missing dependencies or changed build inputs.
Read this guide once; prefer `--brief` evidence and small method excerpts afterwards.

Submit each completed passing fix immediately; do not accumulate 10–30 targets or wait
for the rest of a file list. Include only inseparable supporting edits in its coherent batch.
Save the submitted job ID, then immediately discover more proposals: submit restores the private baseline. Check pending jobs once per batch or every
few minutes. Use `integrate watch` only when the user requests waiting or a dependent step
requires acceptance. Revalidate after baseline changes, not after every status poll.

If the server goes down, keep the session alive and retry for up to two hours of continuous
outage. Start an elapsed-time deadline at the first connectivity failure. Query `/v1/status`
after 30s, then 60s, then every 2m; cap each request timeout at 30s and each wait at 60s so
stop/pause remain responsive. Resume automatically when a valid server response returns;
reset the outage deadline only on successful contact. Do not ask the user to restart or
reconfirm while waiting. Continue independent local trials where possible, preserving edits,
proofs, claims and submitted job IDs. After recovery, refresh baseline/claims and check job
IDs or server scores before replaying an uncertain submission. Never disable TLS verification
or duplicate queued submissions. Authentication, invalid-request and verification rejections
need their actual repair; they are not server outages. If still unreachable at two hours,
save progress, report the last error and pause network work until the user resumes it.
A rejected batch needs repair; it does not end the session. If no fresh
targets remain, stay alive at a modest polling interval; revisit after source/evidence changes.
Respect stop/pause and configured limits. Report only meaningful blockers or new progress.

The automatic Integrator starts another discovery cycle within 60s without fresh
files, rotating pending targets. Failed linked preflight retains saved proposals
and continues other files after 30s. Idle AI slots during linked preflight are
expected; inspect phase heartbeats before diagnosing a stalled controller.

For OpenCode NVIDIA sign-in, select `opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b#none`;
direct NVIDIA API uses `nvidia:nvidia/nemotron-3-ultra-550b-a55b` with `NVIDIA_API_KEY`.
Keep the full vendor namespace. HTTP 401/403 means repair credentials/access, 402 means
provider balance, and 404 means repair model ID/endpoint. Do not retry these as outages.
Permanent provider errors stop generation and skip queued files. Do not duplicate
CLI generations after uncertain HTTP results.

Automatic integrator workers share a whole-source-file compile for independent method edits:
`roc integrator --compile-batch 4 --compile-workers auto`. The default is four methods;
1 disables shared compilation, up to 32 is supported. Conflicting edits and failing batches
split for diagnosis, and recovered combinations are compiled again. Exact code/data,
baseline-loss, linked ownership, ABI and runtime checks remain mandatory. Compiler auto
caps at eight or half the logical CPUs; more AI workers need not mean more compilers.
The automatic Integrator queues immutable saved proposals when the accepted baseline
advances before submission. The next automatic pass rechecks them without AI, using
their original model attribution. Current compiler/code/data/ownership proofs and
combined linked/runtime/ABI checks remain mandatory. Already integrated targets are
skipped; stale individual edits are retained separately for repair without blocking
safe files. Gateway recovery checks existing server state before replaying requests.
Rejected server batches are not blindly resubmitted. Recovery archives and tickets
live under the run's `recovery-proposals/` and `recovery-pending/` directories.

Automatic scheduling fills short batches with different pending targets from
earlier files. Exhausted files reopen when relevant source/baseline inputs change.

## Failure and recovery

| Observed result | Next action |
| --- | --- |
| Unknown CLI action | Inspect installed help. Use native-try or supported next/context commands; do not require work/packet actions. |
| Compiler / SDK / include error | Repair the named prerequisite or evidenced source error. Reuse working setup; rerun only the failed trial. |
| Method bytes or referenced data differ | Read the first relevant diff; test one hypothesis in the real TU. Never promote masked-code agreement alone. |
| Lost exact / ambiguous ownership | Isolate the offending edit. Require linked surviving ownership or remove that edit before submitting. |
| Missing declaration / ABI evidence | Save the precise missing fact, move to another target; use the documented promotion path for genuine missing native types. |
| Baseline advanced / stale anchors | Preserve proposals, sync, reconcile changed anchors and recheck. Retain the original writer attribution. |
| Submission timeout / gateway error | Save job/request identifiers, inspect server state, then use integrate resume or native-try submit recovery. Never create a second batch blindly. |
| Server rejected / failed | Read the receipt, repair its actual cause, revalidate; continue independent work. A rejected receipt grants no credit. |
| HTTP 401/403, 402 or 404 from provider | Fix credentials/access, balance or model/endpoint respectively. These are not transient outages. |
| Server unreachable | Follow the bounded outage policy above; preserve proofs and job IDs. Refresh claims and baseline after recovery. |
| Provider budget reached / operator stop | Save the checkpoint below; stop new generation. Already-submitted server jobs may finish. |
| Repeated build/generator timeout | Inspect phase logs and process state; preserve artifacts. Noninteractive children must not inherit controller stdin. Do not regenerate the same edits as a timeout workaround. |

## Durable checkpoint

Keep one small `native-agent-checkpoint.md` in the active private checkout. Update
it after saving a useful proof, submitting a batch, changing baseline, or stopping.
Reference existing receipts rather than copying large evidence packets. Never
include credentials, provider keys or lease tokens.

```text
Client / server / contributor / actual model: ...
Absolute checkout / GUI session ID (if applicable): ...
Accepted baseline revision / generator hash: ...
Current file / targets / hypothesis / rejected variants: ...
Saved proposals / object and source proof paths: ...
Claim IDs / last confirmed lease state: ...
Pending job IDs / last confirmed states / receipt paths: ...
Accepted new native credits / local-only gains: ...
Budget spent / remaining (unknown where unavailable): ...
Blocker / next command / stop or pause instruction: ...
```

On resume, retain the recorded workspace and selected client. Honor recorded
stop/pause until the operator resumes work. Check pending server jobs first, then
refresh baseline/claims and revalidate affected proofs. Do not infer acceptance
from a saved local score, or replay an uncertain request with a new identity.

## First response: select the client

Before setup or identity questions, fetch the public server's `/v1/status` using the agent's HTTP tool
or one grouped HTTP request. Default server: `https://colinpc.tail2879d0.ts.net`; use an explicitly supplied server instead.
Then make the first user-facing response a selectable question: **"Which client do you want to run?"**
List every returned client, showing `integration_percent` as **X% integrated (integrated/functions)**.
Use `native_supported` to label clients without a native rebuild **"integration unavailable; source mining available"**.
A null percentage means **"integration unknown"**, never 0%. Do not show mined/matched percentages as integration.
Do not substitute old screenshot numbers or cached example percentages. If the server is unreachable, show
that error and fetch the registered client names from the public site's progress data; mark integration unknown.
Use the agent's question tool when available. Wait for selection before client downloads, analysis, claims or trials.
If a client was explicitly selected earlier, keep it; do not ask again. Native integration currently supports
**2008-06** only. Other clients can use ordinary source mining; explain their native limitation in the choices.
Keep the selected client locked for this run.

## Verify RoConstruct is up to date

First locate existing work. Prefer the checkpoint's absolute checkout, then the
current directory, then immediate `RoConstruct*` folders in this authorized
workspace and its parent. Inspect `roc.py`, package identity, contributor/server
configuration, saved proposals and pending job IDs. Reuse a suitable idle private
checkout; do not create another folder merely because a new chat started. Never
take over another active session or a checkout containing `work/server.db`.
Do not recursively search the whole drive or reset existing edits.

After client selection, before setup, claims or native trials in a new or resumed
session, fetch the current Worker manifest below with cache busting. Compare its
`workflow_version` and package `sha256` with the installed package identity.
Having the files or meeting this guide's minimum version is not enough: a package
can be republished with fixes without changing that minimum. Record the checked
manifest version/hash and installed package identity in the session checkpoint.

If the Worker needs updating, first look for a cached ZIP matching the manifest's
SHA-256 in the chosen workspace, immediate RoConstruct folders, `local/packages`,
`local/findings/data` and the user's Downloads folder. Reuse verified media;
download only when no matching archive exists. Extract an update into a fresh
private folder. Preserve the old checkout, local edits, saved proofs, claims and pending
job IDs. Reconcile saved work with the current accepted baseline and revalidate
it before submitting. Never overwrite a running agent's files or reset/stash
someone else's changes to perform an update.

For a normal Git installation, inspect status and its configured remote/upstream,
fetch updates, and use a fast-forward update only when the checkout is clean and
that upstream is unambiguous. Preserve dirty/diverged work in its current checkout;
use a separate current checkout instead of forcing an update. Packaged Workers
must use the verified package-refresh path, not `roc update`.

If the update check fails, report the actual error and that currency is unverified;
do not claim RoConstruct is up to date. Recheck after a long interruption or a
server compatibility error, not before every unchanged local trial. If the newest
package still disagrees with the server's generator/protocol, preserve work and
report both versions; do not repeatedly download the same incompatible archive.

## Automatic Worker download

Do not ask the user to locate or attach a Worker ZIP. If `roc/native_try.py`, `research/native-units.json`,
or `research/native-source-lock.json` is missing, `roc native-try --help` is unavailable, or a package marker
reports `native_workflow_version` below 12, download the current Worker package yourself:

- Manifest: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.json
- Package: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.zip
- This guide: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/NATIVE_AGENT.md

Use the chat's current authorized workspace, never an assumed Desktop or owner-specific path.
On Windows the following grouped PowerShell bootstrap downloads and verifies the archive, then extracts
into a new folder without overwriting the user's existing checkout or edits:

```powershell
$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'
$nativeManifest = Invoke-RestMethod ('https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.json?t=' + [guid]::NewGuid().ToString('N'))
if ($nativeManifest.workflow_version -lt 12 -or
    $nativeManifest.url -ne 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.zip' -or
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
```

On Linux use the same discovery/cache checks and HTTPS manifest/package, verify
SHA-256, and extract only a needed update into a fresh authorized folder.
Capture the printed absolute checkout path and use it as the explicit working directory for every later
tool call. `Set-Location` and process environment changes do not persist across separate terminal calls.
Set `ROC_NONINTERACTIVE=1` again in the grouped setup call if needed.
Read the extracted `AGENTS.md` and `CLAUDE.md`, then execute setup below. Use an existing working server
configuration when supplied, otherwise use the manifest's `server` URL. Never copy another contributor's
credentials. Ask only for missing contributor identity. Native integration is public; no invitation required.
If downloads fail, retry and report the actual URL/error; never invent a successful install.
After extraction, check `native-try --help` again. If required native-try commands
or files remain missing, report the manifest version, package revision and exact
error. Preserve the existing checkout and edits; do not repeat the same download
indefinitely. Never require the nonexistent `integrate work / packet` actions.

## Goal

Make byte-exact mined 2008 functions come out of the real rbxgs C++ (native integration). A target is a function
that is already 100% mined and whose method already exists in the rebuild but compiles differently. Credit comes
only from the server's independent linked rebuild.

## Setup (execute before mining)

Install missing dependencies yourself; downloads are authorized. Do not stop at a setup plan or ask the
user to download dependencies manually. Reuse installed files. Group setup commands into one terminal
invocation, run sequentially, and stop on the first failure. Retry a failed download before reporting a blocker.
Use existing `roc` commands; do not import project modules from ad-hoc scripts.

Use a current Worker package or checkout with `roc native-try --help`. The Worker package must include
`native_try`, `native_sweep`, `standins`, `rebuild_install`, this document and `research/libs-bundle.json`.
If a public clone lacks `roc/native_try.py`, use Automatic Worker download above rather than cloning
that same public revision again. A pasted copy of this guide is sufficient to obtain the package.
Reuse a compatible private checkout; extract into a fresh authorized folder only
when installation/update is needed. Keep older checkouts and edits intact.
A guide cannot grant filesystem or network permissions. Packaged installs contain `roconstruct-package.json`;
their installer keeps the bundled code instead of replacing it with potentially older public Git code.
Do not run `roc update` on that standalone package; use Automatic Worker download for a fresh update.
If Python 3.12 is unavailable on Windows, run `install.cmd` first. Linux requires Wine and cabextract/7z.
If Git is missing, install Git for Windows with
`winget install --id Git.Git -e --accept-package-agreements --accept-source-agreements`, then refresh PATH before fetching source trees.
Use the platform package manager for Git on Linux. Report an actual OS permission block if installation
requires approval; a prompt cannot grant administrator rights.
If `python --version` reports 3.12 but `py -3.12` fails, use `python roc.py ...`; do not reinstall Python
solely because its launcher registration is broken. Current `roc.cmd` and `install.cmd` select a working
Python 3.12 directly before trying `py`. Agents may set `ROC_NONINTERACTIVE=1` to suppress installer pauses.

Use a private contributor checkout: `native-try` writes local rebuild outputs and refuses a checkout
holding `work/server.db`. Server DB, manifests and compiled server outputs are not required on another PC.
Keep one contributor checkout per concurrent agent. Preserve unsent edits when updating or syncing.

Configure the contributor name and reachable group-server URL with `roc config --user NAME --server URL`
if not already configured. Use the supplied server URL, not the owner's `localhost`. No native invitation,
`ROC_NATIVE_TOKEN` or owner approval is required. Ask only for missing contributor identity.
Leave `ROC_NATIVE_EVIDENCE_ROOT` unset on
another PC; it is an optional same-machine testing override.

Before downloads, inventory existing dependencies once. Run `roc doctor` and
`roc rebuild 2008-06 doctor`; inspect this checkout's tools, client executable,
analysis files and native source trees. Also check the selected checkpoint and
nearby existing RoConstruct installs for working tools and compiler media.
`roc install` already skips detected compiler builds. For compilers outside its
tool tree, set `ROC_CL` to the verified cl.exe paths (platform path separator);
for a working SDK use `ROC_WINSDK`. Do not reinstall working Python, Git or SDKs.

Compiler downloads first reuse pinned ISO/MSI hashes from `tools/dl`, immediate
nearby RoConstruct installs, the workspace parent and Downloads. Extra cache
directories can be supplied through `ROC_DOWNLOAD_CACHE` (platform path
separator). Original ISO names `DVD1.ISO` and
`Micorosft_Visual_C++_2005_Express.iso` are recognized too. Never trust filenames
alone or remove another checkout's cached files. Reuse existing vendor trees
through supported configuration/shared inputs; never copy credentials or blindly
replace this checkout's modified tools.

On Windows, use `.\roc.cmd` (Linux: `./roc.sh`). The following is the dependency
order for missing/stale prerequisites, not a mandatory full setup on every run.
Run only needed steps; keep baseline sync and validation before new trials:

```text
roc install --yes --client 2008-06
roc client-fetch 2008-06
roc analyze 2008-06
roc vtables 2008-06
roc rebuild 2008-06 install
roc pull 2008-06
roc lib-fetch rbxgs rbxgs-net rbxgs-appdraw rbxgs-render rbxgs-view openrbx-client
roc libs-bundle fetch mfc-9.0-rtm
roc rebuild 2008-06 prepare
roc integrate sync
roc rebuild 2008-06 doctor
roc native-try targets --limit 20
```

Skip analysis setup only when both `work/2008-06/functions.jsonl` and `vtables.json` cover the current verified client.
If only the RTTI index is missing, run `roc vtables 2008-06` without repeating analysis.
`rebuild prepare` validates the published ABI evidence, RTTI index, all declared historical compiler
profiles and dependency libraries before a cold native baseline. Missing libraries build through
their ordinary module recipes (including VS2005/50727 where declared), outside the pinned
VS2008/21022 app verifier. It does not relax that profile or any acceptance gate. Worker packages
include the original-binary ABI manifest; `rebuild install` also fills it when recipes already exist.
`install`
installs Python packages and historical compilers; the VCForPython bundle supplies the Windows SDK.
`lib-fetch` downloads rbxgs and its Git submodules; `pull` downloads mined sources and generated units,
which `lib-fetch` then installs. The Worker also bundles the accepted adopted native headers in
`research/native-units.json`; `lib-fetch` installs these even when the remote unit registry lacks them.
`research/native-source-lock.json` pins source repositories to the server-compatible revisions on fresh installs.
If an existing vendor checkout has another revision or local edits, preserve it and bootstrap a fresh Worker
folder rather than resetting or stashing someone else's work.
The indexed MFC bundle supplies ATL/MFC headers/libraries.
`rebuild install` obtains trusted build recipes when absent. `integrate sync` installs accepted overlays.
`rebuild doctor` must compile, link and run its smoke EXE before starting native trials.

If an existing Git rbxgs installation has empty dependency folders, check `git -C tools/rbxgs submodule status --recursive`.
Initialize only the paths marked `-` using `git -C tools/rbxgs submodule update --init --recursive --depth 1 -- PATH...`;
preserve modified initialized submodules. Do not patch vendor files by hand. If a required vendor bundle
is unavailable, report the named missing dependency and download error; do not replace it with stubs.
If doctor cannot find an installed SDK, set `ROC_WINSDK` to this PC's SDK folder containing `Include` and
`Lib/kernel32.lib`; never copy the owner's absolute paths. Resolve compiler/SDK errors before continuing.

## Local trial setup

- `check` edits one source/header. For a header fix, use `--only ADDR` to identify a real caller;
  the tool compiles that caller against the trial header and restores the private overlay afterwards.
  Saved header proposals remember their caller and pass the same independent server gates.
- Evidence comes from local rebuild artifacts when present, otherwise from the server (`/v1/integration/evidence`).
  Missing local mined sources are fetched from `/v1/source`; unavailable proofs stop with an explicit error.
  Library-referenced proofs still require their local vendor sources/generated units.
- Saved proposals (`work/native-try/proposals.json`) belong to that checkout.
- Drive everything through `roc native-try`. Read headers with your own file tools, but do not import `roc`
  modules in ad-hoc scripts; ask for `--only` or `--context file` instead.

## Loop

1. `roc native-try targets --limit 20` lists files with waiting near-miss targets, most first. Take the top file.
2. `roc native-try evidence FILE --context methods [--only ADDR,ADDR]` prints everything you need
   (`--only` narrows it to the targets you are still working on):
   - the rules;
   - the file excerpt (use `--context file` when the fix may sit in an inlined helper elsewhere in the file);
   - for each target: its address, its `rebuilt_symbol` and `native_score`, the byte-exact mined source, the
     target asm, `standins`, and `current_diff` (target vs current rebuilt instructions).
   - `native_score` is how close the rebuild's own method compiles today. Every target is already 100% mined;
     the job is to close that gap in the real C++.
   - When `current_diff` shows calls where the target has inlined code (or the reverse), the fix usually sits in
     a helper. Rerun with `--context file` to see it.
3. Write SEARCH/REPLACE blocks for FILE into a scratch file (for example `blocks.txt`):

   ```text
   <<<<<<< SEARCH
   exact old text, copied verbatim from the file
   =======
   new text
   >>>>>>> REPLACE
   ```

4. `roc native-try check FILE blocks.txt` applies the blocks, compiles the real file and reports:
   newly exact, lost, still not exact, plus fresh diffs.
   It also saves an `.evidence.json` beside the compiled object with proof metadata,
   gains/losses, full ownership candidates and displayed diffs. The printed evidence
   path avoids extra inspection commands; ambiguous bodies print candidate counts.
   - **Compile error:** fix the blocks.
   - **Lost:** undo what broke the existing exacts.
   - **New exact with no loss:** the edits are minimized to what the proof needs and saved to
     `work/native-try/proposals.json`.
   - Minimization preserves helper definitions still called by retained code. A compile
     that turns a previously defined symbol into an unresolved external cannot remove
     that edit, even when the caller's bytes still match. Submit rechecks this invariant.

   When a genuine declaration and its source must change together, the same command
   accepts a JSON blocks file mapping the primary `.cpp` and its headers to
   `[["SEARCH", "REPLACE"], ...]`. For example,
   `roc native-try check App/tool/PartDragTool.cpp paired.json` compiles the C++
   against those temporary header edits, minimizes both, and restores the original
   header bytes. The saved proposal retains the paired headers and their hashes;
   submit rechecks the pair and stages all files in one server batch.

   Later checks of the same file build on its saved edits.
   To discard one experiment while retaining other files' proofs, use
   `roc native-try reset FILE`. Without FILE, reset clears every saved proposal.
   They must preserve both existing exacts and every previously saved gain.
   After syncing a changed baseline, revalidate saved edits without a blocks file:
   `roc native-try check FILE`. If anchors changed, reconcile the edits before checking again.
   For example, `roc native-try check App/include/util/Events.h blocks.txt --only 0055ae20`
   automatically finds and compiles `Instance.cpp`; it never compiles the header as a standalone TU.
5. Read the diff and make one hypothesis per try. If a check saves a new exact proposal
   with no loss, go immediately to step 6 before trying another unrelated target or file.
   Stop a file after about 3 tries without progress; record its blocker and move on.
6. **Submit after every completed passing fix.** Run `roc integrate sync`, then
   `roc native-try submit --model YOUR_ACTUAL_MODEL`. It rechecks the required gates,
   claims, stages and queues the fix. Do not wait for 10–30 targets, all files, or session end.
   - When the accepted baseline moves, submit recompiles versioned saved edits against
     the latest clean baseline automatically. Changed anchors, lost gains or regressions
     stop submission and retain saved proposals for repair.
   - Submission recompiles saved proposals, then independently builds the combined linked module
     and runs M2/M4a/M5, size/base, global coverage and ownership gates before staging.
     `roc native-try preflight` runs the linked batch proof without claiming or submitting.
     First proof needs a cold baseline build; later proofs reuse content-checked baseline objects.
     Per-file `check` is preliminary: local exact bytes do not prove linked ownership.
   - Claims follow the server's address-to-unit inventory. Skip parked classes and absent units;
     a method named ICharacterSubject may be scheduled under RBX::Humanoid. Keep the existing
     carrier-claim fallback for catalog-less proposals. Reuse valid owned claims.
   - After a gateway error/timeout, use `roc integrate resume`, or rerun native-try submit.
     A hash-checked journal saves the exact request and proof locations before POST. Recovery
     checks server state first and reuses the identical idempotent request; never create a new
     batch blindly. Retain proposals when claims expire or a saved request needs repair.
   - Forbidden invented-type edits fail before trial compilation. Invalid saved proposals are
     retained under `blocked-proposals/`; they do not prevent valid saved files from proceeding.
   - `roc integrate release --claim ID` frees immediately. To park a real blocker for two hours,
     use `roc integrate park --claim ID --reason TEXT`. `release --reason` is rejected.
     `roc integrate unpark --claim ID` (or `--all`) clears your owned parks and frees those classes immediately.
     New park/unpark and claim-inventory APIs require the protocol-3 server update.
   - Source identity is case-insensitive. Keep the accepted registry spelling (`GUI.cpp`, for example).
     A single alias is canonicalized; two differently cased keys in one registry/batch are rejected.
     Never duplicate a file entry to bypass its existing edits or floating-point pragmas.
   - Linked proof receipts record gained/lost/uncovered addresses and baseline/candidate folders.
     Compiler objects have `.command.json` evidence: actual source hash, flags, defines,
     include search order, resolved header hashes and compiler environment.
     Failed revalidation leaves saved proposals intact. Replacing a successful saved check
     archives its previous proposal file under `work/native-try/archive/`.
   - If another worker holds a required class, submit reports the blocked class and retains the proposal for a later retry.
     A partial batch archives only the submitted proposals; the remaining proposals stay saved.

   After submitting:
   - Record the server job ID before starting the next fix. If no job was created, preserve
     the proposal and report the exact blocking gate, claim, baseline or transport error.
     A local exact without a submission is not a completed integration.
   - `native-try submit` keeps the submitted snapshot and restores the local baseline,
     so more discovery can run while the server verifies the batch. Concurrent generator edits are preserved.
   - Record JOB and continue discovery. Use `roc integrate status --id JOB` for a single status check;
     a rejection is a per-batch repair task, not a reason to end the session;
   - `roc integrate sync` after acceptance.

## Fewer commands and smaller evidence

Use `roc native-try targets --min-score 85 --max-score 99` to focus on close native
methods. These scores only rank work; exact instruction/data checks still decide acceptance.
Target listing skips already integrated global addresses and locally saved gains.
Default listing includes class-associated targets without rebuilt symbol metadata;
positive `--min-score` filters those out. Checks also capture unique header helpers
emitted by the real translation unit, even when inventory file labels differ.
Evidence labels global integration separately from TU exactness, so duplicate module
ownership is not mistaken for a new distinct native credit.
Add `--brief` to evidence to omit repeated instructions and assembly while keeping
the native excerpt, mined proof, standins and current diff. Omit it when full assembly is needed.
Evidence includes compiler-selected paths for quoted headers, so helper investigations
read the accepted overlay header actually used rather than an older original copy.
Locally available generated mining proof files are embedded automatically, with
their library reference retained; they remain codegen proofs, not original declarations.
Call hints cover the whole function, including external tail jumps beyond the assembly
preview. Truncated assembly previews report their shown and total instruction counts.
Instruction diffs show relocated operands as `sym`, preserving pointer indirection
and real numeric constants. `push sym` represents an address, rather than literal zero.
Local checks also test whole-binary address ambiguity using the server's pairing rule.
Bodies matching multiple target addresses earn no unique module ownership; `check`
reports these separately and saves only new unambiguous gains.

## Rules

- Derive every change from the target bytes: `current_diff`, `target_asm` and the mined source.
- The mined source is a proof written with placeholder types. Copy its control flow, call order, constants and
  evaluation order into the real classes and methods. `standins` names the real symbol behind each placeholder.
- Never add padding structs, offset views, invented fields, inline asm, raw-offset casts or byte blobs.
- Keep every other method unchanged. Minimization drops unneeded edits, but do not rewrite neighbours.
- Prefer the real cause over a byte-equal workaround:
  - an inline helper or header changed in 2008: edit that header and prove it through its real caller;
  - avoid magic numbers where a named enum or inline call produces the same bytes;
  - do not delete calls unless the bytes prove they are gone.
- Typical real fixes:
  - a removed `RBXASSERT`;
  - a changed condition or evaluation order;
  - an extra `dynamic_cast`;
  - a member-wise copy instead of a conversion;
  - `size() > 0` against `size()`.
- Label submissions with your actual model name. Each unique native credit adds one leaderboard point and increments Native integrated; it does not create a duplicate mining event.

## Example evidence (abridged)

```text
FILE App/v8world/Primitive.cpp
  Contact* Primitive::getFirstContact() { return rbx_static_cast<Contact*>(contacts.first()); }
TARGET 005e7ca0  rebuilt ?getNextRigid@Primitive@RBX@@...  (score 37)
  mined_source: Geometry::next(item) { index = this == item->owner0 ? item->i0 : item->i1; ++index; ... }
  standins: ?resolve@Geometry@@ -> 005e7c10
  current_diff:  target inlines the edge walk (cmp ecx,[eax+0xc] ... jmp X);
                 rebuilt makes two calls (call X / call X)
```

Reading it: in the target, the next-edge lookup is inlined and the call is a tail jump. The rebuilt code calls two
out-of-line helpers. So the fix lives in how `getNextEdge`/`EdgeList::next` are declared or written, which is
inlining-related, not in the body of `getNextRigid`.
