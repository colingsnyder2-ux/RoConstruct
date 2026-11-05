// from server: 100% by auto
// roc 2010-06 0040f760  unit: boost::bad_weak_ptr  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040f760
//
// 0040f760  8b442404             mov eax, dword ptr [esp + 4]
// 0040f764  85c0                 test eax, eax
// 0040f766  7515                 jne 0x40f77d
// 0040f768  8b542408             mov edx, dword ptr [esp + 8]
// 0040f76c  52                   push edx
// 0040f76d  50                   push eax
// 0040f76e  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040f771  6a30                 push 0x30
// 0040f773  50                   push eax
// 0040f774  ff1554ba9e00         call dword ptr [0x9eba54]
// 0040f77a  c20800               ret 8
// 0040f77d  8b542408             mov edx, dword ptr [esp + 8]
// 0040f781  8b4004               mov eax, dword ptr [eax + 4]
// 0040f784  52                   push edx
// 0040f785  50                   push eax
// 0040f786  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040f789  6a30                 push 0x30
// 0040f78b  50                   push eax
// 0040f78c  ff1554ba9e00         call dword ptr [0x9eba54]
// 0040f792  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?SetFont@CWnd@@QAEXPAVCFont@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
