// from server: 100% by auto
// roc 2011-06 00821890  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00821890
//
// 00821890  8bc1                 mov eax, ecx
// 00821892  33c9                 xor ecx, ecx
// 00821894  894804               mov dword ptr [eax + 4], ecx
// 00821897  89480c               mov dword ptr [eax + 0xc], ecx
// 0082189a  894810               mov dword ptr [eax + 0x10], ecx
// 0082189d  894814               mov dword ptr [eax + 0x14], ecx
// 008218a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008218a4  c7005030ac00         mov dword ptr [eax], 0xac3050
// 008218aa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008218b1  894818               mov dword ptr [eax + 0x18], ecx
// 008218b4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
