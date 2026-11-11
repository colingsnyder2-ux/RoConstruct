# Whole-object native pilot

`roc.cmd native-bulk CONFIG.json --out work/native-bulk/MY-BATCH`

This connects the existing original-MSVC compiler runner, COFF matcher, original
PE relocation inventory, dependency graph and delinker. It compiles each complete
source once, examines every emitted function and writes generated manifests.
It never executes donor code or a generated executable. Review donor sources
and headers before putting them in the config; contributor receipts are data.

```json
{
  "client": "2008-06",
  "families": [
    {
      "name": "Name",
      "sources": ["rebuild/2008-06/native-classes/accepted/App/util/Name.cpp"],
      "evidence": ["work/2008-06/shared-layouts/name-whole-integrated.json"]
    },
    {
      "name": "Seat",
      "sources": ["rebuild/2008-06/native-classes/Seat.cpp"],
      "evidence": ["work/2008-06/shared-layouts/seat-working.json"]
    }
  ]
}
```

Sources and evidence must already be inside the checkout. Evidence identifies
original symbol addresses; it does not waive a fresh comparison. A receipt's
source fingerprints must match. Existing headers are used unchanged. Missing
declarations stay compiler blockers; no placeholder implementation is generated.
Optional family `requires`, `needs` and `blockers` add symbol, family and manual
constraints. Only the 2008-06/original VS2008 RTM profile is supported initially.

The output contains:

- `drafts/`: immutable source snapshots for review, compiled at the original path
  so relative includes keep their meaning.
- `objects/`: compiler logs, COFF objects and original compiler-runner receipts.
- `manifest.json`: every emitted symbol, byte analogs, verified identities,
  rejected references, input hashes, per-symbol verification time and throughput.
- `checks.json`: grouped source/check jobs for the existing native check runner.
- `providers.json`: one selected provider per symbol, retained original providers,
  conflicts and dependency-ordered strongly connected batches.
- `ledger.json`: content-keyed compile and proof results for subsequent runs.

The stages are `draft -> compiled -> inactive exact -> dependency/ABI ready ->
runtime verified -> server accepted`. This tool implements local inactive proofs
and a queue **for preflight**. A ready queue is not a completed ABI gate. A family
can contain exact methods while other emitted methods remain drafts. Neither
that family status nor a successful link proves class layout, lifetime, virtual
dispatch, P5/P6, runtime safety or server acceptance. Existing host checks and
server verification remain authoritative for later stages.

Local exact proofs require named identity evidence, equal code, complete original
absolute-relocation coverage, supported relocation kinds and bound reference
identities. Referenced local data and nested pointers are checked recursively;
unproven spans, unsupported relocations and ambiguous identities stay drafts.
Byte analogs alone never select a provider. Recursion is bounded conservatively.

Duplicate native providers must agree on address and identity to coalesce.
Conflicts park their owners and consumers, retaining the original provider when
available. Dependency cycles form one batch. Missing or blocked external
dependencies prevent preflight. Unknown dependencies remain visible blockers.

To consume ready providers through the existing delinker:

```powershell
roc.cmd native-bulk CONFIG.json --out work/native-bulk/MY-BATCH --prepare-link work/native-bulk/MY-NEW-LINK
```

The link directory must be new. Only approved object/symbol/address triples can
be selected. Original code, data and imports retain dependencies without a native
replacement. Selection must exactly match the manifest; mismatches stop linking.
`selection.json`, `link.log` and `preflight.json` record the result. The resulting
`bulk-diagnostic.exe` is never launched and must not become a runtime selection.
This does not delete donor objects from existing P5/P6 provider graphs.

Rerun the same command to retry relevant changes. Source, included-header,
compiler, flags, tools, original-image and identity changes invalidate their
affected receipts. Include-search file inventories detect newly created shadow
headers. Missing-header creation wakes failed compiles. Unchanged failed inputs
remain parked; unchanged successful objects and proofs are reused. Provider and
family dependency planning always reruns, without recompiling unrelated sources.
A `run.lock` prevents simultaneous writers to the same output. After a crashed
process, verify it has exited before removing its stale lock.

Throughput counts distinct addresses newly proved relative to that output's
previous manifest, so warm reruns do not count them again. Compiler/proof seconds,
compile invocations, cache reuse and lost proofs are reported separately.
Server-accepted addresses/hour is `null` until measured through authoritative
server receipts. Cold/warm pilot results describe discovery cost, not newly
recovered work or an improvement over an already batched compiler workflow.

Pilot before expansion: run the ready Name family and layout-blocked Seat family;
retain cold and warm manifests, verify Name's diagnostic link, confirm Seat stays
parked, and compare useful proof throughput with the existing batch runner.

## Recorded pilot: 2026-11-04

The config above emitted 574 symbols from two original-MSVC compiles. It
revalidated 40 distinct inactive addresses: 10 Name rows and 31 Seat rows,
including one shared address. These were existing recovery candidates, not 40
newly recovered functions. Name's 10 selected addresses linked successfully
against the original scaffold; Seat stayed blocked by its recorded layout gap.
The diagnostic executable was never run.

Cold discovery took 12.500 seconds (compiler: 3.703 seconds, proof analysis:
0.282 seconds). The unchanged rerun took 4.875 seconds, reused both objects,
performed no compilation or proof recomputation, and counted zero new addresses.
This measures cache benefit against this pipeline's cold run, not a speedup over
the existing batched verification runner. Server-accepted throughput remains
unknown. Do not expand the campaign on an assumed recovery-rate improvement.

Local receipts are in `work/native-bulk-pilot/release-cold-manifest.json`,
`work/native-bulk-pilot/release/manifest.json` and
`work/native-bulk-pilot/release-link/preflight.json`. The last receipt pins the
cold manifest identity as
`a03e9e826e019f05c676ba98eb28a470d5e5b56a19acd2f666edddd63f39bfb1`.
