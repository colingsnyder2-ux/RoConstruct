// from server: 100% by auto
// roc 2009-12 007d2840  unit: seg_007d0000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d2840
//
// 007d2840  53                   push ebx
// 007d2841  6a00                 push 0
// 007d2843  57                   push edi
// 007d2844  56                   push esi
// 007d2845  bb01000000           mov ebx, 1
// 007d284a  e861080000           call 0x7d30b0
// 007d284f  83c40c               add esp, 0xc
// 007d2852  837e102c             cmp dword ptr [esi + 0x10], 0x2c
// 007d2856  751f                 jne 0x7d2877
// 007d2858  56                   push esi
// 007d2859  e8d23e0000           call 0x7d6730
// 007d285e  8b4630               mov eax, dword ptr [esi + 0x30]
// 007d2861  57                   push edi
// 007d2862  50                   push eax
// 007d2863  e8a8a30000           call 0x7dcc10
// 007d2868  6a00                 push 0
// 007d286a  57                   push edi
// 007d286b  56                   push esi
// 007d286c  e83f080000           call 0x7d30b0
// 007d2871  83c418               add esp, 0x18
// 007d2874  43                   inc ebx
// 007d2875  ebdb                 jmp 0x7d2852
// 007d2877  8bc3                 mov eax, ebx
// 007d2879  5b                   pop ebx
// 007d287a  c3                   ret 
// library lua-5.1/lparser.c (function _explist1)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
