# P6 acceptance audit

Verdict: **scoped pass of the offline client gate; not a recovered application.**

The roadmap's listed checks ran on one build. The app is a new MFC/XTP client
following the original startup order, hosting the recovered player engine. It is
not the recovered `CRobloxApp`, and it is not byte-verified. No server credit.

## Gate

| Requirement | Result | Evidence |
|---|---|---|
| New x86 `Roblox.exe`, ordinary launch | Pass | `ordinary_launch.py`: place path only, no test flags |
| Opens a local place | Pass | Command line, resource 129 template |
| Accepts input | Pass | Real W, 3 of 3 runs reach the wall at z=18.99 |
| Exits cleanly twice | Pass | Two `WM_CLOSE` runs, exit 0 |
| Entry in map | Pass | `_WinMain@16`, `CRobloxApp::InitInstance` in `Roblox.map` |
| Runtime trace | Pass | Client `startup-stages.txt`; original `original-startup.json` |
| Edit, save, reopen, compare | Pass | Brick moved to 3,4,5 and renamed; same after reopen |
| Original opens the saved place | Pass, visual | `Roblox - [gate.rbxl]`; no original memory read |

Evidence: `work/2008-06/p6-client/`, including `gate.txt`.

## Original UI inventory

Present: 8 menus, toolbars 128/137/135, document tabs, Explorer with class icons,
Properties, Output, status FPS, script editor, Object Browser, in-view strip.
Working commands: New, Open, Save, Close, Exit, About, Undo (moves), Clear,
Execute Script, Run, Pause, Reset, Play Solo, Full Screen, click select, drag,
orbit, zoom.

Not present or unbound: Publish and web dialogs, Print, Cut/Copy/Paste, Duplicate,
Find/Replace, Group, Insert menu, Format menu, Tools other than the above,
toolbars 145/147/150, drag handles, Settings dialog.

## Deliberately not done

- Template 185 and Start Page: online URL, outside the offline gate.
- Crash reporter: uploads to an online service.
- `/RegServer`, `/Unregserver`: exit without registering. Real registration
  writes machine-wide COM keys and needs Colin's explicit go-ahead.
- Native type and name registration calls: the donor engine registers its own.

## Known limits

- Single place document: the engine holds one DataModel.
- Scintilla has no Lua highlighting. Double-click script open and grid typing
  are untested with real input.
- `CoordinateFrame` string conversion hangs and is skipped. Internal properties
  show because `PropertyDescriptor::isPublic` is undefined.
- 60 Hz cap, not the original deadline loop 00555190.
- The original spends about 2.2 s in setup this client skips.
- Merged Codex through cc5796493c, so later P5 work is absent.
- Mixed `_afxForce*` shims, original resources copied into a generated `.res`.
