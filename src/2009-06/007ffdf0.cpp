// from server: 100% by auto
// roc 2009-06 007ffdf0  unit: CXTColorPageStandard  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ffdf0
//
// 007ffdf0  8bc1                 mov eax, ecx
// 007ffdf2  33c9                 xor ecx, ecx
// 007ffdf4  89480c               mov dword ptr [eax + 0xc], ecx
// 007ffdf7  894810               mov dword ptr [eax + 0x10], ecx
// 007ffdfa  894808               mov dword ptr [eax + 8], ecx
// 007ffdfd  894804               mov dword ptr [eax + 4], ecx
// 007ffe00  894814               mov dword ptr [eax + 0x14], ecx
// 007ffe03  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007ffe07  c700b4aa9000         mov dword ptr [eax], 0x90aab4
// 007ffe0d  894818               mov dword ptr [eax + 0x18], ecx
// 007ffe10  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
