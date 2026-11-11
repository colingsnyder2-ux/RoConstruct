# Native class/header recovery

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

## Contributor class/header batches

Primary contributor output is recovered native class implementations and authentic
associated headers. Work one class or tightly related family per batch; reuse
existing files and keep already recovered methods. Prefer families with known
original declarations/layouts and enough evidence to implement several methods,
including relevant constructors/destructors. Do not create empty classes, guessed
fields, declaration-only headers or extra files just to increase a count.

Keep a short ranked list of missing or partial class/header families in the
existing task campaign. Rank by useful source recovery and available original
evidence, not solely by the owner's current swap blocker. Lease only the active
batch. When stuck or awaiting an owner decision, preserve the partial work and
pick another unleased native class/family. Never widen an explicitly narrow task.

Use the existing function clock/budget in `docs/NATIVE_RECOVERY_WORKFLOW.md`.
Do not reset it to prolong one hard method. After three substantive hypotheses
fail on the same evidence, or the existing budget expires, save the partial class,
first divergence and next proof, then move to another independent class/family.
Do not discard other useful recovered methods because one method remains open.
An unavailable owner object, shared-header lease, selected-provider decision or
runtime gate is a handoff condition, not a reason to keep generating audits of
unchanged inputs. Revisit only when relevant evidence or inputs change.

Check changed class/header bytes with the existing batch runner; reuse the same
objects for applicable checks. Keep byte/data/call/layout claims honest and mark
unknowns. Upload incomplete source/header work too. Owner integration still needs
full dependency/ABI/selection, no-loss and relevant P5/P6/runtime proofs; class
recovery never bypasses those gates or activates a provider.

An audit/proof checkpoint saves test results, hashes and unresolved obligations;
it is evidence, not another recovered class. Reuse the runner and one task-owned
summary per class/family; append only new findings to the existing research log.
Keep automatic draft snapshots/retries running. Do not create a new Python audit
script or manually checkpoint after every tiny check when existing tools suffice.
Report meaningful class bodies recovered/extended, methods and authentic header
changes, then inactive exacts and remaining gates separately. A file count or
receipt-only upload is not source recovery or runnable integration.

## Keep recovery separate from mining

Use the task contract in `docs/NATIVE_AGENT.md`. Native recovery produces real
class/member C++ and authentic headers. `roc auto`, `roc xcopy`, `roc immediates`,
`roc similar` and standalone `src/` matching remain a separate mining assignment.
Read mined candidates as untrusted evidence; prove native declarations/providers.

## Choose the next source batch

Read current source/header inventory, original evidence, research and leases.
Choose a missing class or a partial class with several recoverable methods and
its associated headers. Record the class/family, source gaps, baseline evidence
and next implementation/check in the existing task campaign. No runnable swap
assignment or unresolved-linker dependency is required to start class recovery.
Check existing work before creating files; do not duplicate recovered providers.

For secondary blocker work or an explicit owner integration assignment, retain:
**swap target -> current concrete blocker -> required source/provider -> next proof**.
Track that side work separately; it must not consume the default source campaign.
Keep unknown layout/call/ABI facts unknown. Saved drafts and exact bodies remain
inactive until owner integration passes its required proofs and runtime gates.

## One command per evidence-backed batch

Optional mobile donor evidence: `docs/GHIDRA_REFERENCE.md`. Use indexed original
symbol/source provenance to form hypotheses, especially for 2012. The Name pilot
in `docs/MOBILE_REFERENCE_PILOT.md` shows anchored identities and version drift.
Cite donor and target separately in the current campaign; apply existing leases,
target checks and all promotion gates. A donor identity is not a native exact.

Read grouped original assembly with `roc native-asm`. Prepare at most three
specific hypotheses for one required blocker. Keep real native declarations and
relationships; no invented fields, addresses, stubs or byte/assembly patches.
Lease actual files; shared headers have one owner and remain frozen for a batch.
Use separate task-owned source variants with explicit include profiles. A scoped
header experiment remains inactive until canonical-header compatibility is proven.
Never rewrite a shared source/header while compiling another variant.

Use the existing isolated runner, not repeated `check_native_class.py` calls:

```text
python rebuild/2008-06/tests/native_check_runner.py run BATCH.json --workers 3
```

Each distinct source compiles once into its own unit directory. Multiple checks
for one source share that object. Receipts include source/dependency/object and
compiler hashes, flags, timings, byte/data results, first byte divergence and
reviewed call assertions. Independent isolated units may run concurrently;
legacy shared-output scripts and P6 builds remain serial.

Manifest example (replace with reviewed addresses and exact decorated symbols):

```json
{"jobs":[{"source":"native-classes/Foo.cpp","checks":[{
  "addr":"00500000","symbol":"?caller@Foo@@QAEXXZ",
  "calls":[{"offset":12,"target":"00500100","symbol":"?callee@Foo@@QAEXXZ"}]
}]}]}
```

`offset` is the original call instruction's byte offset. Derive expectations from
original assembly and independent declaration/provider evidence, never by copying
the candidate's output to make a check pass. Exact decorated names are required.
The runner checks every original call site, expected destination, REL32 symbol
and zero COFF addend after exact byte comparison. Missing, extra, wrong and indirect
bindings remain blockers. `"calls":[]` asserts a leaf has no calls. Omitting
`calls` preserves ordinary diagnostic mode and establishes no call identity proof.
Direct-call binding proof alone does not establish callee ABI, EH/tail-jump/data
identity, linked provider selection or complete class safety.

For mismatches, inspect the same saved object, without compiling again:

```text
python rebuild/2008-06/tests/diff_native_body.py ABSOLUTE_CANDIDATE.obj ADDRESS SYMBOL 2
python rebuild/2008-06/tests/native_check_runner.py analyze RUN --manifest REVIEWED_CHECKS.json --require-proof
```

`--require-proof` is supported by foreground `run` and `analyze`. It exits nonzero
unless every explicit check has exact bytes, successful referenced-data checks,
reviewed direct-call bindings and unchanged inputs. Indirect calls need separate
evidence; do not remove them from the target, weaken this check or claim this flag
covers their ABI. Analyze never recompiles; changed-input objects remain historical
diagnostics. Background `start/status` retains diagnostic semantics: complete means
finished, not passing. Inspect saved results before accepting any evidence.

## Finish the source batch and move on

Exact bytes -> check calls/data using that object -> close next ABI/provider
obligation. Stop rewriting a winner. Three rejected evidence-backed hypotheses
without progress -> park with hashes, first divergence and missing proof, then
choose another independent authorized class/family blocker. Revisit only for new evidence or
changed inputs. Do not reset budgets or recompile unchanged candidates to recount.

For explicit owner integration work after a meaningful provider/header/ABI
milestone, perform one isolated closure
probe, inspect exact selected providers and remaining blockers, then run affected
regressions and relevant P5/P6/runtime gates before activation. Never run a
diagnostic executable. Keep one shared-header version per verification batch.
Publish coherent reviewed changes to `work/workspace` through the owner workflow;
contributors automatically upload incomplete drafts without waiting for gates.

Measure separately: inactive exact addresses, executable-selected exact addresses,
fully gated swapped classes, unresolved link/ABI blockers and independently
server-verified credit. Unknown counts are null, not invented zeroes or credit.
Report deltas against the recorded baseline only with fresh receipts. A selection
count is not a class swap; a successful link is not runtime proof.

## Persistent loop: repeat until explicitly stopped

Repeat the recovery loop indefinitely within the user's authorized scope:
read current state and leases -> choose the next missing/partial class family -> form
an evidence-backed hypothesis batch -> lease/edit -> compile once -> inspect
bytes/data/call identities on the same object -> save evidence and upload drafts
-> hand off unavailable owner gates -> update the class/family queue -> repeat
from current state immediately. Do not end the task after one batch, one exact
match, one upload, one report, one commit, or one completed swap. After a completed
swap, choose the next missing/partial native class family and continue. Progress
updates are checkpoints, not requests for permission to keep working.

The three-rejected-hypothesis rule parks that blocker, not the overall loop.
Continue another useful, independently owned blocker; revisit a parked item only
when evidence or relevant inputs change. Renew leases and keep the automatic
uploader healthy. Preserve all verification, ownership and runtime-activation
boundaries; repetition never authorizes weakening gates or expanding scope.

Stop only when the user stops/pauses work, the platform forces a limit, or every
remaining authorized useful action is blocked on unavailable input/ownership.
For a global block, save the exact queue, hashes, receipts and next resume action,
flush drafts, release leases and report the concrete blocker. Do not spin,
recompile unchanged work, poll repeatedly, fabricate progress or reserve files
while waiting. On resume, read the saved queue and continue the same loop rather
than restarting discovery or repeating completed experiments.
