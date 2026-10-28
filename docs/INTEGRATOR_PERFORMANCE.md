# Integrator performance experiments — 2026-10-28

These are measured local experiments, not accepted integration credit. No server
database, claims, jobs, binaries or installed source trees were changed by the
benchmarks. Historical MSVC 21022 produced every compared object. Independent
linked ownership, runtime, ABI and referenced-data gates remain unchanged.

## Observed bottlenecks

The contributor's actual 20-worker Codex session used four compiler slots. Its
median AI time was 23.0s, compile time 12.7s, and compiler queue time 6.5s. The
131 recorded compilations accumulated 1,544 seconds of queue time across workers.

On this 20-logical-CPU, 32GB Windows machine, a warm, reordered repeat of 20 real
translation-unit builds (Block, DebrisService, GUI, Humanoid) measured:

| Compiler slots | Total seconds |
| --- | ---: |
| 1 | 71.36 |
| 4 | 22.97 |
| 8 | 19.22 |
| 20 | 27.22 |

Each object retained the baseline's exact code/data matches. The initial cold
serial sweep was much slower (356.63s), so it is not used for the warm speedup.
These are shared-machine observations, not universal CPU recommendations.

Repeated COFF symbol-table parsing dominated Humanoid's comparison. A shared
immutable index changed its whole-binary code/data scan from 3.406s to 0.625s.
The results matched exactly; data references were also compared against the old
implementation for all 276 matched symbols. Block, GUI and DebrisService results
were likewise identical. Each concurrent scan retains its index to avoid cache
thrashing when more than eight objects are active.

## Live model experiments

The opt-in `benchmarks/native_integrator.py` sends real requests but uses small
synthetic functions and verifies genuine COFF output. They are not new historical
client functions. Each row below has 20 independent fixture tasks.

| Model / mode | Workers | Concurrent AI limit | Proofs | Seconds | Proofs/min |
| --- | ---: | ---: | ---: | ---: | ---: |
| Codex gpt-5.6-terra / method | 1 | 1 | 20 | 107.34 | 11.18 |
| Codex gpt-5.6-terra / method | 20 | 20 | 20 | 14.80 | 81.10 |
| NVIDIA Nemotron Ultra / method | 1 | 1 | 18 | 118.84 | 9.09 |
| NVIDIA Nemotron Ultra / method | 4 | 4 | 20 | 39.45 | 30.42 |
| NVIDIA Nemotron Ultra / method | 8 | 8 | 19 | 31.81 | 35.83 |
| NVIDIA Nemotron Ultra / method | 20 | 20 | 19 | 30.56 | 37.30 |
| NVIDIA / auto, one round | 20 | 8 | 16 | 12.55 | 76.51 |
| NVIDIA / auto, up to three rounds | 20 | 8 | 20 | 23.05 | 52.07 |
| NVIDIA / method, up to three rounds | 20 | 8 | 20 | 35.56 | 33.74 |

One-shot method requests used about 52% fewer input characters than anchored edit
requests in the first comparison. Characters are not provider token measurements;
OpenCode's text route did not report tokens. Fixture cache warmth, remote capacity
and model variability limit conclusions about absolute speed and small differences.

Earlier high-concurrency OpenCode runs suffered socket closures and a stopped
shared service. Those failed runs are retained locally, not interpreted as model
quality. Requests now use an empty persistent workspace outside the repository,
explicitly connect to an existing service, and ignore stale service metadata.
This avoids repository snapshot work and Windows cleanup errors caused by a
service holding a temporary request directory as its working directory.

Three real waiting functions were also trialed: Instance::readProperty,
Feature::getRenderCoord and Primitive::getAssembly. No new exact was established.
The two compiled one-shot trials lost no existing exacts; the other reply was
rejected before compilation. For Primitive, the remaining difference is a load at
0x24 in the target versus 0x20 in the rebuild's inlined Clump::getAssembly. This
needs header/layout or member-selection evidence, not invented padding or a raw
offset cast. These results do not prove improved real integration yield yet.

## Controls and current changes

`roc integrator --generation auto|method|edits --compile-workers auto|N`:

- Auto first requests one complete, unambiguous method of at most 6,000 characters,
  then uses anchored repair feedback. Original signatures stay unchanged. Unsupported
  or large methods use anchored edits. Every candidate still compiles the whole TU.
- Compiler auto uses half the logical CPUs, capped at eight and the worker count.
  Explicit limits override it. Returned AI edits get priority over queued baselines.
- OpenCode NVIDIA auto allows eight simultaneous AI requests. Extra file workers
  can prepare baselines and check proofs; explicit cloud concurrency overrides it.
- Already-local-exact targets consume no model requests. Duplicate failed candidates
  are not recompiled. A bounded provider timeout covers all retries rather than
  restarting a full timeout on each attempt.
- SDK discovery is shared across concurrent cold starts. Content hashes, dependency
  inventories, compiler settings, referenced data and object integrity still gate reuse.

Reproduce the synthetic experiment only when live model usage is authorized:

```text
python benchmarks/native_integrator.py --live --workers 1,4,8,20 --tasks 20 --modes edits,method
python benchmarks/native_integrator.py --live --workers 20 --rounds 3 --modes auto --inflight auto
```

Raw local receipts are under `work/integrator-bench/`. Real translation-unit
experiments and profiles are in the dedicated private benchmark workspace recorded
by `work/integrator-bench/workspace.json`. No benchmark submits its results.

Next experiment: combine independent method edits from several AI workers into one
file compilation, with conflict handling and failure isolation. That batching is
not part of the measured results above.
