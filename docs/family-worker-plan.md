# Family-guided worker plan

## Objective

Raise candidate quality before repair. Repeated functions often share exact
opcode shape, so one verified source can teach siblings their compact C++ form.

## Shipped now

- `roc/families.py` groups by function size plus opcode sequence.
- `benchmarks/segment_families.py` emits deterministic family manifests.
- `benchmarks/family_replay.py` compares direct vs verified sibling exemplars.
- Worker flag `--family-exemplars` fetches only strict same-shape verified sources.
- Prompt labels exemplar as structural evidence, limits it to one source, and
  forbids unrelated class expansion or assembly dumps.
- Family mode is now default-on for worker launches; flag remains accepted for
  backward-compatible launcher configs.

## Evidence

On unseen `2007-08/seg_00770000` siblings, DeepSeek direct scored 49/68 exact;
family exemplar scored 68/68, with 40% fewer tokens/cost. A 2008-06 holdout
also improved 22/28 → 28/28, with 25% fewer tokens/cost. Strong evidence, but
still wrapper-heavy sections and one model.

## Next gates

1. Run paired family-vs-direct holdouts on 2008 and a fresh client.
2. Promote default only if exact matches improve and cost/exact does not worsen.
3. Add a verified exemplar index keyed by strict family fingerprint when server
   can store opcode fingerprints; never fall back to unrelated examples in mode.
4. Add deterministic thunk/wrapper propagation only where compiler verification
   proves byte equality; reuse `roc/auto.py`, do not duplicate repair logic.
5. Track exact, compile, tokens, cost/exact, and family coverage separately.

## Usage

```text
python roc.py worker --model deepseek:deepseek-flash --allow-cloud
```

Launcher/signed worker can use the same `--family-exemplars` option.
