# RoConstruct

Native C++ recovery, original-binary matching, and verified client integration.

## Explore the project

| Area | Contents |
| --- | --- |
| [Native source map](2008-06/SOURCE_MAP.md) | Project-grouped navigation with canonical and public source links |
| [Reviewed workspace](workspace/) | Maintained source, tools, tests, research and build recipes |
| [2008-06 source](2008-06/) | Public native source view and build inputs |
| [Recovered functions](src/) | Address-indexed mined functions |
| [Native contributor guide](data/NATIVE_AGENT.md) | Setup, ownership and draft sharing |
| [Worker package](data/native-worker.zip) | [Package manifest](data/native-worker.json) |
| [Reconciliation status](reports/source-cleanup-20261107.md) | Source differences, archive and remaining review |

## Source authority

`work:workspace/rebuild/2008-06` contains reviewed native source. Public
`2008-06/native-*` paths are reconciled per method and header. Drafts, mined
functions and historical snapshots retain their provenance and separate status.

Browse by project without changing compiler include paths or proof identities.
Stored source, exact methods, selected providers and runtime-verified swaps are
different milestones; the source map reports stored-file comparisons only.

## Contribute

Start with the [native guide](data/NATIVE_AGENT.md). Existing contributors can
share incomplete drafts without creating a fork. Owner review checks identity,
dependencies, ABI and required runtime gates before activation.

`main` provides bootstrap, `work` maintains recovery, and `gh-pages` hosts the site.
Historical material remains indexed under [migration](migration/), [archive](archive/)
and [drafts](drafts/).
