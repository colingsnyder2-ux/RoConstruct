// from server: 100% by auto
// roc 2009-12 008ce130  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce130
//
// 008ce130  8b442404             mov eax, dword ptr [esp + 4]
// 008ce134  8b542408             mov edx, dword ptr [esp + 8]
// 008ce138  894110               mov dword ptr [ecx + 0x10], eax
// 008ce13b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008ce13f  895114               mov dword ptr [ecx + 0x14], edx
// 008ce142  8b542410             mov edx, dword ptr [esp + 0x10]
// 008ce146  894118               mov dword ptr [ecx + 0x18], eax
// 008ce149  89511c               mov dword ptr [ecx + 0x1c], edx
// 008ce14c  c21000               ret 0x10
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetRect@CXTPTabManagerNavigateButton@@QAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
