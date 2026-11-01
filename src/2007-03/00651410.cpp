// from server: 100% by auto
// roc 2007-03 00651410  unit: seg_00650000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651410
//
// 00651410  53                   push ebx
// 00651411  56                   push esi
// 00651412  8bf1                 mov esi, ecx
// 00651414  57                   push edi
// 00651415  8b7e04               mov edi, dword ptr [esi + 4]
// 00651418  33db                 xor ebx, ebx
// 0065141a  3bfb                 cmp edi, ebx
// 0065141c  7421                 je 0x65143f
// 0065141e  395e08               cmp dword ptr [esi + 8], ebx
// 00651421  761c                 jbe 0x65143f
// 00651423  8b5608               mov edx, dword ptr [esi + 8]
// 00651426  8bcf                 mov ecx, edi
// 00651428  8b01                 mov eax, dword ptr [ecx]
// 0065142a  3bc3                 cmp eax, ebx
// 0065142c  7409                 je 0x651437
// 0065142e  8bff                 mov edi, edi
// 00651430  8b4048               mov eax, dword ptr [eax + 0x48]
// 00651433  3bc3                 cmp eax, ebx
// 00651435  75f9                 jne 0x651430
// 00651437  83c104               add ecx, 4
// 0065143a  83ea01               sub edx, 1
// 0065143d  75e9                 jne 0x651428
// 0065143f  57                   push edi
// 00651440  e86fcffcff           call 0x61e3b4
// 00651445  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00651448  83c404               add esp, 4
// 0065144b  895e04               mov dword ptr [esi + 4], ebx
// 0065144e  895e0c               mov dword ptr [esi + 0xc], ebx
// 00651451  895e10               mov dword ptr [esi + 0x10], ebx
// 00651454  e8b1d6fcff           call 0x61eb0a
// 00651459  5f                   pop edi
// 0065145a  895e14               mov dword ptr [esi + 0x14], ebx
// 0065145d  5e                   pop esi
// 0065145e  5b                   pop ebx
// 0065145f  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?RemoveAll@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
