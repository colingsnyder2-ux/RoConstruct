# 2008-06 rebuild policy

Status: **decided by the maintainer, 2026-10-26** (replaces the provisional default of 2026-10-25).

## Source families

- Every source family stays **local**: RBXGS, OpenRBX (GPL-3.0), 2016 snapshots, XTP (commercial), MFC/ATL (Microsoft) and the open libraries. Builds read them from the contributor's own `tools/` trees. Vendor trees and integrated source trees are not committed.

## What tracked files may contain

- The rebuild tooling (`roc/rebuild.py`, `rebuild/2008-06/*.py`), module specs, glue sources and this policy.
- Build recipes that name upstream files by path and hash.
- **Overlay patches** (`rebuild/2008-06/patches/`), including the vendor text they use as anchors and the corrected text they put in its place. The maintainer accepted that these are published: the main branch is public, and the RoConstruct server pushes it hourly (`roc/server.py`).

Whole vendor files are still not copied into tracked files: adopted 2008 headers are referenced by their generated unit's file name (`@replace`) and read from the local tree at build time.

## Untracked

- `rebuild/2008-06/manifests/` and `out/` stay untracked (see `.gitignore`). They hold data derived from the client binary and object files built from vendor source.

## Still open

1. The findings repo already publishes generated units derived from RBXGS/OpenRBX, and some containing MFC header text. On 2026-10-25, 1,230 more were captured into `local/units/generated-units.json`. Keep them, or audit them and add a provenance filter to `libs.capture_source_units`.
