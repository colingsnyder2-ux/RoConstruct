# Interrupted Claude work: 2008-06 continuation

This continuation added **93 distinct group-server-verified exact functions**:
90 from binary-observed Boost/std template instantiations and 3 from desktop RTM
XTP headers. No AI calls or spend. Only 2008-06 was mined, compiled or submitted;
2009-12 was excluded. Prior Claude gains are not included in these 93.

| Experiment | Scope | New verified exacts | Decision |
|---|---|---:|---|
| Ogre 1.4.5 DLL replay | SceneManager, SceneNode, Entity, SubEntity | 0 | Exhausted these four source/settings combinations |
| RTTI template recovery | 42 observed vendor-only types, three flag combinations, header refinements | 90 | Expanded across every unresolved 2008 function; portable generator added |
| Desktop RTM recovery | 20-file pilot, then remaining PropertyGrid sources; 32 corrected configurations | 3 | PropertyGrid expansion complete; other RTM families remain untested |
| 2016-source retry | 10 units; 17 scored targets, one blocked; fanout over 7,219 open functions | 0 | No broad scale; see source2016-pilot-20261011.md |

## Template recovery

The earlier mangled-name parser truncated nested RTTI names and generated invalid
types such as `std::CArray`. The replacement reads complete NUL-terminated RTTI
type descriptors from the 2008 binary, decodes them with Windows DbgHelp's
`UnDecorateSymbolName` type flag, and retains only types supplied by vendor headers.
No application classes, sizes, fields, enum values or ABI stubs were fabricated.

The largest gains came from Boost iostreams gzip/stream-buffer and chain templates.
Adding the real `boost/iostreams/filtering_stream.hpp` header resolved the failed
chain/filtering instantiations and added 15 further exacts after the initial 75.
No gain came from the selected Ogre SharedPtr instantiations or Boost any holders.

There are 162 journaled template evaluations, including six repeated failed
configurations, hence **156 unique configurations**, not 162 distinct functions.
The 36 compile-error entries preserve initial missing-header failures. The final
38 compilable Boost translation units are in `roc/client_templates.py`; the existing
`templates-2008-06` recipe and its DLL variant generate these files on other PCs.
Hashed filenames preserve every accepted `roc-lib` reference. Windows DbgHelp is
needed only to discover new types; replaying the static generator also works with
the repository's Linux/Wine compiler path. No physical Linux replay was run here.

## RTM repairs

Two independent setup faults invalidated the previous RTM pilot:

1. The RTM variant rewrite handled `mfc-9.0/...` but not the source root
   `mfc-9.0`, leaving shared/static MFC on SP1 sources. The root rewrite is fixed.
2. The MSI placement script discarded the prefix before `atlmfc`. Windows CE
   files subsequently overwrote desktop files with identical names. The MSI
   table contains both `Vc7/atlmfc` and `Vc7/ce/atlmfc`; `afx.h` proved the mix
   through a CE-only CArray forward declaration and desktop compilation errors.

`benchmarks/rtm_desktop_repair.py` restored **613 desktop include/source files**
from the already-extracted, MSI-keyed cabinet members. The complete mixed tree,
old preprocessed caches and MSI member manifest were preserved under
`work/claude-continuation-20261011/rtm-desktop-repair/`.

The matcher caches compilation failures by directive text before expanding a
library dependency. Reusing an identical source reference therefore replayed
obsolete errors after the tree repair. Corrected RTM sources include a desktop
manifest hash comment, giving them fresh failure-cache keys without changing
matching rules or deleting another worker's cache. Cache invalidation after
dependency changes remains a general unresolved issue.

The corrected pilot used ten MFC and ten XTP files ranked by unresolved source
references. One PropertyGrid exact justified expansion to its other source files,
which added two more. Of 32 corrected configurations, 31 compiled; MFC wincore
still fails because its implementation defines dllimport static members. Actual
MFC implementation export settings need a separate evidence-based pilot.
The other 50 error entries in the RTM journal are retained setup/cache failures,
not evidence that desktop RTM vendor code cannot match.

## Cleanup and validation

83 server-downloaded partial files at retired function starts were moved to
`work/claude-continuation-20261011/retired-src/`, with full text, scores in their
original headers, original paths and SHA-256 hashes retained in `cleanup.jsonl`.
Hand-edited sources were retained. `roc lint 2008-06` then reported no issues.
No function-boundary changes were made in this continuation.

Every winning source was locally checked and independently recompiled by the
group server before credit. Submissions skipped functions already exact; no
stored scores were reduced. Six named Ogre rescore winners were checked and
already exact on the server, so they received no duplicate credit. Four Ogre
translation units were then checked against all remaining targets with no gains.

A temporary verifier on localhost:18768 used the same authoritative group
`work/server.db`, current recipe code, and only the 2008-06 verification scope.
It did not seed clients, publish the site or replace the running public server.
It was stopped after submissions. The canonical server remained available.

Final journals, generated source provenance, candidate sources, rejected compile
output and per-address submission receipts are under
`work/claude-continuation-20261011/`; totals are in `summary.json`.
The 2016 subagent kept its independent journals under
`work/source2016-pilot-20261011/`.

Final validation: **318 tests passed, 2 skipped**, with 16 warnings (existing
heartbeat test doubles and msilib deprecation). Worker and Server package audits
imported all 43 and 50 included modules respectively. All 93 credited addresses
were checked again against the canonical server and remained exact.

## Reproduction and next work

With the current library recipes, compiler 21022 and local vendor trees installed:

```
py -3.12 -m benchmarks.claude_continuation ogre
py -3.12 -m benchmarks.claude_continuation templates
py -3.12 -m benchmarks.claude_continuation rtm --limit 20
py -3.12 -m benchmarks.claude_continuation rtm --area PropertyGrid
py -3.12 -m benchmarks.source2016_pilot --units 10 --submit
```

Successful configurations resume from journal hashes. Do not repeat exhausted
template configurations hoping for additional credit. For a new target-table or
dependency revision, use a separate output directory or dependency stamp and
retain the original journals. RTM desktop extraction repair is intentionally
one-shot; it refuses to overwrite its recorded backup.

Next ranked work: repair referenced-data differences in older 99% vendor sources;
then pilot real MFC implementation export settings and other RTM source families.
Application-specific RTTI templates were deliberately not instantiated without
their genuine definitions. 2016 vendor releases differ substantially from 2008;
their value on later clients remains untested. Recovery-handoff leads were not
added to or changed by this continuation.
