# 2008-06 rebuild policy

Status: **provisional default, set 2026-10-25 by an agent pending the maintainer's decision.**
Until the maintainer replaces this file, the rules below hold.

## Default (in force)

- Every source family is **local-only**: RBXGS, OpenRBX (GPL-3.0), 2016 snapshots, XTP (commercial), MFC/ATL (Microsoft) and the open libraries. Builds read them from the contributor's own `tools/` trees.
- Tracked files may contain only:
  - the rebuild tooling (`roc/rebuild.py`);
  - this policy;
  - build recipes that name upstream files by path and hash.
  
  Copied vendor text is not allowed.
- `rebuild/2008-06/manifests/` and `out/` stay untracked (see `.gitignore`). They hold data derived from the client binary and object files built from vendor source.
- Nothing produced by the rebuild is published: not to the findings repo, not to the website, not to the server.

## Open decisions for the maintainer

1. For each family, decide whether it may be used locally, committed, or published.
2. The findings repo already publishes generated units derived from RBXGS/OpenRBX, and some containing MFC header text. On 2026-10-25, 1,230 more were captured into `local/units/generated-units.json`. Keep them, or audit them and add a provenance filter to `libs.capture_source_units`.
3. Where the integrated source tree lives: a private branch of this repo, or a separate private repo.
