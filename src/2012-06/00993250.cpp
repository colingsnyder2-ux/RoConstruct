// from server: 100% by auto
// roc 2012-06 00993250  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00993250
//
// 00993250  8b442404             mov eax, dword ptr [esp + 4]
// 00993254  85c0                 test eax, eax
// 00993256  7403                 je 0x99325b
// 00993258  8b4020               mov eax, dword ptr [eax + 0x20]
// 0099325b  8b542408             mov edx, dword ptr [esp + 8]
// 0099325f  52                   push edx
// 00993260  50                   push eax
// 00993261  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00993264  50                   push eax
// 00993265  ff15003db200         call dword ptr [0xb23d00]
// 0099326b  50                   push eax
// 0099326c  e8f5f3feff           call 0x982666
// 00993271  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?GetNextDlgGroupItem@CWnd@@QBEPAV1@PAV1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
