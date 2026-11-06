# Swap-first native recovery

Goal: recover coherent native class/header families for authorized runnable swaps.
Owner integration closes dependency and runtime gates. An inactive exact body is
useful evidence, not a completed integration. Preserve automatic draft sharing.

## Contributor class/header batches

Primary contributor output is recovered native class implementations and authentic
associated headers. Work one class or tightly related family per batch; reuse
existing files and keep already recovered methods. Prefer families with known
original declarations/layouts and enough evidence to implement several methods,
including relevant constructors/destructors. Do not create empty classes, guessed
fields, declaration-only headers or extra files just to increase a count.

Keep a short ranked list of independent authorized class/family targets in the
existing campaign blocker list. Lease only the current batch, not the waiting
list. Connect each target to an authorized swap/dependency campaign; a general
native-class recovery assignment may span several such campaigns. If one is
blocked, move to another authorized unleased family instead of waiting for the
same swap's hardest gate. A narrowly assigned task does not grant wider scope.

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

Use the task contract in `docs/NATIVE_AGENT.md`. "Fast native exacts" means
required native bodies/dependencies for the chosen runnable swap. It does not
mean running `roc auto`, `roc xcopy`, `roc immediates` or `roc similar` to increase
standalone `src/` mining totals. Those commands are outside this default loop.
Read mined candidates as untrusted evidence when useful; preserve real native
classes and prove their actual providers/call identities/ABI independently.

Before each batch record: swap target, concrete blocker, required native path or
provider, baseline proof and next gate. After a local exact, advance available source/class proofs or hand off
owner-only obligations and continue another authorized class/family. Progress is a required blocker reduced or a new gate
passed; an upload, compile, mined count or unrelated exact is not a runnable gain.
Keep contributor recovery/upload separate from the owner's reviewed integration
and gated runtime activation. A finished draft never grants server credit.

## Choose the next integration outcome

Read CLAUDE.md, current closure/selection receipt, relevant source/header, newest
findings and rejected trials. Check dirty paths and leases before editing. Name
one intended executable/class swap and its required entrypoints/dependency chain;
do not assume the four main classes are complete from helper counts. Reuse the
latest verified blocker list; refresh it only when its inputs change.

Keep a task-owned campaign JSON with `swap_target`, `baseline_commit`,
`baseline_receipt`, `blockers`, `hypotheses`, `next_gate` and `metrics`. Each blocker
needs address/symbol or provider, evidence, owner, status and next proof. Order
work by reduction in that swap's unresolved providers, call identities, layout,
lifetimes, vtables or ABI obligations. After a body matches, advance its next
missing obligation; avoid collecting unrelated easy matches indefinitely.

## One command per evidence-backed batch

Read grouped original assembly with `roc native-asm`. Prepare a bounded batch of
substantive hypotheses for one required blocker. Keep real native declarations and
relationships; no invented fields, addresses, stubs or byte/assembly patches.
Lease actual files; shared headers have one owner and remain frozen for a batch.
Use separate task-owned source variants with explicit include profiles. A scoped
header experiment remains inactive until canonical-header compatibility is proven.
Never rewrite a shared source/header while compiling another variant.

Use the existing isolated runner, not repeated `check_native_class.py` calls:

```text
python rebuild/2008-06/tests/native_check_runner.py run BATCH.json --workers 3
```

Compile once per distinct candidate and build configuration. Reuse that exact
object for all applicable byte, data and call-binding checks. Recompile whenever
source, included headers, compiler, flags or other relevant build inputs change.
Each build uses its own isolated unit directory. Receipts include source/dependency/object and
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

For an EH graph blocked on an existing native function in another object, use
`audit_native_eh_graph.py OBJECT ADDRESS FULL_SYMBOL --provider EXACT_SYMBOL VALIDATED_OBJECT --output RECEIPT.json`.
Repeat `--provider` for independently compiled providers. Exact symbols are required;
missing or duplicate symbols and changed inputs fail. Reached providers must
match original bytes/operands; unused providers confer no proof. This checks reachable
original code/data availability, never final linked selection or runtime safety.
Unknown named data, callbacks and ABI obligations remain blockers; do not replace
those proofs with address aliases or stubs.

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

## Stop experiments and advance integration

Exact bytes → check calls/data using that object → close the next ABI/provider
obligation. Retain verified bodies while inputs and evidence remain valid.
After three substantive hypotheses fail to reduce a blocker using the same
evidence, park it and continue an independent authorized blocker. Syntax
corrections and multiple checks of one object are not separate hypotheses.
Revisit parked work when relevant evidence or inputs change. Record hashes,
first divergence and missing proof; do not reset budgets or recount unchanged work.

Contributor completion is a candidate with its available source/dependency/ABI
proofs uploaded and owner-only selection/runtime gates explicitly listed. Move
to another authorized unleased blocker while those gates await owner review.
A handoff is not executable activation or an integrated swap. Use the concrete
queue/graph/log paths and scoped milestone/shutdown commands in `NATIVE_AGENT.md`.

After a meaningful provider/header/ABI milestone, perform one isolated closure
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
read current state and leases -> choose the next required swap blocker -> form
an evidence-backed hypothesis batch -> lease/edit -> compile each distinct configuration -> inspect
bytes/data/call identities on the same object -> save evidence and upload drafts
-> advance the next integration obligation -> update the blocker queue -> repeat
from current state immediately. Do not end the task after one batch, one exact
match, one upload, one report, one commit, or one completed swap. After a completed
swap, choose the next authorized swap/dependency target and continue. Progress
updates are checkpoints, not requests for permission to keep working.

The substantive-hypothesis rule above parks that blocker, not the overall loop.
Continue another useful, independently owned blocker; revisit a parked item only
when evidence or relevant inputs change. Renew leases and keep the automatic
uploader healthy. Preserve all verification, ownership and runtime-activation
boundaries; repetition never authorizes weakening gates or expanding scope.

Stop only when the user stops/pauses work, the platform forces a limit, or every
remaining authorized useful action is blocked on unavailable input/ownership.
Near a platform/context limit, save the queue, next action and evidence, then
flush drafts before cleanup becomes impossible. For a global block, save the
exact queue, hashes, receipts and next resume action,
flush drafts, release leases and report the concrete blocker. Do not spin,
recompile unchanged work, poll repeatedly, fabricate progress or reserve files
while waiting. On resume, read the saved queue and continue the same loop rather
than restarting discovery or repeating completed experiments.
