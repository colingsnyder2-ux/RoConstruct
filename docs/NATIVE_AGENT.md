# Native integration with an agent (Codex, Claude)

Paste this file into a Codex or Claude Code session opened in a RoConstruct checkout. It runs the same loop as
the DeepSeek native pass (`roc research run native-model-2008`). You write the edits; the tools compile the real
2008-06 file, check exact bytes and referenced data, minimize your edits, and submit each passing fix immediately.

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

After client selection, before setup, claims or native trials in a new or resumed
session, fetch the current Worker manifest below with cache busting. Compare its
`workflow_version` and package `sha256` with the installed package identity.
Having the files or meeting this guide's minimum version is not enough: a package
can be republished with fixes without changing that minimum. Record the checked
manifest version/hash and installed package identity in the session checkpoint.

If the Worker is outdated or its identity cannot be verified, download and
SHA-256-check the latest package using the bootstrap below, into a fresh private
folder. Preserve the old checkout, local edits, saved proofs, claims and pending
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
reports `native_workflow_version` below 3, download the current Worker package yourself:

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
if ($nativeManifest.workflow_version -lt 3 -or
    $nativeManifest.url -ne 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.zip' -or
    $nativeManifest.sha256 -notmatch '^[0-9a-fA-F]{64}$') { throw 'Invalid Worker manifest' }
$nativeFolder = Join-Path (Get-Location) ('RoConstruct-Native-' + [guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $nativeFolder -ErrorAction Stop | Out-Null
$nativeArchive = Join-Path $nativeFolder 'worker.zip'
Invoke-WebRequest -UseBasicParsing -Uri ($nativeManifest.url + '?sha256=' + $nativeManifest.sha256) -OutFile $nativeArchive
if ((Get-FileHash -LiteralPath $nativeArchive -Algorithm SHA256).Hash -ne $nativeManifest.sha256) {
    throw 'Worker ZIP hash mismatch'
}
Expand-Archive -LiteralPath $nativeArchive -DestinationPath $nativeFolder
Set-Location -LiteralPath $nativeFolder
$env:ROC_NONINTERACTIVE = '1'
Write-Output ('Native checkout: ' + $nativeFolder)
```

On Linux use the same HTTPS manifest/package, verify SHA-256, and extract into a fresh authorized folder.
Capture the printed absolute checkout path and use it as the explicit working directory for every later
tool call. `Set-Location` and process environment changes do not persist across separate terminal calls.
Set `ROC_NONINTERACTIVE=1` again in the grouped setup call if needed.
Read the extracted `AGENTS.md` and `CLAUDE.md`, then execute setup below. Use an existing working server
configuration when supplied, otherwise use the manifest's `server` URL. Never copy another contributor's
credentials. Ask only for missing contributor identity. Native integration is public; no invitation required.
If downloads fail, retry and report the actual URL/error; never invent a successful install.

## Goal

Make byte-exact mined 2008 functions come out of the real rbxgs C++ (native integration). A target is a function
that is already 100% mined and whose method already exists in the rebuild but compiles differently. Credit comes
only from the server's independent linked rebuild.

A source/library tag does not certify authentic headers or original variable names.
Generated mining proofs can contain reconstructed declarations. Native work must use
the real classes and evidenced layouts, then pass the independent integration gates.

## Setup (execute before mining)

Install missing dependencies yourself; downloads are authorized. Do not stop at a setup plan or ask the
user to download dependencies manually. Reuse installed files. Group setup commands into one terminal
invocation, run sequentially, and stop on the first failure. Retry a failed download before reporting a blocker.
Use existing `roc` commands; do not import project modules from ad-hoc scripts.

Use a current Worker package or checkout with `roc native-try --help`. The Worker package must include
`native_try`, `native_sweep`, `standins`, `rebuild_install`, this document and `research/libs-bundle.json`.
If a public clone lacks `roc/native_try.py`, use Automatic Worker download above rather than cloning
that same public revision again. A pasted copy of this guide is sufficient to obtain the package.
Extract into a fresh folder inside this chat's authorized workspace; keep older checkouts and edits intact.
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
if not already configured. Use the human-provided username consistently for every claim and submission;
for Colin's authorized agent runs, configure `roc config --user colin`. Record that identity with each job.
A source author or model name does not replace the submitting contributor's username. Use the supplied server URL, not the owner's `localhost`. No native invitation,
`ROC_NATIVE_TOKEN` or owner approval is required. Ask only for missing contributor identity.
Leave `ROC_NATIVE_EVIDENCE_ROOT` unset on
another PC; it is an optional same-machine testing override.

On Windows, run these existing commands through `.\roc.cmd` (Linux: `./roc.sh`), in this order:

```text
roc install --yes --client 2008-06
roc client-fetch 2008-06
roc analyze 2008-06
roc rebuild 2008-06 install
roc pull 2008-06
roc lib-fetch rbxgs rbxgs-net rbxgs-appdraw rbxgs-render rbxgs-view openrbx-client
roc libs-bundle fetch mfc-9.0-rtm
roc integrate sync
roc rebuild 2008-06 doctor
roc native-try targets --limit 20
```

Skip `analyze` when `work/2008-06/functions.jsonl` already covers the current verified client. `install`
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
5. Read the diff and make one hypothesis per try. When a check saves a new exact proposal
   with no loss, proceed immediately to step 6 before trying another unrelated target or file.
   Stop a file after about 3 tries without progress; record its blocker and move on.
6. **Submit after every completed passing fix.** Run `roc integrate sync`, then
   `roc native-try submit --model YOUR_ACTUAL_MODEL`. It claims, rechecks, stages and queues the fix.
   Do not wait for 10–30 targets, all files in a sweep, or the end of the session.
   Include inseparable supporting source/header edits in the same coherent submission;
   keep unrelated unfinished experiments separate.
   - When the accepted baseline moves, submit recompiles versioned saved edits against
     the latest clean baseline automatically. Changed anchors, lost gains or regressions
     stop submission and retain saved proposals for repair.
   - Submission recompiles saved proposals and verifies their gains and preserved exacts before claiming or staging.
   - If another worker holds a required class, submit reports the blocked class and retains the proposal for a later retry.
     A partial batch archives only the submitted proposals; the remaining proposals stay saved.

   After submitting:
   - Record the server job ID before starting the next fix. If no job was created, record
     the exact blocking check, claim conflict, baseline issue or transport error and preserve
     the proposal. A local exact with no submission is not a completed integration.
   - `native-try submit` keeps the submitted snapshot and restores the local baseline,
     so more discovery can run while the server verifies the batch. Concurrent generator edits are preserved.
   - `roc integrate watch --id JOB` to follow it;
     rejection or a missing job exits with failure, so dependent shell steps stop;
   - `roc integrate sync` after acceptance.
   - Report accepted native credit only from the server receipt. Watch an existing pending
     job rather than submitting duplicates. Do not restart a busy server to flush local work.
   - Accepted jobs with real gains trigger the server's integration webhook automatically.
     Include every accepted gain in the server submission; do not stop after a local compile,
     module proof, commit or push. Those are not server acceptance receipts.
   - Record webhook delivery/message ID when available. If delivery cannot be confirmed,
     mark it pending or unverified and report the actual reporting problem separately from
     native acceptance. Never claim webhook delivery from an attempted request alone.
     Avoid posting a duplicate manual digest when the server already delivered it.

This instruction changes the agent's workflow; it does not make `native-try check`
submit automatically or change an already running agent that has not read this file.

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
- Label submissions with your actual model name. Native credit is separate from mining points.

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
