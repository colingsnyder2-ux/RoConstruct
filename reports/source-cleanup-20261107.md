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

## Follow-up review

Exact comparison after removing only recognized generated status banners finds
801 banner-only differences, one line-ending-only difference and ten remaining
byte differences. One of those ten is a comment encoding difference in Matrix3.
The 812 original differences therefore do not mean 812 different implementations.

Public source restorations use exact existing canonical blobs: AxisMoveToolRender
include profile, CMainFrameXtp::OnDraw, CWebToolbox::showPage, InstanceBaseCallbacks
flags, RunService methods/flags, CMainFrame::showFrame declaration, CRobloxApp
framework/open-file declarations and Matrix3 comment encoding. Eight existing
canonical overlay headers are added to the public tree. Canonical source and
executable selection remain unchanged. These are mirror repairs, not newly
recovered functions or fresh runtime verification.

ActiveDocumentData and CRobloxDoc remain intentionally unreconciled: public
currentDocument/setCurrentDocument ownership changes must be reviewed together
against original call/data identity and lifetime behavior. No replacement was
made merely to produce equal file counts.

Colin's exact mewpokemons donor `0e57052cc3` was inspected. Its
AppUnit558_2008Instance.cpp contains existing setName, onChildChanged, serialization
and child-listener implementations plus other candidate methods and a pending
declaration section. Whole-file import would duplicate canonical providers.
The exact unit, owned header and recorder are preserved externally in
`mew-0e57052cc3-instance-unit.zip` beside the Git bundle. The recorder was read,
not executed. Its exactness claims remain donor claims pending independent checks.
Current mew, coldek and ivan remote refs were refreshed for subsequent review.

Published work already contains the modern work/workspace publisher. The stale
publisher references previously found belong to the older active local checkout;
do not replace modern work tooling with that checkout's older modules.

- Review every differing/public-only path by method, header and dependency.
- Compare drafts, contributor forks and local snapshots; retain provenance.
- Eight canonical-only overlay headers were published unchanged in e0cda2d828.
- Trace experimental binaries and all build entrypoints before physical quarantine.
- Inventory and back up dirty worktree files before retiring local branches.
- Archive obsolete outputs only after dependency and active-worker checks.
- Retire the extra owner branch after unique work is reviewed and recoverable.

No source files, branches, worker folders, installed inputs or outboxes were
deleted by this navigation batch. Source reconciliation is still pending.
