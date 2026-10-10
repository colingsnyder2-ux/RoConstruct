# AI worker handoff

Read this first, then [experiment summary](EXPERIMENTS.md). Updated 2026-10-10.
Next work and validation gaps: [match-maximization audit](NEXT_EXPERIMENTS.md).
This is a Python/x86 matching project; use repository instructions for edits.

## Goal and acceptance

Recover real C++ that compiles with each registered client's historical MSVC.
Normal exactness means relocation-normalized instruction bytes **and referenced
data** pass `roc.match` verification. It is not a general semantic proof.
99% is partial; `code_exact=true` alone is insufficient. Never patch target bytes,
accept inline assembly as recovered source, or replace a better source with a
regression. Recompile stale scores before selecting or claiming gains.

## Where things live

| Path | Purpose |
| --- | --- |
| `roc.py`, `roc/` | CLI; analysis, compiler, scoring, repair, providers, server and GUI |
| `clients/clients.json`, `clients/sources.json` | Registered binaries and download provenance |
| `benchmarks/`, `tests/` | Reusable experiment runners, frozen manifests, regressions |
| `docs/repair-patterns.json` | Measured repair patterns used for evidence-based ranking |
| `docs/investigations/matching-findings.md` | Detailed chronological attempts, addresses, failures |
| `docs/archive/` | Historical reports/plans; evidence, not current instructions |
| `work/` | Ignored analysis, scores, telemetry, reports, checkpoints, candidate archives |
| `work/investigation/` | Local scratch scripts/output; see investigation README |
| `src/` | Ignored separate RoConstruct-findings checkout containing recovered source |
| `tools/` | Ignored historical compilers, libraries, optional research prototypes |

Website HTML/assets and progress JSON still live directly in `docs/`; they are
published artifacts. Keep them separate from research cleanup.

## Productive workflow

1. Check Git status and existing workers; preserve other edits. Run `python roc.py
   doctor` before diagnosing toolchain failures. Avoid duplicate servers on 8765.
2. Freeze client/address, source hash, compiler/flags, fresh score and mismatch
   diagnosis. Use `python roc.py classify CLIENT ADDR SOURCE` for evidence.
3. Search exact same-family/unit sources and known library recipes first. Try
   safe family propagation before model generation. Use scoped fingerprint pilots.
4. Route repair by evidence: ABI/receiver/return/data/layout/branch/register.
   Preserve best candidate and failed compilation feedback between rounds.
5. Compare fixed-manifest arms, then independently verify winners with normal
   `match.check_text` code/data checks before promotion. Server also verifies leases.
6. Record negative results. After two independent zero-gain shards, park that
   profile until source, toolchain, mismatch family or evidence changes.

Do not rerun historical commands blindly: some launch paid generation or submit
live sources. Use explicit bounded requests/tokens/cost and existing cloud consent.
Provider pricing estimates are not invoices; unknown pricing cannot enforce a
reliable dollar cap. Request/token guards still matter. No live run is required
for documentation work.

## Current worker behavior and pitfalls

- `--preset automatic`: direct strategy, auto rounds/output/workers/order, 512-byte
  ceiling, Rev.ng off. Explicit knobs override corresponding automatic defaults.
- Auto concurrency: DeepSeek 8, other cloud 4, local 7B 2, larger local 1;
  source-only 1. Auto output: 1024 for call-free targets <=64 bytes, otherwise 2048.
  CLI, launcher and GUI accept explicit output budgets 128–32768.
- DeepSeek automatic thinking is disabled: reasoning previously consumed the whole
  output budget without code. Bigger budgets alone did not solve this.
- Automatic mode is convenient, not a proven quality/cost improvement. Direct vs
  structured and hint choices remain workload-dependent; see paired results.
- Source-only and near-repair skip unrelated reference compilation. Localhost
  reconnect must remain local. Cooldown/provider failure is not a model-quality loss.
- Wrong-address headers, inline asm and invented numbered-field layouts were
  recurring rejected outputs. Sanitization/quarantine reduce waste, not proven gains.
- Cache keys must reflect compiler configuration; one layout pilot initially reused
  identical-source cached output across configuration changes and was invalidated.

## Useful bounded entry points

```text
python roc.py worker --source-only --jobs 10 --workers 1
python -m roc.deep_fingerprint --dry-run --family raknet --client 2007-08
python -m roc.deep_fingerprint --max-batches 24 --family raknet --client 2007-08
python benchmarks/aggregate_search.py work/mass-search/RUN --output work/RUN-summary.json
python -m pytest tests -q
node tests/test_gui_frontend.js
git diff --check
```

The source-only worker and non-dry fingerprint command can submit improvements.
Check command `--help` and settings before using them. Frozen holdouts contain
already solved functions with source hidden: their exacts are not new recoveries.

## Linux and research boundaries

Linux runs historical MSVC through Wine using `tools/wineprefix`; `ROC_WINE` can
select a loader/wrapper. Linux support, MSI extraction, architecture and source-path
case fixes remain in main. Ubuntu/Windows CI passed at `e070c219c`; this does not
prove a native Wine compilation run. Linux entry points are `install.sh`, `roc.sh`.

Optional angr/Unicorn/Clang/SMT probes are not normal installer dependencies.
Whole-PE CFG recovery was too expensive; use verified function-size windows.
`/GL` needs linked `/LTCG` output, not ordinary object scoring. `roc/ltcg.py` builds
DLLs/extracts exports/map symbols; target-compatible scoring/context is unfinished.
Binary equivalence hypotheses still require compiler-backed C++ provenance.

For new work, prioritize genuine configuration/layout evidence, client-specific
template arguments, real caller/callee context and bounded data-flow repair.
These remain research opportunities, not demonstrated automatic recovery systems.
