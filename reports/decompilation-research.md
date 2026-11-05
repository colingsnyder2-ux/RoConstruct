# Matching-decompilation research notes

Research date: 2026-10-08. Claims below are scoped to the cited papers and
repositories; they are not evidence of a RoConstruct improvement.

| Work | Verified method | RoConstruct fit |
| --- | --- | --- |
| Decaf (2026 preprint) | Sample candidates, compile/execute, then rerank with byte-distance and neural feedback. Its artifact ships 1.3B/6.7B/22B generators and 32B rerankers. | Existing compiler/masked-byte evaluator and top-k cover a small part. Missing: independent diverse sampling, candidate reranking by normalized mismatch, and execution oracle. Do not import its models/data (>200 GB) before an MSVC/x86 pilot. |
| LLM4Decompile (EMNLP 2024) | End model maps asm to C; Ref model refines Ghidra pseudocode. V2 was trained on Ghidra pseudocode. | Pseudocode-first is high value. Released models target Linux x86_64/GCC, not historical 32-bit MSVC; direct use would not be a valid comparison. |
| SLaDe (CGO 2024) | 200M seq2seq model, assembly-aware tokenizer, no-dropout training, plus type inference. | Model/training ideas need retraining. Transferable now: use deterministic type facts in prompts, keep model-independent facts compact. |
| SK2Decompile (2025 preprint) | Two-stage skeleton IR then identifier skin; separate objectives keep structure independent from naming. | High-value direction. RoConstruct has binary facts but not a real CFG/typed skeleton. Names have little byte-match value; prioritize skeleton/types. |
| Retypd (PLDI 2016) | Constraint solver for recursive, polymorphic, subtyping-aware machine-code types; accepts weak program representations. | Full integration is costly/GPL-3.0. Low-cost subset: evidence-tagged `this`/stack/pointer/calling-convention constraints only; never invent layouts. |
| DIRTY (USENIX Security 2022) | Transformer postprocesses decompiler AST/context to predict names/types; DIRT has 75K+ programs/1M functions. | No MSVC32 validation. Type prediction may help only after reliable pseudocode; variable names do not affect byte equality. |
| TuneRDEC (ICLR 2026 under review) | AST-weighted fine-tuning then compiler/test feedback with stronger-model escalation. | Current repair/feedback overlaps. AST-weighting and test oracle need training/harnesses; no evidence yet for adding a fallback model. |
| Echo (2026 preprint) | Trusted back-translation: generate source+config, recompile, normalized edit distance, rule/neural/reasoning refinement. | Existing fixed-config compile/diff/mutations overlap. Missing candidate diversity and normalized CFG-aware ranking. Config search has low value while per-client flags are known. |

Availability: Decaf and LLM4Decompile publish artifacts/code. Retypd and DIRTY publish
implementations but introduce GPL-3.0 and legacy PyTorch/IDA/Ghidra integration concerns,
respectively. SK2Decompile is available inside the LLM4Decompile repository. No usable public
implementation was found for TuneRDEC or Echo; treat their claims as preprint evidence, not a
drop-in dependency. SLaDe's paper is published, but no maintained upstream implementation was
identified during this audit.

## Current-gap ranking

1. **High / low cost:** reset model conversation after rejected inline asm; preserve
   reject telemetry. Reusing a response context after an asm dump encourages a repeat.
2. **High / medium cost:** compact, deterministic CFG/type skeleton. Include entry,
   block labels/edges, branch kind, stack slots, ECX/`ret N` calling evidence, calls,
   globals, constants, and confidence. Existing `binary_facts()` already supplies part.
3. **Medium / low cost:** retrieval rank by target strings, unit, call/import overlap and
   CFG shape; feed a bounded method/signature, not broad class text. Mark later-source
   evidence speculative.
4. **Medium / medium cost:** independent diverse samples plus compile/diff reranking.
   Do not use fuzzy score as proof; exact masked equality remains acceptance criterion.
5. **Future / high cost:** Ghidra P-code/pseudocode first pass and a historical-MSVC
   dataset pilot. Ghidra's SLEIGH/P-code is a portable IR, but must be validated against
   this toolchain before model work.

## Historical-MSVC dataset: pilot gate

Do not train yet. First compile a legally usable, source-project-disjoint pilot with
the already verified VS2005/VS2008 configurations. For every function retain: source
span, preprocessed translation unit, compiler build/flags, object bytes/relocations,
function boundary, disassembly, and optional Ghidra pseudocode. Reject pairs where
inlining or COMDAT folding breaks the source-to-object correspondence. Split by
project, never function, then measure the installed 7B/14B models against held-out
functions before estimating fine-tuning cost. This directly tests whether MSVC-specific
pairs reduce inline-asm and compile failures; generic GCC/x86_64 datasets cannot prove it.

An installed `llm4decompile-6.7b` checkpoint is worth a *small, separate* pilot only.
Its published scope is Linux x86_64/GCC, so it must not be merged into the worker default
or compared as an MSVC-capable system unless it produces real `cl.exe` conversions on the
frozen corpus.

## Sources

- https://arxiv.org/abs/2605.11501
- https://github.com/AlexShypula/decaf
- https://arxiv.org/abs/2403.05286
- https://github.com/albertan017/LLM4Decompile
- https://arxiv.org/abs/2305.12520
- https://arxiv.org/abs/2509.22114
- https://arxiv.org/abs/1603.05495
- https://github.com/GrammaTech/retypd
- https://www.usenix.org/conference/usenixsecurity22/presentation/chen-qibin
- https://arxiv.org/abs/2609.18706
- https://openreview.net/forum?id=m4MhSqtaPC
- https://learn.microsoft.com/en-us/cpp/cpp/thiscall
- https://ghidra.re/ghidra_docs/languages/index.html
