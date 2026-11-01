// from server: 100% by auto
// roc 2009-12 008a8310  unit: CXTPDockingPaneBase  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a8310
//
// 008a8310  8bc1                 mov eax, ecx
// 008a8312  33c9                 xor ecx, ecx
// 008a8314  89480c               mov dword ptr [eax + 0xc], ecx
// 008a8317  894810               mov dword ptr [eax + 0x10], ecx
// 008a831a  894808               mov dword ptr [eax + 8], ecx
// 008a831d  894804               mov dword ptr [eax + 4], ecx
// 008a8320  894814               mov dword ptr [eax + 0x14], ecx
// 008a8323  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008a8327  c700fc62a000         mov dword ptr [eax], 0xa062fc
// 008a832d  894818               mov dword ptr [eax + 0x18], ecx
// 008a8330  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
