# Follow-up pilots, 2026-10-10

These experiments exclude 2009-12 and the five ranked shapes reserved in
AI-RECOVERY-HANDOFF.md. They do not change another worker's source or compiler
settings. No cloud requests are made. Acceptance requires score 100 locally,
referenced-data verification, and server byte verification. Existing exacts
are skipped; weaker candidates are logged, never submitted.

## Existing sweeps and fresh donors

The original propagation and expanded configuration sweeps remain running.
The existing scale queue then runs all donor source forms and layout recovery.
`benchmarks.followup_refresh` waits for that queue, configuration, and the new
cross-client config sweep. It then captures **live** server sources, resumes
propagation with all source forms, and rebuilds the layout manifest. This extra
refresh matters: the older driver's cached snapshots omit newly accepted donors.
History is copied into a separate output directory so previous attempts are
skipped without altering another worker's files. Reserved handoff shapes are
excluded from the new propagation/layout indexes.

## Compiler pilot

A seeded eligible pool contains 3,047 short, non-library partial sources across
allowed clients, excluding reserved shapes. Candidate qualification requires
at least 70% of instructions aligned identically or by register substitution,
plus a frame, register, size, or instruction-count diagnosis. These diagnoses
are hypotheses, not proof that function behavior matches.

53 sources were screened to obtain 30 qualified targets. Test optimization,
frame-pointer omission, security cookies, exception handling, inlining, and
intrinsics, one option group at a time. A second round starts only after a
score improvement, to test interactions with the improved setting. Keep the
source's compiler, calling convention, CRT linkage, and unrelated flags.

Result: **0 server exacts; one partial 70 -> 73**. Every tested flag/source and
score or compiler error is retained. This pilot does not justify scaling.

## Initialized-data pilot

All 56 previously confirmed code-exact/data-wrong targets are revisited.
Read expected bytes directly from executable addresses referenced by the
code-exact symbol. Read complete narrow strings through their terminator,
instead of truncating replacement strings to the old literal length. Only
explicitly sized integer arrays whose compiled bytes equal the entire baseline
reference qualify for integer replacement. Reject embedded relocations,
unmapped data, ambiguous types, and unsupported layouts.

The initial materialized-library attempt was rejected by the inline-assembly
policy because SDK headers contain assembly helpers. A second pass replaces
recognizable helper definitions with declarations and requires the materialized
baseline to recompile to its original score before changing data. Out-of-class
member redeclarations still fail for several libraries; those failures are saved.

Result: **0 server exacts**. Two GetPlayers literal corrections are locally 100,
but their approximately 4.5 MB materialized sources exceed the server's 200,000
character source limit. They are not counted. Three minimal-source hypotheses
per target reached only 79%; those sources and diffs are preserved. RTTI,
relocatable tables, and section-padding mismatches remain unresolved. No matcher
checks or server limits were weakened. Further scaling is not justified.

## Winning configs on untouched targets

Reuse server-verified successful shared-MFC source/config forms. First restrict
to previously source-less functions within winning client/class cohorts.
Pilot: 12 cohorts, **2 new exacts**. Complete all 17 eligible cohorts:
**3 new exacts** total.

The broader pilot tests successful forms on unresolved named CXT classes across
all allowed clients. A frozen manifest has 648 client/source cohorts. It excludes
previously tested source/target combinations and reserved handoff shapes.
Pilot: 12 cohorts, **10 new exacts**, meeting the predeclared full-scale threshold.
The full sweep is running; its live count is in config-cross.jsonl.

For speed, compile each source once per cohort, index open targets by function
size, and compare object functions with `fingerprint.Target.match_obj`. Require
executable relocation sites to be present in the object, retain referenced-data
verification, and submit each exact through the usual server verifier. Resume
skips finished cohorts. Successful forms are tried throughout the complete
frozen pool, not only the winning classes.

## Commands and artifacts

```text
py -3.12 -m benchmarks.followup_pilots data --limit 56 --scale-if-wins
py -3.12 -m benchmarks.followup_pilots compiler --limit 30 --scale-if-wins
py -3.12 -m benchmarks.followup_pilots config --limit 12 --scale-if-wins
py -3.12 -m benchmarks.followup_pilots config-cross --limit 12 --scale-if-wins
py -3.12 -m benchmarks.followup_refresh --wait-pids <existing-queue> <configuration> <cross-config>
```

Artifacts: `work/followup-pilots-20261010/`, including frozen manifests, pilot
decisions, per-target JSONL, all candidate sources, compiler errors, server
responses, and fresh-donors/queue.json. Only unique allowed client/address
responses with `verified=true`, `score=100`, and `improved=true` count as new.
Do not add the fresh-donor history copies to campaign totals a second time.

Validation: four focused tests check complete-string replacement, integer-array
baseline/size requirements, preservation of unrelated flags, and assembly-helper
normalization. Existing budget-persistence test assumes the previous $1.80 limit
and fails against another worker's $4.50 edit; that unrelated test/code is untouched.
