# Control-flow reconstruction research

## Existing implementation audit

RoConstruct already had bounded CFG extraction in `roc/draft.py`:
`cfg_outline`, `reconstruction_outline`, `structure_ir`, and `facts_from_asm`.
`roc/match.py` already decodes x86 with Capstone and provides byte-level
diagnostics. `roc/mutate.py` already performs compiler-backed, evidence-gated
mutations. Rebuilding a decompiler or adding a large IR would duplicate these
facilities and increase prompt/runtime cost.

## Source review

| Project | Relevant implementation | License / decision |
| --- | --- | --- |
| [angr](https://github.com/angr/angr) | CFG recovery and decompiler optimization passes; [CrossJumpReverter](https://docs.angr.io/en/v10.0.0/api/angr.analyses.decompiler.optimization_passes.cross_jump_reverter.html). SAILR integration tracks cross-jump reversal, eager returns, constant depropagation, and block deduplication. | BSD-2-Clause. Do not copy code; clean-room ideas only. |
| [SAILR evaluation](https://github.com/mahaloz/sailr-eval) | Measures gotos, CFG-edits, booleans, calls, and normalized decompiler quality on fixed source/binary pairs. | BSD-2-Clause. Useful methodology, not a Roblox byte-match oracle. |
| [Miasm](https://github.com/cea-sec/miasm) | x86 lifter, IR, expression simplification, SSA/data-flow, symbolic execution. | GPLv2. No code integration; concepts support optional offline research. |
| [RetDec](https://github.com/avast/retdec) | PE/x86 loader, CFG/call-graph statistics, LLVM-based decompilation and type recovery. | MIT core with third-party notices; Keystone exception/GPL notice requires dependency review. Optional external tool only. |
| [rev.ng](https://github.com/revng/revng) | QEMU/LLVM lifting, CFG artifacts, type model, structured C emission. | Project is GPLv2 as a whole because of QEMU; individual files MIT. No vendoring. |
| [Reko](https://github.com/uxmal/reko/wiki/Design) | RTL, data-flow/type inference, expression simplification, if/while/switch structuring. | GPL-2.0. External comparison only. |
| [Capstone](https://github.com/capstone-engine/capstone) | x86 instruction decoding and operand metadata. | BSD-family. Already used by `roc.match`; no replacement needed. |

## Selection

Selected clean-room subset: block boundaries, typed branch/fallthrough edges,
reachability, iterative dominators, loop back-edges/headers, and return blocks.
These are reliable machine facts and small enough for a prompt. Rejected for
runtime integration: full SAILR deoptimization, symbolic execution, LLVM
lifting, RTTI/type synthesis, and external decompiler output. They add large
dependencies or guessed source structure without evidence they reproduce old
MSVC bytes.

## Implementation

`roc/draft.py` now exposes `cfg_facts(asm)` and adds bounded `cfg_facts` to
`structure_ir`. Existing `cfg_outline` output remains compatible. The prompt
still makes this opt-in through structured generation; direct generation is
unchanged. Facts never force an ambiguous CFG into an if/loop: they report
observed edges and dominance only.

## Benchmark evidence

Frozen manifest: `benchmarks/holdout-fresh-100-20261008.json` (100 unseen
targets, 8 clients, 33/33/34 tiny/medium/large).

| arm | exact | compilable | tokens | cost | runtime |
| --- | ---: | ---: | ---: | ---: | ---: |
| DeepSeek direct | 11/100 | 24/100 | 217,408 | $0.123552 | 332s |
| DeepSeek structured | 13/100 | 22/100 | 222,967 | $0.117594 | 282s |

Both arms matched only tiny functions. Structured gained +2 exact matches
(13 vs 11) at slightly fewer dollars but slightly more tokens. 24 jobs in the
structured arm hit the 250k token guard; those are failures, not zero-score
model outputs. This is promising but not enough to make structured default.
The 100-target runs completed before the new dominator fields were added, so
they validate existing structured mode, not a claimed post-change CFG gain.
The next controlled arm must use a fresh manifest or a clearly labeled tuning
set.

Post-change paired smoke holdout (`holdout-fresh-cfg12-20261009`, fingerprint
`8a16397896bc8c8d791fd1023beaa0d020fe0e678f352c8ec381d1e6a63b4fd9`) used the
same 12 unseen targets and one round per arm:

| arm | exact | compilable | tokens | cost | runtime |
| --- | ---: | ---: | ---: | ---: | ---: |
| direct | 1/12 | 10/12 | 20,751 | $0.008973 | 23.93s |
| structured + dominators | 0/12 | 9/12 | 27,541 | $0.011192 | 24.73s |

Repair replay converted 0/10 structured non-exact candidates. This small
paired result is a regression for the new CFG prompt fields, not evidence to
make them default. Keep them experimental and test on a larger fresh arm
before tuning the representation further.

Repair replay on the latest 52 compilable non-exact structured candidates:
existing arm 0 conversions; guided arm 2 calling-convention conversions,
including one 90–99% and one 75–89% candidate. Guided replay spent no LLM
tokens, 10.426s mutation time, and added 2 exact matches. Result supports
last-mile repair, but candidate selection/session isolation should be tightened
before claiming this as a paired arm result.

## Reproducible commands

```text
pytest -q tests/test_roc.py
python benchmarks/run_holdout.py benchmarks/holdout-fresh-100-20261008.json --model deepseek:deepseek-flash --rounds 1 --strategy direct --allow-cloud --max-cloud-requests 100 --max-cloud-tokens 250000 --max-cloud-cost 1.00
python benchmarks/run_holdout.py benchmarks/holdout-fresh-100-20261008.json --model deepseek:deepseek-flash --rounds 1 --strategy structured --allow-cloud --max-cloud-requests 100 --max-cloud-tokens 250000 --max-cloud-cost 1.00
python benchmarks/repairs.py --corpus benchmarks/holdout-fresh-100-20261008.json --model deepseek:deepseek-flash
```

## Conclusion

CFG facts are worth keeping as compact structured evidence. Full external
decompiler integration is not justified yet. Next bottleneck is first-pass
generation on medium/large functions and token truncation, not CFG readability.
