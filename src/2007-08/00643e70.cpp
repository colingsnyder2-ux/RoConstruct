// from server: 100% by auto
// roc 2007-08 00643e70  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00643e70
//
// 00643e70  8b442404             mov eax, dword ptr [esp + 4]
// 00643e74  85c0                 test eax, eax
// 00643e76  7403                 je 0x643e7b
// 00643e78  8b4020               mov eax, dword ptr [eax + 0x20]
// 00643e7b  8b542408             mov edx, dword ptr [esp + 8]
// 00643e7f  52                   push edx
// 00643e80  50                   push eax
// 00643e81  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00643e84  50                   push eax
// 00643e85  ff1564ee7700         call dword ptr [0x77ee64]
// 00643e8b  50                   push eax
// 00643e8c  e82fc3feff           call 0x6301c0
// 00643e91  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?GetNextDlgTabItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
