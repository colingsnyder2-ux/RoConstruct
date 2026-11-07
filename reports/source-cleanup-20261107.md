# Source cleanup — 2026-11-07

## Reviewed baseline

Catalog commit: `68a9d6279893d9efa8b3df76ceee6c13a8d14a28`.
824 canonical native files; 945 public native files. Four equivalent, 812
different, 129 public-only, eight canonical-only. These are file comparisons,
not completed reviews or integration counts.

The generated [source map](../2008-06/SOURCE_MAP.md) links exact source revisions.
WindowsClient, App/v8datamodel, App/v8world, Network, Rendering and Base/util are
browse groups, inspired by later project organization. Classification remains
heuristic; it does not claim recovered original project paths.

## Experimental stub build: excluded from verified claims

Local untracked `rebuild/2008-06/p6/build_native_client.py` generates an empty
`CRobloxDoc::initializeCommands()` and adds `NativeClientStub.cpp`. The latter
provides empty Workspace load/cleanup, document handlers and dummy subsystem
results. Its "playable" comment is unsupported by the inspected build log,
which ends in LNK1120 with 113 unresolved externals.

Neither file exists in this catalog's canonical work subtree. They were preserved
locally, not imported or run. Repository Python/CMD search found the stub source
referenced by this experimental builder only. Executables and external launchers
have not yet been exhaustively traced. Do not use this profile as a verified
client, integration gate or runtime result.

## Recovery archive

All local Git refs were saved to an independently verified bundle at
`C:\Users\colin\RoConstruct-cleanup-archive-20261107\all-refs.bundle`.
This bundle preserves committed history only. Dirty files, untracked native
work, draft databases and outboxes remain in their original folders; the bundle
does not replace their backup or review.

## Pending reconciliation

- Review every differing/public-only path by method, header and dependency.
- Compare drafts, contributor forks and local snapshots; retain provenance.
- Publish eight canonical-only files only after ownership and proof review.
- Trace experimental binaries and all build entrypoints before physical quarantine.
- Inventory and back up dirty worktree files before retiring local branches.
- Archive obsolete outputs only after dependency and active-worker checks.
- Retire the extra owner branch after unique work is reviewed and recoverable.

No source files, branches, worker folders, installed inputs or outboxes were
deleted by this navigation batch. Source reconciliation is still pending.
