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
in place. Receipt promotion requires a fresh, reviewed source/address/symbol
identity, exact code/data, and complete call/reference checks.

Outputs live under `work/native-autopilot/2008-06/run-*/`:

- `summary.json`: per-group counts, original addresses, unresolved reasons,
  decimal raw/adjusted/fuzzy scores, and separate integration/runtime status.
- `report.html`: standalone searchable report; open directly in a browser.
- `similarity.json`: mining opcode-family fingerprints and instruction-shape
  similarity reused against existing native objects, including already-mined
  addresses. Search hits cannot grant exact status.
- `llm-reviews/queue.json`: bounded text-only investigations, cached by original
  image and evidence hashes. Every response remains an unverified hypothesis.
- `integration.json`: frozen eligible candidates and owner pipeline results.

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

The existing pipeline acquires the integration lock, validates unchanged pinned
inputs, reruns checks and fresh assertions, and retains durable side-effect
state. Its reviewed commands must not commit, push, publish or execute diagnostic
clients. Publication stages are rejected by this adapter. No registered plan
means candidates remain staged and pending owner gates; no runtime result is
invented. There is currently no blanket integration plan for all libraries.

## Follow-up and limits

After the sweep, wait five minutes, inspect changed source/dependency/identity
evidence, and retry only affected or failed batches once. Unchanged proof gaps
stay in the report. `--followup-seconds 0 --limit N` supports a small pilot;
`--plan-only` inventories without compiling. It cannot replace an active run.

Exit 2 means the sweep ended with unresolved work, discovery gaps or pending
integration gates. It does not mean every batch crashed. The command never runs
mining submissions, commits, pushes or website publication. Full original source
recovery, broader cross-object discovery and automatic model-proposal application
remain separate unfinished capabilities.
