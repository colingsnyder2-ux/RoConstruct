// roc 2012-06 00939ae0  unit: seg_00930000  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00939ae0
//
// 00939ae0  83c0db               add eax, -0x25
// 00939ae3  3df6000000           cmp eax, 0xf6
// 00939ae8  7765                 ja 0x939b4f
// 00939aea  0fb680989b9300       movzx eax, byte ptr [eax + 0x939b98]
// 00939af1  ff2485589b9300       jmp dword ptr [eax*4 + 0x939b58]
// 00939af8  33c0                 xor eax, eax
// 00939afa  c3                   ret 
// 00939afb  b801000000           mov eax, 1
// 00939b00  c3                   ret 
// 00939b01  b802000000           mov eax, 2
// 00939b06  c3                   ret 
// 00939b07  b803000000           mov eax, 3
// 00939b0c  c3                   ret 
// 00939b0d  b804000000           mov eax, 4
// 00939b12  c3                   ret 
// 00939b13  b805000000           mov eax, 5
// 00939b18  c3                   ret 
// 00939b19  b806000000           mov eax, 6
// 00939b1e  c3                   ret 
// 00939b1f  b807000000           mov eax, 7
// 00939b24  c3                   ret 
// 00939b25  b808000000           mov eax, 8
// 00939b2a  c3                   ret 
// 00939b2b  b809000000           mov eax, 9
// 00939b30  c3                   ret 
// 00939b31  b80a000000           mov eax, 0xa
// 00939b36  c3                   ret 
// 00939b37  b80b000000           mov eax, 0xb
// 00939b3c  c3                   ret 
// 00939b3d  b80c000000           mov eax, 0xc
// 00939b42  c3                   ret 
// 00939b43  b80d000000           mov eax, 0xd
// 00939b48  c3                   ret 
// 00939b49  b80e000000           mov eax, 0xe
// 00939b4e  c3                   ret 
// 00939b4f  b80f000000           mov eax, 0xf
// 00939b54  c3                   ret 
// 00939b55  8d4900               lea ecx, [ecx]
// 00939b58  0d9b930001           or eax, 0x100939b
// 00939b5d  9b                   wait 
// 00939b5e  93                   xchg ebx, eax
// 00939b5f  00f8                 add al, bh
// 00939b61  9a9300fb9a9300       lcall 0x93, 0x9afb0093
// 00939b68  07                   pop es
// 00939b69  9b                   wait 
// 00939b6a  93                   xchg ebx, eax
// 00939b6b  002b                 add byte ptr [ebx], ch
// 00939b6d  9b                   wait 
// 00939b6e  93                   xchg ebx, eax
// 00939b6f  0037                 add byte ptr [edi], dh
// 00939b71  9b                   wait 
// 00939b72  93                   xchg ebx, eax
// 00939b73  0013                 add byte ptr [ebx], dl
// 00939b75  9b                   wait 
// 00939b76  93                   xchg ebx, eax
// 00939b77  00439b               add byte ptr [ebx - 0x65], al
// 00939b7a  93                   xchg ebx, eax
// 00939b7b  00499b               add byte ptr [ecx - 0x65], cl
// 00939b7e  93                   xchg ebx, eax
// 00939b7f  0019                 add byte ptr [ecx], bl
// 00939b81  9b                   wait 
// 00939b82  93                   xchg ebx, eax
// 00939b83  00259b93003d         add byte ptr [0x3d00939b], ah
// 00939b89  9b                   wait 
// 00939b8a  93                   xchg ebx, eax
// 00939b8b  0031                 add byte ptr [ecx], dh
// 00939b8d  9b                   wait 
// 00939b8e  93                   xchg ebx, eax
// 00939b8f  001f                 add byte ptr [edi], bl
// 00939b91  9b                   wait 
// 00939b92  93                   xchg ebx, eax
// 00939b93  004f9b               add byte ptr [edi - 0x65], cl
// 00939b96  93                   xchg ebx, eax
// 00939b97  0000                 add byte ptr [eax], al
// library lua-5.1/lparser.c (function _getbinopr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
