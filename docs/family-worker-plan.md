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
- Worker registers exact size/opcode fingerprints with server; strict family
  lookup uses fingerprint plus same-client verified source.
- Worker tries address-literal propagation from verified exemplar before LLM;
  equal-literal-count and cl.exe score gates reject unsafe rewrites.
- Family mode is now default-on for worker launches; flag remains accepted for
  backward-compatible launcher configs.

## Evidence

On unseen `2007-08/seg_00770000` siblings, DeepSeek direct scored 49/68 exact;
family exemplar scored 68/68, with 40% fewer tokens/cost. A 2008-06 holdout
also improved 22/28 → 28/28, with 25% fewer tokens/cost. Strong evidence, but
still wrapper-heavy sections and one model.

Additional paired holdouts: 2009-06 improved 12/15 → 15/15; 2010-06 improved
10/12 → 12/12. All compiled. Four client versions now support default-on mode,
though random whole-client validation remains.

Propagation replay produced 32 exact conversions on 2008-06 and 37 on 2009-06;
2007-08 and 2010-06 had no safe literal rewrites. This validates fast-path
value, not universal family coverage.

## Next gates

1. Run paired family-vs-direct holdouts on 2008 and a fresh client.
2. Promote default only if exact matches improve and cost/exact does not worsen.
3. Measure propagation conversion rate on fresh worker jobs; current replay is
   positive, but continue monitoring compile cost.
4. Track exact, compile, tokens, cost/exact, family coverage, and propagation
   conversions separately.

## Usage

```text
python roc.py worker --model deepseek:deepseek-flash --allow-cloud
```

Launcher/signed worker can use the same `--family-exemplars` option.
