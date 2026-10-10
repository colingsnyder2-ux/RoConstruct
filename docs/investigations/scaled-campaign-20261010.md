# Expanded matching campaign

Exclude 2009-12 from targets, donors and result totals. Normal code and referenced
data verification plus server acknowledgement remain mandatory for new exacts.
Concurrent runs submit only exact improvements. No blanket compiler/library
changes are promoted.

## Running sweeps

- Original propagation continues. `benchmarks.scale_queue` waits for its exact
  process to exit, then resumes with `--donor-limit 0` (all distinct source forms),
  followed by another refreshed class-layout sweep. Resume restores exact donors
  from previous records and all other campaign stages. Existing checked hashes
  prevent repeat compilation.
- Existing template expansion continues. Its queue then adds shared/weak/intrusive
  pointer and allocator types, tests all compiler builds registered for the seven
  allowed clients, and skips completed variant/build combinations. Frozen server
  scores, not stale local score files, determine target eligibility.
- Shared-MFC expansion: 1,999 eligible client/class/library-path cohorts,
  25,958 planned target/guard rows. Both O2 and O1 are retained. All positive-score
  partials are eligible; known-exact guards remain. Completed rows are skipped.
- Class-layout expansion: 3,508 frozen donor/target pairs. Refresh combines
  propagation failures with same-class/same-shape donors across clients. Each
  donor verifies once per run. Absolute address maps and anonymous segment reuse
  are excluded from class evidence. New exacts are accepted per target.

Commands:

```text
python -m benchmarks.match_campaign configuration --scale --server http://127.0.0.1:8765
python -m benchmarks.class_layout --refresh --limit 1000000
python -m benchmarks.match_campaign templates --template-limit 10000000 --all-template-builds --server http://127.0.0.1:8765
python -m benchmarks.match_campaign propagate --donor-limit 0 --server http://127.0.0.1:8765
```

## Completed unfinished pilots

AI representatives: 12 uncovered high-fanout families, two rounds each (23 actual
requests), one new server-verified representative exact. Trials and full round
stats retained. Peak-price usage estimate $0.0185895; persisted budget cap $1.80
with a 60-request limit, leaving room under the user's $2 campaign cap. Reservation
is written before each request; crashes retain reservations and missing usage
does not refund. Official DeepSeek pricing checked on 2026-10-10:
https://api-docs.deepseek.com/quick_start/pricing/?push_animated=1&theme=light&webview_progress_bar=1
AI family siblings undergo normal verification; representative success does not
guarantee sibling gains. An authorized follow-up extends to 30 families under
the same persisted 60-request/$1.80 cap; this does not reset the spend ledger.

Real contexts: corrected adapter now handles recovered member names and named
parameters. Ten actual callers with independently byte/data-exact callee bridges
completed opaque/visible/LTCG trials. Linked scores still involve unresolved
external symbols and do not verify linked data; report as diagnostic only. No
linked-only exact or new recovery gain is claimed.

Data-only: a frozen randomized 200-target scan of stored 99% sources completed:
56 genuine code-exact/data-wrong targets, zero exact conversions from literal
string repair. Other initialized-data and library mismatches remain unresolved.
It selects all exact object-symbol ties, verifies referenced data, and attempts
conservative literal-string replacement only on genuine code-exact/data-wrong
targets. Other data mismatches are preserved for future recovery work. A stored
99% label alone does not qualify. No global or external symbols are replaced by
guessed contents.

Broader AST synthesis, SMT/CEGIS and global graph matching remain research topics;
these pilots do not claim those systems are complete.

## Progress checkpoint

At the checkpoint during expansion: propagation 4,877 rows / 425 new exacts;
templates 494 variants / 92 new exacts; configuration 544 rows / 72 new exacts;
class-layout 989 rows / 141 new exacts. These are historical checkpoints, not live
state. Class-layout totals include the earlier three address-correction wins;
those must be excluded when attributing gains specifically to field recovery.

Evidence lives under `work/match-campaign-20261010/`: immutable trial hashes,
manifests, JSONL logs, saved candidates, `ai-budget.json`, and queue logs. Recompute
new gains from unique client/address records with `submission.improved=true`,
excluding 2009-12. Do not sum diagnostic replay exacts into new server wins.

Validation: `python -m pytest -q tests` passed 270 tests. Pilot tests exercise
budget persistence and missing-usage conservatism, stack/address exclusion,
conflicting field evidence, actual named-callee adaptation, string replacement,
and rejection of unknown value layouts. Root-level pytest still imports an old
standalone script that exits during collection; the maintained suite is `tests/`.
