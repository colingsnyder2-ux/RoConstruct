// from server: 100% by auto
// roc 2009-12 00402bd0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402bd0
//
// 00402bd0  8bc1                 mov eax, ecx
// 00402bd2  33c9                 xor ecx, ecx
// 00402bd4  8908                 mov dword ptr [eax], ecx
// 00402bd6  894804               mov dword ptr [eax + 4], ecx
// 00402bd9  894808               mov dword ptr [eax + 8], ecx
// 00402bdc  89480c               mov dword ptr [eax + 0xc], ecx
// 00402bdf  894810               mov dword ptr [eax + 0x10], ecx
// 00402be2  894814               mov dword ptr [eax + 0x14], ecx
// 00402be5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\doccore.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/doccore.cpp
