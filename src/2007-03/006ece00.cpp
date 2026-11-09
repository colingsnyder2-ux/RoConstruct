// from server: 100% by auto
// roc 2007-03 006ece00  unit: seg_006e0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ece00
//
// 006ece00  8bc1                 mov eax, ecx
// 006ece02  33c9                 xor ecx, ecx
// 006ece04  89480c               mov dword ptr [eax + 0xc], ecx
// 006ece07  894810               mov dword ptr [eax + 0x10], ecx
// 006ece0a  894808               mov dword ptr [eax + 8], ecx
// 006ece0d  894804               mov dword ptr [eax + 4], ecx
// 006ece10  894814               mov dword ptr [eax + 0x14], ecx
// 006ece13  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006ece17  c700b4a17d00         mov dword ptr [eax], 0x7da1b4
// 006ece1d  894818               mov dword ptr [eax + 0x18], ecx
// 006ece20  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
