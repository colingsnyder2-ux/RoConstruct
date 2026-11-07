# 2008-06 native rebuild

Recovering native classes and headers against the original 2008 client.

## Browse source

- [Project source map](SOURCE_MAP.md): WindowsClient, App, Network, Rendering and Base navigation.
- [Class implementations](native-classes/) and [headers](native-headers/).
- [Canonical native source](../workspace/rebuild/2008-06/): maintained work authority.
- [Source reconciliation](../reports/source-cleanup-20261107.md) and [storage audit](../reports/storage-audit-20261107.md).

The map groups existing files without rewriting includes or moving provider paths.
Mined functions, inactive drafts and runtime-selected code have separate status.

## Build inputs and verification

Run compile_test.bat with ROC_ROOT set to a configured RoConstruct checkout containing the historical compilers and dependencies. The default builds engine modules and runs their runtime harnesses. --smoke-only checks the toolchain; --tests-only relinks against a prior local build. Renderer failures are reported honestly; this is not yet a complete playable client.

- src/Client/: assembled native C++ and required assets.
- src/glue/: build glue.
- ../src/2008-06/: recovered functions and library build recipes (stable URLs).
- config/ and patches/: module definitions, overlays and their provenance. Native source already has the overlay applied.
- tests/: runtime harnesses, auxiliary sources, fixtures and launch scripts.
- scripts/: build and ABI checks used by RoConstruct.
- verification/: accepted integration history, proposal states, source locations and required binary-analysis manifests.

Build outputs stay local under work/. Compiler installs and external library dependencies are supplied by RoConstruct. Original vendor license notices remain with their sources. Package metadata is not a new acceptance receipt.
