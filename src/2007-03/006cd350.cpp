// from server: 100% by auto
// roc 2007-03 006cd350  unit: seg_006c0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006cd350
//
// 006cd350  8bc1                 mov eax, ecx
// 006cd352  33c9                 xor ecx, ecx
// 006cd354  89480c               mov dword ptr [eax + 0xc], ecx
// 006cd357  894810               mov dword ptr [eax + 0x10], ecx
// 006cd35a  894808               mov dword ptr [eax + 8], ecx
// 006cd35d  894804               mov dword ptr [eax + 4], ecx
// 006cd360  894814               mov dword ptr [eax + 0x14], ecx
// 006cd363  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006cd367  c700686f7d00         mov dword ptr [eax], 0x7d6f68
// 006cd36d  894818               mov dword ptr [eax + 0x18], ecx
// 006cd370  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
