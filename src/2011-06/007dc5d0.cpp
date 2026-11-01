// from server: 100% by auto
// roc 2011-06 007dc5d0  unit: seg_007d0000  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007dc5d0
//
// 007dc5d0  83c0db               add eax, -0x25
// 007dc5d3  3df6000000           cmp eax, 0xf6
// 007dc5d8  7765                 ja 0x7dc63f
// 007dc5da  0fb68088c67d00       movzx eax, byte ptr [eax + 0x7dc688]
// 007dc5e1  ff248548c67d00       jmp dword ptr [eax*4 + 0x7dc648]
// 007dc5e8  33c0                 xor eax, eax
// 007dc5ea  c3                   ret 
// 007dc5eb  b801000000           mov eax, 1
// 007dc5f0  c3                   ret 
// 007dc5f1  b802000000           mov eax, 2
// 007dc5f6  c3                   ret 
// 007dc5f7  b803000000           mov eax, 3
// 007dc5fc  c3                   ret 
// 007dc5fd  b804000000           mov eax, 4
// 007dc602  c3                   ret 
// 007dc603  b805000000           mov eax, 5
// 007dc608  c3                   ret 
// 007dc609  b806000000           mov eax, 6
// 007dc60e  c3                   ret 
// 007dc60f  b807000000           mov eax, 7
// 007dc614  c3                   ret 
// 007dc615  b808000000           mov eax, 8
// 007dc61a  c3                   ret 
// 007dc61b  b809000000           mov eax, 9
// 007dc620  c3                   ret 
// 007dc621  b80a000000           mov eax, 0xa
// 007dc626  c3                   ret 
// 007dc627  b80b000000           mov eax, 0xb
// 007dc62c  c3                   ret 
// 007dc62d  b80c000000           mov eax, 0xc
// 007dc632  c3                   ret 
// 007dc633  b80d000000           mov eax, 0xd
// 007dc638  c3                   ret 
// 007dc639  b80e000000           mov eax, 0xe
// 007dc63e  c3                   ret 
// 007dc63f  b80f000000           mov eax, 0xf
// 007dc644  c3                   ret 
// 007dc645  8d4900               lea ecx, [ecx]
// 007dc648  fd                   std 
// 007dc649  c57d00               lds edi, ptr [ebp]
// 007dc64c  f1                   int1 
// 007dc64d  c57d00               lds edi, ptr [ebp]
// 007dc650  e8c57d00eb           call 0xeb7e441a
// 007dc655  c57d00               lds edi, ptr [ebp]
// 007dc658  f7c57d001bc6         test ebp, 0xc61b007d
// 007dc65e  7d00                 jge 0x7dc660
// 007dc660  27                   daa 
// library lua-5.1/lparser.c (function _getbinopr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
