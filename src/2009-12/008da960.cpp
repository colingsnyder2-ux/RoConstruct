// from server: 100% by auto
// roc 2009-12 008da960  unit: CXTColorPageStandard  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008da960
//
// 008da960  8bc1                 mov eax, ecx
// 008da962  33c9                 xor ecx, ecx
// 008da964  89480c               mov dword ptr [eax + 0xc], ecx
// 008da967  894810               mov dword ptr [eax + 0x10], ecx
// 008da96a  894808               mov dword ptr [eax + 8], ecx
// 008da96d  894804               mov dword ptr [eax + 4], ecx
// 008da970  894814               mov dword ptr [eax + 0x14], ecx
// 008da973  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008da977  c70024afa000         mov dword ptr [eax], 0xa0af24
// 008da97d  894818               mov dword ptr [eax + 0x18], ecx
// 008da980  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
