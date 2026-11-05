# Deep fingerprint pass

Optional expansion after the fast fingerprint passes. It tries installed source
versions, additional MSVC builds, and optimization/inlining/frame-pointer flags.
No source downloads, new AI calls, or server restart are required.

Named families/classes stay isolated. Unclassified units require exact-source
evidence in that same client/unit. Near-exact partials (85–99%) come first;
unknown source families and explicitly restricted Wild Magic sources are excluded.
The server recompiles each candidate and keeps only score improvements.

Start with a bounded pilot:

```sh
python -m roc.deep_fingerprint --dry-run
python -m roc.deep_fingerprint --max-batches 24
```

The default is one sequential worker, eight targets per batch, and 24 batches.
Recipe versions and families are interleaved so the sample does not spend its
whole budget on one version. Compilation caches and existing fast-pass pair
checkpoints are reused. Independent resume state is `work/deep-fingerprint.json`.
Failures remain pending; they are not recorded as successful checks.

For a larger bounded experiment:

```sh
python -m roc.deep_fingerprint --max-batches 96
```

`--max-batches 0` checks all currently pending batches and can take much longer.
`--min-score 0` also expands to low-score and zero-score targets. Measure gains
before either expansion; a bigger search is not guaranteed to find more matches.

Console summaries distinguish source/target checks, improvement events, unique
improved functions, new exact matches, and elapsed time. `last_run` in the state
file records counts and per-family measurements for subsequent runs. Improvement
events may count one function several times; do not report them as unique matches.

The first pilot checked 101 source/target pairs in 73 seconds and raised seven
2010 Ogre functions to server-verified 100%. This small sample is not a reliable
full-run ETA or proof that every library benefits equally.
