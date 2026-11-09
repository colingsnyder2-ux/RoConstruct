// from server: 100% by auto
// roc 2009-12 008396c0  unit: CXTPDockingPaneManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008396c0
//
// 008396c0  8bc1                 mov eax, ecx
// 008396c2  33c9                 xor ecx, ecx
// 008396c4  89480c               mov dword ptr [eax + 0xc], ecx
// 008396c7  894810               mov dword ptr [eax + 0x10], ecx
// 008396ca  894808               mov dword ptr [eax + 8], ecx
// 008396cd  894804               mov dword ptr [eax + 4], ecx
// 008396d0  894814               mov dword ptr [eax + 0x14], ecx
// 008396d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008396d7  c70050809f00         mov dword ptr [eax], 0x9f8050
// 008396dd  894818               mov dword ptr [eax + 0x18], ecx
// 008396e0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
