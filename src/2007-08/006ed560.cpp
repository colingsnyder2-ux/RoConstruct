// from server: 100% by auto
// roc 2007-08 006ed560  unit: CXTPDockingPaneContext  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ed560
//
// 006ed560  8bc1                 mov eax, ecx
// 006ed562  33c9                 xor ecx, ecx
// 006ed564  89480c               mov dword ptr [eax + 0xc], ecx
// 006ed567  894810               mov dword ptr [eax + 0x10], ecx
// 006ed56a  894808               mov dword ptr [eax + 8], ecx
// 006ed56d  894804               mov dword ptr [eax + 4], ecx
// 006ed570  894814               mov dword ptr [eax + 0x14], ecx
// 006ed573  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006ed577  c7000caf7d00         mov dword ptr [eax], 0x7daf0c
// 006ed57d  894818               mov dword ptr [eax + 0x18], ecx
// 006ed580  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
