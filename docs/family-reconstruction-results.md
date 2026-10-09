# Repeated function-family reconstruction

`seg_00770000` is a code-section name, not one class. In the 2007-08 client it
contains 1,062 functions, but opcode-only grouping found 38 repeated
size-and-shape families covering 1,041 members. The largest families were 322
10-byte jump thunks and 275 25-byte wrappers.

## Representative pass

One representative per repeated family was tested with DeepSeek Flash, two
rounds, auto routing, and thinking disabled:

- 38 representatives
- 11 exact
- 37 compilable
- 110,750 tokens
- $0.039767 estimated cost

## Sibling exemplar pass

The 11 exact representatives supplied verified C++ as family-specific prompt
examples to 25 previously unseen siblings. Baseline and exemplar arms used the
same sibling manifest. The exemplar arm initially hit its request cap after 19
jobs; the remaining six were retried with a fresh budget.

| arm | jobs | exact | compilable | tokens | cost |
| --- | ---: | ---: | ---: | ---: | ---: |
| direct baseline | 25 | 19 | 25 | 45,748 | $0.016025 |
| family exemplar | 25 | 25 | 25 | 25,923 | $0.009096 |

The family exemplar produced six additional exact matches, 43% fewer tokens,
and 43% lower estimated cost on this paired sibling sample. This is strong
evidence for repeated thunk/wrapper families, but it is still one client and
one section. Expand only after preserving strict same-client/compiler matching
and cl.exe verification.

The larger follow-up selected 68 additional unseen siblings from the same 11
verified families. Last-row-per-address paired results:

| arm | jobs | exact | compilable | tokens | cost |
| --- | ---: | ---: | ---: | ---: | ---: |
| direct baseline | 68 | 49 | 68 | 121,795 | $0.042863 |
| family exemplar | 68 | 68 | 68 | 72,967 | $0.025731 |

This is +19 exact matches, −40% tokens, and −40% cost. It strongly supports
family exemplars for this repeated section, but must not be generalized to
unrelated sections without another paired test.

## 2008-06 cross-client holdout

`seg_007f0000` produced 36 repeated families. Representative pass: 8/36
exact, 36/36 compilable, 105,304 tokens, $0.042758. On 28 unseen siblings:

| arm | jobs | exact | compilable | tokens | cost |
| --- | ---: | ---: | ---: | ---: | ---: |
| direct baseline | 28 | 22 | 28 | 39,655 | $0.014096 |
| family exemplar | 28 | 28 | 28 | 29,856 | $0.010596 |

Exemplar gain: +6 exact, −25% tokens/cost. Evidence now spans two clients, but
still covers repeated wrapper-heavy sections and one cloud model.

## Reproduction

```text
python benchmarks/segment_families.py --client 2007-08 --unit seg_00770000 --output benchmarks/families-2007-08-seg_00770000.json
python benchmarks/family_replay.py --client 2007-08 --unit seg_00770000 --representative-session families-2007-08-seg770000-auto-20261009 --families 5 --siblings 5 --output benchmarks/family-siblings-2007-08-seg770000.json
```

Benchmark injection remains explicit through `benchmark.run_local(...,
family_examples=...)`; production worker family mode is now default-on.
