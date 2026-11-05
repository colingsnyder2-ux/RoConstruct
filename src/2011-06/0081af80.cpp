// from server: 100% by auto
// roc 2011-06 0081af80  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081af80
//
// 0081af80  8b442404             mov eax, dword ptr [esp + 4]
// 0081af84  85c0                 test eax, eax
// 0081af86  7403                 je 0x81af8b
// 0081af88  8b4020               mov eax, dword ptr [eax + 0x20]
// 0081af8b  8b542408             mov edx, dword ptr [esp + 8]
// 0081af8f  52                   push edx
// 0081af90  50                   push eax
// 0081af91  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0081af94  50                   push eax
// 0081af95  ff15f81aa400         call dword ptr [0xa41af8]
// 0081af9b  50                   push eax
// 0081af9c  e887f3feff           call 0x80a328
// 0081afa1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?GetNextDlgGroupItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
