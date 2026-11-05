// from server: 100% by auto
// roc 2011-06 00413a30  unit: boost::bad_weak_ptr  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00413a30
//
// 00413a30  8b442404             mov eax, dword ptr [esp + 4]
// 00413a34  85c0                 test eax, eax
// 00413a36  7515                 jne 0x413a4d
// 00413a38  8b542408             mov edx, dword ptr [esp + 8]
// 00413a3c  52                   push edx
// 00413a3d  50                   push eax
// 00413a3e  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00413a41  6a30                 push 0x30
// 00413a43  50                   push eax
// 00413a44  ff15c019a400         call dword ptr [0xa419c0]
// 00413a4a  c20800               ret 8
// 00413a4d  8b542408             mov edx, dword ptr [esp + 8]
// 00413a51  8b4004               mov eax, dword ptr [eax + 4]
// 00413a54  52                   push edx
// 00413a55  50                   push eax
// 00413a56  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00413a59  6a30                 push 0x30
// 00413a5b  50                   push eax
// 00413a5c  ff15c019a400         call dword ptr [0xa419c0]
// 00413a62  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?SetFont@CWnd@@QAEXPAVCFont@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
