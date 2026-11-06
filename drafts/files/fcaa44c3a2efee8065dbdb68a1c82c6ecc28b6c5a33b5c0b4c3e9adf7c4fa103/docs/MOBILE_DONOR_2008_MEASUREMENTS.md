# Mobile donor test: 2008 native integration

Date: 2026-11-06. Scope: 2008 only. Three existing integration families were
tested against the installed 2013 iOS donor, with an additional Android name
coverage check. No mining pass, 2012 experiment, native source/header edit,
linked-provider change or runtime activation was performed.

## Result

**No immediate native integration gain in this sample.** The donor corroborated
existing Instance behavior and exposed significant RunService version drift, but
resolved none of the recorded ABI/provider/EH gaps. The embedded writer's class
and its desktop caller have no named counterpart in these mobile inputs.

| Family | Fresh target-only baseline | Additional donor evidence | Verified gain |
|---|---|---|---|
| RunService | enqueueTask, drainTasks and setRunState already code/data exact (3/3); callable return type, timing fields, virtual/ABI/provider work remain open | State-transition guards survive, but 2013 adds job startup, different reset fields and signal dispatch. No RunService enqueueTask/drainTasks/RunView symbol evidence found | 0 methods, fields or integration gates recovered |
| Instance parenting | setParent and contains already code/data exact (2/2); whole-class ABI and linked closure remain open | Corroborates same-parent exit, self/cycle rejection, descendant notifications and final Parent property notification. New lock/bypass/internal-parent API and signal backend prevent direct transplant | 0 new identities or source corrections beyond existing target proof |
| TextXmlWriterWithEmbeddedContent / CWorkspace writer | constructor code/data exact; caller 99% and destructor 78% code similarity, both still different | No named embedded-writer or CWorkspace counterpart in indexed iOS symbols or corresponding Android binary name strings. Base TextXmlWriter exists, but does not answer this derived-class lifetime or Windows EH question | 0 blocker fixes; both mismatches remain |

Aggregate: **6/8 bodies code/data exact before donor lookup; 6/8 after inspection**.
The six are existing source proofs, not new recoveries. New methods, header
facts proven, exact bodies, ABI proofs, selected providers and gated swaps: **0**.
No reviewed direct-call-binding manifest was provided in this baseline run, so
these checks do not establish fresh complete call identity, ABI or selection.
The 99%/78% figures are diagnostic code similarity, not integration completion.

## Method and timings

Before looking up donor implementations, the test froze three native source/header
pairs and their unresolved obligations in
`work/2008-06/shared-layouts/mobile-donor-measurement/baseline.json`.
The owner working checkout was the baseline for these inactive candidates; it
was not represented as an already selected authoritative native provider.

A single isolated batch compiled each of the three existing translation units
once using original VS2008 RTM (`21022`). The existing native runner checked eight
methods and their available referenced data. Sources/headers remained unchanged
throughout the experiment, so another identical compile after donor lookup would
add no evidence and was not run. The retained objects/receipts are the before/after
baseline; none of their outcomes was promoted by reading donor text.

- Run: `work/2008-06/native-check-runs/20261106-184100-58ab7f83`.
- Compile times: Instance 4.250 s, RunService 4.656 s, writer 7.390 s;
  16.296 s summed compiler time across concurrent jobs.
- Batch wall time: 15.937 s, including analysis.
- First measurement snapshot: 104.392 s from baseline freeze through initial
  donor inspection and comparison. This excludes initial task discovery and
  later report/upload work; it is not a per-class recovery time.
- Full raw method results, source/object hashes and scores:
  `work/2008-06/shared-layouts/mobile-donor-measurement/measurement.json`.

This is a serial marginal-evidence test against already developed native sources,
not a randomized control or a from-scratch decompilation benchmark. It establishes
zero additional verified gain on these gaps; it cannot estimate a general speedup,
prove the donor is useless for other classes, or measure hypothetical hours saved.

## Evidence that limits transfer

RunService donor `0036d920` (`RBX/setRunState.c`) starts the newer job machinery
when entering running state, clears a different collection of fields on reset,
and emits an rbx signal. Target `00554da0` only resets the independently recovered
2008 field and raises its two legacy Notifier events. Copying the donor body would
damage already exact target behavior. The absence of the old callable queue's
named methods means the donor cannot settle its inferred return type.

Instance donor `0072d658` (`RBX/setParent.c`) is a wrapper calling
`setParentInternal(newParent,false)` at `00729e64`. That implementation includes
parent-lock handling and newer signal data. Target `0055a8f0` implements the older
parenting chain directly. Shared algorithms corroborate the target source; donor
offsets, virtual slots, locks and notification types do not prove 2008 ABI.

The iOS index returned zero symbols containing TextXmlWriterWithEmbeddedContent
or CWorkspace. The Android binary contained neither name string. These are bounded
named-evidence coverage results, not proof that no optimized/inlined related code
could exist. A mobile binary is a poor source for this desktop writer obligation.

Ghidra pseudo-C also needs range verification: the exported RunService
onServiceProvider body is much larger than its stated short symbol range and
contains stop-task logic. Do not infer a target implementation from that export
without checking the original donor bytes and boundaries. No claim in this test
depends on that questionable pseudo-C body.

## Integration recommendation

For 2008, use this donor for bounded symbol/behavior corroboration after reading
the existing native source and original target evidence. Prefer a closer 2007/2008
source when available. Use mobile evidence when the needed system exists in the
mobile build and its behavior demonstrably survived. Keep desktop-only lifetimes,
MSVC EH, 2008 layouts, provider ownership and runtime gates on their original
evidence paths. Do not spend further trials on these same gaps without new inputs.

The earlier broad expectation of a major 2008 recovery boost is not demonstrated
by this sample. Here its value was supporting context and avoiding incorrect
cross-version transfers, rather than recovering additional native implementation.
