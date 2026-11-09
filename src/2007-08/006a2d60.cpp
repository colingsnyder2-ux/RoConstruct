// from server: 100% by auto
// roc 2007-08 006a2d60  unit: CXTPHookManagerHookAble  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a2d60
//
// 006a2d60  8bc1                 mov eax, ecx
// 006a2d62  33c9                 xor ecx, ecx
// 006a2d64  89480c               mov dword ptr [eax + 0xc], ecx
// 006a2d67  894810               mov dword ptr [eax + 0x10], ecx
// 006a2d6a  894808               mov dword ptr [eax + 8], ecx
// 006a2d6d  894804               mov dword ptr [eax + 4], ecx
// 006a2d70  894814               mov dword ptr [eax + 0x14], ecx
// 006a2d73  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a2d77  c70008357d00         mov dword ptr [eax], 0x7d3508
// 006a2d7d  894818               mov dword ptr [eax + 0x18], ecx
// 006a2d80  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
