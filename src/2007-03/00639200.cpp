// from server: 100% by auto
// roc 2007-03 00639200  unit: seg_00630000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00639200
//
// 00639200  8b442404             mov eax, dword ptr [esp + 4]
// 00639204  85c0                 test eax, eax
// 00639206  7403                 je 0x63920b
// 00639208  8b4020               mov eax, dword ptr [eax + 0x20]
// 0063920b  8b542408             mov edx, dword ptr [esp + 8]
// 0063920f  52                   push edx
// 00639210  50                   push eax
// 00639211  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00639214  50                   push eax
// 00639215  ff1544ef7700         call dword ptr [0x77ef44]
// 0063921b  50                   push eax
// 0063921c  e82d54feff           call 0x61e64e
// 00639221  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?GetNextDlgTabItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
