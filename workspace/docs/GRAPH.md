# Function dependency explorer

Generate from an analyzed client and pulled sources:

```text
roc graph build 2008-06 --web
roc graph 2008-06 --focus 007ab0a0 --depth 2 --json
roc graph 2008-06 --focus 0067d9b0 --upstream --depth 2
roc graph 2008-06 --why 00549a50 --milestone p2 --json
roc graph 2008-06 --next 20 --milestone p2 --json
roc graph 2008-06 --path 00549a50 --milestone p2 --json
roc graph 2008-06 --cycles --json
roc graph 2008-06 --order --json
```

Use any registered/analyzed client instead of `2008-06`. Exported clients populate
the website picker automatically. P2 is currently defined for June 2008 only;
unknown milestones fail explicitly. The preset is a set of rendering entry points,
not a runtime milestone acceptance receipt. See `GRAPH_EVIDENCE.md` for the two
geometry targets identified from original calls.

## Data and trust

`roc/graph.py` reads inventory `call_targets`, imports and unresolved virtual slots;
mining score hints; function and TU manifests; ABI evidence; rebuilt symbol names,
owned addresses and object ownership; the existing native baseline and published
native-source links; and existing attempt history. It reuses `native_adapt` class
resolution, `integration_site.readable` labels, library recipes/directives and
`ranking.rank_one` mining readiness. It never compiles or disassembles while
indexing. Fresh disassembly was used only for the documented geometry inspection.

Function IDs are normalized original addresses, scoped by client. Compiler helpers
remain searchable inventory nodes; data/bad entries and generated/EH/adjustor/thunk
entries are excluded from the reconstruction queue. Non-function
IDs use `class:`, `module:`, `symbol:` and `external:` prefixes. Unknown direct-call
targets remain address nodes with missing-inventory status. Classes and decorated
source labels are evidence-backed hints, not original declaration claims.

Mining, compilation, linkage, runtime verification and blockers are separate
booleans. `MINED` from cached 100% scores remains explicitly a cached hint.
Missing local files do not erase known mining progress. Retrieve existing source
with `roc pull`; `roc-lib` pointers resolve to the real recipe source path, including
recipes rooted outside `tools/libs` in `tools/rbxgs`. Missing score/size values
remain null/unknown. A linked module smoke test never proves runtime execution of
every owned function. The native baseline is reused as server-verified linkage;
accepted native source paths come from the existing public source-link index.
Current-source freshness of build artifacts remains unverified until rebuilding.

Edges carry provenance and confidence. `call` is an inventory direct call;
`external` is an import; `class` is a source/native-label relationship;
`ownership` associates functions with a module; `dependency` requires actual
reviewed evidence or an unresolved module link symbol. Module linker requirements
are labelled **module scope**. They are not assertions that every function in that
module directly calls a missing symbol. Unknown virtual dispatch keeps its slot
evidence without an invented target. Reviewed proven virtual edges can be supplied
through the evidence overlay.

## Curated evidence and milestones

Tracked evidence lives in `research/graph/<client>.json`. An optional local
`rebuild/<client>/manifests/graph-evidence.json` can add reviewed relationships and
node facts. Node labels and all relationships require provenance. Example:

```json
{
  "nodes": {
    "00401000": {
      "label": "Class::method",
      "evidence": "source or binary evidence reference",
      "blockers": ["ABI layout not yet established"],
      "verified_states": {"RUNTIME_VERIFIED": "function-specific runtime receipt"}
    }
  },
  "edges": [{
    "source": "00401000", "target": "00402000", "kind": "dependency",
    "evidence": "specific linker/runtime/ABI receipt", "confidence": "confirmed"
  }]
}
```

No full-class dependency is inferred from sharing a class or vtable. No historical
layout gap is automatically treated as a current blocker. Add current, scoped
proof when a real integration dependency is known. The engine's milestone map is
small; add further milestone seeds from verified roadmap entry points. Traversal
and shortest paths use observed calls and explicit dependencies, not speculative
virtual resolution.

## Queue and agent use

`--why` returns source locations, independent states, incoming/outgoing evidence,
blocking dependencies, affected dependents and score factors. `--next` is a
heuristic queue: confirmed transitive function unlocks, module-scoped potential
impact, distance from milestone seeds, existing source/compiler evidence, existing
mining readiness and no-gain attempts. Module impact is reported separately from
confirmed function unlocks. Resolving one symbol may expose another linker error;
rank scores are not verified success probabilities or estimates of completed work.

SCCs use iterative traversal, so large cycles do not exhaust Python recursion.
`--order` emits prerequisite-first SCC groups; cyclic functions stay together.
Call edges never impose a dependency order. `--cycles` reports dependency SCCs.
The Python API also accepts selected relationship kinds and bounded node limits.

CLI queues consult existing local server-issued mining leases and unexpired native
claim packets. Public exports omit claim tokens, worker identities and active
lease state. Use `--server URL` for a fresh June 2008 native claim/parked-unit lookup
through the existing `/v1/integration?claims=1` API. It does not claim work.
Remote workers' fresh ownership cannot be established by an offline snapshot. Before working, use existing `roc integrate next --unit CLASS` or mining
claim commands and their server leases. Graph queries never acquire/release claims
or create a second ownership system. Already linked/runtime-verified functions
are excluded; known library implementations prompt inspection instead of recovery.

## Update and publish

`work/<client>/graph.json` is the complete local index. A versioned input signature
covers source file metadata, manifests, ownership reports, attempt history and
native snapshots. Queries reuse it until an input or engine changes. A per-source metadata cache
re-parses only changed source files during incremental rebuilds. `graph build`
forces rebuilding. Unchanged export files retain their bytes and timestamps.

Public data is deterministic gzip-compressed JSON under `docs/graph-data/<client>`:
`index.json.gz` contains the searchable labels, provenance dictionary and queue;
address-prefix shards contain small node neighborhoods and compact edge records.
Each compact edge is `[source, target, kind, evidenceIndex, confidence]`.
`clients.json` lists exported clients. Compression uses a fixed timestamp/OS marker.
The browser uses native `DecompressionStream`; no live backend, client binary,
private DB, source body or token is shipped. Cytoscape 3.30.4 is vendored with its
MIT license, so viewing the graph does not need a CDN.

The browser starts with 50 nodes and draws at most 150 nodes, loads partitions on expansion, and limits
milestone-path search to six edges / 1500 visited nodes. A bounded failed search
means no path was found within those limits, not proof of no dependency. Search
returns at most 30 results. Caller/callee/dependency/class expansions are separate.
Status filters apply to the loaded neighborhood. Selected-node details retain
unknowns and provenance. The P2 preset and queue work without RoConstruct server.

Local preview:

```text
python -m http.server 8765 --bind 127.0.0.1 --directory docs
```

Open `http://127.0.0.1:8765/graph.html` in a modern browser. Opening a `file://` URL
cannot fetch shards. Publish `graph.html`, `graph.css`, `graph.js`, `vendor/`, the
navigation changes and `graph-data/` together through the existing GitHub Pages
workflow. The included June 2008 snapshot is ready for static publication. Re-run
export after mining/integration updates; never copy `work/`, `clients/` or private
server data into website output. No `git push` is performed by graph generation.

## Verification

Run `python -m pytest tests/test_graph.py -q` and
`node --test tests/graph_ui.test.js`. Existing CI runs both. Tests cover address
normalization, direct/reverse calls, unresolved virtual evidence, cycles, ordering,
independent states, real recipe paths, missing/stale manifests, cached sources,
module-scoped blockers, existing leases, deterministic compression/cache updates,
native baseline reuse and a 10,000-node synthetic inventory. Browser QA covers
search, selection, directional expansion, filters and the P2 neighborhood against
real static exports.

Broader existing checks in this checkout exposed unrelated failures:

- `test_roc.py::test_find_functions`: expected rows omit `start_evidence`.
- `test_roc.py::test_server_store`: leaderboard order differs from expectation.
- `test_roc.py::test_hidden_exact_sources_stay_byte_exact`: missing local
  `clients/2007-08/Roblox.exe`.
- `test_integration.py::test_cli_worker_identity_is_stable_per_checkout_not_shared_by_same_pc`:
  test API mock does not support the existing GET `/v1/integration`.
- `test_integration.py::test_cli_compact_claim_batch_selects_only_its_own_packets`:
  baseline advances before the existing submit stale-claim check.

These paths were not changed for the graph implementation.

## Read implementation source

`roc source CLIENT ADDRESS` resolves `roc-lib` through the existing recipe and
managed-unit store, then prints the actual C++ implementation unit. Use `--json`
for source text plus provenance, or `--output PATH` to save a separate readable
view. Build pointers remain unchanged, preserving compiler flags and verification
behavior. Implementation units may contain multiple recovered functions. Missing
units fail explicitly; archive objects are labelled as archive references rather
than fabricated source. Graph library-source links are labelled "Build pointer"
and show the corresponding implementation-view command.
