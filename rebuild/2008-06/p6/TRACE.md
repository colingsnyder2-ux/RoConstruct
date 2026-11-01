# P6 startup trace

Static evidence from the unmodified 2008-06 `Roblox.exe`. Reproduce with
`python entry_trace.py` (paths assume `C:\Users\colin\roc-p6`). No runtime
trace yet: slot names below are inferred, marked where so.

## Entry chain

| VA | Role | Evidence |
|---|---|---|
| 006a1ba6 | Entry: security cookie, then jump | PE entry point; call 006a2348, jmp 006a18e6 |
| 006a18e6 | CRT startup | Imports GetStartupInfoA, _ismbblead, exit, _cexit |
| 006a1a21 | Calls WinMain | Direct call 007bca00, last call before exit |
| 007bca00 | WinMain thunk | Tail jump to 007bca86, inferred AfxWinMain |
| 00816a64 | CRobloxApp vtable | RTTI complete object locator |

## CRobloxApp overrides

| Slot | VA | Identity | Basis |
|---|---|---|---|
| 12 | 0044d440 | Message map getter (inferred) | Returns 00816c50 |
| 22 | 0044d810 | InitInstance | String "ROBLOX InitInstance" |
| 23 | 0044d790 | Likely Run | Runtime: entered after openFiles |
| 28 | 0044ad60 | ExitInstance | String "ROBLOX ExitInstance" |

All four have mined sources; none is natively integrated in
`docs/integration.json` at 40cbe42fa2. The WinMain thunk has no source file.

## Other vtables

- CMainFrame 00811a1c
- CRobloxDoc 00817ce4
- CRobloxView 0081933c

## Scale of the UI

Resources: 35 dialogs, 12 menus, 58 string blocks, 56 bitmaps, 99 PNGs,
2 accelerator tables, 1 typelib. 16 mined sources mention CRobloxApp and 38
mention CMainFrame. Application classes include CRobloxCommandLineInfo,
CRbxDocTemplate, CRbxPlayDocTemplate, CInstanceExplorer, CScriptEditor,
CSettingsDialog and CAboutRobloxDialog.

## Link state

- XTP links and passes its test.
- MfcAtl fails: `?AtlFindExtension@ATL@@YAPADPBD@Z`, plus imported CString
  externals in its link output.
- Ogre fails on recovered Rbx* symbols. The player avoids this by importing
  rgmain.dll, which P6 may also do.

## Client state

`build_client.py` links `out/p6/Roblox.exe`. Evidence and known limits live in
`work/2008-06/p6-client/receipt.json`; startup order in `startup-stages.txt`.

Present: XTP frame, menu 128, toolbars 128/137/135, CIDEDocManager with the 129
place template, Explorer, Properties, Run/Pause/Reset, Play Solo, File New,
Open, Save, About, Execute Script.

Open:

- Templates 185, 207 and 138; crash reporter; real COM registration.
- Edit-mode camera, selection and drag tools.
- Output pane, script editor, document tabs, Explorer icons, FPS readout,
  in-game menu overlay.
- Links libraries from the Codex build, so rebuild after engine changes.

## Source swap start

`runtime-classes.json` holds real sizes and in-exe bases for 104 MFC classes.

`CRobloxDoc` is 0x98, on a 0x54 `CDocument`. Constructor 00451ac0 calls 00451590,
then zeroes +0x74, builds a member at +0x78 with zeroed fields at +0x84, +0x88 and
+0x8c, and zeroes +0x90 and +0x94 (`workspace`). +0x54 to +0x70 is unread so far;
start at 00451590. Class swaps wait for P5 and the branch merge.
