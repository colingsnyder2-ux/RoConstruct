# Evidence-guided repair results

Implementation is opt-in. Normal worker behavior stays unchanged unless
`roc worker --guided-mutations` (or benchmark `provider_options["guided_mutations"]`)
is enabled.

## Added

- `roc.match.diagnose` classifies likely immediate/constant, argument-order,
  branch-condition, calling-convention, register-allocation,
  stack-layout, instruction-selection, missing/extra-instruction, code-size,
  or unknown mismatches. Classifications remain hypotheses unless directly
  supported by decoded evidence.
- `roc.mutate.guided_variants` uses bounded evidence-backed edits for immediate
  literals, reversed calls, branch conditions, signedness (`shr`→`sar`), stack
  padding deltas, known Interlocked spelling, and return cleanup/calling
  convention. Guided mode tries these first, then keeps
  the existing bounded mutators as fallback. Exact match stops immediately.
- Mutation telemetry records category, score, exact result, compile time, and
  exact conversions. `roc.metrics.summarize_runs` reports category totals and
  conversion counts.
- `benchmarks/repairs.py` replays identical saved compilable candidates through
  existing and guided arms. It makes no model calls and submits nothing. It
  alternates arm order, records corpus fingerprint, and reports size buckets,
  attempts, runtime, conversions, and cost (if generation pricing is known).

## Real replay

Command:

```text
python benchmarks/repairs.py --corpus work/benchmark-hidden.json --model deepseek:deepseek-flash
```

Run `repair-paired-hybrid-v2-20261008`: 101 identical candidate sources, 8
client versions, 19 tiny / 40 medium / 42 large.

| arm | exact conversions | attempts | mutation time | total replay |
| --- | ---: | ---: | ---: | ---: |
| existing | 4 | 226 | 13.1s | 18.4s |
| guided-first + fallback | 5 | 227 | 21.0s | 26.5s |

Existing conversions: four medium `unsigned int`→`int` fixes. Guided added one
medium calling-convention fix (`ret 8`→`ret`) while retaining those four.
No tiny or large conversions. No LLM tokens were spent. Generation cost was
unknown because saved candidate rows lacked complete pricing telemetry.

This is a paired repair replay over previously generated candidates, not a new
untouched generation holdout. It proves deterministic conversions and bounded
overhead for this sample; it does not prove broad match-rate improvement.

## Fresh final validation

Frozen corpus: `benchmarks/repair-holdout-fresh-20261008.json`; 18 targets,
three client versions, six tiny/six medium/six large. Every target had no prior
worker job before corpus freeze. One direct DeepSeek generation arm produced
18/18 compilable candidates, 3/18 exact, 112,887 total tokens, and about
$0.0439 estimated generation cost. The 15 non-exact candidates were replayed
through both repair arms:

| arm | candidates | conversions | attempts | mutation time | replay time |
| --- | ---: | ---: | ---: | ---: | ---: |
| existing | 15 | 0 | 33 | 1.99s | 2.69s |
| guided-first + fallback | 15 | 0 | 35 | 1.27s | 1.98s |

No fresh candidate became exact through either repair arm. This is strong
negative evidence against claiming broad repair gain; guided mode remains
opt-in and useful mainly where decoded mismatch evidence is high-confidence.

## Verification

Focused repair/diagnostic tests: 4 passed. Full `tests/test_roc.py`: **64
passed**. The freshness test now matches current model-specific semantics in
the existing unstaged optimizer edit.

Still unsupported as automatic source edits: arbitrary raw byte substitutions,
register allocation, and stack layout without a unique padding declaration.
Intrinsic/call handling is limited to known Interlocked spelling; generic calls
remain diagnostic hypotheses until a real compiler pattern justifies a bounded
mutation.
