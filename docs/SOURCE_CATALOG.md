# Source catalog

`workspace/rebuild/2008-06/` is the reviewed native source authority on the
`work` branch. `2008-06/` is its public, browsable mirror. Neither tree is a
dumping ground for mined functions, draft sessions, package extracts, or newer
source trees.

Build a read-only inventory before any reconciliation:

```text
git fetch --no-write-fetch-head findings refs/heads/work:refs/remotes/findings/work
python -m roc.source_catalog --ref refs/remotes/findings/work --local --output work/source-catalog/2008-06-COMMIT.json --map-output work/source-map/2008-06-COMMIT.json
```

The catalog pairs only `native-classes`, `native-headers`, and `native-world`.
The larger public package source tree remains browseable but is not mislabeled
as a native mirror conflict. It records reviewed/public blob identity per native
file and a content-derived hash for each local source snapshot. It never copies,
moves, deletes, compiles, executes, or promotes source. A per-output lock stops
duplicate long local inventories from racing the same result path.

`--map-output` also writes a generated JSON map plus a Markdown browse index beside
it. It groups native paths conservatively into Studio/App, Engine/DataModel,
Engine/World, Network, Rendering, Shared/Util, and Other. This is a navigation
layer only: it never moves files, rewrites includes, changes provenance, or
promotes code.

## Source lanes

| Lane | Use | Promotion rule |
| --- | --- | --- |
| `workspace/rebuild/2008-06` | reviewed canonical classes, headers, world code, tests and proofs | normal reviewed integration only |
| `2008-06` | public mirror of the reviewed tree | reconcile exact reviewed paths only |
| `src/2008-06` | address-named mined functions | keep separate; nominate a class path only with identity and ABI evidence |
| `work/2008-06` | drafts, receipts, experiments, queues and local outputs | retain in place; review as evidence only |
| `local/findings/2008-06` and `RoConstruct-Native-*` | historical/package snapshots | preserve as snapshots; compare by path and hash |
| `tools/roblox2016` | later-version reference source | version-labeled donor evidence only |

## Reconciliation

For each `diverged`, `missing-public`, or `public-only` row: compare the work
base, current canonical source, public source, original code/data/call evidence,
header/ABI dependencies, and affected tests. Keep the better complete method.
Record the decision and source hashes. Use the normal private-index integration
path, the no-loss check, and then refresh the public mirror.

Blob equality only says both stored files have identical bytes. It does not show
that code is selected, ABI-safe, runnable, or credited.
