// from server: 100% by auto
// roc 2010-06 007b8b20  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b8b20
//
// 007b8b20  8b442404             mov eax, dword ptr [esp + 4]
// 007b8b24  85c0                 test eax, eax
// 007b8b26  7403                 je 0x7b8b2b
// 007b8b28  8b4020               mov eax, dword ptr [eax + 0x20]
// 007b8b2b  8b542408             mov edx, dword ptr [esp + 8]
// 007b8b2f  52                   push edx
// 007b8b30  50                   push eax
// 007b8b31  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007b8b34  50                   push eax
// 007b8b35  ff15bcba9e00         call dword ptr [0x9ebabc]
// 007b8b3b  50                   push eax
// 007b8b3c  e829f1feff           call 0x7a7c6a
// 007b8b41  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?GetNextDlgGroupItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
