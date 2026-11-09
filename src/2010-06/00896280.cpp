// from server: 100% by auto
// roc 2010-06 00896280  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00896280
//
// 00896280  8bc1                 mov eax, ecx
// 00896282  33c9                 xor ecx, ecx
// 00896284  89480c               mov dword ptr [eax + 0xc], ecx
// 00896287  894810               mov dword ptr [eax + 0x10], ecx
// 0089628a  894808               mov dword ptr [eax + 8], ecx
// 0089628d  894804               mov dword ptr [eax + 4], ecx
// 00896290  894814               mov dword ptr [eax + 0x14], ecx
// 00896293  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00896297  c7004401a700         mov dword ptr [eax], 0xa70144
// 0089629d  894818               mov dword ptr [eax + 0x18], ecx
// 008962a0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
