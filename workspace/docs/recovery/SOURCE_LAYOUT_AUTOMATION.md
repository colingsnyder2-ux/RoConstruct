# Bulk native source moves

Use `roc.source_layout` to prepare and check a reviewed batch of whole-file moves.
It never edits the shared checkout, runs an executable, commits or pushes.

Create a JSON spec containing the exact work-branch commit and independently
reviewed original addresses and symbols:

```json
{"base":"EXACT_40_CHARACTER_COMMIT","moves":[{"source":"native-classes/Example.cpp","target":"WindowsClient/src/Example.cpp","checks":[{"addr":"00400000","symbol":"?originalMethod@"}]}]}
```

To build a proposal from an existing independently reviewed native-check manifest,
run `python -m roc.source_layout --root REPOSITORY suggest --base EXACT_COMMIT
--target-prefix WindowsClient/src --checks CHECKS.json --output
REPOSITORY/work/native-candidates/suggestions.json`. It reports skipped paths and
never treats a proposal as approval. Choose the project folder explicitly.

Fetch work and inspect the sources, target grouping, ownership, compiler flags
and original identities before using the spec. Checks are input evidence;
never infer them solely from candidate output. Each source needs at least one.
The tool rejects relative source includes, pre-existing destinations, public
code differences and ambiguous compiler flags; review those cases separately.

```text
python -m roc.source_layout --root REPOSITORY prepare --spec SPEC.json --out REPOSITORY/work/native-candidates/NEW_BATCH
python -m roc.source_layout --root REPOSITORY run --out REPOSITORY/work/native-candidates/NEW_BATCH --approved-runner REVIEWED_SHA256 --workers 3
```

The plan records the canonical runner hash. Review that exact runner first;
pass its SHA-256 as `--approved-runner`. Each candidate compiles once with
frozen canonical headers. The tool rechecks original code/data, source, header
and compiler hashes, and compares all non-debug object sections and named
relocations. Files that fail any check stay skipped. It writes `review.json`,
`integration-manifest.json` and `public-manifest.json` in the new folder.
If every job finished but some sources failed, successful pairs are verified
and retained automatically; failed pairs stay in the report for later review.
An interrupted run or changed shared headers invalidates the batch. No bisect
or recompilation is needed to separate successful pairs in a finished run.

For an already completed isolated runner, use `verify --out NEW_BATCH --run
RUN_DIRECTORY`; the saved runner must match the canonical runner for the base.
No command here uploads or activates source. Batch evidence does not prove
indirect calls, provider selection, ABI, exception safety, runtime or credit.

Before promotion, review the complete exact diff and source/proof inventory;
acquire real file and shared-header leases, reconcile any base advances, add
necessary layout and proof records, and run affected ABI/regression gates.
Use the existing `roc.findings_workspace integrate --manifest ...` and its
exact-tree preservation checks; mirror reviewed public paths and refresh the
package and navigation separately. Never compile both a compatibility unit
and its organized source into one target.
