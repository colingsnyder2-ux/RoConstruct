// from server: 100% by auto
// roc 2008-06 007874f0  unit: CXTColorPageStandard  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007874f0
//
// 007874f0  8bc1                 mov eax, ecx
// 007874f2  33c9                 xor ecx, ecx
// 007874f4  89480c               mov dword ptr [eax + 0xc], ecx
// 007874f7  894810               mov dword ptr [eax + 0x10], ecx
// 007874fa  894808               mov dword ptr [eax + 8], ecx
// 007874fd  894804               mov dword ptr [eax + 4], ecx
// 00787500  894814               mov dword ptr [eax + 0x14], ecx
// 00787503  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00787507  c700f4998600         mov dword ptr [eax], 0x8699f4
// 0078750d  894818               mov dword ptr [eax + 0x18], ecx
// 00787510  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
