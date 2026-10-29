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

## Shared compilation and cache reuse

Compatible worker edits to different methods in one source file now share a whole-TU
compile. The default batch is four methods; `--compile-batch N` accepts 1–32, with
1 retaining individual proofs. Conflicting alternatives compile separately. Syntax
failures and regressions split for isolation; recovered edits must compile together
again before their combined proof can be saved. Unproved method edits are removed
and the reduced source is recompiled. Linked acceptance gates remain independent.

An offline replay of 20 recorded method edits used genuine MSVC 21022 and made no
model requests or submissions:

| Methods per compile | Compiler calls | Seconds | Exact targets | Losses |
| --- | ---: | ---: | ---: | ---: |
| 1 | 21 | 0.969 | 20 | 0 |
| 4 | 5 | 0.859 | 20 | 0 |
| 20 | 1 | 0.219 | 20 | 0 |

The individual case includes a final combined-source compile: independent object
proofs cannot certify their union. This small integer fixture establishes compile
counts and proof safety, not production throughput or new historical matches.

Windows include-path casing also caused identical warm builds to miss the content
cache. Cache keys now normalize path casing, retain dependency content hashes, and
serialize only relevant directory entries. Newly shadowing headers still invalidate
objects. In a private real-source run, Humanoid cold/warm took 23.516/1.797 seconds;
Block took 1.766/1.047 seconds. Profiles confirmed warm runs skipped the compiler.
Method-span parsing is shared by immutable source text, avoiding repeated scans for
each worker method.

Header inventory reuse further reduces repeated filesystem walks. Only directories
actually traversed by the parent scan reuse its listing; excluded `_wrap` folders
and skipped links retain independent scans. Include order, content hashing and new
shadow detection stay unchanged. In an interleaved real-source warm comparison,
Humanoid used 30 walks instead of 115 and took 0.859–0.922s versus 1.031–1.140s;
Block used 30 instead of 38 and took 0.344–0.375s versus 0.469s. Every run reused
the existing object with zero compiler invocations, confirming compatible cache
keys. A 98-second first-access outlier under concurrent worker load is excluded
from the warm comparison. Measurements are local observations, not guarantees.

Reproduce the compiler-only fixture without calling any model:

```text
python benchmarks/native_compile_batches.py --workers 20 --tasks 20
```

## Earlier live model experiments

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

`roc integrator --generation auto|method|edits --compile-workers auto|N --compile-batch N`:

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

Further tuning should use compiler-only replay and real-source profiles. Different
translation units stay separate: unity builds can change include order, floating-point
pragmas and emitted code. Production integration yield still requires real proposals
to pass the independent linked verifier.

Discovery checkpoints each finished proposal, with its accepted baseline revision,
before slower files finish. This preserves source edits and local proof through
interruptions; it does not label them submitted or bypass linked preflight. Repair
excerpts and batch feedback now select pending targets after local exacts are removed,
avoiding irrelevant already-exact methods at the front of the file's target list.

Automatic discovery now cycles after at most 60 seconds without fresh files and
rotates the pending method order each cycle. Previously it waited indefinitely
for published totals to change after exhausting its file set. Failed candidate
preflight retains proofs and skips those files for the current cycle; discovery
continues after a 30-second recovery interval. Permanent provider/auth failures,
budget limits and explicit stop/pause remain effective. Server startup sync and
subsequent network failures retry within a two-hour outage deadline. Compact UI
now displays coordinator/preflight logs and a batch phase when file workers finish.

## Claim inventory latency

Class-specific claim requests previously rebuilt the complete catalog whenever the
requested class changed, and each function searched concatenated header text with a
regular expression. The catalog now indexes declared classes once, caches eligibility
independently of the requested class, and applies the explicit-class exception for
the queue's `done` hints when returning results. Parked units remain excluded.
Concurrent requests share one index build; manifest/report/queue and accepted-ledger
changes still invalidate it. Claims, leases, ownership and acceptance checks are unchanged.

A compiler-free replay against the installed native source tree and copied real
manifests, using a separate benchmark SQLite database, measured three lookups:

| Lookup | Before | After |
| --- | ---: | ---: |
| Inventory | 5.844s | 0.187s |
| PartInstance | 5.906s | <0.001s |
| SoundService | 5.907s | <0.001s |

All 128 unit/function inventories had identical hashes. A separate live inventory
request before deployment took 10.828s for 123 available units; unlike the replay,
the live server also includes its accepted-job ledger. These are catalog timings,
not complete linked-verification throughput. The benchmark never claimed targets,
submitted jobs, called models or modified the server database.

## Windows child startup deadlock

The live controller repeatedly timed out after 120s while regenerating overlays.
Its child Python process had consumed no CPU and produced no output. A minimal
reproduction with a controller reading its open stdin pipe reproduced the problem
twice: inherited child stdin timed out after 3.0s; explicit `DEVNULL` started and
completed in 0.063s. The actual generator, copied with the same accepted ledger
into a private fixture, then completed in 0.14s and produced exactly the server's
accepted overlay. The copied stale local overlay differed, explaining why sync
needed regeneration in the first place.

Noninteractive generators, verifier commands, compiler wrappers and smoke processes
now receive `DEVNULL`. Interactive worker/controller pipes keep their explicit
input. Controller JSON uses one raw line iterator across initial configuration and
subsequent commands; this preserves coalesced/split messages and avoids buffered
stdin locks during shutdown. Generator timeouts also respect their remaining
deadline rather than always waiting another ten seconds.

Same dashboard-session restarts now retain their owned private workspace, including
source edits, local proof history and dependency/build outputs. A per-session lock
prevents simultaneous reuse, ownership markers reject another session's directory,
and runtime updates leave native/rebuild inputs intact. New sessions remain isolated.
Verification and content-cache invalidation still apply. Real Windows regression
tests hold the controller input pipe open while exercising generator, verifier and
compiler-wrapper children; no model requests or server database edits are involved.

## Preflight discovery and fingerprint overhead

A real private preflight profile covered 21,410 inputs (21,293 read-through inputs).
Cold discovery repeatedly traversed installed tool trees for compiler and SDK paths.
Compiler discovery, library includes and rebuild SDK selection now share one locked
walk, retaining the same sorted candidates. Installation and explicit SDK refresh
invalidate the shared cache. Compiler version probes still execute, with stdin
disconnected from controller commands.

An unprofiled installed-tree replay measured the two former recursive globs at
10.906s, the shared cold scan at 4.500s and its cached lookup below 0.001s. It found
the same three compiler paths and one SDK. A separate pair of full/live fingerprint
labeling comparisons over frozen content hashes measured 2.171/2.500s before versus
0.110/0.125s after. Both full and live digests remained identical. Absolute, relative,
drive-root and Windows Unicode-case paths have reference-digest regression tests.
File contents, input selection, environment fields and SHA-256 validation remain intact.

A complete unprofiled sample took 22.813s with cold discovery and 10.875s with warm
discovery. There is no equivalent earlier unprofiled whole-fingerprint sample, so
these are not claimed as a full-preflight speedup. A file-hashing chunk experiment
showed no consistent advantage; per-file scheduling and eight readers remain.
Reproduce a complete local input fingerprint with `roc integrate fingerprint`;
it does not call a model or submit a job.

## Parallel native matching

Discovery now indexes the first eight object bytes by function size and relocation
positions. This only filters impossible candidates: every surviving address still
passes the complete `Target.same` relocation/code comparison and referenced-data
check. Address ordering and symbol selection stay unchanged. Each matcher owns a
locked, bounded 256-entry prefix cache; it cannot reuse another client's image.

A real replay used Block, DebrisService, GUI and Humanoid objects against the whole
2008-06 function inventory. Twenty uncached scans returned exactly the same address
and symbol lists with both algorithms. A first experiment measured 4.625s exhaustive
versus 0.718/0.719s filtered with 20 workers. The packaged benchmark replay measured
12.203s exhaustive versus 1.687s with a cold prefix cache and 1.547s warm. Machine
load varied between runs; these are matcher timings, not end-to-end integration
rates. Object-result caching was disabled and COFF parser caches were warm in both
comparisons. No models, compiles or submissions were involved.

Run `python benchmarks/native_matcher.py path/to/Block.obj path/to/Humanoid.obj`
to compare exhaustive and filtered scans with one and twenty workers. Every result
is checked against the exhaustive address/symbol list. Regression tests additionally
cover prefix collisions, partial relocation fields, missing required relocations,
referenced-data rejection, concurrent scans and cache eviction.

## Warm compiler-cache validation

Header inventory views now reuse normalized path strings within one compile call.
The cache still lists shadowing candidates, hashes every dependency and compiler
input, checks include order/flags/environment and validates the object hash.
Dependencies no longer receive a separate existence probe before their mandatory
content read. A missing dependency falls through to ordinary compilation; failed
compilation removes stale object/cache files. Nothing is cached across calls by
timestamp or file size.

A real replay alternated Block and Humanoid for twenty warm validations. With
twenty workers the original implementation took 8.453/7.812s versus 7.375/6.735s
afterward. Serial warm results were 9.281s original versus 8.062/7.969s afterward;
the first original replay took 18.891s and is excluded from steady comparisons.
The benchmark forbade compiler invocation and verified all object bytes and cache
records stayed unchanged. These measure validation overhead, not cold compilation
or accepted functions per minute. Same-mtime content mutation, new shadowing headers,
include ordering, removed headers and failed-build cleanup remain regression-tested.

Compile failures now report `comparison_complete=false` with no inferred losses.
Previously an absent object produced an empty match set and misleadingly listed
every baseline exact as lost. Successful compilations still compare every prior
exact and retain real lost addresses. Compilation success remains mandatory for
any proposal; batch isolation and combined-proof checks are unchanged.

Long contributor preflights emit a phase heartbeat every thirty seconds. The
controller reports each coordinator message once, rather than duplicating it as
both a worker log and a stage. Heartbeats stop when verification returns or fails;
the original receipt/exception propagates unchanged. These controller changes do
not modify verifier inputs or invalidate an otherwise matching baseline cache.

## Saved-proof recovery and file-slot utilization

Baseline changes now queue content-hashed, immutable proposal archives before
leaving a pass. Automatic recovery synchronizes accepted sources, recompiles the
current TU and saved edits, verifies code/data and existing exacts, checks ownership
and runs the combined linked proof before submission. It requests no new AI output
and preserves the original writer's model identity. Already covered targets need
no candidate compile; changed/ambiguous anchors remain quarantined for repair.
Exact already-applied edits can be removed during rebase. No fuzzy anchors or
stale compiler proofs are accepted. Invalid files do not prevent other saved files
from being revalidated. Blocked recovery is retried after a baseline change;
completed/submitted tickets are not blindly replayed.

The file coordinator keeps per-file target offsets and known remaining-target
counts. A short fresh-file pass fills unused slots from previously visited files
with different pending targets. A regression test reproduces seven fresh files
plus thirteen revisits with twenty simultaneous file workers. Exhausted files are
not used as filler; revision changes invalidate old scheduling evidence. Linked
verification still requires a complete batch, so idle AI slots during that phase
are expected and the UI now reports actual active slots separately.

The RakNet loopback test previously bound both sockets to all interfaces on a fixed
server port. It now binds only 127.0.0.1 and discovers an ephemeral server port.
Genuine VS2008 compilation/linking and twenty parallel reliable-packet tests passed.
The payload and connection assertions remain mandatory. No firewall policy or
administrator configuration is changed.

A replay of the real held twelve-file/sixteen-target proposal archive against a
new accepted baseline took 80.609s with model generation and server writes disabled.
Seven files' saved targets were already covered, three had no unique ownership
candidate and remained in their immutable archive, and two yielded fresh local
code/data proofs with zero losses. This was a contributor recheck, not new server
credit or a completed combined linked proof. The original Codex model identity was
retained throughout recovery.

## Exhausted providers and ambiguous local hits

Explicit OpenCode allowance failures (`Free usage limit reached`, `Go usage limit
exceeded`) and API `insufficient_quota` now require provider action instead of
opening a retry circuit for every file. Ordinary request-rate throttles, per-minute
quota messages and transport failures retain transient retry handling. Existing
proofs remain saved when an allowance stops new generation.

Automatic discovery checks whole-binary ownership before emitting local gains.
Ambiguous code/data matches are archived under `ambiguous-proposals/` instead of
inflating the gain counter. Mixed batches minimize down to uniquely owned gains
and re-prove the remaining edits with baseline loss checks. Server acceptance gates
are unchanged. Historical local counters may include repeat addresses and ambiguous
matches; they are not counts of distinct server credits.
