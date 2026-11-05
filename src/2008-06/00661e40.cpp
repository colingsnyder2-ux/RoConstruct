// from server: 100% by auto
// roc 2008-06 00661e40  unit: RBX::FilterStairs  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00661e40
//
// 00661e40  83c0db               add eax, -0x25
// 00661e43  3df6000000           cmp eax, 0xf6
// 00661e48  7765                 ja 0x661eaf
// 00661e4a  0fb680f81e6600       movzx eax, byte ptr [eax + 0x661ef8]
// 00661e51  ff2485b81e6600       jmp dword ptr [eax*4 + 0x661eb8]
// 00661e58  33c0                 xor eax, eax
// 00661e5a  c3                   ret 
// 00661e5b  b801000000           mov eax, 1
// 00661e60  c3                   ret 
// 00661e61  b802000000           mov eax, 2
// 00661e66  c3                   ret 
// 00661e67  b803000000           mov eax, 3
// 00661e6c  c3                   ret 
// 00661e6d  b804000000           mov eax, 4
// 00661e72  c3                   ret 
// 00661e73  b805000000           mov eax, 5
// 00661e78  c3                   ret 
// 00661e79  b806000000           mov eax, 6
// 00661e7e  c3                   ret 
// 00661e7f  b807000000           mov eax, 7
// 00661e84  c3                   ret 
// 00661e85  b808000000           mov eax, 8
// 00661e8a  c3                   ret 
// 00661e8b  b809000000           mov eax, 9
// 00661e90  c3                   ret 
// 00661e91  b80a000000           mov eax, 0xa
// 00661e96  c3                   ret 
// 00661e97  b80b000000           mov eax, 0xb
// 00661e9c  c3                   ret 
// 00661e9d  b80c000000           mov eax, 0xc
// 00661ea2  c3                   ret 
// 00661ea3  b80d000000           mov eax, 0xd
// 00661ea8  c3                   ret 
// 00661ea9  b80e000000           mov eax, 0xe
// 00661eae  c3                   ret 
// 00661eaf  b80f000000           mov eax, 0xf
// 00661eb4  c3                   ret 
// 00661eb5  8d4900               lea ecx, [ecx]
// 00661eb8  6d                   insd dword ptr es:[edi], dx
// 00661eb9  1e                   push ds
// 00661eba  6600611e             add byte ptr [ecx + 0x1e], ah
// 00661ebe  6600581e             add byte ptr [eax + 0x1e], bl
// 00661ec2  66005b1e             add byte ptr [ebx + 0x1e], bl
// 00661ec6  6600671e             add byte ptr [edi + 0x1e], ah
// 00661eca  66008b1e660097       add byte ptr [ebx - 0x68ff99e2], cl
// 00661ed1  1e                   push ds
// 00661ed2  6600731e             add byte ptr [ebx + 0x1e], dh
// 00661ed6  6600a31e6600a9       add byte ptr [ebx - 0x56ff99e2], ah
// 00661edd  1e                   push ds
// 00661ede  6600791e             add byte ptr [ecx + 0x1e], bh
// 00661ee2  6600851e66009d       add byte ptr [ebp - 0x62ff99e2], al
// 00661ee9  1e                   push ds
// 00661eea  6600911e66007f       add byte ptr [ecx + 0x7f00661e], dl
// 00661ef1  1e                   push ds
// 00661ef2  6600af1e660000       add byte ptr [edi + 0x661e], ch
// library lua-5.1/lparser.c (function _getbinopr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
