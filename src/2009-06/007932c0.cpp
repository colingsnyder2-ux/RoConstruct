// from server: 100% by auto
// roc 2009-06 007932c0  unit: CXTPHookManagerHookAble  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007932c0
//
// 007932c0  8bc1                 mov eax, ecx
// 007932c2  33c9                 xor ecx, ecx
// 007932c4  89480c               mov dword ptr [eax + 0xc], ecx
// 007932c7  894810               mov dword ptr [eax + 0x10], ecx
// 007932ca  894808               mov dword ptr [eax + 8], ecx
// 007932cd  894804               mov dword ptr [eax + 4], ecx
// 007932d0  894814               mov dword ptr [eax + 0x14], ecx
// 007932d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007932d7  c70038019000         mov dword ptr [eax], 0x900138
// 007932dd  894818               mov dword ptr [eax + 0x18], ecx
// 007932e0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
