// from server: 100% by auto
// roc 2007-03 006c12a0  unit: seg_006c0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c12a0
//
// 006c12a0  8bc1                 mov eax, ecx
// 006c12a2  33c9                 xor ecx, ecx
// 006c12a4  89480c               mov dword ptr [eax + 0xc], ecx
// 006c12a7  894810               mov dword ptr [eax + 0x10], ecx
// 006c12aa  894808               mov dword ptr [eax + 8], ecx
// 006c12ad  894804               mov dword ptr [eax + 4], ecx
// 006c12b0  894814               mov dword ptr [eax + 0x14], ecx
// 006c12b3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006c12b7  c70078597d00         mov dword ptr [eax], 0x7d5978
// 006c12bd  894818               mov dword ptr [eax + 0x18], ecx
// 006c12c0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
