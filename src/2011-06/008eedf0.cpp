// from server: 100% by auto
// roc 2011-06 008eedf0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008eedf0
//
// 008eedf0  8bc1                 mov eax, ecx
// 008eedf2  33c9                 xor ecx, ecx
// 008eedf4  89480c               mov dword ptr [eax + 0xc], ecx
// 008eedf7  894810               mov dword ptr [eax + 0x10], ecx
// 008eedfa  894808               mov dword ptr [eax + 8], ecx
// 008eedfd  894804               mov dword ptr [eax + 4], ecx
// 008eee00  894814               mov dword ptr [eax + 0x14], ecx
// 008eee03  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008eee07  c7006c9cad00         mov dword ptr [eax], 0xad9c6c
// 008eee0d  894818               mov dword ptr [eax + 0x18], ecx
// 008eee10  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
