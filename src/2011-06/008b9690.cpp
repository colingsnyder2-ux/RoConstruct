// from server: 100% by auto
// roc 2011-06 008b9690  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b9690
//
// 008b9690  8bc1                 mov eax, ecx
// 008b9692  33c9                 xor ecx, ecx
// 008b9694  894804               mov dword ptr [eax + 4], ecx
// 008b9697  89480c               mov dword ptr [eax + 0xc], ecx
// 008b969a  894810               mov dword ptr [eax + 0x10], ecx
// 008b969d  894814               mov dword ptr [eax + 0x14], ecx
// 008b96a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008b96a4  c7001050ad00         mov dword ptr [eax], 0xad5010
// 008b96aa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008b96b1  894818               mov dword ptr [eax + 0x18], ecx
// 008b96b4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
