// from server: 100% by auto
// roc 2009-12 008049c0  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008049c0
//
// 008049c0  8b442404             mov eax, dword ptr [esp + 4]
// 008049c4  85c0                 test eax, eax
// 008049c6  7403                 je 0x8049cb
// 008049c8  8b4020               mov eax, dword ptr [eax + 0x20]
// 008049cb  8b542408             mov edx, dword ptr [esp + 8]
// 008049cf  52                   push edx
// 008049d0  50                   push eax
// 008049d1  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008049d4  50                   push eax
// 008049d5  ff15e4ca9800         call dword ptr [0x98cae4]
// 008049db  50                   push eax
// 008049dc  e849f1feff           call 0x7f3b2a
// 008049e1  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?GetNextDlgTabItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
