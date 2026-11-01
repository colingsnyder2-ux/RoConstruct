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
| 23 | 0044d790 | Unnamed; likely Run (inferred) | Slot follows InitInstance |
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

## Next

Read 0044d810 end to end, list its first ordered calls, then build a minimal
`p6-app` module: real CRobloxApp shell, resources, MFC and XTP, opening a window
and exiting cleanly, before attaching the engine. Renaming the player harness
does not count.
