// from server: 100% by auto
// roc 2007-03 00509640  unit: seg_00500000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509640
//
// 00509640  57                   push edi
// 00509641  8b7c2408             mov edi, dword ptr [esp + 8]
// 00509645  85ff                 test edi, edi
// 00509647  746b                 je 0x5096b4
// 00509649  56                   push esi
// 0050964a  8b742410             mov esi, dword ptr [esp + 0x10]
// 0050964e  85f6                 test esi, esi
// 00509650  7461                 je 0x5096b3
// 00509652  8b442414             mov eax, dword ptr [esp + 0x14]
// 00509656  3dffffff7f           cmp eax, 0x7fffffff
// 0050965b  7e15                 jle 0x509672
// 0050965d  68f8097a00           push 0x7a09f8
// 00509662  57                   push edi
// 00509663  e868ed0000           call 0x5183d0
// 00509668  83c408               add esp, 8
// 0050966b  b8ffffff7f           mov eax, 0x7fffffff
// 00509670  eb14                 jmp 0x509686
// 00509672  85c0                 test eax, eax
// 00509674  7d10                 jge 0x509686
// 00509676  68140a7a00           push 0x7a0a14
// 0050967b  57                   push edi
// 0050967c  e84fed0000           call 0x5183d0
// 00509681  83c408               add esp, 8
// 00509684  33c0                 xor eax, eax
// 00509686  8944240c             mov dword ptr [esp + 0xc], eax
// 0050968a  db44240c             fild dword ptr [esp + 0xc]
// 0050968e  834e0801             or dword ptr [esi + 8], 1
// 00509692  85c0                 test eax, eax
// 00509694  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0050969a  dc35d0097a00         fdiv qword ptr [0x7a09d0]
// 005096a0  d95e28               fstp dword ptr [esi + 0x28]
// 005096a3  750e                 jne 0x5096b3
// 005096a5  68e8097a00           push 0x7a09e8
// 005096aa  57                   push edi
// 005096ab  e820ed0000           call 0x5183d0
// 005096b0  83c408               add esp, 8
// 005096b3  5e                   pop esi
// 005096b4  5f                   pop edi
// 005096b5  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_gAMA_fixed)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
