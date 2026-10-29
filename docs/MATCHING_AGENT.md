# Source matching with an agent (OpenCode, Codex, Claude)

Use this as the **working prompt for an OpenCode, Codex, or Claude coding agent**. Optimize for **server-verified exact matches per minute**, not time spent on one address or local similarity score. Work continuously after the user selects a client.

## Server outages: wait up to two hours

If the server goes down, keep the session alive and retry for up to two hours of continuous
outage. Start an elapsed-time deadline at the first connectivity failure. Query `/v1/status`
after 30s, then 60s, then every 2m; cap each request timeout at 30s and each wait at 60s so
stop/pause remain responsive. Resume automatically when a valid server response returns;
reset the outage deadline only on successful contact. Do not ask the user to restart or
reconfirm while waiting. Continue independent local trials where possible, preserving edits,
proofs, claims and submitted job IDs. After recovery, refresh claims/server scores before
replaying an uncertain submission. Never disable TLS verification or duplicate submissions.
Authentication, invalid-request and verification rejections need their actual repair; they
are not server outages. If still unreachable at two hours, save progress, report the last
error and pause network work until the user resumes it.

## Client selection

If the user already selected a client, keep it. Otherwise show current source-mining progress
from `roc work` when available, or fetch the public server's `/v1/status` before setup.
Use the existing configured/supplied server; public default: `https://colinpc.tail2879d0.ts.net`.
If unavailable, read `https://colingsnyder2-ux.github.io/RoConstruct/progress.json` and label
its timestamp. Show matched/functions and mined code coverage with their correct labels;
never substitute integration percentages. Unknown progress is unknown, not zero.
Ask once which client to run and wait. Do not download client binaries, claim targets,
or change clients before selection. Keep the selected client locked for this session.

## Automatic Worker download

Do not ask the user to locate or attach a Worker ZIP. If `roc.py`, `roc/packet.py`, or `docs/MATCHING_AGENT.md` is missing,
`roc work --help` / `roc check-batch --help` is unavailable, or a package marker
reports `matching_workflow_version` below 4, download the current Worker package yourself:

- Manifest: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.json
- Package: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.zip
- Matching guide: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/MATCHING_AGENT.md
- Native integration guide: https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/NATIVE_AGENT.md

Use the chat's current authorized workspace, never an assumed Desktop or owner-specific path.
On Windows the following grouped PowerShell bootstrap downloads and verifies the archive, then extracts
into a new folder without overwriting the user's existing checkout or edits:

```powershell
$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'
$matchingManifest = Invoke-RestMethod ('https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.json?t=' + [guid]::NewGuid().ToString('N'))
if ($matchingManifest.workflow_version -lt 9 -or
    $matchingManifest.matching_workflow_version -lt 4 -or
    $matchingManifest.url -ne 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/data/native-worker.zip' -or
    $matchingManifest.sha256 -notmatch '^[0-9a-fA-F]{64}$') { throw 'Invalid Worker manifest' }
$matchingFolder = Join-Path (Get-Location) ('RoConstruct-Matching-' + [guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $matchingFolder -ErrorAction Stop | Out-Null
$matchingArchive = Join-Path $matchingFolder 'worker.zip'
Invoke-WebRequest -UseBasicParsing -Uri ($matchingManifest.url + '?sha256=' + $matchingManifest.sha256) -OutFile $matchingArchive
if ((Get-FileHash -LiteralPath $matchingArchive -Algorithm SHA256).Hash -ne $matchingManifest.sha256) {
    throw 'Worker ZIP hash mismatch'
}
Expand-Archive -LiteralPath $matchingArchive -DestinationPath $matchingFolder
Set-Location -LiteralPath $matchingFolder
$env:ROC_NONINTERACTIVE = '1'
Write-Output ('Matching checkout: ' + $matchingFolder)
```

On Linux use the same HTTPS manifest/package, verify SHA-256, and extract into a fresh authorized folder.
Capture the printed absolute checkout path and use it as the explicit working directory for every later
tool call. `Set-Location` and process environment changes do not persist across separate terminal calls.
Set `ROC_NONINTERACTIVE=1` again in the grouped setup call if needed.
Read the extracted `AGENTS.md` and `CLAUDE.md`, then execute setup below. Use an existing working server
configuration when supplied, otherwise use the manifest's `server` URL. Never copy another contributor's
credentials. Ask only for missing contributor identity. Mining uses the configured server authentication; ask for a missing server password only when required. Never copy another contributor's credentials.
If downloads fail, retry and report the actual URL/error; never invent a successful install.

## Dependency setup (execute after selection)

Reuse an existing working checkout or obtain the verified Worker above. Discover paths
on this PC. Install missing dependencies through existing launchers; do not leave the user
with a download checklist when their task authorizes setup. A saved guide grants no OS,
filesystem, network, account or administrator permission beyond the user's actual request.

On Windows, run `install.cmd` first if Python 3.12 or required Python packages are missing.
The launcher can select a working Python 3.12 directly when `py -3.12` registration is broken.
On Linux, use `install.sh`; install missing Wine and cabextract/7z through the platform's
supported package manager when authorized. Report actual permission or download failures.
Set `ROC_NONINTERACTIVE=1` for unattended installer invocations. Group setup commands
sequentially, stop on the first failure, retry a failed download once, and reuse successful
steps. Do not start another server or touch another contributor's installation.

After configuring the user's contributor name and reachable server using
`roc config --user NAME --server URL` when missing, run:

```text
roc install --yes --client CLIENT
roc client-fetch CLIENT
roc analyze CLIENT
roc pull CLIENT
roc doctor
```

Replace CLIENT with the selected registered client. Skip binary downloads when its verified
client is already installed; skip analysis when `work/CLIENT/functions.jsonl` covers that
binary. `pull` preserves local edits and fetches shared sources/generated units. Configure
server credentials through ROC's local configuration only when required; never print secrets.
Ask only for missing contributor identity, required credentials, or an actual approval block.

Fetch a named missing vendor recipe with `roc lib-fetch RECIPE`; use `roc lib-info RECIPE`
to inspect its requirements first. For a required indexed bundle use `roc libs-bundle fetch NAME`.
Use the recipe/manifest names reported by ROC, not guesses or another PC's absolute paths.
Install only dependencies used by the selected target. Native rebuild SDK/MFC/source setup
belongs in [NATIVE_AGENT.md](NATIVE_AGENT.md); ordinary matching does not require every
native dependency. Remill is optional: use an installed/configured copy when relevant;
its absence must not block evidence-first C++ matching.

If using a signed-in CLI, choose its actual model and configure/sign in through ROC's
provider setup or that CLI. API and local-model backends remain supported. Respect the
user's worker count, provider limits and budget. Never guess the identity of another AI.

## Non-negotiable rules

- Start from the repository containing `roc.py` and its launcher. Discover its root from the current directory or parents; **never assume any contributor's username, drive letter, absolute checkout path, compiler location, or Remill location**.
- Use the repository launcher: **Windows:** `.\roc.cmd`; **Linux:** `./roc.sh`. Commands below use `roc` as shorthand for the appropriate launcher **from the repository root**. If the launcher differs, inspect `roc --help`; never invent a command.
- Read `CLAUDE.md` and relevant sections of `docs/AGENT_GUIDE.md` once. Inspect other files only when needed. Do not dump large files into a small model's context.
- Match ordinary C++ using the **target client's actual MSVC compiler and flags**. No inline assembly, `_emit`, byte-patched code, fabricated layout/ABI facts, or speculative rewrites presented as verified.
- **Exact = server-confirmed 100% for code AND referenced data.** Local percentages and LLVM verification are evidence, not successful submissions.
- Never overwrite a better candidate. Use scratch files for hypotheses. Never `git push`, modify unrelated files, or print secrets.
- The **mining agent** edits only `src/<CLIENT>/<ADDR>.cpp` (when promoting a proven improvement) and local `work/` logs/scratch. Do not modify `roc/`, `tools/`, `clients/`, or shared agent instructions during mining.
- Other agents may work concurrently. Respect server claims, recheck stale status, and reload files changed by another agent.
- **No blocking bulk runs:** do not run `roc mass`, `roc xcopy`, all-client analyze/rebuild, or large research campaigns. `roc pull CLIENT` once per session is allowed. A bounded single-address repair/check is allowed.

## Start of each session

1. Complete client selection and dependency setup above. Reuse a prior explicit selection; do not ask again.
2. Reuse the setup pull (do not repeat it), then read the relevant entries in `work/hard-functions.md` and existing attempt records. Missing optional logs are not errors.
3. Keep the selected client for the session. Do not ask about every subsequent function. **Never work on, claim, or submit for any client other than the one the user selected.** If the user selected 2008-06, every `roc work`, `roc check`, `roc submit`, and scratch path uses that client only.
4. Run `roc work CLIENT` to claim one unmatched server target. The quick profile ranks available candidates using current evidence; treat its result as a candidate, not an order to spend a long time on it.

## Fast feasibility gate — before editing anything

For `CLIENT`, `ADDR` returned by `roc work`:

1. **Read the packet first:** `roc work` writes `work/CLIENT/packets/ADDR.txt`. It contains the real residue hunks, the mismatch class, deduped failed hypotheses, exact siblings, and STALE-SOURCE / OUT-OF-EXTENT warnings. Act on any warning before anything else. Also look in `work/CLIENT/scratch/ADDR/`: earlier agents' variants are there, so don't re-test them. Then read the existing `src/CLIENT/ADDR.cpp`, previous attempts, server score, size, unit, and `Twin` hint. If already exact, already solved, or being changed by another agent, stop on that target.
2. Run **at most the relevant commands** (not all every time):

   ```text
   roc similar CLIENT ADDR --limit 3
   roc check CLIENT ADDR --context 3
   roc classify CLIENT ADDR src/CLIENT/ADDR.cpp
   ```

   `roc similar` needs local analysis and pulled sources. Use the `Twin` printed by `roc work` first when available. Skip `classify` if there is no compilable source yet.
   - **Stale local source:** if `roc check` scores lower than the server score `roc work` printed, your local `src/CLIENT/ADDR.cpp` is not the server's best (`roc pull` keeps local files). Do not start from it. Use the server-best source from the packet as a scratch baseline. Preserve unsubmitted local edits; never force-pull the whole client to replace one stale candidate.
   - **Missing generated unit:** if compiling fails because the `// roc-lib:` unit is absent, run `roc pull CLIENT` once. If the unit is still missing, park with reason `unit missing: NAME`.
   - **Extent check:** an external tail jump alone does not prove a bad extent. Check SEH scope tables, catch ownership, jump-table entries and `BOUNDS:` proofs. When those establish a truncated owner, record `BOUNDS LEAD`, preserve the proof and park that target. Only the server host applies reviewed bounds and re-analyzes/hot-reseeds. Do not invent a local extent to claim a match.

3. Pick a lane by **evidence, not percentage**:
   - **REUSE:** Verified twin/same-shape source, authentic library/source template, or one proven family substitution. Cheapest priority.
   - **PATCH:** Existing compilable candidate with a clearly identified data-only, immediate, import, layout, or single-hunk mismatch. Next priority.
   - **STRUCTURE:** Multi-block C++ candidate where a specific branch, return, type, or argument is uncertain. Only proceed if evidence can narrow the change.
   - **RESEARCH/PARK:** No usable source, large function with major structural divergence, missing type/ABI facts, or an exhausted register-allocation mismatch. Try one cheap reuse/twin or first-diff check before parking; park only if no concrete lead. **Do not ask a weak model to regenerate a large function blindly.**
4. For quick/free models prefer strong-evidence targets and small localized edits. A 98% function with an opaque ABI problem can be harder than a 70% function with a verified twin. A big function is acceptable **only** when the remaining mismatch is demonstrably small.

## One-target repair loop (budgeted)

### A. Use free deterministic evidence first

- **REUSE:** Test the exact twin's source (minus address-specific assembly-comment headers) as a scratch candidate. Adapt only binary-proven literals/types if needed; don't modify the stored donor.
- **PATCH:** Identify the **first real mismatch** in `roc check --context 3`. `-` is target, `+` is candidate. Ignore cosmetic symbol-name differences; inspect the actual compile result. Check data-only errors before code changes.
- If there is a reasonable partial source at 80%+, a **single-address**, bounded deterministic pass is available:

  ```text
  roc repair CLIENT --addr ADDR --min-score 80 --dry-run
  ```

  Use it only when likely relevant; it may run multiple compiles. It must not become a default full-client pass. If `research/log.jsonl` already records `roc repair CLIENT ADDR | ... tried 0 variants` for this address, **do not run it again**: it has no mutation that applies.
- Use prior `work/hard-functions.md` attempts to avoid retrying exhausted ideas. Consult the near-miss cheat sheet below **only for the symptom actually visible**.

### B. Generate small independent candidates

- Generate **2–4 scratch variants**, **one isolated hypothesis per file**, stored beneath `work/CLIENT/scratch/ADDR/`. Keep a copy of the best source untouched.
- Favor direct source edits (constants, imports, control-flow spelling, local expression order) over a whole-function rewrite. For a large source, ask the model for a **minimal patch or changed function fragment**, not 300 lines of regenerated C++.
- Test candidates **in one batch** with the existing tool:

  ```text
  roc check-batch CLIENT ADDR work/CLIENT/scratch/ADDR/a/ADDR.cpp work/CLIENT/scratch/ADDR/b/ADDR.cpp --context 3 --summary --model ACTUAL_MODEL_ID
  ```

- Retain only the best compilable result; evaluate exact score first and fewer *meaningful* mismatch hunks as a secondary tie-breaker. Never replace a better existing source on the strength of a cosmetic diff.
- After a useful gain, make **one more targeted batch** based on the new residue. Don't repeat the same ineffective variants.

### C. Escalate only with a reason

For a structural mismatch that cannot be decided from asm/source:

```text
roc rtti CLIENT ADDR
roc ref CLIENT ADDR
roc lift CLIENT ADDR
```

- Use RTTI when a dynamic type/template argument is uncertain, reference-source evidence when a library/function identity is uncertain, and Remill **only** when control flow, flags, arithmetic, or memory behavior is the blocker.
- Remill produces instruction-level LLVM IR evidence, **not the original C++**. LLVM `opt -passes=verify` checks IR well-formedness; it does **not** prove a reconstructed C++ function or recovered CFG is correct. Prioritize target assembly and server verification.
- Give weak models a **compact evidence packet**: function signature facts, relevant CFG blocks, 1–3 semantic observations, current source excerpt, and the first mismatch. **Never dump full LLVM IR or unrelated disassembly** into the prompt.
- If Remill is not configured on this PC, skip it cleanly; do not install or assume machine-specific paths.
- If a stronger model is configured, hand off a small evidence packet and the exact stuck hypothesis; don't pay it to rediscover everything. Without one, park the target.

### D. Park condition (per target only — never the session)

Default budget per target:

- **At most 2 batches** (about **4–8 total compiler-tested candidates**).
- **At most 2 focused model requests** for a weak/free model.
- Park immediately after a repeated failure with the same source/evidence hash, absent new evidence.
- If no gain, or the available evidence cannot establish a valid C++ structure, **PARK this target only** and work on a different one. "Park" releases the claim and moves on; it is never a reason to pause or stop mining. If a new, concrete source lead exists, log it as a research handoff instead of hallucinating code.
- Do not burn time on a large zero-score function unless a genuine source/library match has been found.
- **Context budget (free/weak models):** keep each target's evidence under ~20k tokens. Never paste a whole `--context 3` diff of a function over ~400 bytes; paste the first 2 hunks. Start a fresh session after about 25 targets or 3M input tokens. Long sessions on free models failed after 1–9M tokens with no exacts.

These are ceilings, not minimums. Do not use all attempts if the diagnosis already says the problem is underdetermined. **Park is a per-target action; the session continues immediately with the next claim.**

## Submit, record, and continue

- Test the winner with `roc check CLIENT ADDR --file PATH --context 3` when needed, then submit without replacing the source first:

  ```text
  roc submit CLIENT ADDR --file PATH --model ACTUAL_MODEL_ID
  ```

  PATH must end in `ADDR.cpp`, including for scratch submissions. Supply the actual AI model ID
  for AI-written candidates; never use `function`, a lease mode, or `roc repair` as an AI model.
  Use `human` for hand-written work. If model identity is unavailable, state that explicitly rather
  than inventing it. The server determines the authoritative score. Player Mining shows the
  contributor, verified score gain/points and submitted model. Native integration earns separate
  native counts; each new distinct native integration adds one leaderboard point. Resubmitting an already-exact match earns no duplicate mining score gain.
- If the server accepts an improvement, preserve the verified source according to the project's normal `src/`/pull workflow. Never overwrite a newer or better source.
- Append one concise line to `work/hard-functions.md`:

  ```text
  CLIENT ADDR | before -> after | EXACT / IMPROVED / PARKED | evidence; tried hypotheses; next useful lead
  ```

- Record source-hash, exact hypothesis, compiler error/result, and server receipt in the existing agent attempt journal when supported. Use `roc research note` for a **new reusable successful fix**, not for every ordinary trial.
- Print one short progress line, then move to the next function automatically.
- **Claim management:** `roc work CLIENT` creates a soft server claim. Use `roc work CLIENT --skip ADDR --reason "..."` (or `roc release CLIENT ADDR`) to release a parked claim immediately after parking it. **Do not stop after 2–3 parked claims, do not stop after 20, do not stop at all** — keep claiming and mining on the same client. If the queue is exhausted (no unmatched targets returned), try `roc work CLIENT --min-score 0`, then `roc work CLIENT --include-cooling` (aliases: `--include-parked`, `--revisit`, `--revisit-parked`, `--force`) to revisit parked targets. A parked target is only truly blocked if its evidence is unchanged; edit the source or change the hypothesis first, then revisit. Only consider a client exhausted after BOTH `roc work CLIENT --min-score 0` and `roc work CLIENT --include-cooling` return nothing. Even then, do NOT work on another client on your own: report exhaustion for the selected client, show the remaining clients from `roc work`, and **ask the user which client to switch to and wait for their answer** before touching any other client.

## Tiny-model prompt (provide only the selected evidence)

```text
You are repairing C++ for byte-exact matching with the specified historical MSVC compiler.
Goal: improve this ONE mismatch without changing unrelated behavior or declarations.
No inline asm, emitted bytes, fake offsets, unsupported C++ features, or full rewrites.

Client/compiler: <facts>
Target/score/size: <facts>
Known exact donor or source reference, if any: <small relevant excerpt>
Current C++: <relevant excerpt, not the entire corpus>
First REAL target-vs-candidate diff: <short excerpt>
CFG/Remill facts, only if needed: <max 3 grounded facts>
Already tried: <brief list of failed hypotheses>

Produce up to THREE independent, minimal C++ patch alternatives (one isolated change per alternative).
For each, explain in ONE sentence which target instruction difference it should fix.
Do not combine alternatives into one patch. If evidence is insufficient, output BLOCKED and the missing fact.
```

## Near-miss cheat sheet (only read the matching line)

| Symptom | Targeted idea |
| --- | --- |
| `call dword ptr [sym]` vs direct `call sym` | Verify DLL import declaration / `__declspec(dllimport)` |
| Wrong constant, size, member displacement | Re-read literal, object size, and padding from the binary; change only that value |
| EH state differs around imported destructor | Check imported destructor declaration / exception specification |
| Same instructions, different register allocation | Try one named local, expression inlining, or local statement order; park if several attempts fail |
| `lea` vs `add` on `this` subobject | Check evidence of base-class subobject conversion, do not invent inheritance |
| Bool lowering mismatch | Compare explicit conditional returns with expression return |
| x87 compare/order mismatch | Check operand order, casts, and already-evidenced FP compiler flags |
| `lock xadd` / refcount mismatch | Check exact intrinsic and refcount ownership layout |
| Code appears exact, referenced data wrong | Fix only proven string/data bytes, then server-verify |
| Large wrong CFG / ABI | Require a real source/template/decompilation lead; otherwise park for stronger analysis |
| `push sym` (target) vs `push 0` (yours) in the EH prologue | Inspect relocation and referenced-data evidence. Renamed symbols may be cosmetic; an unrelocated literal zero is not automatically equivalent to an address |
| `je/jmp sym` leaving the target, or extra catch/`__finally` code | Possible extent lead; first prove ownership from SEH/catch/jump-table evidence. External tail calls can be valid |
| Only `[esp+N]` slot offsets differ (by 4/8), same instructions | Frame size or a local packed into a dead parameter slot. Check the target's `sub esp, N`; try one local reorder/scope change. If the slot is a dead *incoming parameter* home, park (known blocker) |
| `mov edi, edi` first + `pop ecx` arg cleanup | SP1 hotpatch thunk: `// roc-cl: 30729` + `// roc-flags: /hotpatch /O1 /GS- /EHsc /MD` |
| EH-spill vs `mov eax, esp` order around a by-value temp | Copy the caller-guard shape: two calls sharing one by-value temp (see log "spill-order fix via guard-in-caller") |

### Previously reported 2008-06 blocker families

These examples come from the supplied matching workflow. Check current packets and
receipt-backed attempt history before retrying or parking; do not treat an address
or symptom as a permanent blacklist. Other clients require their own evidence.

- Callee-saved register role swap (`esi`/`edi` swapped, same instructions): e.g. 00422b40.
- Epilogue `pop esi` scheduled before/after `mov fs:[0], ecx`: e.g. 004b44c0.
- `EnumPropDescriptor::read` out-int packed into the dead `element` arg slot (`[esp+0x44]` vs `0x48`): 00448800, 00565970.
- Single x87 `fsubrp`/`fld` scheduling shift with everything else equal: e.g. 006064a0, 00613080.
- VS2003-style `push sym` SEH frame stubs with out-of-line funclets: 00428310, 005f38e0, 00421530 (`/hotpatch` does not help).

## Success metric

Count **server-verified exacts per hour** and **verified score gains per compiler/LLM attempt**, grouped by difficulty band. Track tokens, wall-clock time, false starts, and parked functions. Avoid optimizing only for local percent changes.

Continue with the chosen client until interrupted. Release parked claims immediately with `roc work CLIENT --skip ADDR --reason "..."` so the claim budget stays available. If `roc work CLIENT` returns no new targets, try `roc work CLIENT --min-score 0` or investigate previously parked addresses.

## Continue within the selected scope

Continue automatically after each verified submission or parked target, within the user's
requested duration, budget and authorization. A parked target is not a stopped session.
Respect the user's stop/pause request immediately at a safe boundary. Keep claims renewed
through the supported worker flow; release abandoned manual claims.

If normal and expanded target selection are exhausted, report the actual blocker or completion,
show current remaining clients, and ask before switching. Do not spin on unchanged parked
hypotheses, bypass another worker's claim, fabricate progress, or declare unmatched targets solved.
