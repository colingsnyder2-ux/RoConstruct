// from server: 100% by auto
// roc 2009-06 007e2e60  unit: CXTPDockingPaneContext  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e2e60
//
// 007e2e60  8bc1                 mov eax, ecx
// 007e2e62  33c9                 xor ecx, ecx
// 007e2e64  894804               mov dword ptr [eax + 4], ecx
// 007e2e67  89480c               mov dword ptr [eax + 0xc], ecx
// 007e2e6a  894810               mov dword ptr [eax + 0x10], ecx
// 007e2e6d  894814               mov dword ptr [eax + 0x14], ecx
// 007e2e70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e2e74  c7004c829000         mov dword ptr [eax], 0x90824c
// 007e2e7a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007e2e81  894818               mov dword ptr [eax + 0x18], ecx
// 007e2e84  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
