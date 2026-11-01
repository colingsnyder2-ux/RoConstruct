// from server: 100% by auto
// roc 2009-12 0040f330  unit: boost::bad_weak_ptr  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040f330
//
// 0040f330  8b442404             mov eax, dword ptr [esp + 4]
// 0040f334  85c0                 test eax, eax
// 0040f336  7515                 jne 0x40f34d
// 0040f338  8b542408             mov edx, dword ptr [esp + 8]
// 0040f33c  52                   push edx
// 0040f33d  50                   push eax
// 0040f33e  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040f341  6a30                 push 0x30
// 0040f343  50                   push eax
// 0040f344  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0040f34a  c20800               ret 8
// 0040f34d  8b542408             mov edx, dword ptr [esp + 8]
// 0040f351  8b4004               mov eax, dword ptr [eax + 4]
// 0040f354  52                   push edx
// 0040f355  50                   push eax
// 0040f356  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040f359  6a30                 push 0x30
// 0040f35b  50                   push eax
// 0040f35c  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0040f362  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?SetFont@CWnd@@QAEXPAVCFont@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
