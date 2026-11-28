# Donor-free client rulebook (2026-11-25 night run)

Goal tonight: `run/RobloxQT.exe` launched normally → File→New → world runs with no crash.
Then the feature ladder below.

## Rule 1: never fix one function at a time
A crash is a **sample of a bug class**, not the bug. For every crash:
1. **Diagnose** to the root mechanism: wrong ret size, wrong binding, stale stub, duplicate init, null table…
2. **Name the class** and write the *audit* that finds every member statically (seconds, no run).
3. **Pilot:** fix the crash site plus a few others the audit found. Relink once, confirm the crash moved.
4. **Speed up:** cache / batch the audit and make it part of every link.
5. **Full launch:** apply to all members in the same relink.

Only fall back to a one-off fix when the audit has a single member. Even then, record the rule.

## Rule 2: one relink carries many fixes
- A relink costs about 2 min (`quicktest.py 0`); renamed_link adds about 3 min. Never relink for one change.
- Before relinking, run every static audit and fold all their fixes in.
- Reconvert only affected objects: `rename_par.py 12 --addrs auto/X.json`, then `renamed_link.py`.

## Rule 3: run order after each relink (cheapest first)
1. Static audits (seconds): `callaudit.py`, `dataaudit.py`, `impcheck.py`, ret-size checks.
2. `shot.py`: real launch plus screenshot. It also cleans up IE/Edge windows.
3. Crashed → `oneshot.py` (crash site, stubs hit, C++ throws). Probe behaves differently? → `attachcrash.py`.
4. Narrow with WATCH / BPENTRY / ENTRY_MEM / ENTRY_WALK / PEEK / TRACE_ENTRY (crashsite env options).
5. **File→New must be tested on the real UI path.** The window at launch is the startup "Untitled" document.

## Rule 4: generic fixes live in the pipeline, grow-only
Every fix is a rule applied at link time. State is persisted and only grows:
- `auto/*.json` (nameinit_found, dllimports_found, callfix_plan, valsizes)
- `aliases_*.txt`

A rerun must never drop an earlier fix (this already happened 3 times).

## Known bug classes (each now has a generic fix)
| Class | Symptom | Fix (runs every link) |
|---|---|---|
| Duplicate `.CRT$XCU` entries | Init runs twice; MFC class-list cycle; badClass | `xcudedup.py` |
| `dat_` placeholder = CRuntimeClass | `IsKindOf` fails | `rtclass.py` → `aliases_rtclass.txt` |
| Thunk stub took the neighbour's `ret N` | Stack skew, return into heap | `make_stubs.addr_ret_bytes` stops at jmp |
| By-value struct sized as 4 | Stack skew (Heartbeat 8) | `valsizes.py` → `auto/valsizes.json` |
| Stale base-stub `dat_` copies | Null pointer inside tables (message map) | quicktest rebuilds base `dat_` |
| Analog callee name binds the wrong real function | Wrong code runs | `callaudit.py` + `callfix.py` |
| Field-of-global binding swallows the next global | Writes land in other objects | `rename.py` keeps the analog's own small global |
| Stubbed DLL exports | Null / zero result | `dllimports.py` (grow-only) |
| Shifted vtables | Wrong virtual called | `vt_orig.obj` (vtorig --all) |
| `vt_orig` named `6B@` as the offset-0 table | Listener/GUI interfaces called the wrong function (heartbeat, input) | `vt_orig_remap.obj`: registry name→table, 304/native-COL rule (`auto/vt_force.json`, vtdiff_obj.py) |
| vt slot bound by a folded registry name | Wrong function, wrong pop size | `natret.py` + `vtfix.py` (grow-only list) |
| Foreign-analog helpers / private statics | Wrong init or state split (SafeChat, getNullName) | callaudit DIR32 + helper rule, callfix local retarget, `datafix.py` |
| `dat_X` vs native `g_X` global | Split state | rtclass.py `g_<addr>` alias |
| Exact conversions not linked (mass list) | Stub instead of real code | `ROC_LINK_ALL=1 renamed_link.py` |
| Thunks stubbed | `return 0` instead of `this`-adjust + jump | `glue.py` (coffstub relocations) |
| Virtual-forwarding thunks stubbed (`mov eax,[ecx]; jmp [eax+N]`) | Message-map handler returns 0 | `glue.py` vcall pattern |
| Stubbed `delete` slot (deleting dtor) | Hook sink never removed; WM_PAINT storm, 100% CPU | `dtorslots.py` → vtfix list |
| `dat_` placeholder for a native-owned global | State split (XTP hook-manager singleton) | `natdata.py` (+ natext copies make statics external) |
| C name used only as data, stubbed as code | Write to a code page | `cnames.py` → `auto/cdata.json` |
| `create<C>` stubbed | Null instance | `createinst.py` |
| Registry-folded static (`doDeclare<sDecal>::n`) shared by many converted copies | 50 Names in one slot; `clientIsPresent` true, Run greyed | `foldaudit.py` → `auto/foldfix_plan.json` (data only; code `__ehhandler`/`??__F` folds parked) |
| Converted body under a WRONG registry name beats the native definition | `mutex::do_lock` posed as `recursive_mutex::do_lock`; recursive count went negative, Run deadlocked | `natbody_check.py` (candidates) → curated `auto/natbody_defrename.json` |
| Native draft calls the wrong callee (misdeclared type) | Plain mutex locked with the recursive lock; next member corrupted | `natcallaudit.py` → `auto/natcallfix_plan.json` |
| callaudit not refreshed | Converted callers keep a stale binding | quicktest now runs `callaudit.py` before every link |

Diagnosis aids: `attachcrash.py` (ATTACH_POST=0xE100,0x80c6; ATTACH_WATCH=addr hardware write watch on all threads;
ATTACH_ECX filters ATTACH_CALLER tallies), `spinsample.py` (SPIN_POST list, SPIN_ALL=1 every thread's exe frames for
lock holders), `shot.py` (SHOT_POST=0x80c6 commands after File→New). Pilot lesson: a fix that unblocks a path
(correct locking) exposes the next bug class on that path. Fix the class, never revert the correct fix.
Pilot lesson 11-25: two "class-wide" rules (vtable slot-truth overrides, COL-offset remap) broke things;
parallel variants (`variants.py`) and a known-good object (`vt_orig_prev.obj`) caught both within one round.
| Zero `Name&` globals | Wrong attribute lookups | `nameinit.py` |

## Feature ladder (after File→New is stable)
Each step: use the feature, then apply Rules 1–3 to its crashes.
1. File→New: world view renders, camera moves, no crash for 60 s.
2. Insert → Object / Insert → Service dialogs, with insert into Workspace.
3. Explorer + Properties panes: select an object, edit a property.
4. Run / Play (RunService start, physics steps), Stop. **Run works 11-25** (t advances, Pause/Reset enabled).
5. Toolbox / parts: drag, move, rotate, group.
6. Save / Open a place file (.rbxl).
7. Scripts: insert Script, edit, run.
8. Multiplayer / network: Play Solo, then server/client.

## Safety
- Commit only when the owner asks. Never push. Lease before editing native classes or headers.
- Don't close the user's own windows. IE/Edge cleanup only touches windows opened during our runs.
- Don't edit `clients/` or `tools/` by hand. Ask before deleting anything not created here.
