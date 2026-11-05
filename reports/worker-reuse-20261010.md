# Worker reuse and repair correctness — 2026-10-10

Client: August 19, 2007 (`2007-08`), registered VS2005 build 50727.
Changes target concrete worker defects rather than another global prompt tweak.

## Accepted changes

- Cache example sources together with their strict-family provenance. Previously,
  only cache misses set the strict flag, so later sibling jobs skipped propagation
  and lost family-specific prompt instructions. Cache keys distinguish family mode
  from general examples. Publish source/provenance together so concurrent readers
  cannot observe a partially populated entry.
- Compile a strict-family donor directly when literal rewriting returns no candidate.
  Symbolic external references often need no rewritten address literal; the old
  path skipped them. Normal byte and referenced-data checks remain authoritative;
  compile failures and non-improvements continue to model generation.
- Explicit near-repair mode uses its supplied source and measured diff in the first
  model round. Normal generation and explicit candidate diversity retain independent
  first draws.
- Replace a baseline's claimed score with its freshly compiled score. A baseline
  that fails compilation cannot remain the best candidate or hide a valid improvement.

## Real compiler replay

Discovery donor `00777ad0` independently scored 100. Its unchanged source matched
`00777af0`, `00777b10`, `00777b30`, `00777b50` at 100; literal rewriting returned
no candidate for all four.

Before target evaluation, froze four other repeated families in `seg_00770000`:
ranked by member count, 10–128 bytes, at least four members, an independently verified
exact donor, then first five other addresses. Excluded the discovery fingerprint.
No target-result filtering was used. Frozen manifest:
`benchmarks/worker-family-cache-holdout-2007-08.json`.

| Isolated family stage, 20 source-hidden targets | Frozen control | Fixed worker |
| --- | --- | --- |
| Normal code/data exact | 1 | 11 |
| Model entry calls | 17 | 0 |
| Family example queries | 4 | 4 |

This replay uses real target bytes, fingerprints, donor source and MSVC compilation.
Its local API fixture independently recompiles every proposed submission after
clearing the compiler cache. Automatic/reference candidates are disabled and model
output is stubbed, isolating the family stage. Counts are neither a comparison of
real AI quality nor a whole-worker speed measurement. All eleven fixed-arm exacts
already had exact catalog entries; these are reuse successes, not new discoveries.
Four fixed targets scored 99 because referenced data differed; five remained other
partials. Such candidates were never counted as exact. Real jobs retain their
existing better source because submission still requires a score improvement.

Report, proposed sources and frozen control: `work/worker-family-cache-20261010/`
and `work/worker-repair-start-20261010/control_worker.py`.

```text
python benchmarks/worker_family_cache.py benchmarks/worker-family-cache-holdout-2007-08.json --control-worker work/worker-repair-start-20261010/control_worker.py --output work/family-cache-UNIQUE
```

## Rejected alternatives

Making every supplied-source job repair immediately, rather than taking its normal
independent first draw, lost on an eight-target paid pilot: control 2/8 exact,
four improved, mean 60.88%; candidate 1/8 exact, three improved, mean 52.38%.
Three rounds, 2048 output tokens, disabled thinking, seed 42, shared $0.50 cap.
Only the explicit near-repair behavior correction was retained; its unit tests
verify first-round source/diff inclusion and normal/diversity behavior.
Pilot report: `work/worker-repair-start-discovery-20261010/report.json`.
The reusable repair runner supports `--near-repair` for testing the final scoped fix.

Compiler-only early guided-repair replay of 24 distinct saved high-partial drafts
produced one partial gain and zero exact conversions. No per-round mutation sweep
was added. Report: `work/worker-early-repair-20261010/report.json`.

## Budget

Paid pilot estimated $0.0679491; previous history tests $0.1693719.
Cumulative estimated DeepSeek usage: **$0.237321 of the authorized $3**.
Maximum combined paid-run reservation caps were $1.75. Family replay and tests
made no paid API requests. Estimates use configured peak pricing, not invoices.
Ledger: `work/worker-improvement-budget-20261010.json`.
No live submissions, recovered-source replacements, or provider-setting changes.
