# Handoff for Gemini: donor-free RobloxQT client (2026-11-26)

## Goal
Get `work/donorfree-route/run/RobloxQT.exe` working through every FEATURE_LADDER tier:
boot, instances, tools, scripts, physics, Play Solo, files and network, then a soak run.

## Owner rules
- Fix whole bug classes, not one crash at a time.
- Batch 10 to 30 fixes that compile, then link once. Linking is slow and the owner dislikes frequent links.
- Run static audits first. Never drop an `.obj` until you have checked it for unique COMDATs.
- Never use `__emit`, byte blobs or patched target bytes. Mark inferred code with `// INFERRED: <evidence>`.
- Lease native classes and core headers before you edit them (`roc.cmd lease take ...`).
- Never edit `clients/` or `tools/`. Commit or push only when the owner asks.
- At the very end, remove the IFEO `RobloxPH.exe` registry key.

## State now
- `run/RobloxLadder15.exe` passes 9/9 on the ladder, but only with every new toggle off.
- The current `run/RobloxQT.exe` has every fix on. It passes the stats-view fix and File->New. The ladder reports
  "alive" at 2/9. It still crashes in the property grid (details below).
- `run/RobloxLadder14.exe` is the older 9/9 control build.

## Open bug: PropGrid crash (current work)
- The access violation is at pc `0x5f96f0`. The handler is `func_00439d70` (ours `0x436a40`): the `WM_USER+0x65`
  entry in CPropGrid's message map.
- `this` is `0x03e729a0` (CDataModelPropGrid). The handler calls `for_each` on a `std::set<Item*>` at `this+0x218`.
  That set's head pointer is null.
- A TTD reverse write watch on `0x03e72bb8` (`this+0x218`) found the last writer at trace position `4BD92:128E`:
  - The writing function is the `_Tree` constructor at ours `0x492d10`.
  - `0x492d10` carries two names: the Ogre `map<unsigned,Vector4>` constructor from `004d8680.obj`, and the
    `map<const ClassDescriptor*, vector<shared_ptr<Instance>>>` constructor. They share code (identical folding),
    so the name alone is harmless.
  - It was called from `CDataModelPropGrid::update(shared_ptr<DataModel>, ...)`: ours `0x43c8c0`, converted object
    `00442900.obj`, return address `0x43cbbb`, with `this` = `0x03e72bb8`.
- Conclusion: in our build, `update()` treats `this+0x218` as a ClassDescriptor map, while the handler treats the
  same offset as a `set<Item*>`. This is a member-layout or binding mismatch between converted `00442900.obj` and the
  handler or CPropGrid code.
- Next steps:
  1. Disassemble the original `update` (`0x442900` in the target) near the call that returns to `0x43cbbb`. Check the
     offset of the map it constructs: is it `+0x218`, or a stack local?
  2. Compare that offset with the original CPropGrid constructor's setup of `+0x218` and with the handler's use of it.
  3. If the offsets differ, the converted object or a native header has the wrong CDataModelPropGrid layout.
     If the original also uses `+0x218` for the map, the handler side is mis-bound. Check the alias, callfix and
     `qt_results` lines for `func_00439d70`.
  4. Fix it, link once, then run the ladder and `sweep.py`.

## Tools (all under work/donorfree-route)
- `quicktest.py` links the client and writes `linkexp/qt.map`.
  - Results file: `linkexp/qt_results.txt`. Later lines win for each source.
  - Bisect switches: `QT_SKIP_RESULTS`, `QT_SKIP_ALIASES`, `QT_NO_COLALIAS`, `QT_NO_GADJ`, `QT_NO_DLLEXSTRIP`,
    `QT_NO_MSGMAPFIX`, `QT_NO_TIFIX`, `QT_OLD_CLASSGUARD`, `QT_OLD_AZERO`, `VTORIG_OBJ`.
- Generators that the link cycle consumes:
  - `relocsplit.py`, `zeroreloc.py` (cached in `auto/zeroreloc_cache.pkl`), `dupnative.py`.
  - `dllexstrip.py` (Ogre Singleton members only), `dllvt.py` and `stub-drafts/DllVtCopy.cpp`.
  - `initgen.py`, `colalias.py`, `rbxinst.py`, `deldtor_gen.py`, `classnames_gen.py`.
  - `callfix_validate.py` applies a strict per-call-site rule.
- `make_stubs.py`: EH unwind funclets (`0x7b0000` to `0x801000`) now return 0 instead of `ret 8` or `ret 16`.
  `stubret_all.py` checks every stub's `ret N` against the original.
- Probes:
  - `featladder` runs the ladder.
  - `sweep.py` runs crash-and-continue script cases and writes `auto/sweep_report.json`.
  - Fault tools: `auto/peekfault.py`, `peekthis.py`, `watchw.py`, `onecase.py`, `attachcrash.py`, `throwtrace.py`.
- `bindsrc.py SRC` compiles one source and makes it the `qt_results` line.

## TTD (time travel debugging), runs without an admin shell
- Record: `python ttdrun.py --out auto/ttd3 --secs 90`.
  - It triggers the elevated scheduled task `RoConstructTTD`.
  - The task runs `C:\ProgramData\RoTTD\ttd_runner.ps1`, which is only writable by an admin.
  - The source copy is `ttd/ttd_runner.ps1`. `--post 0xE100` posts File->New.
  - The log is `auto/ttd_runner.log`. The done marker is `auto/ttd_done.json`.
- Replay: `python ttdq.py "<cdb commands>" [RUN]`. Useful commands: `!tt <pos>`, `ba w4 <addr>`, `g-`,
  `dx @$curprocess.TTD.Events`.
- The existing trace is `auto/ttd2/RobloxQT01.run` (1.1 GB). It contains the PropGrid crash.
- To remove the task later, run as admin:
  `Unregister-ScheduledTask -TaskName RoConstructTTD -Confirm:$false; Remove-Item -Recurse C:\ProgramData\RoTTD`

## Fixed this session (do not redo)
- **Stats-view crash:** `func_005a19e0` is a boost::function invoker. Its stub used `ret 8`. Fixed natively in
  `stub-drafts/StubLive_FnInvoker.cpp` plus an alias line in `aliases_override.txt`.
- **Unwind funclet stubs:** stubs that returned `ret 8` or `ret 16` corrupted the stack during unwind. Fixed in
  `make_stubs.py`.
- **NetworkSettings startup exception:** the analog ThrowInfo escaped `catch(std::exception)`. `zeroreloc.py` now
  retargets `__TI` to the registry ThrowInfo.
- **Script crash on Part parent:** a wrong begin/end callfix rename. Fixed by the strict validator.
- **Other fixes:** MeshPtr initializer globals (`initgen`); a bogus zero relocation in the RenderableListener
  vtable (`zeroreloc`); rgmain data thunks (`stub-drafts/OgreConstImports.cpp`, `dllvt`); and the Instance signal and
  function descriptors plus Service descriptors (native-classes `*Descriptors.cpp`, leased headers
  `v8tree/Instance.h` and `v8tree/Service.h`).
- **Dead ends:** `descinit.py` (the converted initializers are analog mocks); a bulk `__imp_` retarget; stripping all
  rgmain exports (it broke File->New); generic vcall thunks for non-RBX classes (they crash CPropGrid).
- **Bisect note:** turning off any single toggle does not restore 9/9; only turning off all of them does. The 9/9
  result reported in dossier section 30 was a misreading of the Ladder14 control run.

## Backlog after the PropGrid crash
- Link with everything on, then run the ladder, `sweep.py` and the scripttest feature/solo tests. Re-run the static
  audits.
- Fix about 86 failing `rbxinst` templates (header mismatches) and `RefType::singleton`.
- Scintilla runtime classes.
- About 50 live mutable Ogre statics.
- Humanoid properties.
- Remove the `dbg literal` print in `quicktest.py`.
- Tiers 3 to 7 of the ladder.
