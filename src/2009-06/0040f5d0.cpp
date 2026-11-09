// from server: 100% by auto
// roc 2009-06 0040f5d0  unit: boost::bad_weak_ptr  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040f5d0
//
// 0040f5d0  8b442404             mov eax, dword ptr [esp + 4]
// 0040f5d4  85c0                 test eax, eax
// 0040f5d6  7515                 jne 0x40f5ed
// 0040f5d8  8b542408             mov edx, dword ptr [esp + 8]
// 0040f5dc  52                   push edx
// 0040f5dd  50                   push eax
// 0040f5de  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040f5e1  6a30                 push 0x30
// 0040f5e3  50                   push eax
// 0040f5e4  ff1590ee8900         call dword ptr [0x89ee90]
// 0040f5ea  c20800               ret 8
// 0040f5ed  8b542408             mov edx, dword ptr [esp + 8]
// 0040f5f1  8b4004               mov eax, dword ptr [eax + 4]
// 0040f5f4  52                   push edx
// 0040f5f5  50                   push eax
// 0040f5f6  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040f5f9  6a30                 push 0x30
// 0040f5fb  50                   push eax
// 0040f5fc  ff1590ee8900         call dword ptr [0x89ee90]
// 0040f602  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?SetFont@CWnd@@QAEXPAVCFont@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
