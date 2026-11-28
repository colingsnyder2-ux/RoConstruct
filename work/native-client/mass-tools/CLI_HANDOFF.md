# CLI Handoff: Donor-Free RobloxQT Client (2026-11-26)

## Goal
Get `work/donorfree-route/run/RobloxQT.exe` working cleanly through every `FEATURE_LADDER.md` tier (boot, File->New, Explorer, Insert Object, Run/Reset, tools, Lua scripts, physics, Play Solo, `.rbxl` save/load, network, soak) without crashes.

## Why we moved to CLI
Antigravity desktop app ran commands on hidden sandbox desktop `WinSta0\exebox-*`, where Windows blocks D3D9 (`D3DERR_NOTAVAILABLE`) and OpenGL (`ERROR_ACCESS_DENIED`) for **both** `RobloxOrig.exe` and `RobloxQT.exe`. Running in a normal CLI on `WinSta0\Default` unblocks live `featladder.py`, `scripttest.py`, and `sweep.py` testing immediately.

## Owner Rules
- Fix whole bug classes, not one crash at a time.
- Batch 10–30 compile-verified fixes, then link **once** (`quicktest.py` takes ~3 min).
- Run static audits first. Never drop an `.obj` without checking `coff_externals` for unique COMDATs (e.g., never drop the 45 `OgreMain*.cpp` objs — they supply 3,803 unique STL/template COMDATs).
- Never use `__emit`, byte blobs, or patched target bytes. Mark inferred code `// INFERRED: <evidence>`.
- Lease shared native headers/classes before editing (`.\roc.cmd lease take ... --hours 4`), release when done (`.\roc.cmd lease release ...`). Currently **0 active leases**.
- Never edit `clients/` or `tools/`. Do not commit/push unless asked.
- **Final cleanup (at the very end)**:
  - Remove `RoConstructTTD` scheduled task (admin PowerShell):
    `Unregister-ScheduledTask -TaskName RoConstructTTD -Confirm:$false; Remove-Item -Recurse C:\ProgramData\RoTTD`
  - Remove IFEO `RobloxPH.exe` registry key.

## Current Build State (`work/donorfree-route/run/RobloxQT.exe`)
Linked cleanly (`lld exit 0`, 0 conflict rounds, all toggles ON). **Not yet tested on `WinSta0\Default` since the PropGrid + Scintilla + Sret + Lua fixes below!**

### Static Audit Numbers (verified on current `run/RobloxQT.exe`)
- `stubcall_audit.py`: `total_stubs=46,268`, `vtable_stub_slots=1,274`, `unique_called_stubs=442`, `call_sites=853` (down from 875).
  - `Reflection` called stubs: **0** (down from 19).
  - `Lua` called stubs: **0** (down from 7).
  - Remaining RBX subsystems: `Instance=51`, `Script=13`, `Workspace=11`, `View=6`, `Render=5`.
- `stub_sret_audit.py`: `sret_udt=6`, `dangerous_dtor=3` (down from 5; remaining 3 are `AFXGetRegPath`, `AFX_GLOBAL_DATA::RegisterWindowClass`, `composeClothingTexture`).
- `stub_ret_audit.py`: 3 entries (`func_00772960`, `func_0072ea40`, `func_00799560`) — verified non-bugs (all 3 are `sub ecx, off; jmp dtor` adjustor thunks whose target is `ret 4`).
- `dll_data_audit.py`: 50 `mutable_data` Ogre statics — **all 50 have 0 referrers** in `RobloxQT.exe` (harmless).
- `vt_orig.obj` multi-vtable subobject collisions: **0** (down from 26).
- `ZERO-ADDRESS names`: 2 (`func_0055f940`, `func_0061fb20`) — still in `aliases_renamed.txt` / `qt_prev_und.txt`.

## Fixed This Session (do not redo)
1. **PropGrid crash (whole bug class — 38 vtables fixed)** in `work/donorfree-route/vtorig.py`:
   - Root cause: for multi-vtable classes where `??_R4X@@6B@` was absent (or `off=0` from a draft) while `??_R4X@@6B<Base>@@` already claimed `off=0`, `vtorig.py` put the `off=0` (`CXTPPropertyGridItem::GetRuntimeClass`, `ret 0`) table into `??_7X@@6B@` instead of the 1-slot `CPropGrid::Item` table (`Item::update`, `ret 4`). Every call to `Vector3Item`, `XBrickColorItem`, `RefItem`, `ContentItem<TextureId>` in `func_00439d70` leaked 4 bytes onto the stack, shifting `esp` and corrupting `for_each`.
   - Fix: remaining-subobject resolution in `vtorig.py` (`_other_offs` + `_vo_by_cls`) remapped **38** bare `??_7X@@6B@` tables (all 4 broken `CPropGrid::Item` subclasses + 34 RBX classes incl. `Accoutrement`, `Backpack`, `BodyColors`, `Clothing`, `Pants`, `Shirt`, `StarterPackService`, `LocalBackpack*`).
2. **Scintilla MFC runtime classes** in `work/donorfree-route/aliases_override.txt`:
   - Added **52** verified `CScintilla*@@` -> `CScintilla*@Scintilla@@` aliases (`GetRuntimeClass`, `GetMessageMap`, `GetThisMessageMap`, `CreateObject`, ctors/dtors, `On*` handlers).
3. **Lua `wait()` / `delay()` / Reflection args (`*2008` whole bug class)** in `work/donorfree-route/aliases_override.txt`:
   - Added **15** verified aliases mapping `YieldingThreads` -> `YieldingThreads2008` (`queueWaiter`, `resume`, `WaitingThread` vector helpers) and `LuaArguments` -> `LuaArguments2008` (`get`, `size`).
4. **Heap-corrupting `sret` stubs + `Reflection::Tuple`** in `work/native-client/stub-drafts/StubLive_Sret.cpp` (bound via `bindsrc.py`):
   - `RBX::StringConverter<BrickColor>::convertToString`
   - `RBX::StringConverter<G3D::Color3>::convertToString`
   - `RBX::Reflection::Tuple::Tuple(size_t)`, `Tuple(const Tuple&)`, `~Tuple()` (fixed all 18 Reflection call sites).
5. **`rbxinst.py` upgraded**: all-identifier header resolution, `G3D` includes, `RefType::singleton` return type (`const RefType&` + alias to `const Type&`).
6. **Cleanup**: removed `dbg literal` print from `work/donorfree-route/quicktest.py`.

## Immediate First Steps in CLI (on `WinSta0\Default`)
1. **Run the live runtime tests on the already-linked `run/RobloxQT.exe` (no relink needed first!)**:
   ```powershell
   cd C:\Users\colin\RoConstruct\work\donorfree-route
   python featladder.py run/RobloxQT.exe
   python scripttest.py run/RobloxQT.exe
   python sweep.py
   ```
   Check `auto/featladder.json`, `auto/scripttest.json`, and `auto/sweep_report.json` (verify `_workspace > 0` in `sweep_report.json`, not just `ok`!).
2. **Fix any runtime crashes found**, batching them with the ready-to-apply static wins below before doing 1 link.

## Ready-to-Apply Static Wins (discovered, not yet applied)
1. **`392` `??_E` -> `??_G` deleting-destructor aliases** (all 15/15 called `??_E` stubs in `stubcall_audit.json` have an exact `??_G` in `renamed/defined.json`, including `Workspace`, `Decal`, `Texture`, `ScriptContext`, `Team`, `DebrisService`, `Selection`, `Hat`, `CSettingsExplorer`, `RootNode`, `CSelectionTreeCtrl`, `SteppingController`, `AIController`). Check `deldtor_gen.py` or add `??_E -> ??_G` aliases for single-object classes (fixes destructor leaks/crashes on `Remove()` / `Reset` / `File->Close`).
2. **Remaining `sret` / `View` / `Render` stubs**:
   - `composeClothingTexture` (2x, called by `ViewNew::Part::getMaterial`) — dangerous `std::string` sret stub.
   - `ViewNew::MaterialFactory::getMaterial` (2x) and `getMegaMaterial` (1x) — `ReferenceCountedPointer<MaterialBase>` sret stubs.
   - `Render::getShaderModel()` (1x).
3. **`Body::getNextStateIndex` static initializer** (`?p@?1??getNextStateIndex@Body@RBX@@SAHXZ@4HA`, orig `0095a898`, initial value `1` currently zeroed).
4. **Last 2 `ZERO-ADDRESS` names**: `func_0055f940` (still referenced in `aliases_renamed.txt` line 2517 `?getLocalCachePath...=func_0055f940` and `qt_prev_und.txt`) and `func_0061fb20`.
5. **Remaining 92 `rbxinst.py` templates** (e.g., `IdManager`, `Stats::Item`, `Named<Base, sName>`, `SignalDescImpl::GenericSlotAdapter`, `ServiceProvider::create/find(DataModel*)`).
6. **Humanoid `BoundProp<float, 1>` constructors** (5-arg / 6-arg overloads for `Health`, `MaxHealth`, `WalkSpeed` + Humanoid state ctors).
7. **Link speed**: `work/donorfree-route/shard_libs.py` packs loose `.obj`s into `.lib`s (`21,419 -> 9,290` opens, 56.6% reduction) if not yet wired into `quicktest.py`.

## Key Tools & References
- `work/native-client/mass-tools/GEMINI_HANDOFF.md`: Claude's earlier handoff (TTD commands, `quicktest.py` bisect env vars, dead ends).
- `work/native-client/mass-tools/CLAUDE_RESEARCH_DOSSIER.md`: 30 sections of static audits.
- `work/donorfree-route/quicktest.py`: links `run/RobloxQT.exe` + `linkexp/qt.map` (~3 min).
- `work/donorfree-route/bindsrc.py SRC.cpp`: compiles one C++ file via `native_check_runner.py` and binds it into `linkexp/qt_results.txt`.
- `work/donorfree-route/vtorig.py`: regenerates `linkexp/vt_orig.obj`.
- `work/donorfree-route/featladder.py`, `scripttest.py`, `sweep.py`, `throwtrace.py`, `auto/peekfault.py`: runtime probes.
- TTD: `python ttdrun.py --out auto/ttd3 --secs 90` (uses `RoConstructTTD` task), replay with `python ttdq.py "<cdb cmds>" <run>`.
