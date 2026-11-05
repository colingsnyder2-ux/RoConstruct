// roc 2009-12 007d2f00  unit: seg_007d0000  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d2f00
//
// 007d2f00  83c0db               add eax, -0x25
// 007d2f03  3df6000000           cmp eax, 0xf6
// 007d2f08  7765                 ja 0x7d2f6f
// 007d2f0a  0fb680b82f7d00       movzx eax, byte ptr [eax + 0x7d2fb8]
// 007d2f11  ff2485782f7d00       jmp dword ptr [eax*4 + 0x7d2f78]
// 007d2f18  33c0                 xor eax, eax
// 007d2f1a  c3                   ret 
// 007d2f1b  b801000000           mov eax, 1
// 007d2f20  c3                   ret 
// 007d2f21  b802000000           mov eax, 2
// 007d2f26  c3                   ret 
// 007d2f27  b803000000           mov eax, 3
// 007d2f2c  c3                   ret 
// 007d2f2d  b804000000           mov eax, 4
// 007d2f32  c3                   ret 
// 007d2f33  b805000000           mov eax, 5
// 007d2f38  c3                   ret 
// 007d2f39  b806000000           mov eax, 6
// 007d2f3e  c3                   ret 
// 007d2f3f  b807000000           mov eax, 7
// 007d2f44  c3                   ret 
// 007d2f45  b808000000           mov eax, 8
// 007d2f4a  c3                   ret 
// 007d2f4b  b809000000           mov eax, 9
// 007d2f50  c3                   ret 
// 007d2f51  b80a000000           mov eax, 0xa
// 007d2f56  c3                   ret 
// 007d2f57  b80b000000           mov eax, 0xb
// 007d2f5c  c3                   ret 
// 007d2f5d  b80c000000           mov eax, 0xc
// 007d2f62  c3                   ret 
// 007d2f63  b80d000000           mov eax, 0xd
// 007d2f68  c3                   ret 
// 007d2f69  b80e000000           mov eax, 0xe
// 007d2f6e  c3                   ret 
// 007d2f6f  b80f000000           mov eax, 0xf
// 007d2f74  c3                   ret 
// 007d2f75  8d4900               lea ecx, [ecx]
// 007d2f78  2d2f7d0021           sub eax, 0x21007d2f
// 007d2f7d  2f                   das 
// 007d2f7e  7d00                 jge 0x7d2f80
// 007d2f80  182f                 sbb byte ptr [edi], ch
// 007d2f82  7d00                 jge 0x7d2f84
// 007d2f84  1b2f                 sbb ebp, dword ptr [edi]
// 007d2f86  7d00                 jge 0x7d2f88
// 007d2f88  27                   daa 
// 007d2f89  2f                   das 
// 007d2f8a  7d00                 jge 0x7d2f8c
// 007d2f8c  4b                   dec ebx
// 007d2f8d  2f                   das 
// 007d2f8e  7d00                 jge 0x7d2f90
// 007d2f90  57                   push edi
// 007d2f91  2f                   das 
// 007d2f92  7d00                 jge 0x7d2f94
// 007d2f94  332f                 xor ebp, dword ptr [edi]
// 007d2f96  7d00                 jge 0x7d2f98
// 007d2f98  632f                 arpl word ptr [edi], bp
// 007d2f9a  7d00                 jge 0x7d2f9c
// 007d2f9c  692f7d00392f         imul ebp, dword ptr [edi], 0x2f39007d
// 007d2fa2  7d00                 jge 0x7d2fa4
// 007d2fa4  45                   inc ebp
// 007d2fa5  2f                   das 
// 007d2fa6  7d00                 jge 0x7d2fa8
// 007d2fa8  5d                   pop ebp
// 007d2fa9  2f                   das 
// 007d2faa  7d00                 jge 0x7d2fac
// 007d2fac  51                   push ecx
// 007d2fad  2f                   das 
// 007d2fae  7d00                 jge 0x7d2fb0
// 007d2fb0  3f                   aas 
// 007d2fb1  2f                   das 
// 007d2fb2  7d00                 jge 0x7d2fb4
// 007d2fb4  6f                   outsd dx, dword ptr [esi]
// 007d2fb5  2f                   das 
// 007d2fb6  7d00                 jge 0x7d2fb8
// 007d2fb8  000f                 add byte ptr [edi], cl
// library lua-5.1/lparser.c (function _getbinopr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
