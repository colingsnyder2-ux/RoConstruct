// from server: 100% by auto
// roc 2008-06 006b5310  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006b5310
//
// 006b5310  8b442404             mov eax, dword ptr [esp + 4]
// 006b5314  85c0                 test eax, eax
// 006b5316  7403                 je 0x6b531b
// 006b5318  8b4020               mov eax, dword ptr [eax + 0x20]
// 006b531b  8b542408             mov edx, dword ptr [esp + 8]
// 006b531f  52                   push edx
// 006b5320  50                   push eax
// 006b5321  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006b5324  50                   push eax
// 006b5325  ff15642b8000         call dword ptr [0x802b64]
// 006b532b  50                   push eax
// 006b532c  e8adb8feff           call 0x6a0bde
// 006b5331  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?GetNextDlgGroupItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
