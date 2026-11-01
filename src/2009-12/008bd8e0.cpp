// from server: 100% by auto
// roc 2009-12 008bd8e0  unit: CXTPDockingPaneContext  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008bd8e0
//
// 008bd8e0  8bc1                 mov eax, ecx
// 008bd8e2  33c9                 xor ecx, ecx
// 008bd8e4  89480c               mov dword ptr [eax + 0xc], ecx
// 008bd8e7  894810               mov dword ptr [eax + 0x10], ecx
// 008bd8ea  894808               mov dword ptr [eax + 8], ecx
// 008bd8ed  894804               mov dword ptr [eax + 4], ecx
// 008bd8f0  894814               mov dword ptr [eax + 0x14], ecx
// 008bd8f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008bd8f7  c700a486a000         mov dword ptr [eax], 0xa086a4
// 008bd8fd  894818               mov dword ptr [eax + 0x18], ecx
// 008bd900  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
