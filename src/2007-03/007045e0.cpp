// from server: 100% by auto
// roc 2007-03 007045e0  unit: seg_00700000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007045e0
//
// 007045e0  8bc1                 mov eax, ecx
// 007045e2  33c9                 xor ecx, ecx
// 007045e4  89480c               mov dword ptr [eax + 0xc], ecx
// 007045e7  894810               mov dword ptr [eax + 0x10], ecx
// 007045ea  894808               mov dword ptr [eax + 8], ecx
// 007045ed  894804               mov dword ptr [eax + 4], ecx
// 007045f0  894814               mov dword ptr [eax + 0x14], ecx
// 007045f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007045f7  c700fcd57d00         mov dword ptr [eax], 0x7dd5fc
// 007045fd  894818               mov dword ptr [eax + 0x18], ecx
// 00704600  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
