// from server: 100% by auto
// roc 2007-03 006d62e0  unit: seg_006d0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d62e0
//
// 006d62e0  8bc1                 mov eax, ecx
// 006d62e2  33c9                 xor ecx, ecx
// 006d62e4  89480c               mov dword ptr [eax + 0xc], ecx
// 006d62e7  894810               mov dword ptr [eax + 0x10], ecx
// 006d62ea  894808               mov dword ptr [eax + 8], ecx
// 006d62ed  894804               mov dword ptr [eax + 4], ecx
// 006d62f0  894814               mov dword ptr [eax + 0x14], ecx
// 006d62f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006d62f7  c7000c7c7d00         mov dword ptr [eax], 0x7d7c0c
// 006d62fd  894818               mov dword ptr [eax + 0x18], ecx
// 006d6300  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
