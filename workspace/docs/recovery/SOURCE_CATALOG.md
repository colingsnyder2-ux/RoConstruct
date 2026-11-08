# Source catalog

`workspace/rebuild/2008-06/` is the reviewed native source authority on the
`work` branch. `2008-06/` is its public, browsable mirror. Neither tree is a
dumping ground for mined functions, draft sessions, package extracts, or newer
source trees.

Build a read-only inventory before any reconciliation:

```text
git fetch --no-write-fetch-head findings refs/heads/work:refs/remotes/findings/work
python -m roc.source_catalog --ref refs/remotes/findings/work --output work/source-navigation/RUN/catalog.json --map-output work/source-navigation/RUN/source-map.json
```

The catalog pairs `native-classes`, `native-headers`, `native-world`, and organized `src` and `include` sources under App, Base, Network, Rendering, WindowsClient and Studio.
The larger public package source tree remains browseable but is not mislabeled
as a native mirror conflict. It records reviewed/public blob identity per native
file and a content-derived hash for each local source snapshot. It never copies,
moves, deletes, compiles, executes, or promotes source. A per-output lock stops
duplicate long local inventories from racing the same result path.

`--map-output` also writes a generated JSON map plus a Markdown browse index beside
it. It groups native paths conservatively into WindowsClient, App/v8tree,
App/v8datamodel, App/v8world, App/v8xml, App/reflection, Network, Rendering,
Base/util, and Other. Links identify the exact
cataloged revision and distinguish canonical from public source. This is a navigation
layer only: it never moves files, rewrites includes, changes provenance, or
promotes code. A new `catalog/` directory beside the map contains compact,
expandable project pages. Use a fresh RUN directory; existing results are never
overwritten. `--browse-output` selects another new browse directory.

## Every navigation build includes donor versions

`--map-output` automatically indexes fetched contributor refs under
`refs/remotes/` and `refs/forks/`, local branch history, committed draft files, the durable local inbox,
the current checkout, registered worktrees and nearby RoConstruct snapshots.
Refresh contributor fork refs first with the existing intake/discovery workflow.
The catalog never fetches, uploads, compiles or promotes contributor code itself.
Every map refresh merges the previously published version and origin inventory
from the selected commit. Older donor links remain visible even when their local
refs or temporary folders have disappeared; current scan errors remain separate.
A malformed previous map or conflicting content hashes stops the refresh.

`--all-sources` enables the same intake for JSON-only output. `--donor-ref REF`
and `--source-root FOLDER` include additional known branches or temporary folders.

Versions are grouped by explicit 2008-06 native logical path and exact Git blob
identity. Every origin survives deduplication. Other client versions cannot enter
this map. Contributor and draft links pin immutable commits; local-only versions
retain a path and content hash without pretending a public URL exists. Original
scripts are never executed. Candidate proof/runtime status stays not-assessed.

Coverage, errors and excluded generated/vendor directory names are included in
JSON. Address-only mined functions and unmapped trials remain separate evidence;
they are not silently relabeled as native providers. A content inventory is not
method review, and a locally newer file is not automatically the best version.
Neither generation nor alias recovery advances contributor review cursors.

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

Compatibility translation units are linked to their organized sources in the
browse pages. Earlier paths retain their distinct fork, draft and snapshot
versions; the links do not imply that any donor was accepted. Compile either
a compatibility path or its organized source, never both.

The generated `source-map.json` keeps its project index and points to bounded
`source-map-versions/*.json` files containing every version and origin. Each
part includes a SHA-256 digest and row count in the index. Publish the index and
all parts together. Later scans read and verify every part before carrying prior
origins forward; a missing or changed part stops the scan. Older unsharded maps
remain readable. Sharding does not review candidates or activate code.
