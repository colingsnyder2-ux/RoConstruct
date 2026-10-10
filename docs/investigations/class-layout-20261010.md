# Class layout recovery pilot

Run: `python -X utf8 -m benchmarks.class_layout --limit 160`.

Frozen input: 129 eligible donor/target pairs from the propagation log, randomized
with seed 20261010. The available input was predominantly 2007-03 because the
concurrent propagation run was still traversing its first client. 2009-12 is
excluded as both a target and donor. No paid model calls.

Method: independently verify donor source, rebuild the failed propagation
candidate, compare compiled instruction shapes and infer consistent memory
displacement changes. Try explicit byte-offset rewrites and uniform padding
changes. Verified mappings can inform sibling methods only for the same target
and donor client/class combination; anonymous segments are excluded from reuse.
Every accepted candidate passes normal code and referenced-data verification,
then server verification. This recovers offsets used by methods, not complete
class layouts or inheritance.

Results: 129 pair records, 30 skipped because already exact on the server,
14 new server-acknowledged exact functions, zero outer errors. Of the 14 wins,
11 used field-size displacement maps; three also involved absolute address
corrections and must not be attributed to class layout recovery. The initial
run exposed this distinction; the runner now rejects displacement maps with
values at or above 0x10000 and excludes those historical maps from class reuse.
No gain is attributed to a concurrent worker or to locally exact baselines.

Evidence: `work/match-campaign-20261010/class-layout-manifest.json`,
`class-layout.jsonl`, `class-layout-trials/`, and `candidates/class-layout/`.
Trial sources and rejected outcomes are retained. Two tests cover consistent
field correspondence, conflicting mappings, stack arguments, absolute addresses,
padding changes and simultaneous offset replacement.

Next: refresh the frozen input after propagation reaches other clients; measure
unique exact gains from method-inferred versus previously verified class maps.
The current sample does not establish broad class-layout recovery performance.
