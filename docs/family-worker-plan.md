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
- `benchmarks/register_families.py` bulk-preseeds fingerprints before mining;
  2008-06 (42,213), 2009-06 (47,078), and 2010-06 (59,084) registered.
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

Second-section check, 2008-06 `seg_00800000`: direct and exemplar both 7/7
exact; exemplar used 13.5% fewer tokens/cost.

Fixed-seed randomized sibling checks improved 2008 `18/19 → 19/19` and 2009
`8/15 → 15/15`, while reducing tokens/cost 21% and 40%.

Fresh 2010 holdout (12 previously unused siblings, DB-backed verified
exemplars) improved direct `8/12 → 12/12`; exemplar mode used 15,853 → 11,826
tokens and estimated cost `$0.00536 → $0.00406`.

Fresh 2009 holdout (16 siblings) held exact rate at `10/16 → 10/16`, but
exemplar guidance cut tokens `27,303 → 10,105` and cost `$0.00931 → $0.00352`.
This is a cost/reuse win, not an exact-rate win; promotion must track both.

Other-section check, 2009 `seg_00580000` (4 siblings), improved exacts
`1/4 → 3/4`; tokens were nearly flat (`8,931 → 9,419`) and cost rose
`$0.00324 → $0.00414`. Family guidance can improve exacts outside main
sections, but needs cost-aware routing.

Propagation replay produced 32 exact conversions on 2008-06 and 37 on 2009-06;
2007-08 and 2010-06 had no safe literal rewrites. This validates fast-path
value, not universal family coverage.

Fresh full-section compiler-gated replays using DB-backed exact exemplars found
45 exact zero-LLM conversions on 2008 `seg_007f0000` (547 siblings) and 35 on
2009 `seg_00890000` (1,136 siblings). Recursive mode stayed bounded; no
non-exact candidate became trusted.

2010 `seg_009e0000` replay found 8 exact zero-LLM conversions across 948
siblings. Propagation is therefore useful across all tested client versions,
but coverage varies sharply by family and section.

## Next gates

1. Run random whole-client holdout, not only repeated-family targets.
2. Promote default only if exact matches improve and cost/exact does not worsen.
3. Measure propagation conversion rate on fresh worker jobs; current replay is
   positive, but continue monitoring compile cost.
4. Track exact, compile, tokens, cost/exact, family coverage, and propagation
   conversions separately.

## Whole-section snapshot

`python benchmarks/family_coverage.py --client 2007-08 --unit seg_00770000`
reports current corpus state without changing scores. Current local snapshot:
1,354 functions; 1,062 exact; 292 unmatched; 51 detected families; 1,319
family members; 42 families contain at least one verified source; 1,150
members sit inside those verified families (84.93% section coverage). This is
historical coverage, not a claim that propagation solved all 1,150 members.
The remaining proof is a fresh, fixed-manifest hybrid run separating existing
matches, deterministic conversions, exemplar-guided LLM results, and normal
generation.

## Usage

```text
python roc.py worker --model deepseek:deepseek-flash --allow-cloud
```

Optional family-local leasing keeps one worker on a strict fingerprint until
no eligible siblings remain, then rotates normally:

```text
python roc.py worker --lease-mode family --model deepseek:deepseek-flash --allow-cloud
```

Server still verifies each lease independently; family mode changes scheduling
only, never trust or exact-match rules.

Launcher/signed worker can use the same `--family-exemplars` option.
