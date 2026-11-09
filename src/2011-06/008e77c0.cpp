// from server: 100% by auto
// roc 2011-06 008e77c0  unit: CXTColorPageStandard  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e77c0
//
// 008e77c0  8bc1                 mov eax, ecx
// 008e77c2  33c9                 xor ecx, ecx
// 008e77c4  89480c               mov dword ptr [eax + 0xc], ecx
// 008e77c7  894810               mov dword ptr [eax + 0x10], ecx
// 008e77ca  894808               mov dword ptr [eax + 8], ecx
// 008e77cd  894804               mov dword ptr [eax + 4], ecx
// 008e77d0  894814               mov dword ptr [eax + 0x14], ecx
// 008e77d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008e77d7  c700448dad00         mov dword ptr [eax], 0xad8d44
// 008e77dd  894818               mov dword ptr [eax + 0x18], ecx
// 008e77e0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
