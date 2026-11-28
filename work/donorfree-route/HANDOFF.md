# Donor-free RobloxQT client: handoff and finishing guide (2026-11-27)

This directory builds `run/RobloxQT.exe`. It is a relink of the 2008-06 Roblox Studio client from three kinds of input:

- recovered native C++ sources;
- converted ("renamed") original functions;
- generated stubs and aliases.

The goal is a client that works like the original through every tier of `FEATURE_LADDER.md`:

1. Boot, File→New, Explorer, Insert Object, Run/Reset.
2. Tools.
3. Lua scripts.
4. Physics.
5. Play Solo.
6. `.rbxl` save/load.
7. Network.
8. Soak.

This file covers the current state, how to rebuild and test, every tool, the known bug classes and what is left.

> Older handoffs (still useful, partly superseded):
> - `../native-client/mass-tools/GEMINI_HANDOFF.md`
> - `../native-client/mass-tools/CLI_HANDOFF.md`
> - `../native-client/mass-tools/CLAUDE_RESEARCH_DOSSIER.md` (30 sections of static audits)
>
> Also read: `RULEBOOK.md` (bug-class workflow), `FEATURE_LADDER.md` (tiers), `codex_recovery_evidence.md`.

---

## 1. Current state

The build is `run/RobloxQT.exe`. It links cleanly: lld exit 0, no conflict rounds, 2 undefined names left.

The scorecard is `codex_feature_scorecard.py`, which runs the original side by side. Ours scores **129/146 (88.4%)**:

| Row | Result | Notes |
|---|---|---|
| T0/1/4 featladder (boot/new/run/reset) | 8/9 | |
| T1.2 insertsweep (every Insert class) | 25/25 | |
| T1/2/6 interactive edit + save | 16/16 | |
| T2 tooltest (16 Studio tools) | 16/16 | |
| T1/3/4 feature_test.lua (47 classes + physics) | 55/55 | |
| T5 solo_test.lua (Play Solo) | 7/7 | |
| T1/3-5 full_features_test.lua | **0/7** | See open issue A |
| T6.3 server/client survival | 2/2 | The test script was wrong for 2008; fixed (see below) |
| T1/2 keyboard shortcuts | **0/9** | Never run: the harness needs a foreground window |

Extra checks added on 2026-11-27, all passing on the current build:

- **`gridedit.py`:** select a Part, then type a value and press Enter in all 74 property-grid rows. No crash. Before the fix, the first edit crashed.
- **`auto/resizetest.py`:** 20 resizes, maximizes and restores. Survives.
- **`propsweep.py`:** 199 Lua property assignments across about 50 classes. None crash.
- **Hinge/Motor surface render** (`auto/repro/hinge.lua`): survives. Before the fix it crashed in `RbxSubEntity::getRenderOperation`.

### Fixed on 2026-11-27: four bug classes

All four are **wrong alias bindings**. The machine code matched the original on every crash path; the data or vtable bindings did not.

1. **Many-to-one data aliases.**
   - `aliases_renamed.txt` bound distinct original globals to one name. Examples:
     - 18 different `*Value` `desc_Value` descriptors → `ObjectValue::desc_Value`;
     - `adornCylinderMesh` (a MeshPtr), `explosionMaterial` and 3 more → `G3D::RenderDevice::dummyString`.
   - Every initializer wrote the same storage.
   - Fix: `quicktest.py` drops any `dat_X=T` line in `aliases_renamed.txt` whose `T` claims more than one `dat_`. Look for the `datcollide` block; `QT_NO_DATCOLLIDE=1` turns it off.
   - It is deliberately limited to `aliases_renamed.txt`. The other files hold legitimate duplicates: two IAT slots for one `__imp_`, folded COMDAT statics, hardaddr `_functor_type`. Dropping those broke stats drawing.
2. **A stale grow-only `aliases_bytealias.txt` line.**
   - `func_00773710` is XTP `CXTPPropertyGridInplaceEdit::SetValue` (vtable slot +0x160). It stayed bound to `boost::thread_resource_error::~thread_resource_error`.
   - Every property-grid edit therefore reset the edit control's vptr to `std::exception`, and the next call jumped into d3d11.
   - Fix: native `../native-client/stub-drafts/StubTh_00773710.cpp`, plus `bytealias.py` now re-verifies every kept line.
3. **Adjustor thunks bound to their target.**
   - `sub ecx,N; jmp <deleting dtor>` thunks were bound straight to FactoryProduct constructors or `create<T>`. This affected Pants, LegacyHopperService, Hole, GlobalSettings and Hint.
   - Hint's scalar deleting destructor `func_004a4d20` was bound to static `create<Hint>`, so `hint:Remove()` wrote a `shared_ptr` to address 1.
   - `func_00584b10` lost its `this` adjustment (−0x28c) to `getPrimaryPartInternal`.
   - Fix: `../native-client/stub-drafts/StubLive_ThunkFix.cpp` and override lines in `aliases_override.txt`. The competing lines are listed in `auto/alias_drop.json`.
4. **Import thunks lost from the main link.**
   - Codex's fix binding `func_0069fc5a` → `_FMOD_Memory_GetStats` and `func_0078c560` → `_GetSysColor@4` existed only in `codex_*_variant.py`.
   - Without it, those `ret`-mismatched stubs shifted the stack in the Sound stats update. The result was a crash painting the stats/report view on any resize or repaint.
   - Fix: both lines are now in `aliases_override.txt`.

Also fixed: the scorecard's network test called `NetworkClient:PlayerConnect`, which does not exist in 2008. The original rejects it too and exits. The test now uses `Players:CreateLocalPlayer(0)` and `NetworkClient:Connect(host, port, 0)`.

---

## 2. What you need

These are **not in git**; they total about 59 GB of generated data.

| Item | Where | How to get it |
|---|---|---|
| Original client | `clients/2008-06/Roblox.exe`, copied as `run/RobloxOrig.exe` with its runtime DLLs (`rgmain.dll`, `fmodex.dll`, mfc90/msvcr90, content folders) in `run/` | Your own copy of the 2008-06 client (`docs/SETUP.md`) |
| VS2008 SP0 compiler (`cl` 15.00.21022) | Set up by `roc.cmd` / `docs/SETUP.md` | `native_check_runner.py` compiles with it |
| Converted objects `renamed/obj/*.obj` plus `renamed/*.json` (rename.json, ordinals.json, …) | `work/donorfree-route/renamed/` (11 GB) | The donor-free pipeline: `donorfree_link.py` / `boot.py` cycle, converter retries (commit 80396bc685). Expect hours. |
| Native drafts and run results | `work/2008-06/native-check-runs/*`, listed in `linkexp/qt_results.txt` | Rebuild with `bindsrc.py SRC.cpp` for each draft, or re-run the class lanes |
| Link inputs | `link/donorfree.rsp`, `link/stubs.obj`, `linkexp/*` | Produced by the pipeline's last cycle link; `quicktest.py` reuses them |
| Registry | `work/2008-06/identity-registry.json`, `work/native-client/layout/function-files.json` | Repository tooling (`roc.cmd`) |
| Python 3.11+ | `pip install pefile capstone frida psutil` | `frida` is used by the crash probes |
| WinDbg Preview / TTD (optional) | Microsoft Store | Time-travel traces (§5) |

Run every client test on the **interactive desktop** (`WinSta0\Default`). Hidden sandbox desktops block D3D9 and OpenGL for both clients.

---

## 3. Build

```powershell
cd work\donorfree-route
python quicktest.py          # one link, about 4-5 min; writes run\RobloxQT.exe and linkexp\qt.map
```

Useful environment toggles for bisecting (each turns one fix family off):

`QT_NO_DATCOLLIDE`, `QT_SKIP_RESULTS=<run ids>`, `QT_SKIP_ALIASES=<alias file names>`, `QT_NO_COLALIAS`, `QT_NO_GADJ`, `QT_NO_DLLEXSTRIP`, `QT_NO_MSGMAPFIX`, `QT_NO_TIFIX`, `QT_NO_ALIASDROP`, `QT_OLD_CLASSGUARD`, `QT_OLD_AZERO`, `VTORIG_OBJ`.

To make one native C++ draft part of the link:

```powershell
python bindsrc.py ..\native-client\stub-drafts\MyFix.cpp   # compiles and makes it the qt_results.txt line
```

Then add `func_<addr>=<mangled name>` to `aliases_override.txt`. That file is read first and wins.

The owner's rules (also in the repository `CLAUDE.md`):

- Fix whole bug classes, not single crashes.
- Batch 10 to 30 compile-checked fixes, then link once. Linking is slow.
- No `__emit`, byte blobs or patched target bytes.
- Mark inferred code with `// INFERRED: <evidence>`.
- Lease native classes and core headers before editing (`roc.cmd lease take ...`).
- Never edit `clients/` or `tools/`.

---

## 4. Test

```powershell
python codex_feature_scorecard.py              # full scorecard, about 15 min, original vs ours
python featladder.py run\RobloxQT.exe          # T0/1/4 ladder
python scripttest.py run\RobloxQT.exe --lua feature_test.lua   # Lua checks via -script; writes auto\scripttest.json
python sweep.py                                # crash-and-continue script cases; auto\sweep_report.json
python gridedit.py run\RobloxQT.exe [--orig] [--frida] [--class Part] [--from N]   # property-grid edit walk
python propsweep.py run\RobloxQT.exe           # Lua property-set sweep with bisection
python auto\resizetest.py run\RobloxQT.exe [LUA] [--frida]                         # resize/repaint stress
```

Crash diagnosis, fastest first:

1. **Find the faulting function.** Use `auto\resizetest.py ... --frida` or `gridedit.py --frida`. Both print the access violation, a symbolised stack and C++ throw types.
   - `RT_HOOK=file.js` / `GE_HOOK=file.js` inject extra Frida hooks, such as a call site's register or vtable dump.
2. **Get a Win32 debugger stop.** `ATTACH_ARGS_FILE=lua.lua python attachcrash.py run\RobloxQT.exe 6 40` launches with `-script` and stops at the first second-chance exception.
3. **Trace throws and message boxes.** `ATTACH_ARGS_FILE=lua.lua python throwtrace.py EXE --post 0 --secs 20` reports every C++ throw (type and text) and every message box.
4. **Compare code.**
   - `python auto\cmpfn.py ORIG:OURS [-v]` diffs the original's function against ours.
   - `python auto\stuborig.py NAME...` finds which original function a called stub stands for.
   - `python auto\callers.py EXE TARGET [map]` lists call sites.
5. **Audit bindings.**
   - `python auto\aliasverify.py` compares every `func_X=NAME` alias against the original's code. Of 390 flagged lines, most are benign: different EH codegen, generated deldtor wrappers, mid-function chunks.
   - `python stubcall_audit.py` lists stubs that are still called.
   - `python vtaudit.py` checks vtable slots by address.
   - `python auto\vtcode.py` checks vtable slots by code. It is noisy because some vtables are paired with the wrong original.
6. **Time travel.** See §5.

**Rule of thumb from 2026-11-27:** if the crashing code matches the original byte for byte, the bug is a binding (alias, vtable slot, data alias or stub `ret N`), not codegen. Check `aliasverify.py`, then the vtable slots, then `auto/datcollide.json`.

---

## 5. TTD (time travel debugging)

- **One-time admin setup:** `ttd\setup_ttd_task.ps1`. It installs `C:\ProgramData\RoTTD\ttd_runner.ps1` and the elevated scheduled task `RoConstructTTD`.
- **Record without an admin shell:** `python ttdrun.py --out auto\ttd3 --secs 90 [--post 0xE100]`. The runner launches the exe with no arguments; `-script` is not supported yet.
- **Replay:** `python ttdq.py "<cdb commands>" auto\ttd3\RobloxQT01.run`. Useful commands: `!tt <pos>`, `ba w4 <addr>`, `g-`, `dx @$curprocess.TTD.Events`.
- **Remove when finished (admin):** `Unregister-ScheduledTask -TaskName RoConstructTTD -Confirm:$false; Remove-Item -Recurse C:\ProgramData\RoTTD`

---

## 6. Open issues (next steps, most valuable first)

A. **The full_features_test.lua R7 stage never reports.**
   - Ours reaches R6 (6/6). The original reaches R7 (7/7).
   - R7 is `wait(2)`, then `snd:Stop()`, `msg:Remove()` and `hint:Remove()` with the character and tool loaded.
   - Running the same script under `auto\resizetest.py ... --frida` with `RT_WAIT=25` did **not** crash. So check whether ours hangs, or whether the Explorer read happens too early (`scripttest_long.py`, 90 s).
   - The scorecard copy is `C:\Users\colin\.gemini\antigravity-cli\brain\...\scratch\full_features_test.lua`. A local per-step copy is `full_features_diag.lua`.

B. **The keyboard test never runs** ("foreground unavailable"). Give `codex_feature_scorecard.py:test_keybinds` a real foreground window, or post `WM_KEYDOWN` to the view.

C. **Script-error exit differs.**
   - With `-script 'error("x")'` the original exits (code 0, about 3 s); ours stays open.
   - When a C++ exception escapes a script (for example a nonexistent member), ours later crashes in `DataModel::closeDataModel` → `ChangeHistoryService::setEnabled` → `requirePermission` ("current security context cannot ChangeHistoryService.enabled"). The security identity is probably not restored on that path; look at an `Impersonator` destructor that is stubbed or skipped.

D. **About 18 RBX stubs are still called** (`stubcall_audit.py`). These are native draft objects calling functions nobody defines:
   - `Value::convert<TextureId>`
   - `JointInstance::setC1`
   - `TypedPropertyDescriptor<shared_ptr<DescribedBase>>::getStringValue`
   - `SpecialShape::getAlpha`
   - `shared_ptr<Script>(Script*)`
   - `ModelInstance::getCameraIgnorePrimitives` (3 vcall thunks)
   - `Joint::setJointOwner`
   - `Humanoid::getPrimitives`
   - `registerSound`
   - `IdSerializer::deserializeInstanceRef`
   - `permissionA/B`

   Instantiate or define them natively; see `rbxinst.py` for templates.

E. **Remaining `aliasverify.py` mismatches to review** (`auto/aliasverify.json`). Candidates:
   - `func_005d7560` renderMultiplayer
   - `func_004685b0` postMouseEvent
   - `func_006f7050` XTPEnumFontFamExProc
   - `func_0056cd80` `singleton<TextureId>`
   - mid-function `func_00455744`, `func_005e8287`, `func_006064f3`, `func_0062dccc`

F. **Codex's other variant-only fixes are not in `quicktest.py` yet.**
   - `codex_cache_variant.py` / `codex_zero_variant.py` resolve 3 calls to address zero: 2 `getLocalCachePath` calls, plus `pushArgs` via `_nx` for `0061fb20`.
   - Port them as `quicktest.py` was ported for the import thunks (§1.4). Then verify with `codex_zero_call_audit.py` and `codex_lua_call_audit.py`.

G. **Backlog carried from earlier handoffs:**
   - about 86–92 failing `rbxinst.py` templates (header mismatches);
   - Humanoid `BoundProp` constructors;
   - `composeClothingTexture` / `MaterialFactory` sret stubs;
   - `Body::getNextStateIndex` static initializer (value 1);
   - 2 zero-address names (`func_0055f940`, `func_0061fb20`);
   - `shard_libs.py`, to speed up linking.

H. **Final cleanup:** remove the `RoConstructTTD` task (§5) and the IFEO `RobloxPH.exe` registry key.

---

## 7. Files in this handoff

- **`work/donorfree-route/`:**
  - all `*.py` tools (index below);
  - `aliases_*.txt` (link aliases);
  - `*.lua` tests;
  - `*.md` docs;
  - `ttd/`;
  - the small `auto/*.json`/`*.txt` inputs `quicktest.py` reads;
  - `auto/*.py` probes.
- **`work/native-client/stub-drafts/*.cpp`:** native drafts bound into the link (`StubLive_*`, `StubTh_*`, `DllVtCopy.cpp`, `OgreConstImports.cpp`, `StubLive_DelDtor.cpp` generated by `deldtor_gen.py`, …).
- **`work/native-client/mass-tools/*.md`:** earlier handoffs and the research dossier.

Not included: generated objects (`renamed/obj`, `linkexp/*.obj`), executables, caches (`*.pkl`), traces, and the original client binaries.

## Appendix: tool index (first docstring line of each script)

| Script | Purpose |
|---|---|
| `abi_fix.py` | python abi_fix.py [--apply]: make every caller declaration of a draft helper match the helper's own definition, when that definition agrees with the original exe's ABI (callee `ret N` and ecx use, as autorecover.target_a |
| `accessalias.py` | python accessalias.py: stubbed C++ names whose twin differing ONLY in the access letter is defined. Converted analogs declared members with another access (doDeclare<sStarterPackService> public `SAABV01` vs the native |
| `alias_abi.py` | python alias_abi.py: every /alternatename alias whose decorated name implies a stack size (@name@N fastcall, _name@N stdcall, plain _name cdecl) is checked against the ret N of the function it resolves to in link/donorfr |
| `aliasaudit.py` | python aliasaudit.py: func_<A>=S aliases whose S is NATIVE code proven to be another original function. aliases_renamed.txt bound func_00490c30 (the original find<Service>) to the registry's folded name |
| `analogmap.py` | python analogmap.py ADDR [ADDR...]: for converted objects renamed/obj/<ADDR>.obj, line up the function's call relocations with the ORIGINAL function's call instructions (same offsets in an exact object) and print which O |
| `annot_dis.py` | python annot_dis.py ADDR [-n BYTES]: disasm of the original 2008-06 exe with string literals, IAT imports and known function names inline. |
| `attachcrash.py` | python attachcrash.py [EXE] [delay] [secs]: launch the client NORMALLY (no debugger at creation: no debug heap, no IsDebuggerPresent at startup), attach with DebugActiveProcess after `delay` s, and report the first acces |
| `audit3.py` | (no docstring) |
| `audits_all.py` | python audits_all.py: the binding audits in waves on the CURRENT map/exe (quicktest used to run them before every link: 231 s of a ~5 min link). quicktest now starts this right AFTER a link in the background; the next li |
| `auto\aliasverify.py` | python auto/aliasverify.py: for every func_<X>=NAME line in the alias files quicktest reads, compare the original's code at X with the code now linked under NAME (first 8 instructions, image addresses/rel32 masked, impor |
| `auto\audit_import_calls.py` | Compare indirect import calls in converted functions with the original. |
| `auto\audit_lock_unwind.py` | Compare converted Lock cleanup targets with original EH unwind maps. |
| `auto\batch2.py` | (no docstring) |
| `auto\bisect_cls.py` | (no docstring) |
| `auto\boost_patch_debug.py` | Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest symbols from the link map. python crashsite.py EXE MAP [seconds] |
| `auto\callers.py` | python auto/callers.py EXE TARGETHEX [mapfile]: list E8 call sites to TARGET in .text (with containing symbol if map given). |
| `auto\cmpfn.py` | python auto/cmpfn.py ORIG:OURS ... : side-by-side mnemonic diff of original vs our function (stops at first ret). |
| `auto\coverage.py` | (no docstring) |
| `auto\coverage2.py` | (no docstring) |
| `auto\fixnul.py` | (no docstring) |
| `auto\header_debug.py` | Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest symbols from the link map. python crashsite.py EXE MAP [seconds] |
| `auto\mfc_patch_debug.py` | Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest symbols from the link map. python crashsite.py EXE MAP [seconds] |
| `auto\native_debug.py` | Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest symbols from the link map. python crashsite.py EXE MAP [seconds] |
| `auto\native_debug2.py` | Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest symbols from the link map. python crashsite.py EXE MAP [seconds] |
| `auto\ogremain_audit.py` | (no docstring) |
| `auto\ogremain_audit2.py` | (no docstring) |
| `auto\onecase.py` | (no docstring) |
| `auto\peek.py` | (no docstring) |
| `auto\peekdtor.py` | (no docstring) |
| `auto\peekfault.py` | (no docstring) |
| `auto\peekfind.py` | (no docstring) |
| `auto\peekfind_orig.py` | (no docstring) |
| `auto\peekop.py` | (no docstring) |
| `auto\peekop_orig.py` | (no docstring) |
| `auto\peekset.py` | (no docstring) |
| `auto\peekthis.py` | (no docstring) |
| `auto\peekthis14.py` | (no docstring) |
| `auto\peekvc.py` | (no docstring) |
| `auto\peekvc14.py` | (no docstring) |
| `auto\peekwrap.py` | (no docstring) |
| `auto\probe_anycast.py` | Trace reflection-to-Lua conversion calls for focused feature failures. |
| `auto\probe_physics.py` | Count physics pipeline calls during the falling-part reproduction. |
| `auto\probe_script_entry.py` | (no docstring) |
| `auto\resizetest.py` | python auto/resizetest.py [EXE] [LUA]: launch, then resize/maximize/restore the main frame 20 times; report survival. |
| `auto\run_boost_patch.py` | (no docstring) |
| `auto\run_header_break.py` | (no docstring) |
| `auto\run_mfc_patch.py` | (no docstring) |
| `auto\run_mfc_trial.py` | (no docstring) |
| `auto\run_native_trial.py` | (no docstring) |
| `auto\run_native_trial2.py` | (no docstring) |
| `auto\run_trace_regs.py` | (no docstring) |
| `auto\stub_bind.py` | (no docstring) |
| `auto\stub_check_mined.py` | (no docstring) |
| `auto\stub_left_check.py` | (no docstring) |
| `auto\stub_measure.py` | (no docstring) |
| `auto\stub_native_hits.py` | (no docstring) |
| `auto\stub_results_build.py` | (no docstring) |
| `auto\stub_stdinst.py` | python stdinst.py [--jobs N]: replace stubbed std:: template members (std::list/vector/_Tree/... instantiated on our types: 11k of the 21k stubs, all returning 0) with REAL code: demangle each, write an explicit instanti |
| `auto\stub_stdinst2.py` | python stdinst2.py [--jobs N]: phase 2 of stdinst.py: stubbed std:: members whose template arguments are user types BY VALUE (std::vector<RBX::Foo>) need the full type: include the native header that defines it (index of |
| `auto\stub_stdinst3.py` | python stdinst2.py [--jobs N]: phase 2 of stdinst.py: stubbed std:: members whose template arguments are user types BY VALUE (std::vector<RBX::Foo>) need the full type: include the native header that defines it (index of |
| `auto\stub_symtry.py` | (no docstring) |
| `auto\stub_symtry2.py` | (no docstring) |
| `auto\stub_symtry3.py` | (no docstring) |
| `auto\stuborig.py` | python auto/stuborig.py NAME_SUBSTR...: for each called stub whose name contains a substring, align our call sites with the original caller (converted objects are named <origaddr>.obj) and print the original call target  |
| `auto\trace_regs_debug.py` | Run a 32-bit exe under a ctypes debugger; print the first exception's address, registers, stack words, and the nearest symbols from the link map. python crashsite.py EXE MAP [seconds] |
| `auto\verify_data_strings.py` | Check original string tails survive data reconstruction while pointers are cleared. |
| `auto\verify_settings_lock.py` | Verify loadState releases its settings lock, including on exception. |
| `auto\vtcode.py` | python auto/vtcode.py: code-level vtable audit. For every vtable vtaudit.json pairs with an original vtable, compare each slot's TARGET CODE (orig slot target vs our slot target; first 6 instructions, image addresses/rel |
| `auto\watchw.py` | (no docstring) |
| `auto\wheeltest.py` | Compare real mouse-wheel input in the viewport and Explorer (requires interactive desktop).  |
| `auto\zeroreloc_scan.py` | (no docstring) |
| `auto_aliases.py` | python auto_aliases.py: write aliases_auto.txt (symbol=target lines for /alternatename) linking draft helper names to the function that another draft actually defines for the same address. |
| `auto_dashboard.py` | python auto_dashboard.py: render work/donorfree-route/auto/results.json (autorecover.py output) as auto/dashboard.html (auto-refreshing every 20 s). Open the file in a browser. |
| `autoflip.py` | python autoflip.py [--max N] [--par P]: crash-driven exact-vs-native search, unattended and PARALLEL. Every startup crash so far was an exact copy and a native/library copy disagreeing. For the functions on the current |
| `autoloop.py` | python autoloop.py [--no-link]: one round of the batch loop. link (quicktest 0, gate included) -> featladder -> if the score beats the good baseline: linkgate --promote |
| `autorecover.py` | Automated recovery loop for boot stubs (LLM workers). For each target function address:   packet (annotated 2008 disassembly + class header excerpt + donor/OpenRBX analog by Class::method name + a sibling native source) |
| `behavior_oracle.py` | python behavior_oracle.py [--max 600] [--secs 15]: behavioral differential test orig vs rebuilt exe. Hooks non-byte-exact functions (auto/reccmp_map.json ratio<1) in run/RobloxOrig.exe and run/RobloxQT.exe, records |
| `bindcheck.py` | (no docstring) |
| `bindcheck_wrong.py` | Static audit of auto/bindcheck.json 'wrong' (WRONG/PROVEN misbindings) against CODEX_RESULTS.txt, GEMINI_RESULTS.txt, shared-layouts/*.json, and linkexp/qt.map. |
| `bindsrc.py` | python bindsrc.py SRC.cpp [SRC2.cpp ...]: compile the sources with native_check_runner (one run), then make that run the only qt_results.txt line for each source (older runs of the same source are removed; later lines wi |
| `bodymatch.py` | python bodymatch.py [EXE MAP]: masked-body hashes of every original function (cached auto/orig_hash.json) and of our exe. Our named functions whose body equals a DIFFERENT original address = mislabels; original bodies ab |
| `boostfn_gen.py` | python boostfn_gen.py: scans linkexp/qt.map for stubbed boost::detail::function::functor_manager and [void_]function_obj_invokerN instantiations -> emits one explicit-instantiation .cpp per unique |
| `boot.py` | One-command boot cycle: relink the donor-free exe (skipping links whose inputs did not change) and probe it once.  |
| `boundfunc_gen.py` | python boundfunc_gen.py: scans linkexp/qt.map for stubbed BoundFuncDesc<C, Sig, N> (and 2-arg BoundFuncDesc<C, Sig>) instantiations -> emits one explicit-instantiation .cpp per specialization |
| `boundprop_gen.py` | python boundprop_gen.py: stubbed BoundProp<T,1>::BoundPropGetSet<C> constructors (the converted static initializers call them out of line with the analog's `BoundProp*` spelling, PAV123@) -> explicit instantiations of th |
| `bytealias.py` | python bytealias.py: bind stubbed func_<X> to code our link ALREADY has under another name. Unnamed library functions (XTP's tab paint-manager / docking helpers, func_0077da70...) are in the linked XTP objects, but with  |
| `callaudit.py` | python callaudit.py [EXE MAP]: call-identity audit of converted functions. Each converted func_<X> (object <X>.obj) is the original's code: for every rel32 `call` at the same offset in our function and in the original at |
| `callfix.py` | Call-identity repair for converted objects (callaudit.py finds them): a converted func_<X>'s call to an analog callee NAME that our link defines as real code of ANOTHER function (func_00792440 -> boost::basic_regex::comp |
| `callfix_validate.py` | python callfix_validate.py: prune auto/callfix_plan.json (grow-only) to renames the ORIGINAL confirms. A rename S -> func_T in converted object X is dropped only when, in an instruction-aligned prefix of X's original bod |
| `callidentity_batch.py` | Diagnostic batch finder for misbound call identities (read-only).  |
| `callpair.py` | python callpair.py: bind func_<T> stubs through native functions PROVEN exact against the original. In an exact native body each relocated call/jmp names a symbol S, and the original calls address T at the same offset, s |
| `childwins.py` | python childwins.py EXE [secs] [orig]: launch, File->New at 8 s, at `secs` list the main window's child tree (class, visible, size). |
| `classdesc.py` | python classdesc.py: converted Described<C>::classDescriptor() copies that build a SECOND ClassDescriptor in a dat_ static while the native classDescriptor<C> builds the real one. StarterPackService instances carried the |
| `classnames_gen.py` | python classnames_gen.py: class-name globals (?sPart@RBX@@3PADA, ?sMotor@RBX@@3PBDB ...) that our link left as stub DATA (zero blocks): every such class was declared with the name "" -> one shared Name for Part/ServicePr |
| `classscan.py` | python classscan.py: static scan of the last link (linkexp/qt.map + renamed/rename.json) for known bug CLASSES, so a whole class is fixed in one batch instead of one crash per run. Seconds; read-only. Writes auto/classsc |
| `classsweep.py` | python classsweep.py [EXE] [--secs 60]: crash-and-continue sweep of EVERY registered class in one client run. After File->New, walks AbstractFactoryProduct<Instance>::getCreators() (std::map<const Name*, ICreator*>) and  |
| `classtree.py` | python classtree.py [EXE]: after File->New, walk the reflection class tree from ClassDescriptor::rootDescriptor() (derived-class vector at +0xb0 first / +0xb4 last / +0xb8 end) and flag every descriptor whose vector is |
| `closure.py` | python closure.py [--rounds N]: convert mined 100% analogs for the File->New path and everything they call, until closed. Round: rename.py (ROC_RENAME_DEFINED = symbols the donor-free link defines, plus the set) -> every |
| `cmdcensus.py` | python cmdcensus.py [EXE] [--orig run/RobloxOrig.exe] [--jobs 4] [--ids auto/FILE] [--limit N] Crash census of every UI command id (menus, toolbars, string-table prompts of the ORIGINAL exe) in ours vs the original. |
| `cmpfn.py` | (no docstring) |
| `cnames.py` | python cnames.py: C-spelled undefined names (_name) that NO linked object ever calls (only DIR32 references, never REL32) are variables: a code stub for them (`mov eax,0; ret` in .text) faulted when call_once wrote the f |
| `codecollide.py` | Colliding analog CODE names: twin of collidefix.py for CODE (0x401000..0x7c0000). Converted objects reference generic analog function names (?initMoo@@YAXXZ, ?moo2@@YAAAVmutex@boost@@XZ, |
| `codematch.py` | Relocation TARGETS are compared too (masked bytes alone matched 357/358 same-shaped deleting destructors and thunks that call different functions): every relocated operand of the candidate names a symbol that must be one |
| `codex_cache_launch.py` | (no docstring) |
| `codex_cache_variant.py` | python quicktest.py [secs]: test a fix NOW without waiting for a cycle round. Takes the cycle's last link inputs (link/donorfree.rsp + link/stubs.obj), swaps in the current converted-object set (renamed/results.json) and |
| `codex_census_capture.py` | python fastcensus.py [EXE] [--ids auto/crashcont_ids.json] [--cap 3]: fast command census. One client runs the commands back to back (PostMessage WM_COMMAND, then a SENT WM_NULL returns as soon as the command finished; a |
| `codex_fastcensus.py` | python fastcensus.py [EXE] [--ids auto/crashcont_ids.json] [--cap 3]: fast command census. One client runs the commands back to back (PostMessage WM_COMMAND, then a SENT WM_NULL returns as soon as the command finished; a |
| `codex_fault_probe.py` | (no docstring) |
| `codex_feature_scorecard.py` | Unified Feature Scorecard for RobloxQT.exe vs RobloxOrig.exe across FEATURE_LADDER Tiers 0-6. |
| `codex_fmod_probe.py` | (no docstring) |
| `codex_import_thunk_audit.py` | Find linked stubs that replace direct import thunks in the original client. |
| `codex_import_thunks.py` | Resolve original import thunks only when a DLL-specific symbol is unambiguous. |
| `codex_import_variant.py` | python quicktest.py [secs]: test a fix NOW without waiting for a cycle round. Takes the cycle's last link inputs (link/donorfree.rsp + link/stubs.obj), swaps in the current converted-object set (renamed/results.json) and |
| `codex_lua_call_audit.py` | Compare Lua helper direct-call target names with original registry identities. |
| `codex_noopfree_launch.py` | (no docstring) |
| `codex_noopfree_variant.py` | python quicktest.py [secs]: test a fix NOW without waiting for a cycle round. Takes the cycle's last link inputs (link/donorfree.rsp + link/stubs.obj), swaps in the current converted-object set (renamed/results.json) and |
| `codex_repeat_census.py` | Serial repeated census runner: python codex_repeat_census.py EXE TAG N [--ids FILE]. |
| `codex_script_crash_capture.py` | Capture exceptions from one -script client run.  |
| `codex_scripttest.py` | python scripttest.py [EXE] [--orig run/RobloxOrig.exe] [--lua FILE]: FEATURE_LADDER Tiers 3-4 without UI driving. Launches the client with `-script "<lua>"` (the command line the app itself builds for Play Solo), the Lua |
| `codex_sound_link_audit.py` | Verify selected Stats string constructor, caption imports, and Sound update slot. |
| `codex_zero_call_audit.py` | Verify three original direct calls do not resolve to address zero. |
| `codex_zero_launch.py` | (no docstring) |
| `codex_zero_variant.py` | python quicktest.py [secs]: test a fix NOW without waiting for a cycle round. Takes the cycle's last link inputs (link/donorfree.rsp + link/stubs.obj), swaps in the current converted-object set (renamed/results.json) and |
| `coffstub.py` | Write stubs.obj directly (no MASM): .text with one stub per function (mov eax,imm32; ret [n]), .data with data stubs. write(path, funcs=[(name, imm, ret_n)], data=[(name, initial_bytes, size)] or [(name, initial_bytes, s |
| `colalias.py` | python colalias.py: zero-stubbed dat_<X> placeholders that are the original's RTTI CompleteObjectLocators (vtable[-1] of vt_orig/vt_orig_remap tables: Backpack, Shirt, Pants, Tool, HopperBin ... -> dynamic_cast / askSetP |
| `collidefix.py` | Colliding analog DATA names: converted objects reference generic analog names (?flag@@3JA, ?G@@3DA, ??_7S@@6B@, ?g_value@@3HA ...) that renamed/rename.json maps to DIFFERENT original addresses in different objects. Linke |
| `comdatdiv.py` | python comdatdiv.py [RSP] [--jobs 8] [--top 60]: COMDAT divergence audit (static, no link). Every COMDAT (inline function, template, vtable, string literal...) defined by more than one object in the link |
| `convpair.py` | python convpair.py: stubbed NAMES called by converted objects, bound through the original's call targets. A converted object (renamed/obj/<A>.obj) is the original function's own code, so its relocated call at offset k go |
| `crashcapture.py` | (no docstring) |
| `crashcont.py` | python crashcont.py [EXE] [--ids auto/cmdcensus_ids.json] [--gap 1.5] [--skip-new]: crash-and-continue census. ONE process: Frida saves esp/return address/SEH head at every USER32 DispatchMessageW/A entry on the UI threa |
| `crashfix.py` | python crashfix.py [--rounds N] [--secs S]: unattended File->New crash loop. Each round: relink (boot.py --no-probe), probe on the real desktop with the window kept behind other windows (second-chance |
| `crashlist.py` | python crashlist.py [secs]: EVERY crash site on the startup + File->New path in ONE run, instead of one crash per relink. Runs oneshot.py with SKIPAV=200 + SKIPAV_ANY=1 (crashsite skips faulting loads, fake-returns 0 fro |
| `crashprobe.py` | (no docstring) |
| `createfix.py` | python createfix.py: stubbed func_<X> that are really Creatable<Instance>::create<T>() (the original body mallocs, calls T's constructor and wraps the object in a shared_ptr) -> aliases_createfix.txt func_<X> = our linke |
| `createinst.py` | python createinst.py: Creatable<Instance>::create<C>() instances our link only has as stubs (Insert Object's Creator<BodyPosition>::create called func_005c2150 -> `return 0` -> NULL deref). A stub whose ORIGINAL body is  |
| `creator_gen.py` | python creator_gen.py: FactoryProduct<T,D,N>::Creator members our link left as `return 0` stubs: Creator() (the creators-map registration: Decal, Hint, Message, StringValue... never registered -> create(name) NULL), ~Cre |
| `creatorinit.py` | python creatorinit.py: run the ORIGINAL factory-creator registrations that no native object performs. Insert Object listed 23 of 41 classes: AbstractFactoryProduct<Instance>::create found no creator for BoolValue, Decal, |
| `creatorstub.py` | python creatorstub.py: every FactoryProduct<T>::Creator vtable in our exe whose create slot (or the first calls inside it) lands on a `return 0` stub -> Insert Object / AbstractFactoryProduct::create(name) gets NULL for  |
| `cycle.py` | python cycle.py [--no-link] [--no-ladder]: one fix cycle. Runs every bulk fixer on the LAST map (each is static or compiles only its own generated sources), records new results.json files in work/native-client/STUB_RESUL |
| `data_zero_audit.py` | python data_zero_audit.py: compares every non-code (.data/.rdata) global symbol in snapshot RobloxQT.exe against original Roblox.exe (matched via identity-registry.json and dat_00xxxxxx |
| `dataaudit.py` | python dataaudit.py [EXE MAP]: data-binding consistency of converted functions. Every converted func_<X> is the original's code, so each absolute pointer into original data (0x7c0000-0x9a0000) at offset k pairs ONE origi |
| `datafix.py` | Data-identity repair for FOREIGN analogs: a converted func_<X> compiled from another function's source (rename.json: renamed analog name != the target's name) keeps that source's data names. When those names are real glo |
| `datatype_audit.py` | python datatype_audit.py: converted objects bind each analog global (?nativeAdornCount@RBX@@3HA, an int) to the name the registry has at that original address (?dummyString@RenderDevice@G3D@@0V?$basic_string..., a std::s |
| `datcode_alias.py` | python datcode_alias.py: dat_<A> placeholders whose A is in the original's CODE section (??__F atexit functions at 007fa230..., callback pointers in copied tables): referenced as data, they became 4 KB of zero data, so w |
| `declare_gen.py` | python declare_gen.py: stubbed Name::declare<sX>() / doDeclare<sX>() / callDoDeclare<sX>() (64 `return 0` stubs: ClassDescriptor ctors got whatever eax held as their Name& -> 7 classes shared one garbage Name, Part/Motor |
| `defined_now.py` | python defined_now.py: the names the donor-free link really defines NOW: native objects (link/obj_ext_cache.pkl, kept fresh by auto_aliases.py) + every public symbol of every .lib in link/donorfree.rsp (archive linker me |
| `deldtor_gen.py` | python deldtor_gen.py: compiler-generated deleting destructors (??_G/??_E, registry kind `gen`) and the this-adjusting thunks in front of them (kind `adjustor`) that our link left as `return 0` stubs. They sit in the cop |
| `descinit.py` | python descinit.py: run the ORIGINAL reflection-descriptor initializers that no native object performs. `part:Remove()` failed ("Remove is not a valid member of Part") for every class: Instance's function descriptors |
| `diff_variants.py` | (no docstring) |
| `difftest.py` | python difftest.py [secs]: function-level differential test, original exe vs the current build (run/RobloxQT.exe). Both run File->New under the same one-shot entry breakpoints (functions reachable in the original, paired |
| `difftrace.py` | python difftrace.py [secs]: run the ORIGINAL exe and ours under the same one-shot entry breakpoints (functions whose bodies are identical in both: auto/bodymatch.json pairs, File->New-reachable first) with the same File- |
| `difftrace2.py` | python difftrace2.py --post 0xE100,0x807f [--secs 25] [--max 3000] First-divergence finder: one-shot entry int3s on N converted functions (original address A in RobloxOrig.exe, our address |
| `dis_linked.py` | python dis_linked.py ADDR [N]: disasm the donor-free exe (link/donorfree.exe) with map symbols for call targets. |
| `disasm.py` | (no docstring) |
| `disasm2.py` | (no docstring) |
| `disasm3.py` | (no docstring) |
| `disasm4.py` | (no docstring) |
| `disasm5.py` | (no docstring) |
| `dll_data_audit.py` | python dll_data_audit.py: read-only static audit that finds EVERY DLL-exported DATA symbol referenced without __declspec(dllimport) in the linked binary. |
| `dllexstrip.py` | dllexstrip.py (quicktest pass): rgmain.dll exports Ogre's inline/template code itself (Singleton<T>::getSingletonPtr, StringInterface::getParamDictionary ...), but the converted analog TUs and native Ogre drafts carry th |
| `dllimports.py` | python dllimports.py: an import library for every function our link only has as a STUB although a DLL really exports it (FMOD's C API in fmodex.dll, the GDI+ flat API, the CRT's _invalid_parameter*...). The probe's LIVE_ |
| `dllsym.py` | python dllsym.py ADDR [ADDR...]: name DLL addresses from a probe (72e4616c -> msvcr90.dll!strlen+0x1c). Starts the client briefly to read each 32-bit module's load base (system DLL bases are fixed per boot), then picks t |
| `dllvt.py` | python dllvt.py: exe-local copies of rgmain.dll vtables / RTTI / const data that our link only has as jmp THUNKS. Analog TUs and native Ogre drafts were compiled without dllimport, so `mov [ecx], offset ??_7X@Ogre@@6B@`  |
| `donor_header_scan.py` | Which 2007 rbxgs donor Roblox headers do native sources still read? Preprocess-only (`cl /EP /showIncludes`).  |
| `donor_paths.py` | Path candidates for held native files: the classes each file defines (Class::member definitions), looked up in the 2007 rbxgs donor tree (which file defines Class::...). Evidence only; a weak, inferred-tier signal. |
| `donorfree_link.py` | Donor-free link: every native object from a donor_free trial run + vendor libraries only (no content-without-donor-log or P2*/owner libs, no tools/rbxgs objects). The linker's own unresolved-external list is the honest g |
| `donorfree_link_parse.py` | (no docstring) |
| `draft_imports.py` | python draft_imports.py: drafts stand in for import slots with invented function-pointer variables (AutoRecover_004f0920: `extern DestroyStringFunction destroyString; destroyString(this)` where the original calls |
| `dropcheck.py` | python dropcheck.py: re-verify auto/alias_drop.json. aliasaudit drops func_<A>=S when it decides our S is another original function; it dropped func_005aefa0=?openState@ScriptContext@RBX@@AAEXXZ although the native openS |
| `dtoraudit.py` | python dtoraudit.py: authoritative destructor address of every polymorphic class in the ORIGINAL, from RTTI: COL (offset 0) -> vtable -> the slot whose body is a deleting destructor -> the ~T it calls. Compared with the  |
| `dtorfix.py` | Mislabeled destructors: dtoraudit.py finds, from the ORIGINAL's RTTI (COL -> vtable -> deleting destructor -> the ~T it calls), the true ~T address of every polymorphic class; for 65 classes the identity registry gives ? |
| `dtorslots.py` | python dtorslots.py: vt_orig deleting-destructor slots that point at a STUB while the native class defines its own ??_G / ??_E. CXTPHookManager::CHookSink's slot was func_0071c700 (`return 0`): `delete pSink` never ran ~ |
| `dumpobj.py` | (no docstring) |
| `dumpstats.py` | (no docstring) |
| `dumpsvc.py` | (no docstring) |
| `dupdata.py` | python dupdata.py: data symbols DEFINED by two or more linked converted objects. /FORCE:MULTIPLE keeps the first copy silently, so unrelated functions end up sharing one variable (Context::ptr's thread_specific_ptr and a |
| `dupnative.py` | python dupnative.py: converted copies (ca_*/nx_* objects defining func_<A>) of functions whose registry name S is also defined by a native object. Two live copies of one function split its state: Array::realloc allocated |
| `ehaudit.py` | python ehaudit.py [EXE MAP]: static audit of every C++ exception-handling table (__ehfuncinfo$...) in our link. A throw unwinds through FuncInfo -> unwind map (cleanup funclets) and try-block map -> catch handlers; a NUL |
| `enum_ctors.py` | List every EnumDescriptor(name,type_info) ctor call site (0056c590) in the 2008-06 exe with the pushed strings and addPair (0064d530) calls. |
| `exact_check.py` | Byte-check every function a native source defines against the 2008 exe (address from function-files.json by name). python work/donorfree-route/exact_check.py native-classes/Foo.cpp [...] |
| `exact_check2.py` | Byte-check every function a native source defines against the 2008 exe (address from function-files.json by name). python work/donorfree-route/exact_check.py native-classes/Foo.cpp [...] |
| `exe_dis.py` | python exe_dis.py ADDR [ADDR...] [-n BYTES]  -> capstone disasm of the 2008-06 exe at virtual addresses (any start, not only function starts). |
| `exe_dis_full.py` | python exe_dis.py ADDR [ADDR...] [-n BYTES]  -> capstone disasm of the 2008-06 exe at virtual addresses (any start, not only function starts). |
| `facprod_gen.py` | python facprod_gen.py: stubbed func_<X> that are really FactoryProduct<T,D,N>::FactoryProduct() (the original body calls the base constructor, then stores FactoryProduct<T..> vtables; registry names of these ICF bodies l |
| `fastcensus.py` | python fastcensus.py [EXE] [--ids auto/crashcont_ids.json] [--cap 3]: fast command census. One client runs the commands back to back (PostMessage WM_COMMAND, then a SENT WM_NULL returns as soon as the command finished; a |
| `fastlink.py` | python fastlink.py [OBJ...]: ~1 min relink for fixes that only ADD or REPLACE objects (nameinit.obj, a rebuilt tmplinst lib, one reconverted object): reruns lld once on the last full link's final response file |
| `featladder.py` | python featladder.py [EXE] [--orig run/RobloxOrig.exe] [--json out.json] Feature-ladder scoreboard: drives each exe through startup/File->New/idle CPU/Explorer/Insert Object/Run/Reset |
| `filetrace.py` | python filetrace.py EXE [--post 0xE100] [--secs 12]: list files the client opens (kernel32 CreateFileA/W, with the result handle) during startup + the posted commands. Diff ours vs RobloxOrig.exe to find wrong content pa |
| `findcallers.py` | (no docstring) |
| `findinit.py` | (no docstring) |
| `findref.py` | (no docstring) |
| `findref2.py` | (no docstring) |
| `findret.py` | (no docstring) |
| `findsmall.py` | (no docstring) |
| `fixloop.py` | python fixloop.py [--has BYTES] [--secs N]: one command for the link-fix cycle that used to be 4-6 manual steps. 1. --has BYTES: reconvert only converted analogs whose object contains BYTES (after a rename.py rule change |
| `foldaudit.py` | python foldaudit.py: converted code bound to ONE native data symbol from TWO OR MORE distinct original data addresses. The registry folds identical-code functions under one name (doDeclare<sDecal> for every Name::declare |
| `funcdefaudit.py` | python funcdefaudit.py: native drafts that DEFINE a func_<A> name for code that is not the original at A. A SpawnLocation draft labelled its own onServiceProvider `func_00490c30`; the original 0x490c30 is find<Service>,  |
| `gen_sp_members.py` | python gen_sp_members.py: generate native-classes/ServiceProviderMembersBoot2008.cpp from the stub list: member ServiceProvider::find<T>() const / create<T>() const instances (bodies as AppUnit448_2008Services.cpp). Prin |
| `getidx_alias.py` | python getidx_alias.py: ServiceProvider::getClassIndex<T>() stubs (return 0: every such service shared slot 0 of serviceArray, so a newly created JointsService/Teams/SpawnerService overwrote Workspace and find<Workspace> |
| `glue.py` | Compiler glue the original has where our link only has a `mov eax,0; ret` stub, rebuilt from the original's instructions with RELOCATIONS (never raw target addresses): |
| `grab_branches.py` | python grab_branches.py: copy native class sources that exist on ANY fetched remote branch (any path ending in native-classes/<file>.cpp, plus findings/main drafts/files) but in neither rebuild/2008-06/native-classes nor |
| `grab_changed.py` | python grab_changed.py BRANCH...: native class files a branch CHANGED (same name, different content from ours) -> rebuild/2008-06/native-findings-<tag>/ for gap-fill linking after our natives (they never replace our obje |
| `gridedit.py` | python gridedit.py [EXE] [--orig] [--class Part] [--rows N]: property-grid EDIT test (FEATURE_LADDER T1 "change a property in the Properties grid"). Launches the client with a -script that inserts one object named GE_<cl |
| `hardaddr.py` | Hard-coded original DATA addresses in converted objects. A converted source like 00467550.cpp passes `(const void*)0x85012c` (GUID_SysMouse) and `(const void*)0x84ff0c` (c_dfDIMouse2) to DirectInput: in the original |
| `header_port_proof.py` | Prove staged header ports object-neutral, then keep them in rebuild/2008-06/native-headers.  |
| `hook645.py` | (no docstring) |
| `hookcrash.py` | (no docstring) |
| `hookfunc.py` | (no docstring) |
| `hookmyptr.py` | (no docstring) |
| `hookprop.py` | (no docstring) |
| `hookresult.py` | (no docstring) |
| `hooksound.py` | (no docstring) |
| `hooktext.py` | (no docstring) |
| `iat.py` | python iat.py HEXADDR... -> import name at IAT slot (original 2008-06 exe) |
| `ieclean.py` | ieclean.clean(): test-harness IE cleanup for donor-free runs, delegating to work/ie_cleanup.py (iexplore.exe, the ielowutil.exe IE COM broker, and the Edge windows Windows 11 opens for the client's IE pages). Call it onc |
| `ieloop.py` | python ieloop.py: forever, every 1 s, close the IE pages the client opens: every visible iexplore.exe window and Edge windows showing a Roblox/IE-redirect page (WM_CLOSE, graceful). Never kills ielowutil.exe (the client' |
| `impcheck.py` | python impcheck.py [EXE]: walk the import directory by hand (pefile stops early on this exe) and check every imported name/ordinal against the DLL's real exports (run/ first, then SysWOW64; WinSxS-only DLLs like mfc90 ar |
| `initgen.py` | python initgen.py: original static objects that our link only has as ZERO STUBS. The original builds ~490 globals in .CRT$XCU initializers (mov ecx, G / push args / call CTOR / atexit DTOR); the converted initializer obj |
| `initscan.py` | python initscan.py: globals the ORIGINAL exe constructs at startup (dynamic initializers 0x7c0000-0x800000: `mov ecx, ADDR` then `call ctor`) that our link still reads as zero placeholders (dat_<ADDR>) -- the class behin |
| `insertsweep.py` | python insertsweep.py [EXE] [--orig run/RobloxOrig.exe] [--only A,B]: FEATURE_LADDER Tier 1.2. Inserts every Insert Object class one at a time through the real dialog (File->New, Insert->Object, select the item, OK) and  |
| `inspectobj.py` | (no docstring) |
| `layoutdiff.py` | python layoutdiff.py [EXE MAP]: classes whose polymorphic subobject offsets (RTTI complete-object-locator offsets of their vtables) differ between the original exe and ours. A difference means our objects of that class h |
| `ledger.py` | python ledger.py: one table of EVERY original function (function-files.json) vs. the server's analog status and what our donor-free link actually does with it -- the "how many functions are really left" count. |
| `libalias.py` | python libalias.py DIR [DIR...]: bind stubbed func_<X> to functions of compiled LIBRARY objects (xtpbuild.py output) whose body equals the original's at X. Unnamed XTP helpers (tab paint manager, docking, tree) had no re |
| `libalias_g.py` | (no docstring) |
| `link_lint.py` | python link_lint.py [--fix]: static checks over AutoRecover drafts that predict runtime crashes without probing. 1. ABI mismatch: one helper address declared with different C decorations (fastcall @n@N / stdcall _n@N / c |
| `linkgate.py` | python linkgate.py [--promote]: acceptance gate after a link, before launching anything. lld already resolves symbols exactly; this checks ITS answer against the last good build: |
| `listwins.py` | (no docstring) |
| `livebisect.py` | python livebisect.py ADDRS.json --bad REGEX [--secs N]: find which converted function causes a regression WITHOUT relinking. Leaving a converted object out of the link only turns its function into a `return 0` stub; the  |
| `lld_link.py` | python lld_link.py: link the donor-free exe with LLVM lld-link (multithreaded) from link/donorfree.rsp. lld refuses conflicting /alternatename pairs that link.exe silently resolves (first wins). This keeps link.exe's beh |
| `lld_mfc_probe.py` | python lld_link.py: link the donor-free exe with LLVM lld-link (multithreaded) from link/donorfree.rsp. lld refuses conflicting /alternatename pairs that link.exe silently resolves (first wins). This keeps link.exe's beh |
| `lld_modstate_probe.py` | python lld_link.py: link the donor-free exe with LLVM lld-link (multithreaded) from link/donorfree.rsp. lld refuses conflicting /alternatename pairs that link.exe silently resolves (first wins). This keeps link.exe's beh |
| `lld_native_probe.py` | python lld_link.py: link the donor-free exe with LLVM lld-link (multithreaded) from link/donorfree.rsp. lld refuses conflicting /alternatename pairs that link.exe silently resolves (first wins). This keeps link.exe's beh |
| `lldprof.py` | python lldprof.py [RSP]: time one lld-link run on a copy of the last final response file (default linkexp/qt.final.rsp) with /time, writing linkexp/prof.exe/.map so the real link outputs are untouched. |
| `luaunify.py` | Two Lua runtimes in one link: the original's Lua has C names (_lua_load, _luaX_tokens ...; built as C++ with lua_exception, extern "C" API) and the converted objects call those; native drafts included the Lua headers wit |
| `make_route.py` | Harness link glue (NOT native source): route the donor's pointer-form (PBDB) Described<>::classDescriptor() for each class that has one native twin, to the authentic 2008 array-form (QBDB/PADA) specialization, so the don |
| `make_stubs.py` | stubs.obj for the donor-free link: one zero-return stub per unresolved FUNCTION symbol and zeroed storage per unresolved DATA symbol, so the exe links without /FORCE:UNRESOLVED holes and `crashsite.py` (BPSTUBS=1) can lo |
| `make_variants.py` | (no docstring) |
| `memdiff.py` | python memdiff.py [EXE] [--post 0xE100] [--wait 6]: global-memory snapshot diff vs the ORIGINAL at the same point. Launches the original and ours (no debugger), waits for the main window, optionally posts commands, waits |
| `merge_bisect.py` | Find which members break a failing layout merge group.  |
| `mewmerge.py` | python mewmerge.py [--apply]: take mew's new/changed native sources that are safe to merge. Safe = file changed on mew's branch since the common base, unchanged here since that base (and no uncommitted edits), |
| `mine_frontier.py` | python mine_frontier.py: the functions that ACTUALLY need mining -- no source anywhere (ledger.py: not server-exact, no native/findings/draft source) AND called by REAL code in our current link (a linked, non-stub object |
| `mistarget_fix.py` | python mistarget_fix.py [--apply]: auto/calldiff.json (namediff.py) lists direct calls that land on a function whose body differs from the original target. Where our name M always stands for one original address T (and T |
| `mp_crash_probe.py` | (no docstring) |
| `mp_exception_probe.py` | (no docstring) |
| `mp_parity_probe.py` | (no docstring) |
| `msgmapaudit.py` | python msgmapaudit.py: every MFC message-map entry in our exe whose handler is a STUB. A stubbed WM_PAINT handler returned without BeginPaint: the window stayed invalid, ~4k WM_PAINT/s, 100% CPU, no idle -> WM_TIMER neve |
| `multiprobe.py` | python multiprobe.py [secs]: ONE probe run that skips up to 30 faults (crashsite FASTFWD fakes a null call's return) and lists every distinct fault site with its caller, so a batch of crash classes gets fixed per relink  |
| `namediff.py` | python namediff.py [EXE MAP]: compare every function that has the same mangled name in the original 2008-06 exe (function-files.json) and in our linked exe (map): instruction streams with address operands masked. Writes |
| `nameinit.py` | python nameinit.py: real definitions for `const RBX::Name&` globals our link only has as zero base stubs. The original constructs each at startup (`push idx; push "version"; call Name::declare; mov [addr], eax` in the |
| `natbody_check.py` | python natbody_check.py: registry-misnamed converted bodies. A converted func_<A> took symbol S (rename), and the link picked it over a NATIVE object's own S. When the native S, compiled alone, matches a DIFFERENT origin |
| `natcallaudit.py` | python natcallaudit.py: call-identity audit of NATIVE functions (callaudit.py covers converted ones). A native function whose masked body equals one original function's is that function; at each rel32 call offset the |
| `natdata.py` | python natdata.py: bind dat_<A> placeholders to the NATIVE global that owns the same state. XTP's hook-manager singleton lived twice: native code used ?s_managerInstance@?1??XTPHookManager@@, converted code the placehold |
| `natinit.py` | python natinit.py: pair ORIGINAL static globals with the NATIVE globals that replace them, by the string literals their initializers push. Converted code used dat_00976b7c / dat_00976b94 copies of ScriptContext::propScri |
| `native_addrs.py` | python native_addrs.py: address -> native decorated name, from the '// <addr>' comments native sources put right above a function definition ('// 004492d0 (thiscall ret 4...)' + 'void CRenderSettings::checkProfile(bool f |
| `native_data.py` | python native_data.py: original data address -> native global symbol, from native declarations that name the address ('namespace RBX { extern int renderMode; }   // 00942ec4', 'extern bool shadowsEnabled;   // 0096de64') |
| `native_index.py` | python native_index.py: auto/native_index.json = {addr: {file, signature, headers}} for every non-draft native source that documents an address with a `// <8 hex>` comment above (within 26 lines) a function definition. T |
| `natret.py` | python natret.py: callee-pop audit of NATIVE methods reached through vtables. For each vt_orig vtable slot (original layout, original address known) whose target in our exe is native code (not converted <X>.obj, not a st |
| `nearmatch.py` | python nearmatch.py [ADDR...]: NEAR-MATCH fallback for exact sources that compile but are not byte-identical (rename.json status 'nomatch'). Owner decision 2026-11-24: a working (buggy) client first, so a close analog be |
| `next_targets.py` | python next_targets.py [--file-new] [--limit N]: probe the donor-free exe and print the addresses of the stubs it hits, in call order, that exist as named functions in the original exe (candidates for autorecover.py). Te |
| `nightly.py` | python nightly.py: unattended full refresh (Task Scheduler, 03:00). Rebuild every native source against the current headers (native_check_runner, 8 workers), swap the fresh objects into the quicktest link set, then a ful |
| `noauto.py` | python noauto.py [--start]: functions that still differ from the original (namediff), are called wrongly or stubbed (calldiff), or fill a wrong virtual slot (vtdiff), for which no automatic fix exists (no server-exact an |
| `nullcalls.py` | python nullcalls.py [EXE MAP]: static scan of our linked exe for calls that can only crash: direct call/jmp targets below the code section (address 0, the image header: unresolved symbols, bogus aliases), absolute call [ |
| `obj_bisect.py` | python bisect.py SIGNATURE [--set FILE]: find which linked converted (mass) object causes a crash whose probe output contains SIGNATURE (e.g. "at 00000000"). Candidates = mass-converted objects currently linked (or --set |
| `odrdiff.py` | python odrdiff.py: one-definition-rule breaks between native objects: the same data symbol (function-local static, COMDAT global) defined by several objects of the link with DIFFERENT sizes means those translation units  |
| `oneshot.py` | python oneshot.py [EXE MAP] [secs]: ONE probe run that collects everything one crash loop used to need 3-4 runs for: LIVE_STUBFIX (stubs of names a loaded DLL exports jump to the real function), BPSTUBS (placeholder stub |
| `origcache.py` | Original-exe disassembly cache shared by namediff/vtdiff: masked bodies never change, so they are computed once (auto/orig_body.pkl). Use: from origcache import orig_body; orig_body(body_fn, img, addr, tag). |
| `origcover.py` | python origcover.py [secs]: the COMPLETE list of functions our build is missing on the startup + File->New path, in one run instead of one crash per relink. Every function our current link resolves to a STUB is mapped ba |
| `pathdiff.py` | python pathdiff.py ORIG_ADDR OUR_ADDR [--depth N]: walk the original exe and our linked exe in parallel from a pair of function addresses, following direct calls/jumps pairwise, and report every function whose instructio |
| `probe.py` | python probe.py [secs]: debugger probe of run/RobloxQT.exe (File->New), no relink. First real fault; also breaks in RobloxCrashReporter::ProcessException (the client's own crash dialog hid AVs from SECOND_CHANCE_ONLY). S |
| `propdesc_gen.py` | python propdesc_gen.py: scans linkexp/qt.map for stubbed RefPropDescriptor, PropDescriptor, EnumPropDescriptor, EnumDesc, and BoundProp instantiations -> emits one explicit-instantiation |
| `propsweep.py` | python propsweep.py [EXE] [--orig] [--only CLASS.PROP,...]: property-set sweep (FEATURE_LADDER T1 "change a property"). Each case creates an instance (parented to Workspace, or the given service) and assigns one property |
| `qualname_alias.py` | python qualname_alias.py [STUBLIST...]: stubbed decorated names that are the same function as one defined symbol, spelled differently by a draft: (1) only the access/virtual letter differs (?onChildAdded@DataModel@RBX@@M |
| `quicktest.py` | python quicktest.py [secs]: test a fix NOW without waiting for a cycle round. Takes the cycle's last link inputs (link/donorfree.rsp + link/stubs.obj), swaps in the current converted-object set (renamed/results.json) and |
| `rates.py` | python rates.py [HOURS=24]: rates from work/donorfree-route/auto/metrics.jsonl (autorecover.py) and metrics.jsonl (boot.py). Exact bytes/hour (function bytes whose draft matched exactly), drafts and approx tokens (chars/ |
| `rbxinst.py` | python rbxinst.py: RBX function/member TEMPLATE instances our link only has as `return 0` stubs, by explicit instantiation from the native headers (tmplinst.py does STL/Ogre class templates). Gemini dossier section 11/13 |
| `rdis.py` | python rdis.py ADDR/SYMBOL [N] [orig]: disassemble our exe (or the original) with map/registry names on operands. |
| `reach.py` | python reach.py [ROOT_ADDR ...] [--depth N]: direct-call reachability over the original 2008-06 exe from File->New roots, classified against the donor-free link. Writes auto/reach.json and auto/reach_missing.txt (missing |
| `readslot.py` | (no docstring) |
| `readslot2.py` | (no docstring) |
| `readslot3.py` | (no docstring) |
| `readslot4.py` | (no docstring) |
| `reccmp_map.py` | python reccmp_map.py [EXE MAP] [--only ADDR,...] [--top N]: reccmp's comparison engine without a PDB. reccmp (isledecomp) normally learns recomp symbols from a PDB and original addresses from `// FUNCTION:` source |
| `regcreator_gen.py` | python regcreator_gen.py CLASS [CLASS...]: native FactoryProduct<T,D,sT>::creator registrations (the creator static, its ??__E initializer and atexit, via getCreator() like FactoryProductCreators2008.cpp) for classes tha |
| `relocsplit.py` | python relocsplit.py: converted objects that address an original global as NEAREST NAMED SYMBOL + addend. The converter named 0x973f48 (Instance::event_propertyChanged, unnamed in the registry then) `propArchivable + 0xd |
| `rename_par.py` | python rename_par.py [N]: run rename.py over every job in renamed/addrmap.json in N parallel processes (default 4), fresh; merges the per-chunk results into renamed/rename.json. Donor-free mode (ROC_RENAME_DEFINED = rena |
| `renamed_link.py` | (no docstring) |
| `rescore.py` | python rescore.py: exact_check every AutoRecover draft in chunks; writes auto/scores.txt (one exact_check line per draft). |
| `retcheck.py` | python retcheck.py: stack-balance check for every claimed pair (as bindcheck.py): the original function's ret immediate (ret N = callee-popped bytes) must equal ours. A mismatch skews the caller's stack after every call: |
| `retdiff.py` | python retdiff.py [EXE MAP]: functions in our link whose stack cleanup (first `ret N`) differs from the original function at the same identity (func_<addr>, or the registry's real name for that address). A mismatch unbal |
| `robloxscreenshot.py` | (no docstring) |
| `rtclass.py` | python rtclass.py: alias dat_<addr> placeholders that are an MFC CRuntimeClass in the original to our real ?class<N>@<N>@@2UCRuntimeClass@@A. An analog GetRuntimeClass (func_00745630 = CXTPControlButton's vtable slot 0) |
| `rtti_vtable.py` | Exe vtable of a class by its RTTI decorated name: python rtti_vtable.py '.?AV...' [slots] |
| `rttiname.py` | (no docstring) |
| `savetest.py` | (no docstring) |
| `screenshot.py` | (no docstring) |
| `scripttest.py` | python scripttest.py [EXE] [--orig run/RobloxOrig.exe] [--lua FILE]: FEATURE_LADDER Tiers 3-4 without UI driving. Launches the client with `-script "<lua>"` (the command line the app itself builds for Play Solo), the Lua |
| `scripttest_long.py` | scripttest with a longer observation window: python scripttest_long.py EXE --lua FILE [SECS]. |
| `shard_libs.py` | python shard_libs.py [--dry-run / --build] [--shards 16] [--out-dir work/native-client/lib-shards] Standalone .lib-packing tool for linkexp/qt.rsp (does NOT edit quicktest.py or linkexp/). |
| `shardcache.py` | Sharded pickle cache for the per-object symbol caches (link/obj_ext_cache.pkl, linkexp/qt_ext_cache.pkl: ~2 GB each). A single pickle was rewritten whole whenever one object changed (~25 s of dump per link). ShardCache k |
| `shot.py` | python shot.py [EXE] [secs]: run the client normally (no debugger), post File->New to its main frame, wait, and save a screenshot of the main window to auto/shot.png (PrintWindow with full-content rendering, so a covered |
| `signaldesc_gen.py` | python signaldesc_gen.py: scans linkexp/qt.map for stubbed SignalDesc<C, Sig> and SignalDescImpl<N, Sig> instantiations -> emits one explicit-instantiation .cpp per specialization |
| `size_audit.py` | For every Creatable<Instance>::create<X> in the linked exe, compare the operator-new size it pushes with the size pushed by every other copy in the link inputs (donor lib members, native objects). A copy whose size diffe |
| `sizecheck.py` | python sizecheck.py [--jobs 4]: bulk LAYOUT check -- the true object size of every RBX class (the original allocates it: `push N; call operator new/malloc` followed by that class's constructor, or a constructor that stor |
| `snap.py` | python snap.py EXE OUT.png [secs]: launch EXE (no debugger), File->New at 8 s, capture its main window (PrintWindow) at `secs`, kill. |
| `spcounted_gen.py` | python spcounted_gen.py: scans snapshot/live qt.map for stubbed boost::detail::sp_counted_impl_p<T> (deleting dtors ??_E/??_G, dispose, destroy, get_deleter) -> emits one explicit-instantiation .cpp |
| `spellalias.py` | python spellalias.py: mass alias for `return 0` stubs whose name differs from a REAL linked definition only by how the analog headers spelled a type: class-name globals (const char* const / char[] / char* const: 3PBDB 3Q |
| `spellunify.py` | Class-name spelling splits template instantiations: Described<PartInstance, sPart> exists as $1?sPart@2@3PADA (native char[]) AND $1?sPart@2@3PBDB / 3QBDB (analog pointer spellings). Each is its own instantiation with it |
| `spinsample.py` | python spinsample.py [EXE] [warmup] [samples]: find where a hung-but-alive client spins. Starts the exe normally, waits, then repeatedly suspends each thread, reads its EIP (Wow64GetThreadContext) and resumes. Prints the |
| `srcaddr_alias.py` | python srcaddr_alias.py: func_<A> stubs whose body a NATIVE draft already defines under its real name. Converted callers reference the placeholder (executeInNewThread -> func_005aefa0) while the native object defines |
| `startcheck.py` | python startcheck.py [EXE] [secs]: fast standalone health check, no debugger (~15 s): start the client, post File->New when its window shows, and report OK (window up, no crash dialog), CRASH-DIALOG (the client's own 'RO |
| `stdinst.py` | python stdinst.py [--jobs N]: replace stubbed std:: template members (std::list/vector/_Tree/... instantiated on our types: 11k of the 21k stubs, all returning 0) with REAL code: demangle each, write an explicit instanti |
| `stdinst2.py` | python stdinst2.py [--jobs N]: phase 2 of stdinst.py: stubbed std:: members whose template arguments are user types BY VALUE (std::vector<RBX::Foo>) need the full type: include the native header that defines it (index of |
| `stub_exact.py` | python stub_exact.py: stubbed fn_/func_<addr> names whose address has a server-exact analog that was never converted (fn_0056be10, a function-static mutex getter, returned 0 and crashed at static init). Adds addrmap jobs |
| `stub_reach.py` | python stub_reach.py [--depth N]: static crash forecast for the linked donor-free exe, no run. Walks direct calls in link/donorfree.exe from File->New entry points (CIDEDocManager::OnFileNew, CRobloxView::OnInitialUpdate |
| `stub_ret_audit.py` | python stub_ret_audit.py: report-only audit comparing called stubs' stack-pop (`ret N`) in snapshot RobloxQT.exe against original RobloxOrig.exe (matched via identity-registry.json / |
| `stub_sret_audit.py` | python stub_sret_audit.py: scans work/native-client/mass-tools/stubcall_audit.json (461 called stubs + 1,515 vtable stub slots) for stubs returning a C++ UDT by value (`?AV`, `?AU` in MSVC |
| `stubalias.py` | python stubalias.py: bind STUB names (analog spellings) to what the original has at their address. origcover.py found the original running 123 of our stubs on the File->New path: ?allocate@@YAPAXI@Z / ?freeObject@@YAXPAX |
| `stubcall_audit.py` | python stubcall_audit.py: read-only static audit of live RobloxQT.exe against linkexp/qt.map. Snapshots run/RobloxQT.exe and linkexp/qt.map into work/native-client/mass-tools/snap/ first |
| `stubhits.py` | python stubhits.py [EXE] [--post 0xE100,0x807f,0x80c6] [--secs 30]: Frida stub-hit tracer. Hooks every `return 0` stub our link generated (qt_stubs*.obj symbols in linkexp/qt.map), launches the exe, posts the WM_COMMANDs |
| `stubret.py` | python stubret.py [EXE MAP]: callee-pop audit of STUBS, link-wide. A stub whose `ret N` differs from the function it replaces skews its caller's stack (CMainFrame::onEvent(Heartbeat) popped 8 of 12 -> RunService thread c |
| `stubret_all.py` | python stubret_all.py: every `ret N` stub in our link vs the original function's own stack-pop count (first ret in its body; a tail-jump body ending in `jmp reg/mem` = depends on the target). A stub reached through a fun |
| `swap_native.py` | python swap_native.py ADDR NATIVE_SYMBOL [RESULTS_JSON]: use a native function instead of the AutoRecover_<ADDR> draft. Adds aliases.txt lines mapping every draft helper name for ADDR (fn_<addr> in any decoration, read f |
| `sweep.py` | python sweep.py: one crash-and-continue pass over the milestone script cases (no relink). Each case runs once through scripttest (-script); a crashing case is re-run under the Frida fault probe (auto/peekfault.py) to rec |
| `symmap.py` | (no docstring) |
| `test_absolute_zero.py` | (no docstring) |
| `test_codex_import_thunks.py` | (no docstring) |
| `test_natinit_guard.py` | (no docstring) |
| `texture_compare_probe.py` | (no docstring) |
| `throwaudit.py` | python throwaudit.py [EXE MAP]: static audit of every C++ throw descriptor (__TI* ThrowInfo -> __CTA* catchable-type array -> __CT* catchable types -> ??_R0 type descriptors) in our link. The exception dispatcher walks t |
| `throwtrace.py` | python throwtrace.py [EXE] [--post 0xE100] [--secs 15]: Frida tracer for error dialogs and C++ throws. Hooks user32 MessageBoxA/W/IndirectA/W and kernel32 RaiseException (C++ throws = 0xE06D7363), launches the exe, posts |
| `tmp_b520.py` | (no docstring) |
| `tmp_b520a.py` | (no docstring) |
| `tmp_b520b.py` | (no docstring) |
| `tmp_cast.py` | (no docstring) |
| `tmp_cast2.py` | (no docstring) |
| `tmp_cast3.py` | (no docstring) |
| `tmp_fix.py` | (no docstring) |
| `tmp_gen.py` | (no docstring) |
| `tmp_replace.py` | (no docstring) |
| `tmp_transform.py` | (no docstring) |
| `tmplinst.py` | python tmplinst.py [--max N]: resolve stubbed STL/Ogre TEMPLATE members by explicit instantiation. The original exe compiled std::_Tree<...Ogre::X*...>, std::vector<Ogre::Y>, Ogre::ConstMapIterator<...> members into itse |
| `tooltest.py` | python tooltest.py [EXE] [--orig run/RobloxOrig.exe]: FEATURE_LADDER Tier 2 smoke test. File->New, insert a Part (Insert Object 'Part' is not offered: the place's baseplate is used when there is none), then for each tool |
| `ttdq.py` | python ttdq.py "<cdb commands; separated by ;>" [RUN]: replay a TTD trace headless (cdb -z) and print the output. Default trace: newest auto/ttd/*.run. Addresses: use linkexp/qt.map (no PDB); `ln` resolves nothing, so pr |
| `ttdrec.py` | python ttdrec.py [EXE] [--post 0xE100] [--out DIR]: record a Time Travel Debugging trace of the client (TTD.exe from the WinDbg package), post the WM_COMMANDs once the main frame shows (File->New = 0xE100), and wait for  |
| `ttdrun.py` | python ttdrun.py [EXE] [--post 0xE100,...] [--out auto/ttd] [--secs 60]: record a TTD trace WITHOUT an admin shell. Writes auto/ttd_request.json and triggers the elevated scheduled task RoConstructTTD (installed once by |
| `twins.py` | python twins.py: stubbed func_<addr> whose original body is identical (masked) to another original function that already has an exact converted object, and whose direct call targets are identical too (one level) -> alias |
| `valsizes.py` | python valsizes.py: by-value class argument sizes learned from the original binary -> auto/valsizes.json, read by make_stubs._signature_ret_bytes. A stub for CMainFrame::onEvent(const RunService*, Heartbeat) popped 8 byt |
| `variants.py` | python variants.py SPEC.json: build several link variants IN PARALLEL (quicktest.py QT_TAG=<tag>: own exe/map/ stubs/patched copies) and probe each, to try competing fixes in one round instead of one relink each. |
| `vlink.py` | python vlink.py [RSP] [--check MAP]: virtual linker. Predicts lld's symbol resolution for a planned rsp WITHOUT linking: objects in order (first external definition wins: /FORCE:MULTIPLE), archives (.lib) only fill names |
| `vt_pool.py` | python vt_pool.py JOBS.json [N]: the per-object write phase of vt_strip.py on N processes (it ran single-core: 10+ minutes when every object changed). Each job: full (pre-strip object), out (linked copy), drop (names to  |
| `vt_strip.py` | python vt_strip.py: converted exact objects (renamed/obj) carry vtable COMDATs (??_7) compiled from analog/donor headers; native objects carry their own. Converted objects link first, so their copy wins unless stripped.  |
| `vtable_audit.py` | python vtable_audit.py: compare every class vtable of the donor-free exe with the original exe's, by RTTI name. Reports classes whose slot count differs (an extra/missing virtual shifts every later slot: a wrong call at  |
| `vtable_check.py` | Pair each vtable slot of a compiled object's ??_7Class vtables with the exe vtable that the class's constructor stores, then byte-check every slot function the object defines. python vtable_check.py SOURCE OBJ CTOR_ADDR. |
| `vtaudit.py` | python vtaudit.py [EXE MAP]: slot-by-slot audit of every primary vtable (??_7X@@6B@) in our link against the ORIGINAL exe's vtable for that class (auto/orig_vt.pkl). Each original slot is resolved to the symbol our link  |
| `vtcolfix.py` | python vtcolfix.py: vt_orig.obj tables whose RTTI-locator slot ([-1]) has no relocation (our link had no ??_R4 for the class) get a DIR32 relocation to dat_<original COL address> (a copy of the original locator, stubbed  |
| `vtdiff.py` | python vtdiff.py [EXE MAP]: every RTTI vtable in the original exe and in ours, paired by (class type name, subobject offset); each slot's target compared by masked body (namediff rules). Wrong slots -> auto/vtdiff.json,  |
| `vtdiff_obj.py` | python vtdiff_obj.py A.obj B.obj: per vtable symbol, the relocation target names of its slots; prints names whose slot lists differ and writes auto/vt_force_diff.json (the names to take from B). |
| `vtfix.py` | python vtfix.py: repoint vt_orig.obj slots that natret.py found bound to the WRONG function (same registry name, other code: a folded label made DescribedCreatable<BodyForce> slot 1 call DirectPhysicsReceiver::receivePac |
| `vtorig.py` | python vtorig.py [--all]: linkexp/vt_orig.obj -- the ORIGINAL exe's vtables for classes whose linked vtable has a shifted layout (vtaudit.py: our slots hold methods the original has at other indexes; e.g. stock Ogre 1.4. |
| `vtscan.py` | python vtscan.py: every vtable (??_7) in our link: slots that point into DATA instead of code (a vtable slot bound to a data symbol jumps into data at runtime). Compares slot count/targets with the original exe's vtable  |
| `vtslotaudit.py` | python vtslotaudit.py: every ??_7 vtable in our exe (linkexp/qt.map) whose slots point OUTSIDE .text (data executed as code: a slot relocated to a dat_/vtable name), or to 0. Compares with the original table where the re |
| `watchfield.py` | python watchfield.py CTOR_SYMBOL OFFSET [--post 0xE100] [--secs 15] [--max 3]: who WRITES object field +OFFSET? Hooks the constructor (map symbol) of the first few objects; on return arms a hardware write watchpoint (Fri |
| `who_refs.py` | Which COMDAT sections / symbols reference a symbol? python who_refs.py OBJ SUBSTRING |
| `xcu_gen.py` | python xcu_gen.py: a COFF object whose .CRT$XCU section points at the converted dynamic initializers the original exe ran at startup (auto/init_fns.json from initscan.py: initializers of globals our link only had as zero |
| `xcudedup.py` | python xcudedup.py EXE MAP: zero repeated pointers in the CRT initializer table (__xc_a..__xc_z) of a linked exe. The same object linked twice (unit_2127/unit_2596 were one candidate obj), or two objects defining one glo |
| `xcusweep.py` | python xcusweep.py: every ORIGINAL C++ static initializer (.CRT$XCU table 0x804f74..0x80aa08, from _initterm in __tmainCRTStartup) classified against our link. Tonight's classes (factory creators, class descriptors, Boun |
| `xtpbuild.py` | python xtpbuild.py [N]: compile every XTP 11.2.2 source file with the matched recipe (xtp-11.2.2-lib-strlen, its first grid flags) into linkexp/xtplib/<file>.obj, N processes (default 12). Cached: an existing object is k |
| `zerodata_gen.py` | python zerodata_gen.py: dat_<A> placeholders our link left as ZERO data while the original holds a string literal there ("url", "BMP", "min", "LocalScript", "Closing log file" ...: data_zero_audit). Code comparing or pri |
| `zeroreloc.py` | python zeroreloc.py: converted relocations on immediates that are 0 in the original (converter paired `mov [eax], 0` with a vtable: RCP<TextureProxy>() 005410b0 stored Ogre::RenderableListener's vtable, MegaTextureProxy: |
