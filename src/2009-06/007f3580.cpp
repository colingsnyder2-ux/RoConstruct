// from server: 100% by auto
// roc 2009-06 007f3580  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3580
//
// 007f3580  8b442404             mov eax, dword ptr [esp + 4]
// 007f3584  8b542408             mov edx, dword ptr [esp + 8]
// 007f3588  894110               mov dword ptr [ecx + 0x10], eax
// 007f358b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007f358f  895114               mov dword ptr [ecx + 0x14], edx
// 007f3592  8b542410             mov edx, dword ptr [esp + 0x10]
// 007f3596  894118               mov dword ptr [ecx + 0x18], eax
// 007f3599  89511c               mov dword ptr [ecx + 0x1c], edx
// 007f359c  c21000               ret 0x10
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetRect@CXTPTabManagerNavigateButton@@QAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
