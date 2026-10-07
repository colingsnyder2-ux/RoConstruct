# Worker speed goal

Goal: increase functions/hour and reduce GPU/CPU time without lowering match quality.

## Baseline

- [x] Keep model/source/compile telemetry per job.
- [x] Preserve current best score and source on every retry.
- [x] Keep benchmark resumable for before/after comparison.
- [ ] Record a fixed baseline from the hidden corpus.

## Safe optimizations

- [x] Reuse Ollama context between repair rounds.
- [x] Skip Rev.ng for tiny/simple functions.
- [x] Cache source hints, compiler environments, and compile failures.
- [x] Bound worker concurrency with `roc worker --workers N`.
- [ ] Add adaptive worker count from observed GPU memory/time.
- [x] Avoid duplicate source/index lookups across retries/process workers (bounded prompt-hint cache).
- [ ] Batch compatible compile checks without cross-target collisions.

## Quality guardrails

- [ ] Compare score gain and match rate before/after each optimization.
- [ ] Never trade a 100% match for lower latency.
- [ ] Keep failed attempts and quarantine rules intact.
- [ ] Run targeted tests plus a sampled benchmark after changes.

## Finish gate

- [ ] Update README with speed controls and measured results.
- [ ] Commit speed changes separately.
