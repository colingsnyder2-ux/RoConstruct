# Historical native Worker changes

Historical reference only. Current contributor workflow: `NATIVE_AGENT.md`.
Old submission commands here describe earlier releases, not current draft sharing.

## Integration-aware recovery leases (Worker/Server 49)

Recovery catalog entries become unavailable while their addresses are reserved
by an active integration claim or submitted verification job. The claim endpoint
rechecks this under a database write transaction, so a stale catalog cannot grant
duplicate recovery work. Submitted work stays fenced after lease expiry; released
or expired unsubmitted claims stop blocking. This server change requires a host
restart after pending verification finishes.

## Short shared-header cache paths (Worker 48)

Historical MSVC can silently skip headers with paths longer than 259 characters.
When a recovery snapshot would exceed this limit, shared probe/canonical headers
use a short immutable cache under `%LOCALAPPDATA%/RoConstruct/nc`, keyed by the
full header-content revision. Modified cache contents are rejected. A header
that still cannot fit fails explicitly instead of falling back to raw SDK declarations.

## Original virtual dispatch clues (Worker 47)

Native task packets include bounded `virtual_dispatch` entries from the original
RTTI vtable index, with class names, table addresses and slot indices. A table can
inherit a method; these entries do not establish the declaring class or layout.
Compare them with genuine declarations before trusting a mined name. Report an
ownership/layout blocker when the evidence conflicts; do not invent fields.

## Smaller recovery packets (Worker 46)

Native agents start with `task.json`: complete target assembly, genuine reference
source, assigned declarations and baseline diff. Duplicate include paths are
consolidated. Mined source analogs and stand-ins remain in `task-full.json`,
available through `full_evidence_file` when a specific hypothesis needs them.
These are untrusted reference data; stand-ins do not establish native layouts.
The initial packet estimate uses the compact packet. Measured multi-turn usage
still settles after the agent exits; token limits remain soft for signed-in CLI.

## Accepted preflight reuse and clear status (Worker 45)

After the server accepts an overlay, a matching local candidate can become the
next preflight baseline. Reuse requires the same verifier/compiler implementation,
reproduced accepted overlay, full input fingerprint and passing gate receipt.
The next candidate still builds and runs all gates. Changed inputs require a
fresh baseline. Diagnostic last-success reports are outputs, not cache inputs.
Upgrading verifier code also requires a fresh baseline.

GUI/console distinguish blocked attempts, no local gain and exact proofs awaiting
verification. A failed trial is never reported as awaiting verification.

## Code and data ownership (Worker 44)

Discovery, linked ownership counts and status use the same whole-binary pairing:
exact relocation-masked code plus all resolvable referenced data. Wrong data
rejects a match even when its code was unique. Missing data retains ambiguity.
Other modules can cover a regression only through current object checks and a
passing build/smoke result, rather than an old ownership report alone.

A tooling refresh can reclassify already compiled functions. Fresh baseline and
candidate builds use the same rule; inventory changes alone earn no submission
credit. Runtime, ABI, referenced-call and P5/P6 requirements remain unchanged.

## Durable attempts and visible blockers (Worker 43)

Replaced local attempts remain in the claims database's `task_history` table.
Lease refusals retain saved private work for later resumption, including repeated
refusals from other PCs. Owner fencing and fresh compiler checks still apply.

Host-maintained `work/native-recovery/blockers.json` reports layout, linkage,
codegen or evidence blockers in GUI/console logs. Reports do not create tasks,
invalidate source leases, permit layout guesses or earn credit. Evidence paths
refer to host artifacts; blocker text is reference data, never agent instructions.

## Budget refusal handling (Worker 42)

Native recovery stops new assignments when a request/token reservation is refused,
while already admitted agents finish and queued host checks drain. It does not
retry the same refused assignment indefinitely. Restart with adjusted limits to
admit more work.

CLI input reservations estimate tokens from evidence and instructions; measured
multi-turn usage replaces the estimate after the agent exits. Token caps are soft
for an individual CLI invocation. Use launch, time and probe caps to bound trials.

## Explicit overload recovery (Worker 41)

Host task mappings can select an existing out-of-line overload using its full
source signature, for example `Name::lookup(const std::string& sName)`, plus
`expected_symbol` containing its exact MSVC decorated symbol. The compiler must
emit that symbol and match the assigned original address, including data checks.
Ambiguous names remain blocked. Header overloads require an owner-established
consuming translation unit; constructor overloads remain unsupported.

Each lease binds the signature and symbol. Older Workers cannot claim these
tasks. Recovery changes only the selected body, preserves sibling overloads,
recompiles before merging, and retains normal submission and independent gates.
Use console `roc integrator` for testing; desktop automation is unnecessary.

## Native source recovery with real Codex agents (Worker 32)

Open `roc gui`, choose **Workers → Integrator**, select your Codex model and
launch cap, then **Start native recovery**. This panel exposes native C++ recovery
only. It defaults to ten worker slots, two compiler slots and at most ten agent
launches. Worker count, time/probe limits and independent submissions stay adjustable.

Equivalent CLI (worker count defaults to ten):

```text
roc integrator --generation agent --model codex:gpt-6.1-terra --workers 10 --compile-workers 2 --agent-minutes 4 --agent-checks 6 --max-cloud-requests 10 --allow-cloud
```

Real Codex subprocesses read original assembly/RTTI and genuine headers, edit private
C++, run `python check.py`, and iterate from compiler errors and target diffs. Each
agent has one method assignment and a private snapshot including uncommitted native
work. Installed clients, compilers and original source inputs are reused. Recovery
setup defers full dependency builds until submission needs them. Compiler concurrency
is separate from agent concurrency. Only signed-in `codex:` models support this mode;
API/local models remain available in method-generation mode.

Proven method bodies merge into the launching checkout's
`rebuild/2008-06/native-classes`, `native-headers`, or `native-world`, according to the
assignment. Another agent's changed target body causes a conflict, never a stale
whole-file replacement. Unrelated changes are preserved. Current shared source and
candidate are recompiled against freshly copied current headers; existing matches
must survive. Source/header changes during recheck abort that write. Backups, hashes,
source candidates and receipts are retained. No commit, player swap or credit is
implied by merge-back. A different editor can still save its own stale copy later;
recovery controllers cannot govern unrelated editors' later writes.

Automatic discovery uses unambiguous existing out-of-line C++ methods, original
address annotations and compiler-probe nominations. Missing evidence is a blocker,
not permission to guess a layout. Header bodies and specific assignments can use
`--agent-tasks PATH` (GUI: **Native task manifest**), a JSON list:

```json
[
  {
    "file": "rebuild/2008-06/native-classes/CRobloxDoc.cpp",
    "method": "CRobloxDoc::SetModifiedFlag",
    "addr": "0044fad0"
  }
]
```

Header tasks require `translation_unit`, naming an existing consuming native `.cpp`
or `rebuild/2008-06/tests/Native*.cpp` probe. They support unambiguous qualified
method definitions; in-class inline definitions, fields, signatures and layout changes
remain owner work. Existing C++ sources under `native-world` use the same mechanism;
a manifest alone is not a recoverable C++ body. An explicit `add_method: true` task
may append one missing qualified definition to an existing source; its genuine header
declaration must already exist and compile. It cannot add fields or declarations.

Worker 24 collaborates across PCs using the **same server URL**. Server method
leases last 120 seconds and renew every 20 seconds, including baseline compilation.
An expired/replaced lease cannot upload, renew or release another worker's method.
Local SQLite still protects multiple sessions on one PC. An older server prints a
local-only warning; update/restart the host before relying on cross-PC coordination.

The server publishes its current native source/header catalog, so classes added by
owners become available without downloading another compiler or waiting for a new
Worker ZIP. Agents compile private server snapshots. New host files can be created
locally; existing local files are never replaced wholesale. After host verification, a proven body uses the
same guarded merge against current local headers. Header tasks edit existing public
inline/out-of-line method bodies only; private force-emission probes use genuine
member declarations. Fields, bases, signatures and layouts remain owner-only.

Candidates upload into the host's file inbox and independent native recheck queue.
The host preserves concurrent body/header edits, rejects wrong known imports, and
retains unresolved imported callees for owner review. Host-verified source merges
post a batched **report-only, zero-credit** milestone to the configured mining
webhook. Already-exact, failed and conflicting tasks do not post gain reports.
The Integrator resumes supported canonical mappings through existing linked
preflight/submission/acceptance; keep it running to finish that stage. Missing
class linkage stays pending. No contributor text is queued into a coding chat.

The agent preset selects Terra when no explicit Codex model was chosen and caps
the initial batch at ten agent launches; explicit model choices are preserved.
Reaching the AI budget stops new agents while queued host checks and canonical
submissions finish without additional model calls.
Snapshots/proofs use a persistent short path printed at startup (Windows:
`%LOCALAPPDATA%/RoConstruct/nr/<session-hash>`), avoiding historical MSVC path limits.
Restarting the same GUI session retains private work; expired claims can be recovered.
Pause holds new tasks. Stop kills active agent process trees; partial source stays
saved. No stronger-model escalation occurs automatically.

**Submissions stay independently gated.** A native method with one supported
accepted-module mapping is recompiled in that canonical context, then joins a submission batch for its class and model. That batch follows the
existing claims, linked preflight and server verifier. Missing mapping or linkage
leaves an explicit pending candidate. Uncheck **Submit linkable recoveries** or use
`--no-agent-submit` for local-only recovery; drafts persist for later submission.
The GUI distinguishes local recovery, merged changes, conflicts, submitted jobs,
accepted jobs and pending work. Only server receipts establish credit. P5/P6 are
still required for an actual active class swap; the shared-header workflow remains
provisional until that first swap lands.

The local GUI prioritizes published classes with more known integration mappings,
then fills free slots with other classes. New sessions default to five AI workers;
compiler concurrency and model budgets remain independently adjustable. Classes
listed under **Excluded classes** receive no new assignments. Existing submitted
work still finishes. The default excludes CRobloxView, CMainFrame and HUMAN while
they are assigned elsewhere; edit the list when ownership changes.

If linked preflight records uncovered losses, multi-method batches are split in
half and saved for recheck; singleton failures remain blocked with their receipt.
The controller waits for an outstanding integration job before another preflight,
so a later batch uses the accepted baseline. Owner-published helper mappings can
append a proven method to an existing canonical unit, using exact anchors and the
normal independent gates. A changed or revoked owner mapping invalidates its task
signature; unsupported or absent mappings remain pending.

The GUI reports distinct server credits and session credits/hour. Agents receive
the `native-asm` command when installed. Class names and mappings are scheduling
clues, not proof that every mined function is usable. Missing owner declarations,
unpublished methods and unsupported layouts still require owner work. Completion
of every function cannot be guaranteed; no layout or player swap is automatic.

A request cap in this mode counts launched Codex agents, not their internal model
turns. Subscription token usage is reported after an agent exits; in-flight agents
can exceed a token cap. Time and check budgets bound each task. CLI subscription
runs have no reliable USD cap. Start with one worker/one agent for a cheap trial.
Contributor source/evidence are untrusted data, never agent instructions. Inbox
uploads are never automatically queued into chats.

Worker 20 uses the original frame probes' XTP include/static-link profile, retaining
Windows `min`/`max` macros for XTP while keeping `NOMINMAX` for other native probes.
A source file shares one baseline compile across its method workers per pass.
Compiler/profile updates reopen previously blocked local assignments on restart.
The feed distinguishes already locally exact methods (AI skipped) from baseline
failures, and expandable errors retain the complete compiler diagnostic.

Worker 21 reuses missing library/source directories from verified compiler/client
locations before any dependency downloads. Native-only startup prepares the RTM
compiler, SDK/MFC, donor sources and required XTP headers; standalone linked-library
recipes (including SDL 1.2.11) wait until submission needs them. New private sessions
share the launching checkout's tool/client cache, and resumed sessions repair missing
or broken input links while preserving private source and proofs.

Worker 22 resolves the installed Codex executable before launch. Each task gets an
assigned-header path and its baseline instruction/data diff. `python check.py`
prints a compact verdict and the full proof's filename; it exits unsuccessfully
unless `ok` and `target_exact` are true with no losses. Compiler success alone does
not prove recovery. Tiny bodies and identical sibling bodies are checked against
the assigned emitted symbol before spending an AI request. Missing canonical
module mappings leave proven native recoveries pending; they cannot earn server
acceptance until genuine linkage is implemented.

For an additional installed input cache, set `ROC_REUSE_TOOLS` to its `tools`
directory (multiple roots use the platform path separator), or record:

```json
{"tools_roots": ["C:/path/to/existing/RoConstruct/tools"]}
```

in `local/config/roconstruct-inputs.json`. Only missing directories are linked;
existing files are preserved. These paths are local configuration, not contributor
instructions. A genuinely missing required input still needs installation.
