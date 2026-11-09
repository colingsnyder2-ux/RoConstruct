// from server: 100% by auto
// roc 2007-08 006d80b0  unit: CXTPDockingPaneBase  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d80b0
//
// 006d80b0  8bc1                 mov eax, ecx
// 006d80b2  33c9                 xor ecx, ecx
// 006d80b4  89480c               mov dword ptr [eax + 0xc], ecx
// 006d80b7  894810               mov dword ptr [eax + 0x10], ecx
// 006d80ba  894808               mov dword ptr [eax + 8], ecx
// 006d80bd  894804               mov dword ptr [eax + 4], ecx
// 006d80c0  894814               mov dword ptr [eax + 0x14], ecx
// 006d80c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006d80c7  c700208c7d00         mov dword ptr [eax], 0x7d8c20
// 006d80cd  894818               mov dword ptr [eax + 0x18], ecx
// 006d80d0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
