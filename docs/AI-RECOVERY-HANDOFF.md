# AI recovery handoff — continue from here

Paste the block at the bottom into a fresh RoConstruct agent. Everything it needs is
in this file plus `docs/AI-RECOVERY-PROMPT.md` and `docs/investigations/re-recovery-workflow.md`.

## Where we are (2026-10-10, end of run)

**8,727 server-verified exact submissions, 0 regressions, $0 cloud cost.**

| Item | Value |
|---|---|
| Template families solved and exhausted | 11 |
| Hand-solved functions | 12 |
| Client 2009-12 | never touched |
| Ledger | `work/re-pilot-20261010/attempts.jsonl` (8,727 rows) |
| Driver | `benchmarks/re_pilot.py` (`select`, `inspect`, `try`, `submit`, `creator`, `templates`) |
| Helpers | `work/re-pilot-20261010/{try.py,dump.py,asm.py,shapes.py,refresh_scores.py,backfill.py,submit_samples.py}` |

Server totals (session start → now):

| Client | Start | Now | Δ |
|---|---|---|---|
| 2007-03 | 8,138 | 8,139 | +1 |
| 2007-08 | 10,147 | 10,452 | +305 |
| 2008-06 | 10,611 | 11,244 | +633 |
| 2009-06 | 9,384 | 10,870 | +1,486 |
| 2010-06 | 10,721 | 12,647 | +1,926 |
| 2011-06 | 9,066 | 11,617 | +2,551 |
| 2012-06 | 10,296 | 11,837 | +1,541 |

Exhausted families (0 candidates left, do not re-run):
guard-static reference (3,767), two-call wrapper (959), global init (675), type factory
(534), three-call init (503), reg_wrapper (351), reg_wrapper4 (265), lock-free pop (250),
ctor_atexit (226), static_reg (221), creator guard-static (966).

## Open leads, ranked

1. **499× family** `2010-06 009da850` (55 B) — best candidate `work/re-pilot-20261010/t9a.cpp`
   scores **82%**. Target vs mine:
   ```text
   target: push ecx ; push A ; push B ; mov [C],D ; call F1 ; add esp,8 ; call F2 ;
           mov [esp],eax ; lea eax,[esp] ; push eax ; call F3 ; mov ecx,eax ; call F4 ;
           pop ecx ; ret
   mine:   push ecx ; push A ; push B ; mov [C],D ; call F1 ; call F2 ;
           mov [esp+8],eax ; lea eax,[esp+8] ; push eax ; call F3 ; add esp,0xc ;
           mov ecx,eax ; call F4 ; ...
   ```
   Two deltas only: (a) the 4-byte local must live **at [esp] via the pushed `ecx`
   reservation** (MSVC stack-temp slot), not in the frame; (b) the `add esp,8` cleanup of
   F1's two cdecl args must sit immediately after F1 instead of being merged into F3's.
   Try: a temporary whose address escapes (`void* tmp = make(); init(&tmp);`) with F1
   declared plain `extern "C"` cdecl, or a `&local` on a *temporary*.
2. **442× family** `2010-06 009c6290` (57 B) — 9-arg call with mixed address/immediate
   pushes plus `mov ecx, imm` receiver, then a 1-arg SEH-wrapper call. Same family as
   `reg_wrapper` but with more args.
3. **344× family** `2010-06 009c2ae0` (73 B) — the sret variant of lead 1 with extra
   stores (`mov [eax], N`, `mov [N], N`).
4. **236× family** `2010-06 0041ade0` (33 B, `CXTPReportGroupRow_Batch`) — candidate
   `work/re-pilot-20261010/t8a.cpp` scores 68%; needs the `push ecx` slot reservation +
   `pop ecx` epilogue (callee is cdecl-with-ecx `this`, caller cleans by popping).
5. **Creator-constructor family** `2011-06 00635e40` (110 B, 373 instances) — 87% with
   `work/re-pilot-20261010/ctor5.cpp`; needs two extra callee-saved pushes (`ebx`,`edi`)
   and `mov [ebp-0x10], esp`.
6. Fresh-seed hand cycles: `py -3.12 -m benchmarks.re_pilot select --seed <new> --out work/re-run-N`.

## Reproduce the loop

```text
py -3.12 work/re-pilot-20261010/refresh_scores.py          # sync local scores from server.db
py -3.12 work/re-pilot-20261010/shapes.py --top 8          # find the next big shape
py -3.12 -m benchmarks.re_pilot inspect --client C --addr A
py -3.12 work/re-pilot-20261010/try.py CLIENT ADDR cand.cpp
py -3.12 -m benchmarks.re_pilot templates --clients <list> --submit --limit 5000 --user colin
```

---

## PROMPT FOR THE NEXT AGENT

```text
You continue a RoConstruct matching-decompilation campaign. Read
docs/AI-RECOVERY-PROMPT.md and docs/investigations/re-recovery-workflow.md first, then
docs/AI-RECOVERY-HANDOFF.md for the current position.

HARD RULES
- Client 2009-12 is banned: never mine, test, submit, count or propagate it.
- A function counts only when the group server re-verifies it byte-identical.
- Never invent fields, offsets or ABI behaviour; every claim comes from a compiled
  experiment or repeated binary evidence.
- Preserve every partial and rejected hypothesis with its score and reason.
- Submit only when the local score beats the stored server score (0 if none).
- Commit only the files you create for this task; never touch another worker's edits.

WORKFLOW
1. py -3.12 work/re-pilot-20261010/refresh_scores.py
2. py -3.12 work/re-pilot-20261010/shapes.py --top 8  (repeat after each family is done)
3. Pick the biggest unresolved shape, dump the exemplar, reconstruct a minimal candidate,
   compile with try.py, iterate one change at a time (max 3 hypotheses, 3 candidates,
   2 refinement rounds per target).
4. When a candidate hits 100, add it to TEMPLATE_FAMILIES in benchmarks/re_pilot.py
   (string template or a callable generator for variable immediates), then run
   py -3.12 -m benchmarks.re_pilot templates --clients <all but 2009-12> --submit --limit 5000 --user colin
5. Record every attempt in work/re-pilot-20261010/attempts.jsonl and every reusable
   discovery in discoveries.jsonl.
6. Report units processed, functions attempted, exacts, partials, regressions, cost,
   unfinished targets and the next ranked experiment.

KNOWN TEMPLATES ALREADY EXHAUSTED (do not redo): guard-static reference, two-call wrapper,
global init, type factory, three-call init, reg_wrapper, reg_wrapper4, lock-free pop,
ctor_atexit, static_reg, creator guard-static. See TEMPLATE_FAMILIES in
benchmarks/re_pilot.py for their sources.

START WITH the ranked open leads in this file (499x sret family first). Then loop:
survey -> crack -> propagate -> report, until the human stops you.
```
