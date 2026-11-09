// from server: 100% by auto
// roc 2007-03 006f45d0  unit: seg_006f0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f45d0
//
// 006f45d0  8bc1                 mov eax, ecx
// 006f45d2  33c9                 xor ecx, ecx
// 006f45d4  89480c               mov dword ptr [eax + 0xc], ecx
// 006f45d7  894810               mov dword ptr [eax + 0x10], ecx
// 006f45da  894808               mov dword ptr [eax + 8], ecx
// 006f45dd  894804               mov dword ptr [eax + 4], ecx
// 006f45e0  894814               mov dword ptr [eax + 0x14], ecx
// 006f45e3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f45e7  c700d4b17d00         mov dword ptr [eax], 0x7db1d4
// 006f45ed  894818               mov dword ptr [eax + 0x18], ecx
// 006f45f0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
