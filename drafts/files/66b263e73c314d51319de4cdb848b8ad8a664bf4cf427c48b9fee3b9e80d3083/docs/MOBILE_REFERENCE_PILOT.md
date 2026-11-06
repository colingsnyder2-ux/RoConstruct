# Mobile donor pilot: Name, 2012 and 2008

This is an identity/provenance pilot for native recovery, not a new class swap.
No native class/header, active provider or target function label was changed.
No new exact-match, selected-provider, P5/P6 or server-credit gain is claimed.

## Input and extraction results

The user supplied an iOS `2.132.41333` IPA and its Ghidra export, plus an Android
`2.155.47886` APK. Hashes and original package details are in GHIDRA_REFERENCE.md.
The `research/mobile_reference.py index` command checks the iOS executable hash,
reads its Mach-O symbol/debug-map records and joins `functions.csv` by address.

- 415,406 symbol records; 58,950 named N_FUN entries with debug-map source/object
  provenance and donor function ranges.
- 89,125 CSV rows; 58,950 have an N_FUN at the same address. Address agreement
  supports pairing but is not proof of every inferred signature or decompilation.
- N_SO compilation paths, N_OSO object/archive paths and N_SOL include paths exist.
- Zero N_SLINE, N_LSYM, N_PSYM or recognized local type-definition records;
  no `__debug_*` sections were found. These records are a linker debug map,
  not a recovered full type database. Class fields/layouts remain target work.
- Ghidra's exported `size` and N_FUN range sizes are preserved separately. Do not
  equate them or use either as Windows function sizes.

LLVM documents that dsymutil uses executable symbol-table debug-map information
to find DWARF in original object files. Those original objects/dSYM are absent:
https://www.llvm.org/docs/CommandGuide/dsymutil.html
Record constants: https://github.com/llvm/llvm-project/blob/main/llvm/include/llvm/BinaryFormat/MachO.h

## 2012 Name family

Swap/dependency target: future 2012 native Name provider. Concrete first blocker:
identify the family and distinguish target semantics from compiler-only analogs.
Required source/provider: 2012-specific Name declarations, storage and methods.
Next proof: authenticate target container/atomic/lock declarations and build a
2012-capable isolated native verifier before any source/provider promotion.

Both Windows target executable hashes were verified against `clients/clients.json`.
Original assembly and per-method byte hashes are saved under
`work/mobile-reference-pilot/`; the reference kit includes those evidence files.

| Method identity | iOS donor | 2012 Windows | Evidence / limit |
|---|---|---|---|
| `Name::setOrderIndex()` | `00367acc` | `0067ee50` | Strong anchor: Name.cpp, identical assertions `ordered[i-1]->str != str` and `ordered[i-1]->sortIndex == i`, lines 98/103, backwards insertion loop and atomic rank increments |
| `Name::Name(char const* const&)` | `003679a8` | `0067f120` | Calls rank setter; constructs string at target `this+4`; dereferences pointer-reference argument; exact full class declaration not yet proven |
| `Name::map()` | `0036801c` | `0067f260` | Family call graph and function-static map initialization; exact container declaration remains open |
| `Name::declare(char const* const&)` | `00368168` | `0067f2e0` | Null input returns null-name; map find/insert; allocates target 32-byte Name and calls constructor. Target uses TBB read lock/upgrade; donor uses pthread mutex |
| file-static `declareNullName()` | `00368140` | `0067f460` | Calls declare with empty-string pointer-reference; stores result to target `00e2a1ac` |
| `Name::getNullName()` | `00367da8` | `0067f480` | Once flag `00e2a204`, callback `0067f460`, call-once helper `004015a0`, shared result `00e2a1ac` |
| `Name::lookup(std::string const&)` | `00367dcc` | `0067f4a0` | Read-locked map lookup; miss follows the same null-name callback/storage |
| `Name::lookup(char const* const&)` | `00367c58` | `0067f5b0` | Null pointer-reference returns null-name; otherwise temporary string delegates to string lookup |

The first mapping has an independent target string/source anchor. Remaining
identities are strongly corroborated by donor signatures and the anchored target
family's call graph/semantics; they are not byte-equivalent cross-platform code.

Important identity trap: the existing mined source at `src/2012-06/0067f480.cpp`
names a Guid::getLocalScope compiler analog. Its short singleton body can match
other functions. That analog is not original identity evidence. The target's
null-name/declare/rank-setter chain supports the Name identity above. Generic
`unit` labels on the disassembler output are also hints, not ownership proof.

## 2008 native integration relevance

Existing recovered Name source and original methods were examined read-only:
`rebuild/2008-06/native-classes/accepted/App/util/Name.cpp`, `NameNull.cpp`,
`native-headers/util/Name.h`, and the existing Name verification scripts.

| 2008 method | Target | Donor use / significant difference |
|---|---|---|
| `getNullName()` | `00554270` | Corroborates once-initialized shared singleton; target callback `00554160` and storage `009739d0` |
| `initNullName()` | `00554160` | Target declares empty name with dictionary index 0; 2013 declare has no dictionary-index argument |
| `declare(char const*, int)` | `00553f90` | Common interning behavior; 2008 retains dictionary/map coordination absent from donor signature |
| `lookup(std::string const&)` | `00554180` | Common lookup/miss-to-null behavior; target container and lock implementation must stay 2008-specific |
| `lookup(char const*)` | `00554290` | Common null-input/temporary-string delegation; later donor's const pointer-reference signature must not replace 2008 by-value pointer |

Practical blocker reduced: agents now have named source/object provenance and
explicit version differences, rather than guessing which donor declarations can
be transferred. This corroborates existing 2008 recovery; it does not count those
methods again. No source edit was warranted from this pilot. Name ABI/storage
unification, linked selection and runtime obligations keep their existing gates.

## Contributor handoff and next family

Use `Name.cpp getNullName` with the index query to avoid hundreds of templated
Name functions instantiated in other translation units. Preserve donor identity,
target address, independent anchors, contradictions and remaining proof in each
family's existing campaign record. Do not create a second mining campaign.

Next priority: authorized 2012 Instance parent/name family, anchored by reflection
strings and target call graph. For 2008, query the current native swap blocker
first (Instance/Reflection/serialization are possible consumers); do not replace
its queue with a general donor-porting campaign. Shared-header proposals go to
the lease owner. Contributor drafts remain inactive until independently reviewed.

The kit is prepared locally for offline distribution. The owner can share its ZIP
and SHA-256 receipt through the existing contributor distribution channel. It has
not been published to a public URL. Review/install tooling and routing docs through
normal findings integration before rebuilding the public Worker package; raw
binaries and indexes remain optional local inputs, outside Git and draft uploads.
