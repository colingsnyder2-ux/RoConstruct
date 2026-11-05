# Library completion campaign — 2026-10-11

Scope: 2008-06 only. No 2009-12 access or paid model calls. Only authoritative
group-server verification credits gains. Existing matching/data guards remain in
force; each submission must beat a freshly fetched server score.

## Results

Final machine-readable totals and coverage: `work/library-fill-20261011/summary.json`.
The coverage tables use approximate RTTI/unit attribution; before/after totals
include concurrent workers. Campaign gains come exclusively from its recorded
verified submission responses, deduplicated by address.

| Experiment | Outcome |
| --- | --- |
| Full RTM MFC/XTP sweep | 531 additional configurations; 15 compile errors preserved; no new exacts |
| MFC core implementation macro | 12 configurations compiled; no gains |
| Real application headers for observed template types | 3 types × 2 configurations; no gains |
| Assertion line repair | 8 exacts; 3 earlier rejected candidates recovered by same-size candidate selection |
| Referenced literal/filename repair | 3 exacts from 4 candidates; 65 diagnostics |
| Repaired-source propagation | 11 donors scanned against unresolved code; 5 additional exacts |
| Nearly complete vendor units | All 14 eligible units; 22 targets, 66 candidates, 16 distinct partial improvements, no exacts |

Final total: **16 new server-verified exacts, 16 improved partials, $0 AI spend**.
All scans and the final repaired-source propagation pass completed.
These gains exclude the preceding campaign's 93 exacts and the independent 2016
source pilot.

## Implementation and evidence

`benchmarks/claude_continuation.py` compiles with a bounded prefetch queue (three
workers in the full sweep); matching, submissions and journal writes stay serial.
Source hashes suppress completed configurations. Dependency manifest stamps avoid
replaying stale compilation failures after the RTM desktop-header repair.

`benchmarks/library_fill.py` reuses actual vendor/application definitions. The MFC
macro follows the vendor `stdafx.h` branch. Template types come from binary RTTI;
their fields are supplied by genuine headers. No sizes, fields or ABI stubs guessed.

Assertion repair accepts equal-length bodies whose only unmasked differences are
same-opcode immediate pushes corresponding to assertion lines in the source. It
changes line directives, then recompiles and verifies the complete target. Binary
referenced strings provide filename/literal evidence. Original vendor files remain
intact; generated copies keep rejected changes isolated.

Successful repairs were propagated across all unresolved code functions. The
assertion scan expanded from 99% to 95–99% stored scores. Same-size candidate ranking
avoids expensive unrelated-function comparisons; earlier targets are rechecked
under that comparison version. Every diagnostic and rejected trial remains saved.

Artifacts: journals, source snapshots, candidate files, diffs, server responses and
before/after score snapshots under `work/library-fill-20261011`. Full RTM journal
remains in `work/claude-continuation-20261011/rtm.jsonl`; rows after the first 83 belong
to this campaign. `summarize.py` refreshes only the allowed client and verifies that
campaign gains remain stored at least at their accepted scores.

## Validation and remaining work

`py -3.12 -m pytest tests -q`: 320 passed, 2 skipped, 16 existing warnings.
Focused assertion-evidence and bounded-prefetch tests passed after the final edits.
Bare repository-wide pytest collection encounters an existing standalone script's
`SystemExit`; the maintained suite is `tests`.

G3D targets 00471590, 00478f80 and 0047fbe0 are now verified exact: the original
ranking selected a different-sized compiled function. Restricting candidates to
the required size recovered the correct assertion evidence.

Next ranked experiment: compiler/settings search limited to the 16 improved vendor
targets and their exact siblings. The broad RTM/core/template pilots do not justify
larger blind sweeps.

Follow-up compiler-settings pilot then scaled to all 16 improved targets. It tested
one flag or compiler build change at a time: 90 configurations in the pilot/scale
journal. Result: **7 more server-verified exacts and 7 partial upgrades**; five
unique exact donor sources were propagated with no additional wins. These results
are recorded under `work/library-settings-20261011`.

Automatic approval review blocked a temporary-verifier launch with the generic
reason “blocked by policy.” The campaign used the already-running authoritative
group server instead. No temporary verifier was launched as a workaround.
