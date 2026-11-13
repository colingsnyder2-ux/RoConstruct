# Native acceleration tools

These are development aids. They do not prove binary matching, ABI, provider
ownership, successful linking, runtime activation, or independent server credit.
Keep the original MSVC matching workflow and all existing integration gates.

## Tools on Colin's machine

- Ninja 1.13.2: `tools/native-accel-20261108/ninja.exe` (upstream archive SHA-256 `07fc8261b42b20e71d1720b39068c2e14ffcee6396b76fb7a795fb460b78dc65`).
- Mergiraf 0.16.3: `tools/native-accel-20261108/mergiraf.exe` (upstream archive SHA-256 `f29da2de294dcc99982de623a32234821681554ee6785edfb67e20c692bd2099`).
- LLVM `llvm-nm`: `C:\Program Files\LLVM\bin\llvm-nm.exe`.
- Ghidra 12.1.4, including BSim: `C:\ghidra\ghidra_12.1.4_PUBLIC`.

These paths are machine-local; binaries are not included in the worker package.
Other workers should install the tools from their official upstream distributions
and pass their own paths. For syntax triage, install the optional parser with
`python -m pip install tree-sitter==0.26.0 tree-sitter-cpp==0.23.4`.

## Incremental development compilation

```powershell
python -m roc.native_accel compile --ninja tools/native-accel-20261108/ninja.exe --build-dir work/native-ninja/my-batch source1.cpp source2.cpp
```

The wrapper reuses the existing `native_check_runner.py` flag selection and
MSVC 2008 RTM toolchain. Ninja records `/showIncludes` dependencies, and a
compiler/environment fingerprint forces rebuilds when those inputs change.
Each named directory has an exclusive lock. Build output and a receipt stay in
that directory. This is a development cache: Ninja normally tracks file times,
so do not use cached objects as independent evidence after files or timestamps
have been manipulated. Run the existing fresh matching, relocation, ABI and
runtime checks separately. This command compiles; it does not link or run a client.

In a two-source trial, first build compiled 2 files, unchanged build compiled 0,
and a private header change recompiled only its 1 dependent source. The real
Extents candidate produced the same 42 function bodies and relocations as the
existing fresh compiler run. This is a small trial, not a full-client benchmark.

## Three-way Mew merges

```powershell
python -m roc.native_accel merge --mergiraf tools/native-accel-20261108/mergiraf.exe --output work/my-merge.cpp base.cpp current.cpp donor.cpp
python -m roc.native_accel merge-batch --mergiraf tools/native-accel-20261108/mergiraf.exe --plan work/my-plan.json --output work/my-new-batch --workers 3
```

The batch plan has `{"items":[{"base":"...","left":"...","right":"...",
"source_path":"...","canonical_path":"..."}]}` and accepts 1–50 files.
Inputs must be a real common ancestor, current source and donor, respectively.
Outputs are new scratch files; originals are never overwritten. Reports include
hashes, conflicts, errors, and optional parser-based method triage. A clean merge
can still remove methods, change headers, or choose an inferior implementation.
Review every changed file and its ownership before promotion.

## LLVM object and archive index

```powershell
python -m roc.native_accel symbols --llvm-nm 'C:\Program Files\LLVM\bin\llvm-nm.exe' --output work/my-symbols.json one.obj another.lib
```

The report groups undefined symbols by referencing object and lists definitions
in the supplied objects/libraries. An archive member is a possible provider, not
proof the linker selects it. Referencing objects are not function-level callers.

## BSim

Ghidra's BSim runs from `C:\ghidra\ghidra_12.1.4_PUBLIC\support\bsim.bat`.
Create an isolated H2 database, generate signatures from an analyzed Ghidra
project, and commit those signatures as described in the [BSim CLI documentation](https://ghidra.re/ghidra_docs/GhidraClass/BSim/BSimTutorial_BSim_Command_Line.html).
`rebuild/2008-06/tests/NativeBSimQuery.py` provides a headless name-substring
query: pass database URL, function-name substring, and a new output JSON path as
post-script arguments to `analyzeHeadless.bat` while processing a program.
Check that the output JSON exists and contains results; Ghidra may exit zero
even if a script fails. Similarity is a lead, never proof of original identity.

For the existing local trial, the query command is:

```powershell
& 'C:\ghidra\ghidra_12.1.4_PUBLIC\support\analyzeHeadless.bat' `
  'C:\Users\colin\RoConstruct\work\native-candidates\mew-method-bulk-20261108\ghidra-project' NativeCompare `
  -process candidate.obj -noanalysis -scriptPath 'C:\Users\colin\RoConstruct\rebuild\2008-06\tests' `
  -postScript NativeBSimQuery.py `
  'file:/C:/Users/colin/RoConstruct/work/native-candidates/mew-method-bulk-20261108/bsim/native2008' `
  'Extents::faceCenter' 'C:\Users\colin\RoConstruct\work\native-candidates\my-new-bsim-result.json'
```

Use a new output filename every time. Query substrings must match no more than
50 functions. For another checkout, adjust the paths and use that checkout's
`rebuild/2008-06/tests` as the script path.

The isolated initial trial indexed the original executable and one Extents object.
Original analysis timed out at 120 seconds, so that database is incomplete.
Despite this, a query for `Extents::faceCenter` returned original address
`0060f7b0`; existing byte/reference proofs remain the authority. Ghidra currently
reports warnings about an existing GhidraMCP extension manifest; it was untouched.
