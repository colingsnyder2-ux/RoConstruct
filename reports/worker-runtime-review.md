# Live worker review — 2026-10-09

Ran four bounded batches against the configured mining server with eight concurrent
DeepSeek workers, automatic rounds/output, and direct drafting. Accepted improvements
were submitted through the normal worker verification flow. Saved settings were preserved.

| Batch | Selection | Jobs | Exact | Improved, including exact | Worker errors | Wall seconds |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| Baseline | Automatic, ≤512 bytes | 16 | 2 | 2 | 0 | 57.813 |
| Telemetry fix | Unmatched, ≤256 bytes | 16 | 5 | 13 | 0 | 30.313 |
| Repair fixes | Automatic, ≤512 bytes | 16 | 10 | 10 | 0 | 44.046 |
| Larger random targets | Random, ≤1024 bytes | 16 | 1 | 11 | 0 | 33.860 |
| Total | | 64 | 18 | 36 | 0 | 166.032 |

115 generation rounds used 353,167 input/output tokens. Estimated cost from configured
provider pricing: $0.123236. Compile failures remain possible during generation and
are handled as repair feedback; zero worker errors does not mean every draft compiled.
These are changing server lease sets, not a controlled quality or throughput comparison.

## Fixes

- Recent telemetry reads now seek backward to the last 5,000 lines and cache parsed
  records until the file changes. Eight worker loops share the cache. History stays intact.
  Invalid JSON and non-object records are skipped. The real log contained an invalid row
  that previously broke summary parsing.
- Failed generated compilations now reach the next repair prompt even when a prior
  candidate scored 99%. The best candidate remains preserved for submission.
- AI-generated compiler, language, flags, and library/archive directives are removed
  before compilation. Manual source recipes retain their existing behavior.
- Exact instruction bytes with incorrect referenced data now report a referenced-data
  mismatch, with `exact=false` and `code_exact=true`, while retaining the 99% score.

## Measurement and validation

On the 583.75 MB local telemetry log, a full-history read took 1.3602 seconds;
the tail reader took 0.1288 seconds, and cached reads averaged 0.000018 seconds.
Both returned the same 4,999 valid records from the latest 5,000 lines.
This measures telemetry reading, not total worker speed.

`python -m pytest tests -q`: 208 passed, one existing Python `msilib` deprecation warning.
`node tests/test_gui_frontend.js`: passed. `git diff --check`: passed.
Four new regressions cover threaded cache reuse, append/replacement/corrupt telemetry,
compile-error feedback, generated directives, and referenced-data diagnosis.

Reproduce bounded live profiling with:

```powershell
python benchmarks/live_worker.py --jobs 16 --order random --max-size 1024
python benchmarks/telemetry_read.py
```

The live runner requires existing cloud consent, a DeepSeek key, and configured pricing.
It submits real improvements. Logs and isolated profiling JSON live in
`work/worker-review/live-worker-*-20261009.*`; telemetry timing is saved in
`work/worker-review/telemetry-benchmark.json`.
