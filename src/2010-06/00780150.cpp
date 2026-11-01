// from server: 100% by auto
// roc 2010-06 00780150  unit: seg_00780000  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00780150
//
// 00780150  83c0db               add eax, -0x25
// 00780153  3df6000000           cmp eax, 0xf6
// 00780158  7765                 ja 0x7801bf
// 0078015a  0fb68008027800       movzx eax, byte ptr [eax + 0x780208]
// 00780161  ff2485c8017800       jmp dword ptr [eax*4 + 0x7801c8]
// 00780168  33c0                 xor eax, eax
// 0078016a  c3                   ret 
// 0078016b  b801000000           mov eax, 1
// 00780170  c3                   ret 
// 00780171  b802000000           mov eax, 2
// 00780176  c3                   ret 
// 00780177  b803000000           mov eax, 3
// 0078017c  c3                   ret 
// 0078017d  b804000000           mov eax, 4
// 00780182  c3                   ret 
// 00780183  b805000000           mov eax, 5
// 00780188  c3                   ret 
// 00780189  b806000000           mov eax, 6
// 0078018e  c3                   ret 
// 0078018f  b807000000           mov eax, 7
// 00780194  c3                   ret 
// 00780195  b808000000           mov eax, 8
// 0078019a  c3                   ret 
// 0078019b  b809000000           mov eax, 9
// 007801a0  c3                   ret 
// 007801a1  b80a000000           mov eax, 0xa
// 007801a6  c3                   ret 
// 007801a7  b80b000000           mov eax, 0xb
// 007801ac  c3                   ret 
// 007801ad  b80c000000           mov eax, 0xc
// 007801b2  c3                   ret 
// 007801b3  b80d000000           mov eax, 0xd
// 007801b8  c3                   ret 
// 007801b9  b80e000000           mov eax, 0xe
// 007801be  c3                   ret 
// 007801bf  b80f000000           mov eax, 0xf
// 007801c4  c3                   ret 
// 007801c5  8d4900               lea ecx, [ecx]
// 007801c8  7d01                 jge 0x7801cb
// 007801ca  7800                 js 0x7801cc
// 007801cc  7101                 jno 0x7801cf
// 007801ce  7800                 js 0x7801d0
// 007801d0  680178006b           push 0x6b007801
// 007801d5  017800               add dword ptr [eax], edi
// 007801d8  7701                 ja 0x7801db
// 007801da  7800                 js 0x7801dc
// 007801dc  9b                   wait 
// 007801dd  017800               add dword ptr [eax], edi
// 007801e0  a7                   cmpsd dword ptr [esi], dword ptr es:[edi]
// 007801e1  017800               add dword ptr [eax], edi
// 007801e4  830178               add dword ptr [ecx], 0x78
// 007801e7  00b3017800b9         add byte ptr [ebx - 0x46ff87ff], dh
// 007801ed  017800               add dword ptr [eax], edi
// 007801f0  8901                 mov dword ptr [ecx], eax
// 007801f2  7800                 js 0x7801f4
// 007801f4  95                   xchg ebp, eax
// 007801f5  017800               add dword ptr [eax], edi
// 007801f8  ad                   lodsd eax, dword ptr [esi]
// 007801f9  017800               add dword ptr [eax], edi
// 007801fc  a10178008f           mov eax, dword ptr [0x8f007801]
// 00780201  017800               add dword ptr [eax], edi
// 00780204  bf01780000           mov edi, 0x7801
// library lua-5.1/lparser.c (function _getbinopr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
