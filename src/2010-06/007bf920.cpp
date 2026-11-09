// from server: 100% by auto
// roc 2010-06 007bf920  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bf920
//
// 007bf920  8bc1                 mov eax, ecx
// 007bf922  33c9                 xor ecx, ecx
// 007bf924  894804               mov dword ptr [eax + 4], ecx
// 007bf927  89480c               mov dword ptr [eax + 0xc], ecx
// 007bf92a  894810               mov dword ptr [eax + 0x10], ecx
// 007bf92d  894814               mov dword ptr [eax + 0x14], ecx
// 007bf930  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007bf934  c7002074a500         mov dword ptr [eax], 0xa57420
// 007bf93a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007bf941  894818               mov dword ptr [eax + 0x18], ecx
// 007bf944  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
