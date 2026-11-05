// from server: 100% by auto
// roc 2008-06 0078eeb0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0078eeb0
//
// 0078eeb0  8bc1                 mov eax, ecx
// 0078eeb2  33c9                 xor ecx, ecx
// 0078eeb4  89480c               mov dword ptr [eax + 0xc], ecx
// 0078eeb7  894810               mov dword ptr [eax + 0x10], ecx
// 0078eeba  894808               mov dword ptr [eax + 8], ecx
// 0078eebd  894804               mov dword ptr [eax + 4], ecx
// 0078eec0  894814               mov dword ptr [eax + 0x14], ecx
// 0078eec3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078eec7  c700b4a98600         mov dword ptr [eax], 0x86a9b4
// 0078eecd  894818               mov dword ptr [eax + 0x18], ecx
// 0078eed0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
