// from server: 100% by auto
// roc 2011-06 00821850  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00821850
//
// 00821850  8bc1                 mov eax, ecx
// 00821852  33c9                 xor ecx, ecx
// 00821854  894804               mov dword ptr [eax + 4], ecx
// 00821857  89480c               mov dword ptr [eax + 0xc], ecx
// 0082185a  894810               mov dword ptr [eax + 0x10], ecx
// 0082185d  894814               mov dword ptr [eax + 0x14], ecx
// 00821860  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00821864  c7003830ac00         mov dword ptr [eax], 0xac3038
// 0082186a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00821871  894818               mov dword ptr [eax + 0x18], ecx
// 00821874  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
