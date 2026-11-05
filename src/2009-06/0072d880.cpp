// from server: 100% by auto
// roc 2009-06 0072d880  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072d880
//
// 0072d880  8b442404             mov eax, dword ptr [esp + 4]
// 0072d884  85c0                 test eax, eax
// 0072d886  7403                 je 0x72d88b
// 0072d888  8b4020               mov eax, dword ptr [eax + 0x20]
// 0072d88b  8b542408             mov edx, dword ptr [esp + 8]
// 0072d88f  52                   push edx
// 0072d890  50                   push eax
// 0072d891  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0072d894  50                   push eax
// 0072d895  ff15f8ee8900         call dword ptr [0x89eef8]
// 0072d89b  50                   push eax
// 0072d89c  e861b4feff           call 0x718d02
// 0072d8a1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?GetNextDlgGroupItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
