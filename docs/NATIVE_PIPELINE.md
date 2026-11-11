# Resumable native integration

Run `python -m roc.native_pipeline PLAN.json --root C:\Users\colin\RoConstruct`.
Use `--validate` for structure-only validation. Plans are locally authored, reviewed
executable configuration, never contributor packets or commands copied from receipts.

The runner owns the integration guard. Do not nest it inside another guard. One
plan per coherent family: prepare private candidates, review their exact diff,
then pin every source, header, manifest, checker, runtime tool and binary input
using SHA-256. The plan itself is identified by SHA-256. Any change stops execution.
Pin transitive inputs; the runner cannot infer compiler/header/import dependencies.

Schema 1 fields:

* `reviewed_by`: reviewer identity after source/script and exact-diff review.
* `inputs`: mapping of absolute or root-relative input paths to SHA-256.
* `acquire`: argv commands taking this run's named file leases.
* `stages`: ordered objects with unique `name`, `kind`, `argv`, optional `cwd`,
  `timeout` (seconds), and `assertions`.
* `cleanup`: argv commands releasing only this plan's leases, run on failure too.

Kinds: `check`, `integrate`, `publish`. Check stages require fresh JSON receipts
and explicit assertions: `{"file":"proof.json","key":"passed","equals":true}`.
Dotted keys support array indexes. Pin/check all required original byte, data,
relocation, call, ABI and regression proofs; a process exit code alone proves none.
Use current reviewed findings runtime for integrate/publish, not stale checkout
tools. Keep native activation outside source-only plans until all required runtime
and P5/P6 gates pass. No inference of active providers or server credit.

All commands use argument arrays with no shell. Each command has bounded runtime;
work stops within 150 minutes, before the guard's three-hour expiry. Leases must
cover that duration (normally three hours); never release another worker's lease.

Logs and atomically replaced state live under `work/native-pipeline/PLAN_SHA/`.
Checks rerun on resume. Completed integration/publication stages are skipped.
If an integration/publication command fails or the runner dies while it runs,
state remains `running`: inspect exact remote contents and receipts, then reconcile
that state to `done` only with evidence of success. Otherwise prepare a newly
reviewed plan against current canonical source. Never blindly replay an uncertain
push. Publication retries use a separate publication-only plan after confirming
the prior attempt's remote result; source is not imported again.

The runner automates approved commands, proof assertions, checkpoints, resume,
timeouts and cleanup. The scheduled integration chat still performs source recovery,
script review, proof-obligation selection and three-way reconciliation. Unknown
proofs stay blockers; automation does not fabricate them.
