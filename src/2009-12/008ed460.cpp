// from server: 100% by auto
// roc 2009-12 008ed460  unit: CXTPRibbonGroup  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ed460
//
// 008ed460  53                   push ebx
// 008ed461  55                   push ebp
// 008ed462  57                   push edi
// 008ed463  8be9                 mov ebp, ecx
// 008ed465  e826ffffff           call 0x8ed390
// 008ed46a  6a01                 push 1
// 008ed46c  33ff                 xor edi, edi
// 008ed46e  57                   push edi
// 008ed46f  8bcd                 mov ecx, ebp
// 008ed471  8bd8                 mov ebx, eax
// 008ed473  e878f8ffff           call 0x8eccf0
// 008ed478  83f802               cmp eax, 2
// 008ed47b  7d06                 jge 0x8ed483
// 008ed47d  5f                   pop edi
// 008ed47e  5d                   pop ebp
// 008ed47f  33c0                 xor eax, eax
// 008ed481  5b                   pop ebx
// 008ed482  c3                   ret 
// 008ed483  7447                 je 0x8ed4cc
// 008ed485  85db                 test ebx, ebx
// 008ed487  7e43                 jle 0x8ed4cc
// 008ed489  56                   push esi
// 008ed48a  8d9b00000000         lea ebx, [ebx]
// 008ed490  8d041f               lea eax, [edi + ebx]
// 008ed493  99                   cdq 
// 008ed494  2bc2                 sub eax, edx
// 008ed496  8bf0                 mov esi, eax
// 008ed498  6a01                 push 1
// 008ed49a  d1fe                 sar esi, 1
// 008ed49c  56                   push esi
// 008ed49d  8bcd                 mov ecx, ebp
// 008ed49f  e84cf8ffff           call 0x8eccf0
// 008ed4a4  83f802               cmp eax, 2
// 008ed4a7  7f04                 jg 0x8ed4ad
// 008ed4a9  8bde                 mov ebx, esi
// 008ed4ab  eb06                 jmp 0x8ed4b3
// 008ed4ad  3bfe                 cmp edi, esi
// 008ed4af  7410                 je 0x8ed4c1
// 008ed4b1  8bfe                 mov edi, esi
// 008ed4b3  3bfb                 cmp edi, ebx
// 008ed4b5  7cd9                 jl 0x8ed490
// 008ed4b7  5e                   pop esi
// 008ed4b8  5f                   pop edi
// 008ed4b9  5d                   pop ebp
// 008ed4ba  b801000000           mov eax, 1
// 008ed4bf  5b                   pop ebx
// 008ed4c0  c3                   ret 
// 008ed4c1  6a01                 push 1
// 008ed4c3  53                   push ebx
// 008ed4c4  8bcd                 mov ecx, ebp
// 008ed4c6  e825f8ffff           call 0x8eccf0
// 008ed4cb  5e                   pop esi
// 008ed4cc  5f                   pop edi
// 008ed4cd  5d                   pop ebp
// 008ed4ce  b801000000           mov eax, 1
// 008ed4d3  5b                   pop ebx
// 008ed4d4  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?_FindBestWrapSpecialDynamicSize@CXTPRibbonGroup@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
