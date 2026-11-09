// from server: 100% by auto
// roc 2010-06 0088eb10  unit: CXTColorPageStandard  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088eb10
//
// 0088eb10  8bc1                 mov eax, ecx
// 0088eb12  33c9                 xor ecx, ecx
// 0088eb14  89480c               mov dword ptr [eax + 0xc], ecx
// 0088eb17  894810               mov dword ptr [eax + 0x10], ecx
// 0088eb1a  894808               mov dword ptr [eax + 8], ecx
// 0088eb1d  894804               mov dword ptr [eax + 4], ecx
// 0088eb20  894814               mov dword ptr [eax + 0x14], ecx
// 0088eb23  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0088eb27  c7001cf2a600         mov dword ptr [eax], 0xa6f21c
// 0088eb2d  894818               mov dword ptr [eax + 0x18], ecx
// 0088eb30  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
