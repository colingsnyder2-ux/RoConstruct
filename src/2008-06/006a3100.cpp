// from server: 100% by auto
// roc 2008-06 006a3100  unit: CRobloxControlColorSelector  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a3100
//
// 006a3100  8bc1                 mov eax, ecx
// 006a3102  33c9                 xor ecx, ecx
// 006a3104  894804               mov dword ptr [eax + 4], ecx
// 006a3107  89480c               mov dword ptr [eax + 0xc], ecx
// 006a310a  894810               mov dword ptr [eax + 0x10], ecx
// 006a310d  894814               mov dword ptr [eax + 0x14], ecx
// 006a3110  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a3114  c70004048500         mov dword ptr [eax], 0x850404
// 006a311a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006a3121  894818               mov dword ptr [eax + 0x18], ecx
// 006a3124  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
