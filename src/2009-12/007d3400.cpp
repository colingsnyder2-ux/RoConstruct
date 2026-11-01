// from server: 100% by auto
// roc 2009-12 007d3400  unit: seg_007d0000  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3400
//
// 007d3400  53                   push ebx
// 007d3401  8b5830               mov ebx, dword ptr [eax + 0x30]
// 007d3404  56                   push esi
// 007d3405  8b7314               mov esi, dword ptr [ebx + 0x14]
// 007d3408  57                   push edi
// 007d3409  33ff                 xor edi, edi
// 007d340b  85f6                 test esi, esi
// 007d340d  7413                 je 0x7d3422
// 007d340f  90                   nop 
// 007d3410  807e0a00             cmp byte ptr [esi + 0xa], 0
// 007d3414  751a                 jne 0x7d3430
// 007d3416  0fb64e09             movzx ecx, byte ptr [esi + 9]
// 007d341a  8b36                 mov esi, dword ptr [esi]
// 007d341c  0bf9                 or edi, ecx
// 007d341e  85f6                 test esi, esi
// 007d3420  75ee                 jne 0x7d3410
// 007d3422  68c0ef9e00           push 0x9eefc0
// 007d3427  50                   push eax
// 007d3428  e8131f0000           call 0x7d5340
// 007d342d  83c408               add esp, 8
// 007d3430  85ff                 test edi, edi
// 007d3432  7414                 je 0x7d3448
// 007d3434  0fb65608             movzx edx, byte ptr [esi + 8]
// 007d3438  6a00                 push 0
// 007d343a  6a00                 push 0
// 007d343c  52                   push edx
// 007d343d  6a23                 push 0x23
// 007d343f  53                   push ebx
// 007d3440  e8bb910000           call 0x7dc600
// 007d3445  83c414               add esp, 0x14
// 007d3448  53                   push ebx
// 007d3449  e842930000           call 0x7dc790
// 007d344e  50                   push eax
// 007d344f  83c604               add esi, 4
// 007d3452  56                   push esi
// 007d3453  53                   push ebx
// 007d3454  e8778c0000           call 0x7dc0d0
// 007d3459  83c410               add esp, 0x10
// 007d345c  5f                   pop edi
// 007d345d  5e                   pop esi
// 007d345e  5b                   pop ebx
// 007d345f  c3                   ret 
// library lua-5.1/lparser.c (function _breakstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
