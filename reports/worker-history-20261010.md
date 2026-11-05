# Worker history experiment — 2026-10-10

Client: August 19, 2007 (`2007-08`), registered VS2005 build 50727,
`/O2 /GS /EHsc /MD`. Model: `deepseek:deepseek-flash`, thinking disabled,
2048 output tokens, three rounds, seed 42. Local compiler/data verification;
no submissions or recovered-source replacements. Seed does not guarantee
identical provider outputs.

## Accepted change

Cloud budget reservation previously counted only the latest prompt, omitting
target facts and previous exchanges transmitted with repair requests. It now
counts the complete bounded conversation, conservatively using UTF-8 bytes
plus message framing. Measured usage still refunds unused reservations.
Regression covers token and dollar rejection before any HTTP request.

## Rejected change

Dropping tail exchanges retains the first target prompt and current repair
source/diff. It saved input tokens but did not generalize. Worker history
defaults remain unchanged.

| Corpus | Control | Compact history |
| --- | --- | --- |
| Initial nine targets, two repeats: exact | 4/18 | 2/18 |
| Initial mean byte-match score | 57.56% | 60.39% |
| Initial input tokens | 172,034 | 141,291 |
| Initial targets >48 bytes: exact | 1/12 | 2/12 |
| Initial targets >48 bytes: mean score | 38.00% | 48.75% |
| Fresh six targets >48 bytes: exact | 0/6 | 0/6 |
| Fresh mean score | 71.33% | 67.00% |
| Fresh input tokens | 54,311 | 41,573 |

All six initial exact candidate files were independently recompiled in a
fresh Python process and remained 100%, including referenced-data checks.
These benchmark exacts are not new recovered functions. Fresh targets came
from an already-solved source-hidden corpus and cover only a few units.

## Budget and reproduction

Both arms/repeats shared one CloudBudget per invocation: initial cap $0.75,
fresh cap $0.50, maximum combined reservation limits $1.25 against the user's
$3 total authorization. Total estimated usage was $0.1693719: initial
$0.1269351 plus fresh $0.0424368. Estimates use configured peak prices and
do not discount cached input; they are not provider invoices.

```text
python benchmarks/worker_history.py --manifest benchmarks/worker-history-2007-08.json --session history-initial-UNIQUE --allow-cloud --max-cloud-cost 0.75
python benchmarks/worker_history.py --manifest benchmarks/worker-history-holdout-2007-08.json --session history-fresh-UNIQUE --repeats 1 --allow-cloud --max-cloud-cost 0.50
```

Runner compares the final selective (>48 bytes) policy. Original initial
experiment applied compact history to all sizes; read its report for those
tiny-target regressions. Reports and candidates remain in ignored
`work/worker-history-20261010/` and `work/worker-history-holdout-20261010/`.
Initial report was recovered from session telemetry after the original
summary reader encountered an unrelated malformed historical metrics line;
the reusable runner now writes isolated metrics and reads valid records.
