// from server: 100% by auto
// roc 2009-12 007f6520  unit: CXTPPropertyGridItem  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f6520
//
// 007f6520  53                   push ebx
// 007f6521  56                   push esi
// 007f6522  8bf1                 mov esi, ecx
// 007f6524  57                   push edi
// 007f6525  8b7e04               mov edi, dword ptr [esi + 4]
// 007f6528  33db                 xor ebx, ebx
// 007f652a  3bfb                 cmp edi, ebx
// 007f652c  7421                 je 0x7f654f
// 007f652e  395e08               cmp dword ptr [esi + 8], ebx
// 007f6531  761c                 jbe 0x7f654f
// 007f6533  8b5608               mov edx, dword ptr [esi + 8]
// 007f6536  8bcf                 mov ecx, edi
// 007f6538  8b01                 mov eax, dword ptr [ecx]
// 007f653a  3bc3                 cmp eax, ebx
// 007f653c  7409                 je 0x7f6547
// 007f653e  8bff                 mov edi, edi
// 007f6540  8b4008               mov eax, dword ptr [eax + 8]
// 007f6543  3bc3                 cmp eax, ebx
// 007f6545  75f9                 jne 0x7f6540
// 007f6547  83c104               add ecx, 4
// 007f654a  83ea01               sub edx, 1
// 007f654d  75e9                 jne 0x7f6538
// 007f654f  57                   push edi
// 007f6550  e8b1d5ffff           call 0x7f3b06
// 007f6555  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007f6558  83c404               add esp, 4
// 007f655b  895e04               mov dword ptr [esi + 4], ebx
// 007f655e  895e0c               mov dword ptr [esi + 0xc], ebx
// 007f6561  895e10               mov dword ptr [esi + 0x10], ebx
// 007f6564  e85bdeffff           call 0x7f43c4
// 007f6569  5f                   pop edi
// 007f656a  895e14               mov dword ptr [esi + 0x14], ebx
// 007f656d  5e                   pop esi
// 007f656e  5b                   pop ebx
// 007f656f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?RemoveAll@?$CMap@PAUHICON__@@PAU1@HH@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
