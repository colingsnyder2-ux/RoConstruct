# Recovery workflow runbook

Operational companion to `AI-RECOVERY-PROMPT.md`. Use the prompt for the agent
identity and rules; use this file for the mechanics, decision tree and scorecard.

## 0. Preflight (5 minutes)

```text
py -3.12 -m pytest -q tests                 # 269 pass; 1 fail == another worker's edits
py -3.12 roc.py status                      # server reachable? other workers active?
py -3.12 -m benchmarks.re_pilot status       # per-client match counts
```

If `tests/test_campaign_pilots.py::test_budget_survives_restart_and_failed_requests`
fails, `git stash` someone's `benchmarks/ai_representatives.py` only to confirm it is
not yours, then `git stash pop`. Never commit their file.

Pick an output dir, e.g. `work/re-run-<date>/`, and copy `try.py`, `dump.py`,
`asm.py` from `work/re-pilot-20261010/` into it (the driver writes there).

## 1. Selection

```text
py -3.12 -m benchmarks.re_pilot select --seed <seed> --out work/re-run-<date>
```

Mix: 2 high-reuse (>=90%), 1 random >=90% (seeded), 1 medium-match unit with the
highest average callers, 1 cross-family/library unit. 5 units x 3-5 functions.
Reject any unit where the only unresolved functions are already 100, already failed
twice, or are in 2009-12.

Good targets, in order: size <= 40 bytes; size <= 130 bytes; same-shape siblings that
are already exact; functions whose callers are exact (caller contract is known).

## 2. Evidence dump

```text
py -3.12 -m benchmarks.re_pilot inspect --client C --addr A --sibling-lines 24
```

Then, from Python, add: `row["callers"]`, `row["call_targets"]`, `row["strings"]`,
`row["virtual_slots"]`, `row["this_reads/writes"]`, `row["calling_convention"]`,
absolute-address disassembly, the exe bytes at every referenced data address, and the
server's stored source for the target. Save all of it into the attempt row.

Look for an exemplar: same normalized `shape` in the same client (exact siblings are
gold), then in other clients. If an exemplar is a library (`// roc-lib:`), the pinned
library source is in `tools/libs/` — read the real source; that is where the layout and
ABI facts come from.

## 3. Hypothesis loop (bounded)

| Observation | Hypothesis | Test |
|---|---|---|
| `mov ecx,[ecx+8]; test ecx,ecx; je` | pointer copied to a local before the null test (smart-pointer-like member) | copy to a local first |
| no SEH frame on your side | callee is `extern "C"` => MSVC thinks it cannot throw | declare C++ linkage |
| fast path is `mov eax,[slot]` | static bound to a **reference**, not an object | `static T& v = f()` |
| fast path is `mov eax,offset` | static object returned by reference | `static T v; return v;` |
| frame pointer missing | flags: try `/Oy-`, `/EHa`, `/GS` | vary flags only |
| vtable slot off by k | class has k extra virtuals (add virtuals to your class) | count and add |
| `call [IAT]` with `this` in ecx | MFC member function; find the ordinal's DLL | resolve the import thunk |
| 99% + "data differs" | literal/constant wrong; the message quotes the exe bytes | use the quoted bytes |
| `mov eax,[esp+N]; mov ecx,[esp+M]; call` | internal-linkage callee, ECX+EAX ABI | static + noinline helper |

One change per candidate. Record the score, the diff, and the rejection reason even for
a no-gain.

## 4. Compile / compare / refine

Local compile is free: `try.py` prints the score and the diff. `dump.py` prints your
own disassembly — always inspect it when the diff is confusing. Masked fields mean
names and addresses never matter; a *missing* reloc where the target has one still
fails. If the diff is only register allocation, change the expression form (local copy,
ternary, inlined helper, different flag), not the layout.

## 5. Submit / propagate

`re_pilot submit --client C --addr A --source <file> --user <you>` leases the target,
compiles locally, then uploads. Only runs when local >= stored. After an exact, extract
the template and re-run:

```text
py -3.12 -m benchmarks.re_pilot creator --clients 2009-06,2010-06,2011-06,2012-06
```

(or the equivalent template batch for the family you just cracked) and submit the
exact ones. Watch regression rate; two consecutive regressions stops the batch.

## 6. Scorecard (per run)

| Metric | Target |
|---|---|
| exacts gained | >= 2 (pilot success) |
| partials with a known next step | >= 5 |
| regressions | 0 |
| submissions / cap | <= 25 |
| cloud spend | 0 (deterministic + local compiler preferred) |
| new reusable discoveries | >= 3 |
| ungained hypotheses recorded | all, with reasons |

Stop conditions: budget warning, two consecutive no-gain rounds on the same target,
two consecutive propagation regressions, or any target already at 100.

## 7. Artifacts and commit

`work/re-run-<date>/attempts.jsonl` (one row per attempt, schema in the prompt),
`discoveries.jsonl`, `units.json`, candidates `C_ADDR.cpp`, and the helper scripts.
Commit only your own new files (driver + report). Never `git add -A`.

## 8. Reporting

Return the 12-item report from the prompt: units processed, functions attempted,
exacts, partials, propagated matches, reusable discoveries, regressions, failed
hypotheses, cost/requests, unfinished targets, next experiment ranked by expected
exacts, and exact artifact paths.
