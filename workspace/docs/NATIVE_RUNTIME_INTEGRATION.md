# Native MD5 provider in a runnable client

The optional normal-client profile selects the recovered `RBX::MD5HasherImpl`
and `MD5Hasher::create` instead of the donor implementations in ContentProvider.
Seven native methods, original 40-byte layout and five-slot interface are checked.
The source-built ContentProvider remainder preserves unrelated bodies, relocation
identities and named data; every other archive member stays byte-identical.
No binary function stripping, stubs or address patches are used.

This is a real provider replacement in the existing P6 shell. It does not complete
the CRobloxApp/CMainFrame/CRobloxDoc/CRobloxView swaps, replace the whole engine,
establish full interactive P5/P6 acceptance or grant server credit.

With historical compiler/vendor/runtime inputs installed and existing UI build
prerequisites available, run from the authorized checkout using fresh paths:

```text
python rebuild/2008-06/p6/build_client.py rebuild/2008-06/out --out work/md5-client --native-md5 work/md5-proof
work\md5-client\Roblox.exe -p6-autoclose -p6-check-md5 rebuild\2008-06\tests\fixtures\lifetime-blocks.rbxl
```

The builder creates the proof bundle if absent. It runs the original-MSVC matching,
call/data/layout/vtable recorder and five exception-metadata graph audits, then
rechecks all recorded input/object hashes before source ownership transfer.
Existing stale proofs fail; choose a fresh proof directory after an input change.
`record_native_misc_leaves.py --out DIR` also generates an isolated matching bundle;
its `--help` does not compile. Diagnostic-only nonexact rows remain excluded.

`--out` uses a private engine overlay and frozen copies of the seven existing UI
objects. Missing prerequisites fail with their filenames; they are never silently
rebuilt over another worker's files. `--assets DIR` selects an already frozen UI
object directory. Shared source, vendor inputs, overlays, default client and other
workers' output remain untouched. Do not use a busy/shared output directory.

The ordinary link must succeed and its final map must select `NativeMD5Hasher.obj`
for all seven methods. Selection receipt is `native-md5-selection.json`; ownership
receipt is `md5-owner/receipt.json`; exact link arguments/log are retained beside
the executable. Neither link success nor those receipts alone establish runtime.

`-p6-check-md5` executes five known hash vectors through all three input overloads
and both result methods inside this client. A mismatch fails startup with nonzero
exit. Require its success marker plus clean fixture/asset loading, edit/save/reopen
and missing-file controls. Record the exact executable/map/input hashes. Full
interactive gates remain separate; never run the native-Doc diagnostic executable.

Keep progressing actual closure: current Doc diagnostic still needs an exact
`CWorkspace::write` lifetime/EH implementation. Native MD5 success does not bypass
that blocker or authorize selecting an incomplete main-class replacement.
