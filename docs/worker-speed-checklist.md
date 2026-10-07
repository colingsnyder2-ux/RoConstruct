# Worker speed goal

Goal: increase functions/hour and reduce GPU/CPU time without lowering match quality.

## Baseline

- [x] Keep model/source/compile telemetry per job.
- [x] Preserve current best score and source on every retry.
- [x] Keep benchmark resumable for before/after comparison.
- [x] Record a fixed baseline from the hidden corpus (`work/benchmark-baseline.json`).

## Safe optimizations

- [x] Reuse Ollama context between repair rounds.
- [x] Skip Rev.ng for tiny/simple functions.
- [x] Cache source hints, compiler environments, and compile failures.
- [x] Bound worker concurrency with `roc worker --workers N`.
- [x] Add conservative model-aware worker count with `--workers auto`.
- [x] Avoid duplicate source/index lookups across retries/process workers (bounded prompt-hint cache).
- [x] Batch compatible compile checks with isolated namespaces (no cross-target collisions).

## Quality guardrails

- [x] Compare score gain and match rate from the sampled benchmark records.
- [ ] Never trade a 100% match for lower latency.
- [ ] Keep failed attempts and quarantine rules intact.
- [x] Run targeted tests plus a sampled benchmark after changes.

## Finish gate

- [x] Update README with speed controls and measured baseline.
- [ ] Commit speed changes separately.
