# Worker review — 2026-10-09

Automatic is available in the dashboard, terminal setup (choice 6), and
`roc worker --preset automatic`. The dashboard keeps worker count, rounds,
output tokens, maximum bytes, order, strategy, reasoning, hints, targeting and
cloud budgets inside Advanced controls. Selecting Automatic fills defaults;
editing individual controls overrides them.

Policy: DeepSeek uses eight workers, other cloud providers four; local 7B
models use two and larger local models one. Source-only auto runs use one.
DeepSeek gets two generation rounds; other models get two for targets up to
48 bytes and four otherwise. Automatic output caps are 1,024 tokens for leaf
targets up to 64 bytes and 2,048 otherwise. Target ceiling is 512 bytes, order
is best-evidence auto, strategy remains direct, and Rev.ng is off. DeepSeek
automatic reasoning remains disabled. Explicit round/output/order/worker/size
arguments override the preset. The automatic CLI preset keeps small targets
on the chosen cloud model; an explicit cloud-min-size can request fallback.

Fixed-prompt DeepSeek smoke test: eight requests each at concurrency 1, 4 and
8, then reversed order. All 48 replies were valid. Serial batches took
6.601/5.904 seconds, four-way 1.708/1.931, eight-way 1.027/0.912. This supports
eight-way request overlap for this provider, not a universal mining speedup.
Reproduce: `python benchmarks/concurrency.py --requests 8 --limits 1 4 8`.

Initial source-hidden strategy check used the existing frozen twelve-target
manifest across four clients, two rounds, 2,048 output tokens, thinking disabled
and seed 42. Auto strategy reached 2/12 exact versus direct 3/12. Automatic
therefore keeps direct; the explicit experimental auto strategy remains offered.
Sessions: `worker-auto-review-20261009-before` and
`worker-auto-review-20261009-direct`.

Paired automatic-policy comparison used the same manifest, two draws per
function and arm, reversing arm order in the second repeat. Both arms used
eight slots and direct strategy. Control used two rounds, 2,048 output tokens
and full source hints. Automatic used production round/output policies and
the existing DeepSeek auto source-hint cutoff at 128 bytes.

| Arm | Jobs | Exact | Compiling jobs | Total tokens | Estimated generation cost |
| --- | ---: | ---: | ---: | ---: | ---: |
| Automatic | 24 | 5 | 22 | 121,393 | $0.05360 |
| Control | 24 | 6 | 23 | 118,293 | $0.05144 |

Automatic batch times: 13.781/12.672 seconds; control: 11.422/11.219.
No failures escaped the benchmark, but not every target produced compiling
source. This sample does not demonstrate improved exact-match quality, cost
or latency. Repeated draws are correlated within twelve targets, and seed
does not eliminate provider variation. This manifest had previous experiments;
do not describe these as newly unseen targets. Costs are locally configured
estimates, not invoices. No mining server submissions occurred.

Sessions: `worker-policy-review-20261009-complete-{automatic,control}-r{1,2}`.
Reproduce: `python benchmarks/worker_auto.py
benchmarks/holdout-fresh-auto12-20261009.json --allow-cloud --session UNIQUE`.
The runner records manifest hashes and shares request/token/cost bounds.

Regression fixes: compact summaries now finish for two/three workers, verbose
parallel workers avoid calling a nonexistent logger finish method, terminal
auto rounds are forwarded rather than silently dropped, signed launches honor
saved output/strategy/thinking choices, GUI accepts auto values, overview counts
avoid concatenating the auto string, and cloud budget rejection releases the
lease and stops the session. Token/cost caps also stop GUI workers.
Signed launches retain saved Rev.ng choices. Automatic generation preserves
other cloud providers' reasoning defaults for larger functions, while still
disabling DeepSeek reasoning and respecting explicit thinking overrides.

Tests cover automatic option validation, CLI overrides, launcher forwarding,
live control snapshots, budget rejection, compact logging and frontend auto
serialization/control placement. A browser preview verified the selected
Automatic mode and expandable Advanced controls.
