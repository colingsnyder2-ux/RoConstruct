// from server: 100% by auto
// roc 2007-03 00624ea0  unit: seg_00620000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00624ea0
//
// 00624ea0  8b442408             mov eax, dword ptr [esp + 8]
// 00624ea4  56                   push esi
// 00624ea5  8b742408             mov esi, dword ptr [esp + 8]
// 00624ea9  6a02                 push 2
// 00624eab  50                   push eax
// 00624eac  56                   push esi
// 00624ead  ff1590d27700         call dword ptr [0x77d290]
// 00624eb3  85c0                 test eax, eax
// 00624eb5  7504                 jne 0x624ebb
// 00624eb7  33c0                 xor eax, eax
// 00624eb9  5e                   pop esi
// 00624eba  c3                   ret 
// 00624ebb  50                   push eax
// 00624ebc  56                   push esi
// 00624ebd  ff1594d27700         call dword ptr [0x77d294]
// 00624ec3  85c0                 test eax, eax
// 00624ec5  74f0                 je 0x624eb7
// 00624ec7  50                   push eax
// 00624ec8  ff1520d27700         call dword ptr [0x77d220]
// 00624ece  85c0                 test eax, eax
// 00624ed0  74e5                 je 0x624eb7
// 00624ed2  33c9                 xor ecx, ecx
// 00624ed4  6683780e20           cmp word ptr [eax + 0xe], 0x20
// 00624ed9  5e                   pop esi
// 00624eda  0f94c1               sete cl
// 00624edd  8bc1                 mov eax, ecx
// 00624edf  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlphaBitmapResource@CXTPImageManagerIcon@@SAHPAUHINSTANCE__@@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
