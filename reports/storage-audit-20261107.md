# Storage and source audit — 2026-11-07

Inventory baseline: `e7425c5c94585424a77a6277259446ce76b2c03f`.
All branch blobs and 2,811,729 local work files were enumerated. Local files
totaled 543.03 GiB before cleanup. No filesystem errors were reported; reparse
links were excluded from traversal. Totals are logical file sizes, not physical
allocated blocks. Full machine-local inventory remains outside the published tree.

## Published work branch

| Area | Logical size | Action |
| --- | ---: | --- |
| Address-named mined functions, all clients | 2.36 GiB | Keep; separate navigation from native classes |
| Immutable draft bundles and files | 206.7 MiB | Keep originals and content identities |
| Public 2008 native/build view | 95.7 MiB | Repair reviewed mirror paths |
| Canonical workspace | 58.7 MiB | Keep maintained source, tools, tests and evidence |
| Worker downloads | 22.3 MiB | Keep verified package and manifest together |
| Generated units | 15.0 MiB | Keep while recipes reference them |
| Historical archive | 5.8 MiB | Keep indexed; insignificant storage savings |

Identical Git blobs already share object storage. Moving duplicates between
folders does not itself reduce repository storage. The local Git object store
was approximately 711 MiB; 770 bytes of temporary garbage is not a cleanup priority.

## Local work folder

| Area | Logical size | Decision |
| --- | ---: | --- |
| integration/jobs | 128.29 GiB | Retain: indexed baseline/job dependencies need closure review |
| integration/baselines | 84.12 GiB | Retain: index refers to these original snapshots |
| libcache | 187.64 GiB | Rebuildable preprocessing cache; retention/compression candidate after recipe/dependency checks |
| object-cache | 53.14 GiB | Evict old generated matching objects under per-key nonblocking locks |
| 2008-06 | 19.50 GiB | Retain source, original lifted evidence, runner objects and proofs |
| codex-native-colin-20261029 | 9.31 GiB | Historical source/build snapshot; compare before archival |
| function-history.sqlite | 4.13 GiB | Keep database; do not delete as scratch |
| server.db | 1.14 GiB | Keep live server state |

The first eviction is limited to 64-hex-named `.obj` entries in object-cache with
mtime before 2026-10-24 UTC: preview 360,777 files / 45,128,883,690 bytes.
The matching implementation recomputes missing objects from source/configuration.
Busy keys, lock files, recent objects, source, proof receipts, uploads, outboxes,
databases and installed compiler/library inputs are excluded. A local per-file
eviction receipt records successful removals. This cache eviction is not archival
of source and does not invalidate the separate retained native runner receipts.

Completed cache cleanup: 360,777 old matching objects (45,128,883,690 bytes),
94,998 additional unused matching objects (11,926,044,824 bytes), and 131,688
generated preprocessing/dependency cache files (201,473,884,175 bytes). Total
logical cache bytes removed: 258,528,812,689 (240.78 GiB). No busy object keys or
failed preprocessing removals were reported. The second object pass retained
anything written within five minutes. Installed libraries under tools remain.

Large retained integration evidence is also being compressed with NTFS file
compression. This preserves file names, source bytes, object bytes and receipt
paths. Logical sizes do not reflect those physical disk savings. Compression
errors, if any, remain in the local compression log.

Historical published OpenCode goal sessions/locks are moved byte-for-byte from
workspace/.opencode/goals into archive/workspace-state-20261107/opencode-goals.
No tracked tool/test/doc reference to the old directory was found. Active local
sessions are untouched. The OpenCode RoConstruct tool plugin remains in place.
Existing downloadable ZIPs require their normal packaging refresh before this
workspace cleanup is reflected in those ZIPs.

## Source reconciliation

After removing only recognized generated status banners, 801 of the original
812 differences are banner-only, one is line-ending-only, and ten remain for
manual comparison. Canonical/public repairs restored eight existing reviewed
files and published eight missing overlay headers in `e0cda2d828`.
Both exact final workspace/public preservation checks passed with zero losses.
Canonical sources and executable selection were unchanged; no new runtime gate
or recovered-function count is claimed.

ActiveDocumentData and CRobloxDoc have coupled document-state changes still
requiring original call/data/lifetime review. 129 public-only paths remain
pending independent source/proof review. An inventory is not review completion.

The exact mewpokemons Instance donor `0e57052cc3` was read and archived with its
header and recorder. It overlaps existing canonical methods and includes pending
declarations. Do not import the complete unit as an additional provider.

## Branches and tooling

Published work already has the consolidated work/workspace publisher. Old
publisher targets found in the active local checkout must not overwrite it.
The current checkout and running server still depend on that local environment;
retire the extra branch only after their dependency transition is complete.
The verified all-refs bundle preserves committed history, but does not back up
dirty files, local databases or untracked worker changes. Those remain in place.
