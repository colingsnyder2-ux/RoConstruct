// from server: 100% by auto
// roc 2009-06 008074f0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008074f0
//
// 008074f0  8bc1                 mov eax, ecx
// 008074f2  33c9                 xor ecx, ecx
// 008074f4  89480c               mov dword ptr [eax + 0xc], ecx
// 008074f7  894810               mov dword ptr [eax + 0x10], ecx
// 008074fa  894808               mov dword ptr [eax + 8], ecx
// 008074fd  894804               mov dword ptr [eax + 4], ecx
// 00807500  894814               mov dword ptr [eax + 0x14], ecx
// 00807503  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00807507  c700dcb99000         mov dword ptr [eax], 0x90b9dc
// 0080750d  894818               mov dword ptr [eax + 0x18], ecx
// 00807510  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
