// from server: 100% by auto
// roc 2010-06 00882310  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882310
//
// 00882310  8b442404             mov eax, dword ptr [esp + 4]
// 00882314  8b542408             mov edx, dword ptr [esp + 8]
// 00882318  894110               mov dword ptr [ecx + 0x10], eax
// 0088231b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0088231f  895114               mov dword ptr [ecx + 0x14], edx
// 00882322  8b542410             mov edx, dword ptr [esp + 0x10]
// 00882326  894118               mov dword ptr [ecx + 0x18], eax
// 00882329  89511c               mov dword ptr [ecx + 0x1c], edx
// 0088232c  c21000               ret 0x10
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetRect@CXTPTabManagerNavigateButton@@QAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
