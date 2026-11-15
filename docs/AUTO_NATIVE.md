# One-command native sweep

```bat
roc.cmd auto-native 2008-06
```

The command inventories configured source recipes and explicit native batch plans,
prioritizes G3D, groups checks by source, and runs the existing isolated compiler
and proof verifier. It reuses the original compiler configuration recorded by
each native source and valid cached objects. Three bounded compiler profiles are
diagnostic trials. Different compiler generations still need an explicit supported
recipe; a failed trial never establishes a match.

The coordinator resumes unfinished work, checks worker PID **and creation time**,
preserves source/dependency fingerprints, and retains compile failures without
discarding successful translation units. Independent compiler units use three
workers; canonical source files are not rewritten. Existing leases and edits stay
in place. The report records a fresh lease inventory (explicitly labelled when
only cached lease data is available). Receipt promotion requires a fresh, reviewed source/address/symbol
identity, exact code/data, and complete call/reference checks.

Outputs live under `work/native-autopilot/2008-06/run-*/`:

- `summary.json`: per-group counts, original addresses, unresolved reasons,
  decimal raw/adjusted/fuzzy scores, and separate integration/runtime status.
- `report.html`: standalone searchable report; open directly in a browser.
- `similarity.json`: mining opcode-family fingerprints and instruction-shape
  similarity reused against existing native objects, including already-mined
  addresses. Search hits cannot grant exact status.
- `fingerprint-discovery.json`: cross-object search of current compiler outputs
  and valid source-sweep/object-cache evidence; conflicting owners stay visible.
- `identity-vtables.json`: independent original PE RTTI class and complete
  primary virtual-slot correspondence for directly declared simple methods.
  Inherited/template/helper owners remain unproved. Source, object, compiler,
  real header dependencies and include search context are checked for freshness
  before indexing; code/data/call/reference gates still run independently.
- `llm-reviews/queue.json`: bounded text-only investigations, cached by original
  image and evidence hashes. Every response remains an unverified hypothesis.
- `integration.json`: frozen eligible candidates and owner pipeline results.
- `owner-handoff.json`: durable draft-inbox session and upload receipt IDs for
  candidates awaiting owner gates. Upload failures preserve the local outbox.

The first run inventories existing inactive status; that prior index is distinct
from fresh checks in this run. Recipe/source labels and identical template bodies
are discovery hints. Missing symbols, missing source, collisions and unsupported
proof obligations remain visible.

## Model review

Current owner preference: **ChatGPT Luna only**, through the existing
ChatGPT-signed-in Codex CLI (`codex:gpt-6-luna`, medium reasoning).
OpenCode/NVIDIA fallback is disabled. Earlier provider investigations remain
historical hypotheses. No credentials enter reports; no purchase or sign-in
setup occurs automatically.

Review outcomes are cached across sweeps by original image and complete evidence
fingerprints. Unchanged evidence does not cause another request. Interrupted or
timed-out submissions remain uncertain across runs too.

The review lane drains promising unresolved targets with six text requests
at a time and a 60-second request deadline. Its Python API accepts a `limit`
for pilots; the one-command default covers the queued targets. Lower-quality source
candidates remain deterministic discovery work. Submitted requests interrupted
or timed out remain uncertain; they are not blindly duplicated. Model output
cannot edit canonical source, supply a trusted identity, weaken a gate or grant
exact/runtime/server credit. Source changes suggested by a model still need the
same independent compiler/proof loop; automatic application is not implemented.

## Owner integration

The adapter reuses `roc.native_pipeline` for an existing **locally reviewed**
integration plan. Register pinned plans in
`rebuild/2008-06/manifests/native-autopilot-integrations.json`:

```json
{"plans":[{"path":"rebuild/2008-06/manifests/owner-plan.json",
           "sha256":"SHA256_OF_REVIEWED_PLAN",
           "addresses":["00500000"]}]}
```

The plan uses the existing pipeline schema: `schema:1`, `reviewed_by`, pinned
`inputs`, commands as argv arrays, and fresh receipt `assertions` on every check.
Its `autopilot_targets` must exactly match registered addresses. Check stages
declare the gates they independently verify in a `gates` list. Before an
`integrate` stage, all of these must pass:

`provider`, `layout`, `abi`, `link`, `preservation`, `regressions`, `p5`, `p6`, `runtime`.

Each plan declares concrete repo-relative `write_paths`, including every
candidate source and every header/build/selection file it may change. The adapter
acquires these paths atomically from the live lease server before invoking the
pipeline and releases them on completion or failure. Offline or conflicting
leases cannot authorize activation. Candidate proof and identity inputs must be
pinned in the reviewed owner plan.

The existing pipeline acquires the integration lock, validates unchanged pinned
inputs, reruns checks and fresh assertions, and retains durable side-effect
state. Its reviewed commands must not commit, push, publish or execute diagnostic
clients. Publication stages are rejected by this adapter. No registered plan
means candidates remain staged and pending owner gates; no runtime result is
invented. There is currently no blanket integration plan for all libraries.

Unselected eligible candidates are frozen under
`work/native-candidates/auto-native/<receipt hash>/` with their source snapshot,
body receipt, identity evidence when available, and original canonical path.
The adapter automatically checkpoints and uploads only that candidate folder
through the existing native draft inbox. It reuses the saved session on retry
and requires a durable receipt for the latest bundle before reporting delivery.
This sends evidence for owner review; it grants no integration or server credit.

## Follow-up and limits

After the sweep, wait five minutes, inspect changed source/dependency/identity
evidence, and retry only affected or failed batches once. Unchanged proof gaps
stay in the report. `--followup-seconds 0 --limit N` supports a small pilot;
`--plan-only` inventories without compiling. It cannot replace an active run.

Exit 2 means the sweep ended with unresolved work, discovery gaps or pending
integration gates. It does not mean every batch crashed. The command never runs
mining submissions, commits, pushes or website publication. Full original source
recovery and automatic model-proposal application
remain separate unfinished capabilities.
