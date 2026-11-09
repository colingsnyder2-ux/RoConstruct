// from server: 100% by auto
// roc 2011-06 008cef40  unit: CXTPDockingPaneContext  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008cef40
//
// 008cef40  8bc1                 mov eax, ecx
// 008cef42  33c9                 xor ecx, ecx
// 008cef44  894804               mov dword ptr [eax + 4], ecx
// 008cef47  89480c               mov dword ptr [eax + 0xc], ecx
// 008cef4a  894810               mov dword ptr [eax + 0x10], ecx
// 008cef4d  894814               mov dword ptr [eax + 0x14], ecx
// 008cef50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008cef54  c700b473ad00         mov dword ptr [eax], 0xad73b4
// 008cef5a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008cef61  894818               mov dword ptr [eax + 0x18], ecx
// 008cef64  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
