// from server: 100% by auto
// roc 2009-12 00831840  unit: CXTTreeBase  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00831840
//
// 00831840  53                   push ebx
// 00831841  56                   push esi
// 00831842  8bf1                 mov esi, ecx
// 00831844  57                   push edi
// 00831845  8b7e04               mov edi, dword ptr [esi + 4]
// 00831848  33db                 xor ebx, ebx
// 0083184a  3bfb                 cmp edi, ebx
// 0083184c  7421                 je 0x83186f
// 0083184e  395e08               cmp dword ptr [esi + 8], ebx
// 00831851  761c                 jbe 0x83186f
// 00831853  8b5608               mov edx, dword ptr [esi + 8]
// 00831856  8bcf                 mov ecx, edi
// 00831858  8b01                 mov eax, dword ptr [ecx]
// 0083185a  3bc3                 cmp eax, ebx
// 0083185c  7409                 je 0x831867
// 0083185e  8bff                 mov edi, edi
// 00831860  8b4048               mov eax, dword ptr [eax + 0x48]
// 00831863  3bc3                 cmp eax, ebx
// 00831865  75f9                 jne 0x831860
// 00831867  83c104               add ecx, 4
// 0083186a  83ea01               sub edx, 1
// 0083186d  75e9                 jne 0x831858
// 0083186f  57                   push edi
// 00831870  e89122fcff           call 0x7f3b06
// 00831875  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00831878  83c404               add esp, 4
// 0083187b  895e04               mov dword ptr [esi + 4], ebx
// 0083187e  895e0c               mov dword ptr [esi + 0xc], ebx
// 00831881  895e10               mov dword ptr [esi + 0x10], ebx
// 00831884  e83b2bfcff           call 0x7f43c4
// 00831889  5f                   pop edi
// 0083188a  895e14               mov dword ptr [esi + 0x14], ebx
// 0083188d  5e                   pop esi
// 0083188e  5b                   pop ebx
// 0083188f  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?RemoveAll@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
