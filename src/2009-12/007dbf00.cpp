// from server: 100% by auto
// roc 2009-12 007dbf00  unit: RBX::GroupDragTool  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dbf00
//
// 007dbf00  83f801               cmp eax, 1
// 007dbf03  8b12                 mov edx, dword ptr [edx]
// 007dbf05  8b520c               mov edx, dword ptr [edx + 0xc]
// 007dbf08  56                   push esi
// 007dbf09  8d1482               lea edx, [edx + eax*4]
// 007dbf0c  7c12                 jl 0x7dbf20
// 007dbf0e  8b42fc               mov eax, dword ptr [edx - 4]
// 007dbf11  8d72fc               lea esi, [edx - 4]
// 007dbf14  83e03f               and eax, 0x3f
// 007dbf17  f6807cf29e0080       test byte ptr [eax + 0x9ef27c], 0x80
// 007dbf1e  7502                 jne 0x7dbf22
// 007dbf20  8bf2                 mov esi, edx
// 007dbf22  8b06                 mov eax, dword ptr [esi]
// 007dbf24  8bd0                 mov edx, eax
// 007dbf26  83e23f               and edx, 0x3f
// 007dbf29  80fa1b               cmp dl, 0x1b
// 007dbf2c  7404                 je 0x7dbf32
// 007dbf2e  33c0                 xor eax, eax
// 007dbf30  5e                   pop esi
// 007dbf31  c3                   ret 
// 007dbf32  81f9ff000000         cmp ecx, 0xff
// 007dbf38  741f                 je 0x7dbf59
// 007dbf3a  8bd0                 mov edx, eax
// 007dbf3c  c1ea17               shr edx, 0x17
// 007dbf3f  3bca                 cmp ecx, edx
// 007dbf41  7416                 je 0x7dbf59
// 007dbf43  c1e106               shl ecx, 6
// 007dbf46  33c8                 xor ecx, eax
// 007dbf48  81e1c03f0000         and ecx, 0x3fc0
// 007dbf4e  33c8                 xor ecx, eax
// 007dbf50  890e                 mov dword ptr [esi], ecx
// 007dbf52  b801000000           mov eax, 1
// 007dbf57  5e                   pop esi
// 007dbf58  c3                   ret 
// 007dbf59  8bc8                 mov ecx, eax
// 007dbf5b  81e1ffffb5ff         and ecx, 0xffb5ffff
// 007dbf61  81c900003400         or ecx, 0x340000
// 007dbf67  2500c07f00           and eax, 0x7fc000
// 007dbf6c  c1e911               shr ecx, 0x11
// 007dbf6f  0bc8                 or ecx, eax
// 007dbf71  890e                 mov dword ptr [esi], ecx
// 007dbf73  b801000000           mov eax, 1
// 007dbf78  5e                   pop esi
// 007dbf79  c3                   ret 
// library lua-5.1/lcode.c (function _patchtestreg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
